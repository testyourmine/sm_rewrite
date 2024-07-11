// Enemy AI - space pirates
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

/**
* @brief Runs the normal power bomb AI
*/
void SpacePirates_Powerbomb(void) {  // 0xB28767
  NormalEnemyPowerBombAi();
}

/**
* @brief Runs the normal touch AI if the space pirate is not frozen
*/
void SpacePirates_TouchAi(void) {  // 0xB2876C
  if (Get_SpacePirates(cur_enemy_index)->base.frozen_timer == 0)
    NormalEnemyTouchAi();
}

/**
* @brief Handles whether to run the space pirate shot or the normal shot function
*/
void SpacePirates_ShotAi(void) {  // 0xB28779
  if (Get_SpacePirates(cur_enemy_index)->base.enemy_ptr == addr_kEnemyDef_GoldNinjaSpacePirate)
    SpacePirates_NormalShot();
  else
    NormalEnemyShotAi();
}

/**
* @brief Handles space pirates getting shot and dying
*/
void SpacePirates_NormalShot(void) {  // 0xB28789
  Enemy_SpacePirates *E = Get_SpacePirates(cur_enemy_index);
  special_death_item_drop_x_origin_pos = E->base.x_pos;
  special_death_item_drop_y_origin_pos = E->base.y_pos;
  NormalEnemyShotAiSkipDeathAnim_CurEnemy();
  if (E->base.health == 0) {
    if (E->base.enemy_ptr == addr_kEnemyDef_GoldNinjaSpacePirate) {
      E->sps_var_B_unused = 0;
      EnemyDeathAnimation(cur_enemy_index, 4);
      Enemy_ItemDrop_LowerNorfairSpacePirate(cur_enemy_index);
    }
    else {
      E->sps_var_B_unused = 0;
      EnemyDeathAnimation(cur_enemy_index, 4);
    }
  }
}

/**
* @brief Handles whether the gold ninja space pirate is shot while vulnerable or while invincible
*/
void SpacePirates_Shot_LowerNorfairPirateVulnerable(void) {  // 0xB287C8
  Vulnerability* v;
  Enemy_SpacePirates *E = Get_SpacePirates(cur_enemy_index);

  if (E->base.enemy_ptr != addr_kEnemyDef_GoldNinjaSpacePirate) {
    SpacePirates_NormalShot();
    return;
  }
  uint16 proj_type = projectile_type[collision_detection_index];
  if ((proj_type & kProjectileType_ProjMask) < kProjectileType_PowerBomb) {
    uint16 enemy_ptr = E->base.enemy_ptr;
    uint16 vulnerability_ptr = get_EnemyDef_A2(enemy_ptr)->vulnerability_ptr;
    if (vulnerability_ptr == 0)
      vulnerability_ptr = addr_kEnemyVulnerability;

    if (proj_type & kProjectileType_ProjMask) {
      if ((proj_type & kProjectileType_ProjMask) != kProjectileType_Missile
          && (proj_type & kProjectileType_ProjMask) != kProjectileType_SuperMissile) {
        SpacePirates_NormalShot();
        return;
      }
      v = get_Vulnerability(vulnerability_ptr + GET_HIBYTE(proj_type & kProjectileType_ProjMask));
      uint16 weapon_dmg = v->plasma_ice_wave & 0xF;
      if (weapon_dmg != 0 && weapon_dmg != 15) {
        SpacePirates_NormalShot();
        return;
      }
    }
    else {
      v = get_Vulnerability(vulnerability_ptr + (proj_type & kProjectileType_BeamMask));
      uint16 beam_dmg = v->power & 0xF;
      if (beam_dmg != 0 && beam_dmg != 15) {
        SpacePirates_NormalShot();
        return;
      }
    }
    SpacePirates_Shot_LowerNorfairPirateInvincible();
  }
}

/**
* @brief Reflects the shot projectile off a gold ninja space pirate
*/
void SpacePirates_Shot_LowerNorfairPirateInvincible(void) {  // 0xB2883E
  Enemy_SpacePirates *E = Get_SpacePirates(cur_enemy_index);
  if (E->base.enemy_ptr != addr_kEnemyDef_GoldNinjaSpacePirate) {
    SpacePirates_NormalShot();
    return;
  }

  int idx = collision_detection_index;
  uint16 proj_type = projectile_type[idx];
  if ((proj_type & kProjectileType_ProjMask) == kProjectileType_SuperMissile) {
    // if super missile has link
    if (projectile_variables[idx] == 0)
      return;
  }
  else if ((proj_type & kProjectileType_ProjMask) >= kProjectileType_PowerBomb) {
    return;
  }
  E->base.invincibility_timer = 10;

  uint16 proj_dir;
  if ((projectile_dir[idx] & kProjectileDir_DirMask) == kProjectileDir_Left) {
    proj_dir = kProjectileDir_UpRight;
  }
  else if ((projectile_dir[idx] & kProjectileDir_DirMask) == kProjectileDir_Right) {
    proj_dir = kProjectileDir_UpLeft;
  }
  else {
    proj_dir = kProjectileDir_DownFaceLeft;
  }
  projectile_dir[idx] = proj_dir;
  ProjectileReflection(idx << 1);
  QueueSfx2_Max6(kSfx2_ShotKiHunter_WalkingSpacePirate_SpacePirateAttack);
}

/**
* @brief Moves down on the left wall by the amount of pixels specified by the instruction list and changes vertical direction
* @param enemy_idx The current index of the enemy
* @param enemy_ptr* The pointer to the enemy instruction list
* @return uint16* The pointer to the next instruction if there was no collision, otherwise the instruction
* for the new vertical direction
*/
const uint16 *WallSpacePirates_Instr_MovePixelsDownAndChangeDirFaceRight(uint16 enemy_idx, const uint16 *enemy_ptr) {  // 0xB2EE40
  if (!(Enemy_MoveDown(cur_enemy_index, INT16_SHL16(enemy_ptr[0]))))
    return enemy_ptr + 1;
  Enemy_SpacePirates *E = Get_SpacePirates(cur_enemy_index);
  E->direction ^= 1;  // up
  if (E->direction != 0)  // not down
    return INSTR_RETURN_ADDR(addr_kWallSpacePirates_Ilist_MoveUpLWall);
  return INSTR_RETURN_ADDR(addr_kWallSpacePirates_Ilist_MoveDownLWall);
}

