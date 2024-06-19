// Animated tiles

#include "ida_types.h"
#include "funcs.h"
#include "variables.h"
#include "sm_87.h"


/**
* @brief Enables animated tiles
*/
void EnableAnimtiles(void) {  // 0x878000
  animtiles_enable_flag |= 0x8000;
}

/**
* @brief Disables animated tiles
*/
void DisableAnimtiles(void) {  // 0x87800B
  animtiles_enable_flag &= ~0x8000;
}

/**
* @brief Clears all animated tiles
*/
void ClearAnimtiles(void) {  // 0x878016
  //for (int animtile_idx = 10; animtile_idx >= 0; animtile_idx -= 2)
  //  animtiles_ids[animtile_idx >> 1] = 0;
  memset7E(animtiles_ids, 0, 12);
}

/**
* @brief Spawns an animated tile
* @param animtile_id The address of the animated tile to spawn
*/
void SpawnAnimtiles(uint16 animtile_id) {  // 0x878027
  int16 animtile_idx = 10;
  while (animtiles_ids[animtile_idx >> 1] != 0) {
    animtile_idx -= 2;
    if (animtile_idx < 0)
      return;
  }

  int idx = animtile_idx >> 1;
  animtiles_ids[idx] = animtile_id;
  animtiles_timers[idx] = 0;
  AnimtilesObject animtile = get_AnimtilesObject(animtile_id);
  animtiles_instr_list_ptrs[idx] = animtile.instruction_list;
  animtiles_src_ptr[idx] = 0;
  animtiles_sizes[idx] = animtile.size;
  animtiles_vram_ptr[idx] = animtile.vram_addr;
  animtiles_instr_timers[idx] = 1;
}

/**
* @brief Handles animated tiles and processes them
*/
void AnimtilesHandler(void) {  // 0x878064
  if (animtiles_enable_flag & 0x8000) {
    for (int animtile_idx = 10; animtile_idx >= 0; animtile_idx -= 2) {
      animtiles_object_index = animtile_idx;
      if (animtiles_ids[animtile_idx >> 1] != 0) {
        ProcessAnimtilesObject();
        animtile_idx = animtiles_object_index;
      }
    }
  }
}

uint16 CallAnimtilesInstr(uint32 ea, uint16 animtile_idx, uint16 instrlist_ptr) {
  switch (ea) {
  case fnAnimtilesInstr_Delete: return AnimtilesInstr_Delete(animtile_idx, instrlist_ptr);
  case fnAnimtilesInstr_Goto: return AnimtilesInstr_Goto(animtile_idx, get_AnimtilesEntry(instrlist_ptr).instr_list_ptr1);
  case fnAnimtilesInstr_GotoRel_Unused: return AnimtilesInstr_GotoRel_Unused(animtile_idx, instrlist_ptr);
  case fnAnimtilesInstr_DecrementTimerAndGoto_Unused: return AnimtilesInstr_DecrementTimerAndGoto_Unused(animtile_idx, instrlist_ptr);
  case fnAnimtilesInstr_DecrementTimerAndGotoRel_Unused: return AnimtilesInstr_DecrementTimerAndGotoRel_Unused(animtile_idx, instrlist_ptr);
  case fnAnimtilesInstr_SetTimer_Unused: return AnimtilesInstr_SetTimer_Unused(animtile_idx, instrlist_ptr);
  case fnAnimtilesInstr_QueueMusic_Unused: return AnimtilesInstr_QueueMusic_Unused(animtile_idx, instrlist_ptr);
  case fnAnimtilesInstr_QueueSfx1_Unused: return AnimtilesInstr_QueueSfx1_Unused(animtile_idx, instrlist_ptr);
  case fnAnimtilesInstr_QueueSfx2_Unused: return AnimtilesInstr_QueueSfx2_Unused(animtile_idx, instrlist_ptr);
  case fnAnimtilesInstr_QueueSfx3_Unused: return AnimtilesInstr_QueueSfx3_Unused(animtile_idx, instrlist_ptr);
  case fnAnimtilesInstr_GotoIfBossBitSet_Unused: return AnimtilesInstr_GotoIfBossBitSet_Unused(animtile_idx, instrlist_ptr);
  case fnAnimtilesInstr_SetBossBit_Unused: return AnimtilesInstr_SetBossBit_Unused(animtile_idx, instrlist_ptr);
  case fnAnimtilesInstr_GotoIfEventHappened: return AnimtilesInstr_GotoIfEventHappened(animtile_idx, instrlist_ptr);
  case fnAnimtilesInstr_SetEventHappened: return AnimtilesInstr_SetEventHappened(animtile_idx, instrlist_ptr);
  case fnAnimtilesInstr_WaitUntilAreaBossDead_DoubleRet: return AnimtilesInstr_WaitUntilAreaBossDead_DoubleRet(animtile_idx, instrlist_ptr);
  case fnAnimtilesInstr_GotoIfBossBitSetInArea: return AnimtilesInstr_GotoIfBossBitSetInArea(animtile_idx, instrlist_ptr);
  case fnAnimtilesInstr_SpawnTourianStatueEyeGlow: return AnimtilesInstr_SpawnTourianStatueEyeGlow(animtile_idx, instrlist_ptr);
  case fnAnimtilesInstr_SpawnTourianStatueSoul: return AnimtilesInstr_SpawnTourianStatueSoul(animtile_idx, instrlist_ptr);
  case fnAnimtilesInstr_GotoIfTourianStatueBusy: return AnimtilesInstr_GotoIfTourianStatueBusy(animtile_idx, instrlist_ptr);
  case fnAnimtilesInstr_TourianStatueSetState: return AnimtilesInstr_TourianStatueSetState(animtile_idx, instrlist_ptr);
  case fnAnimtilesInstr_TourianStatueClearState: return AnimtilesInstr_TourianStatueClearState(animtile_idx, instrlist_ptr);
  case fnAnimtilesInstr_Clear3PaletteColors: return AnimtilesInstr_Clear3PaletteColors(animtile_idx, instrlist_ptr);
  case fnAnimtilesInstr_SpawnPalfxObj: return AnimtilesInstr_SpawnPalfxObj(animtile_idx, instrlist_ptr);
  case fnAnimtilesInstr_Write8PaletteColors: return AnimtilesInstr_Write8PaletteColors(animtile_idx, instrlist_ptr);
  default: return Unreachable();
  }
}

