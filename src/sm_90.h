#pragma once

#include "types.h"

#define ANIM_TIMER_INACTIVE 0x8000
// Bombs start at projectile byte 10 (slot 5)
#define BOMB_PROJ_OFFSET 10
#define BOMB_SPREAD_LEFT 0x8000
#define BOMB_SPREAD_RIGHT 0

#define PROJ_TRAIL(INSTR) (addr_kProjectileTrail_IList_##INSTR)
#define PROJ_TRAIL_DRAW(INSTR, ENTRY, ANIM) (addr_kProjectileTrail_IList_##INSTR + ENTRY*4 + ANIM*2)
#define PROJ_TRAIL_FUNC(INSTR, ENTRY, ANIM) (addr_kProjectileTrail_IList_##INSTR + ENTRY*4 + ANIM*2)

static const uint8 kWaterSplashTypeTable[28] = {  // 0x9081A4
  [kMovementType_00_Standing]                                             = 1,
  [kMovementType_01_Running]                                              = 0,
  [kMovementType_02_NormalJumping]                                        = 0,
  [kMovementType_03_SpinJumping]                                          = 0,
  [kMovementType_04_MorphBallOnGround]                                    = 1,
  [kMovementType_05_Crouching]                                            = 1,
  [kMovementType_06_Falling]                                              = 0,
  [kMovementType_07_Unused]                                               = 0,
  [kMovementType_08_MorphBallFalling]                                     = 0,
  [kMovementType_09_Unused]                                               = 0,
  [kMovementType_0A_KnockbackOrCrystalFlashEnding]                        = 0,
  [kMovementType_0B_Unused]                                               = 0,
  [kMovementType_0C_Unused]                                               = 0,
  [kMovementType_0D_Unused]                                               = 0,
  [kMovementType_0E_TurningAroundOnGround]                                = 1,
  [kMovementType_0F_Crouch_Stand_Morph_Unmorph_Transition]                = 1,
  [kMovementType_10_Moonwalking]                                          = 1,
  [kMovementType_11_SpringBallOnGround]                                   = 1,
  [kMovementType_12_SpringBallInAir]                                      = 0,
  [kMovementType_13_SpringBallFalling]                                    = 0,
  [kMovementType_14_WallJumping]                                          = 0,
  [kMovementType_15_RanIntoWall]                                          = 1,
  [kMovementType_16_Grappling]                                            = 0,
  [kMovementType_17_TurningAroundJumping]                                 = 0,
  [kMovementType_18_TurningAroundFalling]                                 = 0,
  [kMovementType_19_DamageBoost]                                          = 0,
  [kMovementType_1A_GrabbedByDraygon]                                     = 0,
  [kMovementType_1B_Shinespark_CrystalFlash_Drained_DamagedByMotherBrain] = 0,
};

static const uint16 kAtmosphericTypeNumFrames[8] = {  // 0x908BEF
  [kAtmosphericGraphicType_0_None]                  = 0,
  [kAtmosphericGraphicType_1_FootstepSplashes]      = 4,
  [kAtmosphericGraphicType_2_FootstepSplashes]      = 4,
  [kAtmosphericGraphicType_3_DivingSplashes]        = 9,
  [kAtmosphericGraphicType_4_LavaAcidSurfaceDamage] = 4,
  [kAtmosphericGraphicType_5_Bubbles]               = 8,
  [kAtmosphericGraphicType_6_LandingDust]           = 4,
  [kAtmosphericGraphicType_7_SpeedBoostDust]        = 4,
};

// Access to the array can be OOB
uint8 kSamusFramesForUnderwaterSfx[] = {
  1,   0,   0,   0,   0,   0,   0,   0,   1,   0,   0,   0,   0, 
  8, 194,  48, 173,  74,  11, 208,  61, 173,  30,  10,  41, 255, 
  0, 201,   4,   0,
};

const uint8 *kPauseMenuMapData[8];

LongPtr kPauseMenuMapTilemaps_90[] = {
  0x9000, 0xb5, 0x8000, 0xb5, 0xa000, 0xb5, 0xb000, 0xb5, 0xc000, 0xb5, 0xd000, 0xb5, 0xe000, 0xb5,
};

uint16 kBeamTilePtrs[] = {
  [kProjectileType_Power]                                           = 0xf200,
  [kProjectileType_Wave]                                            = 0xf600,
  [kProjectileType_Ice]                                             = 0xf400,
  [kProjectileType_Ice|kProjectileType_Wave]                        = 0xf600,
  [kProjectileType_Spazer]                                          = 0xfa00,
  [kProjectileType_Spazer|kProjectileType_Wave]                     = 0xfa00,
  [kProjectileType_Spazer|kProjectileType_Ice]                      = 0xfa00,
  [kProjectileType_Spazer|kProjectileType_Ice|kProjectileType_Wave] = 0xfa00,
  [kProjectileType_Plasma]                                          = 0xf800,
  [kProjectileType_Plasma|kProjectileType_Wave]                     = 0xf800,
  [kProjectileType_Plasma|kProjectileType_Ice]                      = 0xf800,
  [kProjectileType_Plasma|kProjectileType_Ice|kProjectileType_Wave] = 0xf800,
};

uint16 kBeamPalettePtrs[] = {
  [kProjectileType_Power]                                           = 0xc3e1,
  [kProjectileType_Wave]                                            = 0xc421,
  [kProjectileType_Ice]                                             = 0xc401,
  [kProjectileType_Ice|kProjectileType_Wave]                        = 0xc401,
  [kProjectileType_Spazer]                                          = 0xc461,
  [kProjectileType_Spazer|kProjectileType_Wave]                     = 0xc421,
  [kProjectileType_Spazer|kProjectileType_Ice]                      = 0xc401,
  [kProjectileType_Spazer|kProjectileType_Ice|kProjectileType_Wave] = 0xc401,
  [kProjectileType_Plasma]                                          = 0xc441,
  [kProjectileType_Plasma|kProjectileType_Wave]                     = 0xc441,
  [kProjectileType_Plasma|kProjectileType_Ice]                      = 0xc401,
  [kProjectileType_Plasma|kProjectileType_Ice|kProjectileType_Wave] = 0xc401,
};

uint16 kFlareAnimDelayPtrs[] = {
  0xc487, 0xc4a7, 0xc4ae,
};

static const uint8 kFlareAnimDelays[3][32] = {
  [0] = { 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3,
          3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 0xFE,14, },  // main flare
  [1] = { 5, 4, 3, 3, 3, 3, 0xFF, },  // flare fast sparks
  [2] = { 4, 3, 2, 2, 2, 2, 0xFF, },  // flare slow sparks
};

static const SamusSpeedTableEntry kSamusSpeedTable_DuringDiagonalBombJump[1] = {  // 0x909F25
  [0]  = { .accel =  0, .accel_sub = 0x3000, .max_speed =  3, .max_speed_sub =    0x0, .decel =  0, .decel_sub =  0x800, },
};

static const SamusSpeedTableEntry kSamusSpeedTable_GrappleDisconnect_Air[1] = {  // 0x909F31
  [0]  = { .accel =  0, .accel_sub = 0x3000, .max_speed = 15, .max_speed_sub =    0x0, .decel =  0, .decel_sub = 0x1000, },
};

static const SamusSpeedTableEntry kSamusSpeedTable_GrappleDisconnect_Water[1] = {  // 0x909F3D
  [0]  = { .accel =  0, .accel_sub = 0x3000, .max_speed = 15, .max_speed_sub =    0x0, .decel =  0, .decel_sub = 0x1000, },
};

static const SamusSpeedTableEntry kSamusSpeedTable_GrappleDisconnect_LavaAcid[1] = {  // 0x909F49
  [0]  = { .accel =  0, .accel_sub = 0x3000, .max_speed = 15, .max_speed_sub =    0x0, .decel =  0, .decel_sub = 0x1000, },
};

static const SamusSpeedTableEntry kSamusSpeedTable_Normal_X[28] = {  // 0x909F55
  [kMovementType_00_Standing]                                             = { .accel =  0, .accel_sub = 0xc000, .max_speed =  0, .max_speed_sub =    0x0, .decel =  0, .decel_sub = 0x8000, },
  [kMovementType_01_Running]                                              = { .accel =  0, .accel_sub = 0x3000, .max_speed =  2, .max_speed_sub = 0xc000, .decel =  0, .decel_sub = 0x8000, },
  [kMovementType_02_NormalJumping]                                        = { .accel =  0, .accel_sub = 0xc000, .max_speed =  1, .max_speed_sub = 0x4000, .decel =  0, .decel_sub = 0x8000, },
  [kMovementType_03_SpinJumping]                                          = { .accel =  0, .accel_sub = 0xc000, .max_speed =  1, .max_speed_sub = 0x6000, .decel =  0, .decel_sub = 0x8000, },
  [kMovementType_04_MorphBallOnGround]                                    = { .accel =  0, .accel_sub = 0xc000, .max_speed =  3, .max_speed_sub = 0x4000, .decel =  0, .decel_sub = 0x8000, },
  [kMovementType_05_Crouching]                                            = { .accel =  0, .accel_sub = 0xc000, .max_speed =  0, .max_speed_sub =    0x0, .decel =  0, .decel_sub = 0x8000, },
  [kMovementType_06_Falling]                                              = { .accel =  0, .accel_sub = 0xc000, .max_speed =  1, .max_speed_sub =    0x0, .decel =  0, .decel_sub = 0x8000, },
  [kMovementType_07_Unused]                                               = { .accel =  2, .accel_sub =    0x0, .max_speed =  1, .max_speed_sub =    0x0, .decel =  0, .decel_sub = 0x8000, },
  [kMovementType_08_MorphBallFalling]                                     = { .accel =  0, .accel_sub = 0xc000, .max_speed =  1, .max_speed_sub =    0x0, .decel =  0, .decel_sub = 0x8000, },
  [kMovementType_09_Unused]                                               = { .accel =  2, .accel_sub =    0x0, .max_speed =  2, .max_speed_sub =    0x0, .decel =  0, .decel_sub = 0x8000, },
  [kMovementType_0A_KnockbackOrCrystalFlashEnding]                        = { .accel =  1, .accel_sub = 0x8000, .max_speed =  5, .max_speed_sub =    0x0, .decel =  0, .decel_sub = 0x8000, },
  [kMovementType_0B_Unused]                                               = { .accel =  0, .accel_sub = 0xc000, .max_speed =  0, .max_speed_sub =    0x0, .decel =  0, .decel_sub = 0x8000, },
  [kMovementType_0C_Unused]                                               = { .accel =  0, .accel_sub = 0xc000, .max_speed =  0, .max_speed_sub =    0x0, .decel =  0, .decel_sub = 0x8000, },
  [kMovementType_0D_Unused]                                               = { .accel =  0, .accel_sub = 0xc000, .max_speed =  2, .max_speed_sub =    0x0, .decel =  0, .decel_sub = 0x8000, },
  [kMovementType_0E_TurningAroundOnGround]                                = { .accel =  0, .accel_sub = 0xc000, .max_speed =  0, .max_speed_sub =    0x0, .decel =  0, .decel_sub = 0x8000, },
  [kMovementType_0F_Crouch_Stand_Morph_Unmorph_Transition]                = { .accel =  0, .accel_sub = 0xc000, .max_speed =  1, .max_speed_sub = 0x4000, .decel =  0, .decel_sub = 0x8000, },
  [kMovementType_10_Moonwalking]                                          = { .accel =  0, .accel_sub = 0xc000, .max_speed =  0, .max_speed_sub = 0x8000, .decel =  0, .decel_sub = 0x8000, },
  [kMovementType_11_SpringBallOnGround]                                   = { .accel =  0, .accel_sub = 0xc000, .max_speed =  3, .max_speed_sub = 0x4000, .decel =  0, .decel_sub = 0x8000, },
  [kMovementType_12_SpringBallInAir]                                      = { .accel =  0, .accel_sub = 0xc000, .max_speed =  1, .max_speed_sub = 0x4000, .decel =  0, .decel_sub = 0x8000, },
  [kMovementType_13_SpringBallFalling]                                    = { .accel =  0, .accel_sub = 0xc000, .max_speed =  1, .max_speed_sub =    0x0, .decel =  0, .decel_sub = 0x8000, },
  [kMovementType_14_WallJumping]                                          = { .accel =  0, .accel_sub = 0xc000, .max_speed =  1, .max_speed_sub = 0x6000, .decel =  0, .decel_sub = 0x8000, },
  [kMovementType_15_RanIntoWall]                                          = { .accel =  0, .accel_sub = 0xc000, .max_speed =  0, .max_speed_sub =    0x0, .decel =  0, .decel_sub = 0x8000, },
  [kMovementType_16_Grappling]                                            = { .accel =  0, .accel_sub = 0xc000, .max_speed =  1, .max_speed_sub = 0x4000, .decel =  0, .decel_sub = 0x8000, },
  [kMovementType_17_TurningAroundJumping]                                 = { .accel =  0, .accel_sub = 0xc000, .max_speed =  0, .max_speed_sub =    0x0, .decel =  0, .decel_sub = 0x8000, },
  [kMovementType_18_TurningAroundFalling]                                 = { .accel =  0, .accel_sub = 0xc000, .max_speed =  0, .max_speed_sub =    0x0, .decel =  0, .decel_sub = 0x8000, },
  [kMovementType_19_DamageBoost]                                          = { .accel =  0, .accel_sub = 0xc000, .max_speed =  5, .max_speed_sub =    0x0, .decel =  0, .decel_sub = 0x8000, },
  [kMovementType_1A_GrabbedByDraygon]                                     = { .accel =  0, .accel_sub = 0xc000, .max_speed =  0, .max_speed_sub =    0x0, .decel =  0, .decel_sub =  0x800, },
  [kMovementType_1B_Shinespark_CrystalFlash_Drained_DamagedByMotherBrain] = { .accel =  0, .accel_sub =  0x400, .max_speed =  2, .max_speed_sub = 0xc000, .decel =  0, .decel_sub =  0x800, },
};