/**
* @brief Moves down on the left wall by the amount of pixels specified by the instruction list and changes vertical direction
* @param enemy_idx The current index of the enemy
* @param enemy_ptr* The pointer to the enemy instruction list
* @return uint16* The pointer to the next instruction if there was no collision, otherwise the instruction
* for the new vertical direction
*/
const uint16 *WallSpacePirates_Instr_MovePixelsDownAndChangeDirFaceLeft(uint16 enemy_idx, const uint16 *enemy_ptr) {  // 0xB2EE72
  if (!(Enemy_MoveDown(cur_enemy_index, INT16_SHL16(enemy_ptr[0]))))
    return enemy_ptr + 1;
  Enemy_SpacePirates *E = Get_SpacePirates(cur_enemy_index);
  E->direction ^= 1;  // up
  if (E->direction != 0)  // not down
    return INSTR_RETURN_ADDR(addr_kWallSpacePirates_Ilist_MoveUpRWall);
  return INSTR_RETURN_ADDR(addr_kWallSpacePirates_Ilist_MoveDownRWall);
}

/**
* @brief Chooses a random vertical direction while on the left wall
* @param enemy_idx The current index of the enemy
* @param enemy_ptr* The pointer to the enemy instruction list
* @return uint16* The pointer to the instruction for the new vertical direction
*/
const uint16 *WallSpacePirates_Instr_RandomNewDirFaceR(uint16 enemy_idx, const uint16 *enemy_ptr) {  // 0xB2EEA4
  uint16 Random = NextRandom() & 1;
  Get_SpacePirates(cur_enemy_index)->direction = Random;
  if (Random != 0)  // not down
    return INSTR_RETURN_ADDR(addr_kWallSpacePirates_Ilist_MoveUpLWall);
  return INSTR_RETURN_ADDR(addr_kWallSpacePirates_Ilist_MoveDownLWall);
}

/**
* @brief Chooses a random vertical direction while on the right wall
* @param enemy_idx The current index of the enemy
* @param enemy_ptr* The pointer to the enemy instruction list
* @return uint16* The pointer to the instruction for the new vertical direction
*/
const uint16 *WallSpacePirates_Instr_RandomNewDirFaceL(uint16 enemy_idx, const uint16 *enemy_ptr) {  // 0xB2EEBC
  uint16 Random = NextRandom() & 1;
  Get_SpacePirates(cur_enemy_index)->direction = Random;
  if (Random != 0)  // not down
    return INSTR_RETURN_ADDR(addr_kWallSpacePirates_Ilist_MoveUpRWall);
  return INSTR_RETURN_ADDR(addr_kWallSpacePirates_Ilist_MoveDownRWall);
}

/**
* @brief Sets the arc for the wall jump towards the right
* @param enemy_idx The current index of the enemy
* @param enemy_ptr* The pointer to the enemy instruction list
* @return uint16* The pointer to the next instruction
*/
const uint16 *WallSpacePirates_Instr_PrepareWallJumpR(uint16 enemy_idx, const uint16 *enemy_ptr) {  // 0xB2EED4
  Enemy_SpacePirates *E = Get_SpacePirates(cur_enemy_index);
  E->sps_var_B_unused = E->base.x_pos + E->sps_parameter_2;
  E->walljump_arc_center_x_pos = E->base.x_pos + (E->sps_parameter_2 / 2);
  E->walljump_arc_center_y_pos = E->base.y_pos;
  E->walljump_arc_angle = 64;
  return enemy_ptr;
}

/**
* @brief Sets the arc for the wall jump towards the left
* @param enemy_idx The current index of the enemy
* @param enemy_ptr* The pointer to the enemy instruction list
* @return uint16* The pointer to the next instruction
*/
const uint16 *WallSpacePirates_Instr_PrepareWallJumpL(uint16 enemy_idx, const uint16 *enemy_ptr) {  // 0xB2EEFD
  Enemy_SpacePirates *E = Get_SpacePirates(cur_enemy_index);
  E->sps_var_B_unused = E->base.x_pos - E->sps_parameter_2;
  E->walljump_arc_center_x_pos = E->base.x_pos - (E->sps_parameter_2 / 2);
  E->walljump_arc_center_y_pos = E->base.y_pos;
  E->walljump_arc_angle = 192;
  return enemy_ptr;
}

/**
* @brief Spawns a laser projectile leftwards
* @param enemy_idx The current index of the enemy
* @param enemy_ptr* The pointer to the enemy instruction list
* @return uint16* The pointer to the next instruction
*/
const uint16 *WallSpacePirates_Instr_FireLaserL(uint16 enemy_idx, const uint16 *enemy_ptr) {  // 0xB2EF2A
  Enemy_SpacePirates *E = Get_SpacePirates(cur_enemy_index);
  eproj_init_param_0 = *((uint16 *)RomPtr_A0(E->base.enemy_ptr) + 3);
  eproj_spawn_pt = (Point16U){ .x = E->base.x_pos - 24, .y = E->base.y_pos - 16 };
  eproj_spawn_r22 = 0;
  SpawnEprojWithRoomGfx(addr_kEprojDef_PirateAndMotherBrainLaser, 0);
  return enemy_ptr;
}

/**
* @brief Spawns a laser projectile rightwards
* @param enemy_idx The current index of the enemy
* @param enemy_ptr* The pointer to the enemy instruction list
* @return uint16* The pointer to the next instruction
*/
const uint16 *WallSpacePirates_Instr_FireLaserR(uint16 enemy_idx, const uint16 *enemy_ptr) {  // 0xB2EF5D
  Enemy_SpacePirates *E = Get_SpacePirates(cur_enemy_index);
  eproj_spawn_pt = (Point16U){ .x = E->base.x_pos + 24, .y = E->base.y_pos - 16 };
  eproj_spawn_r22 = 1;
  SpawnEprojWithRoomGfx(addr_kEprojDef_PirateAndMotherBrainLaser, 1);
  return enemy_ptr;
}

/**
* @brief Sets the enemy function specified by the instruction
* @param enemy_idx The current index of the enemy
* @param enemy_ptr* The pointer to the enemy instruction list
* @return uint16* The pointer to the next instruction
*/
const uint16 *WallSpacePirates_Instr_SetEnemyFunc(uint16 enemy_idx, const uint16 *enemy_ptr) {  // 0xB2EF83
  Get_SpacePirates(cur_enemy_index)->enemy_func = enemy_ptr[0];
  return enemy_ptr + 1;
}

/**
* @brief Plays the sound effect for the space pirate attack
* @param enemy_idx The current index of the enemy
* @param enemy_ptr* The pointer to the enemy instruction list
* @return uint16* The pointer to the next instruction
*/
const uint16 *WallSpacePirates_Instr_PlaySpacePirateAttackSfx(uint16 enemy_idx, const uint16 *enemy_ptr) {  // 0xB2EF93
  QueueSfx2_Max6(kSfx2_ShotKiHunter_WalkingSpacePirate_SpacePirateAttack);
  return enemy_ptr;
}

