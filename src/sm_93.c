// Projectiles
#include "ida_types.h"
#include "variables.h"
#include "funcs.h"
#include "sm_93.h"


/**
* @brief Sets up a projectile
* @param proj_index The index of the projectile
*/
void InitializeProjectile(uint16 proj_index) {  // 0x938000
  int idx = proj_index >> 1;
  int proj_dir = (projectile_dir[idx] & kProjectileDir_DirMask);
  uint16 proj_type = projectile_type[idx];
  ProjectileDataTable PD;

  if (proj_type & kProjectileType_ProjMask) {
    PD = kProjectileData_NonBeams[GET_HIBYTE(proj_type & kProjectileType_ProjMask)];
  } 
  else if (proj_type & kProjectileType_Charged) {
    PD = kProjectileData_ChargedBeams[proj_type & kProjectileType_BeamMask];
  } 
  else {
    PD = kProjectileData_UnchargedBeams[proj_type & kProjectileType_BeamMask];
  }

  if (sign16(PD.damage))
    InvalidInterrupt_Crash();
  projectile_damage[idx] = PD.damage;
  uint16 proj_instr_ptr = PD.instr_ptrs[proj_dir];
  projectile_instruction_ptr[idx] = proj_instr_ptr;
  ProjectileInstr proj_instr = get_ProjectileInstr(proj_instr_ptr);
  projectile_x_radius[idx] = proj_instr.x_radius;
  projectile_y_radius[idx] = proj_instr.y_radius;
  projectile_instruction_timers[idx] = 1;
}

/**
* @brief Sets up a super missile
* @param proj_index The index of the super missile
*/
void InitializeInstrForSuperMissile(uint16 proj_index) {  // 0x938071
  int idx = proj_index >> 1;
  ProjectileDataTable super_missile_data = kRunInstrForSuperMissile[GET_HIBYTE(projectile_type[idx] & kProjectileType_ProjMask)];
  projectile_damage[idx] = super_missile_data.damage;
  if ((int16)projectile_damage[idx] < 0)
    InvalidInterrupt_Crash();
  projectile_instruction_ptr[idx] = super_missile_data.instr_ptrs[0];
  projectile_instruction_timers[idx] = 1;
}

/**
* @brief Sets up a bomb or power bomb
* @param proj_idnex The index of the bomb or power bomb
*/
void InitializeInstrForBombOrPowerBomb(uint16 proj_index) {  // 0x9380A0
  int idx = proj_index >> 1;
  ProjectileDataTable bomb_data = kProjectileData_NonBeams[GET_HIBYTE(projectile_type[idx] & kProjectileType_ProjMask)];
  projectile_damage[idx] = bomb_data.damage;
  if ((int16)projectile_damage[idx] < 0)
    InvalidInterrupt_Crash();
  projectile_instruction_ptr[idx] = bomb_data.instr_ptrs[0];
  projectile_instruction_timers[idx] = 1;
}

/**
* @brief Sets up the sound effect and instructions for a projectile, and an earthquake if it's a super missile
* @param proj_index The index of the projectile
*/
void KillProjectileInner(uint16 proj_index) {  // 0x9380CF
  int idx = proj_index >> 1;
  uint16 proj_type = projectile_type[idx];
  if (proj_type & kProjectileType_ProjMask) {
    if (cinematic_function == 0) {
      QueueSfx2_Max6(kSfx2_SuperOrMissileHitWall);
    }
    projectile_type[idx] = proj_type & 0xF0FF | kProjectileType_MissileExplosion;

    if (proj_type & kProjectileType_SuperMissile) {
      projectile_instruction_ptr[idx] = kProjInstrList_SuperMissileExplosion.instr_ptr;
      earthquake_type = EARTHQUAKE(kEarthquake_Direction_Diag, kEarthquake_Intensity_1, kEarthquake_Layers_Bg1_Bg2_Enemies);
      earthquake_timer = 30;
    }
    else {
      projectile_instruction_ptr[idx] = kProjInstrList_MissileExplosion.instr_ptr;
    }

    cooldown_timer = IntMin(20, cooldown_timer);
  }
  else {
    projectile_type[idx] = proj_type & 0xF0FF | kProjectileType_BeamExplosion;
    projectile_instruction_ptr[idx] = kProjInstrList_BeamExplosion.instr_ptr;
    QueueSfx2_Max6(kSfx2_BeamHitWall_TorizoStatueCrumbles);
  }
  projectile_instruction_timers[idx] = 1;
  projectile_damage[idx] = 8;
}

/**
* @brief Sets up a bomb explosion
* @param proj_index The index of the projectile
*/
void InitializeBombExplosion(uint16 proj_index) {  // 0x93814E
  int idx = proj_index >> 1;
  projectile_instruction_ptr[idx] = kProjInstrList_BombExplosion.instr_ptr;
  projectile_instruction_timers[idx] = 1;
}