static const SamusSpeedTableEntry kSamusSpeedTable_Water_X[28] = {  // 0x90A08D
  [kMovementType_00_Standing]                                             = { .accel =  0, .accel_sub = 0xc000, .max_speed =  0, .max_speed_sub =    0x0, .decel =  0, .decel_sub =  0x800, },
  [kMovementType_01_Running]                                              = { .accel =  0, .accel_sub =  0x400, .max_speed =  2, .max_speed_sub = 0xc000, .decel =  0, .decel_sub =  0x800, },
  [kMovementType_02_NormalJumping]                                        = { .accel =  0, .accel_sub = 0xc000, .max_speed =  1, .max_speed_sub = 0x4000, .decel =  0, .decel_sub =  0x800, },
  [kMovementType_03_SpinJumping]                                          = { .accel =  0, .accel_sub = 0xc000, .max_speed =  1, .max_speed_sub = 0x6000, .decel =  0, .decel_sub =  0x800, },
  [kMovementType_04_MorphBallOnGround]                                    = { .accel =  0, .accel_sub =  0x400, .max_speed =  2, .max_speed_sub = 0xc000, .decel =  0, .decel_sub =  0x800, },
  [kMovementType_05_Crouching]                                            = { .accel =  0, .accel_sub = 0xc000, .max_speed =  0, .max_speed_sub =    0x0, .decel =  0, .decel_sub =  0x800, },
  [kMovementType_06_Falling]                                              = { .accel =  0, .accel_sub = 0xc000, .max_speed =  1, .max_speed_sub =    0x0, .decel =  0, .decel_sub =  0x800, },
  [kMovementType_07_Unused]                                               = { .accel =  2, .accel_sub =    0x0, .max_speed =  1, .max_speed_sub =    0x0, .decel =  0, .decel_sub =  0x800, },
  [kMovementType_08_MorphBallFalling]                                     = { .accel =  0, .accel_sub =  0x400, .max_speed =  1, .max_speed_sub = 0x8000, .decel =  0, .decel_sub =  0x800, },
  [kMovementType_09_Unused]                                               = { .accel =  2, .accel_sub =    0x0, .max_speed =  2, .max_speed_sub =    0x0, .decel =  0, .decel_sub =  0x800, },
  [kMovementType_0A_KnockbackOrCrystalFlashEnding]                        = { .accel =  1, .accel_sub = 0x8000, .max_speed =  5, .max_speed_sub =    0x0, .decel =  0, .decel_sub =  0x800, },
  [kMovementType_0B_Unused]                                               = { .accel =  0, .accel_sub = 0xc000, .max_speed =  0, .max_speed_sub =    0x0, .decel =  0, .decel_sub =  0x800, },
  [kMovementType_0C_Unused]                                               = { .accel =  0, .accel_sub = 0xc000, .max_speed =  0, .max_speed_sub =    0x0, .decel =  0, .decel_sub =  0x800, },
  [kMovementType_0D_Unused]                                               = { .accel =  0, .accel_sub = 0xc000, .max_speed =  2, .max_speed_sub =    0x0, .decel =  0, .decel_sub =  0x800, },
  [kMovementType_0E_TurningAroundOnGround]                                = { .accel =  0, .accel_sub = 0xc000, .max_speed =  0, .max_speed_sub =    0x0, .decel =  0, .decel_sub =  0x800, },
  [kMovementType_0F_Crouch_Stand_Morph_Unmorph_Transition]                = { .accel =  0, .accel_sub = 0xc000, .max_speed =  1, .max_speed_sub = 0x4000, .decel =  0, .decel_sub =  0x800, },
  [kMovementType_10_Moonwalking]                                          = { .accel =  0, .accel_sub = 0xc000, .max_speed =  0, .max_speed_sub = 0x8000, .decel =  0, .decel_sub =  0x800, },
  [kMovementType_11_SpringBallOnGround]                                   = { .accel =  0, .accel_sub =  0x400, .max_speed =  2, .max_speed_sub = 0xc000, .decel =  0, .decel_sub =  0x800, },
  [kMovementType_12_SpringBallInAir]                                      = { .accel =  0, .accel_sub =  0x400, .max_speed =  1, .max_speed_sub = 0x4000, .decel =  0, .decel_sub =  0x800, },
  [kMovementType_13_SpringBallFalling]                                    = { .accel =  0, .accel_sub =  0x400, .max_speed =  1, .max_speed_sub = 0x8000, .decel =  0, .decel_sub =  0x800, },
  [kMovementType_14_WallJumping]                                          = { .accel =  0, .accel_sub = 0xc000, .max_speed =  1, .max_speed_sub = 0x6000, .decel =  0, .decel_sub =  0x800, },
  [kMovementType_15_RanIntoWall]                                          = { .accel =  0, .accel_sub = 0xc000, .max_speed =  0, .max_speed_sub =    0x0, .decel =  0, .decel_sub =  0x800, },
  [kMovementType_16_Grappling]                                            = { .accel =  0, .accel_sub = 0xc000, .max_speed =  1, .max_speed_sub = 0x4000, .decel =  0, .decel_sub =  0x800, },
  [kMovementType_17_TurningAroundJumping]                                 = { .accel =  0, .accel_sub = 0xc000, .max_speed =  0, .max_speed_sub =    0x0, .decel =  0, .decel_sub =  0x800, },
  [kMovementType_18_TurningAroundFalling]                                 = { .accel =  0, .accel_sub = 0xc000, .max_speed =  0, .max_speed_sub =    0x0, .decel =  0, .decel_sub =  0x800, },
  [kMovementType_19_DamageBoost]                                          = { .accel =  0, .accel_sub = 0xc000, .max_speed =  0, .max_speed_sub = 0x8000, .decel =  0, .decel_sub =  0x800, },
  [kMovementType_1A_GrabbedByDraygon]                                     = { .accel =  0, .accel_sub = 0xc000, .max_speed =  5, .max_speed_sub =    0x0, .decel =  0, .decel_sub =  0x800, },
  [kMovementType_1B_Shinespark_CrystalFlash_Drained_DamagedByMotherBrain] = { .accel =  0, .accel_sub = 0xc000, .max_speed =  5, .max_speed_sub =    0x0, .decel =  0, .decel_sub =  0x800, },
};

static const SamusSpeedTableEntry kSamusSpeedTable_LavaAcid_X[28] = {  // 0x90A1DD
  [kMovementType_00_Standing]                                             = { .accel =  0, .accel_sub = 0xc000, .max_speed =  0, .max_speed_sub =    0x0, .decel =  0, .decel_sub = 0x4000, },
  [kMovementType_01_Running]                                              = { .accel =  0, .accel_sub =  0x400, .max_speed =  1, .max_speed_sub = 0xc000, .decel =  0, .decel_sub = 0x4000, },
  [kMovementType_02_NormalJumping]                                        = { .accel =  0, .accel_sub = 0xc000, .max_speed =  1, .max_speed_sub = 0x4000, .decel =  0, .decel_sub = 0x4000, },
  [kMovementType_03_SpinJumping]                                          = { .accel =  0, .accel_sub = 0xc000, .max_speed =  1, .max_speed_sub = 0x6000, .decel =  0, .decel_sub = 0x4000, },
  [kMovementType_04_MorphBallOnGround]                                    = { .accel =  0, .accel_sub =  0x400, .max_speed =  2, .max_speed_sub = 0xc000, .decel =  0, .decel_sub = 0x4000, },
  [kMovementType_05_Crouching]                                            = { .accel =  0, .accel_sub = 0xc000, .max_speed =  0, .max_speed_sub =    0x0, .decel =  0, .decel_sub = 0x4000, },
  [kMovementType_06_Falling]                                              = { .accel =  0, .accel_sub = 0xc000, .max_speed =  1, .max_speed_sub =    0x0, .decel =  0, .decel_sub = 0x4000, },
  [kMovementType_07_Unused]                                               = { .accel =  2, .accel_sub =    0x0, .max_speed =  1, .max_speed_sub =    0x0, .decel =  0, .decel_sub = 0x4000, },
  [kMovementType_08_MorphBallFalling]                                     = { .accel =  0, .accel_sub =  0x400, .max_speed =  1, .max_speed_sub = 0x6000, .decel =  0, .decel_sub = 0x4000, },
  [kMovementType_09_Unused]                                               = { .accel =  2, .accel_sub =    0x0, .max_speed =  2, .max_speed_sub =    0x0, .decel =  0, .decel_sub = 0x4000, },
  [kMovementType_0A_KnockbackOrCrystalFlashEnding]                        = { .accel =  1, .accel_sub = 0x8000, .max_speed =  5, .max_speed_sub =    0x0, .decel =  0, .decel_sub = 0x4000, },
  [kMovementType_0B_Unused]                                               = { .accel =  0, .accel_sub = 0xc000, .max_speed =  0, .max_speed_sub =    0x0, .decel =  0, .decel_sub = 0x4000, },
  [kMovementType_0C_Unused]                                               = { .accel =  0, .accel_sub = 0xc000, .max_speed =  0, .max_speed_sub =    0x0, .decel =  0, .decel_sub = 0x4000, },
  [kMovementType_0D_Unused]                                               = { .accel =  0, .accel_sub = 0xc000, .max_speed =  2, .max_speed_sub =    0x0, .decel =  0, .decel_sub = 0x4000, },
  [kMovementType_0E_TurningAroundOnGround]                                = { .accel =  0, .accel_sub = 0xc000, .max_speed =  0, .max_speed_sub =    0x0, .decel =  0, .decel_sub = 0x4000, },
  [kMovementType_0F_Crouch_Stand_Morph_Unmorph_Transition]                = { .accel =  0, .accel_sub = 0xc000, .max_speed =  1, .max_speed_sub = 0x4000, .decel =  0, .decel_sub = 0x4000, },
  [kMovementType_10_Moonwalking]                                          = { .accel =  0, .accel_sub = 0xc000, .max_speed =  0, .max_speed_sub = 0x8000, .decel =  0, .decel_sub = 0x4000, },
  [kMovementType_11_SpringBallOnGround]                                   = { .accel =  0, .accel_sub =  0x400, .max_speed =  2, .max_speed_sub = 0xc000, .decel =  0, .decel_sub = 0x4000, },
  [kMovementType_12_SpringBallInAir]                                      = { .accel =  0, .accel_sub =  0x400, .max_speed =  1, .max_speed_sub = 0x4000, .decel =  0, .decel_sub = 0x4000, },
  [kMovementType_13_SpringBallFalling]                                    = { .accel =  0, .accel_sub =  0x400, .max_speed =  1, .max_speed_sub = 0x6000, .decel =  0, .decel_sub = 0x4000, },
  [kMovementType_14_WallJumping]                                          = { .accel =  0, .accel_sub = 0xc000, .max_speed =  1, .max_speed_sub = 0x6000, .decel =  0, .decel_sub = 0x4000, },
  [kMovementType_15_RanIntoWall]                                          = { .accel =  0, .accel_sub = 0xc000, .max_speed =  0, .max_speed_sub =    0x0, .decel =  0, .decel_sub = 0x4000, },
  [kMovementType_16_Grappling]                                            = { .accel =  0, .accel_sub = 0xc000, .max_speed =  1, .max_speed_sub = 0x4000, .decel =  0, .decel_sub = 0x4000, },
  [kMovementType_17_TurningAroundJumping]                                 = { .accel =  0, .accel_sub = 0xc000, .max_speed =  0, .max_speed_sub =    0x0, .decel =  0, .decel_sub = 0x4000, },
  [kMovementType_18_TurningAroundFalling]                                 = { .accel =  0, .accel_sub = 0xc000, .max_speed =  0, .max_speed_sub =    0x0, .decel =  0, .decel_sub = 0x4000, },
  [kMovementType_19_DamageBoost]                                          = { .accel =  0, .accel_sub = 0xc000, .max_speed =  0, .max_speed_sub = 0x8000, .decel =  0, .decel_sub = 0x4000, },
  [kMovementType_1A_GrabbedByDraygon]                                     = { .accel =  0, .accel_sub = 0xc000, .max_speed =  5, .max_speed_sub =    0x0, .decel =  0, .decel_sub = 0x4000, },
  [kMovementType_1B_Shinespark_CrystalFlash_Drained_DamagedByMotherBrain] = { .accel =  0, .accel_sub = 0xc000, .max_speed =  5, .max_speed_sub =    0x0, .decel =  0, .decel_sub = 0x4000, },
};

static const SamusSpeedTableEntry *get_SamusSpeedTableEntry(uint16 ptr) {
  switch (ptr) {
    case addr_kSamusSpeedTable_DuringDiagonalBombJump     : return kSamusSpeedTable_DuringDiagonalBombJump;
    case addr_kSamusSpeedTable_GrappleDisconnect_Air      : return kSamusSpeedTable_GrappleDisconnect_Air;
    case addr_kSamusSpeedTable_GrappleDisconnect_Water    : return kSamusSpeedTable_GrappleDisconnect_Water;
    case addr_kSamusSpeedTable_GrappleDisconnect_LavaAcid : return kSamusSpeedTable_GrappleDisconnect_LavaAcid;
    case addr_kSamusSpeedTable_Normal_X                   : return kSamusSpeedTable_Normal_X;
    case addr_kSamusSpeedTable_Water_X                    : return kSamusSpeedTable_Water_X;
    case addr_kSamusSpeedTable_LavaAcid_X                 : return kSamusSpeedTable_LavaAcid_X;
    default: Unreachable(); return (SamusSpeedTableEntry*) {0};
  }
}


