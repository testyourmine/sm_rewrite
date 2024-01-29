// Animated tiles
#include "ida_types.h"
#include "funcs.h"
#include "variables.h"
#include "sm_87.h"





void EnableAnimtiles(void) {  // 0x878000
  animtiles_enable_flag |= 0x8000;
}

void DisableAnimtiles(void) {  // 0x87800B
  animtiles_enable_flag &= ~0x8000;
}

void ClearAnimtiles(void) {  // 0x878016
  for (int i = 10; i >= 0; i -= 2)
    animtiles_ids[i >> 1] = 0;
}

void SpawnAnimtiles(uint16 j) {  // 0x878027
  uint16 v0 = j;

  uint16 v1 = 10;
  while (animtiles_ids[v1 >> 1]) {
    v1 -= 2;
    if ((v1 & 0x8000) != 0)
      return;
  }
  int v2 = v1 >> 1;
  animtiles_ids[v2] = v0;
  animtiles_timers[v2] = 0;
  //const uint16 *v3 = (const uint16 *)RomPtr_87(v0);
  AnimtilesObject v3 = get_AnimtilesObject(v0);
  animtiles_instr_list_ptrs[v2] = v3.instruction_list;
  animtiles_src_ptr[v2] = 0;
  animtiles_sizes[v2] = v3.size;
  animtiles_vram_ptr[v2] = v3.vram_addr;
  animtiles_instr_timers[v2] = 1;
}

void AnimtilesHandler(void) {  // 0x878064
  if ((animtiles_enable_flag & 0x8000) != 0) {
    for (int i = 10; i >= 0; i -= 2) {
      animtiles_object_index = i;
      if (animtiles_ids[i >> 1]) {
        ProcessAnimtilesObject();
        i = animtiles_object_index;
      }
    }
  }
}

uint16 CallAnimtilesInstr(uint32 ea, uint16 j, uint16 k) {
  switch (ea) {
  case fnAnimtilesInstr_Delete: return AnimtilesInstr_Delete(j, k);
  case fnAnimtilesInstr_Goto: return AnimtilesInstr_Goto(j, get_AnimtilesEntry(k).instr_list_ptr1);
  case fnAnimtilesInstr_GotoRel_Unused: return AnimtilesInstr_GotoRel_Unused(j, k);
  case fnAnimtilesInstr_DecrementTimerAndGoto_Unused: return AnimtilesInstr_DecrementTimerAndGoto_Unused(j, k);
  case fnAnimtilesInstr_DecrementTimerAndGotoRel_Unused: return AnimtilesInstr_DecrementTimerAndGotoRel_Unused(j, k);
  case fnAnimtilesInstr_SetTimer_Unused: return AnimtilesInstr_SetTimer_Unused(j, k);
  case fnAnimtilesInstr_QueueMusic_Unused: return AnimtilesInstr_QueueMusic_Unused(j, k);
  case fnAnimtilesInstr_QueueSfx1_Unused: return AnimtilesInstr_QueueSfx1_Unused(j, k);
  case fnAnimtilesInstr_QueueSfx2_Unused: return AnimtilesInstr_QueueSfx2_Unused(j, k);
  case fnAnimtilesInstr_QueueSfx3_Unused: return AnimtilesInstr_QueueSfx3_Unused(j, k);
  case fnAnimtilesInstr_GotoIfBossBitSet_Unused: return AnimtilesInstr_GotoIfBossBitSet_Unused(j, k);
  case fnAnimtilesInstr_SetBossBit_Unused: return AnimtilesInstr_SetBossBit_Unused(j, k);
  case fnAnimtilesInstr_GotoIfEventHappened: return AnimtilesInstr_GotoIfEventHappened(j, k);
  case fnAnimtilesInstr_SetEventHappened: return AnimtilesInstr_SetEventHappened(j, k);
  case fnAnimtilesInstr_WaitUntilAreaBossDead_DoubleRet: return AnimtilesInstr_WaitUntilAreaBossDead_DoubleRet(j, k);
  case fnAnimtilesInstr_GotoIfBossBitSetInArea: return AnimtilesInstr_GotoIfBossBitSetInArea(j, k);
  case fnAnimtilesInstr_SpawnTourianStatueEyeGlow: return AnimtilesInstr_SpawnTourianStatueEyeGlow(j, k);
  case fnAnimtilesInstr_SpawnTourianStatueSoul: return AnimtilesInstr_SpawnTourianStatueSoul(j, k);
  case fnAnimtilesInstr_GotoIfTourianStatueBusy: return AnimtilesInstr_GotoIfTourianStatueBusy(j, k);
  case fnAnimtilesInstr_TourianStatueSetState: return AnimtilesInstr_TourianStatueSetState(j, k);
  case fnAnimtilesInstr_TourianStatueClearState: return AnimtilesInstr_TourianStatueClearState(j, k);
  case fnAnimtilesInstr_Clear3PaletteColors: return AnimtilesInstr_Clear3PaletteColors(j, k);
  case fnAnimtilesInstr_SpawnPalfxObj: return AnimtilesInstr_SpawnPalfxObj(j, k);
  case fnAnimtilesInstr_Write8PaletteColors: return AnimtilesInstr_Write8PaletteColors(j, k);
  default: return Unreachable();
  }
}