/**
* @brief Sets up the wall space pirate instruction, arc variables, function, and x position
*/
void WallSpacePirates_Init(void) {  // 0xB2EF9F
  Enemy_SpacePirates *E = Get_SpacePirates(cur_enemy_index);
  uint16 curr_instr = addr_kWallSpacePirates_Ilist_MoveDownLWall;
  if ((E->sps_parameter_1 & 1) != 0)
    curr_instr = addr_kWallSpacePirates_Ilist_MoveDownRWall;
  E->base.current_instruction = curr_instr;
  E->walljump_arc_right_target_angle = 190;
  E->walljump_arc_left_target_angle = 66;
  E->walljump_arc_angle_delta = 2;
  if ((E->sps_parameter_1 & 0x8000) == 0) {
    E->walljump_arc_right_target_angle += 2;
    E->walljump_arc_left_target_angle -= 2;
    E->walljump_arc_angle_delta += 2;
  }
  uint16 curr_func = FUNC16(WallSpacePirates_Func_ClimbLWall);
  if ((E->sps_parameter_1 & 1) != 0)
    curr_func = FUNC16(WallSpacePirates_Func_ClimbRWall);
  E->enemy_func = curr_func;
  uint16 x_pos;
  if ((E->base.x_pos & 15) < 11)
    x_pos = E->base.x_pos & (uint16)-8;
  else
    x_pos = (E->base.x_pos & (uint16)-16) + 16;
  E->base.x_pos = x_pos;
}

void CallSpacePiratesEnemyFunc(uint32 ea, uint16 enemy_idx) {
  switch (ea) {
  case fnnullsub_169_B2: return;  // 0xb2804b
  case fnWallSpacePirates_Func_ClimbLWall: WallSpacePirates_Func_ClimbLWall(enemy_idx); return;  // 0xb2f034
  case fnnullsub_279: return;  // 0xb2f04f
  case fnWallSpacePirates_Func_WallJumpR: WallSpacePirates_Func_WallJumpR(enemy_idx); return;  // 0xb2f050
  case fnWallSpacePirates_Func_ClimbRWall: WallSpacePirates_Func_ClimbRWall(enemy_idx); return;  // 0xb2f0c8
  case fnnullsub_281: return;  // 0xb2f0e3
  case fnnullsub_282: return;
  case fnWallSpacePirates_Func_WallJumpL: WallSpacePirates_Func_WallJumpL(enemy_idx); return;  // 0xb2f0e4
  case fnNinjaSpacePirates_Func_Initial: NinjaSpacePirates_Func_Initial(enemy_idx); return;  // 0xb2f6a9
  case fnNinjaSpacePirates_Func_Active: NinjaSpacePirates_Func_Active(enemy_idx); return;  // 0xb2f6e4
  case fnNinjaSpacePirates_Func_SpinJumpL_Rise: NinjaSpacePirates_Func_SpinJumpL_Rise(enemy_idx); return;  // 0xb2f817
  case fnNinjaSpacePirates_Func_SpinJumpL_Fall: NinjaSpacePirates_Func_SpinJumpL_Fall(enemy_idx); return;
  case fnNinjaSpacePirates_Func_SpinJumpR_Rise: NinjaSpacePirates_Func_SpinJumpR_Rise(enemy_idx); return;  // 0xb2f890
  case fnNinjaSpacePirates_Func_SpinJumpR_Fall: NinjaSpacePirates_Func_SpinJumpR_Fall(enemy_idx); return;  // 0xb2f8c5
  case fnNinjaSpacePirates_Func_DivekickReady: NinjaSpacePirates_Func_DivekickReady(enemy_idx); return;  // 0xb2f909
  case fnNinjaSpacePirates_Func_DivekickL_Jump: NinjaSpacePirates_Func_DivekickL_Jump(enemy_idx); return;  // 0xb2f985
  case fnNinjaSpacePirates_Func_DivekickL_Divekick: NinjaSpacePirates_Func_DivekickL_Divekick(enemy_idx); return;  // 0xb2f9c1
  case fnNinjaSpacePirates_Func_DivekickL_WalkToLeftPost: NinjaSpacePirates_Func_DivekickL_WalkToLeftPost(enemy_idx); return;  // 0xb2fa15
  case fnNinjaSpacePirates_Func_DivekickR_Jump: NinjaSpacePirates_Func_DivekickR_Jump(enemy_idx); return;  // 0xb2fa59
  case fnNinjaSpacePirates_Func_DivekickR_Divekick: NinjaSpacePirates_Func_DivekickR_Divekick(enemy_idx); return;  // 0xb2fa95
  case fnNinjaSpacePirates_Func_DivekickR_WalkToRightPost: NinjaSpacePirates_Func_DivekickR_WalkToRightPost(enemy_idx); return;  // 0xb2fae9
  case fnWalkingSpacePirates_Func_WalkL: WalkingSpacePirates_Func_WalkL(); return;
  case fnWalkingSpacePirates_Func_WalkR: WalkingSpacePirates_Func_WalkR(); return;
  default: Unreachable();
  }
}

void WallSpacePirates_Main(void) {  // 0xB2F02D
  Enemy_SpacePirates *E = Get_SpacePirates(cur_enemy_index);
  CallSpacePiratesEnemyFunc(E->enemy_func | 0xB20000, cur_enemy_index);
}

/**
* @brief Fire a laser and wall jump to the right if Samus is within 32 pixels (2 blocks) in the Y direction
* @param enemy_idx The current index of the enemy
*/
void WallSpacePirates_Func_ClimbLWall(uint16 enemy_idx) {  // 0xB2F034
  if (IsSamusWithinEnemy_Y(cur_enemy_index, 0x20)) {
    Enemy_SpacePirates *E = Get_SpacePirates(cur_enemy_index);
    E->base.current_instruction = addr_kWallSpacePirates_Ilist_FireLaser_WallJumpR;
    E->base.instruction_timer = 1;
  }
}

/**
* @brief Updates the enemy x and y positions and arc angle while wall jumping right
* @param enemy_idx The current index of the enemy
*/
void WallSpacePirates_Func_WallJumpR(uint16 enemy_idx) {  // 0xB2F050
  Enemy_SpacePirates *E = Get_SpacePirates(cur_enemy_index);
  E->base.x_pos = E->walljump_arc_center_x_pos + SineMult8bit(E->walljump_arc_angle, E->sps_parameter_2 / 2);
  E->base.y_pos = E->walljump_arc_center_y_pos - CosineMult8bit(E->walljump_arc_angle, E->sps_parameter_2 / 4);
  E->walljump_arc_angle = (uint8)(LOBYTE(E->walljump_arc_angle) - LOBYTE(E->walljump_arc_angle_delta));
  if (E->walljump_arc_angle == E->walljump_arc_right_target_angle) {
    E->base.current_instruction = addr_kWallSpacePirates_Ilist_LandedRWall;
    E->base.instruction_timer = 1;
    uint16 x_pos;
    if ((E->base.x_pos & 15) < 11)
      x_pos = E->base.x_pos & (uint16)-8;
    else
      x_pos = (E->base.x_pos & (uint16)-16) + 16;
    E->base.x_pos = x_pos;
  }
}