static const ProjectileTrailInstr get_ProjTrailInstr(uint16 ilist_ptr) {
  switch (ilist_ptr) {
  case PROJ_TRAIL_DRAW(Empty, 0, 0)                            : return (ProjectileTrailInstr) { .timer = 0, };

  case PROJ_TRAIL_DRAW(IceBeams_ChargedPowerBeam_Left, 0, 0)   : return (ProjectileTrailInstr) { .timer = 1, .tile_num_attributes = OAM_DATA(0, 0, 2, 6, 56), };
  case PROJ_TRAIL_DRAW(IceBeams_ChargedPowerBeam_Left, 1, 0)   : return (ProjectileTrailInstr) { .timer = 1, .tile_num_attributes = OAM_DATA(0, 0, 2, 6, 56), };
  case PROJ_TRAIL_DRAW(IceBeams_ChargedPowerBeam_Left, 2, 0)   : return (ProjectileTrailInstr) { .timer = 1, .tile_num_attributes = OAM_DATA(0, 0, 2, 6, 56), };
  case PROJ_TRAIL_DRAW(IceBeams_ChargedPowerBeam_Left, 3, 0)   : return (ProjectileTrailInstr) { .timer = 1, .tile_num_attributes = OAM_DATA(0, 0, 2, 6, 56), };
  case PROJ_TRAIL_DRAW(IceBeams_ChargedPowerBeam_Left, 4, 0)   : return (ProjectileTrailInstr) { .timer = 1, .tile_num_attributes = OAM_DATA(0, 0, 2, 6, 57), };
  case PROJ_TRAIL_DRAW(IceBeams_ChargedPowerBeam_Left, 5, 0)   : return (ProjectileTrailInstr) { .timer = 1, .tile_num_attributes = OAM_DATA(0, 0, 2, 6, 57), };
  case PROJ_TRAIL_FUNC(IceBeams_ChargedPowerBeam_Left, 6, 0)   : return (ProjectileTrailInstr) { .func_ptr = FUNC16(ProjTrailInstr_MoveLeftProjectileTrailDown), };
  case PROJ_TRAIL_DRAW(IceBeams_ChargedPowerBeam_Left, 6, 1)   : return (ProjectileTrailInstr) { .timer = 1, .tile_num_attributes = OAM_DATA(0, 0, 2, 6, 57), };
  case PROJ_TRAIL_DRAW(IceBeams_ChargedPowerBeam_Left, 7, 1)   : return (ProjectileTrailInstr) { .timer = 1, .tile_num_attributes = OAM_DATA(0, 0, 2, 6, 57), };
  case PROJ_TRAIL_FUNC(IceBeams_ChargedPowerBeam_Left, 8, 1)   : return (ProjectileTrailInstr) { .func_ptr = FUNC16(ProjTrailInstr_MoveLeftProjectileTrailDown), };
  case PROJ_TRAIL_DRAW(IceBeams_ChargedPowerBeam_Left, 8, 2)   : return (ProjectileTrailInstr) { .timer = 1, .tile_num_attributes = OAM_DATA(0, 0, 2, 6, 58), };
  case PROJ_TRAIL_FUNC(IceBeams_ChargedPowerBeam_Left, 9, 2)   : return (ProjectileTrailInstr) { .func_ptr = FUNC16(ProjTrailInstr_MoveLeftProjectileTrailDown), };
  case PROJ_TRAIL_DRAW(IceBeams_ChargedPowerBeam_Left, 9, 3)   : return (ProjectileTrailInstr) { .timer = 1, .tile_num_attributes = OAM_DATA(0, 0, 2, 6, 58), };
  case PROJ_TRAIL_FUNC(IceBeams_ChargedPowerBeam_Left, 10, 3)  : return (ProjectileTrailInstr) { .func_ptr = FUNC16(ProjTrailInstr_MoveLeftProjectileTrailDown), };
  case PROJ_TRAIL_DRAW(IceBeams_ChargedPowerBeam_Left, 10, 4)  : return (ProjectileTrailInstr) { .timer = 1, .tile_num_attributes = OAM_DATA(0, 0, 2, 6, 58), };
  case PROJ_TRAIL_FUNC(IceBeams_ChargedPowerBeam_Left, 11, 4)  : return (ProjectileTrailInstr) { .func_ptr = FUNC16(ProjTrailInstr_MoveLeftProjectileTrailDown), };
  case PROJ_TRAIL_DRAW(IceBeams_ChargedPowerBeam_Left, 11, 5)  : return (ProjectileTrailInstr) { .timer = 1, .tile_num_attributes = OAM_DATA(0, 0, 2, 6, 58), };
  case PROJ_TRAIL_FUNC(IceBeams_ChargedPowerBeam_Left, 12, 5)  : return (ProjectileTrailInstr) { .func_ptr = FUNC16(ProjTrailInstr_MoveLeftProjectileTrailDown), };
  case PROJ_TRAIL_DRAW(IceBeams_ChargedPowerBeam_Left, 12, 6)  : return (ProjectileTrailInstr) { .timer = 1, .tile_num_attributes = OAM_DATA(0, 0, 2, 6, 58), };
  case PROJ_TRAIL_FUNC(IceBeams_ChargedPowerBeam_Left, 13, 6)  : return (ProjectileTrailInstr) { .func_ptr = FUNC16(ProjTrailInstr_MoveLeftProjectileTrailDown), };
  case PROJ_TRAIL_DRAW(IceBeams_ChargedPowerBeam_Left, 13, 7)  : return (ProjectileTrailInstr) { .timer = 1, .tile_num_attributes = OAM_DATA(0, 0, 2, 6, 58), };
  case PROJ_TRAIL_FUNC(IceBeams_ChargedPowerBeam_Left, 14, 7)  : return (ProjectileTrailInstr) { .func_ptr = FUNC16(ProjTrailInstr_MoveLeftProjectileTrailDown), };
  case PROJ_TRAIL_DRAW(IceBeams_ChargedPowerBeam_Left, 14, 8)  : return (ProjectileTrailInstr) { .timer = 1, .tile_num_attributes = OAM_DATA(0, 0, 2, 6, 58), };
  case PROJ_TRAIL_FUNC(IceBeams_ChargedPowerBeam_Left, 15, 8)  : return (ProjectileTrailInstr) { .func_ptr = FUNC16(ProjTrailInstr_MoveLeftProjectileTrailDown), };
  case PROJ_TRAIL_DRAW(IceBeams_ChargedPowerBeam_Left, 15, 9)  : return (ProjectileTrailInstr) { .timer = 1, .tile_num_attributes = OAM_DATA(0, 0, 2, 6, 58), };
  case PROJ_TRAIL_FUNC(IceBeams_ChargedPowerBeam_Left, 16, 9)  : return (ProjectileTrailInstr) { .func_ptr = FUNC16(ProjTrailInstr_MoveLeftProjectileTrailDown), };
  case PROJ_TRAIL_DRAW(IceBeams_ChargedPowerBeam_Left, 16, 10) : return (ProjectileTrailInstr) { .timer = 4, .tile_num_attributes = OAM_DATA(0, 0, 2, 6, 59), };
  case PROJ_TRAIL_DRAW(IceBeams_ChargedPowerBeam_Left, 17, 10) : return (ProjectileTrailInstr) { .timer = 0, };

  case PROJ_TRAIL_DRAW(SomeIceBeams_Right, 0, 0)               : return (ProjectileTrailInstr) { .timer = 1, .tile_num_attributes = OAM_DATA(0, 0, 2, 6, 56), };
  case PROJ_TRAIL_DRAW(SomeIceBeams_Right, 1, 0)               : return (ProjectileTrailInstr) { .timer = 1, .tile_num_attributes = OAM_DATA(0, 0, 2, 6, 56), };
  case PROJ_TRAIL_DRAW(SomeIceBeams_Right, 2, 0)               : return (ProjectileTrailInstr) { .timer = 1, .tile_num_attributes = OAM_DATA(0, 0, 2, 6, 56), };
  case PROJ_TRAIL_DRAW(SomeIceBeams_Right, 3, 0)               : return (ProjectileTrailInstr) { .timer = 1, .tile_num_attributes = OAM_DATA(0, 0, 2, 6, 56), };
  case PROJ_TRAIL_DRAW(SomeIceBeams_Right, 4, 0)               : return (ProjectileTrailInstr) { .timer = 1, .tile_num_attributes = OAM_DATA(0, 0, 2, 6, 57), };
  case PROJ_TRAIL_DRAW(SomeIceBeams_Right, 5, 0)               : return (ProjectileTrailInstr) { .timer = 1, .tile_num_attributes = OAM_DATA(0, 0, 2, 6, 57), };
  case PROJ_TRAIL_FUNC(SomeIceBeams_Right, 6, 0)               : return (ProjectileTrailInstr) { .func_ptr = FUNC16(ProjTrailInstr_MoveRightProjectileTrailDown), };
  case PROJ_TRAIL_DRAW(SomeIceBeams_Right, 6, 1)               : return (ProjectileTrailInstr) { .timer = 1, .tile_num_attributes = OAM_DATA(0, 0, 2, 6, 57), };
  case PROJ_TRAIL_DRAW(SomeIceBeams_Right, 7, 1)               : return (ProjectileTrailInstr) { .timer = 1, .tile_num_attributes = OAM_DATA(0, 0, 2, 6, 57), };
  case PROJ_TRAIL_FUNC(SomeIceBeams_Right, 8, 1)               : return (ProjectileTrailInstr) { .func_ptr = FUNC16(ProjTrailInstr_MoveRightProjectileTrailDown), };
  case PROJ_TRAIL_DRAW(SomeIceBeams_Right, 8, 2)               : return (ProjectileTrailInstr) { .timer = 1, .tile_num_attributes = OAM_DATA(0, 0, 2, 6, 58), };
  case PROJ_TRAIL_FUNC(SomeIceBeams_Right, 9, 2)               : return (ProjectileTrailInstr) { .func_ptr = FUNC16(ProjTrailInstr_MoveRightProjectileTrailDown), };
  case PROJ_TRAIL_DRAW(SomeIceBeams_Right, 9, 3)               : return (ProjectileTrailInstr) { .timer = 1, .tile_num_attributes = OAM_DATA(0, 0, 2, 6, 58), };
  case PROJ_TRAIL_FUNC(SomeIceBeams_Right, 10, 3)              : return (ProjectileTrailInstr) { .func_ptr = FUNC16(ProjTrailInstr_MoveRightProjectileTrailDown), };
  case PROJ_TRAIL_DRAW(SomeIceBeams_Right, 10, 4)              : return (ProjectileTrailInstr) { .timer = 1, .tile_num_attributes = OAM_DATA(0, 0, 2, 6, 58), };
  case PROJ_TRAIL_FUNC(SomeIceBeams_Right, 11, 4)              : return (ProjectileTrailInstr) { .func_ptr = FUNC16(ProjTrailInstr_MoveRightProjectileTrailDown), };
  case PROJ_TRAIL_DRAW(SomeIceBeams_Right, 11, 5)              : return (ProjectileTrailInstr) { .timer = 1, .tile_num_attributes = OAM_DATA(0, 0, 2, 6, 58), };
  case PROJ_TRAIL_FUNC(SomeIceBeams_Right, 12, 5)              : return (ProjectileTrailInstr) { .func_ptr = FUNC16(ProjTrailInstr_MoveRightProjectileTrailDown), };
  case PROJ_TRAIL_DRAW(SomeIceBeams_Right, 12, 6)              : return (ProjectileTrailInstr) { .timer = 1, .tile_num_attributes = OAM_DATA(0, 0, 2, 6, 58), };
  case PROJ_TRAIL_FUNC(SomeIceBeams_Right, 13, 6)              : return (ProjectileTrailInstr) { .func_ptr = FUNC16(ProjTrailInstr_MoveRightProjectileTrailDown), };
  case PROJ_TRAIL_DRAW(SomeIceBeams_Right, 13, 7)              : return (ProjectileTrailInstr) { .timer = 1, .tile_num_attributes = OAM_DATA(0, 0, 2, 6, 58), };
  case PROJ_TRAIL_FUNC(SomeIceBeams_Right, 14, 7)              : return (ProjectileTrailInstr) { .func_ptr = FUNC16(ProjTrailInstr_MoveRightProjectileTrailDown), };
  case PROJ_TRAIL_DRAW(SomeIceBeams_Right, 14, 8)              : return (ProjectileTrailInstr) { .timer = 1, .tile_num_attributes = OAM_DATA(0, 0, 2, 6, 58), };
  case PROJ_TRAIL_FUNC(SomeIceBeams_Right, 15, 8)              : return (ProjectileTrailInstr) { .func_ptr = FUNC16(ProjTrailInstr_MoveRightProjectileTrailDown), };
  case PROJ_TRAIL_DRAW(SomeIceBeams_Right, 15, 9)              : return (ProjectileTrailInstr) { .timer = 1, .tile_num_attributes = OAM_DATA(0, 0, 2, 6, 58), };
  case PROJ_TRAIL_FUNC(SomeIceBeams_Right, 16, 9)              : return (ProjectileTrailInstr) { .func_ptr = FUNC16(ProjTrailInstr_MoveRightProjectileTrailDown), };
  case PROJ_TRAIL_DRAW(SomeIceBeams_Right, 16, 10)             : return (ProjectileTrailInstr) { .timer = 4, .tile_num_attributes = OAM_DATA(0, 0, 2, 6, 59), };
  case PROJ_TRAIL_DRAW(SomeIceBeams_Right, 17, 10)             : return (ProjectileTrailInstr) { .timer = 0, };

  case PROJ_TRAIL_DRAW(WaveBeam, 0, 0)                         : return (ProjectileTrailInstr) { .timer = 4, .tile_num_attributes = OAM_DATA(0, 0, 2, 5, 60), };
  case PROJ_TRAIL_DRAW(WaveBeam, 1, 0)                         : return (ProjectileTrailInstr) { .timer = 4, .tile_num_attributes = OAM_DATA(0, 0, 2, 5, 61), };
  case PROJ_TRAIL_DRAW(WaveBeam, 2, 0)                         : return (ProjectileTrailInstr) { .timer = 4, .tile_num_attributes = OAM_DATA(0, 0, 2, 5, 62), };
  case PROJ_TRAIL_DRAW(WaveBeam, 3, 0)                         : return (ProjectileTrailInstr) { .timer = 4, .tile_num_attributes = OAM_DATA(0, 0, 2, 5, 63), };
  case PROJ_TRAIL_DRAW(WaveBeam, 4, 0)                         : return (ProjectileTrailInstr) { .timer = 0, };

  case PROJ_TRAIL_DRAW(AnyMissile, 0, 0)                       : return (ProjectileTrailInstr) { .timer = 4, .tile_num_attributes = OAM_DATA(0, 0, 2, 5, 72), };
  case PROJ_TRAIL_DRAW(AnyMissile, 1, 0)                       : return (ProjectileTrailInstr) { .timer = 4, .tile_num_attributes = OAM_DATA(0, 0, 2, 5, 73), };
  case PROJ_TRAIL_DRAW(AnyMissile, 2, 0)                       : return (ProjectileTrailInstr) { .timer = 4, .tile_num_attributes = OAM_DATA(0, 0, 2, 5, 74), };
  case PROJ_TRAIL_DRAW(AnyMissile, 3, 0)                       : return (ProjectileTrailInstr) { .timer = 4, .tile_num_attributes = OAM_DATA(0, 0, 2, 5, 75), };
  case PROJ_TRAIL_DRAW(AnyMissile, 4, 0)                       : return (ProjectileTrailInstr) { .timer = 0, };

  default: Unreachable(); return (ProjectileTrailInstr) {0};
  }
}