/**
* @brief Processes animated tiles and their instructions
*/
void ProcessAnimtilesObject(void) {  // 0x878085
  uint16 animetile_idx = animtiles_object_index;
  int idx = animtiles_object_index >> 1;
  if (--animtiles_instr_timers[idx] == 0) {
    uint16 instrlist_ptr = animtiles_instr_list_ptrs[idx];
    AnimtilesEntry AtE;
    while (1) {
      AtE = get_AnimtilesEntry(instrlist_ptr);
      // If the instruction is not a function, break
      if (!IS_FUNC(AtE.func_ptr))
        break;
      animtiles_instruction = AtE.func_ptr;
      instrlist_ptr = CallAnimtilesInstr(AtE.func_ptr | 0x870000, animetile_idx, instrlist_ptr);
      if (instrlist_ptr == 0)
        return;
    }
    animtiles_instr_timers[idx] = AtE.timer;
    animtiles_src_ptr[idx] = AtE.tile_src;
    animtiles_instr_list_ptrs[idx] = instrlist_ptr + 4;
  }
}

/**
* @brief Deletes an animated tile
* @param animtile_idx The index of the animated tile to delete
* @param instrlist_ptr The instruction list pointer
* @return uint16 0, indicating that processing is finished
*/
uint16 AnimtilesInstr_Delete(uint16 animtile_idx, uint16 instrlist_ptr) {  // 0x8780B2
  animtiles_ids[animtile_idx >> 1] = 0;
  return 0;
}

/**
* @brief Returns the instruction list pointer
* @param animtile_idx The index of the animated tile
* @param instrlist_ptr The instruction list pointer
* @return uint16 The pointer to the next instruction
*/
uint16 AnimtilesInstr_Goto(uint16 animtile_idx, uint16 instrlist_ptr) {  // 0x8780B7
  // In order to make this work, i pass in the instruction to go to when it's called, rather than inside the function
  return instrlist_ptr;
}

uint16 AnimtilesInstr_GotoRel_Unused(uint16 k, uint16 j) {  // 0x8780BC
  animtiles_instruction = j;
  return j + get_AnimtilesEntry(j).instr_list_ptr1;
}

uint16 AnimtilesInstr_DecrementTimerAndGoto_Unused(uint16 k, uint16 j) {  // 0x8780D4
  if (animtiles_timers[k >> 1]-- == 1)
    return j + 2;
  else
    return AnimtilesInstr_Goto(k, j);
}

uint16 AnimtilesInstr_DecrementTimerAndGotoRel_Unused(uint16 k, uint16 j) {  // 0x8780DC
  if (animtiles_timers[k >> 1]-- == 1)
    return j + 1;
  else
    return AnimtilesInstr_GotoRel_Unused(k, j);
}

uint16 AnimtilesInstr_SetTimer_Unused(uint16 k, uint16 j) {  // 0x8780E3
  animtiles_timers[k >> 1] = get_AnimtilesEntry(j).instr_list_ptr1;
  return j + 1 + 2;
}

uint16 AnimtilesInstr_QueueMusic_Unused(uint16 k, uint16 j) {  // 0x8780F0
  QueueMusic_Delayed8(get_AnimtilesEntry(j).instr_list_ptr1);
  return j + 1 + 2;
}

