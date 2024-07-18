// PLMs

#include <stdio.h>

#include "ida_types.h"
#include "variables.h"
#include "sm_rtl.h"
#include "funcs.h"
#include "sm_84.h"



void CallPlmPreInstr(uint32 ea, uint16 k);
const uint8 *CallPlmInstr(uint32 ea, const uint8 *j, uint16 k);
uint8 CallPlmHeaderFunc(uint32 ea, uint16 j);
const uint8 *PlmInstr_LoadItemPlmGfx(const uint8 *plmp, uint16 k);

/**
* @brief Sets the Golden Torizo palette based off the amount of health it has left
* @param torizo_health The health of the Golden Torizo
*/
void SetGoldenTorizoPalette(uint16 torizo_health) {  // 0x848000
  uint16 health_range = HIBYTE(torizo_health) & 0x78;
  if (health_range & 0x40)
    health_range = 0x38;

  uint16 src_idx = 4 * health_range;
  src_idx >>= 1;
  MemCpy(palette_buffer.sprite_pal_2, kGoldenTorizoPalette2 + src_idx, sizeof(palette_buffer.sprite_pal_2));
  MemCpy(palette_buffer.sprite_pal_1, kGoldenTorizoPalette1 + src_idx, sizeof(palette_buffer.sprite_pal_1));
}

/**
* @brief Loads the item PLM graphics in the room
*/
void LoadRoomPlmGfx(void) {  // 0x848232
  plm_item_gfx_index = 0;
  for (int item_plm_idx = 0; item_plm_idx < 8; item_plm_idx += 2) {
    if (plm_item_gfx_ptrs[item_plm_idx >> 1] != 0)
      PlmInstr_LoadItemPlmGfx(RomPtr_84(plm_item_gfx_ptrs[item_plm_idx >> 1]), item_plm_idx);
  }
}

/**
* @brief Runs the code for clearing sounds when going through a door
*/
void ClearSoundsWhenGoingThroughDoor(void) {  // 0x848250
  RunSamusCode(kSamusCode_29_ClearSoundInDoor);
}

void UNUSED_sub_848258(void) {  // 0x848258
  if (samus_movement_type == kMovementType_03_SpinJumping || samus_movement_type == kMovementType_14_WallJumping)
    QueueSfx1_Max15(kSfx1_SpinJumpEnd_Silence);
}

/**
* @brief Runs the code for playing the spin jump sound if spin jumping
*/
void PlaySpinJumpSoundIfSpinJumping(void) {  // 0x848270
  RunSamusCode(kSamusCode_28_PlaySpinSfxIfSpinJumping);
}

void UNUSED_sub_848278(void) {  // 0x848278
  if (samus_movement_type == kMovementType_03_SpinJumping || samus_movement_type == kMovementType_14_WallJumping)
    QueueSfx1_Max15(kSfx1_ResumedSpinJump);
}

/**
* @brief Calculates the PLM block (x, y) coordinates
*/
void CalculatePlmBlockCoords(uint16 plm_idx) {  // 0x848290
  uint16 plm_block_idx = plm_block_indices[plm_idx >> 1] / 2;
  plm_y_block = SnesDivide(plm_block_idx, room_width_in_blocks);
  plm_x_block = SnesModulus(plm_block_idx, room_width_in_blocks);
}

/**
* @brief Writes the block type and BTS to the PLM block
* @param plm_blk_idx The index of the PLM block
* @param plm_blk_data The low byte is the BTS type, the high byte is the block type
*/
void WriteLevelDataBlockTypeAndBts(uint16 plm_blk_idx, uint16 plm_blk_data) {  // 0x8482B4
  uint8 *plm_blk_type = &HIBYTE(level_data[plm_blk_idx >> 1]);
  *plm_blk_type = HIBYTE(plm_blk_data) | *plm_blk_type & 0xF;
  BTS[plm_blk_idx >> 1] = LOBYTE(plm_blk_data);
}

/**
* @brief Writes a row of level data and BTS blocks
* @param plm_idx The index of the PLM block
* @param level_data_blk The level data block
* @param bts_blk The BTS block
* @param num_blks The number of blocks to write
*/
void WriteRowOfLevelDataBlockAndBTS(uint16 plm_idx, uint16 level_data_blk, uint16 bts_blk, uint16 num_blks) {  // 0x8482D6
  uint16 plm_blk_idx = plm_block_indices[plm_idx >> 1] >> 1;
  for (int blk = 0; blk < num_blks; blk++) {
    level_data[plm_blk_idx + blk] = level_data_blk;
    BTS[plm_blk_idx + blk] = bts_blk;
  }
}

/**
* @brief Loads uncollected item PLMs Xray blocks and special Xray blocks
*/
void LoadXrayBlocks(void) {  // 0x84831A
  for (int plm_idx = MAX_PLMS-2; plm_idx >= 0; plm_idx -= 2) {
    int idx = plm_idx >> 1;
    if (plm_header_ptr[idx] >= FUNC16(PlmPreInstr_GotoLinkIfTriggered)) {
      uint16 item_collected = item_bit_array[PrepareBitAccess(plm_room_arguments[idx])];
      if (!(item_collected & bitmask)) {
        CalculatePlmBlockCoords(plm_idx);
        const uint8 *xray_blk_draw_instr_ptr = RomPtr_84(kXrayBlockDrawingInstrs[plm_variables[idx] >> 1]);
        uint16 blk_to_draw = GET_WORD(xray_blk_draw_instr_ptr + 2) & 0xFFF;
        LoadBlockToXrayBg2(blk_to_draw, plm_x_block, plm_y_block);
      }
    }
  }

  RoomDefRoomstate RS = get_RoomDefRoomstate(roomdefroomstate_ptr);
  if (RS.xray_special_casing_ptr != 0) {
    const XraySpecialCasing *p = get_XraySpecialCasing(RS.xray_special_casing_ptr);
    for (p; p->x_block || p->y_block; p++)
      LoadBlockToXrayBg2(p->level_data_block, p->x_block, p->y_block);
  }
}

/**
* @brief Sets the PLM flag to enabled
*/
void EnablePLMs(void) {  // 0x8483AD
  plm_flag |= PLMS_ENABLED;
}

/**
* @brief Sets the PLM flag to disabled
*/
void DisablePLMs(void) {  // 0x8483B8
  plm_flag &= ~PLMS_ENABLED;
}

/**
* @brief Clears all PLMs
*/
void ClearPLMs(void) {  // 0x8483C3
  memset7E(plm_header_ptr, 0, MAX_PLMS);
  plm_item_gfx_index = 0;
}

/**
* @brief Spawns a PLM with hardcoded arguments
* @param p The arguments for the PLM
*/
void SpawnHardcodedPlm(SpawnHardcodedPlmArgs p) {  // 0x8483D7
  int16 plm_idx = MAX_PLMS-2;
  while (plm_header_ptr[plm_idx >> 1] != 0) {
    plm_idx -= 2;
    if (plm_idx < 0) {
      return;
    }
  }

  uint16 y_offset = Mult8x8(p.y_pos, room_width_in_blocks);
  int idx = plm_idx >> 1;
  plm_block_indices[idx] = 2 * (y_offset + p.x_pos);
  uint16 plm_id_ = p.plm_id_;
  plm_header_ptr[idx] = plm_id_;
  plm_room_arguments[idx] = 0;
  plm_variables[idx] = 0;
  plm_pre_instrs[idx] = FUNC16(PlmPreInstr_nullsub_60);
  PlmHeader_Size4 *PH = get_PlmHeader_Size4(plm_id_);
  plm_instr_list_ptrs[idx] = PH->instr_list_ptr;
  plm_instruction_timer[idx] = 1;
  plm_instruction_draw_ptr[idx] = addr_kDefaultPlmDrawInstruction;
  plm_timers[idx] = 0;
  plm_id = plm_idx;

  CallPlmHeaderFunc(PH->func_ptr | 0x840000, plm_idx);
}

/**
* @brief Spawns a PLM associated with the room
* @param plm_entry_ptr The pointer to the room PLM entry
*/
void SpawnRoomPLM(uint16 plm_entry_ptr) {  // 0x84846A
  RoomPlmEntry rpe;
  int16 plm_idx = MAX_PLMS-2;
  while (plm_header_ptr[plm_idx >> 1] != 0) {
    plm_idx -= 2;
    if (plm_idx < 0)
      return;
  }

  // When called by SpawnDoorClosingPLM(), plm_entry_ptr is 0x12, which points to RAM
  if (plm_entry_ptr == 0x12) {
	rpe = *(RoomPlmEntry*)(g_ram + 0x12);
  }
  else {
	rpe = get_RoomPlmEntry(plm_entry_ptr);
  }
  uint16 y_offset = Mult8x8(rpe.y_block, room_width_in_blocks);
  int idx = plm_idx >> 1;
  plm_block_indices[idx] = 2 * (y_offset + rpe.x_block);
  plm_room_arguments[idx] = rpe.plm_room_argument;
  uint16 plm_id_ = rpe.plm_header_ptr_;
  plm_header_ptr[idx] = plm_id_;
  plm_variables[idx] = 0;
  plm_pre_instrs[idx] = FUNC16(PlmPreInstr_Empty2);
  PlmHeader_Size4 *PH = get_PlmHeader_Size4(plm_id_);
  plm_instr_list_ptrs[idx] = PH->instr_list_ptr;
  plm_instruction_timer[idx] = 1;
  plm_instruction_draw_ptr[idx] = addr_kDefaultPlmDrawInstruction;
  plm_timers[idx] = 0;
  plm_id = plm_idx;
  
  CallPlmHeaderFunc(PH->func_ptr | 0x840000, plm_idx);
}

void PlmPreInstr_Empty2(void) {  // 0x8484E6
  ;
}

// returns bit 0 set if carry, 0x40 if ovf
/**
* @brief Spawns a PLM
* @param plm_id_ The PLM ID
* @return uint8 0 if no PLM could be spawned, otherwise it depends on the PLM function
*/
uint8 SpawnPLM(uint16 plm_id_) {  // 0x8484E7
  int16 plm_idx = MAX_PLMS-2;
  while (plm_header_ptr[plm_idx >> 1] != 0) {
    plm_idx -= 2;
    if (plm_idx < 0)
      return 0;
  }

  int idx = plm_idx >> 1;
  plm_block_indices[idx] = 2 * cur_block_index;
  plm_header_ptr[idx] = plm_id_;
  plm_pre_instrs[idx] = FUNC16(PlmPreInstr_Empty3);
  PlmHeader_Size4 *PH = get_PlmHeader_Size4(plm_id_);
  plm_instr_list_ptrs[idx] = PH->instr_list_ptr;
  plm_instruction_timer[idx] = 1;
  plm_instruction_draw_ptr[idx] = addr_kDefaultPlmDrawInstruction;
  plm_timers[idx] = 0;
  plm_room_arguments[idx] = 0;
  plm_variables[idx] = 0;
  plm_id = plm_idx;

  return CallPlmHeaderFunc(PH->func_ptr | 0x840000, plm_idx);
}

/**
* @brief Processes and spawns a PLM
*/
CoroutineRet PlmHandler_Async(void) {  // 0x8485B4
  COROUTINE_BEGIN(coroutine_state_2, 0);
  if (!(plm_flag & PLMS_ENABLED))
    return kCoroutineNone;
  plm_draw_tilemap_index = 0;
  for (plm_id = MAX_PLMS-2; (int16)plm_id >= 0; plm_id -= 2) {
    if (plm_header_ptr[plm_id >> 1] == 0)
      continue;
    CallPlmPreInstr(plm_pre_instrs[plm_id >> 1] | 0x840000, plm_id);
    if (--plm_instruction_timer[plm_id >> 1] != 0)
      continue;
    const uint8 *base = RomBankBase(0x84), *instr_list_ptr;
    instr_list_ptr = base + plm_instr_list_ptrs[plm_id >> 1];
    while (1) {
      if (!IS_FUNC(GET_WORD(instr_list_ptr)))
        break;
      instr_list_ptr = CallPlmInstr(GET_WORD(instr_list_ptr) | 0x840000, instr_list_ptr + 2, plm_id);
      if (instr_list_ptr == 0)
        goto NEXT_PLM;
      if ((uintptr_t)instr_list_ptr < 0x10000)
        instr_list_ptr = base + (uintptr_t)instr_list_ptr;
      // If the plm handler wanted to display a message, then display it.
      if (queued_message_box_index != 0) {
        plm_instr_list_ptrs[plm_id >> 1] = instr_list_ptr - base;
        COROUTINE_AWAIT(1, DisplayMessageBox_Async(queued_message_box_index));
        queued_message_box_index = 0;
        base = RomBankBase(0x84);
        instr_list_ptr = base + plm_instr_list_ptrs[plm_id >> 1];
      }
    }
    int idx = plm_id >> 1;
    plm_instruction_timer[idx] = GET_WORD(instr_list_ptr);
    plm_instruction_draw_ptr[idx] = GET_WORD(instr_list_ptr + 2);
    plm_instr_list_ptrs[idx] = instr_list_ptr + 4 - base;
    ProcessPlmDrawInstruction(plm_id);
    CalculatePlmBlockCoords(plm_id);
    DrawPlm(plm_id);
NEXT_PLM:;
  }
  plm_id = 0;
  COROUTINE_END(0);
}

static inline uint8 *RomPtr_84orRAM(uint16_t addr) {
  if (addr & 0x8000) {
    return (uint8*)RomPtr(0x840000 | addr);
  } else {
    assert(addr < 0x2000);
    return RomPtr_RAM(addr);
  }
}

/**
* @brief Draws the PLM according to the instructions
* @param plm_idx The index of the PLM
*/
void ProcessPlmDrawInstruction(uint16 plm_idx) {  // 0x84861E
  int idx = plm_idx >> 1;
  uint16 *plm_instr_draw_ptr = (uint16 *)RomPtr_84orRAM(plm_instruction_draw_ptr[idx]);
  uint16 plm_blk_idx = plm_block_indices[idx], dst_base = plm_blk_idx;
  while (1) {
    uint16 num_blocks = *plm_instr_draw_ptr++;
    if (num_blocks & 0x8000) {
      for (int col = 0, room_width = room_width_in_blocks * 2; col < (uint8)num_blocks; col++)
        level_data[(plm_blk_idx + col * room_width) >> 1] = *plm_instr_draw_ptr++;
    }
    else {
      for (int row = 0; row < (uint8)num_blocks; row++)
        level_data[(plm_blk_idx + row * 2) >> 1] = *plm_instr_draw_ptr++;
    }
    if (*plm_instr_draw_ptr == 0)
      break;
    int8 x_offset = *plm_instr_draw_ptr;
    int8 y_offset = HIBYTE(*plm_instr_draw_ptr);
    plm_blk_idx = dst_base + 2 * (x_offset + y_offset * room_width_in_blocks);
    plm_instr_draw_ptr++;
  }
}

/**
* @brief Puts the pointer back where it was, thus doing nothing
* @param plmp The pointer to the PLM
* @param plm_idx The index of the PLM
* @return uint8* 0 indicating that the PLM is done processing
*/
const uint8 *PlmInstr_Sleep(const uint8 *plmp, uint16 plm_idx) {  // 0x8486B4
  plm_instr_list_ptrs[plm_idx >> 1] = plmp - RomBankBase(0x84) - 2;
  return 0;
}

/**
* @brief Deletes the PLM
* @param plmp The pointer to the PLM
* @param plm_idx The index of the PLM
* @return uint8* 0 indicating that the PLM is done processing
*/
const uint8 *PlmInstr_Delete(const uint8 *plmp, uint16 plm_idx) {  // 0x8486BC
  plm_header_ptr[plm_idx >> 1] = 0;
  return 0;
}

/**
* @brief Sets the PLM pre-instruction
* @param plmp The pointer to the PLM
* @param plm_idx The index of the PLM
* @return uint8* The pointer to the next PLM instruction
*/
const uint8 *PlmInstr_PreInstr(const uint8 *plmp, uint16 plm_idx) {  // 0x8486C1
  plm_pre_instrs[plm_idx >> 1] = GET_WORD(plmp);
  return plmp + 2;
}

/**
* @brief Clears the PLM pre-instruction
* @param plmp The pointer to the PLM
* @param plm_idx The index of the PLM
* @return uint8* The pointer to the next PLM instruction
*/
const uint8 *PlmInstr_ClearPreInstr(const uint8 *plmp, uint16 plm_idx) {  // 0x8486CA
  plm_pre_instrs[plm_idx >> 1] = FUNC16(PlmPreInstr_Empty);
  return plmp;
}

void CallPlmInstrFunc(uint32 ea) {
  switch (ea) {
  case fnVariaSuitPickup: VariaSuitPickup(); return;
  case fnGravitySuitPickup: GravitySuitPickup(); return;
  default: Unreachable();
  }
}

/**
* @brief Calls the function specified by the instruction list
* @param plmp The pointer to the PLM
* @param plm_idx The index of the PLM
* @return uint8* The pointer to the next PLM instruction
*/
const uint8 *PlmInstr_CallFunction(const uint8 *plmp, uint16 plm_idx) {  // 0x84870B
  CallPlmInstrFunc(Load24((LongPtr *)plmp));
  return plmp + 3;
}

/**
* @brief Goes to the instruction specified by the instruction list
* @param plmp The pointer to the PLM
* @param plm_idx The index of the PLM
* @return uint8* The pointer to the instruction list
*/
const uint8 *PlmInstr_Goto(const uint8 *plmp, uint16 plm_idx) {  // 0x848724
  return INSTRB_RETURN_ADDR(GET_WORD(plmp));
}


/**
* @brief Decrements the timer and goes to the instruction specified if the timer is not zero
* @param plmp The pointer to the PLM
* @param plm_idx The index of the PLM
* @return uint8* The next instruction if the timer is zero, otherwise the instruction specified
*/
const uint8 *PlmInstr_DecrementAndBranchNonzero(const uint8 *plmp, uint16 plm_idx) {  // 0x84873F
  if (--plm_timers[plm_idx >> 1] != 0)
    return PlmInstr_Goto(plmp, plm_idx);
  return plmp + 2;
}

/**
* @brief Sets the timer for the PLM
* @param plmp The pointer to the PLM
* @param plm_idx The index of the PLM
* @return uint8* The pointer to the next PLM instruction
*/
const uint8 *PlmInstr_SetTimer(const uint8 *plmp, uint16 plm_idx) {  // 0x84874E
  plm_timers[plm_idx >> 1] = *plmp;
  return plmp + 1;
}

/**
* @brief Loads Item PLM graphics to VRAM and sets the tile table palettes
* @param plmp The pointer to the PLM
* @param plm_idx The index of the PLM
* @return uint8* The pointer to the next PLM instruction
*/
const uint8 *PlmInstr_LoadItemPlmGfx(const uint8 *plmp, uint16 plm_idx) {  // 0x848764
  uint16 gfx_idx = plm_item_gfx_index;
  plm_variables[plm_idx >> 1] = gfx_idx;
  plm_item_gfx_index = (gfx_idx + 2) & 6;
  int idx = gfx_idx >> 1;
  int vram_addr = kPlmVramAddresses[idx];
  int tile_table_idx = kPlmTileDataOffs[idx];
  int tile_num = kPlmStartingTileNumber[idx];
  plm_item_gfx_ptrs[idx] = plmp - RomBankBase(0x84);

  VramWriteEntry *vram_entry = gVramWriteEntry(vram_write_queue_tail);
  vram_entry->size = 0x100;
  vram_entry->src.addr = GET_WORD(plmp);
  vram_entry->src.bank = 0x89;
  vram_entry->vram_dst = vram_addr;
  vram_write_queue_tail += sizeof(VramWriteEntry);

  plmp += 2;
  int tile_table_end = tile_table_idx + 16;
  for (tile_table_idx; tile_table_idx < tile_table_end; tile_table_idx += 2) {
    *(uint16*)((uint8*)&tile_table + tile_table_idx) = tile_num++ + (*plmp++ * 0x400);
  }
  return plmp;
}

/**
* @brief Queues a transfer from RAM to VRAM
* @param plmp The pointer to the PLM
* @param plm_idx The index of the PLM
* @return uint8* The pointer to the next PLM instruction
*/
const uint8 *PlmInstr_CopyFromRamToVram(const uint8 *plmp, uint16 plm_idx) {  // 0x8487E5
  VramWriteEntry *vram_entry = gVramWriteEntry(vram_write_queue_tail);
  vram_entry->size = GET_WORD(plmp);
  vram_entry->src.addr = GET_WORD(plmp + 2);
  vram_entry->src.bank = plmp[4];
  vram_entry->vram_dst = GET_WORD(plmp + 5);
  vram_write_queue_tail += sizeof(VramWriteEntry);
  return plmp + sizeof(VramWriteEntry);
}

/**
* @brief Goes to the instruction specified if the boss bit is set
* @param plmp The pointer to the PLM
* @param plm_idx The index of the PLM
* @return uint8* The pointer to the instruction specified if the boss bit is set, otherwise the next PLM instruction
*/
const uint8 *PlmInstr_GotoIfBossBitSet(const uint8 *plmp, uint16 plm_idx) {  // 0x84880E
  if (CheckBossBitForCurArea(plmp[0]))
    return PlmInstr_Goto(plmp + 1, plm_idx);
  return plmp + 3;
}

/**
* @brief Goes to the instruction specified if the event happened
* @param plmp The pointer to the PLM
* @param plm_idx The index of the PLM
* @return uint8* The pointer to the instruction specified if the event happened, otherwise the next PLM instruction
*/
const uint8 *PlmInstr_GotoIfEventSet(const uint8 *plmp, uint16 plm_idx) {  // 0x84882D
  if (CheckEventHappened(GET_WORD(plmp)))
    return PlmInstr_Goto(plmp + 2, plm_idx);
  return plmp + 4;
}

/**
* @brief Sets the event specified in the instruction list as happened
* @param plmp The pointer to the PLM
* @param plm_idx The index of the PLM
* @return uint8* The pointer to the next PLM instruction
*/
const uint8 *PlmInstr_SetEvent(const uint8 *plmp, uint16 plm_idx) {  // 0x84883E
  SetEventHappened(GET_WORD(plmp));
  return plmp + 2;
}

/**
* @brief Goes to the instruction specified if the chozo bit is set
* This function is called by an ununused PLM, thus making it unused as well
* @param plmp The pointer to the PLM
* @param plm_idx The index of the PLM
* @return uint8* The pointer to the instruction specified if the chozo bit is set, otherwise the next PLM instruction
*/
const uint8 *PlmInstr_GotoIfChozoSet(const uint8 *plmp, uint16 plm_idx) {  // 0x848848
  uint16 plm_arg = plm_room_arguments[plm_idx >> 1];
  int idx = PrepareBitAccess(plm_arg);
  // Positive argument means chozo block is destroyed
  if (!sign16(plm_arg) && (room_chozo_bits[idx] & bitmask))
    return PlmInstr_Goto(plmp, plm_idx);
  return plmp + 2;
}

/**
* @brief Sets the chozo bit specified in the instruction list
* This function is called by an ununused PLM, thus making it unused as well
* @param plmp The pointer to the PLM
* @param plm_idx The index of the PLM
* @return uint8* The pointer to the next PLM instruction
*/
const uint8 *PlmInstr_SetRoomChozoBit(const uint8 *plmp, uint16 plm_idx) {  // 0x848865
  uint16 plm_arg = plm_room_arguments[plm_idx >> 1];
  // Positive argument means chozo block destroyed flag is set
  if (!sign16(plm_arg)) {
    int idx = PrepareBitAccess(plm_arg);
    room_chozo_bits[idx] |= bitmask;
  }
  return plmp;
}

/**
* @brief Goes to the instruction specified if the item bit is set
* @param plmp The pointer to the PLM
* @param plm_idx The index of the PLM
* @return uint8* The pointer to the instruction specified if the item bit is set, otherwise the next PLM instruction
*/
const uint8 *PlmInstr_GotoIfItemBitSet(const uint8 *plmp, uint16 plm_idx) {  // 0x84887C
  uint16 plm_arg = plm_room_arguments[plm_idx >> 1];
  int idx = PrepareBitAccess(plm_arg);
  // Positive argument means item is collected
  if (!sign16(plm_arg) && (item_bit_array[idx] & bitmask))
    return PlmInstr_Goto(plmp, plm_idx);
  return plmp + 2;
}

/**
* @brief Sets the item bit specified in the instruction list
* @param plmp The pointer to the PLM
* @param plm_idx The index of the PLM
* @return uint8* The pointer to the next PLM instruction
*/
const uint8 *PlmInstr_SetItemBit(const uint8 *plmp, uint16 plm_idx) {  // 0x848899
  uint16 plm_arg = plm_room_arguments[plm_idx >> 1];
  // Positive argument means item collected is set
  if (!sign16(plm_arg)) {
    uint16 idx = PrepareBitAccess(plm_arg);
    item_bit_array[idx] |= bitmask;
  }
  return plmp;
}

/**
* @brief Sets the beam and displays the message specified in the instruction list
* @param plmp The pointer to the PLM
* @param plm_idx The index of the PLM
* @return uint8* The pointer to the next PLM instruction
*/
const uint8 *PlmInstr_PickupBeamAndShowMessage(const uint8 *plmp, uint16 plm_idx) {  // 0x8488B0
  uint16 beam = GET_WORD(plmp);
  collected_beams |= beam;
  equipped_beams |= beam;
  // Unsets Plasma if Spazer is collected, and Spazer if Plasma is collected
  equipped_beams &= ~((beam << 1) & kBeam_Plasma);
  equipped_beams &= ~((beam >> 1) & kBeam_Spazer);
  UpdateBeamTilesAndPalette();
#if 0
  PlayRoomMusicTrackAfterAFrames(360);
#endif
  DisplayMessageBox(plmp[2]);
  return plmp + 3;
}

/**
* @brief Sets the equipment and displays the message specified in the instruction list
* @param plmp The pointer to the PLM
* @param plm_idx The index of the PLM
* @return uint8* The pointer to the next PLM instruction
*/
const uint8 *PlmInstr_PickupEquipmentAndShowMessage(const uint8 *plmp, uint16 plm_idx) {  // 0x8488F3
  uint16 item = GET_WORD(plmp);
  equipped_items |= item;
  collected_items |= item;
#if 0
  PlayRoomMusicTrackAfterAFrames(360);
#endif
  DisplayMessageBox(plmp[2]);
  return plmp + 3;
}

/**
* @brief Sets the equipment and displays the message specified in the instruction list, and adds grapple to the HUD
* @param plmp The pointer to the PLM
* @param plm_idx The index of the PLM
* @return uint8* The pointer to the next PLM instruction
*/
const uint8 *PlmInstr_PickupEquipmentAddGrappleShowMessage(const uint8 *plmp, uint16 plm_idx) {  // 0x84891A
  uint16 item = GET_WORD(plmp);
  equipped_items |= item;
  collected_items |= item;
  AddGrappleToHudTilemap();
#if 0
  PlayRoomMusicTrackAfterAFrames(360);
#endif
  DisplayMessageBox(kMessageBox_5_GrapplingBeam);
  return plmp + 2;
}

/**
* @brief Sets the equipment and displays the message specified in the instruction list, and adds xray to the HUD
* @param plmp The pointer to the PLM
* @param plm_idx The index of the PLM
* @return uint8* The pointer to the next PLM instruction
*/
const uint8 *PlmInstr_PickupEquipmentAddXrayShowMessage(const uint8 *plmp, uint16 plm_idx) {  // 0x848941
  uint16 item = GET_WORD(plmp);
  equipped_items |= item;
  collected_items |= item;
  AddXrayToHudTilemap();
#if 0
  PlayRoomMusicTrackAfterAFrames(360);
#endif
  DisplayMessageBox(kMessageBox_6_XrayScope);
  return plmp + 2;
}

/**
* @brief Adds the amount of health and displays the message specified in the instruction list
* @param plmp The pointer to the PLM
* @param plm_idx The index of the PLM
* @return uint8* The pointer to the next PLM instruction
*/
const uint8 *PlmInstr_CollectHealthEnergyTank(const uint8 *plmp, uint16 plm_idx) {  // 0x848968
  samus_max_health += GET_WORD(plmp);
  samus_health = samus_max_health;
#if 0
  PlayRoomMusicTrackAfterAFrames(360);
#endif
  DisplayMessageBox(kMessageBox_1_EnergyTank);
  return plmp + 2;
}

/**
* @brief Adds the amount of reserve health and displays the message specified in the instruction list
* @param plmp The pointer to the PLM
* @param plm_idx The index of the PLM
* @return uint8* The pointer to the next PLM instruction
*/
const uint8 *PlmInstr_CollectHealthReserveTank(const uint8 *plmp, uint16 plm_idx) {  // 0x848986
  samus_max_reserve_health += GET_WORD(plmp);
  if (reserve_health_mode == kReserveHealthMode_0_None)
    reserve_health_mode = kReserveHealthMode_1_Auto;
#if 0
  PlayRoomMusicTrackAfterAFrames(360);
#endif
  DisplayMessageBox(kMessageBox_25_ReserveTank);
  return plmp + 2;
}

/**
* @brief Adds the amount of missiles and displays the message specified in the instruction list
* @param plmp The pointer to the PLM
* @param plm_idx The index of the PLM
* @return uint8* The pointer to the next PLM instruction
*/
const uint8 *PlmInstr_CollectAmmoMissileTank(const uint8 *plmp, uint16 plm_idx) {  // 0x8489A9
  int amt = GET_WORD(plmp);
  samus_max_missiles += amt;
  samus_missiles += amt;
  AddMissilesToHudTilemap();
#if 0
  PlayRoomMusicTrackAfterAFrames(360);
#endif
  DisplayMessageBox(kMessageBox_2_Missile);
  return plmp + 2;
}

/**
* @brief Adds the amount of super missiles and displays the message specified in the instruction list
* @param plmp The pointer to the PLM
* @param plm_idx The index of the PLM
* @return uint8* The pointer to the next PLM instruction
*/
const uint8 *PlmInstr_CollectAmmoSuperMissileTank(const uint8 *plmp, uint16 plm_idx) {  // 0x8489D2
  uint16 amt = GET_WORD(plmp);
  samus_max_super_missiles += amt;
  samus_super_missiles += amt;
  AddSuperMissilesToHudTilemap();
#if 0
  PlayRoomMusicTrackAfterAFrames(360);
#endif
  DisplayMessageBox(kMessageBox_3_SuperMissile);
  return plmp + 2;
}

/**
* @brief Adds the amount of power bombs and displays the message specified in the instruction list
* @param plmp The pointer to the PLM
* @param plm_idx The index of the PLM
* @return uint8* The pointer to the next PLM instruction
*/
const uint8 *PlmInstr_CollectAmmoPowerBombTank(const uint8 *plmp, uint16 plm_idx) {  // 0x8489FB
  uint16 amt = GET_WORD(plmp);
  samus_max_power_bombs += amt;
  samus_power_bombs += amt;
  AddPowerBombsToHudTilemap();
#if 0
  PlayRoomMusicTrackAfterAFrames(360);
#endif
  DisplayMessageBox(kMessageBox_4_PowerBomb);
  return plmp + 2;
}

/**
* @brief Sets the link register to the instruction specified in the instruction list
* @param plmp The pointer to the PLM
* @param plm_idx The index of the PLM
* @return uint8* The pointer to the next PLM instruction
*/
const uint8 *PlmInstr_SetLinkReg(const uint8 *plmp, uint16 plm_idx) {  // 0x848A24
  plm_instruction_list_link_reg[plm_idx >> 1] = GET_WORD(plmp);
  return plmp + 2;
}

/**
* @brief Calls the instruction specified in the instruction list and sets the link register to the next instruction
* @param plmp The pointer to the PLM
* @param plm_idx The index of the PLM
* @return uint8* The pointer to the instruction specified
*/
const uint8 *PlmInstr_Call(const uint8 *plmp, uint16 plm_idx) {  // 0x848A2E
  plm_instruction_list_link_reg[plm_idx >> 1] = plmp - RomBankBase(0x84) + 2;
  return INSTRB_RETURN_ADDR(GET_WORD(plmp));
}

/**
* @brief Returns to the instruction specified in the link register
* @param plmp The pointer to the PLM
* @param plm_idx The index of the PLM
* @return uint8* The pointer to the instruction specified in the link register
*/
const uint8 *PlmInstr_Return(const uint8 *plmp, uint16 plm_idx) {  // 0x848A3A
  return INSTRB_RETURN_ADDR(plm_instruction_list_link_reg[plm_idx >> 1]);
}

/**
* @brief Goes to the instruction specified if the door bit is set, otherwise the next PLM instruction
* @param plmp The pointer to the PLM
* @param plm_idx The index of the PLM
* @return uint8* The pointer to the instruction specified if the door bit is set, otherwise the next PLM instruction
*/
const uint8 *PlmInstr_GotoIfDoorBitSet(const uint8 *plmp, uint16 plm_idx) {  // 0x848A72
  uint16 plm_arg = plm_room_arguments[plm_idx >> 1];
  if (sign16(plm_arg))
    return plmp + 2;
  int idx = PrepareBitAccess(plm_arg);
  // Positive argument means door is set
  if (!sign16(plm_arg) && (opened_door_bit_array[idx] & bitmask))
    return INSTRB_RETURN_ADDR(GET_WORD(plmp));
  return plmp + 2;
}

