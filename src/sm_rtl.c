#include "sm_rtl.h"
#include "sm_cpu_infra.h"
#include "types.h"
//#include "ida_types.h"
#include "variables.h"
#include "funcs.h"
#include "spc_player.h"
#include "util.h"

struct StateRecorder;

static void RtlSaveMusicStateToRam_Locked();
static void RtlRestoreMusicAfterLoad_Locked(bool is_reset);

uint8 g_ram[0x20000];
uint8 *g_sram;
const uint8 *g_rom;

uint32 g_wanted_sm_features;

static uint8 *g_rtl_memory_ptr;
static RunFrameFunc *g_rtl_runframe;
static SyncAllFunc *g_rtl_syncall;

void RtlSetupEmuCallbacks(uint8 *emu_ram, RunFrameFunc *func, SyncAllFunc *sync_all) {
  g_rtl_memory_ptr = emu_ram;
  g_rtl_runframe = func;
  g_rtl_syncall = sync_all;
}

static void RtlSynchronizeWholeState(void) {
  if (g_rtl_syncall)
    g_rtl_syncall();
}

// |ptr| must be a pointer into g_ram, will synchronize the RAM memory with the
// emulator.
static void RtlSyncMemoryRegion(void *ptr, size_t n) {
  uint8 *data = (uint8 *)ptr;
  assert(data >= g_ram && data < g_ram + 0x20000);
  if (g_rtl_memory_ptr)
    memcpy(g_rtl_memory_ptr + (data - g_ram), data, n);
}

void ByteArray_AppendVl(ByteArray *arr, uint32 v) {
  for (; v >= 255; v -= 255)
    ByteArray_AppendByte(arr, 255);
  ByteArray_AppendByte(arr, v);
}

void saveFunc(void *ctx_in, void *data, size_t data_size) {
  ByteArray_AppendData((ByteArray *)ctx_in, (uint8*)data, data_size);
}

typedef struct LoadFuncState {
  uint8 *p, *pend;
} LoadFuncState;

void loadFunc(void *ctx, void *data, size_t data_size) {
  LoadFuncState *st = (LoadFuncState *)ctx;
  assert((size_t)(st->pend - st->p) >= data_size);
  memcpy(data, st->p, data_size);
  st->p += data_size;
}
static void LoadSnesState(SaveLoadFunc *func, void *ctx) {
  // Do the actual loading
  snes_saveload(g_snes, func, ctx);

  g_snes->cpu->e = false;
  uint32 next = (g_snes->ram[g_snes->cpu->sp + 3] | g_snes->ram[g_snes->cpu->sp + 4] << 8 | g_snes->ram[g_snes->cpu->sp + 5] << 16) + 1;
  if (next == 0x82897e) {
    g_snes->ram[g_snes->cpu->sp + 3] = (0xF71B - 1) & 0xff;
    g_snes->ram[g_snes->cpu->sp + 4] = (0xF71B - 1) >> 8;
  }
  RtlSynchronizeWholeState();
}

static void SaveSnesState(SaveLoadFunc *func, void *ctx) {
  snes_saveload(g_snes, func, ctx);
}

typedef struct StateRecorder {
  uint16 last_inputs;
  uint32 frames_since_last;
  uint32 total_frames;

  // For replay
  uint32 replay_pos, replay_pos_last_complete;
  uint32 replay_frame_counter;
  uint32 replay_next_cmd_at;
  uint32 snapshot_flags;
  uint8 replay_cmd;
  bool replay_mode;

  ByteArray log;
  ByteArray base_snapshot;
} StateRecorder;

static StateRecorder state_recorder;

void StateRecorder_Init(StateRecorder *sr) {
  ByteArray_Destroy(&sr->log);
  ByteArray_Destroy(&sr->base_snapshot);
  memset(sr, 0, sizeof(*sr));
}

void StateRecorder_RecordCmd(StateRecorder *sr, uint8 cmd) {
  int frames = sr->frames_since_last;
  sr->frames_since_last = 0;
  int x = (cmd < 0xc0) ? 0xf : 0x1;
  ByteArray_AppendByte(&sr->log, cmd | (frames < x ? frames : x));
  if (frames >= x)
    ByteArray_AppendVl(&sr->log, frames - x);
}

void StateRecorder_Record(StateRecorder *sr, uint16 inputs) {
  uint16 diff = inputs ^ sr->last_inputs;
  if (diff != 0) {
    sr->last_inputs = inputs;
    //    printf("0x%.4x %d: ", diff, sr->frames_since_last);
    //    size_t lb = sr->log.size;
    for (int i = 0; i < 12; i++) {
      if ((diff >> i) & 1)
        StateRecorder_RecordCmd(sr, i << 4);
    }
    //    while (lb < sr->log.size)
    //      printf("%.2x ", sr->log.data[lb++]);
    //    printf("\n");
  }
  sr->frames_since_last++;
  sr->total_frames++;
}

