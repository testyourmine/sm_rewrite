// Samus

#include "ida_types.h"
#include "variables.h"
#include "sm_rtl.h"
#include "funcs.h"
#include "sm_90.h"


static Pair_Bool_Amt Samus_CalcBaseSpeed_NoDecel_X(uint16 k);

static const uint16 kUnchargedProjectile_Sfx[12] = { kSfx1_UnchargedPowerBeam, kSfx1_UnchargedWaveBeam, kSfx1_UnchargedIceBeam, kSfx1_UnchargedIceWaveBeam, kSfx1_UnchargedSpazerBeam, kSfx1_UnchargedSpazerWaveBeam, kSfx1_UnchargedSpazerIceBeam, kSfx1_UnchargedSpazerIceWaveBeam, kSfx1_UnchargedPlasmaBeam, kSfx1_UnchargedPlasmaWaveBeam, kSfx1_UnchargedPlasmaIceBeam, kSfx1_UnchargedPlasmaIceWaveBeam };
static const uint16 kChargedProjectile_Sfx[12] = { kSfx1_ChargedPowerBeam, kSfx1_ChargedWaveBeam, kSfx1_ChargedIceBeam, kSfx1_ChargedIceWaveBeam, kSfx1_ChargedSpazerBeam, kSfx1_ChargedSpazerWaveBeam, kSfx1_ChargedSpazerIceBeam, kSfx1_ChargedSpazerIceWaveBeam, kSfx1_ChargedPlasmaBeamHyperBeam, kSfx1_ChargedPlasmaWaveBeam, kSfx1_ChargedPlasmaIceBeam, kSfx1_ChargedPlasmaIceWaveBeam };
static const uint16 kNonBeamProjectile_Sfx[9] = { 0, kSfx1_Missile, kSfx1_SuperMissile, 0, 0, 0, 0, 0, 0 };
static const uint8 kProjectileCooldown_Uncharged[38] = {
  15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 12, 15, 0, 0, 0, 0,
  30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 0, 0, 0, 0,
   0,  0,  0,  0,  0,  0,
};
static const uint8 kNonBeamProjectileCooldowns[9] = { 0, 0xa, 0x14, 0x28, 0, 0x10, 0, 0, 0 };
static const uint8 kBeamAutoFireCooldowns[12] = { 0x19, 0x19, 0x19, 0x19, 0x19, 0x19, 0x19, 0x19, 0x19, 0x19, 0x19, 0x19 };

static void Samus_HandleAnimDelay(void);

void nullsub_12(void) {}

static Func_V *const kSamusFxHandlers[8] = {
  Samus_Animate_NoFx,
  Samus_Animate_LavaFx,
  Samus_Animate_AcidFx,
  Samus_Animate_WaterFx,
  nullsub_12,
  nullsub_12,
  nullsub_12,
  nullsub_12,
};

void Samus_Animate(void) {  // 0x908000
  kSamusFxHandlers[(fx_type & 0xF) >> 1]();
  if (samus_pose == kPose_4D_FaceR_Jump_NoAim_NoMove_NoGun || samus_pose == kPose_4E_FaceL_Jump_NoAim_NoMove_NoGun) {
    if (samus_y_dir != kSamusYDir_Down && samus_anim_frame == 1 && samus_anim_frame_timer == 1) {
      samus_anim_frame_timer = 4;
    }
    --samus_anim_frame_timer;
    if ((int16)samus_anim_frame_timer <= 0) {
      ++samus_anim_frame;
      Samus_HandleAnimDelay();
    }
  }
  // @todo possibly remove the else clause since it's the same as the above
  else {
    --samus_anim_frame_timer;
    if ((int16)samus_anim_frame_timer <= 0) {
      ++samus_anim_frame;
      Samus_HandleAnimDelay();
    }
  }
}

void Samus_Animate_NoFx(void) {  // 0x908078
  uint16 samus_bottom_bound = Samus_GetBottom_R18();
  samus_anim_frame_buffer = samus_x_speed_divisor;
  if (liquid_physics_type != kLiquidPhysicsType_Air) {
    if (liquid_physics_type & kLiquidPhysicsType_Water) {
      liquid_physics_type = kLiquidPhysicsType_Air;
      QueueSfx2_Max6(kSfx2_SplashedOutOfWater);
      if (!(samus_suit_palette_index & kSuitPaletteIndex_4_Gravity)
          && (samus_movement_type == kMovementType_03_SpinJumping || samus_movement_type == kMovementType_14_WallJumping)) {
        QueueSfx1_Max6(kSfx1_ResumedSpinJump);
      }
      Samus_SpawnWaterSplash(samus_bottom_bound);
    }
    else {
      liquid_physics_type = kLiquidPhysicsType_Air;
    }
  }
}

void Samus_Animate_WaterFx(void) {  // 0x9080B8
  static const uint16 kSamusPhys_AnimDelayInWater = 3;
  int16 samus_bottom_bound = Samus_GetBottom_R18();
  if (0 <= (int16)fx_y_pos && (int16)fx_y_pos < samus_bottom_bound
      && !(fx_liquid_options & kFxLiquidOption_4_LiquidPhysicsDisabled)) {
    samus_anim_frame_buffer = kSamusPhys_AnimDelayInWater;
    if (liquid_physics_type == kLiquidPhysicsType_Water) {
      Samus_SpawnAirBubbles();
    }
    else {
      liquid_physics_type = kLiquidPhysicsType_Water;
      QueueSfx2_Max6(kSfx2_SplashedIntoWater);
      Samus_SpawnWaterSplash(samus_bottom_bound);
    }
  }
  else {
    Samus_Animate_NoFx();
  }
}

void Samus_SpawnWaterSplash(uint16 samus_bottom_bound) {  // 0x9080E6
  static const uint8 kWaterSplashTypeTable[28] = {
    1, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1,
    1, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0,
  };
  // 0 is not in water, 1 is in water
  if (kWaterSplashTypeTable[samus_movement_type] != 0) {
    atmospheric_gfx_frame_and_type[0] = 256;
    atmospheric_gfx_frame_and_type[1] = 256;
    atmospheric_gfx_anim_timer[0] = 3;
    atmospheric_gfx_anim_timer[1] = 3;
    atmospheric_gfx_x_pos[0] = samus_x_pos + 4;
    atmospheric_gfx_x_pos[1] = samus_x_pos - 3;
    atmospheric_gfx_y_pos[0] = samus_bottom_bound - 4;
    atmospheric_gfx_y_pos[1] = samus_bottom_bound - 4;
  }
  else {
    atmospheric_gfx_frame_and_type[0] = 768;
    atmospheric_gfx_anim_timer[0] = 2;
    atmospheric_gfx_x_pos[0] = samus_x_pos;
    atmospheric_gfx_y_pos[0] = fx_y_pos;
  }
  Samus_SpawnAirBubbles();
}

void Samus_SpawnAirBubbles() {  // 0x90813E
  uint16 r20 = Samus_GetTop_R20();
  if ((int16)(r20 - 24 - fx_y_pos) >= 0 && (nmi_frame_counter_word & 0x7F) == 0
      && !atmospheric_gfx_frame_and_type[2]) {
    atmospheric_gfx_frame_and_type[2] = 1280;
    atmospheric_gfx_anim_timer[2] = 3;
    atmospheric_gfx_x_pos[2] = samus_x_pos;
    atmospheric_gfx_y_pos[2] = samus_y_pos - samus_y_radius + 6;
    QueueSfx2_Max6((NextRandom() & 1) ? kSfx2_LowPitchedAirBubbles : kSfx2_HighPitchedAirBubbles);
  }
  if (samus_pose == kPose_00_FaceF_Powersuit || samus_pose == kPose_9B_FaceF_VariaGravitySuit
      || (equipped_items & kItem_GravitySuit) != 0) {
    samus_anim_frame_buffer = 0;
  }
}

void Samus_Animate_LavaFx(void) {  // 0x9081C0
  static const uint16 kSamusPhys_LavaDamagePerFrame = 0;
  static const uint16 kSamusPhys_LavaSubdamagePerFrame = 0x8000;

  uint16 r18 = Samus_GetBottom_R18();
  if ((lava_acid_y_pos & 0x8000) == 0 && sign16(lava_acid_y_pos - r18)) {
    if (speed_boost_counter) {
      Samus_CancelSpeedBoost();
      samus_x_extra_run_speed = 0;
      samus_x_extra_run_subspeed = 0;
    }
    if ((equipped_items & kItem_GravitySuit) != 0) {
      samus_anim_frame_buffer = 0;
      liquid_physics_type = kLiquidPhysicsType_LavaAcid;
    } else {
      if ((game_time_frames & 7) == 0 && !sign16(samus_health - 71))
        QueueSfx3_Max3(kSfx3_GainingLosingIncrementalHealth);
      AddToHiLo(&samus_periodic_damage, &samus_periodic_subdamage, __PAIR32__(kSamusPhys_LavaDamagePerFrame, kSamusPhys_LavaSubdamagePerFrame));
      Samus_Animate_SubmergedLavaAcid();
    }
  } else {
    Samus_Animate_NoFx();
  }
}

void Samus_Animate_AcidFx(void) {  // 0x908219
  static const uint16 kSamusPhys_AcidSubdamagePerFrame = 0x8000;
  static const uint16 kSamusPhys_AcidDamagePerFrame = 1;
  uint16 r18 = Samus_GetBottom_R18();

  if ((lava_acid_y_pos & 0x8000) == 0 && sign16(lava_acid_y_pos - r18)) {
    if ((game_time_frames & 7) == 0 && !sign16(samus_health - 71))
      QueueSfx3_Max3(kSfx3_GainingLosingIncrementalHealth);
    AddToHiLo(&samus_periodic_damage, &samus_periodic_subdamage, __PAIR32__(kSamusPhys_AcidDamagePerFrame, kSamusPhys_AcidSubdamagePerFrame));
    Samus_Animate_SubmergedLavaAcid();
  } else {
    Samus_Animate_NoFx();
  }
}

void Samus_Animate_SubmergedLavaAcid(void) {  // 0x90824C
  static const uint16 kSamusPhys_AnimDelayInAcid = 2;
  uint16 r20 = Samus_GetTop_R20();
  samus_anim_frame_buffer = kSamusPhys_AnimDelayInAcid;
  liquid_physics_type = kLiquidPhysicsType_LavaAcid;
  if ((int16)(r20 - lava_acid_y_pos) < 0 && (atmospheric_gfx_frame_and_type[0] & 0x400) == 0) {
    atmospheric_gfx_frame_and_type[0] = 1024;
    atmospheric_gfx_frame_and_type[1] = 1024;
    atmospheric_gfx_frame_and_type[2] = 1024;
    atmospheric_gfx_frame_and_type[3] = 1024;
    atmospheric_gfx_anim_timer[0] = 3;
    atmospheric_gfx_anim_timer[3] = 3;
    atmospheric_gfx_anim_timer[1] = -32766;
    atmospheric_gfx_anim_timer[2] = -32766;
    atmospheric_gfx_y_pos[0] = lava_acid_y_pos;
    atmospheric_gfx_y_pos[1] = lava_acid_y_pos;
    atmospheric_gfx_y_pos[2] = lava_acid_y_pos;
    atmospheric_gfx_y_pos[3] = lava_acid_y_pos;
    atmospheric_gfx_x_pos[0] = samus_x_pos + 6;
    atmospheric_gfx_x_pos[1] = samus_x_pos;
    atmospheric_gfx_x_pos[2] = samus_x_pos;
    atmospheric_gfx_x_pos[3] = samus_x_pos - 6;
    if ((game_time_frames & 1) == 0)
      QueueSfx2_Max6(kSfx2_LavaAcidDamagingSamus);
  }
  if (samus_pose == kPose_00_FaceF_Powersuit || samus_pose == kPose_9B_FaceF_VariaGravitySuit || (equipped_items & kItem_GravitySuit) != 0) {
    samus_anim_frame_buffer = 0;
  }
}

static uint8 Samus_HandleSpeedBoosterAnimDelay(const uint8 *jp);


typedef bool Func_AnimDelay(const uint8 *jp);

static bool Samus_AnimDelayFunc_0to5_Nothing(const uint8 *jp) {  // 0x908344
  return false;
}

static bool Samus_AnimDelayFunc_6_GotoStartIfLittleHealth(const uint8 *jp) {  // 0x908346
  samus_anim_frame = sign16(samus_health - 30) ? samus_anim_frame + 1 : 0;
  return true;
}

static bool Samus_AnimDelayFunc_7_SetDrainedHandler(const uint8 *jp) {  // 0x908360
  samus_movement_handler = FUNC16(Samus_MovementHandler_DrainedCrouching);
  samus_anim_frame++;
  return true;
}

static bool Samus_AnimDelayFunc_13_TransToPose(const uint8 *jp) {  // 0x9084B6
  samus_new_pose_transitional = jp[1];
  samus_hurt_switch_index = 3;
  return false;
}

static bool Samus_AnimDelayFunc_8_AutoJumpHack_TransToPoseNoJump(const uint8 *jp) {  // 0x908370
  if (samus_input_handler == FUNC16(Samus_InputHandler_Demo))
    return Samus_AnimDelayFunc_13_TransToPose(jp);
  if (samus_new_pose != kPose_4B_FaceR_Jumptrans
      && samus_new_pose != kPose_4C_FaceL_Jumptrans
      && samus_new_pose != kPose_19_FaceR_SpinJump
      && samus_new_pose != kPose_1A_FaceL_SpinJump) {
    samus_input_handler = FUNC16(Samus_InputHandler_AutoJump);
    return Samus_AnimDelayFunc_13_TransToPose(jp);
  }
  return false;
}

static bool Samus_AnimDelayFunc_9_TransToPose_ItemEquipped_YSpeed(const uint8 *jp) {  // 0x90839A
  if ((GET_WORD(jp + 1) & equipped_items) != 0) {
    if (samus_y_speed || samus_y_subspeed)
      samus_new_pose_transitional = jp[6];
    else
      samus_new_pose_transitional = jp[5];
  } else if (samus_y_speed || samus_y_subspeed) {
    samus_new_pose_transitional = jp[4];
  } else {
    samus_new_pose_transitional = jp[3];
  }
  samus_hurt_switch_index = 3;
  return false;
}

static bool UNUSED_Samus_AnimDelayFunc_10_TransToPose_YSpeed(const uint8 *jp) {  // 0x9083F6
  if (samus_y_speed || samus_y_subspeed)
    samus_new_pose_transitional = jp[2];
  else
    samus_new_pose_transitional = jp[1];
  samus_hurt_switch_index = 3;
  return false;
}

static bool Samus_AnimDelayFunc_11_SelectDelaySequenceWalljump(const uint8 *jp) {  // 0x90841D
  if ((equipped_items & kItem_GravitySuit) == 0) {
    uint16 r20 = Samus_GetTop_R20();
    if ((fx_y_pos & 0x8000) != 0) {
      if ((lava_acid_y_pos & 0x8000) == 0 && sign16(lava_acid_y_pos - r20))
        goto LABEL_10;
    } else if (sign16(fx_y_pos - r20) && !(fx_liquid_options & kFxLiquidOption_4_LiquidPhysicsDisabled)) {
      goto LABEL_10;
    }
  }
  if ((equipped_items & kItem_ScrewAttack) != 0) {
    QueueSfx1_Max6(kSfx1_ScrewAttack);
    samus_anim_frame += 21;
  } else {
    if ((equipped_items & kItem_SpaceJump) == 0) {
LABEL_10:
      QueueSfx1_Max6(kSfx1_SpinJump);
      samus_anim_frame += 1;
    } else {
      QueueSfx1_Max6(kSfx1_SpaceJump);
      samus_anim_frame += 11;
    }
  }
  return true;
}

static bool Samus_AnimDelayFunc_12_TransToPose_ItemEquipped(const uint8 *jp) {  // 0x90848B
  if ((GET_WORD(jp + 1) & equipped_items) != 0)
    samus_new_pose_transitional = jp[4];
  else
    samus_new_pose_transitional = jp[3];
  samus_hurt_switch_index = 3;
  return false;
}

static bool Samus_AnimDelayFunc_14_Goto(const uint8 *jp) {  // 0x9084C7
  samus_anim_frame -= jp[1];
  return true;
}

static bool Samus_AnimDelayFunc_15_GotoStart(const uint8 *jp) {  // 0x9084DB
  samus_anim_frame = 0;
  return true;
}

static Func_AnimDelay *const kAnimDelayFuncs[16] = {  // 0x9082DC
  Samus_AnimDelayFunc_0to5_Nothing,
  Samus_AnimDelayFunc_0to5_Nothing,
  Samus_AnimDelayFunc_0to5_Nothing,
  Samus_AnimDelayFunc_0to5_Nothing,
  Samus_AnimDelayFunc_0to5_Nothing,
  Samus_AnimDelayFunc_0to5_Nothing,
  Samus_AnimDelayFunc_6_GotoStartIfLittleHealth,
  Samus_AnimDelayFunc_7_SetDrainedHandler,
  Samus_AnimDelayFunc_8_AutoJumpHack_TransToPoseNoJump,
  Samus_AnimDelayFunc_9_TransToPose_ItemEquipped_YSpeed,
  UNUSED_Samus_AnimDelayFunc_10_TransToPose_YSpeed,
  Samus_AnimDelayFunc_11_SelectDelaySequenceWalljump,
  Samus_AnimDelayFunc_12_TransToPose_ItemEquipped,
  Samus_AnimDelayFunc_13_TransToPose,
  Samus_AnimDelayFunc_14_Goto,
  Samus_AnimDelayFunc_15_GotoStart,
};


#define kDefaultAnimFramePtr ((uint16 *)RomFixedPtr(0x91B5D1))

static uint8 Samus_HandleSpeedBoosterAnimDelay(const uint8 *jp) {  // 0x90852C
  if (!samus_has_momentum_flag || (button_config_run_b & joypad1_lastkeys) == 0 || samus_movement_type != kMovementType_01_Running)
    return jp[0];
  if ((equipped_items & kItem_SpeedBooster) == 0) {
    samus_anim_frame = 0;
    samus_anim_frame_timer = samus_anim_frame_buffer + RomPtr_91(*kDefaultAnimFramePtr)[0];
    return 0;
  }
  if ((uint8)--speed_boost_counter)
    return jp[0];
  uint16 v2 = speed_boost_counter;
  if ((speed_boost_counter & 0x400) == 0) {
    v2 = speed_boost_counter + 0x100;
    speed_boost_counter = v2;
    if ((v2 & 0x400) != 0) {
      // The original code forgets to preserve A here.
      samus_echoes_sound_flag = 1;
      QueueSfx3_Max6(kSfx3_SpeedBooster);
      //v2 = 0x103; // bug!
    }
  }
  int v3 = HIBYTE(v2);
  speed_boost_counter = kSpeedBoostToCtr[v3] | speed_boost_counter & 0xFF00;
  samus_anim_frame = 0;
  samus_anim_frame_timer = samus_anim_frame_buffer + RomPtr_91(kSpeedBoostToAnimFramePtr[v3])[0];
  return 0;
}

static void Samus_HandleAnimDelay(void) {
  const uint8 *p = RomPtr_91(kSamusAnimationDelayData[samus_pose]);
  if ((p[samus_anim_frame] & 0x80) != 0) {
    uint8 v1 = Samus_HandleSpeedBoosterAnimDelay(p + samus_anim_frame);
    //  printf("v1=%x\n", v1);
    if (kAnimDelayFuncs[v1 & 0xF](p + samus_anim_frame))
      samus_anim_frame_timer = samus_anim_frame_buffer + p[samus_anim_frame];
  } else {
    if (samus_has_momentum_flag && samus_movement_type == kMovementType_01_Running) {
      uint16 addr = ((equipped_items & kItem_SpeedBooster) != 0) ? kSpeedBoostToAnimFramePtr[HIBYTE(speed_boost_counter)] : *kDefaultAnimFramePtr;
      p = RomPtr_91(addr);
    }
    samus_anim_frame_timer = samus_anim_frame_buffer + p[samus_anim_frame];
  }
}

static Func_U8 *const kSamusIsBottomDrawnFuncs[28] = {  // 0x9085E2
  SamusBottomDrawn_0_Standing,
  SamusBottomDrawn_1_FlagDrawn,
  SamusBottomDrawn_1_FlagDrawn,
  SamusBottomDrawn_3_SpinJump,
  SamusBottomDrawn_4_FlagNotDrawn,
  SamusBottomDrawn_1_FlagDrawn,
  SamusBottomDrawn_1_FlagDrawn,
  SamusBottomDrawn_4_FlagNotDrawn,
  SamusBottomDrawn_4_FlagNotDrawn,
  SamusBottomDrawn_4_FlagNotDrawn,
  SamusBottomDrawn_A_Knockback_CrystalFlashEnd,
  SamusBottomDrawn_1_FlagDrawn,
  SamusBottomDrawn_1_FlagDrawn,
  UNUSED_SamusBottomDrawn_D,
  SamusBottomDrawn_1_FlagDrawn,
  SamusBottomDrawn_F_Transitions,
  SamusBottomDrawn_1_FlagDrawn,
  SamusBottomDrawn_4_FlagNotDrawn,
  SamusBottomDrawn_4_FlagNotDrawn,
  SamusBottomDrawn_4_FlagNotDrawn,
  SamusBottomDrawn_14_WallJump,
  SamusBottomDrawn_1_FlagDrawn,
  SamusBottomDrawn_1_FlagDrawn,
  SamusBottomDrawn_1_FlagDrawn,
  SamusBottomDrawn_1_FlagDrawn,
  SamusBottomDrawn_19_DamageBoost,
  SamusBottomDrawn_1_FlagDrawn,
  SamusBottomDrawn_1B_Shinespark_CrystalFlash_Drained_MBDamaged,
};

void Samus_Draw(void) {
  PairU16 v0;

  if (samus_knockback_timer || !samus_invincibility_timer || samus_shine_timer || (nmi_frame_counter_word & 1) == 0) {
    uint16 v2 = 2 * samus_pose;
    samus_top_half_spritemap_index = samus_anim_frame
      + kSamusPoseToBaseSpritemapIndexTop[samus_pose];
    uint16 a = samus_top_half_spritemap_index;
    v0 = Samus_CalcSpritemapPos(2 * samus_pose);
    DrawSamusSpritemap(a, v0.k, v0.j);
    uint16 R36 = v2;
    if (kSamusIsBottomDrawnFuncs[samus_movement_type]() & 1) {
      samus_bottom_half_spritemap_index = samus_anim_frame + kSamusPoseToBaseSpritemapIndexBottom[R36 >> 1];
      DrawSamusSpritemap(samus_bottom_half_spritemap_index, samus_spritemap_x_pos, samus_spritemap_y_pos);
    }
  }
  SetSamusTilesDefsForCurAnim();
}

uint8 SamusBottomDrawn_1_FlagDrawn(void) {  // 0x908686
  return 1;
}

uint8 SamusBottomDrawn_4_FlagNotDrawn(void) {  // 0x908688
  samus_bottom_half_spritemap_index = 0;
  return 0;
}

uint8 SamusBottomDrawn_0_Standing(void) {  // 0x90868D
  OamEnt *v1;

  if (samus_pose == kPose_00_FaceF_Powersuit) {
    uint16 v0 = oam_next_ptr;
    v1 = gOamEnt(oam_next_ptr);
    *(uint16 *)&v1->xcoord = samus_x_pos - 7 - layer1_x_pos;
    *(uint16 *)&v1->ycoord = samus_y_pos - 17 - layer1_y_pos;
    *(uint16 *)&v1->charnum = 14369;
    oam_next_ptr = v0 + 4;
  }
  return 1;
}

uint8 SamusBottomDrawn_3_SpinJump(void) {  // 0x9086C6
  if (samus_pose == kPose_81_FaceR_Screwattack
      || samus_pose == kPose_82_FaceL_Screwattack
      || samus_pose == kPose_1B_FaceR_SpaceJump
      || samus_pose == kPose_1C_FaceL_SpaceJump
      || !samus_anim_frame
      || !sign16(samus_anim_frame - kPose_0B_MoveR_Gun)) {
    return 1;
  }
  samus_bottom_half_spritemap_index = 0;
  return 0;
}

uint8 SamusBottomDrawn_A_Knockback_CrystalFlashEnd(void) {  // 0x9086EE
  if (samus_pose != kPose_D7_FaceR_CrystalFlashEnd && samus_pose != kPose_D8_FaceL_CrystalFlashEnd
      || !sign16(samus_anim_frame - 3)) {
    return 1;
  }
  samus_bottom_half_spritemap_index = 0;
  return 0;
}

uint8 SamusBottomDrawn_F_Transitions(void) {  // 0x90870C
  if (!sign16(samus_pose - kPose_F1_FaceR_CrouchTrans_AimU))
    return 1;
  if (!sign16(samus_pose - 219)) {
    if (sign16(samus_pose - 221)) {
      if (samus_anim_frame)
        goto LABEL_8;
    } else if (samus_anim_frame != 2) {
      goto LABEL_8;
    }
    return 1;
  }
  if (samus_pose == kPose_35_FaceR_CrouchTrans
      || samus_pose == kPose_36_FaceL_CrouchTrans
      || samus_pose == kPose_3B_FaceR_StandTrans
      || samus_pose == kPose_3C_FaceL_StandTrans) {
    return 1;
  }
LABEL_8:
  samus_bottom_half_spritemap_index = 0;
  return 0;
}

uint8 UNUSED_SamusBottomDrawn_D(void) {  // 0x90874C
  if (samus_pose != (kPose_44_FaceL_Turn_Crouch | kPose_01_FaceR_Normal | 0x20)
      && samus_pose != (kPose_44_FaceL_Turn_Crouch | kPose_02_FaceL_Normal | 0x20)
      || sign16(samus_anim_frame - 1)) {
    return 1;
  }
  samus_bottom_half_spritemap_index = 0;
  return 0;
}

uint8 SamusBottomDrawn_14_WallJump(void) {  // 0x908768
  if (sign16(samus_anim_frame - 3) || !sign16(samus_anim_frame - 13))
    return 1;
  samus_bottom_half_spritemap_index = 0;
  return 0;
}

uint8 SamusBottomDrawn_19_DamageBoost(void) {  // 0x90877C
  if (sign16(samus_anim_frame - 2) || !sign16(samus_anim_frame - 9))
    return 1;
  samus_bottom_half_spritemap_index = 0;
  return 0;
}

uint8 SamusBottomDrawn_1B_Shinespark_CrystalFlash_Drained_MBDamaged(void) {  // 0x908790
  if (sign16(samus_pose - kPose_CF_FaceR_Ranintowall_AimUR)) {
    if (samus_pose != kPose_CB_FaceR_Shinespark_Vert && samus_pose != kPose_CC_FaceL_Shinespark_Vert)
      return 1;
  } else if (samus_pose != kPose_E8_FaceR_Drained_CrouchFalling && samus_pose != kPose_E9_FaceL_Drained_CrouchFalling
             || !sign16(samus_anim_frame - 2)) {
    return 1;
  }
  samus_bottom_half_spritemap_index = 0;
  return 0;
}

void Samus_DrawEchoes(void) {  // 0x9087BD
  if ((speed_echoes_index & 0x8000) == 0) {
    if ((speed_boost_counter & 0xFF00) == 0x400) {
      if (speed_echo_xpos[1])
        Samus_DrawEcho(2);
      if (speed_echo_xpos[0])
        Samus_DrawEcho(0);
    }
    return;
  }
  for (int i = 2; i >= 0; i -= 2) {
    int v1 = i >> 1;
    if (!speed_echo_xpos[v1])
      continue;
    uint16 v2 = speed_echo_ypos[v1], v3;
    if (v2 != samus_y_pos) {
      if ((int16)(v2 - samus_y_pos) < 0)
        v3 = v2 + 2;
      else
        v3 = v2 - 2;
      speed_echo_ypos[v1] = v3;
    }
    if ((speed_echo_xspeed[v1] & 0x8000) != 0) {
      uint16 v5 = speed_echo_xspeed[v1] + speed_echo_xpos[v1];
      speed_echo_xpos[v1] = v5;
      if ((int16)(v5 - samus_x_pos) < 0) {
        speed_echo_xpos[v1] = 0;
        continue;
      }
    } else {
      uint16 v4 = speed_echo_xspeed[v1] + speed_echo_xpos[v1];
      speed_echo_xpos[v1] = v4;
      if ((int16)(v4 - samus_x_pos) >= 0) {
        speed_echo_xpos[v1] = 0;
        continue;
      }
    }
    Samus_DrawEcho(i);
  }
  if (!speed_echo_xpos[1] && !speed_echo_xpos[0])
    speed_echoes_index = 0;
}

void Samus_DrawEcho(uint16 j) {  // 0x908855
  int v1 = j >> 1;
  int16 v2 = speed_echo_ypos[v1] - kPoseParams[samus_pose].y_offset_to_gfx - layer1_y_pos;
  if (v2 >= 0 && sign16(v2 - 248)) {
    DrawSamusSpritemap(samus_top_half_spritemap_index, speed_echo_xpos[v1] - layer1_x_pos, v2);
    if (samus_bottom_half_spritemap_index)
      DrawSamusSpritemap(samus_bottom_half_spritemap_index, speed_echo_xpos[v1] - layer1_x_pos, v2);
  }
}

void Samus_DrawShinesparkCrashEchoes(uint16 k) {  // 0x9088BA
  if ((nmi_frame_counter_word & 1) != 0) {
    uint16 a = samus_anim_frame + kSamusPoseToBaseSpritemapIndexTop[samus_pose];
    int16 v2 = speed_echo_ypos[k >> 1] - kPoseParams[samus_pose].y_offset_to_gfx - layer1_y_pos;
    if (v2 >= 0 && sign16(v2 - 248)) {
      DrawSamusSpritemap(a, speed_echo_xpos[k >> 1] - layer1_x_pos, v2);
      if (kSamusIsBottomDrawnFuncs[samus_movement_type]() & 1) {
        uint16 v5 = samus_anim_frame + kSamusPoseToBaseSpritemapIndexBottom[samus_pose];
        DrawSamusSpritemap(v5, speed_echo_xpos[k >> 1] - layer1_x_pos, v2);
      }
    }
  }
}

void Samus_DrawShinesparkCrashEchoProjectiles(void) {  // 0x908953
  if ((nmi_frame_counter_word & 1) != 0) {
    if (speed_echo_xspeed[3])
      Samus_DrawEcho(6);
    if (speed_echo_xspeed[2])
      Samus_DrawEcho(4);
  }
}

void Samus_DrawStartingDeathAnim(void) {  // 0x908976
  bool v0 = (--samus_anim_frame_timer & 0x8000) != 0;
  if (!samus_anim_frame_timer || v0) {
    ++samus_anim_frame;
    Samus_HandleAnimDelay();
  }
  Samus_DrawDuringDeathAnim();
}

void Samus_DrawDuringDeathAnim(void) {  // 0x908998
  uint16 v1 = 2 * samus_pose;
  uint16 a = samus_anim_frame + kSamusPoseToBaseSpritemapIndexTop[samus_pose];
  Samus_CalcSpritemapPos(2 * samus_pose);
  DrawSamusSpritemap(a, layer1_x_pos + samus_spritemap_x_pos, layer1_y_pos + samus_spritemap_y_pos);
  uint16 R36 = v1;
  if (kSamusIsBottomDrawnFuncs[samus_movement_type]() & 1)
    DrawSamusSpritemap(
      samus_anim_frame + kSamusPoseToBaseSpritemapIndexBottom[R36 >> 1],
      layer1_x_pos + samus_spritemap_x_pos,
      layer1_y_pos + samus_spritemap_y_pos);
  SetSamusTilesDefsForCurAnim();
}

void Samus_DrawWhenNotAnimatingOrDying(void) {  // 0x908A00
  PairU16 v0;

  uint16 v2 = 2 * samus_pose;
  uint16 a = samus_anim_frame + kSamusPoseToBaseSpritemapIndexTop[samus_pose];
  v0 = Samus_CalcSpritemapPos(2 * samus_pose);
  DrawSamusSpritemap(a, v0.k, v0.j);
  uint16 R36 = v2;
  if (kSamusIsBottomDrawnFuncs[samus_movement_type]() & 1)
    DrawSamusSpritemap(
      samus_anim_frame + kSamusPoseToBaseSpritemapIndexBottom[R36 >> 1],
      samus_spritemap_x_pos,
      samus_spritemap_y_pos);
  SetSamusTilesDefsForCurAnim();
}

static FuncXY_V *const kAtmosphericTypeFuncs[8] = {  // 0x908A4C
  0,
  AtmosphericTypeFunc_1_2_FootstepSplash,
  AtmosphericTypeFunc_1_2_FootstepSplash,
  AtmosphericTypeFunc_3_DivingSplash,
  AtmosphericTypeFunc_4_LavaSurfaceDmg,
  AtmosphericTypeFunc_5_Bubbles,
  AtmosphericTypeFunc_6_7_Dust,
  AtmosphericTypeFunc_6_7_Dust,
};

void HandleAtmosphericEffects(void) {
  int16 v4;

  for (int i = 6; i >= 0; i -= 2) {
    int v1 = i >> 1;
    uint16 v2 = atmospheric_gfx_frame_and_type[v1];
    if (!v2)
      continue;
    uint16 r18 = 2 * (uint8)v2;
    uint16 v3 = 2 * HIBYTE(v2);
    v4 = atmospheric_gfx_anim_timer[v1] - 1;
    atmospheric_gfx_anim_timer[v1] = v4;
    if (v4) {
      if (v4 < 0) {
        if (v4 != (int16)0x8000)
          continue;
        atmospheric_gfx_anim_timer[v1] = *(uint16 *)RomPtr_90(r18 + kAtmosphericGraphicAnimationTimers[v3 >> 1]);
      }
    } else {
      atmospheric_gfx_anim_timer[v1] = *(uint16 *)RomPtr_90(r18 + kAtmosphericGraphicAnimationTimers[v3 >> 1]);
      uint16 v5 = atmospheric_gfx_frame_and_type[v1] + 1;
      atmospheric_gfx_frame_and_type[v1] = v5;
      if ((int16)((uint8)v5 - kAtmosphericTypeNumFrames[v3 >> 1]) >= 0) {
        atmospheric_gfx_frame_and_type[v1] = 0;
        continue;
      }
    }
    kAtmosphericTypeFuncs[v3 >> 1](v3, i);
  }
}

void AtmosphericTypeFunc_1_2_FootstepSplash(uint16 k, uint16 j) {  // 0x908AC5
  int16 v4;
  OamEnt *v5;
  int16 v6;

  int v2 = j >> 1;
  uint16 r18 = 2 * LOBYTE(atmospheric_gfx_frame_and_type[v2]);
  uint16 v3 = oam_next_ptr;
  v4 = atmospheric_gfx_x_pos[v2] - layer1_x_pos - 4;
  if (v4 >= 0) {
    if (sign16(atmospheric_gfx_x_pos[v2] - layer1_x_pos - 260)) {
      v5 = gOamEnt(oam_next_ptr);
      v5->xcoord = v4;
      v6 = atmospheric_gfx_y_pos[v2] - layer1_y_pos - 4;
      if (v6 >= 0) {
        if (sign16(atmospheric_gfx_y_pos[v2] - layer1_y_pos - 260)) {
          v5->ycoord = v6;
          *(uint16 *)&v5->charnum = *(uint16 *)RomPtr_90(r18 + kAtmosphericTypeTileNumAndAttributes[k >> 1]);
          oam_next_ptr = v3 + 4;
        }
      }
    }
  }
}

void AtmosphericTypeFunc_Common(uint16 j, uint16 a) {  // 0x908B74
  int v1 = j >> 1;
  if (((atmospheric_gfx_y_pos[v1] - layer1_y_pos) & 0xFF00) == 0)
    DrawSamusSpritemap(a, atmospheric_gfx_x_pos[v1] - layer1_x_pos, atmospheric_gfx_y_pos[v1] - layer1_y_pos);
}

void AtmosphericTypeFunc_3_DivingSplash(uint16 k, uint16 j) {  // 0x908B16
  int v2 = j >> 1;
  uint16 r18 = LOBYTE(atmospheric_gfx_frame_and_type[v2]);
  atmospheric_gfx_y_pos[v2] = fx_y_pos;
  AtmosphericTypeFunc_Common(j, r18 + 399);
}

void AtmosphericTypeFunc_4_LavaSurfaceDmg(uint16 k, uint16 j) {  // 0x908B2E
  int v2 = j >> 1;
  uint16 v3;
  if ((j & 4) != 0)
    v3 = atmospheric_gfx_x_pos[v2] - 1;
  else
    v3 = atmospheric_gfx_x_pos[v2] + 1;
  atmospheric_gfx_x_pos[v2] = v3;
  --atmospheric_gfx_y_pos[j >> 1];
  AtmosphericTypeFunc_1_2_FootstepSplash(k, j);
}

void AtmosphericTypeFunc_6_7_Dust(uint16 k, uint16 j) {  // 0x908B57
  --atmospheric_gfx_y_pos[j >> 1];
  AtmosphericTypeFunc_1_2_FootstepSplash(k, j);
}

void AtmosphericTypeFunc_5_Bubbles(uint16 k, uint16 j) {  // 0x908B64
  uint16 r18 = LOBYTE(atmospheric_gfx_frame_and_type[j >> 1]);
  AtmosphericTypeFunc_Common(j, r18 + 390);
}

static Func_Y_To_PairU16 *const kSamus_CalcSpritemapPos[28] = {  // 0x908C1F
  &Samus_CalcSpritemapPos_Standing,
  &Samus_CalcSpritemapPos_Default,
  &Samus_CalcSpritemapPos_Default,
  &Samus_CalcSpritemapPos_Default,
  &Samus_CalcSpritemapPos_Default,
  &Samus_CalcSpritemapPos_Default,
  &Samus_CalcSpritemapPos_Default,
  &Samus_CalcSpritemapPos_Default,
  &Samus_CalcSpritemapPos_Default,
  &Samus_CalcSpritemapPos_Default,
  &Samus_CalcSpritemapPos_Default,
  &Samus_CalcSpritemapPos_Default,
  &Samus_CalcSpritemapPos_Default,
  &Samus_CalcSpritemapPos_Default,
  &Samus_CalcSpritemapPos_Default,
  &Samus_CalcSpritemapPos_Transitions,
  &Samus_CalcSpritemapPos_Default,
  &Samus_CalcSpritemapPos_Default,
  &Samus_CalcSpritemapPos_Default,
  &Samus_CalcSpritemapPos_Default,
  &Samus_CalcSpritemapPos_Default,
  &Samus_CalcSpritemapPos_Default,
  &Samus_CalcSpritemapPos_Default,
  &Samus_CalcSpritemapPos_Default,
  &Samus_CalcSpritemapPos_Default,
  &Samus_CalcSpritemapPos_Default,
  &Samus_CalcSpritemapPos_Default,
  &Samus_CalcSpritemapPos_Special,
};

PairU16 Samus_CalcSpritemapPos(uint16 k) {
  PairU16 v1;

  if (ceres_status & kCeresStatus_8000_ElevatorRoomRotate) {
    uint16 old_x = samus_x_pos, old_y = samus_y_pos;
    Samus_CalcPos_Mode7();
    v1 = kSamus_CalcSpritemapPos[samus_movement_type](k);
    samus_y_pos = old_y;
    samus_x_pos = old_x;
  } else {
    v1 = kSamus_CalcSpritemapPos[samus_movement_type](k);
  }
  return MakePairU16(v1.k, v1.j);
}

PairU16 Samus_CalcSpritemapPos_Default(uint16 j) {  // 0x908C94
  int v1 = (int8)*(&kPoseParams[0].y_offset_to_gfx + 4 * j);
  samus_spritemap_y_pos = samus_y_pos - v1 - layer1_y_pos;
  samus_spritemap_x_pos = samus_x_pos - layer1_x_pos;
  return MakePairU16(samus_spritemap_x_pos, samus_spritemap_y_pos);
}

PairU16 Samus_CalcSpritemapPos_Standing(uint16 j) {  // 0x908CC3
  static const uint8 g_byte_908D28[16] = {
    3, 6, 0, 0,
    3, 6, 0, 0,
    3, 3, 6, 0,
    3, 3, 6, 0,
  };

  int16 v1;
  PairU16 v3;

  v1 = j >> 1;
  if (!(j >> 1) || v1 == kPose_9B_FaceF_VariaGravitySuit) {
    if (!sign16(samus_anim_frame - 2)) {
      samus_spritemap_y_pos = samus_y_pos - 1 - layer1_y_pos;
      samus_spritemap_x_pos = samus_x_pos - layer1_x_pos;
      return MakePairU16(samus_x_pos - layer1_x_pos, samus_y_pos - 1 - layer1_y_pos);
    }
  } else if (!sign16(v1 - kPose_A4_FaceR_LandJump) && sign16(v1 - kPose_A8_FaceR_Grappling)) {
    uint16 r18 = *(uint16 *)&g_byte_908D28[(uint16)(samus_anim_frame + 4 * (v1 - 164))];
    samus_spritemap_y_pos = samus_y_pos - r18 - layer1_y_pos;
    samus_spritemap_x_pos = samus_x_pos - layer1_x_pos;
    return MakePairU16(samus_x_pos - layer1_x_pos, samus_y_pos - r18 - layer1_y_pos);
  }
  v3 = Samus_CalcSpritemapPos_Default(j);
  return MakePairU16(v3.k, v3.j);
}

PairU16 Samus_CalcSpritemapPos_Transitions(uint16 j) {  // 0x908D3C
  static const int8 byte_908D80[24] = {
    -8,  0, -8,  0,
    -4, -2, -4, -2,
     0,  0,  0,  0,
    -4,  0, -4,  0,
     5,  4,  5,  4,
     0,  0,  0,  0,
  };

  int16 v1;

  v1 = j >> 1;
  if (sign16((j >> 1) - kPose_35_FaceR_CrouchTrans) || !sign16(v1 - kPose_41_FaceL_Morphball_Ground)) {
    return Samus_CalcSpritemapPos_Default(j);
  } else {
    int v4 = byte_908D80[(uint16)(samus_anim_frame + 2 * (v1 - 53))];
    samus_spritemap_y_pos = v4 + samus_y_pos - layer1_y_pos;
    samus_spritemap_x_pos = samus_x_pos - layer1_x_pos;
    return MakePairU16(samus_x_pos - layer1_x_pos, samus_spritemap_y_pos);
  }
}

PairU16 Samus_CalcSpritemapPos_Special(uint16 j) {  // 0x908D98
  static const int8 byte_908DEF[32] = {
   7, 5, -8, -8, -8, -8, -8, -5,
   4, 4,  4,  4,  0,  0,  4, -3,
  -5, 0,  0,  4, -3, -5, -3,  4,
   0, 0,  4,  0,  0,  4,  0,  0,
  };
  int v1, v2;

  v1 = j >> 1;
  if (v1 == kPose_E8_FaceR_Drained_CrouchFalling || v1 == kPose_E9_FaceL_Drained_CrouchFalling) {
    v2 = byte_908DEF[samus_anim_frame];
  } else {
    if (v1 != kPose_EA_FaceR_Drained_Stand && v1 != kPose_EB_FaceL_Drained_Stand || (int16)(samus_anim_frame - 5) < 0) {
      return Samus_CalcSpritemapPos_Default(j);
    }
    v2 = -3;
  }
  samus_spritemap_y_pos = v2 + samus_y_pos - layer1_y_pos;
  samus_spritemap_x_pos = samus_x_pos - layer1_x_pos;
  return MakePairU16(samus_x_pos - layer1_x_pos, v2 + samus_y_pos - layer1_y_pos);
}

void SetLiquidPhysicsType(void) {  // 0x908E0F
  int16 samus_bottom_bound = Samus_GetBottom_R18();
  switch ((fx_type & 0xF) >> 1) {
    case (kFxType_2_Lava >> 1) | ((kFxType_22_Unused & 0xF) >> 1) :
    case (kFxType_4_Acid >> 1) | ((kFxType_24_Fireflea & 0xF) >> 1) :
      if (0 <= (int16)lava_acid_y_pos && (int16)lava_acid_y_pos < samus_bottom_bound) {
        liquid_physics_type = kLiquidPhysicsType_LavaAcid;
      }
      else {
        liquid_physics_type = kLiquidPhysicsType_Air;
      }
      break;
    
    case (kFxType_6_Water >> 1) | ((kFxType_26_TourianEntranceStatue & 0xF) >> 1) :
      if (0 <= (int16)fx_y_pos && (int16)fx_y_pos < samus_bottom_bound
          && !(fx_liquid_options & kFxLiquidOption_4_LiquidPhysicsDisabled)) {
        liquid_physics_type = kLiquidPhysicsType_Water;
      }
      else {
        liquid_physics_type = kLiquidPhysicsType_Air;
      }
      break;
    
    default:
      liquid_physics_type = kLiquidPhysicsType_Air;
    }
}

void Samus_HandleMovement_X(void) {  // 0x908E64
  Samus_HandleExtraRunspeedX();
  Samus_MoveX(Samus_CalcBaseSpeed_X(Samus_DetermineSpeedTableEntryPtr_X()));
}

void Samus_MoveX(int32 amt) {  // 0x908EA9
  if (!samus_x_accel_mode || samus_x_accel_mode == 2) {
    if (samus_pose_x_dir != kSamusXDir_FaceLeft) {
LABEL_6:
      amt = Samus_CalcDisplacementMoveRight(amt);
      goto LABEL_8;
    }
  } else if (samus_pose_x_dir != kSamusXDir_FaceRight) {
    goto LABEL_6;
  }
  amt = Samus_CalcDisplacementMoveLeft(amt);
LABEL_8:
  if (amt < 0)
    Samus_MoveLeft(amt);
  else
    Samus_MoveRight(amt);
}

void Samus_BombJumpRisingXMovement_(void) {
  int32 amt;
  if (knockback_dir) {
    amt = Samus_CalcBaseSpeed_X(Samus_DetermineSpeedTableEntryPtr_X());
    if (!knockback_x_dir)
      goto LABEL_6;
LABEL_5:
    amt = Samus_CalcDisplacementMoveRight(amt);
    goto LABEL_7;
  }
  amt = Samus_CalcBaseSpeed_X(addr_kSamusSpeedTable_DuringDiagonalBombJump);
  if ((uint8)bomb_jump_dir != 1)
    goto LABEL_5;
LABEL_6:
  amt = Samus_CalcDisplacementMoveLeft(amt);
LABEL_7:
  if (amt < 0)
    Samus_MoveLeft(amt);
  else
    Samus_MoveRight(amt);
}

void Samus_BombJumpRisingYMovement_(void) {
  if (samus_y_dir == 1) {
    if ((samus_y_speed & 0x8000) != 0) {
      samus_y_subspeed = 0;
      samus_y_speed = 0;
      samus_y_dir = 2;
      if ((uint8)bomb_jump_dir != 2)
        samus_x_accel_mode = 2;
    } else if (sign16(samus_y_speed - 1)) {
      if (samus_input_handler != FUNC16(Samus_InputHandler_Demo))
        samus_input_handler = FUNC16(Samus_InputHandler_Normal);
    }
  }
}

void Samus_BombJumpFallingXMovement_(void) {
  int32 amt = Samus_CalcBaseSpeed_X(Samus_DetermineSpeedTableEntryPtr_X());
  if (samus_push_direction == 1)
    amt = Samus_CalcDisplacementMoveLeft(amt);
  else
    amt = Samus_CalcDisplacementMoveRight(amt);
  if (amt < 0)
    Samus_MoveLeft(amt);
  else
    Samus_MoveRight(amt);
}

void Samus_BombJumpFallingYMovement_(void) {
  if (sign16(samus_y_speed - 5))
    AddToHiLo(&samus_y_speed, &samus_y_subspeed, __PAIR32__(samus_y_accel, samus_y_subaccel));
  Samus_MoveDown(__PAIR32__(samus_y_speed, samus_y_subspeed));
}

void Samus_JumpingMovement(void) {  // 0x908FB3
  Samus_HandleExtraRunspeedX();
  if (samus_pose == kPose_4B_FaceR_Jumptrans
      || samus_pose == kPose_4C_FaceL_Jumptrans
      || !sign16(samus_pose - kPose_55_FaceR_Jumptrans_AimU) && sign16(samus_pose - kPose_5B)) {
    samus_x_accel_mode = 0;
    Samus_Move_NoBaseSpeed_X();
    Samus_MoveExtraY();
    return;
  }
  if (samus_y_dir == 1 && ((button_config_jump_a & joypad1_lastkeys) == 0 || (samus_y_speed & 0x8000) != 0)) {
    samus_y_subspeed = 0;
    samus_y_speed = 0;
    samus_y_dir = 2;
  }
  Pair_Bool_Amt pair = Samus_CalcBaseSpeed_NoDecel_X(Samus_DetermineSpeedTableEntryPtr_X());
  if (samus_movement_type == kMovementType_14_WallJumping) {
    if (!samus_x_accel_mode)
      samus_x_accel_mode = 2;
    goto LABEL_17;
  }
  if (samus_x_accel_mode || (joypad1_lastkeys & kButton_Right) != 0 || (joypad1_lastkeys & kButton_Left) != 0) {
LABEL_17:
    Samus_MoveX(pair.amt);
    goto LABEL_18;
  }
  samus_x_base_speed = 0;
  samus_x_base_subspeed = 0;
  samus_collision_flag = 0;
LABEL_18:
  Samus_MoveY_WithSpeedCalc();
}

void Samus_SpinJumpMovement(void) {  // 0x909040
  static const uint16 g_word_909E9F = 8;

  Samus_HandleExtraRunspeedX();
  if (samus_y_dir == 1 && ((button_config_jump_a & joypad1_lastkeys) == 0 || (samus_y_speed & 0x8000) != 0)) {
    samus_y_subspeed = 0;
    samus_y_speed = 0;
    samus_y_dir = 2;
  }
  Pair_Bool_Amt pair = Samus_CalcBaseSpeed_NoDecel_X(Samus_DetermineSpeedTableEntryPtr_X());
  if (pair.flag || samus_x_accel_mode == 1)
    goto LABEL_12;
  if (samus_pose_x_dir == kSamusXDir_FaceLeft) {
    if ((joypad1_lastkeys & kButton_Left) != 0)
      goto LABEL_12;
LABEL_11:
    pair.amt = 0;
    samus_x_base_speed = 0;
    samus_x_base_subspeed = 0;
    samus_collision_flag = 0;
    samus_x_accel_mode = 0;
    goto LABEL_14;
  }
  if ((joypad1_lastkeys & kButton_Right) == 0)
    goto LABEL_11;
LABEL_12:
  if (!samus_x_accel_mode)
    samus_x_accel_mode = 2;
LABEL_14:
  Samus_MoveX(pair.amt);
  if (!Samus_WallJumpCheck(INT16_SHL16(g_word_909E9F)))
    Samus_MoveY_WithSpeedCalc();
}

void Samus_CheckStartFalling(void) {  // 0x9090C4
  if (samus_y_dir == 1 && (samus_y_speed & 0x8000) != 0) {
    samus_y_subspeed = 0;
    samus_y_speed = 0;
    samus_y_dir = 2;
  }
}

void Samus_MoveY_WithSpeedCalc(void) {  // 0x9090E2
  int32 amt = __PAIR32__(samus_y_speed, samus_y_subspeed);
  if (samus_y_dir == 2) {
    if (samus_y_speed != 5)
      AddToHiLo(&samus_y_speed, &samus_y_subspeed, __PAIR32__(samus_y_accel, samus_y_subaccel));
  } else {
    AddToHiLo(&samus_y_speed, &samus_y_subspeed, -IPAIR32(samus_y_accel, samus_y_subaccel));
  }
  if (samus_y_dir != 2)
    amt = -amt;
  amt += __PAIR32__(extra_samus_y_displacement, extra_samus_y_subdisplacement);
  if (amt < 0)
    Samus_MoveUp(amt);
  else
    Samus_MoveDown(amt);
}

void Samus_FallingMovement(void) {  // 0x909168
  Samus_HandleExtraRunspeedX();
  Pair_Bool_Amt pair = Samus_CalcBaseSpeed_NoDecel_X(Samus_DetermineSpeedTableEntryPtr_X());
  if (samus_x_accel_mode || (joypad1_lastkeys & kButton_Right) != 0 || (joypad1_lastkeys & kButton_Left) != 0) {
    Samus_MoveX(pair.amt);
  } else {
    samus_x_base_speed = 0;
    samus_x_base_subspeed = 0;
    samus_collision_flag = 0;
  }
  Samus_CheckStartFalling();
  Samus_MoveY_WithSpeedCalc();
}

void Samus_MorphedFallingMovement(void) {  // 0x90919F
  Pair_Bool_Amt pair = Samus_CalcBaseSpeed_NoDecel_X(Samus_DetermineSpeedTableEntryPtr_X());
  if (!samus_x_accel_mode && (joypad1_lastkeys & kButton_Right) == 0 && (joypad1_lastkeys & kButton_Left) == 0) {
    pair.amt = 0;
    samus_x_base_speed = 0;
    samus_x_base_subspeed = 0;
    samus_collision_flag = 0;
  }
  Samus_MoveX(pair.amt);
  Samus_CheckStartFalling();
  Samus_MoveY_WithSpeedCalc();
}

void Samus_MorphedBouncingMovement(void) {  // 0x9091D1
  Pair_Bool_Amt pair = Samus_CalcBaseSpeed_NoDecel_X(Samus_DetermineSpeedTableEntryPtr_X());
  if (!samus_x_accel_mode && (joypad1_lastkeys & kButton_Right) == 0 && (joypad1_lastkeys & kButton_Left) == 0) {
    pair.amt = 0;
    samus_x_base_speed = 0;
    samus_x_base_subspeed = 0;
    samus_collision_flag = 0;
  }
  Samus_MoveX(pair.amt);
  if (!knockback_dir) {
    if (extra_samus_y_displacement || extra_samus_y_subdisplacement) {
      samus_y_dir = 2;
      samus_y_subspeed = 0;
      samus_y_speed = 0;
      int32 amt = __PAIR32__(extra_samus_y_displacement, extra_samus_y_subdisplacement);
      if (amt < 0)
        Samus_MoveUp(amt);
      else
        Samus_MoveDown(amt + INT16_SHL16(1));
    } else {
      Samus_CheckStartFalling();
      Samus_MoveY_WithSpeedCalc();
    }
  }
}

void Samus_Move_NoSpeedCalc_Y(void) {  // 0x90923F
  int32 amt = __PAIR32__(extra_samus_y_displacement, extra_samus_y_subdisplacement);
  if (amt == 0) {
    if (!samus_pos_adjusted_by_slope_flag)
      amt = __PAIR32__(samus_total_x_speed, samus_total_x_subspeed);
    Samus_MoveDown(amt + INT16_SHL16(1));
  } else {
    if (amt < 0)
      Samus_MoveUp(amt);
    else
      Samus_MoveDown(amt + INT16_SHL16(1));
  }
}

void Samus_MoveExtraY(void) {  // 0x909288
  int32 amt = __PAIR32__(extra_samus_y_displacement, extra_samus_y_subdisplacement);
  if (amt != 0) {
    if (amt < 0)
      Samus_MoveUp(amt);
    else
      Samus_MoveDown(amt + INT16_SHL16(1));
  }
}

uint8 Samus_CheckAndMoveY(void) {  // 0x9092B8
  if (!samus_y_dir)
    return 0;
  Samus_CheckStartFalling();
  Samus_MoveY_WithSpeedCalc();
  return 1;
}

uint8 Samus_MoveY_Simple_(void) {  // 0x9092C7
  if (!samus_y_dir)
    return 0;
  Samus_CheckStartFalling();
  Samus_MoveY_WithSpeedCalc();
  return 1;
}

void Samus_Move_NoBaseSpeed_X(void) {  // 0x909348
  Samus_MoveX(0);
}

void Samus_MoveLeft(int32 amt) {  // 0x909350
  amt = -amt;
  CheckEnemyColl_Result cres = Samus_CheckSolidEnemyColl(amt);
  samus_collision_flag = cres.collision, amt = cres.amt;
  if (samus_collision_flag) {
    Samus_ClearXSpeedIfColl();
    Samus_MoveLeft_NoColl(amt);
    Samus_AlignYPosSlope();
  } else {
    amt = Samus_MoveRight_NoSolidColl(-amt);
    SetHiLo(&projectile_init_speed_samus_moved_left, &projectile_init_speed_samus_moved_left_fract, amt);
    if ((samus_collision_direction & 1) != 0)
      samus_collision_flag = 0;
    Samus_ClearXSpeedIfColl();
    Samus_AlignYPosSlope();
  }
}

void Samus_MoveRight(int32 amt) {  // 0x9093B1
  CheckEnemyColl_Result cres = Samus_CheckSolidEnemyColl(amt);
  samus_collision_flag = cres.collision, amt = cres.amt;
  if (samus_collision_flag) {
    Samus_ClearXSpeedIfColl();
    Samus_MoveRight_NoColl(amt);
    Samus_AlignYPosSlope();
  } else {
    amt = Samus_MoveRight_NoSolidColl(amt);
    SetHiLo(&projectile_init_speed_samus_moved_right, &projectile_init_speed_samus_moved_right_fract, amt);
    if ((samus_collision_direction & 1) == 0)
      samus_collision_flag = 0;
    Samus_ClearXSpeedIfColl();
    Samus_AlignYPosSlope();
  }
}

void Samus_MoveUp(int32 amt) {  // 0x9093EC
  samus_collision_direction = 2;
  CheckEnemyColl_Result cres = Samus_CheckSolidEnemyColl(-amt);
  samus_collision_flag = cres.collision, amt = cres.amt;
  if (samus_collision_flag) {
    Samus_MoveUp_SetPoseCalcInput();
    Samus_MoveUp_NoColl(amt);
  } else {
    amt = Samus_MoveDown_NoSolidColl(-amt);
    SetHiLo(&projectile_init_speed_samus_moved_up, &projectile_init_speed_samus_moved_up_fract, amt);
    Samus_MoveUp_SetPoseCalcInput();
  }
}

void Samus_MoveDown(int32 amt) {  // 0x909440
  samus_collision_direction = 3;
  CheckEnemyColl_Result cres = Samus_CheckSolidEnemyColl(amt);
  samus_collision_flag = cres.collision, amt = cres.amt;
  if (samus_collision_flag) {
    Samus_MoveDown_SetPoseCalcInput();
    Samus_MoveDown_NoColl(amt);
  } else {
    amt = Samus_MoveDown_NoSolidColl(amt);
    projectile_init_speed_samus_moved_down_fract = amt;
    projectile_init_speed_samus_moved_down = amt >> 16;
    Samus_MoveDown_SetPoseCalcInput();
  }
}

void Samus_MovementHandler_ReleaseFromGrapple(void) {  // 0x90946E
  if (samus_y_dir == 1 && (samus_y_speed & 0x8000) != 0) {
    samus_y_subspeed = 0;
    samus_y_speed = 0;
    samus_y_dir = 2;
    samus_movement_handler = FUNC16(Samus_MovementHandler_Normal);
  }
  samus_x_accel_mode = 2;
  int32 amt = Samus_CalcBaseSpeed_X(Samus_DetermineGrappleSwingSpeed_X());
  if (samus_x_accel_mode || (joypad1_lastkeys & kButton_Right) != 0 || (joypad1_lastkeys & kButton_Left) != 0) {
    Samus_MoveX(amt);
  } else {
    samus_x_base_speed = 0;
    samus_x_base_subspeed = 0;
    samus_collision_flag = 0;
  }
  Samus_MoveY_WithSpeedCalc();
  if (input_to_pose_calc)
    samus_movement_handler = FUNC16(Samus_MovementHandler_Normal);
}

void Samus_MovementHandler_DrainedCrouching(void) {  // 0x9094CB
  Samus_MoveY_WithSpeedCalc();
  if (samus_collision_flag) {
    samus_movement_handler = FUNC16(Samus_MovementHandler_Normal);
    samus_anim_frame_timer = 8;
    samus_anim_frame = 7;
    samus_y_subspeed = 0;
    samus_y_speed = 0;
  }
}

void CallScrollingFinishedHook(uint32 ea) {
  switch (ea) {
  case fnSamus_ScrollFinishedHook_SporeSpawnFight: Samus_ScrollFinishedHook_SporeSpawnFight(); return;
  default: Unreachable();
  }
}

void MainScrollingRoutine(void) {  // 0x9094EC
  if (slow_grapple_scrolling_flag) {
    if ((samus_x_pos & 0x8000) != 0)
      goto LABEL_14;
    uint16 v0;
    v0 = samus_x_pos - layer1_x_pos;
    if (samus_x_pos < layer1_x_pos)
      goto LABEL_7;
    if (v0 >= 0xA0) {
      layer1_x_pos += 3;
      goto LABEL_8;
    }
    if (v0 < 0x60)
      LABEL_7:
    layer1_x_pos -= 3;
LABEL_8:
    if ((samus_y_pos & 0x8000) == 0) {
      uint16 v1 = samus_y_pos - layer1_y_pos;
      if (samus_y_pos >= layer1_y_pos) {
        if (v1 >= 0x90) {
          layer1_y_pos += 3;
          goto LABEL_14;
        }
        if (v1 >= 0x70)
          goto LABEL_14;
      }
      layer1_y_pos -= 3;
    }
LABEL_14:
    HandleAutoscrolling_X();
    HandleAutoscrolling_Y();
    goto LABEL_16;
  }
  Samus_CalcDistanceMoved_X();
  Samus_HandleScroll_X();
  Samus_CalcDistanceMoved_Y();
  Samus_HandleScroll_Y();
LABEL_16:
  if (scrolling_finished_hook)
    CallScrollingFinishedHook(scrolling_finished_hook | 0x900000);
  samus_prev_x_pos = samus_x_pos;
  samus_prev_x_subpos = samus_x_subpos;
  samus_prev_y_pos = samus_y_pos;
  samus_prev_y_subpos = samus_y_subpos;
}

void Samus_ScrollFinishedHook_SporeSpawnFight(void) {  // 0x909589
  if (layer1_y_pos <= 0x1D0)
    layer1_y_pos = 464;
}

void Samus_HandleScroll_X(void) {  // 0x9095A0
  static const uint16 kSamus_HandleScroll_X_FaceLeft[4] = { 0xa0, 0x50, 0x20, 0xe0 };
  static const uint16 kSamus_HandleScroll_X_FaceRight[4] = { 0x60, 0x40, 0x20, 0xe0 };
  if (samus_prev_x_pos == samus_x_pos) {
    HandleAutoscrolling_X();
    return;
  }
  if ((knockback_dir || samus_movement_type == kMovementType_10_Moonwalking || samus_x_accel_mode == 1) ^ (samus_pose_x_dir != kSamusXDir_FaceLeft)) {
    ideal_layer1_xpos = samus_x_pos - kSamus_HandleScroll_X_FaceRight[camera_distance_index >> 1];
  } else {
    ideal_layer1_xpos = samus_x_pos - kSamus_HandleScroll_X_FaceLeft[camera_distance_index >> 1];
  }
  if (ideal_layer1_xpos != layer1_x_pos) {
    if ((int16)(ideal_layer1_xpos - layer1_x_pos) < 0) {
      AddToHiLo(&layer1_x_pos, &layer1_x_subpos, -IPAIR32(camera_x_speed, camera_x_subspeed));
      HandleScrollingWhenTriggeringScrollLeft();
    } else {
      AddToHiLo(&layer1_x_pos, &layer1_x_subpos, __PAIR32__(camera_x_speed, camera_x_subspeed));
      HandleScrollingWhenTriggeringScrollRight();
    }
  }
}

void Samus_HandleScroll_Y(void) {  // 0x90964F
  if (samus_prev_y_pos == samus_y_pos) {
    HandleAutoscrolling_Y();
  } else {
    //r18 = layer1_y_pos;
    if (samus_y_dir == 1)
      ideal_layer1_ypos = samus_y_pos - down_scroller;
    else
      ideal_layer1_ypos = samus_y_pos - up_scroller;
    if (ideal_layer1_ypos != layer1_y_pos) {
      if ((int16)(ideal_layer1_ypos - layer1_y_pos) < 0) {
        AddToHiLo(&layer1_y_pos, &layer1_y_subpos, -IPAIR32(camera_y_speed, camera_y_subspeed));
        HandleScrollingWhenTriggeringScrollUp();
      } else {
        AddToHiLo(&layer1_y_pos, &layer1_y_subpos, __PAIR32__(camera_y_speed, camera_y_subspeed));
        HandleScrollingWhenTriggeringScrollDown();
      }
    }
  }
}

void Samus_CalcDistanceMoved_X(void) {  // 0x9096C0
  if ((int16)(samus_x_pos - samus_prev_x_pos) >= 0) {
    SetHiLo(&camera_x_speed, &camera_x_subspeed,
      __PAIR32__(samus_x_pos, samus_x_subpos) - __PAIR32__(samus_prev_x_pos, samus_prev_x_subpos) + (1 << 16));
  } else {
    SetHiLo(&camera_x_speed, &camera_x_subspeed,
      __PAIR32__(samus_prev_x_pos, samus_prev_x_subpos) - __PAIR32__(samus_x_pos, samus_x_subpos) + (1 << 16));
  }
}

void Samus_CalcDistanceMoved_Y(void) {  // 0x9096FF
  if ((int16)(samus_y_pos - samus_prev_y_pos) >= 0) {
    SetHiLo(&camera_y_speed, &camera_y_subspeed,
      __PAIR32__(samus_y_pos, samus_y_subpos) - __PAIR32__(samus_prev_y_pos, samus_prev_y_subpos) + (1 << 16));
  } else {
    SetHiLo(&camera_y_speed, &camera_y_subspeed,
      __PAIR32__(samus_prev_y_pos, samus_prev_y_subpos) - __PAIR32__(samus_y_pos, samus_y_subpos) + (1 << 16));
  }
}

static const uint16 kSamus_HandleExtraRunspeedX_Tab0[3] = { 0, 0, 0 };
static const uint16 kSamus_HandleExtraRunspeedX_Tab1[3] = { 0x1000, 0x400, 0x400 };
static const uint16 kSamus_HandleExtraRunspeedX_Tab2[3] = { 7, 4, 4 };
static const uint16 kSamus_HandleExtraRunspeedX_Tab3[3] = { 0, 0, 0 };
static const uint16 kSamus_HandleExtraRunspeedX_Tab4[3] = { 2, 1, 0 };
static const uint16 kSamus_HandleExtraRunspeedX_Tab5[3] = { 0, 0, 0 };

void Samus_HandleExtraRunspeedX(void) {  // 0x90973E
  if ((equipped_items & kItem_GravitySuit) == 0) {
    uint16 r18 = Samus_GetBottom_R18();
    if ((fx_y_pos & 0x8000) != 0) {
      if ((lava_acid_y_pos & 0x8000) == 0 && sign16(lava_acid_y_pos - r18)) {
LABEL_24:
        if (!samus_has_momentum_flag) {
          samus_x_extra_run_speed = 0;
          samus_x_extra_run_subspeed = 0;
        }
        goto LABEL_26;
      }
    } else if (sign16(fx_y_pos - r18) && !(fx_liquid_options & kFxLiquidOption_4_LiquidPhysicsDisabled)) {
      goto LABEL_24;
    }
  }
  if (samus_movement_type != kMovementType_01_Running || (button_config_run_b & joypad1_lastkeys) == 0)
    goto LABEL_24;
  if ((equipped_items & kItem_SpeedBooster) != 0) {
    if (!samus_has_momentum_flag) {
      samus_has_momentum_flag = 1;
      special_samus_palette_timer = 1;
      special_samus_palette_frame = 0;
      speed_boost_counter = kSpeedBoostToCtr[0];
    }
    if ((int16)(samus_x_extra_run_speed - kSamus_HandleExtraRunspeedX_Tab2[0]) >= 0
        && (int16)(samus_x_extra_run_subspeed - kSamus_HandleExtraRunspeedX_Tab3[0]) >= 0) {
      samus_x_extra_run_speed = kSamus_HandleExtraRunspeedX_Tab2[0];
      samus_x_extra_run_subspeed = kSamus_HandleExtraRunspeedX_Tab3[0];
      goto LABEL_26;
    }
  } else {
    if (!samus_has_momentum_flag) {
      samus_has_momentum_flag = 1;
      speed_boost_counter = 0;
    }
    if ((int16)(samus_x_extra_run_speed - kSamus_HandleExtraRunspeedX_Tab4[0]) >= 0
        && (int16)(samus_x_extra_run_subspeed - kSamus_HandleExtraRunspeedX_Tab5[0]) >= 0) {
      samus_x_extra_run_speed = kSamus_HandleExtraRunspeedX_Tab4[0];
      samus_x_extra_run_subspeed = kSamus_HandleExtraRunspeedX_Tab5[0];
      goto LABEL_26;
    }
  }
  AddToHiLo(&samus_x_extra_run_speed, &samus_x_extra_run_subspeed,
      __PAIR32__(kSamus_HandleExtraRunspeedX_Tab0[0], kSamus_HandleExtraRunspeedX_Tab1[0]));
LABEL_26:
  if ((speed_boost_counter & 0xFF00) == 0x400)
    samus_contact_damage_index = kSamusContactDamageIndex_1_SpeedBoost;
}

void Samus_MoveRight_NoColl(int32 amt) {  // 0x909826
  AddToHiLo(&samus_x_pos, &samus_x_subpos, amt);
  SetHiLo(&projectile_init_speed_samus_moved_right, &projectile_init_speed_samus_moved_right_fract, amt);
}

void Samus_MoveLeft_NoColl(int32 amt) {  // 0x909842
  AddToHiLo(&samus_x_pos, &samus_x_subpos, -amt);
  SetHiLo(&projectile_init_speed_samus_moved_left, &projectile_init_speed_samus_moved_left_fract, -amt);
}

void Samus_MoveDown_NoColl(int32 amt) {  // 0x909871
  AddToHiLo(&samus_y_pos, &samus_y_subpos, amt);
  SetHiLo(&projectile_init_speed_samus_moved_down, &projectile_init_speed_samus_moved_down_fract, amt);
}

void Samus_MoveUp_NoColl(int32 amt) {  // 0x90988D
  AddToHiLo(&samus_y_pos, &samus_y_subpos, -amt);
  SetHiLo(&projectile_init_speed_samus_moved_up, &projectile_init_speed_samus_moved_up_fract, -amt);
}

void Samus_InitJump(void) {  // 0x9098BC
  static const uint16 kSamus_InitJump_Speed_Y[3] = { 4, 1, 2 };
  static const uint16 kSamus_InitJump_Subspeed_Y[3] = { 0xe000, 0xc000, 0xc000 };
  static const uint16 kSamus_InitJump_HiJump_Speed_Y[3] = { 6, 2, 3 };
  static const uint16 kSamus_InitJump_HiJump_Subspeed_Y[3] = { 0, 0x8000, 0x8000 };
  uint16 v0;

  if ((equipped_items & kItem_GravitySuit) != 0)
    goto LABEL_7;
  uint16 r18 = Samus_GetBottom_R18();
  if ((fx_y_pos & 0x8000) == 0) {
    if (sign16(fx_y_pos - r18) && !(fx_liquid_options & kFxLiquidOption_4_LiquidPhysicsDisabled)) {
      v0 = 2;
      goto LABEL_11;
    }
LABEL_7:
    v0 = 0;
    goto LABEL_11;
  }
  if ((lava_acid_y_pos & 0x8000) != 0 || !sign16(lava_acid_y_pos - r18))
    goto LABEL_7;
  v0 = 4;
LABEL_11:;
  int v1 = v0 >> 1;
  if ((equipped_items & kItem_HiJumpBoots) != 0) {
    samus_y_subspeed = kSamus_InitJump_HiJump_Subspeed_Y[v1];
    samus_y_speed = kSamus_InitJump_HiJump_Speed_Y[v1];
  } else {
    samus_y_subspeed = kSamus_InitJump_Subspeed_Y[v1];
    samus_y_speed = kSamus_InitJump_Speed_Y[v1];
  }
  if ((equipped_items & kItem_SpeedBooster) != 0) {
    samus_y_subspeed += samus_x_extra_run_subspeed;
    samus_y_speed += samus_x_extra_run_speed >> 1;
  }
  grapple_walljump_timer = 0;
  reached_ceres_elevator_fade_timer = 0;
  samus_y_dir = 1;
}

void Samus_InitWallJump(void) {  // 0x909949
  static const uint16 kSamus_InitWallJump_Speed_Y[3] = { 4, 0, 2 };
  static const uint16 kSamus_InitWallJump_Subspeed_Y[3] = { 0xa000, 0x4000, 0xa000 };
  static const uint16 kSamus_InitWallJump_HiJump_Speed_Y[3] = { 5, 0, 3 };
  static const uint16 kSamus_InitWallJump_HiJump_Subspeed_Y[3] = { 0x8000, 0x8000, 0x8000 };
  uint16 v0;

  if ((equipped_items & kItem_GravitySuit) != 0)
    goto LABEL_7;
  uint16 r18 = Samus_GetBottom_R18();
  if ((fx_y_pos & 0x8000) == 0) {
    if (sign16(fx_y_pos - r18) && !(fx_liquid_options & kFxLiquidOption_4_LiquidPhysicsDisabled)) {
      v0 = 2;
      goto LABEL_11;
    }
LABEL_7:
    v0 = 0;
    goto LABEL_11;
  }
  if ((lava_acid_y_pos & 0x8000) != 0 || !sign16(lava_acid_y_pos - r18))
    goto LABEL_7;
  v0 = 4;
LABEL_11:;
  int v1 = v0 >> 1;
  if ((equipped_items & kItem_HiJumpBoots) != 0) {
    samus_y_subspeed = kSamus_InitWallJump_HiJump_Subspeed_Y[v1];
    samus_y_speed = kSamus_InitWallJump_HiJump_Speed_Y[v1];
  } else {
    samus_y_subspeed = kSamus_InitWallJump_Subspeed_Y[v1];
    samus_y_speed = kSamus_InitWallJump_Speed_Y[v1];
  }
  if ((equipped_items & kItem_SpeedBooster) != 0) {
    r18 = samus_x_extra_run_speed >> 1;
    samus_y_subspeed += samus_x_extra_run_subspeed;
    samus_y_speed += samus_x_extra_run_speed >> 1;
  }
  grapple_walljump_timer = 0;
  reached_ceres_elevator_fade_timer = 0;
  samus_y_dir = 1;
}

static const uint16 kSamus_SetSpeedForKnockback_Y_Speed[3] = { 5, 2, 2 };
static const uint16 kSamus_SetSpeedForKnockback_Y_Subspeed[3] = { 0, 0, 0 };

void Samus_SetSpeedForKnockback_Y(void) {  // 0x9099D6
  uint16 v0;

  if ((equipped_items & kItem_GravitySuit) == 0) {
    uint16 r18 = Samus_GetBottom_R18();
    if ((fx_y_pos & 0x8000) != 0) {
      if ((lava_acid_y_pos & 0x8000) == 0 && sign16(lava_acid_y_pos - r18)) {
        v0 = 4;
        goto LABEL_11;
      }
    } else if (sign16(fx_y_pos - r18) && !(fx_liquid_options & kFxLiquidOption_4_LiquidPhysicsDisabled)) {
      v0 = 2;
      goto LABEL_11;
    }
  }
  v0 = 0;
LABEL_11:;
  int v1 = v0 >> 1;
  samus_y_subspeed = kSamus_SetSpeedForKnockback_Y_Subspeed[v1];
  samus_y_speed = kSamus_SetSpeedForKnockback_Y_Speed[v1];
  grapple_walljump_timer = 0;
  reached_ceres_elevator_fade_timer = 0;
  samus_y_dir = 1;
}

void Samus_InitBombJump(void) {  // 0x909A2C
  static const uint16 kSamus_InitBombJump_Speed_Y[3] = { 2, 0, 0 };
  static const uint16 kSamus_InitBombJump_Subspeed_Y[3] = { 0xc000, 0x1000, 0x1000 };
  uint16 v0;

  if ((equipped_items & kItem_GravitySuit) == 0) {
    uint16 r18 = Samus_GetBottom_R18();
    if ((fx_y_pos & 0x8000) != 0) {
      if ((lava_acid_y_pos & 0x8000) == 0 && sign16(lava_acid_y_pos - r18)) {
        v0 = 4;
        goto LABEL_11;
      }
    } else if (sign16(fx_y_pos - r18) && !(fx_liquid_options & kFxLiquidOption_4_LiquidPhysicsDisabled)) {
      v0 = 2;
      goto LABEL_11;
    }
  }
  v0 = 0;
LABEL_11:;
  int v1 = v0 >> 1;
  samus_y_subspeed = kSamus_InitBombJump_Subspeed_Y[v1];
  samus_y_speed = kSamus_InitBombJump_Speed_Y[v1];
  grapple_walljump_timer = 0;
  reached_ceres_elevator_fade_timer = 0;
  samus_y_dir = 1;
}

static bool IsGreaterThanQuirked(uint16 vhi, uint16 vlo, uint16 cmphi, uint16 cmplo) {
  if ((int16)(vhi - cmphi) >= 0) {
    if (vhi != cmphi || ((int16)(vlo - cmplo) >= 0) && vlo != cmplo)
      return true;
  }
  return false;
}

int32 Samus_CalcBaseSpeed_X(uint16 k) {  // 0x909A7E
  SamusSpeedTableEntry *sste = get_SamusSpeedTableEntry(k);
  if (samus_x_accel_mode) {
    int32 delta = samus_x_decel_mult ?
        __PAIR32__(Mult8x8(samus_x_decel_mult, sste->decel) >> 8, Mult8x8(samus_x_decel_mult, HIBYTE(sste->decel_sub))) :
        __PAIR32__(sste->decel, sste->decel_sub);
    AddToHiLo(&samus_x_base_speed, &samus_x_base_subspeed, -delta);
    if ((int16)samus_x_base_speed < 0) {
      samus_x_base_speed = 0;
      samus_x_base_subspeed = 0;
      samus_x_accel_mode = 0;
    }
  } else {
    AddToHiLo(&samus_x_base_speed, &samus_x_base_subspeed, __PAIR32__(sste->accel, sste->accel_sub));
    if (IsGreaterThanQuirked(samus_x_base_speed, samus_x_base_subspeed, sste->max_speed, sste->max_speed_sub)) {
      samus_x_base_speed = sste->max_speed;
      samus_x_base_subspeed = sste->max_speed_sub;
    }
  }
  return __PAIR32__(samus_x_base_speed, samus_x_base_subspeed);
}

static Pair_Bool_Amt Samus_CalcBaseSpeed_NoDecel_X(uint16 k) {  // 0x909B1F
  SamusSpeedTableEntry *sste = get_SamusSpeedTableEntry(k);
  bool rv = false;
  if ((samus_x_accel_mode & 1) != 0) {
    int32 delta = samus_x_decel_mult ?
      __PAIR32__(Mult8x8(samus_x_decel_mult, sste->decel) >> 8, Mult8x8(samus_x_decel_mult, HIBYTE(sste->decel_sub))) :
      __PAIR32__(sste->decel, sste->decel_sub);
    AddToHiLo(&samus_x_base_speed, &samus_x_base_subspeed, -delta);
    if ((int16)samus_x_base_speed < 0) {
      samus_x_base_speed = 0;
      samus_x_base_subspeed = 0;
      samus_x_accel_mode = 0;
    }
  } else {
    AddToHiLo(&samus_x_base_speed, &samus_x_base_subspeed, __PAIR32__(sste->accel, sste->accel_sub));
    if (IsGreaterThanQuirked(samus_x_base_speed, samus_x_base_subspeed, sste->max_speed, sste->max_speed_sub)) {
      samus_x_base_speed = sste->max_speed;
      samus_x_base_subspeed = sste->max_speed_sub;
      rv = true;
    }
  }
  return (Pair_Bool_Amt) { rv, __PAIR32__(samus_x_base_speed, samus_x_base_subspeed) };
}

uint16 Samus_DetermineSpeedTableEntryPtr_X(void) {  // 0x909BD1
  if ((equipped_items & kItem_GravitySuit) == 0) {
    uint16 r18 = Samus_GetBottom_R18();
    if ((fx_y_pos & 0x8000) != 0) {
      if ((lava_acid_y_pos & 0x8000) == 0 && sign16(lava_acid_y_pos - r18))
        samus_x_speed_table_pointer = addr_kSamusSpeedTable_LavaAcid_X;
    } else if (sign16(fx_y_pos - r18) && !(fx_liquid_options & kFxLiquidOption_4_LiquidPhysicsDisabled)) {
      samus_x_speed_table_pointer = addr_kSamusSpeedTable_Water_X;
    }
  }
  return samus_x_speed_table_pointer + 12 * samus_movement_type;
}

uint16 Samus_DetermineGrappleSwingSpeed_X(void) {  // 0x909C21
  if ((equipped_items & kItem_GravitySuit) != 0)
    return addr_kSamusSpeedTable_GrappleDisconnect_Air;
  uint16 r18 = Samus_GetBottom_R18();
  if ((fx_y_pos & 0x8000) == 0) {
    if (sign16(fx_y_pos - r18) && !(fx_liquid_options & kFxLiquidOption_4_LiquidPhysicsDisabled))
      return addr_kSamusSpeedTable_GrappleDisconnect_Water;
    return addr_kSamusSpeedTable_GrappleDisconnect_Air;
  }
  if ((lava_acid_y_pos & 0x8000) != 0 || !sign16(lava_acid_y_pos - r18))
    return addr_kSamusSpeedTable_GrappleDisconnect_Air;
  return addr_kSamusSpeedTable_GrappleDisconnect_LavaAcid;
}

void Samus_DetermineAccel_Y(void) {  // 0x909C5B
  static const uint16 kSamusPhys_YSubaccAir = 0x1c00;
  static const uint16 kSamusPhys_YSubaccWater = 0x800;
  static const uint16 kSamusPhys_YSubaccAcidLava = 0x900;
  static const uint16 kSamusPhys_YAccAir = 0;
  static const uint16 kSamusPhys_YAccWater = 0;
  static const uint16 kSamusPhys_YAccAcidLava = 0;

  if ((equipped_items & kItem_GravitySuit) != 0)
    goto LABEL_7;
  uint16 r18 = Samus_GetBottom_R18();
  if ((fx_y_pos & 0x8000) == 0) {
    if (sign16(fx_y_pos - r18) && !(fx_liquid_options & kFxLiquidOption_4_LiquidPhysicsDisabled)) {
      samus_y_subaccel = kSamusPhys_YSubaccWater;
      samus_y_accel = kSamusPhys_YAccWater;
      return;
    }
LABEL_7:
    samus_y_subaccel = kSamusPhys_YSubaccAir;
    samus_y_accel = kSamusPhys_YAccAir;
    return;
  }
  if ((lava_acid_y_pos & 0x8000) != 0 || !sign16(lava_acid_y_pos - r18))
    goto LABEL_7;
  samus_y_subaccel = kSamusPhys_YSubaccAcidLava;
  samus_y_accel = kSamusPhys_YAccAcidLava;
}

uint8 Samus_GrappleWallJumpCheck(int32 amt) {  // 0x909CAC
  enemy_index_to_shake = -1;
  if (samus_pose_x_dir != kSamusXDir_FaceLeft) {
    if (samus_pose_x_dir != kSamusXDir_FaceRight)
      return 0;
    samus_collision_direction = 1;
  } else {
    samus_collision_direction = 0;
  }
  CheckEnemyColl_Result cres = Samus_CheckSolidEnemyColl(amt);
  if (!cres.collision) {
    amt = WallJumpBlockCollDetect(cres.amt);
    return samus_collision_flag && (button_config_jump_a & joypad1_newkeys) != 0;
  }
  if ((button_config_jump_a & joypad1_newkeys) == 0)
    return 0;
  enemy_index_to_shake = collision_detection_index;
  return 1;
}

uint8 Samus_WallJumpCheck(int32 amt) {  // 0x909D35
  CheckEnemyColl_Result cres;

  if (samus_last_different_pose_movement_type != 3 && samus_last_different_pose_movement_type != 20)
    return 0;
  if (samus_pose == kPose_81_FaceR_Screwattack || samus_pose == kPose_82_FaceL_Screwattack) {
    if (!sign16(samus_anim_frame - 27))
      goto LABEL_22;
    goto LABEL_8;
  }
  if (sign16(samus_anim_frame - 11)) {
LABEL_8:
    if ((joypad1_lastkeys & kButton_Left) == 0) {
      if ((joypad1_lastkeys & kButton_Right) == 0)
        return 0;
      samus_collision_direction = 0;
      cres = Samus_CheckSolidEnemyColl(amt);
      amt = cres.amt;
      if (!cres.collision) {
        amt = WallJumpBlockCollDetect(-amt);
        if (!samus_collision_flag)
          return 0;
      }
    } else {
      samus_collision_direction = 1;
      cres = Samus_CheckSolidEnemyColl(amt);
      amt = cres.amt;
      if (!cres.collision) {
        amt = WallJumpBlockCollDetect(amt);
        if (!samus_collision_flag)
          return 0;
      }
    }
    if (samus_pose == kPose_81_FaceR_Screwattack || samus_pose == kPose_82_FaceL_Screwattack) {
      samus_anim_frame_timer = 1;
      samus_anim_frame = 26;
    } else {
      samus_anim_frame_timer = 1;
      samus_anim_frame = 10;
    }
    return 0;
  }
LABEL_22:
  enemy_index_to_shake = -1;
  if ((joypad1_lastkeys & kButton_Left) != 0) {
    samus_collision_direction = 1;
    cres = Samus_CheckSolidEnemyColl(amt), amt = cres.amt;
    if (!cres.collision) {
      amt = WallJumpBlockCollDetect(amt);
      if (samus_collision_flag && (button_config_jump_a & joypad1_newkeys) != 0)
        goto LABEL_40;
      return 0;
    }
    if ((button_config_jump_a & joypad1_newkeys) == 0)
      return 0;
    goto LABEL_38;
  } else {
    if ((joypad1_lastkeys & kButton_Right) == 0)
      return 0;
    samus_collision_direction = 0;
    cres = Samus_CheckSolidEnemyColl(amt), amt = cres.amt;
    if (!cres.collision) {
      amt = -amt;
      WallJumpBlockCollDetect(amt);
      if (samus_collision_flag && (button_config_jump_a & joypad1_newkeys) != 0)
        goto LABEL_40;
      return 0;
    }
    if ((button_config_jump_a & joypad1_newkeys) == 0)
      return 0;
    goto LABEL_38;

LABEL_40:
    if (sign16((amt >> 16) - 8)) {
      input_to_pose_calc = 5;
      return 1;
    }
    return 0;
LABEL_38:
    if (sign16((amt >> 16) - 8)) {
      input_to_pose_calc = 5;
      enemy_index_to_shake = collision_detection_index;
      return 1;
    }
    return 0;
  }
}

void Samus_Movement_07_Unused(void) {  // 0x90A32D
  input_to_pose_calc = 0;
}

static HandlerFunc *const kSamusMovementHandlers[28] = {  // 0x90A337
  &Samus_Movement_00_Standing,
  &Samus_Movement_01_Running,
  &Samus_Movement_02_NormalJumping,
  &Samus_Movement_03_SpinJumping,
  &Samus_Movement_04_MorphBallOnGround,
  &Samus_Movement_05_Crouching,
  &Samus_Movement_06_Falling,
  &Samus_Movement_07_Unused,
  &Samus_Movement_08_MorphBallFalling,
  &Samus_Movement_09_Unused,
  &Samus_Movement_0A_KnockbackOrCrystalFlashEnding,
  &Samus_Movement_0B_Unused,
  &Samus_Movement_0C_Unused,
  &Samus_Movement_0D_Unused,
  &Samus_Movement_0E_TurningAroundOnGround,
  &Samus_Movement_0F_CrouchingEtcTransition,
  &Samus_Movement_10_Moonwalking,
  &Samus_Movement_11_SpringBallOnGround,
  &Samus_Movement_12_SpringBallInAir,
  &Samus_Movement_13_SpringBallFalling,
  &Samus_Movement_14_WallJumping,
  &Samus_Movement_15_RanIntoWall,
  &Samus_Movement_16_Grappling,
  &Samus_Movement_17_TurningAroundJumping,
  &Samus_Movement_18_TurningAroundFalling,
  &Samus_Movement_19_DamageBoost,
  &Samus_Movement_1A_GrabbedByDraygon,
  &Samus_Movement_1B_ShinesparkEtc,
};

void Samus_MovementHandler_Normal(void) {
  if (!time_is_frozen_flag) {
    kSamusMovementHandlers[samus_movement_type]();
    Samus_UpdateSpeedEchoPos();
  }
}

void Samus_Movement_00_Standing(void) {  // 0x90A383
  if (samus_pose && samus_pose != kPose_9B_FaceF_VariaGravitySuit) {
    if ((samus_pose == kPose_01_FaceR_Normal || samus_pose == kPose_02_FaceL_Normal)
        && (button_config_shoot_x & joypad1_lastkeys) != 0) {
      samus_anim_frame_timer = 16;
      samus_anim_frame = 0;
    }
    Samus_Move_NoBaseSpeed_X();
    Samus_Move_NoSpeedCalc_Y();
    Samus_CancelSpeedBoost();
    samus_x_extra_run_speed = 0;
    samus_x_extra_run_subspeed = 0;
    samus_x_base_speed = 0;
    samus_x_base_subspeed = 0;
    samus_x_accel_mode = 0;
  } else {
    if (elevator_status != kElevatorStatus_Inactive) {
      samus_collision_direction = 2;
      Samus_MoveDown_NoSolidColl(INT16_SHL16(1));
    }
    input_to_pose_calc = 0;
  }
}

void Samus_Movement_01_Running(void) {  // 0x90A3E5
  static const uint8 kSamusFootstepFrame[10] = { 0, 0, 1, 0, 0, 0, 0, 1, 0, 0 };
  Samus_HandleMovement_X();
  Samus_Move_NoSpeedCalc_Y();
  if (samus_anim_frame_timer == 1) {
    if (kSamusFootstepFrame[samus_anim_frame]) {
      Samus_FootstepGraphics();
      if (!cinematic_function && !boss_id && !samus_shine_timer && (speed_boost_counter & 0x400) == 0)
        QueueSfx3_Max6(kSfx3_SamusFootsteps);
    }
  }
}

void Samus_Movement_02_NormalJumping(void) {  // 0x90A42E
  Samus_JumpingMovement();
}

// Warning: OOB

void Samus_Movement_03_SpinJumping(void) {  // 0x90A436
  static const uint16 kSamusPhys_JumpMinYVelAir = 0x280;
  static const uint16 kSamusPhys_JumpMaxYVelAir = 0x500;
  static const uint16 kSamusPhys_JumpMinYVelWater = 0x80;
  static const uint16 kSamusPhys_JumpMaxYVelWater = 0x500;
  uint16 r18 = 0;
  if ((samus_suit_palette_index & kSuitPaletteIndex_4_Gravity) == 0) {
    uint16 r20 = Samus_GetTop_R20();
    if ((fx_y_pos & 0x8000) != 0) {
      if ((lava_acid_y_pos & 0x8000) == 0 && sign16(lava_acid_y_pos - r20))
        r18 = 1;
    } else if (sign16(fx_y_pos - r20) && !(fx_liquid_options & kFxLiquidOption_4_LiquidPhysicsDisabled)) {
      r18 = 1;
    }
  }
  if (!r18) {
    if ((equipped_items & kItem_SpaceJump) != 0) {
      if (samus_y_dir != 2)
        goto LABEL_24;
      if (liquid_physics_type != kLiquidPhysicsType_Air) {
        if ((int16)(*(uint16 *)((uint8 *)&samus_y_subspeed + 1) - kSamusPhys_JumpMinYVelWater) < 0
          || (int16)(*(uint16 *)((uint8 *)&samus_y_subspeed + 1) - kSamusPhys_JumpMaxYVelWater) >= 0) {
          goto LABEL_24;
        }
      } else if ((int16)(*(uint16 *)((uint8 *)&samus_y_subspeed + 1) - kSamusPhys_JumpMinYVelAir) < 0
        || (int16)(*(uint16 *)((uint8 *)&samus_y_subspeed + 1) - kSamusPhys_JumpMaxYVelAir) >= 0) {
        goto LABEL_24;
      }
      UNUSED_word_7E0DFA = UNUSED_word_7E0DFA & 0xFF00 | 1;
      if ((button_config_jump_a & joypad1_newkeys) != 0)
        Samus_InitJump(); // bug: this overwrites r18
    }
LABEL_24:;
    if (samus_pose == kPose_81_FaceR_Screwattack || samus_pose == kPose_82_FaceL_Screwattack) {
      samus_contact_damage_index = kSamusContactDamageIndex_3_ScrewAttack;
    } else if (!sign16(flare_counter - 60)) {
      samus_contact_damage_index = kSamusContactDamageIndex_4_PsuedoScrewAttack;
    }
  } else {
    if (samus_anim_frame_timer == 1 && kSamusFramesForUnderwaterSfx[samus_anim_frame])
      QueueSfx1_Max6(kSfx1_UnderwaterSpaceJump);
  }
  Samus_SpinJumpMovement();
}

void Samus_Movement_04_MorphBallOnGround(void) {  // 0x90A521
  if (!samus_x_accel_mode) {
    if (samus_pose_x_dir == kSamusXDir_FaceLeft) {
      if (samus_pose == kPose_41_FaceL_Morphball_Ground)
        goto LABEL_6;
    } else if (samus_pose == kPose_1D_FaceR_Morphball_Ground) {
LABEL_6:
      Samus_Move_NoBaseSpeed_X();
      if (!(Samus_CheckAndMoveY() & 1)) {
        Samus_Move_NoSpeedCalc_Y();
        Samus_CancelSpeedBoost();
        samus_x_extra_run_speed = 0;
        samus_x_extra_run_subspeed = 0;
        samus_x_base_speed = 0;
        samus_x_base_subspeed = 0;
        samus_x_accel_mode = 0;
      }
      return;
    }
  }
  Samus_HandleMovement_X();
  if (!(Samus_CheckAndMoveY() & 1))
    Samus_Move_NoSpeedCalc_Y();
}

void Samus_Movement_05_Crouching(void) {  // 0x90A573
  Samus_Move_NoBaseSpeed_X();
  Samus_Move_NoSpeedCalc_Y();
  samus_x_extra_run_speed = 0;
  samus_x_extra_run_subspeed = 0;
  samus_x_base_speed = 0;
  samus_x_base_subspeed = 0;
  samus_x_accel_mode = 0;
}

void Samus_Movement_06_Falling(void) {  // 0x90A58D
  Samus_FallingMovement();
  if ((samus_pose == kPose_29_FaceR_Fall
       || samus_pose == kPose_2A_FaceL_Fall
       || samus_pose == kPose_67_FaceR_Fall_Gun
       || samus_pose == kPose_68_FaceL_Fall_Gun)
      && !sign16(samus_y_speed - 5)) {
    if (sign16(samus_anim_frame - 5)) {
      samus_anim_frame_timer = 8;
      samus_anim_frame = 5;
    }
  }
}

void Samus_Movement_08_MorphBallFalling(void) {  // 0x90A5CA
  if ((joypad1_lastkeys & (kButton_Left | kButton_Right)) == 0 && !samus_x_accel_mode) {
    Samus_CancelSpeedBoost();
    samus_x_extra_run_speed = 0;
    samus_x_extra_run_subspeed = 0;
    samus_x_base_speed = 0;
    samus_x_base_subspeed = 0;
    samus_x_accel_mode = 0;
  }
  if (used_for_ball_bounce_on_landing)
    Samus_MorphedBouncingMovement();
  else
    Samus_MorphedFallingMovement();
}

void Samus_Movement_09_Unused(void) {  // 0x90A5FB
  ;
}

void Samus_Movement_0A_KnockbackOrCrystalFlashEnding(void) {  // 0x90A5FC
  input_to_pose_calc = 0;
  Samus_Move_NoSpeedCalc_Y();
}

void Samus_Movement_0B_Unused(void) {  // 0x90A607
  input_to_pose_calc = 0;
}

void Samus_Movement_0C_Unused(void) {  // 0x90A60F
  input_to_pose_calc = 0;
}

void Samus_Movement_0D_Unused(void) {  // 0x90A617
  ;
}

void SamusCrouching_Nothing(void) {}

static HandlerFunc *const kSamusCrouchingEtcFuncs[12] = {  // 0x90A61C
  SamusCrouching_Nothing,
  SamusCrouching_Nothing,
  SamusCrouching_Nothing,
  SamusCrouching_Nothing,
  UNUSED_SamusCrouching_Nothing,
  UNUSED_SamusCrouching_Nothing,
  SamusCrouching_Nothing,
  SamusCrouching_Nothing,
  SamusCrouching_Nothing,
  SamusCrouching_Nothing,
  UNUSED_SamusCrouching_Nothing,
  UNUSED_SamusCrouching_Nothing,
};

void Samus_Movement_0F_CrouchingEtcTransition(void) {
  if (sign16(samus_pose - kPose_F1_FaceR_CrouchTrans_AimU)) {
    if (!sign16(samus_pose - kPose_DB))
      goto LABEL_6;
    kSamusCrouchingEtcFuncs[samus_pose - 53]();
  }
  Samus_Move_NoBaseSpeed_X();
  if (!(Samus_MoveY_Simple_() & 1))
    Samus_Move_NoSpeedCalc_Y();
LABEL_6:
  if (input_to_pose_calc == 1025) {
    samus_y_subspeed = 0;
    samus_y_speed = 0;
    samus_y_dir = 0;
    used_for_ball_bounce_on_landing = 0;
  }
  input_to_pose_calc = 0;
}

void UNUSED_SamusCrouching_Nothing(void) {  // 0x90A672
  enable_horiz_slope_coll = 3;
  UNUSED_word_7E0AA4 = 0;
}

void Samus_Movement_0E_TurningAroundOnGround(void) {  // 0x90A67C
  Samus_HandleMovement_X();
  Samus_Move_NoSpeedCalc_Y();
  Samus_CancelSpeedBoost();
  samus_x_extra_run_speed = 0;
  samus_x_extra_run_subspeed = 0;
  input_to_pose_calc = 0;
}

void Samus_Movement_10_Moonwalking(void) {  // 0x90A694
  Samus_HandleMovement_X();
  Samus_Move_NoSpeedCalc_Y();
}

void Samus_Movement_11_SpringBallOnGround(void) {  // 0x90A69F
  if (!samus_x_accel_mode) {
    if (samus_pose_x_dir == kSamusXDir_FaceLeft) {
      if (samus_pose == kPose_7A_FaceL_Springball_Ground)
        goto LABEL_6;
    } else if (samus_pose == kPose_79_FaceR_Springball_Ground) {
LABEL_6:
      Samus_Move_NoBaseSpeed_X();
      if (!(Samus_CheckAndMoveY() & 1)) {
        Samus_Move_NoSpeedCalc_Y();
        Samus_CancelSpeedBoost();
        samus_x_extra_run_speed = 0;
        samus_x_extra_run_subspeed = 0;
        samus_x_base_speed = 0;
        samus_x_base_subspeed = 0;
        samus_x_accel_mode = 0;
      }
      return;
    }
  }
  Samus_HandleMovement_X();
  if (!(Samus_CheckAndMoveY() & 1))
    Samus_Move_NoSpeedCalc_Y();
}

void Samus_Movement_12_SpringBallInAir(void) {  // 0x90A6F1
  if (used_for_ball_bounce_on_landing)
    Samus_MorphedBouncingMovement();
  else
    Samus_JumpingMovement();
}

void Samus_Movement_13_SpringBallFalling(void) {  // 0x90A703
  if ((joypad1_lastkeys & (kButton_Left | kButton_Right)) == 0 && !samus_x_accel_mode) {
    Samus_CancelSpeedBoost();
    samus_x_extra_run_speed = 0;
    samus_x_extra_run_subspeed = 0;
    samus_x_base_speed = 0;
    samus_x_base_subspeed = 0;
    samus_x_accel_mode = 0;
  }
  if (used_for_ball_bounce_on_landing)
    Samus_MorphedBouncingMovement();
  else
    Samus_MorphedFallingMovement();
}

void Samus_Movement_14_WallJumping(void) {  // 0x90A734
  if (sign16(samus_anim_frame - 23)) {
    if (!sign16(samus_anim_frame - 3) && !sign16(flare_counter - 60))
      samus_contact_damage_index = kSamusContactDamageIndex_4_PsuedoScrewAttack;
  } else {
    samus_contact_damage_index = kSamusContactDamageIndex_3_ScrewAttack;
  }
  Samus_JumpingMovement();
}

void Samus_Movement_15_RanIntoWall(void) {  // 0x90A75F
  Samus_Move_NoBaseSpeed_X();
  Samus_Move_NoSpeedCalc_Y();
  Samus_CancelSpeedBoost();
  samus_x_extra_run_speed = 0;
  samus_x_extra_run_subspeed = 0;
  samus_x_base_speed = 0;
  samus_x_base_subspeed = 0;
  samus_x_accel_mode = 0;
}

void Samus_Movement_16_Grappling(void) {  // 0x90A780
  if (input_to_pose_calc != 5)
    input_to_pose_calc = 0;
}

void Samus_Movement_17_TurningAroundJumping(void) {  // 0x90A790
  Samus_HandleMovement_X();
  if (!(Samus_CheckAndMoveY() & 1))
    Samus_Move_NoSpeedCalc_Y();
  Samus_CancelSpeedBoost();
  samus_x_extra_run_speed = 0;
  samus_x_extra_run_subspeed = 0;
  input_to_pose_calc = 0;
}

void Samus_Movement_18_TurningAroundFalling(void) {  // 0x90A7AD
  Samus_HandleMovement_X();
  if (!(Samus_CheckAndMoveY() & 1))
    Samus_Move_NoSpeedCalc_Y();
  Samus_CancelSpeedBoost();
  samus_x_extra_run_speed = 0;
  samus_x_extra_run_subspeed = 0;
  input_to_pose_calc = 0;
}

void Samus_Movement_19_DamageBoost(void) {  // 0x90A7CA
  Samus_JumpingMovement();
}

void Samus_Movement_1A_GrabbedByDraygon(void) {  // 0x90A7D2
  input_to_pose_calc = 0;
}

void Samus_Movement_1B_ShinesparkEtc(void) {  // 0x90A7DA
  input_to_pose_calc = 0;
}

static const uint8 kMapTileBitmask_1Bit[8] = { 0x80, 0x40, 0x20, 0x10, 8, 4, 2, 1 };
static const uint16 kMapTileBitmask_6Bits[8] = { 0xfc00, 0x7e00, 0x3f00, 0x1f80, 0xfc0, 0x7e0, 0x3f0, 0x1f8 };

static void MarkMapTileAsExplored(uint16 r18, uint16 r24) {  // 0x90A8A6
  uint8 v0 = (uint16)(r18 & 0xFF00) >> 8;
  uint16 R34 = (room_x_coordinate_on_map + v0) & 0x20;
  uint16 r20 = ((room_x_coordinate_on_map + v0) & 0x1F) >> 3;
  uint16 R22 = room_y_coordinate_on_map + ((r24 & 0xFF00) >> 8) + 1;
  map_tiles_explored[(uint16)(r20 + 4 * (R34 + R22))] |= kMapTileBitmask_1Bit[(room_x_coordinate_on_map + v0) & 7];
}

void DisableMinimapAndMarkBossRoomAsExplored(void) {  // 0x90A7E2
  debug_disable_minimap = 1;
  uint16 v0 = 0;
  do {
    int v1 = v0 >> 1;
    hud_tilemap.row1.minimap[v1] = 0x2C1F;
    hud_tilemap.row2.minimap[v1] = 0x2C1F;
    hud_tilemap.row3.minimap[v1] = 0x2C1F;
    v0 += 2;
  } while ((int16)(v0 - 10) < 0);
  uint16 v2 = 5;
  while (boss_id != kBossRoomMapTile[v2].boss_id_) {
    if ((--v2 & 0x8000) != 0)
      return;
  }
  for (int i = kBossRoomMapTile[v2].ptrs; ; i += 4) {
    const uint16 *v4 = (const uint16 *)RomPtr_90(i);
    if ((*v4 & 0x8000) != 0)
      break;
    MarkMapTileAsExplored(v4[0], v4[1]);
  }
}

void InitializeMiniMapBroken(void) {  // 0x90A8EF
  //SetR18_R20(room_x_coordinate_on_map + ((samus_x_pos & 0xFF00) >> 8), r18 >> 3);
  //R22_ = room_y_coordinate_on_map + ((samus_y_pos & 0xFF00) >> 8) + 1;
  //UpdateMinimapInside();
}


void UpdateMinimap(void) {  // 0x90A91B
  int16 v4;
  int16 v10;

  if (debug_disable_minimap || (samus_x_pos >> 4) >= room_width_in_blocks ||
      (samus_y_pos >> 4) >= room_height_in_blocks)
    return;
  uint16 r46 = 0;
  uint8 v0 = (uint16)(samus_x_pos & 0xFF00) >> 8;
  uint16 r34 = (room_x_coordinate_on_map + v0) & 0x20;
  uint16 r18 = (room_x_coordinate_on_map + v0) & 0x1F;
  uint16 v1 = (room_x_coordinate_on_map + v0) & 7;
  uint16 r20 = ((room_x_coordinate_on_map + v0) & 0x1F) >> 3;
  uint16 r22 = room_y_coordinate_on_map + ((samus_y_pos & 0xFF00) >> 8) + 1;
  uint16 v2 = r20 + 4 * (r34 + r22);
  map_tiles_explored[v2] |= kMapTileBitmask_1Bit[(room_x_coordinate_on_map + v0) & 7];
  uint16 r32 = v1;
  uint16 r30 = v2;
  uint16 v3 = v2 - 4;
  v4 = v1 - 2;
  if ((int16)(v1 - 2) < 0) {
    v4 &= 7;
    --v3;
    ++r46;
  }
  uint16 R50 = v3;
  int r52 = 2 * v4;
  int v6 = r52 >> 1;
  uint16 r24 = kMapTileBitmask_6Bits[v6] & swap16(*(uint16 *)&map_tiles_explored[v3]);
  uint16 r26 = kMapTileBitmask_6Bits[v6] & swap16(*(uint16 *)&map_tiles_explored[v3 + 4]);
  uint16 r28 = kMapTileBitmask_6Bits[v6] & swap16(*(uint16 *)&map_tiles_explored[v3 + 8]);
  const uint8 *r9 = RomPtr_82(kPauseMenuMapData_90[area_index]);
  const uint8 *r15 = r9;
  r9 += v3;
  uint16 r38 = swap16(GET_WORD(r9));
  r9 += 4;
  uint16 r40 = swap16(GET_WORD(r9));
  r9 += 4;
  uint16 r42 = swap16(GET_WORD(r9));
  if ((R50 & 3) == 3) {
    v10 = r46 ? r52 >> 1 : r32;
    if (!sign16(v10 - 6)) {
      uint8 R48 = r34 ? (R50 - 124) : (R50 + 125);

      uint16 v0 = (uint8)R48;
      uint16 r44 = 0;
      r9 = r15 + (uint8)R48;
      LOBYTE(r44) = map_tiles_explored[(uint8)R48];
      HIBYTE(r44) = *r9;
      if ((uint8)r34 == 32) {
        HIBYTE(r38) = HIBYTE(r44);
        HIBYTE(r24) = r44;
      } else {
        LOBYTE(r38) = HIBYTE(r44);
        LOBYTE(r24) = r44;
      }
      LOBYTE(r44) = map_tiles_explored[v0 + 4];
      r9 += 4;
      HIBYTE(r44) = *r9;
      if ((uint8)r34 == 32) {
        HIBYTE(r40) = HIBYTE(r44);
        HIBYTE(r26) = r44;
      } else {
        LOBYTE(r40) = HIBYTE(r44);
        LOBYTE(r26) = r44;
      }
      LOBYTE(r44) = map_tiles_explored[v0 + 8];
      r9 += 4;
      HIBYTE(r44) = *r9;
      if ((uint8)r34 == 32) {
        HIBYTE(r42) = HIBYTE(r44);
        HIBYTE(r28) = r44;
      } else {
        LOBYTE(r42) = HIBYTE(r44);
        LOBYTE(r28) = r44;
      }
    }
  }
  for (int n = r52 >> 1; n; n--) {
    r24 *= 2;
    r38 *= 2;
    r26 *= 2;
    r40 *= 2;
    r28 *= 2;
    r42 *= 2;
  }
  UpdateMinimapInside(r18, r22, r34, r30, r32, r38, r24, r40, r26, r42, r28);
}

void UpdateMinimapInside(uint16 r18, uint16 r22, uint16 r34, uint16 r30, uint16 r32,
                         uint16 r38, uint16 r24, uint16 r40,
                         uint16 r26, uint16 r42, uint16 r28) {  // 0x90AA43
  uint16 v0;
  int16 v1;
  int16 v5;
  int16 v7;
  int16 v8;

  LOBYTE(v0) = (uint16)(r34 + r22) >> 8;
  HIBYTE(v0) = r34 + r22;
  uint16 t = r18 + (v0 >> 3);
  if (r34 && sign16((t & 0x1F) - 2))
    v1 = t - 1026;
  else
    v1 = t - 34;
  uint16 v2 = 2 * v1;
  const uint16 *r0 = (const uint16 *)RomPtr(Load24(&kPauseMenuMapTilemaps_90[area_index]));
  const uint16 *r3 = r0 + 32;
  const uint16 *r6 = r0 + 64;
  int n = 5;
  uint16 v3 = 0;
  do {
    bool v4 = r38 >> 15;
    r38 *= 2;
    if (!v4 || (v5 = r0[v2 >> 1], !has_area_map))
      v5 = 0x1F;
    int v6 = v3 >> 1;
    hud_tilemap.row1.minimap[v6] = v5 & 0xC3FF | 0x2C00;

    v4 = r24 >> 15;
    r24 *= 2;
    if (v4)
      hud_tilemap.row1.minimap[v6] = r0[v2 >> 1] & 0xC3FF | 0x2800;
    
    v4 = r40 >> 15;
    r40 *= 2;
    if (!v4 || (v7 = r3[v2 >> 1], !has_area_map))
      v7 = 0x1F;
    hud_tilemap.row2.minimap[v6] = v7 & 0xC3FF | 0x2C00;

    v4 = r26 >> 15;
    r26 *= 2;
    if (v4) {
      hud_tilemap.row2.minimap[v6] = r3[v2 >> 1] & 0xC3FF | 0x2800;
      if (n == 3 && (hud_tilemap.row2.minimap[v6] & 0x1FF) == 40) {
        // MarkMapTileAboveSamusAsExplored
        *((uint8 *)&music_data_index + r30) |= kMapTileBitmask_1Bit[r32];
      }
    }

    v4 = r42 >> 15;
    r42 *= 2;
    if (!v4 || (v8 = r6[v2 >> 1], !has_area_map))
      v8 = 0x1F;
    hud_tilemap.row3.minimap[v6] = v8 & 0xC3FF | 0x2C00;

    v4 = r28 >> 15;
    r28 *= 2;
    if (v4)
      hud_tilemap.row3.minimap[v6] = r6[v2 >> 1] & 0xC3FF | 0x2800;

    v3 += 2;
    v2 += 2;
    if ((v2 & 0x3F) == 0)
      v2 += (0x800 - 0x40);
  } while (--n);
  if ((nmi_frame_counter_byte & 8) == 0)
    hud_tilemap.row2.minimap_samus_pos |= 0x1C00;
}

void Samus_HandleCooldown(void) {  // 0x90AC1C
  if (time_is_frozen_flag) {
    cooldown_timer = 32;
  } else if (cooldown_timer) {
    if ((cooldown_timer & 0x8000) != 0 || (--cooldown_timer, (cooldown_timer & 0x8000) != 0))
      cooldown_timer = 0;
  }
}

uint8 Samus_CanFireBeam(void) {  // 0x90AC39
  if (!sign16(projectile_counter - 5) || (uint8)cooldown_timer)
    return 0;
  cooldown_timer = 1;
  ++projectile_counter;
  return 1;
}

uint8 Samus_CanFireSuperMissile(void) {  // 0x90AC5A
  if (hud_item_index != kHudItem_2_SuperMissile) {
    if (!sign16(projectile_counter - 5))
      return 0;
LABEL_3:
    if (!(uint8)cooldown_timer) {
      cooldown_timer = 1;
      ++projectile_counter;
      return 1;
    }
    return 0;
  }
  if (sign16(projectile_counter - 4))
    goto LABEL_3;
  return 0;
}


void UpdateBeamTilesAndPalette(void) {  // 0x90AC8D
  uint16 v0 = 2 * (equipped_beams & 0xFFF);
  uint16 v1 = vram_write_queue_tail;
  gVramWriteEntry(vram_write_queue_tail)->size = 256;
  v1 += 2;
  gVramWriteEntry(v1)->size = kBeamTilePtrs[v0 >> 1];
  v1 += 2;
  LOBYTE(gVramWriteEntry(v1++)->size) = -102;
  gVramWriteEntry(v1)->size = addr_kVram_Beam;
  vram_write_queue_tail = v1 + 2;
  WriteBeamPalette_Y(v0);
}

void WriteBeamPalette_A(uint16 a) {  // 0x90ACC2
  WriteBeamPalette_Y(2 * (a & 0xFFF));
}

void WriteBeamPalette_Y(uint16 j) {  // 0x90ACCD
  uint16 r0 = kBeamPalettePtrs[j >> 1];
  uint16 v1 = 0;
  uint16 v2 = 0;
  do {
    palette_buffer.sprite_pal_6[(v2 >> 1)] = GET_WORD(RomPtr_90(r0 + v1));
    v2 += 2;
    v1 += 2;
  } while ((int16)(v1 - 0x20) < 0);
}

void LoadProjectilePalette(uint16 a) {  // 0x90ACFC
  uint16 r0 = kBeamPalettePtrs[a & 0xFFF];
  uint16 v1 = 0;
  uint16 v2 = 0;
  do {
    palette_buffer.sprite_pal_6[(v2 >> 1)] = GET_WORD(RomPtr_90(r0 + v1));
    v2 += 2;
    v1 += 2;
  } while ((int16)(v1 - 0x20) < 0);
}

void ResetProjectileData(void) {  // 0x90AD22
  uint16 v0 = 0;
  do {
    int v1 = v0 >> 1;
    projectile_timers[v1] = 0;
    projectile_x_pos[v1] = 0;
    projectile_y_pos[v1] = 0;
    projectile_dir[v1] = 0;
    projectile_x_speed[v1] = 0;
    projectile_y_speed[v1] = 0;
    projectile_x_radius[v1] = 0;
    projectile_y_radius[v1] = 0;
    projectile_type[v1] = 0;
    projectile_damage[v1] = 0;
    projectile_instruction_ptr[v1] = 0;
    projectile_instruction_timers[v1] = 0;
    projectile_variables[v1] = 0;
    projectile_spritemap_pointers[v1] = 0;
    projectile_pre_instructions[v1] = FUNC16(ProjPreInstr_Empty);
    v0 += 2;
  } while ((int16)(v0 - 20) < 0);
  bomb_counter = 0;
  cooldown_timer = 0;
  projectile_counter = 0;
  power_bomb_flag = 0;
  if (hud_auto_cancel_flag) {
    hud_item_index = 0;
    samus_auto_cancel_hud_item_index = 0;
  }
  speed_echo_xpos[0] = 0;
  speed_echo_xpos[1] = 0;
  speed_echo_xpos[2] = 0;
  speed_echo_xpos[3] = 0;
  speed_echo_ypos[0] = 0;
  speed_echo_ypos[1] = 0;
  speed_echo_ypos[2] = 0;
  speed_echo_ypos[3] = 0;
  speed_echo_xspeed[0] = 0;
  speed_echo_xspeed[1] = 0;
  speed_echo_xspeed[2] = 0;
  speed_echo_xspeed[3] = 0;
  speed_echoes_index = 0;
  if (samus_special_super_palette_flags) {
    samus_special_super_palette_flags = 0;
    Samus_LoadSuitTargetPalette();
  }
  if (hyper_beam_flag)
    SpawnPalfxObject(addr_kPalfx_HyperBeam);
}

void ClearProjectile(uint16 k) {  // 0x90ADB7
  int v1 = k >> 1;
  projectile_x_pos[v1] = 0;
  projectile_y_pos[v1] = 0;
  projectile_x_subpos[v1] = 0;
  projectile_y_subpos[v1] = 0;
  projectile_dir[v1] = 0;
  projectile_x_speed[v1] = 0;
  projectile_y_speed[v1] = 0;
  projectile_x_radius[v1] = 0;
  projectile_y_radius[v1] = 0;
  projectile_type[v1] = 0;
  projectile_damage[v1] = 0;
  projectile_instruction_ptr[v1] = 0;
  projectile_instruction_timers[v1] = 0;
  projectile_variables[v1] = 0;
  projectile_spritemap_pointers[v1] = 0;
  projectile_pre_instructions[v1] = FUNC16(ProjPreInstr_Empty);
  if ((int16)(k - 10) >= 0) {
    if ((--bomb_counter & 0x8000) != 0)
      bomb_counter = 0;
  } else if ((--projectile_counter & 0x8000) != 0) {
    projectile_counter = 0;
  }
}

static Func_Y_V *const kKillProjectileFuncs[10] = {  // 0x90AE06
  KillProjectileFunc_0_Up,
  KillProjectileFunc_1_UpRight,
  KillProjectileFunc_2_Right,
  KillProjectileFunc_3_DownRight,
  KillProjectileFunc_4_Down,
  KillProjectileFunc_4_Down,
  KillProjectileFunc_6_DownLeft,
  KillProjectileFunc_7_Left,
  KillProjectileFunc_8_UpLeft,
  KillProjectileFunc_0_Up,
};

void KillProjectile(uint16 k) {

  int v1 = k >> 1;
  if ((projectile_type[v1] & kProjectileType_ProjMask) != 0) {
    if (!sign16((HIBYTE(projectile_type[v1]) & kProjectileType_BeamMask) - ((kProjectileType_SuperMissile | kProjectileType_Missile) >> 8))) {
      ClearProjectile(k);
      return;
    }
  } else {
    kKillProjectileFuncs[projectile_dir[v1] & kProjectileDir_DirMask](k);
  }
  KillProjectileInner(k);
  projectile_pre_instructions[k >> 1] = FUNC16(ProjPreInstr_Empty);
}

void KillProjectileFunc_0_Up(uint16 j) {  // 0x90AE4E
  projectile_y_pos[j >> 1] -= projectile_y_radius[j >> 1];
}

void KillProjectileFunc_1_UpRight(uint16 j) {  // 0x90AE59
  int v1 = j >> 1;
  projectile_x_pos[v1] += projectile_x_radius[v1];
  projectile_y_pos[v1] -= projectile_y_radius[v1];
}

void KillProjectileFunc_2_Right(uint16 j) {  // 0x90AE6E
  projectile_x_pos[j >> 1] += projectile_x_radius[j >> 1];
}

void KillProjectileFunc_3_DownRight(uint16 j) {  // 0x90AE79
  int v1 = j >> 1;
  projectile_x_pos[v1] += projectile_x_radius[v1];
  projectile_y_pos[v1] += projectile_y_radius[v1];
}

void KillProjectileFunc_4_Down(uint16 j) {  // 0x90AE8E
  projectile_y_pos[j >> 1] += projectile_y_radius[j >> 1];
}

void KillProjectileFunc_6_DownLeft(uint16 j) {  // 0x90AE99
  int v1 = j >> 1;
  projectile_x_pos[v1] -= projectile_x_radius[v1];
  projectile_y_pos[v1] += projectile_y_radius[v1];
}

void KillProjectileFunc_7_Left(uint16 j) {  // 0x90AEAE
  projectile_x_pos[j >> 1] -= projectile_x_radius[j >> 1];
}

void KillProjectileFunc_8_UpLeft(uint16 j) {  // 0x90AEB9
  int v1 = j >> 1;
  projectile_x_pos[v1] -= projectile_x_radius[v1];
  projectile_y_pos[v1] -= projectile_y_radius[v1];
}

void CallProjPreInstr(uint32 ea, uint16 k) {
  switch (ea) {
  case fnProjPreInstr_Empty: return;
  case fnProjPreInstr_Beam_NoWaveBeam: ProjPreInstr_Beam_NoWaveBeam(k); return;
  case fnProjPreInstr_BlockCollNoWaveBeamVert: ProjPreInstr_BlockCollNoWaveBeamVert(k); return;
  case fnProjPreInstr_BlockCollNoWaveBeamDiagonal: ProjPreInstr_BlockCollNoWaveBeamDiagonal(k); return;
  case fnProjPreInstr_BlockCollNoWaveBeamHoriz: ProjPreInstr_BlockCollNoWaveBeamHoriz(k); return;
  case fnProjPreInstr_Missile: ProjPreInstr_Missile(k); return;
  case fnProjPreInstr_BlockCollMissileVert: ProjPreInstr_BlockCollMissileVert(k); return;
  case fnProjPreInstr_BlockCollMissileDiagonal: ProjPreInstr_BlockCollMissileDiagonal(k); return;
  case fnProjPreInstr_BlockCollMissileHoriz: ProjPreInstr_BlockCollMissileHoriz(k); return;
  case fnProjPreInstr_SuperMissile: ProjPreInstr_SuperMissile(k); return;
  case fnProjPreInstr_BlockCollSuperMissileVert: ProjPreInstr_BlockCollSuperMissileVert(k); return;
  case fnProjPreInstr_BlockCollSuperMissileDiagonal: ProjPreInstr_BlockCollSuperMissileDiagonal(k); return;
  case fnProjPreInstr_BlockCollSuperMissileHoriz: ProjPreInstr_BlockCollSuperMissileHoriz(k); return;
  case fnProjPreInstr_SuperMissileLink: ProjPreInstr_SuperMissileLink(k); return;
  case fnProjPreInstr_Bomb: ProjPreInstr_Bomb(k); return;
  case fnProjPreInstr_PowerBomb: ProjPreInstr_PowerBomb(k); return;
  case fnProjPreInstr_WaveCombined: ProjPreInstr_WaveCombined(k); return;
  case fnProjPreInstr_BeamOrIceWave: ProjPreInstr_BeamOrIceWave(k); return;
  case fnProjPreInstr_Wave_Shared: ProjPreInstr_Wave_Shared(k); return;
  case fnProjPreInstr_BlockCollWaveBeamVert: ProjPreInstr_BlockCollWaveBeamVert(k); return;
  case fnProjPreInstr_BlockCollWaveBeamDiagonal: ProjPreInstr_BlockCollWaveBeamDiagonal(k); return;
  case fnProjPreInstr_BlockCollWaveBeamHoriz: ProjPreInstr_BlockCollWaveBeamHoriz(k); return;
  case fnProjPreInstr_HyperBeam: ProjPreInstr_HyperBeam(k); return;
  case fnProjPreInstr_IceSbaMain: ProjPreInstr_IceSbaMain(k); return;
  case fnProjPreInstr_IceSbaEnd: ProjPreInstr_IceSbaEnd(k); return;
  case fnProjPreInstr_SpeedEcho: ProjPreInstr_SpeedEcho(k); return;
  case fnProjPreInstr_PlasmaSba: ProjPreInstr_PlasmaSba(k); return;
  case fnProjPreInstr_PlasmaSba_Phase0Expand: ProjPreInstr_PlasmaSba_Phase0_Expand(k); return;
  case fnProjPreInstr_PlasmaSba_Phase1Contract: ProjPreInstr_PlasmaSba_Phase1_Contract(k); return;
  case fnProjPreInstr_PlasmaSba_Phase2Disperse: ProjPreInstr_PlasmaSba_Phase2_Disperse(k); return;
  case fnProjPreInstr_SpreadBomb: ProjPreInstr_SpreadBomb(k); return;
  case fnProjPreInstr_WaveSba: ProjPreInstr_WaveSba(k); return;
  case fnProjPreInstr_SpazerSba: ProjPreInstr_SpazerSba(k); return;
  case fnProjPreInstr_EndOfSpazerSba: ProjPreInstr_EndOfSpazerSba(k); return;
  case fnProjPreInstr_UnknownProj8027: ProjPreInstr_UnknownProj8027(k); return;
  default: Unreachable();
  }
}

void HandleProjectile(void) {  // 0x90AECE
  projectile_index = 18;
  for (int i = 18; i >= 0; projectile_index = i) {
    int v1 = i >> 1;
    if (projectile_instruction_ptr[v1]) {
      CallProjPreInstr(projectile_pre_instructions[v1] | 0x900000, i);
      RunProjectileInstructions();
      i = projectile_index;
    }
    i -= 2;
  }
}

static const int16 kDirToVelMult16_X[10] = { 0, 16, 16, 16, 0, 0, -16, -16, -16, 0 };
static const int16 kDirToVelMult16_Y[10] = { -16, -16, 0, 16, 16, 16, 16, 0, -16, -16 };

static Func_Y_V *const kProjPreInstr_Beam_Funcs[10] = {  // 0x90AEF3
  ProjPreInstr_BlockCollNoWaveBeamVert,
  ProjPreInstr_BlockCollNoWaveBeamDiagonal,
  ProjPreInstr_BlockCollNoWaveBeamHoriz,
  ProjPreInstr_BlockCollNoWaveBeamDiagonal,
  ProjPreInstr_BlockCollNoWaveBeamVert,
  ProjPreInstr_BlockCollNoWaveBeamVert,
  ProjPreInstr_BlockCollNoWaveBeamDiagonal,
  ProjPreInstr_BlockCollNoWaveBeamHoriz,
  ProjPreInstr_BlockCollNoWaveBeamDiagonal,
  ProjPreInstr_BlockCollNoWaveBeamVert,
};

void ProjPreInstr_Beam_NoWaveBeam(uint16 k) {

  int v1 = k >> 1;
  if ((projectile_dir[v1] & (0xF0 | kProjectileDir_Delete)) != 0) {
    ClearProjectile(k);
  } else {
    if (projectile_timers[v1]-- == 1) {
      projectile_timers[v1] = 4;
      SpawnProjectileTrail(k);
      k = projectile_index;
    }
    int v3 = k >> 1;
    uint16 v4 = 2 * (projectile_dir[v3] & kProjectileDir_DirMask);
    int v5 = v4 >> 1;
    projectile_x_speed[v3] += kDirToVelMult16_X[v5];
    projectile_y_speed[v3] += kDirToVelMult16_Y[v5];
    kProjPreInstr_Beam_Funcs[v5](v4);
    DeleteProjectileIfFarOffScreen();
  }
}

void ProjPreInstr_BlockCollNoWaveBeamVert(uint16 k) {  // 0x90AF4A
  BlockCollNoWaveBeamVert(projectile_index);
}

void ProjPreInstr_BlockCollNoWaveBeamDiagonal(uint16 k) {  // 0x90AF52
  uint16 v1 = projectile_index;
  if (!(BlockCollNoWaveBeamHoriz(projectile_index) & 1))
    BlockCollNoWaveBeamVert(v1);
}

void ProjPreInstr_BlockCollNoWaveBeamHoriz(uint16 k) {  // 0x90AF60
  BlockCollNoWaveBeamHoriz(projectile_index);
}

static Func_Y_V *const kProjPreInstr_Missile_Funcs[10] = {  // 0x90AF68
  ProjPreInstr_BlockCollMissileVert,
  ProjPreInstr_BlockCollMissileDiagonal,
  ProjPreInstr_BlockCollMissileHoriz,
  ProjPreInstr_BlockCollMissileDiagonal,
  ProjPreInstr_BlockCollMissileVert,
  ProjPreInstr_BlockCollMissileVert,
  ProjPreInstr_BlockCollMissileDiagonal,
  ProjPreInstr_BlockCollMissileHoriz,
  ProjPreInstr_BlockCollMissileDiagonal,
  ProjPreInstr_BlockCollMissileVert,
};

void ProjPreInstr_Missile(uint16 k) {

  int v1 = k >> 1;
  if ((projectile_dir[v1] & (0xF0 | kProjectileDir_Delete)) != 0) {
    ClearProjectile(k);
  } else {
    if (projectile_timers[v1]-- == 1) {
      projectile_timers[v1] = 4;
      SpawnProjectileTrail(k);
      k = projectile_index;
    }
    int v3 = k >> 1;
    uint16 v4 = 2 * (projectile_dir[v3] & kProjectileDir_DirMask);
    int v5 = v4 >> 1;
    projectile_x_speed[v3] += kDirToVelMult16_X[v5];
    projectile_y_speed[v3] += kDirToVelMult16_Y[v5];
    AccelerateMissileOrSuperMissile(k);
    kProjPreInstr_Missile_Funcs[v4 >> 1](v4);
    DeleteProjectileIfFarOffScreen();
  }
}

void ProjPreInstr_BlockCollMissileVert(uint16 k) {  // 0x90AFC7
  BlockCollMissileVert(projectile_index);
}

void ProjPreInstr_BlockCollMissileDiagonal(uint16 k) {  // 0x90AFCF
  uint16 v1 = projectile_index;
  if (!BlockCollMissileHoriz(projectile_index))
    BlockCollMissileVert(v1);
}

void ProjPreInstr_BlockCollMissileHoriz(uint16 k) {  // 0x90AFDD
  BlockCollMissileHoriz(projectile_index);
}

static Func_Y_V *const kProjPreInstr_SuperMissile_Funcs[10] = {  // 0x90AFE5
  ProjPreInstr_BlockCollSuperMissileVert,
  ProjPreInstr_BlockCollSuperMissileDiagonal,
  ProjPreInstr_BlockCollSuperMissileHoriz,
  ProjPreInstr_BlockCollSuperMissileDiagonal,
  ProjPreInstr_BlockCollSuperMissileVert,
  ProjPreInstr_BlockCollSuperMissileVert,
  ProjPreInstr_BlockCollSuperMissileDiagonal,
  ProjPreInstr_BlockCollSuperMissileHoriz,
  ProjPreInstr_BlockCollSuperMissileDiagonal,
  ProjPreInstr_BlockCollSuperMissileVert,
};

void ProjPreInstr_SuperMissile(uint16 k) {
  int16 v3;

  int v1 = k >> 1;
  if ((projectile_dir[v1] & (0xF0 | kProjectileDir_Delete)) != 0) {
    ClearProjectile(k);
LABEL_7:
    for (int i = 8; i >= 0; i -= 2) {
      if ((projectile_type[i >> 1] & 0xFFF) == kProjectileType_SuperMissile)
        ClearProjectile(i);
    }
    return;
  }
  if (projectile_timers[v1]-- == 1) {
    projectile_timers[v1] = 2;
    SpawnProjectileTrail(k);
    k = projectile_index;
  }
  v3 = projectile_dir[k >> 1] & kProjectileDir_DirMask;
  AccelerateMissileOrSuperMissile(k);
  kProjPreInstr_SuperMissile_Funcs[v3](v3);
  if (DeleteProjectileIfFarOffScreen() & 1)
    goto LABEL_7;
}

void ProjPreInstr_BlockCollSuperMissileVert(uint16 k) {  // 0x90B047
  BlockCollMissileVert(projectile_index);
  SuperMissileBlockCollDetect_Y();
}

void ProjPreInstr_BlockCollSuperMissileDiagonal(uint16 k) {  // 0x90B052
  uint16 v1 = projectile_index;
  if (BlockCollMissileHoriz(projectile_index)) {
    SuperMissileBlockCollDetect_X();
  } else {
    SuperMissileBlockCollDetect_X();
    BlockCollMissileVert(v1);
    SuperMissileBlockCollDetect_Y();
  }
}

void ProjPreInstr_BlockCollSuperMissileHoriz(uint16 k) {  // 0x90B06A
  BlockCollMissileHoriz(projectile_index);
  SuperMissileBlockCollDetect_X();
}

void ProjPreInstr_SuperMissileLink(uint16 k) {  // 0x90B075
  if ((projectile_dir[k >> 1] & (0xF0 | kProjectileDir_Delete)) != 0) {
    ClearProjectile(k);
    for (int i = 8; i >= 0; i -= 2) {
      if ((projectile_type[i >> 1] & 0xFFF) == kProjectileType_SuperMissile)
        ClearProjectile(i);
    }
  }
}

void ProjPreInstr_Bomb(uint16 k) {  // 0x90B099
  if ((projectile_dir[k >> 1] & (0xF0 | kProjectileDir_Delete)) != 0) {
    ClearProjectile(k);
  } else {
    HandleBomb();
    BombOrPowerBomb_ExplosionBlockCollHandling(k);
  }
}

void ProjPreInstr_PowerBomb(uint16 k) {  // 0x90B0AE
  if ((projectile_dir[k >> 1] & (0xF0 | kProjectileDir_Delete)) != 0) {
    ClearProjectile(k);
  } else {
    HandlePowerBomb();
    BombOrPowerBomb_ExplosionBlockCollHandling(k);
  }
}

void ProjPreInstr_WaveCombined(uint16 k) {  // 0x90B0C3
  int v1 = k >> 1;
  if ((projectile_dir[v1] & (0xF0 | kProjectileDir_Delete)) != 0) {
    ClearProjectile(k);
  } else if (projectile_timers[v1]-- == 1) {
    projectile_timers[v1] = 4;
    SpawnProjectileTrail(k);
    ProjPreInstr_Wave_Shared(projectile_index);
  } else {
    ProjPreInstr_Wave_Shared(k);
  }
}

void ProjPreInstr_BeamOrIceWave(uint16 k) {  // 0x90B0E4
  int v1 = k >> 1;
  if ((projectile_dir[v1] & (0xF0 | kProjectileDir_Delete)) != 0) {
    ClearProjectile(k);
  } else if (projectile_timers[v1]-- == 1) {
    projectile_timers[v1] = 3;
    SpawnProjectileTrail(k);
    ProjPreInstr_Wave_Shared(projectile_index);
  } else {
    ProjPreInstr_Wave_Shared(k);
  }
}

static Func_Y_V *const kProjPreInstr_WavePlasmaEtcFuncs[10] = {  // 0x90B103
  ProjPreInstr_BlockCollWaveBeamVert,
  ProjPreInstr_BlockCollWaveBeamDiagonal,
  ProjPreInstr_BlockCollWaveBeamHoriz,
  ProjPreInstr_BlockCollWaveBeamDiagonal,
  ProjPreInstr_BlockCollWaveBeamVert,
  ProjPreInstr_BlockCollWaveBeamVert,
  ProjPreInstr_BlockCollWaveBeamDiagonal,
  ProjPreInstr_BlockCollWaveBeamHoriz,
  ProjPreInstr_BlockCollWaveBeamDiagonal,
  ProjPreInstr_BlockCollWaveBeamVert,
};

void ProjPreInstr_Wave_Shared(uint16 k) {

  int v1 = k >> 1;
  uint16 v2 = 2 * (projectile_dir[v1] & kProjectileDir_DirMask);
  int v3 = v2 >> 1;
  projectile_x_speed[v1] += kDirToVelMult16_X[v3];
  projectile_y_speed[v1] += kDirToVelMult16_Y[v3];
  kProjPreInstr_WavePlasmaEtcFuncs[v3](v2);
  DeleteProjectileIfFarOffScreen();
}

void ProjPreInstr_BlockCollWaveBeamVert(uint16 k) {  // 0x90B13B
  BlockCollWaveBeamVert(projectile_index);
}

void ProjPreInstr_BlockCollWaveBeamDiagonal(uint16 k) {  // 0x90B143
  uint16 v1 = projectile_index;
  if (!(BlockCollWaveBeamHoriz(projectile_index) & 1))
    BlockCollWaveBeamVert(v1);
}

void ProjPreInstr_BlockCollWaveBeamHoriz(uint16 k) {  // 0x90B151
  BlockCollWaveBeamHoriz(projectile_index);
}

void ProjPreInstr_HyperBeam(uint16 k) {  // 0x90B159
  if ((projectile_dir[k >> 1] & (0xF0 | kProjectileDir_Delete)) != 0)
    ClearProjectile(k);
  else
    ProjPreInstr_Wave_Shared(k);
}

uint8 DeleteProjectileIfFarOffScreen(void) {  // 0x90B16A
  int16 v0;
  int16 v2;

  v0 = projectile_x_pos[projectile_index >> 1] - layer1_x_pos;
  if (!sign16(v0 + 64)) {
    if (sign16(v0 - 320)) {
      v2 = projectile_y_pos[projectile_index >> 1] - layer1_y_pos;
      if (!sign16(v2 + 64)) {
        if (sign16(v2 - 320))
          return 0;
      }
    }
  }
  ClearProjectile(projectile_index);
  return 1;
}

static const uint16 kInitializeProjectileSpeed_XY_Diag[24] = {  // 0x90B197
  0x400, 0x2ab,
  0x400, 0x2ab,
  0x400, 0x2ab,
  0x400, 0x2ab,
  0x400, 0x2ab,
  0x400, 0x2ab,
  0x400, 0x2ab,
  0x400, 0x2ab,
  0x400, 0x2ab,
  0x400, 0x2ab,
  0x400, 0x2ab,
  0x400, 0x2ab,
};

void SetInitialProjectileSpeed(uint16 r20) {
  int v0 = r20 >> 1;
  uint16 v1 = 4 * (projectile_type[v0] & kProjectileType_BeamMask);
  uint16 v2 = 2 * (projectile_dir[v0] & kProjectileDir_DirMask);
  uint16 r22;
  if (v2 == (2 * kProjectileDir_UpFaceRight) || v2 == (2 * kProjectileDir_Right) || v2 == (2 * kProjectileDir_DownFaceRight) 
      || v2 == (2 * kProjectileDir_DownFaceLeft) || v2 == (2 * kProjectileDir_Left) || v2 == (2 * kProjectileDir_UpFaceLeft)) {
    r22 = kInitializeProjectileSpeed_XY_Diag[v1 >> 1];
  } else {
      if (v2 != (2 * kProjectileDir_UpRight) && v2 != (2 * kProjectileDir_DownRight) 
          && v2 != (2 * kProjectileDir_DownLeft) && v2 != (2 * kProjectileDir_UpLeft))
      Unreachable();
    r22 = kInitializeProjectileSpeed_XY_Diag[(v1 >> 1) + 1];
  }
  InitializeProjectileSpeed(r20, r22);
}

void InitializeProjectileSpeedOfType(uint16 r20) {  // 0x90B1DD
  InitializeProjectileSpeed(r20, 0);
}

void InitializeProjectileSpeed(uint16 k, uint16 r22) {  // 0x90B1F3
  uint16 r18;

  int kh = k >> 1;
  projectile_x_subpos[kh] = 0;
  projectile_y_subpos[kh] = 0;
  switch (2 * (projectile_dir[kh] & kProjectileDir_DirMask)) {
  case 0:
  case 18: {
    if ((uint8)projectile_init_speed_samus_moved_up)
      r18 = (*(uint16 *)((uint8 *)&projectile_init_speed_samus_moved_right_fract + 1) >> 2) | 0xC000;
    else
      r18 = 0;
    projectile_y_speed[kh] = r18 - r22;
    projectile_x_speed[kh] = 0;
    break;
  }
  case 2: {
    if ((uint8)projectile_init_speed_samus_moved_up)
      r18 = (*(uint16 *)((uint8 *)&projectile_init_speed_samus_moved_right_fract + 1) >> 2) | 0xC000;
    else
      r18 = 0;
    projectile_y_speed[kh] = r18 - r22;
    projectile_x_speed[kh] = *(uint16 *)((uint8 *)&projectile_init_speed_samus_moved_left_fract + 1) + r22;
    break;
  }
  case 4: {
    projectile_y_speed[kh] = 0;
    projectile_x_speed[kh] = *(uint16 *)((uint8 *)&projectile_init_speed_samus_moved_left_fract + 1) + r22;
    break;
  }
  case 6: {
    projectile_y_speed[kh] = *(uint16 *)((uint8 *)&projectile_init_speed_samus_moved_up_fract + 1) + r22;
    projectile_x_speed[kh] = *(uint16 *)((uint8 *)&projectile_init_speed_samus_moved_left_fract + 1) + r22;
    break;
  }
  case 8:
  case 10: {
    projectile_y_speed[kh] = *(uint16 *)((uint8 *)&projectile_init_speed_samus_moved_up_fract + 1) + r22;
    projectile_x_speed[kh] = 0;
    break;
  }
  case 12: {
    projectile_y_speed[kh] = *(uint16 *)((uint8 *)&projectile_init_speed_samus_moved_up_fract + 1) + r22;
    projectile_x_speed[kh] = *(uint16 *)((uint8 *)&camera_y_subspeed + 1) - r22;
    break;
  }
  case 14: {
    projectile_y_speed[kh] = 0;
    projectile_x_speed[kh] = *(uint16 *)((uint8 *)&camera_y_subspeed + 1) - r22;
    break;
  }
  case 16: {
    if ((uint8)projectile_init_speed_samus_moved_up)
      r18 = (*(uint16 *)((uint8 *)&projectile_init_speed_samus_moved_right_fract + 1) >> 2) | 0xC000;
    else
      r18 = 0;
    projectile_y_speed[kh] = r18 - r22;
    projectile_x_speed[kh] = *(uint16 *)((uint8 *)&camera_y_subspeed + 1) - r22;
    break;
  }
  default:
    Unreachable();
  }
}

void AccelerateMissileOrSuperMissile(uint16 k) {  // 0x90B2F6
  static const uint16 kMissileInitalizedBitset = 0x100;
  uint16 v3;

  int v1 = k >> 1;
  if ((projectile_variables[v1] & 0xFF00) != 0) {
    if ((projectile_type[v1] & kProjectileType_SuperMissile) != 0)
      v3 = addr_kSuperMissileAccelerations;
    else
      v3 = addr_kMissileAccelerations;
    const uint8 *v4 = RomPtr_90(v3 + 4 * (projectile_dir[v1] & kProjectileDir_DirMask));
    projectile_x_speed[v1] += GET_WORD(v4);
    projectile_y_speed[v1] += GET_WORD(v4 + 2);
  } else {
    uint16 v2 = kMissileInitalizedBitset + projectile_variables[v1];
    projectile_variables[v1] = v2;
    if ((v2 & 0xFF00) != 0) {
      InitializeProjectileSpeed(k, projectile_variables[v1]);
      if ((projectile_type[v1] & kProjectileType_SuperMissile) != 0)
        SpawnSuperMissileLink();
    }
  }
}

void SuperMissileBlockCollDetect_Y(void) {  // 0x90B366
  int v0 = projectile_index >> 1;
  if ((projectile_type[v0] & kProjectileType_ProjMask) == kProjectileType_SuperMissile 
      || (projectile_type[v0] & kProjectileType_ProjMask) == kProjectileType_MissileExplosion) {
    uint8 v5 = projectile_variables[v0];
    if (*((uint8 *)projectile_variables + projectile_index + 1)) {
      uint16 v1 = abs16(projectile_y_speed[v0]) & 0xFF00;
      if (sign16(v1 - 2816)) {
        int v4 = projectile_index >> 1;
        if ((projectile_type[v4] & kProjectileType_ProjMask) != kProjectileType_MissileExplosion) {
          projectile_y_pos[v5 >> 1] = projectile_y_pos[v4];
          return;
        }
      } else {
        uint16 r18 = (v1 >> 8) - 10;
        if ((projectile_y_speed[v0] & 0x8000) == 0) {
          uint16 v6 = projectile_index;
          projectile_y_pos[v5 >> 1] = projectile_y_pos[v0] - r18;
          projectile_index = v5;
          BlockCollMissileVert(v5);
          projectile_index = v6;
          if ((projectile_type[v6 >> 1] & kProjectileType_ProjMask) == kProjectileType_MissileExplosion)
            ClearProjectile(v5);
          return;
        }
        uint16 v7 = projectile_index;
        projectile_y_pos[v5 >> 1] = r18 + projectile_y_pos[projectile_index >> 1];
        projectile_index = v5;
        BlockCollMissileVert(v5);
        projectile_index = v7;
        if ((projectile_type[v7 >> 1] & kProjectileType_ProjMask) != kProjectileType_MissileExplosion)
          return;
      }
      ClearProjectile(v5);
    }
  }
}

void UNUSED_ClearSuperMissileLinkIfExplosion(uint16 k) {  // 0x90B4A6
  int v1 = k >> 1;
  if (*((uint8 *)projectile_variables + k + 1)) {
    if ((projectile_type[v1] & kProjectileType_ProjMask) == kProjectileType_MissileExplosion)
      ClearProjectile((uint8)projectile_variables[v1]);
  }
}

void SuperMissileBlockCollDetect_X(void) {  // 0x90B406
  int v0 = projectile_index >> 1;
  if ((projectile_type[v0] & kProjectileType_ProjMask) == kProjectileType_SuperMissile || (projectile_type[v0] & kProjectileType_ProjMask) == kProjectileType_MissileExplosion) {
    uint8 v5 = projectile_variables[v0];
    if (*((uint8 *)projectile_variables + projectile_index + 1)) {
      uint16 v1 = abs16(projectile_x_speed[v0]) & 0xFF00;
      if (sign16(v1 - 2816)) {
        int v4 = projectile_index >> 1;
        if ((projectile_type[v4] & kProjectileType_ProjMask) != kProjectileType_MissileExplosion) {
          projectile_x_pos[v5 >> 1] = projectile_x_pos[v4];
          return;
        }
      } else {
        uint16 r18 = (v1 >> 8) - 10;
        if ((projectile_x_speed[v0] & 0x8000) == 0) {
          uint16 v6 = projectile_index;
          projectile_x_pos[v5 >> 1] = projectile_x_pos[v0] - r18;
          projectile_index = v5;
          BlockCollMissileHoriz(v5);
          projectile_index = v6;
          if ((projectile_type[v6 >> 1] & kProjectileType_ProjMask) == kProjectileType_MissileExplosion)
            ClearProjectile(v5);
          return;
        }
        uint16 v7 = projectile_index;
        projectile_x_pos[v5 >> 1] = r18 + projectile_x_pos[projectile_index >> 1];
        projectile_index = v5;
        BlockCollMissileHoriz(v5);
        projectile_index = v7;
        if ((projectile_type[v7 >> 1] & kProjectileType_ProjMask) != kProjectileType_MissileExplosion)
          return;
      }
      ClearProjectile(v5);
    }
  }
}

void ProjTrailInstr_MoveLeftProjectileTrailDown(uint16 j) {  // 0x90B525
  ++projectiletrail_left_y_pos[j >> 1];
}

void ProjTrailInstr_MoveRightProjectileTrailDown(uint16 j) {  // 0x90B587
  ++projectiletrail_right_y_pos[j >> 1];
}

void ProjTrailInstr_MoveLeftProjectileTrailUp(uint16 j) {  // 0x90B5B3
  --projectiletrail_left_y_pos[j >> 1];
}

void SpawnProjectileTrail(uint16 k) {  // 0x90B657
  int16 v2;

  uint16 v1 = projectile_type[k >> 1];
  if ((v1 & kProjectileType_ProjMask) != 0) {
    uint16 v3 = HIBYTE(v1) & (kProjectileType_ProjMask >> 8);
    if (v3 >= ((kProjectileType_SuperMissile | kProjectileType_Missile) >> 8))
      return;
    v2 = v3 + 31;
  } else {
    v2 = projectile_type[k >> 1] & kProjectileType_CooldownMask;
  }
  uint16 v4 = 34;
  while (projectiletrail_left_instr_timer[v4 >> 1]) {
    v4 -= 2;
    if ((v4 & 0x8000) != 0)
      return;
  }
  int v5 = v4 >> 1;
  projectiletrail_left_instr_timer[v5] = 1;
  projectiletrail_right_instr_timer[v5] = 1;
  int v6 = v2;
  projectiletrail_left_instr_list_ptr[v5] = kLeftProjTrailInstrListPtrs[v6];
  projectiletrail_right_instr_list_ptr[v5] = kRightProjTrailInstrListPtrs[v6];
  SetProjectileTrailPosition(projectile_index, v4);
}

void CallProjTrailInstr(uint32 ea, uint16 j) {
  switch (ea) {
  case fnProjTrailInstr_MoveLeftProjectileTrailDown: ProjTrailInstr_MoveLeftProjectileTrailDown(j); return;  // 0x90b525
  case fnProjTrailInstr_MoveRightProjectileTrailDown: ProjTrailInstr_MoveRightProjectileTrailDown(j); return;  // 0x90b587
  case fnProjTrailInstr_MoveLeftProjectileTrailUp: ProjTrailInstr_MoveLeftProjectileTrailUp(j); return;  // 0x90b5b3
  default: Unreachable();
  }
}

void HandleProjectileTrails(void) {  // 0x90B6A9
  int i;
  int16 v10;
  OamEnt *v11;
  int16 v12;
  uint16 j;
  int16 v22;
  OamEnt *v23;
  int16 v24;
  uint16 k;
  int16 v28;
  OamEnt *v29;
  int16 v30;
  int16 v33;
  OamEnt *v34;
  int16 v35;
  uint16 v6, v18;
  int v7;

  if (!time_is_frozen_flag) {
    uint16 v0 = 34;
    while (1) {
      uint16 v2;
      int v1;
      v1 = v0 >> 1;
      v2 = projectiletrail_left_instr_timer[v1];
      if (v2) {
        uint16 v3 = v2 - 1;
        projectiletrail_left_instr_timer[v1] = v3;
        if (v3)
          goto LABEL_10;
        for (i = projectiletrail_left_instr_list_ptr[v1]; ; i += 2) {
          const uint16 *v5 = (const uint16 *)RomPtr_90(i);
          v6 = *v5;
          if ((*v5 & 0x8000) == 0)
            break;
          CallProjTrailInstr(v6 | 0x900000, v0);
        }
        v7 = v0 >> 1;
        projectiletrail_left_instr_timer[v7] = v6;
        if (v6)
          break;
      }
LABEL_14:;
      int v13 = v0 >> 1;
      uint16 v14 = projectiletrail_right_instr_timer[v13];
      if (v14) {
        uint16 v15 = v14 - 1;
        projectiletrail_right_instr_timer[v13] = v15;
        if (v15)
          goto LABEL_21;
        for (j = projectiletrail_right_instr_list_ptr[v13]; ; j += 2) {
          const uint16 *v17 = (const uint16 *)RomPtr_90(j);
          v18 = *v17;
          if ((*v17 & 0x8000) == 0)
            break;
          CallProjTrailInstr(v18 | 0x900000, v0);
        }
        int v19;
        v19 = v0 >> 1;
        projectiletrail_right_instr_timer[v19] = v18;
        if (v18) {
          projectiletrail_right_tile_and_attribs[v19] = *((uint16 *)RomPtr_90(j) + 1);
          projectiletrail_right_instr_list_ptr[v19] = j + 4;
LABEL_21:;
          uint16 v20 = oam_next_ptr;
          if ((int16)(oam_next_ptr - 512) < 0) {
            int v21 = v0 >> 1;
            v22 = projectiletrail_right_x_pos[v21] - layer1_x_pos;
            if ((v22 & 0xFF00) == 0) {
              v23 = gOamEnt(oam_next_ptr);
              *(uint16 *)&v23->xcoord = v22;
              v24 = projectiletrail_right_y_pos[v21] - layer1_y_pos;
              if ((v24 & 0xFF00) == 0) {
                *(uint16 *)&v23->ycoord = v24;
                *(uint16 *)&v23->charnum = projectiletrail_right_tile_and_attribs[v21];
                oam_next_ptr = v20 + 4;
              }
            }
          }
        }
      }
      v0 -= 2;
      if ((v0 & 0x8000) != 0)
        return;
    }
    projectiletrail_left_tile_and_attribs[v7] = *((uint16 *)RomPtr_90(i) + 1);
    projectiletrail_left_instr_list_ptr[v7] = i + 4;
LABEL_10:;
    uint16 v8 = oam_next_ptr;
    if ((int16)(oam_next_ptr - 512) < 0) {
      int v9 = v0 >> 1;
      v10 = projectiletrail_left_x_pos[v9] - layer1_x_pos;
      if ((v10 & 0xFF00) == 0) {
        v11 = gOamEnt(oam_next_ptr);
        *(uint16 *)&v11->xcoord = v10;
        v12 = projectiletrail_left_y_pos[v9] - layer1_y_pos;
        if ((v12 & 0xFF00) == 0) {
          *(uint16 *)&v11->ycoord = v12;
          *(uint16 *)&v11->charnum = projectiletrail_left_tile_and_attribs[v9];
          oam_next_ptr = v8 + 4;
        }
      }
    }
    goto LABEL_14;
  }
  for (k = 34; (k & 0x8000) == 0; k -= 2) {
    uint16 v26 = oam_next_ptr;
    if ((int16)(oam_next_ptr - 512) < 0) {
      int v27 = k >> 1;
      if (projectiletrail_left_instr_timer[v27]) {
        v28 = projectiletrail_left_x_pos[v27] - layer1_x_pos;
        if ((v28 & 0xFF00) == 0) {
          v29 = gOamEnt(oam_next_ptr);
          *(uint16 *)&v29->xcoord = v28;
          v30 = projectiletrail_left_y_pos[v27] - layer1_y_pos;
          if ((v30 & 0xFF00) == 0) {
            *(uint16 *)&v29->ycoord = v30;
            *(uint16 *)&v29->charnum = projectiletrail_left_tile_and_attribs[v27];
            oam_next_ptr = v26 + 4;
          }
        }
      }
    }
    uint16 v31 = oam_next_ptr;
    if ((int16)(oam_next_ptr - 512) < 0) {
      int v32 = k >> 1;
      if (projectiletrail_right_instr_timer[v32]) {
        v33 = projectiletrail_right_x_pos[v32] - layer1_x_pos;
        if ((v33 & 0xFF00) == 0) {
          v34 = gOamEnt(oam_next_ptr);
          *(uint16 *)&v34->xcoord = v33;
          v35 = projectiletrail_right_y_pos[v32] - layer1_y_pos;
          if ((v35 & 0xFF00) == 0) {
            *(uint16 *)&v34->ycoord = v35;
            *(uint16 *)&v34->charnum = projectiletrail_right_tile_and_attribs[v32];
            oam_next_ptr = v31 + 4;
          }
        }
      }
    }
  }
}

void HudSelectionHandler_NothingOrPowerBombs(void) {  // 0x90B80D
  prev_beam_charge_counter = flare_counter;
  if (hyper_beam_flag || (equipped_beams & kBeam_Charge) == 0) {
    if ((button_config_shoot_x & joypad1_lastkeys) != 0)
      FireUnchargedBeam();
    return;
  }
  if (new_projectile_direction_changed_pose) {
    if (sign16(flare_counter - 60)) {
LABEL_14:
      flare_counter = 0;
      ClearFlareAnimationState();
      FireUnchargedBeam();
      return;
    }
LABEL_15:
    flare_counter = 0;
    ClearFlareAnimationState();
    FireChargedBeam();
    return;
  }
  if ((button_config_shoot_x & joypad1_lastkeys) == 0) {
    if (!flare_counter)
      return;
    if (sign16(flare_counter - 60))
      goto LABEL_14;
    goto LABEL_15;
  }
  if (sign16(flare_counter - 120)) {
    if (++flare_counter == 1) {
      ClearFlareAnimationState();
      FireUnchargedBeam();
    }
  } else if (FireSba() & 1) {
    flare_counter = 0;
    ClearFlareAnimationState();
    Samus_LoadSuitPalette();
  }
}

static const uint16 kProjectileBombPreInstr[12] = {  // 0x90B887
  (uint16)fnProjPreInstr_Beam_NoWaveBeam,
  (uint16)fnProjPreInstr_BeamOrIceWave,
  (uint16)fnProjPreInstr_Beam_NoWaveBeam,
  (uint16)fnProjPreInstr_BeamOrIceWave,
  (uint16)fnProjPreInstr_Beam_NoWaveBeam,
  (uint16)fnProjPreInstr_WaveCombined,
  (uint16)fnProjPreInstr_Beam_NoWaveBeam,
  (uint16)fnProjPreInstr_WaveCombined,
  (uint16)fnProjPreInstr_Beam_NoWaveBeam,
  (uint16)fnProjPreInstr_WaveCombined,
  (uint16)fnProjPreInstr_Beam_NoWaveBeam,
  (uint16)fnProjPreInstr_WaveCombined,
};

void FireUnchargedBeam(void) {
  int8 v3;

  if (hyper_beam_flag) {
    FireHyperBeam();
    return;
  }
  if (Samus_CanFireBeam() & 1) {
    uint16 v0 = 0;
    while (projectile_damage[v0 >> 1]) {
      v0 += 2;
      if ((int16)(v0 - 10) >= 0) {
        v0 -= 2;
        break;
      }
    }
    if (!(InitProjectilePositionDirection(v0) & 1)) {
      projectile_invincibility_timer = 10;
      uint16 v1 = v0;
      int v2 = v0 >> 1;
      projectile_timers[v2] = 4;
      v3 = equipped_beams;
      projectile_type[v2] = equipped_beams | 0x8000;
      QueueSfx1_Max15(kUnchargedProjectile_Sfx[v3 & 0xF]);
      play_resume_charging_beam_sfx = 0;
      InitializeProjectile(v1);
      if ((equipped_beams & kBeam_Charge) != 0
          || (button_config_shoot_x & joypad1_newkeys) != 0
          || (button_config_shoot_x & joypad1_newinput_samusfilter) != 0) {
        uint16 v6;
        v6 = projectile_type[v2];
        cooldown_timer = kProjectileCooldown_Uncharged[v6 & kProjectileType_CooldownMask];
        if ((v6 & 1) == 0)
          goto LABEL_17;
      } else {
        uint16 v5;
        v5 = projectile_type[v2];
        cooldown_timer = kBeamAutoFireCooldowns[v5 & kProjectileType_CooldownMask];
        if ((v5 & 1) == 0) {
LABEL_17:
          projectile_x_speed[v2] = 0;
          projectile_y_speed[v2] = 0;
          projectile_index = v1;
          CheckBeamCollByDir(v1);
          v1 = projectile_index;
          if ((projectile_type[projectile_index >> 1] & kProjectileType_ProjMask) != 0)
            return;
          goto LABEL_20;
        }
      }
      int v4;
      v4 = v1 >> 1;
      projectile_x_speed[v4] = 0;
      projectile_y_speed[v4] = 0;
      projectile_index = v1;
      WaveBeam_CheckColl(v1);
LABEL_20:
      projectile_pre_instructions[v1 >> 1] = kProjectileBombPreInstr[projectile_type[v1 >> 1] & kProjectileType_BeamMask];
      SetInitialProjectileSpeed(v1);
      return;
    }
  }
  if (!sign16(prev_beam_charge_counter - 16)) {
    play_resume_charging_beam_sfx = 0;
    QueueSfx1_Max15(kSfx1_Silence);
  }
}

static const uint16 kFireChargedBeam_Funcs[12] = {  // 0x90B986
  [kProjectileType_Power]                                           = FUNC16(ProjPreInstr_Beam_NoWaveBeam),
  [kProjectileType_Wave]                                            = FUNC16(ProjPreInstr_WaveCombined),
  [kProjectileType_Ice]                                             = FUNC16(ProjPreInstr_Beam_NoWaveBeam),
  [kProjectileType_Ice|kProjectileType_Wave]                        = FUNC16(ProjPreInstr_WaveCombined),
  [kProjectileType_Spazer]                                          = FUNC16(ProjPreInstr_Beam_NoWaveBeam),
  [kProjectileType_Spazer|kProjectileType_Wave]                     = FUNC16(ProjPreInstr_WaveCombined),
  [kProjectileType_Spazer|kProjectileType_Ice]                      = FUNC16(ProjPreInstr_Beam_NoWaveBeam),
  [kProjectileType_Spazer|kProjectileType_Ice|kProjectileType_Wave] = FUNC16(ProjPreInstr_WaveCombined),
  [kProjectileType_Plasma]                                          = FUNC16(ProjPreInstr_Beam_NoWaveBeam),
  [kProjectileType_Plasma|kProjectileType_Wave]                     = FUNC16(ProjPreInstr_WaveCombined),
  [kProjectileType_Plasma|kProjectileType_Ice]                      = FUNC16(ProjPreInstr_Beam_NoWaveBeam),
  [kProjectileType_Plasma|kProjectileType_Ice|kProjectileType_Wave] = FUNC16(ProjPreInstr_WaveCombined),
};

void FireChargedBeam(void) {
  if (Samus_CanFireBeam() & 1) {
    uint16 v0 = 0;
    while (projectile_damage[v0 >> 1]) {
      v0 += 2;
      if ((int16)(v0 - 10) >= 0) {
        v0 -= 2;
        break;
      }
    }
    uint16 r20 = v0;
    if (!(InitProjectilePositionDirection(r20) & 1)) {
      projectile_invincibility_timer = 10;
      uint16 v1 = r20;
      int v2 = r20 >> 1;
      projectile_timers[v2] = 4;
      uint16 v3 = equipped_beams & (kBeam_Charge | kBeam_Plasma | kBeam_Spazer | kBeam_Ice | kBeam_Wave) | 0x8010;
      projectile_type[v2] = v3;
      QueueSfx1_Max15(kChargedProjectile_Sfx[v3 & kProjectileType_BeamMask]);
      play_resume_charging_beam_sfx = 0;
      InitializeProjectile(v1);
      uint16 v5 = projectile_type[v2];
      cooldown_timer = kProjectileCooldown_Uncharged[v5 & kProjectileType_CooldownMask];
      if ((v5 & 1) != 0) {
        int v4 = v1 >> 1;
        projectile_x_speed[v4] = 0;
        projectile_y_speed[v4] = 0;
        projectile_index = v1;
        WaveBeam_CheckColl(v1);
      } else {
        projectile_x_speed[v2] = 0;
        projectile_y_speed[v2] = 0;
        projectile_index = v1;
        CheckBeamCollByDir(v1);
        v1 = projectile_index;
        if ((projectile_type[projectile_index >> 1] & kProjectileType_ProjMask) != 0) {
LABEL_14:
          charged_shot_glow_timer = 4;
          return;
        }
      }
      r20 = v1;
      projectile_pre_instructions[v1 >> 1] = kFireChargedBeam_Funcs[projectile_type[v1 >> 1] & kProjectileType_BeamMask];
      SetInitialProjectileSpeed(r20);
      goto LABEL_14;
    }
  }
  if (!sign16(prev_beam_charge_counter - 16)) {
    play_resume_charging_beam_sfx = 0;
    QueueSfx1_Max15(kSfx1_Silence);
  }
}

static const int16 kProjectileOriginOffsets_Default_X[10] = { 2, 13, 11, 13, 2, -5, -14, -11, -19, -2 };
static const int16 kProjectileOriginOffsets_Default_Y[10] = { -8, -13, 1, 4, 13, 13, 4, 1, -19, -8 };
static const int16 kProjectileOriginOffsets_Moonwalk_X[10] = { 2, 15, 15, 13, 2, -5, -13, -13, -15, -2 };
static const int16 kProjectileOriginOffsets_Moonwalk_Y[10] = { -8, -16, -2, 1, 13, 13, 1, -2, -16, -8 };

uint8 InitProjectilePositionDirection(uint16 r20) {  // 0x90BA56
  uint16 v0 = samus_pose;
  uint16 direction_shots_fired;

  if (new_projectile_direction_changed_pose) {
    direction_shots_fired = (uint8)new_projectile_direction_changed_pose;
    new_projectile_direction_changed_pose = 0;
  } else {
    direction_shots_fired = kPoseParams[v0].direction_shots_fired;
    if ((direction_shots_fired & 0xF0) != 0) {
      if (direction_shots_fired != 16
          || (LOBYTE(direction_shots_fired) = kPoseParams[samus_last_different_pose].direction_shots_fired,
              (direction_shots_fired & 0xF0) != 0)) {
        --projectile_counter;
        return 1;
      }
      direction_shots_fired = (uint8)direction_shots_fired;
      v0 = samus_pose;
    }
  }
  int v2 = r20 >> 1;
  projectile_dir[v2] = direction_shots_fired;
  uint16 r22 = kPoseParams[v0].y_offset_to_gfx;
  uint16 v3 = 2 * (projectile_dir[v2] & kProjectileDir_DirMask);
  if (samus_pose == kPose_75_FaceL_Moonwalk_AimUL
      || samus_pose == kPose_76_FaceR_Moonwalk_AimUR
      || samus_movement_type == kMovementType_01_Running) {
    int v6 = v3 >> 1;
    projectile_x_pos[v2] = samus_x_pos + kProjectileOriginOffsets_Moonwalk_X[v6];
    projectile_y_pos[v2] = samus_y_pos + kProjectileOriginOffsets_Moonwalk_Y[v6] - r22;
    return 0;
  } else {
    int v4 = v3 >> 1;
    projectile_x_pos[v2] = samus_x_pos + kProjectileOriginOffsets_Default_X[v4];
    projectile_y_pos[v2] = samus_y_pos + kProjectileOriginOffsets_Default_Y[v4] - r22;
    return 0;
  }
}

void HandleChargingBeamGfxAudio(void) {  // 0x90BAFC
  int16 v1;
  int16 v4;
  uint16 v9;

  if (hyper_beam_flag) {
    if (flare_counter) {
      for (int i = 4; i >= 0; i -= 2) {
        bool v7 = *(uint16 *)((uint8 *)&flare_animation_timer + i) == 1;
        bool v8 = (-- * (uint16 *)((uint8 *)&flare_animation_timer + i) & 0x8000) != 0;
        if (v7 || v8) {
          v7 = (*(uint16 *)((uint8 *)&flare_animation_frame + i))-- == 1;
          if (v7) {
            if (i == 4)
              flare_counter = 0;
          } else {
            *(uint16 *)((uint8 *)&flare_animation_timer + i) = 3;
          }
        }
        DrawFlareAnimationComponent(i);
      }
    }
  } else if ((int16)flare_counter > 0) {
    if (flare_counter == 1) {
      flare_animation_frame = 0;
      flare_slow_sparks_anim_frame = 0;
      flare_fast_sparks_anim_frame = 0;
      flare_animation_timer = 3;
      flare_slow_sparks_anim_timer = 5;
      flare_fast_sparks_anim_timer = 4;
    }
    if (!sign16(flare_counter - 15)) {
      if (flare_counter == 16)
        QueueSfx1_Max9(kSfx1_ChargingBeam);
      uint16 v0 = 0;
      do {
        v1 = *(uint16 *)((uint8 *)&flare_animation_timer + v0) - 1;
        *(uint16 *)((uint8 *)&flare_animation_timer + v0) = v1;
        if (v1 < 0) {
          uint16 v2 = *(uint16 *)((uint8 *)&flare_animation_frame + v0) + 1;
          *(uint16 *)((uint8 *)&flare_animation_frame + v0) = v2;
          uint16 v3 = v2;
          const uint8 *r0 = RomPtr_90(kFlareAnimDelays[v0 >> 1]);
          v4 = r0[v2];
          if (v4 == 255) {
            *(uint16 *)((uint8 *)&flare_animation_frame + v0) = 0;
            v3 = 0;
          } else if (v4 == 254) {
            uint16 v5 = *(uint16 *)((uint8 *)&flare_animation_frame + v0) - r0[v3 + 1];
            *(uint16 *)((uint8 *)&flare_animation_frame + v0) = v5;
            v3 = v5;
          }
          *(uint16 *)((uint8 *)&flare_animation_timer + v0) = r0[v3];
        }
        v9 = v0;
        DrawFlareAnimationComponent(v0);
        if (sign16(flare_counter - 30))
          break;
        v0 += 2;
      } while ((int16)(v9 - 4) < 0);
    }
  }
}

static const int16 kProjectileOriginOffsets_X[13] = { 2, 18, 15, 17, 3, -4, -17, -15, -18, -2, -4, -4, -4 };
static const int16 kProjectileOriginOffsets_Y[13] = { -28, -19, 1, 6, 17, 17, 6, 1, -20, -28, -20, -2, 8 };
static const int16 kProjectileOriginOffsets2_X[10] = { 2, 19, 20, 18, 3, -4, -18, -20, -19, -2 };
static const int16 kProjectileOriginOffsets2_Y[10] = { -32, -22, -3, 6, 25, 25, 6, -3, -20, -32 };

void DrawFlareAnimationComponent(uint16 k) {  // 0x90BBE1
  static const uint16 kFlareSpritemapIndexOffset_FaceRight_Tab0[3] = { 0, 0x1e, 0x24 };
  static const uint16 kFlareSpritemapIndexOffset_FaceLeft_Tab0[3] = { 0, 0x2a, 0x30 };
  int16 v2;
  uint16 v1;
  uint16 r20;
  uint16 r18 = *((uint8 *)&flare_animation_frame + k);
  if (samus_pose_x_dir == kSamusXDir_FaceLeft)
    v1 = kFlareSpritemapIndexOffset_FaceLeft_Tab0[k >> 1];
  else
    v1 = kFlareSpritemapIndexOffset_FaceRight_Tab0[k >> 1];
  uint16 r22 = r18 + v1;
  uint16 r24 = kPoseParams[samus_pose].y_offset_to_gfx;
  v2 = kPoseParams[samus_pose].direction_shots_fired;
  if (v2 != 255 && v2 != 16) {
    uint16 v3 = 2 * (v2 & 0xF);
    uint16 old_x = samus_x_pos, old_y = samus_y_pos;
    if (ceres_status & kCeresStatus_8000_ElevatorRoomRotate)
      Samus_CalcPos_Mode7();
    int v4 = v3 >> 1;
    uint16 v5;
    if (samus_movement_type == kMovementType_01_Running) {
      r20 = samus_x_pos + kProjectileOriginOffsets2_X[v4] - layer1_x_pos;
      v5 =  samus_y_pos + kProjectileOriginOffsets2_Y[v4] - r24 - layer1_y_pos;
    } else {
      r20 = samus_x_pos + kProjectileOriginOffsets_X[v4] - layer1_x_pos;
      v5 = samus_y_pos + kProjectileOriginOffsets_Y[v4] - r24 - layer1_y_pos;
    }
    r18 = v5;
    if ((v5 & 0xFF00) == 0)
      DrawBeamGrappleSpritemap(r22, r20, r18);
    if (ceres_status & kCeresStatus_8000_ElevatorRoomRotate)
      samus_y_pos = old_y, samus_x_pos = old_x;
  }
}

void ClearFlareAnimationState(void) {  // 0x90BCBE
  flare_animation_frame = 0;
  flare_slow_sparks_anim_frame = 0;
  flare_fast_sparks_anim_frame = 0;
  flare_animation_timer = 0;
  flare_slow_sparks_anim_timer = 0;
  flare_fast_sparks_anim_timer = 0;
}

void FireHyperBeam(void) {  // 0x90BCD1
  if (Samus_CanFireBeam() & 1) {
    uint16 v0 = 0;
    while (projectile_damage[v0 >> 1]) {
      v0 += 2;
      if ((int16)(v0 - 10) >= 0) {
        v0 -= 2;
        break;
      }
    }
    uint16 r20 = v0;
    if (!(InitProjectilePositionDirection(r20) & 1)) {
      projectile_invincibility_timer = 10;
      uint16 k = r20;
      projectile_type[r20 >> 1] = (kProjectileType_DontInteractWithSamus | kProjectileType_ChargeBeamEquipped | kProjectileType_Charged | kProjectileType_Plasma);
      QueueSfx1_Max15(kChargedProjectile_Sfx[8]);
      play_resume_charging_beam_sfx = 0;
      InitializeProjectile(k);
      int v1 = k >> 1;
      projectile_x_speed[v1] = 0;
      projectile_y_speed[v1] = 0;
      projectile_index = k;
      WaveBeam_CheckColl(k);
      uint16 v2 = projectile_index;
      int v3 = projectile_index >> 1;
      projectile_damage[v3] = 1000;
      projectile_pre_instructions[v3] = FUNC16(ProjPreInstr_HyperBeam);
      r20 = v2;
      SetInitialProjectileSpeed(r20);
      cooldown_timer = 21;
      charged_shot_glow_timer = 20 | 0x8000;
      flare_animation_frame = 29;
      flare_slow_sparks_anim_frame = 5;
      flare_fast_sparks_anim_frame = 5;
      flare_animation_timer = 3;
      flare_slow_sparks_anim_timer = 3;
      flare_fast_sparks_anim_timer = 3;
      flare_counter = 0x8000;
    }
  }
}

static Func_V *const kCheckBeamCollByDir[10] = {  // 0x90BD64
  CheckBeamCollByDir_Vertical,
  CheckBeamCollByDir_Diagonal,
  CheckBeamCollByDir_Right,
  CheckBeamCollByDir_Diagonal,
  CheckBeamCollByDir_Vertical,
  CheckBeamCollByDir_Vertical,
  CheckBeamCollByDir_Diagonal,
  CheckBeamCollByDir_Left,
  CheckBeamCollByDir_Diagonal,
  CheckBeamCollByDir_Vertical,
};

void CheckBeamCollByDir(uint16 k) {
  kCheckBeamCollByDir[projectile_dir[k >> 1] & kProjectileDir_DirMask]();
}

void CheckBeamCollByDir_Vertical(void) {  // 0x90BD86
  BlockCollNoWaveBeamVert(projectile_index);
}

void CheckBeamCollByDir_Diagonal(void) {  // 0x90BD8E
  uint16 v0 = projectile_index;
  if (!(BlockCollNoWaveBeamHoriz(projectile_index) & 1))
    BlockCollNoWaveBeamVert(v0);
}

void CheckBeamCollByDir_Right(void) {  // 0x90BD9C
  BlockCollNoWaveBeamHoriz(projectile_index);
}

void CheckBeamCollByDir_Left(void) {  // 0x90BDA4
  uint16 v0 = projectile_index;
  projectile_x_speed[projectile_index >> 1] = -1;
  BlockCollNoWaveBeamHoriz(v0);
}

static Func_V *const kWaveBeam_CheckColl_Funcs[10] = {  // 0x90BDB2
  WaveBeam_CheckColl_Vertical,
  WaveBeam_CheckColl_Diagonal,
  WaveBeam_CheckColl_Right,
  WaveBeam_CheckColl_Diagonal,
  WaveBeam_CheckColl_Vertical,
  WaveBeam_CheckColl_Vertical,
  WaveBeam_CheckColl_Diagonal,
  WaveBeam_CheckColl_Left,
  WaveBeam_CheckColl_Diagonal,
  WaveBeam_CheckColl_Vertical,
};
void WaveBeam_CheckColl(uint16 k) {
  kWaveBeam_CheckColl_Funcs[projectile_dir[k >> 1] & kProjectileDir_DirMask]();
}

void WaveBeam_CheckColl_Vertical(void) {  // 0x90BDD4
  BlockCollWaveBeamVert(projectile_index);
}

void WaveBeam_CheckColl_Diagonal(void) {  // 0x90BDDC
  uint16 v0 = projectile_index;
  if (!(BlockCollWaveBeamHoriz(projectile_index) & 1))
    BlockCollWaveBeamVert(v0);
}

void WaveBeam_CheckColl_Right(void) {  // 0x90BDEA
  BlockCollWaveBeamHoriz(projectile_index);
}

void WaveBeam_CheckColl_Left(void) {  // 0x90BDF2
  uint16 v0 = projectile_index;
  projectile_x_speed[projectile_index >> 1] = -1;
  BlockCollWaveBeamHoriz(v0);
}

void ProjectileReflection(uint16 proj_idx) {  // 0x90BE00
  int idx = proj_idx >> 1;
  uint16 proj_type = projectile_type[idx];
  if (proj_type & kProjectileType_Missile) {
    InitializeProjectile(proj_idx);
    projectile_pre_instructions[idx] = FUNC16(ProjPreInstr_Missile);
    // projectile extra base speed
    projectile_variables[idx] = 240;
  }
  else if (proj_type & kProjectileType_SuperMissile) {
    ClearProjectile(LOBYTE(projectile_variables[idx]));
    InitializeProjectile(proj_idx);
    projectile_pre_instructions[idx] = FUNC16(ProjPreInstr_SuperMissile);
    // projectile extra base speed
    projectile_variables[idx] = 240;
  }
  else {
    SetInitialProjectileSpeed(proj_idx);
    InitializeProjectile(proj_idx);
    projectile_pre_instructions[idx] = kFireChargedBeam_Funcs[proj_type & kProjectileType_BeamMask];
  }
}

void HudSelectionHandler_MissilesOrSuperMissiles(void) {  // 0x90BE62
  if ((button_config_shoot_x & joypad1_newkeys) == 0 && (button_config_shoot_x & joypad1_newinput_samusfilter) == 0
      || !(Samus_CanFireSuperMissile() & 1)) {
    return;
  }
  if (hud_item_index != kHudItem_2_SuperMissile) {
    if (samus_missiles)
      goto LABEL_10;
LABEL_5:
    --projectile_counter;
    return;
  }
  if (!samus_super_missiles)
    goto LABEL_5;
LABEL_10:;
  uint16 v0 = 0;
  while (projectile_damage[v0 >> 1]) {
    v0 += 2;
    if ((int16)(v0 - 10) >= 0)
      goto LABEL_5;
  }
  uint16 r20 = v0;
  if (!(InitProjectilePositionDirection(r20) & 1)) {
    projectile_invincibility_timer = 20;
    if (hud_item_index == kHudItem_2_SuperMissile)
      --samus_super_missiles;
    else
      --samus_missiles;
    int v1 = r20 >> 1;
    projectile_timers[v1] = 4;
    uint16 v3 = hud_item_index;
    uint16 r18 = swap16(hud_item_index);
    projectile_type[v1] |= r18 | 0x8000;
    uint16 v4 = 2 * (v3 & 0xF);
    if (!cinematic_function)
      QueueSfx1_Max6(kNonBeamProjectile_Sfx[v4 >> 1]);
    InitializeProjectileSpeedOfType(r20);
    InitializeProjectile(r20);
    uint16 v7 = projectile_type[v1];
    if ((v7 & kProjectileType_SuperMissile) != 0)
      projectile_pre_instructions[v1] = FUNC16(ProjPreInstr_SuperMissile);
    else
      projectile_pre_instructions[v1] = FUNC16(ProjPreInstr_Missile);
    cooldown_timer = kNonBeamProjectileCooldowns[HIBYTE(v7) & kProjectileType_BeamMask];
    if (samus_auto_cancel_hud_item_index) {
      hud_item_index = kHudItem_0_Nothing;
      samus_auto_cancel_hud_item_index = 0;
      return;
    }
    if (hud_item_index == kHudItem_2_SuperMissile) {
      if (samus_super_missiles)
        return;
    } else if (samus_missiles) {
      return;
    }
    hud_item_index = kHudItem_0_Nothing;
  }
}

void SpawnSuperMissileLink(void) {  // 0x90BF46
  uint16 v0 = 0;
  while (projectile_damage[v0 >> 1]) {
    v0 += 2;
    if ((int16)(v0 - 10) >= 0)
      return;
  }
  uint16 r20 = v0;
  int v1 = v0 >> 1;
  projectile_type[v1] |= (0x8000 | kProjectileType_SuperMissile);
  int v2 = projectile_index >> 1;
  projectile_x_pos[v1] = projectile_x_pos[v2];
  projectile_y_pos[v1] = projectile_y_pos[v2];
  projectile_dir[v1] = projectile_dir[v2];
  InitProjectilePositionDirection(r20);
  InitializeInstrForSuperMissile(v0);
  projectile_pre_instructions[v1] = FUNC16(ProjPreInstr_SuperMissileLink);
  projectile_variables[projectile_index >> 1] = v0 + (projectile_variables[projectile_index >> 1] & 0xFF00);
  ++projectile_counter;
}

void HudSelectionHandler_MorphBall(void) {  // 0x90BF9D
  if ((button_config_shoot_x & joypad1_lastkeys) != 0) {
    if (hud_item_index == kHudItem_3_PowerBomb) {
      if ((power_bomb_flag & 0x8000) == 0) {
        if (HudSelectionHandler_MorphBall_Helper_FireBombOrPowerBomb() & 1) {
          if (samus_power_bombs) {
            if ((--samus_power_bombs & 0x8000) == 0) {
              power_bomb_flag = -1;
              uint16 v2 = 10;
              while (projectile_type[v2 >> 1]) {
                v2 += 2;
                if ((int16)(v2 - 20) >= 0) {
                  v2 -= 2;
                  break;
                }
              }
//              r20 = v2;
              uint16 r18 = swap16(hud_item_index);
              int v4 = v2 >> 1;
              uint16 v5 = r18 | projectile_type[v4];
              projectile_type[v4] = v5;
              uint8 v6 = HIBYTE(v5);
              projectile_dir[v4] = 0;
              projectile_x_pos[v4] = samus_x_pos;
              projectile_y_pos[v4] = samus_y_pos;
              projectile_variables[v4] = 60;
              InitializeInstrForBombOrPowerBomb(v2);
              projectile_pre_instructions[v4] = FUNC16(ProjPreInstr_PowerBomb);
              cooldown_timer = kNonBeamProjectileCooldowns[v6 & 0xF];
              if (samus_auto_cancel_hud_item_index) {
                hud_item_index = kHudItem_0_Nothing;
                samus_auto_cancel_hud_item_index = 0;
              } else if (hud_item_index == kHudItem_3_PowerBomb && !samus_power_bombs) {
                hud_item_index = kHudItem_0_Nothing;
              }
            }
          }
        }
      }
    } else if (HudSelectionHandler_MorphBall_Helper_FireBombOrSpread() & 1) {
      uint16 v0 = 10;
      while (projectile_type[v0 >> 1]) {
        v0 += 2;
        if ((int16)(v0 - 20) >= 0) {
          v0 -= 2;
          break;
        }
      }
//      r20 = v0;
      int v1 = v0 >> 1;
      projectile_type[v1] = kProjectileType_Bomb;
      projectile_dir[v1] = 0;
      projectile_x_pos[v1] = samus_x_pos;
      projectile_y_pos[v1] = samus_y_pos;
      projectile_variables[v1] = 60;
      InitializeInstrForBombOrPowerBomb(v0);
      projectile_pre_instructions[v1] = FUNC16(ProjPreInstr_Bomb);
      cooldown_timer = kNonBeamProjectileCooldowns[5];
    }
  } else if (flare_counter) {
    QueueSfx1_Max9(kSfx1_Silence);
    flare_counter = 0;
    ClearFlareAnimationState();
    Samus_LoadSuitPalette();
  }
}

uint8 HudSelectionHandler_MorphBall_Helper_FireBombOrSpread(void) {  // 0x90C0AB
  if ((equipped_items & kItem_Bombs) != 0) {
    if (sign16(flare_counter - 60) || bomb_counter)
      return HudSelectionHandler_MorphBall_Helper_FireBombOrPowerBomb();
    if ((joypad1_lastkeys & kButton_Down) != 0 && sign16((bomb_spread_charge_timeout_counter & 0xC0) - 192)) {
      ++bomb_spread_charge_timeout_counter;
    } else {
      BombSpread();
      Samus_LoadSuitPalette();
      QueueSfx1_Max9(kSfx1_Silence);
    }
  }
  return 0;
}

uint8 HudSelectionHandler_MorphBall_Helper_FireBombOrPowerBomb(void) {  // 0x90C0E7
  if ((button_config_shoot_x & joypad1_newkeys) == 0
      || bomb_counter && (!sign16(bomb_counter - 5) || (uint8)cooldown_timer)) {
    if (flare_counter) {
      QueueSfx1_Max9(kSfx1_Silence);
      flare_counter = 0;
      ClearFlareAnimationState();
      Samus_LoadSuitPalette();
    }
    return 0;
  } else {
    ++cooldown_timer;
    ++bomb_counter;
    return 1;
  }
}

void HandleBomb(void) {  // 0x90C128
  uint16 v0 = projectile_index;
  int v1 = projectile_index >> 1;
  uint16 v2 = projectile_variables[v1];
  if (v2) {
    uint16 v3 = v2 - 1;
    projectile_variables[v1] = v3;
    if (v3) {
      if (v3 == 15)
        projectile_instruction_ptr[v1] += 28;
    } else {
      QueueSfx2_Max6(kSfx2_BombExplosion);
      InitializeBombExplosion(v0);
    }
  }
}

void HandlePowerBomb(void) {  // 0x90C157
  uint16 v0 = projectile_index;
  int v1 = projectile_index >> 1;
  uint16 v2 = projectile_variables[v1];
  if (v2) {
    uint16 v3 = v2 - 1;
    projectile_variables[v1] = v3;
    if (v3) {
      if (v3 == 15)
        projectile_instruction_ptr[v1] += 28;
    } else {
      power_bomb_explosion_x_pos = projectile_x_pos[v1];
      power_bomb_explosion_y_pos = projectile_y_pos[v1];
      EnableHdmaObjects();
      SpawnPowerBombExplosion();
      projectile_variables[v0 >> 1] = -1;
    }
  } else if (!power_bomb_flag) {
    ClearProjectile(projectile_index);
  }
}

static Func_U8 *const kRunSwitchedToHudHandler[6] = {  // 0x90C4B5
  SwitchToHudHandler_Nothing,
  SwitchToHudHandler_Missiles,
  SwitchToHudHandler_SuperMissiles,
  SwitchToHudHandler_PowerBombs,
  SwitchToHudHandler_Grapple,
  SwitchToHudHandler_Xray,
};
void HandleSwitchingHudSelection(void) {
  uint16 v0;
  uint16 r22 = 0;
  uint16 r18 = hud_item_index;
  if ((button_config_itemcancel_y & joypad1_newkeys) != 0) {
    samus_auto_cancel_hud_item_index = 0;
LABEL_5:
    v0 = 0;
    goto LABEL_6;
  }
  r22 = (button_config_itemcancel_y & joypad1_lastkeys) != 0;
  if ((button_config_itemswitch & joypad1_newkeys) == 0)
    goto LABEL_13;
  v0 = hud_item_index + 1;
  if (!sign16(hud_item_index - 5))
    goto LABEL_5;
LABEL_6:
  hud_item_index = v0;
  while (kRunSwitchedToHudHandler[v0]() & 1) {
    v0 = hud_item_index + 1;
    hud_item_index = v0;
    if (!sign16(v0 - 6)) {
      v0 = 0;
      hud_item_index = kHudItem_0_Nothing;
    }
  }
  if (r22)
    samus_auto_cancel_hud_item_index = hud_item_index;
  else
    samus_auto_cancel_hud_item_index = 0;
LABEL_13:
  if (hud_item_index == r18) {
    uint16 v1 = arm_cannon_toggle_flag + 1;
    if (!sign16(arm_cannon_toggle_flag - 2))
      v1 = 2;
    arm_cannon_toggle_flag = v1;
  } else {
    arm_cannon_toggle_flag = 1;
  }
}

uint8 SwitchToHudHandler_Nothing(void) {  // 0x90C545
  flare_counter = 0;
  ClearFlareAnimationState();
  Samus_LoadSuitPalette();
  return 0;
}

uint8 SwitchToHudHandler_Missiles(void) {  // 0x90C551
  if (!samus_missiles)
    return 1;
  flare_counter = 0;
  ClearFlareAnimationState();
  Samus_LoadSuitPalette();
  return 0;
}

uint8 SwitchToHudHandler_SuperMissiles(void) {  // 0x90C564
  if (!samus_super_missiles)
    return 1;
  flare_counter = 0;
  ClearFlareAnimationState();
  Samus_LoadSuitPalette();
  return 0;
}

uint8 SwitchToHudHandler_PowerBombs(void) {  // 0x90C577
  if (!samus_power_bombs)
    return 1;
  flare_counter = 0;
  ClearFlareAnimationState();
  Samus_LoadSuitPalette();
  return 0;
}

uint8 SwitchToHudHandler_Grapple(void) {  // 0x90C58A
  if ((equipped_items & kItem_Grapple) == 0)
    return 1;
  if (grapple_beam_function == FUNC16(GrappleBeamFunc_Inactive)) {
    Samus_LoadSuitPalette();
    flare_counter = 0;
    ClearFlareAnimationState();
    grapple_beam_function = FUNC16(GrappleBeamFunc_Inactive);
  }
  return 0;
}

uint8 SwitchToHudHandler_Xray(void) {  // 0x90C5AE
  if ((equipped_items & kItem_Xray) == 0)
    return 1;
  flare_counter = 0;
  ClearFlareAnimationState();
  Samus_LoadSuitPalette();
  return 0;
}

void HandleArmCannonOpenState(void) {  // 0x90C5C4
  if (flag_arm_cannon_opening_or_closing || UpdateArmCannonIsOpenFlag() & 1)
    AdvanceArmCannonFrame();
  arm_cannon_drawing_mode = RomPtr_90(kPlayerPoseToPtr[samus_pose])[1];
}

uint8 UpdateArmCannonIsOpenFlag(void) {  // 0x90C5EB
  static const int8 kFlagShouldArmCannonBeOpen[6] = { 0, 1, 1, 0, 1, 0 };
  if (sign16(arm_cannon_toggle_flag - 2))
    return 0;
  uint16 r18 = kFlagShouldArmCannonBeOpen[hud_item_index];
  if (flag_arm_cannon_open_or_opening == r18)
    return 0;
  if (r18)
    arm_cannon_frame = 0;
  else
    arm_cannon_frame = 4;
  *(uint16 *)&flag_arm_cannon_open_or_opening = r18 | 0x100;
  return 1;
}

void AdvanceArmCannonFrame(void) {  // 0x90C627
  if (flag_arm_cannon_open_or_opening) {
    if (sign16(arm_cannon_frame - 2)) {
      ++arm_cannon_frame;
      return;
    }
    arm_cannon_frame = 3;
  } else {
    if (arm_cannon_frame != 1 && (int16)(arm_cannon_frame - 1) >= 0) {
      --arm_cannon_frame;
      return;
    }
    arm_cannon_frame = 0;
  }
  *(uint16 *)&flag_arm_cannon_open_or_opening = flag_arm_cannon_open_or_opening;
}

void Samus_ArmCannon_Draw(void) {  // 0x90C663
  static const uint16 kDrawArmCannon_Char[10] = { 0x281f, 0x281f, 0x281f, 0x681f, 0xa81f, 0xe81f, 0x281f, 0x681f, 0x681f, 0x681f };
  uint16 v3;
  uint16 r22;

  if (arm_cannon_frame && (!samus_invincibility_timer || (nmi_frame_counter_word & 1) == 0)) {
    uint16 v0 = kPlayerPoseToPtr[samus_pose];
    const uint8 *v1 = RomPtr_90(v0);
    int16 v2 = *v1;
    if ((v2 & 0x80) != 0) {
      if (samus_anim_frame)
        v3 = 2 * (v1[2] & 0x7F);
      else
        v3 = 2 * (*v1 & 0x7F);
      r22 = v0 + 4;
    } else {
      v3 = 2 * v2;
      r22 = v0 + 2;
    }
    uint16 r24 = kDrawArmCannon_Char[v3 >> 1];
    const uint8 *v4 = RomPtr_90(r22 + 2 * samus_anim_frame);
    uint16 r18 = (int8)v4[0], r20 = (int8)v4[1];
    r22 = kPoseParams[samus_pose].y_offset_to_gfx;
    uint16 v7 = oam_next_ptr;
    int16 v8 = r18 + samus_x_pos - layer1_x_pos;
    if (v8 >= 0) {
      if (sign16(v8 - 256)) {
        OamEnt *v9 = gOamEnt(oam_next_ptr);
        v9->xcoord = v8;
        int16 v10 = r20 + samus_y_pos - r22 - layer1_y_pos;
        if (v10 >= 0) {
          if (sign16(v10 - 256)) {
            v9->ycoord = v10;
            *(uint16 *)&v9->charnum = r24;
            oam_next_ptr = v7 + 4;
          }
        }
      }
    }
    const uint8 *v11 = RomPtr_90(kPlayerPoseToPtr[samus_pose]);
    uint8 v12 = *v11;
    if ((v12 & 0x80) != 0) {
      v12 = samus_anim_frame ? v11[2] : v11[0];
    }
    uint16 v13 = kDrawArmCannon_Tab2[v12 & 0x7F] + 2 * arm_cannon_frame;
    uint16 v14 = vram_write_queue_tail;
    gVramWriteEntry(vram_write_queue_tail)->size = 32;
    v14 += 2;
    uint16 v15 = *(uint16 *)RomPtr_90(v13);
    gVramWriteEntry(v14)->size = v15;
    v14 += 2;
    LOBYTE(gVramWriteEntry(v14++)->size) = -102;
    gVramWriteEntry(v14)->size = addr_kVram_UnclosedArmCannon;
    vram_write_queue_tail = v14 + 2;
  }
}

static uint16 Projectile_SinLookup_Inner(uint16 k, uint16 r24) {  // 0x90CC8A
  uint16 prod = Mult8x8(*((uint8 *)&kSinCosTable8bit_Sext[64] + k), r24);
  uint16 r18 = prod >> 8;
  prod = Mult8x8(*((uint8 *)&kSinCosTable8bit_Sext[64] + k + 1), r24);
  return r18 + prod;
}

Point16U Projectile_SinLookup(uint16 j, uint16 a) {  // 0x90CC39
  uint16 v2, v4;
  uint16 r24 = a;
  uint16 r26 = j;
  if (sign16(j - 128))
    v2 = Projectile_SinLookup_Inner(2 * j, r24);
  else
    v2 = -Projectile_SinLookup_Inner(2 * (uint8)(j + 0x80), r24);
  int16 v3 = (uint8)(r26 - 64);
  if (sign16(v3 - 128))
    v4 = Projectile_SinLookup_Inner(2 * v3, r24);
  else
    v4 = -Projectile_SinLookup_Inner(2 * (uint8)(v3 + 0x80), r24);
  return (Point16U) { v2, v4 };
}


static const uint16 kCostOfSbaInPowerBombs[12] = {  // 0x90CCC0
  0, 1, 1, 0, 1, 0, 0, 0,
  1, 0, 0, 0,
};

static Func_V_A *const kFireSbaFuncs[12] = {
  FireSba_ClearCarry,
  FireSba_FireWave,
  FireSba_FireIce,
  FireSba_ClearCarry,
  FireSba_FireSpazer,
  FireSba_ClearCarry,
  FireSba_ClearCarry,
  FireSba_ClearCarry,
  FireSba_FirePlasma,
  FireSba_ClearCarry,
  FireSba_ClearCarry,
  FireSba_ClearCarry,
};

uint8 FireSba(void) {
  int16 v2;

  if (hud_item_index != kHudItem_3_PowerBomb)
    return 0;
  uint16 v1 = 2 * (equipped_beams & (kBeam_Plasma | kBeam_Spazer | kBeam_Ice | kBeam_Wave));
  v2 = samus_power_bombs - kCostOfSbaInPowerBombs[v1 >> 1];
  if (v2 < 0)
    v2 = 0;
  samus_power_bombs = v2;
  uint8 rv = kFireSbaFuncs[v1 >> 1]();
  if (!samus_power_bombs) {
    hud_item_index = kHudItem_0_Nothing;
    samus_auto_cancel_hud_item_index = 0;
  }
  return rv;
}

uint8 FireSba_ClearCarry(void) {  // 0x90CD18
  return 0;
}

uint8 FireSba_FireWave(void) {  // 0x90CD1A
  static const int16 kFireSba_FireWave_X[4] = { 128, 128, -128, -128 };
  static const int16 kFireSba_FireWave_Y[4] = { 128, -128, -128, 128 };

  for (int i = 6; i >= 0; i -= 2) {
    int v1 = i >> 1;
    projectile_timers[v1] = 4;
    projectile_type[v1] = equipped_beams & (kBeam_Charge | kBeam_Plasma | kBeam_Spazer | kBeam_Ice | kBeam_Wave) | (kProjectileType_DontInteractWithSamus | kProjectileType_Charged);
    projectile_dir[v1] = 0;
    projectile_pre_instructions[v1] = FUNC16(ProjPreInstr_WaveSba);
    projectile_y_speed[v1] = 600;
    projectile_x_speed[v1] = 0;
    projectile_variables[v1] = 0;
    projectile_x_subpos[v1] = 0;
    projectile_y_subpos[v1] = 0;
    projectile_x_pos[v1] = kFireSba_FireWave_X[v1] + samus_x_pos;
    projectile_y_pos[v1] = kFireSba_FireWave_Y[v1] + samus_y_pos;
    InitializeSbaProjectile(i);
  }
  projectile_counter = 4;
  cooldown_timer = kProjectileCooldown_Uncharged[projectile_type[0] & kProjectileType_CooldownMask];
  sba_angle_delta = 4;
  QueueSfx1_Max6(kSfx1_WaveSba);
  return 1;
}

uint8 FireSba_FireIce(void) {  // 0x90CD9B
  static const uint16 kIcePlasmaSbaProjectileOriginAngles[8] = { 0, 0x40, 0x80, 0xc0, 0x20, 0x60, 0xa0, 0xe0 };

  if (projectile_pre_instructions[0] == FUNC16(ProjPreInstr_IceSbaEnd)
      || projectile_pre_instructions[0] == FUNC16(ProjPreInstr_IceSbaMain)) {
    return 0;
  }
  for (int i = 6; i >= 0; i -= 2) {
    int v2 = i >> 1;
    projectile_timers[v2] = 4;
    projectile_type[v2] = equipped_beams & (kBeam_Charge | kBeam_Plasma | kBeam_Spazer | kBeam_Ice | kBeam_Wave) | (kProjectileType_DontInteractWithSamus | kProjectileType_Charged);
    projectile_dir[v2] = 0;
    projectile_pre_instructions[v2] = FUNC16(ProjPreInstr_IceSbaMain);
    projectile_variables[v2] = kIcePlasmaSbaProjectileOriginAngles[v2];
    projectile_y_speed[v2] = 600;
    InitializeProjectile(i);
  }
  projectile_counter = 4;
  cooldown_timer = kProjectileCooldown_Uncharged[projectile_type[0] & kProjectileType_CooldownMask];
  if (samus_pose_x_dir == kSamusXDir_FaceLeft)
    sba_angle_delta = -4;
  else
    sba_angle_delta = 4;
  QueueSfx1_Max6(kSfx1_IceSba);
  return 1;
}

uint8 FireSba_FireSpazer(void) {  // 0x90CE14
  static const int16 kFireSpazer_Timer[4] = { 0, 0, 4, 4 };
  static const int16 kFireSpazer_Yspeed[4] = { 4, -4, 4, -4 };

  for (int i = 6; i >= 0; i -= 2) {
    int v1 = i >> 1;
    projectile_timers[v1] = kFireSpazer_Timer[v1];
    projectile_dir[v1] = kProjectileDir_DownFaceLeft;
    projectile_pre_instructions[v1] = FUNC16(ProjPreInstr_SpazerSba);
    projectile_x_speed[v1] = 40;
    projectile_y_speed[v1] = kFireSpazer_Yspeed[v1];
    projectile_variables[v1] = 0;
    projectile_unk_A[v1] = 0;
    projectile_x_subpos[v1] = 0;
    projectile_y_subpos[v1] = 0;
    if ((int16)(i - 4) >= 0) {
      projectile_type[i >> 1] = (kProjectileType_DontInteractWithSamus | kProjectileType_SpazerSbaMask | kProjectileType_Spazer);
      InitializeShinesparkEchoOrSpazerSba(i);
    } else {
      projectile_type[i >> 1] = equipped_beams & (kBeam_Charge | kBeam_Plasma | kBeam_Spazer | kBeam_Ice | kBeam_Wave) | (kProjectileType_DontInteractWithSamus | kProjectileType_Charged);
      InitializeSbaProjectile(i);
    }
  }
  projectile_counter = 4;
  cooldown_timer = kProjectileCooldown_Uncharged[projectile_type[0] & kProjectileType_CooldownMask];
  sba_angle_delta = 0;
  QueueSfx1_Max6(kSfx1_SpazerSba);
  return 1;
}

uint8 FireSba_FirePlasma(void) {  // 0x90CE98
  static const uint16 kIcePlasmaSbaProjectileOriginAngles[8] = { 0, 0x40, 0x80, 0xc0, 0x20, 0x60, 0xa0, 0xe0 };


  if (projectile_pre_instructions[0] == FUNC16(ProjPreInstr_PlasmaSba))
    return 0;
  for (int i = 6; i >= 0; i -= 2) {
    int v2 = i >> 1;
    projectile_type[v2] = equipped_beams & (kBeam_Charge | kBeam_Plasma | kBeam_Spazer | kBeam_Ice | kBeam_Wave) | (kProjectileType_DontInteractWithSamus | kProjectileType_Charged);
    projectile_dir[v2] = 0;
    projectile_pre_instructions[v2] = FUNC16(ProjPreInstr_PlasmaSba);
    projectile_variables[v2] = kIcePlasmaSbaProjectileOriginAngles[v2];
    projectile_x_speed[v2] = 40;
    projectile_y_speed[v2] = 0;
    InitializeSbaProjectile(i);
  }
  projectile_counter = 4;
  cooldown_timer = kProjectileCooldown_Uncharged[projectile_type[0] & kProjectileType_CooldownMask];
  if (samus_pose_x_dir == kSamusXDir_FaceLeft)
    sba_angle_delta = -4;
  else
    sba_angle_delta = 4;
  QueueSfx1_Max6(kSfx1_PlasmaSba);
  return 1;
}

void ProjPreInstr_IceSbaMain(uint16 k) {  // 0x90CF09
  int v1 = k >> 1;
  if ((projectile_dir[v1] & (0xF0 | kProjectileDir_Delete)) != 0) {
    QueueSfx1_Max6(kSfx1_IceSbaEnd);
    ClearProjectile(k);
  } else {
    bool v2 = projectile_timers[v1]-- == 1;
    if (v2) {
      projectile_timers[v1] = 4;
      SpawnProjectileTrail(k);
      k = projectile_index;
    }
    int v3 = k >> 1;
    Point16U pt = Projectile_SinLookup(projectile_variables[v3], 0x20);
    projectile_x_pos[v3] = pt.x + samus_x_pos;
    projectile_y_pos[v3] = pt.y + samus_y_pos;
    projectile_variables[v3] = (uint8)(sba_angle_delta + projectile_variables[v3]);
    v2 = projectile_y_speed[v3]-- == 1;
    if (v2) {
      projectile_pre_instructions[v3] = FUNC16(ProjPreInstr_IceSbaEnd);
      projectile_x_speed[v3] = 40;
      QueueSfx1_Max6(kSfx1_IceSbaEnd);
    }
    cooldown_timer = 2;
    flare_counter = 0;
  }
}

void ProjPreInstr_IceSbaEnd(uint16 k) {  // 0x90CF7A
  int16 v5;
  int16 v6;
  int16 v7;

  int v1 = k >> 1;
  if ((projectile_dir[v1] & (0xF0 | kProjectileDir_Delete)) != 0)
    goto LABEL_9;
  if (projectile_timers[v1]-- == 1) {
    projectile_timers[v1] = 4;
    SpawnProjectileTrail(k);
    k = projectile_index;
  }
  int v3;
  v3 = k >> 1;
  Point16U pt = Projectile_SinLookup(projectile_variables[v3], projectile_x_speed[v3]);
  pt.x += samus_x_pos;
  projectile_x_pos[v3] = pt.x;
  v5 = pt.x - layer1_x_pos;
  if (sign16(v5 + 32)
      || !sign16(v5 - 288)
      || (v6 = pt.y + samus_y_pos, projectile_y_pos[v3] = pt.y + samus_y_pos, v7 = v6 - layer1_y_pos, sign16(v7 - 16))
      || !sign16(v7 - 256)) {
LABEL_9:
    ClearProjectile(k);
  } else {
    projectile_variables[v3] = (uint8)(sba_angle_delta + projectile_variables[v3]);
    projectile_x_speed[v3] = (uint8)(projectile_x_speed[v3] + 8);
    cooldown_timer = 2;
    flare_counter = 0;
  }
}

void TriggerShinesparkWindup(void) {  // 0x90CFFA
  samus_movement_handler = FUNC16(Samus_MovementHandler_ShinesparkWindup);
  samus_y_dir = 1;
  speed_boost_counter = 0x400;
  samus_y_subspeed = 0;
  samus_y_speed = 0;
  knockback_dir = 0;
  samus_x_extra_run_speed = 8;
  samus_x_extra_run_subspeed = 0;
  samus_x_base_speed = 0;
  samus_x_base_subspeed = 0;
  substate = 7;
  suit_pickup_light_beam_pos = 0;
  cooldown_timer = 0;
  timer_for_shinesparks_startstop = 30;
  samus_shine_timer = 60;
  timer_for_shine_timer = 6;
  special_samus_palette_frame = 0;
  bomb_jump_dir = 0;
  if (flare_counter) {
    if (!sign16(flare_counter - 16))
      QueueSfx1_Max9(kSfx1_Silence);
    flare_counter = 0;
    ClearFlareAnimationState();
  }
}

void Samus_MovementHandler_ShinesparkWindup(void) {  // 0x90D068
  bool v0 = (--timer_for_shinesparks_startstop & 0x8000) != 0;
  if (!timer_for_shinesparks_startstop || v0) {
    if (samus_pose_x_dir == kSamusXDir_FaceLeft)
      samus_new_pose_interrupted = 204;
    else
      samus_new_pose_interrupted = 203;
    samus_movement_handler = FUNC16(Samus_MovementHandler_VerticalShinespark);
    samus_input_handler = FUNC16(nullsub_152);
    speed_echoes_index = 0;
    speed_echo_xspeed[0] = 0;
    speed_echo_xspeed[1] = 0;
    speed_echo_xpos[0] = 0;
    speed_echo_xpos[1] = 0;
    QueueSfx3_Max9(kSfx3_Shinespark);
  }
}

/**
* @brief Feature: Control the shinespark in any direction
*/
void Shinespark_Control(void) {
  if (joypad1_newkeys & kButton_Left && samus_pose != kPose_CA_FaceL_Shinespark_Horiz) {
    samus_new_pose = kPose_CA_FaceL_Shinespark_Horiz;
    SetHiLo(&samus_x_extra_run_speed, &samus_x_extra_run_subspeed, INT16_SHL16(2));
  }
  else if (joypad1_newkeys & kButton_Right && samus_pose != kPose_C9_FaceR_Shinespark_Horiz) {
    samus_new_pose = kPose_C9_FaceR_Shinespark_Horiz;
    SetHiLo(&samus_x_extra_run_speed, &samus_x_extra_run_subspeed, INT16_SHL16(2));
  }
  else if (joypad1_newkeys & kButton_Up) {
    if (samus_pose_x_dir == kSamusXDir_FaceLeft && samus_pose != kPose_CC_FaceL_Shinespark_Vert) {
      samus_new_pose = kPose_CC_FaceL_Shinespark_Vert;
      SetHiLo(&samus_y_speed, &samus_y_subspeed, INT16_SHL16(1));
      SetHiLo(&substate, &suit_pickup_light_beam_pos, 0);
    }
    else if (samus_pose_x_dir == kSamusXDir_FaceRight && samus_pose != kPose_CB_FaceR_Shinespark_Vert) {
      samus_new_pose = kPose_CB_FaceR_Shinespark_Vert;
      SetHiLo(&samus_y_speed, &samus_y_subspeed, INT16_SHL16(1));
      SetHiLo(&substate, &suit_pickup_light_beam_pos, 0);
    }
  }
  if (samus_pose == kPose_CA_FaceL_Shinespark_Horiz || samus_pose == kPose_C9_FaceR_Shinespark_Horiz) {
    if (joypad1_prev & button_config_aim_down_L) {
      Samus_MoveDown(__PAIR32__(4, 0));
    }
    else if (joypad1_prev & button_config_aim_up_R) {
      Samus_MoveUp(__PAIR32__(-4, 0));
    }
  }
  if (samus_pose != samus_new_pose) {
  }
}

void Samus_MovementHandler_VerticalShinespark(void) {  // 0x90D0AB
  samus_contact_damage_index = kSamusContactDamageIndex_2_Shinespark;
  samus_hurt_flash_counter = 8;
  Samus_UpdateSpeedEchoPos();
  Samus_ShinesparkMove_Y();
  if (enhanced_features0 & kFeatures0_ShinesparkControl) {
      Shinespark_Control();
  }
  Samus_EndShinespark();
// disable shinespark health drain
  if (enhanced_features0 & kFeatures0_ShinesparkHealth) {
      return;
  }

  if (samus_health >= 30) {
      --samus_health;
  }
}

void Samus_MovementHandler_DiagonalShinespark(void) {  // 0x90D0D7
  samus_contact_damage_index = kSamusContactDamageIndex_2_Shinespark;
  samus_hurt_flash_counter = 8;
  Samus_UpdateSpeedEchoPos();
  Samus_ShinesparkMove_X();
  Samus_ShinesparkMove_Y();
  if (enhanced_features0 & kFeatures0_ShinesparkControl) {
      Shinespark_Control();
  }
  Samus_EndShinespark();
  // disable shinespark health drain
  if (enhanced_features0 & kFeatures0_ShinesparkHealth) {
      return;
  }

  if (samus_health >= 30) {
      --samus_health;
  }
}

void Samus_MovementHandler_HorizontalShinespark(void) {  // 0x90D106
  samus_contact_damage_index = kSamusContactDamageIndex_2_Shinespark;
  samus_hurt_flash_counter = 8;
  Samus_UpdateSpeedEchoPos();
  Samus_ShinesparkMove_X();
  if (enhanced_features0 & kFeatures0_ShinesparkControl) {
      Shinespark_Control();
  }
  Samus_EndShinespark();
  // disable shinespark health drain
  if (enhanced_features0 & kFeatures0_ShinesparkHealth) {
      return;
  }

  if (samus_health >= 30) {
      --samus_health;
  }
}

static uint32 Samus_ClampSpeedHi(int32 amt, int val) {
  if (!sign16((amt >> 16) - val))
    amt = val << 16 | (amt & 0xffff);
  return amt;
}

void Samus_ShinesparkMove_X(void) {  // 0x90D132
  int16 v4;

  samus_shine_timer = 15;
  AddToHiLo(&samus_x_extra_run_speed, &samus_x_extra_run_subspeed, __PAIR32__(samus_y_accel, samus_y_subaccel));
  if (!sign16(samus_x_extra_run_speed - 15))
    SetHiLo(&samus_x_extra_run_speed, &samus_x_extra_run_subspeed, INT16_SHL16(15));
  int32 amt = 0;
  if (samus_pose_x_dir == kSamusXDir_FaceLeft) {
    amt = Samus_ClampSpeedHi(-(int32)Samus_CalcDisplacementMoveLeft(amt), 15);
    CheckEnemyColl_Result cres = Samus_CheckSolidEnemyColl(amt);
    amt = cres.amt;
    if (cres.collision) {
      samus_collision_flag = cres.collision;
      goto LABEL_18;
    }
    amt = -(int32)amt;
  } else {
    amt = Samus_ClampSpeedHi(Samus_CalcDisplacementMoveRight(amt), 25);
    CheckEnemyColl_Result cres = Samus_CheckSolidEnemyColl(amt);
    amt = cres.amt;
    if (cres.collision) {
      samus_collision_flag = cres.collision;
      goto LABEL_18;
    }
  }
  Samus_MoveRight_NoSolidColl(amt);
  Samus_AlignYPosSlope();
LABEL_18:
  v4 = samus_x_pos - samus_prev_x_pos;
  if ((int16)(samus_x_pos - samus_prev_x_pos) < 0) {
    if (sign16(v4 + 15))
      samus_prev_x_pos = samus_x_pos + 15;
  } else if (!sign16(v4 - 16)) {
    samus_prev_x_pos = samus_x_pos - 15;
  }
}

void Samus_ShinesparkMove_Y(void) {  // 0x90D1FF
  samus_shine_timer = 15;

  AddToHiLo(&substate, &suit_pickup_light_beam_pos, __PAIR32__(samus_y_accel, samus_y_subaccel));
  AddToHiLo(&samus_y_speed, &samus_y_subspeed, __PAIR32__(substate, suit_pickup_light_beam_pos));
  int32 amt = Samus_ClampSpeedHi(__PAIR32__(samus_y_speed, samus_y_subspeed), 14);
  amt -= __PAIR32__(extra_samus_y_displacement, extra_samus_y_subdisplacement);
  samus_collision_direction = 2;
  CheckEnemyColl_Result cres = Samus_CheckSolidEnemyColl(Samus_ClampSpeedHi(amt, 15));
  amt = cres.amt;
  if (cres.collision) {
    samus_collision_flag = cres.collision;
  } else {
    Samus_MoveDown_NoSolidColl(-(int32)amt);
  }
  if (sign16(samus_y_pos - samus_prev_y_pos + 14))
    samus_prev_y_pos = samus_y_pos + 14;
}

uint8 Samus_EndShinespark(void) {  // 0x90D2BA
  if (!sign16(samus_health - 30) && !samus_collision_flag)
    return 0;
  if (samus_pose_x_dir == kSamusXDir_FaceLeft) {
    speed_echo_xspeed[0] = 32;
    speed_echo_xspeed[1] = 160;
    speed_echo_xpos[2] = 4;
  } else {
    speed_echo_xspeed[0] = 224;
    speed_echo_xspeed[1] = 96;
    speed_echo_xpos[2] = -4;
  }
  samus_y_subspeed = 0;
  samus_y_speed = 0;
  samus_x_extra_run_speed = 0;
  samus_x_extra_run_subspeed = 0;
  speed_boost_counter = 0;
  UNUSED_word_7E0B1A = 0;
  samus_y_dir = 0;
  samus_movement_handler = FUNC16(Samus_MovementHandler_ShinesparkCrash_EchoCircle);
  samus_draw_handler = FUNC16(Samus_DrawHandler_EndOfShinespark);
  speed_echoes_index = 0;
  speed_echo_xpos[0] = samus_x_pos;
  speed_echo_xpos[1] = samus_x_pos;
  speed_echo_ypos[0] = samus_y_pos;
  speed_echo_ypos[1] = samus_y_pos;
  speed_echo_xspeed[2] = 0;
  samus_hurt_flash_counter = 0;
  QueueSfx1_Max6(kSfx1_SamusDamaged_HighPriority);
  QueueSfx3_Max6(kSfx3_ShinesparkEnded);
  return 1;
}

static Func_V *const kSamus_MoveHandler_ShinesparkCrash[3] = {  // 0x90D346
  Samus_MovementHandler_ShinesparkCrash_EchoCircle_Phase0,
  Samus_MovementHandler_ShinesparkCrash_EchoCircle_Phase1,
  Samus_MovementHandler_ShinesparkCrash_EchoCircle_Phase2,
};

void Samus_MovementHandler_ShinesparkCrash_EchoCircle(void) {

  samus_shine_timer = 15;
  kSamus_MoveHandler_ShinesparkCrash[HIBYTE(speed_echoes_index)]();
  for (int i = 2; i >= 0; i -= 2) {
    int v1 = i >> 1;
    Point16U pt = Projectile_SinLookup(speed_echo_xspeed[v1], (uint8)speed_echoes_index);
    speed_echo_xpos[v1] = pt.x + samus_x_pos;
    speed_echo_ypos[v1] = pt.y + samus_y_pos;
  }
}

void Samus_MovementHandler_ShinesparkCrash_EchoCircle_Phase0(void) {  // 0x90D383
  uint16 v0 = speed_echoes_index + 4;
  if (!sign16(speed_echoes_index - 12))
    v0 |= 0x100;
  speed_echoes_index = v0;
}

void Samus_MovementHandler_ShinesparkCrash_EchoCircle_Phase1(void) {  // 0x90D396
  speed_echo_xspeed[0] = (uint8)(LOBYTE(speed_echo_xpos[2]) + LOBYTE(speed_echo_xspeed[0]));
  speed_echo_xspeed[1] = (uint8)(LOBYTE(speed_echo_xpos[2]) + LOBYTE(speed_echo_xspeed[1]));
  speed_echo_ypos[2] += 4;
  if (!sign16(speed_echo_ypos[2] - 128))
    speed_echoes_index = (uint8)speed_echoes_index | 0x200;
}

void Samus_MovementHandler_ShinesparkCrash_EchoCircle_Phase2(void) {  // 0x90D3CC
  speed_echoes_index -= 4;
  if (!(uint8)speed_echoes_index) {
    samus_movement_handler = FUNC16(Samus_MovementHandler_ShinesparkCrash_EchoCircle_Finish);
    timer_for_shinesparks_startstop = 30;
    speed_echoes_index = 0;
    speed_echo_xspeed[0] = 0;
    speed_echo_xspeed[1] = 0;
  }
}

void Samus_MovementHandler_ShinesparkCrash_EchoCircle_Finish(void) {  // 0x90D3F3
  samus_shine_timer = 15;
  bool v0 = (--timer_for_shinesparks_startstop & 0x8000) != 0;
  if (!timer_for_shinesparks_startstop || v0) {
    samus_movement_handler = FUNC16(Samus_MovementHandler_ShinesparkCrash_Finish);
    samus_draw_handler = FUNC16(SamusDrawHandler_Default);
  }
}

void Samus_MovementHandler_ShinesparkCrash_Finish(void) {  // 0x90D40D
  static const uint8 kShinesparkCrashFinish_Tab0[12] = { 0, 0x80, 0, 0x80, 0x40, 0xc0, 0x40, 0xc0, 0xe0, 0x60, 0x20, 0xa0 };
  speed_echoes_index = 0;
  if (sign16(projectile_counter - 5)) {
    if (sign16(projectile_counter - 4)) {
      ++projectile_counter;
      speed_echo_xspeed[2] = 64;
      speed_echo_xpos[2] = samus_x_pos;
      speed_echo_ypos[2] = samus_y_pos;
      projectile_type[3] = kProjectileType_DontInteractWithSamus | kProjectileType_ShinesparkEcho;
      InitializeShinesparkEchoOrSpazerSba(6);
      projectile_pre_instructions[3] = FUNC16(ProjPreInstr_SpeedEcho);
      projectile_variables[3] = kShinesparkCrashFinish_Tab0[(uint16)(2 * (samus_pose - kPose_C9_FaceR_Shinespark_Horiz))];
      projectile_x_speed[3] = 0;
    }
    ++projectile_counter;
    speed_echo_xspeed[3] = 64;
    speed_echo_xpos[3] = samus_x_pos;
    speed_echo_ypos[3] = samus_y_pos;
    projectile_type[4] = kProjectileType_DontInteractWithSamus | kProjectileType_ShinesparkEcho;
    InitializeShinesparkEchoOrSpazerSba(8);
    projectile_pre_instructions[4] = FUNC16(ProjPreInstr_SpeedEcho);
    projectile_variables[4] = kShinesparkCrashFinish_Tab0[(uint16)(2 * (samus_pose - kPose_C9_FaceR_Shinespark_Horiz)) + 1];
    projectile_x_speed[4] = 0;
  }
  cooldown_timer = 0;
  samus_shine_timer = 1;
  if (samus_pose_x_dir == kSamusXDir_FaceLeft)
    samus_new_pose_transitional = 2;
  else
    samus_new_pose_transitional = 1;
  samus_hurt_switch_index = 2;
  substate = 0;
  suit_pickup_light_beam_pos = 0;
}

void ProjPreInstr_SpeedEcho(uint16 k) {  // 0x90D4D2
  int16 v3;
  uint16 v4;
  int16 v5;

  int v1 = k >> 1;
  projectile_x_speed[v1] += 8;
  Point16U pt = Projectile_SinLookup(projectile_variables[v1], LOBYTE(projectile_x_speed[v1]));
  uint16 v2 = pt.x + samus_x_pos;
  *(uint16 *)((uint8 *)&speed_echoes_index + k) = pt.x + samus_x_pos;
  projectile_x_pos[v1] = v2;
  v3 = v2 - layer1_x_pos;
  if (v3 < 0
      || !sign16(v3 - 256)
      || (v4 = pt.y + samus_y_pos,
          speed_echo_xpos[v1 + 3] = pt.y + samus_y_pos,
          projectile_y_pos[v1] = v4,
          v5 = v4 - layer1_y_pos,
          v5 < 0)
      || !sign16(v5 - 256)) {
    speed_echo_ypos[v1 + 3] = 0;
    *(uint16 *)((uint8 *)&speed_echoes_index + k) = 0;
    speed_echo_xpos[v1 + 3] = 0;
    ClearProjectile(k);
  }
}

void UNUSED_Grapple_Func1(void) {  // 0x90D525
  bool v0; // sf

  if ((button_config_shoot_x & joypad1_lastkeys) != 0
      && (v0 = (int16)(grapple_walljump_timer - 1) < 0, --grapple_walljump_timer, grapple_walljump_timer)
      && !v0) {
    if ((grapple_beam_length_delta & 0x8000) == 0) {
      grapple_beam_length += grapple_beam_length_delta;
      if (!sign16(grapple_beam_length - 96))
        grapple_beam_length_delta = -16;
    }
    Point16U pt = Projectile_SinLookup(HIBYTE(grapple_beam_end_angle16), grapple_beam_length);
    grapple_beam_end_x_pos = pt.x + x_pos_of_start_of_grapple_beam;
    grapple_beam_end_y_pos = pt.y + y_pos_of_start_of_grapple_beam;
    grapple_beam_end_angle16 += 2048;
    GrappleBeamFunc_BF1B();
  } else {
    grapple_beam_function = FUNC16(GrappleBeamFunc_Cancel);
  }
}

uint8 CrystalFlash(void) {  // 0x90D5A2
  SamusPose v1;

  if (sign16(game_state - kGameState_40_TransitionToDemo)) {
    if (joypad1_lastkeys != (button_config_shoot_x | (kButton_Down | kButton_L | kButton_R)))
      return 1;
  }
  if (samus_y_speed
      || samus_y_subspeed
      || !sign16(samus_health - 51)
      || samus_reserve_health
      || sign16(samus_missiles - 10)
      || sign16(samus_super_missiles - 10)
      || sign16(samus_power_bombs - 10)) {
    return 1;
  }
  v1 = samus_pose_x_dir == kSamusXDir_FaceLeft ? kPose_D4_FaceL_CrystalFlash : kPose_D3_FaceR_CrystalFlash;
  samus_pose = v1;
  SamusFunc_F433();
  Samus_SetAnimationFrameIfPoseChanged();
  if (samus_movement_type != kMovementType_1B_Shinespark_CrystalFlash_Drained_DamagedByMotherBrain)
    return 1;
  samus_last_different_pose = samus_prev_pose;
  *(uint16 *)&samus_last_different_pose_x_dir = *(uint16 *)&samus_prev_pose_x_dir;
  samus_prev_pose = samus_pose;
  *(uint16 *)&samus_prev_pose_x_dir = *(uint16 *)&samus_pose_x_dir;
  samus_movement_handler = FUNC16(SamusMoveHandler_CrystalFlashStart);
  if (samus_input_handler != FUNC16(Samus_InputHandler_Demo))
    samus_input_handler = FUNC16(nullsub_152);
  timer_for_shinesparks_startstop = 9;
  crystal_flash_ammo_decrement_index = 0;
  substate = 10;
  suit_pickup_light_beam_pos = 0;
  *(uint16 *)&suit_pickup_color_math_R = 0;
  timer_for_shine_timer = 7;
  special_samus_palette_frame = 0;
  samus_shine_timer = 1;
  *(uint16 *)&suit_pickup_color_math_B = 1;
  samus_invincibility_timer = 0;
  samus_knockback_timer = 0;
  knockback_dir = 0;
  return 0;
}

void SamusMoveHandler_CrystalFlashStart(void) {  // 0x90D678
  samus_y_pos -= 2;
  if ((--timer_for_shinesparks_startstop & 0x8000) != 0) {
    samus_anim_frame_timer = 3;
    samus_anim_frame = 6;
    *(uint16 *)&suit_pickup_color_math_R = samus_y_pos;
    samus_movement_handler = FUNC16(SamusMoveHandler_CrystalFlashMain);
    samus_invincibility_timer = 0;
    samus_knockback_timer = 0;
    QueueSfx3_Max15(kSfx3_Silence);
    power_bomb_flag = 0;
    power_bomb_explosion_x_pos = samus_x_pos;
    power_bomb_explosion_y_pos = samus_y_pos;
    EnableHdmaObjects();
    SpawnCrystalFlashHdmaObjs();
  }
}

static Func_V *const kSamusMoveHandler_CrystalFlashMainFuncs[3] = {  // 0x90D6CE
  SamusMoveHandler_CrystalFlash_0_DecMissiles,
  SamusMoveHandler_CrystalFlash_1_DecSuperMissiles,
  SamusMoveHandler_CrystalFlash_2_DecPowerBombs,
};

void SamusMoveHandler_CrystalFlashMain(void) {
  kSamusMoveHandler_CrystalFlashMainFuncs[crystal_flash_ammo_decrement_index]();
  samus_invincibility_timer = 0;
  samus_knockback_timer = 0;
}

void SamusMoveHandler_CrystalFlash_0_DecMissiles(void) {  // 0x90D6E3
  if ((nmi_frame_counter_word & 7) == 0) {
    --samus_missiles;
    Samus_RestoreHealth(50);
    bool v0 = (int16)(substate - 1) < 0;
    if (!--substate || v0) {
      substate = 10;
      ++crystal_flash_ammo_decrement_index;
    }
  }
}

void SamusMoveHandler_CrystalFlash_1_DecSuperMissiles(void) {  // 0x90D706
  if ((nmi_frame_counter_word & 7) == 0) {
    --samus_super_missiles;
    Samus_RestoreHealth(50);
    bool v0 = (int16)(substate - 1) < 0;
    if (!--substate || v0) {
      substate = 10;
      ++crystal_flash_ammo_decrement_index;
    }
  }
}

void SamusMoveHandler_CrystalFlash_2_DecPowerBombs(void) {  // 0x90D729
  if ((nmi_frame_counter_word & 7) == 0) {
    --samus_power_bombs;
    Samus_RestoreHealth(50);
    bool v0 = (int16)(substate - 1) < 0;
    if (!--substate || v0) {
      samus_movement_handler = FUNC16(SamusMoveHandler_CrystalFlashFinish);
      samus_draw_handler = FUNC16(SamusDrawHandler_Default);
      samus_anim_frame_timer = 3;
      samus_anim_frame = 12;
    }
  }
}

void SamusMoveHandler_CrystalFlashFinish(void) {  // 0x90D75B
  if (samus_y_pos != *(uint16 *)&suit_pickup_color_math_R)
    ++samus_y_pos;
  if (samus_movement_type == kMovementType_00_Standing) {
    power_bomb_flag = 0;
    samus_shine_timer = -1;
    samus_movement_handler = FUNC16(Samus_MovementHandler_Normal);
    if (samus_input_handler != FUNC16(Samus_InputHandler_Demo)) {
      samus_input_handler = FUNC16(Samus_InputHandler_Normal);
      samus_invincibility_timer = 0;
      samus_knockback_timer = 0;
    }
  }
}

void ProjPreInstr_PlasmaSba(uint16 k) {  // 0x90D793
  int16 v3;

  int v1 = k >> 1;
  if ((projectile_dir[v1] & (0xF0 | kProjectileDir_Delete)) != 0) {
    ClearProjectile(k);
  } else {
    cooldown_timer = 2;
    flare_counter = 0;
    Point16U pt = Projectile_SinLookup(projectile_variables[v1], projectile_x_speed[v1]);
    projectile_x_pos[v1] = pt.x + samus_x_pos;
    projectile_y_pos[v1] = pt.y + samus_y_pos;
    projectile_variables[v1] = (uint8)(sba_angle_delta + projectile_variables[v1]);
    v3 = 2 * projectile_y_speed[v1];
    if (v3) {
      if (v3 == 2) {
        ProjPreInstr_PlasmaSba_Phase1_Contract(k);
      } else {
        if (v3 != 4) {
          Unreachable();
          while (1)
            ;
        }
        ProjPreInstr_PlasmaSba_Phase2_Disperse(k);
      }
    } else {
      ProjPreInstr_PlasmaSba_Phase0_Expand(k);
    }
  }
}

void ProjPreInstr_PlasmaSba_Phase0_Expand(uint16 j) {  // 0x90D7E1
  int v1 = j >> 1;
  uint16 v2 = (uint8)(projectile_x_speed[v1] + 4);
  projectile_x_speed[v1] = v2;
  if (!sign16(v2 - 192))
    projectile_y_speed[v1] = 1;
}

void ProjPreInstr_PlasmaSba_Phase1_Contract(uint16 j) {  // 0x90D7FA
  int v1 = j >> 1;
  uint16 v2 = (uint8)(projectile_x_speed[v1] - 4);
  projectile_x_speed[v1] = v2;
  if (sign16(v2 - 45))
    projectile_y_speed[v1] = 2;
}

void ProjPreInstr_PlasmaSba_Phase2_Disperse(uint16 j) {  // 0x90D813
  int v1 = j >> 1;
  if (sign16(projectile_x_pos[v1] - layer1_x_pos + 32)
      || !sign16(projectile_x_pos[v1] - layer1_x_pos - 288)
      || sign16(projectile_y_pos[v1] - layer1_y_pos - 16)
      || !sign16(projectile_y_pos[v1] - layer1_y_pos - 256)) {
    ClearProjectile(j);
  } else {
    projectile_x_speed[v1] = (uint8)(projectile_x_speed[v1] + 4);
  }
}

static const uint16 kBombSpread_Tab0[5] = { 0x78, 0x6e, 0x64, 0x6e, 0x78 };
static const uint16 kBombSpread_Tab1[5] = { 0x8100, 0x8080, 0, 0x80, 0x100 };
static const uint16 kBombSpread_Tab2[5] = { 0, 1, 2, 1, 0 };
static const uint16 kBombSpread_Tab3[5] = { 0, 0, 0x8000, 0, 0 };

void ProjPreInstr_SpreadBomb(uint16 k) {  // 0x90D8F7
  int v1 = k >> 1;
  if ((projectile_dir[v1] & (0xF0 | kProjectileDir_Delete)) != 0) {
    ClearProjectile(k);
    return;
  }
  HandleBomb();
  if (projectile_variables[v1]) {
    AddToHiLo(&projectile_y_speed[v1], &projectile_timers[v1], __PAIR32__(samus_y_accel, samus_y_subaccel));
    AddToHiLo(&projectile_y_pos[v1], &projectile_y_subpos[v1], __PAIR32__(projectile_y_speed[v1], projectile_timers[v1]));
    if (BlockCollSpreadBomb(k) & 1) {
      AddToHiLo(&projectile_y_pos[v1], &projectile_y_subpos[v1], -IPAIR32(projectile_y_speed[v1], projectile_timers[v1]));
      if ((projectile_y_speed[v1] & 0x8000) != 0) {
        projectile_y_speed[v1] = 0;
        projectile_y_radius[v1] = 0;
      } else {
        projectile_timers[v1] = kBombSpread_Tab3[v1 - 5];
        projectile_y_speed[v1] = projectile_unk_A[v1];
      }
      return;
    }
    uint16 t = projectile_x_speed[v1];
    if (t & 0x8000)
      AddToHiLo(&projectile_x_pos[v1], &projectile_x_subpos[v1], -INT16_SHL8(t & 0x7fff));
    else
      AddToHiLo(&projectile_x_pos[v1], &projectile_x_subpos[v1], INT16_SHL8(t));
  }
  if (BlockCollSpreadBomb(k) & 1) {
    uint16 t = projectile_x_speed[v1];
    projectile_x_speed[v1] ^= 0x8000;
    if (!(t & 0x8000))
      AddToHiLo(&projectile_x_pos[v1], &projectile_x_subpos[v1], -INT16_SHL8(t));
    else
      AddToHiLo(&projectile_x_pos[v1], &projectile_x_subpos[v1], INT16_SHL8(t & 0x7fff));
  }
}

void ProjPreInstr_WaveSba(uint16 k) {  // 0x90DA08
  int v1 = k >> 1;
  bool v2, v3;
  if ((projectile_dir[v1] & (0xF0 | kProjectileDir_Delete)) != 0
      || (v2 = projectile_y_speed[v1] == 1,
          v3 = (int16)(projectile_y_speed[v1] - 1) < 0,
          --projectile_y_speed[v1],
          v2)
      || v3) {
    QueueSfx1_Max6(kSfx1_WaveSbaEnd_Silence);
    ClearProjectile(k);
    return;
  }
  uint16 R34 = projectile_x_speed[v1];
  //R36 = projectile_variables[v1];
  v2 = projectile_timers[v1]-- == 1;
  if (v2) {
    projectile_timers[v1] = 4;
    SpawnProjectileTrail(k);
    k = projectile_index;
  }
  if ((int16)(samus_x_pos - projectile_x_pos[v1]) < 0) {
    if (!sign16(projectile_x_speed[v1] + 2047))
      projectile_x_speed[v1] -= 64;
  } else if (sign16(projectile_x_speed[v1] - 2048)) {
    projectile_x_speed[v1] += 64;
  }
  AddToHiLo(&projectile_x_pos[v1], &projectile_x_subpos[v1], INT16_SHL8(projectile_x_speed[v1]));

  if ((int16)(samus_y_pos - projectile_y_pos[v1]) < 0) {
    if (!sign16(projectile_variables[v1] + 2047))
      projectile_variables[v1] -= 64;
  } else if (sign16(projectile_variables[v1] - 2048)) {
    projectile_variables[v1] += 64;
  }
  AddToHiLo(&projectile_y_pos[v1], &projectile_y_subpos[v1], INT16_SHL8(projectile_variables[v1]));
  if (k == 6) {
    if ((projectile_x_speed[3] & 0x8000) != 0) {
      if ((R34 & 0x8000) == 0)
        QueueSfx1_Max6(kSfx1_WaveSba);
    } else if ((R34 & 0x8000) != 0) {
      QueueSfx1_Max6(kSfx1_WaveSba);
    }
  }
  cooldown_timer = 2;
  flare_counter = 0;
}

void BombSpread(void) {  // 0x90D849
  if (bomb_functions[0] != FUNC16(ProjPreInstr_SpreadBomb)) {
    uint16 v0 = 10;
    do {
      int v1 = v0 >> 1;
      projectile_type[v1] = kProjectileType_DontInteractWithSamus | kProjectileType_Bomb;
      projectile_dir[v1] = 0;
      projectile_pre_instructions[v1] = FUNC16(ProjPreInstr_SpreadBomb);
      InitializeInstrForBombOrPowerBomb(v0);
      projectile_x_pos[v1] = samus_x_pos;
      projectile_x_subpos[v1] = 0;
      projectile_y_pos[v1] = samus_y_pos;
      projectile_y_subpos[v1] = 0;
      int v2 = (uint16)(v0 - 10) >> 1;
      projectile_x_speed[v1] = kBombSpread_Tab1[v2];
      projectile_timers[v1] = kBombSpread_Tab3[v2];
      uint16 v3 = -(int16)(kBombSpread_Tab2[v2] + ((bomb_spread_charge_timeout_counter >> 6) & 3));
      projectile_y_speed[v1] = v3;
      projectile_unk_A[v1] = v3;
      projectile_variables[v1] = kBombSpread_Tab0[v2];
      v0 += 2;
    } while ((int16)(v0 - 20) < 0);
    bomb_counter = 5;
    cooldown_timer = kNonBeamProjectileCooldowns[HIBYTE(projectile_type[5]) & (kProjectileType_ProjMask >> 8)];
    bomb_spread_charge_timeout_counter = 0;
    flare_counter = 0;
  }
}

typedef void Func_SpazerSba_V(uint16 j, uint16 r22);

static Func_SpazerSba_V *const kProjPreInstr_SpazerSba_FuncsB[3] = {  // 0x90DB06
  ProjPreInstr_SpazerSba_Phase0_Circle,
  ProjPreInstr_SpazerSba_Phase2_FlyToPoint,
  ProjPreInstr_SpazerSba_Phase4_FlyFromPoint,
};

static Func_Y_V *const kProjPreInstr_SpazerSba_FuncsA[4] = {
  ProjPreInstr_SpazerSba_ClearProjPair0,
  ProjPreInstr_SpazerSba_ClearProjPair2,
  ProjPreInstr_SpazerSba_ClearProjPair4,
  ProjPreInstr_SpazerSba_ClearProjPair6,
};

void ProjPreInstr_SpazerSba(uint16 k) {
  int v1 = k >> 1;
  if ((projectile_dir[v1] & (0xF0 | kProjectileDir_Delete)) != 0) {
    kProjPreInstr_SpazerSba_FuncsA[v1](k);
  } else {
    int v2 = k >> 1;
    if (projectile_timers[v2]-- == 1) {
      projectile_timers[v2] = 4;
      SpawnProjectileTrail(k);
      k = projectile_index;
    }
    int v4 = k >> 1;
    Point16U pt = Projectile_SinLookup(projectile_variables[v4], projectile_x_speed[v4]);
    projectile_x_pos[v4] = pt.x + samus_x_pos;
    kProjPreInstr_SpazerSba_FuncsB[projectile_unk_A[v4] >> 1](k, pt.y);
    cooldown_timer = 2;
    flare_counter = 0;
  }
}

void ProjPreInstr_SpazerSba_ClearProjPair0(uint16 k) {  // 0x90DB57
  ClearProjectile(k);
  ClearProjectile(4);
}

void ProjPreInstr_SpazerSba_ClearProjPair2(uint16 k) {  // 0x90DB66
  ClearProjectile(k);
  ClearProjectile(6);
}

void ProjPreInstr_SpazerSba_ClearProjPair4(uint16 k) {  // 0x90DB75
  ClearProjectile(k);
  ClearProjectile(0);
}

void ProjPreInstr_SpazerSba_ClearProjPair6(uint16 k) {  // 0x90DB84
  ClearProjectile(k);
  ClearProjectile(2);
}

void ProjPreInstr_SpazerSba_Phase0_Circle(uint16 j, uint16 r22) {  // 0x90DB93
  static const int16 kProjPreInstr_SpazerSba_Yspeed[4] = { 2, -2, 2, -2 };

  int v1 = j >> 1;
  projectile_y_pos[v1] = r22 + samus_y_pos;
  uint16 v2 = (uint8)(LOBYTE(projectile_y_speed[v1]) + LOBYTE(projectile_variables[v1]));
  projectile_variables[v1] = v2;
  if (v2 == 128) {
    projectile_x_speed[v1] = 160;
    projectile_y_speed[v1] = kProjPreInstr_SpazerSba_Yspeed[v1];
    projectile_dir[v1] = kProjectileDir_UpFaceRight;
    projectile_unk_A[v1] = 2;
  }
}

void ProjPreInstr_SpazerSba_Phase2_FlyToPoint(uint16 j, uint16 r22) {  // 0x90DBCF
  static const int16 kSpazerProjectileYSpeed[4] = { -2, 2, -2, 2 };

  uint16 v1 = r22 + samus_y_pos - 114;
  int v2 = j >> 1;
  projectile_y_pos[v2] = v1;
  if (sign16(v1 - layer1_y_pos - 16)) {
    FireEndOfSpazerSba(j);
  } else {
    projectile_variables[v2] = (uint8)(LOBYTE(projectile_y_speed[v2]) + LOBYTE(projectile_variables[v2]));
    uint16 v3 = projectile_x_speed[v2] - 5;
    projectile_x_speed[v2] = v3;
    if (!v3) {
      projectile_y_speed[v2] = kSpazerProjectileYSpeed[v2];
      projectile_variables[v2] = (uint8)(projectile_variables[v2] + 0x80);
      projectile_unk_A[v2] = 4;
      if (!j)
        QueueSfx1_Max6(kSfx1_SpazerSbaEnd);
    }
  }
}

void ProjPreInstr_SpazerSba_Phase4_FlyFromPoint(uint16 j, uint16 r22) {  // 0x90DC30
  int v2;
  uint16 v3;

  uint16 v1 = r22 + samus_y_pos - 114;
  projectile_y_pos[j >> 1] = v1;
  if (sign16(v1 - layer1_y_pos - 16)
      || (v2 = j >> 1,
          projectile_variables[v2] = (uint8)(LOBYTE(projectile_y_speed[v2])
                                             + LOBYTE(projectile_variables[v2])),
          v3 = projectile_x_speed[v2] + 5,
          projectile_x_speed[v2] = v3,
          !sign16(v3 - 96))) {
    FireEndOfSpazerSba(j);
  }
}

void FireEndOfSpazerSba(uint16 j) {  // 0x90DC67
  static const int16 kFireEndOfSpazerSba_X_Position[4] = { 16, 16, -16, -16 };

  int v1 = j >> 1;
  projectile_x_pos[v1] += kFireEndOfSpazerSba_X_Position[v1];
  projectile_dir[v1] = kProjectileDir_DownFaceLeft;
  projectile_timers[v1] = 4;
  projectile_pre_instructions[v1] = FUNC16(ProjPreInstr_EndOfSpazerSba);
  if ((int16)(j - 4) < 0) {
    projectile_type[j >> 1] = kProjectileType_DontInteractWithSamus | kProjectileType_SpazerSbaMask | kProjectileType_Spazer;
    InitializeShinesparkEchoOrSpazerSba(j);
  }
}

void ProjPreInstr_EndOfSpazerSba(uint16 k) {  // 0x90DC9C
  int v1 = k >> 1;
  if ((projectile_dir[v1] & (0xF0 | kProjectileDir_Delete)) != 0)
    goto LABEL_2;
  if (projectile_timers[v1]-- == 1) {
    projectile_timers[v1] = 4;
    SpawnProjectileTrail(k);
    k = projectile_index;
  }
  int v3;
  v3 = k >> 1;
  uint16 v4;
  v4 = projectile_y_pos[v3] + 8;
  projectile_y_pos[v3] = v4;
  if (!sign16(v4 - layer1_y_pos - 248)) {
LABEL_2:
    ClearProjectile(k);
  } else {
    cooldown_timer = 2;
    flare_counter = 0;
  }
}

static Func_V *kHandleHudSpecificBehaviorAndProjs[28] = {  // 0x90DCDD
  HudSelectionHandler_Normal,
  HudSelectionHandler_Normal,
  HudSelectionHandler_Normal,
  HudSelectionHandler_JumpEtc,
  HudSelectionHandler_MorphBall,
  HudSelectionHandler_Normal,
  HudSelectionHandler_Normal,
  HudSelectionHandler_MorphBall,
  HudSelectionHandler_MorphBall,
  HudSelectionHandler_MorphBall,
  HudSelectionHandler_JumpEtc,
  HudSelectionHandler_Grappling,
  HudSelectionHandler_Grappling,
  HudSelectionHandler_JumpEtc,
  HudSelectionHandler_TurningAround,
  HudSelectionHandler_CrouchEtcTrans,
  HudSelectionHandler_Normal,
  HudSelectionHandler_MorphBall,
  HudSelectionHandler_MorphBall,
  HudSelectionHandler_MorphBall,
  HudSelectionHandler_JumpEtc,
  HudSelectionHandler_Normal,
  HudSelectionHandler_Grappling,
  HudSelectionHandler_TurningAround,
  HudSelectionHandler_TurningAround,
  HudSelectionHandler_JumpEtc,
  HudSelectionHandler_GrabbedByDraygon,
  HudSelectionHandler_JumpEtc,
};

void Samus_HandleHudSpecificBehaviorAndProjs(void) {
  if (samus_pose == kPose_00_FaceF_Powersuit
      || samus_pose == kPose_9B_FaceF_VariaGravitySuit
      || (Samus_HandleCooldown(),
          HandleSwitchingHudSelection(),
          kHandleHudSpecificBehaviorAndProjs[samus_movement_type](),
          !time_is_frozen_flag)) {
    HandleProjectile();
  }
}

void HudSelectionHandler_Normal(void) {  // 0x90DD3D
  static Func_V *const kHudSelectionHandler_Normal[7] = {
  HudSelectionHandler_NothingOrPowerBombs,
  HudSelectionHandler_MissilesOrSuperMissiles,
  HudSelectionHandler_MissilesOrSuperMissiles,
  HudSelectionHandler_NothingOrPowerBombs,
  HudSelectionHandler_Grappling,
  HudSelectionHandler_Xray,
  HudSelectionHandler_TurningAround,
  };
  uint16 v0;
  if (grapple_beam_function == FUNC16(GrappleBeamFunc_Inactive)) {
    if (time_is_frozen_flag)
      v0 = 10;
    else
      v0 = 2 * hud_item_index;
  } else {
    v0 = 8;
  }
  kHudSelectionHandler_Normal[v0 >> 1]();
}

void HudSelectionHandler_Grappling(void) {  // 0x90DD6F
  GrappleBeamHandler();
}

void HudSelectionHandler_TurningAround(void) {  // 0x90DD74
  if (new_projectile_direction_changed_pose) {
    HudSelectionHandler_Normal();
  } else if (grapple_beam_function != FUNC16(GrappleBeamFunc_Inactive)) {
    grapple_beam_function = FUNC16(GrappleBeamFunc_Cancel);
  }
}

void HudSelectionHandler_CrouchEtcTrans(void) {  // 0x90DD8C
  static const uint8 byte_90DDAA[12] = { 0, 0, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1 };
  if (!sign16(samus_pose - kPose_F1_FaceR_CrouchTrans_AimU))
    goto LABEL_4;
  if (!sign16(samus_pose - kPose_DB))
    return;
  if (byte_90DDAA[(uint16)(samus_pose - 53)]) {
    if (grapple_beam_function != FUNC16(GrappleBeamFunc_Inactive)) {
      grapple_beam_function = FUNC16(GrappleBeamFunc_Cancel);
      HudSelectionHandler_Normal();
    }
  } else {
LABEL_4:
    HudSelectionHandler_Normal();
  }
}

void HudSelectionHandler_JumpEtc(void) {  // 0x90DDB6
  if (grapple_beam_function != FUNC16(GrappleBeamFunc_Inactive)) {
    grapple_beam_function = FUNC16(GrappleBeamFunc_Cancel);
    HudSelectionHandler_Normal();
  }
}

void HudSelectionHandler_Xray(void) {  // 0x90DDC8
  if ((button_config_run_b & joypad1_lastkeys) != 0)
    XrayRunHandler();
  else
    HudSelectionHandler_NothingOrPowerBombs();
}

void HudSelectionHandler_GrabbedByDraygon(void) {  // 0x90DDD8
  if (samus_pose == (kPose_DB | kPose_04_FaceL_AimU))
    HudSelectionHandler_MorphBall();
  else
    HudSelectionHandler_Normal();
}

static Func_U8 *const kSamusHitInterrupts[28] = {  // 0x90DDE9
  Samus_HitInterrupt_Stand,
  Samus_HitInterrupt_Stand,
  Samus_HitInterrupt_Stand,
  Samus_HitInterrupt_Stand,
  Samus_HitInterrupt_Ball,
  Samus_HitInterrupt_Stand,
  Samus_HitInterrupt_Falling,
  Samus_HitInterrupt_Unused,
  Samus_HitInterrupt_Ball,
  Samus_HitInterrupt_Ball,
  Samus_HitInterrupt_KnockbackGrapple,
  Samus_HitInterrupt_Turning,
  Samus_HitInterrupt_Turning,
  Samus_HitInterrupt_Stand,
  Samus_HitInterrupt_Turning,
  Samus_HitInterrupt_Turning,
  Samus_HitInterrupt_Stand,
  Samus_HitInterrupt_Ball,
  Samus_HitInterrupt_Ball,
  Samus_HitInterrupt_Ball,
  Samus_HitInterrupt_Stand,
  Samus_HitInterrupt_Stand,
  Samus_HitInterrupt_KnockbackGrapple,
  Samus_HitInterrupt_Turning,
  Samus_HitInterrupt_Turning,
  Samus_HitInterrupt_Turning,
  Samus_HitInterrupt_Turning,
  Samus_HitInterrupt_Drained,
};

void Samus_HitInterruption(void) {
  if (samus_knockback_timer) {
    if (sign16(debug_invincibility - 7)) {
      if (!time_is_frozen_flag && !knockback_dir) {
        if (kSamusHitInterrupts[samus_movement_type]() & 1)
          samus_special_transgfx_index = 1;
      }
    } else {
      samus_invincibility_timer = 0;
      samus_knockback_timer = 0;
    }
  } else if (knockback_dir) {
    if (samus_movement_type == kMovementType_0A_KnockbackOrCrystalFlashEnding) {
      if (!sign16(flare_counter - 16))
        QueueSfx1_Max6(kSfx1_ResumeChargingBeam);
      if (samus_pose_x_dir == kSamusXDir_FaceLeft)
        samus_new_pose_transitional = kPose_2A_FaceL_Fall;
      else
        samus_new_pose_transitional = kPose_29_FaceR_Fall;
    } else {
      if (samus_hurt_switch_index == 3) {
        samus_hurt_switch_index = 8;
        return;
      }
      samus_new_pose_transitional = samus_pose;
    }
    samus_hurt_switch_index = 1;
  } else if (bomb_jump_dir) {
    SetupBombJump();
  }
}

uint8 Samus_HitInterrupt_Drained(void) {  // 0x90DEBA
  if (samus_pose == kPose_E8_FaceR_Drained_CrouchFalling || samus_pose == kPose_E9_FaceL_Drained_CrouchFalling) {
    samus_anim_frame_timer = 17;
    samus_anim_frame = 26;
  }
  samus_special_transgfx_index = 0;
  knockback_dir = 0;
  return 0;
}

uint8 Samus_HitInterrupt_KnockbackGrapple(void) {  // 0x90DEDD
  samus_special_transgfx_index = 0;
  return 0;
}

uint8 Samus_HitInterrupt_Turning(void) {  // 0x90DEE2
  samus_special_transgfx_index = 0;
  knockback_dir = 0;
  return 0;
}

uint8 Samus_HitInterrupt_Falling(void) {  // 0x90DEEA
  if (frame_handler_gamma != FUNC16(Samus_FrameHandlerGamma_SpecialFalling_Unused))
    return Samus_HitInterrupt_Stand();
  samus_special_transgfx_index = 0;
  knockback_dir = 0;
  return 0;
}

uint8 Samus_HitInterrupt_Stand(void) {  // 0x90DEFA
  if (samus_pose_x_dir == kSamusXDir_FaceLeft)
    samus_new_pose_interrupted = 84;
  else
    samus_new_pose_interrupted = 83;
  return 1;
}

uint8 Samus_HitInterrupt_Ball(void) {  // 0x90DF15
  samus_new_pose_interrupted = samus_pose;
  return 1;
}

uint8 Samus_HitInterrupt_Unused(void) {  // 0x90DF1D
  if (samus_pose_x_dir == kSamusXDir_FaceLeft)
    samus_new_pose_interrupted = 52;
  else
    samus_new_pose_interrupted = 51;
  return 1;
}

static Func_V *const kSamus_MoveHandler_Knockback[6] = {  // 0x90DF38
  Samus_MoveHandler_Invalid,
  Samus_MoveHandler_Knockback_Up,
  Samus_MoveHandler_Knockback_Up,
  Samus_MoveHandler_Knockback_StraightUp_Unused,
  Samus_MoveHandler_Knockback_Down,
  Samus_MoveHandler_Knockback_Down,
};

void Samus_MoveHandler_Knockback(void) {
  kSamus_MoveHandler_Knockback[knockback_dir]();
  input_to_pose_calc = 0;
}

void Samus_MoveHandler_Invalid(void) {  // 0x90DF50
  InvalidInterrupt_Crash();
}

void Samus_MoveHandler_Knockback_Up(void) {  // 0x90DF53
  Samus_BombJumpRisingXMovement_();
  Samus_MoveY_WithSpeedCalc();
  Samus_HandleKnockbackVerticalColl();
}

void Samus_MoveHandler_Knockback_StraightUp_Unused(void) {  // 0x90DF5D
  Samus_MoveY_WithSpeedCalc();
  Samus_HandleKnockbackVerticalColl();
}

void Samus_MoveHandler_Knockback_Down(void) {  // 0x90DF64
  Samus_BombJumpRisingXMovement_();
  Samus_Move_NoSpeedCalc_Y();
  Samus_HandleKnockbackVerticalColl();
}

void Samus_HandleKnockbackVerticalColl(void) {  // 0x90DF6E
  if (samus_collision_flag) {
    samus_x_accel_mode = 0;
    samus_collides_with_solid_enemy = 0;
    samus_is_falling_flag = 0;
    UNUSED_word_7E0B1A = 0;
    UNUSED_word_7E0B2A = 0;
    samus_y_subspeed = 0;
    samus_y_speed = 0;
    samus_y_dir = 0;
    UNUSED_word_7E0B38 = 0;
    samus_x_base_speed = 0;
    samus_x_base_subspeed = 0;
    Samus_AlignBottomWithPrevPose();
  }
}

static Func_U8 *const kSetupBombJump[28] = {  // 0x90DF99
  SetupBombJump_Stand_Crouch,
  SetupBombJump_Run_Fall_Moonwalk_WallJump_RanIntoWall_Grapple,
  SetupBombJump_Jump_TurnAround_DamageBoost_Transition,
  SetupBombJump_Jump_TurnAround_DamageBoost_Transition,
  SetupBombJump_Morphed_Knockback_CrystalFlash,
  SetupBombJump_Stand_Crouch,
  SetupBombJump_Run_Fall_Moonwalk_WallJump_RanIntoWall_Grapple,
  SetupBombJump_Morphed_Knockback_CrystalFlash,
  SetupBombJump_Morphed_Knockback_CrystalFlash,
  SetupBombJump_Morphed_Knockback_CrystalFlash,
  SetupBombJump_Morphed_Knockback_CrystalFlash,
  SetupBombJump_Run_Fall_Moonwalk_WallJump_RanIntoWall_Grapple,
  SetupBombJump_Run_Fall_Moonwalk_WallJump_RanIntoWall_Grapple,
  SetupBombJump_Run_Fall_Moonwalk_WallJump_RanIntoWall_Grapple,
  SetupBombJump_Jump_TurnAround_DamageBoost_Transition,
  SetupBombJump_Jump_TurnAround_DamageBoost_Transition,
  SetupBombJump_Run_Fall_Moonwalk_WallJump_RanIntoWall_Grapple,
  SetupBombJump_Morphed_Knockback_CrystalFlash,
  SetupBombJump_Morphed_Knockback_CrystalFlash,
  SetupBombJump_Morphed_Knockback_CrystalFlash,
  SetupBombJump_Run_Fall_Moonwalk_WallJump_RanIntoWall_Grapple,
  SetupBombJump_Run_Fall_Moonwalk_WallJump_RanIntoWall_Grapple,
  SetupBombJump_Run_Fall_Moonwalk_WallJump_RanIntoWall_Grapple,
  SetupBombJump_Jump_TurnAround_DamageBoost_Transition,
  SetupBombJump_Jump_TurnAround_DamageBoost_Transition,
  SetupBombJump_Jump_TurnAround_DamageBoost_Transition,
  SetupBombJump_Grabbed_Shinespark_CrystalFlash_Drained_MBAttack,
  SetupBombJump_Grabbed_Shinespark_CrystalFlash_Drained_MBAttack,
};
void SetupBombJump(void) {
  if (!HIBYTE(bomb_jump_dir)) {
    if (kSetupBombJump[samus_movement_type]() & 1)
      samus_special_transgfx_index = 3;
  }
}

uint8 SetupBombJump_Stand_Crouch(void) {  // 0x90DFED
  if (!time_is_frozen_flag)
    return SetupBombJump_Run_Fall_Moonwalk_WallJump_RanIntoWall_Grapple();
  bomb_jump_dir = 0;
  return 0;
}

uint8 SetupBombJump_Run_Fall_Moonwalk_WallJump_RanIntoWall_Grapple(void) {  // 0x90DFF7
  if (samus_pose_x_dir == kSamusXDir_FaceLeft)
    samus_new_pose_interrupted = kPose_52_FaceL_Jump_NoAim_MoveF;
  else
    samus_new_pose_interrupted = kPose_51_FaceR_Jump_NoAim_MoveF;
  return 1;
}

uint8 SetupBombJump_Morphed_Knockback_CrystalFlash(void) {  // 0x90E012
  samus_new_pose_interrupted = samus_pose;
  return 1;
}

uint8 SetupBombJump_Jump_TurnAround_DamageBoost_Transition(void) {  // 0x90E01A
  samus_input_handler = FUNC16(Samus_InputHandler_Normal);
  return SetupBombJump_Grabbed_Shinespark_CrystalFlash_Drained_MBAttack();
}

uint8 SetupBombJump_Grabbed_Shinespark_CrystalFlash_Drained_MBAttack(void) {  // 0x90E020
  bomb_jump_dir = 0;
  return 0;
}

void Samus_MoveHandler_BombJumpStart(void) {  // 0x90E025
  Samus_InitBombJump();
  samus_movement_handler = FUNC16(Samus_MoveHandler_BombJumpMain);
  input_to_pose_calc = 0;
}

static Func_V *const kSamus_MoveHandler_BombJumpMain[4] = {  // 0x90E032
  Samus_MoveHandler_Invalid,
  Samus_MoveHandler_HorizontalBombJump,
  Samus_MoveHandler_VerticalBombJump,
  Samus_MoveHandler_HorizontalBombJump,
};

void Samus_MoveHandler_BombJumpMain(void) {
  if (bomb_jump_dir)
    kSamus_MoveHandler_BombJumpMain[(uint8)bomb_jump_dir]();
  else
    Samus_MoveHandler_EndBombJump();
}

void Samus_MoveHandler_HorizontalBombJump(void) {  // 0x90E04C
  Samus_BombJumpRisingXMovement_();
  Samus_BombJumpRisingYMovement_();
  if (samus_y_dir == 2 || (Samus_MoveY_WithSpeedCalc(), samus_collision_flag))
    Samus_MoveHandler_EndBombJump();
}

void Samus_MoveHandler_VerticalBombJump(void) {  // 0x90E066
  Samus_BombJumpRisingYMovement_();
  if (samus_y_dir == 2 || (Samus_MoveY_WithSpeedCalc(), samus_collision_flag))
    Samus_MoveHandler_EndBombJump();
}

void Samus_MoveHandler_EndBombJump(void) {  // 0x90E07D
  samus_movement_handler = FUNC16(Samus_MovementHandler_Normal);
  if (samus_input_handler != FUNC16(Samus_InputHandler_Demo))
    samus_input_handler = FUNC16(Samus_InputHandler_Normal);
  bomb_jump_dir = 0;
}

void CallFrameHandlerGamma(uint32 ea) {
  switch (ea) {
  case fnSamus_FrameHandlerGamma_UnlockSamusFromDrained: Samus_FrameHandlerGamma_UnlockSamusFromDrained(); return;
  case fnSamus_FrameHandlerGamma_KeepSamusLockedFromDrained: Samus_FrameHandlerGamma_KeepSamusLockedFromDrained(); return;
  case fnSamus_FrameHandlerGamma_HandleTimer: Samus_FrameHandlerGamma_HandleTimer(); return;
  case fnSamus_FrameHandlerGamma_DrawTimer: Samus_FrameHandlerGamma_DrawTimer(); return;
  case fnSamus_FrameHandlerGamma_PushOutOfRidleysWay: Samus_FrameHandlerGamma_PushOutOfRidleysWay(); return;
  case fnSamus_FrameHandlerGamma_PushingOutOfRidleysWay: Samus_FrameHandlerGamma_PushingOutOfRidleysWay(); return;
  case fnSamus_FrameHandlerGamma_GrabbedByDraygon: Samus_FrameHandlerGamma_GrabbedByDraygon(); return;
  case fnnullsub_151: return;
  case fnSamus_FrameHandlerGamma_PushMorphedSamusOutOfRidleysWay_Unused: Samus_FrameHandlerGamma_PushMorphedSamusOutOfRidleysWay_Unused(); return;
  case fnSamus_FrameHandlerGamma_SpecialFalling_Unused: Samus_FrameHandlerGamma_SpecialFalling_Unused(); return;
  case fnnullsub_152: return;
  default: Unreachable();
  }
}
void RunFrameHandlerGamma(void) {  // 0x90E097
  CallFrameHandlerGamma(frame_handler_gamma | 0x900000);
}

void Samus_FrameHandlerGamma_UnlockSamusFromDrained(void) {  // 0x90E09B
  if (samus_pose == kPose_E9_FaceL_Drained_CrouchFalling
      && !sign16(samus_anim_frame - 8)
      && (joypad1_newkeys & kButton_Up) != 0) {
    samus_anim_frame_timer = 1;
    samus_anim_frame = 13;
    frame_handler_gamma = FUNC16(nullsub_152);
  }
}

void Samus_FrameHandlerGamma_KeepSamusLockedFromDrained(void) {  // 0x90E0C5
  if (!sign16(samus_anim_frame - 8) && sign16(samus_anim_frame - 12) && (joypad1_newkeys & kButton_Up) != 0) {
    samus_anim_frame_timer = 1;
    samus_anim_frame = 18;
  }
}

void Samus_FrameHandlerGamma_HandleTimer(void) {  // 0x90E0E6
  if (ProcessTimer() & 1) {
    game_state = kGameState_35_TimeUp;
    // Make screen white
    memset7E(target_palettes.pal, 0x7FFF, sizeof(Palettes));
    frame_handler_gamma = FUNC16(Samus_FrameHandlerGamma_DrawTimer);
    DisablePaletteFx();
  }
  if (timer_status != kTimerStatus_0_Inactive)
    DrawTimer();
}

void Samus_FrameHandlerGamma_DrawTimer(void) {  // 0x90E114
  DrawTimer();
}

void Samus_SetPushedOutOfCeresRidley(void) {  // 0x90E119
  samus_movement_handler = FUNC16(nullsub_152);
  frame_handler_gamma = FUNC16(Samus_FrameHandlerGamma_PushOutOfRidleysWay);
}

void Samus_FrameHandlerGamma_PushOutOfRidleysWay(void) {  // 0x90E12E
  if (samus_pose_x_dir == kSamusXDir_FaceLeft)
    samus_pose = kPose_54_FaceL_Knockback;
  else
    samus_pose = kPose_53_FaceR_Knockback;
  SamusFunc_F433();
  Samus_SetAnimationFrameIfPoseChanged();
  samus_last_different_pose = samus_prev_pose;
  *(uint16 *)&samus_last_different_pose_x_dir = *(uint16 *)&samus_prev_pose_x_dir;
  samus_prev_pose = samus_pose;
  *(uint16 *)&samus_prev_pose_x_dir = *(uint16 *)&samus_pose_x_dir;
  samus_y_pos -= 21 - samus_y_radius;
  if (sign16(samus_x_pos - layer1_x_pos - 128))
    samus_push_direction = 1;
  else
    samus_push_direction = 2;
  samus_y_speed = 5;
  samus_y_subspeed = 0;
  bomb_jump_dir = 0;
  frame_handler_gamma = FUNC16(Samus_FrameHandlerGamma_PushingOutOfRidleysWay);
  samus_new_pose = -1;
  samus_new_pose_interrupted = -1;
  samus_new_pose_transitional = -1;
  samus_new_pose_command = 0;
  samus_special_transgfx_index = 0;
  samus_hurt_switch_index = 0;
  ProcessTimer();
  if (timer_status != kTimerStatus_0_Inactive)
    DrawTimer();
}

void Samus_FrameHandlerGamma_PushingOutOfRidleysWay(void) {  // 0x90E1C8
  static Func_V *const kSamus_PushOutOfRidleysWay_Func[3] = {
    0,
    Samus_PushOutOfRidleysWay_Leftwards,
    Samus_PushOutOfRidleysWay_Rightwards,
  };

  if (samus_new_pose == kPose_4F_FaceL_Dmgboost || samus_new_pose == kPose_50_FaceR_Dmgboost) {
    samus_new_pose = -1;
    samus_new_pose_command = 0;
  }
  kSamus_PushOutOfRidleysWay_Func[samus_push_direction]();
  input_to_pose_calc = 0;
  ProcessTimer();
  if (timer_status != kTimerStatus_0_Inactive)
    DrawTimer();
}

void Samus_PushOutOfRidleysWay_Leftwards(void) {  // 0x90E1FD
  Samus_BombJumpFallingXMovement_();
  if (samus_collision_flag) {
    samus_movement_handler = FUNC16(Samus_MovementHandler_Normal);
    frame_handler_gamma = FUNC16(Samus_FrameHandlerGamma_HandleTimer);
    samus_push_direction = 0;
    Samus_HandleKnockbackVerticalColl();
  } else {
    Samus_BombJumpFallingYMovement_();
  }
}
void Samus_PushOutOfRidleysWay_Rightwards(void) {  // 0x90E21C
  Samus_BombJumpFallingXMovement_();
  if (samus_collision_flag) {
    samus_movement_handler = FUNC16(Samus_MovementHandler_Normal);
    frame_handler_gamma = FUNC16(Samus_FrameHandlerGamma_HandleTimer);
    samus_push_direction = 0;
    Samus_HandleKnockbackVerticalColl();
  } else {
    Samus_BombJumpFallingYMovement_();
  }
}
void Samus_FrameHandlerGamma_GrabbedByDraygon(void) {  // 0x90E2A1
  if (grapple_beam_function == FUNC16(GrappleBeamFunc_ConnectedLockedInPlace)) {
    samus_new_pose = -1;
    samus_new_pose_command = 0;
  }
  if ((joypad1_newkeys & (kButton_Up | kButton_Down | kButton_Left | kButton_Right)) != 0
      && (joypad1_newkeys & (kButton_Up | kButton_Down | kButton_Left | kButton_Right)) != suit_pickup_light_beam_pos) {
    suit_pickup_light_beam_pos = joypad1_newkeys & (kButton_Up | kButton_Down | kButton_Left | kButton_Right);
    if ((int16)(++substate - 60) >= 0)
      Samus_ReleaseFromDraygon();
  }
}

void Samus_SetGrabbedByDraygonPose(uint16 a) {  // 0x90E23B
  if ((a & 1) != 0)
    samus_pose = kPose_EC_FaceR_Draygon_NoMove_NoAim;
  else
    samus_pose = kPose_BA_FaceL_Draygon_NoMove_NoAim;
  SamusFunc_F433();
  Samus_SetAnimationFrameIfPoseChanged();
  frame_handler_gamma = FUNC16(Samus_FrameHandlerGamma_GrabbedByDraygon);
  samus_movement_handler = FUNC16(nullsub_152);
  substate = 0;
  suit_pickup_light_beam_pos = 0;
  *(uint16 *)&suit_pickup_color_math_R = 0;
  samus_last_different_pose = samus_prev_pose;
  *(uint16 *)&samus_last_different_pose_x_dir = *(uint16 *)&samus_prev_pose_x_dir;
  samus_prev_pose = samus_pose;
  *(uint16 *)&samus_prev_pose_x_dir = *(uint16 *)&samus_pose_x_dir;
  samus_new_pose = -1;
  samus_new_pose_interrupted = -1;
  samus_new_pose_transitional = -1;
  samus_new_pose_command = 0;
  samus_special_transgfx_index = 0;
  samus_hurt_switch_index = 0;
}

void Samus_ReleaseFromDraygon_(void) {  // 0x90E2D4
  Samus_ReleaseFromDraygon();
}

void Samus_ReleaseFromDraygon(void) {  // 0x90E2DE
  if (samus_pose_x_dir == kSamusXDir_FaceLeft)
    samus_pose = kPose_02_FaceL_Normal;
  else
    samus_pose = kPose_01_FaceR_Normal;
  SamusFunc_F433();
  Samus_SetAnimationFrameIfPoseChanged();
  samus_movement_handler = FUNC16(Samus_MovementHandler_Normal);
  frame_handler_gamma = FUNC16(nullsub_152);
  samus_last_different_pose = samus_prev_pose;
  *(uint16 *)&samus_last_different_pose_x_dir = *(uint16 *)&samus_prev_pose_x_dir;
  samus_prev_pose = samus_pose;
  *(uint16 *)&samus_prev_pose_x_dir = *(uint16 *)&samus_pose_x_dir;
  samus_x_base_speed = 0;
  samus_x_base_subspeed = 0;
  samus_new_pose = -1;
  samus_new_pose_interrupted = -1;
  samus_new_pose_transitional = -1;
  samus_new_pose_command = 0;
  samus_special_transgfx_index = 0;
  samus_hurt_switch_index = 0;
  samus_y_speed = 0;
  samus_y_subspeed = 0;
  samus_y_dir = 0;
  used_for_ball_bounce_on_landing = 0;
  samus_x_accel_mode = 0;
  samus_grapple_flags = samus_grapple_flags & 0xFFFD | 2;
}

void Samus_FrameHandlerGamma_PushMorphedSamusOutOfRidleysWay_Unused(void) {  // 0x90E3A3
  Samus_BombJumpFallingXMovement_();
  if (samus_collision_flag || (Samus_BombJumpFallingYMovement_(), samus_collision_flag)) {
    samus_movement_handler = FUNC16(Samus_MovementHandler_Normal);
    frame_handler_gamma = FUNC16(nullsub_152);
    samus_push_direction = 0;
    Samus_HandleKnockbackVerticalColl();
    samus_new_pose_interrupted = 65;
    samus_special_transgfx_index = 0;
  }
}

void Samus_ClearSpecialFalling_Unused(void) {  // 0x90E400
  samus_y_subspeed = 0;
  samus_y_speed = 0;
  samus_movement_handler = FUNC16(Samus_MovementHandler_Normal);
  frame_handler_gamma = FUNC16(nullsub_152);
}

void Samus_FrameHandlerGamma_SpecialFalling_Unused(void) {  // 0x90E41B
  if (sign16(samus_y_speed - 5))
    AddToHiLo(&samus_y_speed, &samus_y_subspeed, __PAIR32__(samus_y_accel, samus_y_subaccel));
  if ((samus_pose == kPose_29_FaceR_Fall || samus_pose == kPose_2A_FaceL_Fall
       || samus_pose == kPose_67_FaceR_Fall_Gun || samus_pose == kPose_68_FaceL_Fall_Gun)
      && !sign16(samus_y_speed - 5)) {
    samus_anim_frame_timer = 16;
    samus_anim_frame = 4;
  }
}

static int32 Samus_ClampSpeed(int32 amt) {
  uint16 r18 = amt >> 16, r20 = amt;
  int16 v0 = r18;
  if (v0 < 0) {
    if (sign16(v0 + 15))
      r18 = -15;
  } else if (!sign16(v0 - 16)) {
    r18 = 15;
  }
  return r18 << 16 | r20;
}

int32 Samus_CalcDisplacementMoveLeft(int32 amt) {  // 0x90E464
  amt = Samus_CalcSpeed_X(amt);
  samus_collision_direction = 0;
  amt = __PAIR32__(extra_samus_x_displacement, extra_samus_x_subdisplacement) - amt;
  return Samus_ClampSpeed(amt);
}

int32 Samus_CalcDisplacementMoveRight(int32 amt) {  // 0x90E4AD
  amt = Samus_CalcSpeed_X(amt);
  samus_collision_direction = 1;
  amt += __PAIR32__(extra_samus_x_displacement, extra_samus_x_subdisplacement);
  return Samus_ClampSpeed(amt);
}

uint32 Samus_CalcSpeed_X(uint32 amt) {  // 0x90E4E6
  amt += __PAIR32__(samus_x_extra_run_speed, samus_x_extra_run_subspeed);
  amt >>= (samus_x_speed_divisor <= 4) ? samus_x_speed_divisor : 4;
  SetHiLo(&samus_total_x_speed, &samus_total_x_subspeed, amt);
  return amt;
}

void Samus_ClearXSpeedIfColl(void) {  // 0x90E5CE
  if (samus_collision_flag) {
    if (samus_collision_direction)
      samus_collides_with_solid_enemy = 8;
    else
      samus_collides_with_solid_enemy = 4;
    Samus_CancelSpeedBoost();
    samus_x_extra_run_speed = 0;
    samus_x_extra_run_subspeed = 0;
    samus_x_base_speed = 0;
    samus_x_base_subspeed = 0;
    samus_x_accel_mode = 0;
  } else {
    input_to_pose_calc = 0;
    samus_collides_with_solid_enemy = 0;
  }
}

void Samus_MoveUp_SetPoseCalcInput(void) {  // 0x90E606
  if (samus_collision_flag)
    input_to_pose_calc = 4;
  else
    input_to_pose_calc = 0;
}

static const uint8 kSamus_MoveDown_SetPoseCalcInput_Tab0[28] = {  // 0x90E61B
  0, 0, 4, 4, 1, 0, 4, 2,
  4, 4, 0, 0, 0, 0, 4, 4,
  0, 3, 4, 4, 4, 0, 4, 4,
  4, 4, 4, 4,
};
static const uint8 kSamus_MoveDown_SetPoseCalcInput_Tab1[28] = {
  4, 4, 0, 0, 4, 4, 0, 4,
  1, 2, 0, 4, 4, 0, 4, 4,
  4, 4, 3, 3, 0, 4, 4, 4,
  4, 0, 4, 4,
};
void Samus_MoveDown_SetPoseCalcInput(void) {
  if (samus_collision_flag) {
    input_to_pose_calc = 1;
    HIBYTE(input_to_pose_calc) = kSamus_MoveDown_SetPoseCalcInput_Tab1[samus_movement_type];
  } else if ((uint8)input_to_pose_calc != 5) {
    input_to_pose_calc = 2;
    HIBYTE(input_to_pose_calc) = kSamus_MoveDown_SetPoseCalcInput_Tab0[samus_movement_type];
  }
}

void CallFrameHandlerAlfa(uint32 ea) {
  switch (ea) {
  case fnSamus_FrameHandlerAlfa_Normal: Samus_FrameHandlerAlfa_Normal(); return;
  case fnSamus_FrameHandlerAlfa_Demo: Samus_FrameHandlerAlfa_Demo(); return;
  case fnSamus_FrameHandlerAlfa_SamusLocked: Samus_FrameHandlerAlfa_SamusLocked(); return;
  case fnSamus_FrameHandlerBeta_DoNothing: return;
  default: Unreachable();
  }
}
void HandleControllerInputForGamePhysics(void) {  // 0x90E692
  CallFrameHandlerAlfa(frame_handler_alfa | 0x900000);
}

void Samus_FrameHandlerAlfa_Normal(void) {  // 0x90E695
  samus_new_pose = -1;
  samus_new_pose_interrupted = -1;
  samus_new_pose_transitional = -1;
  samus_new_pose_command = 0;
  samus_special_transgfx_index = 0;
  samus_hurt_switch_index = 0;
  Samus_SetRadius();
  Samus_CallInputHandler();
  Samus_UpdateSuitPaletteIndex();
  Samus_DetermineAccel_Y();
  BlockInsideDetection();
  Samus_HandleHudSpecificBehaviorAndProjs();
  Samus_Func10();
}

void Samus_FrameHandlerAlfa_Demo(void) {  // 0x90E6C9
  samus_new_pose = -1;
  samus_new_pose_interrupted = -1;
  samus_new_pose_transitional = -1;
  samus_new_pose_command = 0;
  samus_special_transgfx_index = 0;
  samus_hurt_switch_index = 0;
  controller1_input_for_demo = joypad1_lastkeys;
  controller1_new_input_for_demo = joypad1_newkeys;
  demo_backup_prev_controller_input = joypad1_input_samusfilter;
  demo_backup_prev_controller_input_new = joypad1_newinput_samusfilter;
  Samus_SetRadius();
  Samus_UpdateSuitPaletteIndex();
  Samus_CallInputHandler();
  Samus_DetermineAccel_Y();
  BlockInsideDetection();
  Samus_HandleHudSpecificBehaviorAndProjs();
  Samus_Func10();
}

void Samus_FrameHandlerAlfa_SamusLocked(void) {  // 0x90E713
  HandleProjectile();
  Samus_Func10();
}

void CallFrameHandlerBeta(uint32 ea) {
  switch (ea) {
  case fnSamus_FrameHandlerBeta_Normal: Samus_FrameHandlerBeta_Normal(); return;
  case fnSamus_FrameHandlerBeta_Debug: Samus_FrameHandlerBeta_Debug(); return;
  case fnSamus_FrameHandlerBeta_TitleDemo: Samus_FrameHandlerBeta_TitleDemo(); return;
  case fnSamus_FrameHandlerBeta_IntroDemo: Samus_FrameHandlerBeta_IntroDemo(); return;
  case fnSamus_FrameHandlerBeta_SamusAppears: Samus_FrameHandlerBeta_SamusAppears(); return;
  case fnSamus_FrameHandlerBeta_Ceres: Samus_FrameHandlerBeta_Ceres(); return;
  case fnSamus_FrameHandlerBeta_DoNothing: return;
  case fnSamus_FrameHandlerBeta_SamusLockedToStation: return;
  case fnSamus_FrameHandlerBeta_SamusBeingDrained: return;
  case fnSamus_FrameHandlerBeta_SamusLocked: Samus_FrameHandlerBeta_SamusLocked(); return;
  case fnSamus_FrameHandlerBeta_RidingElevator: Samus_FrameHandlerBeta_RidingElevator(); return;
  case fnSamus_FrameHandlerBeta_EnterExitGunship: Samus_FrameHandlerBeta_EnterExitGunship(); return;
  default: Unreachable();
  }
}

void HandleSamusMovementAndPause(void) {  // 0x90E722
  CallFrameHandlerBeta(frame_handler_beta | 0x900000);
}

void Samus_FrameHandlerBeta_Normal(void) {  // 0x90E725
  samus_contact_damage_index = kSamusContactDamageIndex_0_Normal;
  RunSamusMovementHandler();
  UpdateMinimap();
  RunFrameHandlerGamma();
  Samus_Animate();
  Samus_HitInterruption();
  Samus_HandleTransFromBlockColl();
  Samus_HandleTransitions();
  Samus_HandlePalette();
  Samus_HandlePeriodicDamage();
  Samus_PauseCheck();
  Samus_LowHealthCheck_();
}

void HandleSamusPlacementModeToggles(void) {  // 0x90E786
  if ((joypad2_new_keys & 0x8000) == 0) {
    if (!debug_flag && (joypad2_new_keys & 0x80) != 0) {
      DisableEprojs();
      time_is_frozen_flag = 1;
      frame_handler_alfa = FUNC16(Samus_FrameHandlerBeta_DoNothing);
      frame_handler_beta = FUNC16(Samus_FrameHandlerBeta_Debug);
    }
  } else if (debug_flag) {
    samus_draw_handler = FUNC16(nullsub_152);
    debug_flag = 0;
  } else {
    debug_flag = 1;
    samus_draw_handler = FUNC16(SamusDrawHandler_Default);
  }
}

void Samus_FrameHandlerBeta_Debug(void) {  // 0x90E7D2
  if ((joypad2_new_keys & 0x80) != 0) {
    frame_handler_alfa = FUNC16(Samus_FrameHandlerAlfa_Normal);
    frame_handler_beta = FUNC16(Samus_FrameHandlerBeta_Normal);
    EnableEprojs();
    time_is_frozen_flag = 0;
  }
}

void Samus_FrameHandlerBeta_TitleDemo(void) {  // 0x90E7F5
  samus_contact_damage_index = kSamusContactDamageIndex_0_Normal;
  RunSamusMovementHandler();
  UpdateMinimap();
  Samus_Animate();
  Samus_HitInterruption();
  Samus_HandleTransFromBlockColl();
  Samus_HandleTransitions();
  Samus_HandlePalette();
  joypad1_lastkeys = controller1_input_for_demo;
  joypad1_newkeys = controller1_new_input_for_demo;
  joypad1_input_samusfilter = demo_backup_prev_controller_input;
  joypad1_newinput_samusfilter = demo_backup_prev_controller_input_new;
}

void Samus_FrameHandlerBeta_IntroDemo(void) {  // 0x90E833
  samus_contact_damage_index = kSamusContactDamageIndex_0_Normal;
  RunSamusMovementHandler();
  Samus_Animate();
  Samus_HitInterruption();
  Samus_HandleTransFromBlockColl();
  Samus_HandleTransitions();
  Samus_HandlePalette();
  joypad1_lastkeys = controller1_input_for_demo;
  joypad1_newkeys = controller1_new_input_for_demo;
  joypad1_input_samusfilter = demo_backup_prev_controller_input;
  joypad1_newinput_samusfilter = demo_backup_prev_controller_input_new;
}

void Samus_FrameHandlerBeta_SamusAppears(void) {  // 0x90E86A
  Samus_SetRadius();
  UpdateMinimap();
  Samus_Animate();
  elevator_status = kElevatorStatus_Inactive;
  samus_prev_y_pos = samus_y_pos;
  if (PlaySamusFanfare() & 1) {
    if (sign16(debug_invincibility - 7) || (joypad2_last & 0x8000) == 0)
      debug_invincibility = 0;
    frame_handler_alfa = FUNC16(Samus_FrameHandlerAlfa_Normal);
    frame_handler_beta = FUNC16(Samus_FrameHandlerBeta_Normal);
  }
}

void Samus_FrameHandlerBeta_Ceres(void) {  // 0x90E8AA
  Samus_FrameHandlerBeta_Normal();
  if (frame_handler_gamma == FUNC16(Samus_FrameHandlerGamma_DrawTimer) && game_state != kGameState_35_TimeUp)
    game_state = kGameState_35_TimeUp;
}

void Samus_FrameHandlerBeta_SamusLocked(void) {  // 0x90E8DC
  samus_contact_damage_index = kSamusContactDamageIndex_0_Normal;
  UpdateMinimap();
}

void Samus_FrameHandlerBeta_RidingElevator(void) {  // 0x90E8EC
  samus_contact_damage_index = kSamusContactDamageIndex_0_Normal;
  RunSamusMovementHandler();
  UpdateMinimap();
  Samus_Animate();
}

void Samus_FrameHandlerBeta_EnterExitGunship(void) {  // 0x90E902
  Samus_LowHealthCheck_();
}

void CallSamusInputHandler(uint32 ea) {
  switch (ea) {
  case fnnullsub_152: return;
  case fnSamus_InputHandler_Normal: Samus_InputHandler_Normal(); return;
  case fnSamus_InputHandler_Xray: Samus_InputHandler_Xray(); return;
  case fnSamus_InputHandler_Demo: Samus_InputHandler_Demo(); return;
  case fnSamus_InputHandler_AutoJump: Samus_InputHandler_AutoJump(); return;
  default: Unreachable();
  }
}

void Samus_CallInputHandler(void) {  // 0x90E90F
  CallSamusInputHandler(samus_input_handler | 0x900000);
}

void Samus_InputHandler_Normal(void) {  // 0x90E913
  Samus_InputHandler();
}

void Samus_InputHandler_Xray(void) {  // 0x90E918
  XraySamusPostInputHandler();
}

void Samus_InputHandler_Demo(void) {  // 0x90E91D
  DemoObjectInputHandler();
  Samus_InputHandler();
}

void Samus_InputHandler_AutoJump(void) {  // 0x90E926
  uint16 v0 = joypad1_newkeys;
  if (autojump_timer && sign16(autojump_timer - 9)) {
    joypad1_newkeys |= button_config_jump_a;
    autojump_timer = 0;
  }
  Samus_InputHandler();
  joypad1_newkeys = v0;
  samus_input_handler = FUNC16(Samus_InputHandler_Normal);
}

void CallSamusMovementHandler(uint32 ea) {
  switch (ea) {
  case fnSamus_MovementHandler_ReleaseFromGrapple: Samus_MovementHandler_ReleaseFromGrapple(); return;
  case fnSamus_MovementHandler_DrainedCrouching: Samus_MovementHandler_DrainedCrouching(); return;
  case fnSamus_MovementHandler_Normal: Samus_MovementHandler_Normal(); return;
  case fnSamus_MovementHandler_ShinesparkWindup: Samus_MovementHandler_ShinesparkWindup(); return;
  case fnSamus_MovementHandler_VerticalShinespark: Samus_MovementHandler_VerticalShinespark(); return;
  case fnSamus_MovementHandler_DiagonalShinespark: Samus_MovementHandler_DiagonalShinespark(); return;
  case fnSamus_MovementHandler_HorizontalShinespark: Samus_MovementHandler_HorizontalShinespark(); return;
  case fnSamus_MovementHandler_ShinesparkCrash_EchoCircle: Samus_MovementHandler_ShinesparkCrash_EchoCircle(); return;
  case fnSamus_MovementHandler_ShinesparkCrash_EchoCircle_Phase0: Samus_MovementHandler_ShinesparkCrash_EchoCircle_Phase0(); return;
  case fnSamus_MovementHandler_ShinesparkCrash_EchoCircle_Phase1: Samus_MovementHandler_ShinesparkCrash_EchoCircle_Phase1(); return;
  case fnSamus_MovementHandler_ShinesparkCrash_EchoCircle_Phase2: Samus_MovementHandler_ShinesparkCrash_EchoCircle_Phase2(); return;
  case fnSamus_MovementHandler_ShinesparkCrash_EchoCircle_Finish: Samus_MovementHandler_ShinesparkCrash_EchoCircle_Finish(); return;
  case fnSamus_MovementHandler_ShinesparkCrash_Finish: Samus_MovementHandler_ShinesparkCrash_Finish(); return;
  case fnSamusMoveHandler_CrystalFlashStart: SamusMoveHandler_CrystalFlashStart(); return;
  case fnSamusMoveHandler_CrystalFlashMain: SamusMoveHandler_CrystalFlashMain(); return;
  case fnSamusMoveHandler_CrystalFlashFinish: SamusMoveHandler_CrystalFlashFinish(); return;
  case fnSamus_MoveHandler_Knockback: Samus_MoveHandler_Knockback(); return;
  case fnSamus_MoveHandler_Knockback_0: Samus_MoveHandler_Invalid(); return;
  case fnSamus_MoveHandler_Knockback_Up: Samus_MoveHandler_Knockback_Up(); return;
  case fnSamus_MoveHandler_Knockback_3: Samus_MoveHandler_Knockback_StraightUp_Unused(); return;
  case fnSamus_MoveHandler_Knockback_Down: Samus_MoveHandler_Knockback_Down(); return;
  case fnSamus_MoveHandler_BombJumpStart: Samus_MoveHandler_BombJumpStart(); return;
  case fnSamus_MoveHandler_BombJumpMain: Samus_MoveHandler_BombJumpMain(); return;
  case fnSamus_MoveHandler_BombJumpFunc1: Samus_MoveHandler_EndBombJump(); return;
  case fnnullsub_152: return;
  case fnSamusMovementType_Xray: SamusMovementType_Xray(); return;
  case fnSamus_MoveHandler_F04B_Unused: Samus_MoveHandler_F04B_Unused(); return;
  case fnSamus_MoveHandler_F072_Unused: Samus_MoveHandler_F072_Unused(); return;
  default: Unreachable();
  }
}

void RunSamusMovementHandler(void) {  // 0x90E94B
  CallSamusMovementHandler(samus_movement_handler | 0x900000);
}

void SamusMovementType_Xray(void) {  // 0x90E94F
  uint16 v0;
  if (samus_movement_type != kMovementType_0E_TurningAroundOnGround) {
    samus_anim_frame_timer = 15;
    if (samus_pose_x_dir == kSamusXDir_FaceLeft) {
      if (sign16(xray_angle - 153)) {
        v0 = 4;
      } else if (sign16(xray_angle - 178)) {
        v0 = 3;
      } else if (sign16(xray_angle - 203)) {
        v0 = 2;
      } else {
        v0 = sign16(xray_angle - 228) != 0;
      }
    } else if (sign16(xray_angle - 25)) {
      v0 = 0;
    } else if (sign16(xray_angle - 50)) {
      v0 = 1;
    } else if (sign16(xray_angle - 75)) {
      v0 = 2;
    } else if (sign16(xray_angle - 100)) {
      v0 = 3;
    } else {
      v0 = 4;
    }
    samus_anim_frame = v0;
  }
}

void Samus_HandlePeriodicDamage(void) {  // 0x90E9CE
  if (time_is_frozen_flag) {
    samus_periodic_damage = samus_periodic_subdamage = 0;
    return;
  }
  int32 t = __PAIR32__(samus_periodic_damage, samus_periodic_subdamage);
  if (t < 0) {
    InvalidInterrupt_Crash();
    return;
  }
  if ((equipped_items & kItem_GravitySuit) != 0)
    t = (t >> 2) & 0xffff00;
  else if ((equipped_items & kItem_VariaSuit) != 0)
    t = (t >> 1) & 0xffff00;
  AddToHiLo(&samus_health, &samus_subunit_health, -t);
  if ((int16)samus_health < 0)
    samus_health = samus_subunit_health = 0;
  samus_periodic_damage = samus_periodic_subdamage = 0;
}

void Samus_PauseCheck(void) {  // 0x90EA45
  if (!power_bomb_flag
      && !time_is_frozen_flag
      && !door_transition_flag_enemies
      && area_index != kArea_6_Ceres
      && game_state == kGameState_8_MainGameplay
      && (joypad1_newkeys & kButton_Start) != 0) {
    screen_fade_delay = 1;
    screen_fade_counter = 1;
    game_state = kGameState_12_Pausing;
  }
}

void Samus_LowHealthCheck_(void) {  // 0x90EA7F
  if (sign16(samus_health - 31)) {
    if (!samus_health_warning) {
      QueueSfx3_Max6(kSfx3_LowHealthBeep);
      samus_health_warning = 1;
    }
  } else if (samus_health_warning) {
    samus_health_warning = 0;
    QueueSfx3_Max6(kSfx3_Silence);
  }
}

void Samus_LowHealthCheck_0(void) {  // 0x90EAAB
  Samus_LowHealthCheck_();
}

void Samus_JumpCheck(void) {  // 0x90EAB3
  if ((button_config_jump_a & joypad1_lastkeys) != 0 && (button_config_jump_a & joypad1_input_samusfilter) != 0)
    ++autojump_timer;
  else
    autojump_timer = 0;
  joypad1_input_samusfilter = joypad1_lastkeys;
  joypad1_newinput_samusfilter = joypad1_newkeys;
  if ((int16)(samus_health - samus_prev_health_for_flash) >= 0)
    goto LABEL_10;
  if (!samus_hurt_flash_counter)
    samus_hurt_flash_counter = 1;
  if (sign16(debug_invincibility - 7))
    LABEL_10:
  samus_prev_health_for_flash = samus_health;
  else
    samus_health = samus_prev_health_for_flash;
}

void Samus_Func10(void) {  // 0x90EB02
  projectile_init_speed_samus_moved_left = 0;
  projectile_init_speed_samus_moved_left_fract = 0;
  projectile_init_speed_samus_moved_right = 0;
  projectile_init_speed_samus_moved_right_fract = 0;
  projectile_init_speed_samus_moved_up = 0;
  projectile_init_speed_samus_moved_up_fract = 0;
  projectile_init_speed_samus_moved_down = 0;
  projectile_init_speed_samus_moved_down_fract = 0;
  samus_anim_frame_skip = 0;
  new_projectile_direction_changed_pose = 0;
  UNUSED_word_7E0DFA <<= 8;
  WORD(g_ram[0xa10]) = *(uint16 *)&samus_pose_x_dir;
}

void DrawSamusAndProjectiles(void) {  // 0x90EB35
  SamusDrawSprites();
  DrawProjectiles();
  Samus_JumpCheck();
  Samus_ShootCheck();
}

void CallSamusDrawHandler(uint32 ea) {
  switch (ea) {
  case fnSamusDrawHandler_Default: SamusDrawHandler_Default(); return;
  case fnSamusDrawHandler_NoChargeOrGrapple: SamusDrawHandler_NoChargeOrGrapple(); return;
  case fnnullsub_152:
  case fnnullsub_156: return;
  case fnSamus_DrawHandler_EndOfShinespark: Samus_DrawHandler_EndOfShinespark(); return;
  case fnSamusDisplayHandler_UsingElevator: SamusDisplayHandler_UsingElevator(); return;
  case fnSamusDisplayHandler_SamusReceivedFatal: SamusDisplayHandler_SamusReceivedFatal(); return;
  default: Unreachable();
  }
}

void SamusDrawSprites(void) {  // 0x90EB4B
  HandleArmCannonOpenState();
  CallSamusDrawHandler(samus_draw_handler | 0x900000);
}

void SamusDrawHandler_Default(void) {  // 0x90EB52
  HandleChargingBeamGfxAudio();
  DrawSamus_NoChargeOrGrapple();
}

void DrawSamus_NoChargeOrGrapple(void) {  // 0x90EB55
  if ((arm_cannon_drawing_mode & 0xF) != 0) {
    if ((arm_cannon_drawing_mode & 0xF) == 2) {
      HandleAtmosphericEffects();
      Samus_Draw();
      Samus_ArmCannon_Draw();
    } else {
      HandleAtmosphericEffects();
      Samus_ArmCannon_Draw();
      Samus_Draw();
    }
    Samus_DrawEchoes();
  } else {
    HandleAtmosphericEffects();
    Samus_Draw();
    Samus_DrawEchoes();
  }
}

void SamusDrawHandler_NoChargeOrGrapple(void) {  // 0x90EB86
  if (!sign16(grapple_beam_function + 0x37AA)) {
    DrawSamus_NoChargeOrGrapple();
    return;
  }
  if (grapple_beam_function == FUNC16(GrappleBeamFunc_Firing)
      || grapple_beam_function == FUNC16(UNUSED_sub_9BC759)) {
    GrappleBeamFunc_BF1B();
  }
  HandleGrappleBeamFlare();
  if ((arm_cannon_drawing_mode & 0xF) != 0) {
    if ((arm_cannon_drawing_mode & 0xF) == 2) {
      HandleAtmosphericEffects();
      Samus_Draw();
      Samus_ArmCannon_Draw();
      UpdateGrappleBeamTilesAndIncrFlameCtr();
      if (!grapple_beam_length)
        return;
    } else {
      HandleAtmosphericEffects();
      Samus_ArmCannon_Draw();
      Samus_Draw();
      UpdateGrappleBeamTilesAndIncrFlameCtr();
      if (!grapple_beam_length)
        return;
    }
  } else {
    HandleAtmosphericEffects();
    Samus_Draw();
    UpdateGrappleBeamTilesAndIncrFlameCtr();
    if (!grapple_beam_length)
      return;
  }
  HandleGrappleBeamGfx();
}

void Samus_DrawHandler_EndOfShinespark(void) {  // 0x90EBF3
  Samus_Draw();
  for (int i = 2; i >= 0; i -= 2)
    Samus_DrawShinesparkCrashEchoes(i);
}

void Samus_DrawManyEchoes(void) {  // 0x90EC03
  SamusDrawHandler_Default();
  for (int i = 2; i >= 0; i -= 2)
    Samus_DrawEchoes();
}

void SamusDisplayHandler_UsingElevator(void) {  // 0x90EC14
  if ((nmi_frame_counter_word & 1) == 0)
    SamusDisplayHandler_SamusReceivedFatal();
}

void SamusDisplayHandler_SamusReceivedFatal(void) {  // 0x90EC1D
  Samus_DrawWhenNotAnimatingOrDying();
}

void Samus_SetRadius(void) {  // 0x90EC22
  samus_y_radius = kPoseParams[samus_pose].y_radius;
  samus_x_radius = 5;
}

uint16 Samus_GetBottom_R18(void) {
  return samus_y_pos + kPoseParams[samus_pose].y_radius - 1;
}

uint16 Samus_GetTop_R20(void) {
  return samus_y_pos - kPoseParams[samus_pose].y_radius;
}

void Samus_AlignBottomWithPrevPose(void) {  // 0x90EC7E
  uint16 r18 = kPoseParams[samus_pose].y_radius;
  r18 = kPoseParams[samus_prev_pose].y_radius - r18;
  samus_y_pos += r18;
  samus_prev_y_pos += r18;
}

void Samus_UpdateSuitPaletteIndex(void) {  // 0x90ECB6
  if ((equipped_items & kItem_GravitySuit) != 0) {
    samus_suit_palette_index = kSuitPaletteIndex_4_Gravity;
  } else if ((equipped_items & kItem_VariaSuit) != 0) {
    samus_suit_palette_index = kSuitPaletteIndex_2_Varia;
  } else {
    samus_suit_palette_index = kSuitPaletteIndex_0_Power;
  }
}

void MoveSamusWithControlPad(void) {  // 0x90ECD5
  if ((joypad1_lastkeys & kButton_Up) != 0)
    Samus_MoveUp(INT16_SHL16(-4));
  if ((joypad1_lastkeys & kButton_Down) != 0)
    Samus_MoveDown(INT16_SHL16(4));
  if ((joypad1_lastkeys & kButton_Left) != 0)
    Samus_MoveLeft(INT16_SHL16(-4));
  if ((joypad1_lastkeys & kButton_Right) != 0)
    Samus_MoveRight(INT16_SHL16(4));
}

static const uint8 kSamusMovementType_CheckMorphed_Tab0[28] = {  // 0x90ED26
  0, 0, 0, 0, 1, 0, 0, 1,
  1, 1, 0, 0, 0, 0, 0, 0,
  0, 1, 1, 1, 0, 0, 0, 0,
  0, 0, 0, 0,
};

void DisplaySamusPositionAsAmmoIfMorphed(void) {
  if (kSamusMovementType_CheckMorphed_Tab0[samus_movement_type]) {
    samus_missiles = samus_x_pos >> 4;
    samus_max_missiles = samus_x_pos >> 4;
    samus_super_missiles = samus_y_pos >> 4;
    samus_max_super_missiles = samus_y_pos >> 4;
  }
}

void UNUSED_DisplayInGameTimeAsAmmo(void) {  // 0x90ED6C
  samus_missiles = game_time_hours;
  samus_max_missiles = game_time_hours;
  samus_super_missiles = game_time_minutes;
  samus_max_super_missiles = game_time_minutes;
  samus_power_bombs = game_time_seconds;
  samus_max_power_bombs = game_time_seconds;
}

static Func_V *const kSamus_FootstepGraphics[8] = {  // 0x90ED88
  [kArea_0_Crateria] = Samus_FootstepGraphics_Crateria,
  [kArea_1_Brinstar] = Samus_FootstepGraphics_Common,
  [kArea_2_Norfair] = Samus_FootstepGraphics_Common,
  [kArea_3_WreckedShip] = Samus_FootstepGraphics_Common,
  [kArea_4_Maridia] = Samus_FootstepGraphics_Maridia,
  [kArea_5_Tourian] = Samus_FootstepGraphics_Common,
  [kArea_6_Ceres] = Samus_FootstepGraphics_Common,
  [kArea_7_Debug] = Samus_FootstepGraphics_Common,
};
void Samus_FootstepGraphics(void) {
  kSamus_FootstepGraphics[area_index]();
}

static const uint8 kFootstepGraphics_AreaIndex_Tab0[16] = {  // 0x90EDA1
  1, 0, 0, 0, 0, 2, 0, 4,
  0, 4, 4, 4, 4, 0, 4, 0,
};
void Samus_FootstepGraphics_Crateria(void) {
  if (cinematic_function || (int16)(room_index - 16) >= 0)
    goto LABEL_11;
  if ((kFootstepGraphics_AreaIndex_Tab0[room_index] & 1) == 0) {
    if ((kFootstepGraphics_AreaIndex_Tab0[room_index] & 2) != 0) {
      if (!sign16(samus_y_pos - 944))
        goto LABEL_12;
    } else if ((kFootstepGraphics_AreaIndex_Tab0[room_index] & 4) != 0) {
      goto LABEL_12;
    }
LABEL_11:
    Samus_FootstepGraphics_Common();
    return;
  }
  if (fx_type != kFxType_A_Rain)
    goto LABEL_11;
LABEL_12:
  Samus_FootstepGraphics_Maridia();
}

void Samus_FootstepGraphics_Maridia(void) {  // 0x90EDEC
  uint16 r18 = Samus_GetBottom_R18();
  if ((fx_y_pos & 0x8000) != 0) {
    if ((lava_acid_y_pos & 0x8000) == 0 && sign16(lava_acid_y_pos - r18))
      return;
  } else if (sign16(fx_y_pos - r18) && !(fx_liquid_options & kFxLiquidOption_4_LiquidPhysicsDisabled)) {
    return;
  }
  if (samus_pose_x_dir == kSamusXDir_FaceLeft) {
    atmospheric_gfx_x_pos[0] = samus_x_pos - 12;
    atmospheric_gfx_x_pos[1] = samus_x_pos + 8;
  } else {
    atmospheric_gfx_x_pos[0] = samus_x_pos + 12;
    atmospheric_gfx_x_pos[1] = samus_x_pos - 8;
  }
  atmospheric_gfx_y_pos[0] = samus_y_pos + 16;
  atmospheric_gfx_y_pos[1] = samus_y_pos + 16;
  atmospheric_gfx_frame_and_type[0] = 256;
  atmospheric_gfx_frame_and_type[1] = 256;
  atmospheric_gfx_anim_timer[0] = -32766;
  atmospheric_gfx_anim_timer[1] = 3;
}

void Samus_FootstepGraphics_Common(void) {  // 0x90EE64
  if ((speed_boost_counter & 0xFF00) == 0x400) {
    uint16 r18 = Samus_GetBottom_R18();
    if ((fx_y_pos & 0x8000) != 0) {
      if ((lava_acid_y_pos & 0x8000) == 0 && sign16(lava_acid_y_pos - r18))
        return;
    } else if (sign16(fx_y_pos - r18) && !(fx_liquid_options & kFxLiquidOption_4_LiquidPhysicsDisabled)) {
      return;
    }
    if (samus_pose_x_dir == kSamusXDir_FaceLeft) {
      atmospheric_gfx_x_pos[0] = samus_x_pos - 12;
      atmospheric_gfx_x_pos[1] = samus_x_pos + 8;
    } else {
      atmospheric_gfx_x_pos[0] = samus_x_pos + 12;
      atmospheric_gfx_x_pos[1] = samus_x_pos - 8;
    }
    atmospheric_gfx_y_pos[0] = samus_y_pos + 16;
    atmospheric_gfx_y_pos[1] = samus_y_pos + 16;
    atmospheric_gfx_frame_and_type[0] = 1792;
    atmospheric_gfx_frame_and_type[1] = 1792;
    atmospheric_gfx_anim_timer[0] = -32766;
    atmospheric_gfx_anim_timer[1] = 3;
  }
}

void Samus_UpdateSpeedEchoPos(void) {  // 0x90EEE7
  if ((speed_boost_counter & 0xFF00) == 0x400 && (speed_echoes_index & 0x8000) == 0 && (game_time_frames & 3) == 0) {
    uint16 v0 = speed_echoes_index;
    int v1 = speed_echoes_index >> 1;
    speed_echo_xpos[v1] = samus_x_pos;
    speed_echo_ypos[v1] = samus_y_pos;
    uint16 v2 = v0 + 2;
    if ((int16)(v2 - 4) >= 0)
      v2 = 0;
    speed_echoes_index = v2;
  }
}

void Samus_PostGrappleCollisionDetect(void) {  // 0x90EF22
  PostGrappleCollisionDetect_X();
  PostGrappleCollisionDetect_Y();
  if (!distance_to_eject_samus_down || !distance_to_eject_samus_up) {
    if (distance_to_eject_samus_up) {
      samus_y_pos -= distance_to_eject_samus_up;
      if (!sign16(samus_y_radius - 16)) {
        PostGrappleCollisionDetect_Y();
        samus_y_pos -= distance_to_eject_samus_up;
      }
    }
  }
}


void ProjPreInstr_UnknownProj8027(uint16 k) {  // 0x90EFD3
  static const int16 kProjPreInstr_UnknownProj8027_X[4] = { -4, -4, 4, 4 };
  static const int16 kProjPreInstr_UnknownProj8027_Y[4] = { 4, -4, -4, 4 };
  static const int16 kProjPreInstr_UnknownProj8027_X2[4] = { 0x80, 0x80, -0x80, -0x80 };
  static const int16 kProjPreInstr_UnknownProj8027_Y2[4] = { -0x80, 0x80, 0x80, -0x80 };

  int v1 = k >> 1;
  projectile_x_pos[v1] += kProjPreInstr_UnknownProj8027_X[v1];
  uint16 v2 = kProjPreInstr_UnknownProj8027_Y[v1] + projectile_y_pos[v1];
  projectile_y_pos[v1] = v2;
  if (v2 == samus_y_pos) {
    if (projectile_variables[v1] == 1) {
      if (k == 6)
        samus_movement_handler = FUNC16(Samus_MoveHandler_F04B_Unused);
      ClearProjectile(k);
    } else {
      int v3 = k >> 1;
      ++projectile_variables[v3];
      samus_shine_timer = 180;
      timer_for_shine_timer = 1;
      special_samus_palette_frame = 0;
      projectile_x_pos[v3] = kProjPreInstr_UnknownProj8027_X2[v3] + samus_x_pos;
      projectile_y_pos[v3] = kProjPreInstr_UnknownProj8027_Y2[v3] + samus_y_pos;
    }
  }
}

void Samus_MoveHandler_F04B_Unused(void) {  // 0x90F04B
  if (!samus_shine_timer) {
    special_samus_palette_frame = 6;
    special_samus_palette_timer = 1;
    demo_timer_counter = 1;
    timer_for_shine_timer = 10;
    samus_shine_timer = 120;
    samus_movement_handler = FUNC16(Samus_MoveHandler_F072_Unused);
  }
}

void Samus_MoveHandler_F072_Unused(void) {  // 0x90F072
  if (!samus_shine_timer) {
    frame_handler_alfa = FUNC16(Samus_FrameHandlerAlfa_Normal);
    samus_movement_handler = FUNC16(Samus_MovementHandler_Normal);
  }
}

static Func_U8 *const kSamusCodeHandlers[32] = {  // 0x90F084
  SamusCode_00_LockSamus,
  SamusCode_01_UnlockSamus,
  SamusCode_02_ReachCeresElevator,
  SamusCode_03_UnspinSamus,
  SamusCode_04_EndChargeBeam,
  SamusCode_05_SetupDrained_AbleToStand,
  SamusCode_06_LockToStation,
  SamusCode_07_SetupForElevator,
  SamusCode_08_SetupForCeresStart,
  SamusCode_09_SetupForZebesStart,
  SamusCode_0A_ClearDrawHandler,
  SamusCode_0B_UnlockFromFacingForward,
  SamusCode_0C_UpdateDueToUnpause,
  SamusCode_0D_IsGrappleActive,
  SamusCode_0E_UnlockFromCeresElevator,
  SamusCode_0F_EnableTimerHandling,
  SamusCode_10_UnlockFromReserveTank,
  SamusCode_11_SetupForDeath,
  SamusCode_12_EnableBlueFlashing,
  SamusCode_13_DisableBlueFlashing,
  SamusCode_14_QueueSfx,
  SamusCode_15_LockToSuitAcquisition,
  SamusCode_16_EnableRainbowSamus,
  SamusCode_17_DisableRainbowSamusAndStandUp,
  SamusCode_18_SetupDrained_UnableToStand,
  SamusCode_19_FreezeDrainedSamus,
  SamusCode_1A_EnterGunship,
  SamusCode_1B_LockForReserveTank,
  SamusCode_1C_PlaySpinSfxIfSpinJumping,
  SamusCode_1D_ClearSoundInDoor,
  SamusCode_1E_ResumeSfxAfterPowerBombExplosion,
  SamusCode_1F_KillGrappleBeam,
};

uint16 RunSamusCode(uint16 a) {
  uint16 code = kSamusCodeHandlers[a & 0x1F]();
  if (!(code & 1))
    return code >> 1;
  samus_new_pose = -1;
  samus_new_pose_interrupted = -1;
  samus_new_pose_transitional = -1;
  samus_new_pose_command = 0;
  samus_special_transgfx_index = 0;
  samus_hurt_switch_index = 0;
  return -1;
}

void Samus_UpdatePreviousPose(void) {  // 0x90F0EE
  samus_last_different_pose = samus_prev_pose;
  *(uint16 *)&samus_last_different_pose_x_dir = *(uint16 *)&samus_prev_pose_x_dir;
  samus_prev_pose = samus_pose;
  *(uint16 *)&samus_prev_pose_x_dir = *(uint16 *)&samus_pose_x_dir;
}

uint8 ClearCarry(void) {  // 0x90F107
  return 0;
}

uint8 SamusCode_00_LockSamus(void) {  // 0x90F109
  frame_handler_alfa = FUNC16(Samus_FrameHandlerAlfa_SamusLocked);
  frame_handler_beta = FUNC16(Samus_FrameHandlerBeta_SamusLocked);
  return 1;
}

uint8 SamusCode_01_UnlockSamus(void) {  // 0x90F117
  frame_handler_alfa = FUNC16(Samus_FrameHandlerAlfa_Normal);
  frame_handler_beta = FUNC16(Samus_FrameHandlerBeta_Normal);
  return 1;
}

uint8 SamusCode_02_ReachCeresElevator(void) {  // 0x90F125
  if (samus_pose_x_dir == kSamusXDir_FaceLeft)
    samus_pose = kPose_02_FaceL_Normal;
  else
    samus_pose = kPose_01_FaceR_Normal;
  samus_anim_frame_skip = 0;
  SamusFunc_F433();
  Samus_SetAnimationFrameIfPoseChanged();
  reached_ceres_elevator_fade_timer = 60;
  return SamusCode_00_LockSamus();
}

uint8 SamusCode_03_UnspinSamus(void) {  // 0x90F152
  if (grapple_beam_function != FUNC16(GrappleBeamFunc_Inactive)) {
    grapple_beam_function = FUNC16(GrappleBeam_Func2);
    return 0;
  }
  if (samus_movement_type != kMovementType_03_SpinJumping && samus_movement_type != kMovementType_14_WallJumping)
    return 0;
  if (samus_pose_x_dir == kSamusXDir_FaceLeft)
    samus_pose = kPose_02_FaceL_Normal;
  else
    samus_pose = kPose_01_FaceR_Normal;
  samus_anim_frame_skip = 0;
  SamusFunc_F433();
  Samus_SetAnimationFrameIfPoseChanged();
  Samus_UpdatePreviousPose();
  return 1;
}

uint8 EndChargeBeam(void) {  // 0x90F19E
  flare_counter = 0;
  ClearFlareAnimationState();
  Samus_LoadSuitPalette();
  return 0;
}

uint8 SamusCode_04_EndChargeBeam(void) {  // 0x90F19B
  samus_charge_palette_index = 0;
  return EndChargeBeam();
}

uint8 SamusCode_06_LockToStation(void) {  // 0x90F1AA
  frame_handler_alfa = FUNC16(Samus_FrameHandlerAlfa_SamusLocked);
  frame_handler_beta = FUNC16(Samus_FrameHandlerBeta_SamusLockedToStation);
  if (!sign16(flare_counter - 15))
    QueueSfx1_Max15(kSfx1_Silence);
  return EndChargeBeam();
}

uint8 SamusCode_07_SetupForElevator(void) {  // 0x90F1C8
  MakeSamusFaceForward();
  frame_handler_beta = FUNC16(Samus_FrameHandlerBeta_RidingElevator);
  samus_movement_handler = FUNC16(Samus_MovementHandler_Normal);
  samus_draw_handler = FUNC16(SamusDisplayHandler_UsingElevator);
  samus_input_handler = FUNC16(Samus_InputHandler_Normal);
  bomb_jump_dir = 0;
  return 1;
}

uint8 SamusCode_08_SetupForCeresStart(void) {  // 0x90F1E9
  frame_handler_alfa = FUNC16(Samus_FrameHandlerBeta_DoNothing);
  frame_handler_beta = FUNC16(Samus_FrameHandlerBeta_SamusLocked);
  samus_pose = kPose_00_FaceF_Powersuit;
  samus_anim_frame_skip = 0;
  SamusFunc_F433();
  Samus_SetAnimationFrameIfPoseChanged();
  Samus_LoadSuitPalette();
  samus_draw_handler = FUNC16(SamusDrawHandler_Default);
  samus_prev_pose = samus_pose;
  samus_last_different_pose = samus_pose;
  *(uint16 *)&samus_prev_pose_x_dir = *(uint16 *)&samus_pose_x_dir;
  *(uint16 *)&samus_last_different_pose_x_dir = *(uint16 *)&samus_pose_x_dir;
  samus_y_pos = 0;
  SpawnEprojWithGfx(0, 0, addr_kEproj_CeresElevatorPad);
  SpawnEprojWithGfx(0, 0, addr_kEproj_CeresElevatorPlatform);
  debug_disable_minimap = 0;
  PlayRoomMusicTrackAfterAFrames(0x20);
  return 1;
}

uint8 SamusCode_09_SetupForZebesStart(void) {  // 0x90F23C
  if ((equipped_items & kItem_GravitySuit) != 0) {
    SpawnPalfxObject(addr_kPalfx_SamusLoading_GravitySuit);
    samus_pose = kPose_9B_FaceF_VariaGravitySuit;
  } else if ((equipped_items & kItem_VariaSuit) != 0) {
    SpawnPalfxObject(addr_kPalfx_SamusLoading_VariaSuit);
    samus_pose = kPose_9B_FaceF_VariaGravitySuit;
  } else {
    SpawnPalfxObject(addr_kPalfx_SamusLoading_PowerSuit);
    samus_pose = kPose_00_FaceF_Powersuit;
  }
  Samus_LoadSuitPalette();
  SamusFunc_F433();
  samus_anim_frame_timer = 3;
  samus_anim_frame = 2;
  substate = 0;
  return 1;
}

uint8 SamusCode_0A_ClearDrawHandler(void) {  // 0x90F28D
  samus_draw_handler = FUNC16(nullsub_152);
  return 0;
}

uint8 SamusCode_0B_UnlockFromFacingForward(void) {  // 0x90F295
  samus_draw_handler = FUNC16(SamusDrawHandler_Default);
  return SamusCode_01_UnlockSamus();
}

uint8 SamusCode_0C_UpdateDueToUnpause(void) {  // 0x90F29E
  Samus_UpdatePoseFromEquipmentChange();
  if (frame_handler_beta == FUNC16(Samus_FrameHandlerBeta_SamusLockedToStation)) {
    frame_handler_alfa = FUNC16(Samus_FrameHandlerAlfa_Normal);
    frame_handler_beta = FUNC16(Samus_FrameHandlerBeta_Normal);
  }
  return 1;
}

uint8 SamusCode_0D_IsGrappleActive(void) {  // 0x90F2B8
  return (grapple_beam_function != FUNC16(GrappleBeamFunc_Inactive)) ? 2 : 0;
}

uint8 SamusCode_0D_IsGrappleActive_A(void) {
  return grapple_beam_function != FUNC16(GrappleBeamFunc_Inactive);
}

uint8 SamusCode_0E_UnlockFromCeresElevator(void) {  // 0x90F2CA
  frame_handler_alfa = FUNC16(Samus_FrameHandlerAlfa_Normal);
  frame_handler_beta = FUNC16(Samus_FrameHandlerBeta_Ceres);
  return 1;
}

uint8 SamusCode_0F_EnableTimerHandling(void) {  // 0x90F2D8
  frame_handler_gamma = FUNC16(Samus_FrameHandlerGamma_HandleTimer);
  return 0;
}

uint8 SamusCode_10_UnlockFromReserveTank(void) {  // 0x90F2E0
  if (frame_handler_beta != FUNC16(Samus_FrameHandlerBeta_SamusBeingDrained)) {
    frame_handler_alfa = FUNC16(Samus_FrameHandlerAlfa_Normal);
    frame_handler_beta = FUNC16(Samus_FrameHandlerBeta_Normal);
  }
  return 1;
}

uint8 LockSamus_SetInanimateDrawHandler(void) {  // 0x90F2FC
  frame_handler_alfa = FUNC16(Samus_FrameHandlerAlfa_SamusLocked);
  frame_handler_beta = FUNC16(Samus_FrameHandlerBeta_DoNothing);
  samus_draw_handler = FUNC16(SamusDisplayHandler_SamusReceivedFatal);
  return 1;
}

uint8 SamusCode_11_SetupForDeath(void) {  // 0x90F2F8
  DisablePaletteFx();
  return LockSamus_SetInanimateDrawHandler();
}

uint8 SamusCode_15_LockToSuitAcquisition(void) {  // 0x90F310
  Samus_UpdatePreviousPose();
  flare_counter = 0;
  ClearFlareAnimationState();
  Samus_LoadSuitPalette();
  return LockSamus_SetInanimateDrawHandler();
}

uint8 SamusCode_12_EnableBlueFlashing(void) {  // 0x90F320
  samus_special_super_palette_flags = 1;
  return 0;
}

uint8 SamusCode_13_DisableBlueFlashing(void) {  // 0x90F328
  samus_special_super_palette_flags = 0;
  Samus_LoadSuitPalette();
  return 0;
}

uint8 SamusCode_14_QueueSfx(void) {  // 0x90F331
  if (sign16(samus_health - 31))
    QueueSfx3_Max6(kSfx3_LowHealthBeep);
  if (!SamusCode_0D_IsGrappleActive_A()) {
    if (samus_pose_x_dir == 3) {
      if (samus_pose == kPose_81_FaceR_Screwattack || samus_pose == kPose_82_FaceL_Screwattack) {
        QueueSfx1_Max6(kSfx1_ScrewAttack);
      } else if (samus_pose == kPose_1B_FaceR_SpaceJump || samus_pose == kPose_1C_FaceL_SpaceJump) {
        QueueSfx1_Max6(kSfx1_SpaceJump);
      } else {
        QueueSfx1_Max6(kSfx1_SpinJump);
      }
    }
  } else {
    QueueSfx1_Max6(kSfx1_Grappling);
  }
  return 0;
}

uint8 SamusCode_05_SetupDrained_AbleToStand(void) {  // 0x90F38E
  frame_handler_gamma = FUNC16(Samus_FrameHandlerGamma_UnlockSamusFromDrained);
  return Samus_SetupForBeingDrained();
}

uint8 Samus_SetupForBeingDrained(void) {  // 0x90F394
  samus_pose = kPose_54_FaceL_Knockback;
  samus_anim_frame_skip = 0;
  SamusFunc_F433();
  Samus_SetAnimationFrameIfPoseChanged();
  Samus_UpdatePreviousPose();
  flare_counter = 0;
  ClearFlareAnimationState();
  Samus_LoadSuitPalette();
  frame_handler_alfa = FUNC16(Samus_FrameHandlerAlfa_SamusLocked);
  frame_handler_beta = FUNC16(Samus_FrameHandlerBeta_SamusBeingDrained);
  return 1;
}

uint8 SamusCode_18_SetupDrained_UnableToStand(void) {  // 0x90F3C0
  frame_handler_gamma = FUNC16(Samus_FrameHandlerGamma_KeepSamusLockedFromDrained);
  return Samus_SetupForBeingDrained();
}

uint8 SamusCode_16_EnableRainbowSamus(void) {  // 0x90F3C9
  samus_special_super_palette_flags = 0x8000;
  special_samus_palette_frame = 1;
  special_samus_palette_timer = 1;
  samus_charge_palette_index = 0;
  return 0;
}

uint8 SamusCode_17_DisableRainbowSamusAndStandUp(void) {  // 0x90F3DD
  samus_special_super_palette_flags = 0;
  special_samus_palette_frame = 0;
  special_samus_palette_timer = 0;
  samus_charge_palette_index = 0;
  Samus_LoadSuitPalette();
  samus_anim_frame_timer = 1;
  samus_anim_frame = 13;
  return 0;
}

uint8 SamusCode_19_FreezeDrainedSamus(void) {  // 0x90F3FB
  samus_anim_frame_timer = 1;
  samus_anim_frame = 28;
  return 1;
}

uint8 SamusCode_1A_EnterGunship(void) {  // 0x90F409
  frame_handler_beta = FUNC16(Samus_FrameHandlerBeta_EnterExitGunship);
  return 0;
}

uint8 SamusCode_1B_LockForReserveTank(void) {  // 0x90F411
  if (frame_handler_beta == FUNC16(Samus_FrameHandlerBeta_SamusBeingDrained))
    return 1;
  else
    return SamusCode_00_LockSamus();
}

uint8 SamusCode_1C_PlaySpinSfxIfSpinJumping(void) {  // 0x90F41E
  if (samus_movement_type == kMovementType_14_WallJumping) {
    if (sign16(samus_anim_frame - 23)) {
      if (sign16(samus_anim_frame - 13)) {
LABEL_11:
        QueueSfx1_Max9(kSfx1_SpinJump);
        return 0;
      }
      goto LABEL_12;
    }
  } else {
    if (samus_movement_type != kMovementType_03_SpinJumping)
      return 0;
    if (samus_pose != kPose_81_FaceR_Screwattack && samus_pose != kPose_82_FaceL_Screwattack) {
      if (samus_pose != kPose_1B_FaceR_SpaceJump && samus_pose != kPose_1C_FaceL_SpaceJump)
        goto LABEL_11;
LABEL_12:
      QueueSfx1_Max9(kSfx1_SpaceJump);
      return 0;
    }
  }
  QueueSfx1_Max9(kSfx1_ScrewAttack);
  return 0;
}

uint8 SamusCode_1D_ClearSoundInDoor(void) {  // 0x90F471
  if (samus_movement_type == kMovementType_03_SpinJumping || samus_movement_type == kMovementType_14_WallJumping) {
    QueueSfx1_Max15(kSfx1_SpinJumpEnd_Silence);
    return 0;
  } else {
    if ((button_config_shoot_x & joypad1_lastkeys) == 0) {
      if (sign16(flare_counter - 16))
        QueueSfx1_Max15(kSfx1_Silence);
    }
    return 0;
  }
}

uint8 SamusCode_1E_ResumeSfxAfterPowerBombExplosion(void) {  // 0x90F4A2
  if (game_state == kGameState_8_MainGameplay) {
    if (samus_movement_type == kMovementType_03_SpinJumping || samus_movement_type == kMovementType_14_WallJumping) {
      SamusCode_1C_PlaySpinSfxIfSpinJumping();
      return 0;
    }
    if (!sign16(flare_counter - 16))
      QueueSfx1_Max9(kSfx1_ResumeChargingBeam);
  }
  return 0;
}

uint8 SamusCode_1F_KillGrappleBeam(void) {  // 0x90F4D0
  if (grapple_beam_function != FUNC16(GrappleBeamFunc_Inactive)) {
    grapple_beam_unkD1E = 0;
    grapple_beam_unkD20 = 0;
    grapple_beam_direction = 0;
    grapple_beam_angle_handling_flag = 0;
    grapple_walljump_timer = 0;
    slow_grapple_scrolling_flag = 0;
    grapple_beam_auto_cancel_timer = 0;
    grapple_beam_flags = 0;
    LoadProjectilePalette(equipped_beams);
    grapple_beam_function = FUNC16(GrappleBeamFunc_Inactive);
    samus_draw_handler = FUNC16(SamusDrawHandler_Default);
  }
  return 0;
}

uint8 UNUSED_Samus_Func26(void) {  // 0x90F507
  if (samus_movement_type != kMovementType_03_SpinJumping
      && samus_movement_type != kMovementType_14_WallJumping
      && (button_config_shoot_x & joypad1_lastkeys) != 0
      && !sign16(flare_counter - 16)) {
    QueueSfx1_Max9(kSfx1_ResumeChargingBeam);
  }
  return 0;
}

void Samus_ShootCheck(void) {  // 0x90F576
  if ((play_resume_charging_beam_sfx & 0x8000) != 0)
    goto LABEL_15;
  if (play_resume_charging_beam_sfx) {
    if ((button_config_shoot_x & joypad1_lastkeys) != 0)
      QueueSfx1_Max9(kSfx1_ResumeChargingBeam);
    play_resume_charging_beam_sfx = 0;
  }
  if (samus_echoes_sound_flag && (speed_boost_counter & 0x400) == 0) {
    samus_echoes_sound_flag = 0;
    QueueSfx3_Max15(kSfx3_ClearSpeedBooster_ElevatorSound_Silence);
  }
  if ((samus_prev_movement_type == 3 || samus_prev_movement_type == 20)
      && samus_movement_type != kMovementType_03_SpinJumping
      && samus_movement_type != kMovementType_14_WallJumping) {
    QueueSfx1_Max15(kSfx1_SpinJumpEnd_Silence);
    if (!sign16(flare_counter - 16) && (button_config_shoot_x & joypad1_lastkeys) != 0)
      LABEL_15:
    play_resume_charging_beam_sfx = 1;
  }
  if (enable_debug) {
    if (samus_pose == kPose_00_FaceF_Powersuit || samus_pose == kPose_9B_FaceF_VariaGravitySuit) {
      if ((joypad2_last & 0x30) == 48 && (joypad2_new_keys & 0x80) != 0)
        debug_invincibility = 7;
    } else {
      if (!sign16(debug_invincibility - 7))
        return;
      debug_invincibility = 0;
    }
  }
  if (CheckEventHappened(kEvent_14_ZebesTimebombSet) & 1
      && frame_handler_gamma == FUNC16(Samus_FrameHandlerGamma_DrawTimer)
      && game_state != kGameState_35_TimeUp) {
    game_state = kGameState_35_TimeUp;
  }
}