uint16 AnimtilesInstr_QueueSfx1_Unused(uint16 k, uint16 j) {  // 0x8780FC
  QueueSfx1_Max6(get_AnimtilesEntry(j).instr_list_ptr1);
  return j + 1 + 2;
}

uint16 AnimtilesInstr_QueueSfx2_Unused(uint16 k, uint16 j) {  // 0x878108
  QueueSfx2_Max6(get_AnimtilesEntry(j).instr_list_ptr1);
  return j + 1 + 2;
}

uint16 AnimtilesInstr_QueueSfx3_Unused(uint16 k, uint16 j) {  // 0x878114
  QueueSfx3_Max6(get_AnimtilesEntry(j).instr_list_ptr1);
  return j + 1 + 2;
}

uint16 AnimtilesInstr_GotoIfBossBitSet_Unused(uint16 k, uint16 j) {  // 0x878120
  uint16 v3 = j + 1;
  if (CheckBossBitForCurArea(get_AnimtilesEntry(j).game_event) & 1)
    return AnimtilesInstr_Goto(k, v3);
  else
    return v3 + 2 + 2;
}

uint16 AnimtilesInstr_SetBossBit_Unused(uint16 k, uint16 j) {  // 0x878133
  SetBossBitForCurArea(get_AnimtilesEntry(j).instr_list_ptr1);
  return j + 1 + 2;
}

/**
* @brief Goes to the instruction list pointer if the event happened, otherwise goes to the next instruction
* @param animtile_idx The index of the animated tile
* @param instrlist_ptr The instruction list pointer
* @return uint16 The pointer to the next instruction
*/
uint16 AnimtilesInstr_GotoIfEventHappened(uint16 animtile_idx, uint16 instrlist_ptr) {  // 0x87813F
  if (CheckEventHappened(get_AnimtilesEntry(instrlist_ptr).game_event))
    return AnimtilesInstr_Goto(animtile_idx, get_AnimtilesEntry(instrlist_ptr).instr_list_ptr2);
  return instrlist_ptr + 6;
}

/**
* @brief Sets the event as happened
* @param animtile_idx The index of the animated tile
* @param instrlist_ptr The instruction list pointer
* @return uint16 The pointer to the next instruction
*/
uint16 AnimtilesInstr_SetEventHappened(uint16 animtile_idx, uint16 instrlist_ptr) {  // 0x878150
  SetEventHappened(get_AnimtilesEntry(instrlist_ptr).game_event);
  return instrlist_ptr + 4;
}

void AnimtilesInstr_LockSamus_Unused(void) {  // 0x87815A
  RunSamusCode(kSamusCode_0_LockSamus);
}

void AnimtilesInstr_UnlockSamus_Unused(void) {  // 0x878162
  RunSamusCode(kSamusCode_1_UnlockSamus);
}

/**
* @brief Waits at the instruction and stops processing until the area boss is dead, then continues to the next instruction
* @param animtile_idx The index of the animated tile
* @param instrlist_ptr The instruction list pointer
* @return uint16 The pointer to the next instruction
*/
uint16 AnimtilesInstr_WaitUntilAreaBossDead_DoubleRet(uint16 animtile_idx, uint16 instrlist_ptr) {  // 0x8781BA
  if (!(CheckBossBitForCurArea(kBossBit_AreaBoss))) {
    animtiles_instr_timers[animtile_idx >> 1] = 1;
    return 0;
  }
  return instrlist_ptr + 2;
}

/**
* @brief Goes to the instruction list pointer if the boss bit is set in the area, otherwise goes to the next instruction
* @param animtile_idx The index of the animated tile
* @param instrlist_ptr The instruction list pointer
* @return uint16 The pointer to the next instruction
*/
uint16 AnimtilesInstr_GotoIfBossBitSetInArea(uint16 animtile_idx, uint16 instrlist_ptr) {  // 0x878303
  const AnimtilesEntry AtE = get_AnimtilesEntry(instrlist_ptr);
  if ((AtE.boss_bit & boss_bits_for_area[AtE.area]) != 0)
    return AnimtilesInstr_Goto(animtile_idx, AtE.instr_list_ptr2);
  return instrlist_ptr + 6;
}

/**
* @brief Spawns the Tourian statue eye glow eproj
* @param animtile_idx The index of the animated tile
* @param instrlist_ptr The instruction list pointer
* @return uint16 The pointer to the next instruction
*/
uint16 AnimtilesInstr_SpawnTourianStatueEyeGlow(uint16 animtile_idx, uint16 instrlist_ptr) {  // 0x878320
  // eproj_param is the boss index, with phantoon = 0, ridley = 2, draygon = 4, kraid = 6
  SpawnEprojWithRoomGfx(addr_kEproj_TourianStatueEyeGlow, get_AnimtilesEntry(instrlist_ptr).eproj_param);
  return instrlist_ptr + 4;
}

