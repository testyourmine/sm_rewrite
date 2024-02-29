// $B2 - Enemy AI - space pirates
#include "ida_types.h"
#include "variables.h"
#include "funcs.h"
#include "enemy_types.h"
#include "sm_b2.h"





void Enemy_GrappleReact_CancelBeam_B2(void) {  // 0xB2800F
  Enemy_SwitchToFrozenAi();
}

void Enemy_NormalFrozenAI_B2(void) {  // 0xB28041
  NormalEnemyFrozenAI();
}

void SpacePirates_Powerbomb(void) {  // 0xB28767
  NormalEnemyPowerBombAi();
}

void SpacePirates_TouchAi(void) {  // 0xB2876C
  if (!Get_SpacePirates(cur_enemy_index)->base.frozen_timer)
    NormalEnemyTouchAi();
}

void SpacePirates_ShotAi(void) {  // 0xB28779
  if (Get_SpacePirates(cur_enemy_index)->base.enemy_ptr == addr_kEnemyDef_GoldNinjaSpacePirate)
    SpacePirates_NormalShot();
  else
    NormalEnemyShotAi();
}

void SpacePirates_NormalShot(void) {  // 0xB28789
  Enemy_SpacePirates *E = Get_SpacePirates(cur_enemy_index);
  special_death_item_drop_x_origin_pos = E->base.x_pos;
  special_death_item_drop_y_origin_pos = E->base.y_pos;
  NormalEnemyShotAiSkipDeathAnim_CurEnemy();
  if (!E->base.health) {
    uint16 v1 = cur_enemy_index;
    if (E->base.enemy_ptr == addr_kEnemyDef_GoldNinjaSpacePirate) {
      E->ai_unused = 0;
      EnemyDeathAnimation(v1, 4);
      Enemy_ItemDrop_LowerNorfairSpacePirate(v1);
    } else {
      E->ai_unused = 0;
      EnemyDeathAnimation(v1, 4);
    }
  }
}

void SpacePirates_Shot_LowerNorfairPirateVulnerable(void) {  // 0xB287C8
  Vulnerability *v2;
  int16 v3;
  Vulnerability *v;

  if (Get_SpacePirates(cur_enemy_index)->base.enemy_ptr != addr_kEnemyDef_GoldNinjaSpacePirate)
    goto LABEL_2;
  uint16 r18 = projectile_type[collision_detection_index];
  if (sign16((r18 & kProjectileType_TypeMask) - kProjectileType_PowerBomb)) {
    uint16 enemy_ptr;
    uint16 vulnerability_ptr;
    enemy_ptr = Get_SpacePirates(cur_enemy_index)->base.enemy_ptr;
    vulnerability_ptr = get_EnemyDef_A2(enemy_ptr)->vulnerability_ptr;
    if (!vulnerability_ptr)
      vulnerability_ptr = addr_kEnemyVulnerability;
    uint16 r20 = vulnerability_ptr;
    if ((r18 & kProjectileType_TypeMask) != 0) {
      if ((r18 & kProjectileType_TypeMask) != kProjectileType_Missile && (r18 & kProjectileType_TypeMask) != kProjectileType_SuperMissile)
        goto LABEL_2;
      v3 = (uint16)(r18 & kProjectileType_TypeMask) >> 8;
      v = get_Vulnerability(r20 + v3);
      if ((v->plasma_ice_wave & 0xF) != 0 && (v->plasma_ice_wave & 0xF) != 15)
        goto LABEL_2;
    } else {
      v2 = get_Vulnerability(r20 + (r18 & 0xF));
      if ((v2->power & 0xF) != 0 && (v2->power & 0xF) != 15) {
LABEL_2:
        SpacePirates_NormalShot();
        return;
      }
    }
    SpacePirates_Shot_LowerNorfairPirateInvincible();
  }
}

void SpacePirates_Shot_LowerNorfairPirateInvincible(void) {  // 0xB2883E
  if (Get_SpacePirates(cur_enemy_index)->base.enemy_ptr != addr_kEnemyDef_GoldNinjaSpacePirate) {
    SpacePirates_NormalShot();
    return;
  }
  uint16 v0 = 2 * collision_detection_index;
  int v1 = collision_detection_index;
  uint16 r18 = projectile_type[v1];
  if ((r18 & kProjectileType_TypeMask) == kProjectileType_SuperMissile) {
    if (!projectile_variables[v1])
      return;
  } else if (!sign16((r18 & kProjectileType_TypeMask) - kProjectileType_PowerBomb)) {
    return;
  }
  Get_SpacePirates(cur_enemy_index)->base.invincibility_timer = 10;
  uint16 v2;
  if ((projectile_dir[v1] & kProjectileDir_DirMask) == kProjectileDir_Left) {
    v2 = kProjectileDir_UpRight;
  } else if ((projectile_dir[v1] & kProjectileDir_DirMask) == kProjectileDir_Right) {
    v2 = kProjectileDir_UpLeft;
  } else {
    v2 = kProjectileDir_DownFaceLeft;
  }
  projectile_dir[v1] = v2;
  ProjectileReflection(v0);
  QueueSfx2_Max6(kSfx2_ShotKiHunter_WalkingSpacePirate_SpacePirateAttack);
}

const uint16 *WallSpacePirates_Instr_MovePixelsDownAndChangeDirFaceRight(uint16 k, const uint16 *jp) {  // 0xB2EE40
  if (!(Enemy_MoveDown(cur_enemy_index, INT16_SHL16(jp[0]))))
    return jp + 1;
  Enemy_SpacePirates *E = Get_SpacePirates(cur_enemy_index);
  E->sps_var_C ^= 1;
  if (E->sps_var_C)
    return INSTR_RETURN_ADDR(addr_kWallSpacePirates_Ilist_MoveUpLWall);
  return INSTR_RETURN_ADDR(addr_kWallSpacePirates_Ilist_MoveDownLWall);
}