static const uint16 kLeftProjTrailInstrListPtrs[39] = {  // 0x90B5BB
  [kProjectileType_Power]                                           = PROJ_TRAIL(Empty),
  [kProjectileType_Wave]                                            = PROJ_TRAIL(WaveBeam),
  [kProjectileType_Ice]                                             = PROJ_TRAIL(IceBeams_ChargedPowerBeam_Left),
  [kProjectileType_Ice|kProjectileType_Wave]                        = PROJ_TRAIL(IceBeams_ChargedPowerBeam_Left),
  [kProjectileType_Spazer]                                          = PROJ_TRAIL(Empty),
  [kProjectileType_Spazer|kProjectileType_Wave]                     = PROJ_TRAIL(Empty),
  [kProjectileType_Spazer|kProjectileType_Ice]                      = PROJ_TRAIL(IceBeams_ChargedPowerBeam_Left),
  [kProjectileType_Spazer|kProjectileType_Ice|kProjectileType_Wave] = PROJ_TRAIL(IceBeams_ChargedPowerBeam_Left),
  [kProjectileType_Plasma]                                          = PROJ_TRAIL(Empty),
  [kProjectileType_Plasma|kProjectileType_Wave]                     = PROJ_TRAIL(Empty),
  [kProjectileType_Plasma|kProjectileType_Ice]                      = PROJ_TRAIL(IceBeams_ChargedPowerBeam_Left),
  [kProjectileType_Plasma|kProjectileType_Ice|kProjectileType_Wave] = PROJ_TRAIL(IceBeams_ChargedPowerBeam_Left),
  PROJ_TRAIL(Empty),
  PROJ_TRAIL(Empty),
  PROJ_TRAIL(Empty),
  PROJ_TRAIL(Empty),
  [kProjectileType_Charged|kProjectileType_Power]                                           = PROJ_TRAIL(IceBeams_ChargedPowerBeam_Left),
  [kProjectileType_Charged|kProjectileType_Wave]                                            = PROJ_TRAIL(WaveBeam),
  [kProjectileType_Charged|kProjectileType_Ice]                                             = PROJ_TRAIL(IceBeams_ChargedPowerBeam_Left),
  [kProjectileType_Charged|kProjectileType_Ice|kProjectileType_Wave]                        = PROJ_TRAIL(IceBeams_ChargedPowerBeam_Left),
  [kProjectileType_Charged|kProjectileType_Spazer]                                          = PROJ_TRAIL(Empty),
  [kProjectileType_Charged|kProjectileType_Spazer|kProjectileType_Wave]                     = PROJ_TRAIL(Empty),
  [kProjectileType_Charged|kProjectileType_Spazer|kProjectileType_Ice]                      = PROJ_TRAIL(IceBeams_ChargedPowerBeam_Left),
  [kProjectileType_Charged|kProjectileType_Spazer|kProjectileType_Ice|kProjectileType_Wave] = PROJ_TRAIL(IceBeams_ChargedPowerBeam_Left),
  [kProjectileType_Charged|kProjectileType_Plasma]                                          = PROJ_TRAIL(Empty),
  [kProjectileType_Charged|kProjectileType_Plasma|kProjectileType_Wave]                     = PROJ_TRAIL(Empty),
  [kProjectileType_Charged|kProjectileType_Plasma|kProjectileType_Ice]                      = PROJ_TRAIL(IceBeams_ChargedPowerBeam_Left),
  [kProjectileType_Charged|kProjectileType_Plasma|kProjectileType_Ice|kProjectileType_Wave] = PROJ_TRAIL(IceBeams_ChargedPowerBeam_Left),
  PROJ_TRAIL(Empty),
  PROJ_TRAIL(Empty),
  PROJ_TRAIL(Empty),
  PROJ_TRAIL(Empty),
  [(kProjectileType_Missile>>8) + 0x1F] = PROJ_TRAIL(AnyMissile),
  [(kProjectileType_SuperMissile>>8) + 0x1F] = PROJ_TRAIL(AnyMissile),
  PROJ_TRAIL(Empty),
  PROJ_TRAIL(Empty),
  [kProjectileType_SpazerSbaTrail] = PROJ_TRAIL(IceBeams_ChargedPowerBeam_Left),
  PROJ_TRAIL(IceBeams_ChargedPowerBeam_Left),
  PROJ_TRAIL(IceBeams_ChargedPowerBeam_Left),
};

static const uint16 kRightProjTrailInstrListPtrs[39] = {  // 0x90B609
  [kProjectileType_Power]                                           = PROJ_TRAIL(Empty),
  [kProjectileType_Wave]                                            = PROJ_TRAIL(Empty),
  [kProjectileType_Ice]                                             = PROJ_TRAIL(Empty),
  [kProjectileType_Ice|kProjectileType_Wave]                        = PROJ_TRAIL(Empty),
  [kProjectileType_Spazer]                                          = PROJ_TRAIL(Empty),
  [kProjectileType_Spazer|kProjectileType_Wave]                     = PROJ_TRAIL(Empty),
  [kProjectileType_Spazer|kProjectileType_Ice]                      = PROJ_TRAIL(SomeIceBeams_Right),
  [kProjectileType_Spazer|kProjectileType_Ice|kProjectileType_Wave] = PROJ_TRAIL(SomeIceBeams_Right),
  [kProjectileType_Plasma]                                          = PROJ_TRAIL(Empty),
  [kProjectileType_Plasma|kProjectileType_Wave]                     = PROJ_TRAIL(Empty),
  [kProjectileType_Plasma|kProjectileType_Ice]                      = PROJ_TRAIL(Empty),
  [kProjectileType_Plasma|kProjectileType_Ice|kProjectileType_Wave] = PROJ_TRAIL(SomeIceBeams_Right),
  PROJ_TRAIL(Empty),
  PROJ_TRAIL(Empty),
  PROJ_TRAIL(Empty),
  PROJ_TRAIL(Empty),
  [kProjectileType_Charged|kProjectileType_Power]                                           = PROJ_TRAIL(Empty),
  [kProjectileType_Charged|kProjectileType_Wave]                                            = PROJ_TRAIL(WaveBeam),
  [kProjectileType_Charged|kProjectileType_Ice]                                             = PROJ_TRAIL(Empty),
  [kProjectileType_Charged|kProjectileType_Ice|kProjectileType_Wave]                        = PROJ_TRAIL(SomeIceBeams_Right),
  [kProjectileType_Charged|kProjectileType_Spazer]                                          = PROJ_TRAIL(Empty),
  [kProjectileType_Charged|kProjectileType_Spazer|kProjectileType_Wave]                     = PROJ_TRAIL(Empty),
  [kProjectileType_Charged|kProjectileType_Spazer|kProjectileType_Ice]                      = PROJ_TRAIL(SomeIceBeams_Right),
  [kProjectileType_Charged|kProjectileType_Spazer|kProjectileType_Ice|kProjectileType_Wave] = PROJ_TRAIL(SomeIceBeams_Right),
  [kProjectileType_Charged|kProjectileType_Plasma]                                          = PROJ_TRAIL(Empty),
  [kProjectileType_Charged|kProjectileType_Plasma|kProjectileType_Wave]                     = PROJ_TRAIL(Empty),
  [kProjectileType_Charged|kProjectileType_Plasma|kProjectileType_Ice]                      = PROJ_TRAIL(Empty),
  [kProjectileType_Charged|kProjectileType_Plasma|kProjectileType_Ice|kProjectileType_Wave] = PROJ_TRAIL(SomeIceBeams_Right),
  PROJ_TRAIL(Empty),
  PROJ_TRAIL(Empty),
  PROJ_TRAIL(Empty),
  PROJ_TRAIL(Empty),
  [(kProjectileType_Missile>>8) + 0x1F] = PROJ_TRAIL(Empty),
  [(kProjectileType_SuperMissile>>8) + 0x1F] = PROJ_TRAIL(Empty),
  PROJ_TRAIL(Empty),
  PROJ_TRAIL(Empty),
  [kProjectileType_SpazerSbaTrail] = PROJ_TRAIL(IceBeams_ChargedPowerBeam_Left),
  PROJ_TRAIL(SomeIceBeams_Right),
  PROJ_TRAIL(IceBeams_ChargedPowerBeam_Left),
};

static const ProjectileOriginOffsetDirection kFlareOriginOffsets_Default_X = {  // 0x90C1A8
    .up_face_right = 2,   .up_right = 18, .right = 15, .down_right = 17, .down_face_right = 3,
  .down_face_left = -4, .down_left = -17, .left = -15,   .up_left = -18,   .up_face_left = -2,
  .turn_aim_upward = -4, .turn_aim_neutral = -4, .turn_aim_downward = -4,
};
static const ProjectileOriginOffsetDirection kFlareOriginOffsets_Default_Y = {  // 0x90C1C2
  .up_face_right = -28, .up_right = -19, .right = 1, .down_right = 6, .down_face_right = 17,
  .down_face_left = 17,  .down_left = 6,  .left = 1,  .up_left = -20,   .up_face_left = -28,
  .turn_aim_upward = -20, .turn_aim_neutral = -2, .turn_aim_downward = 8
};

static const ProjectileOriginOffsetDirection kFlareOriginOffsets_Running_X = {  // 0x90C1DC
    .up_face_right = 2,   .up_right = 19, .right = 20, .down_right = 18, .down_face_right = 3,
  .down_face_left = -4, .down_left = -18, .left = -20,   .up_left = -19,   .up_face_left = -2,
};
static const ProjectileOriginOffsetDirection kFlareOriginOffsets_Running_Y = {  // 0x90C1F0
  .up_face_right = -32, .up_right = -22, .right = -3, .down_right = 6, .down_face_right = 25,
  .down_face_left = 25,  .down_left = 6, . left = -3,  .up_left = -20,   .up_face_left = -32,
};

static const ProjectileOriginOffsetDirection kProjectileOriginOffsets_Default_X = {  // 0x90C204
    .up_face_right = 2,   .up_right = 13, .right = 11, .down_right = 13, .down_face_right = 2,
  .down_face_left = -5, .down_left = -14, .left = -11,   .up_left = -19,   .up_face_left = -2,
};
static const ProjectileOriginOffsetDirection kProjectileOriginOffsets_Default_Y = {  // 0x90C218
   .up_face_right = -8, .up_right = -13, .right = 1, .down_right = 4, .down_face_right = 13,
  .down_face_left = 13,  .down_left = 4,  .left = 1,  .up_left = -19,    .up_face_left = -8,
};

static const ProjectileOriginOffsetDirection kProjectileOriginOffsets_Moonwalk_AimUp_Running_X = {  // 0x90C22C
    .up_face_right = 2,   .up_right = 15, .right = 15, .down_right = 13, .down_face_right = 2,
  .down_face_left = -5, .down_left = -13, .left = -13,   .up_left = -15,   .up_face_left = -2,
};
static const ProjectileOriginOffsetDirection kProjectileOriginOffsets_Moonwalk_AimUp_Running_Y = {  // 0x90C240
   .up_face_right = -8, .up_right = -16, .right = -2, .down_right = 1, .down_face_right = 13,
  .down_face_left = 13,  .down_left = 1,  .left = -2,  .up_left = -16,    .up_face_left = -8,
};

static const uint8 kProjectileCooldown_Uncharged[38] = {  // 0x90C254
  [kProjectileType_Power]                                           = 15,
  [kProjectileType_Wave]                                            = 15,
  [kProjectileType_Ice]                                             = 15,
  [kProjectileType_Ice|kProjectileType_Wave]                        = 15,
  [kProjectileType_Spazer]                                          = 15,
  [kProjectileType_Spazer|kProjectileType_Wave]                     = 15,
  [kProjectileType_Spazer|kProjectileType_Ice]                      = 15,
  [kProjectileType_Spazer|kProjectileType_Ice|kProjectileType_Wave] = 15,
  [kProjectileType_Plasma]                                          = 15,
  [kProjectileType_Plasma|kProjectileType_Wave]                     = 15,
  [kProjectileType_Plasma|kProjectileType_Ice]                      = 12,
  [kProjectileType_Plasma|kProjectileType_Ice|kProjectileType_Wave] = 15,
  0,
  0,
  0,
  0,
  [kProjectileType_Charged|kProjectileType_Power]                                           = 30,
  [kProjectileType_Charged|kProjectileType_Wave]                                            = 30,
  [kProjectileType_Charged|kProjectileType_Ice]                                             = 30,
  [kProjectileType_Charged|kProjectileType_Ice|kProjectileType_Wave]                        = 30,
  [kProjectileType_Charged|kProjectileType_Spazer]                                          = 30,
  [kProjectileType_Charged|kProjectileType_Spazer|kProjectileType_Wave]                     = 30,
  [kProjectileType_Charged|kProjectileType_Spazer|kProjectileType_Ice]                      = 30,
  [kProjectileType_Charged|kProjectileType_Spazer|kProjectileType_Ice|kProjectileType_Wave] = 30,
  [kProjectileType_Charged|kProjectileType_Plasma]                                          = 30,
  [kProjectileType_Charged|kProjectileType_Plasma|kProjectileType_Wave]                     = 30,
  [kProjectileType_Charged|kProjectileType_Plasma|kProjectileType_Ice]                      = 30,
  [kProjectileType_Charged|kProjectileType_Plasma|kProjectileType_Ice|kProjectileType_Wave] = 30,
  0,
  0,
  0,
  0,
  0, 0, 0, 0, 0, 0,
};

static const uint8 kNonBeamProjectileCooldowns[9] = {  // 0x90C27A
  0,
  [kProjectileType_Missile>>8] = 10,
  [kProjectileType_SuperMissile>>8] = 20,
  [kProjectileType_PowerBomb>>8] = 40,
  0,
  [kProjectileType_Bomb>>8] = 0x10,
  0,
  0,
  0,
};

static const uint8 kBeamAutoFireCooldowns[12] = {  // 0x90C283
  25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25,
};

static const uint16 kUnchargedProjectile_Sfx[12] = {  // 0x90C28F
  [kProjectileType_Power]                                           = kSfx1_UnchargedPowerBeam,
  [kProjectileType_Wave]                                            = kSfx1_UnchargedWaveBeam,
  [kProjectileType_Ice]                                             = kSfx1_UnchargedIceBeam,
  [kProjectileType_Ice|kProjectileType_Wave]                        = kSfx1_UnchargedIceWaveBeam,
  [kProjectileType_Spazer]                                          = kSfx1_UnchargedSpazerBeam,
  [kProjectileType_Spazer|kProjectileType_Wave]                     = kSfx1_UnchargedSpazerWaveBeam,
  [kProjectileType_Spazer|kProjectileType_Ice]                      = kSfx1_UnchargedSpazerIceBeam,
  [kProjectileType_Spazer|kProjectileType_Ice|kProjectileType_Wave] = kSfx1_UnchargedSpazerIceWaveBeam,
  [kProjectileType_Plasma]                                          = kSfx1_UnchargedPlasmaBeam,
  [kProjectileType_Plasma|kProjectileType_Wave]                     = kSfx1_UnchargedPlasmaWaveBeam,
  [kProjectileType_Plasma|kProjectileType_Ice]                      = kSfx1_UnchargedPlasmaIceBeam,
  [kProjectileType_Plasma|kProjectileType_Ice|kProjectileType_Wave] = kSfx1_UnchargedPlasmaIceWaveBeam,
};

static const uint16 kChargedProjectile_Sfx[12] = {  // 0x90C2A7
  [kProjectileType_Power]                                           = kSfx1_ChargedPowerBeam,
  [kProjectileType_Wave]                                            = kSfx1_ChargedWaveBeam,
  [kProjectileType_Ice]                                             = kSfx1_ChargedIceBeam,
  [kProjectileType_Ice|kProjectileType_Wave]                        = kSfx1_ChargedIceWaveBeam,
  [kProjectileType_Spazer]                                          = kSfx1_ChargedSpazerBeam,
  [kProjectileType_Spazer|kProjectileType_Wave]                     = kSfx1_ChargedSpazerWaveBeam,
  [kProjectileType_Spazer|kProjectileType_Ice]                      = kSfx1_ChargedSpazerIceBeam,
  [kProjectileType_Spazer|kProjectileType_Ice|kProjectileType_Wave] = kSfx1_ChargedSpazerIceWaveBeam,
  [kProjectileType_Plasma]                                          = kSfx1_ChargedPlasmaBeamHyperBeam,
  [kProjectileType_Plasma|kProjectileType_Wave]                     = kSfx1_ChargedPlasmaWaveBeam,
  [kProjectileType_Plasma|kProjectileType_Ice]                      = kSfx1_ChargedPlasmaIceBeam,
  [kProjectileType_Plasma|kProjectileType_Ice|kProjectileType_Wave] = kSfx1_ChargedPlasmaIceWaveBeam,
};

static const uint16 kNonBeamProjectile_Sfx[9] = {  // 0x90C2BF
  0,
  [kProjectileType_Missile>>8] = kSfx1_Missile,
  [kProjectileType_SuperMissile>>8] = kSfx1_SuperMissile,
  0,
  0,
  0,
  0,
  0,
  0,
};

