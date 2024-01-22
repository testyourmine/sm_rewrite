// Projectiles
#include "ida_types.h"
#include "variables.h"
#include "funcs.h"
#include "sm_93.h"


void InitializeProjectile(uint16 k) {  // 0x938000
  int v1 = k >> 1;
  int r18 = (projectile_dir[v1] & 0xF);
  uint16 v2 = projectile_type[v1];
  ProjectileDataTable PD;
  if ((v2 & kProjectileType_TypeMask) != 0) {
    PD = kProjectileData_NonBeams[HIBYTE(v2) & 0xF];
  } 
  else if ((v2 & kProjectileType_Charged) != 0) {
    PD = kProjectileData_ChargedBeams[projectile_type[v1] & 0xF];
  } 
  else {
    PD = kProjectileData_UnchargedBeams[projectile_type[v1] & 0xF];
  }
  if (sign16(PD.damage))
    InvalidInterrupt_Crash();
  projectile_damage[v1] = PD.damage;
  uint16 v7 = PD.instr_ptrs[r18];
  projectile_instruction_ptr[v1] = v7;
  ProjectileInstr v8 = get_ProjectileInstr(v7);
  projectile_x_radius[v1] = v8.x_radius;
  projectile_y_radius[v1] = v8.y_radius;
  projectile_instruction_timers[v1] = 1;
}

void InitializeInstrForSuperMissile(uint16 v0) {  // 0x938071
  int v1 = v0 >> 1;
  ProjectileDataTable v3 = kRunInstrForSuperMissile[HIBYTE(projectile_type[v1]) & 0xF];
  uint16 v4 = v3.damage;
  projectile_damage[v1] = v4;
  if (sign16(v4))
    InvalidInterrupt_Crash();
  projectile_instruction_ptr[v1] = v3.instr_ptrs[0];
  projectile_instruction_timers[v1] = 1;
}

void InitializeInstrForBombOrPowerBomb(uint16 v0) {  // 0x9380A0
  int v1 = v0 >> 1;
  ProjectileDataTable v3 = kProjectileData_NonBeams[HIBYTE(projectile_type[v1]) & 0xF];
  uint16 v4 = v3.damage;
  projectile_damage[v1] = v3.damage;
  if (sign16(v4))
    InvalidInterrupt_Crash();
  projectile_instruction_ptr[v1] = v3.instr_ptrs[0];
  projectile_instruction_timers[v1] = 1;
}

void KillProjectileInner(uint16 k) {  // 0x9380CF
  int v1 = k >> 1;
  if ((projectile_type[v1] & kProjectileType_TypeMask) != 0) {
    if (!cinematic_function)
      QueueSfx2_Max6(kSfx2_SuperOrMissileHitWall);
    uint16 v2 = projectile_type[v1];
    projectile_type[v1] = v2 & 0xF0FF | kProjectileType_MissileExplosion;
    if ((v2 & 0x200) != 0) {
      projectile_instruction_ptr[v1] = kProjInstrList_SuperMissileExplosion.instr_ptr;
      earthquake_type = 20;
      earthquake_timer = 30;
    } else {
      projectile_instruction_ptr[v1] = kProjInstrList_MissileExplosion.instr_ptr;
    }
    if (!sign16(cooldown_timer - 21))
      cooldown_timer = 20;
  } else {
    projectile_type[v1] = projectile_type[v1] & 0xF0FF | kProjectileType_BeamExplosion;
    projectile_instruction_ptr[v1] = kProjInstrList_BeamExplosion.instr_ptr;
    QueueSfx2_Max6(kSfx2_BeamHitWall_TorizoStatueCrumbles);
  }
  projectile_instruction_timers[v1] = 1;
  projectile_damage[v1] = 8;
}

void InitializeBombExplosion(uint16 k) {  // 0x93814E
  int v1 = k >> 1;
  projectile_instruction_ptr[v1] = kProjInstrList_BombExplosion.instr_ptr;
  projectile_instruction_timers[v1] = 1;
}

void InitializeShinesparkEchoOrSpazerSba(uint16 k) {  // 0x938163
  int v1 = k >> 1;
  int r18 = projectile_dir[v1] & 0xF;
  ProjectileDataTable PD = kProjectileData_ShinesparkEchoSpazerSba[LOBYTE(projectile_type[v1]) - 34];
  projectile_damage[v1] = PD.damage;
  if (sign16(PD.damage))
    InvalidInterrupt_Crash();
  projectile_instruction_ptr[v1] = PD.instr_ptrs[r18];
  projectile_instruction_timers[v1] = 1;
}

void InitializeSbaProjectile(uint16 k) {  // 0x9381A4
  int v1 = k >> 1;
  ProjectileDataTable v2 = kProjectileData_SBA[projectile_type[v1] & 0xF];
  uint16 v3 = v2.damage;
  projectile_damage[v1] = v3;
  if (sign16(v3))
    InvalidInterrupt_Crash();
  projectile_instruction_ptr[v1] = v2.instr_ptrs[0];
  projectile_instruction_timers[v1] = 1;
}