/**
* @brief Fire a laser and wall jump to the left if Samus is within 32 pixels (2 blocks) in the Y direction
* @param enemy_idx The current index of the enemy
*/
void WallSpacePirates_Func_ClimbRWall(uint16 enemy_idx) {  // 0xB2F0C8
  if (IsSamusWithinEnemy_Y(cur_enemy_index, 0x20)) {
    Enemy_SpacePirates *E = Get_SpacePirates(cur_enemy_index);
    E->base.current_instruction = addr_kWallSpacePirates_Ilist_FireLaser_WallJumpL;
    E->base.instruction_timer = 1;
  }
}

/**
* @brief Updates the enemy x and y positions and arc angle while wall jumping left
* @param enemy_idx The current index of the enemy
*/
void WallSpacePirates_Func_WallJumpL(uint16 enemy_idx) {  // 0xB2F0E4
  Enemy_SpacePirates *E = Get_SpacePirates(cur_enemy_index);
  E->base.x_pos = E->walljump_arc_center_x_pos + SineMult8bit(E->walljump_arc_angle, E->sps_parameter_2 / 2);
  E->base.y_pos = E->walljump_arc_center_y_pos - CosineMult8bit(E->walljump_arc_angle, E->sps_parameter_2 / 4);
  E->walljump_arc_angle = (uint8)(LOBYTE(E->walljump_arc_angle) + LOBYTE(E->walljump_arc_angle_delta));
  if (E->walljump_arc_angle == E->walljump_arc_left_target_angle) {
    E->base.current_instruction = addr_kWallSpacePirates_Ilist_LandedLWall;
    E->base.instruction_timer = 1;
    uint16 x_pos;
    if ((E->base.x_pos & 15) < 11)
      x_pos = E->base.x_pos & (uint16)-8;
    else
      x_pos = (E->base.x_pos & (uint16)-16) + 16;
    E->base.x_pos = x_pos;
  }
}

/**
* @brief Sets the palette index specified by the instruction
* @param enemy_idx The current index of the enemy
* @param enemy_ptr* The pointer to the enemy instruction list
* @return uint16* The pointer to the next instruction
*/
const uint16 *NinjaSpacePirates_Instr_SetPaletteIndex(uint16 enemy_idx, const uint16 *enemy_ptr) {  // 0xB2F536
  Get_SpacePirates(cur_enemy_index)->base.palette_index = enemy_ptr[0];
  return enemy_ptr + 1;
}

/**
* @brief Queues the library 2 sound effect specified in the instruction list
* with a max queue of 6 sound effects
* @param enemy_idx The current index of the enemy
* @param enemy_ptr* The pointer to the enemy instruction list
* @return uint16* The pointer to the next instruction
*/
const uint16 *NinjaSpacePirates_Instr_QueueSfx2_Max6(uint16 enemy_idx, const uint16 *enemy_ptr) {  // 0xB2F546
  QueueSfx2_Max6(enemy_ptr[0]);
  return enemy_ptr + 1;
}

void NinjaSpacePirates_Instr_GoToEnemy_Unused(void) {  // 0xB2F554
  gEnemyData(cur_enemy_index)->instruction_timer = 1;
}

/**
* @brief Spawns clawn projectile with offsets specified by the instruction
* @param enemy_idx The current index of the enemy
* @param enemy_ptr* The pointer to the enemy instruction list
* @return uint16* The pointer to the next instruction
*/
const uint16 *NinjaSpacePirates_Instr_SpawnEprojPirateClaw(uint16 enemy_idx, const uint16 *enemy_ptr) {  // 0xB2F564
  Enemy_SpacePirates *E = Get_SpacePirates(cur_enemy_index);
  eproj_spawn_rect = (Rect16U){ .x = E->base.x_pos, .y = E->base.y_pos, .w = enemy_ptr[1], .h = enemy_ptr[2] };
  SpawnEprojWithGfx(enemy_ptr[0], cur_enemy_index, addr_kEproj_PirateClaw);
  return enemy_ptr + 3;
}

/**
* @brief Sets the instruction based on if Samus is to the left or the right of the space pirate
* @param enemy_idx The current index of the enemy
* @param enemy_ptr* The pointer to the enemy instruction list
* @return uint16* The pointer to the instruction for the active direction 
*/
const uint16 *NinjaSpacePirates_Instr_SetAiActive(uint16 enemy_idx, const uint16 *enemy_ptr) {  // 0xB2F590
  Enemy_SpacePirates *E = Get_SpacePirates(cur_enemy_index);
  E->base.instruction_timer = 1;
  uint16 curr_instr = addr_kNinjaSpacePirates_Ilist_Active_FaceL;
  if ((int16)E->base.x_pos < (int16)samus_x_pos)
    curr_instr = addr_kNinjaSpacePirates_Ilist_Active_FaceR;
  E->ilist_ptr_unused = curr_instr;
  return INSTR_RETURN_ADDR(E->ilist_ptr_unused);
}

void NinjaSpacePirates_Instr_SetAiStandKick_Unused(void) {  // 0xB2F5B3
  Enemy_SpacePirates *E = Get_SpacePirates(cur_enemy_index);
  E->base.instruction_timer = 1;
  uint16 curr_instr = addr_kNinjaSpacePirates_Ilist_StandKick_FaceL;
  if ((int16)E->base.x_pos < (int16)samus_x_pos)
    curr_instr = addr_kNinjaSpacePirates_Ilist_StandKick_FaceR;
  E->ilist_ptr_unused = curr_instr;
}

/**
* @brief Sets the ninja space pirate's speed to 0
* @param enemy_idx The current index of the enemy
* @param enemy_ptr* The pointer to the enemy instruction list
* @return uint16* The pointer to the next instruction
*/
const uint16 *NinjaSpacePirates_Instr_ResetXSpeed(uint16 enemy_idx, const uint16 *enemy_ptr) {  // 0xB2F5D6
  Get_SpacePirates(enemy_idx)->speed = 0;
  return enemy_ptr;
}