static const BeamSpeed kInitialBeamSpeed[12] = {  // 0x90C2D1
  [kProjectileType_Power]                                           = { .horiz_vert_speed = 0x400, .diag_speed = 0x2ab },
  [kProjectileType_Wave]                                            = { .horiz_vert_speed = 0x400, .diag_speed = 0x2ab },
  [kProjectileType_Ice]                                             = { .horiz_vert_speed = 0x400, .diag_speed = 0x2ab },
  [kProjectileType_Ice|kProjectileType_Wave]                        = { .horiz_vert_speed = 0x400, .diag_speed = 0x2ab },
  [kProjectileType_Spazer]                                          = { .horiz_vert_speed = 0x400, .diag_speed = 0x2ab },
  [kProjectileType_Spazer|kProjectileType_Wave]                     = { .horiz_vert_speed = 0x400, .diag_speed = 0x2ab },
  [kProjectileType_Spazer|kProjectileType_Ice]                      = { .horiz_vert_speed = 0x400, .diag_speed = 0x2ab },
  [kProjectileType_Spazer|kProjectileType_Ice|kProjectileType_Wave] = { .horiz_vert_speed = 0x400, .diag_speed = 0x2ab },
  [kProjectileType_Plasma]                                          = { .horiz_vert_speed = 0x400, .diag_speed = 0x2ab },
  [kProjectileType_Plasma|kProjectileType_Wave]                     = { .horiz_vert_speed = 0x400, .diag_speed = 0x2ab },
  [kProjectileType_Plasma|kProjectileType_Ice]                      = { .horiz_vert_speed = 0x400, .diag_speed = 0x2ab },
  [kProjectileType_Plasma|kProjectileType_Ice|kProjectileType_Wave] = { .horiz_vert_speed = 0x400, .diag_speed = 0x2ab },
};

static const MissileAcceleration kMissileAccelerations[10] = {
  [kProjectileDir_UpFaceRight]   = { .x_accel =    0x0, .y_accel =  -0x40, },
  [kProjectileDir_UpRight]       = { .x_accel =   0x36, .y_accel =  -0x36, },
  [kProjectileDir_Right]         = { .x_accel =   0x40, .y_accel =    0x0, },
  [kProjectileDir_DownRight]     = { .x_accel =   0x36, .y_accel =   0x36, },
  [kProjectileDir_DownFaceRight] = { .x_accel =    0x0, .y_accel =   0x40, },
  [kProjectileDir_DownFaceLeft]  = { .x_accel =    0x0, .y_accel =   0x40, },
  [kProjectileDir_DownLeft]      = { .x_accel =  -0x36, .y_accel =   0x36, },
  [kProjectileDir_Left]          = { .x_accel =  -0x40, .y_accel =    0x0, },
  [kProjectileDir_UpLeft]        = { .x_accel =  -0x36, .y_accel =  -0x36, },
  [kProjectileDir_UpFaceLeft]    = { .x_accel =    0x0, .y_accel =  -0x40, },
};

static const MissileAcceleration kSuperMissileAccelerations[10] = {
  [kProjectileDir_UpFaceRight]   = { .x_accel =    0x0, .y_accel = -0x100, },
  [kProjectileDir_UpRight]       = { .x_accel =   0xb6, .y_accel =  -0xb6, },
  [kProjectileDir_Right]         = { .x_accel =  0x100, .y_accel =    0x0, },
  [kProjectileDir_DownRight]     = { .x_accel =   0xb6, .y_accel =   0xb6, },
  [kProjectileDir_DownFaceRight] = { .x_accel =    0x0, .y_accel =  0x100, },
  [kProjectileDir_DownFaceLeft]  = { .x_accel =    0x0, .y_accel =  0x100, },
  [kProjectileDir_DownLeft]      = { .x_accel =  -0xb6, .y_accel =   0xb6, },
  [kProjectileDir_Left]          = { .x_accel = -0x100, .y_accel =    0x0, },
  [kProjectileDir_UpLeft]        = { .x_accel =  -0xb6, .y_accel =  -0xb6, },
  [kProjectileDir_UpFaceLeft]    = { .x_accel =    0x0, .y_accel = -0x100, },
};

//#define kDrawArmCannon_TilePtr ((uint16*)RomFixedPtr(0x90c7a5))
static const uint16 kDrawArmCannon_VerticalTilePtrs[4] = {  // 0x90C7B9
  0, 0x9A00, 0x9C00, 0x9E00, 
};

static const uint16 kDrawArmCannon_HorizontalTilePtrs[4] = {  // 0x90C7C1
  0, 0xA000, 0xA200, 0xA400, 
};

static const uint16 kDrawArmCannon_DownwardDiagonalTilePtrs[4] = {  // 0x90C7C9
  0, 0xA600, 0xA800, 0xAA00, 
};

static const uint16 kDrawArmCannon_UpwardDiagonalTilePtrs[4] = {  // 0x90C7D1
  0, 0xAC00, 0xAE00, 0xB000, 
};

static const uint16* kDrawArmCannon_TilePtr[10] = {  // 0x90C7A5
  [kProjectileDir_UpFaceRight]   = kDrawArmCannon_VerticalTilePtrs,
  [kProjectileDir_UpRight]       = kDrawArmCannon_UpwardDiagonalTilePtrs,
  [kProjectileDir_Right]         = kDrawArmCannon_HorizontalTilePtrs,
  [kProjectileDir_DownRight]     = kDrawArmCannon_DownwardDiagonalTilePtrs,
  [kProjectileDir_DownFaceRight] = kDrawArmCannon_VerticalTilePtrs,
  [kProjectileDir_DownFaceLeft]  = kDrawArmCannon_VerticalTilePtrs,
  [kProjectileDir_DownLeft]      = kDrawArmCannon_DownwardDiagonalTilePtrs,
  [kProjectileDir_Left]          = kDrawArmCannon_HorizontalTilePtrs,
  [kProjectileDir_UpLeft]        = kDrawArmCannon_UpwardDiagonalTilePtrs,
  [kProjectileDir_UpFaceLeft]    = kDrawArmCannon_VerticalTilePtrs, 
};

static const MarkMapTileExplored kBossRoomMapTile_Kraid[5] = {  // 0x90A852
  [0] = { .room_pixel_x_offset =    0x0, .room_pixel_y_offset =    0x0, },
  [1] = { .room_pixel_x_offset =  0x100, .room_pixel_y_offset =    0x0, },
  [2] = { .room_pixel_x_offset =    0x0, .room_pixel_y_offset =  0x100, },
  [3] = { .room_pixel_x_offset =  0x100, .room_pixel_y_offset =  0x100, },
  0xFFFF,
};

static const MarkMapTileExplored kBossRoomMapTile_Crocomire[4] = {  // 0x90A864
  [0] = { .room_pixel_x_offset =  0x300, .room_pixel_y_offset =    0x0, },
  [1] = { .room_pixel_x_offset =  0x400, .room_pixel_y_offset =    0x0, },
  [2] = { .room_pixel_x_offset =  0x500, .room_pixel_y_offset =    0x0, },
  0xFFFF,
};

static const MarkMapTileExplored kBossRoomMapTile_Phantoon[2] = {  // 0x90A872
  [0] = { .room_pixel_x_offset =    0x0, .room_pixel_y_offset =    0x0, },
  0xFFFF,
};

static const MarkMapTileExplored kBossRoomMapTile_Draygon[5] = {  // 0x90A878
  [0] = { .room_pixel_x_offset =    0x0, .room_pixel_y_offset =    0x0, },
  [1] = { .room_pixel_x_offset =  0x100, .room_pixel_y_offset =    0x0, },
  [2] = { .room_pixel_x_offset =    0x0, .room_pixel_y_offset =  0x100, },
  [3] = { .room_pixel_x_offset =  0x100, .room_pixel_y_offset =  0x100, },
  0xFFFF,
};

static const MarkMapTileExplored kBossRoomMapTile_MotherBrain[5] = {  // 0x90A88A
  [0] = { .room_pixel_x_offset =    0x0, .room_pixel_y_offset =    0x0, },
  [1] = { .room_pixel_x_offset =  0x100, .room_pixel_y_offset =    0x0, },
  [2] = { .room_pixel_x_offset =  0x200, .room_pixel_y_offset =    0x0, },
  [3] = { .room_pixel_x_offset =  0x300, .room_pixel_y_offset =    0x0, },
  0xFFFF,
};

static const MarkMapTileExplored kBossRoomMapTile_Ridley[3] = {  // 0x90A89C
  [0] = { .room_pixel_x_offset =    0x0, .room_pixel_y_offset =    0x0, },
  [1] = { .room_pixel_x_offset =    0x0, .room_pixel_y_offset =  0x100, },
  0xFFFF,
};

static const DisableMinimapAndMarkBossRoomAsExploredEnt kBossRoomMapTile[6] = {  // 0x90A83A
  [0] = { .boss_id_ = kBossId_3_Kraid        , .ptrs = kBossRoomMapTile_Kraid       },
  [1] = { .boss_id_ = kBossId_6_Crocomire    , .ptrs = kBossRoomMapTile_Crocomire   },
  [2] = { .boss_id_ = kBossId_7_Phantoon     , .ptrs = kBossRoomMapTile_Phantoon    },
  [3] = { .boss_id_ = kBossId_8_Draygon      , .ptrs = kBossRoomMapTile_Draygon     },
  [4] = { .boss_id_ = kBossId_10_MotherBrain , .ptrs = kBossRoomMapTile_MotherBrain },
  [5] = { .boss_id_ = kBossId_5_Ridley       , .ptrs = kBossRoomMapTile_Ridley      },
};

static const uint16 kAtmosphericGraphicAnimationTimers[9][9] = {  // 0x908B93
  [kAtmosphericGraphicType_0_None]                  = { 0 },
  [kAtmosphericGraphicType_1_FootstepSplashes]      = { 3, 3, 3, 3, },
  [kAtmosphericGraphicType_2_FootstepSplashes]      = { 3, 3, 3, 3, },
  [kAtmosphericGraphicType_3_DivingSplashes]        = { 2, 2, 3, 3, 3, 5, 5, 6, 7, },
  [kAtmosphericGraphicType_4_LavaAcidSurfaceDamage] = { 2, 2, 2, 2, },
  [kAtmosphericGraphicType_5_Bubbles]               = { 5, 5, 5, 5, 5, 5, 5, 5, },
  [kAtmosphericGraphicType_6_LandingDust]           = { 3, 4, 5, 6, },
  [kAtmosphericGraphicType_7_SpeedBoostDust]        = { 3, 4, 5, 6, },
  [8] = { 0 },
};

static const uint16 kAtmosphericTypeTileNumAndAttributes_Splash[4] = {
  OAM_DATA(0, 0, 2, 5, 44), OAM_DATA(0, 0, 2, 5, 45), OAM_DATA(0, 0, 2, 5, 46), OAM_DATA(0, 0, 2, 5, 47),
};

static const uint16 kAtmosphericTypeTileNumAndAttributes_Dust[4] = {
  OAM_DATA(0, 0, 2, 5, 72), OAM_DATA(0, 0, 2, 5, 73), OAM_DATA(0, 0, 2, 5, 74), OAM_DATA(0, 0, 2, 5, 75),
};

static const uint16* kAtmosphericTypeTileNumAndAttributes[8] = {
  [kAtmosphericGraphicType_0_None]                  = 0,
  [kAtmosphericGraphicType_1_FootstepSplashes]      = kAtmosphericTypeTileNumAndAttributes_Splash,
  [kAtmosphericGraphicType_2_FootstepSplashes]      = 0,
  [kAtmosphericGraphicType_3_DivingSplashes]        = 0,
  [kAtmosphericGraphicType_4_LavaAcidSurfaceDamage] = kAtmosphericTypeTileNumAndAttributes_Dust,
  [kAtmosphericGraphicType_5_Bubbles]               = 0,
  [kAtmosphericGraphicType_6_LandingDust]           = kAtmosphericTypeTileNumAndAttributes_Dust,
  [kAtmosphericGraphicType_7_SpeedBoostDust]        = kAtmosphericTypeTileNumAndAttributes_Dust,
};

static const int16 kProjDirAccel_X[10] = {  // 0x90C353
  [kProjectileDir_UpFaceRight] = 0,
  [kProjectileDir_UpRight] = 16,
  [kProjectileDir_Right] = 16,
  [kProjectileDir_DownRight] = 16,
  [kProjectileDir_DownFaceRight] = 0,
  [kProjectileDir_DownFaceLeft] = 0,
  [kProjectileDir_DownLeft] = -16,
  [kProjectileDir_Left] = -16,
  [kProjectileDir_UpLeft] = -16,
  [kProjectileDir_UpFaceLeft] = 0,
};
static const int16 kProjDirAccel_Y[10] = {  // 0x90C367
  [kProjectileDir_UpFaceRight] = -16,
  [kProjectileDir_UpRight] = -16,
  [kProjectileDir_Right] = 0,
  [kProjectileDir_DownRight] = 16,
  [kProjectileDir_DownFaceRight] = 16,
  [kProjectileDir_DownFaceLeft] = 16,
  [kProjectileDir_DownLeft] = 16,
  [kProjectileDir_Left] = 0,
  [kProjectileDir_UpLeft] = -16,
  [kProjectileDir_UpFaceLeft] = -16
};


