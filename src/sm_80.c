// System routines 

#include "sm_rtl.h"
#include "ida_types.h"
#include "variables.h"
#include "funcs.h"
#include "enemy_types.h"
#include "spc_player.h"
#include "sm_80.h"


/**
* @brief Uploads the song to the SPC player
* @param addr The address of the song
*/
void APU_UploadBank(uint32 addr) {  // 0x808028
  if (!g_use_my_apu_code)
    return;
  RtlApuUpload(RomPtr(addr));
}

/**
* @brief Generates a random number
* @return uint16 The random number
*/
uint16 NextRandom(void) {  // 0x808111
  uint16 RegWord = LOBYTE(random_number) * 5;
  uint8 Reg = HIBYTE(random_number) * 5;

  int carry = HIBYTE(RegWord) + Reg + 1;
  HIBYTE(RegWord) = carry;
  uint16 result = (carry >> 8) + RegWord + 17;
  random_number = result;
  return result;
}

/**
* @brief Updates the held input and the held input timer
* @param uint16 The time until the held input timer will reset
*/
void ReleaseButtonsFilter(uint16 time) {  // 0x808146
  timed_held_input_timer_reset = time;
  bool same_input = ((uint16)~joypad1_newkeys & joypad1_lastkeys) == joypad_released_keys;
  joypad_released_keys = ~joypad1_newkeys & joypad1_lastkeys;
  if (!same_input) {
    timed_held_input_timer = timed_held_input_timer_reset;
    timed_held_input = 0;
  }
  else if ((int16)--timed_held_input_timer >= 0) {
    timed_held_input = 0;
  }
  else {
    timed_held_input_timer = 0;
    previous_timed_held_input = timed_held_input;
    timed_held_input = ~joypad1_newkeys & joypad1_lastkeys;
  }
  newly_held_down_timed_held_input = timed_held_input & (previous_timed_held_input ^ timed_held_input);
}

/**
* @brief Changes the bit index to a byte index and bitmasks
* @param bit_index The amount to shift by
* @return uint16 The index of the byte
*/
uint16 PrepareBitAccess(uint16 bit_index) {  // 0x80818E
  bitmask = 1 << (bit_index & 7);
  return bit_index >> 3;
}

/**
* @brief Sets the boss bits for the current area
* @param boss_bits The type of boss to set
*/
void SetBossBitForCurArea(uint16 boss_bits) {  // 0x8081A6
  boss_bits_for_area[area_index] |= boss_bits;
}

/**
* @brief Resets the boss bits for the current area, unused
* @param boss_bits The type of boss to reset
*/
void ClearBossBitForCurArea_UNUSED(uint16 boss_bits) {  // 0x8081C0
  boss_bits_for_area[area_index] &= ~boss_bits;
}

/**
* @brief Checks if the current area's boss bits matches the incoming boss bits
* @param boss_bits The type of boss to check for
* @return true if they match, false if they don't match
*/
bool CheckBossBitForCurArea(uint16 boss_bits) {  // 0x8081DC
  return (boss_bits & boss_bits_for_area[area_index]) != 0;
}

/**
* @brief Sets the event that is passed in
* @param event_number The event being set
*/
void SetEventHappened(uint16 event_number) {  // 0x8081FA
  uint16 event_index = PrepareBitAccess(event_number);
  events_that_happened[event_index] |= bitmask;
}

/**
* @brief Resets the event that is passed in
* @param event_number The event being reset
*/
void ClearEventHappened(uint16 event_number) {  // 0x808212
  uint16 event_index = PrepareBitAccess(event_number);
  events_that_happened[event_index] &= ~bitmask;
}

/**
* @brief Checks if the event being passed in has happened already
* @param event_number The event being checked for
* @return true if the event happened, false if the event hasn't happened
*/
bool CheckEventHappened(uint16 event_number) {  // 0x808233
  uint16 event_index = PrepareBitAccess(event_number);
  return (bitmask & events_that_happened[event_index]) != 0;
}

/**
* @brief Writes "supermetroid" to RAM after the credits
*/
void CopySuperMetroidString(void) {  // 0x80824F
  memcpy(&g_sram[0x1fe0], "supermetroid", 12);
  RtlWriteSram();
}

/**
* @brief Checks whether the SRAM is corrupted and writes it to RAM
*/
void VerifySRAM(void) {  // 0x808261
  num_demo_sets = 3;
  // If all 3 saves are corrupted
  if (LoadFromSram(0) && LoadFromSram(1) && LoadFromSram(2)) {
    char corrupted_save[] = "madadameyohn";
    memcpy(&g_sram[0x1fe0], corrupted_save, 12);
    RtlWriteSram();
  }
  else {
    // If the game has been beaten before, add the final demo set
    if (!memcmp(&g_sram[0x1fe0], "supermetroid", 12))
      num_demo_sets = 4;
  }
}

/**
* @brief Multiplies two unsigned 16 bit integers
* @param a, j The two 16 bit integers to multiply
* @return result The 32 bit result of the multiplication
*/
uint32 Multiply16x16(uint16 a, uint16 j) {  // 0x8082D6
  uint32 result = (uint32)a * (uint32)j;
  return result;
}

/**
* @brief Waits for non-maskable interrupt to finish
* @return true if waiting for the interrupt, false if it's finished
*/
CoroutineRet WaitForNMI_Async(void) {  // 0x808338
  // Return 0 from this routine as soon as the coroutine has finished
  if (coroutine_completion_flags) {
    coroutine_completion_flags = 0;
    return 0;
  }
  waiting_for_nmi = 1;
  coroutine_completion_flags = 1;
  return 1;
}

/**
* @brief Waits for non-maskable interrupt to finish
* @brief Does not update the nmi flag
* @return true if waiting for the interrupt, false if it's finished
*/
CoroutineRet WaitForNMI_NoUpdate_Async(void) {
  // Return 0 from this routine as soon as the coroutine has finished
  if (coroutine_completion_flags) {
    coroutine_completion_flags = 0;
    return 0;
  }
  coroutine_completion_flags = 1;
  return 1;
}

/**
* @brief Enable non-maskable interrupt
*/
void EnableNMI(void) {  // 0x80834B
  uint8 nmi_backup = reg_NMITIMEN | kNmi_Enable;
  WriteReg(NMITIMEN, nmi_backup);
  reg_NMITIMEN = nmi_backup;
}

/**
* @brief Disable non-maskable interrupt
*/
void DisableNMI(void) {  // 0x80835D
  uint8 nmi_backup = reg_NMITIMEN & ~(kNmi_Enable);
  WriteReg(NMITIMEN, nmi_backup);
  reg_NMITIMEN = nmi_backup;
}

/**
* @brief Sets the force blank by turning off screen
*/
void ScreenOff(void) {  // 0x80836F
  reg_INIDISP |= 0x80;
}

/**
* @brief Clears the force blank by turning on screen
*/
void ScreenOn(void) {  // 0x808382
  reg_INIDISP &= ~0x80;
}

/**
* @brief Sets size bytes of the destination to value
* @param *dst The destination to write to
* @param value The 16 bit integer to write
* @param size The amount in bytes to write
*/
void memset7E(uint16 *dst, uint16 value, uint16 size) {  // 0x8083F6
  do {
    *dst++ = value;
  } while (size -= 2);
}

/**
* @brief The initial boot section of the code
*/
CoroutineRet Vector_RESET_Async(void) {  // 0x80841C
  COROUTINE_BEGIN(coroutine_state_0, 1)
  WriteReg(MEMSEL, 1);
  reg_MEMSEL = 1;
  // Removed code to wait 4 frames
  uint16 bak = bug_fix_counter;
  memset(g_ram, 0, 8192);
  bug_fix_counter = bak;
  COROUTINE_AWAIT(2, InitializeIoDisplayLogo_Async());

  COROUTINE_MANUAL_POS(3); // Soft reset position
  APU_UploadBank(0xCF8000);
  WriteReg(INIDISP, 0x8F);
  bak = bug_fix_counter;
  memset(g_ram, 0, 0x10000);
  bug_fix_counter = bak;
  WriteReg(NMITIMEN, 0);
  reg_NMITIMEN = 0;
  reg_INIDISP = 0x8f;
  InitializeCpuIoRegs();
  InitializePpuIoRegs();
  WriteLotsOf0x1c2f();
  sfx_readpos[0] = 0;
  sfx_readpos[1] = 0;
  sfx_readpos[2] = 0;
  sfx_writepos[0] = 0;
  sfx_writepos[1] = 0;
  sfx_writepos[2] = 0;
  sfx_state[0] = 0;
  sfx_state[1] = 0;
  sfx_state[2] = 0;
  sfx_cur[0] = 0;
  sfx_cur[1] = 0;
  sfx_cur[2] = 0;
  sfx_clear_delay[0] = 0;
  sfx_clear_delay[1] = 0;
  sfx_clear_delay[2] = 0;
  sfx1_queue[0] = 0;
  sfx2_queue[0] = 0;
  sfx3_queue[0] = 0;
  oam_next_ptr = 0;
  reg_OAMaddr_UNUSED = 0;
  ClearOamExt();
  ClearUnusedOam();
  nmi_copy_samus_halves = 0;
  nmi_copy_samus_top_half_src = 0;
  nmi_copy_samus_bottom_half_src = 0;
  EnableNMI();
  RtlApuWrite(APUIO0, 0);
  RtlApuWrite(APUIO2, 0);

  // Removed code to wait 4 frames
  random_number = 97;
  music_timer = 0;
  music_queue_delay[0] = 0;
  music_queue_delay[1] = 0;
  music_queue_delay[2] = 0;
  music_queue_delay[3] = 0;
  music_queue_delay[4] = 0;
  music_queue_delay[5] = 0;
  music_queue_delay[6] = 0;
  music_queue_delay[7] = 0;
  enable_debug = 0;
  VerifySRAM();
  disable_sounds = 0;
  sound_handler_downtime = 0;
  COROUTINE_END(2);
}

/**
* @brief Handles an error by crashing the game
*/
void InvalidInterrupt_Crash(void) {  // 0x808573
  printf("InvalidInterrupt_Crash\n");
  Unreachable();
  for (;;);
}

/**
* @brief Restores the explored map tiles
*/
void LoadMirrorOfExploredMapTiles(void) {  // 0x80858C
  uint16 area_offset = swap16(area_index);
  MemCpy(map_tiles_explored, &explored_map_tiles_saved[area_offset >> 1], 256);
  has_area_map = map_station_byte_array[area_index];
}

/**
* @brief Backs up the explored map tiles
*/
void SaveExploredMapTilesToSaved(void) {  // 0x8085C6
  uint16 area_offset = swap16(area_index);
  MemCpy(&explored_map_tiles_saved[area_offset >> 1], map_tiles_explored, 256);
  if (has_area_map)
    WORD(map_station_byte_array[area_index]) |= 0xFF;
}

/**
* @brief Sets up the CPU registers from boot
*/
void InitializeCpuIoRegs(void) {  // 0x80875D
  WriteReg(NMITIMEN, 1);
  reg_NMITIMEN = 1;
  WriteReg(WRIO, 0);
  WriteReg(WRMPYA, 0);
  WriteReg(WRMPYB, 0);
  WriteReg(WRDIVL, 0);
  WriteReg(WRDIVH, 0);
  WriteReg(WRDIVB, 0);
  WriteReg(HTIMEL, 0);
  WriteReg(HTIMEH, 0);
  WriteReg(VTIMEL, 0);
  WriteReg(VTIMEH, 0);
  WriteReg(MDMAEN, 0);
  WriteReg(HDMAEN, 0);
  reg_HDMAEN = 0;
  WriteReg(MEMSEL, 1);
  reg_MEMSEL = 1;
}

/**
* @brief Sets up the PPU registers from boot
*/
void InitializePpuIoRegs(void) {  // 0x808792
  WriteReg(INIDISP, 0x8F);
  reg_INIDISP = 0x8f;
  WriteReg(OBSEL, 3);
  reg_OBSEL = 3;
  WriteReg(OAMADDL, 0);
  LOBYTE(reg_OAMaddr_UNUSED) = 0;
  WriteReg(OAMADDH, 0x80);
  HIBYTE(reg_OAMaddr_UNUSED) = 0x80;
  WriteReg(OAMDATA, 0);
  WriteReg(OAMDATA, 0);
  WriteReg(BGMODE, 9);
  reg_BGMODE = 9;
  WriteReg(MOSAIC, 0);
  reg_MOSAIC = 0;
  WriteReg(BG1SC, 0x40);
  reg_BG1SC = 64;
  WriteReg(BG2SC, 0x44);
  reg_BG2SC = 68;
  WriteReg(BG3SC, 0x48);
  reg_BG3SC = 72;
  WriteReg(BG4SC, 0);
  reg_BG4SC = 0;
  WriteReg(BG12NBA, 0);
  reg_BG12NBA = 0;
  WriteReg(BG34NBA, 5);
  reg_BG34NBA = 5;
  WriteReg(BG1HOFS, 0);
  WriteReg(BG1HOFS, 0);
  WriteReg(BG1VOFS, 0);
  WriteReg(BG1VOFS, 0);
  WriteReg(BG2HOFS, 0);
  WriteReg(BG2HOFS, 0);
  WriteReg(BG2VOFS, 0);
  WriteReg(BG2VOFS, 0);
  WriteReg(BG3HOFS, 0);
  WriteReg(BG3HOFS, 0);
  WriteReg(BG3VOFS, 0);
  WriteReg(BG3VOFS, 0);
  WriteReg(BG4HOFS, 0);
  WriteReg(BG4HOFS, 0);
  WriteReg(BG4VOFS, 0);
  WriteReg(BG4VOFS, 0);
  WriteReg(VMAIN, 0);
  WriteReg(M7SEL, 0);
  reg_M7SEL = 0;
  WriteReg(M7A, 0);
  WriteReg(M7B, 0);
  WriteReg(M7C, 0);
  WriteReg(M7D, 0);
  WriteReg(M7X, 0);
  WriteReg(M7Y, 0);
  WriteReg(W12SEL, 0);
  reg_W12SEL = 0;
  WriteReg(W34SEL, 0);
  reg_W34SEL = 0;
  WriteReg(WOBJSEL, 0);
  reg_WOBJSEL = 0;
  WriteReg(WH0, 0);
  reg_WH0 = 0;
  WriteReg(WH1, 0xF8);
  reg_WH1 = -8;
  WriteReg(WH2, 0);
  reg_WH2 = 0;
  WriteReg(WH3, 0);
  reg_WH3 = 0;
  WriteReg(WBGLOG, 0);
  reg_WBGLOG = 0;
  WriteReg(WOBJLOG, 0);
  reg_WOBJLOG = 0;
  WriteReg(TM, 0x11);
  reg_TM = 17;
  WriteReg(TMW, 0x11);
  reg_TMW = 17;
  WriteReg(TS, 2);
  reg_TS = 2;
  WriteReg(TSW, 2);
  reg_TSW = 2;
  WriteReg(CGWSEL, 2);
  next_gameplay_CGWSEL = 2;
  WriteReg(CGADSUB, 0xA1);
  next_gameplay_CGADSUB = -95;
  WriteReg(COLDATA, 0xE0);
  WriteReg(COLDATA, 0xE0);
  WriteReg(COLDATA, 0x80);
  reg_COLDATA[0] = 0x80;
  WriteReg(COLDATA, 0x40);
  reg_COLDATA[1] = 64;
  WriteReg(COLDATA, 0x20);
  reg_COLDATA[2] = 32;
  WriteReg(SETINI, 0);
  reg_SETINI = 0;
}

/**
* @brief Writes 0x1C2F to various RAM from boot
*/
void WriteLotsOf0x1c2f(void) {  // 0x8088D1
  Write0x800BytesToRam3000(0x1C2F);
  Write0x800BytesToRam4000(0x1C2F);
  Write0x800BytesToRam6000(0x1C2F);
}

/**
* @brief Writes 0x800 bytes of value to RAM 0x3000
* @param value The value to write
*/
void Write0x800BytesToRam3000(uint16 value) {  // 0x8088EB
  memset7E((uint16*)(g_ram + 0x3000), value, 0x800);
}

/**
* @brief Writes 0x800 bytes of value to RAM 0x4000
* @param value The value to write
*/
void Write0x800BytesToRam4000(uint16 value) {  // 0x8088FE
  memset7E((uint16 *)(g_ram + 0x4000), value, 0x800);
}

/**
* @brief Writes 0x800 bytes of value to RAM 0x6000
* @param value The value to write
*/
void Write0x800BytesToRam6000(uint16 value) {  // 0x808911
  memset7E((uint16 *)(g_ram + 0x6000), value, 0x800);
}

/**
* @brief Continuously decrements the brightness when the screen fade counter is 0
*/
void HandleFadeOut(void) {  // 0x808924
  if (screen_fade_counter < 1) {
    screen_fade_counter = screen_fade_delay;
    // Brightness values range from 1 to 15
    uint16 brightness = reg_INIDISP & 0xF;
    if (brightness != 0) {
      if (brightness == 1)
        reg_INIDISP = 0x80;
      else
        reg_INIDISP = brightness - 1;
    }
  } else {
    --screen_fade_counter;
  }
}

/**
* @brief Continuously increments the brightness when the screen fade counter is 0
*/
void HandleFadeIn(void) {  // 0x80894D
  if (screen_fade_counter < 1) {
    screen_fade_counter = screen_fade_delay;
    // Brightness values range from 1 to 15
    uint16 brightness = (reg_INIDISP + 1) & 0xF;
    if (brightness != 0)
      reg_INIDISP = brightness;
  } else {
    --screen_fade_counter;
  }
}