/**
* @brief Sets up the ninja space pirate instruction, left and right post x position, and palette
*/
void NinjaSpacePirates_Init(void) {  // 0xB2F5DE
  Enemy_SpacePirates *E = Get_SpacePirates(cur_enemy_index);
  uint16 curr_instr = addr_kNinjaSpacePirates_Ilist_Initial_FaceL;
  if ((E->sps_parameter_1 & 1) != 0)
    curr_instr = addr_kNinjaSpacePirates_Ilist_Initial_FaceR;
  E->base.current_instruction = curr_instr;
  E->ilist_ptr_unused = E->base.current_instruction;
  uint16 x_pos = E->base.x_pos;
  if ((E->sps_parameter_1 & 1) != 0) {
    E->left_post_x_pos = x_pos;
    E->right_post_x_pos = x_pos + E->sps_parameter_2;
  }
  else {
    E->right_post_x_pos = x_pos;
    E->left_post_x_pos = x_pos - E->sps_parameter_2;
  }
  uint16 right_post_x_offset = (uint16)(E->right_post_x_pos - E->left_post_x_pos) / 2;
  E->post_midpoint_x_pos = E->left_post_x_pos + right_post_x_offset;
  uint16 travel_time = 0;
  uint16 travel_distance = 0;
  right_post_x_offset = (uint8)right_post_x_offset << 8;
  do {
    travel_time += 32;
    travel_distance += travel_time;
  } while ((int16)travel_distance < (int16)right_post_x_offset);
  E->sps_var_B_unused = travel_time;
  uint16 post_x_pos_offset = HIBYTE(travel_distance);
  E->right_post_x_pos = E->post_midpoint_x_pos + post_x_pos_offset;
  E->left_post_x_pos = E->post_midpoint_x_pos - post_x_pos_offset;
  uint16 post_x_pos = E->left_post_x_pos;
  if ((E->sps_parameter_1 & 1) == 0)
    post_x_pos = E->right_post_x_pos;
  E->base.x_pos = post_x_pos;
  E->enemy_func = FUNC16(nullsub_169_B2);
  E->spawn_y_pos = E->base.y_pos;
  MemCpy(target_palettes.sprite_pal_7, kSpacePirates_GoldPalette, sizeof(kSpacePirates_GoldPalette));
}

void NinjaSpacePirates_Main(void) {  // 0xB2F6A2
  Enemy_SpacePirates *E = Get_SpacePirates(cur_enemy_index);
  CallSpacePiratesEnemyFunc(E->enemy_func | 0xB20000, cur_enemy_index);
}

/**
* @brief Sets the space pirate to active if Samus is within range, otherwise force them to possibly flinch
* @param enemy_idx The current index of the enemy
*/
void NinjaSpacePirates_Func_Initial(uint16 enemy_idx) {  // 0xB2F6A9
  Enemy_SpacePirates *E = Get_SpacePirates(cur_enemy_index);
  // if Samus is too far from the ninja space pirate
  if ((int16)abs16(E->base.x_pos - samus_x_pos) >= 128) {
    NinjaSpacePirates_FlinchTrigger();
  }
  else {
    uint16 curr_instr = addr_kNinjaSpacePirates_Ilist_Active_FaceL;
    if ((int16)E->base.x_pos < (int16)samus_x_pos)
      curr_instr = addr_kNinjaSpacePirates_Ilist_Active_FaceR;
    E->base.current_instruction = curr_instr;
    E->ilist_ptr_unused = E->base.current_instruction;
    E->base.instruction_timer = 1;
  }
}

/**
* @brief Triggers a claw attack if a flinch, stand kick, or spin jump was triggered
* @param enemy_idx The current index of the enemy
*/
void NinjaSpacePirates_Func_Active(uint16 enemy_idx) {  // 0xB2F6E4
  if (!NinjaSpacePirates_FlinchTrigger() && !NinjaSpacePirates_StandKickTrigger() && !NinjaSpacePirates_SpinJumpTrigger())
    NinjaSpacePirates_ProjClawAttackTrigger(enemy_idx);
}

/**
* @brief Sets a claw attack if Samus is on the side of where the ninja space pirate initially jumps to
* @param enemy_idx The current index of the enemy
*/
void NinjaSpacePirates_ProjClawAttackTrigger(uint16 enemy_idx) {  // 0xB2F6F7
  Enemy_SpacePirates *E = Get_SpacePirates(enemy_idx);
  if ((E->base.frame_counter & 0x3F) == 0) {
    if (E->base.x_pos == E->left_post_x_pos) {
      if ((int16)E->base.x_pos < (int16)samus_x_pos)
        return;
      E->base.current_instruction = addr_kNinjaSpacePirates_Ilist_ProjClawAttackL;
    }
    else {
      if ((int16)E->base.x_pos >= (int16)samus_x_pos)
        return;
      E->base.current_instruction = addr_kNinjaSpacePirates_Ilist_ProjClawAttackR;
    }
    E->base.instruction_timer = 1;
  }
}

/**
* @brief Sets the instruction to trigger a flinch if the projectile is within 32 pixels (2 blocks) of the ninja space pirate
* @return 1 if flinch is triggered, 0 if not triggered
*/
uint16 NinjaSpacePirates_FlinchTrigger(void) {  // 0xB2F72E
  int16 proj_idx = 8;
  while (projectile_type[proj_idx >> 1] == 0) {
    proj_idx -= 2;
    if (proj_idx < 0)
      return 0;
  }
  int idx = proj_idx >> 1;
  Enemy_SpacePirates *E = Get_SpacePirates(cur_enemy_index);
  if ((int16)abs16(projectile_x_pos[idx] - E->base.x_pos) >= 32
      || (int16)abs16(projectile_y_pos[idx] - E->base.y_pos) >= 32) {
    return 0;
  }
  uint16 curr_instr = addr_kNinjaSpacePirates_Ilist_Flinch_FaceL;
  if ((int16)E->base.x_pos < (int16)samus_x_pos)
    curr_instr = addr_kNinjaSpacePirates_Ilist_Flinch_FaceR;
  E->base.current_instruction = curr_instr;
  E->base.instruction_timer = 1;
  return 1;
}

/**
* @brief Sets the instruction to trigger a spin jump if Samus is within 32 pixels (2 blocks) of the ninja space pirate
* @return 1 if spin jump is triggered, 0 if not triggered
*/
uint16 NinjaSpacePirates_SpinJumpTrigger(void) {  // 0xB2F78D
  Enemy_SpacePirates *E = Get_SpacePirates(cur_enemy_index);
  if ((int16)abs16(E->post_midpoint_x_pos - samus_x_pos) >= 32)
    return 0;
  uint16 curr_instr = addr_kNinjaSpacePirates_Ilist_SpinJumpL;
  if (E->base.x_pos == E->left_post_x_pos)
    curr_instr = addr_kNinjaSpacePirates_Ilist_SpinJumpR;
  E->base.current_instruction = curr_instr;
  E->base.instruction_timer = 1;
  return 1;
}

/**
* @brief Sets the instruction to trigger a standing kick if Samus is within 40 pixels (2 1/2 blocks) of the ninja space pirate
* @return 1 if spin jump is triggered, 0 if not triggered
*/
uint16 NinjaSpacePirates_StandKickTrigger(void) {  // 0xB2F7C6
  Enemy_SpacePirates *E = Get_SpacePirates(cur_enemy_index);
  if ((int16)abs16(samus_x_pos - E->base.x_pos) >= 40
      || (int16)abs16(samus_y_pos - E->base.y_pos) >= 40) {
    return 0;
  }
  uint16 curr_instr = addr_kNinjaSpacePirates_Ilist_StandKick_FaceL;
  if ((int16)E->base.x_pos < (int16)samus_x_pos)
    curr_instr = addr_kNinjaSpacePirates_Ilist_StandKick_FaceR;
  E->base.current_instruction = curr_instr;
  E->base.instruction_timer = 1;
  return 1;
}