uint16 GetProjectileTrailFrame(uint16 k) {  // 0x9381D1
  int ip = projectile_instruction_ptr[k >> 1];
  int delta = (projectile_instruction_timers[k >> 1] == 1 && !sign16(get_ProjectileInstr(ip).timer)) ? 0 : -8;
  return get_ProjectileInstr(ip + delta).trail_frame;
}

uint16 CallProj93Instr(uint32 ea, uint16 j, uint16 k) {
  switch (ea) {
  case fnProj93Instr_Delete: return Proj93Instr_Delete(j, k);
  case fnProj93Instr_Goto: return Proj93Instr_Goto(j, k);
  default: return Unreachable();
  }
}

void RunProjectileInstructions(void) {  // 0x9381E9
  ProjectileInstr PI;

  uint16 v0 = projectile_index;
  int v1 = projectile_index >> 1;
  if (projectile_instruction_timers[v1]-- == 1) {
    uint16 v3 = projectile_instruction_ptr[v1];
    while (1) {
      PI = get_ProjectileInstr(v3);
      if ((PI.timer & 0x8000) == 0)
        break;
      v3 = CallProj93Instr(PI.func_ptr | 0x930000, v0, PI.instr_list_ptr);
      if (!v3)
        return;
    }
    projectile_instruction_timers[v1] = PI.timer;
    projectile_spritemap_pointers[v1] = PI.spritemap_ptr;
    projectile_x_radius[v1] = PI.x_radius;
    projectile_y_radius[v1] = PI.y_radius;
    projectile_instruction_ptr[v1] = v3 + sizeof(ProjectileInstr);
  }
}

uint16 Proj93Instr_Delete(uint16 k, uint16 j) {  // 0x93822F
  ClearProjectile(k);
  return 0;
}

uint16 Proj93Instr_Goto(uint16 k, uint16 j) {  // 0x938239
  return j;
}

void DrawProjectiles(void) {  // 0x938254
  uint16 v0 = 8;
  uint16 r18, r20;
  projectile_index = 8;
  do {
    int v1 = v0 >> 1;
    if (!projectile_instruction_ptr[v1])
      goto LABEL_25;
    uint16 v2, v3;
    v2 = projectile_type[v1];
    if ((v2 & (kProjectileType_TypeMask | kProjectileType_Charged)) != 0) {
      if (!sign16((v2 & kProjectileType_TypeMask) - kProjectileType_PowerBomb))
        goto LABEL_25;
    } else if ((v2 & (kProjectileType_Plasma | kProjectileType_Spazer)) != 0) {
      if ((v0 & 2) != 0) {
        if ((nmi_frame_counter_word & 2) == 0)
          goto LABEL_25;
      } else if ((nmi_frame_counter_word & 2) != 0) {
        goto LABEL_25;
      }
    } else if ((v0 & 2) != 0) {
      if ((nmi_frame_counter_word & 1) != 0)
        goto LABEL_25;
    } else if ((nmi_frame_counter_word & 1) == 0) {
      goto LABEL_25;
    }
    if ((ceres_status & 0x8000) == 0) {
      r20 = projectile_x_pos[v1] - layer1_x_pos;
      v3 = projectile_y_pos[v1] - layer1_y_pos;
      r18 = v3;
    } else {
      Point16U pt = CalcExplosion_Mode7(v0);
      v3 = pt.y;
      r20 = pt.x;
    }
    if ((v3 & 0xFF00) == 0 && (projectile_spritemap_pointers[v1] & 0x8000) != 0) {
      DrawProjectileSpritemap(v0, r20, r18);
    }
    v0 = projectile_index;
LABEL_25:
    v0 -= 2;
    projectile_index = v0;
  } while ((v0 & 0x8000) == 0);
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

void DrawBombAndProjectileExplosions(void) {  // 0x93834D
  uint16 v0 = 18, v2;
  uint16 r18, r20;
  projectile_index = 18;
  do {
    int v1 = v0 >> 1;
    if (!projectile_instruction_ptr[v1] || (int16)((projectile_type[v1] & kProjectileType_TypeMask) - kProjectileType_PowerBomb) < 0)
      goto LABEL_16;
    if ((projectile_type[v1] & kProjectileType_TypeMask) == kProjectileType_PowerBomb) {
      if (!projectile_variables[v1])
        goto LABEL_16;
LABEL_9:;
      uint16 v3 = projectile_x_pos[v1] - layer1_x_pos;
      r20 = v3;
      if (!sign16(v3 - 304) || sign16(v3 + 48))
        goto LABEL_16;
      v2 = projectile_y_pos[v1] - layer1_y_pos;
      r18 = v2;
      goto LABEL_12;
    }
    if ((projectile_type[v1] & kProjectileType_TypeMask) == kProjectileType_Bomb || (ceres_status & 0x8000) == 0)
      goto LABEL_9;
    CalcExplosion_Mode7(v0);
    v2 = r18;
LABEL_12:
    if ((v2 & 0xFF00) != 0)
      ;
    else
      DrawProjectileSpritemap(v0, r20, r18);
    v0 = projectile_index;
LABEL_16:
    v0 -= 2;
    projectile_index = v0;
  } while ((v0 & 0x8000) == 0);
}