/**
* @brief Clears all unused sprites and resets the OAM stack pointer
*/
void ClearUnusedOam(void) {  // 0x80896E
  for (int i = oam_next_ptr >> 2; i < 0x80; i++)
    oam_ent[i].ycoord = 0xf0;
  oam_next_ptr = 0;
}

/**
* @brief Clears the high OAM
*/
void ClearOamExt(void) {  // 0x808B1A
  memset(oam_ext, 0, sizeof(oam_ext[0]) * 16);
}

/**
* @brief Writes the entries of the Mode 7 transfer data to RAM
* @param db The bank of the Mode 7 transfer data
* @param addr The address of the Mode 7 transfer data
*/
void QueueMode7Transfers(uint8 db, uint16 addr) {  // 0x808B4F
  uint16 vram_entry_size = sizeof(Mode7VramWriteQueue);
  uint16 cgram_entry_size = sizeof(Mode7CgramWriteQueue);

  const uint8 *src = RomPtrWithBank(db, addr);
  uint8 *dst = (uint8 *)mode7_write_queue + mode7_vram_write_queue_tail;
  for (;;) {
    int transfer_mode = GET_BYTE(src);
    if (transfer_mode & VRAM_WRITE) {
      dst[9] = 0;
      memcpy(dst, src, vram_entry_size);
      src += vram_entry_size, dst += vram_entry_size;
    }
    // Mode 7 CGRAM transfers are never used in game
    else if (transfer_mode & CGRAM_WRITE) {
      dst[7] = 0;
      memcpy(dst, src, cgram_entry_size);
      src += cgram_entry_size, dst += cgram_entry_size;
    }
    else {
      break;
    }
  }
  mode7_vram_write_queue_tail = dst - (uint8 *)mode7_write_queue;
}

/**
* @brief Handles pending Mode 7 transfers
*/
void NMI_ProcessMode7Queue(void) {  // 0x808BBA
  if (mode7_vram_write_queue_tail != 0) {
    NMI_ProcessMode7QueueInner((uint8 *)mode7_write_queue);
    WORD(mode7_write_queue[0].control) = 0;
    mode7_vram_write_queue_tail = 0;
  }
}

/**
* @brief Proccesses the Mode 7 transfers
* @param *p The pointer to the Mode 7 transfers
*/
void NMI_ProcessMode7QueueInner(const uint8 *p) {  // 0x808BD3
  while (1) {
    uint8 transfer_mode;
    while (1) {
      transfer_mode = *p;
      if (!(transfer_mode & VRAM_WRITE))
        break;
      WriteReg(DMAP1, transfer_mode & 0x1F);
      Mode7VramWriteQueue *vram_entry = (Mode7VramWriteQueue *)p;
      WriteRegWord(A1T1L, vram_entry->src_addr.addr);
      WriteReg(A1B1, vram_entry->src_addr.bank);
      WriteRegWord(DAS1L, vram_entry->count);
      if (transfer_mode & VRAM_WRITE_TILES)
        WriteReg(BBAD1, 0x19);
      else /* (transfer_mode & VRAM_WRITE_TILEMAP) */
        WriteReg(BBAD1, 0x18);
      WriteRegWord(VMADDL, vram_entry->vram_addr);
      WriteReg(VMAIN, vram_entry->vmain);
      WriteReg(MDMAEN, 2);
      p += sizeof(Mode7VramWriteQueue);
    }
    // Mode 7 CGRAM transfers are never used in game
    if (!(transfer_mode & CGRAM_WRITE))
      break;
    WriteReg(DMAP1, transfer_mode & 0x1F);
    // @todo Properly do mode 7 cgram writes
    Mode7CgramWriteQueue* cgram_entry = (Mode7CgramWriteQueue *)p;
    WriteRegWord(A1T1L, cgram_entry->src_addr);
    WriteReg(A1B1, cgram_entry->gap3[0]);
    WriteRegWord(DAS1L, WORD(cgram_entry->gap3[1]));
    WriteReg(BBAD1, 0x22);
    WriteReg(CGADD, HIBYTE(cgram_entry->field_5));
    WriteReg(MDMAEN, 2);
    p += sizeof(Mode7CgramWriteQueue);
  }
}

/**
* @brief Handles the VRAM write table and scrolling DMAs
*/
void NMI_ProcessVramWriteQueue(void) {  // 0x808C83
  if (vram_write_queue_tail != 0) {
    gVramWriteEntry(vram_write_queue_tail)->size = 0;
    WriteRegWord(DMAP1, 0x1801);
    for (int i = 0; ; i += sizeof(VramWriteEntry)) {
      VramWriteEntry *vram_entry = gVramWriteEntry(i);
      if (vram_entry->size == 0)
        break;
      WriteRegWord(DAS1L, vram_entry->size);
      WriteRegWord(A1T1L, vram_entry->src.addr);
      WriteReg(A1B1, vram_entry->src.bank);
      WriteRegWord(VMAIN, sign16(vram_entry->vram_dst) ? 0x81 : 0x80);
      WriteRegWord(VMADDL, vram_entry->vram_dst);
      WriteReg(MDMAEN, 2);
    }
  }
  vram_write_queue_tail = 0;
  Nmi_ProcessHorizScrollingDma();
  Nmi_ProcessVertScrollingDma();
}

/**
* @brief Transfers the BG1 and BG2 horizontal scrolling tilemaps from RAM to VRAM
*/
void Nmi_ProcessHorizScrollingDma(void) {  // 0x808CD8
  uint16 vram_dst, size, *ram_src;

  if ((uint8)bg1_update_col_enable) {
    LOBYTE(bg1_update_col_enable) = 0;
    // Transfer bg1_update_col_unwrapped_size bytes
    // from bg1_column_update_tilemap_left_halves to VRAM bg1_update_col_unwrapped_dst
    vram_dst = bg1_update_col_unwrapped_dst;
    ram_src = bg1_column_update_tilemap_left_halves;
    size = bg1_update_col_unwrapped_size;
    CopyToVram(vram_dst, ram_src, size, 32);

    // Transfer bg1_update_col_unwrapped_size bytes 
    // from bg1_column_update_tilemap_right_halves to VRAM bg1_update_col_unwrapped_dst+1
    ram_src = bg1_column_update_tilemap_right_halves;
    CopyToVram(vram_dst+1, ram_src, size, 32);

    if (bg1_update_col_wrapped_size != 0) {
      // Transfer bg1_update_col_wrapped_size bytes 
      // from *bg1_update_col_wrapped_left_src to VRAM bg1_update_col_unwrapped_dst
      vram_dst = bg1_update_col_wrapped_dst;
      ram_src = (uint16*)(g_ram+bg1_update_col_wrapped_left_src);
      size = bg1_update_col_wrapped_size;
      CopyToVram(vram_dst, ram_src, size, 32);

      // Transfer bg1_update_col_wrapped_size bytes 
      // from *bg1_update_col_wrapped_right_src to VRAM bg1_update_col_unwrapped_dst+1
      ram_src = (uint16*)(g_ram+bg1_update_col_wrapped_right_src);
      CopyToVram(vram_dst+1, ram_src, size, 32);
    }
  }
  if ((uint8)bg2_update_col_enable) {
    LOBYTE(bg2_update_col_enable) = 0;
    // Transfer bg2_update_col_unwrapped_size bytes
    // from bg2_column_update_tilemap_left_halves to VRAM bg2_update_col_unwrapped_dst
    vram_dst = bg2_update_col_unwrapped_dst;
    size = bg2_update_col_unwrapped_size;
    ram_src = bg2_column_update_tilemap_left_halves;
    CopyToVram(vram_dst, ram_src, size, 32);

    // Transfer bg2_update_col_unwrapped_size bytes
    // from bg2_column_update_tilemap_right_halves to VRAM bg2_update_col_unwrapped_dst+1
    ram_src = bg2_column_update_tilemap_right_halves;
    CopyToVram(vram_dst+1, ram_src, size, 32);

    if (bg2_update_col_wrapped_size != 0) {
      // Transfer bg2_update_col_wrapped_size bytes
      // from bg2_update_col_wrapped_left_src to VRAM bg2_update_col_wrapped_dst
      vram_dst = bg2_update_col_wrapped_dst;
      ram_src = (uint16*)(g_ram+bg2_update_col_wrapped_left_src);
      size = bg2_update_col_wrapped_size;
      CopyToVram(vram_dst, ram_src, size, 32);

      // Transfer bg2_update_col_wrapped_size bytes
      // from bg2_update_col_wrapped_right_src to VRAM bg2_update_col_wrapped_dst+1
      ram_src = (uint16*)(g_ram+bg2_update_col_wrapped_right_src);
      CopyToVram(vram_dst+1, ram_src, size, 32);
    }
  }
}

/**
* @brief Transfers the BG1 and BG2 vertical scrolling tilemaps from RAM to VRAM
*/
void Nmi_ProcessVertScrollingDma(void) {  // 0x808DAC
  uint16 vram_dst, size, *ram_src;

  if ((uint8)bg1_update_row_enable) {
    LOBYTE(bg1_update_row_enable) = 0;
    // Transfer bg1_update_row_unwrapped_size bytes
    // from bg1_column_update_tilemap_top_halves to VRAM bg1_update_row_unwrapped_dst
    vram_dst = bg1_update_row_unwrapped_dst;
    ram_src = bg1_row_update_tilemap_top_halves;
    size = bg1_update_row_unwrapped_size;
    CopyToVram(vram_dst, ram_src, size, 1);

    // Transfer bg1_update_row_unwrapped_size bytes
    // from bg1_column_update_tilemap_bottom_halves to VRAM bg1_update_row_unwrapped_dst|0x20
    ram_src = bg1_row_update_tilemap_bottom_halves;
    CopyToVram(vram_dst|0x20, ram_src, size, 1);
    
    if (bg1_update_row_wrapped_size != 0) {
      // Transfer bg1_update_row_wrapped_size bytes
      // from bg1_update_row_wrapped_top_src to VRAM bg1_update_row_wrapped_dst
      vram_dst = bg1_update_row_wrapped_dst;
      ram_src = (uint16*)(g_ram+bg1_update_row_wrapped_top_src);
      size = bg1_update_row_wrapped_size;
      CopyToVram(vram_dst, ram_src, size, 1);

      // Transfer bg1_update_row_wrapped_size bytes
      // from bg1_update_row_wrapped_bottom_src to VRAM bg1_update_row_wrapped_dst|0x20
      ram_src = (uint16*)(g_ram+bg1_update_row_wrapped_bottom_src);
      CopyToVram(vram_dst|0x20, ram_src, size, 1);
    }
  }
  if ((uint8)bg2_update_row_enable) {
    LOBYTE(bg2_update_row_enable) = 0;
    // Transfer bg2_update_row_unwrapped_size bytes
    // from bg2_column_update_tilemap_top_halves to VRAM bg2_update_row_unwrapped_dst
    vram_dst = bg2_update_row_unwrapped_dst;
    ram_src = bg2_row_update_tilemap_top_halves;
    size = bg2_update_row_unwrapped_size;
    CopyToVram(vram_dst, ram_src, size, 1);

    // Transfer bg2_update_row_unwrapped_size bytes
    // from bg2_column_update_tilemap_bottom_halves to VRAM bg2_update_row_unwrapped_dst|0x20
    ram_src = bg2_row_update_tilemap_bottom_halves;
    CopyToVram(vram_dst|0x20, ram_src, size, 1);
    
    if (bg2_update_row_wrapped_size != 0) {
      // Transfer bg2_update_row_wrapped_size bytes
      // from bg2_update_row_wrapped_top_src to VRAM bg2_update_row_wrapped_dst
      vram_dst = bg2_update_row_wrapped_dst;
      ram_src = (uint16*)(g_ram+bg2_update_row_wrapped_top_src);
      size = bg2_update_row_wrapped_size;
      CopyToVram(vram_dst, ram_src, size, 1);

      // Transfer bg2_update_row_wrapped_size bytes
      // from bg2_update_row_wrapped_bottom_src to VRAM bg2_update_row_wrapped_dst|0x20
      ram_src = (uint16*)(g_ram+bg2_update_row_wrapped_bottom_src);
      CopyToVram(vram_dst|0x20, ram_src, size, 1);
    }
  }
}

/**
* @brief Handles the VRAM read table
*/
void NMI_ProcessVramReadQueue(void) {  // 0x808EA2
  if ((uint8)vram_read_queue_tail != 0) {
    *((uint8 *)&vram_read_queue[0].vram_target + (uint8)vram_read_queue_tail) = 0;
    WriteReg(VMAIN, 0x80);
    for (int table_index = 0; vram_read_queue[table_index].vram_target != 0; ++table_index) {
      WriteRegWord(VMADDL, vram_read_queue[table_index].vram_target);
      ReadRegWord(RDVRAML);
      WriteRegWord(DMAP1, vram_read_queue[table_index].dma_parameters);
      WriteRegWord(A1T1L, vram_read_queue[table_index].src.addr);
      WriteReg(A1B1, vram_read_queue[table_index].src.bank);
      WriteRegWord(DAS1L, vram_read_queue[table_index].size);
      WriteRegWord(DAS10, 0);
      WriteRegWord(A2A1H, 0);
      WriteReg(MDMAEN, 2);
    }
    LOBYTE(vram_read_queue_tail) = 0;
  }
}

/**
* @brief Checks if there's music in the queue
* @return uint8 true if there is music in the queue, false if there isn't music in the queue
*/
bool HasQueuedMusic(void) {  // 0x808EF4
  int queue_entry = 14;
  while (music_queue_delay[queue_entry >> 1] == 0) {
    queue_entry -= 2;
    if (queue_entry < 0)
      return false;
  }
  return true;
}

/**
* @brief Process music when the music timer runs out, uploads the music entry to the SPC player
* @brief Handles choosing original audio or MSU1 audio
*/
void HandleMusicQueue(void) {  // 0x808F0C
  uint16 read_index;

  if ((int16)--music_timer >= 0) {
    if (music_timer != 0)
      return;
    if (sign16(music_entry)) {
      music_data_index = (uint8)music_entry;
      cur_music_track = -1;
      uint32 music_track = DWORD(kMusicPointers[(uint8)music_data_index/sizeof(LongPtr)]);
      APU_UploadBank(music_track);
      cur_music_track = 0;
      read_index = music_queue_read_pos;
      music_queue_track[read_index >> 1] = 0;
      music_queue_delay[read_index >> 1] = 0;
      music_queue_read_pos = (read_index + 2) & 0xE;
      sound_handler_downtime = 8;
      return;
    }
    music_track_index = music_entry & 0x7F;
    // Handles whether to play the original track or MSU1 track
    PlayMsuAudioTrack();
    cur_music_track = music_track_index;
    sound_handler_downtime = 8;
    read_index = music_queue_read_pos;
    music_queue_track[read_index >> 1] = 0;
    music_queue_delay[read_index >> 1] = 0;
    music_queue_read_pos = (read_index + 2) & 0xE;
  }

  // If the music queue is empty
  if (music_queue_read_pos == music_queue_write_pos) {
    music_timer = 0;
  }
  else {
    read_index = music_queue_read_pos;
    music_entry = music_queue_track[read_index >> 1];
    music_timer = music_queue_delay[read_index >> 1];
  }
}

/**
* @brief Puts the music data or track into the queue with an 8 frame delay
* @brief Cannot set last queue entry
* @param music_select The music data or track to queue
*/
void QueueMusic_Delayed8(uint16 music_select) {  // 0x808FC1
  if (game_state < kGameState_40_TransitionToDemo && ((music_queue_write_pos + 2) & 0xE) != music_queue_read_pos) {
    uint16 write_index = music_queue_write_pos;
    music_queue_track[write_index >> 1] = music_select;
    music_queue_delay[write_index >> 1] = 8;
    music_queue_write_pos = (write_index + 2) & 0xE;
  }
}

/**
* @brief Puts the music data or track into the queue with a delay of max(delay, 8) frames
* @brief Can overwrite old entries
* @param music_select The music data or track to queue
* @param delay The amount of frames to delay by
*/
void QueueMusic_DelayedY(uint16 music_select, uint16 delay) {  // 0x808FF7
  if (game_state < kGameState_40_TransitionToDemo) {
    uint16 write_index = music_queue_write_pos;
    music_queue_track[write_index >> 1] = music_select;
    music_queue_delay[write_index >> 1] = IntMax(delay, 8);
    music_queue_write_pos = (write_index + 2) & 0xE;
  }
}

/**
* @brief Puts the sound effect from library 1 into the queue with a maximum of 15 sounds
* @param sound_effect The sound effect to queue
*/
void QueueSfx1_Max15(uint16 sound_effect) {  // 0x809021
  QueueSfx1_Internal(sound_effect << 8 | 15);
}

/**
* @brief Puts the sound effect from library 1 into the queue with a maximum of 9 sounds
* @param sound_effect The sound effect to queue
*/
void QueueSfx1_Max9(uint16 sound_effect) {  // 0x80902B
  QueueSfx1_Internal(sound_effect << 8 | 9);
}

/**
* @brief Puts the sound effect from library 1 into the queue with a maximum of 3 sounds
* @param sound_effect The sound effect to queue
*/
void QueueSfx1_Max3(uint16 sound_effect) {  // 0x809035
  QueueSfx1_Internal(sound_effect << 8 | 3);
}

/**
* @brief Puts the sound effect from library 1 into the queue with a maximum of 1 sound
* @param sound_effect The sound effect to queue
*/
void QueueSfx1_Max1(uint16 sound_effect) {  // 0x80903F
  QueueSfx1_Internal(sound_effect << 8 | 1);
}

/**
* @brief Puts the sound effect from library 1 into the queue with a maximum of 6 sounds
* @param sound_effect The sound effect to queue
*/
void QueueSfx1_Max6(uint16 sound_effect) {  // 0x809049
  QueueSfx1_Internal(sound_effect << 8 | 6);
}