void ProcessAnimtilesObject(void) {  // 0x878085
  uint16 v0 = animtiles_object_index;
  int v1 = animtiles_object_index >> 1;
  if (animtiles_instr_timers[v1]-- == 1) {
    uint16 v3 = animtiles_instr_list_ptrs[v1];
    AnimtilesEntry AtE;
    while (1) {
      AtE = get_AnimtilesEntry(v3);
      //const uint16 *v4 = (const uint16 *)RomPtr_87(v3);
      //v5 = *v4;
      if ((AtE.func_ptr & 0x8000) == 0)
        break;
      animtiles_instruction = AtE.func_ptr;
      v3 = CallAnimtilesInstr(AtE.func_ptr | 0x870000, v0, v3);
      if (!v3)
        return;
    }
    int v6 = v0 >> 1;
    AtE = get_AnimtilesEntry(v3);
    animtiles_instr_timers[v6] = AtE.timer;
    //animtiles_src_ptr[v6] = *((uint16 *)RomPtr_87(v3) + 1);
    animtiles_src_ptr[v6] = AtE.tile_src;
    animtiles_instr_list_ptrs[v6] = v3 + 4;
  }
}

uint16 AnimtilesInstr_Delete(uint16 k, uint16 j) {  // 0x8780B2
  animtiles_ids[k >> 1] = 0;
  return 0;
}

uint16 AnimtilesInstr_Goto(uint16 k, uint16 j) {  // 0x8780B7
  //return *(uint16 *)RomPtr_87(j);
  return j;
}

uint16 AnimtilesInstr_GotoRel_Unused(uint16 k, uint16 j) {  // 0x8780BC
  animtiles_instruction = j;
  return j + get_AnimtilesEntry(j).instr_list_ptr1;
}

uint16 AnimtilesInstr_DecrementTimerAndGoto_Unused(uint16 k, uint16 j) {  // 0x8780D4
  int v2 = k >> 1;
  if (animtiles_timers[v2]-- == 1)
    return j + 2;
  else
    return AnimtilesInstr_Goto(k, j);
}

uint16 AnimtilesInstr_DecrementTimerAndGotoRel_Unused(uint16 k, uint16 j) {  // 0x8780DC
  int v2 = k >> 1;
  if (animtiles_timers[v2]-- == 1)
    return j + 1;
  else
    return AnimtilesInstr_GotoRel_Unused(k, j);
}

uint16 AnimtilesInstr_SetTimer_Unused(uint16 k, uint16 j) {  // 0x8780E3
  //*((uint8 *)animtiles_timers + k) = *RomPtr_87(j);
  *((uint8 *)animtiles_timers + k) = get_AnimtilesEntry(j).instr_list_ptr1;
  return j + 1 + 2;
}

uint16 AnimtilesInstr_QueueMusic_Unused(uint16 k, uint16 j) {  // 0x8780F0
  //const uint8 *v2 = RomPtr_87(j);
  QueueMusic_Delayed8(get_AnimtilesEntry(j).instr_list_ptr1);
  return j + 1 + 2;
}

uint16 AnimtilesInstr_QueueSfx1_Unused(uint16 k, uint16 j) {  // 0x8780FC
  //const uint8 *v2 = RomPtr_87(j);
  QueueSfx1_Max6(get_AnimtilesEntry(j).instr_list_ptr1);
  return j + 1 + 2;
}

uint16 AnimtilesInstr_QueueSfx2_Unused(uint16 k, uint16 j) {  // 0x878108
  //const uint8 *v2 = RomPtr_87(j);
  QueueSfx2_Max6(get_AnimtilesEntry(j).instr_list_ptr1);
  return j + 1 + 2;
}

uint16 AnimtilesInstr_QueueSfx3_Unused(uint16 k, uint16 j) {  // 0x878114
  //const uint8 *v2 = RomPtr_87(j);
  QueueSfx3_Max6(get_AnimtilesEntry(j).instr_list_ptr1);
  return j + 1 + 2;
}

uint16 AnimtilesInstr_GotoIfBossBitSet_Unused(uint16 k, uint16 j) {  // 0x878120
  //const uint8 *v2 = RomPtr_87(j);
  uint16 v3 = j + 1;
  if (CheckBossBitForCurArea(get_AnimtilesEntry(j).game_event) & 1)
    return AnimtilesInstr_Goto(k, v3);
  else
    return v3 + 2 + 2;
}

uint16 AnimtilesInstr_SetBossBit_Unused(uint16 k, uint16 j) {  // 0x878133
  //const uint8 *v2 = RomPtr_87(j);
  SetBossBitForCurArea(get_AnimtilesEntry(j).instr_list_ptr1);
  return j + 1 + 2;
}