const uint16 *WallSpacePirates_Instr_MovePixelsDownAndChangeDirFaceLeft(uint16 k, const uint16 *jp) {  // 0xB2EE72
  if (!(Enemy_MoveDown(cur_enemy_index, INT16_SHL16(jp[0]))))
    return jp + 1;
  Enemy_SpacePirates *E = Get_SpacePirates(cur_enemy_index);
  E->sps_var_C ^= 1;
  if (E->sps_var_C)
    return INSTR_RETURN_ADDR(addr_kWallSpacePirates_Ilist_MoveUpRWall);
  return INSTR_RETURN_ADDR(addr_kWallSpacePirates_Ilist_MoveDownRWall);
}

const uint16 *WallSpacePirates_Instr_RandomNewDirFaceR(uint16 k, const uint16 *jp) {  // 0xB2EEA4
  uint16 result = addr_kWallSpacePirates_Ilist_MoveDownLWall;
  uint16 v4 = NextRandom() & 1;
  Get_SpacePirates(cur_enemy_index)->sps_var_C = v4;
  if (v4)
    return INSTR_RETURN_ADDR(addr_kWallSpacePirates_Ilist_MoveUpLWall);
  return INSTR_RETURN_ADDR(result);
}

const uint16 *WallSpacePirates_Instr_RandomNewDirFaceL(uint16 k, const uint16 *jp) {  // 0xB2EEBC
  uint16 result = addr_kWallSpacePirates_Ilist_MoveDownRWall;
  uint16 v4 = NextRandom() & 1;
  Get_SpacePirates(cur_enemy_index)->sps_var_C = v4;
  if (v4)
    return INSTR_RETURN_ADDR(addr_kWallSpacePirates_Ilist_MoveUpRWall);
  return INSTR_RETURN_ADDR(result);
}

const uint16 *WallSpacePirates_Instr_PrepareWallJumpR(uint16 k, const uint16 *jp) {  // 0xB2EED4
  Enemy_SpacePirates *E = Get_SpacePirates(cur_enemy_index);
  E->ai_unused = E->base.x_pos + E->sps_parameter_2;
  E->walljump_arc_center_x_pos = E->base.x_pos + (E->sps_parameter_2 >> 1);
  E->walljump_arc_center_y_pos = E->base.y_pos;
  E->walljump_arc_angle = 64;
  return jp;
}

const uint16 *WallSpacePirates_Instr_PrepareWallJumpL(uint16 k, const uint16 *jp) {  // 0xB2EEFD
  Enemy_SpacePirates *E = Get_SpacePirates(cur_enemy_index);
  E->ai_unused = E->base.x_pos - E->sps_parameter_2;
  E->walljump_arc_center_x_pos = E->base.x_pos - (E->sps_parameter_2 >> 1);
  E->walljump_arc_center_y_pos = E->base.y_pos;
  E->walljump_arc_angle = 192;
  return jp;
}

const uint16 *WallSpacePirates_Instr_FireLaserL(uint16 k, const uint16 *jp) {  // 0xB2EF2A
  Enemy_SpacePirates *E = Get_SpacePirates(cur_enemy_index);
  eproj_init_param_0 = *((uint16 *)RomPtr_A0(E->base.enemy_ptr) + 3);
  eproj_spawn_pt = (Point16U){ .x = E->base.x_pos - 24, .y = E->base.y_pos - 16 };
  eproj_spawn_r22 = 0;
  SpawnEprojWithRoomGfx(addr_kEprojDef_PirateAndMotherBrainLaser, 0);
  return jp;
}

const uint16 *WallSpacePirates_Instr_FireLaserR(uint16 k, const uint16 *jp) {  // 0xB2EF5D
  Enemy_SpacePirates *E = Get_SpacePirates(cur_enemy_index);
  eproj_spawn_pt = (Point16U){ .x = E->base.x_pos + 24, .y = E->base.y_pos - 16 };
  eproj_spawn_r22 = 1;
  SpawnEprojWithRoomGfx(addr_kEprojDef_PirateAndMotherBrainLaser, 1);
  return jp;
}

const uint16 *WallSpacePirates_Instr_SetEnemyFunc(uint16 k, const uint16 *jp) {  // 0xB2EF83
  Get_SpacePirates(cur_enemy_index)->func_ptr = jp[0];
  return jp + 1;
}

const uint16 *WallSpacePirates_Instr_PlaySpacePirateAttackSfx(uint16 k, const uint16 *jp) {  // 0xB2EF93
  QueueSfx2_Max6(kSfx2_ShotKiHunter_WalkingSpacePirate_SpacePirateAttack);
  return jp;
}