/**
* @brief Puts the sound effect from library 2 into the queue
* @param sound The low byte is the max sound queue size and the high byte is the sound effect to queue
*/
void QueueSfx1_Internal(uint16 sound) {  // 0x809051
  uint8 max_queue_size = LOBYTE(sound);
  uint8 sound_effect = HIBYTE(sound);

  sfx_max_queued[0] = max_queue_size;
  if (((sfx_writepos[0] - sfx_readpos[0]) & 0xF) < max_queue_size
      && !disable_sounds
      && game_state < kGameState_40_TransitionToDemo
      && !(power_bomb_explosion_status & kPowerBombExplosionStatus_Active)) {
    uint8 curr_pos = sfx_writepos[0];
    uint8 next_pos = (curr_pos + 1) & 0xF;
    if (next_pos == sfx_readpos[0]) {
      sfx1_queue[curr_pos] = IntMin(sound_effect, sfx1_queue[curr_pos]);
    }
    else {
      sfx1_queue[curr_pos] = sound_effect;
      sfx_writepos[0] = next_pos;
      sfx1_queue[next_pos] = 0;
    }
  }
}

/**
* @brief Puts the sound effect from library 2 into the queue with a maximum of 15 sounds
* @param sound_effect The sound effect to queue
*/
void QueueSfx2_Max15(uint16 sound_effect) {  // 0x8090A3
  QueueSfx2_Internal(sound_effect << 8 | 15);
}

/**
* @brief Puts the sound effect from library 2 into the queue with a maximum of 9 sounds
* @param sound_effect The sound effect to queue
*/
void QueueSfx2_Max9(uint16 sound_effect) {  // 0x8090AD
  QueueSfx2_Internal(sound_effect << 8 | 9);
}

/**
* @brief Puts the sound effect from library 2 into the queue with a maximum of 3 sounds
* @param sound_effect The sound effect to queue
*/
void QueueSfx2_Max3(uint16 sound_effect) {  // 0x8090B7
  QueueSfx2_Internal(sound_effect << 8 | 3);
}

/**
* @brief Puts the sound effect from library 2 into the queue with a maximum of 1 sound
* @param sound_effect The sound effect to queue
*/
void QueueSfx2_Max1(uint16 sound_effect) {  // 0x8090C1
  QueueSfx2_Internal(sound_effect << 8 | 1);
}

/**
* @brief Puts the sound effect from library 2 into the queue with a maximum of 6 sounds
* @param sound_effect The sound effect to queue
*/
void QueueSfx2_Max6(uint16 sound_effect) {  // 0x8090CB
  QueueSfx2_Internal(sound_effect << 8 | 6);
}

/**
* @brief Puts the sound effect from library 2 into the queue
* @param sound The low byte is the max sound queue size and the high byte is the sound effect to queue
*/
void QueueSfx2_Internal(uint16 sound) {  // 0x8090D3
  uint8 max_queue_size = LOBYTE(sound);
  uint8 sound_effect = HIBYTE(sound);

  sfx_max_queued[1] = max_queue_size;
  if (((sfx_writepos[1] - sfx_readpos[1]) & 0xF) < max_queue_size
      && !disable_sounds
      && game_state < kGameState_40_TransitionToDemo
      && !(power_bomb_explosion_status & kPowerBombExplosionStatus_Active)) {
    uint8 curr_pos = sfx_writepos[1];
    uint8 next_pos = (curr_pos + 1) & 0xF;
    if (next_pos == sfx_readpos[1]) {
      sfx2_queue[curr_pos] = IntMin(sound_effect, sfx2_queue[curr_pos]);
    } 
    else {
      sfx2_queue[curr_pos] = sound_effect;
      sfx_writepos[1] = next_pos;
      sfx2_queue[next_pos] = 0;
    }
  }
}

/**
* @brief Puts the sound effect from library 3 into the queue with a maximum of 15 sounds
* @param sound_effect The sound effect to queue
*/
void QueueSfx3_Max15(uint16 sound_effect) {  // 0x809125
  QueueSfx3_Internal(sound_effect << 8 | 15);
}

/**
* @brief Puts the sound effect from library 3 into the queue with a maximum of 9 sounds
* @param sound_effect The sound effect to queue
*/
void QueueSfx3_Max9(uint16 sound_effect) {  // 0x80912F
  QueueSfx3_Internal(sound_effect << 8 | 9);
}

/**
* @brief Puts the sound effect from library 3 into the queue with a maximum of 3 sounds
* @param sound_effect The sound effect to queue
*/
void QueueSfx3_Max3(uint16 sound_effect) {  // 0x809139
  QueueSfx3_Internal(sound_effect << 8 | 3);
}

/**
* @brief Puts the sound effect from library 3 into the queue with a maximum of 1 sound
* @param sound_effect The sound effect to queue
*/
void QueueSfx3_Max1(uint16 sound_effect) {  // 0x809143
  QueueSfx3_Internal(sound_effect << 8 | 1);
}

/**
* @brief Puts the sound effect from library 3 into the queue with a maximum of 6 sounds
* @param sound_effect The sound effect to queue
*/
void QueueSfx3_Max6(uint16 sound_effect) {  // 0x80914D
  QueueSfx3_Internal(sound_effect << 8 | 6);
}

/**
* @brief Puts the sound effect from library 3 into the queue
* @param sound The low byte is the max sound queue size and the high byte is the sound effect to queue
*/
void QueueSfx3_Internal(uint16 sound) {  // 0x809155
  uint8 max_queue_size = LOBYTE(sound);
  uint8 sound_effect = HIBYTE(sound);

  sfx_max_queued[2] = max_queue_size;
  if (((sfx_writepos[2] - sfx_readpos[2]) & 0xF) < max_queue_size
      && !disable_sounds
      && game_state < kGameState_40_TransitionToDemo
      && !(power_bomb_explosion_status & kPowerBombExplosionStatus_Active)) {
    uint8 curr_pos = sfx_writepos[2];
    uint8 next_pos = (curr_pos + 1) & 0xF;
    if (next_pos == sfx_readpos[2]) {
      sfx3_queue[curr_pos] = IntMin(sound_effect, sfx3_queue[curr_pos]);
    }
    else {
      sfx3_queue[curr_pos] = sound_effect;
      sfx_writepos[2] = next_pos;
      sfx3_queue[next_pos] = 0;
    }
  }
}

/**
* @brief Sets up a DMA or HDMA transfer 
* @param dma_copy The transfer to set up
*/
void SetupDmaTransfer(const void *dma_copy) {  // 0x8091A9
  const StartDmaCopy *dma_src = (const StartDmaCopy *)dma_copy;
  int dma_channel = dma_src->chan * sizeof(StartDmaCopy) * 2;

  WriteRegWord((SnesRegs)(dma_channel + DMAP0), WORD(dma_src->dmap));
  WriteRegWord((SnesRegs)(dma_channel + A1T0L), dma_src->a1.addr);
  WriteReg((SnesRegs)(dma_channel + A1B0), dma_src->a1.bank);
  WriteRegWord((SnesRegs)(dma_channel + DAS0L), dma_src->das);
}

/**
* @brief Updates the IO registers
*/
void NmiUpdateIoRegisters(void) {  // 0x8091EE
  WriteReg(NMITIMEN, reg_NMITIMEN);
  WriteReg(INIDISP, reg_INIDISP);
  WriteReg(OBSEL, reg_OBSEL);
  WriteReg(BGMODE, reg_BGMODE);
  WriteReg(MOSAIC, reg_MOSAIC);
  WriteReg(BG1SC, reg_BG1SC);
  WriteReg(BG2SC, reg_BG2SC);
  WriteReg(BG3SC, reg_BG3SC);
  WriteReg(BG4SC, reg_BG4SC);
  WriteReg(BG12NBA, reg_BG12NBA);
  WriteReg(BG34NBA, reg_BG34NBA);
  WriteReg(M7SEL, reg_M7SEL);
  WriteReg(W12SEL, reg_W12SEL);
  WriteReg(W34SEL, reg_W34SEL);
  WriteReg(WOBJSEL, reg_WOBJSEL);
  WriteReg(WH0, reg_WH0);
  WriteReg(WH1, reg_WH1);
  WriteReg(WH2, reg_WH2);
  WriteReg(WH3, reg_WH3);
  WriteReg(WBGLOG, reg_WBGLOG);
  WriteReg(WOBJLOG, reg_WOBJLOG);
  gameplay_TM = reg_TM;
  WriteReg(TM, reg_TM);
  WriteReg(TMW, reg_TMW);
  WriteReg(TS, reg_TS);
  WriteReg(TSW, reg_TSW);
  WriteReg(CGWSEL, reg_CGWSEL);
  WriteReg(CGADSUB, reg_CGADSUB);
  gameplay_CGWSEL = next_gameplay_CGWSEL;
  gameplay_CGADSUB = next_gameplay_CGADSUB;
  WriteReg(COLDATA, reg_COLDATA[0]);
  WriteReg(COLDATA, reg_COLDATA[1]);
  WriteReg(COLDATA, reg_COLDATA[2]);
  WriteReg(SETINI, reg_SETINI);
  WriteReg(BG1HOFS, reg_BG1HOFS);
  WriteReg(BG1HOFS, HIBYTE(reg_BG1HOFS));
  WriteReg(BG1VOFS, reg_BG1VOFS);
  WriteReg(BG1VOFS, HIBYTE(reg_BG1VOFS));
  WriteReg(BG2HOFS, reg_BG2HOFS);
  WriteReg(BG2HOFS, HIBYTE(reg_BG2HOFS));
  WriteReg(BG2VOFS, reg_BG2VOFS);
  WriteReg(BG2VOFS, HIBYTE(reg_BG2VOFS));
  WriteReg(BG3HOFS, reg_BG3HOFS);
  WriteReg(BG3HOFS, HIBYTE(reg_BG3HOFS));
  WriteReg(BG3VOFS, reg_BG3VOFS);
  WriteReg(BG3VOFS, HIBYTE(reg_BG3VOFS));
  WriteReg(BG4HOFS, reg_BG4HOFS);
  WriteReg(BG4HOFS, HIBYTE(reg_BG4HOFS));
  WriteReg(BG4VOFS, reg_BG4VOFS);
  WriteReg(BG4VOFS, HIBYTE(reg_BG4VOFS));
  HIBYTE(hdma_data_table_in_ceres) = reg_BGMODE_fake;
  if ((reg_BGMODE & 7) == 7 || (reg_BGMODE_fake & 7) == 7) {
    WriteReg(M7A, reg_M7A);
    WriteReg(M7A, HIBYTE(reg_M7A));
    WriteReg(M7B, reg_M7B);
    WriteReg(M7B, HIBYTE(reg_M7B));
    WriteReg(M7C, reg_M7C);
    WriteReg(M7C, HIBYTE(reg_M7C));
    WriteReg(M7D, reg_M7D);
    WriteReg(M7D, HIBYTE(reg_M7D));
    WriteReg(M7X, reg_M7X);
    WriteReg(M7X, HIBYTE(reg_M7X));
    WriteReg(M7Y, reg_M7Y);
    WriteReg(M7Y, HIBYTE(reg_M7Y));
  }
}

/**
* @brief Update OAM and CGRAM from RAM
*/
void NmiUpdatePalettesAndOam(void) {  // 0x80933A
  // Set up transfer for OAM entries in RAM to OAM
  WriteRegWord(DMAP0, 0x400);
  WriteRegWord(A1T0L, ADDR16_OF_RAM(*oam_ent));
  WriteReg(A1B0, 0);
  WriteRegWord(DAS0L, 0x220);
  WriteRegWord(OAMADDL, 0);
  // Set up transfer for palettes in RAM to CGRAM
  WriteRegWord(DMAP1, 0x2200);
  WriteRegWord(A1T1L, ADDR16_OF_RAM(palette_buffer.pal[0]));
  WriteReg(A1B1, 0x7E);
  WriteRegWord(DAS1L, 0x200);
  WriteReg(CGADD, 0);
  // Execute transfers
  WriteReg(MDMAEN, 3);
}

/**
* @brief Transfer Samus tiles from RAM to VRAM
*/
void NmiTransferSamusToVram(void) {  // 0x809376
  WriteReg(VMAIN, 0x80);
  if (LOBYTE(nmi_copy_samus_halves)) {
    SamusTileAnimationTileDefs *td = (SamusTileAnimationTileDefs *)RomPtr_92(nmi_copy_samus_top_half_src);
    WriteRegWord(VMADDL, 0x6000);
    WriteRegWord(DMAP1, 0x1801);
    WriteRegWord(A1T1L, td->src.addr);
    WriteReg(A1B1, td->src.bank);
    WriteRegWord(DAS1L, td->part1_size);
    WriteReg(MDMAEN, 2);
    WriteRegWord(VMADDL, 0x6100);
    WriteRegWord(A1T1L, td->src.addr + td->part1_size);
    if (td->part2_size) {
      WriteRegWord(DAS1L, td->part2_size);
      WriteReg(MDMAEN, 2);
    }
  }
  if (HIBYTE(nmi_copy_samus_halves)) {
    SamusTileAnimationTileDefs *td = (SamusTileAnimationTileDefs *)RomPtr_92(nmi_copy_samus_bottom_half_src);
    WriteRegWord(VMADDL, 0x6080);
    WriteRegWord(DMAP1, 0x1801);
    WriteRegWord(A1T1L, td->src.addr);
    WriteReg(A1B1, td->src.bank);
    WriteRegWord(DAS1L, td->part1_size);
    WriteReg(MDMAEN, 2);
    WriteRegWord(VMADDL, 0x6180);
    WriteRegWord(A1T1L, td->src.addr + td->part1_size);
    if (td->part2_size) {
      WriteRegWord(DAS1L, td->part2_size);
      WriteReg(MDMAEN, 2);
    }
  }
}

/**
* @brief Transfer animated tiles to VRAM
*/
void NmiProcessAnimtilesVramTransfers(void) {  // 0x809416
  if (animtiles_enable_flag & 0x8000) {
    for (int i = 10; i >= 0; i -= 2) {
      int obj_idx = i >> 1;
      if (animtiles_ids[obj_idx] != 0) {
        if (animtiles_src_ptr[obj_idx] != 0) {
          WriteRegWord(A1T0L, animtiles_src_ptr[obj_idx]);
          WriteReg(A1B0, 0x87);
          WriteRegWord(DMAP0, 0x1801);
          WriteRegWord(DAS0L, animtiles_sizes[obj_idx]);
          WriteRegWord(VMADDL, animtiles_vram_ptr[obj_idx]);
          WriteReg(VMAIN, 0x80);
          WriteReg(MDMAEN, 1);
          animtiles_src_ptr[obj_idx] = 0;
        }
      }
    }
  }
}

/**
* @brief Read inputs from joypad
*/
void ReadJoypadInputs(void) {  // 0x809459
  uint16 joypad1_input = ReadRegWord(JOY1L);
  joypad1_lastkeys = joypad1_input;
  joypad1_newkeys = joypad1_input & (joypad1_prev ^ joypad1_input);
  joypad1_newkeys2_UNUSED = joypad1_input & (joypad1_prev ^ joypad1_input);
  // If pressing the last button as before
  if (joypad1_input != 0 && joypad1_input == joypad1_prev) {
    if (--joypad1_keyrepeat_ctr == 0) {
      joypad1_newkeys2_UNUSED = joypad1_lastkeys;
      joypad1_keyrepeat_ctr = joypad_ctr_repeat_next;
    }
  }
  // If a button is let go of, or none is being held
  else {
    joypad1_keyrepeat_ctr = joypad_ctr_repeat_first;
  }
  joypad1_prev = joypad1_lastkeys;
  if (enable_debug) {
    uint16 joypad2_input = ReadRegWord(JOY2L);
    joypad2_last = joypad2_input;
    joypad2_new_keys = joypad2_input & (joypad2_prev ^ joypad2_input);
    joypad2_newkeys2 = joypad2_input & (joypad2_prev ^ joypad2_input);
    // If pressing the last button as before
    if (joypad2_input != 0 && joypad2_input == joypad2_prev) {
      if (!--joypad2_keyrepeat_ctr) {
        joypad2_newkeys2 = joypad2_last;
        joypad2_keyrepeat_ctr = joypad_ctr_repeat_next;
      }
    }
    // If a button is let go of, or none is being held
    else {
      joypad2_keyrepeat_ctr = joypad_ctr_repeat_first;
    }
    joypad2_prev = joypad2_last;
    if (is_uploading_apu || joypad1_lastkeys != (kButton_Select | kButton_Start | kButton_L | kButton_R)) {
      if (enable_debug) {
        joypad_dbg_1 = 0;
        joypad_dbg_2 = 0;
        if (!(joypad_dbg_flags & kDebugOption_DisableInput)) {
          if ((joypad1_lastkeys & (kButton_Select | kButton_L)) == (kButton_Select | kButton_L)) {
            joypad_dbg_1 = joypad1_newkeys;
            joypad1_lastkeys = 0;
            joypad1_newkeys = 0;
          }
          if ((joypad1_lastkeys & (kButton_Select | kButton_R)) == (kButton_Select | kButton_R)) {
            joypad_dbg_2 = joypad1_newkeys;
            joypad1_lastkeys = 0;
            joypad1_newkeys = 0;
          }
          if (joypad_dbg_2 & kButton_A)
            WORD(reg_NMITIMEN) ^= kNmi_Enable_V_H_Irq;
          if (joypad_dbg_2 & kButton_B) {
            bool ammo_is_swapped = (~joypad_dbg_flags & kDebugOption_PressedB_HeldSelectR) != 0;
            joypad_dbg_flags ^= kDebugOption_PressedB_HeldSelectR;
            if (ammo_is_swapped) {
              joypad_dbg_missiles_swap = samus_missiles;
              joypad_dbg_super_missiles_swap = samus_super_missiles;
              joypad_dbg_power_bombs_swap = samus_power_bombs;
              samus_missiles = 0;
              samus_super_missiles = 0;
              samus_power_bombs = 0;
            }
            else {
              samus_missiles = joypad_dbg_missiles_swap;
              samus_super_missiles = joypad_dbg_super_missiles_swap;
              samus_power_bombs = joypad_dbg_power_bombs_swap;
            }
          }
          if (joypad_dbg_2 & kButton_X)
            joypad_dbg_flags ^= kDebugOption_PressedX_HeldSelectR;
        }
      }
      else {
        joypad_dbg_1 = 0;
        joypad_dbg_2 = 0;
        joypad2_last &= 0x10;
        joypad2_new_keys &= 0x10;
      }
    }
    else {
      disable_sounds = 0;
      SoftReset();
    }
  }
}