/**
* @brief Increments the door hit counter and goes to the instruction specified
* if the counter is greater or equal to the value in the instruction list
* @param plmp The pointer to the PLM
* @param plm_idx The index of the PLM
* @return uint8* The pointer to the instruction specified if the counter is greater or equal to the value,
* otherwise the next PLM instruction
*/
const uint8 *PlmInstr_IncrementDoorHitCounterAndJGE(const uint8 *plmp, uint16 plm_idx) {  // 0x848A91
  int idx = plm_idx >> 1;
  if ((uint8)++plm_variables[idx] < plmp[0])
    return plmp + 3;
  uint16 plm_arg = plm_room_arguments[idx];
  if (!sign16(plm_arg)) {
    int bit_idx = PrepareBitAccess(plm_arg);
    opened_door_bit_array[bit_idx] |= bitmask;
    plm_room_arguments[idx] = WORD(opened_door_bit_array[bit_idx]) | 0x8000;
  }
  plm_pre_instrs[idx] = addr_PlmPreInstr_Empty4;
  return PlmInstr_Goto(plmp + 1, plm_idx);
}

/**
* @brief Increments the argument and goes to the instruction specified
* if the argument is greater or equal to the value in the instruction list
* @param plmp The pointer to the PLM
* @param plm_idx The index of the PLM
* @return uint8* The pointer to the instruction specified if the argument is greater or equal to the value,
* otherwise the next PLM instruction
*/
const uint8 *PlmInstr_IncrementArgumentAndJGE(const uint8 *plmp, uint16 plm_idx) {  // 0x848ACD
  int idx = plm_idx >> 1;
  uint8 plm_arg = plm_room_arguments[idx] + 1;
  if (plm_arg >= plmp[0]) {
    plm_room_arguments[idx] = -1;
    plm_pre_instrs[idx] = addr_locret_848AE0;
    return PlmInstr_Goto(plmp + 1, plm_idx);
  }
  plm_room_arguments[idx] = plm_arg;
  return plmp + 3;
}

/**
* @brief Sets the BTS block to the value in the instruction list
* @param plmp The pointer to the PLM
* @param plm_idx The index of the PLM
* @return uint8* The pointer to the next PLM instruction
*/
const uint8 *PlmInstr_SetBTS(const uint8 *plmp, uint16 plm_idx) {  // 0x848AF1
  uint16 plm_blk_idx = plm_block_indices[plm_idx >> 1];
  BTS[plm_blk_idx >> 1] = plmp[0];
  return plmp + 1;
}

/**
* @brief Creates the draw instruction in RAM and draws the PLM block
* @param plmp The pointer to the PLM
* @param plm_idx The index of the PLM
* @return uint8* 0 indicating that the PLM is done processing
*/
const uint8 *PlmInstr_DrawPlmBlock(const uint8 *plmp, uint16 plm_idx) {  // 0x848B17
  int idx = plm_idx >> 1;
  uint16 plm_respawn_blk = plm_variable[idx];
  uint16 plm_blk_idx = plm_block_indices[idx];
  level_data[plm_blk_idx >> 1] = plm_respawn_blk;
  custom_draw_instr_plm_block = plm_respawn_blk;
  custom_draw_instr_num_blocks = 1;
  custom_draw_instr_zero_terminator = 0;
  plm_instruction_timer[idx] = 1;
  plm_instruction_draw_ptr[idx] = ADDR16_OF_RAM(custom_draw_instr_num_blocks);
  plm_instr_list_ptrs[idx] = plmp - RomBankBase(0x84);
  ProcessPlmDrawInstruction(plm_idx);
  CalculatePlmBlockCoords(plm_id);
  DrawPlm(plm_id);
  return 0;
}

/**
* @brief Processes the plm scroll data and sets the special air block
* @param plmp The pointer to the PLM
* @param plm_idx The index of the PLM
* @return uint8* The pointer to the next PLM instruction
*/
const uint8 *PlmInstr_ProcessAirScrollUpdate(const uint8 *plmp, uint16 plm_idx) {  // 0x848B55
  int idx = plm_idx >> 1;
  plm_variable[idx] = 0;
  const PlmScrollData *PSD = get_PlmScrollData(plm_room_arguments[idx]);
  for (PSD; (PSD->dst_scroll & 0x80) == 0; PSD++)
    scrolls[PSD->dst_scroll] = PSD->scroll_type;
  int blk_idx = plm_block_indices[idx] >> 1;
  level_data[blk_idx] = SET_BLK_TYPE(level_data[blk_idx], kBlockType_3_SpecialAir);
  return plmp;
}

/**
* @brief Processes the plm scroll data and sets the special solid block
* @brief This function is called by an ununsed PLM, thus making it unused as well
* @param plmp The pointer to the PLM
* @param plm_idx The index of the PLM
* @return uint8* The pointer to the next PLM instruction
*/
const uint8 *PlmInstr_ProcessSolidScrollUpdate(const uint8 *plmp, uint16 plm_idx) {  // 0x848B93
  int idx = plm_idx >> 1;
  plm_variable[idx] = 0;
  const PlmScrollData *PSD = get_PlmScrollData(plm_room_arguments[idx]);
  for (PSD; (PSD->dst_scroll & 0x80) == 0; PSD++)
    scrolls[PSD->dst_scroll] = PSD->scroll_type;
  int blk_idx = plm_block_indices[idx] >> 1;
  level_data[blk_idx] = SET_BLK_TYPE(level_data[blk_idx], kBlockType_B_SpecialBlock);
  return plmp;
}

//unused
const uint8 *PlmInstr_QueueMusic(const uint8 *plmp, uint16 k) {  // 0x848BD1
  QueueMusic_Delayed8(plmp[0]);
  return plmp + 1;
}

/**
* @brief Clears the music queue and queues the track specified in the instruction list
* @param plmp The pointer to the PLM
* @param plm_idx The index of the PLM
* @return uint8* The pointer to the next PLM instruction
*/
const uint8 *PlmInstr_ClearMusicQueueAndQueueTrack(const uint8 *plmp, uint16 plm_idx) {  // 0x848BDD
  // Feature: Quick pickups
if (enhanced_features0 & kFeatures0_InstantPickups) {
  CancelSoundEffects();
  QueueSfx2_Max6(kSfx2_TypewriterStroke_CeresSelfDestructSequence);
  return plmp + 1;
}
  for (int queue_entry = 14; queue_entry >= 0; queue_entry -= 2) {
    int idx = queue_entry >> 1;
    music_queue_track[idx] = 0;
    music_queue_delay[idx] = 0;
  }
  music_queue_read_pos = music_queue_write_pos;
  music_timer = 0;
  music_entry = 0;
  QueueMusic_Delayed8(plmp[0]);
  return plmp + 1;
}

/**
* @brief Queues the library 1 sound effect specified in the instruction list
* with a max queue of 6 sound effects
* @param plmp The pointer to the PLM
* @param plm_idx The index of the PLM
* @return uint8* The pointer to the next PLM instruction
*/
const uint8 *PlmInstr_QueueSfx1_Max6(const uint8 *plmp, uint16 plm_idx) {  // 0x848C07
  QueueSfx1_Max6(plmp[0]);
  return plmp + 1;
}

/**
* @brief Queues the library 2 sound effect specified in the instruction list
* with a max queue of 6 sound effects
* @param plmp The pointer to the PLM
* @param plm_idx The index of the PLM
* @return uint8* The pointer to the next PLM instruction
*/
const uint8 *PlmInstr_QueueSfx2_Max6(const uint8 *plmp, uint16 plm_idx) {  // 0x848C10
  QueueSfx2_Max6(plmp[0]);
  return plmp + 1;
}

/**
* @brief Queues the library 3 sound effect specified in the instruction list
* with a max queue of 6 sound effects
* @param plmp The pointer to the PLM
* @param plm_idx The index of the PLM
* @return uint8* The pointer to the next PLM instruction
*/
const uint8 *PlmInstr_QueueSfx3_Max6(const uint8 *plmp, uint16 plm_idx) {  // 0x848C19
  QueueSfx3_Max6(plmp[0]);
  return plmp + 1;
}

//unused
const uint8 *PlmInstr_QueueSfx1_Max15(const uint8 *plmp, uint16 plm_idx) {  // 0x848C22
  QueueSfx1_Max15(plmp[0]);
  return plmp + 1;
}

//unused
const uint8 *PlmInstr_QueueSfx2_Max15(const uint8 *plmp, uint16 plm_idx) {  // 0x848C2B
  QueueSfx2_Max15(plmp[0]);
  return plmp + 1;
}

//unused
const uint8 *PlmInstr_QueueSfx3_Max15(const uint8 *plmp, uint16 plm_idx) {  // 0x848C34
  QueueSfx3_Max15(plmp[0]);
  return plmp + 1;
}

//unused
const uint8 *PlmInstr_QueueSfx1_Max3(const uint8 *plmp, uint16 plm_idx) {  // 0x848C3D
  QueueSfx1_Max3(plmp[0]);
  return plmp + 1;
}

/**
* @brief Queues the library 2 sound effect specified in the instruction list
* with a max queue of 3 sound effects
* @param plmp The pointer to the PLM
* @param plm_idx The index of the PLM
* @return uint8* The pointer to the next PLM instruction
*/
const uint8 *PlmInstr_QueueSfx2_Max3(const uint8 *plmp, uint16 plm_idx) {  // 0x848C46
  QueueSfx2_Max3(plmp[0]);
  return plmp + 1;
}

//unused
const uint8 *PlmInstr_QueueSfx_Max3(const uint8 *plmp, uint16 plm_idx) {  // 0x848C4F
  QueueSfx3_Max3(plmp[0]);
  return plmp + 1;
}

//unused
const uint8 *PlmInstr_QueueSfx1_Max9(const uint8 *plmp, uint16 plm_idx) {  // 0x848C58
  QueueSfx1_Max9(plmp[0]);
  return plmp + 1;
}

//unused
const uint8 *PlmInstr_QueueSfx2_Max9(const uint8 *plmp, uint16 plm_idx) {  // 0x848C61
  QueueSfx2_Max9(plmp[0]);
  return plmp + 1;
}

//unused
const uint8 *PlmInstr_QueueSfx3_Max9(const uint8 *plmp, uint16 plm_idx) {  // 0x848C6A
  QueueSfx3_Max9(plmp[0]);
  return plmp + 1;
}

//unused
const uint8 *PlmInstr_QueueSfx1_Max1(const uint8 *plmp, uint16 plm_idx) {  // 0x848C73
  QueueSfx1_Max1(plmp[0]);
  return plmp + 1;
}

//unused
const uint8 *PlmInstr_QueueSfx2_Max1(const uint8 *plmp, uint16 plm_idx) {  // 0x848C7C
  QueueSfx2_Max1(plmp[0]);
  return plmp + 1;
}

//unused
const uint8 *PlmInstr_QueueSfx3_Max1(const uint8 *plmp, uint16 plm_idx) {  // 0x848C85
  QueueSfx3_Max1(plmp[0]);
  return plmp + 1;
}

/**
* @brief Sets the area map station bit and displays the map station message
* @param plmp The pointer to the PLM
* @param plm_idx The index of the PLM
* @return uint8* The pointer to the next PLM instruction
*/
const uint8 *PlmInstr_ActivateMapStation(const uint8 *plmp, uint16 plm_idx) {  // 0x848C8F
  WORD(map_station_byte_array[area_index]) |= 0xFF;
  DisplayMessageBox(kMessageBox_20_MapDataAccessCompleted);
  has_area_map = true;
  return plmp;
}

/**
* @brief Sets the energy to the max health and displays the energy station message
* @param plmp The pointer to the PLM
* @param plm_idx The index of the PLM
* @return uint8* The pointer to the next PLM instruction
*/
const uint8 *PlmInstr_ActivateEnergyStation(const uint8 *plmp, uint16 plm_idx) {  // 0x848CAF
  if (samus_max_health != samus_health) {
    DisplayMessageBox(kMessageBox_21_EnergyRechargeCompleted);
    samus_health = samus_max_health;
  }
  RunSamusCode(kSamusCode_1_UnlockSamus);
  return plmp;
}

/**
* @brief Feature: Missile stations will refill super missiles and power bombs
*/
void AmmoRechargeStation(void) {
  if (samus_max_missiles != samus_missiles || samus_max_super_missiles != samus_super_missiles || samus_max_power_bombs != samus_power_bombs) {
    if (samus_max_missiles != samus_missiles) {
      samus_missiles = samus_max_missiles;
    }
    if (samus_max_super_missiles != samus_super_missiles) {
      samus_super_missiles = samus_max_super_missiles;
    }
    if (samus_max_power_bombs != samus_power_bombs) {
      samus_power_bombs = samus_max_power_bombs;
    }
    DisplayMessageBox(kMessageBox_22_MissileReloadCompleted);
  }
}

/**
* @brief Sets the missiles to the max missiles and displays the missile station message
* @param plmp The pointer to the PLM
* @param plm_idx The index of the PLM
* @return uint8* The pointer to the next PLM instruction
*/
const uint8 *PlmInstr_ActivateMissileStation(const uint8 *plmp, uint16 plm_idx) {  // 0x848CD0
    if (enhanced_features0 & kFeatures0_AmmoRechargeStation) {
        AmmoRechargeStation();
        RunSamusCode(kSamusCode_1_UnlockSamus);
        return plmp;
    }
  if (samus_max_missiles != samus_missiles) {
    DisplayMessageBox(kMessageBox_22_MissileReloadCompleted);
    samus_missiles = samus_max_missiles;
  }
  RunSamusCode(kSamusCode_1_UnlockSamus);
  return plmp;
}

/**
* @brief Sets the save station bit and saves the game to the SRAM slot and displays the save station message,
* if the player chooses to save, otherwise goes to the instruction specified in the instruction list
* @param plmp The pointer to the PLM
* @param plm_idx The index of the PLM
* @return uint8* The pointer to the instruction specified if the player chooses not to save, otherwise the next PLM instruction
*/
const uint8 *PlmInstr_ActivateSaveStationAndGotoIfNo(const uint8 *plmp, uint16 plm_idx) {  // 0x848CF1
  int save_select = DisplayMessageBox_Poll(kMessageBox_23_WouldYouLikeToSave);
  // If the message has not been displayed yet
  if (save_select < 0)
    return plmp - 2; // restart plm instr
  if (save_select == kConfirmSave_No)
    return INSTRB_RETURN_ADDR(GET_WORD(plmp));
  SpawnEprojWithRoomGfx(addr_kEproj_SaveStationElectricity, 0);
  load_station_index = plm_room_arguments[plm_id >> 1] & 7;
  PrepareBitAccess(load_station_index);
  used_save_stations_and_elevators[2 * area_index] |= bitmask;
  SaveToSram(selected_save_slot);
  return plmp + 2;
}

/**
* @brief Goes to the instruction specified if the player is within range of the PLM block
* @param plmp The pointer to the PLM
* @param plm_idx The index of the PLM
* @return uint8* The pointer to the instruction specified if the player is within range of the PLM block,
* otherwise the next PLM instruction
*/
const uint8 *PlmInstr_GotoIfSamusNear(const uint8 *plmp, uint16 plm_idx) {  // 0x848D41
  CalculatePlmBlockCoords(plm_idx);
  uint8 x_offset = abs16((samus_x_pos / 16) - plm_x_block);
  uint8 y_offset = abs16((samus_y_pos /16 ) - plm_y_block);
  if (x_offset <= plmp[0] && y_offset <= plmp[1])
    return INSTRB_RETURN_ADDR(GET_WORD(plmp + 2));
  return plmp + 4;
}

/**
* @brief Sets up transfer of PLM draw tilemap to VRAM
* @param plm_draw_vram_dst The destination VRAM address
* @param vram_write_ptr The VRAM write pointer
* @param draw_size The size of the draw
* @param inc_mode_32 The increment mode, which is 32 bytes
*/
static void PartiallyQueueVramForSingleScreenPlm(uint16 plm_draw_vram_dst, uint16 vram_write_ptr, uint16 draw_size, uint16 inc_mode_32) {  // 0x849220
  VramWriteEntry *vram_entry = gVramWriteEntry(vram_write_ptr);
  vram_entry->vram_dst = inc_mode_32 | plm_draw_vram_dst;
  uint16 size = 4 * draw_size;
  VoidP base = ADDR16_OF_RAM(*plm_draw_tilemap) + plm_draw_tilemap_index;
  vram_entry[0].size = size;
  vram_entry[1].size = size;
  vram_entry[0].src = (LongPtr){ .bank = 0x7E, .addr = base };
  vram_entry[1].src = (LongPtr){ .bank = 0x7E, .addr = base + size };
  // R0/R6 assignments move to caller
}

/**
* @brief Calculates the destination VRAM address for the PLM draw tilemap and sets up transfer of PLM draw tilemap to VRAM
* @param vram_write_ptr The VRAM write pointer
* @param vram_1st_screen_base_addr The base address of the first screen VRAM
* @param vram_2nd_screen_base_addr The base address of the second screen VRAM
* @param draw_size The number of blocks to draw
* @param plm_draw_x_blk The x block of the PLM draw
* @param plm_draw_y_blk The y block of the PLM draw
* @param inc_mode_32 The increment mode, which is 32 bytes
*/
static void CalculatePlmDrawTilemapVramDst(uint16 vram_write_ptr, uint16 vram_1st_screen_base_addr, uint16 vram_2nd_screen_base_addr, uint16 draw_size, uint16 plm_draw_x_blk, uint16 plm_draw_y_blk, uint16 inc_mode_32) {  // 0x8491DC
  uint16 plm_draw_vram_dst;
  uint16 y_pos = (plm_draw_y_blk & 0xF) * 0x40;
  uint16 x_pos = plm_draw_x_blk & 0x1F;
  uint16 vram_offset = addr_kVram_2ndScreen - addr_kVram_1stScreen;
  if (x_pos >= 16) {
    plm_draw_vram_dst = y_pos + vram_2nd_screen_base_addr + 2 * x_pos;
    if (bg1_x_offset & 0x100)
      plm_draw_vram_dst -= vram_offset;
  }
  else {
    plm_draw_vram_dst = y_pos + vram_1st_screen_base_addr + 2 * x_pos;
    if (bg1_x_offset & 0x100)
      plm_draw_vram_dst += vram_offset;
  }
  PartiallyQueueVramForSingleScreenPlm(plm_draw_vram_dst, vram_write_ptr, draw_size, inc_mode_32);
}

/**
* @todo Finish this later
* I decided to rewrite the whole function, but it's so long that it's difficult to fix
*/
void DrawPlmm(uint16 plm_idx) {
  uint16 *plm_top_half_src_ptr,  // 0x0
         *plm_bottom_half_src_ptr;  // 0x6
  uint16 draw_data_addr; // 0x3
  uint16 num_blks_truncated;  // 0x16
  uint16 inc_mode;  // 0x1C

  uint16 vram_1st_screen_base_addr = addr_kVram_1stScreen;  // 0x9
  uint16 vram_2nd_screen_base_addr = addr_kVram_2ndScreenOffset;  // 0xC
  uint16 plm_draw_instr_ptr = plm_instruction_draw_ptr[plm_idx >> 1];
  uint16 plm_draw_x_blk = plm_x_block;  // 0x1E
  uint16 plm_draw_y_blk = plm_y_block;  // 0x20

  while (1) {  // loop draw entry
    uint16 screen_y_blk = layer1_y_pos / 16;  // 0x1A
    // if the plm is below the screen bounds, don't draw
    if ((int16)(screen_y_blk + 15) < (int16)plm_draw_y_blk)
	  return;
    uint16 plm_draw_instr = *(uint16*)RomPtr_84orRAM(plm_draw_instr_ptr);
    // if drawing horizontal
    if (!sign16(plm_draw_instr)) {
      uint16 draw_size = plm_draw_instr & 0x7FFF;  // 0x14
      inc_mode = 0;  // normal increment mode
      // if the plm is above the screen bounds, don't draw
      if (plm_draw_y_blk < screen_y_blk)
        return;
      uint16 plm_draw_y_blk_copy = plm_draw_y_blk;  // 0x1A
      uint16 num_blks_skipped = 0;  // 0x12
      uint16 plm_draw_x_blk_copy = plm_draw_x_blk;  // 0x18
      // ((uint16)(layer1_x_pos + 15) >> 4) - 1
      // (layer1_x_pos + 15) / 16 - 16/16
      // (layer1_x_pos + 15 - 16) / 16
      // (layer1_x_pos - 1) / 16
      uint16 blk_left_of_screen = (layer1_x_pos - 1) / 16;  // 0x16
      if (blk_left_of_screen > plm_draw_x_blk) {
        num_blks_skipped = blk_left_of_screen - plm_draw_x_blk;
        if (draw_size + plm_draw_x_blk <= blk_left_of_screen)
          return;
        draw_size -= num_blks_skipped;
        plm_draw_x_blk_copy = blk_left_of_screen;
      }
      uint16 blk_right_of_screen = blk_left_of_screen + 17;  // 0x16
      if (blk_right_of_screen < plm_draw_x_blk)
        return;
      num_blks_truncated = plm_draw_x_blk_copy + draw_size - 1 - blk_right_of_screen;
      if ((int16)num_blks_truncated >= 0) {
        draw_size -= num_blks_truncated;
		if (draw_size == 0)
		  return;
      }
      if (vram_write_queue_tail >= 0x1E0)
        return;
      // if tilemap is too large to draw
      if ((int16)((0x200 - plm_draw_tilemap_index) / 8) < draw_size)
        return;
      uint16 prod = (plm_draw_y_blk_copy & 0xF) * 0x40;
      uint16 plm_vram_dst;
      if ((plm_draw_x_blk_copy & 0x1F) < 0x10) {
        plm_vram_dst = 2 * (plm_draw_x_blk_copy & 0x1F) + vram_1st_screen_base_addr + prod;
        if (bg1_x_offset & 0x100)
		  plm_vram_dst += addr_kVram_2ndScreen - addr_kVram_1stScreen;
      }
      else {
        plm_vram_dst = 2 * (plm_draw_x_blk_copy & 0x1F) + vram_2nd_screen_base_addr + prod;
		if (bg1_x_offset & 0x100)
          plm_vram_dst -= addr_kVram_2ndScreen - addr_kVram_1stScreen;
      }
      uint16 r1e = draw_size * 2;  // 0x1E
      uint16 r22 = plm_vram_dst & 0x1F; // 0x22
      // if all the blocks are not on the same screen
      if (((plm_vram_dst & 0x1F) + (draw_size * 2) - 1) & 0xFFE0) {
        if (vram_write_queue_tail >= 0xE4)
          return;
        VramWriteEntry *vram_entry = gVramWriteEntry(vram_write_queue_tail);
        uint16 size_until_end_of_screen = 2 * (32 - plm_vram_dst & 0x1F);
        uint16 second_screen_start_addr = (plm_vram_dst & 0xFFE0) ^ 0x400;
        uint16 row_below_entry_1_addr = second_screen_start_addr + 32;
        uint16 row_below_entry_0_addr = plm_vram_dst + 32;
        uint16 size_after_entry_0 = 4 * draw_size - size_until_end_of_screen;
        vram_entry[0].size = size_until_end_of_screen;
        vram_entry[2].size = size_until_end_of_screen;
        vram_entry[0].vram_dst = plm_vram_dst; 
        vram_entry[1].vram_dst = second_screen_start_addr;
        vram_entry[3].vram_dst = row_below_entry_1_addr;
        vram_entry[2].vram_dst = row_below_entry_0_addr;
        vram_entry[1].size = size_after_entry_0;
        vram_entry[3].size = size_after_entry_0;
        uint16 plm_top_half_src_addr = ADDR16_OF_RAM(*plm_draw_tilemap) + plm_draw_tilemap_index;
        vram_entry[0].src.addr = plm_top_half_src_addr;
        plm_top_half_src_ptr = (uint16 *)(g_ram + plm_top_half_src_addr);
        vram_entry[1].src.addr = plm_top_half_src_addr + size_until_end_of_screen;
        uint16 plm_bottom_half_src_addr = plm_top_half_src_addr + size_until_end_of_screen + size_after_entry_0;
        vram_entry[2].src.addr = plm_bottom_half_src_addr;
        plm_bottom_half_src_ptr = (uint16 *)(g_ram + plm_bottom_half_src_addr);
        vram_entry[3].src.addr = plm_bottom_half_src_addr + size_until_end_of_screen;
        vram_entry[3].src.bank = vram_entry[2].src.bank = vram_entry[1].src.bank = vram_entry[0].src.bank = 0x7E;
        vram_write_queue_tail += 4 * sizeof(VramWriteEntry);
      }
      // if all blocks are on same screen
      else {
        PartiallyQueueVramForSingleScreenPlm(plm_vram_dst, vram_write_queue_tail, draw_size, inc_mode);
        VramWriteEntry *vram_entry = gVramWriteEntry(vram_write_queue_tail);
        vram_entry[1].vram_dst = vram_entry[0].vram_dst + 32;
        plm_top_half_src_ptr = (uint16 *)(g_ram + vram_entry[0].src.addr);
        plm_bottom_half_src_ptr = (uint16 *)(g_ram + vram_entry[1].src.addr);
        vram_write_queue_tail += 2 * sizeof(VramWriteEntry);
      }
      num_blks_skipped *= 2;
      draw_data_addr = plm_draw_instr_ptr + 2 + num_blks_skipped;  // 0x3
      uint16 plm_draw_tilemap_idx = 0;
      while (1) {
        uint16 block = GET_WORD(RomPtr_84orRAM(draw_data_addr));  // 0x1E
        uint16 tile_table_idx = block & 0x3FF;
        uint16 blk_flip_type = block & (BLK_VERT_FLIP | BLK_HORIZ_FLIP);
        if (block & BLK_HAS_FLIP) {
          if (blk_flip_type == BLK_HORIZ_FLIP) {
            plm_top_half_src_ptr[plm_draw_tilemap_idx >> 1] = tile_table.tables[tile_table_idx].top_right ^ BLK_X_FLIP;
			plm_bottom_half_src_ptr[plm_draw_tilemap_idx >> 1] = tile_table.tables[tile_table_idx].bottom_right ^ BLK_X_FLIP;
            plm_draw_tilemap_idx += 2;
			plm_top_half_src_ptr[plm_draw_tilemap_idx >> 1] = tile_table.tables[tile_table_idx].top_left ^ BLK_X_FLIP;
			plm_bottom_half_src_ptr[plm_draw_tilemap_idx >> 1] = tile_table.tables[tile_table_idx].bottom_left ^ BLK_X_FLIP;
		  }
          else if (blk_flip_type == BLK_VERT_FLIP) {
            plm_top_half_src_ptr[plm_draw_tilemap_idx >> 1] = tile_table.tables[tile_table_idx].bottom_left ^ BLK_Y_FILP;
            plm_bottom_half_src_ptr[plm_draw_tilemap_idx >> 1] = tile_table.tables[tile_table_idx].top_left ^ BLK_Y_FILP;
            plm_draw_tilemap_idx += 2;
            plm_top_half_src_ptr[plm_draw_tilemap_idx >> 1] = tile_table.tables[tile_table_idx].bottom_right ^ BLK_Y_FILP;
            plm_bottom_half_src_ptr[plm_draw_tilemap_idx >> 1] = tile_table.tables[tile_table_idx].top_right ^ BLK_Y_FILP;
          }
          else {
            plm_top_half_src_ptr[plm_draw_tilemap_idx >> 1] = tile_table.tables[tile_table_idx].bottom_right ^ BLK_X_Y_FLIP;
            plm_bottom_half_src_ptr[plm_draw_tilemap_idx >> 1] = tile_table.tables[tile_table_idx].top_right ^ BLK_X_Y_FLIP;
            plm_draw_tilemap_idx += 2;
            plm_top_half_src_ptr[plm_draw_tilemap_idx >> 1] = tile_table.tables[tile_table_idx].bottom_left ^ BLK_X_Y_FLIP;
            plm_bottom_half_src_ptr[plm_draw_tilemap_idx >> 1] = tile_table.tables[tile_table_idx].bottom_right ^ BLK_X_Y_FLIP;
          }
        }
        else {
          plm_top_half_src_ptr[plm_draw_tilemap_idx >> 1] = tile_table.tables[tile_table_idx].top_left;
          plm_bottom_half_src_ptr[plm_draw_tilemap_idx >> 1] = tile_table.tables[tile_table_idx].bottom_left;
          plm_draw_tilemap_idx += 2;
          plm_top_half_src_ptr[plm_draw_tilemap_idx >> 1] = tile_table.tables[tile_table_idx].top_right;
          plm_bottom_half_src_ptr[plm_draw_tilemap_idx >> 1] = tile_table.tables[tile_table_idx].bottom_right;
        }
        plm_draw_tilemap_idx += 2;
        draw_data_addr += 2;
        plm_draw_tilemap_index += 8;
        if (--draw_size == 0)
          break;
      }
    }
    // else drawing vertical
    else {
      uint16 draw_size = plm_draw_instr & 0x7FFF;  // 0x14
      uint16 screen_x_blk = layer1_x_pos / 16;
      // if the plm is within the screen bounds
      if ((int16)screen_x_blk <= (int16)plm_draw_x_blk && (int16)plm_draw_x_blk < (int16)(screen_x_blk + 17)) {
        uint16 r18 = plm_draw_x_blk;  // 0x18
        uint16 num_blks_skipped = 0;  // 0x12
        uint16 blks_below_screen = screen_y_blk + 16;  // 0x16
        if (screen_y_blk < plm_draw_y_blk) {
          screen_y_blk = plm_draw_y_blk;
        }
		else {
          num_blks_skipped = screen_y_blk - plm_draw_y_blk;
          if (sign16(plm_draw_y_blk + draw_size - screen_y_blk))
            return;
          draw_size -= num_blks_skipped;
          if ((int16)draw_size < 0)
            Unreachable();
          if (draw_size == 0)
            return;
        }
        num_blks_truncated = draw_size + screen_y_blk - blks_below_screen;
        if ((int16)num_blks_truncated >= 0) {
          draw_size -= num_blks_truncated;
                // the condition is never true
          if ((int16)draw_size <= 0)
			return;
		}
        uint16 space_left = (512 - plm_draw_tilemap_index) / 8;
        if (vram_write_queue_tail >= 240 || space_left < draw_size)
          return;
        inc_mode = 0x8000; // increment mode 32 bytes
        CalculatePlmDrawTilemapVramDst(vram_write_queue_tail, vram_1st_screen_base_addr, vram_2nd_screen_base_addr, draw_size, plm_draw_x_blk, screen_y_blk, inc_mode);
        VramWriteEntry *vram_entry = gVramWriteEntry(vram_write_queue_tail);
        vram_entry[1].vram_dst = vram_entry[0].vram_dst + 1;
        plm_top_half_src_ptr = (uint16 *)(g_ram + vram_entry[0].src.addr);
        plm_bottom_half_src_ptr = (uint16 *)(g_ram + vram_entry[1].src.addr);
        vram_write_queue_tail += 2*sizeof(VramWriteEntry);
        num_blks_skipped *= 2;
        draw_data_addr = plm_draw_instr_ptr + 2 + num_blks_skipped;
        uint16 plm_draw_tilemap_idx = 0;
        while (1) {
          uint16 block = GET_WORD(RomPtr_84orRAM(draw_data_addr));  // 0x1E
          uint16 tile_table_idx = block & 0x3FF;
          uint16 blk_flip_type = block & (BLK_VERT_FLIP | BLK_HORIZ_FLIP);
          if (block & BLK_HAS_FLIP) {
            if (blk_flip_type == BLK_HORIZ_FLIP) {
              plm_top_half_src_ptr[plm_draw_tilemap_idx >> 1] = tile_table.tables[tile_table_idx].top_right ^ BLK_X_FLIP;
              plm_bottom_half_src_ptr[plm_draw_tilemap_idx >> 1] = tile_table.tables[tile_table_idx].top_left ^ BLK_X_FLIP;
              plm_draw_tilemap_idx += 2;
              plm_top_half_src_ptr[plm_draw_tilemap_idx >> 1] = tile_table.tables[tile_table_idx].bottom_right ^ BLK_X_FLIP;
              plm_bottom_half_src_ptr[plm_draw_tilemap_idx >> 1] = tile_table.tables[tile_table_idx].bottom_left ^ BLK_X_FLIP;
            }
            else if (blk_flip_type == BLK_VERT_FLIP) {
              plm_top_half_src_ptr[plm_draw_tilemap_idx >> 1] = tile_table.tables[tile_table_idx].bottom_left ^ BLK_Y_FILP;
              plm_bottom_half_src_ptr[plm_draw_tilemap_idx >> 1] = tile_table.tables[tile_table_idx].bottom_right ^ BLK_Y_FILP;
              plm_draw_tilemap_idx += 2;
              plm_top_half_src_ptr[plm_draw_tilemap_idx >> 1] = tile_table.tables[tile_table_idx].top_left ^ BLK_Y_FILP;
              plm_bottom_half_src_ptr[plm_draw_tilemap_idx >> 1] = tile_table.tables[tile_table_idx].top_right ^ BLK_Y_FILP;
            }
			else {
              plm_top_half_src_ptr[plm_draw_tilemap_idx >> 1] = tile_table.tables[tile_table_idx].bottom_right ^ BLK_X_Y_FLIP;
              plm_bottom_half_src_ptr[plm_draw_tilemap_idx >> 1] = tile_table.tables[tile_table_idx].bottom_left ^ BLK_X_Y_FLIP;
              plm_draw_tilemap_idx += 2;
              plm_top_half_src_ptr[plm_draw_tilemap_idx >> 1] = tile_table.tables[tile_table_idx].top_left ^ BLK_X_Y_FLIP;
              plm_bottom_half_src_ptr[plm_draw_tilemap_idx >> 1] = tile_table.tables[tile_table_idx].bottom_right ^ BLK_X_Y_FLIP;
            }
          }
          else {
            plm_top_half_src_ptr[plm_draw_tilemap_idx >> 1] = tile_table.tables[tile_table_idx].top_left;
            plm_bottom_half_src_ptr[plm_draw_tilemap_idx >> 1] = tile_table.tables[tile_table_idx].top_right;
            plm_draw_tilemap_idx += 2;
            plm_top_half_src_ptr[plm_draw_tilemap_idx >> 1] = tile_table.tables[tile_table_idx].bottom_left;
            plm_bottom_half_src_ptr[plm_draw_tilemap_idx >> 1] = tile_table.tables[tile_table_idx].bottom_right;
          }
          plm_draw_tilemap_idx += 2;
          draw_data_addr += 2;
          plm_draw_tilemap_index += 8;
          if (--draw_size == 0)
            break;
        }
      }
      else
        return;
    }
    if ((int16)num_blks_truncated >= 0) {
      draw_data_addr += 2 * num_blks_truncated;
    }
    plm_draw_instr = *(uint16 *)RomPtr_84orRAM(draw_data_addr);
    if (plm_draw_instr == 0)
      return;
    int8 x_offset = *(int8 *)RomPtr_84orRAM(draw_data_addr);
    int8 y_offset = *(int8 *)RomPtr_84orRAM(draw_data_addr + 1);
    plm_draw_x_blk = plm_x_block + x_offset;
    plm_draw_y_blk = plm_y_block + y_offset;
    draw_data_addr += 2;
  }
}