/**
* @brief Spawns the Tourian statue soul eproj
* @param animtile_idx The index of the animated tile
* @param instrlist_ptr The instruction list pointer
* @return uint16 The pointer to the next instruction
*/
uint16 AnimtilesInstr_SpawnTourianStatueSoul(uint16 animtile_idx, uint16 instrlist_ptr) {  // 0x87832F
  // eproj_param is the boss index, with phantoon = 0, ridley = 2, draygon = 4, kraid = 6
  SpawnEprojWithRoomGfx(addr_kEproj_TourianStatueSoul, get_AnimtilesEntry(instrlist_ptr).eproj_param);
  return instrlist_ptr + 4;
}

/**
* @brief Goes to the instruction list pointer if the Tourian statue is busy, otherwise goes to the next instruction
* @param animtile_idx The index of the animated tile
* @param instrlist_ptr The instruction list pointer
* @return uint16 The pointer to the next instruction
*/
uint16 AnimtilesInstr_GotoIfTourianStatueBusy(uint16 animtile_idx, uint16 instrlist_ptr) {  // 0x87833E
  if (tourian_entrance_statue_animstate & kStatueState_ReleasingBossLock)
    return AnimtilesInstr_Goto(animtile_idx, get_AnimtilesEntry(instrlist_ptr).instr_list_ptr1);
  return instrlist_ptr + 4;
}

/**
* @brief Enables the specified Tourian statue animation state
* @param animtile_idx The index of the animated tile
* @param instrlist_ptr The instruction list pointer
* @return uint16 The pointer to the next instruction
*/
uint16 AnimtilesInstr_TourianStatueSetState(uint16 animtile_idx, uint16 instrlist_ptr) {  // 0x878349
  tourian_entrance_statue_animstate |= get_AnimtilesEntry(instrlist_ptr).tourian_statue_state;
  return instrlist_ptr + 4;
}

/**
* @brief Disables the specified Tourian statue animation state
* @param animtile_idx The index of the animated tile
* @param instrlist_ptr The instruction list pointer
* @return uint16 The pointer to the next instruction
*/
uint16 AnimtilesInstr_TourianStatueClearState(uint16 animtile_idx, uint16 instrlist_ptr) {  // 0x878352
  tourian_entrance_statue_animstate &= ~get_AnimtilesEntry(instrlist_ptr).tourian_statue_state;
  return instrlist_ptr + 4;
}

/**
* @brief Clears 3 palette colors at the specified palette offset
* @param animtile_idx The index of the animated tile
* @param instrlist_ptr The instruction list pointer
* @return uint16 The pointer to the next instruction
*/
uint16 AnimtilesInstr_Clear3PaletteColors(uint16 animtile_idx, uint16 instrlist_ptr) {  // 0x87835B
  uint16 pal_offset = get_AnimtilesEntry(instrlist_ptr).palette_offset >> 1;
  palette_buffer.pal[pal_offset] = 0;
  palette_buffer.pal[pal_offset + 1] = 0;
  palette_buffer.pal[pal_offset + 2] = 0;
  return instrlist_ptr + 4;
}

/**
* @brief Spawns a palfx object with the specified palfx ID
* @param animtile_idx The index of the animated tile
* @param instrlist_ptr The instruction list pointer
* @return uint16 The pointer to the next instruction
*/
uint16 AnimtilesInstr_SpawnPalfxObj(uint16 animtile_idx, uint16 instrlist_ptr) {  // 0x878372
  SpawnPalfxObject(get_AnimtilesEntry(instrlist_ptr).palfx_id);
  return instrlist_ptr + 4;
}

/**
* @brief Writes 8 palette colors at the specified palette offset
* @param animtile_idx The index of the animated tile
* @param instrlist_ptr The instruction list pointer
* @return uint16 The pointer to the next instruction
*/
uint16 AnimtilesInstr_Write8PaletteColors(uint16 animtile_idx, uint16 instrlist_ptr) {  // 0x87837F
  // The gray colors used for the grayed out Tourian statue 
  static const uint16 kAnimtilesInstr_Write8PaletteColors[8] = { 0x3800, 0x7f58, 0x6ed5, 0x5a71, 0x49ee, 0x356a, 0x24e7, 0x1083 };

  uint16 pal_offset = get_AnimtilesEntry(instrlist_ptr).palette_offset >> 1;
  uint16 pal_size = sizeof(kAnimtilesInstr_Write8PaletteColors);
  MemCpy(target_palettes.pal + pal_offset, kAnimtilesInstr_Write8PaletteColors, pal_size);
  return instrlist_ptr + 4;
}