/**
* @brief Updates OAM, palettes, VRAM, IO, and handles DMA and HDMA transfers
*/
void Vector_NMI(void) {  // 0x809583
  if (waiting_for_nmi) {
    NmiUpdatePalettesAndOam();
    NmiTransferSamusToVram();
    NmiProcessAnimtilesVramTransfers();
    NmiUpdateIoRegisters();
    for (int obj_pos = 0; obj_pos < 6; ++obj_pos) {
      if (hdma_object_channels_bitmask[obj_pos])
        WriteRegWord((SnesRegs)(LOBYTE(hdma_object_bank_slot[obj_pos]) + A1T0L), hdma_object_table_pointers[obj_pos]);
    }
    if (reg_BGMODE == 7 || reg_BGMODE_fake == 7)
      NMI_ProcessMode7Queue();
    NMI_ProcessVramWriteQueue();
    NMI_ProcessVramReadQueue();
    WriteReg(HDMAEN, reg_HDMAEN);
    waiting_for_nmi = 0;
    nmi_frames_missed = 0;
    ++nmi_frame_counter_byte;
    ++nmi_frame_counter_word;
  }
  else if (++nmi_frames_missed >= nmi_frames_missed_max) {
    nmi_frames_missed_max = nmi_frames_missed;
  }
  ++nmi_frame_counter_including_lag;
}

/**
* @brief Transfers the incoming data to VRAM
* @param vram_dst The address of VRAM to write to
* @param src The source address of the data
* @param size The size of the data to transfer
*/
void CopyToVramNow(uint16 vram_dst, uint32 src, uint16 size) {  // 0x809632
  // src can point either to ram or rom
  WriteReg(INIDISP, 0x80);
  WriteRegWord(VMADDL, vram_dst);
  WriteRegWord(DMAP1, 0x1801);
  WriteRegWord(A1T1L, (uint16)src);
  WriteReg(A1B1, src >> 16);
  WriteRegWord(DAS1L, size);
  WriteReg(VMAIN, 0x80);
  WriteReg(MDMAEN, 2);
  WriteReg(INIDISP, 0xF);
}

/**
* @brief Sets the interrupt command and target
* @param interrupt_command The next interrupt to perform
* @param v_counter The target of the vertical counter
* @param h_counter The target of the horizontal counter
*/
void IrqHandler_SetResult(uint16 interrupt_command, uint16 v_counter, uint16 h_counter) {  // 0x80987E
  //  printf("Setting irq next: %d, %d, %d\n", a, x, y);
  cur_irq_handler = interrupt_command;
  WriteRegWord(VTIMEL, v_counter);
  WriteRegWord(HTIMEL, h_counter);
}

/**
* @brief Do nothing during the interrupt
*/
void IrqHandler_0_Nothing(void) {  // 0x80966E
  uint16 next_irq_handler = irqhandler_next_handler;
  irqhandler_next_handler = 0;
  IrqHandler_SetResult(next_irq_handler, 0, 0);
}

/**
* @brief Disables vertical and horizontal interrupts
*/
void IrqHandler_2_DisableIRQ(void) {  // 0x809680
  WORD(reg_NMITIMEN) &= ~kNmi_Enable_V_H_Irq;
  IrqHandler_SetResult(0, 0, 0);
}

/**
* @brief Start drawing the HUD during main gameplay
*/
void IrqHandler_4_Main_BeginHudDraw(void) {  // 0x80968B
  WriteReg(BG3SC, 0x5A);
  WriteReg(CGWSEL, 0);
  WriteReg(CGADSUB, 0);
  WriteReg(TM, 4);
  IrqHandler_SetResult(kInterruptCommand_6_Main_EndHudDraw, 31, 152);
}

/**
* @brief Finish drawing the HUD during main gameplay
*/
void IrqHandler_6_Main_EndHudDraw(void) {  // 0x8096A9
  WriteReg(CGWSEL, gameplay_CGWSEL);
  WriteReg(CGADSUB, gameplay_CGADSUB);
  WriteReg(BG3SC, gameplay_BG3SC);
  WriteReg(TM, gameplay_TM);

  uint16 next_irq_handler = irqhandler_next_handler;
  irqhandler_next_handler = 0;
  IrqHandler_SetResult(next_irq_handler ? next_irq_handler : kInterruptCommand_4_Main_BeginHudDraw, 0, 152);
}

/**
* @brief Start drawing the HUD during the start of a door transition
*/
void IrqHandler_8_StartOfDoor_BeginHud(void) {  // 0x8096D3
  WriteReg(BG3SC, 0x5A);
  WriteReg(TM, 4);
  WriteReg(CGWSEL, 0);
  WriteReg(CGADSUB, 0);
  IrqHandler_SetResult(kInterruptCommand_10_StartOfDoor_EndHud, 31, 152);
}

/**
* @brief Finish drawing the HUD during the start of a door transition
*/
void IrqHandler_10_StartOfDoor_EndHud(void) {  // 0x8096F1
  uint8 layer;
  if (((previous_cre_bitset | cre_bitset) & 1) != 0)
    layer = 0x10;
  else
    layer = 0x11;
  WriteReg(TM, layer);
  uint16 next_irq_handler = irqhandler_next_handler;
  irqhandler_next_handler = 0;
  IrqHandler_SetResult(next_irq_handler ? next_irq_handler : kInterruptCommand_8_StartOfDoor_BeginHud, 0, 152);
}

/**
* @brief Start drawing the HUD while in Draygon's room
*/
void IrqHandler_12_Draygon_BeginHud(void) {  // 0x80971A
  WriteReg(TM, 4);
  WriteReg(CGWSEL, 0);
  WriteReg(CGADSUB, 0);
  IrqHandler_SetResult(kInterruptCommand_14_Draygon_EndHud, 31, 152);
}

/**
* @brief Finish drawing the HUD while in Draygon's room
*/
void IrqHandler_14_Draygon_EndHud(void) {  // 0x809733
  WriteReg(BG3SC, gameplay_BG3SC);
  WriteReg(CGWSEL, gameplay_CGWSEL);
  WriteReg(CGADSUB, gameplay_CGADSUB);
  uint16 next_irq_handler = irqhandler_next_handler;
  irqhandler_next_handler = 0;
  IrqHandler_SetResult(next_irq_handler ? next_irq_handler : kInterruptCommand_12_Draygon_BeginHud, 0, 152);
}

/**
* @brief Start drawing the HUD during a vertical door transition
*/
void IrqHandler_16_VerticalDoor_BeginHud(void) {  // 0x809758
  WriteReg(TM, 4);
  WriteReg(CGWSEL, 0);
  WriteReg(CGADSUB, 0);
  IrqHandler_SetResult(kInterruptCommand_18_VerticalDoor_EndHud, 31, 152);
}

/**
* @brief Finish drawing the HUD during a vertical door transition
*/
void IrqHandler_18_VerticalDoor_EndHud(void) {  // 0x809771
  uint8 layer;
  if (((previous_cre_bitset | cre_bitset) & 1) != 0)
    layer = 0x10;
  else
    layer = 0x11;
  WriteReg(TM, layer);
  WriteReg(CGWSEL, 0);
  WriteReg(CGADSUB, 0);
  if (!(door_transition_flag & 0x8000))
    Irq_FollowDoorTransition();
  IrqHandler_SetResult(kInterruptCommand_20_VerticalDoor_EndDraw, 216, 152);
}

/**
* @brief Finish drawing during a vertical door transition
*/
void IrqHandler_20_VerticalDoor_EndDraw(void) {  // 0x8097A9
  uint16 next_irq_handler = irqhandler_next_handler;
  irqhandler_next_handler = 0;
  IrqHandler_SetResult(next_irq_handler ? next_irq_handler : kInterruptCommand_16_VerticalDoor_BeginHud, 0, 152);
}

/**
* @brief Start drawing the HUD during a horizontal door transition
*/
void IrqHandler_22_HorizDoor_BeginHud(void) {  // 0x8097C1
  WriteReg(TM, 4);
  WriteReg(CGWSEL, 0);
  WriteReg(CGADSUB, 0);
  IrqHandler_SetResult(kInterruptCommand_24_HorizDoor_EndHud, 31, 152);
}

/**
* @brief Finish drawing the HUD during a horizontal door transition
*/
void IrqHandler_24_HorizDoor_EndHud(void) {  // 0x8097DA
  uint8 layer;

  if (((previous_cre_bitset | cre_bitset) & 1) != 0)
    layer = 0x10;
  else
    layer = 0x11;
  WriteReg(TM, layer);
  WriteReg(CGWSEL, 0);
  WriteReg(CGADSUB, 0);
  if ((door_transition_flag & 0x8000) == 0)
    Irq_FollowDoorTransition();
  IrqHandler_SetResult(kInterruptCommand_26_HorizDoor_EndDraw, 160, 152);
}

/**
* @brief Finish drawing during a horizontal door transition
*/
void IrqHandler_26_HorizDoor_EndDraw(void) {  // 0x80980A
  uint16 next_irq_handler = irqhandler_next_handler;
  irqhandler_next_handler = 0;
  IrqHandler_SetResult(next_irq_handler ? next_irq_handler : kInterruptCommand_22_HorizDoor_BeginHud, 0, 152);
}

/**
* @brief Enable h and v counter interrupts
*/
void EnableIrqInterrupts(void) {  // 0x80982A
  WriteRegWord(VTIMEL, 0);
  WriteRegWord(HTIMEL, 152);
  WORD(reg_NMITIMEN) |= kNmi_Enable_V_H_Irq;
}

/**
* @brief Enable h and v counter interrupts and perform the interrupt
*/
void EnableIrqInterruptsNow(void) {  // 0x809841
  WriteRegWord(VTIMEL, 0);
  WriteRegWord(HTIMEL, 152);
  WORD(reg_NMITIMEN) |= kNmi_Enable_V_H_Irq;
  WriteReg(NMITIMEN, reg_NMITIMEN);
}

/**
* @brief Disable h and v counter interrupts
*/
void DisableIrqInterrupts(void) {  // 0x80985F
  WORD(reg_NMITIMEN) &= ~kNmi_Enable_V_H_Irq;
}

static Func_V *const kIrqHandlers[14] = {  // 0x80986A
  IrqHandler_0_Nothing,
  IrqHandler_2_DisableIRQ,
  IrqHandler_4_Main_BeginHudDraw,
  IrqHandler_6_Main_EndHudDraw,
  IrqHandler_8_StartOfDoor_BeginHud,
  IrqHandler_10_StartOfDoor_EndHud,
  IrqHandler_12_Draygon_BeginHud,
  IrqHandler_14_Draygon_EndHud,
  IrqHandler_16_VerticalDoor_BeginHud,
  IrqHandler_18_VerticalDoor_EndHud,
  IrqHandler_20_VerticalDoor_EndDraw,
  IrqHandler_22_HorizDoor_BeginHud,
  IrqHandler_24_HorizDoor_EndHud,
  IrqHandler_26_HorizDoor_EndDraw,
};

/**
* @brief Executes the current IRQ handler command
*/
void Vector_IRQ(void) {
  kIrqHandlers[cur_irq_handler >> 1]();
}

/**
* @brief Writes the top and bottom row of the HUD missile icon to RAM if the tilemap is blank
*/
void AddMissilesToHudTilemap(void) {  // 0x8099CF
  if ((hud_tilemap.row1.missiles[0] & 0x3FF) == 15) {
    uint16 row_size = sizeof(hud_tilemap.row1.missiles);
    MemCpy(hud_tilemap.row1.missiles, kHudTilemaps_Missiles, row_size);
    MemCpy(hud_tilemap.row2.missiles, kHudTilemaps_Missiles + (row_size >> 1), row_size);
  }
}

/**
* @brief Writes the HUD super missile icon to RAM
*/
void AddSuperMissilesToHudTilemap(void) {  // 0x809A0E
  uint16 super_missile_tilemap_offset = ADDR16_OF_RAM(hud_tilemap.row1.super_missiles) - ADDR16_OF_RAM(hud_tilemap.row1);
  AddToTilemapInner(super_missile_tilemap_offset, kHudTilemaps_SuperMissiles);
}

/**
* @brief Writes the HUD power bomb icon to RAM
*/
void AddPowerBombsToHudTilemap(void) {  // 0x809A1E
  uint16 power_bomb_tilemap_offset = ADDR16_OF_RAM(hud_tilemap.row1.power_bombs) - ADDR16_OF_RAM(hud_tilemap.row1);
  AddToTilemapInner(power_bomb_tilemap_offset, kHudTilemaps_PowerBombs);
}

/**
* @brief Writes the HUD grapple icon to RAM
*/
void AddGrappleToHudTilemap(void) {  // 0x809A2E
  uint16 grapple_tilemap_offset = ADDR16_OF_RAM(hud_tilemap.row1.grapple) - ADDR16_OF_RAM(hud_tilemap.row1);
  AddToTilemapInner(grapple_tilemap_offset, kHudTilemaps_Grapple);
}

/**
* @brief Writes the HUD x-ray icon to RAM
*/
void AddXrayToHudTilemap(void) {  // 0x809A3E
  uint16 xray_tilemap_offset = ADDR16_OF_RAM(hud_tilemap.row1.x_ray) - ADDR16_OF_RAM(hud_tilemap.row1);
  AddToTilemapInner(xray_tilemap_offset, kHudTilemaps_Xray);
}

/**
* @brief Transfers the top and bottom row of the HUD source icon to the offset in RAM if the tilemap is blank
* @param hud_tilemap_offset The offset into the HUD tilemap RAM
* @param tilemap_src The source of the HUD icon tilemap
*/
void AddToTilemapInner(uint16 hud_tilemap_offset, const uint16 *tilemap_src) {  // 0x809A4C
  int offset = hud_tilemap_offset >> 1;
  if ((hud_tilemap.arr[offset] & 0x3FF) == 15) {
    MemCpy(hud_tilemap.row1.arr + offset, &tilemap_src[0], 2*2);
    MemCpy(hud_tilemap.row2.arr + offset, &tilemap_src[2], 2*2);
  }
}

/**
* @brief Initializes the HUD when starting, adds the icons and count to the HUD, and resets the saved Samus values
*/
void InitializeHud(void) {  // 0x809A79
  uint16 ammo_digits_offset;

  CopyToVram(addr_kVram_HudTopRow, kHudTilemaps_TopRow, sizeof(kHudTilemaps_TopRow), 1);
  MemCpy(hud_tilemap.arr, kHudTilemaps_Row1to3, sizeof(kHudTilemaps_Row1to3));
  if (equipped_items & kItem_Xray)
    AddXrayToHudTilemap();
  if (equipped_items & kItem_Grapple)
    AddGrappleToHudTilemap();
  if (samus_max_missiles != 0)
    AddMissilesToHudTilemap();
  if (samus_max_super_missiles != 0)
    AddSuperMissilesToHudTilemap();
  if (samus_max_power_bombs != 0)
    AddPowerBombsToHudTilemap();

  samus_prev_health = 0;
  samus_prev_missiles = 0;
  samus_prev_super_missiles = 0;
  samus_prev_power_bombs = 0;
  samus_prev_hud_item_index = 0;
  InitializeMiniMapBroken();

  ammo_digits_offset = ADDR16_OF_RAM(hud_tilemap.row3.missile_count) - ADDR16_OF_RAM(hud_tilemap.row1);
  if (samus_max_missiles != 0) {
    DrawThreeHudDigits(kDigitTilesetsWeapon, samus_missiles, ammo_digits_offset);
  }
  ammo_digits_offset = ADDR16_OF_RAM(hud_tilemap.row3.super_missile_count) - ADDR16_OF_RAM(hud_tilemap.row1);
  if (samus_max_super_missiles != 0) {
    DrawTwoHudDigits(kDigitTilesetsWeapon, samus_super_missiles, ammo_digits_offset);
  }
  ammo_digits_offset = ADDR16_OF_RAM(hud_tilemap.row3.power_bomb_count) - ADDR16_OF_RAM(hud_tilemap.row1);
  if (samus_max_power_bombs != 0) {
    DrawTwoHudDigits(kDigitTilesetsWeapon, samus_power_bombs, ammo_digits_offset);
  }

  uint16 highlighted_palette = 4 * 0x400;
  uint16 unhighlighted_palette = 5 * 0x400;
  ToggleHudItemHighlight(hud_item_index, highlighted_palette);
  ToggleHudItemHighlight(samus_prev_hud_item_index, unhighlighted_palette);
  HandleHudTilemap();
}