/**
* @brief Draws the PLM
* @param plm_idx The index of the PLM
*/
void DrawPlm(uint16 plm_idx) {  // 0x848DAA
  int16 plm_draw_instr;
  int16 v5;
  int16 v8;
  VramWriteEntry *v10;
  VoidP v12;
  VoidP v13;
  VramWriteEntry *v15;
  int16 v18;
  bool v23; // sf
  VramWriteEntry *v25;
  int16 v28;
  int16 v31;
  uint16 v35, screen_x_blk, screen_y_blk, blks_below_screen;
  uint16 a, r24;
  uint16 draw_size, num_blks_skipped;
  uint16 vram_1st_screen_base_addr = addr_kVram_1stScreen;
  uint16 vram_2nd_screen_base_addr = addr_kVram_2ndScreenOffset;
  uint16 plm_draw_instr_ptr = plm_instruction_draw_ptr[plm_idx >> 1];
  uint16 plm_draw_x_blk = plm_x_block;
  uint16 plm_draw_y_blk = plm_y_block;
  uint16 r3;
  //LongPtr r0, r6;
  uint16 *r0, *r6;
LABEL_2:
  screen_y_blk = layer1_y_pos / 16;
  if ((int16)(screen_y_blk + 15) < (int16)plm_draw_y_blk)
    return;
  plm_draw_instr = *(uint16 *)RomPtr_84orRAM(plm_draw_instr_ptr);
  if (plm_draw_instr < 0) {
    draw_size = plm_draw_instr & 0x7FFF;
    screen_x_blk = layer1_x_pos / 16;
    // if the plm is within the screen bounds
    if ((int16)screen_x_blk <= (int16)plm_draw_x_blk && (int16)plm_draw_x_blk < (int16)(screen_x_blk + 17)) {
      r24 = plm_draw_x_blk;
      num_blks_skipped = 0;
      blks_below_screen = screen_y_blk + 16;
      if ((int16)(screen_y_blk - plm_draw_y_blk) < 0) {
        screen_y_blk = plm_draw_y_blk;
      }
      else {
        num_blks_skipped = screen_y_blk - plm_draw_y_blk;
        if (sign16(plm_draw_y_blk + draw_size - screen_y_blk))
          return;
        bool v21 = draw_size == num_blks_skipped;
        bool v22 = (int16)(draw_size - num_blks_skipped) < 0;
        draw_size -= num_blks_skipped;
        if (v22)
          Unreachable();
        if (v21)
          return;
      }
      blks_below_screen = draw_size + screen_y_blk - blks_below_screen;
      if ((blks_below_screen & 0x8000) != 0 || (v23 = (int16)(draw_size - blks_below_screen) < 0, (draw_size -= blks_below_screen) != 0) && !v23) {
        v35 = plm_idx;
        uint16 v24;
        v24 = vram_write_queue_tail;
        if ((int16)(vram_write_queue_tail - 240) < 0
            && !sign16(((uint16)(512 - plm_draw_tilemap_index) >> 3) - draw_size)) {
          CalculatePlmDrawTilemapVramDst(vram_write_queue_tail, vram_1st_screen_base_addr, vram_2nd_screen_base_addr, draw_size, r24, screen_y_blk, 0x8000);
          v25 = gVramWriteEntry(v24);
          v25[1].vram_dst = v25[0].vram_dst + 1;
          r0 = (uint16 *)(g_ram + v25[0].src.addr);
          r6 = (uint16 *)(g_ram + v25[1].src.addr);
          vram_write_queue_tail = v24 + 14;
          num_blks_skipped *= 2;
          r3 = num_blks_skipped + plm_draw_instr_ptr + 2;
          uint16 v26;
          v26 = 0;
          while (1) {
            plm_draw_x_blk = *(uint16 *)RomPtr_84orRAM(r3);
            uint16 v27, v29;
            v27 = plm_draw_x_blk & 0x3FF;
            v28 = plm_draw_x_blk & 0xC00;
            if ((plm_draw_x_blk & 0xC00) != 0) {
              if (v28 == 1024) {
                r0[v26 >> 1] = tile_table.tables[v27].top_right ^ 0x4000;
                r6[v26 >> 1] = tile_table.tables[v27].top_left ^ 0x4000;
                v29 = v26 + 2;
                r0[v29 >> 1] = tile_table.tables[v27].bottom_right ^ 0x4000;
                r6[v29 >> 1] = tile_table.tables[v27].bottom_left ^ 0x4000;
              } else if (v28 == 2048) {
                r0[v26 >> 1] = tile_table.tables[v27].bottom_left ^ 0x8000;
                r6[v26 >> 1] = tile_table.tables[v27].bottom_right ^ 0x8000;
                v29 = v26 + 2;
                r0[v29 >> 1] = tile_table.tables[v27].top_left ^ 0x8000;
                r6[v29 >> 1] = tile_table.tables[v27].top_right ^ 0x8000;
              } else {
                r0[v26 >> 1] = tile_table.tables[v27].bottom_right ^ 0xC000;
                r6[v26 >> 1] = tile_table.tables[v27].bottom_left ^ 0xC000;
                v29 = v26 + 2;
                r0[v29 >> 1] = tile_table.tables[v27].top_right ^ 0xC000;
                r6[v29 >> 1] = tile_table.tables[v27].top_left ^ 0xC000;
              }
            } else {
              r0[v26 >> 1] = tile_table.tables[v27].top_left;
              r6[v26 >> 1] = tile_table.tables[v27].top_right;
              v29 = v26 + 2;
              r0[v29 >> 1] = tile_table.tables[v27].bottom_left;
              r6[v29 >> 1] = tile_table.tables[v27].bottom_right;
            }
            v26 = v29 + 2;
            ++r3;
            ++r3;
            plm_draw_tilemap_index += 8;
            if (!sign16(plm_draw_tilemap_index - 512))
              break;
            if (!--draw_size) {
LABEL_70:
              plm_idx = v35;
              uint16 addr = r3;
              if ((blks_below_screen & 0x8000) == 0)
                addr = r3 + 2 * blks_below_screen;
              v31 = *(uint16 *)RomPtr_84orRAM(addr);
              if (v31) {
                plm_draw_x_blk = plm_x_block + (int8)v31;
                uint16 v32 = addr + 1;
                plm_draw_y_blk = plm_y_block + (int8)*RomPtr_84orRAM(v32);
                plm_draw_instr_ptr = v32 + 1;
                goto LABEL_2;
              }
              return;
            }
          }
        }
      }
    }
  } else {
    draw_size = plm_draw_instr & 0x7FFF;
    if (sign16(plm_draw_y_blk - screen_y_blk))
      return;
    screen_y_blk = plm_draw_y_blk;
    num_blks_skipped = 0;
    r24 = plm_draw_x_blk;
    blks_below_screen = ((uint16)(layer1_x_pos + 15) >> 4) - 1;
    if ((int16)(blks_below_screen - plm_draw_x_blk) >= 0 && blks_below_screen != plm_draw_x_blk) {
      num_blks_skipped = blks_below_screen - plm_draw_x_blk;
      if (plm_draw_x_blk + draw_size == blks_below_screen || (int16)(plm_draw_x_blk + draw_size - blks_below_screen) < 0)
        return;
      draw_size -= num_blks_skipped;
      r24 = blks_below_screen;
    }
    blks_below_screen += 17;
    if (!sign16(blks_below_screen - plm_draw_x_blk)) {
      blks_below_screen = draw_size + r24 - 1 - blks_below_screen;
      if ((blks_below_screen & 0x8000) != 0 || (draw_size -= blks_below_screen) != 0) {
        v35 = plm_idx;
        uint16 v3 = vram_write_queue_tail;
        if ((int16)(vram_write_queue_tail - 480) < 0
            && !sign16(((uint16)(512 - plm_draw_tilemap_index) >> 3) - draw_size)) {
          uint16 prod = (screen_y_blk & 0xF) * 0x40;
          uint16 v4 = r24 & 0x1F;
          if (v4 >= 0x10) {
            v8 = vram_2nd_screen_base_addr + 2 * v4;
            a = prod + v8;
            if ((bg1_x_offset & 0x100) != 0)
              a -= 1024;
          } else {
            v5 = vram_1st_screen_base_addr + 2 * v4;
            uint16 RegWord = prod;
            a = RegWord + v5;
            if ((bg1_x_offset & 0x100) != 0)
              a += 1024;
          }
          plm_draw_x_blk = 2 * draw_size;
          uint16 R34 = a & 0x1F;
          if (((2 * draw_size + (a & 0x1F) - 1) & 0xFFE0) != 0) {
            if ((int16)(v3 - 228) >= 0 || (int16)(32 - R34) < 0)
              return;
            uint16 v9 = 2 * (32 - R34);
            v10 = gVramWriteEntry(v3);
            v10->size = v9;
            v10[2].size = v9;
            v10[0].vram_dst = a;
            v10[1].vram_dst = a & 0xFFE0 ^ 0x400;
            v10[3].vram_dst = v10[1].vram_dst + 32;
            v10[2].vram_dst = v10->vram_dst + 32;
            plm_draw_x_blk = 4 * draw_size;
            uint16 v11 = 4 * draw_size - v10->size;
            v10[1].size = v11;
            v10[3].size = v11;
            v12 = plm_draw_tilemap_index - 14648;
            v10->src.addr = plm_draw_tilemap_index - 14648;
            r0 = (uint16 *)(g_ram + v12);
            v13 = v10->size + v12;
            v10[1].src.addr = v13;
            uint16 v14 = v10[1].size + v13;
            v10[2].src.addr = v14;
            r6 = (uint16 *)(g_ram + v14);
            v10[3].src.addr = v10[2].size + v14;
            v10->src.bank = 126;
            v10[1].src.bank = 126;
            v10[2].src.bank = 126;
            v10[3].src.bank = 126;
            vram_write_queue_tail = v3 + 28;
          } else {
            PartiallyQueueVramForSingleScreenPlm(a, v3, draw_size, 0);
            v15 = gVramWriteEntry(v3);
            v15[1].vram_dst = v15[0].vram_dst + 32;
            r0 = (uint16 *)(g_ram + v15[0].src.addr);
            r6 = (uint16 *)(g_ram + v15[1].src.addr);
            vram_write_queue_tail = v3 + 14;
          }
          num_blks_skipped *= 2;
          r3 = num_blks_skipped + plm_draw_instr_ptr + 2;
          uint16 v16 = 0;
          while (1) {
            plm_draw_x_blk = *(uint16 *)RomPtr_84orRAM(r3);
            uint16 v17 = plm_draw_x_blk & 0x3FF, v19;
            v18 = plm_draw_x_blk & 0xC00;
            if ((plm_draw_x_blk & 0xC00) != 0) {
              if (v18 == 1024) {
                r0[v16 >> 1] = tile_table.tables[v17].top_right ^ 0x4000;
                r6[v16 >> 1] = tile_table.tables[v17].bottom_right ^ 0x4000;
                v19 = v16 + 2;
                r0[v19 >> 1] = tile_table.tables[v17].top_left ^ 0x4000;
                r6[v19 >> 1] = tile_table.tables[v17].bottom_left ^ 0x4000;
              } else if (v18 == 2048) {
                r0[v16 >> 1] = tile_table.tables[v17].bottom_left ^ 0x8000;
                r6[v16 >> 1] = tile_table.tables[v17].top_left ^ 0x8000;
                v19 = v16 + 2;
                r0[v19 >> 1] = tile_table.tables[v17].bottom_right ^ 0x8000;
                r6[v19 >> 1] = tile_table.tables[v17].top_right ^ 0x8000;
              } else {
                r0[v16 >> 1] = tile_table.tables[v17].bottom_right ^ 0xC000;
                r6[v16 >> 1] = tile_table.tables[v17].top_right ^ 0xC000;
                v19 = v16 + 2;
                r0[v19 >> 1] = tile_table.tables[v17].bottom_left ^ 0xC000;
                r6[v19 >> 1] = tile_table.tables[v17].top_left ^ 0xC000;
              }
            } else {
              r0[v16 >> 1] = tile_table.tables[v17].top_left;
              r6[v16 >> 1] = tile_table.tables[v17].bottom_left;
              v19 = v16 + 2;
              r0[v19 >> 1] = tile_table.tables[v17].top_right;
              r6[v19 >> 1] = tile_table.tables[v17].bottom_right;
            }
            v16 = v19 + 2;
            r3 += 2;
            plm_draw_tilemap_index += 8;
            if (!sign16(plm_draw_tilemap_index - 512))
              break;
            if (!--draw_size)
              goto LABEL_70;
          }
        }
      }
    }
  }
}

/**
* @brief Moves the PLM block down one row of blocks
* @param plmp The pointer to the PLM
* @param plm_idx The index of the PLM
* @return uint8* The pointer to the next PLM instruction
*/
const uint8 *PlmInstr_MovePlmDownOneBlock(const uint8 *plmp, uint16 plm_idx) {  // 0x84AB00
  plm_block_indices[plm_idx >> 1] += (2 * room_width_in_blocks);
  return plmp;
}

/**
* @brief Wait for 64 frames before crumbling the wall
* @param plm_idx The index of the PLM
* @return uint8 0
*/
uint8 PlmSetup_CrumbleBotwoonWall(uint16 plm_idx) {  // 0x84AB28
  plm_instruction_timer[plm_idx >> 1] = 64;
  return 0;
}

/**
* @brief Sets scrolls 0 and 1 to blue
* @param plmp The pointer to the PLM
* @param plm_idx The index of the PLM
* @return uint8* The pointer to the next PLM instruction
*/
const uint8 *PlmInstr_Scroll_0_1_Blue(const uint8 *plmp, uint16 plm_idx) {  // 0x84AB51
  scrolls[1] = scrolls[0] = kScroll_Blue;
  return plmp;
}

/**
* @brief Moves the PLM block down one row of blocks
* @param plmp The pointer to the PLM
* @param plm_idx The index of the PLM
* @return uint8* The pointer to the next PLM instruction
*/
const uint8 *PlmInstr_MovePlmDownOneBlock_0(const uint8 *plmp, uint16 plm_idx) {  // 0x84AB59
  plm_block_indices[plm_idx >> 1] += 2 * room_width_in_blocks;
  return plmp;
}

/**
* @brief Moves the PLM block to the right one block
* @param plmp The pointer to the PLM
* @param plm_idx The index of the PLM
* @return uint8* The pointer to the next PLM instruction
*/
const uint8 *PlmInstr_MovePlmRight1Block(const uint8 *plmp, uint16 plm_idx) {  // 0x84ABD6
  plm_block_indices[plm_idx >> 1] += 2;
  return plmp;
}

/**
* @brief Sets Samus' position to the PLM block's position and makes Samus invincible for 16 extra frames
* @param plm_idx The index of the PLM
*/
void PlmPreInstr_PositionSamusAndInvincible(uint16 plm_idx) {  // 0x84AC89
  int idx = plm_idx >> 1;
  samus_x_pos = plm_variable[idx];  // plm samus x pos
  samus_y_pos = plm_variables[idx];  // plm samus y pos
  samus_invincibility_timer |= 0x10;
}

/**
* @brief Gives Samus 2 damage
* @param plmp The pointer to the PLM
* @param plm_idx The index of the PLM
* @return uint8* The pointer to the next PLM instruction
*/
const uint8 *PlmInstr_DealDamage_2(const uint8 *plmp, uint16 plm_idx) {  // 0x84AC9D
  samus_periodic_damage += 2;
  return plmp;
}

/**
* @brief Sets Samus invincibility to 48 frames
* @param plmp The pointer to the PLM
* @param plm_idx The index of the PLM
* @return uint8* The pointer to the next PLM instruction
*/
const uint8 *PlmInstr_GiveInvincibility(const uint8 *plmp, uint16 plm_idx) {  // 0x84ACB1
  samus_invincibility_timer = 48;
  return plmp;
}

/**
* @brief Draws 56 blank tiles of the right treadmill
* @param plmp The pointer to the PLM
* @param plm_idx The index of the PLM
* @return uint8* The pointer to the next PLM instruction
*/
const uint8 *PlmInstr_Draw0x38FramesOfRightTreadmill(const uint8 *plmp, uint16 plm_idx) {  // 0x84AD43
  WriteRowOfLevelDataBlockAndBTS(plm_idx, 0x30ff, 0x8, 56);
  return plmp;
}

/**
* @brief Draws 56 blank tiles of the left treadmill
* @param plmp The pointer to the PLM
* @param plm_idx The index of the PLM
* @return uint8* The pointer to the next PLM instruction
*/
const uint8 *PlmInstr_Draw0x38FramesOfLeftTreadmill(const uint8 *plmp, uint16 plm_idx) {  // 0x84AD58
  WriteRowOfLevelDataBlockAndBTS(plm_idx, 0x30ff, 0x9, 56);
  return plmp;
}

/**
* @brief Enables Samus' movement and goes to the instruction specified in the instruction list
* if Samus' health is full
* @param plmp The pointer to the PLM
* @param plm_idx The index of the PLM
* @return uint8* The pointer to the instruction specified if Samus' health is full,
* otherwise the next PLM instruction
*/
const uint8 *PlmInstr_GotoIfSamusHealthFull(const uint8 *plmp, uint16 plm_idx) {  // 0x84AE35
  if (samus_max_health != samus_health)
    return plmp + 2;
  RunSamusCode(kSamusCode_1_UnlockSamus);
  return INSTRB_RETURN_ADDR(GET_WORD(plmp));
}

/**
* @brief Enables Samus' movement and goes to the instruction specified in the instruction list
* if Samus' missiles are full
* @param plmp The pointer to the PLM
* @param plm_idx The index of the PLM
* @return uint8* The pointer to the instruction specified if Samus' missiles are full,
* otherwise the next PLM instruction
*/
const uint8 *PlmInstr_GotoIfMissilesFull(const uint8 *plmp, uint16 plm_idx) {  // 0x84AEBF
#if 1
  if (samus_max_missiles != samus_missiles || samus_max_super_missiles != samus_super_missiles || samus_max_power_bombs != samus_power_bombs) {
    return plmp + 2;
  }
#endif
  if (samus_max_missiles != samus_missiles)
    return plmp + 2;
  RunSamusCode(kSamusCode_1_UnlockSamus);
  return INSTRB_RETURN_ADDR(GET_WORD(plmp));
}

/**
* @brief Adjusts Samus' position to the save station and makes Samus face forward
* @param plmp The pointer to the PLM
* @param plm_idx The index of the PLM
* @return uint8* The pointer to the next PLM instruction
*/
const uint8 *PlmInstr_PlaceSamusOnSaveStation(const uint8 *plmp, uint16 plm_idx) {  // 0x84B00E
  // samus_x_pos = samus_x_pos - samus_x_pos % 16 + 8;
  samus_x_pos = (samus_x_pos + 8) & 0xFFF0;
  MakeSamusFaceForward();
  return plmp;
}

/**
* @brief Displays the game saved message box
* @param plmp The pointer to the PLM
* @param plm_idx The index of the PLM
* @return uint8* The pointer to the next PLM instruction
*/
const uint8 *PlmInstr_DisplayGameSavedMessageBox(const uint8 *plmp, uint16 plm_idx) {  // 0x84B024
  DisplayMessageBox(kMessageBox_24_SaveCompleted);
  return plmp;
}

/**
* @brief Enables Samus' movement and sets the save station as used
* @param plmp The pointer to the PLM
* @param plm_idx The index of the PLM
* @return uint8* The pointer to the next PLM instruction
*/
const uint8 *PlmInstr_EnableMovementAndSetSaveStationUsed(const uint8 *plmp, uint16 plm_idx) {  // 0x84B030
  RunSamusCode(kSamusCode_1_UnlockSamus);
  save_station_lockout_flag = 1;
  return plmp;
}

/**
* @brief Writes 56 blank air tiles to the Wrecked Ship entrance treadmill
* @param plm_idx The index of the PLM
* @return 0
*/
uint8 PlmSetup_SetupWreckedShipEntrance(uint16 plm_idx) {  // 0x84B04A
  uint16 plm_blk_idx = plm_block_indices[plm_idx >> 1];
  uint16 blank_air_blk = 0xFF;
  int16 num_blks = 56;
  memset7E(level_data + (plm_blk_idx >> 1), blank_air_blk, 2*num_blks);
  return 0;
}

/**
* @brief Deactivates the block if Samus is at the bottom of the block and sets the PLM's position
* to Samus' position
* @param plm_idx The index of the PLM
* @return 0
*/
uint8 PlmSetup_BTS_Brinstar_0x80_Floorplant(uint16 plm_idx) {  // 0x84B0DC
  // if Samus' y position is at the bottom of the block
  if (((samus_y_radius + samus_y_pos - 1) & 0xF) == 15) {
    int plm_blk_idx = plm_block_indices[plm_idx >> 1] >> 1;
    level_data[plm_blk_idx] = DEACTIVATE_BLK(level_data[plm_blk_idx]);
    int idx = plm_idx >> 1;
    // plm samus x pos
    plm_variable[idx] = samus_x_pos;
    // plm samus y pos
    plm_variables[idx] = samus_y_pos - 1;
  }
  else {
    plm_header_ptr[plm_idx >> 1] = 0;
  }
  return 0;
}

/**
* @brief Deactivates the block if Samus is at the top of the block and sets the PLM's position
* to Samus' position
* @param plm_idx The index of the PLM
* @return 0
*/
uint8 PlmSetup_BTS_Brinstar_0x81_Ceilingplant(uint16 plm_idx) {  // 0x84B113
  // if Samus' y position is at the top of the block
  if (((samus_y_pos - samus_y_radius) & 0xF) != 0) {
    plm_header_ptr[plm_idx >> 1] = 0;
  }
  else {
    int plm_blk_idx = plm_block_indices[plm_idx >> 1] >> 1;
    level_data[plm_blk_idx] = DEACTIVATE_BLK(level_data[plm_blk_idx]);
    int idx = plm_idx >> 1;
    // plm samus x pos
    plm_variable[idx] = samus_x_pos;
    // plm samus y pos
    plm_variables[idx] = samus_y_pos + 1;
  }
  return 0;
}

/**
* @brief Activates the station at the PLM block index if Samus' cannon is lined up
* @param plm_blk_idx The index of the PLM block
* @param plm_idx The index of the PLM
* @return 1
*/
uint8 ActivateStationIfSamusCannonLinedUp(uint16 plm_blk_idx, uint16 plm_idx) {  // 0x84B146
  int16 blk_idx = MAX_PLMS-2;
  while (plm_blk_idx != plm_block_indices[blk_idx >> 1]) {
    blk_idx -= 2;
    if (blk_idx < 0) {
      plm_header_ptr[plm_idx >> 1] = 0;
      return 1;
    }
  }
  CalculatePlmBlockCoords(plm_id);
  if (((uint16)(16 * plm_y_block) + 11) == samus_y_pos) {
    int idx = blk_idx >> 1;
    plm_instr_list_ptrs[idx] = plm_instruction_list_link_reg[idx];
    plm_instruction_timer[idx] = 1;
    RunSamusCode(kSamusCode_6_LockToStation);
    return 1;
  }
  plm_header_ptr[plm_idx >> 1] = 0;
  return 1;
}

/**
* @brief Makes the map station accessible if the area map has not been collected
* @param plm_idx The index of the PLM
* @return 0
*/
uint8 PlmSetup_B6D3_MapStation(uint16 plm_idx) {  // 0x84B18B
  uint16 plm_blk_data;
  int idx = plm_idx >> 1;
  int plm_blk_idx = plm_block_indices[idx] >> 1;
  level_data[plm_blk_idx] = SET_BLK_TYPE(level_data[plm_blk_idx], kBlockType_8_SolidBlock);
  if (map_station_byte_array[area_index]) {
    plm_instr_list_ptrs[idx] = addr_kPlmInstrList_MapStation_FastAnim;
  }
  else {
    plm_blk_data = PLM_TYPE_BTS(kBlockType_B_SpecialBlock, kBtsType_Special_47_MapStationRightAccess);
    WriteLevelDataBlockTypeAndBts(plm_block_indices[idx] + 2, plm_blk_data);
    plm_blk_data = PLM_TYPE_BTS(kBlockType_B_SpecialBlock, kBtsType_Special_48_MapStationLeftAccess);
    WriteLevelDataBlockTypeAndBts(plm_block_indices[idx] - 4, plm_blk_data); 
  }
  return 0;
}

/**
* @brief Makes the map station accessible from the right if Samus is facing left and ran into the station
* @param plm_idx The index of the PLM
* @return 1
*/
uint8 PlmSetup_Bts47_MapStationRightAccess(uint16 plm_idx) {  // 0x84B1C8
  if ((samus_collision_direction & kSamusCollDir_DirMask) == kSamusCollDir_0_Left
      && samus_pose == kPose_8A_FaceL_Ranintowall
      && (samus_pose_x_dir & kSamusXDir_FaceLeft))
    return ActivateStationIfSamusCannonLinedUp(plm_block_indices[plm_idx >> 1] - 2, plm_idx);
  plm_header_ptr[plm_idx >> 1] = 0;
  return 1;
}

/**
* @brief Makes the map station accessible from the left if Samus is facing right and ran into the station
* @param plm_idx The index of the PLM
* @return 1
*/
uint8 PlmSetup_Bts4_MapStationLeftAccess(uint16 plm_idx) {  // 0x84B1F0
  if ((samus_collision_direction & kSamusCollDir_DirMask) == kSamusCollDir_1_Right
      && samus_pose == kPose_89_FaceR_Ranintowall
      && (samus_pose_x_dir & kSamusXDir_FaceRight))
    return ActivateStationIfSamusCannonLinedUp(plm_block_indices[plm_idx >> 1] + 4, plm_idx);
  plm_header_ptr[plm_idx >> 1] = 0;
  return 1;
}

/**
* @brief Makes the PLM block solid and makes the energy station accessible
* @param plm_idx The index of the PLM
* @return 0
*/
uint8 PlmSetup_PlmB6DF_EnergyStation(uint16 plm_idx) {  // 0x84B21D
  uint16 plm_blk_data;
  int idx = plm_idx >> 1;
  int plm_blk_idx = plm_block_indices[idx] >> 1;
  level_data[plm_blk_idx] = SET_BLK_TYPE(level_data[plm_blk_idx], kBlockType_8_SolidBlock);

  plm_blk_data = PLM_TYPE_BTS(kBlockType_B_SpecialBlock, kBtsType_Special_49_EnergyStationRightAccess);
  WriteLevelDataBlockTypeAndBts(plm_block_indices[idx] + 2, plm_blk_data);
  plm_blk_data = PLM_TYPE_BTS(kBlockType_B_SpecialBlock, kBtsType_Special_4A_EnergyStationLeftAccess);
  WriteLevelDataBlockTypeAndBts(plm_block_indices[idx] - 2, plm_blk_data);

  return 0;
}

/**
* @brief Makes the PLM block solid and makes the missile station accessible
* @param plm_idx The index of the PLM
* @return 0
*/
uint8 PlmSetup_PlmB6EB_MissileStation(uint16 plm_idx) {  // 0x84B245
  uint16 plm_blk_data;
  int idx = plm_idx >> 1;
  int plm_blk_idx = plm_block_indices[idx] >> 1;
  level_data[plm_blk_idx] = SET_BLK_TYPE(level_data[plm_blk_idx], kBlockType_8_SolidBlock);

  plm_blk_data = PLM_TYPE_BTS(kBlockType_B_SpecialBlock, kBtsType_Special_4B_MissileStationRightAccess);
  WriteLevelDataBlockTypeAndBts(plm_block_indices[idx] + 2, plm_blk_data);
  plm_blk_data = PLM_TYPE_BTS(kBlockType_B_SpecialBlock, kBtsType_Special_4C_MissileStationLeftAccess);
  WriteLevelDataBlockTypeAndBts(plm_block_indices[idx] - 2, plm_blk_data);

  return 0;
}

/**
* @brief Makes the energy station accessible from the right if Samus is facing left and ran into the station
* @param plm_idx The index of the PLM
* @return 1
*/
uint8 PlmSetup_B6E3_EnergyStationRightAccess(uint16 plm_idx) {  // 0x84B26D
  if ((samus_collision_direction & kSamusCollDir_DirMask) == kSamusCollDir_0_Left
      && samus_pose == kPose_8A_FaceL_Ranintowall
      && (samus_pose_x_dir & kSamusXDir_FaceLeft)
      && samus_health != samus_max_health) {
    return ActivateStationIfSamusCannonLinedUp(plm_block_indices[plm_idx >> 1] - 2, plm_idx);

  }
  plm_header_ptr[plm_idx >> 1] = 0;
  return 1;
}

/**
* @brief Makes the energy station accessible from the left if Samus is facing right and ran into the station
* @param plm_idx The index of the PLM
* @return 1
*/
uint8 PlmSetup_B6E7_EnergyStationLeftAccess(uint16 plm_idx) {  // 0x84B29D
  if ((samus_collision_direction & kSamusCollDir_DirMask) == kSamusCollDir_1_Right
      && samus_pose == kPose_89_FaceR_Ranintowall
      && (samus_pose_x_dir & kSamusXDir_FaceRight)
      && samus_health != samus_max_health) {
    return ActivateStationIfSamusCannonLinedUp(plm_block_indices[plm_idx >> 1] + 2, plm_idx);
  }
  plm_header_ptr[plm_idx >> 1] = 0;
  return 1;
}

/**
* @brief Makes the missile station accessible from the right if Samus is facing left and ran into the station
* @param plm_idx The index of the PLM
* @return 1
*/
uint8 PlmSetup_B6EF_MissileStationRightAccess(uint16 plm_idx) {  // 0x84B2D0
  if ((samus_collision_direction & kSamusCollDir_DirMask) == kSamusCollDir_0_Left
      && samus_pose == kPose_8A_FaceL_Ranintowall
      && (samus_pose_x_dir & kSamusXDir_FaceLeft)
      && (samus_missiles != samus_max_missiles
#if 1
      || samus_super_missiles != samus_max_super_missiles || samus_power_bombs != samus_max_power_bombs
#endif
      )) {
    return ActivateStationIfSamusCannonLinedUp(plm_block_indices[plm_idx >> 1] - 2, plm_idx);
  }
  plm_header_ptr[plm_idx >> 1] = 0;
  return 1;
}

/**
* @brief Makes the missile station accessible from the left if Samus is facing right and ran into the station
* @param plm_idx The index of the PLM
* @return 1
*/
uint8 PlmSetup_B6F3_MissileStationLeftAccess(uint16 plm_idx) {  // 0x84B300
  if ((samus_collision_direction & kSamusCollDir_DirMask) == kSamusCollDir_1_Right
      && samus_pose == kPose_89_FaceR_Ranintowall
      && (samus_pose_x_dir & kSamusXDir_FaceRight)
      && (samus_missiles != samus_max_missiles
#if 1
      || samus_super_missiles != samus_max_super_missiles || samus_power_bombs != samus_max_power_bombs
#endif
      )) {
    return ActivateStationIfSamusCannonLinedUp(plm_block_indices[plm_idx >> 1] + 2, plm_idx);
  }
  plm_header_ptr[plm_idx >> 1] = 0;
  return 1;
}

/**
* @brief Deactivates the PLM
* @param plm_idx The index of the PLM
*/
void DeletePlm(uint16 plm_idx) {  // 0x84B333
  plm_header_ptr[plm_idx >> 1] = 0;
}

/**
* @brief Sets the PLM block to a rightwards extension of the block to the left of it
* @param plm_idx The index of the PLM
* @return 0
*/
uint8 PlmSetup_B638_Rightwards_Extension(uint16 plm_idx) {  // 0x84B33A
  uint16 plm_blk_data = PLM_TYPE_BTS(kBlockType_5_HorizExtension, (uint8)-1);
  WriteLevelDataBlockTypeAndBts(plm_block_indices[plm_idx >> 1], plm_blk_data);
  DeletePlm(plm_idx);
  return 0;
}

/**
* @brief Sets the PLM block to a leftwards extension of the block to the right of it
* @param plm_idx The index of the PLM
* @return 0
*/
uint8 PlmSetup_B63F_Leftwards_Extension(uint16 plm_idx) {  // 0x84B345
  uint16 plm_blk_data = PLM_TYPE_BTS(kBlockType_5_HorizExtension, 1);
  WriteLevelDataBlockTypeAndBts(plm_block_indices[plm_idx >> 1], plm_blk_data);
  DeletePlm(plm_idx);
  return 0;
}