/**
* @brief Raises the ninja space pirate to the left until it reaches the midpoint
* @param enemy_idx The current index of the enemy
*/
void NinjaSpacePirates_Func_SpinJumpL_Rise(uint16 enemy_idx) {  // 0xB2F817
  Enemy_SpacePirates *E = Get_SpacePirates(enemy_idx);
  E->base.x_pos -= HIBYTE(E->speed);
  E->base.y_pos -= 2;
  E->speed += 32;
  if ((int16)E->base.x_pos < (int16)E->post_midpoint_x_pos)
    E->enemy_func = FUNC16(NinjaSpacePirates_Func_SpinJumpL_Fall);
}

/**
* @brief Lowers the ninja space pirate to the left until its speed is zero, and then sets up for landing
* @param enemy_idx The current index of the enemy
*/
void NinjaSpacePirates_Func_SpinJumpL_Fall(uint16 enemy_idx) {  // 0xB2F84C
  Enemy_SpacePirates *E = Get_SpacePirates(enemy_idx);
  E->base.x_pos -= HIBYTE(E->speed);
  E->base.y_pos += 2;
  E->speed -= 32;
  if (E->speed == 0) {
    E->enemy_func = FUNC16(nullsub_169_B2);
    E->base.current_instruction = addr_kNinjaSpacePirates_Ilist_Land_FaceL;
    E->base.instruction_timer = 1;
    E->base.x_pos = E->left_post_x_pos;
    NinjaSpacePirates_SpawnLandingDustCloud(enemy_idx);
  }
}

/**
* @brief Raises the ninja space pirate to the right until it reaches the midpoint
* @param enemy_idx The current index of the enemy
*/
void NinjaSpacePirates_Func_SpinJumpR_Rise(uint16 enemy_idx) {  // 0xB2F890
  Enemy_SpacePirates *E = Get_SpacePirates(enemy_idx);
  E->base.x_pos += HIBYTE(E->speed);
  E->base.y_pos -= 2;
  E->speed += 32;
  if ((int16)E->base.x_pos >= (int16)E->post_midpoint_x_pos)
    E->enemy_func = FUNC16(NinjaSpacePirates_Func_SpinJumpR_Fall);
}

/**
* @brief Lowers the ninja space pirate to the right until its speed is zero, and then sets up for landing
* @param enemy_idx The current index of the enemy
*/
void NinjaSpacePirates_Func_SpinJumpR_Fall(uint16 enemy_idx) {  // 0xB2F8C5
  Enemy_SpacePirates *E = Get_SpacePirates(enemy_idx);
  E->base.x_pos += HIBYTE(E->speed);
  E->base.y_pos += 2;
  E->speed -= 32;
  if (E->speed == 0) {
    E->enemy_func = FUNC16(nullsub_169_B2);
    E->base.current_instruction = addr_kNinjaSpacePirates_Ilist_Land_FaceR;
    E->base.instruction_timer = 1;
    E->base.x_pos = E->right_post_x_pos;
    NinjaSpacePirates_SpawnLandingDustCloud(enemy_idx);
  }
}

/**
* @brief Triggers a dive kick if a flinch and a stand kick was not triggered
* @param enemy_idx The current index of the enemy
*/
void NinjaSpacePirates_Func_DivekickReady(uint16 enemy_idx) {  // 0xB2F909
  if (!NinjaSpacePirates_FlinchTrigger() && !NinjaSpacePirates_StandKickTrigger())
    NinjaSpacePirates_DivekickTrigger();
}

/**
* @brief Sets the ninja space pirate to dive kick if Samus is within 32 pixels (2 blocks)
*/
void NinjaSpacePirates_DivekickTrigger(void) {  // 0xB2F917
  Enemy_SpacePirates *E = Get_SpacePirates(cur_enemy_index);
  if ((int16)abs16(E->post_midpoint_x_pos - samus_x_pos) < 32) {
    uint16 Random;
    do {
      Random = NextRandom() & 3;
    } while (Random == 0);
    uint16 dir_idx = 0;
    // if at left post then divekick right
    if (E->base.x_pos == E->left_post_x_pos)
      dir_idx = 4;
    E->base.current_instruction = kSpacePirate_DivekickRandomDir_InstrListPtrs[dir_idx + Random];
    E->base.instruction_timer = 1;
  }
}

/**
* @brief Sets the initial Y speed for the left divekick jump
* @param enemy_idx The current index of the enemy
* @param enemy_ptr* The pointer to the enemy instruction list
* @return uint16* The pointer to the next instruction
*/
const uint16 *NinjaSpacePirates_Instr_InitDivekickLJumpYSpeed(uint16 enemy_idx, const uint16 *enemy_ptr) {  // 0xB2F969
  Enemy_SpacePirates *E = Get_SpacePirates(enemy_idx);
  E->speed = 0x600;
  uint16 right_post_x_offset = (uint16)(E->right_post_x_pos - E->post_midpoint_x_pos) / 2;
  E->sps_var_03_unused = E->post_midpoint_x_pos + right_post_x_offset;
  return enemy_ptr;
}

/**
* @brief Raises the ninja space pirate until the speed is zero, then sets up for a divekick
* @param enemy_idx The current index of the enemy
*/
void NinjaSpacePirates_Func_DivekickL_Jump(uint16 enemy_idx) {  // 0xB2F985
  Enemy_SpacePirates *E = Get_SpacePirates(enemy_idx);
  E->base.y_pos -= HIBYTE(E->speed);
  E->speed -= 64;
  if ((int16)E->speed < 0) {
    E->enemy_func = FUNC16(NinjaSpacePirates_Func_DivekickL_Divekick);
    E->base.current_instruction = addr_kNinjaSpacePirates_Ilist_DivekickL_Divekick;
    E->base.instruction_timer = 1;
    E->speed = 0x600;
  }
}

/**
* @brief Lowers the ninja space pirate to the left until it hits the ground or has a low enough speed, then sets up
* for walking to the post
* @param enemy_idx The current index of the enemy
*/
void NinjaSpacePirates_Func_DivekickL_Divekick(uint16 enemy_idx) {  // 0xB2F9C1
  Enemy_SpacePirates *E = Get_SpacePirates(enemy_idx);
  E->base.x_pos -= 5;
  if (Enemy_MoveDown(enemy_idx, __PAIR32__(HIBYTE(E->speed), LOBYTE(E->speed)))
      || (E->speed -= 64, (int16)E->speed < 0) || (int16)E->speed < 0x100) {
    E->enemy_func = FUNC16(NinjaSpacePirates_Func_DivekickL_WalkToLeftPost);
    E->base.current_instruction = addr_kNinjaSpacePirates_Ilist_DivekickL_WalkToLeftPost;
    E->base.instruction_timer = 1;
    E->base.y_pos = E->spawn_y_pos;
    NinjaSpacePirates_SpawnLandingDustCloud(enemy_idx);
  }
}