void StateRecorder_RecordPatchByte(StateRecorder *sr, uint32 addr, const uint8 *value, int num) {
  assert(addr < 0x20000);

//  printf("%d: PatchByte(0x%x, 0x%x. %d): ", sr->frames_since_last, addr, *value, num);
  size_t lb = sr->log.size;
  int lq = (num - 1) <= 3 ? (num - 1) : 3;
  StateRecorder_RecordCmd(sr, 0xc0 | (addr & 0x10000 ? 2 : 0) | lq << 2);
  if (lq == 3)
    ByteArray_AppendVl(&sr->log, num - 1 - 3);
  ByteArray_AppendByte(&sr->log, addr >> 8);
  ByteArray_AppendByte(&sr->log, addr);
  for (int i = 0; i < num; i++)
    ByteArray_AppendByte(&sr->log, value[i]);
//    while (lb < sr->log.size)
//      printf("%.2x ", sr->log.data[lb++]);
//    printf("\n");
}

void ReadFromFile(FILE *f, void *data, size_t n) {
  if (fread(data, 1, n, f) != n)
    Die("fread failed\n");
}

void RtlReset(int mode) {
  snes_frame_counter = 0;
  snes_reset(g_snes, true);
  if (!(mode & 1))
    memset(g_sram, 0, 0x2000);
  
  coroutine_state_0 = 1;
    
  RtlApuLock();
  RtlRestoreMusicAfterLoad_Locked(true);
  RtlApuUnlock();

  RtlSynchronizeWholeState();

  if ((mode & 2) == 0)
    StateRecorder_Init(&state_recorder);
}

int GetFileSize(FILE *f) {
  fseek(f, 0, SEEK_END);
  int r = ftell(f);
  fseek(f, 0, SEEK_SET);
  return r;
}

void StateRecorder_Load(StateRecorder *sr, FILE *f, bool replay_mode) {
  uint32 hdr[16] = { 0 };

  bool is_old = false;
  bool is_reset = false;

  ReadFromFile(f, hdr, 8 * sizeof(uint32));
  if (hdr[0] != 2) {
    hdr[8] = hdr[7];
    hdr[7] = hdr[5] >> 1;
    hdr[5] = (hdr[5] & 1) ? hdr[6] : 0;
  } else if (hdr[0] == 2) {
    ReadFromFile(f, hdr + 8, 8 * sizeof(uint32));

  } else {
    assert(0);
  }

  sr->total_frames = hdr[1];
  ByteArray_Resize(&sr->log, hdr[2]);
  ReadFromFile(f, sr->log.data, sr->log.size);
  sr->last_inputs = hdr[3];
  sr->frames_since_last = hdr[4];

  ByteArray_Resize(&sr->base_snapshot, hdr[5]);
  ReadFromFile(f, sr->base_snapshot.data, sr->base_snapshot.size);

  sr->snapshot_flags = hdr[9];
  sr->replay_next_cmd_at = 0;
  sr->replay_mode = replay_mode;
  if (replay_mode) {
    sr->frames_since_last = 0;
    sr->last_inputs = 0;
    sr->replay_pos = sr->replay_pos_last_complete = 0;
    sr->replay_frame_counter = 0;
    // Load snapshot from |base_snapshot_|, or reset if empty.
    if (sr->base_snapshot.size > 8192 ) {
      LoadFuncState state = { sr->base_snapshot.data, sr->base_snapshot.data + sr->base_snapshot.size };
      LoadSnesState(&loadFunc, &state);
      assert(state.p == state.pend);
    } else {
      RtlReset(2);
      if (sr->base_snapshot.size == 8192)
        memcpy(g_sram, sr->base_snapshot.data, 8192);
      is_reset = true;
    }
  } else {
    // Resume replay from the saved position?
    sr->replay_pos = sr->replay_pos_last_complete = hdr[7];
    sr->replay_frame_counter = hdr[8];
    sr->replay_mode = (sr->replay_frame_counter != 0);

    assert(hdr[6] == 275493);

    ByteArray arr = { 0 };
    ByteArray_Resize(&arr, hdr[6]);
    ReadFromFile(f, arr.data, arr.size);
    LoadFuncState state = { arr.data, arr.data + arr.size };
    LoadSnesState(&loadFunc, &state);
    ByteArray_Destroy(&arr);
    assert(state.p == state.pend);

    if (is_old)
      RtlClearKeyLog();
  }

  if (!is_reset)
    RtlRestoreMusicAfterLoad_Locked(false);

  RtlUpdateSnesPatchForBugfix();

  // Temporarily fix reset state
//  if (g_snes->cpu->k == 0x82 && g_snes->cpu->pc == 0xf716)
//    g_snes->cpu->pc = 0xf71c;
  OpenMsuFile();    //restore msu track after loading save state
}