/**
* @brief Sets the PLM block to a downwards extension of the block above it
* @param plm_idx The index of the PLM
* @return 0
*/
uint8 PlmSetup_B643_Downwards_Extension(uint16 plm_idx) {  // 0x84B350
  uint16 plm_blk_data = PLM_TYPE_BTS(kBlockType_D_VertExtension, (uint8)-1);
  WriteLevelDataBlockTypeAndBts(plm_block_indices[plm_idx >> 1], plm_blk_data);
  DeletePlm(plm_idx);
  return 0;
}

/**
* @brief Sets the PLM block to an upwards extension of the block below it
* @param plm_idx The index of the PLM
* @return 0
*/
uint8 PlmSetup_B647_Upwards_Extension(uint16 plm_idx) {  // 0x84B35B
  uint16 plm_blk_data = PLM_TYPE_BTS(kBlockType_D_VertExtension, 1);
  WriteLevelDataBlockTypeAndBts(plm_block_indices[plm_idx >> 1], plm_blk_data);
  DeletePlm(plm_idx);
  return 0;
}

/**
* @brief Skips the draw instruction for the scroll PLMs
* @param plm_idx The index of the PLM
*/
void SkipDebugDrawInstructionsForScrollPlms(uint16 plm_idx) {  // 0x84B366
  plm_instr_list_ptrs[plm_idx >> 1] += 4;
}

/**
* @brief Sets the PLM block to a scroll PLM and sets the PLM to not triggered
* @param plm_idx The index of the PLM
* @return 0
*/
uint8 PlmSetup_B703_ScrollPLM(uint16 plm_idx) {  // 0x84B371
  int idx = plm_idx >> 1;
  uint16 plm_blk_data = PLM_TYPE_BTS(kBlockType_3_SpecialAir, kBtsType_Special_46_ScrollPLMTrigger);
  WriteLevelDataBlockTypeAndBts(plm_block_indices[idx], plm_blk_data);
  plm_variable[idx] = 0;
  SkipDebugDrawInstructionsForScrollPlms(plm_idx);
  return 0;
}

/**
* @brief Sets the PLM block to a solid scroll PLM and sets the PLM to not triggered
* @brief This is used by an unused PLM, so the function is unused
* @param plm_idx The index of the PLM
* @return 0
*/
uint8 PlmSetup_B707_SolidScrollPLM(uint16 plm_idx) {  // 0x84B382
  int idx = plm_idx >> 1;
  uint16 plm_blk_data = PLM_TYPE_BTS(kBlockType_B_SpecialBlock, kBtsType_Special_46_ScrollPLMTrigger);
  WriteLevelDataBlockTypeAndBts(plm_block_indices[idx], plm_blk_data);
  plm_variable[idx] = 0;
  SkipDebugDrawInstructionsForScrollPlms(plm_idx);
  return 0;
}

/**
* @brief Triggers the scroll block touch PLM
* @param plm_idx The index of the PLM
* @return 0
*/
uint8 PlmSetup_B6FF_ScrollBlockTouch(uint16 plm_idx) {  // 0x84B393
  int idx = plm_idx >> 1;
  uint16 plm_blk_idx = plm_block_indices[idx];
  plm_block_indices[idx] = 0;
  int16 blk_idx = MAX_PLMS-2;
  while (plm_blk_idx != plm_block_indices[blk_idx >> 1]) {
    blk_idx -= 2;
    if (blk_idx < 0) {
      Unreachable();
    }
  }

  idx = blk_idx >> 1;
  // if plm not triggered
  if ((plm_variable[idx] & 0x8000) == 0) {
    plm_variable[idx] = 0x8000;  // set plm triggered
    plm_instr_list_ptrs[idx] += 2;
    plm_instruction_timer[idx] = 1;
  }
  return 0;
}

/**
* @brief Deactivates the PLM
* @param plm_idx The index of the PLM
* @return 0
*/
uint8 PlmSetup_DeactivatePlm(uint16 plm_idx) {  // 0x84B3C1
  int plm_blk_idx = plm_block_indices[plm_idx >> 1] >> 1;
  level_data[plm_blk_idx] = DEACTIVATE_BLK(level_data[plm_blk_idx]);
  return 0;
}

/**
* @brief Does nothing
* @param plm_idx The index of the PLM
* @return 0
*/
uint8 PlmSetup_ReturnCarryClear(uint16 plm_idx) {  // 0x84B3D0
  return 0;
}

/**
* @brief Does nothing
* @brief This is used by an unused PLM, so the function is unused
* @param plm_idx The index of the PLM
* @return 1
*/
uint8 PlmSetup_ReturnCarrySet(uint16 plm_idx) {  // 0x84B3D2
  return 1;
}

/**
* @brief Turns the enemy breakable block into an air block
* @param plm_idx The index of the PLM
* @return 0
*/
uint8 PlmSetup_D094_EnemyBreakableBlock(uint16 plm_idx) {  // 0x84B3D4
  int plm_blk_idx = plm_block_indices[plm_idx >> 1] >> 1;
  level_data[plm_blk_idx] = SET_BLK_TYPE(level_data[plm_blk_idx], kBlockType_0_Air);
  return 0;
}

uint8 PlmSetup_B743_Unused(uint16 plm_idx) {  // 0x84B3E3
  assert(0);
  return 0;
}

/**
* @brief Decelerates Samus if she is aligned with the middle or bottom of the block
* @brief This is used by an unused PLM, so the function is unused
* @param plm_idx The index of the PLM
* @return 0
*/
uint8 PlmSetup_B70F_IcePhysics(uint16 plm_idx) {  // 0x84B3EB
  // if Samus is touching the middle or bottom of the block
  if (((samus_y_radius + samus_y_pos - 1) & 0xF) == 7 || ((samus_y_radius + samus_y_pos - 1) & 0xF) == 15) {
    WORD(samus_x_decel_mult) = 16;
  }
  return 0;
}

static Func_Y_V *const kPlmSetup_InsideReaction_QuicksandSurface[4] = {  // 0x84B408
  [kSamusYDir_None] = InReact_QuicksandSurface_SamusOnGround,
  [kSamusYDir_Up]   = InReact_QuicksandSurface_SamusMovingUp,
  [kSamusYDir_Down] = InReact_QuicksandSurface_SamusMovingDown,
  InReact_QuicksandSurface_SamusOnGround,
};

// [0] = no gravity suit, [1] = gravity suit
static const uint16 kInReact_QuicksandSurface_DistMoveSamusVert_Air[2] = { 0x200, 0x200 };
static const uint16 kInReact_QuicksandSurface_DistMoveSamusVert_Ground[2] = { 0x120, 0x100 };
static const uint16 kInReact_QuicksandSurface_MaxVertVel[2] = { 0x280, 0x380 };

/**
* @brief Kills Samus' X velocity and sets the Y velocity if touching the quicksand surface
* @param plm_idx The index of the PLM
* @return 0
*/
uint8 PlmSetup_InsideReaction_QuicksandSurface(uint16 plm_idx) {
  samus_has_momentum_flag = 0;
  speed_boost_counter = 0;
  samus_echoes_sound_flag = 0;
  samus_x_extra_run_subspeed = 0;
  samus_x_extra_run_speed = 0;
  samus_x_base_subspeed &= ~0x8000;
  samus_x_base_speed = 0;
  uint16 suit_offset = 0;
  if (equipped_items & kItem_GravitySuit)
    suit_offset = 2;
  if (inside_block_reaction_samus_point == kInsideBlockReactionSamusPoint_0_Bottom)
    kPlmSetup_InsideReaction_QuicksandSurface[samus_y_dir & 3](suit_offset);
  return 0;
}

/**
* @brief Sets Samus' y speed to 0 and displacement to 2 pixels
* @param suit_offset The offset into the table, 0 for no gravity suit, 2 for gravity suit
*/
void InReact_QuicksandSurface_SamusOnGround(uint16 suit_offset) {  // 0x84B447
  samus_y_subspeed = 0;
  samus_y_speed = 0;
  extra_samus_y_subdisplacement = 0;
  extra_samus_y_displacement = 0;
  uint16 y_disp = kInReact_QuicksandSurface_DistMoveSamusVert_Ground[suit_offset >> 1];
  HIBYTE(extra_samus_y_subdisplacement) = y_disp % 0x100;
  LOBYTE(extra_samus_y_displacement) = y_disp / 0x100;
}

/**
* @brief Sets Samus' y speed to the maximum vertical velocity and displacement to 2 pixels
* @param suit_offset The offset into the table, 0 for no gravity suit, 2 for gravity suit
*/
void InReact_QuicksandSurface_SamusMovingUp(uint16 suit_offset) {  // 0x84B45A
  int idx = suit_offset >> 1;
  uint16 max_y_vel = kInReact_QuicksandSurface_MaxVertVel[idx];
  uint16 y_disp = kInReact_QuicksandSurface_DistMoveSamusVert_Air[idx];
  uint16 y_speed = PAIR16(LOBYTE(samus_y_speed), HIBYTE(samus_y_subspeed));
  if (max_y_vel < y_speed) {
    samus_y_subspeed = 0;
    samus_y_speed = 0;
    //*(uint16 *)((uint8 *)&samus_y_subspeed + 1) = max_y_vel;
    HIBYTE(samus_y_subspeed) = max_y_vel % 0x100;
    LOBYTE(samus_y_speed) = max_y_vel / 0x100;
  }
  extra_samus_y_subdisplacement = 0;
  extra_samus_y_displacement = 0;
  //*(uint16 *)((uint8 *)&extra_samus_y_subdisplacement + 1) = y_disp;
  HIBYTE(extra_samus_y_subdisplacement) = y_disp % 0x100;
  LOBYTE(extra_samus_y_displacement) = y_disp / 0x100;
}

/**
* @brief Sets Samus' y displacement to 2 pixels
* @param suit_offset The offset into the table, 0 for no gravity suit, 2 for gravity suit
*/
void InReact_QuicksandSurface_SamusMovingDown(uint16 suit_offset) {  // 0x84B47B
  extra_samus_y_subdisplacement = 0;
  extra_samus_y_displacement = 0;
  uint16 y_disp = kInReact_QuicksandSurface_DistMoveSamusVert_Air[suit_offset >> 1];
  //*(uint16 *)((uint8 *)&extra_samus_y_subdisplacement + 1) = y_disp;
  HIBYTE(extra_samus_y_subdisplacement) = y_disp % 0x100;
  LOBYTE(extra_samus_y_displacement) = y_disp / 0x100;
  autojump_timer = 0;
}

/**
* @brief Sets Samus' extra Y displacement to 0x1.2000
* @param plm_idx The index of the PLM
* @return 0
*/
uint8 PlmSetup_B71F_SubmergingQuicksand(uint16 plm_idx) {  // 0x84B497
  autojump_timer = 0;
  extra_samus_y_subdisplacement = 0x2000;
  extra_samus_y_displacement = 1;
  return 0;
}

/**
* @brief Sets Samus' extra Y displacement to 0x1.4000
* @param plm_idx The index of the PLM
* @return 0
*/
uint8 PlmSetup_B723_SandfallsSlow(uint16 plm_idx) {  // 0x84B4A8
  extra_samus_y_subdisplacement = 0x4000;
  extra_samus_y_displacement = 1;
  return 0;
}

/**
* @brief Sets Samus' extra Y displacement to 0x1.C000
* @param plm_idx The index of the PLM
* @return 0
*/
uint8 PlmSetup_B727_SandFallsFast(uint16 plm_idx) {  // 0x84B4B6
  extra_samus_y_subdisplacement = 0xC000;
  extra_samus_y_displacement = 1;
  return 0;
}

static Func_Y_Y* const kPlmSetup_CollisionReaction_QuicksandSurface[4] = {  // 0x84B4C4
  [kSamusYDir_None] = CollReact_QuicksandSurface_SamusOnGround,
  [kSamusYDir_Up]   = CollReact_QuicksandSurface_SamusMovingUp,
  [kSamusYDir_Down] = CollReact_QuicksandSurface_SamusMovingDown,
  CollReact_QuicksandSurface_SamusOnGround,
};

// [0] = no gravity suit, [1] = gravity suit
static const uint16 kCollReact_QuicksandSurface_MaxSinkSpeed[2] = { 0x30, 0x30 };

/**
* @brief Sets the collision reaction for Samus in quicksand
* @param plm_idx The index of the PLM
* @return uint8 1 if there was a collision, 0 if there was not
*/
uint8 PlmSetup_CollisionReaction_QuicksandSurface(uint16 plm_idx) {
  if (!(samus_collision_direction & kSamusCollDir_VertMask))
    return 0;

  if (cur_coll_amt32 == NULL) {
    printf("ERROR: PlmSetup_QuicksandSurfaceB is broken!!\n");
    Unreachable();
    return 0;
  }

  uint16 suit_offset = 0;
  if (equipped_items & kItem_GravitySuit)
    suit_offset = 2;
  return kPlmSetup_CollisionReaction_QuicksandSurface[samus_y_dir & 3](suit_offset);
}

/**
* @brief Adjusts collision distance if Samus is on the ground in quicksand
* @param suit_offset The offset into the table, 0 for no gravity suit, 2 for gravity suit
* @return uint8 1 if there was a collision, 0 if there was not
*/
uint16 CollReact_QuicksandSurface_SamusOnGround(uint16 suit_offset) {  // 0x84B500
  if ((samus_collision_direction & kSamusCollDir_DirMask) == kSamusCollDir_3_Down) {
    if (samus_contact_damage_index == kSamusContactDamageIndex_1_SpeedBoost) {
      return CollReact_QuicksandSurface_SpeedBoosting();
    }
    uint16 max_sink_speed = kCollReact_QuicksandSurface_MaxSinkSpeed[suit_offset >> 1];
    if ((uint16)(*cur_coll_amt32 >> 8) > max_sink_speed)
      *cur_coll_amt32 = (*cur_coll_amt32 & 0xff0000ff) | 0x3000;// R19_ = 0x30;
    flag_samus_in_quicksand++;
  }
  return 0;
}

/**
* @brief Does not affect collision distance if Samus is moving up in quicksand
* @param suit_offset The offset into the table, 0 for no gravity suit, 2 for gravity suit
* @return uint8 0, indicating there was no collision
*/
uint16 CollReact_QuicksandSurface_SamusMovingUp(uint16 suit_offset) {  // 0x84B528
  return 0;
}

/**
* @brief Does not affect collision distance if Samus is moving down in quicksand
* @param suit_offset The offset into the table, 0 for no gravity suit, 2 for gravity suit
* @return uint8 1 if there was a collision, 0 if there was not
*/
uint16 CollReact_QuicksandSurface_SamusMovingDown(uint16 suit_offset) {
  if (samus_contact_damage_index == kSamusContactDamageIndex_1_SpeedBoost) {
    return CollReact_QuicksandSurface_SpeedBoosting();
  }
  flag_samus_in_quicksand++;
  return 0;
}

/**
* @brief Resets the collision distance
* @return uint8 1, indicating there was a collision
*/
uint16 CollReact_QuicksandSurface_SpeedBoosting(void) {  // 0x84B537
  *cur_coll_amt32 = 0;
  return 1;
}

/**
* @brief Kills Samus' Y speed
* @param plm_idx The index of the PLM
* @return 0, indicating there was no collision
*/
uint8 PlmSetup_B737_SubmergingQuicksand(uint16 plm_idx) {  // 0x84B541
  samus_y_subspeed = 0;
  samus_y_speed = 0;
  samus_y_subaccel = 0;
  samus_y_accel = 0;
  return 0;
}

/**
* @brief Does nothing
* @param plm_idx The index of the PLM
* @return 0
*/
uint8 PlmSetup_B73B_B73F_SandFalls(uint16 plm_idx) {  // 0x84B54F
  return 0;
}

/**
* @brief Creates 10 air blocks below the PLM block
* @param plm_idx The index of the PLM
* @return 0
*/
uint8 PlmSetup_B763_ClearShitroidInvisibleWall(uint16 plm_idx) {  // 0x84B551
  uint16 plm_blk_idx = plm_block_indices[plm_idx >> 1];
  //int16 blk = 10;
  //do {
  //  level_data[plm_blk_idx >> 1] &= 0xFFF;
  //  plm_blk_idx += room_width_in_blocks * 2;
  //  --blk;
  //} while (blk);
  for (int blk = 0; blk < 10; blk++) {
	level_data[plm_blk_idx >> 1] = SET_BLK_TYPE(level_data[plm_blk_idx >> 1], kBlockType_0_Air);
    plm_blk_idx += room_width_in_blocks * 2;
  }
  return 0;
}

/**
* @brief Creates 10 solid blocks below the PLM block
* @param plm_idx The index of the PLM
* @return 0
*/
uint8 PlmSetup_B767_CreateShitroidInvisibleWall(uint16 plm_idx) {  // 0x84B56F
  uint16 plm_blk_idx = plm_block_indices[plm_idx >> 1];
  //int16 blk = 10;
  //do {
  //  level_data[plm_blk_idx >> 1] = level_data[plm_blk_idx >> 1] & 0xFFF | 0x8000;
  //  plm_blk_idx += room_width_in_blocks * 2;
  //  --blk;
  //} while (blk);
  for (int blk = 0; blk < 10; blk++) {
    level_data[plm_blk_idx >> 1] = SET_BLK_TYPE(level_data[plm_blk_idx >> 1], kBlockType_8_SolidBlock);
	plm_blk_idx += room_width_in_blocks * 2;
  }
  return 0;
}

/**
* @brief Activates the save station if Samus is on the left edge of the station
* @param plm_idx The index of the PLM
* @return 1, indicating there was a collision
*/
uint8 PlmSetup_B76B_SaveStationTrigger(uint16 plm_idx) {  // 0x84B590
  if (power_bomb_explosion_status == kPowerBombExplosionStatus_Inactive
      && (samus_pose == kPose_01_FaceR_Normal || samus_pose == kPose_02_FaceL_Normal)
      && !save_station_lockout_flag
      && (samus_collision_direction & kSamusCollDir_DirMask) == kSamusCollDir_3_Down) {
    CalculatePlmBlockCoords(plm_idx);
    // if Samus is 16 +- 8 distance units to the right of the PLM block
    // Note: For the collision to happen, samus_x_pos must be within 16 distance units to the right of the PLM block
    // so the check is plm_x_pos + 8 <= samus_x_pos < plm_x_pos + 16, meaning you must be on the left edge of the station
    if ((uint16)(samus_x_pos - 8) >> 4 == plm_x_block) {
      int idx = plm_idx >> 1;
      uint16 plm_blk_idx = plm_block_indices[idx];
      plm_block_indices[idx] = 0;
      plm_header_ptr[idx] = 0;
      int16 blk_idx = MAX_PLMS-2;
      while (plm_blk_idx != plm_block_indices[blk_idx >> 1]) {
        blk_idx -= 2;
        if (blk_idx < 0)
          return 1;
      }
      idx = blk_idx >> 1;
      plm_instr_list_ptrs[idx] += 2;
      plm_instruction_timer[idx] = 1;
    }
  }
  return 1;
}

/**
* @brief Sets the PLM block to a save station trigger
* @param plm_idx The index of the PLM
* @return 0
*/
uint8 PlmSetup_B76F_SaveStation(uint16 plm_idx) {  // 0x84B5EE
  uint16 plm_blk_data = PLM_TYPE_BTS(kBlockType_B_SpecialBlock, kBtsType_Special_4D_SaveStationTrigger);
  WriteLevelDataBlockTypeAndBts(plm_block_indices[plm_idx >> 1], plm_blk_data);
  return 0;
}

/**
* @brief Creates a door block and 3 copies of the door block below it
* to create the escape door after Mother Brain is defeated
* @param plm_idx The index of the PLM
* @return 0
*/
uint8 PlmSetup_MotherBrainRoomEscapeDoor(uint16 plm_idx) {  // 0x84B5F8
  uint16 plm_blk_idx = plm_block_indices[plm_idx >> 1];
  uint16 plm_blk_data = PLM_TYPE_BTS(kBlockType_9_DoorBlock, 1);
  WriteLevelDataBlockTypeAndBts(plm_blk_idx, plm_blk_data);

  plm_blk_idx += room_width_in_blocks * 2;
  plm_blk_data = PLM_TYPE_BTS(kBlockType_D_VertExtension, (uint8)-1);
  WriteLevelDataBlockTypeAndBts(plm_blk_idx, plm_blk_data);

  plm_blk_idx += room_width_in_blocks * 2;
  plm_blk_data = PLM_TYPE_BTS(kBlockType_D_VertExtension, (uint8)-1);
  WriteLevelDataBlockTypeAndBts(plm_blk_idx, plm_blk_data);

  plm_blk_idx += room_width_in_blocks * 2;
  WriteLevelDataBlockTypeAndBts(plm_blk_idx, plm_blk_data);
  return 0;
}

/**
* @brief Sets a delay of 32 or 240 frames before enabling sounds and deleting the PLM
* @param plm_idx The index of the PLM
* @return 0
*/
uint8 PlmSetup_B7EB_EnableSoundsIn32Frames(uint16 plm_idx) {  // 0x84B7C3
  uint16 plm_timer;
  if (area_index == kArea_6_Ceres)
    plm_timer = 32;
  else
    plm_timer = 240;
  int idx = plm_idx >> 1;
  plm_timers[idx] = plm_timer;
  plm_pre_instrs[idx] = FUNC16(PlmPreInstr_B7EB_DecTimerEnableSoundsDeletePlm);
  return 0;
}

/**
* @brief Enables sounds and deletes the PLM when the timer reaches zero
* @param plm_idx The index of the PLM
*/
void PlmPreInstr_B7EB_DecTimerEnableSoundsDeletePlm(uint16 plm_idx) {  // 0x84B7DD
  int idx = plm_idx >> 1;
  if (--plm_timers[idx] == 0) {
    disable_sounds = 0;
    plm_header_ptr[idx] = 0;
  }
}

/**
* @brief Starts raising the lava if the speed booster has been collected
* @param plm_idx The index of the PLM
*/
void PlmPreInstr_WakeAndLavaIfBoosterCollected(uint16 plm_idx) {  // 0x84B7EF
  int idx = plm_idx >> 1;
  if (collected_items & kItem_SpeedBooster) {
    if ((int16)fx_target_y_pos < 0) {
      plm_header_ptr[idx] = 0;
    }
    else {
      fx_y_vel = -128;
      plm_instruction_timer[idx] = 1;
      plm_instr_list_ptrs[idx] += 2;
      plm_timers[idx] = 0;
    }
  }
  else {
    fx_target_y_pos = -1;
    fx_y_vel = 0;
    fx_timer = 0;
    earthquake_timer = 0;
    plm_header_ptr[idx] = 0;
  }
}

/**
* @brief Starts the FX motion if Samus is far left
* @param plm_idx The index of the PLM
*/
void PlmPreInstr_WakePLMAndStartFxMotionSamusFarLeft(uint16 plm_idx) {  // 0x84B82A
  if (samus_x_pos <= 0xAE0) {
    fx_timer = 1;
    int idx = plm_idx >> 1;
    plm_instruction_timer[idx] = 1;
    plm_instr_list_ptrs[idx] += 2;
    plm_timers[idx] = 0;
  }
}

/**
* @brief Raises the lava in stages and sets the speed booster event when the top is reached
* @param plm_idx The index of the PLM
*/
void PlmPreInstr_AdvanceLavaSamusMovesLeft(uint16 plm_idx) {  // 0x84B846
  static const LavaStage kLavaquakeFx_YPositionAndVelocity[4] = {
    [0] = { .target_samus_x_pos = 0x72b, .max_fx_y_pos = 0x1bf, .fx_y_vel_ = -0xb0, },
    [1] = { .target_samus_x_pos = 0x50a, .max_fx_y_pos = 0x167, .fx_y_vel_ = -0xe0, },
    [2] = { .target_samus_x_pos = 0x244, .max_fx_y_pos = 0x100, .fx_y_vel_ = -0xe0, },
    [3] = { .target_samus_x_pos = 0x8000 },
  };

  int idx = plm_idx >> 1;
  uint16 stage = plm_timers[idx] / sizeof(LavaStage);
  const LavaStage lava_stage = kLavaquakeFx_YPositionAndVelocity[stage];
  if (lava_stage.target_samus_x_pos & 0x8000) {
    SetEventHappened(kEvent_21_OutranSpeedBoosterLavaquake);
  }
  else if (lava_stage.target_samus_x_pos >= samus_x_pos) {
    fx_base_y_pos = IntMin(lava_stage.max_fx_y_pos, fx_base_y_pos);
    fx_y_vel = lava_stage.fx_y_vel_;
    plm_timers[idx] += sizeof(LavaStage);
  }
}

/**
* @brief Deactivates the PLM if the speed booster lavaquake event has happened
* @param plm_idx The index of the PLM
* @return 0
*/
uint8 PlmSetup_SpeedBoosterEscape(uint16 plm_idx) {  // 0x84B89C
  if (CheckEventHappened(kEvent_21_OutranSpeedBoosterLavaquake))
    plm_header_ptr[plm_idx >> 1] = 0;
  return 0;
}

/**
* @brief Sets the scrolls to blue if a power bomb explosion is active
* and deactivates the PLM and sets the shaktool path cleared event if Samus is far right
* @param plm_idx The index of the PLM
*/
void PlmPreInstr_ShaktoolsRoom(uint16 plm_idx) {  // 0x84B8B0
  if (power_bomb_explosion_status != kPowerBombExplosionStatus_Inactive) {
    scrolls[3] = scrolls[2] = scrolls[1] = scrolls[0] = kScroll_Blue;
  }
  if (samus_x_pos > 0x348) {
    SetEventHappened(kEvent_13_ShaktoolPathCleared);
    plm_header_ptr[plm_idx >> 1] = 0;
  }
}

/**
* @brief Sets the scrolls to not go past the first screen
* @param plm_idx The index of the PLM
* @return 0
*/
uint8 PlmSetup_ShaktoolsRoom(uint16 plm_idx) {  // 0x84B8DC
  scrolls[0] = kScroll_Blue;
  scrolls[3] = scrolls[2] = scrolls[1] = kScroll_Red;
  return 0;
}

/**
* @brief Activates PLM if Samus is to the bottom right of the target
* @param plm_idx The index of the PLM
* @param target_x_pos The target x position
* @param target_y_pos The target y position
* @return true if Samus is not below and right of the target, false otherwise
*/
uint8 WakePlmIfSamusIsBelowAndRightOfTarget(uint16 plm_idx, uint16 target_x_pos, uint16 target_y_pos) {  // 0x84B8FD
  if (target_x_pos < samus_x_pos && target_y_pos < samus_y_pos) {
    int idx = plm_idx >> 1;
    plm_instr_list_ptrs[idx] += 2;
    plm_instruction_timer[idx] = 1;
    return false;
  }
  return true;
}

/**
* @brief Spawns the Old Tourian escape shaft fake wall explosion if Samus is below and right of the target
* @param plm_idx The index of the PLM
*/
void PlmPreInstr_OldTourianEscapeShaftEscape(uint16 plm_idx) {  // 0x84B927
  if (!WakePlmIfSamusIsBelowAndRightOfTarget(plm_idx, 15*16, 130*16))
    SpawnEprojWithRoomGfx(addr_kEproj_OldTourianEscapeShaftFakeWallExplosion, 0);
}

/**
* @brief Raises the acid in the room before the Old Tourian escape shaft if Samus is below and right of the target
* @param plm_idx The index of the PLM
*/
void PlmPreInstr_EscapeRoomBeforeOldTourianEscapeShaft(uint16 plm_idx) {  // 0x84B948
  if (!WakePlmIfSamusIsBelowAndRightOfTarget(plm_idx, 15*16, 84*16)) {
    fx_y_vel = -104;
    fx_timer = 16;
  }
}

/**
* @brief In the original code, this would set the reaction to stop checking blocks
* and only report partial contact collisions
* @param plm_idx The index of the PLM
* @return 0
*/
uint8 PlmSetup_B974(uint16 plm_idx) {  // 0x84B96C
  // Implemented in BlockReact_ShootableAir in sm_94.c
  return 0;
}

/**
* @brief Changes the PLM respawn block to super missile graphics and deactivates the PLM
* @param plm_idx The index of the PLM
* @return 0
*/
uint8 PlmSetup_B9C1_CrittersEscapeBlock(uint16 plm_idx) {  // 0x84B978
  int idx = plm_idx >> 1;
  // probably always true
  if (projectile_type[projectile_index >> 1] != 0) {
    int plm_blk_idx = plm_block_indices[idx] >> 1;
    uint16 plm_respawn_blk = level_data[plm_blk_idx] & 0xF000 | 0x9F;
    plm_variable[idx] = plm_respawn_blk;
    level_data[plm_blk_idx] = DEACTIVATE_BLK(plm_respawn_blk);
  }
  else {
    plm_header_ptr[idx] = 0;
  }
  return 0;
}

/**
* @brief Sets the critters escaped event
* @param plmp The pointer to the PLM instruction
* @param plm_idx The index of the PLM
* @return uint8* The pointer to the next PLM instruction
*/
const uint8 *PlmInstr_SetCrittersEscapedEvent(const uint8 *plmp, uint16 plm_idx) {  // 0x84B9B9
  SetEventHappened(kEvent_15_CrittersEscaped);
  return plmp;
}

/**
* @brief Creates a critters escape block and two vertical extensions below it
* @param plm_idx The index of the PLM
* @return 0
*/
uint8 PlmSetup_B9ED_CrittersEscapeBlock(uint16 plm_idx) {  // 0x84B9C5
  uint16 plm_blk_idx = plm_block_indices[plm_idx >> 1];
  uint16 plm_blk_data = PLM_TYPE_BTS(kBlockType_C_ShootableBlock, kBtsType_Shootable_4F_CrittersEscapeBlock);
  WriteLevelDataBlockTypeAndBts(plm_blk_idx, plm_blk_data);

  plm_blk_idx += room_width_in_blocks * 2;
  plm_blk_data = PLM_TYPE_BTS(kBlockType_D_VertExtension, (uint8)-1);
  WriteLevelDataBlockTypeAndBts(plm_blk_idx, plm_blk_data);

  plm_blk_idx += room_width_in_blocks * 2;
  WriteLevelDataBlockTypeAndBts(plm_blk_idx, plm_blk_data);
  return 0;
}

/**
* @brief Turns the Ceres door blocks solid
* @param plm_idx The index of the PLM
* @return 0
*/
uint8 PlmSetup_B9F1_TurnCeresDoorSolid(uint16 plm_idx) {  // 0x84B9F1
  uint16 plm_blk_idx = plm_block_indices[plm_idx >> 1];
  level_data[plm_blk_idx >> 1] = SET_BLK_TYPE(level_data[plm_blk_idx >> 1], kBlockType_8_SolidBlock);

  plm_blk_idx += room_width_in_blocks * 2;
  level_data[plm_blk_idx >> 1] = SET_BLK_TYPE(level_data[plm_blk_idx >> 1], kBlockType_8_SolidBlock);

  plm_blk_idx += room_width_in_blocks * 2;
  level_data[plm_blk_idx >> 1] = SET_BLK_TYPE(level_data[plm_blk_idx >> 1], kBlockType_8_SolidBlock);

  plm_blk_idx += room_width_in_blocks * 2;
  level_data[plm_blk_idx >> 1] = SET_BLK_TYPE(level_data[plm_blk_idx >> 1], kBlockType_8_SolidBlock);
  return 0;
}

/**
* @brief Goes to the instruction specified if Samus does not have bombs
* @param plmp The pointer to the PLM instruction
* @param plm_idx The index of the PLM
* @return uint8* The pointer to the specified PLM instruction if Samus does not have bombs, the next instruction otherwise
*/
const uint8 *PlmInstr_JumpIfSamusHasNoBombs(const uint8 *plmp, uint16 plm_idx) {  // 0x84BA6F
  if (!(collected_items & kItem_Bombs))
    return INSTRB_RETURN_ADDR(GET_WORD(plmp));
  return plmp + 2;
}

/**
* @brief Deactivates the PLM to clear the escape block if the critters have not escaped
* @param plm_idx The index of the PLM
* @return 0
*/
uint8 PlmSetup_BB30_CrateriaMainstreetEscape(uint16 plm_idx) {  // 0x84BB09
  if (!CheckEventHappened(kEvent_15_CrittersEscaped))
    plm_header_ptr[plm_idx >> 1] = 0;
  return 0;
}

/**
* @brief Moves the PLM right 4 blocks
* @param plmp The pointer to the PLM instruction
* @param plm_idx The index of the PLM
* @return uint8* The pointer to the next PLM instruction
*/
const uint8 *PlmInstr_MovePlmRight4Blocks(const uint8 *plmp, uint16 plm_idx) {  // 0x84BB25
  plm_block_indices[plm_idx >> 1] += 4*2;
  return plmp;
}

/**
* @brief Activates the PLM if it is triggered
* @param plm_idx The index of the PLM
*/
void PlmPreInstr_WakePlmIfTriggered(uint16 plm_idx) {  // 0x84BB52
  int idx = plm_idx >> 1;
  if (plm_timers[idx] != 0) {
    plm_instr_list_ptrs[idx] += 2;
    plm_instruction_timer[idx] = 1;
    plm_pre_instrs[idx] = addr_locret_84BB6A;
  }
}