/**
* @brief Updates the HUD while playing, handles adding new icons and updating the counts, and handles the toggling
*/
void HandleHudTilemap(void) {  // 0x809B44
  if (reserve_health_mode == kReserveHealthMode_1_Auto) {
    const uint16 *autoreserve_tilemap = kHudTilemaps_AutoReserve;
    if (samus_reserve_health == 0)
      autoreserve_tilemap = kHudTilemaps_EmptyAutoReserve;
    hud_tilemap.row1.auto_reserve[0] = autoreserve_tilemap[0];
    hud_tilemap.row1.auto_reserve[1] = autoreserve_tilemap[1];
    hud_tilemap.row2.auto_reserve[0] = autoreserve_tilemap[2];
    hud_tilemap.row2.auto_reserve[1] = autoreserve_tilemap[3];
    hud_tilemap.row3.auto_reserve[0] = autoreserve_tilemap[4];
    hud_tilemap.row3.auto_reserve[1] = autoreserve_tilemap[5];
  }

  if (samus_health != samus_prev_health) {
    samus_prev_health = samus_health;
    uint16 whole_tank_count = samus_health / 100;
    uint16 sub_tank_energy = samus_health % 100;
    uint16 collected_tank_count = samus_max_health / 100 + 1;

    for (uint16 tank_index = 0; tank_index < 14*2; tank_index += 2) {
      if (--collected_tank_count == 0)
        break;
      uint16 tank_tile = 0x3430;
      if (whole_tank_count != 0) {
        --whole_tank_count;
        tank_tile = 0x2831;
      }
      uint16 tank_icon_offset = kEnergyTankIconTilemapOffsets[tank_index >> 1];
      hud_tilemap.arr[tank_icon_offset >> 1] = tank_tile;
    }
    uint16 health_digits_offset = ADDR16_OF_RAM(hud_tilemap.row3.subtank_health) - ADDR16_OF_RAM(hud_tilemap.arr[0]);
    DrawTwoHudDigits(kDigitTilesetsHealth, sub_tank_energy, health_digits_offset);
  }

  if (samus_max_missiles != 0 && samus_missiles != samus_prev_missiles) {
    samus_prev_missiles = samus_missiles;
    uint16 missile_digits_offset = ADDR16_OF_RAM(hud_tilemap.row3.missile_count) - ADDR16_OF_RAM(hud_tilemap.arr[0]);
    DrawThreeHudDigits(kDigitTilesetsWeapon, samus_missiles, missile_digits_offset);
  }

  if (samus_max_super_missiles != 0 && samus_super_missiles != samus_prev_super_missiles) {
    samus_prev_super_missiles = samus_super_missiles;
    uint16 super_missile_digits_offset = ADDR16_OF_RAM(hud_tilemap.row3.super_missile_count) - ADDR16_OF_RAM(hud_tilemap.arr[0]);
    if (joypad_dbg_flags & kDebugOption_Draw3DigitsSuperMissile)
      DrawThreeHudDigits(kDigitTilesetsWeapon, samus_prev_super_missiles, super_missile_digits_offset);
    else
      DrawTwoHudDigits(kDigitTilesetsWeapon, samus_prev_super_missiles, super_missile_digits_offset);
  }

  if (samus_max_power_bombs != 0 && samus_power_bombs != samus_prev_power_bombs) {
    samus_prev_power_bombs = samus_power_bombs;
    uint16 power_bomb_digits_offset = ADDR16_OF_RAM(hud_tilemap.row3.power_bomb_count) - ADDR16_OF_RAM(hud_tilemap.arr[0]);
    DrawTwoHudDigits(kDigitTilesetsWeapon, samus_power_bombs, power_bomb_digits_offset);
  }

  uint16 highlighted_palette = 4 * 0x400;
  uint16 unhighlighted_palette = 5 * 0x400;
  if (hud_item_index != samus_prev_hud_item_index) {
    ToggleHudItemHighlight(hud_item_index, highlighted_palette);
    ToggleHudItemHighlight(samus_prev_hud_item_index, unhighlighted_palette);
    samus_prev_hud_item_index = hud_item_index;
    if (samus_movement_type != kMovementType_03_SpinJumping
        && samus_movement_type != kMovementType_14_WallJumping
        && grapple_beam_function == FUNC16(GrappleBeamFunc_Inactive)
        && !time_is_frozen_flag) {
      QueueSfx1_Max6(kSfx1_SwitchHudItem);
    }
  }

  uint16 hud_palette = unhighlighted_palette;
  if (nmi_frame_counter_byte & 0x10)
    hud_palette = highlighted_palette;
  ToggleHudItemHighlight(samus_auto_cancel_hud_item_index, hud_palette);
  // Transfer the HUD tilemap in RAM to VRAM 0x5820
  VramWriteEntry* vram_entry = gVramWriteEntry(vram_write_queue_tail);
  vram_entry->size = sizeof(RamHudTilemap);
  vram_entry->src.addr = ADDR16_OF_RAM(hud_tilemap.arr[0]);
  vram_entry->src.bank = 0x7E;
  vram_entry->vram_dst = addr_kVram_Hud;
  vram_write_queue_tail += sizeof(VramWriteEntry);
}

/**
* @brief Toggles the highlight palette of the HUD item
* @param hud_item_index_ The index of the item to toggle
* @param tilemap_palette_bits The palette of the HUD item
*/
void ToggleHudItemHighlight(uint16 hud_item_index_, uint16 tilemap_palette_bits) {  // 0x809CEA
  hud_item_tilemap_palette_bits = tilemap_palette_bits;
  int16 item_index = hud_item_index_ - 1;
  if (item_index >= 0) {
    item_index *= 2;
    int offset = kHudItemTilemapOffsets[item_index >> 1] >> 1;
    uint16 blank_tile = 0x2C0F;
    if (hud_tilemap.row1.arr[offset] != blank_tile)
      hud_tilemap.row1.arr[offset] = hud_item_tilemap_palette_bits | hud_tilemap.row1.arr[offset] & 0xE3FF;
    if (hud_tilemap.row1.arr[offset + 1] != blank_tile)
      hud_tilemap.row1.arr[offset + 1] = hud_item_tilemap_palette_bits | hud_tilemap.row1.arr[offset + 1] & 0xE3FF;
    if (hud_tilemap.row2.arr[offset] != blank_tile)
      hud_tilemap.row2.arr[offset] = hud_item_tilemap_palette_bits | hud_tilemap.row2.arr[offset] & 0xE3FF;
    if (hud_tilemap.row2.arr[offset + 1] != blank_tile)
      hud_tilemap.row2.arr[offset + 1] = hud_item_tilemap_palette_bits | hud_tilemap.row2.arr[offset + 1] & 0xE3FF;
    if (item_index == (kHudItem_1_Missile-1)) {
      if (hud_tilemap.row1.arr[offset + 2] != blank_tile)
        hud_tilemap.row1.arr[offset + 2] = hud_item_tilemap_palette_bits | hud_tilemap.row1.arr[offset + 2] & 0xE3FF;
      if (hud_tilemap.row2.arr[offset + 2] != blank_tile)
        hud_tilemap.row2.arr[offset + 2] = hud_item_tilemap_palette_bits | hud_tilemap.row2.arr[offset + 2] & 0xE3FF;
    }
  }
}

/**
* @brief Transfers the hundreds digit of the number to the HUD in RAM
* @param digits_tilemap The tilemap of the digits to draw
* @param num The number to draw
* @param hud_tilemap_offset The index of the HUD digit into RAM
*/
void DrawThreeHudDigits(const uint16* digits_tilemap, uint16 num, uint16 hud_tilemap_offset) {  // 0x809D78
  uint16 hundreds_digit = num / 100;
  hud_tilemap.arr[hud_tilemap_offset >> 1] = digits_tilemap[hundreds_digit];
  DrawTwoHudDigits(digits_tilemap, num % 100, hud_tilemap_offset + 2);
}

/**
* @brief Transfers the tens and ones digit of the number to the HUD in RAM
* @param digits_tilemap The tilemap of the digits to draw
* @param num The number to draw
* @param hud_tilemap_offset The index of the HUD digit into RAM
*/
void DrawTwoHudDigits(const uint16* digits_tilemap, uint16 num, uint16 hud_tilemap_offset) {  // 0x809D98
  int offset = hud_tilemap_offset >> 1;
  uint16 tens_digit = num / 10;
  hud_tilemap.arr[offset] = digits_tilemap[tens_digit];
  uint16 ones_digit = num % 10;
  hud_tilemap.arr[offset + 1] = digits_tilemap[ones_digit];
}

static Func_U8 *const kTimerProcessFuncs[7] = {  // 0x809DE7
  ProcessTimer_Inactive,
  ProcessTimer_CeresStart,
  ProcessTimer_MotherBrainStart,
  ProcessTimer_InitialDelay,
  ProcessTimer_MovementDelayed,
  ProcessTimer_MovingIntoPlace,
  ProcessTimer_MovedIntoPlace,
};

/**
* @brief Handles the escape timers
* @return uint8 1 if timer is zero, 0 if timer is not zero
*/
uint8 ProcessTimer(void) {
  return kTimerProcessFuncs[(uint8)timer_status]();
}

/**
* @brief Begin the timer for Ceres escape
* @return 0 timer has not reached zero
*/
uint8 ProcessTimer_CeresStart(void) {  // 0x809E09
  ClearTimerRam();
  SetTimerMinutes(0x0100);
  timer_status = 0x8000 | kTimerStatus_3_InitialDelay;
  return 0;
}

/**
* @brief Do nothing since the timer is inactive
* @return 0 timer has not reached zero
*/
uint8 ProcessTimer_Inactive(void) {  // 0x809E1A
  return 0;
}

/**
* @brief Begin the timer for Zebes escape
* @return 0 timer has not reached zero
*/
uint8 ProcessTimer_MotherBrainStart(void) {  // 0x809E1C
  ClearTimerRam();
  SetTimerMinutes(0x0300);
  timer_status = 0x8000 | kTimerStatus_3_InitialDelay;
  return 0;
}

/**
* @brief Handles the initial delay before the timer starts running
* @return 0 timer has not reached zero
*/
uint8 ProcessTimer_InitialDelay(void) {  // 0x809E2F
  (uint8)timer_x_pos++;
  if ((uint8)timer_x_pos >= 0x10)
    LOBYTE(timer_status) = kTimerStatus_4_Counting_MovementDelayed;
  return 0;
}

/**
* @brief Handles the delay before the timer starts moving
* @return uint8 1 if timer is zero, 0 if timer is not zero
*/
uint8 ProcessTimer_MovementDelayed(void) {  // 0x809E41
  (uint8)timer_x_pos++;
  if ((uint8)timer_x_pos >= 0x60) {
    LOBYTE(timer_x_pos) = 0;
    LOBYTE(timer_status) = kTimerStatus_5_Counting_MovingIntoPlace;
  }
  return ProcessTimer_Decrement();
}

/**
* @brief Handles moving the timer to the top right
* @return uint8 1 if timer is zero, 0 if timer is not zero
*/
uint8 ProcessTimer_MovingIntoPlace(void) {  // 0x809E58
  uint16 timer_stage = 0;
  uint16 target_x_pos = timer_x_pos + 0xE0;
  uint16 final_x_pos = (220 << 8);
  if (target_x_pos >= final_x_pos)
    ++timer_stage;
  timer_x_pos = IntMin(final_x_pos, target_x_pos);

  uint16 target_y_pos = timer_y_pos - 0xC1;
  uint16 final_y_pos = (48 << 8);
  if (target_y_pos < final_y_pos)
    ++timer_stage;
  timer_y_pos = IntMax(final_y_pos, target_y_pos);
  if (timer_stage == 2)
    LOBYTE(timer_status) = kTimerStatus_6_Counting_MovedIntoPlace;
  return ProcessTimer_Decrement();
}

/**
* @brief Counts the timer down
* @return uint8 1 if timer is zero, 0 if timer is not zero
*/
uint8 ProcessTimer_MovedIntoPlace(void) {  // 0x809E89
  return ProcessTimer_Decrement();
}

/**
* @brief Sets the minutes and seconds of the timer
* @param time_limit The time to start from, the low byte of A is the seconds, the high byte of A is the minutes
*/
void SetTimerMinutes(uint16 time_limit) {  // 0x809E8C
  timer_centiseconds = 0;
  timer_seconds = LOBYTE(time_limit);
  timer_minutes = HIBYTE(time_limit);
}

/**
* @brief Resets the timer data
*/
void ClearTimerRam(void) {  // 0x809E93
  // Puts timer off-screen
  timer_x_pos = 0x8000;
  timer_y_pos = 0x8000;
  timer_centiseconds = 0;
  timer_seconds = 0;
  timer_minutes = 0;
  timer_status = kTimerStatus_0_Inactive;
}

/**
* @todo Figure out what in the world this is doing
*/
bool DecrementDecimal(uint8 *number, uint8 value) {
  int result = (*number & 0xf) + (~value & 0xf) + 1;
  if (result < 0x10) result = (result - 0x6) & ((result - 0x6 < 0) ? 0xf : 0x1f);
  result = (*number & 0xf0) + (~value & 0xf0) + result;
  if (result < 0x100) result -= 0x60;
  *number = result;
  return result < 0x100;
}

/**
* @brief Decrements the timer minutes, seconds, and centiseconds
* @return uint8 1 if timer is zero, 0 if timer is not zero
*/
uint8 ProcessTimer_Decrement(void) {  // 0x809EA9
  // Decrease centiseconds, if centiseconds wrapped
  if (DecrementDecimal(&timer_centiseconds, kTimerCentisecondDecrements[nmi_frame_counter_word & 0x7F])) {
    // Decrement seconds, if seconds wrapped
    if (DecrementDecimal(&timer_seconds, 1)) {
      // Decrement minutes, if run of out of time
      if (DecrementDecimal(&timer_minutes, 1)) {
        timer_centiseconds = 0;
        timer_seconds = 0;
        timer_minutes = 0;
      }
      // If minutes wrapped
      else {
        timer_seconds = 0x59;
      }
    }
  }
  return (timer_centiseconds | timer_seconds | timer_minutes) == 0;

}

/**
* @brief Draws the "TIME" text, minutes, seconds, and centiseconds
*/
void DrawTimer(void) {  // 0x809F6C
  DrawTimerSpritemap(0, addr_kTimerSpritemap_TIME);
  DrawTwoTimerDigits(WORD(timer_minutes), -28);
  DrawTwoTimerDigits(WORD(timer_seconds), -4);
  DrawTwoTimerDigits(WORD(timer_centiseconds), 20);
}

/**
* @brief Draws the tens and ones digits of the timer
* @param timer_value The time to draw
* @param x_offset The offset of the x position
*/
void DrawTwoTimerDigits(uint16 timer_value, uint16 x_offset) {  // 0x809F95
  uint16 tens_digit = (timer_value & 0xF0) >> 4;
  DrawTimerSpritemap(x_offset, kTimerDigitsSpritemapPtr[tens_digit]);
  uint16 ones_digit = timer_value & 0xF;
  DrawTimerSpritemap(x_offset + 8, kTimerDigitsSpritemapPtr[ones_digit]);
}

/**
* @brief Draws the timer spritemap
* @param x_offset The offset of the x position
* @param spritemap_addr The address that holds the pointer to the spritemap
*/
void DrawTimerSpritemap(uint16 x_offset, uint16 spritemap_addr) {  // 0x809FB3
  DrawSpritemap(0x80, spritemap_addr, x_offset + HIBYTE(timer_x_pos), HIBYTE(timer_y_pos), 5 * 0x200);
}

/**
* @brief Sets up gameplay
*/
CoroutineRet StartGameplay_Async(void) {  // 0x80A07B
  COROUTINE_BEGIN(coroutine_state_2, 0)
  WriteRegWord(MDMAEN, 0);
  scrolling_finished_hook = 0;
  music_data_index = 0;
  music_track_index = 0;
  timer_status = 0;
  ResetSoundQueues();
  disable_sounds = -1;
  DisableNMI();
  DisableIrqInterrupts();
  LoadDestinationRoomThings();
  COROUTINE_AWAIT(1, Play20FramesOfMusic_Async());
  ClearAnimtiles();
  WaitUntilEndOfVblankAndClearHdma();
  InitializeSpecialEffectsForNewRoom();
  ClearPLMs();
  ClearEprojs();
  ClearPaletteFXObjects();
  UpdateBeamTilesAndPalette();
  LoadColorsForSpritesBeamsAndEnemies();
  LoadEnemies();
  LoadRoomMusic();
  COROUTINE_AWAIT(2, Play20FramesOfMusic_Async());
  UpdateMusicTrackIndex();
  NullFunc();
  ClearBG2Tilemap();
  LoadLevelDataAndOtherThings();
  LoadFXHeader();
  LoadLibraryBackground();
  CalculateLayer2Xpos();
  CalculateLayer2Ypos();
  bg2_x_scroll = layer2_x_pos;
  bg2_y_scroll = layer2_y_pos;
  CalculateBgScrolls();
  DisplayViewablePartOfRoom();
  EnableNMI();
  irqhandler_next_handler = (room_loading_irq_handler == 0) ? kInterruptCommand_4_Main_BeginHudDraw : room_loading_irq_handler;
  EnableIrqInterrupts();
  COROUTINE_AWAIT(3, Play20FramesOfMusic_Async());
  SpawnHardcodedPlm((SpawnHardcodedPlmArgs) { .x_pos = 0x08, .y_pos = 0x08, .plm_id_ = addr_kPlmHeader_B7EB_EnableSound_32FramesNormal_240FramesCeres });
  door_transition_function = FUNC16(DoorTransitionFunction_FadeInScreenAndFinish);
  COROUTINE_END(0);
}

/**
* @brief Handles the music queue for 20 frames
*/
CoroutineRet Play20FramesOfMusic_Async(void) {  // 0x80A12B
  COROUTINE_BEGIN(coroutine_state_3, 0)
  EnableNMI();
  for(my_counter = 0; my_counter < 20; my_counter++) {
    HandleMusicQueue();
    COROUTINE_AWAIT(1, WaitForNMI_Async());
  }
  DisableNMI();
  COROUTINE_END(0);
}