void StateRecorder_Save(StateRecorder *sr, FILE *f, bool saving_with_bug) {
  uint32 hdr[16] = { 0 };
  ByteArray arr = { 0 };
  SaveSnesState(&saveFunc, &arr);
  assert(sr->base_snapshot.size == 0 || sr->base_snapshot.size == arr.size || sr->base_snapshot.size == 8192);

  hdr[0] = 2;
  hdr[1] = sr->total_frames;
  hdr[2] = (uint32)sr->log.size;
  hdr[3] = sr->last_inputs;
  hdr[4] = sr->frames_since_last;
  hdr[5] = (uint32)sr->base_snapshot.size;
  hdr[6] = (uint32)arr.size;
  // If saving while in replay mode, also need to persist
  // sr->replay_pos_last_complete and sr->replay_frame_counter
  // so the replaying can be resumed.
  if (sr->replay_mode) {
    hdr[7] = sr->replay_pos_last_complete;
    hdr[8] = sr->replay_frame_counter;
  }
  hdr[9] = saving_with_bug * 1;
  fwrite(hdr, 1, sizeof(hdr), f);
  fwrite(sr->log.data, 1, sr->log.size, f);
  fwrite(sr->base_snapshot.data, 1, sr->base_snapshot.size, f);
  fwrite(arr.data, 1, arr.size, f);

  ByteArray_Destroy(&arr);
}

void StateRecorder_ClearKeyLog(StateRecorder *sr) {
  printf("Clearing key log!\n");
  sr->base_snapshot.size = 0;
  SaveSnesState(&saveFunc, &sr->base_snapshot);
  ByteArray old_log = sr->log;
  int old_frames_since_last = sr->frames_since_last;
  memset(&sr->log, 0, sizeof(sr->log));
  // If there are currently any active inputs, record them initially at timestamp 0.
  sr->frames_since_last = 0;
  if (sr->last_inputs) {
    for (int i = 0; i < 12; i++) {
      if ((sr->last_inputs >> i) & 1)
        StateRecorder_RecordCmd(sr, i << 4);
    }
  }
  if (sr->replay_mode) {
    // When clearing the key log while in replay mode, we want to keep
    // replaying but discarding all key history up until this point.
    if (sr->replay_next_cmd_at != 0xffffffff) {
      sr->replay_next_cmd_at -= old_frames_since_last;
      sr->frames_since_last = sr->replay_next_cmd_at;
      sr->replay_pos_last_complete = (uint32)sr->log.size;
      StateRecorder_RecordCmd(sr, sr->replay_cmd);
      int old_replay_pos = sr->replay_pos;
      sr->replay_pos = (uint32)sr->log.size;
      ByteArray_AppendData(&sr->log, old_log.data + old_replay_pos, old_log.size - old_replay_pos);
    }
    sr->total_frames -= sr->replay_frame_counter;
    sr->replay_frame_counter = 0;
  } else {
    sr->total_frames = 0;
  }
  ByteArray_Destroy(&old_log);
  sr->frames_since_last = 0;
}

uint16 StateRecorder_ReadNextReplayState(StateRecorder *sr) {
  assert(sr->replay_mode);
  while (sr->frames_since_last >= sr->replay_next_cmd_at) {
    int replay_pos = sr->replay_pos;
    if (replay_pos != sr->replay_pos_last_complete) {
      // Apply next command
      sr->frames_since_last = 0;
      if (sr->replay_cmd < 0xc0) {
        sr->last_inputs ^= 1 << (sr->replay_cmd >> 4);
      } else if (sr->replay_cmd < 0xd0) {
        int nb = 1 + ((sr->replay_cmd >> 2) & 3);
        uint8 t;
        if (nb == 4) do {
          nb += t = sr->log.data[replay_pos++];
        } while (t == 255);
        uint32 addr = ((sr->replay_cmd >> 1) & 1) << 16;
        addr |= sr->log.data[replay_pos++] << 8;
        addr |= sr->log.data[replay_pos++];
        do {
          g_ram[addr & 0x1ffff] = sr->log.data[replay_pos++];
          RtlSyncMemoryRegion(&g_ram[addr & 0x1ffff], 1);
        } while (addr++, --nb);
      } else {
        assert(0);
      }
    }
    sr->replay_pos_last_complete = replay_pos;
    if (replay_pos >= sr->log.size) {
      sr->replay_pos = replay_pos;
      sr->replay_next_cmd_at = 0xffffffff;
      break;
    }
    // Read the next one
    uint8 cmd = sr->log.data[replay_pos++], t;
    int mask = (cmd < 0xc0) ? 0xf : 0x1;
    int frames = cmd & mask;
    if (frames == mask) do {
      frames += t = sr->log.data[replay_pos++];
    } while (t == 255);
    sr->replay_next_cmd_at = frames;
    sr->replay_cmd = cmd;
    sr->replay_pos = replay_pos;
  }
  sr->frames_since_last++;
  // Turn off replay mode after we reached the final frame position
  if (++sr->replay_frame_counter >= sr->total_frames) {
    sr->replay_mode = false;
  }
  return sr->last_inputs;
}