void WallSpacePirates_Init(void) {  // 0xB2EF9F
  uint16 v0 = addr_kWallSpacePirates_Ilist_MoveDownLWall;
  Enemy_SpacePirates *E = Get_SpacePirates(cur_enemy_index);
  if ((E->sps_parameter_1 & 1) != 0)
    v0 = addr_kWallSpacePirates_Ilist_MoveDownRWall;
  E->base.current_instruction = v0;
  E->walljump_arc_right_target_angle = 190;
  E->walljump_arc_left_target_angle = 66;
  E->walljump_arc_angle_delta = 2;
  if ((E->sps_parameter_1 & 0x8000) == 0) {
    E->walljump_arc_right_target_angle += 2;
    E->walljump_arc_left_target_angle -= 2;
    E->walljump_arc_angle_delta += 2;
  }
  uint16 v2 = FUNC16(WallSpacePirates_Func_ClimbLWall);
  if ((E->sps_parameter_1 & 1) != 0)
    v2 = FUNC16(WallSpacePirates_Func_ClimbRWall);
  E->func_ptr = v2;
  uint16 v3;
  if (sign16((E->base.x_pos & 0xF) - 11))
    v3 = E->base.x_pos & 0xFFF8;
  else
    v3 = (E->base.x_pos & 0xFFF0) + 16;
  E->base.x_pos = v3;
}

void CallSpacePiratesEnemyFunc(uint32 ea, uint16 k) {
  switch (ea) {
  case fnnullsub_169_B2: return;  // 0xb2804b
  case fnWallSpacePirates_Func_ClimbLWall: WallSpacePirates_Func_ClimbLWall(k); return;  // 0xb2f034
  case fnnullsub_279: return;  // 0xb2f04f
  case fnWallSpacePirates_Func_WallJumpR: WallSpacePirates_Func_WallJumpR(k); return;  // 0xb2f050
  case fnWallSpacePirates_Func_ClimbRWall: WallSpacePirates_Func_ClimbRWall(k); return;  // 0xb2f0c8
  case fnnullsub_281: return;  // 0xb2f0e3
  case fnnullsub_282: return;
  case fnWallSpacePirates_Func_WallJumpL: WallSpacePirates_Func_WallJumpL(k); return;  // 0xb2f0e4
  case fnNinjaSpacePirates_Func_Initial: NinjaSpacePirates_Func_Initial(k); return;  // 0xb2f6a9
  case fnNinjaSpacePirates_Func_Active: NinjaSpacePirates_Func_Active(k); return;  // 0xb2f6e4
  case fnNinjaSpacePirates_Func_SpinJumpL_Rise: NinjaSpacePirates_Func_SpinJumpL_Rise(k); return;  // 0xb2f817
  case fnNinjaSpacePirates_Func_SpinJumpL_Fall: NinjaSpacePirates_Func_SpinJumpL_Fall(k); return;
  case fnNinjaSpacePirates_Func_SpinJumpR_Rise: NinjaSpacePirates_Func_SpinJumpR_Rise(k); return;  // 0xb2f890
  case fnNinjaSpacePirates_Func_SpinJumpR_Fall: NinjaSpacePirates_Func_SpinJumpR_Fall(k); return;  // 0xb2f8c5
  case fnNinjaSpacePirates_Func_DivekickReady: NinjaSpacePirates_Func_DivekickReady(k); return;  // 0xb2f909
  case fnNinjaSpacePirates_Func_DivekickL_Jump: NinjaSpacePirates_Func_DivekickL_Jump(k); return;  // 0xb2f985
  case fnNinjaSpacePirates_Func_DivekickL_Divekick: NinjaSpacePirates_Func_DivekickL_Divekick(k); return;  // 0xb2f9c1
  case fnNinjaSpacePirates_Func_DivekickL_WalkToLeftPost: NinjaSpacePirates_Func_DivekickL_WalkToLeftPost(k); return;  // 0xb2fa15
  case fnNinjaSpacePirates_Func_DivekickR_Jump: NinjaSpacePirates_Func_DivekickR_Jump(k); return;  // 0xb2fa59
  case fnNinjaSpacePirates_Func_DivekickR_Divekick: NinjaSpacePirates_Func_DivekickR_Divekick(k); return;  // 0xb2fa95
  case fnNinjaSpacePirates_Func_DivekickR_WalkToRightPost: NinjaSpacePirates_Func_DivekickR_WalkToRightPost(k); return;  // 0xb2fae9
  case fnWalkingSpacePirates_Func_WalkL: WalkingSpacePirates_Func_WalkL(); return;
  case fnWalkingSpacePirates_Func_WalkR: WalkingSpacePirates_Func_WalkR(); return;
  default: Unreachable();
  }
}

void WallSpacePirates_Main(void) {  // 0xB2F02D
  EnemyData *v0 = gEnemyData(cur_enemy_index);
  CallSpacePiratesEnemyFunc(v0->ai_var_A | 0xB20000, cur_enemy_index);
}

void WallSpacePirates_Func_ClimbLWall(uint16 k) {  // 0xB2F034
  if (IsSamusWithinEnemy_Y(cur_enemy_index, 0x20)) {
    Enemy_SpacePirates *E = Get_SpacePirates(cur_enemy_index);
    E->base.current_instruction = addr_kWallSpacePirates_Ilist_FireLaser_WallJumpR;
    E->base.instruction_timer = 1;
  }
}

void WallSpacePirates_Func_WallJumpR(uint16 k) {  // 0xB2F050
  Enemy_SpacePirates *E = Get_SpacePirates(cur_enemy_index);
  E->base.x_pos = E->walljump_arc_center_x_pos + SineMult8bit(E->walljump_arc_angle, E->sps_parameter_2 >> 1);
  E->base.y_pos = E->walljump_arc_center_y_pos - CosineMult8bit(E->walljump_arc_angle, E->sps_parameter_2 >> 2);
  uint16 v1 = (uint8)(LOBYTE(E->walljump_arc_angle) - LOBYTE(E->walljump_arc_angle_delta));
  E->walljump_arc_angle = v1;
  if (v1 == E->walljump_arc_right_target_angle) {
    E->base.current_instruction = addr_kWallSpacePirates_Ilist_LandedRWall;
    E->base.instruction_timer = 1;
    uint16 v2;
    if (sign16((E->base.x_pos & 0xF) - 11))
      v2 = E->base.x_pos & 0xFFF8;
    else
      v2 = (E->base.x_pos & 0xFFF0) + 16;
    E->base.x_pos = v2;
  }
}