/**
* @brief Resume gameplay from unpausing
*/
void ResumeGameplay(void) {  // 0x80A149
  WriteRegWord(MDMAEN, 0);
  DisableNMI();
  DisableIrqInterrupts();
  LoadCRETilesTilesetTilesAndPalette();
  LoadLibraryBackground();
  DisplayViewablePartOfRoom();
  LoadRoomPlmGfx();
  EnableNMI();
  EnableIrqInterrupts();
}

/**
* @brief Displays 17x16 blocks of the room starting at (x_block, y_block)
*/
void DisplayViewablePartOfRoom(void) {  // 0x80A176
  size_of_bg2 = ((reg_BG1SC - reg_BG2SC) << 8) & 0xF800;
  CalculateBgScrollAndLayerPositionBlocks();
  for (uint16 col_num = 0; col_num < 17; col_num++) {
    blocks_to_update_x_block = layer1_x_block;
    blocks_to_update_y_block = layer1_y_block;
    vram_blocks_to_update_x_block = bg1_x_block;
    vram_blocks_to_update_y_block = bg1_y_block;
    UploadLevelDataColumn();
    // If using custom library background
    if (!(layer2_scroll_x & 1)) {
      blocks_to_update_x_block = layer2_x_block;
      blocks_to_update_y_block = layer2_y_block;
      vram_blocks_to_update_x_block = bg2_x_block;
      vram_blocks_to_update_y_block = bg2_y_block;
      UploadBackgroundDataColumn();
    }
    NMI_ProcessVramWriteQueue();
    ++layer1_x_block;
    ++bg1_x_block;
    ++layer2_x_block;
    ++bg2_x_block;
  }
}

/**
* @brief Clears the FX tilemap and queues the transfer of the FX tilemap to VRAM 0x5880
*/
void QueueClearingOfFxTilemap(void) {  // 0x80A211
  uint16 fx_cleared_size = sizeof(ram4000.fx_cleared_tilemap);
  memset7E(ram4000.fx_cleared_tilemap, 0x184E, fx_cleared_size);
  VramWriteEntry* vram_entry = gVramWriteEntry(vram_write_queue_tail);
  vram_entry->size = fx_cleared_size;
  vram_entry->src.addr = ADDR16_OF_RAM(ram4000.fx_cleared_tilemap[0]);
  vram_entry->src.bank = 0x7E;
  vram_entry->vram_dst = addr_kVram_FxBackup;
  vram_write_queue_tail += sizeof(VramWriteEntry);
}

/**
* @brief Clears the BG2 tilemap in VRAM
*/
void ClearBG2Tilemap(void) {  // 0x80A23F
  // Set the low bytes of VRAM 0x4800-0x4FFF to 0x38
  MemSetVram(0x4800, 0x38, 0x800*2, 1 + 4);
  // Set the high bytes of VRAM 0x4800-0x4FFF to 0x38 (mistake, should be 0x03)
  MemSetVram(0x4800, 0x38, 0x800*2, 1 + 8);
}

/**
* @brief Clears the FX tilemap in VRAM
*/
void ClearFXTilemap(void) {  // 0x80A29C
  // Set the low bytes of VRAM 0x5880-0x5FFF to 0x4E
  MemSetVram(0x5880, 0x4E, 0x780*2, 1 + 4);
  // Set the high bytes of VRAM 0x5880-0x5FFF to 0x18
  MemSetVram(0x5880, 0x18, 0x780*2, 1 + 8);
}

/**
* @brief Calculates the x position of layer 2
* @return uint8 returns true if layer 2 x position is not 0 or is 1, returns false otherwise
*/
uint8 CalculateLayer2Xpos(void) {  // 0x80A2F9
  if (layer2_scroll_x == 0) {
    layer2_x_pos = layer1_x_pos;
    return 0;
  }
  if (layer2_scroll_x != 1) {
    // Clear zero bit to ignore library background
    //int t = layer2_scroll_x & ~1;
    //uint8 var933 = t * LOBYTE(layer1_x_pos) >> 8;
    //layer2_x_pos = t * HIBYTE(layer1_x_pos) + var933;
    // This formula is a simplification of the original equations
    layer2_x_pos = layer1_x_pos * (layer2_scroll_x & ~1) / 0x100;
    return 0;
  }
  return 1;
}

/**
* @brief Calculates the y position of layer 2
* @return uint8 returns true if layer 2 y position is not 0 or is 1, returns false otherwise
*/
uint8 CalculateLayer2Ypos(void) {  // 0x80A33A
  if (layer2_scroll_y == 0) {
    layer2_y_pos = layer1_y_pos;
    return 0;
  }
  if (layer2_scroll_y != 1) {
    // Clear zero bit to ignore library background
    //int t = layer2_scroll_y & ~1;
    //uint8 var933 = t * (uint8)layer1_y_pos >> 8;
    //layer2_y_pos = t * HIBYTE(layer1_y_pos) + var933;
    // This formula is a simplification of the original equations
    layer2_y_pos = layer1_y_pos * (layer2_scroll_y & ~1) / 0x100;
    return 0;
  }
  return 1;
}

/**
* @brief Calculates the x and y scrolls for BG1 and BG2
*/
void CalculateBgScrolls(void) {  // 0x80A37B
  reg_BG1HOFS = bg1_x_offset + layer1_x_pos;
  reg_BG1VOFS = bg1_y_offset + layer1_y_pos;
  reg_BG2HOFS = bg2_x_scroll + layer2_x_pos;
  reg_BG2VOFS = bg2_y_scroll + layer2_y_pos;
}

/**
* @brief Update the BG scrolls and the BG graphics when scrolling
*/
void UpdateScrollVarsUpdateMap(void) {  // 0x80A3A0
  CalculateBgScrolls();
  UpdateBgGraphicsWhenScrolling();
}

/**
* @brief Update the BG scrolls, layer 2 positions, and BG graphics when scrolling
*/
void CalculateLayer2PosAndScrollsWhenScrolling(void) {  // 0x80A3AB
  if (!time_is_frozen_flag) {
    reg_BG1HOFS = bg1_x_offset + layer1_x_pos;
    reg_BG1VOFS = bg1_y_offset + layer1_y_pos;
    if (!CalculateLayer2Xpos())
      reg_BG2HOFS = bg2_x_scroll + layer2_x_pos;
    if (!CalculateLayer2Ypos())
      reg_BG2VOFS = bg2_y_scroll + layer2_y_pos;
    UpdateBgGraphicsWhenScrolling();
  }
}

/**
* @brief Calculates the BG and layer positions, updates the level and background row and column data,
* @brief and updates the previous layer 1 or 2 x and y values
*/
void UpdateBgGraphicsWhenScrolling(void) {  // 0x80A3DF
  uint16 scroll_offset;
  bool scrolled_right, scrolled_down;

  CalculateBgScrollAndLayerPositionBlocks();
  scroll_offset = 0;
  scrolled_right = (int16)layer1_x_block >= (int16)previous_layer1_x_block;
  if (layer1_x_block != previous_layer1_x_block) {
    previous_layer1_x_block = layer1_x_block;
    if (scrolled_right)
      scroll_offset = 16;
    blocks_to_update_x_block = layer1_x_block + scroll_offset;
    vram_blocks_to_update_x_block = bg1_x_block + scroll_offset;
    blocks_to_update_y_block = layer1_y_block;
    vram_blocks_to_update_y_block = bg1_y_block;
    UploadLevelDataColumn();
  }
  // If using custom layer 2
  if (!(layer2_scroll_x & 1)) {
    scrolled_right = (int16)layer2_x_block >= (int16)previous_layer2_x_block;
    if (layer2_x_block != previous_layer2_x_block) {
      previous_layer2_x_block = layer2_x_block;
      if (scrolled_right)
        scroll_offset = 16;
      blocks_to_update_x_block = layer2_x_block + scroll_offset;
      vram_blocks_to_update_x_block = bg2_x_block + scroll_offset;
      blocks_to_update_y_block = layer2_y_block;
      vram_blocks_to_update_y_block = bg2_y_block;
      UploadBackgroundDataColumn();
    }
  }
  scroll_offset = 1;
  scrolled_down = (int16)layer1_y_block >= (int16)previous_layer1_y_block;
  if (layer1_y_block != previous_layer1_y_block) {
    previous_layer1_y_block = layer1_y_block;
    if (scrolled_down)
      scroll_offset = 15;
    blocks_to_update_y_block = layer1_y_block + scroll_offset;
    vram_blocks_to_update_y_block = bg1_y_block + scroll_offset;
    blocks_to_update_x_block = layer1_x_block;
    vram_blocks_to_update_x_block = bg1_x_block;
    UpdateLevelDataRow();
  }
  // If using custom layer 2
  if (!(layer2_scroll_y & 1)) {
    scroll_offset = 1;
    scrolled_down = (int16)layer2_y_block >= (int16)previous_layer2_y_block;
    if (layer2_y_block != previous_layer2_y_block) {
      previous_layer2_y_block = layer2_y_block;
      if (scrolled_down)
        scroll_offset = 15;
      blocks_to_update_y_block = layer2_y_block + scroll_offset;
      vram_blocks_to_update_y_block = bg2_y_block + scroll_offset;
      blocks_to_update_x_block = layer2_x_block;
      vram_blocks_to_update_x_block = bg2_x_block;
      UpdateBackgroundDataRow();
    }
  }
}

/**
* @brief Gets the x and y position of the background and layer blocks
*/
void CalculateBgScrollAndLayerPositionBlocks(void) {  // 0x80A4BB
  bg1_x_block = reg_BG1HOFS / 0x10;
  bg2_x_block = reg_BG2HOFS / 0x10;
  layer1_x_block = (int16)layer1_x_pos >> 4;
  layer2_x_block = (int16)layer2_x_pos >> 4;

  bg1_y_block = reg_BG1VOFS / 0x10;
  bg2_y_block = reg_BG2VOFS / 0x10;
  layer1_y_block = (int16)layer1_y_pos >> 4;
  layer2_y_block = (int16)layer2_y_pos >> 4;
}

/**
* @brief Scrolls the room horizontally and prevents scrolling past a red scroll boundary
*/
void HandleAutoscrolling_X(void) {  // 0x80A528
  uint16 new_layer1_x_pos, half_scroll_pos_on_screen, nearest_left_scroll_bound, half_scroll_index;

  if (!time_is_frozen_flag) {
    uint16 layer1_x_pos_backup = layer1_x_pos;
    layer1_x_pos = IntMax(layer1_x_pos, 0);
    uint16 room_pixel_width = swap16(room_width_in_scrolls - 1);
    layer1_x_pos = IntMin(layer1_x_pos, room_pixel_width);

    uint16 nearest_half_scroll_vertically = (uint16)(layer1_y_pos + 0x80) >> 8;
    half_scroll_pos_on_screen = Mult8x8(nearest_half_scroll_vertically, room_width_in_scrolls);
    nearest_left_scroll_bound = HIBYTE(layer1_x_pos);
    half_scroll_index = half_scroll_pos_on_screen + nearest_left_scroll_bound;

    if (scrolls[half_scroll_index] != kScroll_Red) {
      if (scrolls[half_scroll_index + 1] != kScroll_Red)
        return;
      uint16 left_scroll_bound_pos = layer1_x_pos & 0xFF00;
      uint16 next_scroll_leftwards = layer1_x_pos_backup - camera_x_speed - 2;

      if ((int16)next_scroll_leftwards < (int16)left_scroll_bound_pos) {
        new_layer1_x_pos = left_scroll_bound_pos;
      }
      else {
        nearest_left_scroll_bound = HIBYTE(next_scroll_leftwards);
        half_scroll_index = half_scroll_pos_on_screen + nearest_left_scroll_bound;
        if (scrolls[half_scroll_index] != kScroll_Red)
          new_layer1_x_pos = next_scroll_leftwards;
        else
          new_layer1_x_pos = (next_scroll_leftwards & 0xFF00) + 0x100;
      }
    }

    else {
      uint16 right_scroll_bound_pos = (layer1_x_pos & 0xFF00) + 0x100;
      uint16 next_scroll_rightwards = layer1_x_pos_backup + camera_x_speed + 2;

      if (next_scroll_rightwards >= right_scroll_bound_pos) {
        new_layer1_x_pos = right_scroll_bound_pos;
      }
      else {
        nearest_left_scroll_bound = HIBYTE(next_scroll_rightwards);
        half_scroll_index = half_scroll_pos_on_screen + nearest_left_scroll_bound;
        if (scrolls[half_scroll_index+1] != kScroll_Red)
          new_layer1_x_pos = next_scroll_rightwards;
        else
          new_layer1_x_pos = next_scroll_rightwards & 0xFF00;
      }
    }
    layer1_x_pos = new_layer1_x_pos;
  }
}

/**
* @brief Handles scrolling to the right and prevents scrolling too far
*/
void HandleScrollingWhenTriggeringScrollRight(void) {  // 0x80A641
  uint16 layer1_x_pos_backup = layer1_x_pos;
  if ((int16)ideal_layer1_xpos < (int16)layer1_x_pos) {
    layer1_x_pos = ideal_layer1_xpos;
    layer1_x_subpos = 0;
  }

  uint16 room_pixel_width = swap16(room_width_in_scrolls - 1);
  if (room_pixel_width >= layer1_x_pos) {
    uint16 nearest_half_scroll_vertically = (layer1_y_pos + 0x80) >> 8;
    uint16 half_scroll_pos_on_screen = Mult8x8(nearest_half_scroll_vertically, room_width_in_scrolls);
    uint16 nearest_left_scroll_bound = HIBYTE(layer1_x_pos);
    uint16 half_scroll_index = half_scroll_pos_on_screen + nearest_left_scroll_bound;

    if (scrolls[half_scroll_index + 1] == kScroll_Red) {
      int16 left_scroll_bound_pos = layer1_x_pos & 0xFF00;
      int16 next_scroll_leftwards = layer1_x_pos_backup - camera_x_speed - 2;
      layer1_x_pos = IntMax(left_scroll_bound_pos, next_scroll_leftwards);
    }
  }
  else {
    layer1_x_pos = room_pixel_width;
  }
}

/**
* @brief Handles scrolling to the left and prevents scrolling too far
*/
void HandleScrollingWhenTriggeringScrollLeft(void) {  // 0x80A6BB
  uint16 layer1_x_pos_backup = layer1_x_pos;
  if ((int16)layer1_x_pos < (int16)ideal_layer1_xpos) {
    layer1_x_pos = ideal_layer1_xpos;
    layer1_x_subpos = 0;
  }

  if ((int16)layer1_x_pos >= 0) {
    uint16 nearest_half_scroll_vertically = (layer1_y_pos + 0x80) >> 8;
    uint16 half_scroll_pos_on_screen = Mult8x8(nearest_half_scroll_vertically, room_width_in_scrolls);
    uint16 nearest_left_scroll_bound = HIBYTE(layer1_x_pos);
    uint16 half_scroll_index = half_scroll_pos_on_screen + nearest_left_scroll_bound;

    if (scrolls[half_scroll_index] == kScroll_Red) {
      uint16 right_scroll_bound_pos = (layer1_x_pos & 0xFF00) + 0x100;
      uint16 next_scroll_rightwards = camera_x_speed + layer1_x_pos_backup + 2;
      layer1_x_pos = IntMin(right_scroll_bound_pos, next_scroll_rightwards);
    }
  }
  else {
    layer1_x_pos = 0;
  }
}

/**
* @brief Scrolls the room vertically and prevents scrolling past a red scroll boundary
*/
void HandleAutoscrolling_Y(void) {  // 0x80A731
  int16 nearest_half_scroll_horizontally;
  uint16 new_layer1_y_pos;

  if (!time_is_frozen_flag) {
    uint16 next_scroll_offset = 0;
    uint16 nearest_top_scroll_bound = HIBYTE(layer1_y_pos);
    nearest_half_scroll_horizontally = (uint16)(layer1_x_pos + 0x80) >> 8;
    uint16 half_scroll_pos_on_screen = Mult8x8(nearest_top_scroll_bound, room_width_in_scrolls);
    uint16 half_scroll_index = half_scroll_pos_on_screen + nearest_half_scroll_horizontally;
    if (scrolls[half_scroll_index] != kScroll_Blue)
      next_scroll_offset = 31;

    uint16 layer1_y_pos_backup = layer1_y_pos;
    layer1_y_pos = IntMax(layer1_y_pos, 0);
    uint16 room_pixel_height = swap16(room_height_in_scrolls - 1);
    uint16 scroll_pos = next_scroll_offset + room_pixel_height;
    layer1_y_pos = IntMin(layer1_y_pos, scroll_pos);

    nearest_top_scroll_bound = HIBYTE(layer1_y_pos);
    nearest_half_scroll_horizontally = (uint16)(layer1_x_pos + 0x80) >> 8;
    half_scroll_pos_on_screen = Mult8x8(nearest_top_scroll_bound, room_width_in_scrolls);
    half_scroll_index = half_scroll_pos_on_screen + nearest_half_scroll_horizontally;

    if (scrolls[half_scroll_index] == kScroll_Red) {
      uint16 bottom_scroll_bound_pos = (layer1_y_pos & 0xFF00) + 0x100;
      uint16 next_scroll_downwards = camera_y_speed + layer1_y_pos_backup + 2;

      if (next_scroll_downwards >= bottom_scroll_bound_pos) {
        new_layer1_y_pos = bottom_scroll_bound_pos;
      }
      else {
        nearest_half_scroll_horizontally = (uint16)(layer1_x_pos + 0x80) >> 8;
        nearest_top_scroll_bound = HIBYTE(next_scroll_downwards) + 1;
        half_scroll_pos_on_screen = Mult8x8(nearest_top_scroll_bound, room_width_in_scrolls);
        half_scroll_index = half_scroll_pos_on_screen + nearest_half_scroll_horizontally;
        if (scrolls[half_scroll_index] != kScroll_Red)
          new_layer1_y_pos = next_scroll_downwards;
        else
          new_layer1_y_pos = next_scroll_downwards & 0xFF00;
      }
      layer1_y_pos = new_layer1_y_pos;
      return;
    }

    if (scrolls[(uint16)(room_width_in_scrolls + half_scroll_index)] == kScroll_Red) {
      uint16 top_scroll_bound_pos = next_scroll_offset + (layer1_y_pos & 0xFF00);
      if (top_scroll_bound_pos < layer1_y_pos) {
        uint16 next_scroll_upwards = layer1_y_pos_backup - camera_y_speed - 2;

        if ((int16)next_scroll_upwards < (int16)top_scroll_bound_pos) {
          new_layer1_y_pos = top_scroll_bound_pos;
        }
        else {
          layer1_y_pos_backup = next_scroll_upwards;
          nearest_half_scroll_horizontally = (uint16)(layer1_x_pos + 0x80) >> 8;
          nearest_top_scroll_bound = HIBYTE(next_scroll_upwards);
          half_scroll_pos_on_screen = Mult8x8(nearest_top_scroll_bound, room_width_in_scrolls);
          half_scroll_index = half_scroll_pos_on_screen + nearest_half_scroll_horizontally;
          if (scrolls[half_scroll_index] != kScroll_Red)
            new_layer1_y_pos = layer1_y_pos_backup;
          else
            new_layer1_y_pos = (layer1_y_pos_backup & 0xFF00) + 0x100;
        }
        layer1_y_pos = new_layer1_y_pos;
        return;
      }
    }
  }
}