/**
* @brief Activates the PLM if Samus is within 4 blocks below the PLM or the PLM is triggered
* @param plm_idx The index of the PLM
*/
void PlmPreInstr_WakePlmIfTriggeredOrSamusBelowPlm(uint16 plm_idx) {  // 0x84BB6B
  CalculatePlmBlockCoords(plm_idx);
  uint16 samus_x_blk = samus_x_pos / 16;
  uint16 samus_y_blk = samus_y_pos / 16;
  if (samus_x_blk == plm_x_block && (uint16)(samus_y_blk - plm_y_block) < 5
      || plm_timers[plm_idx >> 1] != 0) {
    int idx = plm_idx >> 1;
    plm_instr_list_ptrs[idx] += 2;
    plm_instruction_timer[idx] = 1;
    plm_pre_instrs[idx] = FUNC16(PlmPreInstr_Empty5);
  }
}

/**
* @brief Activates the PLM if Samus is within 4 blocks above the PLM or the PLM is triggered
* @brief This is used by an unused PLM, so the function is not used
* @param plm_idx The index of the PLM
*/
void PlmPreInstr_WakePlmIfTriggeredOrSamusAbovePlm(uint16 plm_idx) {  // 0x84BBA4
  CalculatePlmBlockCoords(plm_idx);
  uint16 samus_x_blk = samus_x_pos / 16;
  uint16 samus_y_blk = samus_y_pos / 16;
  if (samus_x_blk == plm_x_block && (uint16)(samus_y_blk - plm_y_block) >= (uint16)-4
      || plm_timers[plm_idx >> 1] != 0) {
    int idx = plm_idx >> 1;
    plm_instr_list_ptrs[idx] += 2;
    ++plm_instr_list_ptrs[idx];
    plm_instruction_timer[idx] = 1;
    plm_pre_instrs[idx] = addr_locret_84BBDC;
  }
}

/**
* @brief Clears collision trigger
* @param plmp The pointer to the PLM instruction
* @param plm_idx The index of the PLM
* @return uint8* The pointer to the next PLM instruction
*/
const uint8 *PlmInstr_ClearTrigger(const uint8 *plmp, uint16 plm_idx) {  // 0x84BBDD
  plm_timers[plm_idx >> 1] = 0;
  return plmp;
}

/**
* @brief Spawns the enemy projectile specified by the instruction
* @param plmp The pointer to the PLM instruction
* @param plm_idx The index of the PLM
* @return uint8* The pointer to the next PLM instruction
*/
const uint8 *PlmInstr_SpawnEproj(const uint8 *plmp, uint16 plm_idx) {  // 0x84BBE1
  SpawnEprojWithRoomGfx(GET_WORD(plmp), 0);
  return plmp + 2;
}

/**
* @brief Activates the enemy projectile at the PLM block position
* @param plmp The pointer to the PLM instruction
* @param plm_idx The index of the PLM
* @return uint8* The pointer to the next PLM instruction
*/
const uint8 *PlmInstr_WakeEprojAtPlmPos(const uint8 *plmp, uint16 plm_idx) {  // 0x84BBF0
  int eproj_idx;

  uint16 plm_blk_idx = plm_block_indices[plm_idx >> 1];
  for (eproj_idx = 34; eproj_idx >= 0; eproj_idx -= 2) {
    if (plm_blk_idx == eproj_E[eproj_idx >> 1])
      break;
  }
  int idx = eproj_idx >> 1;
  eproj_instr_timers[idx] = 1;
  eproj_instr_list_ptr[idx] += 2;
  return plmp + 2;
}

/**
* @brief Goes to the instruction stored in the link register if the PLM is shot
* @param plm_idx The index of the PLM
*/
void PlmPreInstr_GoToLinkInstrIfShot(uint16 plm_idx) {  // 0x84BD0F
  int idx = plm_idx >> 1;
  // plm_timers is plm shot status
  if (plm_timers[idx] != 0) {
    plm_timers[idx] = 0;
    plm_instr_list_ptrs[idx] = plm_instruction_list_link_reg[idx];
    plm_instruction_timer[idx] = 1;
  }
}

/**
* @brief Goes to the instruction stored in the link register if the PLM is hit with a power bomb
* @brief Plays the dud sound if the PLM is hit with any other shot
* @param plm_idx The index of the PLM
*/
void PlmPreInstr_GoToLinkInstrIfShotWithPowerBomb(uint16 plm_idx) {  // 0x84BD26
  int idx = plm_idx >> 1;
  uint16 shot_status = plm_timers[idx];
  if (shot_status != 0) {
    if ((shot_status & kProjectileType_ProjMask) == kProjectileType_PowerBomb) {
      plm_timers[idx] = 0;
      plm_instr_list_ptrs[idx] = plm_instruction_list_link_reg[idx];
      plm_instruction_timer[idx] = 1;
      return;
    }
    QueueSfx2_Max6(kSfx2_ShotDoorGateWithDudShot_ShotReflec_ShotMaridiaLargeIndestructibleSnail);
  }
  plm_timers[idx] = 0;
}

/**
* @brief Goes to the instruction stored in the link register if the PLM is hit with any missile
* @brief Plays the dud sound if the PLM is hit with any other shot
* @param plm_idx The index of the PLM
*/
void PlmPreInstr_GoToLinkInstrIfShotWithAnyMissile(uint16 plm_idx) {  // 0x84BD50
  int idx = plm_idx >> 1;
  uint16 shot_status = plm_timers[idx];
  if (shot_status != 0) {
    if ((shot_status & kProjectileType_ProjMask) == kProjectileType_SuperMissile) {
      plm_variables[idx] = 119;  // door hit counter
      plm_timers[idx] = 0;
      plm_instr_list_ptrs[idx] = plm_instruction_list_link_reg[idx];
      plm_instruction_timer[idx] = 1;
      return;
    }
    if ((shot_status & kProjectileType_ProjMask) == kProjectileType_Missile) {
      plm_timers[idx] = 0;
      plm_instr_list_ptrs[idx] = plm_instruction_list_link_reg[idx];
      plm_instruction_timer[idx] = 1;
      return;
    }
    QueueSfx2_Max6(kSfx2_ShotDoorGateWithDudShot_ShotReflec_ShotMaridiaLargeIndestructibleSnail);
  }
  plm_timers[idx] = 0;
}

/**
* @brief Goes to the instruction stored in the link register if the PLM is hit with a super missile
* @brief Plays the dud sound if the PLM is hit with any other shot
* @param plm_idx The index of the PLM
*/
void PlmPreInstr_GoToLinkInstrIfShotWithSuperMissile(uint16 plm_idx) {  // 0x84BD88
  int idx = plm_idx >> 1;
  uint16 shot_status = plm_timers[idx];
  if (shot_status != 0) {
    if ((shot_status & kProjectileType_ProjMask) == kProjectileType_SuperMissile) {
      plm_timers[idx] = 0;
      plm_instr_list_ptrs[idx] = plm_instruction_list_link_reg[idx];
      plm_instruction_timer[idx] = 1;
      return;
    }
    QueueSfx2_Max6(kSfx2_ShotDoorGateWithDudShot_ShotReflec_ShotMaridiaLargeIndestructibleSnail);
  }
  plm_timers[idx] = 0;
}

/**
* @brief Goes to the instruction stored in the link register and clears the PLM shot status
* @param plm_idx The index of the PLM
*/
void PlmPreInstr_GoToLinkInstruction(uint16 plm_idx) {  // 0x84BDB2
  int idx = plm_idx >> 1;
  plm_timers[idx] = 0;
  plm_instr_list_ptrs[idx] = plm_instruction_list_link_reg[idx];
  plm_instruction_timer[idx] = 1;
}

/**
* @brief Plays the dud sound if shot and clears the PLM shot status
* @param plm_idx The index of the PLM
*/
void PlmPreInstr_PlayDudSound(uint16 plm_idx) {  // 0x84BDC4
  int idx = plm_idx >> 1;
  if (plm_timers[idx] != 0)
    QueueSfx2_Max6(kSfx2_ShotDoorGateWithDudShot_ShotReflec_ShotMaridiaLargeIndestructibleSnail);
  plm_timers[idx] = 0;
}

/**
* @brief Goes to the instruction stored in the link register if the area boss is dead
* @brief Otherwise, plays the dud sound
* @param plm_idx The index of the PLM
*/
void PlmPreInstr_GotoLinkIfAreaBossDead(uint16 plm_idx) {  // 0x84BDD4
  if (CheckBossBitForCurArea(kBossBit_AreaBoss) & 1)
    PlmPreInstr_GoToLinkInstruction(plm_idx);
  else
    PlmPreInstr_PlayDudSound(plm_idx);
}

/**
* @brief Goes to the instruction stored in the link register if the area mini boss is dead
* @brief Otherwise, plays the dud sound
* @param plm_idx The index of the PLM
*/
void PlmPreInstr_GotoLinkIfMiniBossDead(uint16 plm_idx) {  // 0x84BDE3
  if (CheckBossBitForCurArea(kBossBit_AreaMiniBoss) & 1)
    PlmPreInstr_GoToLinkInstruction(plm_idx);
  else
    PlmPreInstr_PlayDudSound(plm_idx);
}

/**
* @brief Goes to the instruction stored in the link register if the area Torizo is dead
* @brief Otherwise, plays the dud sound
* @param plm_idx The index of the PLM
*/
void PlmPreInstr_GotoLinkIfTorizoDead(uint16 plm_idx) {  // 0x84BDF2
  if (CheckBossBitForCurArea(kBossBit_AreaTorizo) & 1)
    PlmPreInstr_GoToLinkInstruction(plm_idx);
  else
    PlmPreInstr_PlayDudSound(plm_idx);
}

/**
* @brief Goes to the instruction stored in the link register and sets the Zebes Awake event if the enemy death quota is met
* @brief Otherwise, plays the dud sound
* @param plm_idx The index of the PLM
*/
void PlmPreInstr_GotoLinkIfEnemyDeathQuotaOk(uint16 plm_idx) {  // 0x84BE01
  if (num_enemies_killed_in_room < num_enemy_deaths_left_to_clear) {
    PlmPreInstr_PlayDudSound(plm_idx);
  }
  else {
    SetEventHappened(kEvent_0_ZebesAwake);
    PlmPreInstr_GoToLinkInstruction(plm_idx);
  }
}

/**
* @brief Goes to the instruction stored in the link register if the Tourian statue is finished processing
* @brief Otherwise, plays the dud sound
* @param plm_idx The index of the PLM
*/
void PlmPreInstr_GotoLinkIfTourianStatueFinishedProcessing(uint16 plm_idx) {  // 0x84BE1F
  if (tourian_entrance_statue_finished & 0x8000)
    PlmPreInstr_GoToLinkInstruction(plm_idx);
  else
    PlmPreInstr_PlayDudSound(plm_idx);
}

/**
* @brief Goes to the instruction stored in the link register if the critters have escaped
* @brief Otherwise, plays the dud sound
* @param plm_idx The index of the PLM
*/
void PlmPreInstr_GotoLinkIfCrittersEscaped(uint16 plm_idx) {  // 0x84BE30
  if (CheckEventHappened(kEvent_15_CrittersEscaped))
    PlmPreInstr_GoToLinkInstruction(plm_idx);
  else
    PlmPreInstr_PlayDudSound(plm_idx);
}

static const uint16 kGrayDoorPreInstrs[] = {
  FUNC16(PlmPreInstr_GotoLinkIfAreaBossDead),
  FUNC16(PlmPreInstr_GotoLinkIfMiniBossDead),
  FUNC16(PlmPreInstr_GotoLinkIfTorizoDead),
  FUNC16(PlmPreInstr_GotoLinkIfEnemyDeathQuotaOk),
  FUNC16(PlmPreInstr_PlayDudSound),
  FUNC16(PlmPreInstr_GotoLinkIfTourianStatueFinishedProcessing),
  FUNC16(PlmPreInstr_GotoLinkIfCrittersEscaped),
};

/**
* @brief Sets the pre-instruction to the appropriate function for the gray door type
* @param plmp The pointer to the PLM instruction
* @param plm_idx The index of the PLM
* @return uint8* The pointer to the next PLM instruction
*/
const uint8 *PlmInstr_SetGreyDoorPreInstr(const uint8 *plmp, uint16 plm_idx) {  // 0x84BE3F
  uint16 gray_door_type = plm_variable[plm_idx >> 1];
  plm_pre_instrs[plm_idx >> 1] = kGrayDoorPreInstrs[gray_door_type >> 1];
  FUNC16(PlmPreInstr_GotoLinkIfCrittersEscaped);
  return plmp;
}

/**
* @brief Activates the green gate to the right of the trigger if hit with a super missile
* @brief Otherwise, plays the dud sound
* @param plm_idx The index of the PLM
* @return 0
*/
uint8 PlmSetup_C806_LeftGreenGateTrigger(uint16 plm_idx) {  // 0x84C54D
  uint16 proj_idx = projectile_index >> 1;
  uint16 proj_type = projectile_type[proj_idx] & (kProjectileType_ProjMask|0xFF);
  if (proj_type == kProjectileType_SuperMissile)
    return TriggerPlmOfBlockToTheRight(plm_idx);
  QueueSfx2_Max6(kSfx2_ShotDoorGateWithDudShot_ShotReflec_ShotMaridiaLargeIndestructibleSnail);
  plm_header_ptr[plm_idx >> 1] = 0;
  return 0;
}

/**
* @brief Activates the green gate to the left of the trigger if hit with a super missile
* @brief Otherwise, plays the dud sound
* @param plm_idx The index of the PLM
* @return 0
*/
uint8 PlmSetup_C80A_RightGreenGateTrigger(uint16 plm_idx) {  // 0x84C56C
  uint16 proj_idx = projectile_index >> 1;
  uint16 proj_type = projectile_type[proj_idx] & (kProjectileType_ProjMask|0xFF);
  if (proj_type == kProjectileType_SuperMissile)
    return TriggerPlmOfBlockToTheLeft(plm_idx);
  QueueSfx2_Max6(kSfx2_ShotDoorGateWithDudShot_ShotReflec_ShotMaridiaLargeIndestructibleSnail);
  plm_header_ptr[plm_idx >> 1] = 0;
  return 0;
}

/**
* @brief Activates the red gate to the right of the trigger if hit with any missile
* @brief Otherwise, plays the dud sound
* @param plm_idx The index of the PLM
* @return 0
*/
uint8 PlmSetup_C80E_LeftRedGateTrigger(uint16 plm_idx) {  // 0x84C58B
  uint16 proj_idx = projectile_index >> 1;
  uint16 proj_type = projectile_type[proj_idx] & (kProjectileType_ProjMask|0xFF);
  if (proj_type == kProjectileType_Missile || proj_type == kProjectileType_SuperMissile)
    return TriggerPlmOfBlockToTheRight(plm_idx);
  QueueSfx2_Max6(kSfx2_ShotDoorGateWithDudShot_ShotReflec_ShotMaridiaLargeIndestructibleSnail);
  plm_header_ptr[plm_idx >> 1] = 0;
  return 0;
}

/**
* @brief Activates the red gate to the left of the trigger if hit with any missile
* @brief Otherwise, plays the dud sound
* @param plm_idx The index of the PLM
* @return 0
*/
uint8 PlmSetup_C812_RightRedGateTrigger(uint16 plm_idx) {  // 0x84C5AF
  uint16 proj_idx = projectile_index >> 1;
  uint16 proj_type = projectile_type[proj_idx] & (kProjectileType_ProjMask|0xFF);
  if (proj_type == kProjectileType_Missile || proj_type == kProjectileType_SuperMissile)
    return TriggerPlmOfBlockToTheLeft(plm_idx);
  QueueSfx2_Max6(kSfx2_ShotDoorGateWithDudShot_ShotReflec_ShotMaridiaLargeIndestructibleSnail);
  plm_header_ptr[plm_idx >> 1] = 0;
  return 0;
}

/**
* @brief Activates the yellow gate to the left of the trigger if hit with a power bomb
* @brief Otherwise, plays the dud sound
* @brief This is used by an unused PLM, so the function is not used
* @param plm_idx The index of the PLM
* @return 0
*/
uint8 PlmSetup_C822_RightYellowGateTrigger(uint16 plm_idx) {  // 0x84C5F1
  uint16 proj_idx = projectile_index >> 1;
  uint16 proj_type = projectile_type[proj_idx] & (kProjectileType_ProjMask|0xFF);
  if (proj_type == kProjectileType_PowerBomb)
    return TriggerPlmOfBlockToTheLeft(plm_idx);
  QueueSfx2_Max6(kSfx2_ShotDoorGateWithDudShot_ShotReflec_ShotMaridiaLargeIndestructibleSnail);
  plm_header_ptr[plm_idx >> 1] = 0;
  return 0;
}

/**
* @brief Activates the yellow gate to the right of the trigger if hit with a power bomb
* @brief Otherwise, plays the dud sound
* @brief This is used by an unused PLM, so the function is not used
* @param plm_idx The index of the PLM
* @return 0
*/
uint8 PlmSetup_C81E_LeftYellowGateTrigger(uint16 plm_idx) {  // 0x84C5D3
  uint16 proj_idx = projectile_index >> 1;
  uint16 proj_type = projectile_type[proj_idx] & (kProjectileType_ProjMask|0xFF);
  if (proj_type == kProjectileType_PowerBomb)
    return TriggerPlmOfBlockToTheRight(plm_idx);
  QueueSfx2_Max6(kSfx2_ShotDoorGateWithDudShot_ShotReflec_ShotMaridiaLargeIndestructibleSnail);
  plm_header_ptr[plm_idx >> 1] = 0;
  return PlmSetup_C822_RightYellowGateTrigger(plm_idx);
}

/**
* @brief Activates the blue gate to the left of the trigger if hit with anything other than a power bomb
* @brief Otherwise, plays the dud sound
* @param plm_idx The index of the PLM
* @return 0
*/
uint8 PlmSetup_C81A_RightBlueGateTrigger(uint16 plm_idx) {  // 0x84C627
  uint16 proj_idx = projectile_index >> 1;
  uint16 proj_type = projectile_type[proj_idx] & (kProjectileType_ProjMask|0xFF);
  if (proj_type != kProjectileType_PowerBomb)
    return TriggerPlmOfBlockToTheLeft(plm_idx);
  plm_header_ptr[plm_idx >> 1] = 0;
  return 0;
}

/**
* @brief Activates the blue gate to the right of the trigger if hit with anything other than a power bomb
* @brief Otherwise, plays the dud sound
* @param plm_idx The index of the PLM
* @return 0
*/
uint8 PlmSetup_C816_LeftBlueGateTrigger(uint16 plm_idx) {  // 0x84C610
  uint16 proj_idx = projectile_index >> 1;
  uint16 proj_type = projectile_type[proj_idx] & (kProjectileType_ProjMask|0xFF);
  if (proj_type != kProjectileType_PowerBomb)
    return TriggerPlmOfBlockToTheRight(plm_idx);
  plm_header_ptr[plm_idx >> 1] = 0;
  return PlmSetup_C81A_RightBlueGateTrigger(plm_idx);
}

/**
* @brief Activates the PLM at the block to the right of the PLM
* @param plm_idx The index of the PLM
* @return 1
*/
uint8 TriggerPlmOfBlockToTheRight(uint16 plm_idx) {  // 0x84C63F
  return TriggerPlmAtBlockIndex(plm_idx, plm_block_indices[plm_idx >> 1] + 2);
}

/**
* @brief Activates the PLM at the block to the left of the PLM
* @param plm_idx The index of the PLM
* @return 1
*/
uint8 TriggerPlmOfBlockToTheLeft(uint16 plm_idx) {  // 0x84C647
  return TriggerPlmAtBlockIndex(plm_idx, plm_block_indices[plm_idx >> 1] - 2);
}

/**
* @brief Activates the PLM at the specified block index
* @param plm_idx The index of the PLM
* @param plm_blk_idx The block index of the PLM
* @return 1
*/
uint8 TriggerPlmAtBlockIndex(uint16 plm_idx, uint16 plm_blk_idx) {  // 0x84C64C
  int16 blk_idx = MAX_PLMS-2;
  while (plm_blk_idx != plm_block_indices[blk_idx >> 1]) {
    blk_idx -= 2;
    if (blk_idx < 0)
      break;
  }
  if (plm_blk_idx == plm_block_indices[blk_idx >> 1]) {
    int idx;
    idx = blk_idx >> 1;
    if (plm_timers[idx] == 0)
      plm_timers[idx] = 1;
  }
  plm_header_ptr[plm_idx >> 1] = 0;
  return 1;
}

/**
* @brief Spawns 5 gate blocks downwards from the PLM block index
* @param plm_idx The index of the PLM
*/
void Spawn5BlocksOfGateBlocksDownwards(uint16 plm_idx) {  // 0x84C66A
  uint16 plm_blk_idx = plm_block_indices[plm_idx >> 1] >> 1;
  plm_blk_idx = SetBtsToGateBlockMoveDownRow(plm_blk_idx);
  plm_blk_idx = SetBtsToGateBlockMoveDownRow(plm_blk_idx);
  plm_blk_idx = SetBtsToGateBlockMoveDownRow(plm_blk_idx);
  plm_blk_idx = SetBtsToGateBlockMoveDownRow(plm_blk_idx);
  plm_blk_idx = SetBtsToGateBlockMoveDownRow(plm_blk_idx);
}

/**
* @brief Sets the BTS to gate block and moves the block index down a row
* @param plm_blk_idx The block index of the PLM
* @return uint16 The block index of the next row
*/
uint16 SetBtsToGateBlockMoveDownRow(uint16 plm_blk_idx) {  // 0x84C67F
  BTS[plm_blk_idx] = kBtsType_Shootable_10_GateBlocks;
  return plm_blk_idx + room_width_in_blocks;
}

/**
* @brief Spawns 5 gate blocks upwards from the PLM block index
* @param plm_idx The index of the PLM
*/
void Spawn5BlocksOfGateBlocksUpwards(uint16 plm_idx) {  // 0x84C694
  uint16 plm_blk_idx = plm_block_indices[plm_idx >> 1] >> 1;
  plm_blk_idx = SetBtsToGateBlockMoveUpRow(plm_blk_idx);
  plm_blk_idx = SetBtsToGateBlockMoveUpRow(plm_blk_idx);
  plm_blk_idx = SetBtsToGateBlockMoveUpRow(plm_blk_idx);
  plm_blk_idx = SetBtsToGateBlockMoveUpRow(plm_blk_idx);
  plm_blk_idx = SetBtsToGateBlockMoveUpRow(plm_blk_idx);
}

/**
* @brief Sets the BTS to gate block and moves the block index up a row
* @param plm_blk_idx The block index of the PLM
* @return uint16 The block index of the previous row
*/
uint16 SetBtsToGateBlockMoveUpRow(uint16 plm_blk_idx) {  // 0x84C6A9
  BTS[plm_blk_idx] = kBtsType_Shootable_10_GateBlocks;
  return plm_blk_idx - room_width_in_blocks;
}

/**
* @brief Spawns a closed downwards gate at the PLM block index
* @param plm_idx The index of the PLM
* @return 0
*/
uint8 PlmSetup_C82A_DownwardsClosedGate(uint16 plm_idx) {  // 0x84C6BE
  SpawnEprojWithRoomGfx(addr_kEproj_InitialClosedDownwardsShotGate, 0);
  Spawn5BlocksOfGateBlocksDownwards(plm_idx);
  return 0;
}

/**
* @brief Spawns a closed upwards gate at the PLM block index
* @param plm_idx The index of the PLM
* @return 0
*/
uint8 PlmSetup_C832_UpwardsClosedGate(uint16 plm_idx) {  // 0x84C6CB
  SpawnEprojWithRoomGfx(addr_kEproj_InitialClosedUpwardsShotGate, 0);
  Spawn5BlocksOfGateBlocksUpwards(plm_idx);
  return 0;
}

/**
* @brief Spawns 5 gate blocks downwards from the PLM block index
* @param plm_idx The index of the PLM
* @return 0
*/
uint8 PlmSetup_C826_DownwardsOpenGate(uint16 plm_idx) {  // 0x84C6D8
  Spawn5BlocksOfGateBlocksDownwards(plm_idx);
  return 0;
}

/**
* @brief Spawns 5 gate blocks upwards from the PLM block index
* @param plm_idx The index of the PLM
* @return 0
*/
uint8 PlmSetup_C82E_UpwardsOpenGate(uint16 plm_idx) {  // 0x84C6DC
  Spawn5BlocksOfGateBlocksUpwards(plm_idx);
  return 0;
}

uint16 kDownwardGatePlmListPtrs[] = {
  0xbcaf,
  0xbcb5,
  0xbcbb,
  0xbcc1,
  0xbcc7,
  0xbccd,
  0xbcd3,
  0xbcd9,
};
uint16 kDownwardGateLeftBlockBts[] = {
  PLM_TYPE_BTS(kBlockType_C_ShootableBlock, kBtsType_Shootable_46_LeftBlueGateTrigger),
  0x0,
  PLM_TYPE_BTS(kBlockType_C_ShootableBlock, kBtsType_Shootable_48_LeftRedGateTrigger),
  0x0,
  PLM_TYPE_BTS(kBlockType_C_ShootableBlock, kBtsType_Shootable_4A_LeftGreenGateTrigger),
  0x0,
  PLM_TYPE_BTS(kBlockType_C_ShootableBlock, kBtsType_Shootable_4C_LeftOrangeGateTrigger),
  0x0,
};
uint16 kDownwardGateRightBlockBts[] = {
  0x0,
  PLM_TYPE_BTS(kBlockType_C_ShootableBlock, kBtsType_Shootable_47_RightBlueGateTrigger),
  0x0,
  PLM_TYPE_BTS(kBlockType_C_ShootableBlock, kBtsType_Shootable_49_RightRedGateTrigger),
  0x0,
  PLM_TYPE_BTS(kBlockType_C_ShootableBlock, kBtsType_Shootable_4B_RightGreenGateTrigger),
  0x0,
  PLM_TYPE_BTS(kBlockType_C_ShootableBlock, kBtsType_Shootable_4D_RightOrangeGateTrigger),
};

/**
* @brief Sets the instruction list pointer and block types for the downwards gate
* @param plm_idx The index of the PLM
* @return 0
*/
uint8 PlmSetup_C836_DownwardsGateShootblock(uint16 plm_idx) {  // 0x84C6E0
  int idx = plm_idx >> 1;
  uint16 gate_type = plm_room_arguments[idx] >> 1;
  plm_instr_list_ptrs[idx] = kDownwardGatePlmListPtrs[gate_type];

  uint16 left_blk_bts = kDownwardGateLeftBlockBts[gate_type];
  if (left_blk_bts != 0)
    WriteLevelDataBlockTypeAndBts(plm_block_indices[idx] - 2, left_blk_bts);

  uint16 right_blk_bts = kDownwardGateRightBlockBts[gate_type];
  if (right_blk_bts != 0)
    WriteLevelDataBlockTypeAndBts(plm_block_indices[idx] + 2, right_blk_bts);
  return 0;
}

uint16 kUpwardGatePlmListPtrs[] = {
  0xbcdf,
  0xbce5,
  0xbceb,
  0xbcf1,
  0xbcf7,
  0xbcfd,
  0xbd03,
  0xbd09,
};
uint16 kUpwardGateLeftBlockBts[] = {
  PLM_TYPE_BTS(kBlockType_C_ShootableBlock, kBtsType_Shootable_46_LeftBlueGateTrigger),
  0x0,
  PLM_TYPE_BTS(kBlockType_C_ShootableBlock, kBtsType_Shootable_48_LeftRedGateTrigger),
  0x0,
  PLM_TYPE_BTS(kBlockType_C_ShootableBlock, kBtsType_Shootable_4A_LeftGreenGateTrigger),
  0x0,
  PLM_TYPE_BTS(kBlockType_C_ShootableBlock, kBtsType_Shootable_4C_LeftOrangeGateTrigger),
  0x0,
};
uint16 kUpwardGateRightBlockBts[] = {
  0x0,
  PLM_TYPE_BTS(kBlockType_C_ShootableBlock, kBtsType_Shootable_47_RightBlueGateTrigger),
  0x0,
  PLM_TYPE_BTS(kBlockType_C_ShootableBlock, kBtsType_Shootable_49_RightRedGateTrigger),
  0x0,
  PLM_TYPE_BTS(kBlockType_C_ShootableBlock, kBtsType_Shootable_4B_RightGreenGateTrigger),
  0x0,
  PLM_TYPE_BTS(kBlockType_C_ShootableBlock, kBtsType_Shootable_4D_RightOrangeGateTrigger),
};

/**
* @brief Sets the instruction list pointer and block types for the upwards gate
* @param plm_idx The index of the PLM
* @return 0
*/
uint8 PlmSetup_C73A_UpwardsGateShootblock(uint16 plm_idx) {  // 0x84C73A
  int idx = plm_idx >> 1;
  uint16 gate_type = plm_room_arguments[idx] >> 1;
  plm_instr_list_ptrs[idx] = kUpwardGatePlmListPtrs[gate_type];

  uint16 left_blk_bts = kUpwardGateLeftBlockBts[gate_type];
  if (left_blk_bts != 0)
    WriteLevelDataBlockTypeAndBts(plm_block_indices[idx] - 2, left_blk_bts);

  uint16 right_blk_bts = kUpwardGateRightBlockBts[gate_type];
  if (right_blk_bts != 0)
    WriteLevelDataBlockTypeAndBts(plm_block_indices[idx] + 2, right_blk_bts);
  return 0;
}

/**
* @brief Gets the gray door type and sets the door to be shot triggered
* @param plm_idx The index of the PLM
* @return 0
*/
uint8 PlmSetup_GreyDoor(uint16 plm_idx) {  // 0x84C794
  int idx = plm_idx >> 1;
  // plm_room_arguments[idx] >> 9 & 0x3E
  plm_variable[idx] = (uint16)(HIBYTE(plm_room_arguments[idx]) & 0x7C) >> 1; // gray door type
  HIBYTE(plm_room_arguments[idx]) &= ~0x7C;
  uint16 plm_shotblock = PLM_TYPE_BTS(kBlockType_C_ShootableBlock, kBtsType_Shootable_44_GenericShotTrigger);
  WriteLevelDataBlockTypeAndBts(plm_block_indices[idx], plm_shotblock);
  return 0;
}

/**
* @brief Sets the door to be shot triggered
* @param plm_idx The index of the PLM
* @return 0
*/
uint8 PlmSetup_Door_Colored(uint16 plm_idx) {  // 0x84C7B1
  uint16 plm_shotblock = PLM_TYPE_BTS(kBlockType_C_ShootableBlock, kBtsType_Shootable_44_GenericShotTrigger);
  WriteLevelDataBlockTypeAndBts(plm_block_indices[plm_idx >> 1], plm_shotblock);
  return 0;
}

/**
* @brief Sets the door to solid if hit with anything besides a power bomb
* @param plm_idx The index of the PLM
* @return 0
*/
uint8 PlmSetup_Door_Blue(uint16 plm_idx) {  // 0x84C7BB
//  if (sign16(projectile_index))
//    printf("BUG: projectile_index invalid\n");
  int idx = plm_idx >> 1;
  int proj_idx = projectile_index >> 1;
  int proj_type = projectile_type[proj_idx] & kProjectileType_ProjMask;
  // Not sure why it checks for the index to be greater than 0, that's not done in the original code
  if (!sign16(projectile_index) && proj_type == kProjectileType_PowerBomb) {
    plm_header_ptr[idx] = 0;
  }
  else {
    uint16 plm_blk_idx = plm_block_indices[idx] >> 1;
    level_data[plm_blk_idx] = SET_BLK_TYPE(level_data[plm_blk_idx], kBlockType_8_SolidBlock);
  }
  return 0;
}

/**
* @brief Sets the PLM to not interact with Samus
* @param plm_idx The index of the PLM
* @return 0
*/
uint8 PlmSetup_C7E2_GenericShotTrigger(uint16 plm_idx) {  // 0x84C7E2
  int idx = plm_idx >> 1;
  uint16 plm_blk_idx = plm_block_indices[idx];
  plm_block_indices[idx] = 0;
  int16 blk_idx = MAX_PLMS-2;
  while (plm_blk_idx != plm_block_indices[blk_idx >> 1]) {
    blk_idx -= 2;
    if (blk_idx < 0)
      return 0;
  }
  // shot status
  // seriously what's up with projectile_index being signed?
  plm_timers[blk_idx >> 1] = projectile_type[(int16)projectile_index >> 1] & 0x1FFF | kProjectileType_DontInteractWithSamus;
  return 0;
}

/**
* @brief Sets the PLM at the block index to be a respawning grapple block
* @param plm_idx The index of the PLM
* @param plmp The pointer to the PLM instruction
* @return uint8* The pointer to the next PLM instruction
*/
const uint8 *PlmInstr_SetBtsTo1(const uint8 *plmp, uint16 plm_idx) {  // 0x84CD93
  BTS[plm_block_indices[plm_idx >> 1] >> 1] = kBtsType_Grapple_1_RespawningCrumbleGrappleBlock;
  return plmp;
}

/**
* @brief Sets the PLM to air if Samus is screw attacking
* @brief This is used by an unused PLM, so the function is not used
* @param plm_idx The index of the PLM
* @return 0
*/
uint8 PlmSetup_D028_D02C_Unused(uint16 plm_idx) {  // 0x84CDC2
  int idx = plm_idx >> 1;
  if (samus_pose == kPose_81_FaceR_Screwattack || samus_pose == kPose_82_FaceL_Screwattack) {
    int plm_blk_idx = plm_block_indices[idx] >> 1;
    plm_variable[idx] = level_data[plm_blk_idx];
    level_data[plm_blk_idx] = SET_BLK_TYPE(level_data[plm_blk_idx], kBlockType_0_Air);
    return 0;
  }
  else {
    plm_header_ptr[idx] = 0;
    return 1;
  }
}