void WallSpacePirates_Func_ClimbRWall(uint16 k) {  // 0xB2F0C8
  if (IsSamusWithinEnemy_Y(cur_enemy_index, 0x20)) {
    Enemy_SpacePirates *E = Get_SpacePirates(cur_enemy_index);
    E->base.current_instruction = addr_kWallSpacePirates_Ilist_FireLaser_WallJumpL;
    E->base.instruction_timer = 1;
  }
}

void WallSpacePirates_Func_WallJumpL(uint16 k) {  // 0xB2F0E4
  Enemy_SpacePirates *E = Get_SpacePirates(cur_enemy_index);
  E->base.x_pos = E->walljump_arc_center_x_pos + SineMult8bit(E->walljump_arc_angle, E->sps_parameter_2 >> 1);
  E->base.y_pos = E->walljump_arc_center_y_pos - CosineMult8bit(E->walljump_arc_angle, E->sps_parameter_2 >> 2);
  uint16 v1 = (uint8)(LOBYTE(E->walljump_arc_angle_delta) + LOBYTE(E->walljump_arc_angle));
  E->walljump_arc_angle = v1;
  if (v1 == E->walljump_arc_left_target_angle) {
    E->base.current_instruction = addr_kWallSpacePirates_Ilist_LandedLWall;
    E->base.instruction_timer = 1;
    uint16 v2;
    if (sign16((E->base.x_pos & 0xF) - 11))
      v2 = E->base.x_pos & 0xFFF8;
    else
      v2 = (E->base.x_pos & 0xFFF0) + 16;
    E->base.x_pos = v2;
  }
}

const uint16 *NinjaSpacePirates_Instr_SetPaletteIndex(uint16 k, const uint16 *jp) {  // 0xB2F536
  Get_SpacePirates(cur_enemy_index)->base.palette_index = jp[0];
  return jp + 1;
}

const uint16 *NinjaSpacePirates_Instr_QueueSfx2_Max6(uint16 k, const uint16 *jp) {  // 0xB2F546
  QueueSfx2_Max6(jp[0]);
  return jp + 1;
}

void NinjaSpacePirates_Instr_GoToEnemy_Unused(void) {  // 0xB2F554
  gEnemyData(cur_enemy_index)->instruction_timer = 1;
}

const uint16 *NinjaSpacePirates_Instr_SpawnEprojPirateClaw(uint16 k, const uint16 *jp) {  // 0xB2F564
  Enemy_SpacePirates *E = Get_SpacePirates(cur_enemy_index);
  eproj_spawn_rect = (Rect16U){ .x = E->base.x_pos, .y = E->base.y_pos, .w = jp[1], .h = jp[2] };
  SpawnEprojWithGfx(jp[0], cur_enemy_index, addr_kEproj_PirateClaw);
  return jp + 3;
}

const uint16 *NinjaSpacePirates_Instr_SetAiActive(uint16 k, const uint16 *jp) {  // 0xB2F590
  Enemy_SpacePirates *E = Get_SpacePirates(cur_enemy_index);
  E->base.instruction_timer = 1;
  E->sps_var_C = (((E->base.x_pos - samus_x_pos) & 0x8000) != 0) ? addr_kNinjaSpacePirates_Ilist_Active_FaceR : addr_kNinjaSpacePirates_Ilist_Active_FaceL;
  return INSTR_RETURN_ADDR(E->sps_var_C);
}

void NinjaSpacePirates_Instr_SetAiStandKick_Unused(void) {  // 0xB2F5B3
  EnemyData *v0 = gEnemyData(cur_enemy_index);
  v0->instruction_timer = 1;
  v0->ai_var_C = (((v0->x_pos - samus_x_pos) & 0x8000) != 0) ? addr_kNinjaSpacePirates_Ilist_StandKick_FaceR : addr_kNinjaSpacePirates_Ilist_StandKick_FaceL;
}

const uint16 *NinjaSpacePirates_Instr_ResetXSpeed(uint16 k, const uint16 *jp) {  // 0xB2F5D6
  Get_SpacePirates(k)->x_pos_backup = 0;
  return jp;
}

void NinjaSpacePirates_Init(void) {  // 0xB2F5DE
  Enemy_SpacePirates *E = Get_SpacePirates(cur_enemy_index);
  E->base.current_instruction = (E->sps_parameter_1 & 1) != 0 ? addr_kNinjaSpacePirates_Ilist_Initial_FaceR : addr_kNinjaSpacePirates_Ilist_Initial_FaceL;
  E->sps_var_C = E->base.current_instruction;
  uint16 x_pos = E->base.x_pos;
  if ((E->sps_parameter_1 & 1) != 0) {
    E->walljump_arc_center_y_pos = x_pos;
    E->walljump_arc_angle = E->sps_parameter_2 + x_pos;
  } else {
    E->walljump_arc_angle = x_pos;
    E->walljump_arc_center_y_pos = x_pos - E->sps_parameter_2;
  }
  uint16 r20 = (uint16)(E->walljump_arc_angle - E->walljump_arc_center_y_pos) >> 1;
  E->walljump_arc_center_x_pos = E->walljump_arc_center_y_pos + r20;
  uint16 r18 = 0;
  uint16 R22 = 0;
  r20 = (uint8)r20 << 8;
  do {
    r18 += 32;
    R22 += r18;
  } while (sign16(R22 - r20));
  E->ai_unused = r18;
  uint16 R24 = (R22 & 0xFF00) >> 8;
  E->walljump_arc_angle = E->walljump_arc_center_x_pos + R24;
  E->walljump_arc_center_y_pos = E->walljump_arc_center_x_pos - R24;
  uint16 sps_var_E = E->walljump_arc_center_y_pos;
  if ((E->sps_parameter_1 & 1) == 0)
    sps_var_E = E->walljump_arc_angle;
  E->base.x_pos = sps_var_E;
  E->func_ptr = FUNC16(nullsub_169_B2);
  E->sps_var_08 = E->base.y_pos;
  uint16 v6 = 0;
  uint16 v7 = 0;
  int n = 15;
  do {
    target_palettes[(v7 >> 1) + 240] = kWallSpacePirates_Palette_3[v6 >> 1];
    v6 += 2;
    v7 += 2;
  } while (--n >= 0);
}