/**
* @brief Handles scrolling downwards and prevents scrolling too far
*/
void HandleScrollingWhenTriggeringScrollDown(void) {  // 0x80A893
  uint16 layer1_y_pos_backup = layer1_y_pos;
  uint16 next_scroll_offset = 0;
  uint16 nearest_top_scroll_bound = HIBYTE(layer1_y_pos);
  uint16 nearest_half_scroll_horizontally = (uint16)(layer1_x_pos + 0x80) >> 8;
  uint16 half_scroll_pos_on_screen = Mult8x8(nearest_top_scroll_bound, room_width_in_scrolls);
  uint16 half_scroll_index = half_scroll_pos_on_screen + nearest_half_scroll_horizontally;
  if (scrolls[half_scroll_index] != kScroll_Blue)
    next_scroll_offset = 31;

  if ((int16)ideal_layer1_ypos < (int16)layer1_y_pos) {
    layer1_y_pos = ideal_layer1_ypos;
    layer1_y_subpos = 0;
  }
  uint16 room_pixel_height = swap16(room_height_in_scrolls - 1);
  uint16 scroll_pos = next_scroll_offset + room_pixel_height;
  if (scroll_pos < layer1_y_pos || (scrolls[(uint16)(room_width_in_scrolls + half_scroll_index)] == kScroll_Red)
      && (scroll_pos = next_scroll_offset + (layer1_y_pos & 0xFF00), scroll_pos < layer1_y_pos)) {
    int16 next_scroll_upwards = layer1_y_pos_backup - camera_y_speed - 2;
    layer1_y_pos = IntMax((int16)scroll_pos, next_scroll_upwards);
  }
}

/**
* @brief Handles scrolling upwards and prevents scrolling too far
*/
void HandleScrollingWhenTriggeringScrollUp(void) {  // 0x80A936
  uint16 layer1_y_pos_backup = layer1_y_pos;
  if ((int16)layer1_y_pos < (int16)ideal_layer1_ypos) {
    layer1_y_pos = ideal_layer1_ypos;
    layer1_y_subpos = 0;
  }
  if ((int16)layer1_y_pos >= 0) {
    uint16 nearest_top_scroll_bound = HIBYTE(layer1_y_pos);
    uint16 nearest_half_scroll_horizontally = (uint16)(layer1_x_pos + 0x80) >> 8;
    uint16 half_scroll_pos_on_screen = Mult8x8(nearest_top_scroll_bound, room_width_in_scrolls);
    uint16 half_scroll_index = half_scroll_pos_on_screen + nearest_half_scroll_horizontally;
    if (scrolls[half_scroll_index] == kScroll_Red) {
      uint16 bottom_scroll_bound_pos = (layer1_y_pos & 0xFF00) + 0x100;
      uint16 next_scroll_downwards = camera_y_speed + layer1_y_pos_backup + 2;
      layer1_y_pos = IntMin(bottom_scroll_bound_pos, next_scroll_downwards);
    }
  }
  else {
    layer1_y_pos = 0;
  }
}

/**
* @brief Saves or loads the debug scroll positions
*/
void DebugScrollPosSaveLoad(void) {  // 0x80A9AC
  if (joypad2_new_keys & kButton_X)
    ++debug_saveload_scrollpos_toggle;
  if (debug_saveload_scrollpos_toggle & 1) {
    layer1_x_pos = debug_saved_xscroll;
    layer1_y_pos = debug_saved_yscroll;
  }
  else {
    debug_saved_xscroll = layer1_x_pos;
    debug_saved_yscroll = layer1_y_pos;
  }
}

/**
* @brief Updates the column of the background data
*/
void UploadBackgroundDataColumn(void) {  // 0x80A9D6
  uint16 bg_offset = ADDR16_OF_RAM(bg2_update_col_unwrapped_size) - ADDR16_OF_RAM(bg1_update_col_unwrapped_size);
  UpdateLevelOrBackgroundDataColumn(bg_offset);
}

/**
* @brief Updates the column of the level data
*/
void UploadLevelDataColumn(void) {  // 0x80A9DB
  UpdateLevelOrBackgroundDataColumn(0);
}

/**
* @brief Updates the column of the layer
* @param update_layer_2 Selects the layer to update, if its zero then the level data is updated,
* @param otherwise the background data is updated
*/
void UpdateLevelOrBackgroundDataColumn(uint16 update_layer_2) {  // 0x80A9DE
  const uint16 *blocks_to_update;
  if (irq_enable_mode7)
    return;

  uint16 y_block_index = Mult8x8(blocks_to_update_y_block, room_width_in_blocks);
  uint16 blocks_to_update_index = 2 * (y_block_index + blocks_to_update_x_block);
  if (update_layer_2) {
    blocks_to_update = custom_background + (blocks_to_update_index >> 1);
  }
  else {
    blocks_to_update = level_data + (blocks_to_update_index >> 1);
  }
  if (update_layer_2) {
    bg2_update_col_wrapped_size = 4 * (vram_blocks_to_update_y_block & 0xF);
    bg2_update_col_unwrapped_size = 4 * (16 - (vram_blocks_to_update_y_block & 0xF));
  }
  else {
    bg1_update_col_wrapped_size = 4 * (vram_blocks_to_update_y_block & 0xF);
    bg1_update_col_unwrapped_size = 4 * (16 - (vram_blocks_to_update_y_block & 0xF));
  }

  uint16 vram_y_block_index = Mult8x8(vram_blocks_to_update_y_block & 0xF, 0x20);
  uint16 vram_x_block_index = vram_blocks_to_update_x_block & 0x1F;
  uint16 vram_blocks_to_update_offset = 2 * (vram_y_block_index + vram_x_block_index);
  uint16 vram_screen_addr = addr_kVram_1stScreen;
  if (vram_x_block_index >= 16)
    vram_screen_addr = addr_kVram_2ndScreenOffset;
  if (update_layer_2)
    vram_screen_addr -= size_of_bg2;
  if (update_layer_2) {
    bg2_update_col_unwrapped_dst = vram_blocks_to_update_offset + vram_screen_addr;
    bg2_update_col_wrapped_dst = 2 * vram_x_block_index + vram_screen_addr;
  }
  else {
    bg1_update_col_unwrapped_dst = vram_blocks_to_update_offset + vram_screen_addr;
    bg1_update_col_wrapped_dst = 2 * vram_x_block_index + vram_screen_addr;
  }

  uint16 new_layer_tilemap = ADDR16_OF_RAM(*bg1_column_update_tilemap_left_halves);
  uint16 vram_src_index = 0;
  if (update_layer_2) {
    new_layer_tilemap = ADDR16_OF_RAM(*bg2_column_update_tilemap_left_halves);
    vram_src_index = 0x108;
  }
  if (update_layer_2) {
    bg2_update_col_wrapped_left_src = bg2_update_col_unwrapped_size + new_layer_tilemap;
    bg2_update_col_wrapped_right_src = bg2_update_col_wrapped_left_src + 64;
  }
  else {
    bg1_update_col_wrapped_left_src = bg1_update_col_unwrapped_size + new_layer_tilemap;
    bg1_update_col_wrapped_right_src = bg1_update_col_wrapped_left_src + 64;
  }

  uint16 num_row_offset = 0;
  for (uint16 col_ctr = 16; col_ctr > 0; col_ctr--) {
    uint16 block_to_update = blocks_to_update[num_row_offset >> 1];
    uint16 block_tile_offset = block_to_update & 0x3FF;
    uint16 block_flip_type = block_to_update & (BLK_VERT_FLIP | BLK_HORIZ_FLIP);
    uint16 offset = vram_src_index >> 1;

    if (block_flip_type & BLK_HAS_FLIP) {
      if (block_flip_type == BLK_HORIZ_FLIP) {
        bg1_column_update_tilemap_left_halves[offset] = tile_table.tables[block_tile_offset].top_right ^ BLK_X_FLIP;
        bg1_column_update_tilemap_right_halves[offset] = tile_table.tables[block_tile_offset].top_left ^ BLK_X_FLIP;
        bg1_column_update_tilemap_left_halves[offset + 1] = tile_table.tables[block_tile_offset].bottom_right ^ BLK_X_FLIP;
        bg1_column_update_tilemap_right_halves[offset + 1] = tile_table.tables[block_tile_offset].bottom_left ^ BLK_X_FLIP;
      }
      else {
        if (block_flip_type == BLK_VERT_FLIP) {
          bg1_column_update_tilemap_left_halves[offset] = tile_table.tables[block_tile_offset].bottom_left ^ BLK_Y_FILP;
          bg1_column_update_tilemap_right_halves[offset] = tile_table.tables[block_tile_offset].bottom_right ^ BLK_Y_FILP;
          bg1_column_update_tilemap_left_halves[offset + 1] = tile_table.tables[block_tile_offset].top_left ^ BLK_Y_FILP;
          bg1_column_update_tilemap_right_halves[offset + 1] = tile_table.tables[block_tile_offset].top_right ^ BLK_Y_FILP;
        }
        else {
          bg1_column_update_tilemap_left_halves[offset] = tile_table.tables[block_tile_offset].bottom_right ^ BLK_X_Y_FLIP;
          bg1_column_update_tilemap_right_halves[offset] = tile_table.tables[block_tile_offset].bottom_left ^ BLK_X_Y_FLIP;
          bg1_column_update_tilemap_left_halves[offset + 1] = tile_table.tables[block_tile_offset].top_right ^ BLK_X_Y_FLIP;
          bg1_column_update_tilemap_right_halves[offset + 1] = tile_table.tables[block_tile_offset].top_left ^ BLK_X_Y_FLIP;
        }
      }
    }
    else {
      bg1_column_update_tilemap_left_halves[offset] = tile_table.tables[block_tile_offset].top_left;
      bg1_column_update_tilemap_right_halves[offset] = tile_table.tables[block_tile_offset].top_right;
      bg1_column_update_tilemap_left_halves[offset + 1] = tile_table.tables[block_tile_offset].bottom_left;
      bg1_column_update_tilemap_right_halves[offset + 1] = tile_table.tables[block_tile_offset].bottom_right;
    }
    vram_src_index += 4;
    num_row_offset += room_width_in_blocks * 2;
  }

  if (update_layer_2) {
    ++bg2_update_col_enable;
  }
  else {
    ++bg1_update_col_enable;
  }
}

/**
* @brief Updates the row of the background data
*/
void UpdateBackgroundDataRow(void) {  // 0x80AB70
  uint16 bg_offset = ADDR16_OF_RAM(bg2_update_row_unwrapped_size) - ADDR16_OF_RAM(bg1_update_row_unwrapped_size);
  UpdateLevelOrBackgroundDataRow(bg_offset);
}

/**
* @brief Updates the row of the level data
*/
void UpdateLevelDataRow(void) {  // 0x80AB75
  UpdateLevelOrBackgroundDataRow(0);
}

/**
* @brief Updates the row of the layer
* @param update_layer_2 Sets the layer to update, if its zero then the level data is updated,
* @param otherwise the background data is updated
*/
void UpdateLevelOrBackgroundDataRow(uint16 update_layer_2) {  // 0x80AB78
  const uint16 *blocks_to_update;
  if (irq_enable_mode7)
    return;

  uint16 y_block_index = Mult8x8(blocks_to_update_y_block, room_width_in_blocks);
  uint16 blocks_to_update_index = 2 * (y_block_index + blocks_to_update_x_block);
  if (update_layer_2) {
    blocks_to_update = custom_background + (blocks_to_update_index >> 1);
  }
  else {
    blocks_to_update = level_data + (blocks_to_update_index >> 1);
  }
  if (update_layer_2) {
    bg2_update_row_unwrapped_size = 4 * (16 - (vram_blocks_to_update_x_block & 0xF));
    bg2_update_row_wrapped_size = 4 * ((vram_blocks_to_update_x_block & 0xF) + 1);
  }
  else {
    bg1_update_row_unwrapped_size = 4 * (16 - (vram_blocks_to_update_x_block & 0xF));
    bg1_update_row_wrapped_size = 4 * ((vram_blocks_to_update_x_block & 0xF) + 1);
  }

  uint16 vram_y_block_index = Mult8x8(vram_blocks_to_update_y_block & 0xF, 0x20);
  uint16 vram_x_block_index = vram_blocks_to_update_x_block & 0x1F;
  uint16 vram_blocks_to_update_offset = 2 * (vram_y_block_index + vram_x_block_index);
  uint16 wrapped_vram_screen_addr = addr_kVram_2ndScreen;
  uint16 vram_screen_addr = addr_kVram_1stScreen;
  if (vram_x_block_index >= 16) {
    wrapped_vram_screen_addr = addr_kVram_1stScreen;
    vram_screen_addr = addr_kVram_2ndScreenOffset;
  }
  if (update_layer_2)
    vram_screen_addr -= size_of_bg2;

  if (update_layer_2) {
    bg2_update_row_unwrapped_dst = vram_blocks_to_update_offset + vram_screen_addr;
  }
  else {
    bg1_update_row_unwrapped_dst = vram_blocks_to_update_offset + vram_screen_addr;
  }
  if (update_layer_2) {
    wrapped_vram_screen_addr -= size_of_bg2;
  }
  if (update_layer_2) {
    bg2_update_row_wrapped_dst = 2 * vram_y_block_index + wrapped_vram_screen_addr;
  }
  else {
    bg1_update_row_wrapped_dst = 2 * vram_y_block_index + wrapped_vram_screen_addr;
  }

  uint16 new_layer_tilemap = ADDR16_OF_RAM(*bg1_row_update_tilemap_top_halves);
  uint16 vram_src_index = 0;
  if (update_layer_2) {
    new_layer_tilemap = ADDR16_OF_RAM(*bg2_row_update_tilemap_top_halves);
    vram_src_index = 0x108;
  }
  if (update_layer_2) {
    bg2_update_row_wrapped_top_src = bg2_update_row_unwrapped_size + new_layer_tilemap;
    bg2_update_row_wrapped_bottom_src = bg2_update_row_wrapped_top_src + 68;
  }
  else {
    bg1_update_row_wrapped_top_src = bg1_update_row_unwrapped_size + new_layer_tilemap;
    bg1_update_row_wrapped_bottom_src = bg1_update_row_wrapped_top_src + 68;
  }

  uint16 num_col_offset = 0;
  for (uint16 row_ctr = 17; row_ctr > 0; row_ctr--) {
    uint16 block_to_update = blocks_to_update[num_col_offset >> 1];
    uint16 block_tile_offset = block_to_update & 0x3FF;
    uint16 block_flip_type = block_to_update & (BLK_VERT_FLIP | BLK_HORIZ_FLIP);
    uint16 offset = vram_src_index >> 1;

    if (block_to_update & BLK_HAS_FLIP) {
      if (block_flip_type == BLK_HORIZ_FLIP) {
        bg1_row_update_tilemap_top_halves[offset] = tile_table.tables[block_tile_offset].top_right ^ BLK_X_FLIP;
        bg1_row_update_tilemap_top_halves[offset + 1] = tile_table.tables[block_tile_offset].top_left ^ BLK_X_FLIP;
        bg1_row_update_tilemap_bottom_halves[offset] = tile_table.tables[block_tile_offset].bottom_right ^ BLK_X_FLIP;
        bg1_row_update_tilemap_bottom_halves[offset + 1] = tile_table.tables[block_tile_offset].bottom_left ^ BLK_X_FLIP;
      } else {
        if (block_flip_type == BLK_VERT_FLIP) {
          bg1_row_update_tilemap_top_halves[offset] = tile_table.tables[block_tile_offset].bottom_left ^ BLK_Y_FILP;
          bg1_row_update_tilemap_top_halves[offset + 1] = tile_table.tables[block_tile_offset].bottom_right ^ BLK_Y_FILP;
          bg1_row_update_tilemap_bottom_halves[offset] = tile_table.tables[block_tile_offset].top_left ^ BLK_Y_FILP;
          bg1_row_update_tilemap_bottom_halves[offset + 1] = tile_table.tables[block_tile_offset].top_right ^ BLK_Y_FILP;
        } else {
          bg1_row_update_tilemap_top_halves[offset] = tile_table.tables[block_tile_offset].bottom_right ^ BLK_X_Y_FLIP;
          bg1_row_update_tilemap_top_halves[offset + 1] = tile_table.tables[block_tile_offset].bottom_left ^ BLK_X_Y_FLIP;
          bg1_row_update_tilemap_bottom_halves[offset] = tile_table.tables[block_tile_offset].top_right ^ BLK_X_Y_FLIP;
          bg1_row_update_tilemap_bottom_halves[offset + 1] = tile_table.tables[block_tile_offset].top_left ^ BLK_X_Y_FLIP;
        }
      }
    }
    else {
      bg1_row_update_tilemap_top_halves[offset] = tile_table.tables[block_tile_offset].top_left;
      bg1_row_update_tilemap_top_halves[offset + 1] = tile_table.tables[block_tile_offset].top_right;
      bg1_row_update_tilemap_bottom_halves[offset] = tile_table.tables[block_tile_offset].bottom_left;
      bg1_row_update_tilemap_bottom_halves[offset + 1] = tile_table.tables[block_tile_offset].bottom_right;
    }
    vram_src_index += 4;
    num_col_offset += 2;
  }

  if (update_layer_2) {
    ++bg2_update_row_enable;
  }
  else {
    ++bg1_update_row_enable;
  }
}