/**
* @brief Sets the PLM to a respawning speed boost block if Samus is speed boosting or shinesparking during collision
* @param plm_idx The index of the PLM
* @return 1 if there was a collision, 0 if there was no collision
*/
uint8 PlmSetup_RespawningSpeedBoostBlock(uint16 plm_idx) {  // 0x84CDEA
  int idx = plm_idx >> 1;
  if ((speed_boost_counter & 0xF00) == 0x400
      || samus_pose == kPose_C9_FaceR_Shinespark_Horiz
      || samus_pose == kPose_CA_FaceL_Shinespark_Horiz
      || samus_pose == kPose_CB_FaceR_Shinespark_Vert
      || samus_pose == kPose_CC_FaceL_Shinespark_Vert
      || samus_pose == kPose_CD_FaceR_Shinespark_Diag
      || samus_pose == kPose_CE_FaceL_Shinespark_Diag) {
    int plm_blk_idx = plm_block_indices[idx] >> 1;
    uint16 plm_respawn_blk = level_data[plm_blk_idx] & 0xF000 | 0xB6;
    plm_variable[idx] = plm_respawn_blk;
    level_data[plm_blk_idx] = plm_respawn_blk & 0xFFF;
    return 0;
  }
  else {
    plm_header_ptr[idx] = 0;
    return 1;
  }
}

/**
* @brief Sets the PLM to a respawning crumble block if Samus is colliding downwards
* @param plm_idx The index of the PLM
* @return 1, indicating there was a collision
*/
uint8 PlmSetup_RespawningCrumbleBlock(uint16 plm_idx) {  // 0x84CE37
  if ((samus_collision_direction & kSamusCollDir_DirMask) == kSamusCollDir_3_Down) {
    int idx = plm_idx >> 1;
    int plm_blk_idx = plm_block_indices[idx] >> 1;
    uint16 plm_respawn_blk = level_data[plm_blk_idx] & 0xF000 | 0xBC;
    plm_variable[idx] = plm_respawn_blk;
    level_data[plm_blk_idx] = plm_respawn_blk & 0x8FFF;
    plm_instruction_timer[idx] = 4;
  }
  else {
    plm_header_ptr[plm_idx >> 1] = 0;
  }
  return 1;
}

/**
* @brief Sets the PLM to a respawning shot block
* @param plm_idx The index of the PLM
* @return 0
*/
uint8 PlmSetup_RespawningShotBlock(uint16 plm_idx) {  // 0x84CE6B
  int idx = plm_idx >> 1;
  int plm_blk_idx = plm_block_indices[idx] >> 1;
  uint16 plm_respawn_blk = level_data[plm_blk_idx] & 0xF000 | 0x52;
  plm_variable[idx] = plm_respawn_blk;
  level_data[plm_blk_idx] = plm_respawn_blk & 0x8FFF;
  return 0;
}

/**
* @brief Sets the PLM to a respawning bomb block if Samus breaks it from speed boosting, screw attacking, or shinesparking
* @param plm_idx The index of the PLM
* @return 1 if there was a collision, 0 if there was no collision
*/
uint8 PlmSetup_RespawningBombBlock(uint16 plm_idx) {  // 0x84CE83
  if ((speed_boost_counter & 0xF00) == 0x400
      || samus_pose == kPose_81_FaceR_Screwattack
      || samus_pose == kPose_82_FaceL_Screwattack
      || samus_pose == kPose_C9_FaceR_Shinespark_Horiz
      || samus_pose == kPose_CA_FaceL_Shinespark_Horiz
      || samus_pose == kPose_CB_FaceR_Shinespark_Vert
      || samus_pose == kPose_CC_FaceL_Shinespark_Vert
      || samus_pose == kPose_CD_FaceR_Shinespark_Diag
      || samus_pose == kPose_CE_FaceL_Shinespark_Diag) {
    int idx = plm_idx >> 1;
    int plm_blk_idx = plm_block_indices[idx] >> 1;
    uint16 plm_respawn_blk = level_data[plm_blk_idx] & 0xF000 | 0x58;
    plm_variable[idx] = plm_respawn_blk;
    level_data[plm_blk_idx] = plm_respawn_blk & 0xFFF;
    return 0;
  }
  else {
    plm_header_ptr[plm_idx >> 1] = 0;
    return 1;
  }
}

/**
* @brief Sets the PLM to a respawning bomb block if Samus breaks it from bombs or power bombs
* @param plm_idx The index of the PLM
* @return 0
*/
uint8 PlmSetup_RespawningBombBlock2(uint16 plm_idx) {  // 0x84CEDA
  int plm_blk_idx;
  uint16 plm_respawn_blk;

  int idx = plm_idx >> 1;
  uint16 proj_idx = projectile_index >> 1;
  uint16 proj_type = projectile_type[proj_idx] & kProjectileType_ProjMask;
  if (proj_type == kProjectileType_Bomb) {
    plm_instr_list_ptrs[idx] += 3;
    plm_blk_idx = plm_block_indices[idx] >> 1;
    plm_respawn_blk = level_data[plm_blk_idx] & 0xF000 | 0x58;
    plm_variable[idx] = plm_respawn_blk;
    level_data[plm_blk_idx] = plm_respawn_blk & 0x8FFF;
  }
  else if (proj_type == kProjectileType_PowerBomb) {
    plm_blk_idx = plm_block_indices[idx] >> 1;
    plm_respawn_blk = level_data[plm_blk_idx] & 0xF000 | 0x58;
    plm_variable[idx] = plm_respawn_blk;
    level_data[plm_blk_idx] = plm_respawn_blk & 0x8FFF;
  }
  else {
    plm_header_ptr[plm_idx >> 1] = 0;
  }
  return 0;
}

/**
* @brief Sets the PLM to either a respawning power bomb block if Samus breaks it from power bombs,
* @brief or to an exposed power bomb block if Samus bombs it
* @param plm_idx The index of the PLM
* @return 0
*/
uint8 PlmSetup_RespawningPowerBombBlock(uint16 plm_idx) {  // 0x84CF2E
  uint16 proj_idx = projectile_index >> 1;
  uint16 proj_type = projectile_type[proj_idx] & kProjectileType_ProjMask;
  if (proj_type == kProjectileType_Bomb) {
    plm_instr_list_ptrs[plm_idx >> 1] = addr_kPlmInstrList_C91C_PowerBombBlockBombed_UnusedD01C;
  }
  else if (proj_type == kProjectileType_PowerBomb) {
    int idx = plm_idx >> 1;
    int plm_blk_idx = plm_block_indices[idx] >> 1;
    uint16 plm_respawn_blk = level_data[plm_blk_idx] & 0xF000 | 0x57;
    plm_variable[idx] = plm_respawn_blk;
    level_data[plm_blk_idx] = plm_respawn_blk & 0x8FFF;
  }
  else {
    plm_header_ptr[plm_idx >> 1] = 0;
  }
  return 0;
}

/**
* @brief Sets the PLM to either a respawning super missile block if Samus breaks it from super missiles,
* @brief or to an exposed super missile block if Samus bombs it
* @param plm_idx The index of the PLM
* @return 0
*/
uint8 PlmSetup_SuperMissileBlockRespawning(uint16 plm_idx) {  // 0x84CF67
  uint16 proj_idx = projectile_index >> 1;
  uint16 proj_type = projectile_type[proj_idx] & kProjectileType_ProjMask;
  if (proj_type == kProjectileType_Bomb
// Feature: Power bombs reveal super missile blocks
|| ( (enhanced_features0 & kFeatures0_InstantPickups)
      && proj_type == kProjectileType_PowerBomb)
      ) {
    plm_instr_list_ptrs[plm_idx >> 1] = addr_kPlmInstrList_C922_SuperMissileBlockBombed_Unused;
  }
  else if (proj_type == kProjectileType_SuperMissile) {
    int idx = plm_idx >> 1;
    int plm_blk_idx = plm_block_indices[idx] >> 1;
    uint16 plm_respawn_blk = level_data[plm_blk_idx] & 0xF000 | 0x9F;
    plm_variable[idx] = plm_respawn_blk;
    level_data[plm_blk_idx] = plm_respawn_blk & 0x8FFF;
  }
  else {
    plm_header_ptr[plm_idx >> 1] = 0;
  }
  return 0;
}

/**
* @brief Deactivates the PLM if the crumble block was not hit with a bomb
* @param plm_idx The index of the PLM
* @return 0
*/
uint8 PlmSetup_CrumbleBlock(uint16 plm_idx) {  // 0x84CFA0
  uint16 proj_idx = projectile_index >> 1;
  uint16 proj_type = projectile_type[proj_idx] & kProjectileType_ProjMask;
  if (proj_type != kProjectileType_Bomb
// Feature: Power bombs reveal crumble and other blocks
|| ((enhanced_features0 & kFeatures0_InstantPickups)
    && proj_type == kProjectileType_PowerBomb)
      )
    plm_header_ptr[plm_idx >> 1] = 0;
  return 0;
}

/**
* @brief Sets the PLM to a breakable grapple block and clears the BTS
* @param plm_idx The index of the PLM
* @return 0x41, indicating a collision and a connection to grapple
*/
uint8 PlmSetup_BreakableGrappleBlock(uint16 plm_idx) {  // 0x84CFB5
  int idx = plm_idx >> 1;
  uint16 plm_blk_idx = plm_block_indices[idx];
  // plm respawn block
  plm_variable[idx] = level_data[plm_blk_idx >> 1];
  // BTS[plm_blk_idx >> 1] = 0;
  WORD(BTS[plm_blk_idx >> 1]) = BTS[(plm_blk_idx >> 1) + 1] << 8;
  return 0x41;
}

/**
* @brief Does nothing
* @param plm_idx The index of the PLM
* @return 0x41, indicating a collision and a connection to grapple
*/
uint8 PlmSetup_D0D8_SetVFlag(uint16 plm_idx) {  // 0x84CFCD
  return 0x41;
}

/**
* @brief Does nothing
* @param plm_idx The index of the PLM
* @return 1 indicating a collision and a disconnect from grapple
*/
uint8 PlmSetup_D0D8_ClearVflag(uint16 plm_idx) {  // 0x84CFD1
  return 1;
}

/**
* @brief Deals one damage to Samus from touching a broken Draygon turret
* @param plm_idx The index of the PLM
* @return 0x41, indicating a collision and a connection to grapple
*/
uint8 PlmSetup_D0E8_GiveSamusDamage(uint16 plm_idx) {  // 0x84CFD5
  ++samus_periodic_damage;
  return 0x41;
}

/**
* @brief Sets the PLM to an air block
* @brief This function is broken, but works since the PLM is drawn over by the instruction list on the next frame
* @param plm_idx The index of the PLM
* @return 0
*/
uint8 PlmSetup_D113_LowerNorfairChozoRoomPlug(uint16 plm_idx) {  // 0x84D108
  uint16 a = 0; // a undefined
  level_data[plm_block_indices[plm_idx >> 1] >> 1] = a & 0xFFF;
  return 0;
}

/**
* @brief Sets the PLM to a shootable 1x1 respawning shot block
* @brief This is used by an unused PLM, so the function is not used
* @param plm_idx The index of the PLM
* @return 0
*/
uint8 PlmSetup_D127(uint16 plm_idx) {  // 0x84D117
  uint16 plm_blk_idx = plm_block_indices[plm_idx >> 1];
  uint16 plm_blk_data = PLM_TYPE_BTS(kBlockType_C_ShootableBlock, kBtsType_Shootable_0_1x1RespawningShotBlock);
  WriteLevelDataBlockTypeAndBts(plm_blk_idx, plm_blk_data);
  return 0;
}

/**
* @brief Sets the PLM to a grapple block
* @brief This is used by an unused PLM, so the function is not used
* @param plm_idx The index of the PLM
* @return 0
*/
uint8 PlmSetup_D138(uint16 plm_idx) {  // 0x84D12B
  uint16 plm_blk_idx = plm_block_indices[plm_idx >> 1];
  uint16 plm_blk_data = PLM_TYPE_BTS(kBlockType_E_GrappleBlock, kBtsType_Grapple_0_GenericGrappleBlock);
  WriteLevelDataBlockTypeAndBts(plm_blk_idx, plm_blk_data);
  return 0;
}

/**
* @brief Sets the lava to the bottom of the room
* @param plm_idx The index of the PLM
* @param plmp The pointer to the PLM instruction
* @return uint8* The pointer to the next PLM instruction
*/
const uint8 *PlmInstr_FxBaseYPos_0x2D2(const uint8 *plmp, uint16 plm_idx) {  // 0x84D155
  fx_base_y_pos = 722;
  return plmp;
}

/**
* @brief Sets the PLM to the Lower Norfair Chozo Hand Trigger if it is an air block
* @param plm_idx The index of the PLM
*/
void PlmPreInstr_DeletePlmAndSpawnTriggerIfBlockDestroyed(uint16 plm_idx) {  // 0x84D15C
  // block at x=8, y=4
  uint16 plm_blk_idx = 2 * (8 * (uint8)room_width_in_blocks + 4);
  // if block is air
  if (level_data[plm_blk_idx >> 1] == 255) {
    uint16 plm_blk_data = PLM_TYPE_BTS(kBlockType_B_SpecialBlock, kBtsType_Special_Norfair_83_LowerNorfairChozoHandTrigger);
    WriteLevelDataBlockTypeAndBts(plm_blk_idx, plm_blk_data);
    plm_header_ptr[plm_id >> 1] = 0;
  }
}

/**
* @brief Spawns the crumble plug if Samus has the space jump and is in morph ball form while touching the trigger
* @param plm_idx The index of the PLM
* @return 1, indicating a collision
*/
uint8 PlmSetup_D6DA_LowerNorfairChozoHandTrigger(uint16 plm_idx) {  // 0x84D18F
  if ((collected_items & kItem_SpaceJump)
      && (samus_collision_direction & kSamusCollDir_DirMask) == kSamusCollDir_3_Down
      && (samus_pose == kPose_1D_FaceR_Morphball_Ground
          || samus_pose == kPose_79_FaceR_Springball_Ground
          || samus_pose == kPose_7A_FaceL_Springball_Ground)) {
    SetEventHappened(kEvent_12_LowerNorfairChozoLoweredAcid);
    enemy_data[0].parameter_1 = 1;
    int plm_blk_idx = plm_block_indices[plm_idx >> 1] >> 1;
    level_data[plm_blk_idx] = SET_BLK_TYPE(level_data[plm_blk_idx], kBlockType_0_Air);
    RunSamusCode(kSamusCode_0_LockSamus);
    SpawnHardcodedPlm((SpawnHardcodedPlmArgs) { .x_pos = 12, .y_pos = 29, .plm_id_ = addr_kPlmHeader_D113_LowerNorfair_ChozoRoom_CrumblePlug });
  }
  plm_header_ptr[plm_idx >> 1] = 0;
  return 1;
}

/**
* @brief Increments the room argument if the PLM was shot by any missile
* @param plm_idx The index of the PLM
*/
void PlmPreInstr_IncrementRoomArgIfShotBySuperMissile(uint16 plm_idx) {  // 0x84D1E6
  int idx = plm_idx >> 1;
  uint16 shot_status = plm_timers[idx] & kProjectileType_ProjMask;
  if (shot_status == kProjectileType_SuperMissile || shot_status == kProjectileType_Missile)
    plm_room_arguments[idx]++;
  plm_timers[idx] = 0;  // clear shot status
}

/**
* @brief Goes to the instruction if the room argument is less than the PLM argument
* @param plmp The pointer to the PLM instruction
* @param plm_idx The index of the PLM
* @return uint8* The pointer to the next PLM instruction
*/
const uint8 *PlmInstr_GotoIfRoomArgLess(const uint8 *plmp, uint16 plm_idx) {  // 0x84D2F9
  if (plm_room_arguments[plm_idx >> 1] < GET_WORD(plmp))
    return INSTRB_RETURN_ADDR(GET_WORD(plmp + 2));
  else
    return plmp + 4;
}

/**
* @brief Spawns four Mother Brain glass shards and plays the glass shattering sound effect
* @param plmp The pointer to the PLM instruction
* @param plm_idx The index of the PLM
* @return uint8* The pointer to the next PLM instruction
*/
const uint8 *PlmInstr_SpawnFourMotherBrainGlass(const uint8 *plmp, uint16 plm_idx) {  // 0x84D30B
  QueueSfx3_Max15(kSfx3_MotherBrainsGlassShattering_HighPriority);
  SpawnMotherBrainGlassShatteringShard(GET_WORD(plmp + 0));
  SpawnMotherBrainGlassShatteringShard(GET_WORD(plmp + 2));
  SpawnMotherBrainGlassShatteringShard(GET_WORD(plmp + 4));
  SpawnMotherBrainGlassShatteringShard(GET_WORD(plmp + 6));
  return plmp + 8;
}

/**
* @brief Spawns a Mother Brain glass shard enemy projectile
* @param x_offset_idx The index into the x offsets table
*/
void SpawnMotherBrainGlassShatteringShard(uint16 x_offset_idx) {  // 0x84D331
  SpawnEprojWithRoomGfx(addr_kEproj_MotherBrainGlassShatteringShard, x_offset_idx);
}

/**
* @brief Activates the PLM if Samus has bombs
* @param plm_idx The index of the PLM
*/
void PlmPreInstr_WakePlmIfSamusHasBombs(uint16 plm_idx) {  // 0x84D33B
  if (collected_items & kItem_Bombs) {
    int idx = plm_idx >> 1;
    plm_instruction_timer[idx] = 1;
    plm_instr_list_ptrs[idx] += 2;
    plm_pre_instrs[idx] = FUNC16(nullsub_351);
  }
}

/**
* @brief Spawns a Torizo statue breaking enemy projectile
* @param plmp The pointer to the PLM instruction
* @param plm_idx The index of the PLM
* @return uint8* The pointer to the next PLM instruction
*/
const uint8 *PlmInstr_SpawnTorizoStatueBreaking(const uint8 *plmp, uint16 plm_idx) {  // 0x84D357
  SpawnEprojWithRoomGfx(addr_kEproj_BombTorizoStatueBreaking, GET_WORD(plmp));
  return plmp + 2;
}

/**
* @brief Queues the Song 1 music track (Pre-Bomb Torizo fight track)
* @param plmp The pointer to the PLM instruction
* @param plm_idx The index of the PLM
*/
const uint8 *PlmInstr_QueueSong1MusicTrack(const uint8 *plmp, uint16 plm_idx) {  // 0x84D3C7
  QueueMusic_Delayed8(kMusic_Song1);
  return plmp;
}

/**
* @brief Turns the Wrecked Ship spikes into slopes in the Chozo statue room
* @param plmp The pointer to the PLM instruction
* @param plm_idx The index of the PLM
* @return uint8* The pointer to the next PLM instruction
*/
const uint8 *PlmInstr_TransferWreckedShipChozoSpikesToSlopes(const uint8 *plmp, uint16 plm_idx) {  // 0x84D3D7
  uint16 plm_blk_data = PLM_TYPE_BTS(kBlockType_1_Slope, kBtsType_Slope_12_NonSquare_Triangle);
  WriteLevelDataBlockTypeAndBts(0x1608, plm_blk_data);
  plm_blk_data = PLM_TYPE_BTS(kBlockType_1_Slope, kBtsType_Slope_13_NonSquare_Rectangle);
  WriteLevelDataBlockTypeAndBts(0x160A, plm_blk_data);
  return plmp;
}

/**
* @brief Turns the Wrecked Ship slopes back into spikes in the Chozo statue room
* @param plmp The pointer to the PLM instruction
* @param plm_idx The index of the PLM
* @return uint8* The pointer to the next PLM instruction
*/
const uint8 *PlmInstr_TransferWreckedShipSlopesToChozoSpikes(const uint8 *plmp, uint16 plm_idx) {  // 0x84D3F4
  uint16 plm_blk_data = PLM_TYPE_BTS(kBlockType_0_Air, 0);
  WriteLevelDataBlockTypeAndBts(0x1608, plm_blk_data);
  WriteLevelDataBlockTypeAndBts(0x160A, plm_blk_data);
  return plmp;
}

/**
* @brief Activates the PLM if the face buttons or left/right d-pad buttons are pressed
* @param plm_idx The index of the PLM
*/
void PlmPreInstr_WakeOnKeyPress(uint16 plm_idx) {  // 0x84D4BF
  if (joypad1_newkeys & (kButton_B | kButton_Y | kButton_Left | kButton_Right | kButton_A | kButton_X)) {
    int idx = plm_idx >> 1;
    plm_instruction_timer[idx] = 1;
    plm_instr_list_ptrs[idx] += 2;
  }
}

/**
* @brief Enables water physics
* @param plmp The pointer to the PLM instruction
* @param plm_idx The index of the PLM
* @return uint8* The pointer to the next PLM instruction
*/
const uint8 *PlmInstr_EnableWaterPhysics(const uint8 *plmp, uint16 plm_idx) {  // 0x84D525
  fx_liquid_options &= ~kFxLiquidOption_4_LiquidPhysicsDisabled;
  return plmp;
}

/**
* @brief Spawns the N00b Tube crack enemy projectile
* @param plmp The pointer to the PLM instruction
* @param plm_idx The index of the PLM
* @return uint8* The pointer to the next PLM instruction
*/
const uint8 *PlmInstr_SpawnN00bTubeCrackEproj(const uint8 *plmp, uint16 plm_idx) {  // 0x84D52C
  SpawnEprojWithRoomGfx(addr_kEproj_N00bTubeCracks, 0);
  return plmp;
}

/**
* @brief Creates a diagonal, 1 pixel offset earthquake effect
* @param plmp The pointer to the PLM instruction
* @param plm_idx The index of the PLM
* @return uint8* The pointer to the next PLM instruction
*/
const uint8 *PlmInstr_DiagonalEarthquake(const uint8 *plmp, uint16 plm_idx) {  // 0x84D536
  earthquake_type = EARTHQUAKE(kEarthquake_Direction_Diag, kEarthquake_Intensity_1, kEarthquake_Layers_Bg1_Bg2);
  earthquake_timer = 64;
  return plmp;
}

/**
* @brief Spawns 10 N00b Tube shards and 6 N00b Tube released air bubbles enemy projectiles
* @param plmp The pointer to the PLM instruction
* @param plm_idx The index of the PLM
* @return uint8* The pointer to the next PLM instruction
*/
const uint8 *PlmInstr_Spawn10shardsAnd6n00bs(const uint8 *plmp, uint16 plm_idx) {  // 0x84D543
  SpawnEprojWithRoomGfx(addr_kEproj_N00bTubeShards, 0);
  SpawnEprojWithRoomGfx(addr_kEproj_N00bTubeShards, 2);
  SpawnEprojWithRoomGfx(addr_kEproj_N00bTubeShards, 4);
  SpawnEprojWithRoomGfx(addr_kEproj_N00bTubeShards, 6);
  SpawnEprojWithRoomGfx(addr_kEproj_N00bTubeShards, 8);
  SpawnEprojWithRoomGfx(addr_kEproj_N00bTubeShards, 0xA);
  SpawnEprojWithRoomGfx(addr_kEproj_N00bTubeShards, 0xC);
  SpawnEprojWithRoomGfx(addr_kEproj_N00bTubeShards, 0xE);
  SpawnEprojWithRoomGfx(addr_kEproj_N00bTubeShards, 0x10);
  SpawnEprojWithRoomGfx(addr_kEproj_N00bTubeShards, 0x12);
  SpawnEprojWithRoomGfx(addr_kEproj_N00bTubeReleasedAirBubbles, 0);
  SpawnEprojWithRoomGfx(addr_kEproj_N00bTubeReleasedAirBubbles, 2);
  SpawnEprojWithRoomGfx(addr_kEproj_N00bTubeReleasedAirBubbles, 4);
  SpawnEprojWithRoomGfx(addr_kEproj_N00bTubeReleasedAirBubbles, 6);
  SpawnEprojWithRoomGfx(addr_kEproj_N00bTubeReleasedAirBubbles, 8);
  SpawnEprojWithRoomGfx(addr_kEproj_N00bTubeReleasedAirBubbles, 0xA);
  return plmp;
}

/**
* @brief Locks Samus during the n00b tube cutscene
* @param plmp The pointer to the PLM instruction
* @param plm_idx The index of the PLM
* @return uint8* The pointer to the next PLM instruction
*/
const uint8 *PlmInstr_DisableSamusControls(const uint8 *plmp, uint16 plm_idx) {  // 0x84D5E6
  RunSamusCode(kSamusCode_0_LockSamus);
  return plmp;
}

/**
* @brief Unlocks Samus after the n00b tube cutscene
* @param plmp The pointer to the PLM instruction
* @param plm_idx The index of the PLM
* @return uint8* The pointer to the next PLM instruction
*/
const uint8 *PlmInstr_EnableSamusControls(const uint8 *plmp, uint16 plm_idx) {  // 0x84D5EE
  RunSamusCode(kSamusCode_1_UnlockSamus);
  return plmp;
}

/**
* @brief Sets Mother Brain's glass to a shootable block
* @param plm_idx The index of the PLM
* @return 0
*/
uint8 PlmSetup_MotherBrainGlass(uint16 plm_idx) {  // 0x84D5F6
  int idx = plm_idx >> 1;
  plm_room_arguments[idx] = 0;  // hit counter = 0
  // a draw instruction changes the solid block into a shootable block
  uint16 plm_blk_data = PLM_TYPE_BTS(kBlockType_8_SolidBlock, kBtsType_Shootable_44_GenericShotTrigger);
  WriteLevelDataBlockTypeAndBts(plm_block_indices[idx], plm_blk_data);
  return 0;
}

/**
* @brief Deletes the PLM if the area Torizo boss is dead
* @param plm_idx The index of the PLM
* @return 0
*/
uint8 PlmSetup_DeletePlmIfAreaTorizoDead(uint16 plm_idx) {  // 0x84D606
  if (CheckBossBitForCurArea(kBossBit_AreaTorizo))
    plm_header_ptr[plm_idx >> 1] = 0;
  return 0;
}

/**
* @brief Sets the PLM to a trigger for the Wrecked Ship Chozo hand
* @param plm_idx The index of the PLM
* @return 0
*/
uint8 PlmSetup_MakeBllockChozoHandTrigger(uint16 plm_idx) {  // 0x84D616
  uint16 plm_blk_data = PLM_TYPE_BTS(kBlockType_B_SpecialBlock, kBtsType_Special_WreckedShip_80_WreckedShipChozoHandTrigger);
  WriteLevelDataBlockTypeAndBts(plm_block_indices[plm_idx >> 1], plm_blk_data);
  return 0;
}

/**
* @brief Sets up the PLM and level data for the Wrecked Ship Chozo hand trigger cutscene if Samus is in morph ball form
* @param plm_idx The index of the PLM
* @return 1, indicating a collision
*/
uint8 PlmSetup_D6F2_WreckedShipChozoHandTrigger(uint16 plm_idx) {  // 0x84D620
  int idx = plm_idx >> 1;
  if (CheckBossBitForCurArea(kBossBit_AreaBoss)
      && (samus_collision_direction & kSamusCollDir_DirMask) == kSamusCollDir_3_Down
      && (samus_pose == kPose_1D_FaceR_Morphball_Ground
          || samus_pose == kPose_79_FaceR_Springball_Ground
          || samus_pose == kPose_7A_FaceL_Springball_Ground)) {
    enemy_data[0].parameter_1 = 1;
    scrolls[8] = scrolls[7] = kScroll_Green;
    scrolls[14] = scrolls[13] = kScroll_Blue;
    int plm_blk_idx = plm_block_indices[idx] >> 1;
    level_data[plm_blk_idx] = SET_BLK_TYPE(level_data[plm_blk_idx], kBlockType_0_Air);
    RunSamusCode(kSamusCode_0_LockSamus);
    SpawnHardcodedPlm((SpawnHardcodedPlmArgs) { .x_pos = 23, .y_pos = 29, .plm_id_ = addr_kPlmHeader_D6F8_WreckedShip_ClearChozoSlopeAccess });
  }
  plm_header_ptr[idx] = 0;
  return 1;
}

/**
* @brief Sets the PLM to an air block that is shot triggered
* @brief This is used by an unused PLM, so the function is not used
* @param plm_idx The index of the PLM
* @return 0
*/
uint8 PlmSetup_D700_MakePlmAirBlock_Unused(uint16 plm_idx) {  // 0x84D67F
  uint16 plm_blk_data = PLM_TYPE_BTS(kBlockType_0_Air, kBtsType_Shootable_44_GenericShotTrigger);
  WriteLevelDataBlockTypeAndBts(plm_block_indices[plm_idx >> 1], plm_blk_data);
  return 0;
}

/**
* @brief Sets the PLM to a shootable block that is shot triggered
* @brief This is used by an unused PLM, so the function is not used
* @param plm_idx The index of the PLM
* @return 0
*/
uint8 PlmSetup_D704_AlteranateLowerNorfairChozoHand_Unused(uint16 plm_idx) {  // 0x84D689
  uint16 plm_blk_data = PLM_TYPE_BTS(kBlockType_8_SolidBlock, kBtsType_Shootable_44_GenericShotTrigger);
  WriteLevelDataBlockTypeAndBts(plm_block_indices[plm_idx >> 1], plm_blk_data);
  return 0;
}

/**
* @brief Sets the 2x2 block to a solid block that is shot triggered
* @brief This is used by an unused PLM, so the function is not used
* @param plm_idx The index of the PLM
* @return 0
*/
uint8 PlmSetup_D708_LowerNorfairChozoBlockUnused(uint16 plm_idx) {  // 0x84D693
  int idx = plm_idx >> 1;
  uint16 plm_blk_idx = plm_block_indices[idx];
  uint16 plm_blk_data = PLM_TYPE_BTS(kBlockType_8_SolidBlock, kBtsType_Shootable_44_GenericShotTrigger);
  WriteLevelDataBlockTypeAndBts(plm_blk_idx, plm_blk_data);
  plm_blk_data = PLM_TYPE_BTS(kBlockType_5_HorizExtension, (uint8)-1);
  WriteLevelDataBlockTypeAndBts(plm_blk_idx + 2, plm_blk_data);

  plm_blk_idx += 2 * room_width_in_blocks;
  plm_blk_data = PLM_TYPE_BTS(kBlockType_D_VertExtension, (uint8)-1);
  WriteLevelDataBlockTypeAndBts(plm_blk_idx, plm_blk_data);
  WriteLevelDataBlockTypeAndBts(plm_blk_idx + 2, plm_blk_data);
  return 0;
}

/**
* @brief Sets the PLM to a solid block that is shot triggered
* @param plm_idx The index of the PLM
* @return 0
*/
uint8 PlmSetup_D70C_NoobTube(uint16 plm_idx) {  // 0x84D6CC
  uint16 plm_blk_data = PLM_TYPE_BTS(kBlockType_8_SolidBlock, kBtsType_Shootable_44_GenericShotTrigger);
  WriteLevelDataBlockTypeAndBts(plm_block_indices[plm_idx >> 1], plm_blk_data);
  return 0;
}

/**
* @brief Activates the PLM if the door is open
* @param plm_idx The index of the PLM
*/
void PlmPreInstr_WakePlmIfRoomArgumentDoorIsSet(uint16 plm_idx) {  // 0x84D753
  int idx = plm_idx >> 1;
  int byte_idx = PrepareBitAccess(plm_room_arguments[idx]);
  if (opened_door_bit_array[byte_idx] & bitmask) {
    plm_pre_instrs[idx] = addr_locret_84D779;
    plm_instr_list_ptrs[idx] = plm_instruction_list_link_reg[idx];
    plm_instruction_timer[idx] = 1;
  }
}

/**
* @brief Spawns an Eye Door projectile and plays the Eye Door acid spit sound effect
* @param plmp The pointer to the PLM instruction
* @param plm_idx The index of the PLM
* @return uint8* The pointer to the next PLM instruction
*/
const uint8 *PlmInstr_ShootEyeDoorProjectileWithProjectileArg(const uint8 *plmp, uint16 plm_idx) {  // 0x84D77A
  SpawnEprojWithRoomGfx(addr_kEproj_EyeDoorProjectile, GET_WORD(plmp));
  QueueSfx2_Max6(kSfx2_KiHunterSpit_EyeDoorAcidSpit_DraygonGoop);
  return plmp + 2;
}

/**
* @brief Spawns an Eye Door sweat projectile
* @param plmp The pointer to the PLM instruction
* @param plm_idx The index of the PLM
* @return uint8* The pointer to the next PLM instruction
*/
const uint8 *PlmInstr_SpawnEyeDoorSweatEproj(const uint8 *plmp, uint16 plm_idx) {  // 0x84D790
  SpawnEprojWithRoomGfx(addr_kEproj_EyeDoorSweat, GET_WORD(plmp));
  return plmp + 2;
}

/**
* @brief Spawns two Eye Door smoke projectiles
* @param plmp The pointer to the PLM instruction
* @param plm_idx The index of the PLM
* @return uint8* The pointer to the next PLM instruction
*/
const uint8 *PlmInstr_SpawnTwoEyeDoorSmoke(const uint8 *plmp, uint16 plm_idx) {  // 0x84D79F
  SpawnEprojWithRoomGfx(addr_kEproj_EyeDoorSmoke, 0x30A);
  SpawnEprojWithRoomGfx(addr_kEproj_EyeDoorSmoke, 0x30A);
  return plmp;
}