void NinjaSpacePirates_Main(void) {  // 0xB2F6A2
  Enemy_SpacePirates *E = Get_SpacePirates(cur_enemy_index);
  CallSpacePiratesEnemyFunc(E->func_ptr | 0xB20000, cur_enemy_index);
}

void NinjaSpacePirates_Func_Initial(uint16 k) {  // 0xB2F6A9
  Enemy_SpacePirates *E = Get_SpacePirates(cur_enemy_index);
  if ((int16)(abs16(E->base.x_pos - samus_x_pos) - 128) >= 0) {
    NinjaSpacePirates_FlinchTrigger();
  } else {
    E->base.current_instruction = ((E->base.x_pos - samus_x_pos) & 0x8000) ? addr_kNinjaSpacePirates_Ilist_Active_FaceR : addr_kNinjaSpacePirates_Ilist_Active_FaceL;
    E->sps_var_C = E->base.current_instruction;
    E->base.instruction_timer = 1;
  }
}

void NinjaSpacePirates_Func_Active(uint16 k) {  // 0xB2F6E4
  if (!NinjaSpacePirates_FlinchTrigger() && !NinjaSpacePirates_StandKickTrigger() && !NinjaSpacePirates_SpinJumpTrigger())
    NinjaSpacePirates_ProjClawAttackTrigger(k);
}

void NinjaSpacePirates_ProjClawAttackTrigger(uint16 k) {  // 0xB2F6F7
  Enemy_SpacePirates *E = Get_SpacePirates(k);
  if ((E->base.frame_counter & 0x3F) == 0) {
    if (E->base.x_pos == E->walljump_arc_center_y_pos) {
      if ((int16)(E->base.x_pos - samus_x_pos) < 0)
        return;
      E->base.current_instruction = addr_kNinjaSpacePirates_Ilist_ProjClawAttackL;
    } else {
      if ((int16)(E->base.x_pos - samus_x_pos) >= 0)
        return;
      E->base.current_instruction = addr_kNinjaSpacePirates_Ilist_ProjClawAttackR;
    }
    E->base.instruction_timer = 1;
  }
}

uint16 NinjaSpacePirates_FlinchTrigger(void) {  // 0xB2F72E
  uint16 v0 = 8;
  while (!projectile_type[v0 >> 1]) {
    v0 -= 2;
    if ((v0 & 0x8000) != 0)
      return 0;
  }
  int v1 = v0 >> 1;
  Enemy_SpacePirates *E = Get_SpacePirates(cur_enemy_index);
  if ((int16)(abs16(projectile_x_pos[v1] - E->base.x_pos) - 32) >= 0
      || (int16)(abs16(projectile_y_pos[v1] - E->base.y_pos) - 32) >= 0) {
    return 0;
  }
  E->base.current_instruction = (E->base.x_pos - samus_x_pos & 0x8000) ? addr_kNinjaSpacePirates_Ilist_Flinch_FaceR : addr_kNinjaSpacePirates_Ilist_Flinch_FaceL;
  E->base.instruction_timer = 1;
  return 1;
}

uint16 NinjaSpacePirates_SpinJumpTrigger(void) {  // 0xB2F78D
  Enemy_SpacePirates *E = Get_SpacePirates(cur_enemy_index);
  if ((int16)(abs16(E->walljump_arc_center_x_pos - samus_x_pos) - 32) >= 0)
    return 0;
  uint16 v1 = addr_kNinjaSpacePirates_Ilist_SpinJumpL;
  if (E->base.x_pos == E->walljump_arc_center_y_pos)
    v1 = addr_kNinjaSpacePirates_Ilist_SpinJumpR;
  E->base.current_instruction = v1;
  E->base.instruction_timer = 1;
  return 1;
}

uint16 NinjaSpacePirates_StandKickTrigger(void) {  // 0xB2F7C6
  Enemy_SpacePirates *E = Get_SpacePirates(cur_enemy_index);
  if ((int16)(abs16(samus_x_pos - E->base.x_pos) - 40) >= 0
      || (int16)(abs16(samus_y_pos - E->base.y_pos) - 40) >= 0) {
    return 0;
  }
  E->base.current_instruction = ((E->base.x_pos - samus_x_pos) & 0x8000) != 0 ? addr_kNinjaSpacePirates_Ilist_StandKick_FaceR : addr_kNinjaSpacePirates_Ilist_StandKick_FaceL;
  E->base.instruction_timer = 1;
  return 1;
}