void StateRecorder_StopReplay(StateRecorder *sr) {
  if (!sr->replay_mode)
    return;
  sr->replay_mode = false;
  sr->total_frames = sr->replay_frame_counter;
  sr->log.size = sr->replay_pos_last_complete;
}


void RtlClearKeyLog(void) {
  StateRecorder_ClearKeyLog(&state_recorder);
}

void RtlStopReplay(void) {
  StateRecorder_StopReplay(&state_recorder);
}

enum {
  // Version was bumped to 1 after I fixed bug #1
  kCurrentBugFixCounter = 1,
};

bool RtlRunFrame(int inputs) {
  // Avoid up/down and left/right from being pressed at the same time
  if ((inputs & 0x30) == 0x30) inputs ^= 0x30;
  if ((inputs & 0xc0) == 0xc0) inputs ^= 0xc0;

  bool is_replay = state_recorder.replay_mode;

  // Either copy state or apply state
  if (is_replay) {
    inputs = StateRecorder_ReadNextReplayState(&state_recorder);
  } else {
    // Loading a bug snapshot?
    if (state_recorder.snapshot_flags & 1) {
      state_recorder.snapshot_flags &= ~1;
      inputs = state_recorder.last_inputs;
    } else {
      if (bug_fix_counter != kCurrentBugFixCounter) {
        if (g_debug_flag)
          printf("bug_fix_counter %d => %d\n", bug_fix_counter, kCurrentBugFixCounter);
        if (bug_fix_counter < kCurrentBugFixCounter) {
          bug_fix_counter = kCurrentBugFixCounter;
          StateRecorder_RecordPatchByte(&state_recorder, (uint8 *)&bug_fix_counter - g_ram, (uint8 *)&bug_fix_counter, 2);
        }
      }
      if (enhanced_features0 != g_wanted_sm_features) {
          enhanced_features0 = g_wanted_sm_features;
          RtlSyncMemoryRegion(&enhanced_features0, sizeof(enhanced_features0));
          StateRecorder_RecordPatchByte(&state_recorder, kRam_Features0, (uint8*)&enhanced_features0, 4);
      }
    }

    StateRecorder_Record(&state_recorder, inputs);
  }

  if (bug_fix_counter != currently_installed_bug_fix_counter)
    RtlUpdateSnesPatchForBugfix();

  g_rtl_runframe(inputs, 0);

  snes_frame_counter++;

  RtlPushApuState();
  return is_replay;
}

void RtlSaveSnapshot(const char *filename, bool saving_with_bug) {
  FILE *f = fopen(filename, "wb");
  RtlApuLock();
  RtlSaveMusicStateToRam_Locked();
  StateRecorder_Save(&state_recorder, f, saving_with_bug);
  RtlApuUnlock();
  fclose(f);
}

static const char *const kBugSaves[] = {
  "Before Kraid",
  "Before Golden Torizo", "After Crocomire", "Baby Metroid", "Tourian Statue", "Before Ridley", "Enter Mother Brain",
};

void RtlSaveLoad(int cmd, int slot) {
  char name[128];
  if (slot >= 256) {
    int i = slot - 256;
    if (cmd == kSaveLoad_Save || i >= sizeof(kBugSaves) / sizeof(kBugSaves[0]))
      return;
    sprintf(name, "saves/%s.sav", kBugSaves[i]);
  } else {
    sprintf(name, "saves/save%d.sav", slot);
  }
  printf("*** %s slot %d\n",
    cmd == kSaveLoad_Save ? "Saving" : cmd == kSaveLoad_Load ? "Loading" : "Replaying", slot);
  if (cmd != kSaveLoad_Save) {

    FILE *f = fopen(name, "rb");
    if (f == NULL) {
      printf("Failed fopen: %s\n", name);
      return;
    }
    RtlApuLock();
    StateRecorder_Load(&state_recorder, f, cmd == kSaveLoad_Replay);
    ppu_copy(g_snes->my_ppu, g_snes->ppu);
    RtlApuUnlock();
    RtlSynchronizeWholeState();
    fclose(f);

    if (coroutine_state_0 | coroutine_state_1 | coroutine_state_2 | coroutine_state_3 | coroutine_state_4) {
      printf("Coroutine state: %d, %d, %d, %d, %d\n",
        coroutine_state_0, coroutine_state_1, coroutine_state_2, coroutine_state_3, coroutine_state_4);
    }

    // Earlier versions used coroutine_state_0 differently
    if (coroutine_state_0 == 4)
      coroutine_state_0 = 10 + game_state;

    // bug_fix_counter_BAD didn't actually belong to free ram...
    if (bug_fix_counter == 0)
      bug_fix_counter = bug_fix_counter_BAD;

  } else {
    RtlSaveSnapshot(name, false);
  }
}