/**
* @brief Draws the top row and starts the up door transition
*/
void FixDoorsMovingUp(void) {  // 0x80AD1D
  door_transition_frame_counter = 0;
  CalculateBgScrollAndLayerPositionBlocks();
  UpdatePreviousLayerBlocks();
  ++previous_layer1_y_block;
  ++previous_layer2_y_block;
  DoorTransition_Up();
}

static Func_V *const kDoorTransitionSetupFuncs[4] = {  // 0x80AD30
  DoorTransitionScrollingSetup_Right,
  DoorTransitionScrollingSetup_Left,
  DoorTransitionScrollingSetup_Down,
  DoorTransitionScrollingSetup_Up,
};

/**
* @brief Updates the layers and background positions and starts the door transition
*/
void DoorTransitionScrollingSetup(void) {
  layer1_x_pos = door_destination_x_pos;
  layer1_y_pos = door_destination_y_pos;
  kDoorTransitionSetupFuncs[door_direction & kDoorDirection_DirectionMask]();
}

/**
* @brief Updates the layers and background positions and starts the right door transition
*/
void DoorTransitionScrollingSetup_Right(void) {  // 0x80AD4A
  CalculateLayer2Xpos();
  layer2_x_pos -= 256;
  CalculateLayer2Ypos();
  layer1_x_pos -= 256;
  UpdateBgScrollOffsets();
  CalculateBgScrollAndLayerPositionBlocks();
  UpdatePreviousLayerBlocks();
  --previous_layer1_x_block;
  --previous_layer2_x_block;
  DoorTransition_Right();
}

/**
* @brief Updates the layers and background positions and starts the left door transition
*/
void DoorTransitionScrollingSetup_Left(void) {  // 0x80AD74
  CalculateLayer2Xpos();
  layer2_x_pos += 256;
  CalculateLayer2Ypos();
  layer1_x_pos += 256;
  UpdateBgScrollOffsets();
  CalculateBgScrollAndLayerPositionBlocks();
  UpdatePreviousLayerBlocks();
  ++previous_layer1_x_block;
  ++previous_layer2_x_block;
  DoorTransition_Left();
}

/**
* @brief Updates the layers and background positions and starts the down door transition
*/
void DoorTransitionScrollingSetup_Down(void) {  // 0x80AD9E
  CalculateLayer2Xpos();
  CalculateLayer2Ypos();
  layer2_y_pos -= 224;
  layer1_y_pos -= 224;
  UpdateBgScrollOffsets();
  CalculateBgScrollAndLayerPositionBlocks();
  UpdatePreviousLayerBlocks();
  --previous_layer1_y_block;
  --previous_layer2_y_block;
  DoorTransition_Down();
}

/**
* @brief Updates the layers and background positions and starts the up door transition
*/
void DoorTransitionScrollingSetup_Up(void) {  // 0x80ADC8
  CalculateLayer2Xpos();
  uint16 layer1_y_pos_backup = layer1_y_pos;
  layer1_y_pos += 31;
  CalculateLayer2Ypos();
  layer2_y_pos += 224;
  layer1_y_pos = layer1_y_pos_backup + 256;
  UpdateBgScrollOffsets();
  door_destination_y_pos += 32;
  CalculateBgScrollAndLayerPositionBlocks();
  UpdatePreviousLayerBlocks();
  ++previous_layer1_y_block;
  ++previous_layer2_y_block;
  --layer1_y_pos;
  DoorTransition_Up();
}

/**
* @brief Updates the previous layer blocks with the current layer blocks
*/
void UpdatePreviousLayerBlocks(void) {  // 0x80AE10
  previous_layer1_x_block = layer1_x_block;
  previous_layer2_x_block = layer2_x_block;
  previous_layer1_y_block = layer1_y_block;
  previous_layer2_y_block = layer2_y_block;
}

/**
* @brief Updates the background scroll offsets during door transitions
*/
void UpdateBgScrollOffsets(void) {  // 0x80AE29
  bg1_x_offset = reg_BG1HOFS - layer1_x_pos;
  bg1_y_offset = reg_BG1VOFS - layer1_y_pos;
  bg2_x_scroll = reg_BG2HOFS - layer1_x_pos;
  bg2_y_scroll = reg_BG2VOFS - layer1_y_pos;
}

static Func_U8 *const kDoorTransitionFuncs[4] = {
  DoorTransition_Right,
  DoorTransition_Left,
  DoorTransition_Down,
  DoorTransition_Up,
};

/**
* @brief Scrolls Samus and the layers in the direction of the door for an amount of frames
*/
void Irq_FollowDoorTransition(void) {
  if (kDoorTransitionFuncs[door_direction & kDoorDirection_DirectionMask]()) {
    layer1_x_pos = door_destination_x_pos;
    layer1_y_pos = door_destination_y_pos;
    door_transition_flag |= 0x8000;
  }
}

/**
* @brief Moves Samus and the layers right for 64 frames
* @return uint8 true if the door transition is finished, false if it isn't finished
*/
uint8 DoorTransition_Right(void) {  // 0x80AE7E
  AddToHiLo(&samus_x_pos, &samus_x_subpos, __PAIR32__(samus_door_transition_speed, samus_door_transition_subspeed));
  samus_prev_x_pos = samus_x_pos;
  layer1_x_pos += 4;
  layer2_x_pos += 4;
  UpdateScrollVarsUpdateMap();
  door_transition_frame_counter += 1;
  if (door_transition_frame_counter != 64)
    return 0;
  UpdateScrollVarsUpdateMap();
  return 1;
}

/**
* @brief Moves Samus and the layers left for 64 frames
* @return uint8 true if the door transition is finished, false if it isn't finished
*/
uint8 DoorTransition_Left(void) {  // 0x80AEC2
  AddToHiLo(&samus_x_pos, &samus_x_subpos, -IPAIR32(samus_door_transition_speed, samus_door_transition_subspeed));
  samus_prev_x_pos = samus_x_pos;
  layer1_x_pos -= 4;
  layer2_x_pos -= 4;
  UpdateScrollVarsUpdateMap();
  door_transition_frame_counter += 1;
  return door_transition_frame_counter == 64;
}

/**
* @brief Draws the top row of the room for the first frame, then moves Samus and the layers down for the next 56 frames
* @return uint8 true if the door transition is finished, false if it isn't finish
*/
uint8 DoorTransition_Down(void) {  // 0x80AF02
  if (door_transition_frame_counter != 0) {
    if (door_transition_frame_counter < 57) {
      AddToHiLo(&samus_y_pos, &samus_y_subpos, __PAIR32__(samus_door_transition_speed, samus_door_transition_subspeed));
      samus_prev_y_pos = samus_y_pos;
      layer1_y_pos += 4;
      layer2_y_pos += 4;
      UpdateScrollVarsUpdateMap();
    }
  }
  else {
    uint16 reg_BG1VOFS_backup = reg_BG1VOFS;
    uint16 reg_BG2VOFS_backup = reg_BG2VOFS;
    uint16 layer1_y_pos_backup = layer1_y_pos;
    layer1_y_pos -= 15;
    uint16 layer2_y_pos_backup = layer2_y_pos;
    layer2_y_pos -= 15;
    CalculateBgScrollAndLayerPositionBlocks();
    UpdatePreviousLayerBlocks();
    --previous_layer1_y_block;
    --previous_layer2_y_block;
    UpdateScrollVarsUpdateMap();
    layer2_y_pos = layer2_y_pos_backup;
    layer1_y_pos = layer1_y_pos_backup;
    reg_BG2VOFS = reg_BG2VOFS_backup;
    reg_BG1VOFS = reg_BG1VOFS_backup;
  }
  door_transition_frame_counter += 1;
  if (door_transition_frame_counter < 57)
    return 0;
  UpdateScrollVarsUpdateMap();
  return 1;
}

/**
* @brief Draws the top row of the room for the first four frames, then moves Samus and the layers down for the next 52 frames
* @return uint8 true if the door transition is finished, false if it isn't finish
*/
uint8 DoorTransition_Up(void) {  // 0x80AF89
  if (door_transition_frame_counter != 0) {
    AddToHiLo(&samus_y_pos, &samus_y_subpos, -IPAIR32(samus_door_transition_speed, samus_door_transition_subspeed));
    samus_prev_y_pos = samus_y_pos;
    layer1_y_pos -= 4;
    layer2_y_pos -= 4;
    if (door_transition_frame_counter >= 5) {
      UpdateScrollVarsUpdateMap();
    }
    else {
      reg_BG1HOFS = bg1_x_offset + layer1_x_pos;
      reg_BG1VOFS = bg1_y_offset + layer1_y_pos;
      reg_BG2HOFS = bg2_x_scroll + layer2_x_pos;
      reg_BG2VOFS = bg2_y_scroll + layer2_y_pos;
    }
  }
  else {
    uint16 reg_BG1VOFS_backup = reg_BG1VOFS;
    uint16 reg_BG2VOFS_backup = reg_BG2VOFS;
    uint16 layer1_y_pos_backup = layer1_y_pos;
    layer1_y_pos -= 16;
    uint16 layer2_y_pos_backup = layer2_y_pos;
    layer2_y_pos -= 16;
    CalculateBgScrollAndLayerPositionBlocks();
    UpdatePreviousLayerBlocks();
    ++previous_layer1_y_block;
    ++previous_layer2_y_block;
    UpdateScrollVarsUpdateMap();
    layer2_y_pos = layer2_y_pos_backup;
    layer1_y_pos = layer1_y_pos_backup;
    reg_BG2VOFS = reg_BG2VOFS_backup;
    reg_BG1VOFS = reg_BG1VOFS_backup;
  }
  door_transition_frame_counter += 1;
  return door_transition_frame_counter == 57;
}

void UNUSED_ConfigureMode7RotationMatrix(void) {  // 0x80B0C2
  if (irq_enable_mode7) {
    if ((nmi_frame_counter_word & 7) == 0) {
      reg_M7B = kSinCosTable8bit_Sext[((uint8)mode7_rotation_angle) + 64];
      reg_M7C = -reg_M7B;
      reg_M7A = kSinCosTable8bit_Sext[((uint8)(mode7_rotation_angle + 64)) + 64];
      reg_M7D = reg_M7A;
      ++mode7_rotation_angle;
    }
  }
}

static uint32 decompress_src;

/**
* @brief Gets the current byte from the ROM and goes to the next one
* @return uint8 The decompressed byte
*/
static uint8 DecompNextByte() {
  uint8 b = *RomPtr(decompress_src);
  // Handle reaching the end of the bank
  if ((decompress_src++ & 0xffff) == 0xffff)
    decompress_src += 0x8000;
  return b;
}

/**
* @brief Decompresses the incoming data to RAM
* @param src The source address of the compressed data
* @param decompress_dst The RAM location to decompress the data
*/
void DecompressToMem(uint32 src, uint8 *decompress_dst) {  // 0x80B119
  decompress_src = src;
  int src_pos, dst_pos = 0;
  while (1) {
    int len;
    uint8 b = DecompNextByte(), cmd;
    if (b == 0xFF)
      break;
    if ((b & 0xE0) == 0xE0) {
      cmd = (8 * b) & 0xE0;
      len = ((b & 3) << 8 | DecompNextByte()) + 1;
    } else {
      cmd = b & 0xE0;
      len = (b & 0x1F) + 1;
    }
    if (cmd & 0x80) {
      uint8 want_xor = cmd & 0x20 ? 0xff : 0;
      if (cmd >= 0xC0) {
        src_pos = dst_pos - DecompNextByte();
      } else {
        src_pos = DecompNextByte();
        src_pos += DecompNextByte() * 256;
      }
      do {
        b = decompress_dst[src_pos++] ^ want_xor;
        decompress_dst[dst_pos++] = b;
      } while (--len);
    } else {
      switch (cmd) {
      case 0x20:
        b = DecompNextByte();
        do {
          decompress_dst[dst_pos++] = b;
        } while (--len);
        break;
      case 0x40: {
        b = DecompNextByte();
        uint8 b2 = DecompNextByte();
        do {
          decompress_dst[dst_pos++] = b;
          if (!--len)
            break;
          decompress_dst[dst_pos++] = b2;
        } while (--len);
        break;
      }
      case 0x60:
        b = DecompNextByte();
        do {
          decompress_dst[dst_pos++] = b++;
        } while (--len);
        break;
      default:
        do {
          b = DecompNextByte();
          decompress_dst[dst_pos++] = b;
        } while (--len);
        break;
      }
    }
  }
}

/**
* @brief Gets the current byte from the PPU and goes to the next one
* @return uint8 Either return the high byte or the low byte
*/
static uint8 ReadPpuByte(uint16 addr) {
  WriteRegWord(VMADDL, addr >> 1);
  ReadRegWord(RDVRAML);  // latch
  uint16 data = ReadRegWord(RDVRAML);
  return (addr & 1) ? HIBYTE(data) : LOBYTE(data);
}

/**
* @brief Decompresses the incoming data to VRAM
* @param src The source address of the compressed data
* @param dst_addr The VRAM destination to decompress the data
*/
void DecompressToVRAM(uint32 src, uint16 dst_addr) {  // 0x80B271
  decompress_src = src;
  int src_pos, dst_pos = dst_addr;
  while (1) {
    int len;
    uint8 b = DecompNextByte(), cmd;
    if (b == 0xFF)
      break;
    if ((b & 0xE0) == 0xE0) {
      cmd = (8 * b) & 0xE0;
      len = ((b & 3) << 8 | DecompNextByte()) + 1;
    } else {
      cmd = b & 0xE0;
      len = (b & 0x1F) + 1;
    }
    if (cmd & 0x80) {
      uint8 want_xor = cmd & 0x20 ? 0xff : 0;
      if (cmd >= 0xC0) {
        src_pos = dst_pos - DecompNextByte();
      } else {
        src_pos = DecompNextByte();
        src_pos += DecompNextByte() * 256;
        src_pos += dst_addr;
      }
      do {
        b = ReadPpuByte(src_pos++) ^ want_xor;
        WriteRegWord(VMADDL, dst_pos >> 1);
        WriteReg(VMDATAL + (dst_pos++ & 1), b);
      } while (--len);
    } else {
      switch (cmd) {
      case 0x20:
        b = DecompNextByte();
        do {
          WriteReg(VMDATAL + (dst_pos++ & 1), b);
        } while (--len);
        break;
      case 0x40: {
        b = DecompNextByte();
        uint8 b2 = DecompNextByte();
        do {
          WriteReg(VMDATAL + (dst_pos++ & 1), b);
          if (!--len)
            break;
          WriteReg(VMDATAL + (dst_pos++ & 1), b2);
        } while (--len);
        break;
      }
      case 0x60:
        b = DecompNextByte();
        do {
          WriteReg(VMDATAL + (dst_pos++ & 1), b++);
        } while (--len);
        break;
      default:
        do {
          b = DecompNextByte();
          WriteReg(VMDATAL + (dst_pos++ & 1), b++);
        } while (--len);
        break;
      }
    }
  }
}

/**
* @brief Sets the room to start from when initially loading into the game
*/
void LoadFromLoadStation(void) {  // 0x80C437
  save_station_lockout_flag = 1;
  const LoadStationList L = kLoadStationLists[area_index][load_station_index];
  room_ptr = L.room_ptr_;
  door_def_ptr = L.door_ptr;
//  door_bts = v0[2];
  bg1_x_offset = layer1_x_pos = L.screen_x_pos;
  bg1_y_offset = layer1_y_pos = L.screen_y_pos;
  samus_prev_y_pos = samus_y_pos = layer1_y_pos + L.samus_y_offset;
  samus_prev_x_pos = samus_x_pos = layer1_x_pos + L.samus_x_offset + 0x80;
  reg_BG1HOFS = 0;
  reg_BG1VOFS = 0;
  LOBYTE(area_index) = get_RoomDefHeader(room_ptr).area_index_;
  LOBYTE(debug_disable_minimap) = 0;
}

/**
* @brief Sets the debug elevator to used. This is never called normally since
* @brief elevator_door_properties & kElevatorDoor_DebugElevatorBitmask is always false
*/
void SetDebugElevatorsAsUsed(void) {  // 0x80CD07
  const ElevatorsUsedConf E = kAreaElevatorBits[area_index][(elevator_door_properties & kElevatorDoor_DebugElevatorBitmask) - 1];
  used_save_stations_and_elevators[E.src_area] |= E.src_bit;
  used_save_stations_and_elevators[E.dst_area] |= E.dst_bit;
}