/**
* @brief Moves the ninja space pirate to the left until it reaches the left post, then stops it
* @param enemy_idx The current index of the enemy
*/
void NinjaSpacePirates_Func_DivekickL_WalkToLeftPost(uint16 enemy_idx) {  // 0xB2FA15
  Enemy_SpacePirates *E = Get_SpacePirates(enemy_idx);
  E->base.x_pos -= 2;
  if ((int16)E->base.x_pos < (int16)E->left_post_x_pos) {
    E->base.x_pos = E->left_post_x_pos;
    E->base.current_instruction = addr_kNinjaSpacePirates_Ilist_Land_FaceL;
    E->base.instruction_timer = 1;
    E->enemy_func = FUNC16(nullsub_169_B2);
  }
}

/**
* @brief Sets the initial Y speed for the right divekick jump
* @param enemy_idx The current index of the enemy
* @param enemy_ptr* The pointer to the enemy instruction list
* @return uint16* The pointer to the next instruction
*/
const uint16 *NinjaSpacePirates_Instr_InitDivekickRJumpYSpeed(uint16 enemy_idx, const uint16 *enemy_ptr) {  // 0xB2FA3D
  Enemy_SpacePirates *E = Get_SpacePirates(enemy_idx);
  E->speed = 0x600;
  uint16 left_post_x_offset = (uint16)(E->post_midpoint_x_pos - E->left_post_x_pos) / 2;
  E->sps_var_03_unused = E->left_post_x_pos + left_post_x_offset;
  return enemy_ptr;
}

/**
* @brief Raises the ninja space pirate until the speed is zero, then sets up for a divekick
* @param enemy_idx The current index of the enemy
*/
void NinjaSpacePirates_Func_DivekickR_Jump(uint16 enemy_idx) {  // 0xB2FA59
  Enemy_SpacePirates *E = Get_SpacePirates(enemy_idx);
  E->base.y_pos -= HIBYTE(E->speed);
  E->speed -= 64;
  if ((int16)E->speed < 0) {
    E->enemy_func = FUNC16(NinjaSpacePirates_Func_DivekickR_Divekick);
    E->base.current_instruction = addr_kNinjaSpacePirates_Ilist_DivekickR_Divekick;
    E->base.instruction_timer = 1;
    E->speed = 0x600;
  }
}

/**
* @brief Lowers the ninja space pirate to the right until it hits the ground or has a low enough speed, then sets up
* for walking to the post
* @param enemy_idx The current index of the enemy
*/
void NinjaSpacePirates_Func_DivekickR_Divekick(uint16 enemy_idx) {  // 0xB2FA95
  Enemy_SpacePirates *E = Get_SpacePirates(enemy_idx);
  E->base.x_pos += 5;
  if (Enemy_MoveDown(enemy_idx, __PAIR32__(HIBYTE(E->speed), LOBYTE(E->speed)))
      || (E->speed -= 64, (int16)E->speed < 0) || (int16)E->speed < 0x100) {
    E->enemy_func = FUNC16(NinjaSpacePirates_Func_DivekickR_WalkToRightPost);
    E->base.current_instruction = addr_kNinjaSpacePirates_Ilist_DivekickR_WalkToRightPost;
    E->base.instruction_timer = 1;
    E->base.y_pos = E->spawn_y_pos;
    NinjaSpacePirates_SpawnLandingDustCloud(enemy_idx);
  }
}

/**
* @brief Moves the ninja space pirate to the right until it reaches the right post, then stops it
* @param enemy_idx The current index of the enemy
*/
void NinjaSpacePirates_Func_DivekickR_WalkToRightPost(uint16 enemy_idx) {  // 0xB2FAE9
  Enemy_SpacePirates *E = Get_SpacePirates(enemy_idx);
  E->base.x_pos += 2;
  if ((int16)E->base.x_pos >= (int16)E->right_post_x_pos) {
    E->base.x_pos = E->right_post_x_pos;
    E->base.current_instruction = addr_kNinjaSpacePirates_Ilist_Land_FaceR;
    E->base.instruction_timer = 1;
    E->enemy_func = FUNC16(nullsub_169_B2);
  }
}

/**
* @brief Spawns the landing dust clouds
* @param enemy_idx The current index of the enemy
*/
void NinjaSpacePirates_SpawnLandingDustCloud(uint16 enemy_idx) {  // 0xB2FB11
  Enemy_SpacePirates *E = Get_SpacePirates(enemy_idx);
  CreateSpriteAtPos(E->base.x_pos - 8, E->base.y_pos + 28, 10, 0);
  CreateSpriteAtPos(E->base.x_pos + 8, E->base.y_pos + 28, 10, 0);
}

/**
* @brief Spawns a laser projectile leftwards at the Y level specified by the instruction
* @param enemy_idx The current index of the enemy
* @param enemy_ptr* The pointer to the enemy instruction list
* @return uint16* The pointer to the next instruction
*/
const uint16 *WalkingSpacePirates_Instr_FireLaserLOffsetY(uint16 enemy_idx, const uint16 *enemy_ptr) {  // 0xB2FC68
  Enemy_SpacePirates *E = Get_SpacePirates(cur_enemy_index);
  eproj_spawn_pt = (Point16U){ .x = E->base.x_pos - 24, .y = E->base.y_pos - enemy_ptr[0] };
  eproj_spawn_r22 = 0;
  SpawnEprojWithRoomGfx(addr_kEprojDef_PirateAndMotherBrainLaser, 0);
  return enemy_ptr + 1;
}

/**
* @brief Spawns a laser projectile rightwards at the Y level specified by the instruction
* @param enemy_idx The current index of the enemy
* @param enemy_ptr* The pointer to the enemy instruction list
* @return uint16* The pointer to the next instruction
*/
const uint16 *WalkingSpacePirates_Instr_FireLaserROffsetY(uint16 enemy_idx, const uint16 *enemy_ptr) {  // 0xB2FC90
  Enemy_SpacePirates *E = Get_SpacePirates(cur_enemy_index);
  eproj_spawn_pt = (Point16U){ .x = E->base.x_pos + 24, .y = E->base.y_pos - enemy_ptr[0] };
  eproj_spawn_r22 = 1;
  SpawnEprojWithRoomGfx(addr_kEprojDef_PirateAndMotherBrainLaser, 1);
  return enemy_ptr + 1;
}

/**
* @brief Sets the enemy function specified by the instruction
* @param enemy_idx The current index of the enemy
* @param enemy_ptr* The pointer to the enemy instruction list
* @return uint16* The pointer to the next instruction
*/
const uint16 *WalkingSpacePirates_Instr_SetEnemyFunc(uint16 enemy_idx, const uint16 *enemy_ptr) {  // 0xB2FCB8
  Get_SpacePirates(cur_enemy_index)->enemy_func = enemy_ptr[0];
  return enemy_ptr + 1;
}