void NinjaSpacePirates_Func_SpinJumpL_Rise(uint16 k) {  // 0xB2F817
  Enemy_SpacePirates *E = Get_SpacePirates(k);
  E->base.x_pos -= HIBYTE(E->x_pos_backup);
  --E->base.y_pos;
  --E->base.y_pos;
  E->x_pos_backup += 32;
  if ((int16)(E->base.x_pos - E->walljump_arc_center_x_pos) < 0)
    E->func_ptr = FUNC16(NinjaSpacePirates_Func_SpinJumpL_Fall);
}

void NinjaSpacePirates_Func_SpinJumpL_Fall(uint16 k) {  // 0xB2F84C
  Enemy_SpacePirates *E = Get_SpacePirates(k);
  E->base.x_pos -= HIBYTE(E->x_pos_backup);
  ++E->base.y_pos;
  ++E->base.y_pos;
  uint16 v2 = E->x_pos_backup - 32;
  E->x_pos_backup = v2;
  if (!v2) {
    E->func_ptr = FUNC16(nullsub_169_B2);
    E->base.current_instruction = addr_kNinjaSpacePirates_Ilist_Land_FaceL;
    E->base.instruction_timer = 1;
    E->base.x_pos = E->walljump_arc_center_y_pos;
    NinjaSpacePirates_SpawnLandingDustCloud(k);
  }
}

void NinjaSpacePirates_Func_SpinJumpR_Rise(uint16 k) {  // 0xB2F890
  Enemy_SpacePirates *E = Get_SpacePirates(k);
  E->base.x_pos += HIBYTE(E->x_pos_backup);
  --E->base.y_pos;
  --E->base.y_pos;
  E->x_pos_backup += 32;
  if ((int16)(E->base.x_pos - E->walljump_arc_center_x_pos) >= 0)
    E->func_ptr = FUNC16(NinjaSpacePirates_Func_SpinJumpR_Fall);
}

void NinjaSpacePirates_Func_SpinJumpR_Fall(uint16 k) {  // 0xB2F8C5
  Enemy_SpacePirates *E = Get_SpacePirates(k);
  E->base.x_pos += HIBYTE(E->x_pos_backup);
  ++E->base.y_pos;
  ++E->base.y_pos;
  uint16 v2 = E->x_pos_backup - 32;
  E->x_pos_backup = v2;
  if (!v2) {
    E->func_ptr = FUNC16(nullsub_169_B2);
    E->base.current_instruction = addr_kNinjaSpacePirates_Ilist_Land_FaceR;
    E->base.instruction_timer = 1;
    E->base.x_pos = E->walljump_arc_angle;
    NinjaSpacePirates_SpawnLandingDustCloud(k);
  }
}

void NinjaSpacePirates_Func_DivekickReady(uint16 k) {  // 0xB2F909
  if (!NinjaSpacePirates_FlinchTrigger() && !NinjaSpacePirates_StandKickTrigger())
    NinjaSpacePirates_DivekickTrigger();
}

void NinjaSpacePirates_DivekickTrigger(void) {  // 0xB2F917
  int16 v3;

  Enemy_SpacePirates *E = Get_SpacePirates(cur_enemy_index);
  if ((int16)(abs16(E->walljump_arc_center_x_pos - samus_x_pos) - 32) < 0) {
    uint16 v2;
    do
      v2 = NextRandom() & 3;
    while (!v2);
    v3 = 0;
    if (E->base.x_pos == E->walljump_arc_center_y_pos)
      v3 = 4;
    E->base.current_instruction = kSpacePirate_DivekickRandomDir_InstrListPtrs[v2 + v3];
    E->base.instruction_timer = 1;
  }
}

const uint16 *NinjaSpacePirates_Instr_InitDivekickLJumpYSpeed(uint16 k, const uint16 *jp) {  // 0xB2F969
  Enemy_SpacePirates *E = Get_SpacePirates(k);
  E->x_pos_backup = 1536;
  E->sps_var_03 = E->walljump_arc_center_x_pos
    + ((uint16)(E->walljump_arc_angle - E->walljump_arc_center_x_pos) >> 1);
  return jp;
}

void NinjaSpacePirates_Func_DivekickL_Jump(uint16 k) {  // 0xB2F985
  int16 v2;

  Enemy_SpacePirates *E = Get_SpacePirates(k);
  E->base.y_pos -= HIBYTE(E->x_pos_backup);
  v2 = E->x_pos_backup - 64;
  E->x_pos_backup = v2;
  if (v2 < 0) {
    E->func_ptr = FUNC16(NinjaSpacePirates_Func_DivekickL_Divekick);
    E->base.current_instruction = addr_kNinjaSpacePirates_Ilist_DivekickL_Divekick;
    E->base.instruction_timer = 1;
    E->x_pos_backup = 1536;
  }
}

void NinjaSpacePirates_Func_DivekickL_Divekick(uint16 k) {  // 0xB2F9C1
  int16 v2;

  Enemy_SpacePirates *E = Get_SpacePirates(k);
  E->base.x_pos -= 5;
  if (Enemy_MoveDown(k, __PAIR32__(HIBYTE(E->x_pos_backup), LOBYTE(E->x_pos_backup)))
      || (v2 = E->x_pos_backup - 64, E->x_pos_backup = v2, v2 < 0)
      || (v2 & 0xFF00) == 0) {
    E->func_ptr = FUNC16(NinjaSpacePirates_Func_DivekickL_WalkToLeftPost);
    E->base.current_instruction = addr_kNinjaSpacePirates_Ilist_DivekickL_WalkToLeftPost;
    E->base.instruction_timer = 1;
    E->base.y_pos = E->sps_var_08;
    NinjaSpacePirates_SpawnLandingDustCloud(k);
  }
}

