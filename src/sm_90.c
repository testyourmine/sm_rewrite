// Samus

#include "ida_types.h"
#include "variables.h"
#include "sm_rtl.h"
#include "funcs.h"
#include "sm_90.h"


static Pair_Bool_Amt Samus_CalcBaseSpeed_NoDecel_X(uint16 k);

static void Samus_HandleAnimDelay(void);

void nullsub_12(void) {}

static Func_V *const kSamusFxHandlers[8] = {
  [((kFxType_20_ScrollingSkyLand & 0xF)      | kFxType_0_None) >> 1]   = Samus_Animate_NoFx,
  [((kFxType_22_Unused & 0xF)                | kFxType_2_Lava) >> 1]   = Samus_Animate_LavaFx,
  [((kFxType_24_Fireflea & 0xF)              | kFxType_4_Acid) >> 1]   = Samus_Animate_AcidFx,
  [((kFxType_26_TourianEntranceStatue & 0xF) | kFxType_6_Water) >> 1]  = Samus_Animate_WaterFx,
  [((kFxType_28_CeresRidley & 0xF)           | kFxType_8_Spores) >> 1] = nullsub_12,
  [((kFxType_2A_CeresElevator & 0xF)         | kFxType_A_Rain) >> 1]   = nullsub_12,
  [((kFxType_2C_Haze & 0xF)                  | kFxType_C_Fog) >> 1]    = nullsub_12,
  nullsub_12,
};

/**
* @brief Animates Samus based off the room FX and handles animation frame, timer, and delay
*/
void Samus_Animate(void) {  // 0x908000
  kSamusFxHandlers[(fx_type & 0xF) >> 1]();
  if (samus_pose == kPose_4D_FaceR_Jump_NoAim_NoMove_NoGun || samus_pose == kPose_4E_FaceL_Jump_NoAim_NoMove_NoGun) {
    if (samus_y_dir != kSamusYDir_Down && samus_anim_frame == 1 && samus_anim_frame_timer == 1) {
      samus_anim_frame_timer = 4;
    }
    if ((int16)--samus_anim_frame_timer <= 0) {
      ++samus_anim_frame;
      Samus_HandleAnimDelay();
    }
  }
  // if statement duplicated in original code, could merge into one
  else {
    if ((int16)--samus_anim_frame_timer <= 0) {
      ++samus_anim_frame;
      Samus_HandleAnimDelay();
    }
  }
}

/**
* @brief Set animation buffer for no FX, handle liquid physics type, SFX, interaction with water
*/
void Samus_Animate_NoFx(void) {  // 0x908078
  uint16 samus_bottom_bound = Samus_GetBottomBound();
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

/**
* @brief Animates with no FX if Samus is not touching water, otherwise handles liquid physics type,
* SFX, logic and animations from interacting with water
*/
void Samus_Animate_WaterFx(void) {  // 0x9080B8
  static const uint16 kSamusPhys_AnimDelayInWater = 3;

  int16 samus_bottom_bound = Samus_GetBottomBound();
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

/**
* @brief Spawns footstep or dive splash, and air bubbles
* @param samus_bottom_bound The bottom boundary of Samus
*/
void Samus_SpawnWaterSplash(uint16 samus_bottom_bound) {  // 0x9080E6
  // 0 is not in water (dive splash), 1 is in water (footstep splash)
  if (kWaterSplashTypeTable[samus_movement_type] != 0) {
    LOBYTE(atmospheric_gfx_frame_and_type[0]) = 0;
    HIBYTE(atmospheric_gfx_frame_and_type[0]) = kAtmosphericGraphicType_1_FootstepSplashes;

    LOBYTE(atmospheric_gfx_frame_and_type[1]) = 0;
    HIBYTE(atmospheric_gfx_frame_and_type[1]) = kAtmosphericGraphicType_1_FootstepSplashes;

    atmospheric_gfx_anim_timer[0] = 3;
    atmospheric_gfx_anim_timer[1] = 3;

    atmospheric_gfx_x_pos[0] = samus_x_pos + 4;
    atmospheric_gfx_x_pos[1] = samus_x_pos - 3;

    atmospheric_gfx_y_pos[0] = samus_bottom_bound - 4;
    atmospheric_gfx_y_pos[1] = samus_bottom_bound - 4;
  }
  else {
    LOBYTE(atmospheric_gfx_frame_and_type[0]) = 0;
    HIBYTE(atmospheric_gfx_frame_and_type[0]) = kAtmosphericGraphicType_3_DivingSplashes;

    atmospheric_gfx_anim_timer[0] = 2;

    atmospheric_gfx_x_pos[0] = samus_x_pos;
    atmospheric_gfx_y_pos[0] = fx_y_pos;
  }
  Samus_SpawnAirBubbles();
}

/**
* @brief Spawns air bubbles and plays random bubble SFX every 128 frames (~2.13 seconds)
* if Samus is submerged more than 1.5 blocks under water
*/
void Samus_SpawnAirBubbles(void) {  // 0x90813E
  int16 samus_top_bound = Samus_GetTopBound();
  if ((samus_top_bound - 24) >= (int16)fx_y_pos && (nmi_frame_counter_word & 127) == 0
      && atmospheric_gfx_frame_and_type[2] == 0) {
    LOBYTE(atmospheric_gfx_frame_and_type[2]) = 0;
    HIBYTE(atmospheric_gfx_frame_and_type[2]) = kAtmosphericGraphicType_5_Bubbles;

    atmospheric_gfx_anim_timer[2] = 3;

    atmospheric_gfx_x_pos[2] = samus_x_pos;
    atmospheric_gfx_y_pos[2] = samus_y_pos - samus_y_radius + 6;
    QueueSfx2_Max6((NextRandom() & 1) ? kSfx2_LowPitchedAirBubbles : kSfx2_HighPitchedAirBubbles);
  }
  if (samus_pose == kPose_00_FaceF_Powersuit || samus_pose == kPose_9B_FaceF_VariaGravitySuit
      || (equipped_items & kItem_GravitySuit)) {
    samus_anim_frame_buffer = 0;
  }
}

/**
* @brief Animates with no FX if Samus is not touching lava, otherwise handles liquid physics type,
* SFX, logic and animations from interacting with lava
*/
void Samus_Animate_LavaFx(void) {  // 0x9081C0
  static const uint16 kSamusPhys_LavaDamagePerFrame = 0;
  static const uint16 kSamusPhys_LavaSubdamagePerFrame = 0x8000;

  int16 samus_bottom_bound = Samus_GetBottomBound();
  if (0 <= (int16)lava_acid_y_pos && (int16)lava_acid_y_pos < samus_bottom_bound) {
    if (speed_boost_timer != 0 && speed_boost_counter != 0) {
      Samus_CancelSpeedBoost();
      samus_x_extra_run_speed = 0;
      samus_x_extra_run_subspeed = 0;
    }
    if (equipped_items & kItem_GravitySuit) {
      samus_anim_frame_buffer = 0;
      liquid_physics_type = kLiquidPhysicsType_LavaAcid;
    }
    else {
      if ((game_time_frames & 7) == 0 && (int16)samus_health > 70)
        QueueSfx3_Max3(kSfx3_GainingLosingIncrementalHealth);
      uint32 lava_damage_per_frame = __PAIR32__(kSamusPhys_LavaDamagePerFrame, kSamusPhys_LavaSubdamagePerFrame);
      AddToHiLo(&samus_periodic_damage, &samus_periodic_subdamage, lava_damage_per_frame);
      Samus_Animate_SubmergedLavaAcid();
    }
  }
  else {
    Samus_Animate_NoFx();
  }
}

/**
* @brief Animates with no FX if Samus is not touching acid, otherwise handles liquid physics type,
* SFX, logic and animations from interacting with acid
*/
void Samus_Animate_AcidFx(void) {  // 0x908219
  static const uint16 kSamusPhys_AcidSubdamagePerFrame = 0x8000;
  static const uint16 kSamusPhys_AcidDamagePerFrame = 1;

  int16 samus_bottom_bound = Samus_GetBottomBound();
  if (0 <= (int16)lava_acid_y_pos && (int16)lava_acid_y_pos < samus_bottom_bound) {
    if ((game_time_frames & 7) == 0 && (int16)samus_health > 70)
      QueueSfx3_Max3(kSfx3_GainingLosingIncrementalHealth);
    uint32 acid_damage_per_frame = __PAIR32__(kSamusPhys_AcidDamagePerFrame, kSamusPhys_AcidSubdamagePerFrame);
    AddToHiLo(&samus_periodic_damage, &samus_periodic_subdamage, acid_damage_per_frame);
    Samus_Animate_SubmergedLavaAcid();
  }
  else {
    Samus_Animate_NoFx();
  }
}

/**
* @brief Sets animation buffer and liquid physics type, spawns surface damage particles
* and plays lava/acid damage SFX if not submerged in lava/acid
*/
void Samus_Animate_SubmergedLavaAcid(void) {  // 0x90824C
  static const uint16 kSamusPhys_AnimDelayInLavaAcid = 2;

  int16 samus_top_bound = Samus_GetTopBound();
  samus_anim_frame_buffer = kSamusPhys_AnimDelayInLavaAcid;
  liquid_physics_type = kLiquidPhysicsType_LavaAcid;
  if (samus_top_bound < (int16)lava_acid_y_pos
      && !(HIBYTE(atmospheric_gfx_frame_and_type[0]) & kAtmosphericGraphicType_4_LavaAcidSurfaceDamage)) {
    LOBYTE(atmospheric_gfx_frame_and_type[0]) = 0;
    HIBYTE(atmospheric_gfx_frame_and_type[0]) = kAtmosphericGraphicType_4_LavaAcidSurfaceDamage;

    LOBYTE(atmospheric_gfx_frame_and_type[1]) = 0;
    HIBYTE(atmospheric_gfx_frame_and_type[1]) = kAtmosphericGraphicType_4_LavaAcidSurfaceDamage;

    LOBYTE(atmospheric_gfx_frame_and_type[2]) = 0;
    HIBYTE(atmospheric_gfx_frame_and_type[2]) = kAtmosphericGraphicType_4_LavaAcidSurfaceDamage;

    LOBYTE(atmospheric_gfx_frame_and_type[3]) = 0;
    HIBYTE(atmospheric_gfx_frame_and_type[3]) = kAtmosphericGraphicType_4_LavaAcidSurfaceDamage;

    atmospheric_gfx_anim_timer[0] = 3;
    atmospheric_gfx_anim_timer[3] = 3;
    atmospheric_gfx_anim_timer[1] = ANIM_TIMER_INACTIVE | 2;
    atmospheric_gfx_anim_timer[2] = ANIM_TIMER_INACTIVE | 2;

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
  if (samus_pose == kPose_00_FaceF_Powersuit || samus_pose == kPose_9B_FaceF_VariaGravitySuit
      || (equipped_items & kItem_GravitySuit)) {
    samus_anim_frame_buffer = 0;
  }
}

/**
* @brief Does not modify animation delay
* @param *anim_delay_instr The parameters of the animation delay function
* @return bool false, indicating the animation was not modified
*/
static bool Samus_AnimDelayFunc_0to5_Nothing(const uint8 *anim_delay_instr) {  // 0x908344
  return false;
}

/**
* @brief Goes to the beginning of the animatino if health is below 30
* @param *anim_delay_instr The parameters of the animation delay function
* @return bool true, indicating the animation was modified
*/
static bool Samus_AnimDelayFunc_6_GotoStartIfLittleHealth(const uint8 *anim_delay_instr) {  // 0x908346
  samus_anim_frame = (int16)samus_health < 30 ? samus_anim_frame + 1 : 0;
  return true;
}

/**
* @brief Sets the movement handler to drained and goes to the next frame
* @param *anim_delay_instr The parameters of the animation delay function
* @return bool true, indicating the animation was modified
*/
static bool Samus_AnimDelayFunc_7_SetDrainedHandler(const uint8 *anim_delay_instr) {  // 0x908360
  samus_movement_handler = FUNC16(Samus_MovementHandler_DrainedCrouching);
  samus_anim_frame++;
  return true;
}

/**
* @brief Set the new pose transition to parameter 1
* @param *anim_delay_instr The parameters of the animation delay function
* @return bool false, indicating the animation was not modified
*/
static bool Samus_AnimDelayFunc_13_TransToPose(const uint8 *anim_delay_instr) {  // 0x9084B6
  samus_new_pose_transitional = anim_delay_instr[1];
  samus_new_pose_transitional_command = 3;
  return false;
}

/**
* @brief If Samus is not jumping, enable the auto jump hack and set the new pose transition
* @param *anim_delay_instr The parameters of the animation delay function
* @return bool false, indicating the animation was not modified
*/
static bool Samus_AnimDelayFunc_8_AutoJumpHack_TransToPoseNoJump(const uint8 *anim_delay_instr) {  // 0x908370
  if (samus_input_handler == FUNC16(Samus_InputHandler_Demo))
    return Samus_AnimDelayFunc_13_TransToPose(anim_delay_instr);
  if (samus_new_pose != kPose_4B_FaceR_Jumptrans
      && samus_new_pose != kPose_4C_FaceL_Jumptrans
      && samus_new_pose != kPose_19_FaceR_SpinJump
      && samus_new_pose != kPose_1A_FaceL_SpinJump) {
    samus_input_handler = FUNC16(Samus_InputHandler_AutoJump);
    return Samus_AnimDelayFunc_13_TransToPose(anim_delay_instr);
  }
  return false;
}

/**
* @brief Set the new pose transition based on the Y speed and item equipped, and set the transition animation to finish
* @param *anim_delay_instr The parameters of the animation delay function
* @return bool false, indicating the animation was not modified
*/
static bool Samus_AnimDelayFunc_9_TransToPose_ItemEquipped_YSpeed(const uint8 *anim_delay_instr) {  // 0x90839A
  if (equipped_items & GET_WORD(anim_delay_instr + 1)) {
    if (samus_y_speed == 0 && samus_y_subspeed == 0)
      samus_new_pose_transitional = anim_delay_instr[5];
    else
      samus_new_pose_transitional = anim_delay_instr[6];
  }
  else if (samus_y_speed == 0 && samus_y_subspeed == 0) {
    samus_new_pose_transitional = anim_delay_instr[3];
  }
  else {
    samus_new_pose_transitional = anim_delay_instr[4];
  }
  samus_new_pose_transitional_command = 3;
  return false;
}

static bool UNUSED_Samus_AnimDelayFunc_10_TransToPose_YSpeed(const uint8 *anim_delay_instr) {  // 0x9083F6
  if (samus_y_speed == 0 && samus_y_subspeed == 0)
    samus_new_pose_transitional = anim_delay_instr[1];
  else
    samus_new_pose_transitional = anim_delay_instr[2];
  samus_new_pose_transitional_command = 3;
  return false;
}

/**
* @brief Sets the animation and SFX to play based on if Samus is submerged and if she has screw attack or space jump enabled
* @param *anim_delay_instr The parameters of the animation delay function
* @return bool true, indicating the animation was modified
*/
static bool Samus_AnimDelayFunc_11_SelectDelaySequenceWalljump(const uint8 *anim_delay_instr) {  // 0x90841D
  if (!(equipped_items & kItem_GravitySuit)) {
    int16 samus_top_bound = Samus_GetTopBound();
    if ((int16)fx_y_pos < 0) {
      if (0 <= (int16)lava_acid_y_pos && (int16)lava_acid_y_pos < samus_top_bound) {
        QueueSfx1_Max6(kSfx1_SpinJump);
        samus_anim_frame += 1;
        return true;
      }
    }
    else if ((int16)fx_y_pos < samus_top_bound && !(fx_liquid_options & kFxLiquidOption_4_LiquidPhysicsDisabled)) {
      QueueSfx1_Max6(kSfx1_SpinJump);
      samus_anim_frame += 1;
      return true;
    }
  }
  if (equipped_items & kItem_ScrewAttack) {
    QueueSfx1_Max6(kSfx1_ScrewAttack);
    samus_anim_frame += 21;
  }
  else {
    if (equipped_items & kItem_SpaceJump) {
      QueueSfx1_Max6(kSfx1_SpaceJump);
      samus_anim_frame += 11;
    }
    else {
      QueueSfx1_Max6(kSfx1_SpinJump);
      samus_anim_frame += 1;
    }
  }
  return true;
}

static bool UNUSED_Samus_AnimDelayFunc_12_TransToPose_ItemEquipped(const uint8 *anim_delay_instr) {  // 0x90848B
  if (equipped_items & GET_WORD(anim_delay_instr + 1))
    samus_new_pose_transitional = anim_delay_instr[4];
  else
    samus_new_pose_transitional = anim_delay_instr[3];
  samus_new_pose_transitional_command = 3;
  return false;
}

/**
* @brief Reset the animation back by the amount of bytes specified by parameter 1
* @param *anim_delay_instr The parameters of the animation delay function
* @return bool true, indicating the animation was modified
*/
static bool Samus_AnimDelayFunc_14_Goto(const uint8 *anim_delay_instr) {  // 0x9084C7
  samus_anim_frame -= anim_delay_instr[1];
  return true;
}

/**
* @brief Reset the animation
* @param *anim_delay_instr The parameters of the animation delay function
* @return bool true, indicating the animation was modified
*/
static bool Samus_AnimDelayFunc_15_GotoStart(const uint8 *anim_delay_instr) {  // 0x9084DB
  samus_anim_frame = 0;
  return true;
}

/**
* @brief Does not modify animation delay
* @param *anim_delay_instr The parameters of the animation delay function
* @return uint8 0 if running or speed boosting, else the animation delay function
*/
static uint8 Samus_HandleSpeedBoosterAnimDelay(const uint8 *anim_delay_instr) {  // 0x90852C
  if (!samus_has_momentum_flag || !(joypad1_lastkeys & button_config_run) || samus_movement_type != kMovementType_01_Running)
    return anim_delay_instr[0];
  if (!(equipped_items & kItem_SpeedBooster)) {
    samus_anim_frame = 0;
    samus_anim_frame_timer = kDefaultAnimFrames[0] + samus_anim_frame_buffer;
    return 0;
  }
  if (--speed_boost_timer != 0)
    return anim_delay_instr[0];
  if (!(speed_boost_counter & SPEED_BOOST_THRESHOLD)) {
    speed_boost_counter += 1;
    if (speed_boost_counter & SPEED_BOOST_THRESHOLD) {
      // The original code forgets to preserve A here.
      samus_echoes_sound_flag = 1;
      QueueSfx3_Max6(kSfx3_SpeedBooster);
      //next_idx = 0x103; // bug!
    }
  }
  speed_boost_timer = LOBYTE(kSpeedBoostToCtr[speed_boost_counter]);
  samus_anim_frame = 0;
  samus_anim_frame_timer = kSpeedBoostToAnimFrames[speed_boost_counter][0] + samus_anim_frame_buffer;
  return 0;
}

typedef bool Func_AnimDelay(const uint8* jp);
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
  UNUSED_Samus_AnimDelayFunc_12_TransToPose_ItemEquipped,
  Samus_AnimDelayFunc_13_TransToPose,
  Samus_AnimDelayFunc_14_Goto,
  Samus_AnimDelayFunc_15_GotoStart,
};

/**
* @brief Handles Samus' animation frames and transition frames
*/
static void Samus_HandleAnimDelay(void) {
  const uint8 *anim_delay_ptr = get_AnimationDelayData(samus_pose);
  if (anim_delay_ptr[samus_anim_frame] & 0x80) {
    uint8 anim_delay_func = Samus_HandleSpeedBoosterAnimDelay(anim_delay_ptr + samus_anim_frame);
    if (kAnimDelayFuncs[anim_delay_func & 0xF](anim_delay_ptr + samus_anim_frame))
      samus_anim_frame_timer = anim_delay_ptr[samus_anim_frame] + samus_anim_frame_buffer;
  }
  else {
    // Samus_HandleNormalAnimDelay() {  // 0x9084E3
    // Port code inlines the function for some reason
    if (samus_has_momentum_flag && samus_movement_type == kMovementType_01_Running) {
      anim_delay_ptr = (equipped_items & kItem_SpeedBooster) ? kSpeedBoostToAnimFrames[speed_boost_counter]
                                                             : kDefaultAnimFrames;
    }
    samus_anim_frame_timer = anim_delay_ptr[samus_anim_frame] + samus_anim_frame_buffer;
    // }
  }
}

static Func_U8 *const kSamusIsBottomDrawnFuncs[28] = {  // 0x9085E2
  [kMovementType_00_Standing]                                             = SamusBottomDrawn_0_Standing,
  [kMovementType_01_Running]                                              = SamusBottomDrawn_1_FlagDrawn,
  [kMovementType_02_NormalJumping]                                        = SamusBottomDrawn_1_FlagDrawn,
  [kMovementType_03_SpinJumping]                                          = SamusBottomDrawn_3_SpinJump,
  [kMovementType_04_MorphBallOnGround]                                    = SamusBottomDrawn_4_FlagNotDrawn,
  [kMovementType_05_Crouching]                                            = SamusBottomDrawn_1_FlagDrawn,
  [kMovementType_06_Falling]                                              = SamusBottomDrawn_1_FlagDrawn,
  [kMovementType_07_Unused]                                               = SamusBottomDrawn_4_FlagNotDrawn,
  [kMovementType_08_MorphBallFalling]                                     = SamusBottomDrawn_4_FlagNotDrawn,
  [kMovementType_09_Unused]                                               = SamusBottomDrawn_4_FlagNotDrawn,
  [kMovementType_0A_KnockbackOrCrystalFlashEnding]                        = SamusBottomDrawn_A_Knockback_CrystalFlashEnd,
  [kMovementType_0B_Unused]                                               = SamusBottomDrawn_1_FlagDrawn,
  [kMovementType_0C_Unused]                                               = SamusBottomDrawn_1_FlagDrawn,
  [kMovementType_0D_Unused]                                               = UNUSED_SamusBottomDrawn_D,
  [kMovementType_0E_TurningAroundOnGround]                                = SamusBottomDrawn_1_FlagDrawn,
  [kMovementType_0F_Crouch_Stand_Morph_Unmorph_Transition]                = SamusBottomDrawn_F_Transitions,
  [kMovementType_10_Moonwalking]                                          = SamusBottomDrawn_1_FlagDrawn,
  [kMovementType_11_SpringBallOnGround]                                   = SamusBottomDrawn_4_FlagNotDrawn,
  [kMovementType_12_SpringBallInAir]                                      = SamusBottomDrawn_4_FlagNotDrawn,
  [kMovementType_13_SpringBallFalling]                                    = SamusBottomDrawn_4_FlagNotDrawn,
  [kMovementType_14_WallJumping]                                          = SamusBottomDrawn_14_WallJump,
  [kMovementType_15_RanIntoWall]                                          = SamusBottomDrawn_1_FlagDrawn,
  [kMovementType_16_Grappling]                                            = SamusBottomDrawn_1_FlagDrawn,
  [kMovementType_17_TurningAroundJumping]                                 = SamusBottomDrawn_1_FlagDrawn,
  [kMovementType_18_TurningAroundFalling]                                 = SamusBottomDrawn_1_FlagDrawn,
  [kMovementType_19_DamageBoost]                                          = SamusBottomDrawn_19_DamageBoost,
  [kMovementType_1A_GrabbedByDraygon]                                     = SamusBottomDrawn_1_FlagDrawn,
  [kMovementType_1B_Shinespark_CrystalFlash_Drained_DamagedByMotherBrain] = SamusBottomDrawn_1B_Shinespark_CrystalFlash_Drained_MBDamaged,
};

/**
* @brief Handles drawing Samus' spritemap and animation definition
*/
void Samus_Draw(void) {
  if (samus_knockback_timer != 0 || samus_invincibility_timer == 0 || samus_shine_timer != 0 || (nmi_frame_counter_word & 1) == 0) {
    samus_top_half_spritemap_index = kSamusPoseToBaseSpritemapIndexTop[samus_pose] + samus_anim_frame;
    Point16U spritemap_pos = Samus_CalcSpritemapPos(samus_pose);
    DrawSamusSpritemap(samus_top_half_spritemap_index, spritemap_pos.x, spritemap_pos.y);
    if (kSamusIsBottomDrawnFuncs[samus_movement_type]()) {
      samus_bottom_half_spritemap_index = kSamusPoseToBaseSpritemapIndexBottom[samus_pose] + samus_anim_frame;
      DrawSamusSpritemap(samus_bottom_half_spritemap_index, samus_spritemap_x_pos, samus_spritemap_y_pos);
    }
  }
  SetSamusTilesDefsForCurAnim();
}

/**
* @brief Does nothing
* @return uint8 1, indicating that Samus' bottom half is drawn
*/
uint8 SamusBottomDrawn_1_FlagDrawn(void) {  // 0x908686
  return 1;
}

/**
* @brief Sets the bottom spritemap to 0
* @return uint8 0, indicating that Samus' bottom half is not drawn
*/
uint8 SamusBottomDrawn_4_FlagNotDrawn(void) {  // 0x908688
  samus_bottom_half_spritemap_index = 0;
  return 0;
}

/**
* @brief If Samus is facing forward in her normal suit, draw a sprite to cover her left chest
* @return uint8 1, indicating that Samus' bottom half is drawn
*/
uint8 SamusBottomDrawn_0_Standing(void) {  // 0x90868D
  if (samus_pose == kPose_00_FaceF_Powersuit) {
    OamEnt *oam = gOamEnt(oam_next_ptr);
    oam->xcoord = samus_x_pos - 7 - layer1_x_pos;
    oam->ycoord = samus_y_pos - 17 - layer1_y_pos;
    WORD(oam->charnum) = OAM_DATA(0, 0, 3, 4, 33);
    oam_next_ptr += sizeof(OamEnt);
  }
  return 1;
}

/**
* @brief Sets the bottom spritemap to 0 if screw attacking or space jumping
* @return uint8 1 if screw attacking or space jumping, indicating that Samus' bottom half is drawn, else 0,
* indicating that Samus' bottom half is not drawn
*/
uint8 SamusBottomDrawn_3_SpinJump(void) {  // 0x9086C6
  if (samus_pose == kPose_81_FaceR_Screwattack || samus_pose == kPose_82_FaceL_Screwattack
      || samus_pose == kPose_1B_FaceR_SpaceJump || samus_pose == kPose_1C_FaceL_SpaceJump
      || samus_anim_frame == 0 || samus_anim_frame >= 11) {
    return 1;
  }
  samus_bottom_half_spritemap_index = 0;
  return 0;
}

/**
* @brief Sets the bottom spritemap to 0 if crystal flash is ending
* @return uint8 0 if crystal flash is ending, indicating that Samus' bottom half is not drawn, else 1,
* indicating that Samus' bottom half is drawn
*/
uint8 SamusBottomDrawn_A_Knockback_CrystalFlashEnd(void) {  // 0x9086EE
  if (samus_pose != kPose_D7_FaceR_CrystalFlashEnd && samus_pose != kPose_D8_FaceL_CrystalFlashEnd
      || samus_anim_frame >= 3) {
    return 1;
  }
  samus_bottom_half_spritemap_index = 0;
  return 0;
}

/**
* @brief Sets the bottom spritemap to 0 if not in a transition pose
* @return uint8 1 if in a transition pose, indicating that Samus' bottom half is drawn, else 0,
* indicating that Samus' bottom half is not drawn
*/
uint8 SamusBottomDrawn_F_Transitions(void) {  // 0x90870C
  if (samus_pose >= kPose_F1_FaceR_CrouchTrans_AimU)
    return 1;

  // Following chunk of code is unused
  if (samus_pose >= kPose_DB) {
    if (samus_pose < kPose_DD) {
      if (samus_anim_frame != 0) {
        samus_bottom_half_spritemap_index = 0;
        return 0;
      }
    }
    else if (samus_anim_frame != 2) {
      samus_bottom_half_spritemap_index = 0;
      return 0;
    }
    return 1;
  }

  if (samus_pose == kPose_35_FaceR_CrouchTrans || samus_pose == kPose_36_FaceL_CrouchTrans
      || samus_pose == kPose_3B_FaceR_StandTrans || samus_pose == kPose_3C_FaceL_StandTrans) {
    return 1;
  }
  samus_bottom_half_spritemap_index = 0;
  return 0;
}

uint8 UNUSED_SamusBottomDrawn_D(void) {  // 0x90874C
  if (samus_pose != 0x65 && samus_pose != 0x66 || samus_anim_frame < 1) {
    return 1;
  }
  samus_bottom_half_spritemap_index = 0;
  return 0;
}

/**
* @brief Sets the bottom spritemap to 0 if wall jumping
* @return uint8 1 if not wall jumping, indicating that Samus' bottom half is drawn, else 0,
* indicating that Samus' bottom half is not drawn
*/
uint8 SamusBottomDrawn_14_WallJump(void) {  // 0x908768
  if (samus_anim_frame < 3 || samus_anim_frame >= 13)
    return 1;
  samus_bottom_half_spritemap_index = 0;
  return 0;
}

/**
* @brief Sets the bottom spritemap to 0 if spinning during damage boost
* @return uint8 1 if not spinning, indicating that Samus' bottom half is drawn, else 0,
* indicating that Samus' bottom half is not drawn
*/
uint8 SamusBottomDrawn_19_DamageBoost(void) {  // 0x90877C
  if (samus_anim_frame < 2 || samus_anim_frame >= 9)
    return 1;
  samus_bottom_half_spritemap_index = 0;
  return 0;
}

/**
* @brief Does nothing
* @return uint8 1 if shinesparking non vertically or not drained crouching/falling, indicating that Samus' bottom half
* is drawn, else 0, indicating that Samus' bottom half is not drawn
*/
uint8 SamusBottomDrawn_1B_Shinespark_CrystalFlash_Drained_MBDamaged(void) {  // 0x908790
  if (samus_pose <= kPose_CE_FaceL_Shinespark_Diag) {
    if (samus_pose != kPose_CB_FaceR_Shinespark_Vert && samus_pose != kPose_CC_FaceL_Shinespark_Vert)
      return 1;
  }
  else if (samus_pose != kPose_E8_FaceR_Drained_CrouchFalling && samus_pose != kPose_E9_FaceL_Drained_CrouchFalling
           || samus_anim_frame >= 2) {
    return 1;
  }
  samus_bottom_half_spritemap_index = 0;
  return 0;
}

/**
* @brief Updates and draws each speed boost echo behind Samus
*/
void Samus_DrawEchoes(void) {  // 0x9087BD
  if ((speed_echoes_index & 0x8000) == 0) {
    if (speed_boost_counter == SPEED_BOOST_THRESHOLD) {
      if (speed_echo_xpos[1] != 0)
        Samus_DrawEcho(2);
      if (speed_echo_xpos[0] != 0)
        Samus_DrawEcho(0);
    }
    return;
  }

  for (int speed_echoes_idx = 2; speed_echoes_idx >= 0; speed_echoes_idx -= 2) {
    int idx = speed_echoes_idx >> 1;
    if (speed_echo_xpos[idx] == 0)
      continue;

    if (speed_echo_ypos[idx] != samus_y_pos) {
      if ((int16)speed_echo_ypos[idx] < (int16)samus_y_pos)
        speed_echo_ypos[idx] += 2;
      else
        speed_echo_ypos[idx] -= 2;
    }

    if ((int16)speed_echo_xspeed[idx] < 0) {
      speed_echo_xpos[idx] += speed_echo_xspeed[idx];
      if ((int16)speed_echo_xpos[idx] < (int16)samus_x_pos) {
        speed_echo_xpos[idx] = 0;
        continue;
      }
    }

    else {
      speed_echo_xpos[idx] += speed_echo_xspeed[idx];
      if ((int16)speed_echo_xpos[idx] >= (int16)samus_x_pos) {
        speed_echo_xpos[idx] = 0;
        continue;
      }
    }

    Samus_DrawEcho(speed_echoes_idx);
  }
  if (speed_echo_xpos[1] == 0 && speed_echo_xpos[0] == 0)
    speed_echoes_index = 0;
}

/**
* @brief Draws the incoming speed boost echo
* @param speed_echoes_idx The index of the speed boost echo
*/
void Samus_DrawEcho(uint16 speed_echoes_idx) {  // 0x908855
  int idx = speed_echoes_idx >> 1;
  int16 samus_gfx_y_offset = speed_echo_ypos[idx] - kPoseParams[samus_pose].y_offset_proj_origin_to_gfx - layer1_y_pos;

  if (0 <= samus_gfx_y_offset && samus_gfx_y_offset < 248) {
    DrawSamusSpritemap(samus_top_half_spritemap_index, speed_echo_xpos[idx] - layer1_x_pos, samus_gfx_y_offset);
    if (samus_bottom_half_spritemap_index != 0)
      DrawSamusSpritemap(samus_bottom_half_spritemap_index, speed_echo_xpos[idx] - layer1_x_pos, samus_gfx_y_offset);
  }
}

/**
* @brief Draw the speed boost echo that circles Samus when shinespark ends
* @param speed_echoes_idx The index of the speed boost echo
*/
void Samus_DrawShinesparkCrashEchoes(uint16 speed_echoes_idx) {  // 0x9088BA
  if ((nmi_frame_counter_word & 1) != 0) {
    int idx = speed_echoes_idx >> 1;
    uint16 samus_top_half_spritemap_table_idx = kSamusPoseToBaseSpritemapIndexTop[samus_pose] + samus_anim_frame;
    int16 samus_gfx_y_offset = speed_echo_ypos[idx] - kPoseParams[samus_pose].y_offset_proj_origin_to_gfx - layer1_y_pos;

    if (0 <= samus_gfx_y_offset && samus_gfx_y_offset < 248) {
      DrawSamusSpritemap(samus_top_half_spritemap_table_idx, speed_echo_xpos[idx] - layer1_x_pos, samus_gfx_y_offset);

      if (kSamusIsBottomDrawnFuncs[samus_movement_type]()) {
        uint16 samus_bottom_half_spritemap_table_idx = kSamusPoseToBaseSpritemapIndexBottom[samus_pose] + samus_anim_frame;
        DrawSamusSpritemap(samus_bottom_half_spritemap_table_idx, speed_echo_xpos[idx] - layer1_x_pos, samus_gfx_y_offset);
      }
    }
  }
}

/**
* @brief Draws the speed boost echoes that fire off of Samus when shinespark ends
*/
void Samus_DrawShinesparkCrashEchoProjectiles(void) {  // 0x908953
  if ((nmi_frame_counter_word & 1) != 0) {
    if (speed_echo_xspeed[3] != 0)
      Samus_DrawEcho(6);
    if (speed_echo_xspeed[2] != 0)
      Samus_DrawEcho(4);
  }
}

/**
* @brief Finishes the current animation and begin drawing Samus' death animation
*/
void Samus_DrawStartingDeathAnim(void) {  // 0x908976
  if (--samus_anim_frame_timer <= 0) {
    ++samus_anim_frame;
    Samus_HandleAnimDelay();
  }
  Samus_DrawDuringDeathAnim();
}

/**
* @brief Handles drawing Samus' spritemap and animation definition for the death animation
*/
void Samus_DrawDuringDeathAnim(void) {  // 0x908998
  uint16 samus_top_half_spritemap_table_idx = kSamusPoseToBaseSpritemapIndexTop[samus_pose] + samus_anim_frame;
  Samus_CalcSpritemapPos(samus_pose);
  uint16 spritemap_x_pos = layer1_x_pos + samus_spritemap_x_pos;
  uint16 spritemap_y_pos = layer1_y_pos + samus_spritemap_y_pos;
  DrawSamusSpritemap(samus_top_half_spritemap_table_idx, spritemap_x_pos, spritemap_y_pos);

  if (kSamusIsBottomDrawnFuncs[samus_movement_type]()) {
    uint16 samus_bottom_half_spritemap_table_idx = kSamusPoseToBaseSpritemapIndexBottom[samus_pose] + samus_anim_frame;
    DrawSamusSpritemap(samus_bottom_half_spritemap_table_idx, spritemap_x_pos, spritemap_y_pos);
  }
  SetSamusTilesDefsForCurAnim();
}

/**
* @brief Handles drawing Samus' spritemap and animation definition when Samus is not animating
*/
void Samus_DrawInanimateSamus(void) {  // 0x908A00
  uint16 samus_top_half_spritemap_table_idx = kSamusPoseToBaseSpritemapIndexTop[samus_pose] + samus_anim_frame;
  Point16U spritemap_pos = Samus_CalcSpritemapPos(samus_pose);
  DrawSamusSpritemap(samus_top_half_spritemap_table_idx, spritemap_pos.x, spritemap_pos.y);

  if (kSamusIsBottomDrawnFuncs[samus_movement_type]()) {
    uint16 samus_bottom_half_spritemap_table_idx = kSamusPoseToBaseSpritemapIndexBottom[samus_pose] + samus_anim_frame;
    DrawSamusSpritemap(samus_bottom_half_spritemap_table_idx, samus_spritemap_x_pos, samus_spritemap_y_pos);
  }
  SetSamusTilesDefsForCurAnim();
}


static FuncXY_V *const kAtmosphericTypeFuncs[8] = {  // 0x908A4C
  [kAtmosphericGraphicType_0_None] = 0,
  [kAtmosphericGraphicType_1_FootstepSplashes]      = AtmosphericTypeFunc_1_2_FootstepSplash,
  [kAtmosphericGraphicType_2_FootstepSplashes]      = AtmosphericTypeFunc_1_2_FootstepSplash,
  [kAtmosphericGraphicType_3_DivingSplashes]        = AtmosphericTypeFunc_3_DivingSplash,
  [kAtmosphericGraphicType_4_LavaAcidSurfaceDamage] = AtmosphericTypeFunc_4_LavaSurfaceDmg,
  [kAtmosphericGraphicType_5_Bubbles]               = AtmosphericTypeFunc_5_Bubbles,
  [kAtmosphericGraphicType_6_LandingDust]           = AtmosphericTypeFunc_6_7_Dust,
  [kAtmosphericGraphicType_7_SpeedBoostDust]        = AtmosphericTypeFunc_6_7_Dust,
};

/**
* @brief Process each atmospheric effect and handle each atmospheric type
*/
void HandleAtmosphericEffects(void) {
  for (int atmospheric_gfx_idx = 6; atmospheric_gfx_idx >= 0; atmospheric_gfx_idx -= 2) {
    int idx = atmospheric_gfx_idx >> 1;
    if (atmospheric_gfx_frame_and_type[idx] == 0)
      continue;
    uint16 gfx_frame = LOBYTE(atmospheric_gfx_frame_and_type[idx]);
    uint16 gfx_type = HIBYTE(atmospheric_gfx_frame_and_type[idx]);

    if (--atmospheric_gfx_anim_timer[idx] != 0) {
      if (atmospheric_gfx_anim_timer[idx] & ANIM_TIMER_INACTIVE) {
        if (atmospheric_gfx_anim_timer[idx] != ANIM_TIMER_INACTIVE)
          continue;
        atmospheric_gfx_anim_timer[idx] = kAtmosphericGraphicAnimationTimers[gfx_type][gfx_frame];
      }
    }

    else {
      atmospheric_gfx_anim_timer[idx] = kAtmosphericGraphicAnimationTimers[gfx_type][gfx_frame];
      if ((uint8)++atmospheric_gfx_frame_and_type[idx] >= kAtmosphericTypeNumFrames[gfx_type]) {
        atmospheric_gfx_frame_and_type[idx] = 0;
        continue;
      }
    }
    kAtmosphericTypeFuncs[gfx_type](2 * gfx_type, atmospheric_gfx_idx);
  }
}

/**
* @brief Draws the atmospheric graphic to the screen from OAM
* @param gfx_type The type of the atmospheric graphic
* @param atmospheric_gfx_idx The atmospheric graphic index
*/
void AtmosphericTypeFunc_1_2_FootstepSplash(uint16 gfx_type, uint16 atmospheric_gfx_idx) {  // 0x908AC5
  int idx = atmospheric_gfx_idx >> 1;
  uint16 gfx_frame = 2 * LOBYTE(atmospheric_gfx_frame_and_type[idx]);
  int16 oam_x_pos = atmospheric_gfx_x_pos[idx] - layer1_x_pos - 4;
  if (0 <= oam_x_pos && oam_x_pos < (16*16)) {
    OamEnt *oam_entry = gOamEnt(oam_next_ptr);
    oam_entry->xcoord = oam_x_pos;
    int16 oam_y_pos = atmospheric_gfx_y_pos[idx] - layer1_y_pos - 4;
    if (0 <= oam_y_pos && oam_y_pos < (16*16)) {
      oam_entry->ycoord = oam_y_pos;
      WORD(oam_entry->charnum) = kAtmosphericTypeTileNumAndAttributes[gfx_type >> 1][gfx_frame >> 1];
      oam_next_ptr += sizeof(OamEnt);
    }
  }
}

/**
* @brief Draws the atmospheric graphic from Samus graphics
* @param gfx_type The type of the atmospheric graphic
* @param atmospheric_gfx_idx The atmospheric graphic index
*/
void AtmosphericTypeFunc_Common(uint16 atmospheric_gfx_idx, uint16 samus_spritemap_table_idx) {  // 0x908B74
  int idx = atmospheric_gfx_idx >> 1;
  int16 spritemap_x_pos = atmospheric_gfx_x_pos[idx] - layer1_x_pos;
  int16 spritemap_y_pos = atmospheric_gfx_y_pos[idx] - layer1_y_pos;
  if (0 <= spritemap_y_pos && spritemap_y_pos < (16*16)) {
    DrawSamusSpritemap(samus_spritemap_table_idx, spritemap_x_pos, spritemap_y_pos);
  }
}

/**
* @brief Draws the diving splash graphic from Samus graphics
* @param gfx_type The type of the atmospheric graphic
* @param atmospheric_gfx_idx The atmospheric graphic index
*/
void AtmosphericTypeFunc_3_DivingSplash(uint16 gfx_type, uint16 atmospheric_gfx_idx) {  // 0x908B16
  int idx = atmospheric_gfx_idx >> 1;
  uint16 gfx_frame = LOBYTE(atmospheric_gfx_frame_and_type[idx]);
  atmospheric_gfx_y_pos[idx] = fx_y_pos;
  AtmosphericTypeFunc_Common(atmospheric_gfx_idx, gfx_frame + 399);
}

/**
* @brief Draws the lava/acid damage graphic from OAM
* @param gfx_type The type of the atmospheric graphic
* @param atmospheric_gfx_idx The atmospheric graphic index
*/
void AtmosphericTypeFunc_4_LavaSurfaceDmg(uint16 gfx_type, uint16 atmospheric_gfx_idx) {  // 0x908B2E
  int idx = atmospheric_gfx_idx >> 1;
  // Slots 2-3 draw to the left
  if (atmospheric_gfx_idx >= 4)
    --atmospheric_gfx_x_pos[idx];
  // Slots 0-1 draw to the right
  else
    ++atmospheric_gfx_x_pos[idx];
  --atmospheric_gfx_y_pos[atmospheric_gfx_idx >> 1];
  AtmosphericTypeFunc_1_2_FootstepSplash(gfx_type, atmospheric_gfx_idx);
}

/**
* @brief Draws the landing/speed boost dust graphic from OAM
* @param gfx_type The type of the atmospheric graphic
* @param atmospheric_gfx_idx The atmospheric graphic index
*/
void AtmosphericTypeFunc_6_7_Dust(uint16 gfx_type, uint16 atmospheric_gfx_idx) {  // 0x908B57
  --atmospheric_gfx_y_pos[atmospheric_gfx_idx >> 1];
  AtmosphericTypeFunc_1_2_FootstepSplash(gfx_type, atmospheric_gfx_idx);
}

/**
* @brief Draws the bubble graphic from Samus graphics
* @param gfx_type The type of the atmospheric graphic
* @param atmospheric_gfx_idx The atmospheric graphic index
*/
void AtmosphericTypeFunc_5_Bubbles(uint16 gfx_type, uint16 atmospheric_gfx_idx) {  // 0x908B64
  uint16 gfx_frame = LOBYTE(atmospheric_gfx_frame_and_type[atmospheric_gfx_idx >> 1]);
  AtmosphericTypeFunc_Common(atmospheric_gfx_idx, gfx_frame + 390);
}

static Func_Y_To_Point16U *const kSamus_CalcSpritemapPos[28] = {  // 0x908C1F
  [kMovementType_00_Standing]                                             = &Samus_CalcSpritemapPos_Standing,
  [kMovementType_01_Running]                                              = &Samus_CalcSpritemapPos_Default,
  [kMovementType_02_NormalJumping]                                        = &Samus_CalcSpritemapPos_Default,
  [kMovementType_03_SpinJumping]                                          = &Samus_CalcSpritemapPos_Default,
  [kMovementType_04_MorphBallOnGround]                                    = &Samus_CalcSpritemapPos_Default,
  [kMovementType_05_Crouching]                                            = &Samus_CalcSpritemapPos_Default,
  [kMovementType_06_Falling]                                              = &Samus_CalcSpritemapPos_Default,
  [kMovementType_07_Unused]                                               = &Samus_CalcSpritemapPos_Default,
  [kMovementType_08_MorphBallFalling]                                     = &Samus_CalcSpritemapPos_Default,
  [kMovementType_09_Unused]                                               = &Samus_CalcSpritemapPos_Default,
  [kMovementType_0A_KnockbackOrCrystalFlashEnding]                        = &Samus_CalcSpritemapPos_Default,
  [kMovementType_0B_Unused]                                               = &Samus_CalcSpritemapPos_Default,
  [kMovementType_0C_Unused]                                               = &Samus_CalcSpritemapPos_Default,
  [kMovementType_0D_Unused]                                               = &Samus_CalcSpritemapPos_Default,
  [kMovementType_0E_TurningAroundOnGround]                                = &Samus_CalcSpritemapPos_Default,
  [kMovementType_0F_Crouch_Stand_Morph_Unmorph_Transition]                = &Samus_CalcSpritemapPos_Transitions,
  [kMovementType_10_Moonwalking]                                          = &Samus_CalcSpritemapPos_Default,
  [kMovementType_11_SpringBallOnGround]                                   = &Samus_CalcSpritemapPos_Default,
  [kMovementType_12_SpringBallInAir]                                      = &Samus_CalcSpritemapPos_Default,
  [kMovementType_13_SpringBallFalling]                                    = &Samus_CalcSpritemapPos_Default,
  [kMovementType_14_WallJumping]                                          = &Samus_CalcSpritemapPos_Default,
  [kMovementType_15_RanIntoWall]                                          = &Samus_CalcSpritemapPos_Default,
  [kMovementType_16_Grappling]                                            = &Samus_CalcSpritemapPos_Default,
  [kMovementType_17_TurningAroundJumping]                                 = &Samus_CalcSpritemapPos_Default,
  [kMovementType_18_TurningAroundFalling]                                 = &Samus_CalcSpritemapPos_Default,
  [kMovementType_19_DamageBoost]                                          = &Samus_CalcSpritemapPos_Default,
  [kMovementType_1A_GrabbedByDraygon]                                     = &Samus_CalcSpritemapPos_Default,
  [kMovementType_1B_Shinespark_CrystalFlash_Drained_DamagedByMotherBrain] = &Samus_CalcSpritemapPos_Special,
};

/**
* @brief Calculate spritemap X and Y position of Samus
* @param samus_pose_ The current Samus pose
* @return Point16U the X and Y Samus spritemap variables
*/
Point16U Samus_CalcSpritemapPos(uint16 samus_pose_) {
  Point16U spritemap_pos;

  if (ceres_status & kCeresStatus_8000_ElevatorRoomRotate) {
    uint16 old_x = samus_x_pos, old_y = samus_y_pos;
    Samus_CalcPos_Mode7();
    spritemap_pos = kSamus_CalcSpritemapPos[samus_movement_type](samus_pose_);
    samus_x_pos = old_x, samus_y_pos = old_y;
  }
  else {
    spritemap_pos = kSamus_CalcSpritemapPos[samus_movement_type](samus_pose_);
  }
  return MakePoint16U(spritemap_pos.x, spritemap_pos.y);
}

/**
* @brief Calculate normal spritemap X and Y position of Samus
* @param samus_pose_ The current Samus pose
* @return Point16U the X and Y Samus spritemap vairables
*/
Point16U Samus_CalcSpritemapPos_Default(uint16 samus_pose_) {  // 0x908C94
  int16 samus_gfx_y_offset = (int8)kPoseParams[samus_pose_].y_offset_proj_origin_to_gfx;
  samus_spritemap_y_pos = samus_y_pos - samus_gfx_y_offset - layer1_y_pos;
  samus_spritemap_x_pos = samus_x_pos - layer1_x_pos;
  return MakePoint16U(samus_spritemap_x_pos, samus_spritemap_y_pos);
}

/**
* @brief Calculate the spritemap X and Y position of Samus while she is standing still
* @param samus_pose_ The current Samus pose
* @return Point16U the X and Y Samus spritemap variables
*/
Point16U Samus_CalcSpritemapPos_Standing(uint16 samus_pose_) {  // 0x908CC3
  static const uint8 kSamusGfxYOffsets_LandFromJump[16] = {
    [4*(kPose_A4_FaceR_LandJump-kPose_A4_FaceR_LandJump)]     = 3, 6, 0, 0,
    [4*(kPose_A5_FaceL_LandJump-kPose_A4_FaceR_LandJump)]     = 3, 6, 0, 0,
    [4*(kPose_A6_FaceR_LandSpinJump-kPose_A4_FaceR_LandJump)] = 3, 3, 6, 0,
    [4*(kPose_A7_FaceL_LandSpinJump-kPose_A4_FaceR_LandJump)] = 3, 3, 6, 0,
  };

  if (samus_pose_ == kPose_00_FaceF_Powersuit || samus_pose_ == kPose_9B_FaceF_VariaGravitySuit) {
    if (samus_anim_frame >= 2) {
      samus_spritemap_y_pos = samus_y_pos - 1 - layer1_y_pos;
      samus_spritemap_x_pos = samus_x_pos - layer1_x_pos;
      return MakePoint16U(samus_spritemap_x_pos, samus_spritemap_y_pos);
    }
  }
  else if (kPose_A4_FaceR_LandJump <= samus_pose_ && samus_pose_ <= kPose_A7_FaceL_LandSpinJump) {
    uint16 samus_gfx_y_offset = WORD(kSamusGfxYOffsets_LandFromJump[4 * (samus_pose_ - kPose_A4_FaceR_LandJump) + samus_anim_frame]);
    samus_spritemap_y_pos = samus_y_pos - samus_gfx_y_offset - layer1_y_pos;
    samus_spritemap_x_pos = samus_x_pos - layer1_x_pos;
    return MakePoint16U(samus_spritemap_x_pos, samus_spritemap_y_pos);
  }
  return Samus_CalcSpritemapPos_Default(samus_pose_);
}

/**
* @brief Calculate the spritemap X and Y position of Samus while she's in a transition pose
* @param samus_pose_ The current Samus pose
* @return Point16U the X and Y Samus spritemap variables
*/
Point16U Samus_CalcSpritemapPos_Transitions(uint16 samus_pose_) {  // 0x908D3C
  static const int8 kSamusGfxYOffsets_Transition[24] = {
    [2*(kPose_35_FaceR_CrouchTrans-kPose_35_FaceR_CrouchTrans)]  = -8,  0,
    [2*(kPose_36_FaceL_CrouchTrans-kPose_35_FaceR_CrouchTrans)]  = -8,  0,
    [2*(kPose_37_FaceR_MorphTrans-kPose_35_FaceR_CrouchTrans)]   = -4, -2,
    [2*(kPose_38_FaceL_MorphTrans-kPose_35_FaceR_CrouchTrans)]   = -4, -2,
    [2*(kPose_39-kPose_35_FaceR_CrouchTrans)]                    =  0,  0,
    [2*(kPose_3A-kPose_35_FaceR_CrouchTrans)]                    =  0,  0,
    [2*(kPose_3B_FaceR_StandTrans-kPose_35_FaceR_CrouchTrans)]   = -4,  0,
    [2*(kPose_3C_FaceL_StandTrans-kPose_35_FaceR_CrouchTrans)]   = -4,  0,
    [2*(kPose_3D_FaceR_UnmorphTrans-kPose_35_FaceR_CrouchTrans)] =  5,  4,
    [2*(kPose_3E_FaceL_UnmorphTrans-kPose_35_FaceR_CrouchTrans)] =  5,  4,
    [2*(kPose_3F-kPose_35_FaceR_CrouchTrans)]                    =  0,  0,
    [2*(kPose_40-kPose_35_FaceR_CrouchTrans)]                    =  0,  0,
  };

  if (kPose_35_FaceR_CrouchTrans <= samus_pose_ && samus_pose_ <= kPose_40) {
    int samus_gfx_y_offset = kSamusGfxYOffsets_Transition[2 * (samus_pose_ - kPose_35_FaceR_CrouchTrans) + samus_anim_frame];
    samus_spritemap_y_pos = samus_y_pos + samus_gfx_y_offset - layer1_y_pos;
    samus_spritemap_x_pos = samus_x_pos - layer1_x_pos;
    return MakePoint16U(samus_spritemap_x_pos, samus_spritemap_y_pos);
  }
  return Samus_CalcSpritemapPos_Default(samus_pose_);
}

/**
* @brief Calculate the spritemap X and Y position of Samus while she's in a special pose (shinespark, crystal flash, drained)
* @param samus_pose_ The current Samus pose
* @return Point16U the X and Y Samus spritemap variables
*/
Point16U Samus_CalcSpritemapPos_Special(uint16 samus_pose_) {  // 0x908D98
  static const int8 kSamusGfxYOffsets_Special[32] = {
     7, 5, -8, -8, -8, -8, -8, -5, 4, 4, 4, 4, 0, 0, 4, -3,
    -5, 0,  0,  4, -3, -5, -3,  4, 0, 0, 4, 0, 0, 4, 0,  0,
  };
  int8 samus_gfx_y_offset;

  if (samus_pose_ == kPose_E8_FaceR_Drained_CrouchFalling || samus_pose_ == kPose_E9_FaceL_Drained_CrouchFalling) {
    samus_gfx_y_offset = kSamusGfxYOffsets_Special[samus_anim_frame];
  }
  else {
    if (samus_pose_ != kPose_EA_FaceR_Drained_Stand && samus_pose_ != kPose_EB_FaceL_Drained_Stand || samus_anim_frame < 5) {
      return Samus_CalcSpritemapPos_Default(samus_pose_);
    }
    samus_gfx_y_offset = -3;
  }
  samus_spritemap_y_pos = samus_y_pos + samus_gfx_y_offset - layer1_y_pos;
  samus_spritemap_x_pos = samus_x_pos - layer1_x_pos;
  return MakePoint16U(samus_spritemap_x_pos, samus_spritemap_y_pos);
}

/**
* @brief Set the current liquid physics type for Samus if touching the liquid
*/
void SetLiquidPhysicsType(void) {  // 0x908E0F
  int16 samus_bottom_bound = Samus_GetBottomBound();
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

/**
* @brief Moves Samus X position based on base and extra speed
*/
void Samus_HandleMovement_X(void) {  // 0x908E64
  Samus_HandleExtraRunspeedX();
  Samus_MoveX(Samus_CalcBaseSpeed_X(Samus_DetermineSpeedTableEntryPtr_X()));
}

/**
* @brief Moves Samus left or right depending on acceleration and direction
* @param x_base_speed Samus X base speed
*/
void Samus_MoveX(int32 x_base_speed) {  // 0x908EA9
  int32 x_displacement;
  if (samus_x_accel_mode == kSamusXAccelMode_0_Accelerate || samus_x_accel_mode == kSamusXAccelMode_2_Decelerate) {
    if (samus_pose_x_dir == kSamusXDir_FaceLeft) {
      x_displacement = Samus_CalcDisplacementMoveLeft(x_base_speed);
    }
    else {
      x_displacement = Samus_CalcDisplacementMoveRight(x_base_speed);
    }
  }
  // Else Samus is turning around, thus move left if facing right, and vice versa
  else {
    if (samus_pose_x_dir == kSamusXDir_FaceRight) {
      x_displacement = Samus_CalcDisplacementMoveLeft(x_base_speed);
    }
    else {
      x_displacement = Samus_CalcDisplacementMoveRight(x_base_speed);
    }
  }
  
  if (x_displacement < 0)
    Samus_MoveLeft(x_displacement);
  else
    Samus_MoveRight(x_displacement);
}

/**
* @brief Moves Samus left or right depending on direction of knockback/bomb jump
*/
void Samus_MoveX_KnockbackOrBombJump(void) {  // 0x908EDF
  int32 x_base_speed, x_displacement;
  if (knockback_dir != kKnockbackDir_None) {
    x_base_speed = Samus_CalcBaseSpeed_X(Samus_DetermineSpeedTableEntryPtr_X());
    if (knockback_x_dir == kKnockbackXDir_Left) {
      x_displacement = Samus_CalcDisplacementMoveLeft(x_base_speed);
    }
    else {
      x_displacement = Samus_CalcDisplacementMoveRight(x_base_speed);
    }
  }
  else {
    x_base_speed = Samus_CalcBaseSpeed_X(addr_kSamusSpeedTable_DuringDiagonalBombJump);
    if (LOBYTE(bomb_jump_dir) == kBombJumpDir_Left) {
      x_displacement = Samus_CalcDisplacementMoveLeft(x_base_speed);
    }
    else {
      x_displacement = Samus_CalcDisplacementMoveRight(x_base_speed);
    }
  }

  if (x_displacement < 0)
    Samus_MoveLeft(x_displacement);
  else
    Samus_MoveRight(x_displacement);
}

/**
* @brief Reset speed and invert direction when Samus reaches top of bomb jump
*/
void Samus_BombJumpEnd(void) {  // 0x908F1B
  if (samus_y_dir == kSamusYDir_Up) {
    if ((int16)samus_y_speed < 0) {
      samus_y_subspeed = 0;
      samus_y_speed = 0;
      samus_y_dir = kSamusYDir_Down;
      if ((uint8)bomb_jump_dir != kBombJumpDir_Up)
        samus_x_accel_mode = kSamusXAccelMode_2_Decelerate;
    }
    else if ((int16)samus_y_speed < 1) {
      if (samus_input_handler != FUNC16(Samus_InputHandler_Demo))
        samus_input_handler = FUNC16(Samus_InputHandler_Normal);
    }
  }
}

/**
* @brief Move Samus left or right when pushed by Ridley in Ceres
*/
void Samus_MoveX_CeresRidleyPush(void) {  // 0x908F5F
  int32 x_base_speed = Samus_CalcBaseSpeed_X(Samus_DetermineSpeedTableEntryPtr_X());
  int32 x_displacement;
  if (samus_push_direction == kSamusPushDirection_Left)
    x_displacement = Samus_CalcDisplacementMoveLeft(x_base_speed);
  else
    x_displacement = Samus_CalcDisplacementMoveRight(x_base_speed);

  if (x_displacement < 0)
    Samus_MoveLeft(x_displacement);
  else
    Samus_MoveRight(x_displacement);
}

/**
* @brief Moves Samus down when pushed by Ridley in Ceres
*/
void Samus_MoveY_CeresRidleyPush(void) {  // 0x908F86
  if ((int16)samus_y_speed < 5)
    AddToHiLo(&samus_y_speed, &samus_y_subspeed, __PAIR32__(samus_y_accel, samus_y_subaccel));
  Samus_MoveDown(__PAIR32__(samus_y_speed, samus_y_subspeed));
}

/**
* @brief Handle Samus speed, direction, and acceleration when jumping
*/
void Samus_JumpingMovement(void) {  // 0x908FB3
  Samus_HandleExtraRunspeedX();
  if (samus_pose == kPose_4B_FaceR_Jumptrans || samus_pose == kPose_4C_FaceL_Jumptrans
      || kPose_55_FaceR_Jumptrans_AimU <= samus_pose && samus_pose <= kPose_5A_FaceL_Jumptrans_AimDL) {
    samus_x_accel_mode = kSamusXAccelMode_0_Accelerate;
    Samus_Move_NoBaseSpeed_X();
    Samus_MoveExtraY();
    return;
  }
  // Begin falling when let go of jump button or reach peak of jump
  if (samus_y_dir == kSamusYDir_Up && (!(joypad1_lastkeys & button_config_jump) || (int16)samus_y_speed < 0)) {
    samus_y_subspeed = 0;
    samus_y_speed = 0;
    samus_y_dir = kSamusYDir_Down;
  }

  Pair_Bool_Amt x_speed = Samus_CalcBaseSpeed_NoDecel_X(Samus_DetermineSpeedTableEntryPtr_X());
  if (samus_movement_type == kMovementType_14_WallJumping) {
    if (samus_x_accel_mode == kSamusXAccelMode_0_Accelerate)
      samus_x_accel_mode = kSamusXAccelMode_2_Decelerate;
    Samus_MoveX(x_speed.amt);
  }
  else if (samus_x_accel_mode != kSamusXAccelMode_0_Accelerate
           || (joypad1_lastkeys & kButton_Right) || (joypad1_lastkeys & kButton_Left)) {
    Samus_MoveX(x_speed.amt);
  }
  else {
    samus_x_base_speed = 0;
    samus_x_base_subspeed = 0;
    samus_collision_flag = 0;
  }

  Samus_MoveY_WithSpeedCalc();
}

/**
* @brief Handle Samus speed, direction, and acceleration when spin jumping
*/
void Samus_SpinJumpMovement(void) {  // 0x909040
  static const uint16 kSamusPhys_MaxDistFromWallForWallJump = 8;

  Samus_HandleExtraRunspeedX();
  // Begin falling when let go of jump button or reach peak of jump
  if (samus_y_dir == kSamusYDir_Up && (!(joypad1_lastkeys & button_config_jump) || (int16)samus_y_speed < 0)) {
    samus_y_subspeed = 0;
    samus_y_speed = 0;
    samus_y_dir = kSamusYDir_Down;
  }

  Pair_Bool_Amt x_speed = Samus_CalcBaseSpeed_NoDecel_X(Samus_DetermineSpeedTableEntryPtr_X());
  if (!x_speed.max_speed_flag && samus_x_accel_mode != kSamusXAccelMode_1_TurnAround) {
    if (samus_pose_x_dir == kSamusXDir_FaceLeft) {
      if (joypad1_lastkeys & kButton_Left) {
        if (samus_x_accel_mode == kSamusXAccelMode_0_Accelerate) {
          samus_x_accel_mode = kSamusXAccelMode_2_Decelerate;
        }
      }
      else {
        x_speed.amt = 0;
        samus_x_base_speed = 0;
        samus_x_base_subspeed = 0;
        samus_collision_flag = 0;
        samus_x_accel_mode = kSamusXAccelMode_0_Accelerate;
      }
    }
    else /* samus_pose_x_dir == kSamusXDir_FaceRight */ {
      if (joypad1_lastkeys & kButton_Right) {
        if (samus_x_accel_mode == kSamusXAccelMode_0_Accelerate) {
          samus_x_accel_mode = kSamusXAccelMode_2_Decelerate;
        }
      }
      else {
        x_speed.amt = 0;
        samus_x_base_speed = 0;
        samus_x_base_subspeed = 0;
        samus_collision_flag = 0;
        samus_x_accel_mode = kSamusXAccelMode_0_Accelerate;
      }
    }
  }
  else if (samus_x_accel_mode == kSamusXAccelMode_0_Accelerate) {
    samus_x_accel_mode = kSamusXAccelMode_2_Decelerate;
  }

  Samus_MoveX(x_speed.amt);
  if (!Samus_WallJumpCheck(INT16_SHL16(kSamusPhys_MaxDistFromWallForWallJump)))
    Samus_MoveY_WithSpeedCalc();
}

/**
* @brief Set Samus to begin falling if reach peak of jump
*/
void Samus_CheckStartFalling(void) {  // 0x9090C4
  if (samus_y_dir == kSamusYDir_Up && (int16)samus_y_speed < 0) {
    samus_y_subspeed = 0;
    samus_y_speed = 0;
    samus_y_dir = kSamusYDir_Down;
  }
}

/**
* @brief Add Y acceleration to Y speed and move Samus up or down
*/
void Samus_MoveY_WithSpeedCalc(void) {  // 0x9090E2
  int32 y_speed = __PAIR32__(samus_y_speed, samus_y_subspeed);
  if (samus_y_dir == kSamusYDir_Down) {
    if (samus_y_speed != 5)
      AddToHiLo(&samus_y_speed, &samus_y_subspeed, __PAIR32__(samus_y_accel, samus_y_subaccel));
  }
  else {
    AddToHiLo(&samus_y_speed, &samus_y_subspeed, -IPAIR32(samus_y_accel, samus_y_subaccel));
    y_speed = -y_speed;
  }

  int32 y_displacement = y_speed + __PAIR32__(extra_samus_y_displacement, extra_samus_y_subdisplacement);
  if (y_displacement < 0)
    Samus_MoveUp(y_displacement);
  else
    Samus_MoveDown(y_displacement);
}

/**
* @brief Handle Samus speed, direction, and acceleration when falling
*/
void Samus_FallingMovement(void) {  // 0x909168
  Samus_HandleExtraRunspeedX();
  Pair_Bool_Amt x_speed = Samus_CalcBaseSpeed_NoDecel_X(Samus_DetermineSpeedTableEntryPtr_X());
  if (samus_x_accel_mode == kSamusXAccelMode_0_Accelerate
      && !(joypad1_lastkeys & kButton_Right) && !(joypad1_lastkeys & kButton_Left)) {
    samus_x_base_speed = 0;
    samus_x_base_subspeed = 0;
    samus_collision_flag = 0;
  }
  else {
    Samus_MoveX(x_speed.amt);
  }
  Samus_CheckStartFalling();
  Samus_MoveY_WithSpeedCalc();
}

/**
* @brief Handle Samus speed, direction, and acceleration when falling while morphed
*/
void Samus_MorphedFallingMovement(void) {  // 0x90919F
  Pair_Bool_Amt x_speed = Samus_CalcBaseSpeed_NoDecel_X(Samus_DetermineSpeedTableEntryPtr_X());
  if (samus_x_accel_mode == kSamusXAccelMode_0_Accelerate
      && !(joypad1_lastkeys & kButton_Right) && !(joypad1_lastkeys & kButton_Left)) {
    x_speed.amt = 0;
    samus_x_base_speed = 0;
    samus_x_base_subspeed = 0;
    samus_collision_flag = 0;
  }
  Samus_MoveX(x_speed.amt);
  Samus_CheckStartFalling();
  Samus_MoveY_WithSpeedCalc();
}

/**
* @brief Handle Samus speed, direction, and acceleration during morph bounce
*/
void Samus_MorphedBouncingMovement(void) {  // 0x9091D1
  Pair_Bool_Amt x_speed = Samus_CalcBaseSpeed_NoDecel_X(Samus_DetermineSpeedTableEntryPtr_X());
  if (samus_x_accel_mode == kSamusXAccelMode_0_Accelerate
      && !(joypad1_lastkeys & kButton_Right) && !(joypad1_lastkeys & kButton_Left)) {
    x_speed.amt = 0;
    samus_x_base_speed = 0;
    samus_x_base_subspeed = 0;
    samus_collision_flag = 0;
  }
  Samus_MoveX(x_speed.amt);

  if (knockback_dir == kKnockbackDir_None) {
    if (__PAIR32__(extra_samus_y_displacement, extra_samus_y_subdisplacement) != 0) {
      samus_y_dir = kSamusYDir_Down;
      samus_y_subspeed = 0;
      samus_y_speed = 0;
      int32 y_extra_displacement = __PAIR32__(extra_samus_y_displacement, extra_samus_y_subdisplacement);
      if (y_extra_displacement < 0)
        Samus_MoveUp(y_extra_displacement);
      else
        Samus_MoveDown(y_extra_displacement + INT16_SHL16(1));
    }
    else {
      Samus_CheckStartFalling();
      Samus_MoveY_WithSpeedCalc();
    }
  }
}

/**
* @brief Move Samus up or down without adjusting for acceleration
*/
void Samus_Move_NoSpeedCalc_Y(void) {  // 0x90923F
  int32 y_extra_displacement = __PAIR32__(extra_samus_y_displacement, extra_samus_y_subdisplacement);
  if (y_extra_displacement == 0) {
    // Add total X speed to extra Y displacement to keep Samus on the slope
    if (!samus_pos_adjusted_by_slope_flag)
      y_extra_displacement = __PAIR32__(samus_total_x_speed, samus_total_x_subspeed);
    Samus_MoveDown(y_extra_displacement + INT16_SHL16(1));
  }
  else {
    if (y_extra_displacement < 0)
      Samus_MoveUp(y_extra_displacement);
    else
      Samus_MoveDown(y_extra_displacement + INT16_SHL16(1));
  }
}

/**
* @brief Move Samus up or down by extra Y displacement
*/
void Samus_MoveExtraY(void) {  // 0x909288
  int32 y_extra_displacement = __PAIR32__(extra_samus_y_displacement, extra_samus_y_subdisplacement);
  if (y_extra_displacement != 0) {
    if (y_extra_displacement < 0)
      Samus_MoveUp(y_extra_displacement);
    else
      Samus_MoveDown(y_extra_displacement + INT16_SHL16(1));
  }
}

/**
* @brief Handle Samus fall movement and move Samus up or down
* @return uint8 0 if Samus Y Direction is none, 1 otherwise
*/
uint8 Samus_MoveY_Simple(void) {  // 0x9092B8
  if (samus_y_dir == kSamusYDir_None)
    return 0;
  Samus_CheckStartFalling();
  Samus_MoveY_WithSpeedCalc();
  return 1;
}

/**
* @brief Handle Samus fall movement and move Samus up or down
* @return uint8 0 if Samus Y Direction is none, 1 otherwise
*/
uint8 Samus_MoveY_Simple_(void) {  // 0x9092C7
  if (samus_y_dir == kSamusYDir_None)
    return 0;
  Samus_CheckStartFalling();
  Samus_MoveY_WithSpeedCalc();
  return 1;
}

/**
* @brief Moves Samus left or right with 0 base X speed
*/
void Samus_Move_NoBaseSpeed_X(void) {  // 0x909348
  Samus_MoveX(0);
}

/**
* @brief Handle moving Samus leftward
* @param x_displacement The amount to displace Samus X position by
*/
void Samus_MoveLeft(int32 x_displacement) {  // 0x909350
  x_displacement = -x_displacement;
  CheckEnemyColl_Result coll_result = Samus_CheckSolidEnemyColl(x_displacement);
  samus_collision_flag = coll_result.collision, x_displacement = coll_result.amt;
  if (samus_collision_flag) {
    Samus_ClearXSpeedIfColl();
    Samus_MoveLeft_NoColl(x_displacement);
    Samus_AlignYPosSlope();
  }
  else {
    x_displacement = Samus_MoveRight_NoSolidColl(-x_displacement);
    SetHiLo(&distance_samus_moved_left, &distance_samus_moved_left_fract, x_displacement);
    if (samus_collision_direction & kSamusCollDir_1_Right)
      samus_collision_flag = 0;
    Samus_ClearXSpeedIfColl();
    Samus_AlignYPosSlope();
  }
}

/**
* @brief Handle moving Samus rightward
* @param x_displacement The amount to displace Samus X position by
*/
void Samus_MoveRight(int32 x_displacement) {  // 0x9093B1
  CheckEnemyColl_Result coll_result = Samus_CheckSolidEnemyColl(x_displacement);
  samus_collision_flag = coll_result.collision, x_displacement = coll_result.amt;
  if (samus_collision_flag) {
    Samus_ClearXSpeedIfColl();
    Samus_MoveRight_NoColl(x_displacement);
    Samus_AlignYPosSlope();
  }
  else {
    x_displacement = Samus_MoveRight_NoSolidColl(x_displacement);
    SetHiLo(&distance_samus_moved_right, &distance_samus_moved_right_fract, x_displacement);
    if (!(samus_collision_direction & kSamusCollDir_1_Right))
      samus_collision_flag = 0;
    Samus_ClearXSpeedIfColl();
    Samus_AlignYPosSlope();
  }
}

/**
* @brief Handle moving Samus upward
* @param y_displacement The amount to displace Samus Y position by
*/
void Samus_MoveUp(int32 y_displacement) {  // 0x9093EC
  samus_collision_direction = kSamusCollDir_2_Up;
  CheckEnemyColl_Result coll_result = Samus_CheckSolidEnemyColl(-y_displacement);
  samus_collision_flag = coll_result.collision, y_displacement = coll_result.amt;
  if (samus_collision_flag) {
    Samus_MoveUp_SetPoseCalcInput();
    Samus_MoveUp_NoColl(y_displacement);
  }
  else {
    y_displacement = Samus_MoveDown_NoSolidColl(-y_displacement);
    SetHiLo(&distance_samus_moved_up, &distance_samus_moved_up_fract, y_displacement);
    Samus_MoveUp_SetPoseCalcInput();
  }
}

/**
* @brief Handle moving Samus downward
* @param y_displacement The amount to displace Samus Y position by
*/
void Samus_MoveDown(int32 y_displacement) {  // 0x909440
  samus_collision_direction = kSamusCollDir_3_Down;
  CheckEnemyColl_Result coll_result = Samus_CheckSolidEnemyColl(y_displacement);
  samus_collision_flag = coll_result.collision, y_displacement = coll_result.amt;
  if (samus_collision_flag) {
    Samus_MoveDown_SetPoseCalcInput();
    Samus_MoveDown_NoColl(y_displacement);
  }
  else {
    y_displacement = Samus_MoveDown_NoSolidColl(y_displacement);
    SetHiLo(&distance_samus_moved_down, &distance_samus_moved_down_fract, y_displacement);
    Samus_MoveDown_SetPoseCalcInput();
  }
}

/**
* @brief Handle Samus movement when releasing from grapple swing
*/
void Samus_MovementHandler_ReleaseFromGrapple(void) {  // 0x90946E
  if (samus_y_dir == kSamusYDir_Up && (int16)samus_y_speed < 0) {
    samus_y_subspeed = 0;
    samus_y_speed = 0;
    samus_y_dir = kSamusYDir_Down;
    samus_movement_handler = FUNC16(Samus_MovementHandler_Normal);
  }
  samus_x_accel_mode = kSamusXAccelMode_2_Decelerate;
  int32 x_speed = Samus_CalcBaseSpeed_X(Samus_DetermineGrappleSwingSpeed_X());
  if (samus_x_accel_mode == kSamusXAccelMode_0_Accelerate
      && !(joypad1_lastkeys & kButton_Right) && !(joypad1_lastkeys & kButton_Left)) {
    samus_x_base_speed = 0;
    samus_x_base_subspeed = 0;
    samus_collision_flag = 0;
  }
  else {
    Samus_MoveX(x_speed);
  }
  Samus_MoveY_WithSpeedCalc();
  if (samus_solid_vertical_coll_result != kSolidVertCollResult_0_NoChange)
    samus_movement_handler = FUNC16(Samus_MovementHandler_Normal);
}

/**
* @brief Handle Samus Y movement when drained and switch to normal movement when Samus hits the floor
*/
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

/**
* @brief Handle manual and automatic screen scrolling for normal and grapple movement, and save Samus' position
*/
void MainScrollingRoutine(void) {  // 0x9094EC
  if (slow_grapple_scrolling_flag) {
    if ((int16)samus_x_pos >= 0) {
        uint16 samus_screen_x_pos = samus_x_pos - layer1_x_pos;
        if (samus_screen_x_pos < 0) {
          layer1_x_pos -= 3;
        }
        else if (samus_screen_x_pos >= (10*16)) {
          layer1_x_pos += 3;
        }
        else if (samus_screen_x_pos < (6*16)) {
          layer1_x_pos -= 3;
        }
        if ((int16)samus_y_pos >= 0) {
          uint16 samus_screen_y_pos = samus_y_pos - layer1_y_pos;
          if (samus_screen_y_pos < 0) {
            layer1_y_pos -= 3;
          }
          else if (samus_screen_y_pos >= (9*16)) {
            layer1_y_pos += 3;
          }
          else if (samus_screen_y_pos < (7*16)) {
            layer1_y_pos -= 3;
          }
        }
    }
    HandleAutoscrolling_X();
    HandleAutoscrolling_Y();
  }
  else {
    Samus_CalcDistanceMoved_X();
    Samus_HandleScroll_X();
    Samus_CalcDistanceMoved_Y();
    Samus_HandleScroll_Y();
  }
  if (scrolling_finished_hook)
    CallScrollingFinishedHook(scrolling_finished_hook | 0x900000);
  samus_prev_x_pos = samus_x_pos;
  samus_prev_x_subpos = samus_x_subpos;
  samus_prev_y_pos = samus_y_pos;
  samus_prev_y_subpos = samus_y_subpos;
}

/**
* @brief Prevent the camera from moving up during the Spore Spawn fight
*/
void Samus_ScrollFinishedHook_SporeSpawnFight(void) {  // 0x909589
  layer1_y_pos = UintMax(layer1_y_pos, (29*16));
}

/**
* @brief Handle horizontal scrolling for Samus movement
*/
void Samus_HandleScroll_X(void) {  // 0x9095A0
  static const uint16 kSamus_HandleScroll_X_CameraTargetDist_FaceLeft[4] = {
    [kCameraDistanceIndex_0_Normal >> 1]          = (10*16),
    [kCameraDistanceIndex_2_Kraid_Crocomire >> 1] = (5*16),
    [kCameraDistanceIndex_4_Unused >> 1]          = (2*16),
    [kCameraDistanceIndex_6_CrocomireWall >> 1]   = (14*16),
  };
  static const uint16 kSamus_HandleScroll_X_CameraTargetDist_FaceRight[4] = {
    [kCameraDistanceIndex_0_Normal >> 1]          = (6*16),
    [kCameraDistanceIndex_2_Kraid_Crocomire >> 1] = (4*16),
    [kCameraDistanceIndex_4_Unused >> 1]          = (2*16),
    [kCameraDistanceIndex_6_CrocomireWall >> 1]   = (14*16),
  };

  if (samus_prev_x_pos == samus_x_pos) {
    HandleAutoscrolling_X();
    return;
  }
  if ((knockback_dir != kKnockbackDir_None || samus_movement_type == kMovementType_10_Moonwalking
      || samus_x_accel_mode == kSamusXAccelMode_1_TurnAround) ^ (samus_pose_x_dir != kSamusXDir_FaceLeft)) {
    ideal_layer1_xpos = samus_x_pos - kSamus_HandleScroll_X_CameraTargetDist_FaceRight[camera_distance_index >> 1];
  }
  else {
    ideal_layer1_xpos = samus_x_pos - kSamus_HandleScroll_X_CameraTargetDist_FaceLeft[camera_distance_index >> 1];
  }

  if (ideal_layer1_xpos != layer1_x_pos) {
    if ((int16)ideal_layer1_xpos < (int16)layer1_x_pos) {
      AddToHiLo(&layer1_x_pos, &layer1_x_subpos, -IPAIR32(camera_x_speed, camera_x_subspeed));
      HandleScrollingWhenTriggeringScrollLeft();
    }
    else {
      AddToHiLo(&layer1_x_pos, &layer1_x_subpos, __PAIR32__(camera_x_speed, camera_x_subspeed));
      HandleScrollingWhenTriggeringScrollRight();
    }
  }
}

/**
* @brief Handle vertical scrolling for Samus movement
*/
void Samus_HandleScroll_Y(void) {  // 0x90964F
  if (samus_prev_y_pos == samus_y_pos) {
    HandleAutoscrolling_Y();
    return;
  }
  if (samus_y_dir == kSamusYDir_Up)
    ideal_layer1_ypos = samus_y_pos - down_scroller;
  else
    ideal_layer1_ypos = samus_y_pos - up_scroller;

  if (ideal_layer1_ypos != layer1_y_pos) {
    if ((int16)ideal_layer1_ypos < (int16)layer1_y_pos) {
      AddToHiLo(&layer1_y_pos, &layer1_y_subpos, -IPAIR32(camera_y_speed, camera_y_subspeed));
      HandleScrollingWhenTriggeringScrollUp();
    }
    else {
      AddToHiLo(&layer1_y_pos, &layer1_y_subpos, __PAIR32__(camera_y_speed, camera_y_subspeed));
      HandleScrollingWhenTriggeringScrollDown();
    }
  }
}

/**
* @brief Calculate the camera X speed based on the difference of Samus' X position and subposition
*/
void Samus_CalcDistanceMoved_X(void) {  // 0x9096C0
  static const uint16 kSamusPhys_CameraXOffset_Turning = 1;

  if ((int16)samus_x_pos >= (int16)samus_prev_x_pos) {
    SetHiLo(&camera_x_speed, &camera_x_subspeed,
      __PAIR32__(samus_x_pos, samus_x_subpos) - __PAIR32__(samus_prev_x_pos, samus_prev_x_subpos)
      + INT16_SHL16(kSamusPhys_CameraXOffset_Turning));
  }
  else {
    SetHiLo(&camera_x_speed, &camera_x_subspeed,
      __PAIR32__(samus_prev_x_pos, samus_prev_x_subpos) - __PAIR32__(samus_x_pos, samus_x_subpos)
      + INT16_SHL16(kSamusPhys_CameraXOffset_Turning));
  }
}

/**
* @brief Calculate the camera Y speed based on the difference of Samus' Y position and subposition
*/
void Samus_CalcDistanceMoved_Y(void) {  // 0x9096FF
  static const uint16 kSamusPhys_CameraXOffset_Turning = 1;

  if ((int16)samus_y_pos >= (int16)samus_prev_y_pos) {
    SetHiLo(&camera_y_speed, &camera_y_subspeed,
      __PAIR32__(samus_y_pos, samus_y_subpos) - __PAIR32__(samus_prev_y_pos, samus_prev_y_subpos)
      + INT16_SHL16(kSamusPhys_CameraXOffset_Turning));
  }
  else {
    SetHiLo(&camera_y_speed, &camera_y_subspeed,
      __PAIR32__(samus_prev_y_pos, samus_prev_y_subpos) - __PAIR32__(samus_y_pos, samus_y_subpos)
      + INT16_SHL16(kSamusPhys_CameraXOffset_Turning));
  }
  ;
}

static const uint16 kSamusPhys_ExtraRunSpeedXAccel_Running_Tab0[3] = { 0, 0, 0 };
static const uint16 kSamusPhys_ExtraRunSpeedXSubaccel_Running_Tab0[3] = { 0x1000, 0x400, 0x400 };
static const uint16 kSamusPhys_MaxExtraRunSpeedX_Speedbooster_Tab0[3] = { 7, 4, 4 };
static const uint16 kSamusPhys_MaxExtraRunSubspeedX_Speedbooster_Tab0[3] = { 0, 0, 0 };
static const uint16 kSamusPhys_MaxExtraRunSpeedX_NoSpeedbooster_Tab0[3] = { 2, 1, 0 };
static const uint16 kSamusPhys_MaxExtraRunSubspeedX_NoSpeedbooster_Tab0[3] = { 0, 0, 0 };

/**
* @brief Handle extra X runspeed depending on movement type, speed boosting, and liquid type
*/
void Samus_HandleExtraRunspeedX(void) {  // 0x90973E
  if (!(equipped_items & kItem_GravitySuit)) {
    int16 samus_bottom_bound = Samus_GetBottomBound();
    if ((int16)fx_y_pos < 0) {
      if ((int16)lava_acid_y_pos >= 0 && (int16)lava_acid_y_pos < samus_bottom_bound) {
        if (!samus_has_momentum_flag) {
          samus_x_extra_run_speed = 0;
          samus_x_extra_run_subspeed = 0;
        }
        if (speed_boost_counter == SPEED_BOOST_THRESHOLD)
          samus_contact_damage_index = kSamusContactDamageIndex_1_SpeedBoost;
        return;
      }
    }
    else if ((int16)fx_y_pos < samus_bottom_bound && !(fx_liquid_options & kFxLiquidOption_4_LiquidPhysicsDisabled)) {
      if (!samus_has_momentum_flag) {
        samus_x_extra_run_speed = 0;
        samus_x_extra_run_subspeed = 0;
      }
      if (speed_boost_counter == SPEED_BOOST_THRESHOLD)
        samus_contact_damage_index = kSamusContactDamageIndex_1_SpeedBoost;
      return;
    }
  }
  if (samus_movement_type != kMovementType_01_Running || !(joypad1_lastkeys & button_config_run)) {
    if (!samus_has_momentum_flag) {
      samus_x_extra_run_speed = 0;
      samus_x_extra_run_subspeed = 0;
    }
    if (speed_boost_counter == SPEED_BOOST_THRESHOLD)
      samus_contact_damage_index = kSamusContactDamageIndex_1_SpeedBoost;
    return;
  }
  if (equipped_items & kItem_SpeedBooster) {
    if (!samus_has_momentum_flag) {
      samus_has_momentum_flag = 1;
      special_samus_palette_timer = 1;
      special_samus_palette_frame = 0;
      speed_boost_timer = LOBYTE(kSpeedBoostToCtr[0]);
      speed_boost_counter = HIBYTE(kSpeedBoostToCtr[0]);
    }
    if ((int16)samus_x_extra_run_speed >= (int16)kSamusPhys_MaxExtraRunSpeedX_Speedbooster_Tab0[0]
        && (int16)samus_x_extra_run_subspeed >= (int16)kSamusPhys_MaxExtraRunSubspeedX_Speedbooster_Tab0[0]) {
      samus_x_extra_run_speed = kSamusPhys_MaxExtraRunSpeedX_Speedbooster_Tab0[0];
      samus_x_extra_run_subspeed = kSamusPhys_MaxExtraRunSubspeedX_Speedbooster_Tab0[0];
      if (speed_boost_counter == SPEED_BOOST_THRESHOLD)
        samus_contact_damage_index = kSamusContactDamageIndex_1_SpeedBoost;
      return;
    }
  }
  else {
    if (!samus_has_momentum_flag) {
      samus_has_momentum_flag = 1;
      speed_boost_timer = 0;
      speed_boost_counter = 0;
    }
    if ((int16)samus_x_extra_run_speed >= (int16)kSamusPhys_MaxExtraRunSpeedX_NoSpeedbooster_Tab0[0]
        && (int16)samus_x_extra_run_subspeed >= (int16)kSamusPhys_MaxExtraRunSubspeedX_NoSpeedbooster_Tab0[0]) {
      samus_x_extra_run_speed = kSamusPhys_MaxExtraRunSpeedX_NoSpeedbooster_Tab0[0];
      samus_x_extra_run_subspeed = kSamusPhys_MaxExtraRunSubspeedX_NoSpeedbooster_Tab0[0];
      if (speed_boost_counter == SPEED_BOOST_THRESHOLD)
        samus_contact_damage_index = kSamusContactDamageIndex_1_SpeedBoost;
      return;
    }
  }
  AddToHiLo(&samus_x_extra_run_speed, &samus_x_extra_run_subspeed,
      __PAIR32__(kSamusPhys_ExtraRunSpeedXAccel_Running_Tab0[0], kSamusPhys_ExtraRunSpeedXSubaccel_Running_Tab0[0]));
  if (speed_boost_counter == SPEED_BOOST_THRESHOLD)
    samus_contact_damage_index = kSamusContactDamageIndex_1_SpeedBoost;
}

/**
* @brief Move Samus X position to the right and set distance moved right, without checking collision
* @param x_displacement The amount to displace Samus X position by
*/
void Samus_MoveRight_NoColl(int32 x_displacement) {  // 0x909826
  AddToHiLo(&samus_x_pos, &samus_x_subpos, x_displacement);
  SetHiLo(&distance_samus_moved_right, &distance_samus_moved_right_fract, x_displacement);
}

/**
* @brief Move Samus X position to the left and set distance moved left, without checking collision
* @param x_displacement The amount to displace Samus X position by
*/
void Samus_MoveLeft_NoColl(int32 x_displacement) {  // 0x909842
  AddToHiLo(&samus_x_pos, &samus_x_subpos, -x_displacement);
  SetHiLo(&distance_samus_moved_left, &distance_samus_moved_left_fract, -x_displacement);
}

/**
* @brief Move Samus Y position to the down and set distance moved down, without checking collision
* @param y_displacement The amount to displace Samus Y position by
*/
void Samus_MoveDown_NoColl(int32 y_displacement) {  // 0x909871
  AddToHiLo(&samus_y_pos, &samus_y_subpos, y_displacement);
  SetHiLo(&distance_samus_moved_down, &distance_samus_moved_down_fract, y_displacement);
}

/**
* @brief Move Samus Y position to the up and set distance moved up, without checking collision
* @param y_displacement The amount to displace Samus Y position by
*/
void Samus_MoveUp_NoColl(int32 y_displacement) {  // 0x90988D
  AddToHiLo(&samus_y_pos, &samus_y_subpos, -y_displacement);
  SetHiLo(&distance_samus_moved_up, &distance_samus_moved_up_fract, -y_displacement);
}

/**
* @brief Make Samus jump depending on liquid and items equipped
*/
void Samus_InitJump(void) {  // 0x9098BC
  static const uint16 kSamusPhys_InitJump_Speed_Y[3] = { 4, 1, 2 };
  static const uint16 kSamusPhys_InitJump_Subspeed_Y[3] = { 0xe000, 0xc000, 0xc000 };
  static const uint16 kSamusPhys_InitJump_HiJump_Speed_Y[3] = { 6, 2, 3 };
  static const uint16 kSamusPhys_InitJump_HiJump_Subspeed_Y[3] = { 0, 0x8000, 0x8000 };
  uint16 liquid_idx;

  int16 samus_bottom_bound = Samus_GetBottomBound();
  if (equipped_items & kItem_GravitySuit) {
    liquid_idx = 0;
  }
  else if ((int16)fx_y_pos >= 0) {
    if ((int16)fx_y_pos < samus_bottom_bound && !(fx_liquid_options & kFxLiquidOption_4_LiquidPhysicsDisabled)) {
      liquid_idx = 2;
    }
    else {
      liquid_idx = 0;
    }
  }
  else if (0 <= (int16)lava_acid_y_pos < 0 && (int16)lava_acid_y_pos < samus_bottom_bound) {
    liquid_idx = 4;
  }
  else {
    liquid_idx = 0;
  }

  int idx = liquid_idx >> 1;
  if (equipped_items & kItem_HiJumpBoots) {
    samus_y_subspeed = kSamusPhys_InitJump_HiJump_Subspeed_Y[idx];
    samus_y_speed = kSamusPhys_InitJump_HiJump_Speed_Y[idx];
  }
  else {
    samus_y_subspeed = kSamusPhys_InitJump_Subspeed_Y[idx];
    samus_y_speed = kSamusPhys_InitJump_Speed_Y[idx];
  }
  if (equipped_items & kItem_SpeedBooster) {
    samus_y_subspeed += samus_x_extra_run_subspeed;
    samus_y_speed += samus_x_extra_run_speed / 2;
  }
  grapple_walljump_timer = 0;
  reached_ceres_elevator_fade_timer = 0;
  samus_y_dir = kSamusYDir_Up;
}

/**
* @brief Make Samus wall jump depending on liquid and items equipped
*/
void Samus_InitWallJump(void) {  // 0x909949
  static const uint16 kSamusPhys_InitWallJump_Speed_Y[3] = { 4, 0, 2 };
  static const uint16 kSamusPhys_InitWallJump_Subspeed_Y[3] = { 0xa000, 0x4000, 0xa000 };
  static const uint16 kSamusPhys_InitWallJump_HiJump_Speed_Y[3] = { 5, 0, 3 };
  static const uint16 kSamusPhys_InitWallJump_HiJump_Subspeed_Y[3] = { 0x8000, 0x8000, 0x8000 };
  uint16 liquid_idx;

  int16 samus_bottom_bound = Samus_GetBottomBound();
  if (equipped_items & kItem_GravitySuit) {
    liquid_idx = 0;
  }
  else if ((int16)fx_y_pos >= 0) {
    if ((int16)fx_y_pos < samus_bottom_bound && !(fx_liquid_options & kFxLiquidOption_4_LiquidPhysicsDisabled)) {
      liquid_idx = 2;
    }
    else {
      liquid_idx = 0;
    }
  }
  else if (0 <= (int16)lava_acid_y_pos && (int16)lava_acid_y_pos < samus_bottom_bound) {
    liquid_idx = 4;
  }
  else {
    liquid_idx = 0;
  }

  int idx = liquid_idx >> 1;
  if (equipped_items & kItem_HiJumpBoots) {
    samus_y_subspeed = kSamusPhys_InitWallJump_HiJump_Subspeed_Y[idx];
    samus_y_speed = kSamusPhys_InitWallJump_HiJump_Speed_Y[idx];
  }
  else {
    samus_y_subspeed = kSamusPhys_InitWallJump_Subspeed_Y[idx];
    samus_y_speed = kSamusPhys_InitWallJump_Speed_Y[idx];
  }
  if (equipped_items & kItem_SpeedBooster) {
    samus_y_subspeed += samus_x_extra_run_subspeed;
    samus_y_speed += samus_x_extra_run_speed / 2;
  }
  grapple_walljump_timer = 0;
  reached_ceres_elevator_fade_timer = 0;
  samus_y_dir = kSamusYDir_Up;
}

static const uint16 kSamusPhys_SetSpeedForKnockback_Y_Speed[3] = { 5, 2, 2 };
static const uint16 kSamusPhys_SetSpeedForKnockback_Y_Subspeed[3] = { 0, 0, 0 };

/**
* @brief Set Samus Y speed for knockback depending on liquid and items equipped
*/
void Samus_SetSpeedForKnockback_Y(void) {  // 0x9099D6
  uint16 liquid_idx;

  int16 samus_bottom_bound = Samus_GetBottomBound();
  if (equipped_items & kItem_GravitySuit) {
    liquid_idx = 0;
  }
  else if ((int16)fx_y_pos >= 0) {
    if ((int16)fx_y_pos < samus_bottom_bound && !(fx_liquid_options & kFxLiquidOption_4_LiquidPhysicsDisabled)) {
      liquid_idx = 2;
    }
    else {
      liquid_idx = 0;
    }
  }
  else if (0 <= (int16)lava_acid_y_pos && (int16)lava_acid_y_pos < samus_bottom_bound) {
    liquid_idx = 4;
  }
  else {
    liquid_idx = 0;
  }

  int idx = liquid_idx >> 1;
  samus_y_subspeed = kSamusPhys_SetSpeedForKnockback_Y_Subspeed[idx];
  samus_y_speed = kSamusPhys_SetSpeedForKnockback_Y_Speed[idx];
  grapple_walljump_timer = 0;
  reached_ceres_elevator_fade_timer = 0;
  samus_y_dir = kSamusYDir_Up;
}

/**
* @brief Set Samus Y speed for bomb jump depending on liquid and items equipped
*/
void Samus_InitBombJump(void) {  // 0x909A2C
  static const uint16 kSamusPhys_InitBombJump_Speed_Y[3] = { 2, 0, 0 };
  static const uint16 kSamusPhys_InitBombJump_Subspeed_Y[3] = { 0xc000, 0x1000, 0x1000 };
  uint16 liquid_idx;

  int16 samus_bottom_bound = Samus_GetBottomBound();
  if (equipped_items & kItem_GravitySuit) {
    liquid_idx = 0;
  }
  else if ((int16)fx_y_pos >= 0) {
    if ((int16)fx_y_pos < samus_bottom_bound && !(fx_liquid_options & kFxLiquidOption_4_LiquidPhysicsDisabled)) {
      liquid_idx = 2;
    }
    else {
      liquid_idx = 0;
    }
  }
  else if (0 <= (int16)lava_acid_y_pos && (int16)lava_acid_y_pos < samus_bottom_bound) {
    liquid_idx = 4;
  }
  else {
    liquid_idx = 0;
  }

  int idx = liquid_idx >> 1;
  samus_y_subspeed = kSamusPhys_InitBombJump_Subspeed_Y[idx];
  samus_y_speed = kSamusPhys_InitBombJump_Speed_Y[idx];
  grapple_walljump_timer = 0;
  reached_ceres_elevator_fade_timer = 0;
  samus_y_dir = kSamusYDir_Up;
}

/**
* @brief Determines if the high and low word of the value is greater than the high and low word of the value to compare
* @param vhi The high word of the value
* @param vlo The low word of the value
* @param cmphi The high word of the comparison value
* @param cmplo The low word of the comparison value
* @return bool true if the value is strictly greater than the comparison value, false otherwise
*/
static bool IsGreaterThanQuirked(uint16 vhi, uint16 vlo, uint16 cmphi, uint16 cmplo) {
  if ((int16)(vhi - cmphi) >= 0) {
    if (vhi != cmphi || ((int16)(vlo - cmplo) >= 0) && vlo != cmplo)
      return true;
  }
  return false;
}

/**
* @brief Calculate the X base speed based on acceleration type
* @param samus_speed_table_ptr The pointer to the table of speed entries
* @return int32 Samus X base speed
*/
int32 Samus_CalcBaseSpeed_X(uint16 samus_speed_table_ptr) {  // 0x909A7E 
  const SamusSpeedTableEntry sste = (samus_speed_table_ptr >= addr_kSamusSpeedTable_Normal_X)
                                    ? get_SamusSpeedTableEntry(samus_speed_table_ptr)[samus_movement_type]
                                    : get_SamusSpeedTableEntry(samus_speed_table_ptr)[0];
  if (samus_x_accel_mode != kSamusXAccelMode_0_Accelerate) {
    int32 x_decel = samus_x_decel_mult
      ? __PAIR32__(Mult8x8(samus_x_decel_mult, sste.decel) >> 8, Mult8x8(samus_x_decel_mult, HIBYTE(sste.decel_sub)))
      : __PAIR32__(sste.decel, sste.decel_sub);
    AddToHiLo(&samus_x_base_speed, &samus_x_base_subspeed, -x_decel);
    if ((int16)samus_x_base_speed < 0) {
      samus_x_base_speed = 0;
      samus_x_base_subspeed = 0;
      samus_x_accel_mode = kSamusXAccelMode_0_Accelerate;
    }
  }
  else {
    AddToHiLo(&samus_x_base_speed, &samus_x_base_subspeed, __PAIR32__(sste.accel, sste.accel_sub));
    if (IsGreaterThanQuirked(samus_x_base_speed, samus_x_base_subspeed, sste.max_speed, sste.max_speed_sub)) {
      SetHiLo(&samus_x_base_speed, &samus_x_base_subspeed, __PAIR32__(sste.max_speed, sste.max_speed_sub));
    }
  }
  return __PAIR32__(samus_x_base_speed, samus_x_base_subspeed);
}

/**
* @brief Calculate the X base speed based without taking into account deceleration
* @param samus_speed_table_ptr The pointer to the table of speed entries
* @return Pair_Bool_Amt { bool indicating if Samus has reached max X speed, uint16 Samus X base speed }
*/
static Pair_Bool_Amt Samus_CalcBaseSpeed_NoDecel_X(uint16 samus_speed_table_ptr) {  // 0x909B1F
  const SamusSpeedTableEntry sste = (samus_speed_table_ptr >= addr_kSamusSpeedTable_Normal_X)
                                    ? get_SamusSpeedTableEntry(samus_speed_table_ptr)[samus_movement_type]
                                    : get_SamusSpeedTableEntry(samus_speed_table_ptr)[0];
  bool x_speed_is_max = false;
  if (samus_x_accel_mode == kSamusXAccelMode_1_TurnAround) {
    int32 x_decel = samus_x_decel_mult
      ? __PAIR32__(Mult8x8(samus_x_decel_mult, sste.decel) >> 8, Mult8x8(samus_x_decel_mult, HIBYTE(sste.decel_sub)))
      : __PAIR32__(sste.decel, sste.decel_sub);
    AddToHiLo(&samus_x_base_speed, &samus_x_base_subspeed, -x_decel);
    if ((int16)samus_x_base_speed < 0) {
      samus_x_base_speed = 0;
      samus_x_base_subspeed = 0;
      samus_x_accel_mode = 0;
    }
  }
  else {
    AddToHiLo(&samus_x_base_speed, &samus_x_base_subspeed, __PAIR32__(sste.accel, sste.accel_sub));
    if (IsGreaterThanQuirked(samus_x_base_speed, samus_x_base_subspeed, sste.max_speed, sste.max_speed_sub)) {
      SetHiLo(&samus_x_base_speed, &samus_x_base_subspeed, __PAIR32__(sste.max_speed, sste.max_speed_sub));
      x_speed_is_max = true;
    }
  }
  return (Pair_Bool_Amt) { x_speed_is_max, __PAIR32__(samus_x_base_speed, samus_x_base_subspeed) };
}

/**
* @brief Determine the speed table pointer based off liquid type
* @return uint16 Samus X speed table pointer
*/
uint16 Samus_DetermineSpeedTableEntryPtr_X(void) {  // 0x909BD1
  if (!(equipped_items & kItem_GravitySuit)) {
    int16 samus_bottom_bound = Samus_GetBottomBound();
    if ((int16)fx_y_pos >= 0) {
      if ((int16)fx_y_pos < samus_bottom_bound && !(fx_liquid_options & kFxLiquidOption_4_LiquidPhysicsDisabled)) {
        samus_x_speed_table_pointer = addr_kSamusSpeedTable_Water_X;
      }
    }
    else if (0 <= (int16)lava_acid_y_pos && (int16)lava_acid_y_pos < samus_bottom_bound)
      samus_x_speed_table_pointer = addr_kSamusSpeedTable_LavaAcid_X;
  }
  return samus_x_speed_table_pointer;
}

/**
* @brief Determine the grapple speed table pointer based off liquid type
* @return uint16 Samus X speed table pointer
*/
uint16 Samus_DetermineGrappleSwingSpeed_X(void) {  // 0x909C21
  if (!(equipped_items & kItem_GravitySuit)) {
    int16 samus_bottom_bound = Samus_GetBottomBound();
    if ((int16)fx_y_pos >= 0) {
      if ((int16)fx_y_pos < samus_bottom_bound && !(fx_liquid_options & kFxLiquidOption_4_LiquidPhysicsDisabled))
        return addr_kSamusSpeedTable_GrappleDisconnect_Water;
    }
    else if (0 <= (int16)lava_acid_y_pos && (int16)lava_acid_y_pos < samus_bottom_bound)
      return addr_kSamusSpeedTable_GrappleDisconnect_LavaAcid;
  }
  return addr_kSamusSpeedTable_GrappleDisconnect_Air;
}

/**
* @brief Set Samus Y acceleration depending on liquid and items equipped
*/
void Samus_DetermineAccel_Y(void) {  // 0x909C5B
  static const uint16 kSamusPhys_YSubacc[3] = {0x1c00, 0x800, 0x900};
  static const uint16 kSamusPhys_YAcc[3] = { 0, 0, 0 };
  uint16 liquid_idx;

  int16 samus_bottom_bound = Samus_GetBottomBound();
  if (equipped_items & kItem_GravitySuit) {
    liquid_idx = 0;
  }
  else if ((int16)fx_y_pos >= 0) {
    if ((int16)fx_y_pos < samus_bottom_bound && !(fx_liquid_options & kFxLiquidOption_4_LiquidPhysicsDisabled)) {
      liquid_idx = 2;
    }
    else {
      liquid_idx = 0;
    }
  }
  else if (0 <= (int16)lava_acid_y_pos && (int16)lava_acid_y_pos < samus_bottom_bound) {
    liquid_idx = 4;
  }
  else {
    liquid_idx = 0;
  }

  int idx = liquid_idx >> 1;
  samus_y_subaccel = kSamusPhys_YSubacc[idx];
  samus_y_accel = kSamusPhys_YAcc[idx];
}

/**
* @brief Determine if a wall jump will occur while grappling
* @param coll_dist The distance from the collision to check
* @return uint8 1 if a wall jump is triggered, else 0
*/
uint8 Samus_GrappleWallJumpCheck(int32 coll_dist) {  // 0x909CAC
  enemy_index_to_shake = -1;
  if (samus_pose_x_dir == kSamusXDir_FaceLeft) {
    samus_collision_direction = kSamusCollDir_0_Left;
  }
  else if (samus_pose_x_dir == kSamusXDir_FaceRight) {
    samus_collision_direction = kSamusCollDir_1_Right;
  }
  else {
    return 0;
  }
  CheckEnemyColl_Result coll_result = Samus_CheckSolidEnemyColl(coll_dist);
  if (!coll_result.collision) {
    WallJumpBlockCollDetect(coll_result.amt);
    return samus_collision_flag && (joypad1_newkeys & button_config_jump);
  }
  if (!(joypad1_newkeys & button_config_jump))
    return 0;
  enemy_index_to_shake = collision_detection_index;
  return 1;
}

/**
* @brief Determine if a wall jump will occur
* @param coll_dist The distance from the collision to check 
* @return uint8 1 if a wall jump is triggered, else 0
*/
uint8 Samus_WallJumpCheck(int32 coll_dist) {  // 0x909D35
  CheckEnemyColl_Result coll_result;

  if (samus_last_different_pose_movement_type != kMovementType_03_SpinJumping
      && samus_last_different_pose_movement_type != kMovementType_14_WallJumping)
    return 0;
  if (samus_pose == kPose_81_FaceR_Screwattack || samus_pose == kPose_82_FaceL_Screwattack) {
    if (samus_anim_frame < 27)
      goto SPIN_ANIM;
  }
  else if (samus_anim_frame < 11) {
SPIN_ANIM:
    if (joypad1_lastkeys & kButton_Left) {
      samus_collision_direction = kSamusCollDir_1_Right;
      coll_result = Samus_CheckSolidEnemyColl(coll_dist);
      coll_dist = coll_result.amt;
      if (!coll_result.collision) {
        coll_dist = WallJumpBlockCollDetect(coll_dist);
        if (!samus_collision_flag)
          return 0;
      }
    }
    else if (joypad1_lastkeys & kButton_Right) {
      samus_collision_direction = kSamusCollDir_0_Left;
      coll_result = Samus_CheckSolidEnemyColl(coll_dist);
      coll_dist = coll_result.amt;
      if (!coll_result.collision) {
        coll_dist = WallJumpBlockCollDetect(-coll_dist);
        if (!samus_collision_flag)
          return 0;
      }
    }
    else {
      return 0;
    }
    if (samus_pose == kPose_81_FaceR_Screwattack || samus_pose == kPose_82_FaceL_Screwattack) {
      samus_anim_frame_timer = 1;
      samus_anim_frame = 26;
    }
    else {
      samus_anim_frame_timer = 1;
      samus_anim_frame = 10;
    }
    return 0;
  }

  enemy_index_to_shake = -1;
  if (joypad1_lastkeys & kButton_Left) {
    samus_collision_direction = 1;
    coll_result = Samus_CheckSolidEnemyColl(coll_dist), coll_dist = coll_result.amt;
    if (!coll_result.collision) {
      coll_dist = WallJumpBlockCollDetect(coll_dist);
      if (!samus_collision_flag || !(joypad1_newkeys & button_config_jump))
        return 0;
      goto WALL_JUMP_BLOCK;
    }
    if (!(joypad1_newkeys & button_config_jump))
      return 0;
    goto WALL_JUMP_ENEMY;
  }
  else if (joypad1_lastkeys & kButton_Right) {
    samus_collision_direction = 0;
    coll_result = Samus_CheckSolidEnemyColl(coll_dist), coll_dist = coll_result.amt;
    if (!coll_result.collision) {
      coll_dist = -coll_dist;
      WallJumpBlockCollDetect(coll_dist);
      if (!samus_collision_flag || !(joypad1_newkeys & button_config_jump))
        return 0;
      goto WALL_JUMP_BLOCK;
    }
    if (!(joypad1_newkeys & button_config_jump))
      return 0;
    goto WALL_JUMP_ENEMY;
  }
  else {
    return 0;
  }
WALL_JUMP_BLOCK:
    if ((int16)HIWORD(coll_dist) < 8) {
      samus_solid_vertical_coll_result = kSolidVertCollResult_5_WallJumped;
      return 1;
    }
    return 0;
WALL_JUMP_ENEMY:
    if ((int16)HIWORD(coll_dist) < 8) {
      samus_solid_vertical_coll_result = kSolidVertCollResult_5_WallJumped;
      enemy_index_to_shake = collision_detection_index;
      return 1;
    }
    return 0;
}

void Samus_Movement_07_Unused(void) {  // 0x90A32D
  samus_solid_vertical_coll_result = kSolidVertCollResult_0_NoChange;
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

/**
* @brief Handle normal Samus movement
*/
void Samus_MovementHandler_Normal(void) {
  if (!time_is_frozen_flag) {
    kSamusMovementHandlers[samus_movement_type]();
    Samus_UpdateSpeedEchoPos();
  }
}

/**
* @brief Handle Samus standing movement
*/
void Samus_Movement_00_Standing(void) {  // 0x90A383
  if (samus_pose != kPose_00_FaceF_Powersuit && samus_pose != kPose_9B_FaceF_VariaGravitySuit) {
    if ((samus_pose == kPose_01_FaceR_Normal || samus_pose == kPose_02_FaceL_Normal)
        && (joypad1_lastkeys & button_config_shoot)) {
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
    samus_x_accel_mode = kSamusXAccelMode_0_Accelerate;
  }
  else {
    if (elevator_status != kElevatorStatus_Inactive) {
      samus_collision_direction = kSamusCollDir_2_Up;
      Samus_MoveDown_NoSolidColl(INT16_SHL16(1));
    }
    samus_solid_vertical_coll_result = kSolidVertCollResult_0_NoChange;
  }
}

/**
* @brief Handle Samus running movement
*/
void Samus_Movement_01_Running(void) {  // 0x90A3E5
  static const uint8 kSamusFootstepFrame[10] = { 0, 0, 1, 0, 0, 0, 0, 1, 0, 0 };

  Samus_HandleMovement_X();
  Samus_Move_NoSpeedCalc_Y();
  if (samus_anim_frame_timer == 1) {
    if (kSamusFootstepFrame[samus_anim_frame] != 0) {
      Samus_FootstepGraphics();
      if (cinematic_function == 0 && boss_id == kBossId_0_None && samus_shine_timer == 0
          && !(speed_boost_counter & SPEED_BOOST_THRESHOLD))
        QueueSfx3_Max6(kSfx3_SamusFootsteps);
    }
  }
}

/**
* @brief Handle Samus jumping movement
*/
void Samus_Movement_02_NormalJumping(void) {  // 0x90A42E
  Samus_JumpingMovement();
}

/**
* @brief Handle Samus spin jumping movement
*/
void Samus_Movement_03_SpinJumping(void) {  // 0x90A436
  static const uint16 kSamusPhys_JumpMinYVelAir = 0x280;
  static const uint16 kSamusPhys_JumpMaxYVelAir = 0x500;
  static const uint16 kSamusPhys_JumpMinYVelWater = 0x80;
  static const uint16 kSamusPhys_JumpMaxYVelWater = 0x500;

  bool is_liquid_physics = false;
  if (!(samus_suit_palette_index & kSuitPaletteIndex_4_Gravity)) {
    int16 samus_top_bound = Samus_GetTopBound();
    if ((int16)fx_y_pos >= 0) {
      if ((int16)fx_y_pos < samus_top_bound && !(fx_liquid_options & kFxLiquidOption_4_LiquidPhysicsDisabled)) {
        is_liquid_physics = true;
      }
    }
    else if (0 <= (int16)lava_acid_y_pos && (int16)lava_acid_y_pos < samus_top_bound)
      is_liquid_physics = true;
  }

  if (!is_liquid_physics) {

    if (equipped_items & kItem_SpaceJump) {
      if (samus_y_dir == kSamusYDir_Down) {
        int16 y_speed = PAIR16(LOBYTE(samus_y_speed), HIBYTE(samus_y_subspeed));
        if (liquid_physics_type != kLiquidPhysicsType_Air) {
          if (kSamusPhys_JumpMinYVelWater <= y_speed && y_speed < kSamusPhys_JumpMaxYVelWater) {
            UNUSED_word_7E0DFA = UNUSED_word_7E0DFA & 0xFF00 | 1;
            if (joypad1_newkeys & button_config_jump)
              Samus_InitJump(); // bug: this overwrites x_whole_speed
          }
        }
        else if (kSamusPhys_JumpMinYVelAir <= y_speed && y_speed < kSamusPhys_JumpMaxYVelAir) {
          UNUSED_word_7E0DFA = UNUSED_word_7E0DFA & 0xFF00 | 1;
          if (joypad1_newkeys & button_config_jump)
            Samus_InitJump(); // bug: this overwrites x_whole_speed
        }
      }
    }

    if (samus_pose == kPose_81_FaceR_Screwattack || samus_pose == kPose_82_FaceL_Screwattack) {
      samus_contact_damage_index = kSamusContactDamageIndex_3_ScrewAttack;
    }
    else if (flare_counter >= 60) {
      samus_contact_damage_index = kSamusContactDamageIndex_4_PsuedoScrewAttack;
    }
  }
  else {
    // Warning: OOB
    if (samus_anim_frame_timer == 1 && kSamusFramesForUnderwaterSfx[samus_anim_frame])
      QueueSfx1_Max6(kSfx1_UnderwaterSpaceJump);
  }
  Samus_SpinJumpMovement();
}

/**
* @brief Handle Samus morph ball on ground
*/
void Samus_Movement_04_MorphBallOnGround(void) {  // 0x90A521
  if (samus_x_accel_mode == kSamusXAccelMode_0_Accelerate) {
    if (samus_pose_x_dir == kSamusXDir_FaceLeft && samus_pose == kPose_41_FaceL_Morphball_Ground
        || samus_pose_x_dir != kSamusXDir_FaceLeft && samus_pose == kPose_1D_FaceR_Morphball_Ground) {
      Samus_Move_NoBaseSpeed_X();
      if (!Samus_MoveY_Simple()) {
        Samus_Move_NoSpeedCalc_Y();
        Samus_CancelSpeedBoost();
        samus_x_extra_run_speed = 0;
        samus_x_extra_run_subspeed = 0;
        samus_x_base_speed = 0;
        samus_x_base_subspeed = 0;
        samus_x_accel_mode = kSamusXAccelMode_0_Accelerate;
      }
      return;
    }
  }
  Samus_HandleMovement_X();
  if (!Samus_MoveY_Simple())
    Samus_Move_NoSpeedCalc_Y();
}

/**
* @brief Handle Samus crouching movement
*/
void Samus_Movement_05_Crouching(void) {  // 0x90A573
  Samus_Move_NoBaseSpeed_X();
  Samus_Move_NoSpeedCalc_Y();
  samus_x_extra_run_speed = 0;
  samus_x_extra_run_subspeed = 0;
  samus_x_base_speed = 0;
  samus_x_base_subspeed = 0;
  samus_x_accel_mode = kSamusXAccelMode_0_Accelerate;
}

/**
* @brief Handle Samus falling movment
*/
void Samus_Movement_06_Falling(void) {  // 0x90A58D
  Samus_FallingMovement();
  if ((samus_pose == kPose_29_FaceR_Fall || samus_pose == kPose_2A_FaceL_Fall
      || samus_pose == kPose_67_FaceR_Fall_Gun || samus_pose == kPose_68_FaceL_Fall_Gun)) {
    if ((int16)samus_y_speed >= 5 && (int16)samus_anim_frame < 5) {
      samus_anim_frame_timer = 8;
      samus_anim_frame = 5;
    }
  }
}

/**
* @brief Handle Samus morph ball falling movement
*/
void Samus_Movement_08_MorphBallFalling(void) {  // 0x90A5CA
  if (!(joypad1_lastkeys & (kButton_Left|kButton_Right)) && samus_x_accel_mode == kSamusXAccelMode_0_Accelerate) {
    Samus_CancelSpeedBoost();
    samus_x_extra_run_speed = 0;
    samus_x_extra_run_subspeed = 0;
    samus_x_base_speed = 0;
    samus_x_base_subspeed = 0;
    samus_x_accel_mode = kSamusXAccelMode_0_Accelerate;
  }
  if (morph_ball_bounce_state != kMorphBallBounceState_NoBounce)
    Samus_MorphedBouncingMovement();
  else
    Samus_MorphedFallingMovement();
}

void Samus_Movement_09_Unused(void) {  // 0x90A5FB
  ;
}

/**
* @brief Handle Samus knockback or crystal flash ending movement
*/
void Samus_Movement_0A_KnockbackOrCrystalFlashEnding(void) {  // 0x90A5FC
  samus_solid_vertical_coll_result = kSolidVertCollResult_0_NoChange;
  Samus_Move_NoSpeedCalc_Y();
}

void Samus_Movement_0B_Unused(void) {  // 0x90A607
  samus_solid_vertical_coll_result = kSolidVertCollResult_0_NoChange;
}

void Samus_Movement_0C_Unused(void) {  // 0x90A60F
  samus_solid_vertical_coll_result = kSolidVertCollResult_0_NoChange;
}

void Samus_Movement_0D_Unused(void) {  // 0x90A617
  ;
}

/**
* @brief Do nothing for crouching, standing, morphing, unmorphing transitions
*/
void SamusCrouching_Nothing(void) {}

static HandlerFunc *const kSamusCrouchingEtcFuncs[12] = {  // 0x90A61C
  [kPose_35_FaceR_CrouchTrans - kPose_35_FaceR_CrouchTrans]  = SamusCrouching_Nothing,
  [kPose_36_FaceL_CrouchTrans - kPose_35_FaceR_CrouchTrans]  = SamusCrouching_Nothing,
  [kPose_37_FaceR_MorphTrans - kPose_35_FaceR_CrouchTrans]   = SamusCrouching_Nothing,
  [kPose_38_FaceL_MorphTrans - kPose_35_FaceR_CrouchTrans]   = SamusCrouching_Nothing,
  [kPose_39 - kPose_35_FaceR_CrouchTrans]                    = UNUSED_SamusCrouching_Nothing,
  [kPose_3A - kPose_35_FaceR_CrouchTrans]                    = UNUSED_SamusCrouching_Nothing,
  [kPose_3B_FaceR_StandTrans - kPose_35_FaceR_CrouchTrans]   = SamusCrouching_Nothing,
  [kPose_3C_FaceL_StandTrans - kPose_35_FaceR_CrouchTrans]   = SamusCrouching_Nothing,
  [kPose_3D_FaceR_UnmorphTrans - kPose_35_FaceR_CrouchTrans] = SamusCrouching_Nothing,
  [kPose_3E_FaceL_UnmorphTrans - kPose_35_FaceR_CrouchTrans] = SamusCrouching_Nothing,
  [kPose_3F - kPose_35_FaceR_CrouchTrans]                    = UNUSED_SamusCrouching_Nothing,
  [kPose_40 - kPose_35_FaceR_CrouchTrans]                    = UNUSED_SamusCrouching_Nothing,
};

/**
* @brief Handle Samus crouching, standing, morphing, unmorphing transitions movement
*/
void Samus_Movement_0F_CrouchingEtcTransition(void) {
  if (samus_pose < kPose_F1_FaceR_CrouchTrans_AimU) {
    if (samus_pose <= kPose_DA_FaceL_Xray_Crouch) {
      kSamusCrouchingEtcFuncs[samus_pose - kPose_35_FaceR_CrouchTrans]();
      Samus_Move_NoBaseSpeed_X();
      if (!Samus_MoveY_Simple_())
        Samus_Move_NoSpeedCalc_Y();
    }
  }
  else {
    Samus_Move_NoBaseSpeed_X();
    if (!Samus_MoveY_Simple_())
      Samus_Move_NoSpeedCalc_Y();
  }

  if (LOBYTE(samus_solid_vertical_coll_result) == (kSolidVertCollResult_1_Landed)
      && HIBYTE(samus_solid_vertical_coll_result) == kDownwardCollResult_Landed_4_NoChange) {
    samus_y_subspeed = 0;
    samus_y_speed = 0;
    samus_y_dir = kSamusYDir_None;
    morph_ball_bounce_state = kMorphBallBounceState_NoBounce;
  }
  samus_solid_vertical_coll_result = kSolidVertCollResult_0_NoChange;
}

void UNUSED_SamusCrouching_Nothing(void) {  // 0x90A672
  enable_horiz_slope_coll = 3;
  UNUSED_word_7E0AA4 = 0;
}

/**
* @brief Handle Samus turning around on ground movement
*/
void Samus_Movement_0E_TurningAroundOnGround(void) {  // 0x90A67C
  Samus_HandleMovement_X();
  Samus_Move_NoSpeedCalc_Y();
  Samus_CancelSpeedBoost();
  samus_x_extra_run_speed = 0;
  samus_x_extra_run_subspeed = 0;
  samus_solid_vertical_coll_result = kSolidVertCollResult_0_NoChange;
}

/**
* @brief Handle Samus moonwalking movement
*/
void Samus_Movement_10_Moonwalking(void) {  // 0x90A694
  Samus_HandleMovement_X();
  Samus_Move_NoSpeedCalc_Y();
}

/**
* @brief Handle Samus spring ball on ground movement
*/
void Samus_Movement_11_SpringBallOnGround(void) {  // 0x90A69F
  if (samus_x_accel_mode == kSamusXAccelMode_0_Accelerate) {
    if ((samus_pose_x_dir == kSamusXDir_FaceLeft && samus_pose == kPose_7A_FaceL_Springball_Ground)
        || samus_pose == kPose_79_FaceR_Springball_Ground) {
      Samus_Move_NoBaseSpeed_X();
      if (!Samus_MoveY_Simple()) {
        Samus_Move_NoSpeedCalc_Y();
        Samus_CancelSpeedBoost();
        samus_x_extra_run_speed = 0;
        samus_x_extra_run_subspeed = 0;
        samus_x_base_speed = 0;
        samus_x_base_subspeed = 0;
        samus_x_accel_mode = kSamusXAccelMode_0_Accelerate;
      }
      return;
    }
  }
  Samus_HandleMovement_X();
  if (!Samus_MoveY_Simple())
    Samus_Move_NoSpeedCalc_Y();
}

/**
* @brief Handle Samus spring ball in air movement
*/
void Samus_Movement_12_SpringBallInAir(void) {  // 0x90A6F1
  if (morph_ball_bounce_state != kMorphBallBounceState_NoBounce)
    Samus_MorphedBouncingMovement();
  else
    Samus_JumpingMovement();
}

/**
* @brief Handle Samus spring ball falling movement
*/
void Samus_Movement_13_SpringBallFalling(void) {  // 0x90A703
  if (!(joypad1_lastkeys & (kButton_Left|kButton_Right)) && samus_x_accel_mode == kSamusXAccelMode_0_Accelerate) {
    Samus_CancelSpeedBoost();
    samus_x_extra_run_speed = 0;
    samus_x_extra_run_subspeed = 0;
    samus_x_base_speed = 0;
    samus_x_base_subspeed = 0;
    samus_x_accel_mode = kSamusXAccelMode_0_Accelerate;
  }
  if (morph_ball_bounce_state != kMorphBallBounceState_NoBounce)
    Samus_MorphedBouncingMovement();
  else
    Samus_MorphedFallingMovement();
}

/**
* @brief Handle Samus wall jumping movement
*/
void Samus_Movement_14_WallJumping(void) {  // 0x90A734
  if (samus_anim_frame < 23) {
    if (samus_anim_frame >= 3 && flare_counter >= 60)
      samus_contact_damage_index = kSamusContactDamageIndex_4_PsuedoScrewAttack;
  }
  else {
    samus_contact_damage_index = kSamusContactDamageIndex_3_ScrewAttack;
  }
  Samus_JumpingMovement();
}

/**
* @brief Handle Samus running into a wall movement
*/
void Samus_Movement_15_RanIntoWall(void) {  // 0x90A75F
  Samus_Move_NoBaseSpeed_X();
  Samus_Move_NoSpeedCalc_Y();
  Samus_CancelSpeedBoost();
  samus_x_extra_run_speed = 0;
  samus_x_extra_run_subspeed = 0;
  samus_x_base_speed = 0;
  samus_x_base_subspeed = 0;
  samus_x_accel_mode = kSamusXAccelMode_0_Accelerate;
}

/**
* @brief Handle Samus grappling movement
*/
void Samus_Movement_16_Grappling(void) {  // 0x90A780
  if (samus_solid_vertical_coll_result != kSolidVertCollResult_5_WallJumped)
    samus_solid_vertical_coll_result = kSolidVertCollResult_0_NoChange;
}

/**
* @brief Handle Samus turning around while jumping movement
*/
void Samus_Movement_17_TurningAroundJumping(void) {  // 0x90A790
  Samus_HandleMovement_X();
  if (!Samus_MoveY_Simple())
    Samus_Move_NoSpeedCalc_Y();
  Samus_CancelSpeedBoost();
  samus_x_extra_run_speed = 0;
  samus_x_extra_run_subspeed = 0;
  samus_solid_vertical_coll_result = kSolidVertCollResult_0_NoChange;
}

/**
* @brief Handle Samus turning around while falling movement
*/
void Samus_Movement_18_TurningAroundFalling(void) {  // 0x90A7AD
  Samus_HandleMovement_X();
  if (!Samus_MoveY_Simple())
    Samus_Move_NoSpeedCalc_Y();
  Samus_CancelSpeedBoost();
  samus_x_extra_run_speed = 0;
  samus_x_extra_run_subspeed = 0;
  samus_solid_vertical_coll_result = kSolidVertCollResult_0_NoChange;
}

/**
* @brief Handle Samus damage boost movement
*/
void Samus_Movement_19_DamageBoost(void) {  // 0x90A7CA
  Samus_JumpingMovement();
}

/**
* @brief Handle Samus being grabbed by Draygon movement
*/
void Samus_Movement_1A_GrabbedByDraygon(void) {  // 0x90A7D2
  samus_solid_vertical_coll_result = kSolidVertCollResult_0_NoChange;
}

/**
* @brief Handle Samus shinespark, crystal flash, drained by metroid, damaged by mother brain's attack movement
*/
void Samus_Movement_1B_ShinesparkEtc(void) {  // 0x90A7DA
  samus_solid_vertical_coll_result = kSolidVertCollResult_0_NoChange;
}

static const uint8 kMapTileBitmask_1Bit[8] = { 0x80, 0x40, 0x20, 0x10, 8, 4, 2, 1 };
static const uint16 kMapTileBitmask_6Bits[8] = { 0xfc00, 0x7e00, 0x3f00, 0x1f80, 0xfc0, 0x7e0, 0x3f0, 0x1f8 };

/**
* @brief Mark the map tile as explored
* @param room_pixel_x_offset X position offset from room top-left corner in pixels
* @param room_pixel_y_offset Y position offset from room top-left corner in pixels
*/
static void MarkMapTileAsExplored(uint16 room_pixel_x_offset, uint16 room_pixel_y_offset) {  // 0x90A8A6
  uint8 room_screen_x_offset = HIBYTE(room_pixel_x_offset);
  uint8 room_screen_y_offset = HIBYTE(room_pixel_y_offset);
  uint16 map_coord_x_offset = room_x_coordinate_on_map + room_screen_x_offset;
  uint16 map_coord_y_offset = room_y_coordinate_on_map + room_screen_y_offset;

  uint16 map_page = map_coord_x_offset & 0x20;
  uint16 col_byte_idx = (map_coord_x_offset & 0x1F) / 8;
  uint16 next_row_idx = map_coord_y_offset + 1;

  uint16 map_coord_byte_idx = 4 * (map_page + next_row_idx) + col_byte_idx;
  uint16 col_bit_subindex = map_coord_x_offset & 7;

  map_tiles_explored[map_coord_byte_idx] |= kMapTileBitmask_1Bit[col_bit_subindex];
}

/**
* @brief Blank out the minimap and mark the current boss room as explored
*/
void DisableMinimapAndMarkBossRoomAsExplored(void) {  // 0x90A7E2
  static const MarkMapTileExplored *boss_room_tiles;

  disable_minimap = 1;
  memset7E(hud_tilemap.row1.minimap, 0x2C1F, sizeof(hud_tilemap.row1.minimap));
  memset7E(hud_tilemap.row2.minimap, 0x2C1F, sizeof(hud_tilemap.row2.minimap));
  memset7E(hud_tilemap.row3.minimap, 0x2C1F, sizeof(hud_tilemap.row3.minimap));

  int idx = 5;
  while (boss_id != kBossRoomMapTile[idx].boss_id_) {
    if (--idx < 0)
      return;
  }
  for (boss_room_tiles = kBossRoomMapTile[idx].ptrs; boss_room_tiles->room_pixel_x_offset != 0xFFFF; boss_room_tiles++) {
    MarkMapTileAsExplored(boss_room_tiles->room_pixel_x_offset, boss_room_tiles->room_pixel_y_offset);
  }
}

/**
* @brief This function does not work correctly in the original game as it does not call UpdateHudMinimapTilemap()
* with the proper inputs
*/
void InitializeMiniMapBroken(void) {  // 0x90A8EF
  //SetR18_R20(room_x_coordinate_on_map + ((samus_x_pos & 0xFF00) >> 8), lo_opp >> 3);
  //R22_ = room_y_coordinate_on_map + ((samus_y_pos & 0xFF00) >> 8) + 1;
  //UpdateHudMinimapTilemap();
}


/**
* @brief Update the current mini-map position
*/
void UpdateMinimap(void) {  // 0x90A91B
  if (disable_minimap || (samus_x_pos / 16) >= room_width_in_blocks || (samus_y_pos / 16) >= room_height_in_blocks)
    return;

  uint16 map_pos_not_at_minimap_origin_flag = 0;
  uint8 samus_x_screen_pos = HIBYTE(samus_x_pos);
  uint8 samus_y_screen_pos = HIBYTE(samus_y_pos);
  uint16 map_coord_x_offset = room_x_coordinate_on_map + samus_x_screen_pos;
  uint16 map_coord_y_offset = room_y_coordinate_on_map + samus_y_screen_pos;
  uint16 samus_map_page_pos = map_coord_x_offset & 0x20;
  uint16 samus_map_x_coord = map_coord_x_offset & 0x1F;
  uint16 samus_map_col_bit_subindex = map_coord_x_offset & 7;
  uint16 samus_map_col_byte_idx = (map_coord_x_offset & 0x1F) >> 3;
  uint16 samus_map_row_idx = map_coord_y_offset + 1;
  uint16 samus_map_coord_byte_idx = 4 * (samus_map_page_pos + samus_map_row_idx) + samus_map_col_byte_idx;
  map_tiles_explored[samus_map_coord_byte_idx] |= kMapTileBitmask_1Bit[samus_map_col_bit_subindex];
  uint16 samus_map_pos_col_bit_subindex = samus_map_col_bit_subindex;
  uint16 samus_map_pos_map_coord_byte_index = samus_map_coord_byte_idx;
  samus_map_coord_byte_idx -= 4;
  samus_map_col_bit_subindex -= 2;
  if ((int16)samus_map_col_bit_subindex < 0) {
    samus_map_col_bit_subindex &= 7;
    --samus_map_coord_byte_idx;
    ++map_pos_not_at_minimap_origin_flag;
  }
  uint16 minimap_origin_map_coord_byte_idx = samus_map_coord_byte_idx;
  int minimap_origin_col_bit_subindex = 2 * samus_map_col_bit_subindex;
  int idx = minimap_origin_col_bit_subindex >> 1;
  uint16 map_tiles_explored_row0_bits = kMapTileBitmask_6Bits[idx] & swap16(*(uint16 *)&map_tiles_explored[samus_map_coord_byte_idx]);
  uint16 map_tiles_explored_row1_bits = kMapTileBitmask_6Bits[idx] & swap16(*(uint16 *)&map_tiles_explored[samus_map_coord_byte_idx + 4]);
  uint16 map_tiles_explored_row2_bits = kMapTileBitmask_6Bits[idx] & swap16(*(uint16 *)&map_tiles_explored[samus_map_coord_byte_idx + 8]);
  const uint8 *minimap_origin_map_data_ptr = kPauseMenuMapData[area_index];
  const uint8 *area_map_data_ptr = minimap_origin_map_data_ptr;
  minimap_origin_map_data_ptr += samus_map_coord_byte_idx;
  uint16 map_tiles_row0_bits = swap16(GET_WORD(minimap_origin_map_data_ptr));
  minimap_origin_map_data_ptr += 4;
  uint16 map_tiles_row1_bits = swap16(GET_WORD(minimap_origin_map_data_ptr));
  minimap_origin_map_data_ptr += 4;
  uint16 map_tiles_row2_bits = swap16(GET_WORD(minimap_origin_map_data_ptr));
  if ((minimap_origin_map_coord_byte_idx & 3) == 3) {
    int16 col_bit_subindex = map_pos_not_at_minimap_origin_flag
                             ? minimap_origin_col_bit_subindex / 2
                             : samus_map_pos_col_bit_subindex;
    if (col_bit_subindex >= 6) {
      uint8 spilt_map_bits_byte_index = samus_map_page_pos ? (minimap_origin_map_coord_byte_idx + (-0x80 + 4))
                                                           : (minimap_origin_map_coord_byte_idx + (0x80 - 3));

      // Port code inlines the function for some reason
      // AdjustMapBitsForMapPageSpill - 0x90AB75 {
      uint16 spilt_map_tiles_explored_row_bits = 0;
      minimap_origin_map_data_ptr = area_map_data_ptr + spilt_map_bits_byte_index;
      LOBYTE(spilt_map_tiles_explored_row_bits) = map_tiles_explored[spilt_map_bits_byte_index];
      HIBYTE(spilt_map_tiles_explored_row_bits) = *minimap_origin_map_data_ptr;
      if ((uint8)samus_map_page_pos == 32) {
        HIBYTE(map_tiles_row0_bits) = HIBYTE(spilt_map_tiles_explored_row_bits);
        HIBYTE(map_tiles_explored_row0_bits) = spilt_map_tiles_explored_row_bits;
      }
      else {
        LOBYTE(map_tiles_row0_bits) = HIBYTE(spilt_map_tiles_explored_row_bits);
        LOBYTE(map_tiles_explored_row0_bits) = spilt_map_tiles_explored_row_bits;
      }

      LOBYTE(spilt_map_tiles_explored_row_bits) = map_tiles_explored[spilt_map_bits_byte_index + 4];
      minimap_origin_map_data_ptr += 4;
      HIBYTE(spilt_map_tiles_explored_row_bits) = *minimap_origin_map_data_ptr;
      if ((uint8)samus_map_page_pos == 32) {
        HIBYTE(map_tiles_row1_bits) = HIBYTE(spilt_map_tiles_explored_row_bits);
        HIBYTE(map_tiles_explored_row1_bits) = spilt_map_tiles_explored_row_bits;
      }
      else {
        LOBYTE(map_tiles_row1_bits) = HIBYTE(spilt_map_tiles_explored_row_bits);
        LOBYTE(map_tiles_explored_row1_bits) = spilt_map_tiles_explored_row_bits;
      }

      LOBYTE(spilt_map_tiles_explored_row_bits) = map_tiles_explored[spilt_map_bits_byte_index + 8];
      minimap_origin_map_data_ptr += 4;
      HIBYTE(spilt_map_tiles_explored_row_bits) = *minimap_origin_map_data_ptr;
      if ((uint8)samus_map_page_pos == 32) {
        HIBYTE(map_tiles_row2_bits) = HIBYTE(spilt_map_tiles_explored_row_bits);
        HIBYTE(map_tiles_explored_row2_bits) = spilt_map_tiles_explored_row_bits;
      }
      else {
        LOBYTE(map_tiles_row2_bits) = HIBYTE(spilt_map_tiles_explored_row_bits);
        LOBYTE(map_tiles_explored_row2_bits) = spilt_map_tiles_explored_row_bits;
      }
      // }

    }
  }

  map_tiles_explored_row0_bits <<= minimap_origin_col_bit_subindex / 2;
  map_tiles_row0_bits <<= minimap_origin_col_bit_subindex / 2;
  map_tiles_explored_row1_bits <<= minimap_origin_col_bit_subindex / 2;
  map_tiles_row1_bits <<= minimap_origin_col_bit_subindex / 2;
  map_tiles_explored_row2_bits <<= minimap_origin_col_bit_subindex / 2;
  map_tiles_row2_bits <<= minimap_origin_col_bit_subindex / 2;
  UpdateHudMinimapTilemap(samus_map_x_coord, samus_map_row_idx, samus_map_page_pos, samus_map_pos_map_coord_byte_index, samus_map_pos_col_bit_subindex, map_tiles_row0_bits, map_tiles_explored_row0_bits, map_tiles_row1_bits, map_tiles_explored_row1_bits, map_tiles_row2_bits, map_tiles_explored_row2_bits);
}

/**
* @brief Draw the HUD minimap
*/
void UpdateHudMinimapTilemap(uint16 samus_map_x_coord, uint16 samus_map_row_idx, uint16 samus_map_page_pos, 
                             uint16 samus_map_pos_map_coord_byte_index, uint16 samus_map_pos_col_bit_subindex,
                             uint16 map_tiles_row0_bits, uint16 map_tiles_explored_row0_bits,
                             uint16 map_tiles_row1_bits, uint16 map_tiles_explored_row1_bits,
                             uint16 map_tiles_row2_bits, uint16 map_tiles_explored_row2_bits) {  // 0x90AA43
  int16 map_origin_bit_idx;
  int16 map_tile;

  /* @todo figure out what hi_opp is */
  uint16 v0 = swap16(samus_map_page_pos + samus_map_row_idx) >> 3;
  uint16 samus_map_coord_bit_idx = samus_map_x_coord + v0;
  if (samus_map_page_pos != 0 && (samus_map_coord_bit_idx & 0x1F) < 2)
    map_origin_bit_idx = samus_map_coord_bit_idx - 0x20 - 2 + 0x20 - 0x400;
  else
    map_origin_bit_idx = samus_map_coord_bit_idx - 0x20 - 2;
  uint16 map_tilemap_idx = 2 * map_origin_bit_idx;
  const uint16 *map_tilemap_row0_ptr = (const uint16 *)RomPtr(Load24(&kPauseMenuMapTilemaps_90[area_index]));
  const uint16 *map_tilemap_row1_ptr = map_tilemap_row0_ptr + 0x20;
  const uint16 *map_tilemap_row2_ptr = map_tilemap_row0_ptr + 0x40;
  uint16 hud_minimap_tilemap_idx = 0;
  uint16 blank_tile = 0x1F;
  for (int map_cols = 5; map_cols > 0; map_cols--) {
    int hud_idx = hud_minimap_tilemap_idx >> 1;
    int tilemap_idx = map_tilemap_idx >> 1;

    // Tilemap & 0xC3FF zeroes the palette bits and priority bit, and the | sets the palette bits and priority bit
    bool map_tile_bit_set = sign16(map_tiles_row0_bits);
    map_tiles_row0_bits <<= 1;
    if (!map_tile_bit_set || (map_tile = map_tilemap_row0_ptr[tilemap_idx], !has_area_map))
      map_tile = blank_tile;
    hud_tilemap.row1.minimap[hud_idx] = map_tile & 0xC3FF | 0x2C00;

    map_tile_bit_set = sign16(map_tiles_explored_row0_bits);
    map_tiles_explored_row0_bits <<= 1;
    if (map_tile_bit_set)
      hud_tilemap.row1.minimap[hud_idx] = map_tilemap_row0_ptr[tilemap_idx] & 0xC3FF | 0x2800;
    
    map_tile_bit_set = sign16(map_tiles_row1_bits);
    map_tiles_row1_bits <<= 1;
    if (!map_tile_bit_set || (map_tile = map_tilemap_row1_ptr[tilemap_idx], !has_area_map))
      map_tile = blank_tile;
    hud_tilemap.row2.minimap[hud_idx] = map_tile & 0xC3FF | 0x2C00;

    map_tile_bit_set = sign16(map_tiles_explored_row1_bits);
    map_tiles_explored_row1_bits <<= 1;
    if (map_tile_bit_set) {
      hud_tilemap.row2.minimap[hud_idx] = map_tilemap_row1_ptr[tilemap_idx] & 0xC3FF | 0x2800;
      if (map_cols == 3 && (hud_tilemap.row2.minimap[hud_idx] & 0x1FF) == 40) {
        // Port code inlines this function for some reason
        // MarkMapTileAboveSamusAsExplored - 0x90AB5F {
        map_tiles_explored[(samus_map_pos_map_coord_byte_index-2) >> 1] |= kMapTileBitmask_1Bit[samus_map_pos_col_bit_subindex];
        // }
      }
    }

    map_tile_bit_set = sign16(map_tiles_row2_bits);
    map_tiles_row2_bits <<= 1;
    if (!map_tile_bit_set || (map_tile = map_tilemap_row2_ptr[tilemap_idx], !has_area_map))
      map_tile = blank_tile;
    hud_tilemap.row3.minimap[hud_idx] = map_tile & 0xC3FF | 0x2C00;

    map_tile_bit_set = sign16(map_tiles_explored_row2_bits);
    map_tiles_explored_row2_bits <<= 1;
    if (map_tile_bit_set)
      hud_tilemap.row3.minimap[hud_idx] = map_tilemap_row2_ptr[tilemap_idx] & 0xC3FF | 0x2800;

    hud_minimap_tilemap_idx += 2;
    map_tilemap_idx += 2;
    if ((map_tilemap_idx & 0x3F) == 0)
      map_tilemap_idx += (0x800 - 0x40);
  }

  if ((nmi_frame_counter_byte & 8) == 0)
    hud_tilemap.row2.minimap_samus_pos |= 0x1C00;
}

/**
* @brief Handle cool down timer for projectiles
*/
void Samus_HandleCooldown(void) {  // 0x90AC1C
  if (time_is_frozen_flag) {
    cooldown_timer = 32;
  }
  else  {
    cooldown_timer = IntMax(0, cooldown_timer - 1);
  }
}

/**
* @brief Determine if Samus is able to fire her beam
* @return uint8 1 if Samus can fire beam, else 0
*/
uint8 Samus_CanFireBeam(void) {  // 0x90AC39
  if (projectile_counter >= 5 || (uint8)cooldown_timer != 0)
    return 0;
  cooldown_timer = 1;
  ++projectile_counter;
  return 1;
}

/**
* @brief Determine if Samus is able to fire a missile or super missile
* @return uint8 1 if Samus can fire super/missile, else 0
*/
uint8 Samus_CanFireAnyMissile(void) {  // 0x90AC5A
  if (hud_item_index != kHudItem_2_SuperMissile || projectile_counter < 4) {
    if (projectile_counter >= 5)
      return 0;
    if ((uint8)cooldown_timer == 0) {
      cooldown_timer = 1;
      ++projectile_counter;
      return 1;
    }
  }
  return 0;
}


/**
* @brief Set up transfer of beam tiles to VRAM and transfer the beam palette to sprite palette 6
*/
void UpdateBeamTilesAndPalette(void) {  // 0x90AC8D
  uint16 beam_idx = 2 * (equipped_beams & 0xFFF);
  VramWriteEntry *vram_entry = gVramWriteEntry(vram_write_queue_tail);
  vram_entry->size = 0x100;
  vram_entry->src.addr = kBeamTilePtrs[beam_idx >> 1];
  vram_entry->src.bank = 0x9A;
  vram_entry->vram_dst = addr_kVram_Beam;
  vram_write_queue_tail += sizeof(VramWriteEntry);
  WriteBeamPalette_Y(beam_idx);
}

/**
* @brief Transfer the beam palette to sprite palette 6
* @param beams The beams Samus has equipped
*/
void WriteBeamPalette_A(uint16 beams) {  // 0x90ACC2
  WriteBeamPalette_Y(2 * (beams & 0xFFF));
}

/**
* @brief Transfer the beam palette to sprite palette 6
* @param beam_idx The beams Samus has equipped as an index
*/
void WriteBeamPalette_Y(uint16 beam_idx) {  // 0x90ACCD
  uint16 beam_pal_ptr = kBeamPalettePtrs[beam_idx >> 1];
  uint16 beam_pal_idx = 0, pal_idx = 0;
  //MemCpy(palette_buffer.sprite_pal_6, beam_pal, sizeof(beam_pal));
  do {
    palette_buffer.sprite_pal_6[pal_idx >> 1] = GET_WORD(RomPtr_90(beam_pal_ptr + beam_pal_idx));
    pal_idx += 2;
    beam_pal_idx += 2;
  } while (beam_pal_idx < sizeof(palette_buffer.sprite_pal_6));
}

/**
* @brief Transfer the beam palette to sprite palette 6
* @param beams The beams Samus has equipped
*/
void LoadProjectilePalette(uint16 beams) {  // 0x90ACFC
  uint16 beam_pal_ptr = kBeamPalettePtrs[beams & 0xFFF];
  uint16 beam_pal_idx = 0, pal_idx = 0;
  //MemCpy(palette_buffer.sprite_pal_6, beam_pal, sizeof(beam_pal));
  do {
    palette_buffer.sprite_pal_6[pal_idx >> 1] = GET_WORD(RomPtr_90(beam_pal_ptr + beam_pal_idx));
    pal_idx += 2;
    beam_pal_idx += 2;
  } while (beam_pal_idx < sizeof(palette_buffer.sprite_pal_6));
}

/**
* @brief Clear data for all projectile slots
*/
void ResetProjectileData(void) {  // 0x90AD22
  for (uint16 proj_idx = 0; proj_idx < 20; proj_idx += 2) {
    int idx = proj_idx >> 1;
    projectile_trail_timers[idx] = 0;
    projectile_x_pos[idx] = 0;
    projectile_y_pos[idx] = 0;
    projectile_dir[idx] = 0;
    projectile_x_speed[idx] = 0;
    projectile_y_speed[idx] = 0;
    projectile_x_radius[idx] = 0;
    projectile_y_radius[idx] = 0;
    projectile_type[idx] = 0;
    projectile_damage[idx] = 0;
    projectile_instruction_ptr[idx] = 0;
    projectile_instruction_timers[idx] = 0;
    projectile_variables[idx] = 0;
    projectile_spritemap_pointers[idx] = 0;
    projectile_pre_instructions[idx] = FUNC16(ProjPreInstr_Empty);
  }

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

/**
* @brief Clear the data for the projectile
* @param proj_idx The index of the current projectile
*/
void ClearProjectile(uint16 proj_idx) {  // 0x90ADB7
  int idx = proj_idx >> 1;
  projectile_x_pos[idx] = 0;
  projectile_y_pos[idx] = 0;
  projectile_x_subpos[idx] = 0;
  projectile_y_subpos[idx] = 0;
  projectile_dir[idx] = 0;
  projectile_x_speed[idx] = 0;
  projectile_y_speed[idx] = 0;
  projectile_x_radius[idx] = 0;
  projectile_y_radius[idx] = 0;
  projectile_type[idx] = 0;
  projectile_damage[idx] = 0;
  projectile_instruction_ptr[idx] = 0;
  projectile_instruction_timers[idx] = 0;
  projectile_variables[idx] = 0;
  projectile_spritemap_pointers[idx] = 0;
  projectile_pre_instructions[idx] = FUNC16(ProjPreInstr_Empty);
  // Projectile slots 5+ are bomb spread
  if ((int16)proj_idx >= 10) {
    bomb_counter = IntMax(0, bomb_counter - 1);
  }
  else {
    projectile_counter = IntMax(0, projectile_counter - 1);
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

/**
* @brief Handle deleting a projectile
* @param proj_idx The index of the current projectile
*/
void KillProjectile(uint16 proj_idx) {
  int idx = proj_idx >> 1;
  if (projectile_type[idx] & kProjectileType_ProjMask) {
    if ((projectile_type[idx] & kProjectileType_ProjMask) >= (kProjectileType_SuperMissile | kProjectileType_Missile)) {
      ClearProjectile(proj_idx);
      return;
    }
  }
  // Otherwise, the projectile is a beam
  else {
    kKillProjectileFuncs[projectile_dir[idx] & kProjectileDir_DirMask](proj_idx);
  }
  KillProjectileInner(proj_idx);
  projectile_pre_instructions[proj_idx >> 1] = FUNC16(ProjPreInstr_Empty);
}

/**
* @brief Move projectile up
* @param proj_idx The index of the current projectile
*/
void KillProjectileFunc_0_Up(uint16 proj_idx) {  // 0x90AE4E
  projectile_y_pos[proj_idx >> 1] -= projectile_y_radius[proj_idx >> 1];
}

/**
* @brief Move projectile up and right
* @param proj_idx The index of the current projectile
*/
void KillProjectileFunc_1_UpRight(uint16 proj_idx) {  // 0x90AE59
  int idx = proj_idx >> 1;
  projectile_x_pos[idx] += projectile_x_radius[idx];
  projectile_y_pos[idx] -= projectile_y_radius[idx];
}

/**
* @brief Move projectile right
* @param proj_idx The index of the current projectile
*/
void KillProjectileFunc_2_Right(uint16 proj_idx) {  // 0x90AE6E
  projectile_x_pos[proj_idx >> 1] += projectile_x_radius[proj_idx >> 1];
}

/**
* @brief Move projectile down and right
* @param proj_idx The index of the current projectile
*/
void KillProjectileFunc_3_DownRight(uint16 proj_idx) {  // 0x90AE79
  int idx = proj_idx >> 1;
  projectile_x_pos[idx] += projectile_x_radius[idx];
  projectile_y_pos[idx] += projectile_y_radius[idx];
}

/**
* @brief Move projectile down
* @param proj_idx The index of the current projectile
*/
void KillProjectileFunc_4_Down(uint16 proj_idx) {  // 0x90AE8E
  projectile_y_pos[proj_idx >> 1] += projectile_y_radius[proj_idx >> 1];
}

/**
* @brief Move projectile down and left
* @param proj_idx The index of the current projectile
*/
void KillProjectileFunc_6_DownLeft(uint16 proj_idx) {  // 0x90AE99
  int idx = proj_idx >> 1;
  projectile_x_pos[idx] -= projectile_x_radius[idx];
  projectile_y_pos[idx] += projectile_y_radius[idx];
}

/**
* @brief Move projectile left
* @param proj_idx The index of the current projectile
*/
void KillProjectileFunc_7_Left(uint16 proj_idx) {  // 0x90AEAE
  projectile_x_pos[proj_idx >> 1] -= projectile_x_radius[proj_idx >> 1];
}

/**
* @brief Move projectile up and left
* @param proj_idx The index of the current projectile
*/
void KillProjectileFunc_8_UpLeft(uint16 proj_idx) {  // 0x90AEB9
  int idx = proj_idx >> 1;
  projectile_x_pos[idx] -= projectile_x_radius[idx];
  projectile_y_pos[idx] -= projectile_y_radius[idx];
}

void CallProjPreInstr(uint32 ea, uint16 proj_idx) {
  switch (ea) {
  case fnProjPreInstr_Empty: return;
  case fnProjPreInstr_Beam_NoWaveBeam: ProjPreInstr_Beam_NoWaveBeam(proj_idx); return;
  case fnProjPreInstr_BlockCollNoWaveBeamVert: ProjPreInstr_BlockCollNoWaveBeamVert(proj_idx); return;
  case fnProjPreInstr_BlockCollNoWaveBeamDiagonal: ProjPreInstr_BlockCollNoWaveBeamDiagonal(proj_idx); return;
  case fnProjPreInstr_BlockCollNoWaveBeamHoriz: ProjPreInstr_BlockCollNoWaveBeamHoriz(proj_idx); return;
  case fnProjPreInstr_Missile: ProjPreInstr_Missile(proj_idx); return;
  case fnProjPreInstr_BlockCollMissileVert: ProjPreInstr_BlockCollMissileVert(proj_idx); return;
  case fnProjPreInstr_BlockCollMissileDiagonal: ProjPreInstr_BlockCollMissileDiagonal(proj_idx); return;
  case fnProjPreInstr_BlockCollMissileHoriz: ProjPreInstr_BlockCollMissileHoriz(proj_idx); return;
  case fnProjPreInstr_SuperMissile: ProjPreInstr_SuperMissile(proj_idx); return;
  case fnProjPreInstr_BlockCollSuperMissileVert: ProjPreInstr_BlockCollSuperMissileVert(proj_idx); return;
  case fnProjPreInstr_BlockCollSuperMissileDiagonal: ProjPreInstr_BlockCollSuperMissileDiagonal(proj_idx); return;
  case fnProjPreInstr_BlockCollSuperMissileHoriz: ProjPreInstr_BlockCollSuperMissileHoriz(proj_idx); return;
  case fnProjPreInstr_SuperMissileLink: ProjPreInstr_SuperMissileLink(proj_idx); return;
  case fnProjPreInstr_Bomb: ProjPreInstr_Bomb(proj_idx); return;
  case fnProjPreInstr_PowerBomb: ProjPreInstr_PowerBomb(proj_idx); return;
  case fnProjPreInstr_WaveCombined: ProjPreInstr_WaveCombined(proj_idx); return;
  case fnProjPreInstr_BeamOrIceWave: ProjPreInstr_BeamOrIceWave(proj_idx); return;
  case fnProjPreInstr_Wave_Shared: ProjPreInstr_Wave_Shared(proj_idx); return;
  case fnProjPreInstr_BlockCollWaveBeamVert: ProjPreInstr_BlockCollWaveBeamVert(proj_idx); return;
  case fnProjPreInstr_BlockCollWaveBeamDiagonal: ProjPreInstr_BlockCollWaveBeamDiagonal(proj_idx); return;
  case fnProjPreInstr_BlockCollWaveBeamHoriz: ProjPreInstr_BlockCollWaveBeamHoriz(proj_idx); return;
  case fnProjPreInstr_HyperBeam: ProjPreInstr_HyperBeam(proj_idx); return;
  case fnProjPreInstr_IceSbaMain: ProjPreInstr_IceSbaMain(proj_idx); return;
  case fnProjPreInstr_IceSbaEnd: ProjPreInstr_IceSbaEnd(proj_idx); return;
  case fnProjPreInstr_SpeedEcho: ProjPreInstr_SpeedEcho(proj_idx); return;
  case fnProjPreInstr_PlasmaSba: ProjPreInstr_PlasmaSba(proj_idx); return;
  case fnProjPreInstr_PlasmaSba_Phase0Expand: ProjPreInstr_PlasmaSba_Phase0_Expand(proj_idx); return;
  case fnProjPreInstr_PlasmaSba_Phase1Contract: ProjPreInstr_PlasmaSba_Phase1_Contract(proj_idx); return;
  case fnProjPreInstr_PlasmaSba_Phase2Disperse: ProjPreInstr_PlasmaSba_Phase2_Disperse(proj_idx); return;
  case fnProjPreInstr_SpreadBomb: ProjPreInstr_SpreadBomb(proj_idx); return;
  case fnProjPreInstr_WaveSba: ProjPreInstr_WaveSba(proj_idx); return;
  case fnProjPreInstr_SpazerSba: ProjPreInstr_SpazerSba(proj_idx); return;
  case fnProjPreInstr_EndOfSpazerSba: ProjPreInstr_EndOfSpazerSba(proj_idx); return;
  case fnProjPreInstr_UnknownProj8027: ProjPreInstr_UnknownProj8027(proj_idx); return;
  
  default: Unreachable();
  }
}

/**
* @brief Run pre instructions and instructions for each projectile
*/
void HandleProjectiles(void) {  // 0x90AECE
  for (projectile_index = 18; (int16)projectile_index >= 0; projectile_index -= 2) {
    int idx = projectile_index >> 1;
    if (projectile_instruction_ptr[idx] != 0) {
      CallProjPreInstr(projectile_pre_instructions[idx] | 0x900000, projectile_index);
      RunProjectileInstructions();
    }
  }
}

static Func_Y_V *const kProjPreInstr_Beam_Funcs[10] = {  // 0x90AEF3
  [kProjectileDir_UpFaceRight]   = ProjPreInstr_BlockCollNoWaveBeamVert,
  [kProjectileDir_UpRight]       = ProjPreInstr_BlockCollNoWaveBeamDiagonal,
  [kProjectileDir_Right]         = ProjPreInstr_BlockCollNoWaveBeamHoriz,
  [kProjectileDir_DownRight]     = ProjPreInstr_BlockCollNoWaveBeamDiagonal,
  [kProjectileDir_DownFaceRight] = ProjPreInstr_BlockCollNoWaveBeamVert,
  [kProjectileDir_DownFaceLeft]  = ProjPreInstr_BlockCollNoWaveBeamVert,
  [kProjectileDir_DownLeft]      = ProjPreInstr_BlockCollNoWaveBeamDiagonal,
  [kProjectileDir_Left]          = ProjPreInstr_BlockCollNoWaveBeamHoriz,
  [kProjectileDir_UpLeft]        = ProjPreInstr_BlockCollNoWaveBeamDiagonal,
  [kProjectileDir_UpFaceLeft]    = ProjPreInstr_BlockCollNoWaveBeamVert,
};

/**
* @brief Handle speed, trail, and instructions for non-wave beams
* @param proj_idx The index of the current projectile
*/
void ProjPreInstr_Beam_NoWaveBeam(uint16 proj_idx) {
  int idx = proj_idx >> 1;
  if (projectile_dir[idx] & (0xF0 | kProjectileDir_Delete)) {
    ClearProjectile(proj_idx);
  }
  else {
    if (--projectile_trail_timers[idx] == 0) {
      projectile_trail_timers[idx] = 4;
      SpawnProjectileTrail(proj_idx);
      proj_idx = projectile_index;
    }
    idx = proj_idx >> 1;
    int proj_dir_idx = projectile_dir[idx] & kProjectileDir_DirMask;
    projectile_x_speed[idx] += kProjDirAccel_X[proj_dir_idx];
    projectile_y_speed[idx] += kProjDirAccel_Y[proj_dir_idx];
    kProjPreInstr_Beam_Funcs[proj_dir_idx](2 * proj_dir_idx);
    DeleteProjectileIfFarOffScreen();
  }
}

/**
* @brief Handle vertical block collision for vertical non-wave beams
* @param proj_dir_idx The index of the current projectile direction
*/
void ProjPreInstr_BlockCollNoWaveBeamVert(uint16 proj_dir_idx) {  // 0x90AF4A
  BlockCollNoWaveBeamVert(projectile_index);
}

/**
* @brief Handle horizontal and vertical block collision for diagonal non-wave beams
* @param proj_dir_idx The index of the current projectile direction
*/
void ProjPreInstr_BlockCollNoWaveBeamDiagonal(uint16 proj_dir_idx) {  // 0x90AF52
  uint16 proj_idx = projectile_index;
  if (!BlockCollNoWaveBeamHoriz(projectile_index))
    BlockCollNoWaveBeamVert(proj_idx);
}

/**
* @brief Handle horizontal block collision for horizontal non-wave beams
* @param proj_dir_idx The index of the current projectile direction
*/
void ProjPreInstr_BlockCollNoWaveBeamHoriz(uint16 proj_dir_idx) {  // 0x90AF60
  BlockCollNoWaveBeamHoriz(projectile_index);
}

static Func_Y_V *const kProjPreInstr_Missile_Funcs[10] = {  // 0x90AF68
  [kProjectileDir_UpFaceRight]   = ProjPreInstr_BlockCollMissileVert,
  [kProjectileDir_UpRight]       = ProjPreInstr_BlockCollMissileDiagonal,
  [kProjectileDir_Right]         = ProjPreInstr_BlockCollMissileHoriz,
  [kProjectileDir_DownRight]     = ProjPreInstr_BlockCollMissileDiagonal,
  [kProjectileDir_DownFaceRight] = ProjPreInstr_BlockCollMissileVert,
  [kProjectileDir_DownFaceLeft]  = ProjPreInstr_BlockCollMissileVert,
  [kProjectileDir_DownLeft]      = ProjPreInstr_BlockCollMissileDiagonal,
  [kProjectileDir_Left]          = ProjPreInstr_BlockCollMissileHoriz,
  [kProjectileDir_UpLeft]        = ProjPreInstr_BlockCollMissileDiagonal,
  [kProjectileDir_UpFaceLeft]    = ProjPreInstr_BlockCollMissileVert,
};

/**
* @brief Handle speed, trail, and instructions for missiles
* @param proj_idx The index of the current projectile
*/
void ProjPreInstr_Missile(uint16 proj_idx) {
  int idx = proj_idx >> 1;
  if (projectile_dir[idx] & (0xF0 | kProjectileDir_Delete)) {
    ClearProjectile(proj_idx);
  }
  else {
    if (--projectile_trail_timers[idx] == 0) {
      projectile_trail_timers[idx] = 4;
      SpawnProjectileTrail(proj_idx);
      proj_idx = projectile_index;
    }
    idx = proj_idx >> 1;
    int proj_dir_idx = projectile_dir[idx] & kProjectileDir_DirMask;
    projectile_x_speed[idx] += kProjDirAccel_X[proj_dir_idx];
    projectile_y_speed[idx] += kProjDirAccel_Y[proj_dir_idx];
    AccelerateMissileOrSuperMissile(proj_idx);
    kProjPreInstr_Missile_Funcs[proj_dir_idx](2 * proj_dir_idx);
    DeleteProjectileIfFarOffScreen();
  }
}

/**
* @brief Handle vertical block collision for vertical missile
* @param proj_dir_idx The index of the current projectile direction
*/
void ProjPreInstr_BlockCollMissileVert(uint16 proj_dir_idx) {  // 0x90AFC7
  BlockCollMissileVert(projectile_index);
}

/**
* @brief Handle horizontal and vertical block collision for diagonal missile
* @param proj_dir_idx The index of the current projectile direction
*/
void ProjPreInstr_BlockCollMissileDiagonal(uint16 proj_dir_idx) {  // 0x90AFCF
  uint16 proj_idx = projectile_index;
  if (!BlockCollMissileHoriz(projectile_index))
    BlockCollMissileVert(proj_idx);
}

/**
* @brief Handle horizontal block collision for horizontal missile
* @param proj_dir_idx The index of the current projectile direction
*/
void ProjPreInstr_BlockCollMissileHoriz(uint16 proj_dir_idx) {  // 0x90AFDD
  BlockCollMissileHoriz(projectile_index);
}

static Func_Y_V *const kProjPreInstr_SuperMissile_Funcs[10] = {  // 0x90AFE5
  [kProjectileDir_UpFaceRight]   = ProjPreInstr_BlockCollSuperMissileVert,
  [kProjectileDir_UpRight]       = ProjPreInstr_BlockCollSuperMissileDiagonal,
  [kProjectileDir_Right]         = ProjPreInstr_BlockCollSuperMissileHoriz,
  [kProjectileDir_DownRight]     = ProjPreInstr_BlockCollSuperMissileDiagonal,
  [kProjectileDir_DownFaceRight] = ProjPreInstr_BlockCollSuperMissileVert,
  [kProjectileDir_DownFaceLeft]  = ProjPreInstr_BlockCollSuperMissileVert,
  [kProjectileDir_DownLeft]      = ProjPreInstr_BlockCollSuperMissileDiagonal,
  [kProjectileDir_Left]          = ProjPreInstr_BlockCollSuperMissileHoriz,
  [kProjectileDir_UpLeft]        = ProjPreInstr_BlockCollSuperMissileDiagonal,
  [kProjectileDir_UpFaceLeft]    = ProjPreInstr_BlockCollSuperMissileVert,
};

/**
* @brief Handle speed, trail, and instructions for super missiles
* @param proj_idx The index of the current projectile
*/
void ProjPreInstr_SuperMissile(uint16 proj_idx) {
  int idx = proj_idx >> 1;
  if (projectile_dir[idx] & (0xF0 | kProjectileDir_Delete)) {
    ClearProjectile(proj_idx);
  }
  else {
    if (--projectile_trail_timers[idx] == 0) {
      projectile_trail_timers[idx] = 2;
      SpawnProjectileTrail(proj_idx);
      proj_idx = projectile_index;
    }
    idx = proj_idx >> 1;
    int proj_dir_idx = projectile_dir[idx] & kProjectileDir_DirMask;
    AccelerateMissileOrSuperMissile(proj_idx);
    kProjPreInstr_SuperMissile_Funcs[proj_dir_idx](proj_dir_idx);
    if (!DeleteProjectileIfFarOffScreen())
      return;
  }
  // If a super missile is deleted, then all other super missiles are also deleted
  for (proj_idx = 8; (int16)proj_idx >= 0; proj_idx -= 2) {
    if ((projectile_type[proj_idx >> 1] & (kProjectileType_ProjMask|0xFF)) == kProjectileType_SuperMissile)
      ClearProjectile(proj_idx);
  }
}

/**
* @brief Move super missile vertically and handle vertical block collision for vertical super missile
* @param proj_dir_idx The index of the current projectile direction
*/
void ProjPreInstr_BlockCollSuperMissileVert(uint16 proj_dir_idx) {  // 0x90B047
  BlockCollMissileVert(projectile_index);
  SuperMissileBlockCollDetect_Vertical();
}

/**
* @brief Move super missile horizontally and vertically and handle horizontal and vertical block collision
* for diagonal super missile
* @param proj_dir_idx The index of the current projectile direction
*/
void ProjPreInstr_BlockCollSuperMissileDiagonal(uint16 proj_dir_idx) {  // 0x90B052
  uint16 proj_idx = projectile_index;
  if (BlockCollMissileHoriz(projectile_index)) {
    SuperMissileBlockCollDetect_Horizontal();
  }
  else {
    SuperMissileBlockCollDetect_Horizontal();
    BlockCollMissileVert(proj_idx);
    SuperMissileBlockCollDetect_Vertical();
  }
}

/**
* @brief Move super missile horizontally and handle horizontal block collision for horizontal super missile
* @param proj_dir_idx The index of the current projectile direction
*/
void ProjPreInstr_BlockCollSuperMissileHoriz(uint16 proj_dir_idx) {  // 0x90B06A
  BlockCollMissileHoriz(projectile_index);
  SuperMissileBlockCollDetect_Horizontal();
}

/**
* @brief Clear all super missiles if the current super missile is deleted
* @param proj_idx The index of the current projectile
*/
void ProjPreInstr_SuperMissileLink(uint16 proj_idx) {  // 0x90B075
  if (projectile_dir[proj_idx >> 1] & (0xF0 | kProjectileDir_Delete)) {
    ClearProjectile(proj_idx);
    for (proj_idx = 8; (int16)proj_idx >= 0; proj_idx -= 2) {
      if ((projectile_type[proj_idx >> 1] & (kProjectileType_ProjMask|0xFF)) == kProjectileType_SuperMissile)
        ClearProjectile(proj_idx);
    }
  }
}

/**
* @brief Handle bomb and bomb collision
* @param proj_idx The index of the current projectile
*/
void ProjPreInstr_Bomb(uint16 proj_idx) {  // 0x90B099
  if (projectile_dir[proj_idx >> 1] & (0xF0 | kProjectileDir_Delete)) {
    ClearProjectile(proj_idx);
  }
  else {
    HandleBomb();
    BombOrPowerBomb_ExplosionBlockCollHandling(proj_idx);
  }
}

/**
* @brief Handle power bomb and power bomb collision
* @param proj_idx The index of the current projectile
*/
void ProjPreInstr_PowerBomb(uint16 proj_idx) {  // 0x90B0AE
  if (projectile_dir[proj_idx >> 1] & (0xF0 | kProjectileDir_Delete)) {
    ClearProjectile(proj_idx);
  }
  else {
    HandlePowerBomb();
    BombOrPowerBomb_ExplosionBlockCollHandling(proj_idx);
  }
}

/**
* @brief Handle speed, trail, and instructions for wave-type beams
* @param proj_idx The index of the current projectile
*/
void ProjPreInstr_WaveCombined(uint16 proj_idx) {  // 0x90B0C3
  int idx = proj_idx >> 1;
  if (projectile_dir[idx] & (0xF0 | kProjectileDir_Delete)) {
    ClearProjectile(proj_idx);
  }
  else if (--projectile_trail_timers[idx] == 0) {
    projectile_trail_timers[idx] = 4;
    SpawnProjectileTrail(proj_idx);
    ProjPreInstr_Wave_Shared(projectile_index);
  }
  else {
    ProjPreInstr_Wave_Shared(proj_idx);
  }
}

/**
* @brief Handle speed, trail, and instructions for some wave-type beams
* @param proj_idx The index of the current projectile
*/
void ProjPreInstr_BeamOrIceWave(uint16 proj_idx) {  // 0x90B0E4
  int idx = proj_idx >> 1;
  if (projectile_dir[idx] & (0xF0 | kProjectileDir_Delete)) {
    ClearProjectile(proj_idx);
  }
  else if (--projectile_trail_timers[idx] == 0) {
    projectile_trail_timers[idx] = 3;
    SpawnProjectileTrail(proj_idx);
    ProjPreInstr_Wave_Shared(projectile_index);
  }
  else {
    ProjPreInstr_Wave_Shared(proj_idx);
  }
}

static Func_Y_V *const kProjPreInstr_WavePlasmaEtcFuncs[10] = {  // 0x90B103
  [kProjectileDir_UpFaceRight]   = ProjPreInstr_BlockCollWaveBeamVert,
  [kProjectileDir_UpRight]       = ProjPreInstr_BlockCollWaveBeamDiagonal,
  [kProjectileDir_Right]         = ProjPreInstr_BlockCollWaveBeamHoriz,
  [kProjectileDir_DownRight]     = ProjPreInstr_BlockCollWaveBeamDiagonal,
  [kProjectileDir_DownFaceRight] = ProjPreInstr_BlockCollWaveBeamVert,
  [kProjectileDir_DownFaceLeft]  = ProjPreInstr_BlockCollWaveBeamVert,
  [kProjectileDir_DownLeft]      = ProjPreInstr_BlockCollWaveBeamDiagonal,
  [kProjectileDir_Left]          = ProjPreInstr_BlockCollWaveBeamHoriz,
  [kProjectileDir_UpLeft]        = ProjPreInstr_BlockCollWaveBeamDiagonal,
  [kProjectileDir_UpFaceLeft]    = ProjPreInstr_BlockCollWaveBeamVert,
};

/**
* @brief Handle speed and instructions for wave-type beams
* @param proj_idx The index of the current projectile
*/
void ProjPreInstr_Wave_Shared(uint16 proj_idx) {
  int idx = proj_idx >> 1;
  int proj_dir_idx = projectile_dir[idx] & kProjectileDir_DirMask;
  projectile_x_speed[idx] += kProjDirAccel_X[proj_dir_idx];
  projectile_y_speed[idx] += kProjDirAccel_Y[proj_dir_idx];
  kProjPreInstr_WavePlasmaEtcFuncs[proj_dir_idx](2 * proj_dir_idx);
  DeleteProjectileIfFarOffScreen();
}

/**
* @brief Handle vertical block collision for vertical wave-type beams
* @param proj_dir_idx The index of the current projectile direction
*/
void ProjPreInstr_BlockCollWaveBeamVert(uint16 proj_dir_idx) {  // 0x90B13B
  BlockCollWaveBeamVert(projectile_index);
}

/**
* @brief Handle horizontal and vertical block collision for diagonal wave-type beams
* @param proj_dir_idx The index of the current projectile direction
*/
void ProjPreInstr_BlockCollWaveBeamDiagonal(uint16 proj_dir_idx) {  // 0x90B143
  uint16 proj_idx = projectile_index;
  if (!BlockCollWaveBeamHoriz(projectile_index))
    BlockCollWaveBeamVert(proj_idx);
}

/**
* @brief Handle horizontal block collision for horizontal wave-type beams
* @param proj_dir_idx The index of the current projectile direction
*/
void ProjPreInstr_BlockCollWaveBeamHoriz(uint16 proj_dir_idx) {  // 0x90B151
  BlockCollWaveBeamHoriz(projectile_index);
}

/**
* @brief Handle speed and instructions for hyper beam (wave-type)
* @param proj_dir_idx The index of the current projectile direction
*/
void ProjPreInstr_HyperBeam(uint16 proj_dir_idx) {  // 0x90B159
  if (projectile_dir[proj_dir_idx >> 1] & (0xF0 | kProjectileDir_Delete))
    ClearProjectile(proj_dir_idx);
  else
    ProjPreInstr_Wave_Shared(proj_dir_idx);
}

/**
* @brief Delete projectile more than 4 blocks off the screen
* @return uint8 1 if projectile outside screen limits and deleted, 0 otherwise
*/
uint8 DeleteProjectileIfFarOffScreen(void) {  // 0x90B16A
  int16 proj_screen_x_pos = projectile_x_pos[projectile_index >> 1] - layer1_x_pos;
  int16 proj_screen_y_pos = projectile_y_pos[projectile_index >> 1] - layer1_y_pos;

  if (-(4*16) <= proj_screen_x_pos && proj_screen_x_pos < (20*16)) {
    if (-(4*16) <= proj_screen_y_pos && proj_screen_y_pos < (20*16)) {
      return 0;
    }
  }
  ClearProjectile(projectile_index);
  return 1;
}

/**
* @brief Set the initial speed of the beam
* @param proj_idx The index of the current projectile
*/
void SetInitialBeamSpeed(uint16 proj_idx) {  // 0x90B197
  int idx = proj_idx >> 1;
  uint16 proj_type = projectile_type[idx] & kProjectileType_BeamMask;
  uint16 proj_dir = projectile_dir[idx] & kProjectileDir_DirMask;
  uint16 proj_speed;
  switch (proj_dir) {
    case kProjectileDir_UpFaceRight:
    case kProjectileDir_Right:
    case kProjectileDir_DownFaceRight:
    case kProjectileDir_DownFaceLeft:
    case kProjectileDir_Left:
    case kProjectileDir_UpFaceLeft:
      proj_speed = kInitialBeamSpeed[proj_type].horiz_vert_speed;
      break;

    case kProjectileDir_UpRight:
    case kProjectileDir_DownRight:
    case kProjectileDir_DownLeft:
    case kProjectileDir_UpLeft:
      proj_speed = kInitialBeamSpeed[proj_type].diag_speed;
      break;

    default: Unreachable();
  }
  InitializeProjectileSpeed(proj_idx, proj_speed);
}

/**
* @brief Set the initial speed of the missile or super missile
* @param proj_idx The index of the current projectile
*/
void InitializeAnyMissileSpeed(uint16 proj_idx) {  // 0x90B1DD
  InitializeProjectileSpeed(proj_idx, 0);
}

/**
* @brief Set the initial speed of the projectile
* @param proj_idx The index of the current projectile
* @param proj_speed The initial speed of the projectile
*/
void InitializeProjectileSpeed(uint16 proj_idx, uint16 proj_speed) {  // 0x90B1F3
  // The distance variables were stored in the wrong order in the original code,
  // thus instead of loading dir and dir fractional, the code loads dir and some other variable
  uint16 dist_samus_moved_left = PAIR16(LOBYTE(distance_samus_moved_left), HIBYTE(camera_y_subspeed));
  uint16 dist_samus_moved_right = PAIR16(LOBYTE(distance_samus_moved_right), HIBYTE(distance_samus_moved_left_fract));
  int16 dist_samus_moved_up = PAIR16(LOBYTE(distance_samus_moved_up), HIBYTE(distance_samus_moved_right_fract));
  uint16 dist_samus_moved_down = PAIR16(LOBYTE(distance_samus_moved_down), HIBYTE(distance_samus_moved_up_fract));

  int idx = proj_idx >> 1;
  projectile_x_subpos[idx] = 0;
  projectile_y_subpos[idx] = 0;
  uint16 proj_dir = projectile_dir[idx] & kProjectileDir_DirMask;
  switch (proj_dir) {
    // InitializeProjectileSpeed_Up - 0x90B218
    // {
    case kProjectileDir_UpFaceRight:
    case kProjectileDir_UpFaceLeft: {
      if (LOBYTE(distance_samus_moved_up) != 0)
        dist_samus_moved_up >>= 2;
      else
        dist_samus_moved_up = 0;
      projectile_y_speed[idx] = dist_samus_moved_up - proj_speed;
      projectile_x_speed[idx] = 0;
      break;
    }
    // }
    
    // InitializeProjectileSpeed_UpRight - 0x90B23D
    // {
    case kProjectileDir_UpRight: {
      if (LOBYTE(distance_samus_moved_up) != 0)
        dist_samus_moved_up >>= 2;
      else
        dist_samus_moved_up = 0;
      projectile_y_speed[idx] = dist_samus_moved_up - proj_speed;
      projectile_x_speed[idx] = dist_samus_moved_right + proj_speed;
      break;
    }
    // }
    
    // InitializeProjectileSpeed_Right - 0x90B268
    // {
    case kProjectileDir_Right: {
      projectile_y_speed[idx] = 0;
      projectile_x_speed[idx] = dist_samus_moved_right + proj_speed;
      break;
    }
    // }

    // InitializeProjectileSpeed_DownRight - 0x90B277
    // {
    case kProjectileDir_DownRight: {
      projectile_y_speed[idx] = dist_samus_moved_down + proj_speed;
      projectile_x_speed[idx] = dist_samus_moved_right + proj_speed;
      break;
    }
    // }

    // InitializeProjectileSpeed_Down - 0x90B28C
    // {
    case kProjectileDir_DownFaceRight:
    case kProjectileDir_DownFaceLeft: {
      projectile_y_speed[idx] = dist_samus_moved_down + proj_speed;
      projectile_x_speed[idx] = 0;
      break;
    }
    // }

    // InitializeProjectileSpeed_DownLeft - 0x90B29B
    // {
    case kProjectileDir_DownLeft: {
      projectile_y_speed[idx] = dist_samus_moved_down + proj_speed;
      projectile_x_speed[idx] = dist_samus_moved_left - proj_speed;
      break;
    }
    // }

    // InitializeProjectileSpeed_Left - 0x90B2B4
    // {
    case kProjectileDir_Left: {
      projectile_y_speed[idx] = 0;
      projectile_x_speed[idx] = dist_samus_moved_left - proj_speed;
      break;
    }
    // }

    // InitializeProjectileSpeed_UpLeft - 0x90B2C7
    // {
    case kProjectileDir_UpLeft: {
      if (LOBYTE(distance_samus_moved_up) != 0)
        dist_samus_moved_up >>= 2;
      else
        dist_samus_moved_up = 0;
      projectile_y_speed[idx] = dist_samus_moved_up - proj_speed;
      projectile_x_speed[idx] = dist_samus_moved_left - proj_speed;
      break;
    }
    // }

    default: Unreachable(); break;
  }
}

/**
* @brief Accelerate the missile or super missile if it's initialized, otherwise set the initial speed
* @param proj_idx The index of the current projectile
*/
void AccelerateMissileOrSuperMissile(uint16 proj_idx) {  // 0x90B2F6
  static const uint16 kMissileInitalizedBitset = 0x100;

  int idx = proj_idx >> 1;
  if (HIBYTE(projectile_initialized_flag[idx])) {
    MissileAcceleration missile_acceleration;
    if (projectile_type[idx] & kProjectileType_SuperMissile)
      missile_acceleration = kSuperMissileAccelerations[projectile_dir[idx] & kProjectileDir_DirMask];
    else
      missile_acceleration = kMissileAccelerations[projectile_dir[idx] & kProjectileDir_DirMask];
    projectile_x_speed[idx] += missile_acceleration.x_accel;
    projectile_y_speed[idx] += missile_acceleration.y_accel;
  }
  else {
    HIBYTE(projectile_initialized_flag[idx]) += HIBYTE(kMissileInitalizedBitset);
    // Condition always true since we just set 0x100 in projectile_initialized_flag[idx]
    if (HIBYTE(projectile_initialized_flag[idx])) {
      InitializeProjectileSpeed(proj_idx, projectile_initial_speed[idx]);
      if (projectile_type[idx] & kProjectileType_SuperMissile)
        SpawnSuperMissileLink();
    }
  }
}

/**
* @brief Move the linked super missile vertically and check for block collision
*/
void SuperMissileBlockCollDetect_Vertical(void) {  // 0x90B366
  int idx = projectile_index >> 1;
  uint16 proj_type = projectile_type[idx] & kProjectileType_ProjMask;
  if (proj_type == kProjectileType_SuperMissile || proj_type == kProjectileType_MissileExplosion) {
    if (HIBYTE(projectile_initialized_flag[idx])) {
      uint8 proj_link_idx = projectile_link_index[idx];
      uint16 proj_y_abs_speed = GET_HIBYTE(abs16(projectile_y_speed[idx]));
      if (proj_y_abs_speed < 11) {
        if (proj_type != kProjectileType_MissileExplosion) {
          projectile_y_pos[proj_link_idx >> 1] = projectile_y_pos[idx];
          return;
        }
      }
      // if the speed is 11 or above, check 10 pixels in advanced
      else {
        // projectile going downwards
        if ((int16)projectile_y_speed[idx] >= 0) {
          projectile_y_pos[proj_link_idx >> 1] = projectile_y_pos[idx] - proj_y_abs_speed + 10;
        }
        // projectile going upwards
        else /* (int16)projectile_y_speed[idx] < 0 */ {
          projectile_y_pos[proj_link_idx >> 1] = projectile_y_pos[idx] + proj_y_abs_speed - 10;
        }
        uint16 proj_idx_backup = projectile_index;
        projectile_index = proj_link_idx;
        BlockCollMissileVert(proj_link_idx);
        projectile_index = proj_idx_backup;
        if (proj_type != kProjectileType_MissileExplosion)
          return;
      }
      ClearProjectile(proj_link_idx);
    }
  }
}

/**
* @brief Move the linked super missile horizontally and check for block collision
*/
void SuperMissileBlockCollDetect_Horizontal(void) {  // 0x90B406
  int idx = projectile_index >> 1;
  uint16 proj_type = projectile_type[idx] & kProjectileType_ProjMask;
  if (proj_type == kProjectileType_SuperMissile || proj_type == kProjectileType_MissileExplosion) {
    if (HIBYTE(projectile_initialized_flag[idx])) {
      uint8 proj_link_idx = projectile_link_index[idx];
      uint16 proj_y_abs_speed = GET_HIBYTE(abs16(projectile_x_speed[idx]));
      if (proj_y_abs_speed < 11) {
        if (proj_type != kProjectileType_MissileExplosion) {
          projectile_x_pos[proj_link_idx >> 1] = projectile_x_pos[idx];
          return;
        }
      }
      // if the speed is 11 or above, check 10 pixels in advanced
      else {
        // projectile going rightwards
        if ((int16)projectile_x_speed[idx] >= 0) {
          projectile_x_pos[proj_link_idx >> 1] = projectile_x_pos[idx] - proj_y_abs_speed + 10;
        }
        // projectile going leftwards
        else /* (int16)projectile_x_speed[idx] < 0 */ {
          //proj_idx_backup = projectile_index;
          projectile_x_pos[proj_link_idx >> 1] = projectile_x_pos[idx] + proj_y_abs_speed - 10;
        }
        uint16 proj_idx_backup = projectile_index;
        projectile_index = proj_link_idx;
        BlockCollMissileHoriz(proj_link_idx);
        projectile_index = proj_idx_backup;
        if (proj_type != kProjectileType_MissileExplosion)
          return;
      }
      ClearProjectile(proj_link_idx);
    }
  }
}

void UNUSED_ClearSuperMissileLinkIfExplosion(uint16 proj_idx) {  // 0x90B4A6
  int idx = proj_idx >> 1;
  if (HIBYTE(projectile_initialized_flag[idx])) {
    if ((projectile_type[idx] & kProjectileType_ProjMask) == kProjectileType_MissileExplosion)
      ClearProjectile((uint8)projectile_link_index[idx]);
  }
}

/**
* @brief Move the left projectile trail down one pixel
* @param proj_trail_idx The index of the current projectile trail
*/
void ProjTrailInstr_MoveLeftProjectileTrailDown(uint16 proj_trail_idx) {  // 0x90B525
  ++projectiletrail_left_y_pos[proj_trail_idx >> 1];
}

/**
* @brief Move the right projectile trail down one pixel
* @param proj_trail_idx The index of the current projectile trail
*/
void ProjTrailInstr_MoveRightProjectileTrailDown(uint16 proj_trail_idx) {  // 0x90B587
  ++projectiletrail_right_y_pos[proj_trail_idx >> 1];
}

/**
* @brief Move the left projectile trail up one pixel
* @param proj_trail_idx The index of the current projectile trail
*/
void ProjTrailInstr_MoveLeftProjectileTrailUp(uint16 proj_trail_idx) {  // 0x90B5B3
  --projectiletrail_left_y_pos[proj_trail_idx >> 1];
}

/**
* @brief Spawns a projectile trail for the current projectile
* @param proj_idx The index of the current projectile
*/
void SpawnProjectileTrail(uint16 proj_idx) {  // 0x90B657
  uint16 proj_trail_instr_list_idx;

  uint16 proj_type = projectile_type[proj_idx >> 1];
  if (proj_type & kProjectileType_ProjMask) {
    uint16 weapon_idx = proj_type & kProjectileType_ProjMask;
    if (weapon_idx >= ((kProjectileType_SuperMissile | kProjectileType_Missile)))
      return;
    proj_trail_instr_list_idx = HIBYTE(weapon_idx) + 0x1F;  // add 0x1F to align it to 0x20 in the array
  }
  else {
    proj_trail_instr_list_idx = proj_type & kProjectileType_TableIndexMask;
  }

  int16 proj_trail_idx = 34;
  while (projectiletrail_left_instr_timer[proj_trail_idx >> 1] != 0) {
    proj_trail_idx -= 2;
    if (proj_trail_idx < 0)
      return;
  }
  int idx = proj_trail_idx >> 1;

  projectiletrail_left_instr_timer[idx] = 1;
  projectiletrail_right_instr_timer[idx] = 1;
  projectiletrail_left_instr_list_ptr[idx] = kLeftProjTrailInstrListPtrs[proj_trail_instr_list_idx];
  projectiletrail_right_instr_list_ptr[idx] = kRightProjTrailInstrListPtrs[proj_trail_instr_list_idx];
  SetProjectileTrailPosition(projectile_index, proj_trail_idx);
}

void CallProjTrailInstr(uint32 ea, uint16 proj_trail_idx) {
  switch (ea) {
  case fnProjTrailInstr_MoveLeftProjectileTrailDown: ProjTrailInstr_MoveLeftProjectileTrailDown(proj_trail_idx); return;  // 0x90b525
  case fnProjTrailInstr_MoveRightProjectileTrailDown: ProjTrailInstr_MoveRightProjectileTrailDown(proj_trail_idx); return;  // 0x90b587
  case fnProjTrailInstr_MoveLeftProjectileTrailUp: ProjTrailInstr_MoveLeftProjectileTrailUp(proj_trail_idx); return;  // 0x90b5b3
  default: Unreachable();
  }
}

/**
* @brief Handle drawing and processing left and right projectile trails
*/
void HandleProjectileTrails(void) {  // 0x90B6A9
  OamEnt *oam;

  if (!time_is_frozen_flag) {
    for (int16 proj_trail_idx = 34; proj_trail_idx >= 0; proj_trail_idx -= 2) {
      int idx = proj_trail_idx >> 1;
      if (projectiletrail_left_instr_timer[idx] != 0) {

        if (--projectiletrail_left_instr_timer[idx] != 0) {
          if (oam_next_ptr < 0x200) {
            int16 proj_trail_screen_x_pos = projectiletrail_left_x_pos[idx] - layer1_x_pos;
            if (0 <= proj_trail_screen_x_pos && proj_trail_screen_x_pos < (16*16)) {
              oam = gOamEnt(oam_next_ptr);
              oam->xcoord = proj_trail_screen_x_pos;
              int16 proj_trail_screen_y_pos = projectiletrail_left_y_pos[idx] - layer1_y_pos;
              if (0 <= proj_trail_screen_y_pos && proj_trail_screen_y_pos < (16*16)) {
                oam->ycoord = proj_trail_screen_y_pos;
                WORD(oam->charnum) = projectiletrail_left_tile_and_attribs[idx];
                oam_next_ptr += sizeof(OamEnt);
              }
            }
          }
        }

        else {
          uint16 left_trail_instr_list_ptr;
          ProjectileTrailInstr left_trail_instr;
          for (left_trail_instr_list_ptr = projectiletrail_left_instr_list_ptr[idx]; ; left_trail_instr_list_ptr += 2) {
            left_trail_instr = get_ProjTrailInstr(left_trail_instr_list_ptr);
            if (!IS_FUNC(left_trail_instr.func_ptr))
              break;
            CallProjTrailInstr(left_trail_instr.func_ptr | 0x900000, proj_trail_idx);
          }
          projectiletrail_left_instr_timer[idx] = left_trail_instr.timer;
          if (projectiletrail_left_instr_timer[idx] != 0) {
            projectiletrail_left_tile_and_attribs[idx] = left_trail_instr.tile_num_attributes;
            projectiletrail_left_instr_list_ptr[idx] = left_trail_instr_list_ptr + 4;
            if (oam_next_ptr < 0x200) {
              int16 proj_trail_screen_x_pos = projectiletrail_left_x_pos[idx] - layer1_x_pos;
              if (0 <= proj_trail_screen_x_pos && proj_trail_screen_x_pos < (16*16)) {
                oam = gOamEnt(oam_next_ptr);
                oam->xcoord = proj_trail_screen_x_pos;
                int16 proj_trail_screen_y_pos = projectiletrail_left_y_pos[idx] - layer1_y_pos;
                if (0 <= proj_trail_screen_y_pos && proj_trail_screen_y_pos < (16*16)) {
                  oam->ycoord = proj_trail_screen_y_pos;
                  WORD(oam->charnum) = projectiletrail_left_tile_and_attribs[idx];
                  oam_next_ptr += sizeof(OamEnt);
                }
              }
            }
          }
        }

      }
      if (projectiletrail_right_instr_timer[idx] != 0) {

        if (--projectiletrail_right_instr_timer[idx] != 0) {
          if (oam_next_ptr < 0x200) {
            int16 proj_trail_screen_x_pos = projectiletrail_right_x_pos[idx] - layer1_x_pos;
            if (0 <= proj_trail_screen_x_pos && proj_trail_screen_x_pos < (16*16)) {
              oam = gOamEnt(oam_next_ptr);
              oam->xcoord = proj_trail_screen_x_pos;
              int16 proj_trail_screen_y_pos = projectiletrail_right_y_pos[idx] - layer1_y_pos;
              if (0 <= proj_trail_screen_y_pos && proj_trail_screen_y_pos < (16*16)) {
                oam->ycoord = proj_trail_screen_y_pos;
                WORD(oam->charnum) = projectiletrail_right_tile_and_attribs[idx];
                oam_next_ptr += sizeof(OamEnt);
              }
            }
          }
        }

        else {
          uint16 right_trail_instr_list_ptr;
          ProjectileTrailInstr right_trail_instr;
          for (right_trail_instr_list_ptr = projectiletrail_right_instr_list_ptr[idx]; ; right_trail_instr_list_ptr += 2) {
            right_trail_instr = get_ProjTrailInstr(right_trail_instr_list_ptr);
            if (!IS_FUNC(right_trail_instr.func_ptr))
              break;
            CallProjTrailInstr(right_trail_instr.func_ptr | 0x900000, proj_trail_idx);
          }
          projectiletrail_right_instr_timer[idx] = right_trail_instr.timer;
          if (projectiletrail_right_instr_timer[idx] != 0) {
            projectiletrail_right_tile_and_attribs[idx] = right_trail_instr.tile_num_attributes;
            projectiletrail_right_instr_list_ptr[idx] = right_trail_instr_list_ptr + 4;
            if (oam_next_ptr < 0x200) {
              int16 proj_trail_screen_x_pos = projectiletrail_right_x_pos[idx] - layer1_x_pos;
              int16 proj_trail_screen_y_pos = projectiletrail_right_y_pos[idx] - layer1_y_pos;
              if (0 <= proj_trail_screen_x_pos && proj_trail_screen_x_pos < (16*16)) {
                oam = gOamEnt(oam_next_ptr);
                oam->xcoord = proj_trail_screen_x_pos;
                if (0 <= proj_trail_screen_y_pos && proj_trail_screen_y_pos < (16*16)) {
                  oam->ycoord = proj_trail_screen_y_pos;
                  WORD(oam->charnum) = projectiletrail_right_tile_and_attribs[idx];
                  oam_next_ptr += sizeof(OamEnt);
                }
              }
            }
          }
        }

      }
    }
  }

  else {
    for (int16 proj_trail_idx = 34; proj_trail_idx >= 0; proj_trail_idx -= 2) {
      int idx = proj_trail_idx >> 1;
      if (oam_next_ptr < 0x200) {
        if (projectiletrail_left_instr_timer[idx] != 0) {
          int16 proj_trail_screen_x_pos = projectiletrail_left_x_pos[idx] - layer1_x_pos;
          int16 proj_trail_screen_y_pos = projectiletrail_left_y_pos[idx] - layer1_y_pos;
          if (0 <= proj_trail_screen_x_pos && proj_trail_screen_x_pos < (16*16)) {
            oam = gOamEnt(oam_next_ptr);
            oam->xcoord = proj_trail_screen_x_pos;
            if (0 <= proj_trail_screen_y_pos && proj_trail_screen_y_pos < (16*16)) {
              oam->ycoord = proj_trail_screen_y_pos;
              WORD(oam->charnum) = projectiletrail_left_tile_and_attribs[idx];
              oam_next_ptr += sizeof(OamEnt);
            }
          }
        }
      }
    
      if (oam_next_ptr < 0x200) {
        if (projectiletrail_right_instr_timer[idx] != 0) {
          int16 proj_trail_screen_x_pos = projectiletrail_right_x_pos[idx] - layer1_x_pos;
          int16 proj_trail_screen_y_pos = projectiletrail_right_y_pos[idx] - layer1_y_pos;
          if (0 <= proj_trail_screen_x_pos && proj_trail_screen_x_pos < (16*16)) {
            oam = gOamEnt(oam_next_ptr);
            oam->xcoord = proj_trail_screen_x_pos;
            if (0 <= proj_trail_screen_y_pos && proj_trail_screen_y_pos < (16*16)) {
              oam->ycoord = proj_trail_screen_y_pos;
              WORD(oam->charnum) = projectiletrail_left_tile_and_attribs[idx];
              oam_next_ptr += sizeof(OamEnt);
            }
          }
        }
      }
    }
  }
}

/**
* @brief Handle firing when nothing or power bombs is selected on the HUD
*/
void HudSelectionHandler_NothingOrPowerBombs(void) {  // 0x90B80D
  prev_beam_charge_counter = flare_counter;
  if (hyper_beam_flag || !(equipped_beams & kBeam_Charge)) {
    if (joypad1_lastkeys & button_config_shoot)
      FireUnchargedBeam();
  }
  else if (new_projectile_direction_changed_pose != 0) {
    ClearFlareAnimationState();
    if (flare_counter < 60) {
      FireUnchargedBeam();
    }
    else {
      FireChargedBeam();
    }
    flare_counter = 0;
  }
  else if (joypad1_lastkeys & button_config_shoot) {
    if (flare_counter < 120) {
      if (++flare_counter == 1) {
        ClearFlareAnimationState();
        FireUnchargedBeam();
      }
    }
    else if (FireSba()) {
      flare_counter = 0;
      ClearFlareAnimationState();
      Samus_LoadSuitPalette();
    }
  }
  else if (flare_counter != 0) {
    ClearFlareAnimationState();
    if (flare_counter < 60) {
      FireUnchargedBeam();
    }
    else {
      FireChargedBeam();
    }
    flare_counter = 0;
  }
}

/**
* @brief Handle spawning, sfx, speed, cooldown, collision for an uncharged beam
*/
void FireUnchargedBeam(void) {  // 0x90B887
  static const uint16 kProjectileBombPreInstr[12] = {
    [kProjectileType_Power]                                           = FUNC16(ProjPreInstr_Beam_NoWaveBeam),
    [kProjectileType_Wave]                                            = FUNC16(ProjPreInstr_BeamOrIceWave),
    [kProjectileType_Ice]                                             = FUNC16(ProjPreInstr_Beam_NoWaveBeam),
    [kProjectileType_Ice|kProjectileType_Wave]                        = FUNC16(ProjPreInstr_BeamOrIceWave),
    [kProjectileType_Spazer]                                          = FUNC16(ProjPreInstr_Beam_NoWaveBeam),
    [kProjectileType_Spazer|kProjectileType_Wave]                     = FUNC16(ProjPreInstr_WaveCombined),
    [kProjectileType_Spazer|kProjectileType_Ice]                      = FUNC16(ProjPreInstr_Beam_NoWaveBeam),
    [kProjectileType_Spazer|kProjectileType_Ice|kProjectileType_Wave] = FUNC16(ProjPreInstr_WaveCombined),
    [kProjectileType_Plasma]                                          = FUNC16(ProjPreInstr_Beam_NoWaveBeam),
    [kProjectileType_Plasma|kProjectileType_Wave]                     = FUNC16(ProjPreInstr_WaveCombined),
    [kProjectileType_Plasma|kProjectileType_Ice]                      = FUNC16(ProjPreInstr_Beam_NoWaveBeam),
    [kProjectileType_Plasma|kProjectileType_Ice|kProjectileType_Wave] = FUNC16(ProjPreInstr_WaveCombined),
  };

  if (hyper_beam_flag) {
    FireHyperBeam();
    return;
  }
  if (Samus_CanFireBeam()) {
    uint16 proj_idx = 0;
    while (projectile_damage[proj_idx >> 1] != 0) {
      proj_idx += 2;
      if (proj_idx >= 10) {
        proj_idx -= 2;
        break;
      }
    }

    if (!InitProjectilePositionDirection(proj_idx)) {
      projectile_invincibility_timer = 10;
      int idx = proj_idx >> 1;
      projectile_trail_timers[idx] = 4;
      projectile_type[idx] = equipped_beams | 0x8000;
      QueueSfx1_Max15(kUnchargedProjectile_Sfx[equipped_beams & kProjectileType_BeamMask]);
      play_resume_charging_beam_sfx = 0;
      InitializeProjectile(proj_idx);
      uint16 proj_type = projectile_type[idx];
      if ((equipped_beams & kBeam_Charge)
          || (joypad1_newkeys & button_config_shoot) || (joypad1_newinput_samusfilter & button_config_shoot)) {
        cooldown_timer = kProjectileCooldown_Uncharged[proj_type & kProjectileType_TableIndexMask];
      }
      else {
        cooldown_timer = kBeamAutoFireCooldowns[proj_type & kProjectileType_TableIndexMask];
      }

      if (proj_type & kProjectileType_Wave) {
        projectile_x_speed[idx] = 0;
        projectile_y_speed[idx] = 0;
        projectile_index = proj_idx;
        WaveBeam_CheckColl(proj_idx);
      }
      else {
        projectile_x_speed[idx] = 0;
        projectile_y_speed[idx] = 0;
        projectile_index = proj_idx;
        CheckBeamCollByDir(proj_idx);
        proj_idx = projectile_index;
        if (projectile_type[projectile_index >> 1] & kProjectileType_ProjMask)
          return;
      }
      projectile_pre_instructions[idx] = kProjectileBombPreInstr[projectile_type[idx] & kProjectileType_BeamMask];
      SetInitialBeamSpeed(proj_idx);
      return;
    }
  }

  if (prev_beam_charge_counter >= 16) {
    play_resume_charging_beam_sfx = 0;
    QueueSfx1_Max15(kSfx1_Silence);
  }
}

static const uint16 kFireChargedBeam_Funcs[12] = {
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

/**
* @brief Handle spawning, sfx, speed, cooldown, collision for a charged beam
*/
void FireChargedBeam(void) {  // 0x90B986
  if (Samus_CanFireBeam()) {
    uint16 proj_idx = 0;
    while (projectile_damage[proj_idx >> 1]) {
      proj_idx += 2;
      if (proj_idx >= 10) {
        proj_idx -= 2;
        break;
      }
    }

    if (!InitProjectilePositionDirection(proj_idx)) {
      projectile_invincibility_timer = 10;
      int idx = proj_idx >> 1;
      projectile_trail_timers[idx] = 4;
      projectile_type[idx] = equipped_beams & (kProjectileType_ChargeBeamEquipped | kProjectileType_BeamMask) | 0x8010;
      QueueSfx1_Max15(kChargedProjectile_Sfx[projectile_type[idx] & kProjectileType_BeamMask]);
      play_resume_charging_beam_sfx = 0;
      InitializeProjectile(proj_idx);
      cooldown_timer = kProjectileCooldown_Uncharged[projectile_type[idx] & kProjectileType_TableIndexMask];

      if (projectile_type[idx] & kProjectileType_Wave) {
        projectile_x_speed[idx] = 0;
        projectile_y_speed[idx] = 0;
        projectile_index = proj_idx;
        WaveBeam_CheckColl(proj_idx);
      }
      else {
        projectile_x_speed[idx] = 0;
        projectile_y_speed[idx] = 0;
        projectile_index = proj_idx;
        CheckBeamCollByDir(proj_idx);
        if (projectile_type[idx] & kProjectileType_ProjMask) {
          charged_shot_glow_timer = 4;
          return;
        }
      }
      projectile_pre_instructions[idx] = kFireChargedBeam_Funcs[projectile_type[idx] & kProjectileType_BeamMask];
      SetInitialBeamSpeed(proj_idx);
      charged_shot_glow_timer = 4;
      return;
    }
  }

  if (prev_beam_charge_counter >= 16) {
    play_resume_charging_beam_sfx = 0;
    QueueSfx1_Max15(kSfx1_Silence);
  }
}

/**
* @brief Initialize the projectile position and direction
* @param proj_idx The index of the current projectile
* @return uint8 0 if able to shoot, 1 otherwise
*/
uint8 InitProjectilePositionDirection(uint16 proj_idx) {  // 0x90BA56
  uint8 direction_shots_fired;

  if (new_projectile_direction_changed_pose != 0) {
    direction_shots_fired = new_projectile_direction_changed_pose;
    new_projectile_direction_changed_pose = 0;
  }
  else {
    direction_shots_fired = kPoseParams[samus_pose].direction_shots_fired;
    // This condition is true if shooting while being grabbed by Draygon
    if (direction_shots_fired & 0xF0) {
      // This condition is always true
      if (direction_shots_fired != 0x10
          // This condition is unused
          || (direction_shots_fired = kPoseParams[samus_last_different_pose].direction_shots_fired,
              direction_shots_fired & 0xF0)) {
        --projectile_counter;
        return 1;
      }
    }
  }

  int idx = proj_idx >> 1;
  projectile_dir[idx] = direction_shots_fired;
  uint16 proj_origin_y_offset = kPoseParams[samus_pose].y_offset_proj_origin_to_gfx;
  uint16 dir_idx = projectile_dir[idx] & kProjectileDir_DirMask;
  if (samus_pose == kPose_75_FaceL_Moonwalk_AimUL || samus_pose == kPose_76_FaceR_Moonwalk_AimUR
      || samus_movement_type == kMovementType_01_Running) {
    projectile_x_pos[idx] = samus_x_pos + kProjectileOriginOffsets_Moonwalk_AimUp_Running_X.dir[dir_idx];
    projectile_y_pos[idx] = samus_y_pos + kProjectileOriginOffsets_Moonwalk_AimUp_Running_Y.dir[dir_idx] - proj_origin_y_offset;
  }
  else {
    projectile_x_pos[idx] = samus_x_pos + kProjectileOriginOffsets_Default_X.dir[dir_idx];
    projectile_y_pos[idx] = samus_y_pos + kProjectileOriginOffsets_Default_Y.dir[dir_idx] - proj_origin_y_offset;
  }
  return 0;
}

/**
* @brief Handle the animation and audio for charging a beam
*/
void HandleChargingBeamGfxAudio(void) {  // 0x90BAFC
  // flare animation timer and frame variables cast as pointers to access the main, slow sparks, and fast sparks variables
  uint16 *flare_anim_frame = &flare_animation_frame;
  int16 *flare_anim_timer = &flare_animation_timer;

  if (hyper_beam_flag) {
    if (flare_counter != 0) {
      for (int flare_anim_component_idx = 4; flare_anim_component_idx >= 0; flare_anim_component_idx -= 2) {
        int idx = flare_anim_component_idx >> 1;
        if (--flare_anim_timer[idx] <= 0) {
          if (--flare_anim_frame[idx] == 0) {
            if (flare_anim_component_idx == 4)
              flare_counter = 0;
          }
          else {
            flare_anim_timer[idx] = 3;
          }
        }
        DrawFlareAnimationComponent(flare_anim_component_idx);
      }
    }
  }

  else if ((int16)flare_counter > 0) {
    if (flare_counter == 1) {
      flare_animation_frame = 0;
      flare_slow_sparks_anim_frame = 0;
      flare_fast_sparks_anim_frame = 0;
      flare_animation_timer = 3;
      flare_slow_sparks_anim_timer = 5;
      flare_fast_sparks_anim_timer = 4;
    }
    if (flare_counter >= 15) {
      if (flare_counter == 16)
        QueueSfx1_Max9(kSfx1_ChargingBeam);

      for (int charge_anim_component_idx = 0; charge_anim_component_idx < 6; charge_anim_component_idx += 2) {
        int idx = charge_anim_component_idx >> 1;
        if (--flare_anim_timer[idx] < 0) {
          uint16 charge_anim_component_frame = ++flare_anim_frame[idx];
          const uint8 *flare_anim_delay_ptr = kFlareAnimDelays[idx];
          uint8 flare_anim_delay = flare_anim_delay_ptr[charge_anim_component_frame];

          // Restart animation
          if (flare_anim_delay == 0xFF) {
            flare_anim_frame[idx] = 0;
            charge_anim_component_frame = 0;
          }
          // Go back an amount of frames
          else if (flare_anim_delay == 0xFE) {
            flare_anim_frame[idx] -= flare_anim_delay_ptr[charge_anim_component_frame + 1];
            charge_anim_component_frame = flare_anim_frame[idx];
          }

          flare_anim_timer[idx] = flare_anim_delay_ptr[charge_anim_component_frame];
        }
        DrawFlareAnimationComponent(charge_anim_component_idx);
        if (flare_counter < 30)
          break;
      }

    }
  }
}

/**
* @brief Draw the current component of the flare animation (i.e. main, fast/slow sparks)
* @param flare_anim_component_idx The index into the flare animation components
*/
void DrawFlareAnimationComponent(uint16 flare_anim_component_idx) {  // 0x90BBE1
  static const uint16 kFlareSpritemapIndexOffset_FaceRight_Tab0[3] = { 0, 0x1e, 0x24 };
  static const uint16 kFlareSpritemapIndexOffset_FaceLeft_Tab0[3] = { 0, 0x2a, 0x30 };

  uint16 flare_spritemap_idx_offset;

  uint16 flare_anim_component_frame = *((uint8 *)&flare_animation_frame + flare_anim_component_idx);
  if (samus_pose_x_dir == kSamusXDir_FaceLeft)
    flare_spritemap_idx_offset = kFlareSpritemapIndexOffset_FaceLeft_Tab0[flare_anim_component_idx >> 1];
  else
    flare_spritemap_idx_offset = kFlareSpritemapIndexOffset_FaceRight_Tab0[flare_anim_component_idx >> 1];
  uint16 flare_spritemap_idx = flare_anim_component_frame + flare_spritemap_idx_offset;
  uint16 proj_origin_y_offset = kPoseParams[samus_pose].y_offset_proj_origin_to_gfx;
  uint16 dir_shots_fired = kPoseParams[samus_pose].direction_shots_fired;
  // dir_shots_fired is never 0x10
  if (dir_shots_fired != 0xFF && dir_shots_fired != 0x10) {
    uint16 dir_shots_fired_idx = dir_shots_fired & kProjectileDir_DirMask;
    uint16 old_x = samus_x_pos, old_y = samus_y_pos;
    if (ceres_status & kCeresStatus_8000_ElevatorRoomRotate)
      Samus_CalcPos_Mode7();
    int16 flare_screen_x_pos, flare_screen_y_pos;
    if (samus_movement_type == kMovementType_01_Running) {
      flare_screen_x_pos = samus_x_pos + kFlareOriginOffsets_Running_X.dir[dir_shots_fired_idx] - layer1_x_pos;
      flare_screen_y_pos = samus_y_pos + kFlareOriginOffsets_Running_Y.dir[dir_shots_fired_idx] - proj_origin_y_offset - layer1_y_pos;
    }
    else {
      flare_screen_x_pos = samus_x_pos + kFlareOriginOffsets_Default_X.dir[dir_shots_fired_idx] - layer1_x_pos;
      flare_screen_y_pos = samus_y_pos + kFlareOriginOffsets_Default_Y.dir[dir_shots_fired_idx] - proj_origin_y_offset - layer1_y_pos;
    }
    flare_anim_component_frame = flare_screen_y_pos;
    if (0 <= flare_screen_y_pos && flare_screen_y_pos < (16*16))
      DrawBeamGrappleSpritemap(flare_spritemap_idx, flare_screen_x_pos, flare_anim_component_frame);
    if (ceres_status & kCeresStatus_8000_ElevatorRoomRotate)
      samus_y_pos = old_y, samus_x_pos = old_x;
  }
}

/**
* @brief Clear the flare animation variables
*/
void ClearFlareAnimationState(void) {  // 0x90BCBE
  flare_animation_frame = 0;
  flare_slow_sparks_anim_frame = 0;
  flare_fast_sparks_anim_frame = 0;
  flare_animation_timer = 0;
  flare_slow_sparks_anim_timer = 0;
  flare_fast_sparks_anim_timer = 0;
}

/**
* @brief Initializes hyper beam
*/
void FireHyperBeam(void) {  // 0x90BCD1
  if (Samus_CanFireBeam()) {
    uint16 proj_idx = 0;
    while (projectile_damage[proj_idx >> 1] != 0) {
      proj_idx += 2;
      if (proj_idx >= 10) {
        proj_idx -= 2;
        break;
      }
    }

    if (!InitProjectilePositionDirection(proj_idx)) {
      int idx = proj_idx >> 1;
      projectile_invincibility_timer = 10;
      projectile_type[idx] = (kProjectileType_DontInteractWithSamus | kProjectileType_ChargeBeamEquipped | kProjectileType_Charged | kProjectileType_Plasma);
      QueueSfx1_Max15(kChargedProjectile_Sfx[kProjectileType_Plasma]);
      play_resume_charging_beam_sfx = 0;
      InitializeProjectile(proj_idx);
      projectile_x_speed[idx] = 0;
      projectile_y_speed[idx] = 0;
      projectile_index = proj_idx;
      WaveBeam_CheckColl(proj_idx);
      projectile_damage[idx] = 1000;
      projectile_pre_instructions[idx] = FUNC16(ProjPreInstr_HyperBeam);
      SetInitialBeamSpeed(proj_idx);
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
  [kProjectileDir_UpFaceRight]   = CheckBeamCollByDir_Vertical,
  [kProjectileDir_UpRight]       = CheckBeamCollByDir_Diagonal,
  [kProjectileDir_Right]         = CheckBeamCollByDir_Right,
  [kProjectileDir_DownRight]     = CheckBeamCollByDir_Diagonal,
  [kProjectileDir_DownFaceRight] = CheckBeamCollByDir_Vertical,
  [kProjectileDir_DownFaceLeft]  = CheckBeamCollByDir_Vertical,
  [kProjectileDir_DownLeft]      = CheckBeamCollByDir_Diagonal,
  [kProjectileDir_Left]          = CheckBeamCollByDir_Left,
  [kProjectileDir_UpLeft]        = CheckBeamCollByDir_Diagonal,
  [kProjectileDir_UpFaceLeft]    = CheckBeamCollByDir_Vertical,
};

/**
* @brief Move non-wave beam and check for collision based on direction
* @param proj_idx The index of the current projectile
*/
void CheckBeamCollByDir(uint16 proj_idx) {
  kCheckBeamCollByDir[projectile_dir[proj_idx >> 1] & kProjectileDir_DirMask]();
}

/**
* @brief Move non-wave beam vertically and check for vertical collision
*/
void CheckBeamCollByDir_Vertical(void) {  // 0x90BD86
  BlockCollNoWaveBeamVert(projectile_index);
}

/**
* @brief Move non-wave beam horizontally and vertically and check for both collisions
*/
void CheckBeamCollByDir_Diagonal(void) {  // 0x90BD8E
  if (!BlockCollNoWaveBeamHoriz(projectile_index))
    BlockCollNoWaveBeamVert(projectile_index);
}

/**
* @brief Move non-wave beam rightwards and check for horizontal collision
*/
void CheckBeamCollByDir_Right(void) {  // 0x90BD9C
  BlockCollNoWaveBeamHoriz(projectile_index);
}

/**
* @brief Move non-wave beam leftwards and check for horizontal collision
*/
void CheckBeamCollByDir_Left(void) {  // 0x90BDA4
  projectile_x_speed[projectile_index >> 1] = -1;
  BlockCollNoWaveBeamHoriz(projectile_index);
}

static Func_V *const kWaveBeam_CheckColl_Funcs[10] = {  // 0x90BDB2
  [kProjectileDir_UpFaceRight]   = WaveBeam_CheckColl_Vertical,
  [kProjectileDir_UpRight]       = WaveBeam_CheckColl_Diagonal,
  [kProjectileDir_Right]         = WaveBeam_CheckColl_Right,
  [kProjectileDir_DownRight]     = WaveBeam_CheckColl_Diagonal,
  [kProjectileDir_DownFaceRight] = WaveBeam_CheckColl_Vertical,
  [kProjectileDir_DownFaceLeft]  = WaveBeam_CheckColl_Vertical,
  [kProjectileDir_DownLeft]      = WaveBeam_CheckColl_Diagonal,
  [kProjectileDir_Left]          = WaveBeam_CheckColl_Left,
  [kProjectileDir_UpLeft]        = WaveBeam_CheckColl_Diagonal,
  [kProjectileDir_UpFaceLeft]    = WaveBeam_CheckColl_Vertical,
};

/**
* @brief Move wave-type beam and check for collision based off direction
*/
void WaveBeam_CheckColl(uint16 proj_idx) {
  kWaveBeam_CheckColl_Funcs[projectile_dir[proj_idx >> 1] & kProjectileDir_DirMask]();
}

/**
* @brief Move wave-type beam vertically and check for vertical collision
*/
void WaveBeam_CheckColl_Vertical(void) {  // 0x90BDD4
  BlockCollWaveBeamVert(projectile_index);
}

/**
* @brief Move wave-type beam horizontally and vertically and check for both collisions
*/
void WaveBeam_CheckColl_Diagonal(void) {  // 0x90BDDC
  if (!BlockCollWaveBeamHoriz(projectile_index))
    BlockCollWaveBeamVert(projectile_index);
}

/**
* @brief Move wave-type beam rightwards and check for horizontal collision
*/
void WaveBeam_CheckColl_Right(void) {  // 0x90BDEA
  BlockCollWaveBeamHoriz(projectile_index);
}

/**
* @brief Move non-wave beam leftwards and check for horizontal collision
*/
void WaveBeam_CheckColl_Left(void) {  // 0x90BDF2
  projectile_x_speed[projectile_index >> 1] = -1;
  BlockCollWaveBeamHoriz(projectile_index);
}

/**
* @brief Initialize reflected projectile
* @param proj_idx The index of the current projectile
*/
void ProjectileReflection(uint16 proj_idx) {  // 0x90BE00
  int idx = proj_idx >> 1;
  uint16 proj_type = projectile_type[idx];
  if (proj_type & kProjectileType_Missile) {
    InitializeProjectile(proj_idx);
    projectile_pre_instructions[idx] = FUNC16(ProjPreInstr_Missile);
    projectile_initial_speed[idx] = 240;
  }
  else if (proj_type & kProjectileType_SuperMissile) {
    ClearProjectile(LOBYTE(projectile_variables[idx]));
    InitializeProjectile(proj_idx);
    projectile_pre_instructions[idx] = FUNC16(ProjPreInstr_SuperMissile);
    projectile_initial_speed[idx] = 240;
  }
  else {
    SetInitialBeamSpeed(proj_idx);
    InitializeProjectile(proj_idx);
    projectile_pre_instructions[idx] = kFireChargedBeam_Funcs[proj_type & kProjectileType_BeamMask];
  }
}

/**
* @brief Handle shooting missile or super missile
*/
void HudSelectionHandler_MissilesOrSuperMissiles(void) {  // 0x90BE62
  if (!(joypad1_newkeys & button_config_shoot) && !(joypad1_newinput_samusfilter & button_config_shoot)
      || !Samus_CanFireAnyMissile()) {
    return;
  }

  if (hud_item_index != kHudItem_2_SuperMissile) {
    if (samus_missiles == 0) {
      --projectile_counter;
      return;
    }
  }
  else if (samus_super_missiles == 0) {
    --projectile_counter;
    return;
  }

  uint16 proj_idx = 0;
  while (projectile_damage[proj_idx >> 1] != 0) {
    proj_idx += 2;
    if (proj_idx >= 10) {
      --projectile_counter;
      return;
    }
  }

  if (!InitProjectilePositionDirection(proj_idx)) {
    projectile_invincibility_timer = 20;
    if (hud_item_index == kHudItem_2_SuperMissile)
      --samus_super_missiles;
    else
      --samus_missiles;

    int idx = proj_idx >> 1;
    projectile_trail_timers[idx] = 4;
    uint16 proj_weapon = swap16(hud_item_index);
    projectile_type[idx] |= proj_weapon | kProjectileType_DontInteractWithSamus;
    if (cinematic_function == 0)
      QueueSfx1_Max6(kNonBeamProjectile_Sfx[hud_item_index & 0xF]);
    InitializeAnyMissileSpeed(proj_idx);
    InitializeProjectile(proj_idx);
    if (projectile_type[idx] & kProjectileType_SuperMissile)
      projectile_pre_instructions[idx] = FUNC16(ProjPreInstr_SuperMissile);
    else
      projectile_pre_instructions[idx] = FUNC16(ProjPreInstr_Missile);
    cooldown_timer = kNonBeamProjectileCooldowns[GET_HIBYTE(projectile_type[idx] & kProjectileType_ProjMask)];

    if (samus_auto_cancel_hud_item_index) {
      hud_item_index = kHudItem_0_Nothing;
      samus_auto_cancel_hud_item_index = 0;
      return;
    }
    if (hud_item_index == kHudItem_2_SuperMissile) {
      if (samus_super_missiles != 0)
        return;
    }
    else if (samus_missiles != 0) {
      return;
    }
    hud_item_index = kHudItem_0_Nothing;
  }
}

/**
* @brief Initialize and spawn new super missile link
*/
void SpawnSuperMissileLink(void) {  // 0x90BF46
  uint16 proj_idx = 0;
  while (projectile_damage[proj_idx >> 1] != 0) {
    proj_idx += 2;
    if (proj_idx >= 10)
      return;
  }

  int new_idx = proj_idx >> 1;
  projectile_type[new_idx] |= (kProjectileType_DontInteractWithSamus | kProjectileType_SuperMissile);
  int old_idx = projectile_index >> 1;
  projectile_x_pos[new_idx] = projectile_x_pos[old_idx];
  projectile_y_pos[new_idx] = projectile_y_pos[old_idx];
  projectile_dir[new_idx] = projectile_dir[old_idx];
  InitProjectilePositionDirection(proj_idx);
  InitializeInstrForSuperMissile(proj_idx);
  projectile_pre_instructions[new_idx] = FUNC16(ProjPreInstr_SuperMissileLink);
  projectile_link_index[old_idx] = proj_idx + (projectile_link_index[old_idx] & 0xFF00);
  ++projectile_counter;
}

/**
* @brief Handle laying bombs and power bombs while morphed
*/
void HudSelectionHandler_MorphBall(void) {  // 0x90BF9D
  if (joypad1_lastkeys & button_config_shoot) {

    if (hud_item_index == kHudItem_3_PowerBomb) {
      if (!power_bomb_flag) {
        if (HudSelectionHandler_MorphBall_Helper_FireBombOrPowerBomb()) {
          if (samus_power_bombs != 0) {
            if ((int16)--samus_power_bombs >= 0) {
              power_bomb_flag = -1;

              uint16 proj_idx = BOMB_PROJ_OFFSET;
              while (projectile_type[proj_idx >> 1]) {
                proj_idx += 2;
                if (proj_idx >= BOMB_PROJ_OFFSET + 10) {
                  proj_idx -= 2;
                  break;
                }
              }

              uint16 proj_weapon = swap16(hud_item_index);
              int idx = proj_idx >> 1;
              int bomb_idx = (proj_idx - BOMB_PROJ_OFFSET) >> 1;
              projectile_type[idx] |= proj_weapon;
              projectile_dir[idx] = 0;
              projectile_x_pos[idx] = samus_x_pos;
              projectile_y_pos[idx] = samus_y_pos;
              bomb_timers[bomb_idx] = 60;
              InitializeInstrForBombOrPowerBomb(proj_idx);
              projectile_pre_instructions[idx] = FUNC16(ProjPreInstr_PowerBomb);
              cooldown_timer = kNonBeamProjectileCooldowns[GET_HIBYTE(projectile_type[idx] & kProjectileType_ProjMask)];
              if (samus_auto_cancel_hud_item_index) {
                hud_item_index = kHudItem_0_Nothing;
                samus_auto_cancel_hud_item_index = 0;
              }
              else if (hud_item_index == kHudItem_3_PowerBomb && samus_power_bombs == 0) {
                hud_item_index = kHudItem_0_Nothing;
              }
            }
          }
        }
      }
    }

    else if (HudSelectionHandler_MorphBall_Helper_FireBombOrSpread()) {
      uint16 proj_idx = BOMB_PROJ_OFFSET;
      while (projectile_type[proj_idx >> 1] != 0) {
        proj_idx += 2;
        if (proj_idx >= (BOMB_PROJ_OFFSET + 10)) {
          proj_idx -= 2;
          break;
        }
      }
      int idx = proj_idx >> 1;
      projectile_type[idx] = kProjectileType_Bomb;
      projectile_dir[idx] = 0;
      projectile_x_pos[idx] = samus_x_pos;
      projectile_y_pos[idx] = samus_y_pos;
      projectile_variables[idx] = 60;
      InitializeInstrForBombOrPowerBomb(proj_idx);
      projectile_pre_instructions[idx] = FUNC16(ProjPreInstr_Bomb);
      cooldown_timer = kNonBeamProjectileCooldowns[kProjectileType_Bomb>>8];
    }
  }

  else if (flare_counter != 0) {
    QueueSfx1_Max9(kSfx1_Silence);
    flare_counter = 0;
    ClearFlareAnimationState();
    Samus_LoadSuitPalette();
  }
}

/**
* @brief Fire bomb, power bomb, or bomb spread or charge up bomb spread
* @return uint8 1 if bomb or bomb spread was fired, 0 else
*/
uint8 HudSelectionHandler_MorphBall_Helper_FireBombOrSpread(void) {  // 0x90C0AB
  if (equipped_items & kItem_Bombs) {
    if ((int16)flare_counter < 60 || bomb_counter != 0)
      return HudSelectionHandler_MorphBall_Helper_FireBombOrPowerBomb();
    // Bomb spread continues building up charge until down is let go or after 192 frames (3.2 seconds)
    if ((joypad1_lastkeys & kButton_Down) && (bomb_spread_charge_timeout_counter & 0xC0) < 0xC0) {
      ++bomb_spread_charge_timeout_counter;
    }
    else {
      BombSpread();
      Samus_LoadSuitPalette();
      QueueSfx1_Max9(kSfx1_Silence);
    }
  }
  return 0;
}

/**
* @brief Fire bomb or power bomb
* @return uint8 1 if bomb or bomb spread was fired, 0 else
*/
uint8 HudSelectionHandler_MorphBall_Helper_FireBombOrPowerBomb(void) {  // 0x90C0E7
  if (!(joypad1_newkeys & button_config_shoot)
      || bomb_counter != 0 && (bomb_counter >= 5 || (uint8)cooldown_timer) != 0) {
    if (flare_counter != 0) {
      QueueSfx1_Max9(kSfx1_Silence);
      flare_counter = 0;
      ClearFlareAnimationState();
      Samus_LoadSuitPalette();
    }
    return 0;
  }
  else {
    ++cooldown_timer;
    ++bomb_counter;
    return 1;
  }
}

/**
* @brief Handle bomb timer and explosion
*/
void HandleBomb(void) {  // 0x90C128
  int idx = projectile_index >> 1;
  int bomb_idx = (projectile_index - BOMB_PROJ_OFFSET) >> 1;
  if (bomb_timers[bomb_idx] != 0) {
    if (--bomb_timers[bomb_idx] != 0) {
      if (bomb_timers[bomb_idx] == 15)
        projectile_instruction_ptr[idx] += 28;  // Play fast animation
    }
    else {
      QueueSfx2_Max6(kSfx2_BombExplosion);
      InitializeBombExplosion(projectile_index);
    }
  }
}

/**
* @brief Handle power bomb timer, HDMA, and explosion
*/
void HandlePowerBomb(void) {  // 0x90C157
  int idx = projectile_index >> 1;
  int bomb_idx = (projectile_index - BOMB_PROJ_OFFSET) >> 1;
  if (bomb_timers[bomb_idx] != 0) {
    if (--bomb_timers[bomb_idx] != 0) {
      if (bomb_timers[bomb_idx] == 15)
        projectile_instruction_ptr[idx] += 28;  // Play fast animation
    }
    else {
      power_bomb_explosion_x_pos = projectile_x_pos[idx];
      power_bomb_explosion_y_pos = projectile_y_pos[idx];
      EnableHdmaObjects();
      SpawnPowerBombExplosion();
      bomb_timers[bomb_idx] = -1;
    }
  }
  else if (!power_bomb_flag) {
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

/**
* @brief Handle switching or cancelling HUD selection
*/
void HandleSwitchingHudSelection(void) {
  uint16 old_hud_item_index = hud_item_index;
  if (joypad1_newkeys & button_config_itemcancel) {
    samus_auto_cancel_hud_item_index = kHudItem_0_Nothing;
    hud_item_index = kHudItem_0_Nothing;
  }
  else if (joypad1_newkeys & button_config_itemswitch) {
    if (++hud_item_index > kHudItem_5_Xray)
      hud_item_index = kHudItem_0_Nothing;
  }
  else {
    arm_cannon_toggle_flag = IntMin(kArmCannonToggle_2_No, arm_cannon_toggle_flag + 1);
    return;
  }
  
  // Set the HUD item index to the next available index
  while (kRunSwitchedToHudHandler[hud_item_index]() != 0) {
    if (++hud_item_index > kHudItem_5_Xray) {
      hud_item_index = kHudItem_0_Nothing;
    }
  }

  if (joypad1_lastkeys & button_config_itemcancel)
    samus_auto_cancel_hud_item_index = hud_item_index;
  else
    samus_auto_cancel_hud_item_index = kHudItem_0_Nothing;

  if (hud_item_index == old_hud_item_index) {
    arm_cannon_toggle_flag = IntMin(kArmCannonToggle_2_No, arm_cannon_toggle_flag + 1);
  }
  else {
    arm_cannon_toggle_flag = kArmCannonToggle_1_Yes;
  }
}

/**
* @brief Reset flare variables and load Samus palette
* @return uint8 0
*/
uint8 SwitchToHudHandler_Nothing(void) {  // 0x90C545
  flare_counter = 0;
  ClearFlareAnimationState();
  Samus_LoadSuitPalette();
  return 0;
}

/**
* @brief Reset flare variables and load Samus palette
* @return uint8 1 if Samus has no missiles left, 0 else
*/
uint8 SwitchToHudHandler_Missiles(void) {  // 0x90C551
  if (samus_missiles == 0)
    return 1;
  flare_counter = 0;
  ClearFlareAnimationState();
  Samus_LoadSuitPalette();
  return 0;
}

/**
* @brief Reset flare variables and load Samus palette
* @return uint8 1 if Samus has no super missiles left, 0 else
*/
uint8 SwitchToHudHandler_SuperMissiles(void) {  // 0x90C564
  if (samus_super_missiles == 0)
    return 1;
  flare_counter = 0;
  ClearFlareAnimationState();
  Samus_LoadSuitPalette();
  return 0;
}

/**
* @brief Reset flare variables and load Samus palette
* @return uint8 1 if Samus has no power bombs left, 0 else
*/
uint8 SwitchToHudHandler_PowerBombs(void) {  // 0x90C577
  if (samus_power_bombs == 0)
    return 1;
  flare_counter = 0;
  ClearFlareAnimationState();
  Samus_LoadSuitPalette();
  return 0;
}

/**
* @brief Reset flare variables and load Samus palette
* @return uint8 1 if Samus does not have grapple, 0 else
*/
uint8 SwitchToHudHandler_Grapple(void) {  // 0x90C58A
  if (!(equipped_items & kItem_Grapple))
    return 1;
  if (grapple_beam_function == FUNC16(GrappleBeamFunc_Inactive)) {
    Samus_LoadSuitPalette();
    flare_counter = 0;
    ClearFlareAnimationState();
    grapple_beam_function = FUNC16(GrappleBeamFunc_Inactive);  // Redundant
  }
  return 0;
}

/**
* @brief Reset flare variables and load Samus palette
* @return uint8 1 if Samus does not have xray, 0 else
*/
uint8 SwitchToHudHandler_Xray(void) {  // 0x90C5AE
  if (!(equipped_items & kItem_Xray))
    return 1;
  flare_counter = 0;
  ClearFlareAnimationState();
  Samus_LoadSuitPalette();
  return 0;
}

/**
* @brief Handle arm cannon flags, frame, and drawing mode
*/
void HandleArmCannonOpenState(void) {  // 0x90C5C4
  if (flag_arm_cannon_opening_or_closing || UpdateArmCannonIsOpenFlag())
    AdvanceArmCannonFrame();
  arm_cannon_drawing_mode = get_ArmCannonDrawingData(samus_pose)[0].draw_mode;
}

/**
* @brief Set the arm cannon open flags
* @return uint8 1 if arm cannon is toggled, 0 else
*/
uint8 UpdateArmCannonIsOpenFlag(void) {  // 0x90C5EB
  static const int8 kFlagShouldArmCannonBeOpen[6] = {
    [kHudItem_0_Nothing]      = false,
    [kHudItem_1_Missile]      = true,
    [kHudItem_2_SuperMissile] = true,
    [kHudItem_3_PowerBomb]    = false,
    [kHudItem_4_Grapple]      = true,
    [kHudItem_5_Xray]         = false,
  };

  if (arm_cannon_toggle_flag < kArmCannonToggle_2_No)
    return 0;
  bool arm_cannon_should_be_open_flag = kFlagShouldArmCannonBeOpen[hud_item_index];
  if (flag_arm_cannon_open_or_opening == arm_cannon_should_be_open_flag)
    return 0;
  if (arm_cannon_should_be_open_flag)
    arm_cannon_frame = kArmCannonFrame_0_Closed;
  else
    arm_cannon_frame = kArmCannonFrame_3_Opened + 1;
  flag_arm_cannon_open_or_opening = arm_cannon_should_be_open_flag;
  flag_arm_cannon_opening_or_closing |= true;
  return 1;
}

/**
* @brief Advance the arm cannon to the next opening or closing frame
*/
void AdvanceArmCannonFrame(void) {  // 0x90C627
  if (flag_arm_cannon_open_or_opening) {
    // If the next frame is not fully opened
    if (arm_cannon_frame + 1 < kArmCannonFrame_3_Opened) {
      ++arm_cannon_frame;
      return;
    }
    arm_cannon_frame = kArmCannonFrame_3_Opened;
  }
  else {
    // If the next frame is not fully closed
    if (arm_cannon_frame - 1 > kArmCannonFrame_0_Closed) {
      --arm_cannon_frame;
      return;
    }
    arm_cannon_frame = kArmCannonFrame_0_Closed;
  }
  flag_arm_cannon_opening_or_closing = 0;
}

/**
* @brief Spawn and draw the arm cannon
*/
void Samus_ArmCannon_Draw(void) {  // 0x90C663
  static const uint16 kDrawArmCannon_Char[10] = {
    [kProjectileDir_UpFaceRight]   = OAM_DATA(0, 0, 2, 4, 31),
    [kProjectileDir_UpRight]       = OAM_DATA(0, 0, 2, 4, 31),
    [kProjectileDir_Right]         = OAM_DATA(0, 0, 2, 4, 31),
    [kProjectileDir_DownRight]     = OAM_DATA(0, 1, 2, 4, 31),
    [kProjectileDir_DownFaceRight] = OAM_DATA(1, 0, 2, 4, 31),
    [kProjectileDir_DownFaceLeft]  = OAM_DATA(1, 1, 2, 4, 31),
    [kProjectileDir_DownLeft]      = OAM_DATA(0, 0, 2, 4, 31),
    [kProjectileDir_Left]          = OAM_DATA(0, 1, 2, 4, 31),
    [kProjectileDir_UpLeft]        = OAM_DATA(0, 1, 2, 4, 31),
    [kProjectileDir_UpFaceLeft]    = OAM_DATA(0, 1, 2, 4, 31)
  };

  uint16 arm_cannon_drawing_data_direction;
  uint16 xy_offset;

  if (arm_cannon_frame != kArmCannonFrame_0_Closed && (samus_invincibility_timer == 0 || (nmi_frame_counter_word & 1) == 0)) {
    const ArmCannonDrawingData *arm_cannon_drawing_data = get_ArmCannonDrawingData(samus_pose);
    if (arm_cannon_drawing_data[0].direction & 0x80) {
      if (samus_anim_frame != 0)
        arm_cannon_drawing_data_direction = arm_cannon_drawing_data[1].direction & 0x7F;
      else
        arm_cannon_drawing_data_direction = arm_cannon_drawing_data[0].frame_zero_direction & 0x7F;
      xy_offset = 2;
    }
    else {
      arm_cannon_drawing_data_direction = arm_cannon_drawing_data[0].direction;
      xy_offset = 1;
    }

    uint16 arm_cannon_draw_x_offset = arm_cannon_drawing_data[xy_offset + samus_anim_frame].x_offset;
    uint16 arm_cannon_draw_y_offset = arm_cannon_drawing_data[xy_offset + samus_anim_frame].y_offset;
    uint16 proj_origin_y_offset = kPoseParams[samus_pose].y_offset_proj_origin_to_gfx;

    int16 arm_cannon_draw_screen_x_pos = arm_cannon_draw_x_offset + samus_x_pos - layer1_x_pos;
    int16 arm_cannon_draw_screen_y_pos = arm_cannon_draw_y_offset + samus_y_pos - proj_origin_y_offset - layer1_y_pos;
    if (0 <= arm_cannon_draw_screen_x_pos && arm_cannon_draw_screen_x_pos < (16*16)) {
      OamEnt *oam = gOamEnt(oam_next_ptr);
      oam->xcoord = arm_cannon_draw_screen_x_pos;
      if (0 <= arm_cannon_draw_screen_y_pos && arm_cannon_draw_screen_y_pos < (16*16)) {
          oam->ycoord = arm_cannon_draw_screen_y_pos;
          WORD(oam->charnum) = kDrawArmCannon_Char[arm_cannon_drawing_data_direction];
          oam_next_ptr += sizeof(OamEnt);
      }
    }

    VramWriteEntry *vram_entry = gVramWriteEntry(vram_write_queue_tail);
    vram_entry->size = 32;
    vram_entry->src.addr = kDrawArmCannon_TilePtr[arm_cannon_drawing_data_direction][arm_cannon_frame];
    vram_entry->src.bank = 0x9A;
    vram_entry->vram_dst = addr_kVram_UnclosedArmCannon;
    vram_write_queue_tail += sizeof(VramWriteEntry);
  }
}

/**
* @brief Calculate the length of the side opposite to the angle
* @param angle The angle of the distance
* @param distance The distance
* @return uint16 The length of the opposite side
*/
static uint16 Projectile_SinLookup_Inner(uint16 angle, uint16 distance) {  // 0x90CC8A
  // In bangles: opp = dist * sin(angle / 2 * pi / 0x80)
  // In degrees: opp = dist * sin(angle / 2)
  uint16 sine = kSinCosTable8bit_Sext[64 + (angle / 2)];
  uint16 lo_opp = Mult8x8(LOBYTE(sine), distance) >> 8;
  uint16 hi_opp = Mult8x8(HIBYTE(sine), distance);
  return lo_opp + hi_opp;
}

/**
* @brief Get the X and Y component of the distance with the angle
* @param angle The angle of the distance, the origin starts at up and goes clockwise
* @param distance The distance
* @return Point16U { uint16 X component of the distance, uint16 Y component of the distance }
*/
Point16U Projectile_SinLookup(uint16 angle, uint16 distance) {  // 0x90CC39
  // In bangles: (x, y) = (dist * sin(angle * pi / 0x80), dist * -cos(angle * pi / 0x80)
  // In degrees: (x, y) = (dist * sin(angle), dist * -cos(angle))
  uint16 x_dist, y_dist;
  if ((int16)angle < 0x80)
    x_dist = Projectile_SinLookup_Inner(2 * angle, distance);
  else
    x_dist = -Projectile_SinLookup_Inner(2 * (uint8)(angle + 0x80), distance);

  int16 neg_cos = (uint8)(angle - 0x40);
  if (neg_cos < 0x80)
    y_dist = Projectile_SinLookup_Inner(2 * neg_cos, distance);
  else
    y_dist = -Projectile_SinLookup_Inner(2 * (uint8)(neg_cos + 0x80), distance);
  return (Point16U) { .x = x_dist, .y = y_dist };
}

static Func_V_A *const kFireSbaFuncs[12] = {  // 0x90CCC0
  [kProjectileType_Power]                                           = FireSba_ClearCarry,
  [kProjectileType_Wave]                                            = FireSba_FireWave,
  [kProjectileType_Ice]                                             = FireSba_FireIce,
  [kProjectileType_Ice|kProjectileType_Wave]                        = FireSba_ClearCarry,
  [kProjectileType_Spazer]                                          = FireSba_FireSpazer,
  [kProjectileType_Spazer|kProjectileType_Wave]                     = FireSba_ClearCarry,
  [kProjectileType_Spazer|kProjectileType_Ice]                      = FireSba_ClearCarry,
  [kProjectileType_Spazer|kProjectileType_Ice|kProjectileType_Wave] = FireSba_ClearCarry,
  [kProjectileType_Plasma]                                          = FireSba_FirePlasma,
  [kProjectileType_Plasma|kProjectileType_Wave]                     = FireSba_ClearCarry,
  [kProjectileType_Plasma|kProjectileType_Ice]                      = FireSba_ClearCarry,
  [kProjectileType_Plasma|kProjectileType_Ice|kProjectileType_Wave] = FireSba_ClearCarry,
};

/**
* @brief Fire a Special Beam Attack and consume a power bomb
* @return uint8 1 if an SBA was fired, 0 otherwise
*/
uint8 FireSba(void) {
  if (hud_item_index != kHudItem_3_PowerBomb)
    return 0;
  uint16 beam_idx = equipped_beams & kProjectileType_BeamMask;
  samus_power_bombs = IntMax(0, samus_power_bombs - kCostOfSbaInPowerBombs[beam_idx]);
  bool sba_fired_flag = kFireSbaFuncs[beam_idx]();
  if (samus_power_bombs == 0) {
    hud_item_index = kHudItem_0_Nothing;
    samus_auto_cancel_hud_item_index = kHudItem_0_Nothing;
  }
  return sba_fired_flag;
}

/**
* @brief Do not fire an SBA
* @return uint8 0, indicating an SBA was unable to be fired
*/
uint8 FireSba_ClearCarry(void) {  // 0x90CD18
  return 0;
}

/**
* @brief Handle firing a wave SBA
* @return uint8 1, indicating an SBA was able to be fired
*/
uint8 FireSba_FireWave(void) {  // 0x90CD1A
  static const int16 kFireSba_FireWave_X_Offsets[4] = { 128, 128, -128, -128 };
  static const int16 kFireSba_FireWave_Y_Offsets[4] = { 128, -128, -128, 128 };

  for (int proj_idx = 6; proj_idx >= 0; proj_idx -= 2) {
    int idx = proj_idx >> 1;
    projectile_trail_timers[idx] = 4;
    projectile_type[idx] = equipped_beams & (kBeam_Charge | kBeam_Plasma | kBeam_Spazer | kBeam_Ice | kBeam_Wave) | (kProjectileType_DontInteractWithSamus | kProjectileType_Charged);
    projectile_dir[idx] = 0;
    projectile_pre_instructions[idx] = FUNC16(ProjPreInstr_WaveSba);
    projectile_sba_timer[idx] = 600;
    projectile_x_speed[idx] = 0;
    projectile_wave_sba_y_speed[idx] = 0;
    projectile_x_subpos[idx] = 0;
    projectile_y_subpos[idx] = 0;
    projectile_x_pos[idx] = kFireSba_FireWave_X_Offsets[idx] + samus_x_pos;
    projectile_y_pos[idx] = kFireSba_FireWave_Y_Offsets[idx] + samus_y_pos;
    InitializeSbaProjectile(proj_idx);
  }
  projectile_counter = 4;
  cooldown_timer = kProjectileCooldown_Uncharged[projectile_type[0] & kProjectileType_TableIndexMask];
  // sba_angle_delta is unused for wave SBA
  sba_angle_delta = 4;
  QueueSfx1_Max6(kSfx1_WaveSba);
  return 1;
}

/**
* @brief Handle firing an ice SBA
* @return uint8 1 if an SBA was able to be fired, 0 otherwise
*/
uint8 FireSba_FireIce(void) {  // 0x90CD9B
  if (projectile_pre_instructions[0] == FUNC16(ProjPreInstr_IceSbaEnd)
      || projectile_pre_instructions[0] == FUNC16(ProjPreInstr_IceSbaMain)) {
    return 0;
  }

  for (int proj_idx = 6; proj_idx >= 0; proj_idx -= 2) {
    int idx = proj_idx >> 1;
    projectile_trail_timers[idx] = 4;
    projectile_type[idx] = equipped_beams & (kBeam_Charge | kBeam_Plasma | kBeam_Spazer | kBeam_Ice | kBeam_Wave) | (kProjectileType_DontInteractWithSamus | kProjectileType_Charged);
    projectile_dir[idx] = 0;
    projectile_pre_instructions[idx] = FUNC16(ProjPreInstr_IceSbaMain);
    projectile_variables[idx] = kIcePlasmaSbaProjectileOriginAngles[idx];
    projectile_sba_timer[idx] = 600;
    InitializeProjectile(proj_idx);
  }
  projectile_counter = 4;
  cooldown_timer = kProjectileCooldown_Uncharged[projectile_type[0] & kProjectileType_TableIndexMask];
  sba_angle_delta = (samus_pose_x_dir == kSamusXDir_FaceLeft) ? -4 : 4;
  QueueSfx1_Max6(kSfx1_IceSba);
  return 1;
}

/**
* @brief Handle firing a spazer SBA
* @return uint8 1, indicating an SBA was able to be fired
*/
uint8 FireSba_FireSpazer(void) {  // 0x90CE14
  static const uint16 kFireSpazer_Timer[4] = { 0, 0, 4, 4 };
  static const int16 kFireSpazer_AngleDelta[4] = { 4, -4, 4, -4 };

  for (int proj_idx = 6; proj_idx >= 0; proj_idx -= 2) {
    int idx = proj_idx >> 1;
    projectile_trail_timers[idx] = kFireSpazer_Timer[idx];
    projectile_dir[idx] = kProjectileDir_DownFaceLeft;
    projectile_pre_instructions[idx] = FUNC16(ProjPreInstr_SpazerSba);
    projectile_distance[idx] = 40;
    projectile_angle_delta[idx] = kFireSpazer_AngleDelta[idx];
    projectile_angle[idx] = 0;
    spazer_sba_phase[idx] = kSpazerSbaPhase_0_Circle;
    projectile_x_subpos[idx] = 0;
    projectile_y_subpos[idx] = 0;
    if (proj_idx >= 4) {
      projectile_type[proj_idx >> 1] = (kProjectileType_DontInteractWithSamus | kProjectileType_SpazerSbaMask | kProjectileType_Spazer);
      InitializeShinesparkEchoOrSpazerSba(proj_idx);
    }
    else {
      projectile_type[proj_idx >> 1] = equipped_beams & (kBeam_Charge | kBeam_Plasma | kBeam_Spazer | kBeam_Ice | kBeam_Wave) | (kProjectileType_DontInteractWithSamus | kProjectileType_Charged);
      InitializeSbaProjectile(proj_idx);
    }
  }
  projectile_counter = 4;
  cooldown_timer = kProjectileCooldown_Uncharged[projectile_type[0] & kProjectileType_TableIndexMask];
  sba_angle_delta = 0;
  QueueSfx1_Max6(kSfx1_SpazerSba);
  return 1;
}

/**
* @brief Handle firing a plasma SBA
* @return uint8 1 if an SBA was able to be fired, 0 otherwise
*/
uint8 FireSba_FirePlasma(void) {  // 0x90CE98
  if (projectile_pre_instructions[0] == FUNC16(ProjPreInstr_PlasmaSba)) {
    return 0;
  }

  for (int proj_idx = 6; proj_idx >= 0; proj_idx -= 2) {
    int idx = proj_idx >> 1;
    projectile_type[idx] = equipped_beams & (kBeam_Charge | kBeam_Plasma | kBeam_Spazer | kBeam_Ice | kBeam_Wave) | (kProjectileType_DontInteractWithSamus | kProjectileType_Charged);
    projectile_dir[idx] = 0;
    projectile_pre_instructions[idx] = FUNC16(ProjPreInstr_PlasmaSba);
    projectile_angle[idx] = kIcePlasmaSbaProjectileOriginAngles[idx];
    projectile_distance[idx] = 40;
    projectile_plasma_sba_phase[idx] = 0;
    InitializeSbaProjectile(proj_idx);
  }
  projectile_counter = 4;
  cooldown_timer = kProjectileCooldown_Uncharged[projectile_type[0] & kProjectileType_TableIndexMask];
  sba_angle_delta = (samus_pose_x_dir == kSamusXDir_FaceLeft) ? -4 : 4;
  QueueSfx1_Max6(kSfx1_PlasmaSba);
  return 1;
}

/**
* @brief Handle ice SBA projectiles during the main phase
* @param proj_idx The index of the current projectile
*/
void ProjPreInstr_IceSbaMain(uint16 proj_idx) {  // 0x90CF09
  int idx = proj_idx >> 1;
  if (projectile_dir[idx] & (0xF0 | kProjectileDir_Delete)) {
    QueueSfx1_Max6(kSfx1_IceSbaEnd);
    ClearProjectile(proj_idx);
  }
  else {
    if (--projectile_trail_timers[idx] == 0) {
      projectile_trail_timers[idx] = 4;
      SpawnProjectileTrail(proj_idx);
    }
    Point16U proj_pos = Projectile_SinLookup(projectile_angle[idx], 0x20);
    projectile_x_pos[idx] = samus_x_pos + proj_pos.x;
    projectile_y_pos[idx] = samus_y_pos + proj_pos.y;
    projectile_angle[idx] = (uint8)(projectile_angle[idx] + sba_angle_delta);
    if (--projectile_sba_timer[idx] == 0) {
      projectile_pre_instructions[idx] = FUNC16(ProjPreInstr_IceSbaEnd);
      projectile_distance[idx] = 40;
      QueueSfx1_Max6(kSfx1_IceSbaEnd);
    }
    cooldown_timer = 2;
    flare_counter = 0;
  }
}

/**
* @brief Handle ice SBA projectiles during the ending phase
* @param proj_idx The index of the current projectile
*/
void ProjPreInstr_IceSbaEnd(uint16 proj_idx) {  // 0x90CF7A
  int idx = proj_idx >> 1;
  if (projectile_dir[idx] & (0xF0 | kProjectileDir_Delete)) {
    ClearProjectile(proj_idx);
  }
  else {
    if (--projectile_trail_timers[idx] == 0) {
      projectile_trail_timers[idx] = 4;
      SpawnProjectileTrail(proj_idx);
    }
    Point16U proj_pos = Projectile_SinLookup(projectile_angle[idx], projectile_distance[idx]);
    projectile_x_pos[idx] = samus_x_pos + proj_pos.x;
    int16 proj_screen_x_pos = projectile_x_pos[idx] - layer1_x_pos;
    if (-(2*16) <= proj_screen_x_pos && proj_screen_x_pos < (18*16)) {
      projectile_y_pos[idx] = samus_y_pos + proj_pos.y;
      int16 proj_screen_y_pos = projectile_y_pos[idx] - layer1_y_pos;
      if ((1*16) <= proj_screen_y_pos && proj_screen_y_pos < (16*16)) {
        projectile_angle[idx] = (uint8)(projectile_angle[idx] + sba_angle_delta);
        projectile_distance[idx] = (uint8)(projectile_distance[idx] + 8);
        cooldown_timer = 2;
        flare_counter = 0;
        return;
      }
    }
    ClearProjectile(proj_idx);
  }
}

/**
* @brief Begin the shinespark windup
*/
void TriggerShinesparkWindup(void) {  // 0x90CFFA
  samus_movement_handler = FUNC16(Samus_MovementHandler_ShinesparkWindup);
  samus_y_dir = kSamusYDir_Up;
  speed_boost_timer = 0;
  speed_boost_counter = SPEED_BOOST_THRESHOLD;
  samus_y_subspeed = 0;
  samus_y_speed = 0;
  knockback_dir = kKnockbackDir_None;
  samus_x_extra_run_speed = 8;
  samus_x_extra_run_subspeed = 0;
  samus_x_base_speed = 0;
  samus_x_base_subspeed = 0;
  shinespark_y_accel = 7;
  shinespark_y_subaccel = 0;
  cooldown_timer = 0;
  shinespark_startstop_timer = 30;
  samus_shine_timer = 60;
  special_samus_palette_type = 6;
  special_samus_palette_frame = 0;
  bomb_jump_dir = kBombJumpDir_None;
  if (flare_counter != 0) {
    if ((int16)flare_counter >= 16)
      QueueSfx1_Max9(kSfx1_Silence);
    flare_counter = 0;
    ClearFlareAnimationState();
  }
}

/**
* @brief Handle the shinespark windup
*/
void Samus_MovementHandler_ShinesparkWindup(void) {  // 0x90D068
  if ((int16)--shinespark_startstop_timer <= 0) {
    if (samus_pose_x_dir == kSamusXDir_FaceLeft)
      samus_new_pose_interrupted = kPose_CC_FaceL_Shinespark_Vert;
    else
      samus_new_pose_interrupted = kPose_CB_FaceR_Shinespark_Vert;
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
* @brief Handle a vertical shinespark
*/
void Samus_MovementHandler_VerticalShinespark(void) {  // 0x90D0AB
  samus_contact_damage_index = kSamusContactDamageIndex_2_Shinespark;
  samus_hurt_flash_counter = 8;
  Samus_UpdateSpeedEchoPos();
  Samus_ShinesparkMove_Y();
  Samus_EndShinespark();
  if ((int16)samus_health >= 30) {
    --samus_health;
  }
}

/**
* @brief Handle a diagonal shinespark
*/
void Samus_MovementHandler_DiagonalShinespark(void) {  // 0x90D0D7
  samus_contact_damage_index = kSamusContactDamageIndex_2_Shinespark;
  samus_hurt_flash_counter = 8;
  Samus_UpdateSpeedEchoPos();
  Samus_ShinesparkMove_X();
  Samus_ShinesparkMove_Y();
  Samus_EndShinespark();
  if ((int16)samus_health >= 30) {
    --samus_health;
  }
}

/**
* @brief Handle a horizontal shinespark
*/
void Samus_MovementHandler_HorizontalShinespark(void) {  // 0x90D106
  samus_contact_damage_index = kSamusContactDamageIndex_2_Shinespark;
  samus_hurt_flash_counter = 8;
  Samus_UpdateSpeedEchoPos();
  Samus_ShinesparkMove_X();
  Samus_EndShinespark();
  if ((int16)samus_health >= 30) {
    --samus_health;
  }
}

static uint32 Samus_ClampSpeedHi(int32 amt, int val) {
  if (!sign16((amt >> 16) - val))
    amt = val << 16 | (amt & 0xffff);
  return amt;
}

/**
* @brief Move Samus horizontally during shinespark
*/
void Samus_ShinesparkMove_X(void) {  // 0x90D132
  CheckEnemyColl_Result coll_result;

  samus_shine_timer = 15;
  AddToHiLo(&samus_x_extra_run_speed, &samus_x_extra_run_subspeed, __PAIR32__(shinespark_x_accel, shinespark_x_subaccel));
  if (samus_x_extra_run_speed >= 15)
    SetHiLo(&samus_x_extra_run_speed, &samus_x_extra_run_subspeed, INT16_SHL16(15));

  int32 coll_dist = 0;
  if (samus_pose_x_dir == kSamusXDir_FaceLeft) {
    int32 x_displacement = Samus_ClampSpeedHi(-(int32)Samus_CalcDisplacementMoveLeft(0), 15);
    coll_result = Samus_CheckSolidEnemyColl(x_displacement);
    coll_dist = coll_result.amt;
    if (!coll_result.collision)
      coll_dist = -(int32)coll_dist;
  }
  else {
    int32 x_displacement = Samus_ClampSpeedHi(Samus_CalcDisplacementMoveRight(0), 25);
    coll_result = Samus_CheckSolidEnemyColl(x_displacement);
    coll_dist = coll_result.amt;
  }

  if (coll_result.collision) {
    samus_collision_flag = coll_result.collision;
  }
  else {
    Samus_MoveRight_NoSolidColl(coll_dist);
    Samus_AlignYPosSlope();
  }

  if ((int16)samus_x_pos < (int16)samus_prev_x_pos) {
    if ((int16)samus_x_pos < (int16)(samus_prev_x_pos - 15))
      samus_prev_x_pos = samus_x_pos + 15;
  }
  else if ((int16)samus_x_pos >= (int16)(samus_prev_x_pos + 16)) {
    samus_prev_x_pos = samus_x_pos - 15;
  }
}

/**
* @brief Move Samus vertically during shinespark
*/
void Samus_ShinesparkMove_Y(void) {  // 0x90D1FF
  samus_shine_timer = 15;

  AddToHiLo(&shinespark_y_accel, &shinespark_y_subaccel, __PAIR32__(shinespark_y_accel_delta, shinespark_y_subaccel_delta));
  AddToHiLo(&samus_y_speed, &samus_y_subspeed, __PAIR32__(shinespark_y_accel, shinespark_y_subaccel));
  int32 y_speed = Samus_ClampSpeedHi(__PAIR32__(samus_y_speed, samus_y_subspeed), 14);
  y_speed -= __PAIR32__(extra_samus_y_displacement, extra_samus_y_subdisplacement);
  samus_collision_direction = kSamusCollDir_2_Up;
  CheckEnemyColl_Result coll_result = Samus_CheckSolidEnemyColl(Samus_ClampSpeedHi(y_speed, 15));
  int32 coll_dist = coll_result.amt;
  if (coll_result.collision) {
    samus_collision_flag = coll_result.collision;
  }
  else {
    Samus_MoveDown_NoSolidColl(-(int32)coll_dist);
  }
  if ((int32)samus_y_pos < (int32)(samus_prev_y_pos - 14))
    samus_prev_y_pos = samus_y_pos + 14;
}

/**
* @brief Handle when and how to end the shinespark
* @return uint8 1 if the shinespark ended, 0 otherwise
*/
uint8 Samus_EndShinespark(void) {  // 0x90D2BA
  if ((int16)samus_health >= 30 && !samus_collision_flag)
    return 0;

  if (samus_pose_x_dir == kSamusXDir_FaceLeft) {
    crash_echo_angle[0] = 0x20;
    crash_echo_angle[1] = 0xA0;
    crash_echo_angle_delta = 4;
  }
  else {
    speed_echo_xspeed[0] = 0xE0;
    speed_echo_xspeed[1] = 0x60;
    crash_echo_angle_delta = -4;
  }
  samus_y_subspeed = 0;
  samus_y_speed = 0;
  samus_x_extra_run_speed = 0;
  samus_x_extra_run_subspeed = 0;
  speed_boost_timer = 0;
  speed_boost_counter = 0;
  UNUSED_word_7E0B1A = 0;
  samus_y_dir = kSamusYDir_None;
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

/**
* @brief Handle the shinespark crash phases and echo circles at the end of a shinespark
*/
void Samus_MovementHandler_ShinesparkCrash_EchoCircle(void) {
  samus_shine_timer = 15;
  kSamus_MoveHandler_ShinesparkCrash[crash_echo_circle_phase]();
  for (int speed_echo_idx = 2; speed_echo_idx >= 0; speed_echo_idx -= 2) {
    int idx = speed_echo_idx >> 1;
    Point16U speed_echo_pos = Projectile_SinLookup(crash_echo_angle[idx], crash_echo_distance);
    speed_echo_xpos[idx] = speed_echo_pos.x + samus_x_pos;
    speed_echo_ypos[idx] = speed_echo_pos.y + samus_y_pos;
  }
}

/**
* @brief Handle phase 0 of the echo circle in which the echo distance expands
*/
void Samus_MovementHandler_ShinesparkCrash_EchoCircle_Phase0(void) {  // 0x90D383
  crash_echo_distance += 4;
  if (crash_echo_distance >= 16)
    crash_echo_circle_phase = 1;
}

/**
* @brief Handle phase 1 of the echo circle in which the echo begins to circle
*/
void Samus_MovementHandler_ShinesparkCrash_EchoCircle_Phase1(void) {  // 0x90D396
  crash_echo_angle[0] = (uint8)(crash_echo_angle[0] + crash_echo_angle_delta);
  crash_echo_angle[1] = (uint8)(crash_echo_angle[1] + crash_echo_angle_delta);
  crash_echo_circle_timer += 4;
  if (crash_echo_circle_timer >= 128)
    crash_echo_circle_phase = 2;
}

/**
* @brief Handle phase 2 of the echo circle in which the echo distance contracts
*/
void Samus_MovementHandler_ShinesparkCrash_EchoCircle_Phase2(void) {  // 0x90D3CC
  WORD(crash_echo_distance) -= 4;
  if ((int8)crash_echo_distance <= 0) {
    samus_movement_handler = FUNC16(Samus_MovementHandler_ShinesparkCrash_EchoCircle_Finish);
    shinespark_startstop_timer = 30;
    //speed_echoes_index = 0;
    crash_echo_distance = 0;
    crash_echo_circle_phase = 0;
    speed_echo_xspeed[0] = 0;
    speed_echo_xspeed[1] = 0;
  }
}

/**
* @brief Handle the end of the echo circle
*/
void Samus_MovementHandler_ShinesparkCrash_EchoCircle_Finish(void) {  // 0x90D3F3
  samus_shine_timer = 15;
  if ((int16)--shinespark_startstop_timer <= 0) {
    samus_movement_handler = FUNC16(Samus_MovementHandler_ShinesparkCrash_Finish);
    samus_draw_handler = FUNC16(Samus_DrawHandler_Default);
  }
}

/**
* @brief Handle the final part of the shinespark crash
*/
void Samus_MovementHandler_ShinesparkCrash_Finish(void) {  // 0x90D40D
  static const uint8 kShinesparkCrashFinish_SpeedEchoAngles[12] = {
    [2 * (kPose_C9_FaceR_Shinespark_Horiz - kPose_C9_FaceR_Shinespark_Horiz)] =    0, 0x80,
    [2 * (kPose_CA_FaceL_Shinespark_Horiz - kPose_C9_FaceR_Shinespark_Horiz)] =    0, 0x80,
    [2 * (kPose_CB_FaceR_Shinespark_Vert - kPose_C9_FaceR_Shinespark_Horiz)]  = 0x40, 0xc0,
    [2 * (kPose_CC_FaceL_Shinespark_Vert - kPose_C9_FaceR_Shinespark_Horiz)]  = 0x40, 0xc0,
    [2 * (kPose_CD_FaceR_Shinespark_Diag - kPose_C9_FaceR_Shinespark_Horiz)]  = 0xe0, 0x60,
    [2 * (kPose_CE_FaceL_Shinespark_Diag - kPose_C9_FaceR_Shinespark_Horiz)]  = 0x20, 0xa0,
  };

  speed_echoes_index = 0;
  if (projectile_counter < 5) {
    if (projectile_counter < 4) {
      ++projectile_counter;
      speed_echo_draw_flag[2] = 0x40;
      speed_echo_xpos[2] = samus_x_pos;
      speed_echo_ypos[2] = samus_y_pos;
      projectile_type[3] = kProjectileType_DontInteractWithSamus | kProjectileType_ShinesparkEcho;
      InitializeShinesparkEchoOrSpazerSba(6);
      projectile_pre_instructions[3] = FUNC16(ProjPreInstr_SpeedEcho);
      projectile_angle[3] = kShinesparkCrashFinish_SpeedEchoAngles[2 * (samus_pose - kPose_C9_FaceR_Shinespark_Horiz)];
      projectile_distance[3] = 0;
    }
    ++projectile_counter;
    speed_echo_draw_flag[3] = 0x40;
    speed_echo_xpos[3] = samus_x_pos;
    speed_echo_ypos[3] = samus_y_pos;
    projectile_type[4] = kProjectileType_DontInteractWithSamus | kProjectileType_ShinesparkEcho;
    InitializeShinesparkEchoOrSpazerSba(8);
    projectile_pre_instructions[4] = FUNC16(ProjPreInstr_SpeedEcho);
    projectile_angle[4] = kShinesparkCrashFinish_SpeedEchoAngles[2 * (samus_pose - kPose_C9_FaceR_Shinespark_Horiz) + 1];
    projectile_distance[4] = 0;
  }
  cooldown_timer = 0;
  samus_shine_timer = 1;
  samus_new_pose_transitional = (samus_pose_x_dir == kSamusXDir_FaceLeft) ? kPose_02_FaceL_Normal : kPose_01_FaceR_Normal;
  samus_new_pose_transitional_command = 2;
  substate = 0;
  suit_pickup_light_beam_pos = 0;
}

/**
* @brief Update speed echo projectile positions
* @param proj_idx The index of the current projectile
*/
void ProjPreInstr_SpeedEcho(uint16 proj_idx) {  // 0x90D4D2
  /* @todo projectile index will be 6 or 8, so indexing can be cleaned up here */
  uint16 *speed_echoes_idx = &speed_echoes_index;

  int idx = proj_idx >> 1;
  projectile_distance[idx] += 8;
  Point16U proj_pos = Projectile_SinLookup(projectile_angle[idx], LOBYTE(projectile_distance[idx]));
  speed_echoes_idx[idx] = samus_x_pos + proj_pos.x;
  projectile_x_pos[idx] = speed_echoes_idx[idx];
  int16 proj_screen_x_pos = projectile_x_pos[idx] - layer1_x_pos;
  if (0 <= proj_screen_x_pos && proj_screen_x_pos < (16*16)) {
    speed_echo_xpos[idx + 3] = samus_y_pos + proj_pos.y;
    projectile_y_pos[idx] = speed_echo_xpos[idx + 3];
    int16 proj_screen_y_pos = projectile_y_pos[idx] - layer1_y_pos;
    if (0 <= proj_screen_y_pos && proj_screen_y_pos < (16*16))
      return;
  }
  speed_echo_ypos[idx + 3] = 0;
  speed_echoes_idx[idx] = 0;
  speed_echo_xpos[idx + 3] = 0;
  ClearProjectile(proj_idx);

}

void UNUSED_Grapple_Func1(void) {  // 0x90D525
  bool v0; // sf

  if ((joypad1_lastkeys & button_config_shoot)
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
  }
  else {
    grapple_beam_function = FUNC16(GrappleBeamFunc_Cancel);
  }
}

/**
* @brief Begin a crystal flash
* @return uint8 0 if a crystal flash was activated, 1 otherwise
*/
uint8 CrystalFlash(void) {  // 0x90D5A2
  if (game_state < kGameState_40_TransitionToDemo) {
    // To activate crystal flash, both shoulder buttons and down must be pressed
    if (joypad1_lastkeys != (button_config_shoot | (kButton_Down | kButton_L | kButton_R)))
      return 1;
  }
  // To activate crystal flash, samus must be still, have 50 health or below, no reserve health
  // and at least 10 missiles, super missiles, and power bombs
  if (samus_y_speed != 0 || samus_y_subspeed != 0 || samus_health > 50 || samus_reserve_health != 0
      || samus_missiles < 10 || samus_super_missiles < 10 || samus_power_bombs < 10) {
    return 1;
  }

  samus_pose = (samus_pose_x_dir == kSamusXDir_FaceLeft) ? kPose_D4_FaceL_CrystalFlash : kPose_D3_FaceR_CrystalFlash;
  SamusFunc_F433();
  Samus_SetAnimationFrameIfPoseChanged();
  if (samus_movement_type != kMovementType_1B_Shinespark_CrystalFlash_Drained_DamagedByMotherBrain)
    return 1;
  samus_last_different_pose = samus_prev_pose;
  samus_last_different_pose_x_dir = samus_prev_pose_x_dir;
  samus_last_different_pose_movement_type = samus_prev_movement_type;

  samus_prev_pose = samus_pose;
  samus_prev_pose_x_dir = samus_pose_x_dir;
  samus_prev_movement_type = samus_movement_type;

  samus_movement_handler = FUNC16(Samus_MovementHandler_CrystalFlashStart);
  if (samus_input_handler != FUNC16(Samus_InputHandler_Demo))
    samus_input_handler = FUNC16(nullsub_152);
  crystal_flash_raise_timer = 9;
  crystal_flash_ammo_decrement_index = kCrystalFlashAmmoDecrement_0_Missiles;
  crystal_flash_ammo_decrement_timer = 10;
  suit_pickup_light_beam_pos = 0;
  *(uint16 *)&suit_pickup_color_math_R = 0;  // Pointless
  special_samus_palette_type = 7;
  special_samus_palette_frame = 0;
  samus_shine_timer = 1;
  *(uint16 *)&suit_pickup_color_math_B = 1;  // Pointless
  samus_invincibility_timer = 0;
  samus_knockback_timer = 0;
  knockback_dir = kKnockbackDir_None;
  return 0;
}

/**
* @brief Raise Samus and start the crystal flash effect
*/
void Samus_MovementHandler_CrystalFlashStart(void) {  // 0x90D678
  samus_y_pos -= 2;
  if ((int16)--shinespark_startstop_timer < 0) {
    samus_anim_frame_timer = 3;
    samus_anim_frame = 6;
    crystal_flash_y_pos = samus_y_pos;
    samus_movement_handler = FUNC16(Samus_MovementHandler_CrystalFlashMain);
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

/**
* @brief Handle restoring Samus health and decrementing ammo during crystal flash
*/
void Samus_MovementHandler_CrystalFlashMain(void) {
  kSamusMoveHandler_CrystalFlashMainFuncs[crystal_flash_ammo_decrement_index]();
  samus_invincibility_timer = 0;
  samus_knockback_timer = 0;
}

/**
* @brief Handle restoring Samus health and decrementing missile amount
*/
void SamusMoveHandler_CrystalFlash_0_DecMissiles(void) {  // 0x90D6E3
  if ((nmi_frame_counter_word & 7) == 0) {
    --samus_missiles;
    Samus_RestoreHealth(50);
    if ((int16)--crystal_flash_ammo_decrement_timer <= 0) {
      crystal_flash_ammo_decrement_timer = 10;
      crystal_flash_ammo_decrement_index = kCrystalFlashAmmoDecrement_1_SuperMissiles;
    }
  }
}

/**
* @brief Handle restoring Samus health and decrementing super missile amount
*/
void SamusMoveHandler_CrystalFlash_1_DecSuperMissiles(void) {  // 0x90D706
  if ((nmi_frame_counter_word & 7) == 0) {
    --samus_super_missiles;
    Samus_RestoreHealth(50);
    if (--crystal_flash_ammo_decrement_timer <= 0) {
      crystal_flash_ammo_decrement_timer = 10;
      crystal_flash_ammo_decrement_index = kCrystalFlashAmmoDecrement_2_PowerBombs;
    }
  }
}

/**
* @brief Handle restoring Samus health and decrementing power bomb amount
*/
void SamusMoveHandler_CrystalFlash_2_DecPowerBombs(void) {  // 0x90D729
  if ((nmi_frame_counter_word & 7) == 0) {
    --samus_power_bombs;
    Samus_RestoreHealth(50);
    if (--crystal_flash_ammo_decrement_timer <= 0) {
      samus_movement_handler = FUNC16(Samus_MovementHandler_CrystalFlashFinish);
      samus_draw_handler = FUNC16(Samus_DrawHandler_Default);
      samus_anim_frame_timer = 3;
      samus_anim_frame = 12;
    }
  }
}

/**
* @brief Handle the final part of the crystal flash
*/
void Samus_MovementHandler_CrystalFlashFinish(void) {  // 0x90D75B
  if (samus_y_pos != crystal_flash_y_pos)
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

/**
* @brief Handle plasma SBA movement and phase
* @param proj_idx The index of the current projectile
*/
void ProjPreInstr_PlasmaSba(uint16 proj_idx) {  // 0x90D793
  int idx = proj_idx >> 1;
  if (projectile_dir[idx] & (0xF0 | kProjectileDir_Delete)) {
    ClearProjectile(proj_idx);
  }
  else {
    cooldown_timer = 2;
    flare_counter = 0;
    Point16U proj_pos = Projectile_SinLookup(projectile_angle[idx], projectile_distance[idx]);
    projectile_x_pos[idx] = samus_x_pos + proj_pos.x;
    projectile_y_pos[idx] = samus_y_pos + proj_pos.y;
    projectile_angle[idx] = (uint8)(projectile_angle[idx] + sba_angle_delta);
    switch (projectile_plasma_sba_phase[idx]) {
      case 0: ProjPreInstr_PlasmaSba_Phase0_Expand(proj_idx); break;
      case 1: ProjPreInstr_PlasmaSba_Phase1_Contract(proj_idx); break;
      case 2: ProjPreInstr_PlasmaSba_Phase2_Disperse(proj_idx); break;
      default: Unreachable();
    }
  }
}

/**
* @brief Handle phase 0 of the plasma SBA in which the beam moves outwards
* @param proj_idx The index of the current projectile
*/
void ProjPreInstr_PlasmaSba_Phase0_Expand(uint16 proj_idx) {  // 0x90D7E1
  int idx = proj_idx >> 1;
  projectile_distance[idx] = (uint8)(projectile_distance[idx] + 4);
  if ((int16)projectile_distance[idx] >= (12*16))
    projectile_plasma_sba_phase[idx] = 1;
}

/**
* @brief Handle phase 1 of the plasma SBA in which the beam moves inwards
* @param proj_idx The index of the current projectile
*/
void ProjPreInstr_PlasmaSba_Phase1_Contract(uint16 proj_idx) {  // 0x90D7FA
  int idx = proj_idx >> 1;
  projectile_distance[idx] = (uint8)(projectile_distance[idx] - 4);
  if ((int16)projectile_distance[idx] < 45)
    projectile_plasma_sba_phase[idx] = 2;
}

/**
* @brief Handle phase 2 of the plasma SBA in which the beam leaves the screen
* @param proj_idx The index of the current projectile
*/
void ProjPreInstr_PlasmaSba_Phase2_Disperse(uint16 proj_idx) {  // 0x90D813
  int idx = proj_idx >> 1;
  int16 proj_screen_x_pos = projectile_x_pos[idx] - layer1_x_pos;
  int16 proj_screen_y_pos = projectile_y_pos[idx] - layer1_y_pos;
  if (-(2*16) <= proj_screen_x_pos && proj_screen_x_pos < (18*16)) {
    if ((1*16) <= proj_screen_y_pos && proj_screen_y_pos < (16*16)) {
      projectile_distance[idx] = (uint8)(projectile_distance[idx] + 4);
      return;
    }
  }
  ClearProjectile(proj_idx);
}

/**
* @brief Handle bomb spread movement
* @param proj_idx The current index of the projectile
*/
void ProjPreInstr_SpreadBomb(uint16 proj_idx) {  // 0x90D8F7
  // Bomb spread starts at projectile index 10
  int idx = proj_idx >> 1;
  int bomb_idx = (proj_idx - BOMB_PROJ_OFFSET) >> 1;
  if (projectile_dir[idx] & (0xF0 | kProjectileDir_Delete)) {
    ClearProjectile(proj_idx);
    return;
  }
  HandleBomb();

  if (bomb_timers[bomb_idx] != 0) {
    AddToHiLo(&bomb_y_speed[bomb_idx], &bomb_y_subspeeds[bomb_idx], __PAIR32__(samus_y_accel, samus_y_subaccel));
    AddToHiLo(&projectile_y_pos[idx], &projectile_y_subpos[idx], __PAIR32__(bomb_y_speed[bomb_idx], bomb_y_subspeeds[bomb_idx]));
    if (BlockCollSpreadBomb(proj_idx)) {
      AddToHiLo(&projectile_y_pos[idx], &projectile_y_subpos[idx], -IPAIR32(bomb_y_speed[bomb_idx], bomb_y_subspeeds[bomb_idx]));
      if ((int16)bomb_y_speed[bomb_idx] < 0) {
        bomb_y_speed[bomb_idx] = 0;
        projectile_y_radius[idx] = 0;
      }
      else {
        bomb_y_subspeeds[bomb_idx] = kBombSpread_Subspeed_Y[bomb_idx];
        bomb_y_speed[bomb_idx] = bomb_bounce_y_speed[bomb_idx];
      }
      return;
    }

    if (bomb_x_speed[bomb_idx] & BOMB_SPREAD_LEFT)
      AddToHiLo(&projectile_x_pos[idx], &projectile_x_subpos[idx], -INT16_SHL8(bomb_x_speed[bomb_idx] & 0x7fff));
    else
      AddToHiLo(&projectile_x_pos[idx], &projectile_x_subpos[idx], INT16_SHL8(bomb_x_speed[bomb_idx]));
  }

  if (BlockCollSpreadBomb(proj_idx)) {
    bomb_x_speed[bomb_idx] ^= BOMB_SPREAD_LEFT;
    if (bomb_x_speed[bomb_idx] & BOMB_SPREAD_LEFT)
      AddToHiLo(&projectile_x_pos[idx], &projectile_x_subpos[idx], -INT16_SHL8(bomb_x_speed[bomb_idx] & 0x7fff));
    else
      AddToHiLo(&projectile_x_pos[idx], &projectile_x_subpos[idx], INT16_SHL8(bomb_x_speed[bomb_idx]));
  }
}

/**
* @brief Handle each bomb in bomb spread
*/
void BombSpread(void) {  // 0x90D849
  if (main_bomb_spread_bomb_pre_instruction != FUNC16(ProjPreInstr_SpreadBomb)) {
    // Bomb spread starts at projectile index 10
    for (uint16 proj_idx = BOMB_PROJ_OFFSET; proj_idx < 20; proj_idx += 2) {
      int idx = proj_idx >> 1;
      projectile_type[idx] = kProjectileType_DontInteractWithSamus | kProjectileType_Bomb;
      projectile_dir[idx] = 0;
      projectile_pre_instructions[idx] = FUNC16(ProjPreInstr_SpreadBomb);
      InitializeInstrForBombOrPowerBomb(proj_idx);
      projectile_x_pos[idx] = samus_x_pos;
      projectile_x_subpos[idx] = 0;
      projectile_y_pos[idx] = samus_y_pos;
      projectile_y_subpos[idx] = 0;
      int bomb_idx = (proj_idx - BOMB_PROJ_OFFSET) >> 1;
      bomb_x_speed[bomb_idx] = kBombSpread_Speed_X[bomb_idx];
      bomb_y_subspeeds[bomb_idx] = kBombSpread_Subspeed_Y[bomb_idx];
      uint16 bomb_spread_y_speed = -(((bomb_spread_charge_timeout_counter / 0x40) % 4) + kBombSpread_Speed_Y[bomb_idx]);
      bomb_bounce_y_speed[bomb_idx] = bomb_y_speed[bomb_idx] = bomb_spread_y_speed;
      bomb_timers[bomb_idx] = kBombSpread_Timer[bomb_idx];
    }
    bomb_counter = 5;
    cooldown_timer = kNonBeamProjectileCooldowns[GET_HIBYTE(main_bomb_spread_bomb & kProjectileType_ProjMask)];
    bomb_spread_charge_timeout_counter = 0;
    flare_counter = 0;
  }
}

/**
* @brief Handle wave SBA movement and trails
* @param proj_idx The index of the current projectile
*/
void ProjPreInstr_WaveSba(uint16 proj_idx) {  // 0x90DA08
  int idx = proj_idx >> 1;
  if ((projectile_dir[idx] & (0xF0 | kProjectileDir_Delete)) || (int16)--projectile_y_speed[idx] <= 0) {
    QueueSfx1_Max6(kSfx1_WaveSbaEnd_Silence);
    ClearProjectile(proj_idx);
    return;
  }
  uint16 old_proj_x_speed = projectile_x_speed[idx];
  if (--projectile_trail_timers[idx] == 0) {
    projectile_trail_timers[idx] = 4;
    SpawnProjectileTrail(proj_idx);
    proj_idx = projectile_index;
  }

  if ((int16)samus_x_pos < (int16)projectile_x_pos[idx]) {
    if ((int16)projectile_x_speed[idx] > -0x800)
      projectile_x_speed[idx] -= 0x40;
  }
  else if ((int16)projectile_x_speed[idx] < 0x800) {
    projectile_x_speed[idx] += 0x40;
  }
  AddToHiLo(&projectile_x_pos[idx], &projectile_x_subpos[idx], INT16_SHL8(projectile_x_speed[idx]));

  if ((int16)samus_y_pos < (int16)projectile_y_pos[idx]) {
    if ((int16)projectile_wave_sba_y_speed[idx] > -0x800)
      projectile_wave_sba_y_speed[idx] -= 0x40;
  }
  else if ((int16)projectile_wave_sba_y_speed[idx] < 0x800) {
    projectile_wave_sba_y_speed[idx] += 0x40;
  }
  AddToHiLo(&projectile_y_pos[idx], &projectile_y_subpos[idx], INT16_SHL8(projectile_wave_sba_y_speed[idx]));

  // The 6th projectile index is the first one to be spawned
  if (proj_idx == 6) {
    if ((int16)projectile_x_speed[6 >> 1] < 0) {
      if ((int16)old_proj_x_speed >= 0)
        QueueSfx1_Max6(kSfx1_WaveSba);
    }
    else if ((int16)old_proj_x_speed < 0) {
      QueueSfx1_Max6(kSfx1_WaveSba);
    }
  }
  cooldown_timer = 2;
  flare_counter = 0;
}

typedef void Func_SpazerSba_V(uint16 proj_idx, uint16 proj_y_pos);

static Func_SpazerSba_V *const kProjPreInstr_SpazerSba_PhaseFuncs[3] = {  // 0x90DB06
  ProjPreInstr_SpazerSba_Phase0_Circle,
  ProjPreInstr_SpazerSba_Phase2_FlyToPoint,
  ProjPreInstr_SpazerSba_Phase4_FlyFromPoint,
};

static Func_Y_V *const kProjPreInstr_SpazerSba_ClearFuncs[4] = {
  ProjPreInstr_SpazerSba_ClearProjPair0,
  ProjPreInstr_SpazerSba_ClearProjPair2,
  ProjPreInstr_SpazerSba_ClearProjPair4,
  ProjPreInstr_SpazerSba_ClearProjPair6,
};

/**
* @brief Handle spazer SBA projectiles and phase
* @param proj_idx The index of the current projectile
*/
void ProjPreInstr_SpazerSba(uint16 proj_idx) {
  int idx = proj_idx >> 1;
  if (projectile_dir[idx] & (0xF0 | kProjectileDir_Delete)) {
    kProjPreInstr_SpazerSba_ClearFuncs[idx](proj_idx);
  }
  else {
    if (--projectile_trail_timers[idx] == 0) {
      projectile_trail_timers[idx] = 4;
      SpawnProjectileTrail(proj_idx);
    }
    Point16U proj_pos = Projectile_SinLookup(projectile_angle[idx], projectile_distance[idx]);
    projectile_x_pos[idx] = samus_x_pos + proj_pos.x;
    kProjPreInstr_SpazerSba_PhaseFuncs[spazer_sba_phase[idx] >> 1](proj_idx, proj_pos.y);
    cooldown_timer = 2;
    flare_counter = 0;
  }
}

/**
* @brief Clear spazer SBA projectile index 0 and 4
* @param proj_idx The index of the current projectile
*/
void ProjPreInstr_SpazerSba_ClearProjPair0(uint16 proj_idx) {  // 0x90DB57
  ClearProjectile(proj_idx);
  ClearProjectile(4);
}

/**
* @brief Clear spazer SBA projectile index 2 and 6
* @param proj_idx The index of the current projectile
*/
void ProjPreInstr_SpazerSba_ClearProjPair2(uint16 proj_idx) {  // 0x90DB66
  ClearProjectile(proj_idx);
  ClearProjectile(6);
}

/**
* @brief Clear spazer SBA projectile index 4 and 0
* @param proj_idx The index of the current projectile
*/
void ProjPreInstr_SpazerSba_ClearProjPair4(uint16 proj_idx) {  // 0x90DB75
  ClearProjectile(proj_idx);
  ClearProjectile(0);
}

/**
* @brief Clear spazer SBA projectile index 6 and 2
* @param proj_idx The index of the current projectile
*/
void ProjPreInstr_SpazerSba_ClearProjPair6(uint16 proj_idx) {  // 0x90DB84
  ClearProjectile(proj_idx);
  ClearProjectile(2);
}

/**
* @brief Handle phase 0 of the spazer SBA in which the beam moves in a circle
* @param proj_idx The index of the current projectile
* @param proj_y_pox The Y position of the projectile
*/
void ProjPreInstr_SpazerSba_Phase0_Circle(uint16 proj_idx, uint16 proj_y_pos) {  // 0x90DB93
  static const int16 kProjPreInstr_SpazerSba_Circle_AngleDelta[4] = { 2, -2, 2, -2 };

  int idx = proj_idx >> 1;
  projectile_y_pos[idx] = samus_y_pos + proj_y_pos;
  projectile_angle[idx] = (uint8)(projectile_angle[idx] + projectile_angle_delta[idx]);
  if (projectile_angle[idx] == 0x80) {
    projectile_distance[idx] = (10*16);
    projectile_angle_delta[idx] = kProjPreInstr_SpazerSba_Circle_AngleDelta[idx];
    projectile_dir[idx] = kProjectileDir_UpFaceRight;
    spazer_sba_phase[idx] = kSpazerSbaPhase_2_FlyToPoint;
  }
}

/**
* @brief Handle phase 2 of the spazer SBA in which the beam moves up towards a point
* @param proj_idx The index of the current projectile
* @param proj_y_pox The Y position of the projectile
*/
void ProjPreInstr_SpazerSba_Phase2_FlyToPoint(uint16 proj_idx, uint16 proj_y_pos) {  // 0x90DBCF
  static const int16 kProjPreInstr_SpazerSba_FlyToPoint_AngleDelta[4] = { -2, 2, -2, 2 };

  int idx = proj_idx >> 1;
  projectile_y_pos[idx] = samus_y_pos - 114 + proj_y_pos;
  if ((int16)(projectile_y_pos[idx] - layer1_y_pos) < 16) {
    FireEndOfSpazerSba(proj_idx);
  }
  else {
    projectile_angle[idx] = (uint8)(projectile_angle[idx] + projectile_angle_delta[idx]);
    projectile_distance[idx] -= 5;
    if (projectile_distance[idx] == 0) {
      projectile_angle_delta[idx] = kProjPreInstr_SpazerSba_FlyToPoint_AngleDelta[idx];
      projectile_angle[idx] = (uint8)(projectile_angle[idx] + 0x80);
      spazer_sba_phase[idx] = kSpazerSbaPhase_4_FlyFromPoint;
      if (proj_idx == 0)
        QueueSfx1_Max6(kSfx1_SpazerSbaEnd);
    }
  }
}

/**
* @brief Handle phase 4 of the spazer SBA in which the beam moves up away from a point
* @param proj_idx The index of the current projectile
* @param proj_y_pox The Y position of the projectile
*/
void ProjPreInstr_SpazerSba_Phase4_FlyFromPoint(uint16 proj_idx, uint16 proj_y_pos) {  // 0x90DC30
  int idx = proj_idx >> 1;
  projectile_y_pos[idx] = samus_y_pos - 114 + proj_y_pos;
  if ((int16)(projectile_y_pos[idx] - layer1_y_pos) < 16) {
    FireEndOfSpazerSba(proj_idx);
  }
  else {
    projectile_angle[idx] = (uint8)(projectile_angle[idx] + projectile_angle_delta[idx]);
    projectile_distance[idx] += 5;
    if ((int16)projectile_distance[idx] >= 96) {
      FireEndOfSpazerSba(proj_idx);
    }
  }
}

/**
* @brief Handle the end of the spazer SBA
* @param proj_idx The index of the current projectile
*/
void FireEndOfSpazerSba(uint16 proj_idx) {  // 0x90DC67
  static const int16 kFireEndOfSpazerSba_X_Position[4] = { 16, 16, -16, -16 };

  int idx = proj_idx >> 1;
  projectile_x_pos[idx] += kFireEndOfSpazerSba_X_Position[idx];
  projectile_dir[idx] = kProjectileDir_DownFaceLeft;
  projectile_trail_timers[idx] = 4;
  projectile_pre_instructions[idx] = FUNC16(ProjPreInstr_EndOfSpazerSba);
  if ((int16)proj_idx < 4) {
    projectile_type[idx] = kProjectileType_DontInteractWithSamus | kProjectileType_SpazerSbaMask | kProjectileType_Spazer;
    InitializeShinesparkEchoOrSpazerSba(proj_idx);
  }
}

/**
* @brief Process the end of the spazer SBA
* @param proj_idx The index of the current projectile
*/
void ProjPreInstr_EndOfSpazerSba(uint16 proj_idx) {  // 0x90DC9C
  int idx = proj_idx >> 1;
  if (projectile_dir[idx] & (0xF0 | kProjectileDir_Delete)) {
    ClearProjectile(proj_idx);
    return;
  }

  if (--projectile_trail_timers[idx] == 0) {
    projectile_trail_timers[idx] = 4;
    SpawnProjectileTrail(proj_idx);
  }
  projectile_y_pos[idx] += 8;
  if ((int16)(projectile_y_pos[idx] - layer1_y_pos) >= 248) {
    ClearProjectile(proj_idx);
  }
  else {
    cooldown_timer = 2;
    flare_counter = 0;
  }
}

static Func_V *kHandleHudSpecificBehaviorAndProjs[28] = {  // 0x90DCDD
  [kMovementType_00_Standing]                                             = HudSelectionHandler_Normal,
  [kMovementType_01_Running]                                              = HudSelectionHandler_Normal,
  [kMovementType_02_NormalJumping]                                        = HudSelectionHandler_Normal,
  [kMovementType_03_SpinJumping]                                          = HudSelectionHandler_JumpEtc,
  [kMovementType_04_MorphBallOnGround]                                    = HudSelectionHandler_MorphBall,
  [kMovementType_05_Crouching]                                            = HudSelectionHandler_Normal,
  [kMovementType_06_Falling]                                              = HudSelectionHandler_Normal,
  [kMovementType_07_Unused]                                               = HudSelectionHandler_MorphBall,
  [kMovementType_08_MorphBallFalling]                                     = HudSelectionHandler_MorphBall,
  [kMovementType_09_Unused]                                               = HudSelectionHandler_MorphBall,
  [kMovementType_0A_KnockbackOrCrystalFlashEnding]                        = HudSelectionHandler_JumpEtc,
  [kMovementType_0B_Unused]                                               = HudSelectionHandler_Grappling,
  [kMovementType_0C_Unused]                                               = HudSelectionHandler_Grappling,
  [kMovementType_0D_Unused]                                               = HudSelectionHandler_JumpEtc,
  [kMovementType_0E_TurningAroundOnGround]                                = HudSelectionHandler_TurningAround,
  [kMovementType_0F_Crouch_Stand_Morph_Unmorph_Transition]                = HudSelectionHandler_CrouchEtcTrans,
  [kMovementType_10_Moonwalking]                                          = HudSelectionHandler_Normal,
  [kMovementType_11_SpringBallOnGround]                                   = HudSelectionHandler_MorphBall,
  [kMovementType_12_SpringBallInAir]                                      = HudSelectionHandler_MorphBall,
  [kMovementType_13_SpringBallFalling]                                    = HudSelectionHandler_MorphBall,
  [kMovementType_14_WallJumping]                                          = HudSelectionHandler_JumpEtc,
  [kMovementType_15_RanIntoWall]                                          = HudSelectionHandler_Normal,
  [kMovementType_16_Grappling]                                            = HudSelectionHandler_Grappling,
  [kMovementType_17_TurningAroundJumping]                                 = HudSelectionHandler_TurningAround,
  [kMovementType_18_TurningAroundFalling]                                 = HudSelectionHandler_TurningAround,
  [kMovementType_19_DamageBoost]                                          = HudSelectionHandler_JumpEtc,
  [kMovementType_1A_GrabbedByDraygon]                                     = HudSelectionHandler_GrabbedByDraygon,
  [kMovementType_1B_Shinespark_CrystalFlash_Drained_DamagedByMotherBrain] = HudSelectionHandler_JumpEtc,
};

/**
* @brief Handle HUD and projectiles for movement types
*/
void Samus_HandleHudSpecificBehaviorAndProjs(void) {
  if (samus_pose == kPose_00_FaceF_Powersuit || samus_pose == kPose_9B_FaceF_VariaGravitySuit) {
    HandleProjectiles();
  }
  else {
    Samus_HandleCooldown();
    HandleSwitchingHudSelection();
    kHandleHudSpecificBehaviorAndProjs[samus_movement_type]();
    if (!time_is_frozen_flag) {
      HandleProjectiles();
    }
  }
}

/**
* @brief Handle HUD selection for normal movement types
*/
void HudSelectionHandler_Normal(void) {  // 0x90DD3D
  static Func_V *const kHudSelectionHandler_Normal[7] = {
    [kHudItem_0_Nothing]      = HudSelectionHandler_NothingOrPowerBombs,
    [kHudItem_1_Missile]      = HudSelectionHandler_MissilesOrSuperMissiles,
    [kHudItem_2_SuperMissile] = HudSelectionHandler_MissilesOrSuperMissiles,
    [kHudItem_3_PowerBomb]    = HudSelectionHandler_NothingOrPowerBombs,
    [kHudItem_4_Grapple]      = HudSelectionHandler_Grappling,
    [kHudItem_5_Xray]         = HudSelectionHandler_Xray,
    HudSelectionHandler_TurningAround,
  };

  uint16 hud_selection_handler_idx;
  if (grapple_beam_function != FUNC16(GrappleBeamFunc_Inactive)) {
    hud_selection_handler_idx = kHudItem_4_Grapple;
  }
  else {
    if (time_is_frozen_flag)
      hud_selection_handler_idx = kHudItem_5_Xray;
    else
      hud_selection_handler_idx = hud_item_index;
  }
  kHudSelectionHandler_Normal[hud_selection_handler_idx]();
}

/**
* @brief Handle HUD selection for grapple movement types
*/
void HudSelectionHandler_Grappling(void) {  // 0x90DD6F
  GrappleBeamHandler();
}

/**
* @brief Handle HUD selection for turning around movement types
*/
void HudSelectionHandler_TurningAround(void) {  // 0x90DD74
  if (new_projectile_direction_changed_pose != 0) {
    HudSelectionHandler_Normal();
  }
  else if (grapple_beam_function != FUNC16(GrappleBeamFunc_Inactive)) {
    grapple_beam_function = FUNC16(GrappleBeamFunc_Cancel);
  }
}

/**
* @brief Handle HUD selection for transition movement types
*/
void HudSelectionHandler_CrouchEtcTrans(void) {  // 0x90DD8C
  static const uint8 kPoseIsMorphTrans[12] = {
    [kPose_35_FaceR_CrouchTrans - kPose_35_FaceR_CrouchTrans]  = false,
    [kPose_36_FaceL_CrouchTrans - kPose_35_FaceR_CrouchTrans]  = false,

    [kPose_37_FaceR_MorphTrans - kPose_35_FaceR_CrouchTrans]   = true,
    [kPose_38_FaceL_MorphTrans - kPose_35_FaceR_CrouchTrans]   = true,
    [kPose_39 - kPose_35_FaceR_CrouchTrans]                    = true,
    [kPose_3A - kPose_35_FaceR_CrouchTrans]                    = true,

    [kPose_3B_FaceR_StandTrans - kPose_35_FaceR_CrouchTrans]   = false,
    [kPose_3C_FaceL_StandTrans - kPose_35_FaceR_CrouchTrans]   = false,

    [kPose_3D_FaceR_UnmorphTrans - kPose_35_FaceR_CrouchTrans] = true,
    [kPose_3E_FaceL_UnmorphTrans - kPose_35_FaceR_CrouchTrans] = true,
    [kPose_3F - kPose_35_FaceR_CrouchTrans]                    = true,
    [kPose_40 - kPose_35_FaceR_CrouchTrans]                    = true,
  };

  if (samus_pose >= kPose_F1_FaceR_CrouchTrans_AimU) {
    HudSelectionHandler_Normal();
  }
  else if (samus_pose > kPose_DA_FaceL_Xray_Crouch) {
    return;
  }
  else if (kPoseIsMorphTrans[samus_pose - kPose_35_FaceR_CrouchTrans]) {
    HudSelectionHandler_JumpEtc();
  }
  else {
    HudSelectionHandler_Normal();
  }
}

/**
* @brief Handle HUD selection for special movement types
*/
void HudSelectionHandler_JumpEtc(void) {  // 0x90DDB6
  if (grapple_beam_function != FUNC16(GrappleBeamFunc_Inactive)) {
    grapple_beam_function = FUNC16(GrappleBeamFunc_Cancel);
    HudSelectionHandler_Normal();
  }
}

/**
* @brief Handle HUD selection for xray
*/
void HudSelectionHandler_Xray(void) {  // 0x90DDC8
  if (joypad1_lastkeys & button_config_run)
    XrayRunHandler();
  else
    HudSelectionHandler_NothingOrPowerBombs();
}

/**
* @brief Handle HUD selection for grabbed by Draygon movement type
*/
void HudSelectionHandler_GrabbedByDraygon(void) {  // 0x90DDD8
  if (samus_pose == kPose_DF)
    HudSelectionHandler_MorphBall();
  else
    HudSelectionHandler_Normal();
}

static Func_U8 *const kSamusHitInterrupts[28] = {  // 0x90DDE9
  [kMovementType_00_Standing]                                             = Samus_HitInterrupt_Stand,
  [kMovementType_01_Running]                                              = Samus_HitInterrupt_Stand,
  [kMovementType_02_NormalJumping]                                        = Samus_HitInterrupt_Stand,
  [kMovementType_03_SpinJumping]                                          = Samus_HitInterrupt_Stand,
  [kMovementType_04_MorphBallOnGround]                                    = Samus_HitInterrupt_Ball,
  [kMovementType_05_Crouching]                                            = Samus_HitInterrupt_Stand,
  [kMovementType_06_Falling]                                              = Samus_HitInterrupt_Falling,
  [kMovementType_07_Unused]                                               = Samus_HitInterrupt_Unused,
  [kMovementType_08_MorphBallFalling]                                     = Samus_HitInterrupt_Ball,
  [kMovementType_09_Unused]                                               = Samus_HitInterrupt_Ball,
  [kMovementType_0A_KnockbackOrCrystalFlashEnding]                        = Samus_HitInterrupt_KnockbackGrapple,
  [kMovementType_0B_Unused]                                               = Samus_HitInterrupt_Turning,
  [kMovementType_0C_Unused]                                               = Samus_HitInterrupt_Turning,
  [kMovementType_0D_Unused]                                               = Samus_HitInterrupt_Stand,
  [kMovementType_0E_TurningAroundOnGround]                                = Samus_HitInterrupt_Turning,
  [kMovementType_0F_Crouch_Stand_Morph_Unmorph_Transition]                = Samus_HitInterrupt_Turning,
  [kMovementType_10_Moonwalking]                                          = Samus_HitInterrupt_Stand,
  [kMovementType_11_SpringBallOnGround]                                   = Samus_HitInterrupt_Ball,
  [kMovementType_12_SpringBallInAir]                                      = Samus_HitInterrupt_Ball,
  [kMovementType_13_SpringBallFalling]                                    = Samus_HitInterrupt_Ball,
  [kMovementType_14_WallJumping]                                          = Samus_HitInterrupt_Stand,
  [kMovementType_15_RanIntoWall]                                          = Samus_HitInterrupt_Stand,
  [kMovementType_16_Grappling]                                            = Samus_HitInterrupt_KnockbackGrapple,
  [kMovementType_17_TurningAroundJumping]                                 = Samus_HitInterrupt_Turning,
  [kMovementType_18_TurningAroundFalling]                                 = Samus_HitInterrupt_Turning,
  [kMovementType_19_DamageBoost]                                          = Samus_HitInterrupt_Turning,
  [kMovementType_1A_GrabbedByDraygon]                                     = Samus_HitInterrupt_Turning,
  [kMovementType_1B_Shinespark_CrystalFlash_Drained_DamagedByMotherBrain] = Samus_HitInterrupt_Drained,
};

/**
* @brief Handle setting Samus pose for hit interruption
*/
void Samus_HitInterruption(void) {
  if (samus_knockback_timer != 0) {
    if (debug_invincibility < 7) {
      if (!time_is_frozen_flag && knockback_dir == kKnockbackDir_None) {
        if (kSamusHitInterrupts[samus_movement_type]())
          samus_new_pose_interrupted_command = 1;
      }
    }
    else {
      samus_invincibility_timer = 0;
      samus_knockback_timer = 0;
    }
  }
  else if (knockback_dir != kKnockbackDir_None) {
    if (samus_movement_type == kMovementType_0A_KnockbackOrCrystalFlashEnding) {
      if (flare_counter >= 16)
        QueueSfx1_Max6(kSfx1_ResumeChargingBeam);
      if (samus_pose_x_dir == kSamusXDir_FaceLeft)
        samus_new_pose_transitional = kPose_2A_FaceL_Fall;
      else
        samus_new_pose_transitional = kPose_29_FaceR_Fall;
    }
    else {
      if (samus_new_pose_transitional_command == 3) {
        samus_new_pose_transitional_command = 8;
        return;
      }
      samus_new_pose_transitional = samus_pose;
    }
    samus_new_pose_transitional_command = 1;
  }
  else if (bomb_jump_dir != kBombJumpDir_None) {
    SetupBombJump();
  }
}

/**
* @brief Handle drained animation during hit interruption
* @return uint8 0, indicating no knockback
*/
uint8 Samus_HitInterrupt_Drained(void) {  // 0x90DEBA
  if (samus_pose == kPose_E8_FaceR_Drained_CrouchFalling || samus_pose == kPose_E9_FaceL_Drained_CrouchFalling) {
    samus_anim_frame_timer = 17;
    samus_anim_frame = 26;
  }
  samus_new_pose_interrupted_command = 0;
  knockback_dir = kKnockbackDir_None;
  return 0;
}

/**
* @brief Ignore animation during hit interruption
* @return uint8 0, indicating no knockback
*/
uint8 Samus_HitInterrupt_KnockbackGrapple(void) {  // 0x90DEDD
  samus_new_pose_interrupted_command = 0;
  return 0;
}

/**
* @brief Ignore animation during hit interruption and clear knockback
* @return uint8 0, indicating no knockback
*/
uint8 Samus_HitInterrupt_Turning(void) {  // 0x90DEE2
  samus_new_pose_interrupted_command = 0;
  knockback_dir = kKnockbackDir_None;
  return 0;
}

/**
* @brief Handle pose during hit interruption
* @brief uint8 1 if knockback enabled, 0 otherwise
*/
uint8 Samus_HitInterrupt_Falling(void) {  // 0x90DEEA
  if (frame_handler_gamma != FUNC16(Samus_FrameHandlerGamma_SpecialFalling_Unused))
    return Samus_HitInterrupt_Stand();
  samus_new_pose_interrupted_command = 0;
  knockback_dir = kKnockbackDir_None;
  return 0;
}

/**
* @brief Handle pose during hit interruption
* @brief uint8 1, indicating knockback enabled
*/
uint8 Samus_HitInterrupt_Stand(void) {  // 0x90DEFA
  if (samus_pose_x_dir == kSamusXDir_FaceLeft)
    samus_new_pose_interrupted = kPose_54_FaceL_Knockback;
  else
    samus_new_pose_interrupted = kPose_53_FaceR_Knockback;
  return 1;
}

/**
* @brief Handle pose during hit interruption
* @brief uint8 1, indicating knockback enabled
*/
uint8 Samus_HitInterrupt_Ball(void) {  // 0x90DF15
  samus_new_pose_interrupted = samus_pose;
  return 1;
}

uint8 Samus_HitInterrupt_Unused(void) {  // 0x90DF1D
  if (samus_pose_x_dir == kSamusXDir_FaceLeft)
    samus_new_pose_interrupted = kPose_34;
  else
    samus_new_pose_interrupted = kPose_33;
  return 1;
}

static Func_V *const kSamus_MoveHandler_Knockback[6] = {  // 0x90DF38
  [kKnockbackDir_None]      = Samus_MovementHandler_Invalid,
  [kKnockbackDir_UpLeft]    = Samus_MovementHandler_Knockback_Up,
  [kKnockbackDir_UpRight]   = Samus_MovementHandler_Knockback_Up,
  Samus_MovementHandler_Knockback_StraightUp_Unused,
  [kKnockbackDir_DownLeft]  = Samus_MovementHandler_Knockback_Down,
  [kKnockbackDir_DownRight] = Samus_MovementHandler_Knockback_Down,
};

/**
* @brief Handle Samus knockback movement
*/
void Samus_MovementHandler_Knockback(void) {
  kSamus_MoveHandler_Knockback[knockback_dir]();
  samus_solid_vertical_coll_result = kSolidVertCollResult_0_NoChange;
}

/**
* @brief Crash the game if entering without knockback
*/
void Samus_MovementHandler_Invalid(void) {  // 0x90DF50
  InvalidInterrupt_Crash();
}

/**
* @brief Handle Samus knockback upward movement
*/
void Samus_MovementHandler_Knockback_Up(void) {  // 0x90DF53
  Samus_MoveX_KnockbackOrBombJump();
  Samus_MoveY_WithSpeedCalc();
  Samus_HandleKnockbackVerticalColl();
}

void Samus_MovementHandler_Knockback_StraightUp_Unused(void) {  // 0x90DF5D
  Samus_MoveY_WithSpeedCalc();
  Samus_HandleKnockbackVerticalColl();
}

/**
* @brief Handle Samus knockback downward movement
*/
void Samus_MovementHandler_Knockback_Down(void) {  // 0x90DF64
  Samus_MoveX_KnockbackOrBombJump();
  Samus_Move_NoSpeedCalc_Y();
  Samus_HandleKnockbackVerticalColl();
}

/**
* @brief Handle vertical collision during knockback movement
*/
void Samus_HandleKnockbackVerticalColl(void) {  // 0x90DF6E
  if (samus_collision_flag) {
    samus_x_accel_mode = kSamusXAccelMode_0_Accelerate;
    samus_stopped_by_collision = 0;
    samus_is_falling_flag = 0;
    UNUSED_word_7E0B1A = 0;
    UNUSED_word_7E0B2A = 0;
    samus_y_subspeed = 0;
    samus_y_speed = 0;
    samus_y_dir = kSamusYDir_None;
    UNUSED_word_7E0B38 = 0;
    samus_x_base_speed = 0;
    samus_x_base_subspeed = 0;
    Samus_AlignBottomWithPrevPose();
  }
}

static Func_U8 *const kSetupBombJump[28] = {  // 0x90DF99
  [kMovementType_00_Standing]                                             = SetupBombJump_Stand_Crouch,
  [kMovementType_01_Running]                                              = SetupBombJump_Run_Fall_Moonwalk_WallJump_RanIntoWall_Grapple,
  [kMovementType_02_NormalJumping]                                        = SetupBombJump_Jump_TurnAround_DamageBoost_Transition,
  [kMovementType_03_SpinJumping]                                          = SetupBombJump_Jump_TurnAround_DamageBoost_Transition,
  [kMovementType_04_MorphBallOnGround]                                    = SetupBombJump_Morphed_Knockback_CrystalFlash,
  [kMovementType_05_Crouching]                                            = SetupBombJump_Stand_Crouch,
  [kMovementType_06_Falling]                                              = SetupBombJump_Run_Fall_Moonwalk_WallJump_RanIntoWall_Grapple,
  [kMovementType_07_Unused]                                               = SetupBombJump_Morphed_Knockback_CrystalFlash,
  [kMovementType_08_MorphBallFalling]                                     = SetupBombJump_Morphed_Knockback_CrystalFlash,
  [kMovementType_09_Unused]                                               = SetupBombJump_Morphed_Knockback_CrystalFlash,
  [kMovementType_0A_KnockbackOrCrystalFlashEnding]                        = SetupBombJump_Morphed_Knockback_CrystalFlash,
  [kMovementType_0B_Unused]                                               = SetupBombJump_Run_Fall_Moonwalk_WallJump_RanIntoWall_Grapple,
  [kMovementType_0C_Unused]                                               = SetupBombJump_Run_Fall_Moonwalk_WallJump_RanIntoWall_Grapple,
  [kMovementType_0D_Unused]                                               = SetupBombJump_Run_Fall_Moonwalk_WallJump_RanIntoWall_Grapple,
  [kMovementType_0E_TurningAroundOnGround]                                = SetupBombJump_Jump_TurnAround_DamageBoost_Transition,
  [kMovementType_0F_Crouch_Stand_Morph_Unmorph_Transition]                = SetupBombJump_Jump_TurnAround_DamageBoost_Transition,
  [kMovementType_10_Moonwalking]                                          = SetupBombJump_Run_Fall_Moonwalk_WallJump_RanIntoWall_Grapple,
  [kMovementType_11_SpringBallOnGround]                                   = SetupBombJump_Morphed_Knockback_CrystalFlash,
  [kMovementType_12_SpringBallInAir]                                      = SetupBombJump_Morphed_Knockback_CrystalFlash,
  [kMovementType_13_SpringBallFalling]                                    = SetupBombJump_Morphed_Knockback_CrystalFlash,
  [kMovementType_14_WallJumping]                                          = SetupBombJump_Run_Fall_Moonwalk_WallJump_RanIntoWall_Grapple,
  [kMovementType_15_RanIntoWall]                                          = SetupBombJump_Run_Fall_Moonwalk_WallJump_RanIntoWall_Grapple,
  [kMovementType_16_Grappling]                                            = SetupBombJump_Run_Fall_Moonwalk_WallJump_RanIntoWall_Grapple,
  [kMovementType_17_TurningAroundJumping]                                 = SetupBombJump_Jump_TurnAround_DamageBoost_Transition,
  [kMovementType_18_TurningAroundFalling]                                 = SetupBombJump_Jump_TurnAround_DamageBoost_Transition,
  [kMovementType_19_DamageBoost]                                          = SetupBombJump_Jump_TurnAround_DamageBoost_Transition,
  [kMovementType_1A_GrabbedByDraygon]                                     = SetupBombJump_Grabbed_Shinespark_CrystalFlash_Drained_MBAttack,
  [kMovementType_1B_Shinespark_CrystalFlash_Drained_DamagedByMotherBrain] = SetupBombJump_Grabbed_Shinespark_CrystalFlash_Drained_MBAttack,
};

/**
* @brief Set up a bomb jump when Samus is not already bomb jumping
*/
void SetupBombJump(void) {
  if (!(bomb_jump_dir & kBombJumpDir_Active)) {
    if (kSetupBombJump[samus_movement_type]())
      samus_new_pose_interrupted_command = 3;
  }
}

/**
* @brief Handle bomb jump during standing and crouching movement types
* @return uint8 1 if bomb jump started, 0 otherwise
*/
uint8 SetupBombJump_Stand_Crouch(void) {  // 0x90DFED
  if (!time_is_frozen_flag)
    return SetupBombJump_Run_Fall_Moonwalk_WallJump_RanIntoWall_Grapple();
  bomb_jump_dir = kBombJumpDir_None;
  return 0;
}

/**
* @brief Handle bomb jump during common movement types
* @return uint8 1, indicating a bomb jump started
*/
uint8 SetupBombJump_Run_Fall_Moonwalk_WallJump_RanIntoWall_Grapple(void) {  // 0x90DFF7
  if (samus_pose_x_dir == kSamusXDir_FaceLeft)
    samus_new_pose_interrupted = kPose_52_FaceL_Jump_NoAim_MoveF;
  else
    samus_new_pose_interrupted = kPose_51_FaceR_Jump_NoAim_MoveF;
  return 1;
}

/**
* @brief Handle bomb jump during special movement types
* @return uint8 1, indicating a bomb jump started
*/
uint8 SetupBombJump_Morphed_Knockback_CrystalFlash(void) {  // 0x90E012
  samus_new_pose_interrupted = samus_pose;
  return 1;
}

/**
* @brief Handle bomb jump during special movement types
* @return uint8 0, indicating a bomb jump has not started
*/
uint8 SetupBombJump_Jump_TurnAround_DamageBoost_Transition(void) {  // 0x90E01A
  samus_input_handler = FUNC16(Samus_InputHandler_Normal);
  return SetupBombJump_Grabbed_Shinespark_CrystalFlash_Drained_MBAttack();
}

/**
* @brief Handle bomb jump during special movement types
* @return uint8 0, indicating a bomb jump has not started
*/
uint8 SetupBombJump_Grabbed_Shinespark_CrystalFlash_Drained_MBAttack(void) {  // 0x90E020
  bomb_jump_dir = kBombJumpDir_None;
  return 0;
}

/**
* @brief Handle beginning of bomb jump
*/
void Samus_MovementHandler_BombJumpStart(void) {  // 0x90E025
  Samus_InitBombJump();
  samus_movement_handler = FUNC16(Samus_MovementHandler_BombJumpMain);
  samus_solid_vertical_coll_result = kSolidVertCollResult_0_NoChange;
}

static Func_V *const kSamus_MoveHandler_BombJumpMain[4] = {  // 0x90E032
  [kBombJumpDir_None]  = Samus_MovementHandler_Invalid,
  [kBombJumpDir_Left]  = Samus_MovementHandler_HorizontalBombJump,
  [kBombJumpDir_Up]    = Samus_MovementHandler_VerticalBombJump,
  [kBombJumpDir_Right] = Samus_MovementHandler_HorizontalBombJump,
};

/**
* @brief Handle the main phase of a bomb jump
*/
void Samus_MovementHandler_BombJumpMain(void) {
  if (bomb_jump_dir != kBombJumpDir_None)
    kSamus_MoveHandler_BombJumpMain[(uint8)bomb_jump_dir]();
  else
    Samus_MovementHandler_EndBombJump();
}

/**
* @brief Handle horizontal movement during bomb jump
*/
void Samus_MovementHandler_HorizontalBombJump(void) {  // 0x90E04C
  Samus_MoveX_KnockbackOrBombJump();
  Samus_BombJumpEnd();
  if (samus_y_dir == kSamusYDir_Down)
    Samus_MovementHandler_EndBombJump();
  else {
    Samus_MoveY_WithSpeedCalc();
    if (samus_collision_flag)
      Samus_MovementHandler_EndBombJump();
  }
}

/**
* @brief Handle vertical movement during bomb jump
*/
void Samus_MovementHandler_VerticalBombJump(void) {  // 0x90E066
  Samus_BombJumpEnd();
  if (samus_y_dir == kSamusYDir_Down)
    Samus_MovementHandler_EndBombJump();
  else {
    Samus_MoveY_WithSpeedCalc();
    if (samus_collision_flag)
      Samus_MovementHandler_EndBombJump();
  }
}

/**
* @brief Handle ending of a bomb jump
*/
void Samus_MovementHandler_EndBombJump(void) {  // 0x90E07D
  samus_movement_handler = FUNC16(Samus_MovementHandler_Normal);
  if (samus_input_handler != FUNC16(Samus_InputHandler_Demo))
    samus_input_handler = FUNC16(Samus_InputHandler_Normal);
  bomb_jump_dir = kBombJumpDir_None;
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

/**
* @brief Run hacks for Samus and timer
*/
void RunFrameHandlerGamma(void) {  // 0x90E097
  CallFrameHandlerGamma(frame_handler_gamma | 0x900000);
}

/**
* @brief Handle unlocking Samus from drained movement
*/
void Samus_FrameHandlerGamma_UnlockSamusFromDrained(void) {  // 0x90E09B
  if (samus_pose == kPose_E9_FaceL_Drained_CrouchFalling && samus_anim_frame >= 8 && (joypad1_newkeys & kButton_Up)) {
    samus_anim_frame_timer = 1;
    samus_anim_frame = 14 - 1;
    frame_handler_gamma = FUNC16(nullsub_152);
  }
}

/**
* @brief Handle keeping Samus locked during drained movement
*/
void Samus_FrameHandlerGamma_KeepSamusLockedFromDrained(void) {  // 0x90E0C5
  if (8 <= samus_anim_frame && samus_anim_frame < 12 && (joypad1_newkeys & kButton_Up)) {
    samus_anim_frame_timer = 1;
    samus_anim_frame = 19 - 1;
  }
}

/**
* @brief Handle drawing timer and palettes
*/
void Samus_FrameHandlerGamma_HandleTimer(void) {  // 0x90E0E6
  if (ProcessTimer()) {
    game_state = kGameState_35_TimeUp;
    // Make screen white
    memset7E(target_palettes.pal, 0x7FFF, sizeof(Palettes));
    frame_handler_gamma = FUNC16(Samus_FrameHandlerGamma_DrawTimer);
    DisablePaletteFx();
  }
  if (timer_status != kTimerStatus_0_Inactive)
    DrawTimer();
}

/**
* @brief Draw the timer text
*/
void Samus_FrameHandlerGamma_DrawTimer(void) {  // 0x90E114
  DrawTimer();
}

/**
* @brief Set Samus to push out of Ridley's way
*/
void Samus_SetPushedOutOfCeresRidley(void) {  // 0x90E119
  samus_movement_handler = FUNC16(nullsub_152);
  frame_handler_gamma = FUNC16(Samus_FrameHandlerGamma_PushOutOfRidleysWay);
}

/**
* @brief Handle pushing Samus out of Ridley's way
*/
void Samus_FrameHandlerGamma_PushOutOfRidleysWay(void) {  // 0x90E12E
  if (samus_pose_x_dir == kSamusXDir_FaceLeft)
    samus_pose = kPose_54_FaceL_Knockback;
  else
    samus_pose = kPose_53_FaceR_Knockback;

  SamusFunc_F433();
  Samus_SetAnimationFrameIfPoseChanged();
  samus_last_different_pose = samus_prev_pose;
  samus_last_different_pose_x_dir = samus_prev_pose_x_dir;
  samus_last_different_pose_movement_type = samus_prev_movement_type;
  samus_prev_pose = samus_pose;
  samus_prev_pose_x_dir = samus_pose_x_dir;
  samus_prev_movement_type = samus_movement_type;
  samus_y_pos -= 21 - samus_y_radius;
  if ((int16)(samus_x_pos - layer1_x_pos) < (8*16))
    samus_push_direction = kSamusPushDirection_Left;
  else
    samus_push_direction = kSamusPushDirection_Right;
  samus_y_speed = 5;
  samus_y_subspeed = 0;
  bomb_jump_dir = kBombJumpDir_None;
  frame_handler_gamma = FUNC16(Samus_FrameHandlerGamma_PushingOutOfRidleysWay);
  samus_new_pose = -1;
  samus_new_pose_interrupted = -1;
  samus_new_pose_transitional = -1;
  samus_new_pose_command = 0;
  samus_new_pose_interrupted_command = 0;
  samus_new_pose_transitional_command = 0;
  ProcessTimer();
  if (timer_status != kTimerStatus_0_Inactive)
    DrawTimer();
}

/**
* @brief Handle pushing Samus to the left or right of Ridley's way
*/
void Samus_FrameHandlerGamma_PushingOutOfRidleysWay(void) {  // 0x90E1C8
  static Func_V *const kSamus_PushOutOfRidleysWay_Func[3] = {
    [kSamusPushDirection_None]  = 0,  // Warning: NULL function pointer
    [kSamusPushDirection_Left]  = Samus_PushOutOfRidleysWay_Leftwards,
    [kSamusPushDirection_Right] = Samus_PushOutOfRidleysWay_Rightwards,
  };

  if (samus_new_pose == kPose_4F_FaceL_Dmgboost || samus_new_pose == kPose_50_FaceR_Dmgboost) {
    samus_new_pose = -1;
    samus_new_pose_command = 0;
  }
  kSamus_PushOutOfRidleysWay_Func[samus_push_direction]();
  samus_solid_vertical_coll_result = kSolidVertCollResult_0_NoChange;
  ProcessTimer();
  if (timer_status != kTimerStatus_0_Inactive)
    DrawTimer();
}

/**
* @brief Handle pushing Samus to the left of Ridley's way
*/
void Samus_PushOutOfRidleysWay_Leftwards(void) {  // 0x90E1FD
  Samus_MoveX_CeresRidleyPush();
  if (samus_collision_flag) {
    samus_movement_handler = FUNC16(Samus_MovementHandler_Normal);
    frame_handler_gamma = FUNC16(Samus_FrameHandlerGamma_HandleTimer);
    samus_push_direction = kSamusPushDirection_None;
    Samus_HandleKnockbackVerticalColl();
  }
  else {
    Samus_MoveY_CeresRidleyPush();
  }
}

/**
* @brief Handle pushing Samus to the right of Ridley's way
*/
void Samus_PushOutOfRidleysWay_Rightwards(void) {  // 0x90E21C
  Samus_MoveX_CeresRidleyPush();
  if (samus_collision_flag) {
    samus_movement_handler = FUNC16(Samus_MovementHandler_Normal);
    frame_handler_gamma = FUNC16(Samus_FrameHandlerGamma_HandleTimer);
    samus_push_direction = kSamusPushDirection_None;
    Samus_HandleKnockbackVerticalColl();
  }
  else {
    Samus_MoveY_CeresRidleyPush();
  }
}

/**
* @brief Handle button presses during Draygon grab
*/
void Samus_FrameHandlerGamma_GrabbedByDraygon(void) {  // 0x90E2A1
  if (grapple_beam_function == FUNC16(GrappleBeamFunc_ConnectedLockedInPlace)) {
    samus_new_pose = -1;
    samus_new_pose_command = 0;
  }
  uint16 dpad_buttons_pressed = joypad1_newkeys & (kButton_Up | kButton_Down | kButton_Left | kButton_Right);
  if (dpad_buttons_pressed && dpad_buttons_pressed != draygon_escape_prev_dpad_input) {
    draygon_escape_prev_dpad_input = dpad_buttons_pressed;
    if ((int16)++draygon_escape_button_counter >= 60)
      Samus_ReleaseFromDraygon();
  }
}

/**
* @brief Set Samus poses when grabbed by Draygon
* @param draygon_dir Direction Draygon is facing while grabbing Samus, 0 = left, 1 = right
*/
void Samus_SetGrabbedByDraygonPose(uint16 draygon_dir) {  // 0x90E23B
  if (draygon_dir & 1)
    samus_pose = kPose_EC_FaceR_Draygon_NoMove_NoAim;
  else
    samus_pose = kPose_BA_FaceL_Draygon_NoMove_NoAim;

  SamusFunc_F433();
  Samus_SetAnimationFrameIfPoseChanged();
  frame_handler_gamma = FUNC16(Samus_FrameHandlerGamma_GrabbedByDraygon);
  samus_movement_handler = FUNC16(nullsub_152);

  draygon_escape_button_counter = 0;
  draygon_escape_prev_dpad_input = 0;
  WORD(suit_pickup_color_math_R) = 0;

  samus_last_different_pose = samus_prev_pose;
  samus_last_different_pose_x_dir = samus_prev_pose_x_dir;
  samus_last_different_pose_movement_type = samus_prev_movement_type;

  samus_prev_pose = samus_pose;
  samus_prev_pose_x_dir = samus_pose_x_dir;
  samus_prev_movement_type = samus_movement_type;

  samus_new_pose = -1;
  samus_new_pose_interrupted = -1;
  samus_new_pose_transitional = -1;

  samus_new_pose_command = 0;
  samus_new_pose_interrupted_command = 0;
  samus_new_pose_transitional_command = 0;
}

/**
* @brief Handle releasing Samus from Draygon grab
*/
void Samus_ReleaseFromDraygon_(void) {  // 0x90E2D4
  Samus_ReleaseFromDraygon();
}

/**
* @brief Handle releasing Samus from Draygon grab
*/
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
  samus_last_different_pose_x_dir = samus_prev_pose_x_dir;
  samus_last_different_pose_movement_type = samus_prev_movement_type;

  samus_prev_pose = samus_pose;
  samus_prev_pose_x_dir = samus_pose_x_dir;
  samus_prev_movement_type = samus_movement_type;

  samus_x_base_speed = 0;
  samus_x_base_subspeed = 0;

  samus_new_pose = -1;
  samus_new_pose_interrupted = -1;
  samus_new_pose_transitional = -1;

  samus_new_pose_command = 0;
  samus_new_pose_interrupted_command = 0;
  samus_new_pose_transitional_command = 0;

  samus_y_speed = 0;
  samus_y_subspeed = 0;
  samus_y_dir = kSamusYDir_None;
  morph_ball_bounce_state = kMorphBallBounceState_NoBounce;
  samus_x_accel_mode = kSamusXAccelMode_0_Accelerate;
  samus_grapple_flags = samus_grapple_flags & 0xFFFD | 2;
}

void Samus_FrameHandlerGamma_PushMorphedSamusOutOfRidleysWay_Unused(void) {  // 0x90E3A3
  Samus_MoveX_CeresRidleyPush();
  if (samus_collision_flag || (Samus_MoveY_CeresRidleyPush(), samus_collision_flag)) {
    samus_movement_handler = FUNC16(Samus_MovementHandler_Normal);
    frame_handler_gamma = FUNC16(nullsub_152);
    samus_push_direction = kSamusPushDirection_None;
    Samus_HandleKnockbackVerticalColl();
    samus_new_pose_interrupted = kPose_41_FaceL_Morphball_Ground;
    samus_new_pose_interrupted_command = 0;
  }
}

void Samus_ClearSpecialFalling_Unused(void) {  // 0x90E400
  samus_y_subspeed = 0;
  samus_y_speed = 0;
  samus_movement_handler = FUNC16(Samus_MovementHandler_Normal);
  frame_handler_gamma = FUNC16(nullsub_152);
}

void Samus_FrameHandlerGamma_SpecialFalling_Unused(void) {  // 0x90E41B
  if ((int16)samus_y_speed < 5)
    AddToHiLo(&samus_y_speed, &samus_y_subspeed, __PAIR32__(samus_y_accel, samus_y_subaccel));
  if ((samus_pose == kPose_29_FaceR_Fall || samus_pose == kPose_2A_FaceL_Fall
       || samus_pose == kPose_67_FaceR_Fall_Gun || samus_pose == kPose_68_FaceL_Fall_Gun)
      && (int16)samus_y_speed >= 5) {
    samus_anim_frame_timer = 16;
    samus_anim_frame = 4;
  }
}

/**
* @brief Clamps Samus speed between -15 and 15
* @param x_speed Samus X speed
* @return int32 Samus clamped X speed
*/
static int32 Samus_ClampSpeed(int32 x_speed) {
  int16 x_whole_speed = HIWORD(x_speed), x_subspeed = LOWORD(x_speed);
  if (x_whole_speed < -15)
    x_whole_speed = -15;
  else if (x_whole_speed > 15)
    x_whole_speed = 15;
  return IPAIR32(x_whole_speed, x_subspeed);
}

/**
* @brief Calculate Samus X displacement for moving left
* @param x_base_speed Samus X base speed
* @return int32 Samus clamped X displacement 
*/
int32 Samus_CalcDisplacementMoveLeft(int32 x_base_speed) {  // 0x90E464
  int32 x_speed = Samus_CalcSpeed_X(x_base_speed);
  samus_collision_direction = kSamusCollDir_0_Left;
  x_speed = __PAIR32__(extra_samus_x_displacement, extra_samus_x_subdisplacement) - x_speed;
  return Samus_ClampSpeed(x_speed);
}

/**
* @brief Calculate Samus X displacement for moving right
* @param x_base_speed Samus X base speed
* @return int32 Samus clamped X displacement
*/
int32 Samus_CalcDisplacementMoveRight(int32 x_base_speed) {  // 0x90E4AD
  int32 x_speed = Samus_CalcSpeed_X(x_base_speed);
  samus_collision_direction = kSamusCollDir_1_Right;
  x_speed += __PAIR32__(extra_samus_x_displacement, extra_samus_x_subdisplacement);
  return Samus_ClampSpeed(x_speed);
}

/**
* @brief Calculate Samus X speed
* @param x_base_speed Samus X base speed
* @return int32 Samus X speed
*/
uint32 Samus_CalcSpeed_X(uint32 x_base_speed) {  // 0x90E4E6
  uint32 x_speed = x_base_speed + __PAIR32__(samus_x_extra_run_speed, samus_x_extra_run_subspeed);
  x_speed >>= IntMin(4, samus_x_speed_divisor);
  SetHiLo(&samus_total_x_speed, &samus_total_x_subspeed, x_speed);
  return x_speed;
}

/**
* @brief Clear Samus X speed if Samus collision happened
*/
void Samus_ClearXSpeedIfColl(void) {  // 0x90E5CE
  if (samus_collision_flag) {
    if (samus_collision_direction != kSamusCollDir_0_Left)
      samus_stopped_by_collision = 8;
    else
      samus_stopped_by_collision = 4;

    Samus_CancelSpeedBoost();
    samus_x_extra_run_speed = 0;
    samus_x_extra_run_subspeed = 0;
    samus_x_base_speed = 0;
    samus_x_base_subspeed = 0;
    samus_x_accel_mode = kSamusXAccelMode_0_Accelerate;
  }
  else {
    samus_solid_vertical_coll_result = kSolidVertCollResult_0_NoChange;
    samus_stopped_by_collision = 0;
  }
}

/**
* @brief Set Samus solid vertical collision when moving up
*/
void Samus_MoveUp_SetPoseCalcInput(void) {  // 0x90E606
  if (samus_collision_flag)
    samus_solid_vertical_coll_result = kSolidVertCollResult_4_HitCeiling;
  else
    samus_solid_vertical_coll_result = kSolidVertCollResult_0_NoChange;
}

static const uint8 kSamus_SolidVerticalCollResult_Falling[28] = {  // 0x90E61B
  [kMovementType_00_Standing]                                             = kDownwardCollResult_Falling_0_Airborne,
  [kMovementType_01_Running]                                              = kDownwardCollResult_Falling_0_Airborne,
  [kMovementType_02_NormalJumping]                                        = kDownwardCollResult_Falling_4_NoChange,
  [kMovementType_03_SpinJumping]                                          = kDownwardCollResult_Falling_4_NoChange,
  [kMovementType_04_MorphBallOnGround]                                    = kDownwardCollResult_Falling_1_MorphAirborne,
  [kMovementType_05_Crouching]                                            = kDownwardCollResult_Falling_0_Airborne,
  [kMovementType_06_Falling]                                              = kDownwardCollResult_Falling_4_NoChange,
  [kMovementType_07_Unused]                                               = kDownwardCollResult_Falling_2_Unused,
  [kMovementType_08_MorphBallFalling]                                     = kDownwardCollResult_Falling_4_NoChange,
  [kMovementType_09_Unused]                                               = kDownwardCollResult_Falling_4_NoChange,
  [kMovementType_0A_KnockbackOrCrystalFlashEnding]                        = kDownwardCollResult_Falling_0_Airborne,
  [kMovementType_0B_Unused]                                               = kDownwardCollResult_Falling_0_Airborne,
  [kMovementType_0C_Unused]                                               = kDownwardCollResult_Falling_0_Airborne,
  [kMovementType_0D_Unused]                                               = kDownwardCollResult_Falling_0_Airborne,
  [kMovementType_0E_TurningAroundOnGround]                                = kDownwardCollResult_Falling_4_NoChange,
  [kMovementType_0F_Crouch_Stand_Morph_Unmorph_Transition]                = kDownwardCollResult_Falling_4_NoChange,
  [kMovementType_10_Moonwalking]                                          = kDownwardCollResult_Falling_0_Airborne,
  [kMovementType_11_SpringBallOnGround]                                   = kDownwardCollResult_Falling_3_SpringAirborne,
  [kMovementType_12_SpringBallInAir]                                      = kDownwardCollResult_Falling_4_NoChange,
  [kMovementType_13_SpringBallFalling]                                    = kDownwardCollResult_Falling_4_NoChange,
  [kMovementType_14_WallJumping]                                          = kDownwardCollResult_Falling_4_NoChange,
  [kMovementType_15_RanIntoWall]                                          = kDownwardCollResult_Falling_0_Airborne,
  [kMovementType_16_Grappling]                                            = kDownwardCollResult_Falling_4_NoChange,
  [kMovementType_17_TurningAroundJumping]                                 = kDownwardCollResult_Falling_4_NoChange,
  [kMovementType_18_TurningAroundFalling]                                 = kDownwardCollResult_Falling_4_NoChange,
  [kMovementType_19_DamageBoost]                                          = kDownwardCollResult_Falling_4_NoChange,
  [kMovementType_1A_GrabbedByDraygon]                                     = kDownwardCollResult_Falling_4_NoChange,
  [kMovementType_1B_Shinespark_CrystalFlash_Drained_DamagedByMotherBrain] = kDownwardCollResult_Falling_4_NoChange,
};
static const uint8 kSamus_SolidVerticalCollResult_Landed[28] = {
  [kMovementType_00_Standing]                                             = kDownwardCollResult_Landed_4_NoChange,
  [kMovementType_01_Running]                                              = kDownwardCollResult_Landed_4_NoChange,
  [kMovementType_02_NormalJumping]                                        = kDownwardCollResult_Landed_0_Grounded,
  [kMovementType_03_SpinJumping]                                          = kDownwardCollResult_Landed_0_Grounded,
  [kMovementType_04_MorphBallOnGround]                                    = kDownwardCollResult_Landed_4_NoChange,
  [kMovementType_05_Crouching]                                            = kDownwardCollResult_Landed_4_NoChange,
  [kMovementType_06_Falling]                                              = kDownwardCollResult_Landed_0_Grounded,
  [kMovementType_07_Unused]                                               = kDownwardCollResult_Landed_4_NoChange,
  [kMovementType_08_MorphBallFalling]                                     = kDownwardCollResult_Landed_1_MorphGrounded,
  [kMovementType_09_Unused]                                               = kDownwardCollResult_Landed_2_Unused,
  [kMovementType_0A_KnockbackOrCrystalFlashEnding]                        = kDownwardCollResult_Landed_0_Grounded,
  [kMovementType_0B_Unused]                                               = kDownwardCollResult_Landed_4_NoChange,
  [kMovementType_0C_Unused]                                               = kDownwardCollResult_Landed_4_NoChange,
  [kMovementType_0D_Unused]                                               = kDownwardCollResult_Landed_0_Grounded,
  [kMovementType_0E_TurningAroundOnGround]                                = kDownwardCollResult_Landed_4_NoChange,
  [kMovementType_0F_Crouch_Stand_Morph_Unmorph_Transition]                = kDownwardCollResult_Landed_4_NoChange,
  [kMovementType_10_Moonwalking]                                          = kDownwardCollResult_Landed_4_NoChange,
  [kMovementType_11_SpringBallOnGround]                                   = kDownwardCollResult_Landed_4_NoChange,
  [kMovementType_12_SpringBallInAir]                                      = kDownwardCollResult_Landed_3_SpringGrounded,
  [kMovementType_13_SpringBallFalling]                                    = kDownwardCollResult_Landed_3_SpringGrounded,
  [kMovementType_14_WallJumping]                                          = kDownwardCollResult_Landed_0_Grounded,
  [kMovementType_15_RanIntoWall]                                          = kDownwardCollResult_Landed_4_NoChange,
  [kMovementType_16_Grappling]                                            = kDownwardCollResult_Landed_4_NoChange,
  [kMovementType_17_TurningAroundJumping]                                 = kDownwardCollResult_Landed_4_NoChange,
  [kMovementType_18_TurningAroundFalling]                                 = kDownwardCollResult_Landed_4_NoChange,
  [kMovementType_19_DamageBoost]                                          = kDownwardCollResult_Landed_0_Grounded,
  [kMovementType_1A_GrabbedByDraygon]                                     = kDownwardCollResult_Landed_4_NoChange,
  [kMovementType_1B_Shinespark_CrystalFlash_Drained_DamagedByMotherBrain] = kDownwardCollResult_Landed_4_NoChange,
};

/**
* @brief Set Samus solid vertical collision when moving down
*/
void Samus_MoveDown_SetPoseCalcInput(void) {
  if (samus_collision_flag) {
    samus_solid_vertical_coll_result = kSolidVertCollResult_1_Landed;
    HIBYTE(samus_solid_vertical_coll_result) = kSamus_SolidVerticalCollResult_Landed[samus_movement_type];
  }
  else if (LOBYTE(samus_solid_vertical_coll_result) != kSolidVertCollResult_5_WallJumped) {
    samus_solid_vertical_coll_result = kSolidVertCollResult_2_Falling;
    HIBYTE(samus_solid_vertical_coll_result) = kSamus_SolidVerticalCollResult_Falling[samus_movement_type];
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

/**
* @brief Handle Samus current state
*/
void HandleControllerInputForGamePhysics(void) {  // 0x90E692
  CallFrameHandlerAlfa(frame_handler_alfa | 0x900000);
}

/**
* @brief Handle Samus current normal state
*/
void Samus_FrameHandlerAlfa_Normal(void) {  // 0x90E695
  samus_new_pose = -1;
  samus_new_pose_interrupted = -1;
  samus_new_pose_transitional = -1;

  samus_new_pose_command = 0;
  samus_new_pose_interrupted_command = 0;
  samus_new_pose_transitional_command = 0;

  Samus_SetRadius();
  Samus_CallInputHandler();
  Samus_UpdateSuitPaletteIndex();
  Samus_DetermineAccel_Y();
  BlockInsideDetection();
  Samus_HandleHudSpecificBehaviorAndProjs();
  Samus_ClearMovement_ResetPoseChanges();
}

/**
* @brief Handle Samus current demo state
*/
void Samus_FrameHandlerAlfa_Demo(void) {  // 0x90E6C9
  samus_new_pose = -1;
  samus_new_pose_interrupted = -1;
  samus_new_pose_transitional = -1;

  samus_new_pose_command = 0;
  samus_new_pose_interrupted_command = 0;
  samus_new_pose_transitional_command = 0;

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
  Samus_ClearMovement_ResetPoseChanges();
}

/**
* @brief Handle Samus current locked state
*/
void Samus_FrameHandlerAlfa_SamusLocked(void) {  // 0x90E713
  HandleProjectiles();
  Samus_ClearMovement_ResetPoseChanges();
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

/**
* @brief Handle Samus new state
*/
void HandleSamusMovementAndPause(void) {  // 0x90E722
  CallFrameHandlerBeta(frame_handler_beta | 0x900000);
}

/**
* @brief Handle Samus new normal state
*/
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

/**
* @brief Handle debug mode Samus placement mode toggles
*/
void HandleSamusPlacementModeToggles(void) {  // 0x90E786
  if (!(joypad2_new_keys & kButton_B)) {
    if (!debug_flag && (joypad2_new_keys & kButton_A)) {
      DisableEprojs();
      time_is_frozen_flag = 1;
      frame_handler_alfa = FUNC16(Samus_FrameHandlerBeta_DoNothing);
      frame_handler_beta = FUNC16(Samus_FrameHandlerBeta_Debug);
    }
  }
  else if (debug_flag) {
    samus_draw_handler = FUNC16(nullsub_152);
    debug_flag = 0;
  }
  else {
    debug_flag = 1;
    samus_draw_handler = FUNC16(Samus_DrawHandler_Default);
  }
}

/**
* @brief Handle Samus new debug state
*/
void Samus_FrameHandlerBeta_Debug(void) {  // 0x90E7D2
  if (joypad2_new_keys & kButton_A) {
    frame_handler_alfa = FUNC16(Samus_FrameHandlerAlfa_Normal);
    frame_handler_beta = FUNC16(Samus_FrameHandlerBeta_Normal);
    EnableEprojs();
    time_is_frozen_flag = 0;
  }
}

/**
* @brief Handle Samus new title demo state
*/
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

/**
* @brief Handle Samus new title intro state
*/
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

/**
* @brief Handle Samus new appear state
*/
void Samus_FrameHandlerBeta_SamusAppears(void) {  // 0x90E86A
  Samus_SetRadius();
  UpdateMinimap();
  Samus_Animate();
  elevator_status = kElevatorStatus_Inactive;
  samus_prev_y_pos = samus_y_pos;
  if (PlaySamusFanfare()) {
    if (debug_invincibility < 7 || !(joypad2_last & kButton_B))
      debug_invincibility = 0;
    frame_handler_alfa = FUNC16(Samus_FrameHandlerAlfa_Normal);
    frame_handler_beta = FUNC16(Samus_FrameHandlerBeta_Normal);
  }
}

/**
* @brief Handle Samus new Ceres state and Ceres timer
*/
void Samus_FrameHandlerBeta_Ceres(void) {  // 0x90E8AA
  Samus_FrameHandlerBeta_Normal();
  if (frame_handler_gamma == FUNC16(Samus_FrameHandlerGamma_DrawTimer) && game_state != kGameState_35_TimeUp)
    game_state = kGameState_35_TimeUp;
}

/**
* @brief Handle Samus new locked state
*/
void Samus_FrameHandlerBeta_SamusLocked(void) {  // 0x90E8DC
  samus_contact_damage_index = kSamusContactDamageIndex_0_Normal;
  UpdateMinimap();
}

/**
* @brief Handle Samus new riding elevator state
*/
void Samus_FrameHandlerBeta_RidingElevator(void) {  // 0x90E8EC
  samus_contact_damage_index = kSamusContactDamageIndex_0_Normal;
  RunSamusMovementHandler();
  UpdateMinimap();
  Samus_Animate();
}

/**
* @brief Handle Samus new enter/exit gunship state
*/
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

/**
* @brief Handle Samus pose input
*/
void Samus_CallInputHandler(void) {  // 0x90E90F
  CallSamusInputHandler(samus_input_handler | 0x900000);
}

/**
* @brief Handle Samus normal pose input
*/
void Samus_InputHandler_Normal(void) {  // 0x90E913
  Samus_InputHandler();
}

/**
* @brief Handle Samus xray pose input
*/
void Samus_InputHandler_Xray(void) {  // 0x90E918
  XraySamusPostInputHandler();
}

/**
* @brief Handle Samus demo pose input
*/
void Samus_InputHandler_Demo(void) {  // 0x90E91D
  DemoObjectInputHandler();
  Samus_InputHandler();
}

/**
* @brief Handle Samus auto-jump pose input
*/
void Samus_InputHandler_AutoJump(void) {  // 0x90E926
  uint16 joypad1_newkeys_backup = joypad1_newkeys;
  if (autojump_timer != 0 && autojump_timer < 9) {
    joypad1_newkeys |= button_config_jump;
    autojump_timer = 0;
  }
  Samus_InputHandler();
  joypad1_newkeys = joypad1_newkeys_backup;
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
  case fnSamus_MovementHandler_CrystalFlashStart: Samus_MovementHandler_CrystalFlashStart(); return;
  case fnSamus_MovementHandler_CrystalFlashMain: Samus_MovementHandler_CrystalFlashMain(); return;
  case fnSamus_MovementHandler_CrystalFlashFinish: Samus_MovementHandler_CrystalFlashFinish(); return;
  case fnSamus_MovementHandler_Knockback: Samus_MovementHandler_Knockback(); return;
  case fnSamus_MovementHandler_Invalid: Samus_MovementHandler_Invalid(); return;
  case fnSamus_MovementHandler_Knockback_Up: Samus_MovementHandler_Knockback_Up(); return;
  case fnSamus_MovementHandler_Knockback_StraightUp_Unused: Samus_MovementHandler_Knockback_StraightUp_Unused(); return;
  case fnSamus_MovementHandler_Knockback_Down: Samus_MovementHandler_Knockback_Down(); return;
  case fnSamus_MovementHandler_BombJumpStart: Samus_MovementHandler_BombJumpStart(); return;
  case fnSamus_MovementHandler_BombJumpMain: Samus_MovementHandler_BombJumpMain(); return;
  case fnSamus_MovementHandler_EndBombJump: Samus_MovementHandler_EndBombJump(); return;
  case fnnullsub_152: return;
  case fnSamus_MovementHandler_Xray: Samus_MovementHandler_Xray(); return;
  case fnSamus_MovementHandler_F04B_Unused: Samus_MovementHandler_F04B_Unused(); return;
  case fnSamus_MovementHandler_F072_Unused: Samus_MovementHandler_F072_Unused(); return;
  default: Unreachable();
  }
}

/**
* @brief Handle Samus movement
*/
void RunSamusMovementHandler(void) {  // 0x90E94B
  CallSamusMovementHandler(samus_movement_handler | 0x900000);
}

/**
* @brief Handle Samus xray movement
*/
void Samus_MovementHandler_Xray(void) {  // 0x90E94F
  uint16 anim_frame;
  if (samus_movement_type != kMovementType_0E_TurningAroundOnGround) {
    samus_anim_frame_timer = 15;
    if (samus_pose_x_dir == kSamusXDir_FaceLeft) {
      if (xray_angle < (150+3)) {
        anim_frame = 4;
      }
      else if (xray_angle < (175+3)) {
        anim_frame = 3;
      }
      else if (xray_angle < (200+3)) {
        anim_frame = 2;
      }
      else if (xray_angle < (225+3)) {
        anim_frame = 1;
      }
      else {
        anim_frame = 0;
      }
    }
    else if (xray_angle < 25) {
      anim_frame = 0;
    }
    else if (xray_angle < 50) {
      anim_frame = 1;
    }
    else if (xray_angle < 75) {
      anim_frame = 2;
    }
    else if (xray_angle < 100) {
      anim_frame = 3;
    }
    else {
      anim_frame = 4;
    }
    samus_anim_frame = anim_frame;
  }
}

/**
* @brief Handle giving periodic damage to Samus based on suit
*/
void Samus_HandlePeriodicDamage(void) {  // 0x90E9CE
  if (time_is_frozen_flag) {
    samus_periodic_damage = samus_periodic_subdamage = 0;
    return;
  }

  int32 periodic_damage = __PAIR32__(samus_periodic_damage, samus_periodic_subdamage);
  if (periodic_damage < 0) {
    InvalidInterrupt_Crash();
    return;
  }
  // Clear high byte of perodic damage and low byte of periodic subdamage
  if (equipped_items & kItem_GravitySuit)
    periodic_damage = (periodic_damage / 4) & 0x00ffff00;
  else if (equipped_items & kItem_VariaSuit)
    periodic_damage = (periodic_damage / 2) & 0x00ffff00;
  AddToHiLo(&samus_health, &samus_subunit_health, -periodic_damage);
  if ((int16)samus_health < 0)
    samus_health = samus_subunit_health = 0;
  samus_periodic_damage = samus_periodic_subdamage = 0;
}

/**
* @brief Check and handle pausing
*/
void Samus_PauseCheck(void) {  // 0x90EA45
  if (!power_bomb_flag && !time_is_frozen_flag && !door_transition_flag_enemies && area_index != kArea_6_Ceres
      && game_state == kGameState_8_MainGameplay && (joypad1_newkeys & kButton_Start)) {
    screen_fade_delay = 1;
    screen_fade_counter = 1;
    game_state = kGameState_12_Pausing;
  }
}

/**
* @brief Check for low Samus health and handle low health beep
*/
void Samus_LowHealthCheck_(void) {  // 0x90EA7F
  if ((int16)samus_health <= 30) {
    if (!samus_health_warning) {
      QueueSfx3_Max6(kSfx3_LowHealthBeep);
      samus_health_warning = true;
    }
  }
  else if (samus_health_warning) {
    samus_health_warning = false;
    QueueSfx3_Max6(kSfx3_Silence);
  }
}

/**
* @brief Check for low Samus health and handle low health beep
*/
void Samus_LowHealthCheck_0(void) {  // 0x90EAAB
  Samus_LowHealthCheck_();
}

/**
* @brief Handle auto-jump timer, previous input, health flash counter, health
*/
void Samus_AutoJump_HurtFlash_PreviousInput_Handler(void) {  // 0x90EAB3
  if ((joypad1_lastkeys & button_config_jump) && (joypad1_input_samusfilter & button_config_jump))
    ++autojump_timer;
  else
    autojump_timer = 0;
  joypad1_input_samusfilter = joypad1_lastkeys;
  joypad1_newinput_samusfilter = joypad1_newkeys;

  if ((int16)samus_health < (int16)samus_prev_health_for_flash) {
    if (samus_hurt_flash_counter == 0)
      samus_hurt_flash_counter = 1;
    if (debug_invincibility >= 7) {
      samus_health = samus_prev_health_for_flash;
      return;
    }
  }
  samus_prev_health_for_flash = samus_health;

}

/**
* @brief Clear movement and reset pose changes
*/
void Samus_ClearMovement_ResetPoseChanges(void) {  // 0x90EB02
  distance_samus_moved_left = 0;
  distance_samus_moved_left_fract = 0;
  distance_samus_moved_right = 0;
  distance_samus_moved_right_fract = 0;
  distance_samus_moved_up = 0;
  distance_samus_moved_up_fract = 0;
  distance_samus_moved_down = 0;
  distance_samus_moved_down_fract = 0;
  samus_anim_frame_skip = 0;
  new_projectile_direction_changed_pose = 0;
  UNUSED_word_7E0DFA <<= 8;
  UNUSED_samus_prev_pose_x_dir = samus_pose_x_dir;
  samus_prev_movement_type_ = samus_movement_type;
}

/**
* @brief Draw Samus sprites and projectiles, handle auto-jump timer, previous input, health flash counter,
* health, unspin sfx, echoes sfx, charge sfx, Ceres time up state
* 
*/
void DrawSamusAndProjectiles(void) {  // 0x90EB35
  DrawSamusSprites();
  DrawProjectiles();
  Samus_AutoJump_HurtFlash_PreviousInput_Handler();
  Samus_ShootCheck();
}

void CallSamusDrawHandler(uint32 ea) {
  switch (ea) {
  case fnSamus_DrawHandler_Default: Samus_DrawHandler_Default(); return;
  case fnSamus_DrawHandler_NoChargeOrGrapple: Samus_DrawHandler_NoChargeOrGrapple(); return;
  case fnnullsub_152:
  case fnnullsub_156: return;
  case fnSamus_DrawHandler_EndOfShinespark: Samus_DrawHandler_EndOfShinespark(); return;
  case fnSamus_DisplayHandler_UsingElevator: Samus_DisplayHandler_UsingElevator(); return;
  case fnSamus_DisplayHandler_InanimateSamus: Samus_DisplayHandler_InanimateSamus(); return;
  default: Unreachable();
  }
}

/**
* @brief Handle arm cannon state and drawing Samus
*/
void DrawSamusSprites(void) {  // 0x90EB4B
  HandleArmCannonOpenState();
  CallSamusDrawHandler(samus_draw_handler | 0x900000);
}

/**
* @brief Handle Samus default drawing
*/
void Samus_DrawHandler_Default(void) {  // 0x90EB52
  HandleChargingBeamGfxAudio();
  DrawSamus_NoChargeOrGrapple();
}

/**
* @brief Draw Samus without charge or grapple
*/
void DrawSamus_NoChargeOrGrapple(void) {  // 0x90EB55
  if ((arm_cannon_drawing_mode & 0xF) != kArmCannonDrawingMode_0_NoDraw) {
    if ((arm_cannon_drawing_mode & 0xF) == kArmCannonDrawingMode_2_FaceForward) {
      HandleAtmosphericEffects();
      Samus_Draw();
      Samus_ArmCannon_Draw();
    }
    else {
      HandleAtmosphericEffects();
      Samus_ArmCannon_Draw();
      Samus_Draw();
    }
    Samus_DrawEchoes();
  }
  else {
    HandleAtmosphericEffects();
    Samus_Draw();
    Samus_DrawEchoes();
  }
}

/**
* @brief Handle Samus while firing grapple drawing
*/
void Samus_DrawHandler_NoChargeOrGrapple(void) {  // 0x90EB86
  if (grapple_beam_function >= FUNC16(GrappleBeamFunc_Cancel)) {
    DrawSamus_NoChargeOrGrapple();
    return;
  }

  if (grapple_beam_function == FUNC16(GrappleBeamFunc_Firing)
      || grapple_beam_function == FUNC16(UNUSED_sub_9BC759)) {
    GrappleBeamFunc_BF1B();
  }
  HandleGrappleBeamFlare();

  if ((arm_cannon_drawing_mode & 0xF) != kArmCannonDrawingMode_0_NoDraw) {
    if ((arm_cannon_drawing_mode & 0xF) == kArmCannonDrawingMode_2_FaceForward) {
      HandleAtmosphericEffects();
      Samus_Draw();
      Samus_ArmCannon_Draw();
      UpdateGrappleBeamTilesAndIncrFlameCtr();
      if (grapple_beam_length == 0)
        return;
    }
    else {
      HandleAtmosphericEffects();
      Samus_ArmCannon_Draw();
      Samus_Draw();
      UpdateGrappleBeamTilesAndIncrFlameCtr();
      if (grapple_beam_length == 0)
        return;
    }
  }

  else {
    HandleAtmosphericEffects();
    Samus_Draw();
    UpdateGrappleBeamTilesAndIncrFlameCtr();
    if (grapple_beam_length == 0)
      return;
  }
  HandleGrappleBeamGfx();
}

/**
* @brief Handle Samus shinespark crash echoes drawing
*/
void Samus_DrawHandler_EndOfShinespark(void) {  // 0x90EBF3
  Samus_Draw();
  for (int speed_echo_idx = 2; speed_echo_idx >= 0; speed_echo_idx -= 2)
    Samus_DrawShinesparkCrashEchoes(speed_echo_idx);
}

void Samus_DrawManyEchoes_Unused(void) {  // 0x90EC03
  Samus_DrawHandler_Default();
  for (int speed_echo_idx = 2; speed_echo_idx >= 0; speed_echo_idx -= 2)
    Samus_DrawEchoes();
}

/**
* @brief Handle Samus during elevator drawing
*/
void Samus_DisplayHandler_UsingElevator(void) {  // 0x90EC14
  if ((nmi_frame_counter_word & 1) == 0)
    Samus_DisplayHandler_InanimateSamus();
}

/**
* @brief Handle Samus drawing while not animating
*/
void Samus_DisplayHandler_InanimateSamus(void) {  // 0x90EC1D
  Samus_DrawInanimateSamus();
}

/**
* @brief Set Samus X and Y radius
*/
void Samus_SetRadius(void) {  // 0x90EC22
  samus_y_radius = kPoseParams[samus_pose].y_radius;
  samus_x_radius = 5;
}

/**
* @brief Get Samus bottom boundary
* @return uint16 Samus bottom boundary
*/
uint16 Samus_GetBottomBound(void) {  // 0x90EC3E
  return samus_y_pos + kPoseParams[samus_pose].y_radius - 1;
}

/**
* @brief Get Samus top boundary
* @return uint16 Samus top boundary
*/
uint16 Samus_GetTopBound(void) {  // 0x90EC58
  return samus_y_pos - kPoseParams[samus_pose].y_radius;
}

/**
* @brief Set Samus bottom position to align with the previous pose bottom position
*/
void Samus_AlignBottomWithPrevPose(void) {  // 0x90EC7E
  uint16 prev_pose_offset = kPoseParams[samus_prev_pose].y_radius - kPoseParams[samus_pose].y_radius;
  samus_y_pos += prev_pose_offset;
  samus_prev_y_pos += prev_pose_offset;
}

/**
* @brief Set Samus suit palette index based off suit
*/
void Samus_UpdateSuitPaletteIndex(void) {  // 0x90ECB6
  if (equipped_items & kItem_GravitySuit) {
    samus_suit_palette_index = kSuitPaletteIndex_4_Gravity;
  }
  else if (equipped_items & kItem_VariaSuit) {
    samus_suit_palette_index = kSuitPaletteIndex_2_Varia;
  }
  else {
    samus_suit_palette_index = kSuitPaletteIndex_0_Power;
  }
}

/**
* @brief Move Samus with the d-pad while in demo recording mode
*/
void DemoRecorder_MoveSamusWithControlPad(void) {  // 0x90ECD5
  if (joypad1_lastkeys & kButton_Up)
    Samus_MoveUp(INT16_SHL16(-4));
  if (joypad1_lastkeys & kButton_Down)
    Samus_MoveDown(INT16_SHL16(4));
  if (joypad1_lastkeys & kButton_Left)
    Samus_MoveLeft(INT16_SHL16(-4));
  if (joypad1_lastkeys & kButton_Right)
    Samus_MoveRight(INT16_SHL16(4));
}



/**
* @brief Display Samus position in missile and super missile display while in demo recording mode
*/
void DemoRecorder_DisplaySamusPositionAsAmmoIfMorphed(void) {  // 0x90ED26
  static const uint8 kSamusMovementType_IsMorphed[28] = {
    [kMovementType_00_Standing]                                             = false,
    [kMovementType_01_Running]                                              = false,
    [kMovementType_02_NormalJumping]                                        = false,
    [kMovementType_03_SpinJumping]                                          = false,
    [kMovementType_04_MorphBallOnGround]                                    = true,
    [kMovementType_05_Crouching]                                            = false,
    [kMovementType_06_Falling]                                              = false,
    [kMovementType_07_Unused]                                               = true,
    [kMovementType_08_MorphBallFalling]                                     = true,
    [kMovementType_09_Unused]                                               = true,
    [kMovementType_0A_KnockbackOrCrystalFlashEnding]                        = false,
    [kMovementType_0B_Unused]                                               = false,
    [kMovementType_0C_Unused]                                               = false,
    [kMovementType_0D_Unused]                                               = false,
    [kMovementType_0E_TurningAroundOnGround]                                = false,
    [kMovementType_0F_Crouch_Stand_Morph_Unmorph_Transition]                = false,
    [kMovementType_10_Moonwalking]                                          = false,
    [kMovementType_11_SpringBallOnGround]                                   = true,
    [kMovementType_12_SpringBallInAir]                                      = true,
    [kMovementType_13_SpringBallFalling]                                    = true, 
    [kMovementType_14_WallJumping]                                          = false,
    [kMovementType_15_RanIntoWall]                                          = false,
    [kMovementType_16_Grappling]                                            = false,
    [kMovementType_17_TurningAroundJumping]                                 = false,
    [kMovementType_18_TurningAroundFalling]                                 = false,
    [kMovementType_19_DamageBoost]                                          = false,
    [kMovementType_1A_GrabbedByDraygon]                                     = false,
    [kMovementType_1B_Shinespark_CrystalFlash_Drained_DamagedByMotherBrain] = false,
  };

  if (kSamusMovementType_IsMorphed[samus_movement_type]) {
    samus_max_missiles = samus_missiles = samus_x_pos / 16;
    samus_max_super_missiles = samus_super_missiles = samus_y_pos / 16;
  }
}

void UNUSED_DisplayInGameTimeAsAmmo(void) {  // 0x90ED6C
  samus_max_missiles = samus_missiles = game_time_hours;
  samus_max_super_missiles = samus_super_missiles = game_time_minutes;
  samus_max_power_bombs = samus_power_bombs = game_time_seconds;
}

static Func_V *const kSamus_FootstepGraphics[8] = {  // 0x90ED88
  [kArea_0_Crateria]    = Samus_FootstepGraphics_Crateria,
  [kArea_1_Brinstar]    = Samus_FootstepGraphics_Common,
  [kArea_2_Norfair]     = Samus_FootstepGraphics_Common,
  [kArea_3_WreckedShip] = Samus_FootstepGraphics_Common,
  [kArea_4_Maridia]     = Samus_FootstepGraphics_Maridia,
  [kArea_5_Tourian]     = Samus_FootstepGraphics_Common,
  [kArea_6_Ceres]       = Samus_FootstepGraphics_Common,
  [kArea_7_Debug]       = Samus_FootstepGraphics_Common,
};

/**
* @brief Handle footstep graphics
*/
void Samus_FootstepGraphics(void) {
  kSamus_FootstepGraphics[area_index]();
}

/**
* @brief Handle footstep graphics in Crateria rooms
*/
void Samus_FootstepGraphics_Crateria(void) {  // 0x90EDA1
  static const uint8 kFootstepGraphics_CrateriaRoomIndex[16] = {
    1, 0, 0, 0, 0, 2, 0, 4,
    0, 4, 4, 4, 4, 0, 4, 0,
  };

  if (cinematic_function != 0 || room_index >= 16) {
    Samus_FootstepGraphics_Common();
  }
  else if (!(kFootstepGraphics_CrateriaRoomIndex[room_index] & 1)) {
    if (kFootstepGraphics_CrateriaRoomIndex[room_index] & 2) {
      // Outside room leading to Wrecked Ship entrance room
      if ((int16)samus_y_pos >= (59*16)) {
        Samus_FootstepGraphics_Maridia();
      }
    }
    else if (kFootstepGraphics_CrateriaRoomIndex[room_index] & 4) {
      Samus_FootstepGraphics_Maridia();
    }
    else {
      Samus_FootstepGraphics_Common();
    }
  }
  else if (fx_type != kFxType_A_Rain) {
    Samus_FootstepGraphics_Common();
  }
  else {
    Samus_FootstepGraphics_Maridia();
  }
}

/**
* @brief Handle footstep splash graphics in partially submerged Maridia rooms
*/
void Samus_FootstepGraphics_Maridia(void) {  // 0x90EDEC
  int16 samus_bottom_bound = Samus_GetBottomBound();
  if ((int16)fx_y_pos < 0) {
    if ((int16)lava_acid_y_pos >= 0 && (int16)lava_acid_y_pos < samus_bottom_bound)
      return;
  }
  else if ((int16)fx_y_pos < samus_bottom_bound && !(fx_liquid_options & kFxLiquidOption_4_LiquidPhysicsDisabled)) {
    return;
  }

  if (samus_pose_x_dir == kSamusXDir_FaceLeft) {
    atmospheric_gfx_x_pos[0] = samus_x_pos - 12;
    atmospheric_gfx_x_pos[1] = samus_x_pos + 8;
  }
  else {
    atmospheric_gfx_x_pos[0] = samus_x_pos + 12;
    atmospheric_gfx_x_pos[1] = samus_x_pos - 8;
  }
  atmospheric_gfx_y_pos[1] = atmospheric_gfx_y_pos[0] = samus_y_pos + 16;

  LOBYTE(atmospheric_gfx_frame_and_type[0]) = 0;
  HIBYTE(atmospheric_gfx_frame_and_type[0]) = kAtmosphericGraphicType_1_FootstepSplashes;

  LOBYTE(atmospheric_gfx_frame_and_type[1]) = 0;
  HIBYTE(atmospheric_gfx_frame_and_type[1]) = kAtmosphericGraphicType_1_FootstepSplashes;

  atmospheric_gfx_anim_timer[0] = ANIM_TIMER_INACTIVE | 2;
  atmospheric_gfx_anim_timer[1] = 3;
}

/**
* @brief Handle speed boost footstep graphics in normal rooms
*/
void Samus_FootstepGraphics_Common(void) {  // 0x90EE64
  if (speed_boost_counter == SPEED_BOOST_THRESHOLD) {
    int16 samus_bottom_bound = Samus_GetBottomBound();
    if ((int16)fx_y_pos < 0) {
      if ((int16)lava_acid_y_pos >= 0 && (int16)lava_acid_y_pos < samus_bottom_bound)
        return;
    }
    else if ((int16)fx_y_pos < samus_bottom_bound && !(fx_liquid_options & kFxLiquidOption_4_LiquidPhysicsDisabled)) {
      return;
    }
    if (samus_pose_x_dir == kSamusXDir_FaceLeft) {
      atmospheric_gfx_x_pos[0] = samus_x_pos - 12;
      atmospheric_gfx_x_pos[1] = samus_x_pos + 8;
    }
    else {
      atmospheric_gfx_x_pos[0] = samus_x_pos + 12;
      atmospheric_gfx_x_pos[1] = samus_x_pos - 8;
    }
    atmospheric_gfx_y_pos[1] = atmospheric_gfx_y_pos[0] = samus_y_pos + 16;

    LOBYTE(atmospheric_gfx_frame_and_type[0]) = 0;
    HIBYTE(atmospheric_gfx_frame_and_type[0]) = kAtmosphericGraphicType_7_SpeedBoostDust;

    LOBYTE(atmospheric_gfx_frame_and_type[1]) = 0;
    HIBYTE(atmospheric_gfx_frame_and_type[1]) = kAtmosphericGraphicType_7_SpeedBoostDust;

    atmospheric_gfx_anim_timer[0] = ANIM_TIMER_INACTIVE | 2;
    atmospheric_gfx_anim_timer[1] = 3;
  }
}

/**
* @brief Update position of speed echo
*/
void Samus_UpdateSpeedEchoPos(void) {  // 0x90EEE7
  if (speed_boost_counter == SPEED_BOOST_THRESHOLD && !(speed_echoes_index & 0x8000) && (game_time_frames & 3) == 0) {
    int idx = speed_echoes_index >> 1;
    speed_echo_xpos[idx] = samus_x_pos;
    speed_echo_ypos[idx] = samus_y_pos;
    speed_echoes_index = (speed_echoes_index + 2) % 4;
  }
}

/**
* @brief Handle detecting Samus collision directly after grapple is released
*/
void Samus_PostGrappleCollisionDetect(void) {  // 0x90EF22
  PostGrappleCollisionDetect_X();
  PostGrappleCollisionDetect_Y();
  if (distance_to_eject_samus_down == 0 || distance_to_eject_samus_up == 0) {
    if (distance_to_eject_samus_up != 0) {
      samus_y_pos -= distance_to_eject_samus_up;
      if ((int16)samus_y_radius >= 16) {
        PostGrappleCollisionDetect_Y();
        samus_y_pos -= distance_to_eject_samus_up;
      }
    }
  }
}


void ProjPreInstr_UnknownProj8027(uint16 proj_idx) {  // 0x90EFD3
  static const int16 kProjPreInstr_UnknownProj8027_Speed_X[4] = { -4, -4, 4, 4 };
  static const int16 kProjPreInstr_UnknownProj8027_Speed_Y[4] = { 4, -4, -4, 4 };
  static const int16 kProjPreInstr_UnknownProj8027_Offset_X[4] = { 0x80, 0x80, -0x80, -0x80 };
  static const int16 kProjPreInstr_UnknownProj8027_Offset_Y[4] = { -0x80, 0x80, 0x80, -0x80 };

  int idx = proj_idx >> 1;
  projectile_x_pos[idx] += kProjPreInstr_UnknownProj8027_Speed_X[idx];
  projectile_y_pos[idx] += kProjPreInstr_UnknownProj8027_Speed_Y[idx];
  if (projectile_y_pos[idx] == samus_y_pos) {
    if (projectile_variables[idx] == 1) {
      if (proj_idx == 6)
        samus_movement_handler = FUNC16(Samus_MovementHandler_F04B_Unused);
      ClearProjectile(proj_idx);
    }
    else {
      ++projectile_variables[idx];
      samus_shine_timer = 180;
      special_samus_palette_type = 1;
      special_samus_palette_frame = 0;
      projectile_x_pos[idx] = samus_x_pos + kProjPreInstr_UnknownProj8027_Offset_X[idx];
      projectile_y_pos[idx] = samus_y_pos + kProjPreInstr_UnknownProj8027_Offset_Y[idx];
    }
  }
}

void Samus_MovementHandler_F04B_Unused(void) {  // 0x90F04B
  if (samus_shine_timer == 0) {
    special_samus_palette_frame = 6;
    special_samus_palette_timer = 1;
    demo_timer_counter = 1;
    special_samus_palette_type = 10;
    samus_shine_timer = 120;
    samus_movement_handler = FUNC16(Samus_MovementHandler_F072_Unused);
  }
}

void Samus_MovementHandler_F072_Unused(void) {  // 0x90F072
  if (samus_shine_timer == 0) {
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

/**
* @brief Run Samus command and update poses
* @param samus_code The command to run
* @return uint16 
*/
uint16 RunSamusCode(uint16 samus_code) {
  uint16 code = kSamusCodeHandlers[samus_code & 0x1F]();
  if (!(code & 1))
    return code >> 1;

  samus_new_pose = -1;
  samus_new_pose_interrupted = -1;
  samus_new_pose_transitional = -1;

  samus_new_pose_command = 0;
  samus_new_pose_interrupted_command = 0;
  samus_new_pose_transitional_command = 0;
  return -1;
}

/**
* @brief Update previous Samus poses
*/
void Samus_UpdatePreviousPose(void) {  // 0x90F0EE
  samus_last_different_pose = samus_prev_pose;
  samus_last_different_pose_x_dir = samus_prev_pose_x_dir;
  samus_last_different_pose_movement_type = samus_prev_movement_type;

  samus_prev_pose = samus_pose;
  samus_prev_pose_x_dir = samus_pose_x_dir;
  samus_prev_movement_type = samus_movement_type;
}

uint8 ClearCarry(void) {  // 0x90F107
  return 0;
}

/**
* @brief Set handlers to lock Samus
* @return uint8
*/
uint8 SamusCode_00_LockSamus(void) {  // 0x90F109
  frame_handler_alfa = FUNC16(Samus_FrameHandlerAlfa_SamusLocked);
  frame_handler_beta = FUNC16(Samus_FrameHandlerBeta_SamusLocked);
  return 1;
}

/**
* @brief Set handlers to unlock Samus
* @return uint8
*/
uint8 SamusCode_01_UnlockSamus(void) {  // 0x90F117
  frame_handler_alfa = FUNC16(Samus_FrameHandlerAlfa_Normal);
  frame_handler_beta = FUNC16(Samus_FrameHandlerBeta_Normal);
  return 1;
}

/**
* @brief Handle Samus reaching Ceres elevator during escape
* @return uint8
*/
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

/**
* @brief Handle unspinning Samus from a spin jump or wall jump
* @return uint8
*/
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

/**
* @brief Clear the charge beam state and set Samus palette back to normal
* @return uint8
*/
uint8 EndChargeBeam(void) {  // 0x90F19E
  flare_counter = 0;
  ClearFlareAnimationState();
  Samus_LoadSuitPalette();
  return 0;
}

/**
* @brief End charge beam
* @return uint8
*/
uint8 SamusCode_04_EndChargeBeam(void) {  // 0x90F19B
  samus_charge_palette_index = 0;
  return EndChargeBeam();
}

/**
* @brief Set handlers to lock Samus to a station and kill charge beam
* @return uint8
*/
uint8 SamusCode_06_LockToStation(void) {  // 0x90F1AA
  frame_handler_alfa = FUNC16(Samus_FrameHandlerAlfa_SamusLocked);
  frame_handler_beta = FUNC16(Samus_FrameHandlerBeta_SamusLockedToStation);
  if (flare_counter >= 15)
    QueueSfx1_Max15(kSfx1_Silence);
  return EndChargeBeam();
}

/**
* @brief Set handlers and Samus to riding an elevator
* @return uint8
*/
uint8 SamusCode_07_SetupForElevator(void) {  // 0x90F1C8
  MakeSamusFaceForward();
  frame_handler_beta = FUNC16(Samus_FrameHandlerBeta_RidingElevator);
  samus_movement_handler = FUNC16(Samus_MovementHandler_Normal);
  samus_draw_handler = FUNC16(Samus_DisplayHandler_UsingElevator);
  samus_input_handler = FUNC16(Samus_InputHandler_Normal);
  bomb_jump_dir = kBombJumpDir_None;
  return 1;
}

/**
* @brief Handle spawning Samus from Ceres elevator
* @return uint8
*/
uint8 SamusCode_08_SetupForCeresStart(void) {  // 0x90F1E9
  frame_handler_alfa = FUNC16(Samus_FrameHandlerBeta_DoNothing);
  frame_handler_beta = FUNC16(Samus_FrameHandlerBeta_SamusLocked);
  samus_pose = kPose_00_FaceF_Powersuit;
  samus_anim_frame_skip = 0;
  SamusFunc_F433();
  Samus_SetAnimationFrameIfPoseChanged();
  Samus_LoadSuitPalette();
  samus_draw_handler = FUNC16(Samus_DrawHandler_Default);
  samus_last_different_pose = samus_prev_pose =  samus_pose;
  samus_last_different_pose_x_dir = samus_prev_pose_x_dir = samus_pose_x_dir;
  samus_last_different_pose_movement_type = samus_prev_movement_type = samus_movement_type;
  samus_y_pos = 0;
  SpawnEprojWithGfx(0, 0, addr_kEproj_CeresElevatorPad);
  SpawnEprojWithGfx(0, 0, addr_kEproj_CeresElevatorPlatform);
  disable_minimap = 0;
  PlayRoomMusicTrackAfterAFrames(32);
  return 1;
}

/**
* @brief Handle spawning Samus
* @return uint8
*/
uint8 SamusCode_09_SetupForZebesStart(void) {  // 0x90F23C
  if (equipped_items & kItem_GravitySuit) {
    SpawnPalfxObject(addr_kPalfx_SamusLoading_GravitySuit);
    samus_pose = kPose_9B_FaceF_VariaGravitySuit;
  }
  else if (equipped_items & kItem_VariaSuit) {
    SpawnPalfxObject(addr_kPalfx_SamusLoading_VariaSuit);
    samus_pose = kPose_9B_FaceF_VariaGravitySuit;
  }
  else {
    SpawnPalfxObject(addr_kPalfx_SamusLoading_PowerSuit);
    samus_pose = kPose_00_FaceF_Powersuit;
  }
  Samus_LoadSuitPalette();
  SamusFunc_F433();
  samus_anim_frame_timer = 3;
  samus_anim_frame = 2;
  samus_fanfare_timer = 0;
  return 1;
}

/**
* @brief Stop drawing Samus
* @return uint8
*/
uint8 SamusCode_0A_ClearDrawHandler(void) {  // 0x90F28D
  samus_draw_handler = FUNC16(nullsub_152);
  return 0;
}

/**
* @brief Draw and unlock Samus
* @return uint8
*/
uint8 SamusCode_0B_UnlockFromFacingForward(void) {  // 0x90F295
  samus_draw_handler = FUNC16(Samus_DrawHandler_Default);
  return SamusCode_01_UnlockSamus();
}

/**
* @brief Update Samus pose and unlock Samus from station
* @return uint8
*/
uint8 SamusCode_0C_UpdateDueToUnpause(void) {  // 0x90F29E
  Samus_UpdatePoseFromEquipmentChange();
  if (frame_handler_beta == FUNC16(Samus_FrameHandlerBeta_SamusLockedToStation)) {
    frame_handler_alfa = FUNC16(Samus_FrameHandlerAlfa_Normal);
    frame_handler_beta = FUNC16(Samus_FrameHandlerBeta_Normal);
  }
  return 1;
}

/**
* @brief Check if grapple is active
* @return uint8
*/
uint8 SamusCode_0D_IsGrappleActive(void) {  // 0x90F2B8
  return (grapple_beam_function != FUNC16(GrappleBeamFunc_Inactive)) ? 2 : 0;
}

/**
* @brief Set handlers to unlock Samus while in Ceres
* @return uint8
*/
uint8 SamusCode_0E_UnlockFromCeresElevator(void) {  // 0x90F2CA
  frame_handler_alfa = FUNC16(Samus_FrameHandlerAlfa_Normal);
  frame_handler_beta = FUNC16(Samus_FrameHandlerBeta_Ceres);
  return 1;
}

/**
* @brief Set hack handler to timer
* @return uint8
*/
uint8 SamusCode_0F_EnableTimerHandling(void) {  // 0x90F2D8
  frame_handler_gamma = FUNC16(Samus_FrameHandlerGamma_HandleTimer);
  return 0;
}

/**
* @brief Set handlers to unlock Samus from reserve tank if not being drained by rainbow beam
* @return uint8
*/
uint8 SamusCode_10_UnlockFromReserveTank(void) {  // 0x90F2E0
  if (frame_handler_beta != FUNC16(Samus_FrameHandlerBeta_SamusBeingDrained)) {
    frame_handler_alfa = FUNC16(Samus_FrameHandlerAlfa_Normal);
    frame_handler_beta = FUNC16(Samus_FrameHandlerBeta_Normal);
  }
  return 1;
}

/**
* @brief Set handlers to lock Samus and draw her without animating
* @return uint8
*/
uint8 LockSamus_SetInanimateDrawHandler(void) {  // 0x90F2FC
  frame_handler_alfa = FUNC16(Samus_FrameHandlerAlfa_SamusLocked);
  frame_handler_beta = FUNC16(Samus_FrameHandlerBeta_DoNothing);
  samus_draw_handler = FUNC16(Samus_DisplayHandler_InanimateSamus);
  return 1;
}

/**
* @brief Disable palette fx and lock Samus without animating
* @return uint8
*/
uint8 SamusCode_11_SetupForDeath(void) {  // 0x90F2F8
  DisablePaletteFx();
  return LockSamus_SetInanimateDrawHandler();
}

/**
* @brief Update pose and lock Samus for suit acquisition
* @return uint8
*/
uint8 SamusCode_15_LockToSuitAcquisition(void) {  // 0x90F310
  Samus_UpdatePreviousPose();
  flare_counter = 0;
  ClearFlareAnimationState();
  Samus_LoadSuitPalette();
  return LockSamus_SetInanimateDrawHandler();
}

/**
* @brief Enable Samus blue flashing
* @return uint8
*/
uint8 SamusCode_12_EnableBlueFlashing(void) {  // 0x90F320
  samus_special_super_palette_flags = 1;
  return 0;
}

/**
* @brief Disable Samus blue flashing
* @return uint8
*/
uint8 SamusCode_13_DisableBlueFlashing(void) {  // 0x90F328
  samus_special_super_palette_flags = 0;
  Samus_LoadSuitPalette();
  return 0;
}

/**
* @brief Handle low health and grapple sfx
* @return uint8
*/
uint8 SamusCode_14_QueueSfx(void) {  // 0x90F331
  if ((int16)samus_health <= 30) {
    QueueSfx3_Max6(kSfx3_LowHealthBeep);
  }
  if (SamusCode_0D_IsGrappleActive()) {
    QueueSfx1_Max6(kSfx1_Grappling);
  }
  // This condition is never true, as samus_pose_x_dir is never 3
  // This was likely meant to be samus_movement_type, which is 3 for kMovementType_03_SpinJumping
  else if (samus_pose_x_dir == 3) {
    if (samus_pose == kPose_81_FaceR_Screwattack || samus_pose == kPose_82_FaceL_Screwattack) {
      QueueSfx1_Max6(kSfx1_ScrewAttack);
    }
    else if (samus_pose == kPose_1B_FaceR_SpaceJump || samus_pose == kPose_1C_FaceL_SpaceJump) {
      QueueSfx1_Max6(kSfx1_SpaceJump);
    }
    else {
      QueueSfx1_Max6(kSfx1_SpinJump);
    }
  }

  return 0;
}

/**
* @brief Set Samus to drained state and able to stand
* @return uint8
*/
uint8 SamusCode_05_SetupDrained_AbleToStand(void) {  // 0x90F38E
  frame_handler_gamma = FUNC16(Samus_FrameHandlerGamma_UnlockSamusFromDrained);
  return Samus_SetupForBeingDrained();
}

/**
* @brief Handle setting Samus to drained state
* @return uint8
*/
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

/**
* @brief Set Samus to drained state and unable to stand
* @return uint8
*/
uint8 SamusCode_18_SetupDrained_UnableToStand(void) {  // 0x90F3C0
  frame_handler_gamma = FUNC16(Samus_FrameHandlerGamma_KeepSamusLockedFromDrained);
  return Samus_SetupForBeingDrained();
}

/**
* @brief Set Samus to rainbow flashing during Shitroid death scene
* @return uint8
*/
uint8 SamusCode_16_EnableRainbowSamus(void) {  // 0x90F3C9
  samus_special_super_palette_flags = 0x8000;
  special_samus_palette_frame = 1;
  special_samus_palette_timer = 1;
  samus_charge_palette_index = 0;
  return 0;
}

/**
* @brief Set Samus to normal palette after Shitroid death scene
* @return uint8
*/
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

/**
* @brief Set Samus animation to frozen leading up to hyper beam acquisition
* @return uint8
*/
uint8 SamusCode_19_FreezeDrainedSamus(void) {  // 0x90F3FB
  samus_anim_frame_timer = 1;
  samus_anim_frame = 29 - 1;
  return 1;
}

/**
* @brief Set handler to Samus entering gunship
*/
uint8 SamusCode_1A_EnterGunship(void) {  // 0x90F409
  frame_handler_beta = FUNC16(Samus_FrameHandlerBeta_EnterExitGunship);
  return 0;
}

/**
* @brief Set handlers to lock Samus when not being drained
* @return uint8
*/
uint8 SamusCode_1B_LockForReserveTank(void) {  // 0x90F411
  if (frame_handler_beta != FUNC16(Samus_FrameHandlerBeta_SamusBeingDrained))
    return SamusCode_00_LockSamus();
  return 1;
}

/**
* @brief Handle spin jump sfx during spin jump
* @return uint8
*/
uint8 SamusCode_1C_PlaySpinSfxIfSpinJumping(void) {  // 0x90F41E
  if (samus_movement_type == kMovementType_14_WallJumping) {
    if (samus_anim_frame < 23) {
      if (samus_anim_frame < 13) {
        QueueSfx1_Max9(kSfx1_SpinJump);
        return 0;
      }
      QueueSfx1_Max9(kSfx1_SpaceJump);
      return 0;
    }
  }
  else {
    if (samus_movement_type != kMovementType_03_SpinJumping)
      return 0;
    if (samus_pose != kPose_81_FaceR_Screwattack && samus_pose != kPose_82_FaceL_Screwattack) {
      if (samus_pose != kPose_1B_FaceR_SpaceJump && samus_pose != kPose_1C_FaceL_SpaceJump) {
        QueueSfx1_Max9(kSfx1_SpinJump);
        return 0;
      }
      QueueSfx1_Max9(kSfx1_SpaceJump);
      return 0;
    }
  }
  QueueSfx1_Max9(kSfx1_ScrewAttack);
  return 0;
}

/**
* @brief Clear spin jump and charge beam sfx when entering door
* @return uint8
*/
uint8 SamusCode_1D_ClearSoundInDoor(void) {  // 0x90F471
  if (samus_movement_type == kMovementType_03_SpinJumping || samus_movement_type == kMovementType_14_WallJumping) {
    QueueSfx1_Max15(kSfx1_SpinJumpEnd_Silence);
    return 0;
  }
  else {
    if (!(joypad1_lastkeys & button_config_shoot)) {
      if (flare_counter < 16)
        QueueSfx1_Max15(kSfx1_Silence);
    }
    return 0;
  }
}

/**
* @brief Handle spin jump and charge beam sfx after power bomb explosion
* @return uint8
*/
uint8 SamusCode_1E_ResumeSfxAfterPowerBombExplosion(void) {  // 0x90F4A2
  if (game_state == kGameState_8_MainGameplay) {
    if (samus_movement_type == kMovementType_03_SpinJumping || samus_movement_type == kMovementType_14_WallJumping) {
      SamusCode_1C_PlaySpinSfxIfSpinJumping();
      return 0;
    }
    if (flare_counter >= 16)
      QueueSfx1_Max9(kSfx1_ResumeChargingBeam);
  }
  return 0;
}

/**
* @brief Kill grapple beam
* @return uint8
*/
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
    samus_draw_handler = FUNC16(Samus_DrawHandler_Default);
  }
  return 0;
}

uint8 UNUSED_Samus_Func26(void) {  // 0x90F507
  if (samus_movement_type != kMovementType_03_SpinJumping && samus_movement_type != kMovementType_14_WallJumping
      && (joypad1_lastkeys & button_config_shoot) && flare_counter >= 16) {
    QueueSfx1_Max9(kSfx1_ResumeChargingBeam);
  }
  return 0;
}

/**
* @brief Handle echo sfx, spin jump end sfx, time up game state
*/
void Samus_ShootCheck(void) {  // 0x90F576
  // This condition is never true
  //if (play_resume_charging_beam_sfx & 0x8000)
  //  goto LABEL_15;
  if (play_resume_charging_beam_sfx) {
    if (joypad1_lastkeys & button_config_shoot)
      QueueSfx1_Max9(kSfx1_ResumeChargingBeam);
    play_resume_charging_beam_sfx = 0;
  }

  if (samus_echoes_sound_flag && !(speed_boost_counter & SPEED_BOOST_THRESHOLD)) {
    samus_echoes_sound_flag = 0;
    QueueSfx3_Max15(kSfx3_ClearSpeedBooster_ElevatorSound_Silence);
  }

  if ((samus_prev_movement_type_ == kMovementType_03_SpinJumping || samus_prev_movement_type_ == kMovementType_14_WallJumping)
      && samus_movement_type != kMovementType_03_SpinJumping && samus_movement_type != kMovementType_14_WallJumping) {
    QueueSfx1_Max15(kSfx1_SpinJumpEnd_Silence);
    if (flare_counter >= 16 && (joypad1_lastkeys & button_config_shoot))
      play_resume_charging_beam_sfx = 1;
  }

  if (enable_debug) {
    if (samus_pose == kPose_00_FaceF_Powersuit || samus_pose == kPose_9B_FaceF_VariaGravitySuit) {
      if ((joypad2_last & (kButton_L | kButton_R)) == (kButton_L | kButton_R) && (joypad2_new_keys & kButton_A))
        debug_invincibility = 7;
    }
    else {
      if (debug_invincibility >= 7)
        return;
      debug_invincibility = 0;
    }
  }

  if (CheckEventHappened(kEvent_14_ZebesTimebombSet)
      && frame_handler_gamma == FUNC16(Samus_FrameHandlerGamma_DrawTimer)
      && game_state != kGameState_35_TimeUp) {
    game_state = kGameState_35_TimeUp;
  }
}