/**
* @brief Sets the walking space pirate to fire a laser towards Samus if Samus is within 16 pixels (1 block), otherwise sets it
* to walk away from Samus
* @param enemy_idx The current index of the enemy
* @param enemy_ptr* The pointer to the enemy instruction list
* @return uint16* The pointer to the fire a laser instructions if Samus is close enough, other the walking instructions
*/
const uint16 *WalkingSpacePirates_Instr_ChooseDir_FireLaserIfClose(uint16 enemy_idx, const uint16 * enemy_ptr) {  // 0xB2FCC8
  if (IsSamusWithinEnemy_Y(cur_enemy_index, 0x10)) {
    if ((int16)samus_x_pos >= (int16)Get_SpacePirates(cur_enemy_index)->base.x_pos)
      return INSTR_RETURN_ADDR(addr_kWalkingSpacePirates_Ilist_FireLasersR);
    return INSTR_RETURN_ADDR(addr_kWalkingSpacePirates_Ilist_FireLasersL);
  }
  else {
    if ((int16)samus_x_pos >= (int16)Get_SpacePirates(cur_enemy_index)->base.x_pos)
      return INSTR_RETURN_ADDR(addr_kWalkingSpacePirates_Ilist_WalkL);
    return INSTR_RETURN_ADDR(addr_kWalkingSpacePirates_Ilist_WalkR);
  }
}

/**
* @brief Sets up the walking space pirate's instruction and X and Y positions
*/
void WalkingSpacePirates_Init(void) {  // 0xB2FD02
  Enemy_SpacePirates *E = Get_SpacePirates(cur_enemy_index);
  uint16 curr_instr = addr_kWalkingSpacePirates_Ilist_WalkL;
  if ((E->sps_parameter_1 & 1) != 0)
    curr_instr = addr_kWalkingSpacePirates_Ilist_WalkR;
  E->base.current_instruction = curr_instr;
  E->enemy_func = FUNC16(nullsub_169_B2);
  E->right_post_x_pos = E->base.x_pos + E->sps_parameter_2;
  E->left_post_x_pos = E->base.x_pos - E->sps_parameter_2;
}

/**
* @brief Execute the current function and possibly trigger a flinch
*/
void WalkingSpacePirates_Main(void) {  // 0xB2FD32
  Enemy_SpacePirates *E = Get_SpacePirates(cur_enemy_index);
  CallSpacePiratesEnemyFunc(E->enemy_func | 0xB20000, cur_enemy_index);
  if ((E->sps_parameter_1 & 0x8000) != 0)
    WalkingSpacePirates_FlinchTrigger();
}

/**
* @brief Sets the walking space pirate to fire a laser if Samus is within 16 pixels (1 block), otherwise
* moves the enemy down and to the left
*/
void WalkingSpacePirates_Func_WalkL(void) {  // 0xB2FD44
  Enemy_SpacePirates *E = Get_SpacePirates(cur_enemy_index);

  if (IsSamusWithinEnemy_Y(cur_enemy_index, 0x10)) {
    uint16 curr_instr = addr_kWalkingSpacePirates_Ilist_FireLasersL;
    if ((int16)samus_x_pos >= (int16)E->base.x_pos)
      curr_instr = addr_kWalkingSpacePirates_Ilist_FireLasersR;
    E->base.current_instruction = curr_instr;
    E->base.instruction_timer = 1;
  }
  else {
    uint8 coll = Enemy_MoveDown(cur_enemy_index, INT16_SHL16(1));
    if (coll) {
      E->x_pos_backup = E->base.x_pos;
      E->base.x_pos -= 17;
      coll = Enemy_MoveDown(cur_enemy_index, INT16_SHL16(1));
      E->base.x_pos = E->x_pos_backup;

      if (coll) {
        EnemyFunc_BBBF(cur_enemy_index, INT16_SHL16(-9));  // useless call
        coll = Enemy_MoveRight_IgnoreSlopes(cur_enemy_index, -14337);
        if (!coll && (int16)E->base.x_pos >= (int16)E->left_post_x_pos) {
          return;
        }
      }
      E->base.current_instruction = addr_kWalkingSpacePirates_Ilist_LookAround_FaceL;
      E->base.instruction_timer = 1;
    }
  }
}

/**
* @brief Sets the walking space pirate to fire a laser if Samus is within 16 pixels (1 block), otherwise
* moves the enemy down and to the right
*/
void WalkingSpacePirates_Func_WalkR(void) {  // 0xB2FDCE
  Enemy_SpacePirates *E = Get_SpacePirates(cur_enemy_index);

  if (IsSamusWithinEnemy_Y(cur_enemy_index, 0x10)) {
    uint16 curr_instr = addr_kWalkingSpacePirates_Ilist_FireLasersL;
    if ((int16)samus_x_pos >= (int16)E->base.x_pos)
      curr_instr = addr_kWalkingSpacePirates_Ilist_FireLasersR;
    E->base.current_instruction = curr_instr;
    E->base.instruction_timer = 1;
  }
  else {
    uint8 coll = Enemy_MoveDown(cur_enemy_index, INT16_SHL16(1));
    if (coll) {
      E->x_pos_backup = E->base.x_pos;
      E->base.x_pos += 16;
      coll = Enemy_MoveDown(cur_enemy_index, INT16_SHL16(1));
      E->base.x_pos = E->x_pos_backup;
      if (coll) {
        coll = Enemy_MoveRight_IgnoreSlopes(cur_enemy_index, 14336);
        if (!coll && (int16)E->base.x_pos < (int16)E->right_post_x_pos) {
          return;
        }
      }
      E->base.current_instruction = addr_kWalkingSpacePirates_Ilist_LookAround_FaceR;
      E->base.instruction_timer = 1;
    }
  }
}

/**
* @brief Sets the instruction to trigger a flinch if the shot projectile is within 32 pixels (2 blocks)
*/
void WalkingSpacePirates_FlinchTrigger(void) {  // 0xB2FE4B
  int16 proj_idx = 8;
  while (projectile_type[proj_idx >> 1] == 0) {
    proj_idx -= 2;
    if (proj_idx < 0)
      return;
  }
  int idx = proj_idx >> 1;
  Enemy_SpacePirates *E = Get_SpacePirates(cur_enemy_index);
  if ((int16)abs16(projectile_x_pos[idx] - E->base.x_pos) < 32
      && (int16)abs16(projectile_y_pos[idx] - E->base.y_pos) < 32) {
    uint16 curr_instr = addr_kWalkingSpacePirates_Ilist_Flinch_FaceL;
    if ((int16)E->base.x_pos < (int16)samus_x_pos)
      curr_instr = addr_kWalkingSpacePirates_Ilist_Flinch_FaceR;
    E->base.current_instruction = curr_instr;
    E->base.instruction_timer = 1;
  }
}