/**
* @brief Copies size bytes from the source to the destination
* @param *dst Pointer to destination
* @param *src Pointer to source
* @param size Amount of bytes to copy
*/
void MemCpy(void *dst, const void *src, int size) {
  memcpy(dst, src, size);
}

PairU16 MakePairU16(uint16 k, uint16 j) {
  PairU16 r = { k, j };
  return r;
}

void mov24(struct LongPtr *a, uint32 d) {
  a->addr = d & 0xffff;
  a->bank = d >> 16;
}

uint32 Load24(const LongPtr *src) {
  return *(uint32 *)src & 0xffffff;
}

bool Unreachable(void) {
  printf("Unreachable!\n");
  assert(0);
  g_ram[0x1ffff] = 1;
  return false;
}

const uint8 *RomPtr(uint32_t addr) {
  if (!(addr & 0x8000)) {
    printf("RomPtr - Invalid access 0x%x!\n", addr);
    g_fail = true;
  }
  return &g_rom[(((addr >> 16) << 15) | (addr & 0x7fff)) & 0x3fffff];
}

void WriteReg(uint16 reg, uint8 value) {
  snes_write(g_snes, reg, value);
}

uint16 Mult8x8(uint8 a, uint8 b) {
  return a * b;
}

uint16 SnesDivide(uint16 a, uint8 b) {
  return (b == 0) ? 0xffff : a / b;
}

uint16 SnesModulus(uint16 a, uint8 b) {
  return (b == 0) ? a : a % b;
}


uint8 ReadReg(uint16 reg) {
  return snes_read(g_snes, reg);
}

uint16 ReadRegWord(uint16 reg) {
  uint16_t rv = ReadReg(reg);
  rv |= ReadReg(reg + 1) << 8;
  return rv;
}

void WriteRegWord(uint16 reg, uint16 value) {
  WriteReg(reg, (uint8)value);
  WriteReg(reg + 1, value >> 8);
}

// Maintain a queue cause the snes and audio callback are not in sync.
// If an entry is 255, it means unset.
typedef struct ApuWriteEnt {
  uint8 ports[4];
} ApuWriteEnt;

enum {
  kApuMaxQueueSize = 16,
};

static struct ApuWriteEnt g_apu_write_ents[kApuMaxQueueSize], g_apu_write;
static uint8 g_apu_write_ent_pos, g_apu_queue_size, g_apu_time_since_empty;

void RtlApuWrite(uint32 adr, uint8 val) {
  assert(APUIO0 <= adr && adr <= APUIO3);

  if (is_uploading_apu) {
    snes_catchupApu(g_snes); // catch up the apu before writing
    g_snes->apu->inPorts[adr & 0x3] = val;
    return;
  }

  // If running port code
  if (g_snes->runningWhichVersion != 2) {
    g_apu_write.ports[adr & 0x3] = val;
  }
}

static bool IsFrameEmpty(ApuWriteEnt *w) {
  return (w->ports[0] == 255) && (w->ports[1] == 255) && (w->ports[2] == 255) && (w->ports[3] == 255);
}

void RtlPushApuState(void) {
  RtlApuLock();
  if (!is_uploading_apu) {
    // Strive for the queue to be empty.
    if (g_apu_queue_size == 0) {
        g_apu_time_since_empty = 0;
    } else {
      if (g_apu_time_since_empty >= 32 && IsFrameEmpty(&g_apu_write)) {
        g_apu_time_since_empty -= 4;
        RtlApuUnlock();
        return;
      }
      g_apu_time_since_empty++;
    }

    // Merge the two oldest to make space
    ApuWriteEnt *w0 = &g_apu_write_ents[g_apu_write_ent_pos++ & (kApuMaxQueueSize - 1)];
    if (g_apu_queue_size == kApuMaxQueueSize) {
      ApuWriteEnt *w1 = &g_apu_write_ents[g_apu_write_ent_pos & (kApuMaxQueueSize - 1)];
      for (int i = 0; i < 4; i++)
        if (w1->ports[i] == 255)
          w1->ports[i] = w0->ports[i];
    } else {
      g_apu_queue_size++;
    }
    *w0 = g_apu_write;
    memset(&g_apu_write, 0xff, sizeof(g_apu_write));
  } else {
    g_apu_queue_size = 0;
  }
  RtlApuUnlock();
}