void NinjaSpacePirates_Func_DivekickL_WalkToLeftPost(uint16 k) {  // 0xB2FA15
  Enemy_SpacePirates *E = Get_SpacePirates(k);
  uint16 v2 = E->base.x_pos - 2;
  E->base.x_pos = v2;
  if ((int16)(v2 - E->walljump_arc_center_y_pos) < 0) {
    E->base.x_pos = E->walljump_arc_center_y_pos;
    E->base.current_instruction = addr_kNinjaSpacePirates_Ilist_Land_FaceL;
    E->base.instruction_timer = 1;
    E->func_ptr = FUNC16(nullsub_169_B2);
  }
}

const uint16 *NinjaSpacePirates_Instr_InitDivekickRJumpYSpeed(uint16 k, const uint16 *jp) {  // 0xB2FA3D
  Enemy_SpacePirates *E = Get_SpacePirates(k);
  E->x_pos_backup = 0x600;
  E->sps_var_03 = E->walljump_arc_center_y_pos
    + ((uint16)(E->walljump_arc_center_x_pos - E->walljump_arc_center_y_pos) >> 1);
  return jp;
}

void NinjaSpacePirates_Func_DivekickR_Jump(uint16 k) {  // 0xB2FA59
  int16 v2;

  Enemy_SpacePirates *E = Get_SpacePirates(k);
  E->base.y_pos -= HIBYTE(E->x_pos_backup);
  v2 = E->x_pos_backup - 64;
  E->x_pos_backup = v2;
  if (v2 < 0) {
    E->func_ptr = FUNC16(NinjaSpacePirates_Func_DivekickR_Divekick);
    E->base.current_instruction = addr_kNinjaSpacePirates_Ilist_DivekickR_Divekick;
    E->base.instruction_timer = 1;
    E->x_pos_backup = 0x600;
  }
}

void NinjaSpacePirates_Func_DivekickR_Divekick(uint16 k) {  // 0xB2FA95
  int16 v2;

  Enemy_SpacePirates *E = Get_SpacePirates(k);
  E->base.x_pos += 5;
  if (Enemy_MoveDown(k, __PAIR32__(HIBYTE(E->x_pos_backup), LOBYTE(E->x_pos_backup)))
      || (v2 = E->x_pos_backup - 64, E->x_pos_backup = v2, v2 < 0)
      || (v2 & 0xFF00) == 0) {
    E->func_ptr = FUNC16(NinjaSpacePirates_Func_DivekickR_WalkToRightPost);
    E->base.current_instruction = addr_kNinjaSpacePirates_Ilist_DivekickR_WalkToRightPost;
    E->base.instruction_timer = 1;
    E->base.y_pos = E->sps_var_08;
    NinjaSpacePirates_SpawnLandingDustCloud(k);
  }
}

void NinjaSpacePirates_Func_DivekickR_WalkToRightPost(uint16 k) {  // 0xB2FAE9
  Enemy_SpacePirates *E = Get_SpacePirates(k);
  uint16 v2 = E->base.x_pos + 2;
  E->base.x_pos = v2;
  if ((int16)(v2 - E->walljump_arc_angle) >= 0) {
    E->base.x_pos = E->walljump_arc_angle;
    E->base.current_instruction = addr_kNinjaSpacePirates_Ilist_Land_FaceR;
    E->base.instruction_timer = 1;
    E->func_ptr = FUNC16(nullsub_169_B2);
  }
}

void NinjaSpacePirates_SpawnLandingDustCloud(uint16 k) {  // 0xB2FB11
  Enemy_SpacePirates *E = Get_SpacePirates(k);
  CreateSpriteAtPos(E->base.x_pos - 8, E->base.y_pos + 28, 10, 0);
  CreateSpriteAtPos(E->base.x_pos + 8, E->base.y_pos + 28, 10, 0);
}

const uint16 *WalkingSpacePirates_Instr_FireLaserLOffsetY(uint16 k, const uint16 *jp) {  // 0xB2FC68
  Enemy_SpacePirates *E = Get_SpacePirates(cur_enemy_index);
  eproj_spawn_pt = (Point16U){ .x = E->base.x_pos - 24, .y = E->base.y_pos - jp[0] };
  eproj_spawn_r22 = 0;
  SpawnEprojWithRoomGfx(addr_kEprojDef_PirateAndMotherBrainLaser, 0);
  return jp + 1;
}

const uint16 *WalkingSpacePirates_Instr_FireLaserROffsetY(uint16 k, const uint16 *jp) {  // 0xB2FC90
  Enemy_SpacePirates *E = Get_SpacePirates(cur_enemy_index);
  eproj_spawn_pt = (Point16U){ .x = E->base.x_pos + 24, .y = E->base.y_pos - jp[0] };
  eproj_spawn_r22 = 1;
  SpawnEprojWithRoomGfx(addr_kEprojDef_PirateAndMotherBrainLaser, 1);
  return jp + 1;
}

const uint16 *WalkingSpacePirates_Instr_SetEnemyFunc(uint16 k, const uint16 *jp) {  // 0xB2FCB8
  Get_SpacePirates(cur_enemy_index)->func_ptr = jp[0];
  return jp + 1;
}