/**
* @brief Sets up either a shinespark echo or a spazer SBA trail
* @param proj_index The index of the projectile
*/
void InitializeShinesparkEchoOrSpazerSba(uint16 proj_index) {  // 0x938163
  int idx = proj_index >> 1;
  int proj_dir = projectile_dir[idx] & kProjectileDir_DirMask;
  ProjectileDataTable PD = kProjectileData_ShinesparkEchoSpazerSba[LOBYTE(projectile_type[idx]) - 34];
  projectile_damage[idx] = PD.damage;
  if ((int16)projectile_damage[idx] < 0)
    InvalidInterrupt_Crash();
  projectile_instruction_ptr[idx] = PD.instr_ptrs[proj_dir];
  projectile_instruction_timers[idx] = 1;
}

/**
* @brief Sets up a SBA projectile (doesn't include ice SBA)
* @param proj_index The index of the projectile
*/
void InitializeSbaProjectile(uint16 proj_index) {  // 0x9381A4
  int idx = proj_index >> 1;
  ProjectileDataTable sba_proj = kProjectileData_SBA[projectile_type[idx] & kProjectileType_BeamMask];
  projectile_damage[idx] = sba_proj.damage;
  if ((int16)projectile_damage[idx] < 0)
    InvalidInterrupt_Crash();
  projectile_instruction_ptr[idx] = sba_proj.instr_ptrs[0];
  projectile_instruction_timers[idx] = 1;
}

/**
* @brief Gets the frame for the projectile trail
* @param proj_index The index of the projectile
* @return uint16 The frame for the projectile trail
*/
uint16 GetProjectileTrailFrame(uint16 proj_index) {  // 0x9381D1
  int instr_ptr = projectile_instruction_ptr[proj_index >> 1];
  int instr_offset;
  // If the instruction is a function, or if the timer is not 1, then we want to get the trail frame 
  // from the previous instruction since the previous instruction has the trail frame
  // Otherwise, we want to get the trail frame from the current instruction
  if (projectile_instruction_timers[proj_index >> 1] == 1 && !IS_FUNC(get_ProjectileInstr(instr_ptr).func_ptr))
      instr_offset = 0;
  else /* (projectile_instruction_timers[proj_index >> 1] != 1 || IS_FUNC(get_ProjectileInstr(instr_ptr).func_ptr)) */
      instr_offset = -sizeof(ProjectileInstr);
  return get_ProjectileInstr(instr_ptr + instr_offset).trail_frame;
}

uint16 CallProjInstr(uint32 ea, uint16 j, uint16 k) {
  switch (ea) {
  case fnProjInstr_Delete: return ProjInstr_Delete(j, k);
  case fnProjInstr_Goto: return ProjInstr_Goto(j, k);
  default: return Unreachable();
  }
}

/**
* @brief Handles the current projectile
*/
void RunProjectileInstructions(void) {  // 0x9381E9
  ProjectileInstr PI;

  int idx = projectile_index >> 1;
  if (--projectile_instruction_timers[idx] == 0) {
    uint16 proj_instr = projectile_instruction_ptr[idx];
    while (1) {
      PI = get_ProjectileInstr(proj_instr);
      if (!IS_FUNC(PI.func_ptr))
        break;
      proj_instr = CallProjInstr(PI.func_ptr | 0x930000, projectile_index, PI.instr_list_ptr);
      if (proj_instr == 0)
        return;
    }
    projectile_instruction_timers[idx] = PI.timer;
    projectile_spritemap_pointers[idx] = PI.spritemap_ptr;
    projectile_x_radius[idx] = PI.x_radius;
    projectile_y_radius[idx] = PI.y_radius;
    projectile_instruction_ptr[idx] = proj_instr + sizeof(ProjectileInstr);
  }
}

/**
* @brief Deletes the current projectile
* @param k The index of the projectile
* @param j The current instruction list
* @return uint16 0, indicating the projectile is done being processed
*/
uint16 ProjInstr_Delete(uint16 k, uint16 j) {  // 0x93822F
  ClearProjectile(k);
  return 0;
}

/**
* @brief Goes to the next instruction of the projectile
* @param k The index of the projectile
* @param j The current instruction list
* @return uint16 The next instruction to process
*/
uint16 ProjInstr_Goto(uint16 k, uint16 j) {  // 0x938239
  return j;
}