static void RtlPopApuState_Locked(void) {
  if (is_uploading_apu)
    return;

  uint8 *input_ports = g_use_my_apu_code ? g_spc_player->input_ports : g_snes->apu->inPorts;
  if (g_apu_queue_size != 0) {
    ApuWriteEnt *w = &g_apu_write_ents[(g_apu_write_ent_pos - g_apu_queue_size--) & (kApuMaxQueueSize - 1)];
    for (int i = 0; i != 4; i++) {
      if (w->ports[i] != 255)
        input_ports[i] = w->ports[i];
    }
  }
}

static void RtlResetApuQueue(void) {
  g_apu_write_ent_pos = g_apu_time_since_empty = g_apu_queue_size = 0;
  memset(&g_apu_write, 0xff, sizeof(g_apu_write));
}

void RtlApuUpload(const uint8 *p) {
  RtlApuLock();
  RtlResetApuQueue();
  SpcPlayer_Upload(g_spc_player, p);
  RtlApuUnlock();
}

void RtlRestoreMusicAfterLoad_Locked(bool is_reset) {
  if (g_use_my_apu_code) {
    memcpy(g_spc_player->ram, g_snes->apu->ram, 65536);
    memcpy(g_spc_player->dsp->ram, g_snes->apu->dsp->ram, sizeof(Dsp) - offsetof(Dsp, ram));
    SpcPlayer_CopyVariablesFromRam(g_spc_player);
  }

  if (is_reset) {
    SpcPlayer_Initialize(g_spc_player);
  }

  RtlResetApuQueue();
}

void RtlSaveMusicStateToRam_Locked(void) {
  if (g_use_my_apu_code) {
    // Apply the whole contents of the queue to input ports
    SpcPlayer *spc_player = g_spc_player;
    for (int i = g_apu_queue_size; i; i--) {
      ApuWriteEnt *we = &g_apu_write_ents[(g_apu_write_ent_pos - i) & (kApuMaxQueueSize - 1)];
      for (int j = 0; j < 4; j++) {
        if (we->ports[j] != 255)
          spc_player->input_ports[j] = we->ports[j];
      }
    }
    SpcPlayer_CopyVariablesToRam(g_spc_player);
    memcpy(g_snes->apu->dsp->ram, g_spc_player->dsp->ram, sizeof(Dsp) - offsetof(Dsp, ram));
    memcpy(g_snes->apu->ram, g_spc_player->ram, 65536);
  }
}

void RtlRenderAudio(int16 *audio_buffer, int samples, int channels) {
  assert(channels == 2);
  RtlApuLock();

  RtlPopApuState_Locked();

  if (!g_use_my_apu_code) {
    if (!is_uploading_apu) {
      while (g_snes->apu->dsp->sampleOffset < 534)
        apu_cycle(g_snes->apu);
      dsp_getSamples(g_snes->apu->dsp, audio_buffer, samples);
    }
  } else {
    SpcPlayer_GenerateSamples(g_spc_player);
    dsp_getSamples(g_spc_player->dsp, audio_buffer, samples);
    MixInMsuAudioData(audio_buffer, samples);
  }

  RtlApuUnlock();
}

void RtlCheat(char c) {
  if (c == 'w') {
    samus_health = samus_max_health;
    StateRecorder_RecordPatchByte(&state_recorder, 0x9C2, (uint8 *)&samus_health, 2);
  } else if (c == 'q') {
    samus_y_pos -= 4;
    samus_y_speed = -8;
    StateRecorder_RecordPatchByte(&state_recorder, 0xafa, (uint8 *)&samus_y_pos, 2);
    StateRecorder_RecordPatchByte(&state_recorder, 0xb2e, (uint8 *)&samus_y_speed, 2);
    menu_index = 0;
  } else if (c == 'q') {
    japanese_text_flag = !japanese_text_flag;
    StateRecorder_RecordPatchByte(&state_recorder, 0x9e2, (uint8 *)&japanese_text_flag, 2);
  }
}

void RtlReadSram(void) {
  FILE *f = fopen("saves/sm.srm", "rb");
  if (f) {
    if (fread(g_sram, 1, 8192, f) != 8192)
      fprintf(stderr, "Error reading saves/sm.srm\n");
    fclose(f);
    RtlSynchronizeWholeState();
    ByteArray_Resize(&state_recorder.base_snapshot, 8192);
    memcpy(state_recorder.base_snapshot.data, g_sram, 8192);
  }
}