static const ArmCannonDrawingData kArmCannonDrawingData_09[1] = {  // 0x90C9D9
  [0] = { .direction = kProjectileDir_UpFaceRight, .draw_mode = kArmCannonDrawingMode_0_NoDraw },
};
static const ArmCannonDrawingData kArmCannonDrawingData_00[1] = {  // 0x90C9DB
  [0] = { .direction = kProjectileDir_UpFaceRight, .draw_mode = kArmCannonDrawingMode_2_FaceForward },
};
static const ArmCannonDrawingData kArmCannonDrawingData_01[10] = {  // 0x90C9DD
  [0] = { .direction = kProjectileDir_Right, .draw_mode = kArmCannonDrawingMode_1_Draw },
  [1] = { .x_offset = 11, .y_offset = -3 },
  [2] = { .x_offset = 11, .y_offset = -3 },
  [3] = { .x_offset = 11, .y_offset = -3 },
  [4] = { .x_offset = 11, .y_offset = -3 },
  [5] = { .x_offset = 11, .y_offset = -3 },
  [6] = { .x_offset = 11, .y_offset = -3 },
  [7] = { .x_offset = 11, .y_offset = -3 },
  [8] = { .x_offset = 11, .y_offset = -3 },
  [9] = { .x_offset = 11, .y_offset = -3 },
};
static const ArmCannonDrawingData kArmCannonDrawingData_02[10] = {  // 0x90C9F1
  [0] = { .direction = kProjectileDir_Left, .draw_mode = kArmCannonDrawingMode_1_Draw },
  [1] = { .x_offset = -19, .y_offset = -3 },
  [2] = { .x_offset = -19, .y_offset = -3 },
  [3] = { .x_offset = -19, .y_offset = -3 },
  [4] = { .x_offset = -19, .y_offset = -3 },
  [5] = { .x_offset = -19, .y_offset = -3 },
  [6] = { .x_offset = -19, .y_offset = -3 },
  [7] = { .x_offset = -19, .y_offset = -3 },
  [8] = { .x_offset = -19, .y_offset = -3 },
  [9] = { .x_offset = -19, .y_offset = -3 },
};
static const ArmCannonDrawingData kArmCannonDrawingData_03[4] = {  // 0x90CA05
  [0] = { .frame_zero_direction = 0x80 | kProjectileDir_UpRight, .frame_zero_draw_mode = kArmCannonDrawingMode_1_Draw },
  [1] = { .direction = 0x80 | kProjectileDir_UpFaceRight, .draw_mode = kArmCannonDrawingMode_1_Draw },
  [2] = { .x_offset = 14, .y_offset = -22 },
  [3] = { .x_offset = -2, .y_offset = -31 },
};
static const ArmCannonDrawingData kArmCannonDrawingData_04[4] = {  // 0x90CA0D
  [0] = { .frame_zero_direction = 0x80 | kProjectileDir_UpLeft, .frame_zero_draw_mode = kArmCannonDrawingMode_1_Draw },
  [1] = { .direction = 0x80 | kProjectileDir_UpFaceLeft, .draw_mode = kArmCannonDrawingMode_1_Draw },
  [2] = { .x_offset = -22, .y_offset = -23 },
  [3] = { .x_offset = -6, .y_offset = -31 },
};
static const ArmCannonDrawingData kArmCannonDrawingData_05[2] = {  // 0x90CA15
  [0] = { .direction = kProjectileDir_UpRight, .draw_mode = kArmCannonDrawingMode_1_Draw },
  [1] = { .x_offset = 13, .y_offset = -22 },
};
static const ArmCannonDrawingData kArmCannonDrawingData_06[2] = {  // 0x90CA19
  [0] = { .direction = kProjectileDir_UpLeft, .draw_mode = kArmCannonDrawingMode_1_Draw },
  [1] = { .x_offset = -21, .y_offset = -23 },
};
static const ArmCannonDrawingData kArmCannonDrawingData_07[2] = {  // 0x90CA1D
  [0] = { .direction = kProjectileDir_DownRight, .draw_mode = kArmCannonDrawingMode_1_Draw },
  [1] = { .x_offset = 13, .y_offset = 2 },
};
static const ArmCannonDrawingData kArmCannonDrawingData_08[2] = {  // 0x90CA21
  [0] = { .direction = kProjectileDir_DownLeft, .draw_mode = kArmCannonDrawingMode_1_Draw },
  [1] = { .x_offset = -21, .y_offset = 2 },
};
static const ArmCannonDrawingData kArmCannonDrawingData_0B[11] = {  // 0x90CA25
  [0] = { .direction = kProjectileDir_Right, .draw_mode = kArmCannonDrawingMode_1_Draw },
  [1] = { .x_offset = 17, .y_offset = -6 },
  [2] = { .x_offset = 17, .y_offset = -6 },
  [3] = { .x_offset = 17, .y_offset = -7 },
  [4] = { .x_offset = 17, .y_offset = -8 },
  [5] = { .x_offset = 17, .y_offset = -7 },
  [6] = { .x_offset = 17, .y_offset = -6 },
  [7] = { .x_offset = 17, .y_offset = -7 },
  [8] = { .x_offset = 17, .y_offset = -7 },
  [9] = { .x_offset = 17, .y_offset = -8 },
  [10] = { .x_offset = 17, .y_offset = -7 },
};
static const ArmCannonDrawingData kArmCannonDrawingData_0C[11] = {  // 0x90CA3B
  [0] = { .direction = kProjectileDir_Left, .draw_mode = kArmCannonDrawingMode_1_Draw },
  [1] = { .x_offset = -25, .y_offset = -6 },
  [2] = { .x_offset = -25, .y_offset = -6 },
  [3] = { .x_offset = -25, .y_offset = -8 },
  [4] = { .x_offset = -25, .y_offset = -7 },
  [5] = { .x_offset = -25, .y_offset = -7 },
  [6] = { .x_offset = -25, .y_offset = -6 },
  [7] = { .x_offset = -25, .y_offset = -7 },
  [8] = { .x_offset = -25, .y_offset = -8 },
  [9] = { .x_offset = -25, .y_offset = -7 },
  [10] = { .x_offset = -25, .y_offset = -7 },
};
static const ArmCannonDrawingData kArmCannonDrawingData_0F[11] = {  // 0x90CA51
  [0] = { .direction = kProjectileDir_UpRight, .draw_mode = kArmCannonDrawingMode_1_Draw },
  [1] = { .x_offset = 12, .y_offset = -22 },
  [2] = { .x_offset = 12, .y_offset = -22 },
  [3] = { .x_offset = 12, .y_offset = -23 },
  [4] = { .x_offset = 12, .y_offset = -24 },
  [5] = { .x_offset = 12, .y_offset = -23 },
  [6] = { .x_offset = 12, .y_offset = -22 },
  [7] = { .x_offset = 12, .y_offset = -22 },
  [8] = { .x_offset = 12, .y_offset = -23 },
  [9] = { .x_offset = 12, .y_offset = -24 },
  [10] = { .x_offset = 12, .y_offset = -23 },
};
static const ArmCannonDrawingData kArmCannonDrawingData_10[11] = {  // 0x90CA67
  [0] = { .direction = kProjectileDir_UpLeft, .draw_mode = kArmCannonDrawingMode_1_Draw },
  [1] = { .x_offset = -20, .y_offset = -22 },
  [2] = { .x_offset = -20, .y_offset = -22 },
  [3] = { .x_offset = -20, .y_offset = -23 },
  [4] = { .x_offset = -20, .y_offset = -24 },
  [5] = { .x_offset = -20, .y_offset = -23 },
  [6] = { .x_offset = -20, .y_offset = -22 },
  [7] = { .x_offset = -20, .y_offset = -22 },
  [8] = { .x_offset = -20, .y_offset = -23 },
  [9] = { .x_offset = -20, .y_offset = -24 },
  [10] = { .x_offset = -20, .y_offset = -23 },
};
static const ArmCannonDrawingData kArmCannonDrawingData_11[11] = {  // 0x90CA7D
  [0] = { .direction = kProjectileDir_DownRight, .draw_mode = kArmCannonDrawingMode_1_Draw },
  [1] = { .x_offset = 11, .y_offset = 1 },
  [2] = { .x_offset = 11, .y_offset = 1 },
  [3] = { .x_offset = 11, .y_offset = 0 },
  [4] = { .x_offset = 11, .y_offset = -1 },
  [5] = { .x_offset = 11, .y_offset = 0 },
  [6] = { .x_offset = 11, .y_offset = 1 },
  [7] = { .x_offset = 11, .y_offset = 1 },
  [8] = { .x_offset = 11, .y_offset = 0 },
  [9] = { .x_offset = 11, .y_offset = -1 },
  [10] = { .x_offset = 11, .y_offset = 0 },
};
static const ArmCannonDrawingData kArmCannonDrawingData_12[11] = {  // 0x90CA93
  [0] = { .direction = kProjectileDir_DownLeft, .draw_mode = kArmCannonDrawingMode_1_Draw },
  [1] = { .x_offset = -19, .y_offset = 1 },
  [2] = { .x_offset = -19, .y_offset = 1 },
  [3] = { .x_offset = -19, .y_offset = 0 },
  [4] = { .x_offset = -19, .y_offset = -1 },
  [5] = { .x_offset = -19, .y_offset = 0 },
  [6] = { .x_offset = -19, .y_offset = 1 },
  [7] = { .x_offset = -19, .y_offset = 1 },
  [8] = { .x_offset = -19, .y_offset = 0 },
  [9] = { .x_offset = -19, .y_offset = -1 },
  [10] = { .x_offset = -19, .y_offset = 0 },
};
static const ArmCannonDrawingData kArmCannonDrawingData_13[3] = {  // 0x90CAA9
  [0] = { .direction = kProjectileDir_Right, .draw_mode = kArmCannonDrawingMode_1_Draw },
  [1] = { .x_offset = 11, .y_offset = -3 },
  [2] = { .x_offset = 11, .y_offset = -3 },
};
static const ArmCannonDrawingData kArmCannonDrawingData_14[3] = {  // 0x90CAAF
  [0] = { .direction = kProjectileDir_Left, .draw_mode = kArmCannonDrawingMode_1_Draw },
  [1] = { .x_offset = -19, .y_offset = -3 },
  [2] = { .x_offset = -19, .y_offset = -3 },
};
static const ArmCannonDrawingData kArmCannonDrawingData_15[4] = {  // 0x90CAB5
  [0] = { .frame_zero_direction = 0x80 | kProjectileDir_UpRight, .frame_zero_draw_mode = kArmCannonDrawingMode_1_Draw },
  [1] = { .direction = 0x80 | kProjectileDir_UpFaceRight, .draw_mode = kArmCannonDrawingMode_1_Draw },
  [2] = { .x_offset = 14, .y_offset = -23 },
  [3] = { .x_offset = -2, .y_offset = -32 },
};
static const ArmCannonDrawingData kArmCannonDrawingData_16[4] = {  // 0x90CABD
  [0] = { .frame_zero_direction = 0x80 | kProjectileDir_UpLeft, .frame_zero_draw_mode = kArmCannonDrawingMode_1_Draw },
  [1] = { .direction = 0x80 | kProjectileDir_UpFaceLeft, .draw_mode = kArmCannonDrawingMode_1_Draw },
  [2] = { .x_offset = -22, .y_offset = -24 },
  [3] = { .x_offset = -6, .y_offset = -32 },
};
static const ArmCannonDrawingData kArmCannonDrawingData_17[3] = {  // 0x90CAC5
  [0] = { .direction = kProjectileDir_DownFaceRight, .draw_mode = kArmCannonDrawingMode_1_Draw },
  [1] = { .x_offset = 0, .y_offset = 13 },
  [2] = { .x_offset = 0, .y_offset = 13 },
};
static const ArmCannonDrawingData kArmCannonDrawingData_18[3] = {  // 0x90CACB
  [0] = { .direction = kProjectileDir_DownFaceLeft, .draw_mode = kArmCannonDrawingMode_1_Draw },
  [1] = { .x_offset = -9, .y_offset = 13 },
  [2] = { .x_offset = -9, .y_offset = 13 },
};
static const ArmCannonDrawingData kArmCannonDrawingData_4B[4] = {  // 0x90CAD1
  [0] = { .direction = kProjectileDir_DownRight, .draw_mode = kArmCannonDrawingMode_1_Draw },
  [1] = { .x_offset = -5, .y_offset = 0 },
  [2] = { .x_offset = 6, .y_offset = 2 },
  [3] = { .x_offset = -19, .y_offset = -2 },
};
static const ArmCannonDrawingData kArmCannonDrawingData_51[3] = {  // 0x90CAD9
  [0] = { .direction = kProjectileDir_Right, .draw_mode = kArmCannonDrawingMode_1_Draw },
  [1] = { .x_offset = 11, .y_offset = -3 },
  [2] = { .x_offset = 11, .y_offset = -3 },
};
static const ArmCannonDrawingData kArmCannonDrawingData_52[3] = {  // 0x90CADF
  [0] = { .direction = kProjectileDir_Left, .draw_mode = kArmCannonDrawingMode_1_Draw },
  [1] = { .x_offset = -19, .y_offset = -3 },
  [2] = { .x_offset = -19, .y_offset = -3 },
};
static const ArmCannonDrawingData kArmCannonDrawingData_69[3] = {  // 0x90CAE5
  [0] = { .direction = kProjectileDir_UpRight, .draw_mode = kArmCannonDrawingMode_1_Draw },
  [1] = { .x_offset = 12, .y_offset = -22 },
  [2] = { .x_offset = 12, .y_offset = -22 },
};
static const ArmCannonDrawingData kArmCannonDrawingData_6A[3] = {  // 0x90CAEB
  [0] = { .direction = kProjectileDir_UpLeft, .draw_mode = kArmCannonDrawingMode_1_Draw },
  [1] = { .x_offset = -20, .y_offset = -22 },
  [2] = { .x_offset = -20, .y_offset = -22 },
};
static const ArmCannonDrawingData kArmCannonDrawingData_6B[3] = {  // 0x90CAF1
  [0] = { .direction = kProjectileDir_DownRight, .draw_mode = kArmCannonDrawingMode_1_Draw },
  [1] = { .x_offset = 11, .y_offset = 1 },
  [2] = { .x_offset = 11, .y_offset = 1 },
};
static const ArmCannonDrawingData kArmCannonDrawingData_6C[3] = {  // 0x90CAF7
  [0] = { .direction = kProjectileDir_DownLeft, .draw_mode = kArmCannonDrawingMode_1_Draw },
  [1] = { .x_offset = -19, .y_offset = 1 },
  [2] = { .x_offset = -19, .y_offset = 1 },
};
static const ArmCannonDrawingData kArmCannonDrawingData_67[8] = {  // 0x90CAFD
  [0] = { .direction = kProjectileDir_Right, .draw_mode = kArmCannonDrawingMode_1_Draw },
  [1] = { .x_offset = 11, .y_offset = -3 },
  [2] = { .x_offset = 11, .y_offset = -3 },
  [3] = { .x_offset = 11, .y_offset = -3 },
  [4] = { .x_offset = 11, .y_offset = -3 },
  [5] = { .x_offset = 11, .y_offset = -3 },
  [6] = { .x_offset = 11, .y_offset = -3 },
  [7] = { .x_offset = 11, .y_offset = -3 },
};
static const ArmCannonDrawingData kArmCannonDrawingData_68[8] = {  // 0x90CB0D
  [0] = { .direction = kProjectileDir_Left, .draw_mode = kArmCannonDrawingMode_1_Draw },
  [1] = { .x_offset = -19, .y_offset = -3 },
  [2] = { .x_offset = -19, .y_offset = -3 },
  [3] = { .x_offset = -19, .y_offset = -3 },
  [4] = { .x_offset = -19, .y_offset = -3 },
  [5] = { .x_offset = -19, .y_offset = -3 },
  [6] = { .x_offset = -19, .y_offset = -3 },
  [7] = { .x_offset = -19, .y_offset = -3 },
};
static const ArmCannonDrawingData kArmCannonDrawingData_2B[5] = {  // 0x90CB1D
  [0] = { .frame_zero_direction = 0x80 | kProjectileDir_UpRight, .frame_zero_draw_mode = kArmCannonDrawingMode_1_Draw },
  [1] = { .direction = 0x80 | kProjectileDir_UpFaceRight, .draw_mode = kArmCannonDrawingMode_1_Draw },
  [2] = { .x_offset = 14, .y_offset = -23 },
  [3] = { .x_offset = -2, .y_offset = -32 },
  [4] = { .x_offset = -2, .y_offset = -32 },
};
static const ArmCannonDrawingData kArmCannonDrawingData_2C[5] = {  // 0x90CB27
  [0] = { .frame_zero_direction = 0x80 | kProjectileDir_UpLeft, .frame_zero_draw_mode = kArmCannonDrawingMode_1_Draw },
  [1] = { .direction = 0x80 | kProjectileDir_UpFaceLeft, .draw_mode = kArmCannonDrawingMode_1_Draw },
  [2] = { .x_offset = -22, .y_offset = -24 },
  [3] = { .x_offset = -6, .y_offset = -28 },
  [4] = { .x_offset = -6, .y_offset = -28 },
};
static const ArmCannonDrawingData kArmCannonDrawingData_2D[3] = {  // 0x90CB31
  [0] = { .direction = kProjectileDir_DownFaceRight, .draw_mode = kArmCannonDrawingMode_1_Draw },
  [1] = { .x_offset = 0, .y_offset = 9 },
  [2] = { .x_offset = 0, .y_offset = 9 },
};
static const ArmCannonDrawingData kArmCannonDrawingData_2E[3] = {  // 0x90CB37
  [0] = { .direction = kProjectileDir_DownFaceLeft, .draw_mode = kArmCannonDrawingMode_1_Draw },
  [1] = { .x_offset = -9, .y_offset = 9 },
  [2] = { .x_offset = -9, .y_offset = 9 },
};
static const ArmCannonDrawingData kArmCannonDrawingData_6D[4] = {  // 0x90CB3D
  [0] = { .direction = kProjectileDir_UpRight, .draw_mode = kArmCannonDrawingMode_1_Draw },
  [1] = { .x_offset = 12, .y_offset = -22 },
  [2] = { .x_offset = 12, .y_offset = -22 },
  [3] = { .x_offset = 12, .y_offset = -22 },
};
static const ArmCannonDrawingData kArmCannonDrawingData_6E[4] = {  // 0x90CB45
  [0] = { .direction = kProjectileDir_UpLeft, .draw_mode = kArmCannonDrawingMode_1_Draw },
  [1] = { .x_offset = -20, .y_offset = -22 },
  [2] = { .x_offset = -20, .y_offset = -22 },
  [3] = { .x_offset = -20, .y_offset = -22 },
};
static const ArmCannonDrawingData kArmCannonDrawingData_6F[4] = {  // 0x90CB4D
  [0] = { .direction = kProjectileDir_DownRight, .draw_mode = kArmCannonDrawingMode_1_Draw },
  [1] = { .x_offset = 11, .y_offset = 1 },
  [2] = { .x_offset = 11, .y_offset = 1 },
  [3] = { .x_offset = 11, .y_offset = 1 },
};
static const ArmCannonDrawingData kArmCannonDrawingData_70[4] = {  // 0x90CB55
  [0] = { .direction = kProjectileDir_DownLeft, .draw_mode = kArmCannonDrawingMode_1_Draw },
  [1] = { .x_offset = -19, .y_offset = 1 },
  [2] = { .x_offset = -19, .y_offset = 1 },
  [3] = { .x_offset = -19, .y_offset = 1 },
};
static const ArmCannonDrawingData kArmCannonDrawingData_27[10] = {  // 0x90CB5D
  [0] = { .direction = kProjectileDir_Right, .draw_mode = kArmCannonDrawingMode_1_Draw },
  [1] = { .x_offset = 11, .y_offset = -3 },
  [2] = { .x_offset = 11, .y_offset = -3 },
  [3] = { .x_offset = 11, .y_offset = -3 },
  [4] = { .x_offset = 11, .y_offset = -3 },
  [5] = { .x_offset = 11, .y_offset = -3 },
  [6] = { .x_offset = 11, .y_offset = -3 },
  [7] = { .x_offset = 11, .y_offset = -3 },
  [8] = { .x_offset = 11, .y_offset = -3 },
  [9] = { .x_offset = 11, .y_offset = -3 },
};
static const ArmCannonDrawingData kArmCannonDrawingData_28[10] = {  // 0x90CB71
  [0] = { .direction = kProjectileDir_Left, .draw_mode = kArmCannonDrawingMode_1_Draw },
  [1] = { .x_offset = -19, .y_offset = -3 },
  [2] = { .x_offset = -19, .y_offset = -3 },
  [3] = { .x_offset = -19, .y_offset = -3 },
  [4] = { .x_offset = -19, .y_offset = -3 },
  [5] = { .x_offset = -19, .y_offset = -3 },
  [6] = { .x_offset = -19, .y_offset = -3 },
  [7] = { .x_offset = -19, .y_offset = -3 },
  [8] = { .x_offset = -19, .y_offset = -3 },
  [9] = { .x_offset = -19, .y_offset = -3 },
};
static const ArmCannonDrawingData kArmCannonDrawingData_71[2] = {  // 0x90CB85
  [0] = { .direction = kProjectileDir_UpRight, .draw_mode = kArmCannonDrawingMode_1_Draw },
  [1] = { .x_offset = 14, .y_offset = -23 },
};
static const ArmCannonDrawingData kArmCannonDrawingData_72[2] = {  // 0x90CB89
  [0] = { .direction = kProjectileDir_UpLeft, .draw_mode = kArmCannonDrawingMode_1_Draw },
  [1] = { .x_offset = -22, .y_offset = -24 },
};
static const ArmCannonDrawingData kArmCannonDrawingData_73[2] = {  // 0x90CB8D
  [0] = { .direction = kProjectileDir_DownRight, .draw_mode = kArmCannonDrawingMode_1_Draw },
  [1] = { .x_offset = 13, .y_offset = 2 },
};
static const ArmCannonDrawingData kArmCannonDrawingData_74[2] = {  // 0x90CB91
  [0] = { .direction = kProjectileDir_DownLeft, .draw_mode = kArmCannonDrawingMode_1_Draw },
  [1] = { .x_offset = -21, .y_offset = 2 },
};
static const ArmCannonDrawingData kArmCannonDrawingData_85[4] = {  // 0x90CB95
  [0] = { .frame_zero_direction = 0x80 | kProjectileDir_UpRight, .frame_zero_draw_mode = kArmCannonDrawingMode_1_Draw },
  [1] = { .direction = 0x80 | kProjectileDir_UpFaceRight, .draw_mode = kArmCannonDrawingMode_1_Draw },
  [2] = { .x_offset = 14, .y_offset = -23 },
  [3] = { .x_offset = -2, .y_offset = -32 },
};
static const ArmCannonDrawingData kArmCannonDrawingData_86[4] = {  // 0x90CB9D
  [0] = { .frame_zero_direction = 0x80 | kProjectileDir_UpLeft, .frame_zero_draw_mode = kArmCannonDrawingMode_1_Draw },
  [1] = { .direction = 0x80 | kProjectileDir_UpFaceLeft, .draw_mode = kArmCannonDrawingMode_1_Draw },
  [2] = { .x_offset = -22, .y_offset = -24 },
  [3] = { .x_offset = -6, .y_offset = -32 },
};
static const ArmCannonDrawingData kArmCannonDrawingData_49[7] = {  // 0x90CBA5
  [0] = { .direction = kProjectileDir_Right, .draw_mode = kArmCannonDrawingMode_1_Draw },
  [1] = { .x_offset = -15, .y_offset = -3 },
  [2] = { .x_offset = -15, .y_offset = -4 },
  [3] = { .x_offset = -15, .y_offset = -4 },
  [4] = { .x_offset = -15, .y_offset = -3 },
  [5] = { .x_offset = -15, .y_offset = -4 },
  [6] = { .x_offset = -15, .y_offset = -4 },
};
static const ArmCannonDrawingData kArmCannonDrawingData_4A[7] = {  // 0x90CBB3
  [0] = { .direction = kProjectileDir_Left, .draw_mode = kArmCannonDrawingMode_1_Draw },
  [1] = { .x_offset = 7, .y_offset = -3 },
  [2] = { .x_offset = 7, .y_offset = -4 },
  [3] = { .x_offset = 7, .y_offset = -4 },
  [4] = { .x_offset = 7, .y_offset = -3 },
  [5] = { .x_offset = 7, .y_offset = -4 },
  [6] = { .x_offset = 7, .y_offset = -4 },
};
static const ArmCannonDrawingData kArmCannonDrawingData_75[7] = {  // 0x90CBC1
  [0] = { .direction = kProjectileDir_UpLeft, .draw_mode = kArmCannonDrawingMode_1_Draw },
  [1] = { .x_offset = -20, .y_offset = -22 },
  [2] = { .x_offset = -20, .y_offset = -23 },
  [3] = { .x_offset = -20, .y_offset = -23 },
  [4] = { .x_offset = -20, .y_offset = -22 },
  [5] = { .x_offset = -20, .y_offset = -23 },
  [6] = { .x_offset = -20, .y_offset = -23 },
};
static const ArmCannonDrawingData kArmCannonDrawingData_76[7] = {  // 0x90CBCF
  [0] = { .direction = kProjectileDir_UpRight, .draw_mode = kArmCannonDrawingMode_1_Draw },
  [1] = { .x_offset = 12, .y_offset = -22 },
  [2] = { .x_offset = 12, .y_offset = -23 },
  [3] = { .x_offset = 12, .y_offset = -23 },
  [4] = { .x_offset = 12, .y_offset = -22 },
  [5] = { .x_offset = 12, .y_offset = -23 },
  [6] = { .x_offset = 12, .y_offset = -23 },
};
static const ArmCannonDrawingData kArmCannonDrawingData_77[7] = {  // 0x90CBDD
  [0] = { .direction = kProjectileDir_DownLeft, .draw_mode = kArmCannonDrawingMode_1_Draw },
  [1] = { .x_offset = -19, .y_offset = 1 },
  [2] = { .x_offset = -19, .y_offset = 0 },
  [3] = { .x_offset = -19, .y_offset = 0 },
  [4] = { .x_offset = -19, .y_offset = 1 },
  [5] = { .x_offset = -19, .y_offset = 0 },
  [6] = { .x_offset = -19, .y_offset = 0 },
};
static const ArmCannonDrawingData kArmCannonDrawingData_78[7] = {  // 0x90CBEB
  [0] = { .direction = kProjectileDir_DownRight, .draw_mode = kArmCannonDrawingMode_1_Draw },
  [1] = { .x_offset = 11, .y_offset = 1 },
  [2] = { .x_offset = 11, .y_offset = 0 },
  [3] = { .x_offset = 11, .y_offset = 0 },
  [4] = { .x_offset = 11, .y_offset = 1 },
  [5] = { .x_offset = 11, .y_offset = 0 },
  [6] = { .x_offset = 11, .y_offset = 0 },
};
static const ArmCannonDrawingData kArmCannonDrawingData_A4[6] = {  // 0x90CBF9
  [0] = { .direction = kProjectileDir_DownRight, .draw_mode = kArmCannonDrawingMode_1_Draw },
  [1] = { .x_offset = -5, .y_offset = 0 },
  [2] = { .x_offset = -5, .y_offset = 0 },
  [3] = { .x_offset = 6, .y_offset = 2 },
  [4] = { .x_offset = -19, .y_offset = -2 },
  [5] = { .x_offset = -19, .y_offset = -2 },
};
static const ArmCannonDrawingData kArmCannonDrawingData_A6[8] = {  // 0x90CC05
  [0] = { .direction = kProjectileDir_DownRight, .draw_mode = kArmCannonDrawingMode_1_Draw },
  [1] = { .x_offset = -5, .y_offset = 0 },
  [2] = { .x_offset = -5, .y_offset = 0 },
  [3] = { .x_offset = -5, .y_offset = 0 },
  [4] = { .x_offset = 6, .y_offset = 2 },
  [5] = { .x_offset = -19, .y_offset = -2 },
  [6] = { .x_offset = -19, .y_offset = -2 },
  [7] = { .x_offset = -19, .y_offset = -2 },
};
static const ArmCannonDrawingData kArmCannonDrawingData_55[3] = {  // 0x90CC15
  [0] = { .direction = kProjectileDir_UpFaceRight, .draw_mode = kArmCannonDrawingMode_1_Draw },
  [1] = { .x_offset = -2, .y_offset = -31 },
  [2] = { .x_offset = -2, .y_offset = -31 },
};
static const ArmCannonDrawingData kArmCannonDrawingData_56[3] = {  // 0x90CC1B
  [0] = { .direction = kProjectileDir_UpFaceLeft, .draw_mode = kArmCannonDrawingMode_1_Draw },
  [1] = { .x_offset = -6, .y_offset = -31 },
  [2] = { .x_offset = -6, .y_offset = -31 },
};