/**
* @brief Spawns an Eye Door sweat drop projectile
* @param plmp The pointer to the PLM instruction
* @param plm_idx The index of the PLM
* @return uint8* The pointer to the next PLM instruction
*/
const uint8 *PlmInstr_SpawnEyeDoorSmokeProjectile(const uint8 *plmp, uint16 plm_idx) {  // 0x84D7B6
  SpawnEprojWithRoomGfx(addr_kEproj_EyeDoorSmoke, 0xB);
  return plmp;
}

/**
* @brief Moves the PLM up a row and makes a blue door facing right
* @param plmp The pointer to the PLM instruction
* @param plm_idx The index of the PLM
* @return uint8* The pointer to the next PLM instruction
*/
const uint8 *PlmInstr_MoveUpAndMakeBlueDoorFacingRight(const uint8 *plmp, uint16 plm_idx) {  // 0x84D7C3
  int idx = plm_idx >> 1;
  uint16 plm_blk_idx = (plm_block_indices[idx] -= room_width_in_blocks * 2);
  uint16 plm_blk_data = PLM_TYPE_BTS(kBlockType_C_ShootableBlock, kBtsType_Shootable_41_BlueDoorFacingRight);
  WriteLevelDataBlockTypeAndBts(plm_blk_idx, plm_blk_data);
  Create3BlocksVerticalExtension(plm_blk_idx);
  return plmp;
}

/**
* @brief Moves the PLM up a row and makes a blue door facing left
* @param plmp The pointer to the PLM instruction
* @param plm_idx The index of the PLM
* @return uint8* The pointer to the next PLM instruction
*/
const uint8 *PlmInstr_MoveUpAndMakeBlueDoorFacingLeft(const uint8 *plmp, uint16 plm_idx) {  // 0x84D7DA
  int v2 = plm_idx >> 1;
  uint16 plm_blk_idx = (plm_block_indices[v2] -= room_width_in_blocks * 2);
  uint16 plm_blk_data = PLM_TYPE_BTS(kBlockType_C_ShootableBlock, kBtsType_Shootable_40_BlueDoorFacingLeft);
  WriteLevelDataBlockTypeAndBts(plm_blk_idx, plm_blk_data);
  Create3BlocksVerticalExtension(plm_blk_idx);
  return plmp;
}

/**
* @brief Creates three copies of the block below the PLM block
* @param plm_blk_idx The index of the PLM block
*/
void Create3BlocksVerticalExtension(uint16 plm_blk_idx) {  // 0x84D7EF
  plm_blk_idx += room_width_in_blocks * 2;
  uint16 plm_blk_data = PLM_TYPE_BTS(kBlockType_D_VertExtension, (uint8)-1);
  WriteLevelDataBlockTypeAndBts(plm_blk_idx, plm_blk_data);

  plm_blk_idx += room_width_in_blocks * 2;
  plm_blk_data = PLM_TYPE_BTS(kBlockType_D_VertExtension, (uint8)-2);
  WriteLevelDataBlockTypeAndBts(plm_blk_idx, plm_blk_data);

  plm_blk_idx += room_width_in_blocks * 2;
  plm_blk_data = PLM_TYPE_BTS(kBlockType_D_VertExtension, (uint8)-3);
  WriteLevelDataBlockTypeAndBts(plm_blk_idx, plm_blk_data);
}

/**
* @brief Sets the Eye Door Eye PLM to a shootable block that is shot triggered if the door is closed
* @param plm_idx The index of the PLM
* @return 0
*/
uint8 PlmSetup_EyeDoorEye(uint16 plm_idx) {  // 0x84DA8C
  int idx = plm_idx >> 1;
  int byte_idx = PrepareBitAccess(plm_room_arguments[idx]);
  if (!(opened_door_bit_array[byte_idx] & bitmask)) {
    uint16 plm_blk_idx = plm_block_indices[idx];
    uint16 plm_blk_data = PLM_TYPE_BTS(kBlockType_C_ShootableBlock, kBtsType_Shootable_44_GenericShotTrigger);
    WriteLevelDataBlockTypeAndBts(plm_blk_idx, plm_blk_data);

    plm_blk_idx += room_width_in_blocks * 2;
    plm_blk_data = PLM_TYPE_BTS(kBlockType_D_VertExtension, (uint8)-1);
    WriteLevelDataBlockTypeAndBts(2 * room_width_in_blocks + plm_block_indices[idx], plm_blk_data);
  }
  return 0;
}

/**
* @brief Sets the Eye Door PLM to a solid spike block
* @param plm_idx The index of the PLM
* @return 0
*/
uint8 PlmSetup_EyeDoor(uint16 plm_idx) {  // 0x84DAB9
  int byte_idx = PrepareBitAccess(plm_room_arguments[plm_idx >> 1]);
  if (!(opened_door_bit_array[byte_idx] & bitmask)) {
    uint16 plm_blk_data = PLM_TYPE_BTS(kBlockType_A_SpikeBlock, kBtsType_Spike_0_Solid_GenericSpike);
    WriteLevelDataBlockTypeAndBts(plm_block_indices[plm_idx >> 1], plm_blk_data);
  }
  return 0;
}

/**
* @brief Sets the 1st metroid hall cleared event if the enemy death quota is met
* @param plm_idx The index of the PLM
*/
void PlmPreInstr_SetMetroidsClearState_Ev0x10(uint16 plm_idx) {  // 0x84DADE
  if (num_enemies_killed_in_room >= num_enemy_deaths_left_to_clear)
    SetEventHappened(kEvent_16_1stMetroidHallCleared);
}

/**
* @brief Sets the 2nd metroid hall cleared event if the enemy death quota is met
* @param plm_idx The index of the PLM
*/
void PlmPreInstr_SetMetroidsClearState_Ev0x11(uint16 plm_idx) {  // 0x84DAEE
  if (num_enemies_killed_in_room >= num_enemy_deaths_left_to_clear)
    SetEventHappened(kEvent_17_1stMetroidShaftCleared);
}

/**
* @brief Sets the 3rd metroid hall cleared event if the enemy death quota is met
* @param plm_idx The index of the PLM
*/
void PlmPreInstr_SetMetroidsClearState_Ev0x12(uint16 plm_idx) {  // 0x84DAFE
  if (num_enemies_killed_in_room >= num_enemy_deaths_left_to_clear)
    SetEventHappened(kEvent_18_2ndMetroidHallCleared);
}

/**
* @brief Sets the 4th metroid hall cleared event if the enemy death quota is met
* @param plm_idx The index of the PLM
*/
void PlmPreInstr_SetMetroidsClearState_Ev0x13(uint16 plm_idx) {  // 0x84DB0E
  if (num_enemies_killed_in_room >= num_enemy_deaths_left_to_clear)
    SetEventHappened(kEvent_19_2ndMetroidShaftCleared);
}

uint16 kSetMetroidsClearStatePreInstrs[] = {
  FUNC16(nullsub_73),
  FUNC16(nullsub_74),
  FUNC16(nullsub_75),
  FUNC16(nullsub_76),
  FUNC16(nullsub_77),
  FUNC16(nullsub_78),
  FUNC16(nullsub_79),
  FUNC16(nullsub_80),
  FUNC16(nullsub_81),
  FUNC16(PlmPreInstr_SetMetroidsClearState_Ev0x10),
  FUNC16(PlmPreInstr_SetMetroidsClearState_Ev0x11),
  FUNC16(PlmPreInstr_SetMetroidsClearState_Ev0x12),
  FUNC16(PlmPreInstr_SetMetroidsClearState_Ev0x13),
};
/**
* @brief Sets the metroid hall cleared events
* @param plm_idx The index of the PLM
* @return 0
*/
uint8 PlmSetup_SetMetroidRequiredClearState(uint16 plm_idx) {  // 0x84DB1E
  plm_pre_instrs[plm_idx >> 1] = kSetMetroidsClearStatePreInstrs[plm_room_arguments[plm_idx >> 1] >> 1];
  return 0;
}

/**
* @brief Goes to the instruction stored in the link register if the PLM is shot with any missile
* @param plm_idx The index of the PLM
*/
void PlmPreInstr_GotoLinkIfShotWithSuperMissile(uint16 plm_idx) {  // 0x84DB64
  int idx = plm_idx >> 1;
  uint16 shot_status = plm_timers[idx] & kProjectileType_ProjMask;
  if (shot_status == kProjectileType_SuperMissile) {
    plm_room_arguments[idx] = 119;  // door hit counter
  }
  else if (shot_status != kProjectileType_Missile) {
    return;
  }
  plm_timers[idx] = 0;
  plm_instr_list_ptrs[idx] = plm_instruction_list_link_reg[idx];
  plm_instruction_timer[idx] = 1;
}

/**
* @brief Sets the RAM address in the PLM variable
* @brief Used to set the Draygon turret to damaged
* @param plm_idx The index of the PLM
* @param value The value to store
*/
void SetPlmVarPtr(uint16 plm_idx, uint16 value) {
  WORD(g_ram[plm_variable[plm_idx >> 1]]) = value;
}

/**
* @brief Sets the Draygon turret facing right PLM blocks to a spike
* @param plmp The pointer to the PLM instruction
* @param plm_idx The index of the PLM
* @return uint8* The pointer to the next PLM instruction
*/
const uint8 *PlmInstr_DamageDraygonTurret(const uint8 *plmp, uint16 plm_idx) {  // 0x84DB8E
  SetPlmVarPtr(plm_idx, 1);
  uint16 plm_blk_idx = plm_block_indices[plm_idx >> 1];
  uint16 plm_blk_data = PLM_TYPE_BTS(kBlockType_A_SpikeBlock, kBtsType_Spike_3_Solid_DraygonBrokenTurret);
  WriteLevelDataBlockTypeAndBts(plm_blk_idx, plm_blk_data);

  plm_blk_idx += room_width_in_blocks * 2;
  WriteLevelDataBlockTypeAndBts(plm_blk_idx, plm_blk_data);
  return plmp;
}

/**
* @brief Sets the Draygon turret facing down right PLM blocks to a spike
* @brief This is used by an unused PLM, so the function is not used
* @param plmp The pointer to the PLM instruction
* @param plm_idx The index of the PLM
* @return uint8* The pointer to the next PLM instruction
*/
const uint8 *PlmInstr_DamageDraygonTurretFacingDownRight(const uint8 *plmp, uint16 plm_idx) {  // 0x84DBB8
  SetPlmVarPtr(plm_idx, 1);
  uint16 plm_blk_idx = plm_block_indices[plm_idx >> 1];
  uint16 plm_blk_data = PLM_TYPE_BTS(kBlockType_A_SpikeBlock, kBtsType_Spike_3_Solid_DraygonBrokenTurret);
  WriteLevelDataBlockTypeAndBts(plm_blk_idx, plm_blk_data);
  WriteLevelDataBlockTypeAndBts(plm_blk_idx + 2, plm_blk_data);

  plm_blk_idx += room_width_in_blocks * 2;
  WriteLevelDataBlockTypeAndBts(plm_blk_idx, plm_blk_data);
  plm_blk_data = PLM_TYPE_BTS(kBlockType_0_Air, 0);
  WriteLevelDataBlockTypeAndBts(plm_blk_idx + 2, plm_blk_data);
  return plmp;
}

/**
* @brief Sets the Draygon turret facing up right PLM blocks to a spike
* @brief This is used by an unused PLM, so the function is not used
* @param plmp The pointer to the PLM instruction
* @param plm_idx The index of the PLM
* @return uint8* The pointer to the next PLM instruction
*/
const uint8 *PlmInstr_DamageDraygonTurretFacingUpRight(const uint8 *plmp, uint16 plm_idx) {  // 0x84DBF7
  SetPlmVarPtr(plm_idx, 1);
  uint16 plm_blk_idx = plm_block_indices[plm_idx >> 1];
  uint16 plm_blk_data = PLM_TYPE_BTS(kBlockType_A_SpikeBlock, kBtsType_Spike_3_Solid_DraygonBrokenTurret);
  WriteLevelDataBlockTypeAndBts(plm_blk_idx, plm_blk_data);
  plm_blk_data = PLM_TYPE_BTS(kBlockType_0_Air, 0);
  WriteLevelDataBlockTypeAndBts(plm_blk_idx + 2, plm_blk_data);

  plm_blk_idx += room_width_in_blocks * 2;
  plm_blk_data = PLM_TYPE_BTS(kBlockType_A_SpikeBlock, kBtsType_Spike_3_Solid_DraygonBrokenTurret);
  WriteLevelDataBlockTypeAndBts(plm_blk_idx, plm_blk_data);
  WriteLevelDataBlockTypeAndBts(plm_blk_idx + 2, plm_blk_data);
  return plmp;
}

/**
* @brief Sets the Draygon turret facing left PLM blocks to a spike
* @param plmp The pointer to the PLM instruction
* @param plm_idx The index of the PLM
* @return uint8* The pointer to the next PLM instruction
*/
const uint8 *PlmInstr_DamageDraygonTurret2(const uint8 *plmp, uint16 plm_idx) {  // 0x84DC36
  SetPlmVarPtr(plm_idx, 1);
  uint16 plm_blk_idx = plm_block_indices[plm_idx >> 1];
  uint16 plm_blk_data = PLM_TYPE_BTS(kBlockType_A_SpikeBlock, kBtsType_Spike_3_Solid_DraygonBrokenTurret);
  WriteLevelDataBlockTypeAndBts(plm_blk_idx, plm_blk_data);

  plm_blk_idx += room_width_in_blocks * 2;
  WriteLevelDataBlockTypeAndBts(plm_blk_idx, plm_blk_data);
  return plmp;
}

/**
* @brief Sets the Draygon turret facing down left PLM blocks to a spike
* @brief This is used by an unused PLM, so the function is not used
* @param plmp The pointer to the PLM instruction
* @param plm_idx The index of the PLM
* @return uint8* The pointer to the next PLM instruction
*/
const uint8 *PlmInstr_DamageDraygonTurretFacingDownLeft(const uint8 *plmp, uint16 plm_idx) {  // 0x84DC60
  SetPlmVarPtr(plm_idx, 1);
  uint16 plm_blk_idx = plm_block_indices[plm_idx >> 1];
  uint16 plm_blk_data = PLM_TYPE_BTS(kBlockType_A_SpikeBlock, kBtsType_Spike_3_Solid_DraygonBrokenTurret);
  WriteLevelDataBlockTypeAndBts(plm_blk_idx, plm_blk_data);
  WriteLevelDataBlockTypeAndBts(plm_blk_idx - 2, plm_blk_data);

  plm_blk_idx += room_width_in_blocks * 2;
  WriteLevelDataBlockTypeAndBts(plm_blk_idx, plm_blk_data);
  plm_blk_data = PLM_TYPE_BTS(kBlockType_0_Air, 0);
  WriteLevelDataBlockTypeAndBts(plm_blk_idx - 2, plm_blk_data);
  return plmp;
}

/**
* @brief Sets the Draygon turret facing up left PLM blocks to a spike
* @brief This is used by an unused PLM, so the function is not used
* @param plmp The pointer to the PLM instruction
* @param plm_idx The index of the PLM
* @return uint8* The pointer to the next PLM instruction
*/
const uint8 *PlmInstr_DamageDraygonTurretFacingUpLeft(const uint8 *plmp, uint16 plm_idx) {  // 0x84DC9F
  SetPlmVarPtr(plm_idx, 1);
  uint16 plm_blk_idx = plm_block_indices[plm_idx >> 1];
  uint16 plm_blk_data = PLM_TYPE_BTS(kBlockType_A_SpikeBlock, kBtsType_Spike_3_Solid_DraygonBrokenTurret);
  WriteLevelDataBlockTypeAndBts(plm_blk_idx, plm_blk_data);
  plm_blk_data = PLM_TYPE_BTS(kBlockType_0_Air, 0);
  WriteLevelDataBlockTypeAndBts(plm_blk_idx - 2, plm_blk_data);

  plm_blk_idx += room_width_in_blocks * 2;
  plm_blk_data = PLM_TYPE_BTS(kBlockType_A_SpikeBlock, kBtsType_Spike_3_Solid_DraygonBrokenTurret);
  WriteLevelDataBlockTypeAndBts(plm_blk_idx, plm_blk_data);
  WriteLevelDataBlockTypeAndBts(plm_blk_idx - 2, plm_blk_data);
  return plmp;
}

/**
* @brief Sets the Draygon cannon facing right PLM blocks to a shot triggered block
* @param plm_idx The index of the PLM
* @return 0
*/
uint8 PlmSetup_DraygonCannonFacingRight(uint16 plm_idx) {  // 0x84DE94
  int idx = plm_idx >> 1;
  plm_variable[idx] = plm_room_arguments[idx];
  plm_room_arguments[idx] = 0;
  uint16 plm_blk_idx = plm_block_indices[idx];
  uint16 plm_blk_data = PLM_TYPE_BTS(kBlockType_C_ShootableBlock, kBtsType_Shootable_44_GenericShotTrigger);
  WriteLevelDataBlockTypeAndBts(plm_blk_idx, plm_blk_data);
  plm_blk_idx += room_width_in_blocks * 2;
  plm_blk_data = PLM_TYPE_BTS(kBlockType_D_VertExtension, (uint8)-1);
  WriteLevelDataBlockTypeAndBts(plm_blk_idx, plm_blk_data);
  return 0;
}

/**
* @brief Sets the Draygon cannon facing down/up right PLM blocks to a shot triggered block
* @brief This is used by an unused PLM, so the function is not used
* @param plm_idx The index of the PLM
* @return 0
*/
uint8 PlmSetup_DraygonCannonFacingDiagonalRight(uint16 plm_idx) {  // 0x84DEB9
  int idx = plm_idx >> 1;
  plm_variable[idx] = plm_room_arguments[idx];
  plm_room_arguments[idx] = 0;
  uint16 plm_blk_idx = plm_block_indices[idx];
  uint16 plm_blk_data = PLM_TYPE_BTS(kBlockType_C_ShootableBlock, kBtsType_Shootable_44_GenericShotTrigger);
  WriteLevelDataBlockTypeAndBts(plm_blk_idx, plm_blk_data);
  plm_blk_data = PLM_TYPE_BTS(kBlockType_5_HorizExtension, (uint8)-1);
  WriteLevelDataBlockTypeAndBts(plm_blk_idx + 2, plm_blk_data);

  plm_blk_idx += room_width_in_blocks * 2;
  plm_blk_data = PLM_TYPE_BTS(kBlockType_D_VertExtension, (uint8)-1);
  WriteLevelDataBlockTypeAndBts(plm_blk_idx, plm_blk_data);
  WriteLevelDataBlockTypeAndBts(plm_blk_idx + 2, plm_blk_data);
  return 0;
}

/**
* @brief Sets the Draygon cannon facing left PLM blocks to a shot triggered block
* @param plm_idx The index of the PLM
* @return 0
*/
uint8 PlmSetup_DraygonCannonFacingLeft(uint16 plm_idx) {  // 0x84DEF0
  int idx = plm_idx >> 1;
  plm_variable[idx] = plm_room_arguments[idx];
  plm_room_arguments[idx] = 0;
  uint16 plm_blk_idx = plm_block_indices[idx];
  uint16 plm_blk_data = PLM_TYPE_BTS(kBlockType_C_ShootableBlock, kBtsType_Shootable_44_GenericShotTrigger);
  WriteLevelDataBlockTypeAndBts(plm_blk_idx, plm_blk_data);
  plm_blk_idx += room_width_in_blocks * 2;
  plm_blk_data = PLM_TYPE_BTS(kBlockType_D_VertExtension, (uint8)-1);
  WriteLevelDataBlockTypeAndBts(plm_blk_idx, plm_blk_data);
  return 0;
}

/**
* @brief Sets the Draygon cannon facing down/up left PLM blocks to a shot triggered block
* @brief This is used by an unused PLM, so the function is not used
* @param plm_idx The index of the PLM
* @return 0
*/
uint8 PlmSetup_DraygonCannonFacingDiagonalLeft(uint16 plm_idx) {  // 0x84DF15
  int idx = plm_idx >> 1;
  plm_variable[idx] = plm_room_arguments[idx];
  plm_room_arguments[idx] = 0;
  uint16 plm_blk_idx = plm_block_indices[idx];
  uint16 plm_blk_data = PLM_TYPE_BTS(kBlockType_C_ShootableBlock, kBtsType_Shootable_44_GenericShotTrigger);
  WriteLevelDataBlockTypeAndBts(plm_blk_idx, plm_blk_data);
  plm_blk_data = PLM_TYPE_BTS(kBlockType_5_HorizExtension, 1);
  WriteLevelDataBlockTypeAndBts(plm_blk_idx - 2, plm_blk_data);

  plm_blk_idx += room_width_in_blocks * 2;
  plm_blk_data = PLM_TYPE_BTS(kBlockType_D_VertExtension, (uint8)-1);
  WriteLevelDataBlockTypeAndBts(plm_blk_idx, plm_blk_data);
  WriteLevelDataBlockTypeAndBts(plm_blk_idx - 2, plm_blk_data);
  return 0;
}

/**
* @brief Sets the Draygon cannon damaged flag to the room argument
* @param plm_idx The index of the PLM
* @return 0
*/
uint8 PlmSetup_DraygonCannon(uint16 plm_idx) {  // 0x84DF4C
  int idx = plm_idx >> 1;
  // plm turret damaged flag address
  plm_variable[idx] = plm_room_arguments[idx];
  plm_room_arguments[idx] = 3;
  return 0;
}

/**
* @brief Goes to the instruction stored in the link register if the PLM is triggered
* @param plm_idx The index of the PLM
*/
void PlmPreInstr_GotoLinkIfTriggered(uint16 plm_idx) {  // 0x84DF89
  int idx = plm_idx >> 1;
  if (LOBYTE(plm_timers[idx]) == 0xFF) {
    plm_pre_instrs[idx] = FUNC16(PlmPreInstr_nullsub_301);
    plm_instr_list_ptrs[idx] = plm_instruction_list_link_reg[idx];
    plm_instruction_timer[idx] = 1;
  }
}

/**
* @brief Activates the PLM if the PLM is triggered
* @param plm_idx The index of the PLM
*/
void PlmPreInstr_WakeIfTriggered(uint16 plm_idx) {  // 0x84DFE6
  int idx = plm_idx >> 1;
  uint16 v2 = plm_timers[idx];
  // projectile type is never stored in plm_timers, so the first check is always true
  if (v2 != kProjectileType_PowerBomb && LOBYTE(v2) == 0xFF) {
    plm_timers[idx] = 0;
    plm_instr_list_ptrs[idx] += 2;
    plm_instruction_timer[idx] = 1;
  }
}

/**
* @brief Draws the PLM item frame and sets the delay to 4 frames
* @param plmp The pointer to the PLM instruction
* @param plm_idx The index of the PLM
* @return 0, indicating the PLM is done processing
*/
const uint8 *PlmInstr_DrawItemFrame_Common(const uint8 *plmp, uint16 plm_idx) {  // 0x84E07F
  int idx = plm_idx >> 1;
  plm_instruction_timer[idx] = 4;
  plm_instr_list_ptrs[idx] = plmp - RomBankBase(0x84);
  ProcessPlmDrawInstruction(plm_idx);
  CalculatePlmBlockCoords(plm_id);
  DrawPlm(plm_id);
  return 0;
}

/**
* @brief Draws the PLM item frame 0
* @param plmp The pointer to the PLM instruction
* @param plm_idx The index of the PLM
* @return 0, indicating the PLM is done processing
*/
const uint8 *PlmInstr_DrawItemFrame0(const uint8 *plmp, uint16 plm_idx) {  // 0x84E04F
  plm_instruction_draw_ptr[plm_idx >> 1] = kDrawItemFrame0DrawInstrs[plm_variables[plm_idx >> 1] >> 1];
  return PlmInstr_DrawItemFrame_Common(plmp, plm_idx);
}

/**
* @brief Draws the PLM item frame 1
* @param plmp The pointer to the PLM instruction
* @param plm_idx The index of the PLM
* @return 0, indicating the PLM is done processing
*/
const uint8 *PlmInstr_DrawItemFrame1(const uint8 *plmp, uint16 plm_idx) {  // 0x84E067
  plm_instruction_draw_ptr[plm_idx >> 1] = kDrawItemFrame1DrawInstrs[plm_variables[plm_idx >> 1] >> 1];
  return PlmInstr_DrawItemFrame_Common(plmp, plm_idx);
}

/**
* @brief Clears the beam flame counter
* @param plmp The pointer to the PLM instruction
* @param plm_idx The index of the PLM
* @return uint8* The pointer to the next PLM instruction
*/
const uint8 *PlmInstr_ClearChargeBeamCounter(const uint8 *plmp, uint16 plm_idx) {  // 0x84E29D
  flare_counter = 0;
  return plmp;
}

/**
* @brief Sets the velocity for the lava to move up to 32 pixels per frame
* @param plmp The pointer to the PLM instruction
* @param plm_idx The index of the PLM
* @return uint8* The pointer to the next PLM instruction
*/
const uint8 *PlmInstr_MoveFxYUp(const uint8 *plmp, uint16 plm_idx) {  // 0x84E63B
  fx_y_vel = -32;
  return plmp;
}

/**
* @brief Sets the PLM item gfx index to energy tank and sets up the energy tank PLM
* @param plm_idx The index of the PLM
* @return 0
*/
uint8 PlmSetup_EnergyTank(uint16 plm_idx) {  // 0x84EE4D
  return SetPlmGfxAndSetupAbility(plm_idx, 8);
}

/**
* @brief Sets the PLM item gfx index to missile tank and sets up the missile tank PLM
* @param plm_idx The index of the PLM
* @return 0
*/
uint8 PlmSetup_MissileTank(uint16 plm_idx) {  // 0x84EE52
  return SetPlmGfxAndSetupAbility(plm_idx, 0xA);
}

/**
* @brief Sets the PLM item gfx index to super missile tank and sets up the super missile tank PLM
* @param plm_idx The index of the PLM
* @return 0
*/
uint8 PlmSetup_SuperMissileTank(uint16 plm_idx) {  // 0x84EE57
  return SetPlmGfxAndSetupAbility(plm_idx, 0xC);
}

/**
* @brief Sets the PLM item gfx index to power bomb tank and sets up the power bomb tank PLM
* @param plm_idx The index of the PLM
* @return 0
*/
uint8 PlmSetup_PowerBombTank(uint16 plm_idx) {  // 0x84EE5C
  return SetPlmGfxAndSetupAbility(plm_idx, 0xE);
}

/**
* @brief Sets the PLM item gfx index and sets up the ability tank PLM
* @param plm_idx The index of the PLM
* @param plm_item_gfx_idx The index of the PLM item gfx
* @return 0
*/
uint8 SetPlmGfxAndSetupAbility(uint16 plm_idx, uint16 plm_item_gfx_idx) {  // 0x84EE5F
  // plm item gfx index
  plm_variables[plm_idx >> 1] = plm_item_gfx_idx;
  return PlmSetup_AbilityTank(plm_idx);
}

/**
* @brief Sets the PLM to a tank ability block and increments the number of items loaded
* @param plm_idx The index of the PLM
* @return 0
*/
uint8 PlmSetup_AbilityTank(uint16 plm_idx) {  // 0x84EE64
  uint16 plm_blk_data = PLM_TYPE_BTS(kBlockType_0_Air, kBtsType_Special_45_ItemCollDetection);
  WriteLevelDataBlockTypeAndBts(plm_block_indices[plm_idx >> 1], plm_blk_data);
  ++global_number_of_items_loaded_ctr;
  return 0;
}

/**
* @brief Sets the PLM item gfx index to energy tank and sets up the shootable energy tank PLM
* @param plm_idx The index of the PLM
* @return 0
*/
uint8 PlmSetup_EnergyTankShotBlock(uint16 plm_idx) {  // 0x84EE77
  return SetPlmGfxAndSetupAbilityShotBlock(plm_idx, 8);
}

/**
* @brief Sets the PLM item gfx index to missile tank and sets up the shootable missile tank PLM
* @param plm_idx The index of the PLM
* @return 0
*/
uint8 PlmSetup_MissileTankShotBlock(uint16 plm_idx) {  // 0x84EE7C
  return SetPlmGfxAndSetupAbilityShotBlock(plm_idx, 0xA);
}

/**
* @brief Sets the PLM item gfx index to super missile tank and sets up the shootable super missile tank PLM
* @param plm_idx The index of the PLM
* @return 0
*/
uint8 PlmSetup_SuperMissileTankShotBlock(uint16 plm_idx) {  // 0x84EE81
  return SetPlmGfxAndSetupAbilityShotBlock(plm_idx, 0xC);
}

/**
* @brief Sets the PLM item gfx index to power bomb tank and sets up the shootable power bomb tank PLM
* @param plm_idx The index of the PLM
* @return 0
*/
uint8 PlmSetup_PowerBombTankShotBlock(uint16 plm_idx) {  // 0x84EE86
  return SetPlmGfxAndSetupAbilityShotBlock(plm_idx, 0xE);
}

/**
* @brief Sets the PLM item gfx index and sets up the ability tank block that is shot triggered
* @param plm_idx The index of the PLM
* @param plm_item_gfx_idx The index of the PLM item gfx
* @return 0
*/
uint8 SetPlmGfxAndSetupAbilityShotBlock(uint16 plm_idx, uint16 plm_item_gfx_idx) {  // 0x84EE89
  // plm item gfx index
  plm_variables[plm_idx >> 1] = plm_item_gfx_idx;
  return PlmSetup_AbilityTankShotBlock(plm_idx);
}

/**
* @brief Sets the PLM to a tank ability block that is shot triggered and increments the number of items loaded
* @param plm_idx The index of the PLM
* @return 0
*/
uint8 PlmSetup_AbilityTankShotBlock(uint16 plm_idx) {  // 0x84EE8E
  int idx = plm_idx >> 1;
  uint16 plm_blk_idx = plm_block_indices[idx];
  uint16 plm_blk_data = PLM_TYPE_BTS(kBlockType_C_ShootableBlock, kBtsType_Shootable_45_ItemTrigger);
  WriteLevelDataBlockTypeAndBts(plm_blk_idx, plm_blk_data);
  // plm respawn block
  plm_variable[idx] = level_data[plm_blk_idx >> 1];
  ++global_number_of_items_loaded_ctr;
  return 0;
}

/**
* @brief Sets the PLM to triggered
* @param plm_idx The index of the PLM
* @return 0
*/
uint8 PlmSetup_ItemCollisionDetection(uint16 plm_idx) {  // 0x84EEAB
  int blk_idx;
  int idx = plm_idx >> 1;
  if (time_is_frozen_flag) {
    plm_header_ptr[idx] = 0;
  }
  else {
    uint16 plm_blk_idx = plm_block_indices[idx];
    plm_block_indices[idx] = 0;
    for (blk_idx = 78; blk_idx >= 0; blk_idx -= 2) {
      if (plm_blk_idx == plm_block_indices[blk_idx >> 1])
        break;
    }
    plm_timers[blk_idx >> 1] = 0xFF;  // trigger plm
  }
  return 0;
}