void RtlWriteSram(void) {
  rename("saves/sm.srm", "saves/sm.srm.bak");
  FILE *f = fopen("saves/sm.srm", "wb");
  if (f) {
    fwrite(g_sram, 1, 8192, f);
    fclose(f);
  } else {
    fprintf(stderr, "Unable to write saves/sm.srm\n");
  }
}

/*
*   MSU1 Code
*   HandleMusicQueue() calls PlayMsuAudioTrack(), which calls OpenMsuFile()
*   MixInMsuAudioData() is called by RtlRenderAudio
*   The MSU1 track indices don't line up with the game's track indices,
*   so a special table must be used to get the correct MSU1 track (see the readme for the MSU1 patch)
*/

//MSU1 variables
static uint32 msu_curr_sample0;
static uint8 msu_volume0;
static uint8 msu_track0;

#define msu_curr_sample (*(uint32*)(g_ram+0xF500))
#define msu_volume (*(uint8*)(g_ram+0xF504))
#define msu_track (*(uint8*)(g_ram+0xF505))

bool msu_enabled;
static FILE *msu_file;
static uint32 msu_loop_start;
static uint32 msu_buffer_size;
static uint32 msu_buffer_pos;
static uint8  msu_buffer[0xFFFF + 1];

static const uint8 kMsuTracksWithRepeat[] = {
  1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0,
};

//format is [track bank][song entry] 
static const uint8 kMsuTrackIndices[25][4] ={
  [0]  = { 4, 5 },         [1] = { 4, 5 },    [2] = { 6, 0, 7 },     [3] = { 8, 9 },       [4] = { 10 },
  [5]  = { 11 },           [6] = { 12 },      [7] = { 13 },          [8] = { 14 },         [9] = { 15, 16 },
  [10] = { 17, 0 },       [11] = { 18 },     [12] = { 19, 21, 20 }, [13] = { 22, 23 },    [14] = { 24 },
  [15] = { 0, 25, 0, 0 }, [16] = { 26, 27 }, [17] = { 0, 0, 0 },    [18] = { 28 },        [19] = { 29 },
  [20] = { 30 },          [21] = { 0 },      [22] = { 0 },          [23] = { 22, 23, 0 }, [24] = { 10 },
};

void PlayMsuAudioTrack() {
  if (!msu_enabled || (music_track_index == 4)) {   //if msu is not enabled, disable msu and write to APU as normal
    msu_track = 0;
    RtlApuWrite(APUIO0, music_track_index);
    return;
  }

  //RtlApuLock();
  if (music_track_index != 0) {  //if playing a song that isn't the pre-statue hall, set the msu track to the spc track, set msu to max volume, clear msu sample
    if (cur_music_track == music_track_index) {  //if the msu track hasn't changed, do nothing
      return;
    }
    else if (music_track_index < 5) {  //if the music entry is track 1, 2, or 3, then set the msu track
      msu_track = music_entry & 0x7F;
    }
    else  {
      uint8 msu_track_bank = (music_data_index & 0x7F) / 3;
      uint8 msu_track_index = music_track_index - 5;
      msu_track = kMsuTrackIndices[msu_track_bank][msu_track_index];
    }
    msu_volume = 100;
    msu_curr_sample = 0;
    OpenMsuFile();
  }
  if (msu_file == NULL || msu_track == 0) {  //if there is no msu file, disable msu and write to APU as normal
    msu_track = 0;
    RtlApuWrite(APUIO0, music_track_index);
    return;
  }

  RtlApuWrite(APUIO0, 0x0); //don't play the spc
  //RtlApuUnlock();
};

void OpenMsuFile() {
  if (msu_file) {       //if there is an msu file being played, then clear the msu file stream
    fclose(msu_file);
    msu_file = NULL;
  }
  if (msu_track == 0) { //if there is no song being played, then return
      return;
  }

  char buf[40], hdr[8];
  snprintf(buf, sizeof(buf), "msu/supermetroid_msu1-%d.pcm", msu_track); //transfer the msu file location into a buffer
  msu_file = fopen(buf, "rb");  //open the msu track as "read binary file" from the buffer
  if (msu_file == NULL || fread(hdr, 1, 8, msu_file) != 8 || *(uint32*)(hdr + 0) != (('1' << 24) | ('U' << 16) | ('S' << 8) | 'M') ) {   //if the msu file does not exist, or if the msu_file header is not 8, or does not contain the string "MSU1"
    if (msu_file != NULL) { //if the msu file does not exist, then close it and set to null
      fclose(msu_file);
      msu_file = NULL;
    }
    RtlApuWrite(APUIO0, msu_track); //write the msu track to audio and reset the msu track
    msu_track = 0;
    return;
  }

  if (msu_curr_sample != 0) {   //if in the middle of a track, set the msu file pointer to the beginning, offset by the current sample * 4 + 8
    fseek(msu_file, msu_curr_sample * 4 + 8, SEEK_SET);
  }
  msu_loop_start = *(uint32*)(hdr + 4); //set the start of the loop to after the msu1 header
  msu_buffer_size = msu_buffer_pos = 0; //initalize the msu file size and position
};