uint16 AnimtilesInstr_GotoIfEventHappened(uint16 k, uint16 j) {  // 0x87813F
  //const uint16 *v2 = (const uint16 *)RomPtr_87(j);
  uint16 v3 = j + 2;
  if (CheckEventHappened(get_AnimtilesEntry(j).game_event) & 1)
    return AnimtilesInstr_Goto(k, get_AnimtilesEntry(j).instr_list_ptr2);
  else
    return v3 + 2 + 2;
}

uint16 AnimtilesInstr_SetEventHappened(uint16 k, uint16 j) {  // 0x878150
  //const uint16 *v2 = (const uint16 *)RomPtr_87(j);
  SetEventHappened(get_AnimtilesEntry(j).game_event);
  return j + 2 + 2;
}

void UNUSED_sub_87815A(void) {  // 0x87815A
  RunSamusCode(kSamusCode_0_LockSamus);
}

void UNUSED_sub_878162(void) {  // 0x878162
  RunSamusCode(kSamusCode_1_UnlockSamus);
}

uint16 AnimtilesInstr_WaitUntilAreaBossDead_DoubleRet(uint16 k, uint16 j) {  // 0x8781BA
  if (!(CheckBossBitForCurArea(1) & 1)) {
    animtiles_instr_timers[k >> 1] = 1;
    return 0;
  }
  return j + 2;
}

uint16 AnimtilesInstr_GotoIfBossBitSetInArea(uint16 k, uint16 j) {  // 0x878303
  const AnimtilesEntry v2 = get_AnimtilesEntry(j);
  uint16 v3 = j + 2;
  if ((v2.boss_bit & boss_bits_for_area[v2.area]) != 0)
    return AnimtilesInstr_Goto(k, get_AnimtilesEntry(j).instr_list_ptr2);
  else
    return v3 + 2 + 2;
}

uint16 AnimtilesInstr_SpawnTourianStatueEyeGlow(uint16 k, uint16 j) {  // 0x878320
  //const uint16 *v2 = (const uint16 *)RomPtr_87(j);
  SpawnEprojWithRoomGfx(addr_kEproj_TourianStatueEyeGlow, get_AnimtilesEntry(j).eproj_param);
  return j + 2 + 2;
}

uint16 AnimtilesInstr_SpawnTourianStatueSoul(uint16 k, uint16 j) {  // 0x87832F
  //const uint16 *v2 = (const uint16 *)RomPtr_87(j);
  SpawnEprojWithRoomGfx(addr_kEproj_TourianStatueSoul, get_AnimtilesEntry(j).eproj_param);
  return j + 2 + 2;
}

uint16 AnimtilesInstr_GotoIfTourianStatueBusy(uint16 k, uint16 j) {  // 0x87833E
  if ((tourian_entrance_statue_animstate & kStatueState_ReleasingBossLock) == 0)
    return j + 2 + 2;
  else
    return AnimtilesInstr_Goto(k, get_AnimtilesEntry(j).instr_list_ptr1);
}

uint16 AnimtilesInstr_TourianStatueSetState(uint16 k, uint16 j) {  // 0x878349
  //tourian_entrance_statue_animstate |= *(uint16 *)RomPtr_87(j);
  tourian_entrance_statue_animstate |= get_AnimtilesEntry(j).tourian_statue_state;
  return j + 2 + 2;
}

uint16 AnimtilesInstr_TourianStatueClearState(uint16 k, uint16 j) {  // 0x878352
  //tourian_entrance_statue_animstate &= ~*(uint16 *)RomPtr_87(j);
  tourian_entrance_statue_animstate &= ~get_AnimtilesEntry(j).tourian_statue_state;
  return j + 2 + 2;
}

uint16 AnimtilesInstr_Clear3PaletteColors(uint16 k, uint16 j) {  // 0x87835B
  //int v2 = *(uint16 *)RomPtr_87(j) >> 1;
  uint16 v2 = get_AnimtilesEntry(j).palette_offset >> 1;
  palette_buffer[v2] = 0;
  palette_buffer[v2 + 1] = 0;
  palette_buffer[v2 + 2] = 0;
  return j + 2 + 2;
}

uint16 AnimtilesInstr_SpawnPalfxObj(uint16 k, uint16 j) {  // 0x878372
  //const uint16 *v2 = (const uint16 *)RomPtr_87(j);
  SpawnPalfxObject(get_AnimtilesEntry(j).palfx_id);
  return j + 2 + 2;
}

uint16 AnimtilesInstr_Write8PaletteColors(uint16 k, uint16 j) {  // 0x87837F
  static const uint16 kAnimtilesInstr_Write8PaletteColors[8] = { 0x3800, 0x7f58, 0x6ed5, 0x5a71, 0x49ee, 0x356a, 0x24e7, 0x1083 };

  uint16 v2 = get_AnimtilesEntry(j).palette_offset;
  for (int i = 0; i != 16; i += 2) {
    target_palettes[v2 >> 1] = kAnimtilesInstr_Write8PaletteColors[i >> 1];
    v2 += 2;
  }
  return j + 2 + 2;
}