/**
* @brief Draws the projectiles
* @todo Fix shooting beam in Ceres shaft escape during mode 7, has existed since original version
*/
void DrawProjectiles(void) {  // 0x938254
  int16 curr_proj_index = 8;
  uint16 spritemap_y_pos, spritemap_x_pos;
  projectile_index = 8;
  do {
    int index = curr_proj_index >> 1;
    if (projectile_instruction_ptr[index] == 0)
      goto NEXT_PROJ;
    uint16 proj_type = projectile_type[index];
    if (proj_type & (kProjectileType_ProjMask | kProjectileType_Charged)) {
      if (!sign16((proj_type & kProjectileType_ProjMask) - kProjectileType_PowerBomb))
        goto NEXT_PROJ;
    }
    else if (proj_type & (kProjectileType_Plasma | kProjectileType_Spazer)) {
      if ((curr_proj_index & 2) != 0) {
        if ((nmi_frame_counter_word & 2) == 0)
          goto NEXT_PROJ;
      }
      else if ((nmi_frame_counter_word & 2) != 0) {
        goto NEXT_PROJ;
      }
    }

    else if ((curr_proj_index & 2) != 0) {
      if ((nmi_frame_counter_word & 1) != 0)
        goto NEXT_PROJ;
    }
    else if ((nmi_frame_counter_word & 1) == 0) {
      goto NEXT_PROJ;
    }

    uint16 v3;
    if (ceres_status & kCeresStatus_8000_ElevatorRoomRotate) {
      Point16U pt = CalcExplosion_Mode7(curr_proj_index);
      v3 = pt.y;
      spritemap_y_pos = v3;
      spritemap_x_pos = pt.x;
    }
    else {
      spritemap_x_pos = projectile_x_pos[index] - layer1_x_pos;
      v3 = projectile_y_pos[index] - layer1_y_pos;
      spritemap_y_pos = v3;
    }
    if ((v3 & 0xFF00) == 0 && (projectile_spritemap_pointers[index] & 0x8000) != 0) {
      DrawProjectileSpritemap(curr_proj_index, spritemap_x_pos, spritemap_y_pos);
    }
    curr_proj_index = projectile_index;
NEXT_PROJ:
    curr_proj_index -= 2;
    projectile_index = curr_proj_index;
  } while ((curr_proj_index & 0x8000) == 0);
  Samus_DrawShinesparkCrashEchoProjectiles();
  HandleProjectileTrails();
}

void Unused_PartialDrawProjectiles(void) {  // 0x9382FD
  uint16 v0 = 8;
  projectile_index = 8;
  do {
    int v1 = v0 >> 1;
    if (projectile_instruction_ptr[v1]) {
      uint16 r20 = projectile_x_pos[v1] - layer1_x_pos;
      uint16 r18 = projectile_y_pos[v1] - 8 - layer1_y_pos;
      if ((r18 & 0xFF00) != 0) {
      } else if ((projectile_spritemap_pointers[v1] & 0x8000) != 0) {
        DrawProjectileSpritemap(v0, r20, r18);
      }
      v0 = projectile_index;
    }
    v0 -= 2;
    projectile_index = v0;
  } while ((v0 & 0x8000) == 0);
  HandleProjectileTrails();
}

/**
* @brief Draws bombs and the explosion for projectiles
*/
void DrawBombAndProjectileExplosions(void) {  // 0x93834D
  int16 spritemap_y_pos, spritemap_x_pos;

  int16 curr_proj_index = 18;
  projectile_index = curr_proj_index;
  do {
    int index = curr_proj_index >> 1;
    uint16 proj_instr = projectile_instruction_ptr[index];
    uint16 proj_type = projectile_type[index] & kProjectileType_ProjMask;
    uint16 bomb_timer = projectile_variables[index];
    if (proj_instr != 0 && proj_type >= kProjectileType_PowerBomb) {

      if ((proj_type == kProjectileType_PowerBomb && bomb_timer != 0)
          || (proj_type > kProjectileType_PowerBomb && (proj_type == kProjectileType_Bomb || !(ceres_status & kCeresStatus_8000_ElevatorRoomRotate)))) {
        spritemap_x_pos = projectile_x_pos[index] - layer1_x_pos;
        // If the projectile is within the screen boundary, including three blocks to the left and right of the boundary
        if ((-3*16) <= spritemap_x_pos && spritemap_x_pos < (16*16 + 3*16)) {
          spritemap_y_pos = projectile_y_pos[index] - layer1_y_pos;
          // If the projectile is on screen
          if ((spritemap_y_pos & 0xFF00) == 0) {
            DrawProjectileSpritemap(curr_proj_index, spritemap_x_pos, spritemap_y_pos);
          }
          curr_proj_index = projectile_index;
        }
      }

      else if (proj_type > kProjectileType_PowerBomb && proj_type != kProjectileType_Bomb && (ceres_status & kCeresStatus_8000_ElevatorRoomRotate)) {
        Point16U pt = CalcExplosion_Mode7(curr_proj_index);
        spritemap_y_pos = pt.y;
        spritemap_x_pos = pt.x;
        // If the projectile is on screen
        if ((spritemap_y_pos & 0xFF00) == 0) {
          DrawProjectileSpritemap(curr_proj_index, spritemap_x_pos, spritemap_y_pos);
        }
        curr_proj_index = projectile_index;
      }
    }

    curr_proj_index -= 2;
    projectile_index = curr_proj_index;
  } while (curr_proj_index >= 0);
}