void MixInMsuAudioData(int16* audio_buffer, int audio_samples) {
  if (msu_file == NULL || msu_volume == 0 || msu_track == 0) {   //if the msu is not playing or is muted then return
    return;
  }
  if (msu_volume == 0) {    //if the msu is muted, then return
    return;
  }

  int last_audio_samples = 0;
  while (true) {
    if (msu_buffer_pos >= msu_buffer_size) {    //if the msu exceeds the size of the buffer, set the size to the most recent buffer and reset the buffer size
        msu_buffer_size = (int)fread(msu_buffer, 4, sizeof(msu_buffer) / 4, msu_file);
        msu_buffer_pos = 0;
    }

    int nr = IntMin(audio_samples, msu_buffer_size - msu_buffer_pos);   //get the minimum of the amount of input samples and the remaining number of msu samples
    uint8* buf = msu_buffer + msu_buffer_pos * 4; //get a pointer to the msu buffer at the current position
    msu_buffer_pos += nr;   //go to the next sample
    msu_curr_sample += nr;

    int volume = msu_volume + 1;
    if (volume == 256) {
      for (int i = 0; i < nr; i++) {    //copy the msu audio buffer to the real audio buffer
        audio_buffer[i * 2 + 0] += ((int16*)buf)[i * 2 + 0];
        audio_buffer[i * 2 + 1] += ((int16*)buf)[i * 2 + 1];
      }
    }
    else {
      for (int i = 0; i < nr; i++) {    //clear the real audio buffer
        audio_buffer[i * 2 + 0] += ((int16*)buf)[i * 2 + 0] * volume >> 8;
        audio_buffer[i * 2 + 1] += ((int16*)buf)[i * 2 + 1] * volume >> 8;
      }
    }

    audio_samples -= nr;    //decrease the amount of real samples
    audio_buffer += nr * 2; //put the buffer to the next sample
    if (audio_samples == 0) {   //if done playing every sample, then exit
      break;
    }
    if (nr != 0) {  //if there are more samples, then continue playing them 
      continue;
    }

    if (last_audio_samples == audio_samples) {  //handle an error
      RtlApuWrite(APUIO0, msu_track);
      fclose(msu_file);
      msu_file = NULL;
      return;
    }
    last_audio_samples = audio_samples;

    if (!kMsuTracksWithRepeat[msu_track]) { //if the track does not repeat, then stop playing the music
      fclose(msu_file);
      msu_file = NULL;
      return;
    }
    fseek(msu_file, msu_loop_start * 4 + 8, SEEK_SET);  //repeat the track at the loop point
    msu_curr_sample = msu_loop_start;
  }
};

/**
* @brief Transfers the data in RAM to VRAM
* @param dstv The address of VRAM to write to
* @param src The source of the data
* @param len The size of the data to transfer
* @param inc The amount to increment the VRAM address by
*/
void CopyToVram(uint32 dstv, const void* src, int len, int inc) {
  //MemCpy(&g_snes->ppu->vram[dstv], src, len);
  const uint16 *p = src;
  int offset = 0;
  for (int i = 0; i < len/2; i++) {
    g_snes->ppu->vram[dstv + offset] = *p;
    p++;
    offset += inc;
  }
}

/**
* @brief Transfers the data in VRAM to RAM
* @param srcv The address of VRAM to read from
* @param dst The destination to write to
* @param len The size of the data to transfer
* @param inc The amount to increment the VRAM address by
*/
void CopyFromVram(uint32 srcv, void* dst, int len, int inc) {
  //MemCpy(src, &g_snes->ppu->vram[dstv], len);
  uint16 *p = dst;
  int offset = 0;
  for (int i = 0; i < len/2; i++) {
    *p = g_snes->ppu->vram[srcv + offset];
    p++;
    offset += inc;
  }
}

/**
* @brief Sets the memory in VRAM to val
* @param dstv The address of VRAM to write to
* @param val The value to write
* @param len The size of the data to transfer
* @param inc The amount to increment the VRAM address by, 8 sets high byte, 4 sets low byte
*/
void MemSetVram(uint32 dstv, int val, int len, int inc) {
  //memset(dstv, val, len);
  int offset = 0;
  for (int i = 0; i < len/2; i++) {
    if (inc & 8)
      HIBYTE(g_snes->ppu->vram[dstv + offset]) = val;
    if (inc & 4)
      LOBYTE(g_snes->ppu->vram[dstv + offset]) = val;
    offset += (inc & ~12);
  }
}