const uint16 *WalkingSpacePirates_Instr_ChooseDir_FireLaserIfClose(uint16 k, const uint16 *jp) {  // 0xB2FCC8
  if (IsSamusWithinEnemy_Y(cur_enemy_index, 0x10)) {
    if ((int16)(samus_x_pos - Get_SpacePirates(cur_enemy_index)->base.x_pos) >= 0)
      return INSTR_RETURN_ADDR(addr_kWalkingSpacePirates_Ilist_FireLasersR);
    return INSTR_RETURN_ADDR(addr_kWalkingSpacePirates_Ilist_FireLasersL);
  } else {
    if ((int16)(samus_x_pos - Get_SpacePirates(cur_enemy_index)->base.x_pos) >= 0)
      return INSTR_RETURN_ADDR(addr_kWalkingSpacePirates_Ilist_WalkL);
    return INSTR_RETURN_ADDR(addr_kWalkingSpacePirates_Ilist_WalkR);
  }
}

void WalkingSpacePirates_Init(void) {  // 0xB2FD02
  uint16 v0 = addr_kWalkingSpacePirates_Ilist_WalkL;
  Enemy_SpacePirates *E = Get_SpacePirates(cur_enemy_index);
  if ((E->sps_parameter_1 & 1) != 0)
    v0 = addr_kWalkingSpacePirates_Ilist_WalkR;
  E->base.current_instruction = v0;
  E->func_ptr = FUNC16(nullsub_169_B2);
  E->walljump_arc_angle = E->sps_parameter_2 + E->base.x_pos;
  E->walljump_arc_center_y_pos = E->base.x_pos - E->sps_parameter_2;
}

void WalkingSpacePirates_Main(void) {  // 0xB2FD32
  Enemy_SpacePirates *E = Get_SpacePirates(cur_enemy_index);
  CallSpacePiratesEnemyFunc(E->func_ptr | 0xB20000, cur_enemy_index);
  if ((E->sps_parameter_1 & 0x8000) != 0)
    WalkingSpacePirates_FlinchTrigger();
}

void WalkingSpacePirates_Func_WalkL(void) {  // 0xB2FD44
  Enemy_SpacePirates *E = Get_SpacePirates(cur_enemy_index);

  if (IsSamusWithinEnemy_Y(cur_enemy_index, 0x10)) {
    uint16 v1 = addr_kWalkingSpacePirates_Ilist_FireLasersL;
    if ((int16)(samus_x_pos - E->base.x_pos) >= 0)
      v1 = addr_kWalkingSpacePirates_Ilist_FireLasersR;
    E->base.current_instruction = v1;
    E->base.instruction_timer = 1;
  } else {
    if (Enemy_MoveDown(cur_enemy_index, INT16_SHL16(1))) {
      uint16 x_pos = E->base.x_pos;
      E->x_pos_backup = x_pos;
      E->base.x_pos = x_pos - 17;
      uint8 result = Enemy_MoveDown(cur_enemy_index, INT16_SHL16(1));
      E->base.x_pos = E->x_pos_backup;

      if (result) {
        EnemyFunc_BBBF(cur_enemy_index, INT16_SHL16(-9));
        if (!Enemy_MoveRight_IgnoreSlopes(cur_enemy_index, -14337)) {
          if ((int16)(E->base.x_pos - E->walljump_arc_center_y_pos) >= 0)
            return;
        }
      }
      E->base.current_instruction = addr_kWalkingSpacePirates_Ilist_LookAround_FaceL;
      E->base.instruction_timer = 1;
    }
  }
}

void WalkingSpacePirates_Func_WalkR(void) {  // 0xB2FDCE
  Enemy_SpacePirates *E = Get_SpacePirates(cur_enemy_index);

  if (IsSamusWithinEnemy_Y(cur_enemy_index, 0x10)) {
    uint16 v1 = addr_kWalkingSpacePirates_Ilist_FireLasersL;
    if ((int16)(samus_x_pos - E->base.x_pos) >= 0)
      v1 = addr_kWalkingSpacePirates_Ilist_FireLasersR;
    E->base.current_instruction = v1;
    E->base.instruction_timer = 1;
  } else {
    if (Enemy_MoveDown(cur_enemy_index, INT16_SHL16(1))) {
      uint16 x_pos = E->base.x_pos;
      E->x_pos_backup = x_pos;
      E->base.x_pos = x_pos + 16;
      uint8 result = Enemy_MoveDown(cur_enemy_index, INT16_SHL16(1));
      E->base.x_pos = E->x_pos_backup;
      if (!result ||
          (Enemy_MoveRight_IgnoreSlopes(cur_enemy_index, 14336)) ||
          (int16)(E->base.x_pos - E->walljump_arc_angle) >= 0) {
        E->base.current_instruction = addr_kWalkingSpacePirates_Ilist_LookAround_FaceR;
        E->base.instruction_timer = 1;
      }
    }
  }
}

void WalkingSpacePirates_FlinchTrigger(void) {  // 0xB2FE4B
  uint16 v0 = 8;
  while (!projectile_type[v0 >> 1]) {
    v0 -= 2;
    if ((v0 & 0x8000) != 0)
      return;
  }
  int v1 = v0 >> 1;
  Enemy_SpacePirates *E = Get_SpacePirates(cur_enemy_index);
  if ((int16)(abs16(projectile_x_pos[v1] - E->base.x_pos) - 32) < 0
      && (int16)(abs16(projectile_y_pos[v1] - E->base.y_pos) - 32) < 0) {
    E->base.current_instruction = ((E->base.x_pos - samus_x_pos) & 0x8000) ? addr_kWalkingSpacePirates_Ilist_Flinch_FaceR : addr_kWalkingSpacePirates_Ilist_Flinch_FaceL;
    E->base.instruction_timer = 1;
  }
}