uint8 CallPlmHeaderFunc(uint32 ea, uint16 plm_idx) {
  switch (ea) {
  case fnnullsub_67:
  case fnnullsub_290:
  case fnnullsub_68:
  case fnnullsub_84BAFA:
  case fnnullsub_71:
  case fnnullsub_72:
  case fnnullsub_69: return 0;
  case fnPlmSetup_CrumbleBotwoonWall: return PlmSetup_CrumbleBotwoonWall(plm_idx);
  case fnPlmSetup_SetupWreckedShipEntrance: return PlmSetup_SetupWreckedShipEntrance(plm_idx);
  case fnPlmSetup_BTS_Brinstar_0x80_Floorplant: return PlmSetup_BTS_Brinstar_0x80_Floorplant(plm_idx);
  case fnPlmSetup_BTS_Brinstar_0x81_Ceilingplant: return PlmSetup_BTS_Brinstar_0x81_Ceilingplant(plm_idx);
  case fnPlmSetup_B6D3_MapStation: return PlmSetup_B6D3_MapStation(plm_idx);
  case fnPlmSetup_Bts47_MapStationRightAccess: return PlmSetup_Bts47_MapStationRightAccess(plm_idx);
  case fnPlmSetup_Bts4_MapStationLeftAccess: return PlmSetup_Bts4_MapStationLeftAccess(plm_idx);
  case fnPlmSetup_PlmB6DF_EnergyStation: return PlmSetup_PlmB6DF_EnergyStation(plm_idx);
  case fnPlmSetup_PlmB6EB_MissileStation: return PlmSetup_PlmB6EB_MissileStation(plm_idx);
  case fnPlmSetup_B6E3_EnergyStationRightAccess: return PlmSetup_B6E3_EnergyStationRightAccess(plm_idx);
  case fnPlmSetup_B6E7_EnergyStationLeftAccess: return PlmSetup_B6E7_EnergyStationLeftAccess(plm_idx);
  case fnPlmSetup_B6EF_MissileStationRightAccess: return PlmSetup_B6EF_MissileStationRightAccess(plm_idx);
  case fnPlmSetup_B6F3_MissileStationLeftAccess: return PlmSetup_B6F3_MissileStationLeftAccess(plm_idx);
  case fnPlmSetup_B638_Rightwards_Extension: return PlmSetup_B638_Rightwards_Extension(plm_idx);
  case fnPlmSetup_B63F_Leftwards_Extension: return PlmSetup_B63F_Leftwards_Extension(plm_idx);
  case fnPlmSetup_B643_Downwards_Extension: return PlmSetup_B643_Downwards_Extension(plm_idx);
  case fnPlmSetup_B647_Upwards_Extension: return PlmSetup_B647_Upwards_Extension(plm_idx);
  case fnPlmSetup_B703_ScrollPLM: return PlmSetup_B703_ScrollPLM(plm_idx);
  case fnPlmSetup_B707_SolidScrollPLM: return PlmSetup_B707_SolidScrollPLM(plm_idx);
  case fnPlmSetup_B6FF_ScrollBlockTouch: return PlmSetup_B6FF_ScrollBlockTouch(plm_idx);
  case fnPlmSetup_DeactivatePlm: return PlmSetup_DeactivatePlm(plm_idx);
  case fnPlmSetup_ReturnCarryClear: return PlmSetup_ReturnCarryClear(plm_idx);
  case fnPlmSetup_ReturnCarrySet: return PlmSetup_ReturnCarrySet(plm_idx);
  case fnPlmSetup_D094_EnemyBreakableBlock: return PlmSetup_D094_EnemyBreakableBlock(plm_idx);
  case fnPlmSetup_B743_Unused: return PlmSetup_B743_Unused(plm_idx);
  case fnPlmSetup_B70F_IcePhysics: return PlmSetup_B70F_IcePhysics(plm_idx);
  case fnPlmSetup_InsideReaction_QuicksandSurface: return PlmSetup_InsideReaction_QuicksandSurface(plm_idx);
  case fnPlmSetup_B71F_SubmergingQuicksand: return PlmSetup_B71F_SubmergingQuicksand(plm_idx);
  case fnPlmSetup_B723_SandfallsSlow: return PlmSetup_B723_SandfallsSlow(plm_idx);
  case fnPlmSetup_B727_SandFallsFast: return PlmSetup_B727_SandFallsFast(plm_idx);
  case fnPlmSetup_CollisionReaction_QuicksandSurface: return PlmSetup_CollisionReaction_QuicksandSurface(plm_idx);
  case fnPlmSetup_B737_SubmergingQuicksand: return PlmSetup_B737_SubmergingQuicksand(plm_idx);
  case fnPlmSetup_B73B_B73F_SandFalls: return PlmSetup_B73B_B73F_SandFalls(plm_idx);
  case fnPlmSetup_B763_ClearShitroidInvisibleWall: return PlmSetup_B763_ClearShitroidInvisibleWall(plm_idx);
  case fnPlmSetup_B767_CreateShitroidInvisibleWall: return PlmSetup_B767_CreateShitroidInvisibleWall(plm_idx);
  case fnPlmSetup_B76B_SaveStationTrigger: return PlmSetup_B76B_SaveStationTrigger(plm_idx);
  case fnPlmSetup_B76F_SaveStation: return PlmSetup_B76F_SaveStation(plm_idx);
  case fnPlmSetup_MotherBrainRoomEscapeDoor: return PlmSetup_MotherBrainRoomEscapeDoor(plm_idx);
  case fnPlmSetup_B7EB_EnableSoundsIn32Frames: return PlmSetup_B7EB_EnableSoundsIn32Frames(plm_idx);
  case fnPlmSetup_SpeedBoosterEscape: return PlmSetup_SpeedBoosterEscape(plm_idx);
  case fnPlmSetup_ShaktoolsRoom: return PlmSetup_ShaktoolsRoom(plm_idx);
  case fnPlmSetup_B974: return PlmSetup_B974(plm_idx);
  case fnPlmSetup_B9C1_CrittersEscapeBlock: return PlmSetup_B9C1_CrittersEscapeBlock(plm_idx);
  case fnPlmSetup_B9ED_CrittersEscapeBlock: return PlmSetup_B9ED_CrittersEscapeBlock(plm_idx);
  case fnPlmSetup_B9F1_TurnCeresDoorSolid: return PlmSetup_B9F1_TurnCeresDoorSolid(plm_idx);
  case fnPlmSetup_BB30_CrateriaMainstreetEscape: return PlmSetup_BB30_CrateriaMainstreetEscape(plm_idx);
  case fnPlmSetup_C806_LeftGreenGateTrigger: return PlmSetup_C806_LeftGreenGateTrigger(plm_idx);
  case fnPlmSetup_C80A_RightGreenGateTrigger: return PlmSetup_C80A_RightGreenGateTrigger(plm_idx);
  case fnPlmSetup_C80E_LeftRedGateTrigger: return PlmSetup_C80E_LeftRedGateTrigger(plm_idx);
  case fnPlmSetup_C812_RightRedGateTrigger: return PlmSetup_C812_RightRedGateTrigger(plm_idx);
  case fnPlmSetup_C81E_LeftYellowGateTrigger: return PlmSetup_C81E_LeftYellowGateTrigger(plm_idx);
  case fnPlmSetup_C822_RightYellowGateTrigger: return PlmSetup_C822_RightYellowGateTrigger(plm_idx);
  case fnPlmSetup_C816_LeftBlueGateTrigger: return PlmSetup_C816_LeftBlueGateTrigger(plm_idx);
  case fnPlmSetup_C81A_RightBlueGateTrigger: return PlmSetup_C81A_RightBlueGateTrigger(plm_idx);
  case fnPlmSetup_C82A_DownwardsClosedGate: return PlmSetup_C82A_DownwardsClosedGate(plm_idx);
  case fnPlmSetup_C832_UpwardsClosedGate: return PlmSetup_C832_UpwardsClosedGate(plm_idx);
  case fnPlmSetup_C826_DownwardsOpenGate: return PlmSetup_C826_DownwardsOpenGate(plm_idx);
  case fnPlmSetup_C82E_UpwardsOpenGate: return PlmSetup_C82E_UpwardsOpenGate(plm_idx);
  case fnPlmSetup_C836_DownwardsGateShootblock: return PlmSetup_C836_DownwardsGateShootblock(plm_idx);
  case fnPlmSetup_C73A_UpwardsGateShootblock: return PlmSetup_C73A_UpwardsGateShootblock(plm_idx);
  case fnPlmSetup_GreyDoor: return PlmSetup_GreyDoor(plm_idx);
  case fnPlmSetup_Door_Colored: return PlmSetup_Door_Colored(plm_idx);
  case fnPlmSetup_Door_Blue: return PlmSetup_Door_Blue(plm_idx);
  case fnPlmSetup_C7E2_GenericShotTrigger: return PlmSetup_C7E2_GenericShotTrigger(plm_idx);
  case fnPlmSetup_D028_D02C_Unused: return PlmSetup_D028_D02C_Unused(plm_idx);
  case fnPlmSetup_RespawningSpeedBoostBlock: return PlmSetup_RespawningSpeedBoostBlock(plm_idx);
  case fnPlmSetup_RespawningCrumbleBlock: return PlmSetup_RespawningCrumbleBlock(plm_idx);
  case fnPlmSetup_RespawningShotBlock: return PlmSetup_RespawningShotBlock(plm_idx);
  case fnPlmSetup_RespawningBombBlock: return PlmSetup_RespawningBombBlock(plm_idx);
  case fnPlmSetup_RespawningBombBlock2: return PlmSetup_RespawningBombBlock2(plm_idx);
  case fnPlmSetup_RespawningPowerBombBlock: return PlmSetup_RespawningPowerBombBlock(plm_idx);
  case fnPlmSetup_SuperMissileBlockRespawning: return PlmSetup_SuperMissileBlockRespawning(plm_idx);
  case fnPlmSetup_CrumbleBlock: return PlmSetup_CrumbleBlock(plm_idx);
  case fnPlmSetup_BreakableGrappleBlock: return PlmSetup_BreakableGrappleBlock(plm_idx);
  case fnPlmSetup_D0D8_SetVFlag: return PlmSetup_D0D8_SetVFlag(plm_idx);
  case fnPlmSetup_D0D8_ClearVflag: return PlmSetup_D0D8_ClearVflag(plm_idx);
  case fnPlmSetup_D0E8_GiveSamusDamage: return PlmSetup_D0E8_GiveSamusDamage(plm_idx);
  case fnPlmSetup_D113_LowerNorfairChozoRoomPlug: return PlmSetup_D113_LowerNorfairChozoRoomPlug(plm_idx);
  case fnPlmSetup_D127: return PlmSetup_D127(plm_idx);
  case fnPlmSetup_D138: return PlmSetup_D138(plm_idx);
  case fnPlmSetup_D6DA_LowerNorfairChozoHandTrigger: return PlmSetup_D6DA_LowerNorfairChozoHandTrigger(plm_idx);
  case fnPlmSetup_MotherBrainGlass: return PlmSetup_MotherBrainGlass(plm_idx);
  case fnPlmSetup_DeletePlmIfAreaTorizoDead: return PlmSetup_DeletePlmIfAreaTorizoDead(plm_idx);
  case fnPlmSetup_MakeBllockChozoHandTrigger: return PlmSetup_MakeBllockChozoHandTrigger(plm_idx);
  case fnPlmSetup_D6F2_WreckedShipChozoHandTrigger: return PlmSetup_D6F2_WreckedShipChozoHandTrigger(plm_idx);
  case fnPlmSetup_D700_MakePlmAirBlock_Unused: return PlmSetup_D700_MakePlmAirBlock_Unused(plm_idx);
  case fnPlmSetup_D704_AlteranateLowerNorfairChozoHand_Unused: return PlmSetup_D704_AlteranateLowerNorfairChozoHand_Unused(plm_idx);
  case fnPlmSetup_D708_LowerNorfairChozoBlockUnused: return PlmSetup_D708_LowerNorfairChozoBlockUnused(plm_idx);
  case fnPlmSetup_D70C_NoobTube: return PlmSetup_D70C_NoobTube(plm_idx);
  case fnPlmSetup_EyeDoorEye: return PlmSetup_EyeDoorEye(plm_idx);
  case fnPlmSetup_EyeDoor: return PlmSetup_EyeDoor(plm_idx);
  case fnPlmSetup_SetMetroidRequiredClearState: return PlmSetup_SetMetroidRequiredClearState(plm_idx);
  case fnPlmSetup_DraygonCannonFacingRight: return PlmSetup_DraygonCannonFacingRight(plm_idx);
  case fnPlmSetup_DraygonCannonFacingDiagonalRight: return PlmSetup_DraygonCannonFacingDiagonalRight(plm_idx);
  case fnPlmSetup_DraygonCannonFacingLeft: return PlmSetup_DraygonCannonFacingLeft(plm_idx);
  case fnPlmSetup_DraygonCannonFacingDiagonalLeft: return PlmSetup_DraygonCannonFacingDiagonalLeft(plm_idx);
  case fnPlmSetup_DraygonCannon: return PlmSetup_DraygonCannon(plm_idx);
  case fnPlmSetup_EnergyTank: return PlmSetup_EnergyTank(plm_idx);
  case fnPlmSetup_MissileTank: return PlmSetup_MissileTank(plm_idx);
  case fnPlmSetup_SuperMissileTank: return PlmSetup_SuperMissileTank(plm_idx);
  case fnPlmSetup_PowerBombTank: return PlmSetup_PowerBombTank(plm_idx);
  case fnPlmSetup_AbilityTank: return PlmSetup_AbilityTank(plm_idx);
  case fnPlmSetup_EnergyTankShotBlock: return PlmSetup_EnergyTankShotBlock(plm_idx);
  case fnPlmSetup_MissileTankShotBlock: return PlmSetup_MissileTankShotBlock(plm_idx);
  case fnPlmSetup_SuperMissileTankShotBlock: return PlmSetup_SuperMissileTankShotBlock(plm_idx);
  case fnPlmSetup_PowerBombTankShotBlock: return PlmSetup_PowerBombTankShotBlock(plm_idx);
  case fnPlmSetup_AbilityTankShotBlock: return PlmSetup_AbilityTankShotBlock(plm_idx);
  case fnPlmSetup_ItemCollisionDetection: return PlmSetup_ItemCollisionDetection(plm_idx);
  default: return Unreachable();
  }
}

void CallPlmPreInstr(uint32 ea, uint16 plm_idx) {
  switch (ea) {
  case fnPlmPreInstr_nullsub_60: return;
  case fnPlmPreInstr_nullsub_301: return;
  case fnPlmPreInstr_Empty: return;
  case fnPlmPreInstr_Empty2: return;
  case fnPlmPreInstr_Empty3: return;
  case fnPlmPreInstr_Empty4: return;
  case fnPlmPreInstr_Empty5: return;
  case fnnullsub_351: return;
  case fnnullsub_84BAFA: return;
  case fnPlmSetup_BTS_Brinstar_0x80_Floorplant: PlmSetup_BTS_Brinstar_0x80_Floorplant(plm_idx); return;
  case fnPlmSetup_BTS_Brinstar_0x81_Ceilingplant: PlmSetup_BTS_Brinstar_0x81_Ceilingplant(plm_idx); return;
  case fnPlmPreInstr_B7EB_DecTimerEnableSoundsDeletePlm: PlmPreInstr_B7EB_DecTimerEnableSoundsDeletePlm(plm_idx); return;
  case fnPlmPreInstr_WakeAndLavaIfBoosterCollected: PlmPreInstr_WakeAndLavaIfBoosterCollected(plm_idx); return;
  case fnPlmPreInstr_WakePLMAndStartFxMotionSamusFarLeft: PlmPreInstr_WakePLMAndStartFxMotionSamusFarLeft(plm_idx); return;
  case fnPlmPreInstr_AdvanceLavaSamusMovesLeft: PlmPreInstr_AdvanceLavaSamusMovesLeft(plm_idx); return;
  case fnPlmPreInstr_ShaktoolsRoom: PlmPreInstr_ShaktoolsRoom(plm_idx); return;
  case fnPlmPreInstr_OldTourianEscapeShaftEscape: PlmPreInstr_OldTourianEscapeShaftEscape(plm_idx); return;
  case fnPlmPreInstr_EscapeRoomBeforeOldTourianEscapeShaft: PlmPreInstr_EscapeRoomBeforeOldTourianEscapeShaft(plm_idx); return;
  case fnPlmPreInstr_WakePlmIfTriggered: PlmPreInstr_WakePlmIfTriggered(plm_idx); return;
  case fnPlmPreInstr_WakePlmIfTriggeredOrSamusBelowPlm: PlmPreInstr_WakePlmIfTriggeredOrSamusBelowPlm(plm_idx); return;
  case fnPlmPreInstr_WakePlmIfTriggeredOrSamusAbovePlm: PlmPreInstr_WakePlmIfTriggeredOrSamusAbovePlm(plm_idx); return;
  case fnPlmPreInstr_DeletePlmAndSpawnTriggerIfBlockDestroyed: PlmPreInstr_DeletePlmAndSpawnTriggerIfBlockDestroyed(plm_idx); return;
  case fnPlmPreInstr_IncrementRoomArgIfShotBySuperMissile: PlmPreInstr_IncrementRoomArgIfShotBySuperMissile(plm_idx); return;
  case fnPlmPreInstr_WakePlmIfSamusHasBombs: PlmPreInstr_WakePlmIfSamusHasBombs(plm_idx); return;
  case fnPlmPreInstr_WakePlmIfRoomArgumentDoorIsSet: PlmPreInstr_WakePlmIfRoomArgumentDoorIsSet(plm_idx); return;
  case fnPlmPreInstr_GotoLinkIfShotWithSuperMissile: PlmPreInstr_GotoLinkIfShotWithSuperMissile(plm_idx); return;
  case fnPlmPreInstr_GotoLinkIfTriggered: PlmPreInstr_GotoLinkIfTriggered(plm_idx); return;
  case fnPlmPreInstr_WakeIfTriggered: PlmPreInstr_WakeIfTriggered(plm_idx); return;
  case fnPlmPreInstr_GoToLinkInstrIfShot: PlmPreInstr_GoToLinkInstrIfShot(plm_idx); return;
  case fnPlmPreInstr_GoToLinkInstrIfShotWithPowerBomb: PlmPreInstr_GoToLinkInstrIfShotWithPowerBomb(plm_idx); return;
  case fnPlmPreInstr_GoToLinkInstrIfShotWithAnyMissile: PlmPreInstr_GoToLinkInstrIfShotWithAnyMissile(plm_idx); return;
  case fnPlmPreInstr_GoToLinkInstrIfShotWithSuperMissile: PlmPreInstr_GoToLinkInstrIfShotWithSuperMissile(plm_idx); return;
  case fnPlmPreInstr_GoToLinkInstruction: PlmPreInstr_GoToLinkInstruction(plm_idx); return;
  case fnPlmPreInstr_PlayDudSound: PlmPreInstr_PlayDudSound(plm_idx); return;
  case fnPlmPreInstr_GotoLinkIfAreaBossDead: PlmPreInstr_GotoLinkIfAreaBossDead(plm_idx); return;
  case fnPlmPreInstr_GotoLinkIfMiniBossDead: PlmPreInstr_GotoLinkIfMiniBossDead(plm_idx); return;
  case fnPlmPreInstr_GotoLinkIfTorizoDead: PlmPreInstr_GotoLinkIfTorizoDead(plm_idx); return;
  case fnPlmPreInstr_GotoLinkIfEnemyDeathQuotaOk: PlmPreInstr_GotoLinkIfEnemyDeathQuotaOk(plm_idx); return;
  case fnPlmPreInstr_GotoLinkIfTourianStatueFinishedProcessing: PlmPreInstr_GotoLinkIfTourianStatueFinishedProcessing(plm_idx); return;
  case fnPlmPreInstr_GotoLinkIfCrittersEscaped: PlmPreInstr_GotoLinkIfCrittersEscaped(plm_idx); return;
  case fnPlmPreInstr_PositionSamusAndInvincible: PlmPreInstr_PositionSamusAndInvincible(plm_idx); return;
  case fnPlmPreInstr_WakeOnKeyPress: PlmPreInstr_WakeOnKeyPress(plm_idx); return;
  case fnnullsub_359: return;
  case fnnullsub_73:
  case fnnullsub_74:
  case fnnullsub_75:
  case fnnullsub_76:
  case fnnullsub_77:
  case fnnullsub_78:
  case fnnullsub_79:
  case fnnullsub_80:
  case fnnullsub_81:
  case fnlocret_848AE0: return;
  case fnPlmPreInstr_SetMetroidsClearState_Ev0x10: PlmPreInstr_SetMetroidsClearState_Ev0x10(plm_idx); return;
  case fnPlmPreInstr_SetMetroidsClearState_Ev0x11: PlmPreInstr_SetMetroidsClearState_Ev0x11(plm_idx); return;
  case fnPlmPreInstr_SetMetroidsClearState_Ev0x12: PlmPreInstr_SetMetroidsClearState_Ev0x12(plm_idx); return;
  case fnPlmPreInstr_SetMetroidsClearState_Ev0x13: PlmPreInstr_SetMetroidsClearState_Ev0x13(plm_idx); return;
  default: Unreachable();
  }
}

const uint8 *CallPlmInstr(uint32 ea, const uint8 *plmp, uint16 plm_idx) {
  switch (ea) {
  case fnPlmInstr_Sleep: return PlmInstr_Sleep(plmp, plm_idx);
  case fnPlmInstr_Delete: return PlmInstr_Delete(plmp, plm_idx);
  case fnPlmInstr_PreInstr: return PlmInstr_PreInstr(plmp, plm_idx);
  case fnPlmInstr_ClearPreInstr: return PlmInstr_ClearPreInstr(plmp, plm_idx);
  case fnPlmInstr_CallFunction: return PlmInstr_CallFunction(plmp, plm_idx);
  case fnPlmInstr_Goto: return PlmInstr_Goto(plmp, plm_idx);
  case fnPlmInstr_DecrementAndBranchNonzero: return PlmInstr_DecrementAndBranchNonzero(plmp, plm_idx);
  case fnPlmInstr_SetTimer: return PlmInstr_SetTimer(plmp, plm_idx);
  case fnPlmInstr_LoadItemPlmGfx: return PlmInstr_LoadItemPlmGfx(plmp, plm_idx);
  case fnPlmInstr_CopyFromRamToVram: return PlmInstr_CopyFromRamToVram(plmp, plm_idx);
  case fnPlmInstr_GotoIfBossBitSet: return PlmInstr_GotoIfBossBitSet(plmp, plm_idx);
  case fnPlmInstr_GotoIfEventSet: return PlmInstr_GotoIfEventSet(plmp, plm_idx);
  case fnPlmInstr_SetEvent: return PlmInstr_SetEvent(plmp, plm_idx);
  case fnPlmInstr_GotoIfChozoSet: return PlmInstr_GotoIfChozoSet(plmp, plm_idx);
  case fnPlmInstr_SetRoomChozoBit: return PlmInstr_SetRoomChozoBit(plmp, plm_idx);
  case fnPlmInstr_GotoIfItemBitSet: return PlmInstr_GotoIfItemBitSet(plmp, plm_idx);
  case fnPlmInstr_SetItemBit: return PlmInstr_SetItemBit(plmp, plm_idx);
  case fnPlmInstr_PickupBeamAndShowMessage: return PlmInstr_PickupBeamAndShowMessage(plmp, plm_idx);
  case fnPlmInstr_PickupEquipmentAndShowMessage: return PlmInstr_PickupEquipmentAndShowMessage(plmp, plm_idx);
  case fnPlmInstr_PickupEquipmentAddGrappleShowMessage: return PlmInstr_PickupEquipmentAddGrappleShowMessage(plmp, plm_idx);
  case fnPlmInstr_PickupEquipmentAddXrayShowMessage: return PlmInstr_PickupEquipmentAddXrayShowMessage(plmp, plm_idx);
  case fnPlmInstr_CollectHealthEnergyTank: return PlmInstr_CollectHealthEnergyTank(plmp, plm_idx);
  case fnPlmInstr_CollectHealthReserveTank: return PlmInstr_CollectHealthReserveTank(plmp, plm_idx);
  case fnPlmInstr_CollectAmmoMissileTank: return PlmInstr_CollectAmmoMissileTank(plmp, plm_idx);
  case fnPlmInstr_CollectAmmoSuperMissileTank: return PlmInstr_CollectAmmoSuperMissileTank(plmp, plm_idx);
  case fnPlmInstr_CollectAmmoPowerBombTank: return PlmInstr_CollectAmmoPowerBombTank(plmp, plm_idx);
  case fnPlmInstr_SetLinkReg: return PlmInstr_SetLinkReg(plmp, plm_idx);
  case fnPlmInstr_Call: return PlmInstr_Call(plmp, plm_idx);
  case fnPlmInstr_Return: return PlmInstr_Return(plmp, plm_idx);
  case fnPlmInstr_GotoIfDoorBitSet: return PlmInstr_GotoIfDoorBitSet(plmp, plm_idx);
  case fnPlmInstr_IncrementDoorHitCounterAndJGE: return PlmInstr_IncrementDoorHitCounterAndJGE(plmp, plm_idx);
  case fnPlmInstr_IncrementArgumentAndJGE: return PlmInstr_IncrementArgumentAndJGE(plmp, plm_idx);
  case fnPlmInstr_SetBTS: return PlmInstr_SetBTS(plmp, plm_idx);
  case fnPlmInstr_DrawPlmBlock: return PlmInstr_DrawPlmBlock(plmp, plm_idx);
  case fnPlmInstr_DrawPlmBlock_: return PlmInstr_DrawPlmBlock(plmp, plm_idx);
  case fnPlmInstr_ProcessAirScrollUpdate: return PlmInstr_ProcessAirScrollUpdate(plmp, plm_idx);
  case fnPlmInstr_ProcessSolidScrollUpdate: return PlmInstr_ProcessSolidScrollUpdate(plmp, plm_idx);
  case fnPlmInstr_QueueMusic: return PlmInstr_QueueMusic(plmp, plm_idx);
  case fnPlmInstr_ClearMusicQueueAndQueueTrack: return PlmInstr_ClearMusicQueueAndQueueTrack(plmp, plm_idx);
  case fnPlmInstr_QueueSfx1_Max6: return PlmInstr_QueueSfx1_Max6(plmp, plm_idx);
  case fnPlmInstr_QueueSfx2_Max6: return PlmInstr_QueueSfx2_Max6(plmp, plm_idx);
  case fnPlmInstr_QueueSfx3_Max6: return PlmInstr_QueueSfx3_Max6(plmp, plm_idx);
  case fnPlmInstr_QueueSfx1_Max15: return PlmInstr_QueueSfx1_Max15(plmp, plm_idx);
  case fnPlmInstr_QueueSfx2_Max15: return PlmInstr_QueueSfx2_Max15(plmp, plm_idx);
  case fnPlmInstr_QueueSfx3_Max15: return PlmInstr_QueueSfx3_Max15(plmp, plm_idx);
  case fnPlmInstr_QueueSfx1_Max3: return PlmInstr_QueueSfx1_Max3(plmp, plm_idx);
  case fnPlmInstr_QueueSfx2_Max3: return PlmInstr_QueueSfx2_Max3(plmp, plm_idx);
  case fnPlmInstr_QueueSfx_Max3: return PlmInstr_QueueSfx_Max3(plmp, plm_idx);
  case fnPlmInstr_QueueSfx1_Max9: return PlmInstr_QueueSfx1_Max9(plmp, plm_idx);
  case fnPlmInstr_QueueSfx2_Max9: return PlmInstr_QueueSfx2_Max9(plmp, plm_idx);
  case fnPlmInstr_QueueSfx3_Max9: return PlmInstr_QueueSfx3_Max9(plmp, plm_idx);
  case fnPlmInstr_QueueSfx1_Max1: return PlmInstr_QueueSfx1_Max1(plmp, plm_idx);
  case fnPlmInstr_QueueSfx2_Max1: return PlmInstr_QueueSfx2_Max1(plmp, plm_idx);
  case fnPlmInstr_QueueSfx3_Max1: return PlmInstr_QueueSfx3_Max1(plmp, plm_idx);
  case fnPlmInstr_ActivateMapStation: return PlmInstr_ActivateMapStation(plmp, plm_idx);
  case fnPlmInstr_ActivateEnergyStation: return PlmInstr_ActivateEnergyStation(plmp, plm_idx);
  case fnPlmInstr_ActivateMissileStation: return PlmInstr_ActivateMissileStation(plmp, plm_idx);
  case fnPlmInstr_ActivateSaveStationAndGotoIfNo: return PlmInstr_ActivateSaveStationAndGotoIfNo(plmp, plm_idx);
  case fnPlmInstr_GotoIfSamusNear: return PlmInstr_GotoIfSamusNear(plmp, plm_idx);
  case fnPlmInstr_MovePlmDownOneBlock: return PlmInstr_MovePlmDownOneBlock(plmp, plm_idx);
  case fnPlmInstr_Scroll_0_1_Blue: return PlmInstr_Scroll_0_1_Blue(plmp, plm_idx);
  case fnPlmInstr_MovePlmDownOneBlock_0: return PlmInstr_MovePlmDownOneBlock_0(plmp, plm_idx);
  case fnPlmInstr_DealDamage_2: return PlmInstr_DealDamage_2(plmp, plm_idx);
  case fnPlmInstr_GiveInvincibility: return PlmInstr_GiveInvincibility(plmp, plm_idx);
  case fnPlmInstr_Draw0x38FramesOfRightTreadmill: return PlmInstr_Draw0x38FramesOfRightTreadmill(plmp, plm_idx);
  case fnPlmInstr_Draw0x38FramesOfLeftTreadmill: return PlmInstr_Draw0x38FramesOfLeftTreadmill(plmp, plm_idx);
  case fnPlmInstr_GotoIfSamusHealthFull: return PlmInstr_GotoIfSamusHealthFull(plmp, plm_idx);
  case fnPlmInstr_GotoIfMissilesFull: return PlmInstr_GotoIfMissilesFull(plmp, plm_idx);
  case fnPlmInstr_PlaceSamusOnSaveStation: return PlmInstr_PlaceSamusOnSaveStation(plmp, plm_idx);
  case fnPlmInstr_DisplayGameSavedMessageBox: return PlmInstr_DisplayGameSavedMessageBox(plmp, plm_idx);
  case fnPlmInstr_EnableMovementAndSetSaveStationUsed: return PlmInstr_EnableMovementAndSetSaveStationUsed(plmp, plm_idx);
  case fnPlmInstr_SetCrittersEscapedEvent: return PlmInstr_SetCrittersEscapedEvent(plmp, plm_idx);
  case fnPlmInstr_JumpIfSamusHasNoBombs: return PlmInstr_JumpIfSamusHasNoBombs(plmp, plm_idx);
  case fnPlmInstr_MovePlmRight4Blocks: return PlmInstr_MovePlmRight4Blocks(plmp, plm_idx);
  case fnPlmInstr_ClearTrigger: return PlmInstr_ClearTrigger(plmp, plm_idx);
  case fnPlmInstr_SpawnEproj: return PlmInstr_SpawnEproj(plmp, plm_idx);
  case fnPlmInstr_WakeEprojAtPlmPos: return PlmInstr_WakeEprojAtPlmPos(plmp, plm_idx);
  case fnPlmInstr_SetGreyDoorPreInstr: return PlmInstr_SetGreyDoorPreInstr(plmp, plm_idx);
  case fnPlmInstr_FxBaseYPos_0x2D2: return PlmInstr_FxBaseYPos_0x2D2(plmp, plm_idx);
  case fnPlmInstr_GotoIfRoomArgLess: return PlmInstr_GotoIfRoomArgLess(plmp, plm_idx);
  case fnPlmInstr_SpawnFourMotherBrainGlass: return PlmInstr_SpawnFourMotherBrainGlass(plmp, plm_idx);
  case fnPlmInstr_SpawnTorizoStatueBreaking: return PlmInstr_SpawnTorizoStatueBreaking(plmp, plm_idx);
  case fnPlmInstr_QueueSong1MusicTrack: return PlmInstr_QueueSong1MusicTrack(plmp, plm_idx);
  case fnPlmInstr_TransferWreckedShipChozoSpikesToSlopes: return PlmInstr_TransferWreckedShipChozoSpikesToSlopes(plmp, plm_idx);
  case fnPlmInstr_TransferWreckedShipSlopesToChozoSpikes: return PlmInstr_TransferWreckedShipSlopesToChozoSpikes(plmp, plm_idx);
  case fnPlmInstr_EnableWaterPhysics: return PlmInstr_EnableWaterPhysics(plmp, plm_idx);
  case fnPlmInstr_SpawnN00bTubeCrackEproj: return PlmInstr_SpawnN00bTubeCrackEproj(plmp, plm_idx);
  case fnPlmInstr_DiagonalEarthquake: return PlmInstr_DiagonalEarthquake(plmp, plm_idx);
  case fnPlmInstr_Spawn10shardsAnd6n00bs: return PlmInstr_Spawn10shardsAnd6n00bs(plmp, plm_idx);
  case fnPlmInstr_ShootEyeDoorProjectileWithProjectileArg: return PlmInstr_ShootEyeDoorProjectileWithProjectileArg(plmp, plm_idx);
  case fnPlmInstr_SpawnEyeDoorSweatEproj: return PlmInstr_SpawnEyeDoorSweatEproj(plmp, plm_idx);
  case fnPlmInstr_SpawnTwoEyeDoorSmoke: return PlmInstr_SpawnTwoEyeDoorSmoke(plmp, plm_idx);
  case fnPlmInstr_SpawnEyeDoorSmokeProjectile: return PlmInstr_SpawnEyeDoorSmokeProjectile(plmp, plm_idx);
  case fnPlmInstr_MoveUpAndMakeBlueDoorFacingRight: return PlmInstr_MoveUpAndMakeBlueDoorFacingRight(plmp, plm_idx);
  case fnPlmInstr_MoveUpAndMakeBlueDoorFacingLeft: return PlmInstr_MoveUpAndMakeBlueDoorFacingLeft(plmp, plm_idx);
  case fnPlmInstr_DamageDraygonTurret: return PlmInstr_DamageDraygonTurret(plmp, plm_idx);
  case fnPlmInstr_DamageDraygonTurretFacingDownRight: return PlmInstr_DamageDraygonTurretFacingDownRight(plmp, plm_idx);
  case fnPlmInstr_DamageDraygonTurretFacingUpRight: return PlmInstr_DamageDraygonTurretFacingUpRight(plmp, plm_idx);
  case fnPlmInstr_DamageDraygonTurret2: return PlmInstr_DamageDraygonTurret2(plmp, plm_idx);
  case fnPlmInstr_DamageDraygonTurretFacingDownLeft: return PlmInstr_DamageDraygonTurretFacingDownLeft(plmp, plm_idx);
  case fnPlmInstr_DamageDraygonTurretFacingUpLeft: return PlmInstr_DamageDraygonTurretFacingUpLeft(plmp, plm_idx);
  case fnPlmInstr_DrawItemFrame0: return PlmInstr_DrawItemFrame0(plmp, plm_idx);
  case fnPlmInstr_DrawItemFrame1: return PlmInstr_DrawItemFrame1(plmp, plm_idx);
  case fnPlmInstr_DrawItemFrame_Common: return PlmInstr_DrawItemFrame_Common(plmp, plm_idx);
  case fnPlmInstr_ClearChargeBeamCounter: return PlmInstr_ClearChargeBeamCounter(plmp, plm_idx);
  case fnPlmInstr_MovePlmRight1Block: return PlmInstr_MovePlmRight1Block(plmp, plm_idx);
  case fnPlmInstr_MoveFxYUp: return PlmInstr_MoveFxYUp(plmp, plm_idx);
  case fnPlmInstr_SetBtsTo1: return PlmInstr_SetBtsTo1(plmp, plm_idx);
  case fnPlmInstr_DisableSamusControls: return PlmInstr_DisableSamusControls(plmp, plm_idx);
  case fnPlmInstr_EnableSamusControls: return PlmInstr_EnableSamusControls(plmp, plm_idx);
  default: Unreachable(); return NULL;
  }
}