static const ArmCannonDrawingData* get_ArmCannonDrawingData(uint16 pose) {
  switch (pose) {
  case kPose_09_MoveR_NoAim:
  case kPose_0A_MoveL_NoAim:
  case kPose_0D:
  case kPose_0E:
  case kPose_19_FaceR_SpinJump:
  case kPose_1A_FaceL_SpinJump:
  case kPose_1B_FaceR_SpaceJump:
  case kPose_1C_FaceL_SpaceJump:
  case kPose_1D_FaceR_Morphball_Ground:
  case kPose_1E_MoveR_Morphball_Ground:
  case kPose_1F_MoveL_Morphball_Ground:
  case kPose_20:
  case kPose_21:
  case kPose_22:
  case kPose_23:
  case kPose_24:
  case kPose_25_FaceR_Turn_Stand:
  case kPose_26_FaceL_Turn_Stand:
  case kPose_29_FaceR_Fall:
  case kPose_2A_FaceL_Fall:
  case kPose_2F_FaceR_Turn_Jump:
  case kPose_30_FaceL_Turn_Jump:
  case kPose_31_FaceR_Morphball_Air:
  case kPose_32_FaceL_Morphball_Air:
  case kPose_33:
  case kPose_34:
  case kPose_35_FaceR_CrouchTrans:
  case kPose_36_FaceL_CrouchTrans:
  case kPose_37_FaceR_MorphTrans:
  case kPose_38_FaceL_MorphTrans:
  case kPose_39:
  case kPose_3A:
  case kPose_3B_FaceR_StandTrans:
  case kPose_3C_FaceL_StandTrans:
  case kPose_3D_FaceR_UnmorphTrans:
  case kPose_3E_FaceL_UnmorphTrans:
  case kPose_3F:
  case kPose_40:
  case kPose_41_FaceL_Morphball_Ground:
  case kPose_42:
  case kPose_43_FaceR_Turn_Crouch:
  case kPose_44_FaceL_Turn_Crouch:
  case kPose_45:
  case kPose_46:
  case kPose_4C_FaceL_Jumptrans:
  case kPose_4D_FaceR_Jump_NoAim_NoMove_NoGun:
  case kPose_4E_FaceL_Jump_NoAim_NoMove_NoGun:
  case kPose_4F_FaceL_Dmgboost:
  case kPose_50_FaceR_Dmgboost:
  case kPose_53_FaceR_Knockback:
  case kPose_54_FaceL_Knockback:
  case kPose_5B:
  case kPose_5C:
  case kPose_5D:
  case kPose_5E:
  case kPose_5F:
  case kPose_60:
  case kPose_61:
  case kPose_62:
  case kPose_63:
  case kPose_64:
  case kPose_65:
  case kPose_66:
  case kPose_79_FaceR_Springball_Ground:
  case kPose_7A_FaceL_Springball_Ground:
  case kPose_7B_MoveR_Springball_Ground:
  case kPose_7C_MoveL_Springball_Ground:
  case kPose_7D_FaceR_Springball_Fall:
  case kPose_7E_FaceL_Springball_Fall:
  case kPose_7F_FaceR_Springball_Air:
  case kPose_80_FaceL_Springball_Air:
  case kPose_81_FaceR_Screwattack:
  case kPose_82_FaceL_Screwattack:
  case kPose_83_FaceR_Walljump:
  case kPose_84_FaceL_Walljump:
  case kPose_87_FaceR_Turn_Fall:
  case kPose_88_FaceL_Turn_Fall:
  case kPose_8B_FaceR_Turn_Stand_AimU:
  case kPose_8C_FaceL_Turn_Stand_AimU:
  case kPose_8D_FaceR_Turn_Stand_AimDR:
  case kPose_8E_FaceL_Turn_Stand_AimDL:
  case kPose_8F_FaceR_Turn_Air_AimU:
  case kPose_90_FaceL_Turn_Air_AimU:
  case kPose_91_FaceR_Turn_Air_AimDDR:
  case kPose_92_FaceL_Turn_Air_AimDDL:
  case kPose_93_FaceR_Turn_Fall_AimU:
  case kPose_94_FaceL_Turn_Fall_AimU:
  case kPose_95_FaceR_Turn_Fall_AimDDR:
  case kPose_96_FaceL_Turn_Fall_AimDDL:
  case kPose_97_FaceR_Turn_Crouch_AimU:
  case kPose_98_FaceL_Turn_Crouch_AimU:
  case kPose_99_FaceR_Turn_Crouch_AimDDR:
  case kPose_9A_FaceL_Turn_Crouch_AimDDL:
  case kPose_9C_FaceR_Turn_Stand_AimUR:
  case kPose_9D_FaceL_Turn_Stand_AimUL:
  case kPose_9E_FaceR_Turn_Air_AimUR:
  case kPose_9F_FaceL_Turn_Air_AimUL:
  case kPose_A0_FaceR_Turn_Fall_AimUR:
  case kPose_A1_FaceL_Turn_Fall_AimUL:
  case kPose_A2_FaceR_Turn_Crouch_AimUR:
  case kPose_A3_FaceL_Turn_Crouch_AimUL:
  case kPose_A5_FaceL_LandJump:
  case kPose_A7_FaceL_LandSpinJump:
  case kPose_B2_FaceR_Grapple_Air:
  case kPose_B3_FaceL_Grapple_Air:
  case kPose_B8_FaceL_GrappleWalljumpPose:
  case kPose_B9_FaceR_GrappleWalljumpPose:
  case kPose_BA_FaceL_Draygon_NoMove_NoAim:
  case kPose_BE_FaceL_Draygon_Move:
  case kPose_BF_FaceR_Moonwalk_TurnjumpL:
  case kPose_C0_FaceL_Moonwalk_TurnjumpR:
  case kPose_C1_FaceR_Moonwalk_TurnjumpL_AimUR:
  case kPose_C2_FaceL_Moonwalk_TurnjumpR_AimUL:
  case kPose_C3_FaceR_Moonwalk_TurnjumpL_AimDR:
  case kPose_C4_FaceL_Moonwalk_TurnjumpR_AimDL:
  case kPose_C5:
  case kPose_C6:
  case kPose_C7_FaceR_ShinesparkWindup_Vert:
  case kPose_C8_FaceL_ShinesparkWindup_Vert:
  case kPose_C9_FaceR_Shinespark_Horiz:
  case kPose_CA_FaceL_Shinespark_Horiz:
  case kPose_CB_FaceR_Shinespark_Vert:
  case kPose_CC_FaceL_Shinespark_Vert:
  case kPose_CD_FaceR_Shinespark_Diag:
  case kPose_CE_FaceL_Shinespark_Diag:
  case kPose_D3_FaceR_CrystalFlash:
  case kPose_D4_FaceL_CrystalFlash:
  case kPose_D5_FaceR_Xray_Stand:
  case kPose_D6_FaceL_Xray_Stand:
  case kPose_D7_FaceR_CrystalFlashEnd:
  case kPose_D8_FaceL_CrystalFlashEnd:
  case kPose_D9_FaceR_Xray_Crouch:
  case kPose_DA_FaceL_Xray_Crouch:
  case kPose_DB:
  case kPose_DC:
  case kPose_DD:
  case kPose_DE:
  case kPose_DF:
  case kPose_E8_FaceR_Drained_CrouchFalling:
  case kPose_E9_FaceL_Drained_CrouchFalling:
  case kPose_EA_FaceR_Drained_Stand:
  case kPose_EB_FaceL_Drained_Stand:
  case kPose_EC_FaceR_Draygon_NoMove_NoAim:
  case kPose_F0_FaceR_Draygon_Move:
    return kArmCannonDrawingData_09;
  case kPose_00_FaceF_Powersuit:
  case kPose_9B_FaceF_VariaGravitySuit:
    return kArmCannonDrawingData_00;
  case kPose_01_FaceR_Normal:
  case kPose_47:
  case kPose_89_FaceR_Ranintowall:
  case kPose_A8_FaceR_Grappling:
  case kPose_E6_FaceR_LandJump_Fire:
  case kPose_EE_FaceR_Draygon_Fire:
    return kArmCannonDrawingData_01;
  case kPose_02_FaceL_Normal:
  case kPose_48:
  case kPose_8A_FaceL_Ranintowall:
  case kPose_A9_FaceL_Grappling:
  case kPose_BC_FaceL_Draygon_Fire:
  case kPose_E7_FaceL_LandJump_Fire:
    return kArmCannonDrawingData_02;
  case kPose_03_FaceR_AimU:
    return kArmCannonDrawingData_03;
  case kPose_04_FaceL_AimU:
    return kArmCannonDrawingData_04;
  case kPose_05_FaceR_AimUR:
  case kPose_57_FaceR_Jumptrans_AimUR:
  case kPose_CF_FaceR_Ranintowall_AimUR:
  case kPose_E2_FaceR_LandJump_AimUR:
  case kPose_ED_FaceR_Draygon_NoMove_AimUR:
  case kPose_F3_FaceR_CrouchTrans_AimUR:
  case kPose_F9_FaceR_StandTrans_AimUR:
    return kArmCannonDrawingData_05;
  case kPose_06_FaceL_AimUL:
  case kPose_58_FaceL_Jumptrans_AimUL:
  case kPose_BB_FaceL_Draygon_NoMove_AimUL:
  case kPose_D0_FaceL_Ranintowall_AimUL:
  case kPose_E3_FaceL_LandJump_AimUL:
  case kPose_F4_FaceL_CrouchTrans_AimUL:
  case kPose_FA_FaceL_StandTrans_AimUL:
    return kArmCannonDrawingData_06;
  case kPose_07_FaceR_AimDR:
  case kPose_59_FaceR_Jumptrans_AimDR:
  case kPose_AA_FaceR_Grappling_AimDR:
  case kPose_D1_FaceR_Ranintowall_AimDR:
  case kPose_E4_FaceR_LandJump_AimDR:
  case kPose_EF_FaceR_Draygon_NoMove_AimDR:
  case kPose_F5_FaceR_CrouchTrans_AimDR:
  case kPose_FB_FaceR_StandTrans_AimDR:
    return kArmCannonDrawingData_07;
  case kPose_08_FaceL_AimDL:
  case kPose_5A_FaceL_Jumptrans_AimDL:
  case kPose_AB_FaceL_Grappling_AimDL:
  case kPose_BD_FaceL_Draygon_NoMove_AimDL:
  case kPose_D2_FaceL_Ranintowall_AimDL:
  case kPose_E5_FaceL_LandJump_AimDL:
  case kPose_F6_FaceL_CrouchTrans_AimDL:
  case kPose_FC_FaceL_StandTrans_AimDL:
    return kArmCannonDrawingData_08;
  case kPose_0B_MoveR_Gun:
    return kArmCannonDrawingData_0B;
  case kPose_0C_MoveL_Gun:
    return kArmCannonDrawingData_0C;
  case kPose_0F_MoveR_AimUR:
    return kArmCannonDrawingData_0F;
  case kPose_10_MoveL_AimUL:
    return kArmCannonDrawingData_10;
  case kPose_11_MoveR_AimDR:
    return kArmCannonDrawingData_11;
  case kPose_12_MoveL_AimDL:
    return kArmCannonDrawingData_12;
  case kPose_13_FaceR_Jump_NoAim_NoMove_Gun:
  case kPose_AC:
    return kArmCannonDrawingData_13;
  case kPose_14_FaceL_Jump_NoAim_NoMove_Gun:
  case kPose_AD:
    return kArmCannonDrawingData_14;
  case kPose_15_FaceR_Jump_AimU:
    return kArmCannonDrawingData_15;
  case kPose_16_FaceL_Jump_AimU:
    return kArmCannonDrawingData_16;
  case kPose_17_FaceR_Jump_AimD:
  case kPose_AE:
    return kArmCannonDrawingData_17;
  case kPose_18_FaceL_Jump_AimD:
  case kPose_AF:
    return kArmCannonDrawingData_18;
  case kPose_4B_FaceR_Jumptrans:
    return kArmCannonDrawingData_4B;
  case kPose_51_FaceR_Jump_NoAim_MoveF:
    return kArmCannonDrawingData_51;
  case kPose_52_FaceL_Jump_NoAim_MoveF:
    return kArmCannonDrawingData_52;
  case kPose_69_FaceR_Jump_AimUR:
    return kArmCannonDrawingData_69;
  case kPose_6A_FaceL_Jump_AimUL:
    return kArmCannonDrawingData_6A;
  case kPose_6B_FaceR_Jump_AimDR:
  case kPose_B0:
    return kArmCannonDrawingData_6B;
  case kPose_6C_FaceL_Jump_AimDL:
  case kPose_B1:
    return kArmCannonDrawingData_6C;
  case kPose_67_FaceR_Fall_Gun:
    return kArmCannonDrawingData_67;
  case kPose_68_FaceL_Fall_Gun:
    return kArmCannonDrawingData_68;
  case kPose_2B_FaceR_Fall_AimU:
    return kArmCannonDrawingData_2B;
  case kPose_2C_FaceL_Fall_AimU:
    return kArmCannonDrawingData_2C;
  case kPose_2D_FaceR_Fall_AimD:
    return kArmCannonDrawingData_2D;
  case kPose_2E_FaceL_Fall_AimD:
    return kArmCannonDrawingData_2E;
  case kPose_6D_FaceR_Fall_AimUR:
    return kArmCannonDrawingData_6D;
  case kPose_6E_FaceL_Fall_AimUL:
    return kArmCannonDrawingData_6E;
  case kPose_6F_FaceR_Fall_AimDR:
    return kArmCannonDrawingData_6F;
  case kPose_70_FaceL_Fall_AimDL:
    return kArmCannonDrawingData_70;
  case kPose_27_FaceR_Crouch:
  case kPose_B4_FaceR_Grappling_Crouch:
    return kArmCannonDrawingData_27;
  case kPose_28_FaceL_Crouch:
  case kPose_B5_FaceL_Grappling_Crouch:
    return kArmCannonDrawingData_28;
  case kPose_71_FaceR_Crouch_AimUR:
    return kArmCannonDrawingData_71;
  case kPose_72_FaceL_Crouch_AimUL:
    return kArmCannonDrawingData_72;
  case kPose_73_FaceR_Crouch_AimDR:
  case kPose_B6_FaceR_Grappling_Crouch_AimDR:
    return kArmCannonDrawingData_73;
  case kPose_74_FaceL_Crouch_AimDL:
  case kPose_B7_FaceL_Grappling_Crouch_AimDL:
    return kArmCannonDrawingData_74;
  case kPose_85_FaceR_Crouch_AimU:
    return kArmCannonDrawingData_85;
  case kPose_86_FaceL_Crouch_AimU:
    return kArmCannonDrawingData_86;
  case kPose_49_FaceL_Moonwalk:
    return kArmCannonDrawingData_49;
  case kPose_4A_FaceR_Moonwalk:
    return kArmCannonDrawingData_4A;
  case kPose_75_FaceL_Moonwalk_AimUL:
    return kArmCannonDrawingData_75;
  case kPose_76_FaceR_Moonwalk_AimUR:
    return kArmCannonDrawingData_76;
  case kPose_77_FaceL_Moonwalk_AimDL:
    return kArmCannonDrawingData_77;
  case kPose_78_FaceR_Moonwalk_AimDR:
    return kArmCannonDrawingData_78;
  case kPose_A4_FaceR_LandJump:
    return kArmCannonDrawingData_A4;
  case kPose_A6_FaceR_LandSpinJump:
    return kArmCannonDrawingData_A6;
  case kPose_55_FaceR_Jumptrans_AimU:
  case kPose_E0_FaceR_LandJump_AimU:
  case kPose_F1_FaceR_CrouchTrans_AimU:
  case kPose_F7_FaceR_StandTrans_AimU:
    return kArmCannonDrawingData_55;
  case kPose_56_FaceL_Jumptrans_AimU:
  case kPose_E1_FaceL_LandJump_AimU:
  case kPose_F2_FaceL_CrouchTrans_AimU:
  case kPose_F8_FaceL_StandTrans_AimU:
    return kArmCannonDrawingData_56;
  default: Unreachable(); return (ArmCannonDrawingData*){0};
  }
}


static const uint16 kCostOfSbaInPowerBombs[12] = {  // 0x90CC21
  0,
  [kBeam_Wave] = 1,
  [kBeam_Ice] = 1,
  0,
  [kBeam_Spazer] = 1,
  0,
  0,
  0,
  [kBeam_Plasma] = 1,
  0,
  0,
  0,
};

static const uint16 kIcePlasmaSbaProjectileOriginAngles[8] = {  // 0x90CD08
     0, 0x40, 0x80, 0xc0,
  0x20, 0x60, 0xa0, 0xe0,
};

static const uint16 kBombSpread_Timer[BOMB_PROJ_OFFSET >> 1] = {  // 0x90D8CF
  120,
  110,
  100,
  110,
  120,
};
static const uint16 kBombSpread_Speed_X[BOMB_PROJ_OFFSET >> 1] = {  // 0x90D8D9
  BOMB_SPREAD_LEFT  | 0x100,
  BOMB_SPREAD_LEFT  | 0x80,
  0,
  BOMB_SPREAD_RIGHT | 0x80,
  BOMB_SPREAD_RIGHT | 0x100,
};
static const uint16 kBombSpread_Speed_Y[BOMB_PROJ_OFFSET >> 1] = {  // 0x90D8E3
  0,
  1,
  2,
  1,
  0,
};
static const uint16 kBombSpread_Subspeed_Y[BOMB_PROJ_OFFSET >> 1] = {  // 0x90D8ED
  0,
  0,
  0x8000,
  0,
  0
};
