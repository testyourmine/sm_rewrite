#pragma once

#include "funcs.h"
#include "ida_types.h"
#include "types.h"
#include "variables.h"

#define BLK_VERT_FLIP 0x800
#define SHOT_DISABLED 0xF0

//#define kXrayBlockData ((XrayBlockData*)RomFixedPtr(0x91d2d6))
//#define kSamusPalette_Normal ((uint16*)RomFixedPtr(0x91d727))
//#define kSamusPalette_HyperBeam ((uint16*)RomFixedPtr(0x91d829))
//#define kSamusPalette_NonPseudoScrew ((uint16*)RomFixedPtr(0x91d7d5))
//#define kSamusPalette_PseudoScrew ((uint16*)RomFixedPtr(0x91d7ff))
//#define kSamus_VisorColors ((uint16*)RomFixedPtr(0x9ba3c0))
//#define kSamus_SpeedBoostingPalettes ((uint16*)RomFixedPtr(0x91d998))
//#define kSamus_HyperBeamPalettes ((uint16*)RomFixedPtr(0x91d99e))
//#define kSamusPal_ScrewAttack ((uint16*)RomFixedPtr(0x91da4a))
//#define kSamusPal_SpeedBoost ((uint16*)RomFixedPtr(0x91daa9))
//#define kSamusPal_SpeedBoostShine ((uint16*)RomFixedPtr(0x91db10))
//#define kSamusPal_Shinespark ((uint16*)RomFixedPtr(0x91db75))
//#define kSamusPal_CrystalFlash0to9 ((SamusCrystalFlashPalTable*)RomFixedPtr(0x91dc00))
//#define kSamusPal_CrystalFlash10to15 ((uint16*)RomFixedPtr(0x91dc28))
//#define kSamusNewPose_Falling ((uint16*)RomFixedPtr(0x91e921))
//#define kSamusNewPose_Landing ((uint16*)RomFixedPtr(0x91e9f3))
//#define kSamusNewPose_RanIntoWall ((uint16*)RomFixedPtr(0x91eb74))
//#define kSamusTurnPose_Standing ((uint8*)RomFixedPtr(0x91f9c2))
//#define kSamusTurnPose_Crouching ((uint8*)RomFixedPtr(0x91f9cc))
//#define kSamusTurnPose_Jumping ((uint8*)RomFixedPtr(0x91f9d6))
//#define kSamusTurnPose_Falling ((uint8*)RomFixedPtr(0x91f9e0))
//#define kSamusTurnPose_Moonwalk ((uint8*)RomFixedPtr(0x91f9ea))

XrayBlockData kXrayBlockData[] = {
     0x0, 0xd2fc,
  0x3000, 0xd306,
  0x5000, 0xd310,
  0xa000, 0xd318,
  0xb000, 0xd322,
  0xc000, 0xd3cc,
  0xd000, 0xd462,
  0xe000, 0xd46a,
  0xf000, 0xd484,
  0xffff,
};

uint16 kSamusPalette_Normal[] = {
  0x9400, 0x9520, 0x9800,
};

uint16 kSamusPalette_HyperBeam[] = {
     0x0, 0xa360, 0xa340, 0xa320, 0xa300, 0xa2e0, 0xa2c0, 0xa2a0, 0xa280, 0xa260, 0xa240,
};

uint16 kSamusPalette_NonPseudoScrew[] = {
  0xd7db, 0xd7e7, 0xd7f3,
};

uint16 kSamusPalette_PseudoScrew[] = {
  0xd805, 0xd811, 0xd81d,
};

uint16 kSamus_VisorColors[] = {
  0x3be0, 0x5ff0, 0x7fff, 
  0x43ff, 0x2f5a, 0x1ab5,
};

uint16 kSamus_SpeedBoostingPalettes[] = {
  0x9b80, 0x9d80, 0x9f80,
};

uint16 kSamus_HyperBeamPalettes[] = {
  0xa360, 0xa340, 0xa320, 0xa300, 0xa2e0, 0xa2c0, 0xa2a0, 0xa280, 0xa260, 0xa240,
};

uint16 kSamusPal_ScrewAttack[] = {
  0xda50, 0xda5c, 0xda68,
};

uint16 kSamusPal_SpeedBoost[] = {
  0xdaaf, 0xdab7, 0xdabf,
};

uint16 kSamusPal_SpeedBoostShine[] = {
  0xdb16, 0xdb22, 0xdb2e,
};

uint16 kSamusPal_Shinespark[] = {
  0xdb7b, 0xdb83, 0xdb8b,
};

SamusCrystalFlashPalTable kSamusPal_CrystalFlash0to9[] = {
  0x96c0,10, 0x96e0,10, 0x9700,10, 0x9720,10, 0x9740,10, 0x9760,10, 0x9740,10, 0x9720,10, 0x9700,10, 0x96e0,10,
};

uint16 kSamusPal_CrystalFlash10to15[] = {
  0x96d4, 0x96f4, 0x9714, 0x9734, 0x9754, 0x9774,
};

uint16 kSamusNewPose_Falling[] = {
  kPose_29_FaceR_Fall, kPose_2A_FaceL_Fall,
  kPose_31_FaceR_Morphball_Air, kPose_32_FaceL_Morphball_Air,
  kPose_33, kPose_34,
  kPose_7D_FaceR_Springball_Fall, kPose_7E_FaceL_Springball_Fall,
};

uint16 kSamusNewPose_Landing[] = {
  kPose_E0_FaceR_LandJump_AimU, kPose_E2_FaceR_LandJump_AimUR, kPose_A4_FaceR_LandJump, kPose_E4_FaceR_LandJump_AimDR, kPose_A4_FaceR_LandJump,
  kPose_A5_FaceL_LandJump, kPose_E5_FaceL_LandJump_AimDL, kPose_A5_FaceL_LandJump, kPose_E3_FaceL_LandJump_AimUL, kPose_E1_FaceL_LandJump_AimU,
};

uint16 kSamusNewPose_RanIntoWall[] = {
  kPose_03_FaceR_AimU, kPose_CF_FaceR_Ranintowall_AimUR, kPose_89_FaceR_Ranintowall, kPose_D1_FaceR_Ranintowall_AimDR, kPose_89_FaceR_Ranintowall,
  kPose_8A_FaceL_Ranintowall, kPose_D2_FaceL_Ranintowall_AimDL, kPose_8A_FaceL_Ranintowall, kPose_D0_FaceL_Ranintowall_AimUL, kPose_04_FaceL_AimU,
};

uint8 kSamusTurnPose_Standing[] = {
  kPose_8B_FaceR_Turn_Stand_AimU, kPose_9C_FaceR_Turn_Stand_AimUR, kPose_25_FaceR_Turn_Stand, kPose_8D_FaceR_Turn_Stand_AimDR, kPose_8D_FaceR_Turn_Stand_AimDR,
  kPose_8E_FaceL_Turn_Stand_AimDL, kPose_8E_FaceL_Turn_Stand_AimDL, kPose_26_FaceL_Turn_Stand, kPose_9D_FaceL_Turn_Stand_AimUL, kPose_8C_FaceL_Turn_Stand_AimU,
};

uint8 kSamusTurnPose_Crouching[] = {
  kPose_97_FaceR_Turn_Crouch_AimU, kPose_A2_FaceR_Turn_Crouch_AimUR, kPose_43_FaceR_Turn_Crouch, kPose_99_FaceR_Turn_Crouch_AimDDR, kPose_99_FaceR_Turn_Crouch_AimDDR,
  kPose_9A_FaceL_Turn_Crouch_AimDDL, kPose_9A_FaceL_Turn_Crouch_AimDDL, kPose_44_FaceL_Turn_Crouch, kPose_A3_FaceL_Turn_Crouch_AimUL, kPose_98_FaceL_Turn_Crouch_AimU,
};

uint8 kSamusTurnPose_Jumping[] = {
  kPose_8F_FaceR_Turn_Air_AimU, kPose_9E_FaceR_Turn_Air_AimUR, kPose_2F_FaceR_Turn_Jump, kPose_91_FaceR_Turn_Air_AimDDR, kPose_91_FaceR_Turn_Air_AimDDR,
  kPose_92_FaceL_Turn_Air_AimDDL, kPose_92_FaceL_Turn_Air_AimDDL, kPose_30_FaceL_Turn_Jump, kPose_9F_FaceL_Turn_Air_AimUL, kPose_90_FaceL_Turn_Air_AimU,
};

uint8 kSamusTurnPose_Falling[] = {
  kPose_93_FaceR_Turn_Fall_AimU, kPose_A0_FaceR_Turn_Fall_AimUR, kPose_87_FaceR_Turn_Fall, kPose_95_FaceR_Turn_Fall_AimDDR, kPose_95_FaceR_Turn_Fall_AimDDR,
  kPose_96_FaceL_Turn_Fall_AimDDL, kPose_96_FaceL_Turn_Fall_AimDDL, kPose_88_FaceL_Turn_Fall, kPose_A1_FaceL_Turn_Fall_AimUL, kPose_94_FaceL_Turn_Fall_AimU,
};

uint8 kSamusTurnPose_Moonwalk[] = {
  kPose_C1_FaceR_Moonwalk_TurnjumpL_AimUR, kPose_C1_FaceR_Moonwalk_TurnjumpL_AimUR, kPose_BF_FaceR_Moonwalk_TurnjumpL, kPose_C3_FaceR_Moonwalk_TurnjumpL_AimDR, kPose_8D_FaceR_Turn_Stand_AimDR,
  kPose_8E_FaceL_Turn_Stand_AimDL, kPose_C4_FaceL_Moonwalk_TurnjumpR_AimDL, kPose_C0_FaceL_Moonwalk_TurnjumpR, kPose_C2_FaceL_Moonwalk_TurnjumpR_AimUL, kPose_C2_FaceL_Moonwalk_TurnjumpR_AimUL,
};

const uint8 kDefaultAnimFrames[11] = {  // 0x91B5D1
  2, 2, 2, 2, 2, 2, 2, 2, 2, 2, -1,
};

const uint8 kSpeedBoostToAnimFrames[5][11] = {  // 0x91B5DE
  [0] = { 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, -1, },
  [1] = { 2, 3, 2, 3, 2, 3, 2, 3, 2, 3, -1, },
  [2] = { 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, -1, },
  [3] = { 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, -1, },
  [4] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, -1, },
};

const uint16 kSpeedBoostToCtr[5] = {  // 0x91B61F
  1, 1, 1, 1, 2,
};

const SamusPoseParams kPoseParams[0xFC] = {  // 0x91B629
  [kPose_00_FaceF_Powersuit]                = { .pose_x_dir = kSamusXDir_FaceForward  , .movement_type = kMovementType_00_Standing                                             , .new_pose_unless_buttons = 0xff                                   , .direction_shots_fired = 0xff                                                 , .y_offset_proj_origin_to_gfx =   8, .UNUSED_field_5 = 0, .y_radius = 24, .UNUSED_field_7 = 0, },
  [kPose_01_FaceR_Normal]                   = { .pose_x_dir = kSamusXDir_FaceRight    , .movement_type = kMovementType_00_Standing                                             , .new_pose_unless_buttons = 0xff                                   , .direction_shots_fired = kProjectileOriginDir_Right                           , .y_offset_proj_origin_to_gfx =   6, .UNUSED_field_5 = 0, .y_radius = 21, .UNUSED_field_7 = 0, },
  [kPose_02_FaceL_Normal]                   = { .pose_x_dir = kSamusXDir_FaceLeft     , .movement_type = kMovementType_00_Standing                                             , .new_pose_unless_buttons = 0xff                                   , .direction_shots_fired = kProjectileOriginDir_Left                            , .y_offset_proj_origin_to_gfx =   6, .UNUSED_field_5 = 0, .y_radius = 21, .UNUSED_field_7 = 0, },
  [kPose_03_FaceR_AimU]                     = { .pose_x_dir = kSamusXDir_FaceRight    , .movement_type = kMovementType_00_Standing                                             , .new_pose_unless_buttons = kPose_01_FaceR_Normal                  , .direction_shots_fired = kProjectileOriginDir_UpFaceRight                     , .y_offset_proj_origin_to_gfx =   6, .UNUSED_field_5 = 0, .y_radius = 21, .UNUSED_field_7 = 0, },
  [kPose_04_FaceL_AimU]                     = { .pose_x_dir = kSamusXDir_FaceLeft     , .movement_type = kMovementType_00_Standing                                             , .new_pose_unless_buttons = kPose_02_FaceL_Normal                  , .direction_shots_fired = kProjectileOriginDir_UpFaceLeft                      , .y_offset_proj_origin_to_gfx =   6, .UNUSED_field_5 = 0, .y_radius = 21, .UNUSED_field_7 = 0, },
  [kPose_05_FaceR_AimUR]                    = { .pose_x_dir = kSamusXDir_FaceRight    , .movement_type = kMovementType_00_Standing                                             , .new_pose_unless_buttons = kPose_01_FaceR_Normal                  , .direction_shots_fired = kProjectileOriginDir_UpRight                         , .y_offset_proj_origin_to_gfx =   6, .UNUSED_field_5 = 0, .y_radius = 21, .UNUSED_field_7 = 0, },
  [kPose_06_FaceL_AimUL]                    = { .pose_x_dir = kSamusXDir_FaceLeft     , .movement_type = kMovementType_00_Standing                                             , .new_pose_unless_buttons = kPose_02_FaceL_Normal                  , .direction_shots_fired = kProjectileOriginDir_UpLeft                          , .y_offset_proj_origin_to_gfx =   6, .UNUSED_field_5 = 0, .y_radius = 21, .UNUSED_field_7 = 0, },
  [kPose_07_FaceR_AimDR]                    = { .pose_x_dir = kSamusXDir_FaceRight    , .movement_type = kMovementType_00_Standing                                             , .new_pose_unless_buttons = kPose_01_FaceR_Normal                  , .direction_shots_fired = kProjectileOriginDir_DownRight                       , .y_offset_proj_origin_to_gfx =   6, .UNUSED_field_5 = 0, .y_radius = 21, .UNUSED_field_7 = 0, },
  [kPose_08_FaceL_AimDL]                    = { .pose_x_dir = kSamusXDir_FaceLeft     , .movement_type = kMovementType_00_Standing                                             , .new_pose_unless_buttons = kPose_02_FaceL_Normal                  , .direction_shots_fired = kProjectileOriginDir_DownLeft                        , .y_offset_proj_origin_to_gfx =   6, .UNUSED_field_5 = 0, .y_radius = 21, .UNUSED_field_7 = 0, },
  [kPose_09_MoveR_NoAim]                    = { .pose_x_dir = kSamusXDir_FaceRight    , .movement_type = kMovementType_01_Running                                              , .new_pose_unless_buttons = kPose_01_FaceR_Normal                  , .direction_shots_fired = kProjectileOriginDir_Right                           , .y_offset_proj_origin_to_gfx =   6, .UNUSED_field_5 = 0, .y_radius = 21, .UNUSED_field_7 = 0, },
  [kPose_0A_MoveL_NoAim]                    = { .pose_x_dir = kSamusXDir_FaceLeft     , .movement_type = kMovementType_01_Running                                              , .new_pose_unless_buttons = kPose_02_FaceL_Normal                  , .direction_shots_fired = kProjectileOriginDir_Left                            , .y_offset_proj_origin_to_gfx =   6, .UNUSED_field_5 = 0, .y_radius = 21, .UNUSED_field_7 = 0, },
  [kPose_0B_MoveR_Gun]                      = { .pose_x_dir = kSamusXDir_FaceRight    , .movement_type = kMovementType_01_Running                                              , .new_pose_unless_buttons = kPose_01_FaceR_Normal                  , .direction_shots_fired = kProjectileOriginDir_Right                           , .y_offset_proj_origin_to_gfx =   6, .UNUSED_field_5 = 0, .y_radius = 21, .UNUSED_field_7 = 0, },
  [kPose_0C_MoveL_Gun]                      = { .pose_x_dir = kSamusXDir_FaceLeft     , .movement_type = kMovementType_01_Running                                              , .new_pose_unless_buttons = kPose_02_FaceL_Normal                  , .direction_shots_fired = kProjectileOriginDir_Left                            , .y_offset_proj_origin_to_gfx =   6, .UNUSED_field_5 = 0, .y_radius = 21, .UNUSED_field_7 = 0, },
  [kPose_0D]                                = { .pose_x_dir = kSamusXDir_FaceRight    , .movement_type = kMovementType_01_Running                                              , .new_pose_unless_buttons = kPose_01_FaceR_Normal                  , .direction_shots_fired = kProjectileOriginDir_UpFaceRight                     , .y_offset_proj_origin_to_gfx =   6, .UNUSED_field_5 = 0, .y_radius = 21, .UNUSED_field_7 = 0, },
  [kPose_0E]                                = { .pose_x_dir = kSamusXDir_FaceLeft     , .movement_type = kMovementType_01_Running                                              , .new_pose_unless_buttons = kPose_02_FaceL_Normal                  , .direction_shots_fired = kProjectileOriginDir_UpFaceLeft                      , .y_offset_proj_origin_to_gfx =   6, .UNUSED_field_5 = 0, .y_radius = 21, .UNUSED_field_7 = 0, },
  [kPose_0F_MoveR_AimUR]                    = { .pose_x_dir = kSamusXDir_FaceRight    , .movement_type = kMovementType_01_Running                                              , .new_pose_unless_buttons = kPose_01_FaceR_Normal                  , .direction_shots_fired = kProjectileOriginDir_UpRight                         , .y_offset_proj_origin_to_gfx =   6, .UNUSED_field_5 = 0, .y_radius = 21, .UNUSED_field_7 = 0, },
  [kPose_10_MoveL_AimUL]                    = { .pose_x_dir = kSamusXDir_FaceLeft     , .movement_type = kMovementType_01_Running                                              , .new_pose_unless_buttons = kPose_02_FaceL_Normal                  , .direction_shots_fired = kProjectileOriginDir_UpLeft                          , .y_offset_proj_origin_to_gfx =   6, .UNUSED_field_5 = 0, .y_radius = 21, .UNUSED_field_7 = 0, },
  [kPose_11_MoveR_AimDR]                    = { .pose_x_dir = kSamusXDir_FaceRight    , .movement_type = kMovementType_01_Running                                              , .new_pose_unless_buttons = kPose_01_FaceR_Normal                  , .direction_shots_fired = kProjectileOriginDir_DownRight                       , .y_offset_proj_origin_to_gfx =   6, .UNUSED_field_5 = 0, .y_radius = 21, .UNUSED_field_7 = 0, },
  [kPose_12_MoveL_AimDL]                    = { .pose_x_dir = kSamusXDir_FaceLeft     , .movement_type = kMovementType_01_Running                                              , .new_pose_unless_buttons = kPose_02_FaceL_Normal                  , .direction_shots_fired = kProjectileOriginDir_DownLeft                        , .y_offset_proj_origin_to_gfx =   6, .UNUSED_field_5 = 0, .y_radius = 21, .UNUSED_field_7 = 0, },
  [kPose_13_FaceR_Jump_NoAim_NoMove_Gun]    = { .pose_x_dir = kSamusXDir_FaceRight    , .movement_type = kMovementType_02_NormalJumping                                        , .new_pose_unless_buttons = 0xff                                   , .direction_shots_fired = kProjectileOriginDir_Right                           , .y_offset_proj_origin_to_gfx =   8, .UNUSED_field_5 = 0, .y_radius = 19, .UNUSED_field_7 = 0, },
  [kPose_14_FaceL_Jump_NoAim_NoMove_Gun]    = { .pose_x_dir = kSamusXDir_FaceLeft     , .movement_type = kMovementType_02_NormalJumping                                        , .new_pose_unless_buttons = 0xff                                   , .direction_shots_fired = kProjectileOriginDir_Left                            , .y_offset_proj_origin_to_gfx =   8, .UNUSED_field_5 = 0, .y_radius = 19, .UNUSED_field_7 = 0, },
  [kPose_15_FaceR_Jump_AimU]                = { .pose_x_dir = kSamusXDir_FaceRight    , .movement_type = kMovementType_02_NormalJumping                                        , .new_pose_unless_buttons = kPose_51_FaceR_Jump_NoAim_MoveF        , .direction_shots_fired = kProjectileOriginDir_UpFaceRight                     , .y_offset_proj_origin_to_gfx =   8, .UNUSED_field_5 = 0, .y_radius = 19, .UNUSED_field_7 = 0, },
  [kPose_16_FaceL_Jump_AimU]                = { .pose_x_dir = kSamusXDir_FaceLeft     , .movement_type = kMovementType_02_NormalJumping                                        , .new_pose_unless_buttons = kPose_52_FaceL_Jump_NoAim_MoveF        , .direction_shots_fired = kProjectileOriginDir_UpFaceLeft                      , .y_offset_proj_origin_to_gfx =   8, .UNUSED_field_5 = 0, .y_radius = 19, .UNUSED_field_7 = 0, },
  [kPose_17_FaceR_Jump_AimD]                = { .pose_x_dir = kSamusXDir_FaceRight    , .movement_type = kMovementType_02_NormalJumping                                        , .new_pose_unless_buttons = 0xff                                   , .direction_shots_fired = kProjectileOriginDir_DownFaceRight                   , .y_offset_proj_origin_to_gfx =   6, .UNUSED_field_5 = 0, .y_radius = 10, .UNUSED_field_7 = 0, },
  [kPose_18_FaceL_Jump_AimD]                = { .pose_x_dir = kSamusXDir_FaceLeft     , .movement_type = kMovementType_02_NormalJumping                                        , .new_pose_unless_buttons = 0xff                                   , .direction_shots_fired = kProjectileOriginDir_DownFaceLeft                    , .y_offset_proj_origin_to_gfx =   6, .UNUSED_field_5 = 0, .y_radius = 10, .UNUSED_field_7 = 0, },
  [kPose_19_FaceR_SpinJump]                 = { .pose_x_dir = kSamusXDir_FaceRight    , .movement_type = kMovementType_03_SpinJumping                                          , .new_pose_unless_buttons = 0xff                                   , .direction_shots_fired = 0xff                                                 , .y_offset_proj_origin_to_gfx =   0, .UNUSED_field_5 = 0, .y_radius = 12, .UNUSED_field_7 = 0, },
  [kPose_1A_FaceL_SpinJump]                 = { .pose_x_dir = kSamusXDir_FaceLeft     , .movement_type = kMovementType_03_SpinJumping                                          , .new_pose_unless_buttons = 0xff                                   , .direction_shots_fired = 0xff                                                 , .y_offset_proj_origin_to_gfx =   0, .UNUSED_field_5 = 0, .y_radius = 12, .UNUSED_field_7 = 0, },
  [kPose_1B_FaceR_SpaceJump]                = { .pose_x_dir = kSamusXDir_FaceRight    , .movement_type = kMovementType_03_SpinJumping                                          , .new_pose_unless_buttons = 0xff                                   , .direction_shots_fired = 0xff                                                 , .y_offset_proj_origin_to_gfx =   0, .UNUSED_field_5 = 0, .y_radius = 12, .UNUSED_field_7 = 0, },
  [kPose_1C_FaceL_SpaceJump]                = { .pose_x_dir = kSamusXDir_FaceLeft     , .movement_type = kMovementType_03_SpinJumping                                          , .new_pose_unless_buttons = 0xff                                   , .direction_shots_fired = 0xff                                                 , .y_offset_proj_origin_to_gfx =   0, .UNUSED_field_5 = 0, .y_radius = 12, .UNUSED_field_7 = 0, },
  [kPose_1D_FaceR_Morphball_Ground]         = { .pose_x_dir = kSamusXDir_FaceRight    , .movement_type = kMovementType_04_MorphBallOnGround                                    , .new_pose_unless_buttons = 0xff                                   , .direction_shots_fired = 0xff                                                 , .y_offset_proj_origin_to_gfx =   0, .UNUSED_field_5 = 0, .y_radius =  7, .UNUSED_field_7 = 0, },
  [kPose_1E_MoveR_Morphball_Ground]         = { .pose_x_dir = kSamusXDir_FaceRight    , .movement_type = kMovementType_04_MorphBallOnGround                                    , .new_pose_unless_buttons = kPose_1D_FaceR_Morphball_Ground        , .direction_shots_fired = 0xff                                                 , .y_offset_proj_origin_to_gfx =   0, .UNUSED_field_5 = 0, .y_radius =  7, .UNUSED_field_7 = 0, },
  [kPose_1F_MoveL_Morphball_Ground]         = { .pose_x_dir = kSamusXDir_FaceLeft     , .movement_type = kMovementType_04_MorphBallOnGround                                    , .new_pose_unless_buttons = kPose_41_FaceL_Morphball_Ground        , .direction_shots_fired = 0xff                                                 , .y_offset_proj_origin_to_gfx =   0, .UNUSED_field_5 = 0, .y_radius =  7, .UNUSED_field_7 = 0, },
  [kPose_20]                                = { .pose_x_dir = kSamusXDir_FaceRight    , .movement_type = kMovementType_07_Unused                                               , .new_pose_unless_buttons = 0xff                                   , .direction_shots_fired = 0xff                                                 , .y_offset_proj_origin_to_gfx =   0, .UNUSED_field_5 = 0, .y_radius =  7, .UNUSED_field_7 = 0, },
  [kPose_21]                                = { .pose_x_dir = kSamusXDir_UnusedPose21 , .movement_type = kMovementType_07_Unused                                               , .new_pose_unless_buttons = kPose_20                               , .direction_shots_fired = 0xff                                                 , .y_offset_proj_origin_to_gfx =   0, .UNUSED_field_5 = 0, .y_radius =  7, .UNUSED_field_7 = 0, },
  [kPose_22]                                = { .pose_x_dir = kSamusXDir_UnusedPose22 , .movement_type = kMovementType_07_Unused                                               , .new_pose_unless_buttons = kPose_20                               , .direction_shots_fired = 0xff                                                 , .y_offset_proj_origin_to_gfx =   0, .UNUSED_field_5 = 0, .y_radius =  7, .UNUSED_field_7 = 0, },
  [kPose_23]                                = { .pose_x_dir = kSamusXDir_FaceLeft     , .movement_type = kMovementType_07_Unused                                               , .new_pose_unless_buttons = kPose_42                               , .direction_shots_fired = 0xff                                                 , .y_offset_proj_origin_to_gfx =   0, .UNUSED_field_5 = 0, .y_radius =  7, .UNUSED_field_7 = 0, },
  [kPose_24]                                = { .pose_x_dir = kSamusXDir_FaceRight    , .movement_type = kMovementType_07_Unused                                               , .new_pose_unless_buttons = kPose_20                               , .direction_shots_fired = 0xff                                                 , .y_offset_proj_origin_to_gfx =   0, .UNUSED_field_5 = 0, .y_radius =  7, .UNUSED_field_7 = 0, },
  [kPose_25_FaceR_Turn_Stand]               = { .pose_x_dir = kSamusXDir_FaceLeft     , .movement_type = kMovementType_0E_TurningAroundOnGround                                , .new_pose_unless_buttons = 0xff                                   , .direction_shots_fired = SHOT_DISABLED | kProjectileOriginDir_TurnAimNeutral  , .y_offset_proj_origin_to_gfx =   6, .UNUSED_field_5 = 0, .y_radius = 21, .UNUSED_field_7 = 0, },
  [kPose_26_FaceL_Turn_Stand]               = { .pose_x_dir = kSamusXDir_FaceRight    , .movement_type = kMovementType_0E_TurningAroundOnGround                                , .new_pose_unless_buttons = 0xff                                   , .direction_shots_fired = SHOT_DISABLED | kProjectileOriginDir_TurnAimNeutral  , .y_offset_proj_origin_to_gfx =   6, .UNUSED_field_5 = 0, .y_radius = 21, .UNUSED_field_7 = 0, },
  [kPose_27_FaceR_Crouch]                   = { .pose_x_dir = kSamusXDir_FaceRight    , .movement_type = kMovementType_05_Crouching                                            , .new_pose_unless_buttons = kPose_27_FaceR_Crouch                  , .direction_shots_fired = kProjectileOriginDir_Right                           , .y_offset_proj_origin_to_gfx =   0, .UNUSED_field_5 = 0, .y_radius = 16, .UNUSED_field_7 = 0, },
  [kPose_28_FaceL_Crouch]                   = { .pose_x_dir = kSamusXDir_FaceLeft     , .movement_type = kMovementType_05_Crouching                                            , .new_pose_unless_buttons = kPose_28_FaceL_Crouch                  , .direction_shots_fired = kProjectileOriginDir_Left                            , .y_offset_proj_origin_to_gfx =   0, .UNUSED_field_5 = 0, .y_radius = 16, .UNUSED_field_7 = 0, },
  [kPose_29_FaceR_Fall]                     = { .pose_x_dir = kSamusXDir_FaceRight    , .movement_type = kMovementType_06_Falling                                              , .new_pose_unless_buttons = 0xff                                   , .direction_shots_fired = kProjectileOriginDir_Right                           , .y_offset_proj_origin_to_gfx =   8, .UNUSED_field_5 = 0, .y_radius = 19, .UNUSED_field_7 = 0, },
  [kPose_2A_FaceL_Fall]                     = { .pose_x_dir = kSamusXDir_FaceLeft     , .movement_type = kMovementType_06_Falling                                              , .new_pose_unless_buttons = 0xff                                   , .direction_shots_fired = kProjectileOriginDir_Left                            , .y_offset_proj_origin_to_gfx =   8, .UNUSED_field_5 = 0, .y_radius = 19, .UNUSED_field_7 = 0, },
  [kPose_2B_FaceR_Fall_AimU]                = { .pose_x_dir = kSamusXDir_FaceRight    , .movement_type = kMovementType_06_Falling                                              , .new_pose_unless_buttons = kPose_29_FaceR_Fall                    , .direction_shots_fired = kProjectileOriginDir_UpFaceRight                     , .y_offset_proj_origin_to_gfx =   8, .UNUSED_field_5 = 0, .y_radius = 19, .UNUSED_field_7 = 0, },
  [kPose_2C_FaceL_Fall_AimU]                = { .pose_x_dir = kSamusXDir_FaceLeft     , .movement_type = kMovementType_06_Falling                                              , .new_pose_unless_buttons = kPose_2A_FaceL_Fall                    , .direction_shots_fired = kProjectileOriginDir_UpFaceLeft                      , .y_offset_proj_origin_to_gfx =   8, .UNUSED_field_5 = 0, .y_radius = 19, .UNUSED_field_7 = 0, },
  [kPose_2D_FaceR_Fall_AimD]                = { .pose_x_dir = kSamusXDir_FaceRight    , .movement_type = kMovementType_06_Falling                                              , .new_pose_unless_buttons = 0xff                                   , .direction_shots_fired = kProjectileOriginDir_DownFaceRight                   , .y_offset_proj_origin_to_gfx =   6, .UNUSED_field_5 = 0, .y_radius = 10, .UNUSED_field_7 = 0, },
  [kPose_2E_FaceL_Fall_AimD]                = { .pose_x_dir = kSamusXDir_FaceLeft     , .movement_type = kMovementType_06_Falling                                              , .new_pose_unless_buttons = 0xff                                   , .direction_shots_fired = kProjectileOriginDir_DownFaceLeft                    , .y_offset_proj_origin_to_gfx =   6, .UNUSED_field_5 = 0, .y_radius = 10, .UNUSED_field_7 = 0, },
  [kPose_2F_FaceR_Turn_Jump]                = { .pose_x_dir = kSamusXDir_FaceLeft     , .movement_type = kMovementType_17_TurningAroundJumping                                 , .new_pose_unless_buttons = 0xff                                   , .direction_shots_fired = SHOT_DISABLED | kProjectileOriginDir_TurnAimNeutral  , .y_offset_proj_origin_to_gfx =   8, .UNUSED_field_5 = 0, .y_radius = 19, .UNUSED_field_7 = 0, },
  [kPose_30_FaceL_Turn_Jump]                = { .pose_x_dir = kSamusXDir_FaceRight    , .movement_type = kMovementType_17_TurningAroundJumping                                 , .new_pose_unless_buttons = 0xff                                   , .direction_shots_fired = SHOT_DISABLED | kProjectileOriginDir_TurnAimNeutral  , .y_offset_proj_origin_to_gfx =   8, .UNUSED_field_5 = 0, .y_radius = 19, .UNUSED_field_7 = 0, },
  [kPose_31_FaceR_Morphball_Air]            = { .pose_x_dir = kSamusXDir_FaceRight    , .movement_type = kMovementType_08_MorphBallFalling                                     , .new_pose_unless_buttons = 0xff                                   , .direction_shots_fired = 0xff                                                 , .y_offset_proj_origin_to_gfx =   0, .UNUSED_field_5 = 0, .y_radius =  7, .UNUSED_field_7 = 0, },
  [kPose_32_FaceL_Morphball_Air]            = { .pose_x_dir = kSamusXDir_FaceLeft     , .movement_type = kMovementType_08_MorphBallFalling                                     , .new_pose_unless_buttons = 0xff                                   , .direction_shots_fired = 0xff                                                 , .y_offset_proj_origin_to_gfx =   0, .UNUSED_field_5 = 0, .y_radius =  7, .UNUSED_field_7 = 0, },
  [kPose_33]                                = { .pose_x_dir = kSamusXDir_FaceRight    , .movement_type = kMovementType_09_Unused                                               , .new_pose_unless_buttons = 0xff                                   , .direction_shots_fired = 0xff                                                 , .y_offset_proj_origin_to_gfx =   0, .UNUSED_field_5 = 0, .y_radius =  7, .UNUSED_field_7 = 0, },
  [kPose_34]                                = { .pose_x_dir = kSamusXDir_FaceLeft     , .movement_type = kMovementType_09_Unused                                               , .new_pose_unless_buttons = 0xff                                   , .direction_shots_fired = 0xff                                                 , .y_offset_proj_origin_to_gfx =   0, .UNUSED_field_5 = 0, .y_radius =  7, .UNUSED_field_7 = 0, },
  [kPose_35_FaceR_CrouchTrans]              = { .pose_x_dir = kSamusXDir_FaceRight    , .movement_type = kMovementType_0F_Crouch_Stand_Morph_Unmorph_Transition                , .new_pose_unless_buttons = 0xff                                   , .direction_shots_fired = kProjectileOriginDir_Right                           , .y_offset_proj_origin_to_gfx =   0, .UNUSED_field_5 = 0, .y_radius = 16, .UNUSED_field_7 = 0, },
  [kPose_36_FaceL_CrouchTrans]              = { .pose_x_dir = kSamusXDir_FaceLeft     , .movement_type = kMovementType_0F_Crouch_Stand_Morph_Unmorph_Transition                , .new_pose_unless_buttons = 0xff                                   , .direction_shots_fired = kProjectileOriginDir_Left                            , .y_offset_proj_origin_to_gfx =   0, .UNUSED_field_5 = 0, .y_radius = 16, .UNUSED_field_7 = 0, },
  [kPose_37_FaceR_MorphTrans]               = { .pose_x_dir = kSamusXDir_FaceRight    , .movement_type = kMovementType_0F_Crouch_Stand_Morph_Unmorph_Transition                , .new_pose_unless_buttons = 0xff                                   , .direction_shots_fired = 0xff                                                 , .y_offset_proj_origin_to_gfx =   0, .UNUSED_field_5 = 0, .y_radius =  7, .UNUSED_field_7 = 0, },
  [kPose_38_FaceL_MorphTrans]               = { .pose_x_dir = kSamusXDir_FaceLeft     , .movement_type = kMovementType_0F_Crouch_Stand_Morph_Unmorph_Transition                , .new_pose_unless_buttons = 0xff                                   , .direction_shots_fired = 0xff                                                 , .y_offset_proj_origin_to_gfx =   0, .UNUSED_field_5 = 0, .y_radius =  7, .UNUSED_field_7 = 0, },
  [kPose_39]                                = { .pose_x_dir = kSamusXDir_FaceRight    , .movement_type = kMovementType_0F_Crouch_Stand_Morph_Unmorph_Transition                , .new_pose_unless_buttons = 0xff                                   , .direction_shots_fired = 0xff                                                 , .y_offset_proj_origin_to_gfx =   0, .UNUSED_field_5 = 0, .y_radius =  7, .UNUSED_field_7 = 0, },
  [kPose_3A]                                = { .pose_x_dir = kSamusXDir_FaceLeft     , .movement_type = kMovementType_0F_Crouch_Stand_Morph_Unmorph_Transition                , .new_pose_unless_buttons = 0xff                                   , .direction_shots_fired = 0xff                                                 , .y_offset_proj_origin_to_gfx =   0, .UNUSED_field_5 = 0, .y_radius =  7, .UNUSED_field_7 = 0, },
  [kPose_3B_FaceR_StandTrans]               = { .pose_x_dir = kSamusXDir_FaceRight    , .movement_type = kMovementType_0F_Crouch_Stand_Morph_Unmorph_Transition                , .new_pose_unless_buttons = 0xff                                   , .direction_shots_fired = kProjectileOriginDir_Right                           , .y_offset_proj_origin_to_gfx =   6, .UNUSED_field_5 = 0, .y_radius = 21, .UNUSED_field_7 = 0, },
  [kPose_3C_FaceL_StandTrans]               = { .pose_x_dir = kSamusXDir_FaceLeft     , .movement_type = kMovementType_0F_Crouch_Stand_Morph_Unmorph_Transition                , .new_pose_unless_buttons = 0xff                                   , .direction_shots_fired = kProjectileOriginDir_Left                            , .y_offset_proj_origin_to_gfx =   6, .UNUSED_field_5 = 0, .y_radius = 21, .UNUSED_field_7 = 0, },
  [kPose_3D_FaceR_UnmorphTrans]             = { .pose_x_dir = kSamusXDir_FaceRight    , .movement_type = kMovementType_0F_Crouch_Stand_Morph_Unmorph_Transition                , .new_pose_unless_buttons = 0xff                                   , .direction_shots_fired = 0xff                                                 , .y_offset_proj_origin_to_gfx =   0, .UNUSED_field_5 = 0, .y_radius = 16, .UNUSED_field_7 = 0, },
  [kPose_3E_FaceL_UnmorphTrans]             = { .pose_x_dir = kSamusXDir_FaceLeft     , .movement_type = kMovementType_0F_Crouch_Stand_Morph_Unmorph_Transition                , .new_pose_unless_buttons = 0xff                                   , .direction_shots_fired = 0xff                                                 , .y_offset_proj_origin_to_gfx =   0, .UNUSED_field_5 = 0, .y_radius = 16, .UNUSED_field_7 = 0, },
  [kPose_3F]                                = { .pose_x_dir = kSamusXDir_FaceRight    , .movement_type = kMovementType_0F_Crouch_Stand_Morph_Unmorph_Transition                , .new_pose_unless_buttons = 0xff                                   , .direction_shots_fired = 0xff                                                 , .y_offset_proj_origin_to_gfx =   0, .UNUSED_field_5 = 0, .y_radius =  7, .UNUSED_field_7 = 0, },
  [kPose_40]                                = { .pose_x_dir = kSamusXDir_FaceLeft     , .movement_type = kMovementType_0F_Crouch_Stand_Morph_Unmorph_Transition                , .new_pose_unless_buttons = 0xff                                   , .direction_shots_fired = 0xff                                                 , .y_offset_proj_origin_to_gfx =   0, .UNUSED_field_5 = 0, .y_radius =  7, .UNUSED_field_7 = 0, },
  [kPose_41_FaceL_Morphball_Ground]         = { .pose_x_dir = kSamusXDir_FaceLeft     , .movement_type = kMovementType_04_MorphBallOnGround                                    , .new_pose_unless_buttons = 0xff                                   , .direction_shots_fired = 0xff                                                 , .y_offset_proj_origin_to_gfx =   0, .UNUSED_field_5 = 0, .y_radius =  7, .UNUSED_field_7 = 0, },
  [kPose_42]                                = { .pose_x_dir = kSamusXDir_FaceLeft     , .movement_type = kMovementType_07_Unused                                               , .new_pose_unless_buttons = 0xff                                   , .direction_shots_fired = 0xff                                                 , .y_offset_proj_origin_to_gfx =   0, .UNUSED_field_5 = 0, .y_radius =  7, .UNUSED_field_7 = 0, },
  [kPose_43_FaceR_Turn_Crouch]              = { .pose_x_dir = kSamusXDir_FaceLeft     , .movement_type = kMovementType_0E_TurningAroundOnGround                                , .new_pose_unless_buttons = 0xff                                   , .direction_shots_fired = SHOT_DISABLED | kProjectileOriginDir_TurnAimNeutral  , .y_offset_proj_origin_to_gfx =   0, .UNUSED_field_5 = 0, .y_radius = 16, .UNUSED_field_7 = 0, },
  [kPose_44_FaceL_Turn_Crouch]              = { .pose_x_dir = kSamusXDir_FaceRight    , .movement_type = kMovementType_0E_TurningAroundOnGround                                , .new_pose_unless_buttons = 0xff                                   , .direction_shots_fired = SHOT_DISABLED | kProjectileOriginDir_TurnAimNeutral  , .y_offset_proj_origin_to_gfx =   0, .UNUSED_field_5 = 0, .y_radius = 16, .UNUSED_field_7 = 0, },
  [kPose_45]                                = { .pose_x_dir = kSamusXDir_FaceRight    , .movement_type = kMovementType_01_Running                                              , .new_pose_unless_buttons = kPose_01_FaceR_Normal                  , .direction_shots_fired = kProjectileOriginDir_Left                            , .y_offset_proj_origin_to_gfx =   6, .UNUSED_field_5 = 0, .y_radius = 21, .UNUSED_field_7 = 0, },
  [kPose_46]                                = { .pose_x_dir = kSamusXDir_FaceLeft     , .movement_type = kMovementType_01_Running                                              , .new_pose_unless_buttons = kPose_02_FaceL_Normal                  , .direction_shots_fired = kProjectileOriginDir_Right                           , .y_offset_proj_origin_to_gfx =   6, .UNUSED_field_5 = 0, .y_radius = 21, .UNUSED_field_7 = 0, },
  [kPose_47]                                = { .pose_x_dir = kSamusXDir_FaceRight    , .movement_type = kMovementType_00_Standing                                             , .new_pose_unless_buttons = 0xff                                   , .direction_shots_fired = kProjectileOriginDir_Right                           , .y_offset_proj_origin_to_gfx =   6, .UNUSED_field_5 = 0, .y_radius = 21, .UNUSED_field_7 = 0, },
  [kPose_48]                                = { .pose_x_dir = kSamusXDir_FaceLeft     , .movement_type = kMovementType_00_Standing                                             , .new_pose_unless_buttons = 0xff                                   , .direction_shots_fired = kProjectileOriginDir_Left                            , .y_offset_proj_origin_to_gfx =   6, .UNUSED_field_5 = 0, .y_radius = 21, .UNUSED_field_7 = 0, },
  [kPose_49_FaceL_Moonwalk]                 = { .pose_x_dir = kSamusXDir_FaceRight    , .movement_type = kMovementType_10_Moonwalking                                          , .new_pose_unless_buttons = kPose_02_FaceL_Normal                  , .direction_shots_fired = kProjectileOriginDir_Left                            , .y_offset_proj_origin_to_gfx =   6, .UNUSED_field_5 = 0, .y_radius = 21, .UNUSED_field_7 = 0, },
  [kPose_4A_FaceR_Moonwalk]                 = { .pose_x_dir = kSamusXDir_FaceLeft     , .movement_type = kMovementType_10_Moonwalking                                          , .new_pose_unless_buttons = kPose_01_FaceR_Normal                  , .direction_shots_fired = kProjectileOriginDir_Right                           , .y_offset_proj_origin_to_gfx =   6, .UNUSED_field_5 = 0, .y_radius = 21, .UNUSED_field_7 = 0, },
  [kPose_4B_FaceR_Jumptrans]                = { .pose_x_dir = kSamusXDir_FaceRight    , .movement_type = kMovementType_02_NormalJumping                                        , .new_pose_unless_buttons = 0xff                                   , .direction_shots_fired = kProjectileOriginDir_Right                           , .y_offset_proj_origin_to_gfx =   3, .UNUSED_field_5 = 0, .y_radius = 19, .UNUSED_field_7 = 0, },
  [kPose_4C_FaceL_Jumptrans]                = { .pose_x_dir = kSamusXDir_FaceLeft     , .movement_type = kMovementType_02_NormalJumping                                        , .new_pose_unless_buttons = 0xff                                   , .direction_shots_fired = kProjectileOriginDir_Left                            , .y_offset_proj_origin_to_gfx =   3, .UNUSED_field_5 = 0, .y_radius = 19, .UNUSED_field_7 = 0, },
  [kPose_4D_FaceR_Jump_NoAim_NoMove_NoGun]  = { .pose_x_dir = kSamusXDir_FaceRight    , .movement_type = kMovementType_02_NormalJumping                                        , .new_pose_unless_buttons = 0xff                                   , .direction_shots_fired = kProjectileOriginDir_Right                           , .y_offset_proj_origin_to_gfx =   8, .UNUSED_field_5 = 0, .y_radius = 19, .UNUSED_field_7 = 0, },
  [kPose_4E_FaceL_Jump_NoAim_NoMove_NoGun]  = { .pose_x_dir = kSamusXDir_FaceLeft     , .movement_type = kMovementType_02_NormalJumping                                        , .new_pose_unless_buttons = 0xff                                   , .direction_shots_fired = kProjectileOriginDir_Left                            , .y_offset_proj_origin_to_gfx =   8, .UNUSED_field_5 = 0, .y_radius = 19, .UNUSED_field_7 = 0, },
  [kPose_4F_FaceL_Dmgboost]                 = { .pose_x_dir = kSamusXDir_FaceRight    , .movement_type = kMovementType_19_DamageBoost                                          , .new_pose_unless_buttons = kPose_4E_FaceL_Jump_NoAim_NoMove_NoGun , .direction_shots_fired = 0xff                                                 , .y_offset_proj_origin_to_gfx =   8, .UNUSED_field_5 = 0, .y_radius = 19, .UNUSED_field_7 = 0, },
  [kPose_50_FaceR_Dmgboost]                 = { .pose_x_dir = kSamusXDir_FaceLeft     , .movement_type = kMovementType_19_DamageBoost                                          , .new_pose_unless_buttons = kPose_4D_FaceR_Jump_NoAim_NoMove_NoGun , .direction_shots_fired = 0xff                                                 , .y_offset_proj_origin_to_gfx =   8, .UNUSED_field_5 = 0, .y_radius = 19, .UNUSED_field_7 = 0, },
  [kPose_51_FaceR_Jump_NoAim_MoveF]         = { .pose_x_dir = kSamusXDir_FaceRight    , .movement_type = kMovementType_02_NormalJumping                                        , .new_pose_unless_buttons = 0xff                                   , .direction_shots_fired = kProjectileOriginDir_Right                           , .y_offset_proj_origin_to_gfx =   8, .UNUSED_field_5 = 0, .y_radius = 19, .UNUSED_field_7 = 0, },
  [kPose_52_FaceL_Jump_NoAim_MoveF]         = { .pose_x_dir = kSamusXDir_FaceLeft     , .movement_type = kMovementType_02_NormalJumping                                        , .new_pose_unless_buttons = 0xff                                   , .direction_shots_fired = kProjectileOriginDir_Left                            , .y_offset_proj_origin_to_gfx =   8, .UNUSED_field_5 = 0, .y_radius = 19, .UNUSED_field_7 = 0, },
  [kPose_53_FaceR_Knockback]                = { .pose_x_dir = kSamusXDir_FaceRight    , .movement_type = kMovementType_0A_KnockbackOrCrystalFlashEnding                        , .new_pose_unless_buttons = 0xff                                   , .direction_shots_fired = 0xff                                                 , .y_offset_proj_origin_to_gfx =   6, .UNUSED_field_5 = 0, .y_radius = 21, .UNUSED_field_7 = 0, },
  [kPose_54_FaceL_Knockback]                = { .pose_x_dir = kSamusXDir_FaceLeft     , .movement_type = kMovementType_0A_KnockbackOrCrystalFlashEnding                        , .new_pose_unless_buttons = 0xff                                   , .direction_shots_fired = 0xff                                                 , .y_offset_proj_origin_to_gfx =   6, .UNUSED_field_5 = 0, .y_radius = 21, .UNUSED_field_7 = 0, },
  [kPose_55_FaceR_Jumptrans_AimU]           = { .pose_x_dir = kSamusXDir_FaceRight    , .movement_type = kMovementType_02_NormalJumping                                        , .new_pose_unless_buttons = 0xff                                   , .direction_shots_fired = kProjectileOriginDir_UpFaceRight                     , .y_offset_proj_origin_to_gfx =   3, .UNUSED_field_5 = 0, .y_radius = 19, .UNUSED_field_7 = 0, },
  [kPose_56_FaceL_Jumptrans_AimU]           = { .pose_x_dir = kSamusXDir_FaceLeft     , .movement_type = kMovementType_02_NormalJumping                                        , .new_pose_unless_buttons = 0xff                                   , .direction_shots_fired = kProjectileOriginDir_UpFaceLeft                      , .y_offset_proj_origin_to_gfx =   3, .UNUSED_field_5 = 0, .y_radius = 19, .UNUSED_field_7 = 0, },
  [kPose_57_FaceR_Jumptrans_AimUR]          = { .pose_x_dir = kSamusXDir_FaceRight    , .movement_type = kMovementType_02_NormalJumping                                        , .new_pose_unless_buttons = 0xff                                   , .direction_shots_fired = kProjectileOriginDir_UpRight                         , .y_offset_proj_origin_to_gfx =   3, .UNUSED_field_5 = 0, .y_radius = 19, .UNUSED_field_7 = 0, },
  [kPose_58_FaceL_Jumptrans_AimUL]          = { .pose_x_dir = kSamusXDir_FaceLeft     , .movement_type = kMovementType_02_NormalJumping                                        , .new_pose_unless_buttons = 0xff                                   , .direction_shots_fired = kProjectileOriginDir_UpLeft                          , .y_offset_proj_origin_to_gfx =   3, .UNUSED_field_5 = 0, .y_radius = 19, .UNUSED_field_7 = 0, },
  [kPose_59_FaceR_Jumptrans_AimDR]          = { .pose_x_dir = kSamusXDir_FaceRight    , .movement_type = kMovementType_02_NormalJumping                                        , .new_pose_unless_buttons = 0xff                                   , .direction_shots_fired = kProjectileOriginDir_DownRight                       , .y_offset_proj_origin_to_gfx =   3, .UNUSED_field_5 = 0, .y_radius = 19, .UNUSED_field_7 = 0, },
  [kPose_5A_FaceL_Jumptrans_AimDL]          = { .pose_x_dir = kSamusXDir_FaceLeft     , .movement_type = kMovementType_02_NormalJumping                                        , .new_pose_unless_buttons = 0xff                                   , .direction_shots_fired = kProjectileOriginDir_DownLeft                        , .y_offset_proj_origin_to_gfx =   3, .UNUSED_field_5 = 0, .y_radius = 19, .UNUSED_field_7 = 0, },
  [kPose_5B]                                = { .pose_x_dir = kSamusXDir_FaceRight    , .movement_type = kMovementType_16_Grappling                                            , .new_pose_unless_buttons = 0xff                                   , .direction_shots_fired = 0xff                                                 , .y_offset_proj_origin_to_gfx =  16, .UNUSED_field_5 = 0, .y_radius = 16, .UNUSED_field_7 = 0, },
  [kPose_5C]                                = { .pose_x_dir = kSamusXDir_FaceLeft     , .movement_type = kMovementType_16_Grappling                                            , .new_pose_unless_buttons = 0xff                                   , .direction_shots_fired = 0xff                                                 , .y_offset_proj_origin_to_gfx =  16, .UNUSED_field_5 = 0, .y_radius = 16, .UNUSED_field_7 = 0, },
  [kPose_5D]                                = { .pose_x_dir = kSamusXDir_FaceRight    , .movement_type = kMovementType_0B_Unused                                               , .new_pose_unless_buttons = kPose_5D                               , .direction_shots_fired = 0xff                                                 , .y_offset_proj_origin_to_gfx =  16, .UNUSED_field_5 = 0, .y_radius = 16, .UNUSED_field_7 = 0, },
  [kPose_5E]                                = { .pose_x_dir = kSamusXDir_FaceLeft     , .movement_type = kMovementType_0B_Unused                                               , .new_pose_unless_buttons = kPose_5E                               , .direction_shots_fired = 0xff                                                 , .y_offset_proj_origin_to_gfx =  16, .UNUSED_field_5 = 0, .y_radius = 16, .UNUSED_field_7 = 0, },
  [kPose_5F]                                = { .pose_x_dir = kSamusXDir_FaceRight    , .movement_type = kMovementType_0B_Unused                                               , .new_pose_unless_buttons = kPose_5F                               , .direction_shots_fired = 0xff                                                 , .y_offset_proj_origin_to_gfx =  16, .UNUSED_field_5 = 0, .y_radius = 16, .UNUSED_field_7 = 0, },
  [kPose_60]                                = { .pose_x_dir = kSamusXDir_FaceLeft     , .movement_type = kMovementType_0B_Unused                                               , .new_pose_unless_buttons = kPose_60                               , .direction_shots_fired = 0xff                                                 , .y_offset_proj_origin_to_gfx =  16, .UNUSED_field_5 = 0, .y_radius = 16, .UNUSED_field_7 = 0, },
  [kPose_61]                                = { .pose_x_dir = kSamusXDir_FaceRight    , .movement_type = kMovementType_16_Grappling                                            , .new_pose_unless_buttons = kPose_B2_FaceR_Grapple_Air             , .direction_shots_fired = 0xff                                                 , .y_offset_proj_origin_to_gfx =  16, .UNUSED_field_5 = 0, .y_radius = 16, .UNUSED_field_7 = 0, },
  [kPose_62]                                = { .pose_x_dir = kSamusXDir_FaceLeft     , .movement_type = kMovementType_16_Grappling                                            , .new_pose_unless_buttons = kPose_B3_FaceL_Grapple_Air             , .direction_shots_fired = 0xff                                                 , .y_offset_proj_origin_to_gfx =  16, .UNUSED_field_5 = 0, .y_radius = 16, .UNUSED_field_7 = 0, },
  [kPose_63]                                = { .pose_x_dir = kSamusXDir_FaceRight    , .movement_type = kMovementType_0D_Unused                                               , .new_pose_unless_buttons = 0xff                                   , .direction_shots_fired = 0xff                                                 , .y_offset_proj_origin_to_gfx =  12, .UNUSED_field_5 = 0, .y_radius = 12, .UNUSED_field_7 = 0, },
  [kPose_64]                                = { .pose_x_dir = kSamusXDir_FaceLeft     , .movement_type = kMovementType_0D_Unused                                               , .new_pose_unless_buttons = 0xff                                   , .direction_shots_fired = 0xff                                                 , .y_offset_proj_origin_to_gfx =  12, .UNUSED_field_5 = 0, .y_radius = 12, .UNUSED_field_7 = 0, },
  [kPose_65]                                = { .pose_x_dir = kSamusXDir_FaceRight    , .movement_type = kMovementType_0D_Unused                                               , .new_pose_unless_buttons = kPose_29_FaceR_Fall                    , .direction_shots_fired = 0xff                                                 , .y_offset_proj_origin_to_gfx =  12, .UNUSED_field_5 = 0, .y_radius = 12, .UNUSED_field_7 = 0, },
  [kPose_66]                                = { .pose_x_dir = kSamusXDir_FaceLeft     , .movement_type = kMovementType_0D_Unused                                               , .new_pose_unless_buttons = kPose_2A_FaceL_Fall                    , .direction_shots_fired = 0xff                                                 , .y_offset_proj_origin_to_gfx =  12, .UNUSED_field_5 = 0, .y_radius = 12, .UNUSED_field_7 = 0, },
  [kPose_67_FaceR_Fall_Gun]                 = { .pose_x_dir = kSamusXDir_FaceRight    , .movement_type = kMovementType_06_Falling                                              , .new_pose_unless_buttons = 0xff                                   , .direction_shots_fired = kProjectileOriginDir_Right                           , .y_offset_proj_origin_to_gfx =   8, .UNUSED_field_5 = 0, .y_radius = 19, .UNUSED_field_7 = 0, },
  [kPose_68_FaceL_Fall_Gun]                 = { .pose_x_dir = kSamusXDir_FaceLeft     , .movement_type = kMovementType_06_Falling                                              , .new_pose_unless_buttons = 0xff                                   , .direction_shots_fired = kProjectileOriginDir_Left                            , .y_offset_proj_origin_to_gfx =   8, .UNUSED_field_5 = 0, .y_radius = 19, .UNUSED_field_7 = 0, },
  [kPose_69_FaceR_Jump_AimUR]               = { .pose_x_dir = kSamusXDir_FaceRight    , .movement_type = kMovementType_02_NormalJumping                                        , .new_pose_unless_buttons = kPose_51_FaceR_Jump_NoAim_MoveF        , .direction_shots_fired = kProjectileOriginDir_UpRight                         , .y_offset_proj_origin_to_gfx =   8, .UNUSED_field_5 = 0, .y_radius = 19, .UNUSED_field_7 = 0, },
  [kPose_6A_FaceL_Jump_AimUL]               = { .pose_x_dir = kSamusXDir_FaceLeft     , .movement_type = kMovementType_02_NormalJumping                                        , .new_pose_unless_buttons = kPose_52_FaceL_Jump_NoAim_MoveF        , .direction_shots_fired = kProjectileOriginDir_UpLeft                          , .y_offset_proj_origin_to_gfx =   8, .UNUSED_field_5 = 0, .y_radius = 19, .UNUSED_field_7 = 0, },
  [kPose_6B_FaceR_Jump_AimDR]               = { .pose_x_dir = kSamusXDir_FaceRight    , .movement_type = kMovementType_02_NormalJumping                                        , .new_pose_unless_buttons = kPose_51_FaceR_Jump_NoAim_MoveF        , .direction_shots_fired = kProjectileOriginDir_DownRight                       , .y_offset_proj_origin_to_gfx =   8, .UNUSED_field_5 = 0, .y_radius = 19, .UNUSED_field_7 = 0, },
  [kPose_6C_FaceL_Jump_AimDL]               = { .pose_x_dir = kSamusXDir_FaceLeft     , .movement_type = kMovementType_02_NormalJumping                                        , .new_pose_unless_buttons = kPose_52_FaceL_Jump_NoAim_MoveF        , .direction_shots_fired = kProjectileOriginDir_DownLeft                        , .y_offset_proj_origin_to_gfx =   8, .UNUSED_field_5 = 0, .y_radius = 19, .UNUSED_field_7 = 0, },
  [kPose_6D_FaceR_Fall_AimUR]               = { .pose_x_dir = kSamusXDir_FaceRight    , .movement_type = kMovementType_06_Falling                                              , .new_pose_unless_buttons = kPose_29_FaceR_Fall                    , .direction_shots_fired = kProjectileOriginDir_UpRight                         , .y_offset_proj_origin_to_gfx =   8, .UNUSED_field_5 = 0, .y_radius = 19, .UNUSED_field_7 = 0, },
  [kPose_6E_FaceL_Fall_AimUL]               = { .pose_x_dir = kSamusXDir_FaceLeft     , .movement_type = kMovementType_06_Falling                                              , .new_pose_unless_buttons = kPose_2A_FaceL_Fall                    , .direction_shots_fired = kProjectileOriginDir_UpLeft                          , .y_offset_proj_origin_to_gfx =   8, .UNUSED_field_5 = 0, .y_radius = 19, .UNUSED_field_7 = 0, },
  [kPose_6F_FaceR_Fall_AimDR]               = { .pose_x_dir = kSamusXDir_FaceRight    , .movement_type = kMovementType_06_Falling                                              , .new_pose_unless_buttons = kPose_29_FaceR_Fall                    , .direction_shots_fired = kProjectileOriginDir_DownRight                       , .y_offset_proj_origin_to_gfx =   8, .UNUSED_field_5 = 0, .y_radius = 19, .UNUSED_field_7 = 0, },
  [kPose_70_FaceL_Fall_AimDL]               = { .pose_x_dir = kSamusXDir_FaceLeft     , .movement_type = kMovementType_06_Falling                                              , .new_pose_unless_buttons = kPose_2A_FaceL_Fall                    , .direction_shots_fired = kProjectileOriginDir_DownLeft                        , .y_offset_proj_origin_to_gfx =   8, .UNUSED_field_5 = 0, .y_radius = 19, .UNUSED_field_7 = 0, },
  [kPose_71_FaceR_Crouch_AimUR]             = { .pose_x_dir = kSamusXDir_FaceRight    , .movement_type = kMovementType_05_Crouching                                            , .new_pose_unless_buttons = kPose_27_FaceR_Crouch                  , .direction_shots_fired = kProjectileOriginDir_UpRight                         , .y_offset_proj_origin_to_gfx =   0, .UNUSED_field_5 = 0, .y_radius = 16, .UNUSED_field_7 = 0, },
  [kPose_72_FaceL_Crouch_AimUL]             = { .pose_x_dir = kSamusXDir_FaceLeft     , .movement_type = kMovementType_05_Crouching                                            , .new_pose_unless_buttons = kPose_28_FaceL_Crouch                  , .direction_shots_fired = kProjectileOriginDir_UpLeft                          , .y_offset_proj_origin_to_gfx =   0, .UNUSED_field_5 = 0, .y_radius = 16, .UNUSED_field_7 = 0, },
  [kPose_73_FaceR_Crouch_AimDR]             = { .pose_x_dir = kSamusXDir_FaceRight    , .movement_type = kMovementType_05_Crouching                                            , .new_pose_unless_buttons = kPose_27_FaceR_Crouch                  , .direction_shots_fired = kProjectileOriginDir_DownRight                       , .y_offset_proj_origin_to_gfx =   0, .UNUSED_field_5 = 0, .y_radius = 16, .UNUSED_field_7 = 0, },
  [kPose_74_FaceL_Crouch_AimDL]             = { .pose_x_dir = kSamusXDir_FaceLeft     , .movement_type = kMovementType_05_Crouching                                            , .new_pose_unless_buttons = kPose_28_FaceL_Crouch                  , .direction_shots_fired = kProjectileOriginDir_DownLeft                        , .y_offset_proj_origin_to_gfx =   0, .UNUSED_field_5 = 0, .y_radius = 16, .UNUSED_field_7 = 0, },
  [kPose_75_FaceL_Moonwalk_AimUL]           = { .pose_x_dir = kSamusXDir_FaceRight    , .movement_type = kMovementType_10_Moonwalking                                          , .new_pose_unless_buttons = kPose_06_FaceL_AimUL                   , .direction_shots_fired = kProjectileOriginDir_UpLeft                          , .y_offset_proj_origin_to_gfx =   6, .UNUSED_field_5 = 0, .y_radius = 21, .UNUSED_field_7 = 0, },
  [kPose_76_FaceR_Moonwalk_AimUR]           = { .pose_x_dir = kSamusXDir_FaceLeft     , .movement_type = kMovementType_10_Moonwalking                                          , .new_pose_unless_buttons = kPose_05_FaceR_AimUR                   , .direction_shots_fired = kProjectileOriginDir_UpRight                         , .y_offset_proj_origin_to_gfx =   6, .UNUSED_field_5 = 0, .y_radius = 21, .UNUSED_field_7 = 0, },
  [kPose_77_FaceL_Moonwalk_AimDL]           = { .pose_x_dir = kSamusXDir_FaceRight    , .movement_type = kMovementType_10_Moonwalking                                          , .new_pose_unless_buttons = kPose_08_FaceL_AimDL                   , .direction_shots_fired = kProjectileOriginDir_DownLeft                        , .y_offset_proj_origin_to_gfx =   6, .UNUSED_field_5 = 0, .y_radius = 21, .UNUSED_field_7 = 0, },
  [kPose_78_FaceR_Moonwalk_AimDR]           = { .pose_x_dir = kSamusXDir_FaceLeft     , .movement_type = kMovementType_10_Moonwalking                                          , .new_pose_unless_buttons = kPose_07_FaceR_AimDR                   , .direction_shots_fired = kProjectileOriginDir_DownRight                       , .y_offset_proj_origin_to_gfx =   6, .UNUSED_field_5 = 0, .y_radius = 21, .UNUSED_field_7 = 0, },
  [kPose_79_FaceR_Springball_Ground]        = { .pose_x_dir = kSamusXDir_FaceRight    , .movement_type = kMovementType_11_SpringBallOnGround                                   , .new_pose_unless_buttons = 0xff                                   , .direction_shots_fired = 0xff                                                 , .y_offset_proj_origin_to_gfx =   0, .UNUSED_field_5 = 0, .y_radius =  7, .UNUSED_field_7 = 0, },
  [kPose_7A_FaceL_Springball_Ground]        = { .pose_x_dir = kSamusXDir_FaceLeft     , .movement_type = kMovementType_11_SpringBallOnGround                                   , .new_pose_unless_buttons = 0xff                                   , .direction_shots_fired = 0xff                                                 , .y_offset_proj_origin_to_gfx =   0, .UNUSED_field_5 = 0, .y_radius =  7, .UNUSED_field_7 = 0, },
  [kPose_7B_MoveR_Springball_Ground]        = { .pose_x_dir = kSamusXDir_FaceRight    , .movement_type = kMovementType_11_SpringBallOnGround                                   , .new_pose_unless_buttons = kPose_79_FaceR_Springball_Ground       , .direction_shots_fired = 0xff                                                 , .y_offset_proj_origin_to_gfx =   0, .UNUSED_field_5 = 0, .y_radius =  7, .UNUSED_field_7 = 0, },
  [kPose_7C_MoveL_Springball_Ground]        = { .pose_x_dir = kSamusXDir_FaceLeft     , .movement_type = kMovementType_11_SpringBallOnGround                                   , .new_pose_unless_buttons = kPose_7A_FaceL_Springball_Ground       , .direction_shots_fired = 0xff                                                 , .y_offset_proj_origin_to_gfx =   0, .UNUSED_field_5 = 0, .y_radius =  7, .UNUSED_field_7 = 0, },
  [kPose_7D_FaceR_Springball_Fall]          = { .pose_x_dir = kSamusXDir_FaceRight    , .movement_type = kMovementType_13_SpringBallFalling                                    , .new_pose_unless_buttons = 0xff                                   , .direction_shots_fired = 0xff                                                 , .y_offset_proj_origin_to_gfx =   0, .UNUSED_field_5 = 0, .y_radius =  7, .UNUSED_field_7 = 0, },
  [kPose_7E_FaceL_Springball_Fall]          = { .pose_x_dir = kSamusXDir_FaceLeft     , .movement_type = kMovementType_13_SpringBallFalling                                    , .new_pose_unless_buttons = 0xff                                   , .direction_shots_fired = 0xff                                                 , .y_offset_proj_origin_to_gfx =   0, .UNUSED_field_5 = 0, .y_radius =  7, .UNUSED_field_7 = 0, },
  [kPose_7F_FaceR_Springball_Air]           = { .pose_x_dir = kSamusXDir_FaceRight    , .movement_type = kMovementType_12_SpringBallInAir                                      , .new_pose_unless_buttons = 0xff                                   , .direction_shots_fired = 0xff                                                 , .y_offset_proj_origin_to_gfx =   0, .UNUSED_field_5 = 0, .y_radius =  7, .UNUSED_field_7 = 0, },
  [kPose_80_FaceL_Springball_Air]           = { .pose_x_dir = kSamusXDir_FaceLeft     , .movement_type = kMovementType_12_SpringBallInAir                                      , .new_pose_unless_buttons = 0xff                                   , .direction_shots_fired = 0xff                                                 , .y_offset_proj_origin_to_gfx =   0, .UNUSED_field_5 = 0, .y_radius =  7, .UNUSED_field_7 = 0, },
  [kPose_81_FaceR_Screwattack]              = { .pose_x_dir = kSamusXDir_FaceRight    , .movement_type = kMovementType_03_SpinJumping                                          , .new_pose_unless_buttons = 0xff                                   , .direction_shots_fired = 0xff                                                 , .y_offset_proj_origin_to_gfx =   0, .UNUSED_field_5 = 0, .y_radius = 12, .UNUSED_field_7 = 0, },
  [kPose_82_FaceL_Screwattack]              = { .pose_x_dir = kSamusXDir_FaceLeft     , .movement_type = kMovementType_03_SpinJumping                                          , .new_pose_unless_buttons = 0xff                                   , .direction_shots_fired = 0xff                                                 , .y_offset_proj_origin_to_gfx =   0, .UNUSED_field_5 = 0, .y_radius = 12, .UNUSED_field_7 = 0, },
  [kPose_83_FaceR_Walljump]                 = { .pose_x_dir = kSamusXDir_FaceRight    , .movement_type = kMovementType_14_WallJumping                                          , .new_pose_unless_buttons = kPose_19_FaceR_SpinJump                , .direction_shots_fired = 0xff                                                 , .y_offset_proj_origin_to_gfx =   8, .UNUSED_field_5 = 0, .y_radius = 19, .UNUSED_field_7 = 0, },
  [kPose_84_FaceL_Walljump]                 = { .pose_x_dir = kSamusXDir_FaceLeft     , .movement_type = kMovementType_14_WallJumping                                          , .new_pose_unless_buttons = kPose_1A_FaceL_SpinJump                , .direction_shots_fired = 0xff                                                 , .y_offset_proj_origin_to_gfx =   8, .UNUSED_field_5 = 0, .y_radius = 19, .UNUSED_field_7 = 0, },
  [kPose_85_FaceR_Crouch_AimU]              = { .pose_x_dir = kSamusXDir_FaceRight    , .movement_type = kMovementType_05_Crouching                                            , .new_pose_unless_buttons = kPose_27_FaceR_Crouch                  , .direction_shots_fired = kProjectileOriginDir_UpFaceRight                     , .y_offset_proj_origin_to_gfx =   0, .UNUSED_field_5 = 0, .y_radius = 16, .UNUSED_field_7 = 0, },
  [kPose_86_FaceL_Crouch_AimU]              = { .pose_x_dir = kSamusXDir_FaceLeft     , .movement_type = kMovementType_05_Crouching                                            , .new_pose_unless_buttons = kPose_28_FaceL_Crouch                  , .direction_shots_fired = kProjectileOriginDir_UpFaceLeft                      , .y_offset_proj_origin_to_gfx =   0, .UNUSED_field_5 = 0, .y_radius = 16, .UNUSED_field_7 = 0, },
  [kPose_87_FaceR_Turn_Fall]                = { .pose_x_dir = kSamusXDir_FaceLeft     , .movement_type = kMovementType_18_TurningAroundFalling                                 , .new_pose_unless_buttons = 0xff                                   , .direction_shots_fired = SHOT_DISABLED | kProjectileOriginDir_TurnAimNeutral  , .y_offset_proj_origin_to_gfx =   8, .UNUSED_field_5 = 0, .y_radius = 19, .UNUSED_field_7 = 0, },
  [kPose_88_FaceL_Turn_Fall]                = { .pose_x_dir = kSamusXDir_FaceRight    , .movement_type = kMovementType_18_TurningAroundFalling                                 , .new_pose_unless_buttons = 0xff                                   , .direction_shots_fired = SHOT_DISABLED | kProjectileOriginDir_TurnAimNeutral  , .y_offset_proj_origin_to_gfx =   8, .UNUSED_field_5 = 0, .y_radius = 19, .UNUSED_field_7 = 0, },
  [kPose_89_FaceR_Ranintowall]              = { .pose_x_dir = kSamusXDir_FaceRight    , .movement_type = kMovementType_15_RanIntoWall                                          , .new_pose_unless_buttons = 0xff                                   , .direction_shots_fired = kProjectileOriginDir_Right                           , .y_offset_proj_origin_to_gfx =   6, .UNUSED_field_5 = 0, .y_radius = 21, .UNUSED_field_7 = 0, },
  [kPose_8A_FaceL_Ranintowall]              = { .pose_x_dir = kSamusXDir_FaceLeft     , .movement_type = kMovementType_15_RanIntoWall                                          , .new_pose_unless_buttons = 0xff                                   , .direction_shots_fired = kProjectileOriginDir_Left                            , .y_offset_proj_origin_to_gfx =   6, .UNUSED_field_5 = 0, .y_radius = 21, .UNUSED_field_7 = 0, },
  [kPose_8B_FaceR_Turn_Stand_AimU]          = { .pose_x_dir = kSamusXDir_FaceLeft     , .movement_type = kMovementType_0E_TurningAroundOnGround                                , .new_pose_unless_buttons = 0xff                                   , .direction_shots_fired = SHOT_DISABLED | kProjectileOriginDir_TurnAimUpward   , .y_offset_proj_origin_to_gfx =   6, .UNUSED_field_5 = 0, .y_radius = 21, .UNUSED_field_7 = 0, },
  [kPose_8C_FaceL_Turn_Stand_AimU]          = { .pose_x_dir = kSamusXDir_FaceRight    , .movement_type = kMovementType_0E_TurningAroundOnGround                                , .new_pose_unless_buttons = 0xff                                   , .direction_shots_fired = SHOT_DISABLED | kProjectileOriginDir_TurnAimUpward   , .y_offset_proj_origin_to_gfx =   6, .UNUSED_field_5 = 0, .y_radius = 21, .UNUSED_field_7 = 0, },
  [kPose_8D_FaceR_Turn_Stand_AimDR]         = { .pose_x_dir = kSamusXDir_FaceLeft     , .movement_type = kMovementType_0E_TurningAroundOnGround                                , .new_pose_unless_buttons = 0xff                                   , .direction_shots_fired = SHOT_DISABLED | kProjectileOriginDir_TurnAimDownward , .y_offset_proj_origin_to_gfx =   6, .UNUSED_field_5 = 0, .y_radius = 21, .UNUSED_field_7 = 0, },
  [kPose_8E_FaceL_Turn_Stand_AimDL]         = { .pose_x_dir = kSamusXDir_FaceRight    , .movement_type = kMovementType_0E_TurningAroundOnGround                                , .new_pose_unless_buttons = 0xff                                   , .direction_shots_fired = SHOT_DISABLED | kProjectileOriginDir_TurnAimDownward , .y_offset_proj_origin_to_gfx =   6, .UNUSED_field_5 = 0, .y_radius = 21, .UNUSED_field_7 = 0, },
  [kPose_8F_FaceR_Turn_Air_AimU]            = { .pose_x_dir = kSamusXDir_FaceLeft     , .movement_type = kMovementType_17_TurningAroundJumping                                 , .new_pose_unless_buttons = 0xff                                   , .direction_shots_fired = SHOT_DISABLED | kProjectileOriginDir_TurnAimUpward   , .y_offset_proj_origin_to_gfx =   8, .UNUSED_field_5 = 0, .y_radius = 19, .UNUSED_field_7 = 0, },
  [kPose_90_FaceL_Turn_Air_AimU]            = { .pose_x_dir = kSamusXDir_FaceRight    , .movement_type = kMovementType_17_TurningAroundJumping                                 , .new_pose_unless_buttons = 0xff                                   , .direction_shots_fired = SHOT_DISABLED | kProjectileOriginDir_TurnAimUpward   , .y_offset_proj_origin_to_gfx =   8, .UNUSED_field_5 = 0, .y_radius = 19, .UNUSED_field_7 = 0, },
  [kPose_91_FaceR_Turn_Air_AimDDR]          = { .pose_x_dir = kSamusXDir_FaceLeft     , .movement_type = kMovementType_17_TurningAroundJumping                                 , .new_pose_unless_buttons = 0xff                                   , .direction_shots_fired = SHOT_DISABLED | kProjectileOriginDir_TurnAimDownward , .y_offset_proj_origin_to_gfx =   8, .UNUSED_field_5 = 0, .y_radius = 19, .UNUSED_field_7 = 0, },
  [kPose_92_FaceL_Turn_Air_AimDDL]          = { .pose_x_dir = kSamusXDir_FaceRight    , .movement_type = kMovementType_17_TurningAroundJumping                                 , .new_pose_unless_buttons = 0xff                                   , .direction_shots_fired = SHOT_DISABLED | kProjectileOriginDir_TurnAimDownward , .y_offset_proj_origin_to_gfx =   8, .UNUSED_field_5 = 0, .y_radius = 19, .UNUSED_field_7 = 0, },
  [kPose_93_FaceR_Turn_Fall_AimU]           = { .pose_x_dir = kSamusXDir_FaceLeft     , .movement_type = kMovementType_18_TurningAroundFalling                                 , .new_pose_unless_buttons = 0xff                                   , .direction_shots_fired = SHOT_DISABLED | kProjectileOriginDir_TurnAimUpward   , .y_offset_proj_origin_to_gfx =   8, .UNUSED_field_5 = 0, .y_radius = 19, .UNUSED_field_7 = 0, },
  [kPose_94_FaceL_Turn_Fall_AimU]           = { .pose_x_dir = kSamusXDir_FaceRight    , .movement_type = kMovementType_18_TurningAroundFalling                                 , .new_pose_unless_buttons = 0xff                                   , .direction_shots_fired = SHOT_DISABLED | kProjectileOriginDir_TurnAimUpward   , .y_offset_proj_origin_to_gfx =   8, .UNUSED_field_5 = 0, .y_radius = 19, .UNUSED_field_7 = 0, },
  [kPose_95_FaceR_Turn_Fall_AimDDR]         = { .pose_x_dir = kSamusXDir_FaceLeft     , .movement_type = kMovementType_18_TurningAroundFalling                                 , .new_pose_unless_buttons = 0xff                                   , .direction_shots_fired = SHOT_DISABLED | kProjectileOriginDir_TurnAimDownward , .y_offset_proj_origin_to_gfx =   8, .UNUSED_field_5 = 0, .y_radius = 19, .UNUSED_field_7 = 0, },
  [kPose_96_FaceL_Turn_Fall_AimDDL]         = { .pose_x_dir = kSamusXDir_FaceRight    , .movement_type = kMovementType_18_TurningAroundFalling                                 , .new_pose_unless_buttons = 0xff                                   , .direction_shots_fired = SHOT_DISABLED | kProjectileOriginDir_TurnAimDownward , .y_offset_proj_origin_to_gfx =   8, .UNUSED_field_5 = 0, .y_radius = 19, .UNUSED_field_7 = 0, },
  [kPose_97_FaceR_Turn_Crouch_AimU]         = { .pose_x_dir = kSamusXDir_FaceLeft     , .movement_type = kMovementType_17_TurningAroundJumping                                 , .new_pose_unless_buttons = kPose_28_FaceL_Crouch                  , .direction_shots_fired = SHOT_DISABLED | kProjectileOriginDir_TurnAimUpward   , .y_offset_proj_origin_to_gfx =   0, .UNUSED_field_5 = 0, .y_radius = 16, .UNUSED_field_7 = 0, },
  [kPose_98_FaceL_Turn_Crouch_AimU]         = { .pose_x_dir = kSamusXDir_FaceRight    , .movement_type = kMovementType_17_TurningAroundJumping                                 , .new_pose_unless_buttons = kPose_28_FaceL_Crouch                  , .direction_shots_fired = SHOT_DISABLED | kProjectileOriginDir_TurnAimUpward   , .y_offset_proj_origin_to_gfx =   0, .UNUSED_field_5 = 0, .y_radius = 16, .UNUSED_field_7 = 0, },
  [kPose_99_FaceR_Turn_Crouch_AimDDR]       = { .pose_x_dir = kSamusXDir_FaceLeft     , .movement_type = kMovementType_17_TurningAroundJumping                                 , .new_pose_unless_buttons = kPose_28_FaceL_Crouch                  , .direction_shots_fired = SHOT_DISABLED | kProjectileOriginDir_TurnAimDownward , .y_offset_proj_origin_to_gfx =   0, .UNUSED_field_5 = 0, .y_radius = 16, .UNUSED_field_7 = 0, },
  [kPose_9A_FaceL_Turn_Crouch_AimDDL]       = { .pose_x_dir = kSamusXDir_FaceRight    , .movement_type = kMovementType_17_TurningAroundJumping                                 , .new_pose_unless_buttons = kPose_28_FaceL_Crouch                  , .direction_shots_fired = SHOT_DISABLED | kProjectileOriginDir_TurnAimDownward , .y_offset_proj_origin_to_gfx =   0, .UNUSED_field_5 = 0, .y_radius = 16, .UNUSED_field_7 = 0, },
  [kPose_9B_FaceF_VariaGravitySuit]         = { .pose_x_dir = kSamusXDir_FaceForward  , .movement_type = kMovementType_00_Standing                                             , .new_pose_unless_buttons = 0xff                                   , .direction_shots_fired = 0xff                                                 , .y_offset_proj_origin_to_gfx =   8, .UNUSED_field_5 = 0, .y_radius = 24, .UNUSED_field_7 = 0, },
  [kPose_9C_FaceR_Turn_Stand_AimUR]         = { .pose_x_dir = kSamusXDir_FaceLeft     , .movement_type = kMovementType_0E_TurningAroundOnGround                                , .new_pose_unless_buttons = 0xff                                   , .direction_shots_fired = SHOT_DISABLED | kProjectileOriginDir_TurnAimUpward   , .y_offset_proj_origin_to_gfx =   6, .UNUSED_field_5 = 0, .y_radius = 21, .UNUSED_field_7 = 0, },
  [kPose_9D_FaceL_Turn_Stand_AimUL]         = { .pose_x_dir = kSamusXDir_FaceRight    , .movement_type = kMovementType_0E_TurningAroundOnGround                                , .new_pose_unless_buttons = 0xff                                   , .direction_shots_fired = SHOT_DISABLED | kProjectileOriginDir_TurnAimUpward   , .y_offset_proj_origin_to_gfx =   6, .UNUSED_field_5 = 0, .y_radius = 21, .UNUSED_field_7 = 0, },
  [kPose_9E_FaceR_Turn_Air_AimUR]           = { .pose_x_dir = kSamusXDir_FaceLeft     , .movement_type = kMovementType_17_TurningAroundJumping                                 , .new_pose_unless_buttons = 0xff                                   , .direction_shots_fired = SHOT_DISABLED | kProjectileOriginDir_TurnAimUpward   , .y_offset_proj_origin_to_gfx =   8, .UNUSED_field_5 = 0, .y_radius = 19, .UNUSED_field_7 = 0, },
  [kPose_9F_FaceL_Turn_Air_AimUL]           = { .pose_x_dir = kSamusXDir_FaceRight    , .movement_type = kMovementType_17_TurningAroundJumping                                 , .new_pose_unless_buttons = 0xff                                   , .direction_shots_fired = SHOT_DISABLED | kProjectileOriginDir_TurnAimUpward   , .y_offset_proj_origin_to_gfx =   8, .UNUSED_field_5 = 0, .y_radius = 19, .UNUSED_field_7 = 0, },
  [kPose_A0_FaceR_Turn_Fall_AimUR]          = { .pose_x_dir = kSamusXDir_FaceLeft     , .movement_type = kMovementType_18_TurningAroundFalling                                 , .new_pose_unless_buttons = 0xff                                   , .direction_shots_fired = SHOT_DISABLED | kProjectileOriginDir_TurnAimUpward   , .y_offset_proj_origin_to_gfx =   8, .UNUSED_field_5 = 0, .y_radius = 19, .UNUSED_field_7 = 0, },
  [kPose_A1_FaceL_Turn_Fall_AimUL]          = { .pose_x_dir = kSamusXDir_FaceRight    , .movement_type = kMovementType_18_TurningAroundFalling                                 , .new_pose_unless_buttons = 0xff                                   , .direction_shots_fired = SHOT_DISABLED | kProjectileOriginDir_TurnAimUpward   , .y_offset_proj_origin_to_gfx =   8, .UNUSED_field_5 = 0, .y_radius = 19, .UNUSED_field_7 = 0, },
  [kPose_A2_FaceR_Turn_Crouch_AimUR]        = { .pose_x_dir = kSamusXDir_FaceLeft     , .movement_type = kMovementType_17_TurningAroundJumping                                 , .new_pose_unless_buttons = kPose_28_FaceL_Crouch                  , .direction_shots_fired = SHOT_DISABLED | kProjectileOriginDir_TurnAimUpward   , .y_offset_proj_origin_to_gfx =   0, .UNUSED_field_5 = 0, .y_radius = 16, .UNUSED_field_7 = 0, },
  [kPose_A3_FaceL_Turn_Crouch_AimUL]        = { .pose_x_dir = kSamusXDir_FaceRight    , .movement_type = kMovementType_17_TurningAroundJumping                                 , .new_pose_unless_buttons = kPose_28_FaceL_Crouch                  , .direction_shots_fired = SHOT_DISABLED | kProjectileOriginDir_TurnAimUpward   , .y_offset_proj_origin_to_gfx =   0, .UNUSED_field_5 = 0, .y_radius = 16, .UNUSED_field_7 = 0, },
  [kPose_A4_FaceR_LandJump]                 = { .pose_x_dir = kSamusXDir_FaceRight    , .movement_type = kMovementType_00_Standing                                             , .new_pose_unless_buttons = 0xff                                   , .direction_shots_fired = kProjectileOriginDir_Right                           , .y_offset_proj_origin_to_gfx =   3, .UNUSED_field_5 = 0, .y_radius = 21, .UNUSED_field_7 = 0, },
  [kPose_A5_FaceL_LandJump]                 = { .pose_x_dir = kSamusXDir_FaceLeft     , .movement_type = kMovementType_00_Standing                                             , .new_pose_unless_buttons = 0xff                                   , .direction_shots_fired = kProjectileOriginDir_Left                            , .y_offset_proj_origin_to_gfx =   3, .UNUSED_field_5 = 0, .y_radius = 21, .UNUSED_field_7 = 0, },
  [kPose_A6_FaceR_LandSpinJump]             = { .pose_x_dir = kSamusXDir_FaceRight    , .movement_type = kMovementType_00_Standing                                             , .new_pose_unless_buttons = 0xff                                   , .direction_shots_fired = kProjectileOriginDir_Right                           , .y_offset_proj_origin_to_gfx =   3, .UNUSED_field_5 = 0, .y_radius = 21, .UNUSED_field_7 = 0, },
  [kPose_A7_FaceL_LandSpinJump]             = { .pose_x_dir = kSamusXDir_FaceLeft     , .movement_type = kMovementType_00_Standing                                             , .new_pose_unless_buttons = 0xff                                   , .direction_shots_fired = kProjectileOriginDir_Left                            , .y_offset_proj_origin_to_gfx =   3, .UNUSED_field_5 = 0, .y_radius = 21, .UNUSED_field_7 = 0, },
  [kPose_A8_FaceR_Grappling]                = { .pose_x_dir = kSamusXDir_FaceRight    , .movement_type = kMovementType_16_Grappling                                            , .new_pose_unless_buttons = kPose_01_FaceR_Normal                  , .direction_shots_fired = kProjectileOriginDir_Right                           , .y_offset_proj_origin_to_gfx =   6, .UNUSED_field_5 = 0, .y_radius = 21, .UNUSED_field_7 = 0, },
  [kPose_A9_FaceL_Grappling]                = { .pose_x_dir = kSamusXDir_FaceLeft     , .movement_type = kMovementType_16_Grappling                                            , .new_pose_unless_buttons = kPose_02_FaceL_Normal                  , .direction_shots_fired = kProjectileOriginDir_Left                            , .y_offset_proj_origin_to_gfx =   6, .UNUSED_field_5 = 0, .y_radius = 21, .UNUSED_field_7 = 0, },
  [kPose_AA_FaceR_Grappling_AimDR]          = { .pose_x_dir = kSamusXDir_FaceRight    , .movement_type = kMovementType_16_Grappling                                            , .new_pose_unless_buttons = kPose_07_FaceR_AimDR                   , .direction_shots_fired = kProjectileOriginDir_DownRight                       , .y_offset_proj_origin_to_gfx =   6, .UNUSED_field_5 = 0, .y_radius = 21, .UNUSED_field_7 = 0, },
  [kPose_AB_FaceL_Grappling_AimDL]          = { .pose_x_dir = kSamusXDir_FaceLeft     , .movement_type = kMovementType_16_Grappling                                            , .new_pose_unless_buttons = kPose_08_FaceL_AimDL                   , .direction_shots_fired = kProjectileOriginDir_DownLeft                        , .y_offset_proj_origin_to_gfx =   6, .UNUSED_field_5 = 0, .y_radius = 21, .UNUSED_field_7 = 0, },
  [kPose_AC]                                = { .pose_x_dir = kSamusXDir_FaceRight    , .movement_type = kMovementType_16_Grappling                                            , .new_pose_unless_buttons = kPose_67_FaceR_Fall_Gun                , .direction_shots_fired = kProjectileOriginDir_Right                           , .y_offset_proj_origin_to_gfx =   8, .UNUSED_field_5 = 0, .y_radius = 19, .UNUSED_field_7 = 0, },
  [kPose_AD]                                = { .pose_x_dir = kSamusXDir_FaceLeft     , .movement_type = kMovementType_16_Grappling                                            , .new_pose_unless_buttons = kPose_68_FaceL_Fall_Gun                , .direction_shots_fired = kProjectileOriginDir_Left                            , .y_offset_proj_origin_to_gfx =   8, .UNUSED_field_5 = 0, .y_radius = 19, .UNUSED_field_7 = 0, },
  [kPose_AE]                                = { .pose_x_dir = kSamusXDir_FaceRight    , .movement_type = kMovementType_16_Grappling                                            , .new_pose_unless_buttons = kPose_2D_FaceR_Fall_AimD               , .direction_shots_fired = kProjectileOriginDir_DownFaceRight                   , .y_offset_proj_origin_to_gfx =   6, .UNUSED_field_5 = 0, .y_radius = 10, .UNUSED_field_7 = 0, },
  [kPose_AF]                                = { .pose_x_dir = kSamusXDir_FaceLeft     , .movement_type = kMovementType_16_Grappling                                            , .new_pose_unless_buttons = kPose_2E_FaceL_Fall_AimD               , .direction_shots_fired = kProjectileOriginDir_DownFaceLeft                    , .y_offset_proj_origin_to_gfx =   6, .UNUSED_field_5 = 0, .y_radius = 10, .UNUSED_field_7 = 0, },
  [kPose_B0]                                = { .pose_x_dir = kSamusXDir_FaceRight    , .movement_type = kMovementType_16_Grappling                                            , .new_pose_unless_buttons = kPose_6F_FaceR_Fall_AimDR              , .direction_shots_fired = kProjectileOriginDir_DownRight                       , .y_offset_proj_origin_to_gfx =   8, .UNUSED_field_5 = 0, .y_radius = 19, .UNUSED_field_7 = 0, },
  [kPose_B1]                                = { .pose_x_dir = kSamusXDir_FaceLeft     , .movement_type = kMovementType_16_Grappling                                            , .new_pose_unless_buttons = kPose_70_FaceL_Fall_AimDL              , .direction_shots_fired = kProjectileOriginDir_DownLeft                        , .y_offset_proj_origin_to_gfx =   8, .UNUSED_field_5 = 0, .y_radius = 19, .UNUSED_field_7 = 0, },
  [kPose_B2_FaceR_Grapple_Air]              = { .pose_x_dir = kSamusXDir_FaceRight    , .movement_type = kMovementType_16_Grappling                                            , .new_pose_unless_buttons = kPose_B2_FaceR_Grapple_Air             , .direction_shots_fired = 0xff                                                 , .y_offset_proj_origin_to_gfx =  16, .UNUSED_field_5 = 0, .y_radius = 17, .UNUSED_field_7 = 0, },
  [kPose_B3_FaceL_Grapple_Air]              = { .pose_x_dir = kSamusXDir_FaceLeft     , .movement_type = kMovementType_16_Grappling                                            , .new_pose_unless_buttons = kPose_B3_FaceL_Grapple_Air             , .direction_shots_fired = 0xff                                                 , .y_offset_proj_origin_to_gfx =  16, .UNUSED_field_5 = 0, .y_radius = 17, .UNUSED_field_7 = 0, },
  [kPose_B4_FaceR_Grappling_Crouch]         = { .pose_x_dir = kSamusXDir_FaceRight    , .movement_type = kMovementType_16_Grappling                                            , .new_pose_unless_buttons = kPose_27_FaceR_Crouch                  , .direction_shots_fired = kProjectileOriginDir_Right                           , .y_offset_proj_origin_to_gfx =   0, .UNUSED_field_5 = 0, .y_radius = 16, .UNUSED_field_7 = 0, },
  [kPose_B5_FaceL_Grappling_Crouch]         = { .pose_x_dir = kSamusXDir_FaceLeft     , .movement_type = kMovementType_16_Grappling                                            , .new_pose_unless_buttons = kPose_28_FaceL_Crouch                  , .direction_shots_fired = kProjectileOriginDir_Left                            , .y_offset_proj_origin_to_gfx =   0, .UNUSED_field_5 = 0, .y_radius = 16, .UNUSED_field_7 = 0, },
  [kPose_B6_FaceR_Grappling_Crouch_AimDR]   = { .pose_x_dir = kSamusXDir_FaceRight    , .movement_type = kMovementType_16_Grappling                                            , .new_pose_unless_buttons = kPose_27_FaceR_Crouch                  , .direction_shots_fired = kProjectileOriginDir_DownRight                       , .y_offset_proj_origin_to_gfx =   0, .UNUSED_field_5 = 0, .y_radius = 16, .UNUSED_field_7 = 0, },
  [kPose_B7_FaceL_Grappling_Crouch_AimDL]   = { .pose_x_dir = kSamusXDir_FaceLeft     , .movement_type = kMovementType_16_Grappling                                            , .new_pose_unless_buttons = kPose_28_FaceL_Crouch                  , .direction_shots_fired = kProjectileOriginDir_DownLeft                        , .y_offset_proj_origin_to_gfx =   0, .UNUSED_field_5 = 0, .y_radius = 16, .UNUSED_field_7 = 0, },
  [kPose_B8_FaceL_GrappleWalljumpPose]      = { .pose_x_dir = kSamusXDir_FaceRight    , .movement_type = kMovementType_16_Grappling                                            , .new_pose_unless_buttons = 0xff                                   , .direction_shots_fired = kProjectileOriginDir_DownRight                       , .y_offset_proj_origin_to_gfx =   0, .UNUSED_field_5 = 0, .y_radius = 16, .UNUSED_field_7 = 0, },
  [kPose_B9_FaceR_GrappleWalljumpPose]      = { .pose_x_dir = kSamusXDir_FaceLeft     , .movement_type = kMovementType_16_Grappling                                            , .new_pose_unless_buttons = 0xff                                   , .direction_shots_fired = kProjectileOriginDir_DownLeft                        , .y_offset_proj_origin_to_gfx =   0, .UNUSED_field_5 = 0, .y_radius = 16, .UNUSED_field_7 = 0, },
  [kPose_BA_FaceL_Draygon_NoMove_NoAim]     = { .pose_x_dir = kSamusXDir_FaceLeft     , .movement_type = kMovementType_1A_GrabbedByDraygon                                     , .new_pose_unless_buttons = 0xff                                   , .direction_shots_fired = kProjectileOriginDir_Left                            , .y_offset_proj_origin_to_gfx =   6, .UNUSED_field_5 = 0, .y_radius = 21, .UNUSED_field_7 = 0, },
  [kPose_BB_FaceL_Draygon_NoMove_AimUL]     = { .pose_x_dir = kSamusXDir_FaceLeft     , .movement_type = kMovementType_1A_GrabbedByDraygon                                     , .new_pose_unless_buttons = kPose_BA_FaceL_Draygon_NoMove_NoAim    , .direction_shots_fired = kProjectileOriginDir_UpLeft                          , .y_offset_proj_origin_to_gfx =   6, .UNUSED_field_5 = 0, .y_radius = 21, .UNUSED_field_7 = 0, },
  [kPose_BC_FaceL_Draygon_Fire]             = { .pose_x_dir = kSamusXDir_FaceLeft     , .movement_type = kMovementType_1A_GrabbedByDraygon                                     , .new_pose_unless_buttons = kPose_BA_FaceL_Draygon_NoMove_NoAim    , .direction_shots_fired = kProjectileOriginDir_Left                            , .y_offset_proj_origin_to_gfx =   6, .UNUSED_field_5 = 0, .y_radius = 21, .UNUSED_field_7 = 0, },
  [kPose_BD_FaceL_Draygon_NoMove_AimDL]     = { .pose_x_dir = kSamusXDir_FaceLeft     , .movement_type = kMovementType_1A_GrabbedByDraygon                                     , .new_pose_unless_buttons = kPose_BA_FaceL_Draygon_NoMove_NoAim    , .direction_shots_fired = kProjectileOriginDir_DownLeft                        , .y_offset_proj_origin_to_gfx =   6, .UNUSED_field_5 = 0, .y_radius = 21, .UNUSED_field_7 = 0, },
  [kPose_BE_FaceL_Draygon_Move]             = { .pose_x_dir = kSamusXDir_FaceLeft     , .movement_type = kMovementType_1A_GrabbedByDraygon                                     , .new_pose_unless_buttons = kPose_BA_FaceL_Draygon_NoMove_NoAim    , .direction_shots_fired = 0xff                                                 , .y_offset_proj_origin_to_gfx =   6, .UNUSED_field_5 = 0, .y_radius = 21, .UNUSED_field_7 = 0, },
  [kPose_BF_FaceR_Moonwalk_TurnjumpL]       = { .pose_x_dir = kSamusXDir_FaceLeft     , .movement_type = kMovementType_0E_TurningAroundOnGround                                , .new_pose_unless_buttons = 0xff                                   , .direction_shots_fired = SHOT_DISABLED | kProjectileOriginDir_TurnAimNeutral  , .y_offset_proj_origin_to_gfx =   6, .UNUSED_field_5 = 0, .y_radius = 21, .UNUSED_field_7 = 0, },
  [kPose_C0_FaceL_Moonwalk_TurnjumpR]       = { .pose_x_dir = kSamusXDir_FaceRight    , .movement_type = kMovementType_0E_TurningAroundOnGround                                , .new_pose_unless_buttons = 0xff                                   , .direction_shots_fired = SHOT_DISABLED | kProjectileOriginDir_TurnAimNeutral  , .y_offset_proj_origin_to_gfx =   6, .UNUSED_field_5 = 0, .y_radius = 21, .UNUSED_field_7 = 0, },
  [kPose_C1_FaceR_Moonwalk_TurnjumpL_AimUR] = { .pose_x_dir = kSamusXDir_FaceLeft     , .movement_type = kMovementType_0E_TurningAroundOnGround                                , .new_pose_unless_buttons = 0xff                                   , .direction_shots_fired = SHOT_DISABLED | kProjectileOriginDir_TurnAimUpward   , .y_offset_proj_origin_to_gfx =   8, .UNUSED_field_5 = 0, .y_radius = 21, .UNUSED_field_7 = 0, },
  [kPose_C2_FaceL_Moonwalk_TurnjumpR_AimUL] = { .pose_x_dir = kSamusXDir_FaceRight    , .movement_type = kMovementType_0E_TurningAroundOnGround                                , .new_pose_unless_buttons = 0xff                                   , .direction_shots_fired = SHOT_DISABLED | kProjectileOriginDir_TurnAimUpward   , .y_offset_proj_origin_to_gfx =   8, .UNUSED_field_5 = 0, .y_radius = 21, .UNUSED_field_7 = 0, },
  [kPose_C3_FaceR_Moonwalk_TurnjumpL_AimDR] = { .pose_x_dir = kSamusXDir_FaceLeft     , .movement_type = kMovementType_0E_TurningAroundOnGround                                , .new_pose_unless_buttons = 0xff                                   , .direction_shots_fired = SHOT_DISABLED | kProjectileOriginDir_TurnAimDownward , .y_offset_proj_origin_to_gfx =   8, .UNUSED_field_5 = 0, .y_radius = 21, .UNUSED_field_7 = 0, },
  [kPose_C4_FaceL_Moonwalk_TurnjumpR_AimDL] = { .pose_x_dir = kSamusXDir_FaceRight    , .movement_type = kMovementType_0E_TurningAroundOnGround                                , .new_pose_unless_buttons = 0xff                                   , .direction_shots_fired = SHOT_DISABLED | kProjectileOriginDir_TurnAimDownward , .y_offset_proj_origin_to_gfx =   8, .UNUSED_field_5 = 0, .y_radius = 21, .UNUSED_field_7 = 0, },
  [kPose_C5]                                = { .pose_x_dir = kSamusXDir_FaceLeft     , .movement_type = kMovementType_1A_GrabbedByDraygon                                     , .new_pose_unless_buttons = 0xff                                   , .direction_shots_fired = 0xff                                                 , .y_offset_proj_origin_to_gfx =   0, .UNUSED_field_5 = 0, .y_radius =  7, .UNUSED_field_7 = 0, },
  [kPose_C6]                                = { .pose_x_dir = kSamusXDir_FaceLeft     , .movement_type = kMovementType_1A_GrabbedByDraygon                                     , .new_pose_unless_buttons = 0xff                                   , .direction_shots_fired = SHOT_DISABLED | kProjectileOriginDir_TurnAimNeutral  , .y_offset_proj_origin_to_gfx =   6, .UNUSED_field_5 = 0, .y_radius = 21, .UNUSED_field_7 = 0, },
  [kPose_C7_FaceR_ShinesparkWindup_Vert]    = { .pose_x_dir = kSamusXDir_FaceRight    , .movement_type = kMovementType_1B_Shinespark_CrystalFlash_Drained_DamagedByMotherBrain , .new_pose_unless_buttons = 0xff                                   , .direction_shots_fired = 0xff                                                 , .y_offset_proj_origin_to_gfx =   8, .UNUSED_field_5 = 0, .y_radius = 19, .UNUSED_field_7 = 0, },
  [kPose_C8_FaceL_ShinesparkWindup_Vert]    = { .pose_x_dir = kSamusXDir_FaceLeft     , .movement_type = kMovementType_1B_Shinespark_CrystalFlash_Drained_DamagedByMotherBrain , .new_pose_unless_buttons = 0xff                                   , .direction_shots_fired = 0xff                                                 , .y_offset_proj_origin_to_gfx =   8, .UNUSED_field_5 = 0, .y_radius = 19, .UNUSED_field_7 = 0, },
  [kPose_C9_FaceR_Shinespark_Horiz]         = { .pose_x_dir = kSamusXDir_FaceRight    , .movement_type = kMovementType_1B_Shinespark_CrystalFlash_Drained_DamagedByMotherBrain , .new_pose_unless_buttons = 0xff                                   , .direction_shots_fired = kProjectileOriginDir_Right                           , .y_offset_proj_origin_to_gfx =   8, .UNUSED_field_5 = 0, .y_radius = 19, .UNUSED_field_7 = 0, },
  [kPose_CA_FaceL_Shinespark_Horiz]         = { .pose_x_dir = kSamusXDir_FaceLeft     , .movement_type = kMovementType_1B_Shinespark_CrystalFlash_Drained_DamagedByMotherBrain , .new_pose_unless_buttons = 0xff                                   , .direction_shots_fired = kProjectileOriginDir_Left                            , .y_offset_proj_origin_to_gfx =   8, .UNUSED_field_5 = 0, .y_radius = 19, .UNUSED_field_7 = 0, },
  [kPose_CB_FaceR_Shinespark_Vert]          = { .pose_x_dir = kSamusXDir_FaceRight    , .movement_type = kMovementType_1B_Shinespark_CrystalFlash_Drained_DamagedByMotherBrain , .new_pose_unless_buttons = 0xff                                   , .direction_shots_fired = kProjectileOriginDir_UpFaceRight                     , .y_offset_proj_origin_to_gfx =   8, .UNUSED_field_5 = 0, .y_radius = 19, .UNUSED_field_7 = 0, },
  [kPose_CC_FaceL_Shinespark_Vert]          = { .pose_x_dir = kSamusXDir_FaceLeft     , .movement_type = kMovementType_1B_Shinespark_CrystalFlash_Drained_DamagedByMotherBrain , .new_pose_unless_buttons = 0xff                                   , .direction_shots_fired = kProjectileOriginDir_UpFaceLeft                      , .y_offset_proj_origin_to_gfx =   8, .UNUSED_field_5 = 0, .y_radius = 19, .UNUSED_field_7 = 0, },
  [kPose_CD_FaceR_Shinespark_Diag]          = { .pose_x_dir = kSamusXDir_FaceRight    , .movement_type = kMovementType_1B_Shinespark_CrystalFlash_Drained_DamagedByMotherBrain , .new_pose_unless_buttons = 0xff                                   , .direction_shots_fired = kProjectileOriginDir_UpRight                         , .y_offset_proj_origin_to_gfx =   8, .UNUSED_field_5 = 0, .y_radius = 19, .UNUSED_field_7 = 0, },
  [kPose_CE_FaceL_Shinespark_Diag]          = { .pose_x_dir = kSamusXDir_FaceLeft     , .movement_type = kMovementType_1B_Shinespark_CrystalFlash_Drained_DamagedByMotherBrain , .new_pose_unless_buttons = 0xff                                   , .direction_shots_fired = kProjectileOriginDir_UpLeft                          , .y_offset_proj_origin_to_gfx =   8, .UNUSED_field_5 = 0, .y_radius = 19, .UNUSED_field_7 = 0, },
  [kPose_CF_FaceR_Ranintowall_AimUR]        = { .pose_x_dir = kSamusXDir_FaceRight    , .movement_type = kMovementType_15_RanIntoWall                                          , .new_pose_unless_buttons = kPose_89_FaceR_Ranintowall             , .direction_shots_fired = kProjectileOriginDir_UpRight                         , .y_offset_proj_origin_to_gfx =   6, .UNUSED_field_5 = 0, .y_radius = 21, .UNUSED_field_7 = 0, },
  [kPose_D0_FaceL_Ranintowall_AimUL]        = { .pose_x_dir = kSamusXDir_FaceLeft     , .movement_type = kMovementType_15_RanIntoWall                                          , .new_pose_unless_buttons = kPose_8A_FaceL_Ranintowall             , .direction_shots_fired = kProjectileOriginDir_UpLeft                          , .y_offset_proj_origin_to_gfx =   6, .UNUSED_field_5 = 0, .y_radius = 21, .UNUSED_field_7 = 0, },
  [kPose_D1_FaceR_Ranintowall_AimDR]        = { .pose_x_dir = kSamusXDir_FaceRight    , .movement_type = kMovementType_15_RanIntoWall                                          , .new_pose_unless_buttons = kPose_89_FaceR_Ranintowall             , .direction_shots_fired = kProjectileOriginDir_DownRight                       , .y_offset_proj_origin_to_gfx =   6, .UNUSED_field_5 = 0, .y_radius = 21, .UNUSED_field_7 = 0, },
  [kPose_D2_FaceL_Ranintowall_AimDL]        = { .pose_x_dir = kSamusXDir_FaceLeft     , .movement_type = kMovementType_15_RanIntoWall                                          , .new_pose_unless_buttons = kPose_8A_FaceL_Ranintowall             , .direction_shots_fired = kProjectileOriginDir_DownLeft                        , .y_offset_proj_origin_to_gfx =   6, .UNUSED_field_5 = 0, .y_radius = 21, .UNUSED_field_7 = 0, },
  [kPose_D3_FaceR_CrystalFlash]             = { .pose_x_dir = kSamusXDir_FaceRight    , .movement_type = kMovementType_1B_Shinespark_CrystalFlash_Drained_DamagedByMotherBrain , .new_pose_unless_buttons = 0xff                                   , .direction_shots_fired = 0xff                                                 , .y_offset_proj_origin_to_gfx =   6, .UNUSED_field_5 = 0, .y_radius = 21, .UNUSED_field_7 = 0, },
  [kPose_D4_FaceL_CrystalFlash]             = { .pose_x_dir = kSamusXDir_FaceLeft     , .movement_type = kMovementType_1B_Shinespark_CrystalFlash_Drained_DamagedByMotherBrain , .new_pose_unless_buttons = 0xff                                   , .direction_shots_fired = 0xff                                                 , .y_offset_proj_origin_to_gfx =   6, .UNUSED_field_5 = 0, .y_radius = 21, .UNUSED_field_7 = 0, },
  [kPose_D5_FaceR_Xray_Stand]               = { .pose_x_dir = kSamusXDir_FaceRight    , .movement_type = kMovementType_00_Standing                                             , .new_pose_unless_buttons = 0xff                                   , .direction_shots_fired = kProjectileOriginDir_Right                           , .y_offset_proj_origin_to_gfx =   6, .UNUSED_field_5 = 0, .y_radius = 21, .UNUSED_field_7 = 0, },
  [kPose_D6_FaceL_Xray_Stand]               = { .pose_x_dir = kSamusXDir_FaceLeft     , .movement_type = kMovementType_00_Standing                                             , .new_pose_unless_buttons = 0xff                                   , .direction_shots_fired = kProjectileOriginDir_Left                            , .y_offset_proj_origin_to_gfx =   6, .UNUSED_field_5 = 0, .y_radius = 21, .UNUSED_field_7 = 0, },
  [kPose_D7_FaceR_CrystalFlashEnd]          = { .pose_x_dir = kSamusXDir_FaceRight    , .movement_type = kMovementType_0A_KnockbackOrCrystalFlashEnding                        , .new_pose_unless_buttons = 0xff                                   , .direction_shots_fired = kProjectileOriginDir_Right                           , .y_offset_proj_origin_to_gfx =   6, .UNUSED_field_5 = 0, .y_radius = 21, .UNUSED_field_7 = 0, },
  [kPose_D8_FaceL_CrystalFlashEnd]          = { .pose_x_dir = kSamusXDir_FaceLeft     , .movement_type = kMovementType_0A_KnockbackOrCrystalFlashEnding                        , .new_pose_unless_buttons = 0xff                                   , .direction_shots_fired = kProjectileOriginDir_Left                            , .y_offset_proj_origin_to_gfx =   6, .UNUSED_field_5 = 0, .y_radius = 21, .UNUSED_field_7 = 0, },
  [kPose_D9_FaceR_Xray_Crouch]              = { .pose_x_dir = kSamusXDir_FaceRight    , .movement_type = kMovementType_05_Crouching                                            , .new_pose_unless_buttons = 0xff                                   , .direction_shots_fired = kProjectileOriginDir_Right                           , .y_offset_proj_origin_to_gfx =   0, .UNUSED_field_5 = 0, .y_radius = 16, .UNUSED_field_7 = 0, },
  [kPose_DA_FaceL_Xray_Crouch]              = { .pose_x_dir = kSamusXDir_FaceLeft     , .movement_type = kMovementType_05_Crouching                                            , .new_pose_unless_buttons = 0xff                                   , .direction_shots_fired = kProjectileOriginDir_Left                            , .y_offset_proj_origin_to_gfx =   0, .UNUSED_field_5 = 0, .y_radius = 16, .UNUSED_field_7 = 0, },
  [kPose_DB]                                = { .pose_x_dir = kSamusXDir_FaceRight    , .movement_type = kMovementType_0F_Crouch_Stand_Morph_Unmorph_Transition                , .new_pose_unless_buttons = 0xff                                   , .direction_shots_fired = 0xff                                                 , .y_offset_proj_origin_to_gfx =   0, .UNUSED_field_5 = 0, .y_radius =  7, .UNUSED_field_7 = 0, },
  [kPose_DC]                                = { .pose_x_dir = kSamusXDir_FaceLeft     , .movement_type = kMovementType_0F_Crouch_Stand_Morph_Unmorph_Transition                , .new_pose_unless_buttons = 0xff                                   , .direction_shots_fired = 0xff                                                 , .y_offset_proj_origin_to_gfx =   0, .UNUSED_field_5 = 0, .y_radius =  7, .UNUSED_field_7 = 0, },
  [kPose_DD]                                = { .pose_x_dir = kSamusXDir_FaceRight    , .movement_type = kMovementType_0F_Crouch_Stand_Morph_Unmorph_Transition                , .new_pose_unless_buttons = 0xff                                   , .direction_shots_fired = 0xff                                                 , .y_offset_proj_origin_to_gfx =   6, .UNUSED_field_5 = 0, .y_radius = 21, .UNUSED_field_7 = 0, },
  [kPose_DE]                                = { .pose_x_dir = kSamusXDir_FaceLeft     , .movement_type = kMovementType_0F_Crouch_Stand_Morph_Unmorph_Transition                , .new_pose_unless_buttons = 0xff                                   , .direction_shots_fired = 0xff                                                 , .y_offset_proj_origin_to_gfx =   6, .UNUSED_field_5 = 0, .y_radius = 21, .UNUSED_field_7 = 0, },
  [kPose_DF]                                = { .pose_x_dir = kSamusXDir_FaceLeft     , .movement_type = kMovementType_1A_GrabbedByDraygon                                     , .new_pose_unless_buttons = 0xff                                   , .direction_shots_fired = 0xff                                                 , .y_offset_proj_origin_to_gfx =   0, .UNUSED_field_5 = 0, .y_radius =  7, .UNUSED_field_7 = 0, },
  [kPose_E0_FaceR_LandJump_AimU]            = { .pose_x_dir = kSamusXDir_FaceRight    , .movement_type = kMovementType_00_Standing                                             , .new_pose_unless_buttons = 0xff                                   , .direction_shots_fired = kProjectileOriginDir_UpFaceRight                     , .y_offset_proj_origin_to_gfx =   3, .UNUSED_field_5 = 0, .y_radius = 21, .UNUSED_field_7 = 0, },
  [kPose_E1_FaceL_LandJump_AimU]            = { .pose_x_dir = kSamusXDir_FaceLeft     , .movement_type = kMovementType_00_Standing                                             , .new_pose_unless_buttons = 0xff                                   , .direction_shots_fired = kProjectileOriginDir_UpFaceLeft                      , .y_offset_proj_origin_to_gfx =   3, .UNUSED_field_5 = 0, .y_radius = 21, .UNUSED_field_7 = 0, },
  [kPose_E2_FaceR_LandJump_AimUR]           = { .pose_x_dir = kSamusXDir_FaceRight    , .movement_type = kMovementType_00_Standing                                             , .new_pose_unless_buttons = 0xff                                   , .direction_shots_fired = kProjectileOriginDir_UpRight                         , .y_offset_proj_origin_to_gfx =   3, .UNUSED_field_5 = 0, .y_radius = 21, .UNUSED_field_7 = 0, },
  [kPose_E3_FaceL_LandJump_AimUL]           = { .pose_x_dir = kSamusXDir_FaceLeft     , .movement_type = kMovementType_00_Standing                                             , .new_pose_unless_buttons = 0xff                                   , .direction_shots_fired = kProjectileOriginDir_UpLeft                          , .y_offset_proj_origin_to_gfx =   3, .UNUSED_field_5 = 0, .y_radius = 21, .UNUSED_field_7 = 0, },
  [kPose_E4_FaceR_LandJump_AimDR]           = { .pose_x_dir = kSamusXDir_FaceRight    , .movement_type = kMovementType_00_Standing                                             , .new_pose_unless_buttons = 0xff                                   , .direction_shots_fired = kProjectileOriginDir_DownRight                       , .y_offset_proj_origin_to_gfx =   3, .UNUSED_field_5 = 0, .y_radius = 21, .UNUSED_field_7 = 0, },
  [kPose_E5_FaceL_LandJump_AimDL]           = { .pose_x_dir = kSamusXDir_FaceLeft     , .movement_type = kMovementType_00_Standing                                             , .new_pose_unless_buttons = 0xff                                   , .direction_shots_fired = kProjectileOriginDir_DownLeft                        , .y_offset_proj_origin_to_gfx =   3, .UNUSED_field_5 = 0, .y_radius = 21, .UNUSED_field_7 = 0, },
  [kPose_E6_FaceR_LandJump_Fire]            = { .pose_x_dir = kSamusXDir_FaceRight    , .movement_type = kMovementType_00_Standing                                             , .new_pose_unless_buttons = 0xff                                   , .direction_shots_fired = kProjectileOriginDir_Right                           , .y_offset_proj_origin_to_gfx =   3, .UNUSED_field_5 = 0, .y_radius = 21, .UNUSED_field_7 = 0, },
  [kPose_E7_FaceL_LandJump_Fire]            = { .pose_x_dir = kSamusXDir_FaceLeft     , .movement_type = kMovementType_00_Standing                                             , .new_pose_unless_buttons = 0xff                                   , .direction_shots_fired = kProjectileOriginDir_Left                            , .y_offset_proj_origin_to_gfx =   3, .UNUSED_field_5 = 0, .y_radius = 21, .UNUSED_field_7 = 0, },
  [kPose_E8_FaceR_Drained_CrouchFalling]    = { .pose_x_dir = kSamusXDir_FaceRight    , .movement_type = kMovementType_1B_Shinespark_CrystalFlash_Drained_DamagedByMotherBrain , .new_pose_unless_buttons = 0xff                                   , .direction_shots_fired = 0xff                                                 , .y_offset_proj_origin_to_gfx = 252, .UNUSED_field_5 = 0, .y_radius = 21, .UNUSED_field_7 = 0, },
  [kPose_E9_FaceL_Drained_CrouchFalling]    = { .pose_x_dir = kSamusXDir_FaceLeft     , .movement_type = kMovementType_1B_Shinespark_CrystalFlash_Drained_DamagedByMotherBrain , .new_pose_unless_buttons = 0xff                                   , .direction_shots_fired = 0xff                                                 , .y_offset_proj_origin_to_gfx = 252, .UNUSED_field_5 = 0, .y_radius = 21, .UNUSED_field_7 = 0, },
  [kPose_EA_FaceR_Drained_Stand]            = { .pose_x_dir = kSamusXDir_FaceRight    , .movement_type = kMovementType_1B_Shinespark_CrystalFlash_Drained_DamagedByMotherBrain , .new_pose_unless_buttons = 0xff                                   , .direction_shots_fired = 0xff                                                 , .y_offset_proj_origin_to_gfx = 252, .UNUSED_field_5 = 0, .y_radius = 21, .UNUSED_field_7 = 0, },
  [kPose_EB_FaceL_Drained_Stand]            = { .pose_x_dir = kSamusXDir_FaceLeft     , .movement_type = kMovementType_1B_Shinespark_CrystalFlash_Drained_DamagedByMotherBrain , .new_pose_unless_buttons = 0xff                                   , .direction_shots_fired = 0xff                                                 , .y_offset_proj_origin_to_gfx = 252, .UNUSED_field_5 = 0, .y_radius = 21, .UNUSED_field_7 = 0, },
  [kPose_EC_FaceR_Draygon_NoMove_NoAim]     = { .pose_x_dir = kSamusXDir_FaceRight    , .movement_type = kMovementType_1A_GrabbedByDraygon                                     , .new_pose_unless_buttons = 0xff                                   , .direction_shots_fired = kProjectileOriginDir_Right                           , .y_offset_proj_origin_to_gfx =   6, .UNUSED_field_5 = 0, .y_radius = 21, .UNUSED_field_7 = 0, },
  [kPose_ED_FaceR_Draygon_NoMove_AimUR]     = { .pose_x_dir = kSamusXDir_FaceRight    , .movement_type = kMovementType_1A_GrabbedByDraygon                                     , .new_pose_unless_buttons = kPose_EC_FaceR_Draygon_NoMove_NoAim    , .direction_shots_fired = kProjectileOriginDir_UpRight                         , .y_offset_proj_origin_to_gfx =   6, .UNUSED_field_5 = 0, .y_radius = 21, .UNUSED_field_7 = 0, },
  [kPose_EE_FaceR_Draygon_Fire]             = { .pose_x_dir = kSamusXDir_FaceRight    , .movement_type = kMovementType_1A_GrabbedByDraygon                                     , .new_pose_unless_buttons = kPose_EC_FaceR_Draygon_NoMove_NoAim    , .direction_shots_fired = kProjectileOriginDir_Right                           , .y_offset_proj_origin_to_gfx =   6, .UNUSED_field_5 = 0, .y_radius = 21, .UNUSED_field_7 = 0, },
  [kPose_EF_FaceR_Draygon_NoMove_AimDR]     = { .pose_x_dir = kSamusXDir_FaceRight    , .movement_type = kMovementType_1A_GrabbedByDraygon                                     , .new_pose_unless_buttons = kPose_EC_FaceR_Draygon_NoMove_NoAim    , .direction_shots_fired = kProjectileOriginDir_DownRight                       , .y_offset_proj_origin_to_gfx =   6, .UNUSED_field_5 = 0, .y_radius = 21, .UNUSED_field_7 = 0, },
  [kPose_F0_FaceR_Draygon_Move]             = { .pose_x_dir = kSamusXDir_FaceRight    , .movement_type = kMovementType_1A_GrabbedByDraygon                                     , .new_pose_unless_buttons = kPose_EC_FaceR_Draygon_NoMove_NoAim    , .direction_shots_fired = 0xff                                                 , .y_offset_proj_origin_to_gfx =   6, .UNUSED_field_5 = 0, .y_radius = 21, .UNUSED_field_7 = 0, },
  [kPose_F1_FaceR_CrouchTrans_AimU]         = { .pose_x_dir = kSamusXDir_FaceRight    , .movement_type = kMovementType_0F_Crouch_Stand_Morph_Unmorph_Transition                , .new_pose_unless_buttons = 0xff                                   , .direction_shots_fired = kProjectileOriginDir_UpFaceRight                     , .y_offset_proj_origin_to_gfx =   8, .UNUSED_field_5 = 0, .y_radius = 16, .UNUSED_field_7 = 0, },
  [kPose_F2_FaceL_CrouchTrans_AimU]         = { .pose_x_dir = kSamusXDir_FaceLeft     , .movement_type = kMovementType_0F_Crouch_Stand_Morph_Unmorph_Transition                , .new_pose_unless_buttons = 0xff                                   , .direction_shots_fired = kProjectileOriginDir_UpFaceLeft                      , .y_offset_proj_origin_to_gfx =   8, .UNUSED_field_5 = 0, .y_radius = 16, .UNUSED_field_7 = 0, },
  [kPose_F3_FaceR_CrouchTrans_AimUR]        = { .pose_x_dir = kSamusXDir_FaceRight    , .movement_type = kMovementType_0F_Crouch_Stand_Morph_Unmorph_Transition                , .new_pose_unless_buttons = 0xff                                   , .direction_shots_fired = kProjectileOriginDir_UpRight                         , .y_offset_proj_origin_to_gfx =   8, .UNUSED_field_5 = 0, .y_radius = 16, .UNUSED_field_7 = 0, },
  [kPose_F4_FaceL_CrouchTrans_AimUL]        = { .pose_x_dir = kSamusXDir_FaceLeft     , .movement_type = kMovementType_0F_Crouch_Stand_Morph_Unmorph_Transition                , .new_pose_unless_buttons = 0xff                                   , .direction_shots_fired = kProjectileOriginDir_UpLeft                          , .y_offset_proj_origin_to_gfx =   8, .UNUSED_field_5 = 0, .y_radius = 16, .UNUSED_field_7 = 0, },
  [kPose_F5_FaceR_CrouchTrans_AimDR]        = { .pose_x_dir = kSamusXDir_FaceRight    , .movement_type = kMovementType_0F_Crouch_Stand_Morph_Unmorph_Transition                , .new_pose_unless_buttons = 0xff                                   , .direction_shots_fired = kProjectileOriginDir_DownRight                       , .y_offset_proj_origin_to_gfx =   8, .UNUSED_field_5 = 0, .y_radius = 16, .UNUSED_field_7 = 0, },
  [kPose_F6_FaceL_CrouchTrans_AimDL]        = { .pose_x_dir = kSamusXDir_FaceLeft     , .movement_type = kMovementType_0F_Crouch_Stand_Morph_Unmorph_Transition                , .new_pose_unless_buttons = 0xff                                   , .direction_shots_fired = kProjectileOriginDir_DownLeft                        , .y_offset_proj_origin_to_gfx =   8, .UNUSED_field_5 = 0, .y_radius = 16, .UNUSED_field_7 = 0, },
  [kPose_F7_FaceR_StandTrans_AimU]          = { .pose_x_dir = kSamusXDir_FaceRight    , .movement_type = kMovementType_0F_Crouch_Stand_Morph_Unmorph_Transition                , .new_pose_unless_buttons = 0xff                                   , .direction_shots_fired = kProjectileOriginDir_UpFaceRight                     , .y_offset_proj_origin_to_gfx =   3, .UNUSED_field_5 = 0, .y_radius = 21, .UNUSED_field_7 = 0, },
  [kPose_F8_FaceL_StandTrans_AimU]          = { .pose_x_dir = kSamusXDir_FaceLeft     , .movement_type = kMovementType_0F_Crouch_Stand_Morph_Unmorph_Transition                , .new_pose_unless_buttons = 0xff                                   , .direction_shots_fired = kProjectileOriginDir_UpFaceLeft                      , .y_offset_proj_origin_to_gfx =   3, .UNUSED_field_5 = 0, .y_radius = 21, .UNUSED_field_7 = 0, },
  [kPose_F9_FaceR_StandTrans_AimUR]         = { .pose_x_dir = kSamusXDir_FaceRight    , .movement_type = kMovementType_0F_Crouch_Stand_Morph_Unmorph_Transition                , .new_pose_unless_buttons = 0xff                                   , .direction_shots_fired = kProjectileOriginDir_UpRight                         , .y_offset_proj_origin_to_gfx =   3, .UNUSED_field_5 = 0, .y_radius = 21, .UNUSED_field_7 = 0, },
  [kPose_FA_FaceL_StandTrans_AimUL]         = { .pose_x_dir = kSamusXDir_FaceLeft     , .movement_type = kMovementType_0F_Crouch_Stand_Morph_Unmorph_Transition                , .new_pose_unless_buttons = 0xff                                   , .direction_shots_fired = kProjectileOriginDir_UpLeft                          , .y_offset_proj_origin_to_gfx =   3, .UNUSED_field_5 = 0, .y_radius = 21, .UNUSED_field_7 = 0, },
  [kPose_FB_FaceR_StandTrans_AimDR]         = { .pose_x_dir = kSamusXDir_FaceRight    , .movement_type = kMovementType_0F_Crouch_Stand_Morph_Unmorph_Transition                , .new_pose_unless_buttons = 0xff                                   , .direction_shots_fired = kProjectileOriginDir_DownRight                       , .y_offset_proj_origin_to_gfx =   3, .UNUSED_field_5 = 0, .y_radius = 21, .UNUSED_field_7 = 0, },
};

// Each entry x is the value = |tan(x * pi/0x80)| * 0x100
// Clockwise, 0 = up
const uint16 kAbsTanTable[0x80+1] = {  // 0x91C9D4
      0,     6,    12,    18,    25,    31,    37,    44,    50,    57,    64,    70,    77,    84,    91,    98, 
    106,   113,   121,   128,   136,   145,   153,   162,   171,   180,   189,   199,   210,   220,   232,   243, 
    256,   268,   282,   296,   311,   328,   345,   363,   383,   404,   427,   451,   478,   508,   541,   577, 
    618,   663,   715,   774,   843,   925,  1022,  1140,  1286,  1475,  1725,  2075,  2599,  3470,  5210, 10427, 
  15360, 10427,  5210,  3470,  2599,  2075,  1725,  1475,  1286,  1140,  1022,   925,   843,   774,   715,   663, 
    618,   577,   541,   508,   478,   451,   427,   404,   383,   363,   345,   328,   311,   296,   282,   268, 
    256,   243,   232,   220,   210,   199,   189,   180,   171,   162,   153,   145,   136,   128,   121,   113, 
    106,    98,    91,    84,    77,    70,    64,    57,    50,    44,    37,    31,    25,    18,    12,     6, 
      0,
};

static const PoseEntry Trans_00[] = {  // 0x91a0de
  [0]  = { .new_input = 0             , .cur_input = kButton_Right                        , .new_pose = kPose_26_FaceL_Turn_Stand               , },
  [1]  = { .new_input = 0             , .cur_input = kButton_Left                         , .new_pose = kPose_25_FaceR_Turn_Stand               , },
  [2]  = { 0xffff },
};

static const PoseEntry Trans_01[] = {  // 0x91a0ec
  [0]  = { .new_input = kButton_A     , .cur_input = kButton_Up                           , .new_pose = kPose_55_FaceR_Jumptrans_AimU           , },
  [1]  = { .new_input = kButton_A     , .cur_input = kButton_R                            , .new_pose = kPose_57_FaceR_Jumptrans_AimUR          , },
  [2]  = { .new_input = kButton_A     , .cur_input = kButton_L                            , .new_pose = kPose_59_FaceR_Jumptrans_AimDR          , },
  [3]  = { .new_input = kButton_A     , .cur_input = 0                                    , .new_pose = kPose_4B_FaceR_Jumptrans                , },
  [4]  = { .new_input = kButton_Down  , .cur_input = kButton_R+kButton_L                  , .new_pose = kPose_F1_FaceR_CrouchTrans_AimU         , },
  [5]  = { .new_input = kButton_Down  , .cur_input = kButton_R                            , .new_pose = kPose_F3_FaceR_CrouchTrans_AimUR        , },
  [6]  = { .new_input = kButton_Down  , .cur_input = kButton_L                            , .new_pose = kPose_F5_FaceR_CrouchTrans_AimDR        , },
  [7]  = { .new_input = kButton_Down  , .cur_input = 0                                    , .new_pose = kPose_35_FaceR_CrouchTrans              , },
  [8]  = { .new_input = 0             , .cur_input = kButton_L+kButton_X+kButton_Left     , .new_pose = kPose_78_FaceR_Moonwalk_AimDR           , },
  [9]  = { .new_input = 0             , .cur_input = kButton_R+kButton_X+kButton_Left     , .new_pose = kPose_76_FaceR_Moonwalk_AimUR           , },
  [10] = { .new_input = 0             , .cur_input = kButton_R+kButton_L+kButton_Left     , .new_pose = kPose_25_FaceR_Turn_Stand               , },
  [11] = { .new_input = 0             , .cur_input = kButton_R+kButton_L                  , .new_pose = kPose_03_FaceR_AimU                     , },
  [12] = { .new_input = 0             , .cur_input = kButton_R+kButton_Right              , .new_pose = kPose_0F_MoveR_AimUR                    , },
  [13] = { .new_input = 0             , .cur_input = kButton_L+kButton_Right              , .new_pose = kPose_11_MoveR_AimDR                    , },
  [14] = { .new_input = 0             , .cur_input = kButton_Right+kButton_Up             , .new_pose = kPose_0F_MoveR_AimUR                    , },
  [15] = { .new_input = 0             , .cur_input = kButton_Right+kButton_Down           , .new_pose = kPose_11_MoveR_AimDR                    , },
  [16] = { .new_input = 0             , .cur_input = kButton_X+kButton_Left               , .new_pose = kPose_4A_FaceR_Moonwalk                 , },
  [17] = { .new_input = 0             , .cur_input = kButton_Left                         , .new_pose = kPose_25_FaceR_Turn_Stand               , },
  [18] = { .new_input = 0             , .cur_input = kButton_Up                           , .new_pose = kPose_03_FaceR_AimU                     , },
  [19] = { .new_input = 0             , .cur_input = kButton_R                            , .new_pose = kPose_05_FaceR_AimUR                    , },
  [20] = { .new_input = 0             , .cur_input = kButton_L                            , .new_pose = kPose_07_FaceR_AimDR                    , },
  [21] = { .new_input = 0             , .cur_input = kButton_Right                        , .new_pose = kPose_09_MoveR_NoAim                    , },
  [22] = { 0xffff },
};

static const PoseEntry Trans_02[] = {  // 0x91a172
  [0]  = { .new_input = kButton_A     , .cur_input = kButton_Up                           , .new_pose = kPose_56_FaceL_Jumptrans_AimU           , },
  [1]  = { .new_input = kButton_A     , .cur_input = kButton_R                            , .new_pose = kPose_58_FaceL_Jumptrans_AimUL          , },
  [2]  = { .new_input = kButton_A     , .cur_input = kButton_L                            , .new_pose = kPose_5A_FaceL_Jumptrans_AimDL          , },
  [3]  = { .new_input = kButton_A     , .cur_input = 0                                    , .new_pose = kPose_4C_FaceL_Jumptrans                , },
  [4]  = { .new_input = kButton_Down  , .cur_input = kButton_R+kButton_L                  , .new_pose = kPose_F2_FaceL_CrouchTrans_AimU         , },
  [5]  = { .new_input = kButton_Down  , .cur_input = kButton_R                            , .new_pose = kPose_F4_FaceL_CrouchTrans_AimUL        , },
  [6]  = { .new_input = kButton_Down  , .cur_input = kButton_L                            , .new_pose = kPose_F6_FaceL_CrouchTrans_AimDL        , },
  [7]  = { .new_input = kButton_Down  , .cur_input = 0                                    , .new_pose = kPose_36_FaceL_CrouchTrans              , },
  [8]  = { .new_input = 0             , .cur_input = kButton_L+kButton_X+kButton_Right    , .new_pose = kPose_77_FaceL_Moonwalk_AimDL           , },
  [9]  = { .new_input = 0             , .cur_input = kButton_R+kButton_X+kButton_Right    , .new_pose = kPose_75_FaceL_Moonwalk_AimUL           , },
  [10] = { .new_input = 0             , .cur_input = kButton_R+kButton_L+kButton_Right    , .new_pose = kPose_26_FaceL_Turn_Stand               , },
  [11] = { .new_input = 0             , .cur_input = kButton_R+kButton_L                  , .new_pose = kPose_04_FaceL_AimU                     , },
  [12] = { .new_input = 0             , .cur_input = kButton_R+kButton_Left               , .new_pose = kPose_10_MoveL_AimUL                    , },
  [13] = { .new_input = 0             , .cur_input = kButton_L+kButton_Left               , .new_pose = kPose_12_MoveL_AimDL                    , },
  [14] = { .new_input = 0             , .cur_input = kButton_Left+kButton_Up              , .new_pose = kPose_10_MoveL_AimUL                    , },
  [15] = { .new_input = 0             , .cur_input = kButton_Left+kButton_Down            , .new_pose = kPose_12_MoveL_AimDL                    , },
  [16] = { .new_input = 0             , .cur_input = kButton_X+kButton_Right              , .new_pose = kPose_49_FaceL_Moonwalk                 , },
  [17] = { .new_input = 0             , .cur_input = kButton_Right                        , .new_pose = kPose_26_FaceL_Turn_Stand               , },
  [18] = { .new_input = 0             , .cur_input = kButton_Up                           , .new_pose = kPose_04_FaceL_AimU                     , },
  [19] = { .new_input = 0             , .cur_input = kButton_R                            , .new_pose = kPose_06_FaceL_AimUL                    , },
  [20] = { .new_input = 0             , .cur_input = kButton_L                            , .new_pose = kPose_08_FaceL_AimDL                    , },
  [21] = { .new_input = 0             , .cur_input = kButton_Left                         , .new_pose = kPose_0A_MoveL_NoAim                    , },
  [22] = { 0xffff },
};

static const PoseEntry Trans_09[] = {  // 0x91a1f8
  [0]  = { .new_input = kButton_Down  , .cur_input = 0                                    , .new_pose = kPose_35_FaceR_CrouchTrans              , },
  [1]  = { .new_input = kButton_A     , .cur_input = 0                                    , .new_pose = kPose_19_FaceR_SpinJump                 , },
  [2]  = { .new_input = 0             , .cur_input = kButton_R+kButton_Right              , .new_pose = kPose_0F_MoveR_AimUR                    , },
  [3]  = { .new_input = 0             , .cur_input = kButton_L+kButton_Right              , .new_pose = kPose_11_MoveR_AimDR                    , },
  [4]  = { .new_input = 0             , .cur_input = kButton_Right+kButton_Up             , .new_pose = kPose_0F_MoveR_AimUR                    , },
  [5]  = { .new_input = 0             , .cur_input = kButton_Right+kButton_Down           , .new_pose = kPose_11_MoveR_AimDR                    , },
  [6]  = { .new_input = 0             , .cur_input = kButton_X+kButton_Right              , .new_pose = kPose_0B_MoveR_Gun                      , },
  [7]  = { .new_input = 0             , .cur_input = kButton_Right                        , .new_pose = kPose_09_MoveR_NoAim                    , },
  [8]  = { .new_input = 0             , .cur_input = kButton_Left                         , .new_pose = kPose_25_FaceR_Turn_Stand               , },
  [9]  = { .new_input = 0             , .cur_input = kButton_Up                           , .new_pose = kPose_03_FaceR_AimU                     , },
  [10] = { .new_input = 0             , .cur_input = kButton_R                            , .new_pose = kPose_05_FaceR_AimUR                    , },
  [11] = { .new_input = 0             , .cur_input = kButton_L                            , .new_pose = kPose_07_FaceR_AimDR                    , },
  [12] = { 0xffff },
};

static const PoseEntry Trans_0a[] = {  // 0x91a242
  [0]  = { .new_input = kButton_Down  , .cur_input = 0                                    , .new_pose = kPose_36_FaceL_CrouchTrans              , },
  [1]  = { .new_input = kButton_A     , .cur_input = 0                                    , .new_pose = kPose_1A_FaceL_SpinJump                 , },
  [2]  = { .new_input = 0             , .cur_input = kButton_R+kButton_Left               , .new_pose = kPose_10_MoveL_AimUL                    , },
  [3]  = { .new_input = 0             , .cur_input = kButton_L+kButton_Left               , .new_pose = kPose_12_MoveL_AimDL                    , },
  [4]  = { .new_input = 0             , .cur_input = kButton_Left+kButton_Up              , .new_pose = kPose_10_MoveL_AimUL                    , },
  [5]  = { .new_input = 0             , .cur_input = kButton_Left+kButton_Down            , .new_pose = kPose_12_MoveL_AimDL                    , },
  [6]  = { .new_input = 0             , .cur_input = kButton_X+kButton_Left               , .new_pose = kPose_0C_MoveL_Gun                      , },
  [7]  = { .new_input = 0             , .cur_input = kButton_Left                         , .new_pose = kPose_0A_MoveL_NoAim                    , },
  [8]  = { .new_input = 0             , .cur_input = kButton_Right                        , .new_pose = kPose_26_FaceL_Turn_Stand               , },
  [9]  = { .new_input = 0             , .cur_input = kButton_Up                           , .new_pose = kPose_04_FaceL_AimU                     , },
  [10] = { .new_input = 0             , .cur_input = kButton_R                            , .new_pose = kPose_06_FaceL_AimUL                    , },
  [11] = { .new_input = 0             , .cur_input = kButton_L                            , .new_pose = kPose_08_FaceL_AimDL                    , },
  [12] = { 0xffff },
};

static const PoseEntry Trans_0b[] = {  // 0x91ae94
  [0]  = { .new_input = kButton_Down  , .cur_input = 0                                    , .new_pose = kPose_35_FaceR_CrouchTrans              , },
  [1]  = { .new_input = kButton_A     , .cur_input = 0                                    , .new_pose = kPose_19_FaceR_SpinJump                 , },
  [2]  = { .new_input = 0             , .cur_input = kButton_R+kButton_Right              , .new_pose = kPose_0F_MoveR_AimUR                    , },
  [3]  = { .new_input = 0             , .cur_input = kButton_L+kButton_Right              , .new_pose = kPose_11_MoveR_AimDR                    , },
  [4]  = { .new_input = 0             , .cur_input = kButton_Right+kButton_Up             , .new_pose = kPose_0F_MoveR_AimUR                    , },
  [5]  = { .new_input = 0             , .cur_input = kButton_Right+kButton_Down           , .new_pose = kPose_11_MoveR_AimDR                    , },
  [6]  = { .new_input = 0             , .cur_input = kButton_X+kButton_Right              , .new_pose = kPose_0B_MoveR_Gun                      , },
  [7]  = { .new_input = 0             , .cur_input = kButton_Right                        , .new_pose = kPose_0B_MoveR_Gun                      , },
  [8]  = { .new_input = 0             , .cur_input = kButton_Left                         , .new_pose = kPose_25_FaceR_Turn_Stand               , },
  [9]  = { .new_input = 0             , .cur_input = kButton_Up                           , .new_pose = kPose_03_FaceR_AimU                     , },
  [10] = { .new_input = 0             , .cur_input = kButton_R                            , .new_pose = kPose_05_FaceR_AimUR                    , },
  [11] = { .new_input = 0             , .cur_input = kButton_L                            , .new_pose = kPose_07_FaceR_AimDR                    , },
  [12] = { 0xffff },
};

static const PoseEntry Trans_0c[] = {  // 0x91aede
  [0]  = { .new_input = kButton_Down  , .cur_input = 0                                    , .new_pose = kPose_36_FaceL_CrouchTrans              , },
  [1]  = { .new_input = kButton_A     , .cur_input = 0                                    , .new_pose = kPose_1A_FaceL_SpinJump                 , },
  [2]  = { .new_input = 0             , .cur_input = kButton_R+kButton_Left               , .new_pose = kPose_10_MoveL_AimUL                    , },
  [3]  = { .new_input = 0             , .cur_input = kButton_L+kButton_Left               , .new_pose = kPose_12_MoveL_AimDL                    , },
  [4]  = { .new_input = 0             , .cur_input = kButton_Left+kButton_Up              , .new_pose = kPose_10_MoveL_AimUL                    , },
  [5]  = { .new_input = 0             , .cur_input = kButton_Left+kButton_Down            , .new_pose = kPose_12_MoveL_AimDL                    , },
  [6]  = { .new_input = 0             , .cur_input = kButton_X+kButton_Left               , .new_pose = kPose_0C_MoveL_Gun                      , },
  [7]  = { .new_input = 0             , .cur_input = kButton_Left                         , .new_pose = kPose_0C_MoveL_Gun                      , },
  [8]  = { .new_input = 0             , .cur_input = kButton_Right                        , .new_pose = kPose_26_FaceL_Turn_Stand               , },
  [9]  = { .new_input = 0             , .cur_input = kButton_Up                           , .new_pose = kPose_04_FaceL_AimU                     , },
  [10] = { .new_input = 0             , .cur_input = kButton_R                            , .new_pose = kPose_06_FaceL_AimUL                    , },
  [11] = { .new_input = 0             , .cur_input = kButton_L                            , .new_pose = kPose_08_FaceL_AimDL                    , },
  [12] = { 0xffff },
};

static const PoseEntry Trans_13[] = {  // 0x91aac0
  [0]  = { .new_input = 0             , .cur_input = kButton_A+kButton_Right+kButton_Up   , .new_pose = kPose_69_FaceR_Jump_AimUR               , },
  [1]  = { .new_input = 0             , .cur_input = kButton_A+kButton_Right+kButton_Down , .new_pose = kPose_6B_FaceR_Jump_AimDR               , },
  [2]  = { .new_input = 0             , .cur_input = kButton_R+kButton_A+kButton_Right    , .new_pose = kPose_69_FaceR_Jump_AimUR               , },
  [3]  = { .new_input = 0             , .cur_input = kButton_L+kButton_A+kButton_Right    , .new_pose = kPose_6B_FaceR_Jump_AimDR               , },
  [4]  = { .new_input = 0             , .cur_input = kButton_Right+kButton_Up             , .new_pose = kPose_69_FaceR_Jump_AimUR               , },
  [5]  = { .new_input = 0             , .cur_input = kButton_Right+kButton_Down           , .new_pose = kPose_6B_FaceR_Jump_AimDR               , },
  [6]  = { .new_input = 0             , .cur_input = kButton_A+kButton_Left               , .new_pose = kPose_2F_FaceR_Turn_Jump                , },
  [7]  = { .new_input = 0             , .cur_input = kButton_A+kButton_Up                 , .new_pose = kPose_15_FaceR_Jump_AimU                , },
  [8]  = { .new_input = 0             , .cur_input = kButton_A+kButton_Down               , .new_pose = kPose_17_FaceR_Jump_AimD                , },
  [9]  = { .new_input = 0             , .cur_input = kButton_R+kButton_A                  , .new_pose = kPose_69_FaceR_Jump_AimUR               , },
  [10] = { .new_input = 0             , .cur_input = kButton_L+kButton_A                  , .new_pose = kPose_6B_FaceR_Jump_AimDR               , },
  [11] = { .new_input = 0             , .cur_input = kButton_A+kButton_Right              , .new_pose = kPose_51_FaceR_Jump_NoAim_MoveF         , },
  [12] = { .new_input = 0             , .cur_input = kButton_X+kButton_A                  , .new_pose = kPose_13_FaceR_Jump_NoAim_NoMove_Gun    , },
  [13] = { .new_input = 0             , .cur_input = kButton_Left                         , .new_pose = kPose_2F_FaceR_Turn_Jump                , },
  [14] = { .new_input = 0             , .cur_input = kButton_Up                           , .new_pose = kPose_15_FaceR_Jump_AimU                , },
  [15] = { .new_input = 0             , .cur_input = kButton_Down                         , .new_pose = kPose_17_FaceR_Jump_AimD                , },
  [16] = { .new_input = 0             , .cur_input = kButton_R                            , .new_pose = kPose_69_FaceR_Jump_AimUR               , },
  [17] = { .new_input = 0             , .cur_input = kButton_L                            , .new_pose = kPose_6B_FaceR_Jump_AimDR               , },
  [18] = { .new_input = 0             , .cur_input = kButton_Right                        , .new_pose = kPose_51_FaceR_Jump_NoAim_MoveF         , },
  [19] = { .new_input = 0             , .cur_input = kButton_X                            , .new_pose = kPose_13_FaceR_Jump_NoAim_NoMove_Gun    , },
  [20] = { 0xffff },
};

static const PoseEntry Trans_14[] = {  // 0x91ab3a
  [0]  = { .new_input = 0             , .cur_input = kButton_A+kButton_Left+kButton_Up    , .new_pose = kPose_6A_FaceL_Jump_AimUL               , },
  [1]  = { .new_input = 0             , .cur_input = kButton_A+kButton_Left+kButton_Down  , .new_pose = kPose_6C_FaceL_Jump_AimDL               , },
  [2]  = { .new_input = 0             , .cur_input = kButton_R+kButton_A+kButton_Left     , .new_pose = kPose_6A_FaceL_Jump_AimUL               , },
  [3]  = { .new_input = 0             , .cur_input = kButton_L+kButton_A+kButton_Left     , .new_pose = kPose_6C_FaceL_Jump_AimDL               , },
  [4]  = { .new_input = 0             , .cur_input = kButton_Left+kButton_Up              , .new_pose = kPose_6A_FaceL_Jump_AimUL               , },
  [5]  = { .new_input = 0             , .cur_input = kButton_Left+kButton_Down            , .new_pose = kPose_6C_FaceL_Jump_AimDL               , },
  [6]  = { .new_input = 0             , .cur_input = kButton_A+kButton_Right              , .new_pose = kPose_30_FaceL_Turn_Jump                , },
  [7]  = { .new_input = 0             , .cur_input = kButton_A+kButton_Up                 , .new_pose = kPose_16_FaceL_Jump_AimU                , },
  [8]  = { .new_input = 0             , .cur_input = kButton_A+kButton_Down               , .new_pose = kPose_18_FaceL_Jump_AimD                , },
  [9]  = { .new_input = 0             , .cur_input = kButton_R+kButton_A                  , .new_pose = kPose_6A_FaceL_Jump_AimUL               , },
  [10] = { .new_input = 0             , .cur_input = kButton_L+kButton_A                  , .new_pose = kPose_6C_FaceL_Jump_AimDL               , },
  [11] = { .new_input = 0             , .cur_input = kButton_A+kButton_Left               , .new_pose = kPose_52_FaceL_Jump_NoAim_MoveF         , },
  [12] = { .new_input = 0             , .cur_input = kButton_X+kButton_A                  , .new_pose = kPose_14_FaceL_Jump_NoAim_NoMove_Gun    , },
  [13] = { .new_input = 0             , .cur_input = kButton_Right                        , .new_pose = kPose_30_FaceL_Turn_Jump                , },
  [14] = { .new_input = 0             , .cur_input = kButton_Up                           , .new_pose = kPose_16_FaceL_Jump_AimU                , },
  [15] = { .new_input = 0             , .cur_input = kButton_Down                         , .new_pose = kPose_18_FaceL_Jump_AimD                , },
  [16] = { .new_input = 0             , .cur_input = kButton_R                            , .new_pose = kPose_6A_FaceL_Jump_AimUL               , },
  [17] = { .new_input = 0             , .cur_input = kButton_L                            , .new_pose = kPose_6C_FaceL_Jump_AimDL               , },
  [18] = { .new_input = 0             , .cur_input = kButton_Left                         , .new_pose = kPose_52_FaceL_Jump_NoAim_MoveF         , },
  [19] = { .new_input = 0             , .cur_input = kButton_X                            , .new_pose = kPose_14_FaceL_Jump_NoAim_NoMove_Gun    , },
  [20] = { 0xffff },
};

static const PoseEntry Trans_15[] = {  // 0x91a2f6
  [0]  = { .new_input = 0             , .cur_input = kButton_A+kButton_Right+kButton_Up   , .new_pose = kPose_69_FaceR_Jump_AimUR               , },
  [1]  = { .new_input = 0             , .cur_input = kButton_A+kButton_Right+kButton_Down , .new_pose = kPose_6B_FaceR_Jump_AimDR               , },
  [2]  = { .new_input = 0             , .cur_input = kButton_R+kButton_A+kButton_Right    , .new_pose = kPose_69_FaceR_Jump_AimUR               , },
  [3]  = { .new_input = 0             , .cur_input = kButton_L+kButton_A+kButton_Right    , .new_pose = kPose_6B_FaceR_Jump_AimDR               , },
  [4]  = { .new_input = 0             , .cur_input = kButton_Right+kButton_Up             , .new_pose = kPose_69_FaceR_Jump_AimUR               , },
  [5]  = { .new_input = 0             , .cur_input = kButton_Right+kButton_Down           , .new_pose = kPose_6B_FaceR_Jump_AimDR               , },
  [6]  = { .new_input = 0             , .cur_input = kButton_A+kButton_Left               , .new_pose = kPose_2F_FaceR_Turn_Jump                , },
  [7]  = { .new_input = 0             , .cur_input = kButton_A+kButton_Up                 , .new_pose = kPose_15_FaceR_Jump_AimU                , },
  [8]  = { .new_input = 0             , .cur_input = kButton_A+kButton_Down               , .new_pose = kPose_17_FaceR_Jump_AimD                , },
  [9]  = { .new_input = 0             , .cur_input = kButton_R+kButton_A                  , .new_pose = kPose_69_FaceR_Jump_AimUR               , },
  [10] = { .new_input = 0             , .cur_input = kButton_L+kButton_A                  , .new_pose = kPose_6B_FaceR_Jump_AimDR               , },
  [11] = { .new_input = 0             , .cur_input = kButton_A+kButton_Right              , .new_pose = kPose_51_FaceR_Jump_NoAim_MoveF         , },
  [12] = { .new_input = 0             , .cur_input = kButton_X+kButton_A                  , .new_pose = kPose_13_FaceR_Jump_NoAim_NoMove_Gun    , },
  [13] = { .new_input = 0             , .cur_input = kButton_Left                         , .new_pose = kPose_2F_FaceR_Turn_Jump                , },
  [14] = { .new_input = 0             , .cur_input = kButton_Up                           , .new_pose = kPose_15_FaceR_Jump_AimU                , },
  [15] = { .new_input = 0             , .cur_input = kButton_Down                         , .new_pose = kPose_17_FaceR_Jump_AimD                , },
  [16] = { .new_input = 0             , .cur_input = kButton_R                            , .new_pose = kPose_69_FaceR_Jump_AimUR               , },
  [17] = { .new_input = 0             , .cur_input = kButton_L                            , .new_pose = kPose_6B_FaceR_Jump_AimDR               , },
  [18] = { .new_input = 0             , .cur_input = kButton_Right                        , .new_pose = kPose_51_FaceR_Jump_NoAim_MoveF         , },
  [19] = { .new_input = 0             , .cur_input = kButton_A                            , .new_pose = kPose_4D_FaceR_Jump_NoAim_NoMove_NoGun  , },
  [20] = { .new_input = 0             , .cur_input = kButton_X                            , .new_pose = kPose_13_FaceR_Jump_NoAim_NoMove_Gun    , },
  [21] = { 0xffff },
};

static const PoseEntry Trans_16[] = {  // 0x91a376
  [0]  = { .new_input = 0             , .cur_input = kButton_A+kButton_Left+kButton_Up    , .new_pose = kPose_6A_FaceL_Jump_AimUL               , },
  [1]  = { .new_input = 0             , .cur_input = kButton_A+kButton_Left+kButton_Down  , .new_pose = kPose_6C_FaceL_Jump_AimDL               , },
  [2]  = { .new_input = 0             , .cur_input = kButton_R+kButton_A+kButton_Left     , .new_pose = kPose_6A_FaceL_Jump_AimUL               , },
  [3]  = { .new_input = 0             , .cur_input = kButton_L+kButton_A+kButton_Left     , .new_pose = kPose_6C_FaceL_Jump_AimDL               , },
  [4]  = { .new_input = 0             , .cur_input = kButton_Left+kButton_Up              , .new_pose = kPose_6A_FaceL_Jump_AimUL               , },
  [5]  = { .new_input = 0             , .cur_input = kButton_Left+kButton_Down            , .new_pose = kPose_6C_FaceL_Jump_AimDL               , },
  [6]  = { .new_input = 0             , .cur_input = kButton_A+kButton_Right              , .new_pose = kPose_30_FaceL_Turn_Jump                , },
  [7]  = { .new_input = 0             , .cur_input = kButton_A+kButton_Up                 , .new_pose = kPose_16_FaceL_Jump_AimU                , },
  [8]  = { .new_input = 0             , .cur_input = kButton_A+kButton_Down               , .new_pose = kPose_18_FaceL_Jump_AimD                , },
  [9]  = { .new_input = 0             , .cur_input = kButton_R+kButton_A                  , .new_pose = kPose_6A_FaceL_Jump_AimUL               , },
  [10] = { .new_input = 0             , .cur_input = kButton_L+kButton_A                  , .new_pose = kPose_6C_FaceL_Jump_AimDL               , },
  [11] = { .new_input = 0             , .cur_input = kButton_A+kButton_Left               , .new_pose = kPose_52_FaceL_Jump_NoAim_MoveF         , },
  [12] = { .new_input = 0             , .cur_input = kButton_X+kButton_A                  , .new_pose = kPose_14_FaceL_Jump_NoAim_NoMove_Gun    , },
  [13] = { .new_input = 0             , .cur_input = kButton_Right                        , .new_pose = kPose_30_FaceL_Turn_Jump                , },
  [14] = { .new_input = 0             , .cur_input = kButton_Up                           , .new_pose = kPose_16_FaceL_Jump_AimU                , },
  [15] = { .new_input = 0             , .cur_input = kButton_Down                         , .new_pose = kPose_18_FaceL_Jump_AimD                , },
  [16] = { .new_input = 0             , .cur_input = kButton_R                            , .new_pose = kPose_6A_FaceL_Jump_AimUL               , },
  [17] = { .new_input = 0             , .cur_input = kButton_L                            , .new_pose = kPose_6C_FaceL_Jump_AimDL               , },
  [18] = { .new_input = 0             , .cur_input = kButton_Left                         , .new_pose = kPose_52_FaceL_Jump_NoAim_MoveF         , },
  [19] = { .new_input = 0             , .cur_input = kButton_A                            , .new_pose = kPose_4E_FaceL_Jump_NoAim_NoMove_NoGun  , },
  [20] = { .new_input = 0             , .cur_input = kButton_X                            , .new_pose = kPose_14_FaceL_Jump_NoAim_NoMove_Gun    , },
  [21] = { 0xffff },
};

static const PoseEntry Trans_17[] = {  // 0x91abb4
  [0]  = { .new_input = kButton_Down  , .cur_input = 0                                    , .new_pose = kPose_37_FaceR_MorphTrans               , },
  [1]  = { .new_input = 0             , .cur_input = kButton_A+kButton_Right+kButton_Up   , .new_pose = kPose_69_FaceR_Jump_AimUR               , },
  [2]  = { .new_input = 0             , .cur_input = kButton_A+kButton_Right+kButton_Down , .new_pose = kPose_6B_FaceR_Jump_AimDR               , },
  [3]  = { .new_input = 0             , .cur_input = kButton_R+kButton_A+kButton_Right    , .new_pose = kPose_69_FaceR_Jump_AimUR               , },
  [4]  = { .new_input = 0             , .cur_input = kButton_L+kButton_A+kButton_Right    , .new_pose = kPose_6B_FaceR_Jump_AimDR               , },
  [5]  = { .new_input = 0             , .cur_input = kButton_X+kButton_A+kButton_Right    , .new_pose = kPose_13_FaceR_Jump_NoAim_NoMove_Gun    , },
  [6]  = { .new_input = 0             , .cur_input = kButton_Right+kButton_Up             , .new_pose = kPose_69_FaceR_Jump_AimUR               , },
  [7]  = { .new_input = 0             , .cur_input = kButton_Right+kButton_Down           , .new_pose = kPose_6B_FaceR_Jump_AimDR               , },
  [8]  = { .new_input = 0             , .cur_input = kButton_A+kButton_Left               , .new_pose = kPose_2F_FaceR_Turn_Jump                , },
  [9]  = { .new_input = 0             , .cur_input = kButton_A+kButton_Up                 , .new_pose = kPose_15_FaceR_Jump_AimU                , },
  [10] = { .new_input = 0             , .cur_input = kButton_A+kButton_Down               , .new_pose = kPose_17_FaceR_Jump_AimD                , },
  [11] = { .new_input = 0             , .cur_input = kButton_R+kButton_A                  , .new_pose = kPose_69_FaceR_Jump_AimUR               , },
  [12] = { .new_input = 0             , .cur_input = kButton_L+kButton_A                  , .new_pose = kPose_6B_FaceR_Jump_AimDR               , },
  [13] = { .new_input = 0             , .cur_input = kButton_A+kButton_Right              , .new_pose = kPose_51_FaceR_Jump_NoAim_MoveF         , },
  [14] = { .new_input = 0             , .cur_input = kButton_X+kButton_A                  , .new_pose = kPose_13_FaceR_Jump_NoAim_NoMove_Gun    , },
  [15] = { .new_input = 0             , .cur_input = kButton_Left                         , .new_pose = kPose_2F_FaceR_Turn_Jump                , },
  [16] = { .new_input = 0             , .cur_input = kButton_Up                           , .new_pose = kPose_15_FaceR_Jump_AimU                , },
  [17] = { .new_input = 0             , .cur_input = kButton_Down                         , .new_pose = kPose_17_FaceR_Jump_AimD                , },
  [18] = { .new_input = 0             , .cur_input = kButton_R                            , .new_pose = kPose_69_FaceR_Jump_AimUR               , },
  [19] = { .new_input = 0             , .cur_input = kButton_L                            , .new_pose = kPose_6B_FaceR_Jump_AimDR               , },
  [20] = { .new_input = 0             , .cur_input = kButton_Right                        , .new_pose = kPose_51_FaceR_Jump_NoAim_MoveF         , },
  [21] = { .new_input = 0             , .cur_input = kButton_A                            , .new_pose = kPose_17_FaceR_Jump_AimD                , },
  [22] = { .new_input = 0             , .cur_input = kButton_X                            , .new_pose = kPose_13_FaceR_Jump_NoAim_NoMove_Gun    , },
  [23] = { 0xffff },
};

static const PoseEntry Trans_18[] = {  // 0x91ac40
  [0]  = { .new_input = kButton_Down  , .cur_input = 0                                    , .new_pose = kPose_38_FaceL_MorphTrans               , },
  [1]  = { .new_input = 0             , .cur_input = kButton_A+kButton_Left+kButton_Up    , .new_pose = kPose_6A_FaceL_Jump_AimUL               , },
  [2]  = { .new_input = 0             , .cur_input = kButton_A+kButton_Left+kButton_Down  , .new_pose = kPose_6C_FaceL_Jump_AimDL               , },
  [3]  = { .new_input = 0             , .cur_input = kButton_R+kButton_A+kButton_Left     , .new_pose = kPose_6A_FaceL_Jump_AimUL               , },
  [4]  = { .new_input = 0             , .cur_input = kButton_L+kButton_A+kButton_Left     , .new_pose = kPose_6C_FaceL_Jump_AimDL               , },
  [5]  = { .new_input = 0             , .cur_input = kButton_L+kButton_A+kButton_Left     , .new_pose = kPose_6C_FaceL_Jump_AimDL               , },
  [6]  = { .new_input = 0             , .cur_input = kButton_Left+kButton_Up              , .new_pose = kPose_6A_FaceL_Jump_AimUL               , },
  [7]  = { .new_input = 0             , .cur_input = kButton_Left+kButton_Down            , .new_pose = kPose_6C_FaceL_Jump_AimDL               , },
  [8]  = { .new_input = 0             , .cur_input = kButton_A+kButton_Right              , .new_pose = kPose_30_FaceL_Turn_Jump                , },
  [9]  = { .new_input = 0             , .cur_input = kButton_A+kButton_Up                 , .new_pose = kPose_16_FaceL_Jump_AimU                , },
  [10] = { .new_input = 0             , .cur_input = kButton_A+kButton_Down               , .new_pose = kPose_18_FaceL_Jump_AimD                , },
  [11] = { .new_input = 0             , .cur_input = kButton_R+kButton_A                  , .new_pose = kPose_6A_FaceL_Jump_AimUL               , },
  [12] = { .new_input = 0             , .cur_input = kButton_L+kButton_A                  , .new_pose = kPose_6C_FaceL_Jump_AimDL               , },
  [13] = { .new_input = 0             , .cur_input = kButton_A+kButton_Left               , .new_pose = kPose_52_FaceL_Jump_NoAim_MoveF         , },
  [14] = { .new_input = 0             , .cur_input = kButton_X+kButton_A                  , .new_pose = kPose_14_FaceL_Jump_NoAim_NoMove_Gun    , },
  [15] = { .new_input = 0             , .cur_input = kButton_Right                        , .new_pose = kPose_30_FaceL_Turn_Jump                , },
  [16] = { .new_input = 0             , .cur_input = kButton_Up                           , .new_pose = kPose_16_FaceL_Jump_AimU                , },
  [17] = { .new_input = 0             , .cur_input = kButton_Down                         , .new_pose = kPose_18_FaceL_Jump_AimD                , },
  [18] = { .new_input = 0             , .cur_input = kButton_R                            , .new_pose = kPose_6A_FaceL_Jump_AimUL               , },
  [19] = { .new_input = 0             , .cur_input = kButton_L                            , .new_pose = kPose_6C_FaceL_Jump_AimDL               , },
  [20] = { .new_input = 0             , .cur_input = kButton_Left                         , .new_pose = kPose_52_FaceL_Jump_NoAim_MoveF         , },
  [21] = { .new_input = 0             , .cur_input = kButton_A                            , .new_pose = kPose_18_FaceL_Jump_AimD                , },
  [22] = { .new_input = 0             , .cur_input = kButton_X                            , .new_pose = kPose_14_FaceL_Jump_NoAim_NoMove_Gun    , },
  [23] = { 0xffff },
};

static const PoseEntry Trans_19[] = {  // 0x91a41e
  [0]  = { .new_input = kButton_X     , .cur_input = 0                                    , .new_pose = kPose_13_FaceR_Jump_NoAim_NoMove_Gun    , },
  [1]  = { .new_input = kButton_X     , .cur_input = kButton_Right                        , .new_pose = kPose_13_FaceR_Jump_NoAim_NoMove_Gun    , },
  [2]  = { .new_input = 0             , .cur_input = kButton_X+kButton_Up                 , .new_pose = kPose_15_FaceR_Jump_AimU                , },
  [3]  = { .new_input = 0             , .cur_input = kButton_X+kButton_Down               , .new_pose = kPose_17_FaceR_Jump_AimD                , },
  [4]  = { .new_input = 0             , .cur_input = kButton_R+kButton_X                  , .new_pose = kPose_69_FaceR_Jump_AimUR               , },
  [5]  = { .new_input = 0             , .cur_input = kButton_L+kButton_X                  , .new_pose = kPose_6B_FaceR_Jump_AimDR               , },
  [6]  = { .new_input = 0             , .cur_input = kButton_A+kButton_Right              , .new_pose = kPose_19_FaceR_SpinJump                 , },
  [7]  = { .new_input = 0             , .cur_input = kButton_Up                           , .new_pose = kPose_15_FaceR_Jump_AimU                , },
  [8]  = { .new_input = 0             , .cur_input = kButton_R                            , .new_pose = kPose_69_FaceR_Jump_AimUR               , },
  [9]  = { .new_input = 0             , .cur_input = kButton_L                            , .new_pose = kPose_6B_FaceR_Jump_AimDR               , },
  [10] = { .new_input = 0             , .cur_input = kButton_Down                         , .new_pose = kPose_17_FaceR_Jump_AimD                , },
  [11] = { .new_input = 0             , .cur_input = kButton_Right                        , .new_pose = kPose_19_FaceR_SpinJump                 , },
  [12] = { .new_input = 0             , .cur_input = kButton_Left                         , .new_pose = kPose_1A_FaceL_SpinJump                 , },
  [13] = { 0xffff },
};

static const PoseEntry Trans_1a[] = {  // 0x91a46e
  [0]  = { .new_input = kButton_X     , .cur_input = 0                                    , .new_pose = kPose_14_FaceL_Jump_NoAim_NoMove_Gun    , },
  [1]  = { .new_input = kButton_X     , .cur_input = kButton_Left                         , .new_pose = kPose_14_FaceL_Jump_NoAim_NoMove_Gun    , },
  [2]  = { .new_input = 0             , .cur_input = kButton_X+kButton_Up                 , .new_pose = kPose_16_FaceL_Jump_AimU                , },
  [3]  = { .new_input = 0             , .cur_input = kButton_X+kButton_Down               , .new_pose = kPose_18_FaceL_Jump_AimD                , },
  [4]  = { .new_input = 0             , .cur_input = kButton_R+kButton_X                  , .new_pose = kPose_6A_FaceL_Jump_AimUL               , },
  [5]  = { .new_input = 0             , .cur_input = kButton_L+kButton_X                  , .new_pose = kPose_6C_FaceL_Jump_AimDL               , },
  [6]  = { .new_input = 0             , .cur_input = kButton_A+kButton_Left               , .new_pose = kPose_1A_FaceL_SpinJump                 , },
  [7]  = { .new_input = 0             , .cur_input = kButton_Up                           , .new_pose = kPose_16_FaceL_Jump_AimU                , },
  [8]  = { .new_input = 0             , .cur_input = kButton_R                            , .new_pose = kPose_6A_FaceL_Jump_AimUL               , },
  [9]  = { .new_input = 0             , .cur_input = kButton_L                            , .new_pose = kPose_6C_FaceL_Jump_AimDL               , },
  [10] = { .new_input = 0             , .cur_input = kButton_Down                         , .new_pose = kPose_18_FaceL_Jump_AimD                , },
  [11] = { .new_input = 0             , .cur_input = kButton_Left                         , .new_pose = kPose_1A_FaceL_SpinJump                 , },
  [12] = { .new_input = 0             , .cur_input = kButton_Right                        , .new_pose = kPose_19_FaceR_SpinJump                 , },
  [13] = { 0xffff },
};

static const PoseEntry Trans_1b[] = {  // 0x91a4be
  [0]  = { .new_input = kButton_X     , .cur_input = 0                                    , .new_pose = kPose_13_FaceR_Jump_NoAim_NoMove_Gun    , },
  [1]  = { .new_input = kButton_X     , .cur_input = kButton_Right                        , .new_pose = kPose_13_FaceR_Jump_NoAim_NoMove_Gun    , },
  [2]  = { .new_input = 0             , .cur_input = kButton_X+kButton_Up                 , .new_pose = kPose_15_FaceR_Jump_AimU                , },
  [3]  = { .new_input = 0             , .cur_input = kButton_X+kButton_Down               , .new_pose = kPose_17_FaceR_Jump_AimD                , },
  [4]  = { .new_input = 0             , .cur_input = kButton_R+kButton_X                  , .new_pose = kPose_69_FaceR_Jump_AimUR               , },
  [5]  = { .new_input = 0             , .cur_input = kButton_L+kButton_X                  , .new_pose = kPose_6B_FaceR_Jump_AimDR               , },
  [6]  = { .new_input = 0             , .cur_input = kButton_A+kButton_Right              , .new_pose = kPose_1B_FaceR_SpaceJump                , },
  [7]  = { .new_input = 0             , .cur_input = kButton_Up                           , .new_pose = kPose_15_FaceR_Jump_AimU                , },
  [8]  = { .new_input = 0             , .cur_input = kButton_R                            , .new_pose = kPose_69_FaceR_Jump_AimUR               , },
  [9]  = { .new_input = 0             , .cur_input = kButton_L                            , .new_pose = kPose_6B_FaceR_Jump_AimDR               , },
  [10] = { .new_input = 0             , .cur_input = kButton_Down                         , .new_pose = kPose_17_FaceR_Jump_AimD                , },
  [11] = { .new_input = 0             , .cur_input = kButton_Right                        , .new_pose = kPose_1B_FaceR_SpaceJump                , },
  [12] = { .new_input = 0             , .cur_input = kButton_Left                         , .new_pose = kPose_1C_FaceL_SpaceJump                , },
  [13] = { 0xffff },
};

static const PoseEntry Trans_1c[] = {  // 0x91a50e
  [0]  = { .new_input = kButton_X     , .cur_input = 0                                    , .new_pose = kPose_14_FaceL_Jump_NoAim_NoMove_Gun    , },
  [1]  = { .new_input = kButton_X     , .cur_input = kButton_Left                         , .new_pose = kPose_14_FaceL_Jump_NoAim_NoMove_Gun    , },
  [2]  = { .new_input = 0             , .cur_input = kButton_X+kButton_Up                 , .new_pose = kPose_16_FaceL_Jump_AimU                , },
  [3]  = { .new_input = 0             , .cur_input = kButton_X+kButton_Down               , .new_pose = kPose_18_FaceL_Jump_AimD                , },
  [4]  = { .new_input = 0             , .cur_input = kButton_R+kButton_X                  , .new_pose = kPose_6A_FaceL_Jump_AimUL               , },
  [5]  = { .new_input = 0             , .cur_input = kButton_L+kButton_X                  , .new_pose = kPose_6C_FaceL_Jump_AimDL               , },
  [6]  = { .new_input = 0             , .cur_input = kButton_A+kButton_Left               , .new_pose = kPose_1C_FaceL_SpaceJump                , },
  [7]  = { .new_input = 0             , .cur_input = kButton_Up                           , .new_pose = kPose_16_FaceL_Jump_AimU                , },
  [8]  = { .new_input = 0             , .cur_input = kButton_R                            , .new_pose = kPose_6A_FaceL_Jump_AimUL               , },
  [9]  = { .new_input = 0             , .cur_input = kButton_L                            , .new_pose = kPose_6C_FaceL_Jump_AimDL               , },
  [10] = { .new_input = 0             , .cur_input = kButton_Down                         , .new_pose = kPose_18_FaceL_Jump_AimD                , },
  [11] = { .new_input = 0             , .cur_input = kButton_Left                         , .new_pose = kPose_1C_FaceL_SpaceJump                , },
  [12] = { .new_input = 0             , .cur_input = kButton_Right                        , .new_pose = kPose_1B_FaceR_SpaceJump                , },
  [13] = { 0xffff },
};

static const PoseEntry Trans_1d[] = {  // 0x91a5fe
  [0]  = { .new_input = kButton_Up    , .cur_input = 0                                    , .new_pose = kPose_3D_FaceR_UnmorphTrans             , },
  [1]  = { .new_input = kButton_A     , .cur_input = 0                                    , .new_pose = kPose_3D_FaceR_UnmorphTrans             , },
  [2]  = { .new_input = 0             , .cur_input = kButton_Right                        , .new_pose = kPose_1E_MoveR_Morphball_Ground         , },
  [3]  = { .new_input = 0             , .cur_input = kButton_Left                         , .new_pose = kPose_1F_MoveL_Morphball_Ground         , },
  [4]  = { 0xffff },
};

static const PoseEntry Trans_1e[] = {  // 0x91a618
  [0]  = { .new_input = kButton_Up    , .cur_input = 0                                    , .new_pose = kPose_3D_FaceR_UnmorphTrans             , },
  [1]  = { .new_input = kButton_A     , .cur_input = 0                                    , .new_pose = kPose_3D_FaceR_UnmorphTrans             , },
  [2]  = { .new_input = 0             , .cur_input = kButton_Right                        , .new_pose = kPose_1E_MoveR_Morphball_Ground         , },
  [3]  = { .new_input = 0             , .cur_input = kButton_Left                         , .new_pose = kPose_1F_MoveL_Morphball_Ground         , },
  [4]  = { 0xffff },
};

static const PoseEntry Trans_1f[] = {  // 0x91a632
  [0]  = { .new_input = kButton_Up    , .cur_input = 0                                    , .new_pose = kPose_3E_FaceL_UnmorphTrans             , },
  [1]  = { .new_input = kButton_A     , .cur_input = 0                                    , .new_pose = kPose_3E_FaceL_UnmorphTrans             , },
  [2]  = { .new_input = 0             , .cur_input = kButton_Right                        , .new_pose = kPose_1E_MoveR_Morphball_Ground         , },
  [3]  = { .new_input = 0             , .cur_input = kButton_Left                         , .new_pose = kPose_1F_MoveL_Morphball_Ground         , },
  [4]  = { 0xffff },
};

static const PoseEntry Trans_20[] = {  // 0x91a666
  [0]  = { 0xffff },
};

static const PoseEntry Trans_23[] = {  // 0x91a668
  [0]  = { 0xffff },
};

static const PoseEntry Trans_25[] = {  // 0x91acf4
  [0]  = { .new_input = 0             , .cur_input = kButton_A+kButton_Left               , .new_pose = kPose_1A_FaceL_SpinJump                 , },
  [1]  = { .new_input = kButton_A     , .cur_input = 0                                    , .new_pose = kPose_4C_FaceL_Jumptrans                , },
  [2]  = { .new_input = 0             , .cur_input = kButton_Left                         , .new_pose = kPose_25_FaceR_Turn_Stand               , },
  [3]  = { 0xffff },
};

static const PoseEntry Trans_26[] = {  // 0x91ad08
  [0]  = { .new_input = 0             , .cur_input = kButton_A+kButton_Right              , .new_pose = kPose_19_FaceR_SpinJump                 , },
  [1]  = { .new_input = kButton_A     , .cur_input = 0                                    , .new_pose = kPose_4B_FaceR_Jumptrans                , },
  [2]  = { .new_input = 0             , .cur_input = kButton_Right                        , .new_pose = kPose_26_FaceL_Turn_Stand               , },
  [3]  = { 0xffff },
};

static const PoseEntry Trans_27[] = {  // 0x91a66c
  [0]  = { .new_input = kButton_Up    , .cur_input = kButton_R+kButton_L                  , .new_pose = kPose_F7_FaceR_StandTrans_AimU          , },
  [1]  = { .new_input = kButton_Up    , .cur_input = kButton_R                            , .new_pose = kPose_F9_FaceR_StandTrans_AimUR         , },
  [2]  = { .new_input = kButton_Up    , .cur_input = kButton_L                            , .new_pose = kPose_FB_FaceR_StandTrans_AimDR         , },
  [3]  = { .new_input = kButton_Up    , .cur_input = 0                                    , .new_pose = kPose_3B_FaceR_StandTrans               , },
  [4]  = { .new_input = kButton_Left  , .cur_input = 0                                    , .new_pose = kPose_43_FaceR_Turn_Crouch              , },
  [5]  = { .new_input = kButton_Down  , .cur_input = 0                                    , .new_pose = kPose_37_FaceR_MorphTrans               , },
  [6]  = { .new_input = kButton_A     , .cur_input = 0                                    , .new_pose = kPose_4B_FaceR_Jumptrans                , },
  [7]  = { .new_input = 0             , .cur_input = kButton_R+kButton_L                  , .new_pose = kPose_85_FaceR_Crouch_AimU              , },
  [8]  = { .new_input = 0             , .cur_input = kButton_R+kButton_Right              , .new_pose = kPose_01_FaceR_Normal                   , },
  [9]  = { .new_input = 0             , .cur_input = kButton_L+kButton_Right              , .new_pose = kPose_01_FaceR_Normal                   , },
  [10] = { .new_input = 0             , .cur_input = kButton_R                            , .new_pose = kPose_71_FaceR_Crouch_AimUR             , },
  [11] = { .new_input = 0             , .cur_input = kButton_L                            , .new_pose = kPose_73_FaceR_Crouch_AimDR             , },
  [12] = { .new_input = 0             , .cur_input = kButton_Right                        , .new_pose = kPose_01_FaceR_Normal                   , },
  [13] = { 0xffff },
};

static const PoseEntry Trans_28[] = {  // 0x91a6bc
  [0]  = { .new_input = kButton_Up    , .cur_input = kButton_R+kButton_L                  , .new_pose = kPose_F8_FaceL_StandTrans_AimU          , },
  [1]  = { .new_input = kButton_Up    , .cur_input = kButton_R                            , .new_pose = kPose_FA_FaceL_StandTrans_AimUL         , },
  [2]  = { .new_input = kButton_Up    , .cur_input = kButton_L                            , .new_pose = kPose_FC_FaceL_StandTrans_AimDL         , },
  [3]  = { .new_input = kButton_Up    , .cur_input = 0                                    , .new_pose = kPose_3C_FaceL_StandTrans               , },
  [4]  = { .new_input = kButton_Right , .cur_input = 0                                    , .new_pose = kPose_44_FaceL_Turn_Crouch              , },
  [5]  = { .new_input = kButton_Down  , .cur_input = 0                                    , .new_pose = kPose_38_FaceL_MorphTrans               , },
  [6]  = { .new_input = kButton_A     , .cur_input = 0                                    , .new_pose = kPose_4C_FaceL_Jumptrans                , },
  [7]  = { .new_input = 0             , .cur_input = kButton_R+kButton_L                  , .new_pose = kPose_86_FaceL_Crouch_AimU              , },
  [8]  = { .new_input = 0             , .cur_input = kButton_L+kButton_Left               , .new_pose = kPose_02_FaceL_Normal                   , },
  [9]  = { .new_input = 0             , .cur_input = kButton_R+kButton_Left               , .new_pose = kPose_02_FaceL_Normal                   , },
  [10] = { .new_input = 0             , .cur_input = kButton_R                            , .new_pose = kPose_72_FaceL_Crouch_AimUL             , },
  [11] = { .new_input = 0             , .cur_input = kButton_L                            , .new_pose = kPose_74_FaceL_Crouch_AimDL             , },
  [12] = { .new_input = 0             , .cur_input = kButton_Left                         , .new_pose = kPose_02_FaceL_Normal                   , },
  [13] = { 0xffff },
};

static const PoseEntry Trans_29[] = {  // 0x91a70c
  [0]  = { .new_input = 0             , .cur_input = kButton_Right+kButton_Up             , .new_pose = kPose_6D_FaceR_Fall_AimUR               , },
  [1]  = { .new_input = 0             , .cur_input = kButton_Right+kButton_Down           , .new_pose = kPose_6F_FaceR_Fall_AimDR               , },
  [2]  = { .new_input = 0             , .cur_input = kButton_Left+kButton_Up              , .new_pose = kPose_87_FaceR_Turn_Fall                , },
  [3]  = { .new_input = 0             , .cur_input = kButton_Left+kButton_Down            , .new_pose = kPose_87_FaceR_Turn_Fall                , },
  [4]  = { .new_input = 0             , .cur_input = kButton_Left                         , .new_pose = kPose_87_FaceR_Turn_Fall                , },
  [5]  = { .new_input = 0             , .cur_input = kButton_Up                           , .new_pose = kPose_2B_FaceR_Fall_AimU                , },
  [6]  = { .new_input = 0             , .cur_input = kButton_Down                         , .new_pose = kPose_2D_FaceR_Fall_AimD                , },
  [7]  = { .new_input = 0             , .cur_input = kButton_R                            , .new_pose = kPose_6D_FaceR_Fall_AimUR               , },
  [8]  = { .new_input = 0             , .cur_input = kButton_L                            , .new_pose = kPose_6F_FaceR_Fall_AimDR               , },
  [9]  = { .new_input = 0             , .cur_input = kButton_X                            , .new_pose = kPose_67_FaceR_Fall_Gun                 , },
  [10] = { .new_input = 0             , .cur_input = kButton_Right                        , .new_pose = kPose_29_FaceR_Fall                     , },
  [11] = { 0xffff },
};

static const PoseEntry Trans_2a[] = {  // 0x91a750
  [0]  = { .new_input = 0             , .cur_input = kButton_Left+kButton_Up              , .new_pose = kPose_6E_FaceL_Fall_AimUL               , },
  [1]  = { .new_input = 0             , .cur_input = kButton_Left+kButton_Down            , .new_pose = kPose_70_FaceL_Fall_AimDL               , },
  [2]  = { .new_input = 0             , .cur_input = kButton_Right+kButton_Up             , .new_pose = kPose_88_FaceL_Turn_Fall                , },
  [3]  = { .new_input = 0             , .cur_input = kButton_Right+kButton_Down           , .new_pose = kPose_88_FaceL_Turn_Fall                , },
  [4]  = { .new_input = 0             , .cur_input = kButton_Right                        , .new_pose = kPose_88_FaceL_Turn_Fall                , },
  [5]  = { .new_input = 0             , .cur_input = kButton_Up                           , .new_pose = kPose_2C_FaceL_Fall_AimU                , },
  [6]  = { .new_input = 0             , .cur_input = kButton_Down                         , .new_pose = kPose_2E_FaceL_Fall_AimD                , },
  [7]  = { .new_input = 0             , .cur_input = kButton_R                            , .new_pose = kPose_6E_FaceL_Fall_AimUL               , },
  [8]  = { .new_input = 0             , .cur_input = kButton_L                            , .new_pose = kPose_70_FaceL_Fall_AimDL               , },
  [9]  = { .new_input = 0             , .cur_input = kButton_X                            , .new_pose = kPose_68_FaceL_Fall_Gun                 , },
  [10] = { .new_input = 0             , .cur_input = kButton_Left                         , .new_pose = kPose_2A_FaceL_Fall                     , },
  [11] = { 0xffff },
};

static const PoseEntry Trans_2d[] = {  // 0x91ad94
  [0]  = { .new_input = kButton_Down  , .cur_input = 0                                    , .new_pose = kPose_37_FaceR_MorphTrans               , },
  [1]  = { .new_input = 0             , .cur_input = kButton_Right+kButton_Up             , .new_pose = kPose_6D_FaceR_Fall_AimUR               , },
  [2]  = { .new_input = 0             , .cur_input = kButton_Right+kButton_Down           , .new_pose = kPose_6F_FaceR_Fall_AimDR               , },
  [3]  = { .new_input = 0             , .cur_input = kButton_Up                           , .new_pose = kPose_2B_FaceR_Fall_AimU                , },
  [4]  = { .new_input = 0             , .cur_input = kButton_Down                         , .new_pose = kPose_2D_FaceR_Fall_AimD                , },
  [5]  = { .new_input = 0             , .cur_input = kButton_Left                         , .new_pose = kPose_87_FaceR_Turn_Fall                , },
  [6]  = { .new_input = 0             , .cur_input = kButton_R                            , .new_pose = kPose_6D_FaceR_Fall_AimUR               , },
  [7]  = { .new_input = 0             , .cur_input = kButton_L                            , .new_pose = kPose_6F_FaceR_Fall_AimDR               , },
  [8]  = { .new_input = 0             , .cur_input = kButton_X                            , .new_pose = kPose_67_FaceR_Fall_Gun                 , },
  [9]  = { .new_input = 0             , .cur_input = kButton_Right                        , .new_pose = kPose_29_FaceR_Fall                     , },
  [10] = { 0xffff },
};

static const PoseEntry Trans_2e[] = {  // 0x91add2
  [0]  = { .new_input = kButton_Down  , .cur_input = 0                                    , .new_pose = kPose_38_FaceL_MorphTrans               , },
  [1]  = { .new_input = 0             , .cur_input = kButton_Left+kButton_Up              , .new_pose = kPose_6E_FaceL_Fall_AimUL               , },
  [2]  = { .new_input = 0             , .cur_input = kButton_Left+kButton_Down            , .new_pose = kPose_70_FaceL_Fall_AimDL               , },
  [3]  = { .new_input = 0             , .cur_input = kButton_Up                           , .new_pose = kPose_2C_FaceL_Fall_AimU                , },
  [4]  = { .new_input = 0             , .cur_input = kButton_Down                         , .new_pose = kPose_2E_FaceL_Fall_AimD                , },
  [5]  = { .new_input = 0             , .cur_input = kButton_Right                        , .new_pose = kPose_88_FaceL_Turn_Fall                , },
  [6]  = { .new_input = 0             , .cur_input = kButton_R                            , .new_pose = kPose_6E_FaceL_Fall_AimUL               , },
  [7]  = { .new_input = 0             , .cur_input = kButton_L                            , .new_pose = kPose_70_FaceL_Fall_AimDL               , },
  [8]  = { .new_input = 0             , .cur_input = kButton_X                            , .new_pose = kPose_68_FaceL_Fall_Gun                 , },
  [9]  = { .new_input = 0             , .cur_input = kButton_Left                         , .new_pose = kPose_2A_FaceL_Fall                     , },
  [10] = { 0xffff },
};

static const PoseEntry Trans_2f[] = {  // 0x91a0dc
  [0]  = { 0xffff },
};

static const PoseEntry Trans_31[] = {  // 0x91a794
  [0]  = { .new_input = kButton_Up    , .cur_input = 0                                    , .new_pose = kPose_3D_FaceR_UnmorphTrans             , },
  [1]  = { .new_input = kButton_A     , .cur_input = 0                                    , .new_pose = kPose_3D_FaceR_UnmorphTrans             , },
  [2]  = { .new_input = 0             , .cur_input = kButton_Right                        , .new_pose = kPose_31_FaceR_Morphball_Air            , },
  [3]  = { .new_input = 0             , .cur_input = kButton_Left                         , .new_pose = kPose_32_FaceL_Morphball_Air            , },
  [4]  = { 0xffff },
};

static const PoseEntry Trans_32[] = {  // 0x91a7ae
  [0]  = { .new_input = kButton_Up    , .cur_input = 0                                    , .new_pose = kPose_3E_FaceL_UnmorphTrans             , },
  [1]  = { .new_input = kButton_A     , .cur_input = 0                                    , .new_pose = kPose_3E_FaceL_UnmorphTrans             , },
  [2]  = { .new_input = 0             , .cur_input = kButton_Left                         , .new_pose = kPose_32_FaceL_Morphball_Air            , },
  [3]  = { .new_input = 0             , .cur_input = kButton_Right                        , .new_pose = kPose_31_FaceR_Morphball_Air            , },
  [4]  = { 0xffff },
};

static const PoseEntry Trans_33[] = {  // 0x91a7c8
  [0]  = { 0xffff },
};

static const PoseEntry Trans_34[] = {  // 0x91a7ca
  [0]  = { 0xffff },
};

static const PoseEntry Trans_3d[] = {  // 0x91accc
  [0]  = { .new_input = 0             , .cur_input = kButton_X+kButton_Right              , .new_pose = kPose_67_FaceR_Fall_Gun                 , },
  [1]  = { .new_input = 0             , .cur_input = kButton_X+kButton_Up                 , .new_pose = kPose_2B_FaceR_Fall_AimU                , },
  [2]  = { .new_input = 0             , .cur_input = kButton_X+kButton_Down               , .new_pose = kPose_2D_FaceR_Fall_AimD                , },
  [3]  = { 0xffff },
};

static const PoseEntry Trans_3e[] = {  // 0x91ace0
  [0]  = { .new_input = 0             , .cur_input = kButton_X+kButton_Left               , .new_pose = kPose_68_FaceL_Fall_Gun                 , },
  [1]  = { .new_input = 0             , .cur_input = kButton_X+kButton_Up                 , .new_pose = kPose_2C_FaceL_Fall_AimU                , },
  [2]  = { .new_input = 0             , .cur_input = kButton_X+kButton_Down               , .new_pose = kPose_2E_FaceL_Fall_AimD                , },
  [3]  = { 0xffff },
};

static const PoseEntry Trans_41[] = {  // 0x91a64c
  [0]  = { .new_input = kButton_Up    , .cur_input = 0                                    , .new_pose = kPose_3E_FaceL_UnmorphTrans             , },
  [1]  = { .new_input = kButton_A     , .cur_input = 0                                    , .new_pose = kPose_3E_FaceL_UnmorphTrans             , },
  [2]  = { .new_input = 0             , .cur_input = kButton_Right                        , .new_pose = kPose_1E_MoveR_Morphball_Ground         , },
  [3]  = { .new_input = 0             , .cur_input = kButton_Left                         , .new_pose = kPose_1F_MoveL_Morphball_Ground         , },
  [4]  = { 0xffff },
};

static const PoseEntry Trans_42[] = {  // 0x91a66a
  [0]  = { 0xffff },
};

static const PoseEntry Trans_45[] = {  // 0x91a7cc
  [0]  = { .new_input = 0             , .cur_input = kButton_X+kButton_Left               , .new_pose = kPose_45                                , },
  [1]  = { .new_input = 0             , .cur_input = kButton_Right                        , .new_pose = kPose_09_MoveR_NoAim                    , },
  [2]  = { .new_input = 0             , .cur_input = kButton_Left                         , .new_pose = kPose_25_FaceR_Turn_Stand               , },
  [3]  = { 0xffff },
};

static const PoseEntry Trans_46[] = {  // 0x91a7e0
  [0]  = { .new_input = 0             , .cur_input = kButton_X+kButton_Right              , .new_pose = kPose_46                                , },
  [1]  = { .new_input = 0             , .cur_input = kButton_Left                         , .new_pose = kPose_0A_MoveL_NoAim                    , },
  [2]  = { .new_input = 0             , .cur_input = kButton_Right                        , .new_pose = kPose_26_FaceL_Turn_Stand               , },
  [3]  = { 0xffff },
};

static const PoseEntry Trans_47[] = {  // 0x91a7f4
  [0]  = { 0xffff },
};

static const PoseEntry Trans_48[] = {  // 0x91a834
  [0]  = { 0xffff },
};

static const PoseEntry Trans_49[] = {  // 0x91a874
  [0]  = { .new_input = kButton_Down  , .cur_input = 0                                    , .new_pose = kPose_36_FaceL_CrouchTrans              , },
  [1]  = { .new_input = kButton_A     , .cur_input = 0                                    , .new_pose = kPose_C0_FaceL_Moonwalk_TurnjumpR       , },
  [2]  = { .new_input = kButton_A     , .cur_input = kButton_R                            , .new_pose = kPose_C2_FaceL_Moonwalk_TurnjumpR_AimUL , },
  [3]  = { .new_input = kButton_A     , .cur_input = kButton_L                            , .new_pose = kPose_C4_FaceL_Moonwalk_TurnjumpR_AimDL , },
  [4]  = { .new_input = 0             , .cur_input = kButton_L+kButton_X+kButton_Right    , .new_pose = kPose_77_FaceL_Moonwalk_AimDL           , },
  [5]  = { .new_input = 0             , .cur_input = kButton_R+kButton_X+kButton_Right    , .new_pose = kPose_75_FaceL_Moonwalk_AimUL           , },
  [6]  = { .new_input = 0             , .cur_input = kButton_X+kButton_Right              , .new_pose = kPose_49_FaceL_Moonwalk                 , },
  [7]  = { .new_input = 0             , .cur_input = kButton_Left                         , .new_pose = kPose_0A_MoveL_NoAim                    , },
  [8]  = { .new_input = 0             , .cur_input = kButton_Right                        , .new_pose = kPose_26_FaceL_Turn_Stand               , },
  [9]  = { 0xffff },
};

static const PoseEntry Trans_4a[] = {  // 0x91a8ac
  [0]  = { .new_input = kButton_Down  , .cur_input = 0                                    , .new_pose = kPose_35_FaceR_CrouchTrans              , },
  [1]  = { .new_input = kButton_A     , .cur_input = 0                                    , .new_pose = kPose_BF_FaceR_Moonwalk_TurnjumpL       , },
  [2]  = { .new_input = kButton_A     , .cur_input = kButton_R                            , .new_pose = kPose_C1_FaceR_Moonwalk_TurnjumpL_AimUR , },
  [3]  = { .new_input = kButton_A     , .cur_input = kButton_L                            , .new_pose = kPose_C3_FaceR_Moonwalk_TurnjumpL_AimDR , },
  [4]  = { .new_input = 0             , .cur_input = kButton_R+kButton_X+kButton_Left     , .new_pose = kPose_76_FaceR_Moonwalk_AimUR           , },
  [5]  = { .new_input = 0             , .cur_input = kButton_L+kButton_X+kButton_Left     , .new_pose = kPose_78_FaceR_Moonwalk_AimDR           , },
  [6]  = { .new_input = 0             , .cur_input = kButton_X+kButton_Left               , .new_pose = kPose_4A_FaceR_Moonwalk                 , },
  [7]  = { .new_input = 0             , .cur_input = kButton_Right                        , .new_pose = kPose_09_MoveR_NoAim                    , },
  [8]  = { .new_input = 0             , .cur_input = kButton_Left                         , .new_pose = kPose_25_FaceR_Turn_Stand               , },
  [9]  = { 0xffff },
};

static const PoseEntry Trans_4b[] = {  // 0x91a28c
  [0]  = { .new_input = 0             , .cur_input = kButton_A+kButton_Left               , .new_pose = kPose_2F_FaceR_Turn_Jump                , },
  [1]  = { .new_input = 0             , .cur_input = kButton_A+kButton_Up                 , .new_pose = kPose_15_FaceR_Jump_AimU                , },
  [2]  = { .new_input = 0             , .cur_input = kButton_A+kButton_Down               , .new_pose = kPose_17_FaceR_Jump_AimD                , },
  [3]  = { .new_input = 0             , .cur_input = kButton_R+kButton_A                  , .new_pose = kPose_69_FaceR_Jump_AimUR               , },
  [4]  = { .new_input = 0             , .cur_input = kButton_L+kButton_A                  , .new_pose = kPose_6B_FaceR_Jump_AimDR               , },
  [5]  = { .new_input = 0             , .cur_input = kButton_A+kButton_Right              , .new_pose = kPose_51_FaceR_Jump_NoAim_MoveF         , },
  [6]  = { .new_input = 0             , .cur_input = kButton_X+kButton_A                  , .new_pose = kPose_13_FaceR_Jump_NoAim_NoMove_Gun    , },
  [7]  = { .new_input = 0             , .cur_input = kButton_X                            , .new_pose = kPose_13_FaceR_Jump_NoAim_NoMove_Gun    , },
  [8]  = { 0xffff },
};

static const PoseEntry Trans_4c[] = {  // 0x91a2be
  [0]  = { .new_input = 0             , .cur_input = kButton_A+kButton_Right              , .new_pose = kPose_30_FaceL_Turn_Jump                , },
  [1]  = { .new_input = 0             , .cur_input = kButton_A+kButton_Up                 , .new_pose = kPose_16_FaceL_Jump_AimU                , },
  [2]  = { .new_input = 0             , .cur_input = kButton_A+kButton_Down               , .new_pose = kPose_18_FaceL_Jump_AimD                , },
  [3]  = { .new_input = 0             , .cur_input = kButton_R+kButton_A                  , .new_pose = kPose_6A_FaceL_Jump_AimUL               , },
  [4]  = { .new_input = 0             , .cur_input = kButton_L+kButton_A                  , .new_pose = kPose_6C_FaceL_Jump_AimDL               , },
  [5]  = { .new_input = 0             , .cur_input = kButton_A+kButton_Left               , .new_pose = kPose_52_FaceL_Jump_NoAim_MoveF         , },
  [6]  = { .new_input = 0             , .cur_input = kButton_X+kButton_A                  , .new_pose = kPose_14_FaceL_Jump_NoAim_NoMove_Gun    , },
  [7]  = { .new_input = 0             , .cur_input = kButton_Right                        , .new_pose = kPose_30_FaceL_Turn_Jump                , },
  [8]  = { .new_input = 0             , .cur_input = kButton_X                            , .new_pose = kPose_14_FaceL_Jump_NoAim_NoMove_Gun    , },
  [9]  = { 0xffff },
};

static const PoseEntry Trans_4f[] = {  // 0x91a3f6
  [0]  = { .new_input = 0             , .cur_input = kButton_A+kButton_Left               , .new_pose = kPose_52_FaceL_Jump_NoAim_MoveF         , },
  [1]  = { .new_input = 0             , .cur_input = kButton_A+kButton_Right              , .new_pose = kPose_4F_FaceL_Dmgboost                 , },
  [2]  = { .new_input = 0             , .cur_input = kButton_A                            , .new_pose = kPose_4E_FaceL_Jump_NoAim_NoMove_NoGun  , },
  [3]  = { 0xffff },
};

static const PoseEntry Trans_50[] = {  // 0x91a40a
  [0]  = { .new_input = 0             , .cur_input = kButton_A+kButton_Left               , .new_pose = kPose_50_FaceR_Dmgboost                 , },
  [1]  = { .new_input = 0             , .cur_input = kButton_A+kButton_Right              , .new_pose = kPose_51_FaceR_Jump_NoAim_MoveF         , },
  [2]  = { .new_input = 0             , .cur_input = kButton_A                            , .new_pose = kPose_4D_FaceR_Jump_NoAim_NoMove_NoGun  , },
  [3]  = { 0xffff },
};

static const PoseEntry Trans_53[] = {  // 0x91a8e4
  [0]  = { .new_input = 0             , .cur_input = kButton_A+kButton_Left               , .new_pose = kPose_50_FaceR_Dmgboost                 , },
  [1]  = { 0xffff },
};

static const PoseEntry Trans_54[] = {  // 0x91a8ec
  [0]  = { .new_input = 0             , .cur_input = kButton_A+kButton_Right              , .new_pose = kPose_4F_FaceL_Dmgboost                 , },
  [1]  = { 0xffff },
};

static const PoseEntry Trans_5b[] = {  // 0x91a8fc
  [0]  = { .new_input = 0             , .cur_input = kButton_A+kButton_Left               , .new_pose = kPose_66                                , },
  [1]  = { 0xffff },
};

static const PoseEntry Trans_5c[] = {  // 0x91a904
  [0]  = { .new_input = 0             , .cur_input = kButton_A+kButton_Right              , .new_pose = kPose_65                                , },
  [1]  = { 0xffff },
};

static const PoseEntry Trans_63[] = {  // 0x91a990
  [0]  = { .new_input = 0             , .cur_input = kButton_A+kButton_Left               , .new_pose = kPose_66                                , },
  [1]  = { 0xffff },
};

static const PoseEntry Trans_64[] = {  // 0x91a998
  [0]  = { .new_input = 0             , .cur_input = kButton_A+kButton_Right              , .new_pose = kPose_65                                , },
  [1]  = { 0xffff },
};

static const PoseEntry Trans_65[] = {  // 0x91a9a0
  [0]  = { .new_input = 0             , .cur_input = kButton_A+kButton_Right              , .new_pose = kPose_65                                , },
  [1]  = { .new_input = 0             , .cur_input = kButton_R                            , .new_pose = kPose_69_FaceR_Jump_AimUR               , },
  [2]  = { .new_input = 0             , .cur_input = kButton_L                            , .new_pose = kPose_6B_FaceR_Jump_AimDR               , },
  [3]  = { .new_input = 0             , .cur_input = kButton_X                            , .new_pose = kPose_13_FaceR_Jump_NoAim_NoMove_Gun    , },
  [4]  = { .new_input = 0             , .cur_input = kButton_A                            , .new_pose = kPose_65                                , },
  [5]  = { .new_input = 0             , .cur_input = kButton_Right                        , .new_pose = kPose_65                                , },
  [6]  = { 0xffff },
};

static const PoseEntry Trans_66[] = {  // 0x91a9c6
  [0]  = { .new_input = 0             , .cur_input = kButton_A+kButton_Left               , .new_pose = kPose_66                                , },
  [1]  = { .new_input = 0             , .cur_input = kButton_R                            , .new_pose = kPose_6A_FaceL_Jump_AimUL               , },
  [2]  = { .new_input = 0             , .cur_input = kButton_L                            , .new_pose = kPose_6C_FaceL_Jump_AimDL               , },
  [3]  = { .new_input = 0             , .cur_input = kButton_X                            , .new_pose = kPose_14_FaceL_Jump_NoAim_NoMove_Gun    , },
  [4]  = { .new_input = 0             , .cur_input = kButton_A                            , .new_pose = kPose_66                                , },
  [5]  = { .new_input = 0             , .cur_input = kButton_Left                         , .new_pose = kPose_66                                , },
  [6]  = { 0xffff },
};

static const PoseEntry Trans_67[] = {  // 0x91af28
  [0]  = { .new_input = 0             , .cur_input = kButton_Right+kButton_Up             , .new_pose = kPose_6D_FaceR_Fall_AimUR               , },
  [1]  = { .new_input = 0             , .cur_input = kButton_Right+kButton_Down           , .new_pose = kPose_6F_FaceR_Fall_AimDR               , },
  [2]  = { .new_input = 0             , .cur_input = kButton_Up                           , .new_pose = kPose_2B_FaceR_Fall_AimU                , },
  [3]  = { .new_input = 0             , .cur_input = kButton_Down                         , .new_pose = kPose_2D_FaceR_Fall_AimD                , },
  [4]  = { .new_input = 0             , .cur_input = kButton_Left                         , .new_pose = kPose_87_FaceR_Turn_Fall                , },
  [5]  = { .new_input = 0             , .cur_input = kButton_R                            , .new_pose = kPose_6D_FaceR_Fall_AimUR               , },
  [6]  = { .new_input = 0             , .cur_input = kButton_L                            , .new_pose = kPose_6F_FaceR_Fall_AimDR               , },
  [7]  = { .new_input = 0             , .cur_input = kButton_X                            , .new_pose = kPose_67_FaceR_Fall_Gun                 , },
  [8]  = { .new_input = 0             , .cur_input = kButton_Right                        , .new_pose = kPose_67_FaceR_Fall_Gun                 , },
  [9]  = { 0xffff },
};

static const PoseEntry Trans_68[] = {  // 0x91af60
  [0]  = { .new_input = 0             , .cur_input = kButton_Left+kButton_Up              , .new_pose = kPose_6E_FaceL_Fall_AimUL               , },
  [1]  = { .new_input = 0             , .cur_input = kButton_Left+kButton_Down            , .new_pose = kPose_70_FaceL_Fall_AimDL               , },
  [2]  = { .new_input = 0             , .cur_input = kButton_Up                           , .new_pose = kPose_2C_FaceL_Fall_AimU                , },
  [3]  = { .new_input = 0             , .cur_input = kButton_Down                         , .new_pose = kPose_2E_FaceL_Fall_AimD                , },
  [4]  = { .new_input = 0             , .cur_input = kButton_Right                        , .new_pose = kPose_88_FaceL_Turn_Fall                , },
  [5]  = { .new_input = 0             , .cur_input = kButton_R                            , .new_pose = kPose_6E_FaceL_Fall_AimUL               , },
  [6]  = { .new_input = 0             , .cur_input = kButton_L                            , .new_pose = kPose_70_FaceL_Fall_AimDL               , },
  [7]  = { .new_input = 0             , .cur_input = kButton_X                            , .new_pose = kPose_68_FaceL_Fall_Gun                 , },
  [8]  = { .new_input = 0             , .cur_input = kButton_Left                         , .new_pose = kPose_68_FaceL_Fall_Gun                 , },
  [9]  = { 0xffff },
};

static const PoseEntry Trans_79[] = {  // 0x91a90c
  [0]  = { .new_input = kButton_Up    , .cur_input = 0                                    , .new_pose = kPose_3D_FaceR_UnmorphTrans             , },
  [1]  = { .new_input = kButton_A     , .cur_input = 0                                    , .new_pose = kPose_7F_FaceR_Springball_Air           , },
  [2]  = { .new_input = 0             , .cur_input = kButton_Right                        , .new_pose = kPose_7B_MoveR_Springball_Ground        , },
  [3]  = { .new_input = 0             , .cur_input = kButton_Left                         , .new_pose = kPose_7C_MoveL_Springball_Ground        , },
  [4]  = { 0xffff },
};

static const PoseEntry Trans_7a[] = {  // 0x91a926
  [0]  = { .new_input = kButton_Up    , .cur_input = 0                                    , .new_pose = kPose_3E_FaceL_UnmorphTrans             , },
  [1]  = { .new_input = kButton_A     , .cur_input = 0                                    , .new_pose = kPose_80_FaceL_Springball_Air           , },
  [2]  = { .new_input = 0             , .cur_input = kButton_Right                        , .new_pose = kPose_7B_MoveR_Springball_Ground        , },
  [3]  = { .new_input = 0             , .cur_input = kButton_Left                         , .new_pose = kPose_7C_MoveL_Springball_Ground        , },
  [4]  = { 0xffff },
};

static const PoseEntry Trans_7d[] = {  // 0x91a940
  [0]  = { .new_input = kButton_Up    , .cur_input = 0                                    , .new_pose = kPose_3D_FaceR_UnmorphTrans             , },
  [1]  = { .new_input = 0             , .cur_input = kButton_Left                         , .new_pose = kPose_7E_FaceL_Springball_Fall          , },
  [2]  = { .new_input = 0             , .cur_input = kButton_Right                        , .new_pose = kPose_7D_FaceR_Springball_Fall          , },
  [3]  = { 0xffff },
};

static const PoseEntry Trans_7e[] = {  // 0x91a954
  [0]  = { .new_input = kButton_Up    , .cur_input = 0                                    , .new_pose = kPose_3E_FaceL_UnmorphTrans             , },
  [1]  = { .new_input = 0             , .cur_input = kButton_Right                        , .new_pose = kPose_7D_FaceR_Springball_Fall          , },
  [2]  = { .new_input = 0             , .cur_input = kButton_Left                         , .new_pose = kPose_7E_FaceL_Springball_Fall          , },
  [3]  = { 0xffff },
};

static const PoseEntry Trans_7f[] = {  // 0x91a968
  [0]  = { .new_input = kButton_Up    , .cur_input = 0                                    , .new_pose = kPose_3D_FaceR_UnmorphTrans             , },
  [1]  = { .new_input = 0             , .cur_input = kButton_Right                        , .new_pose = kPose_7F_FaceR_Springball_Air           , },
  [2]  = { .new_input = 0             , .cur_input = kButton_Left                         , .new_pose = kPose_80_FaceL_Springball_Air           , },
  [3]  = { 0xffff },
};

static const PoseEntry Trans_80[] = {  // 0x91a97c
  [0]  = { .new_input = kButton_Up    , .cur_input = 0                                    , .new_pose = kPose_3E_FaceL_UnmorphTrans             , },
  [1]  = { .new_input = 0             , .cur_input = kButton_Right                        , .new_pose = kPose_7F_FaceR_Springball_Air           , },
  [2]  = { .new_input = 0             , .cur_input = kButton_Left                         , .new_pose = kPose_80_FaceL_Springball_Air           , },
  [3]  = { 0xffff },
};

static const PoseEntry Trans_81[] = {  // 0x91a55e
  [0]  = { .new_input = kButton_X     , .cur_input = 0                                    , .new_pose = kPose_13_FaceR_Jump_NoAim_NoMove_Gun    , },
  [1]  = { .new_input = kButton_X     , .cur_input = kButton_Right                        , .new_pose = kPose_13_FaceR_Jump_NoAim_NoMove_Gun    , },
  [2]  = { .new_input = 0             , .cur_input = kButton_X+kButton_Up                 , .new_pose = kPose_15_FaceR_Jump_AimU                , },
  [3]  = { .new_input = 0             , .cur_input = kButton_X+kButton_Down               , .new_pose = kPose_17_FaceR_Jump_AimD                , },
  [4]  = { .new_input = 0             , .cur_input = kButton_R+kButton_X                  , .new_pose = kPose_69_FaceR_Jump_AimUR               , },
  [5]  = { .new_input = 0             , .cur_input = kButton_L+kButton_X                  , .new_pose = kPose_6B_FaceR_Jump_AimDR               , },
  [6]  = { .new_input = 0             , .cur_input = kButton_A+kButton_Right              , .new_pose = kPose_81_FaceR_Screwattack              , },
  [7]  = { .new_input = 0             , .cur_input = kButton_Up                           , .new_pose = kPose_15_FaceR_Jump_AimU                , },
  [8]  = { .new_input = 0             , .cur_input = kButton_R                            , .new_pose = kPose_69_FaceR_Jump_AimUR               , },
  [9]  = { .new_input = 0             , .cur_input = kButton_L                            , .new_pose = kPose_6B_FaceR_Jump_AimDR               , },
  [10] = { .new_input = 0             , .cur_input = kButton_Down                         , .new_pose = kPose_17_FaceR_Jump_AimD                , },
  [11] = { .new_input = 0             , .cur_input = kButton_Right                        , .new_pose = kPose_81_FaceR_Screwattack              , },
  [12] = { .new_input = 0             , .cur_input = kButton_Left                         , .new_pose = kPose_82_FaceL_Screwattack              , },
  [13] = { 0xffff },
};

static const PoseEntry Trans_82[] = {  // 0x91a5ae
  [0]  = { .new_input = kButton_X     , .cur_input = 0                                    , .new_pose = kPose_14_FaceL_Jump_NoAim_NoMove_Gun    , },
  [1]  = { .new_input = kButton_X     , .cur_input = kButton_Left                         , .new_pose = kPose_14_FaceL_Jump_NoAim_NoMove_Gun    , },
  [2]  = { .new_input = 0             , .cur_input = kButton_X+kButton_Up                 , .new_pose = kPose_16_FaceL_Jump_AimU                , },
  [3]  = { .new_input = 0             , .cur_input = kButton_X+kButton_Down               , .new_pose = kPose_18_FaceL_Jump_AimD                , },
  [4]  = { .new_input = 0             , .cur_input = kButton_R+kButton_X                  , .new_pose = kPose_6A_FaceL_Jump_AimUL               , },
  [5]  = { .new_input = 0             , .cur_input = kButton_L+kButton_X                  , .new_pose = kPose_6C_FaceL_Jump_AimDL               , },
  [6]  = { .new_input = 0             , .cur_input = kButton_A+kButton_Left               , .new_pose = kPose_82_FaceL_Screwattack              , },
  [7]  = { .new_input = 0             , .cur_input = kButton_Up                           , .new_pose = kPose_16_FaceL_Jump_AimU                , },
  [8]  = { .new_input = 0             , .cur_input = kButton_R                            , .new_pose = kPose_6A_FaceL_Jump_AimUL               , },
  [9]  = { .new_input = 0             , .cur_input = kButton_L                            , .new_pose = kPose_6C_FaceL_Jump_AimDL               , },
  [10] = { .new_input = 0             , .cur_input = kButton_Down                         , .new_pose = kPose_18_FaceL_Jump_AimD                , },
  [11] = { .new_input = 0             , .cur_input = kButton_Left                         , .new_pose = kPose_82_FaceL_Screwattack              , },
  [12] = { .new_input = 0             , .cur_input = kButton_Right                        , .new_pose = kPose_81_FaceR_Screwattack              , },
  [13] = { 0xffff },
};

static const PoseEntry Trans_83[] = {  // 0x91a9ec
  [0]  = { .new_input = kButton_Down  , .cur_input = 0                                    , .new_pose = kPose_37_FaceR_MorphTrans               , },
  [1]  = { .new_input = 0             , .cur_input = kButton_Left                         , .new_pose = kPose_1A_FaceL_SpinJump                 , },
  [2]  = { .new_input = 0             , .cur_input = kButton_R                            , .new_pose = kPose_69_FaceR_Jump_AimUR               , },
  [3]  = { .new_input = 0             , .cur_input = kButton_L                            , .new_pose = kPose_6B_FaceR_Jump_AimDR               , },
  [4]  = { .new_input = 0             , .cur_input = kButton_X                            , .new_pose = kPose_13_FaceR_Jump_NoAim_NoMove_Gun    , },
  [5]  = { .new_input = 0             , .cur_input = kButton_A                            , .new_pose = kPose_83_FaceR_Walljump                 , },
  [6]  = { 0xffff },
};

static const PoseEntry Trans_84[] = {  // 0x91aa12
  [0]  = { .new_input = kButton_Down  , .cur_input = 0                                    , .new_pose = kPose_38_FaceL_MorphTrans               , },
  [1]  = { .new_input = 0             , .cur_input = kButton_Right                        , .new_pose = kPose_19_FaceR_SpinJump                 , },
  [2]  = { .new_input = 0             , .cur_input = kButton_R                            , .new_pose = kPose_6A_FaceL_Jump_AimUL               , },
  [3]  = { .new_input = 0             , .cur_input = kButton_L                            , .new_pose = kPose_6C_FaceL_Jump_AimDL               , },
  [4]  = { .new_input = 0             , .cur_input = kButton_X                            , .new_pose = kPose_14_FaceL_Jump_NoAim_NoMove_Gun    , },
  [5]  = { .new_input = 0             , .cur_input = kButton_A                            , .new_pose = kPose_84_FaceL_Walljump                 , },
  [6]  = { 0xffff },
};

static const PoseEntry Trans_89[] = {  // 0x91aa38
  [0]  = { .new_input = kButton_A     , .cur_input = 0                                    , .new_pose = kPose_4B_FaceR_Jumptrans                , },
  [1]  = { .new_input = 0             , .cur_input = kButton_Right+kButton_Up             , .new_pose = kPose_0F_MoveR_AimUR                    , },
  [2]  = { .new_input = 0             , .cur_input = kButton_Right+kButton_Down           , .new_pose = kPose_11_MoveR_AimDR                    , },
  [3]  = { .new_input = kButton_Down  , .cur_input = 0                                    , .new_pose = kPose_35_FaceR_CrouchTrans              , },
  [4]  = { .new_input = 0             , .cur_input = kButton_L+kButton_Left               , .new_pose = kPose_78_FaceR_Moonwalk_AimDR           , },
  [5]  = { .new_input = 0             , .cur_input = kButton_R+kButton_Left               , .new_pose = kPose_76_FaceR_Moonwalk_AimUR           , },
  [6]  = { .new_input = 0             , .cur_input = kButton_Up                           , .new_pose = kPose_03_FaceR_AimU                     , },
  [7]  = { .new_input = 0             , .cur_input = kButton_R                            , .new_pose = kPose_05_FaceR_AimUR                    , },
  [8]  = { .new_input = 0             , .cur_input = kButton_L                            , .new_pose = kPose_07_FaceR_AimDR                    , },
  [9]  = { .new_input = 0             , .cur_input = kButton_Left                         , .new_pose = kPose_25_FaceR_Turn_Stand               , },
  [10] = { .new_input = 0             , .cur_input = kButton_Right                        , .new_pose = kPose_09_MoveR_NoAim                    , },
  [11] = { 0xffff },
};

static const PoseEntry Trans_8a[] = {  // 0x91aa7c
  [0]  = { .new_input = kButton_A     , .cur_input = 0                                    , .new_pose = kPose_4C_FaceL_Jumptrans                , },
  [1]  = { .new_input = 0             , .cur_input = kButton_Left+kButton_Up              , .new_pose = kPose_10_MoveL_AimUL                    , },
  [2]  = { .new_input = 0             , .cur_input = kButton_Left+kButton_Down            , .new_pose = kPose_12_MoveL_AimDL                    , },
  [3]  = { .new_input = kButton_Down  , .cur_input = 0                                    , .new_pose = kPose_36_FaceL_CrouchTrans              , },
  [4]  = { .new_input = 0             , .cur_input = kButton_L+kButton_Right              , .new_pose = kPose_77_FaceL_Moonwalk_AimDL           , },
  [5]  = { .new_input = 0             , .cur_input = kButton_R+kButton_Right              , .new_pose = kPose_75_FaceL_Moonwalk_AimUL           , },
  [6]  = { .new_input = 0             , .cur_input = kButton_Up                           , .new_pose = kPose_04_FaceL_AimU                     , },
  [7]  = { .new_input = 0             , .cur_input = kButton_R                            , .new_pose = kPose_06_FaceL_AimUL                    , },
  [8]  = { .new_input = 0             , .cur_input = kButton_L                            , .new_pose = kPose_08_FaceL_AimDL                    , },
  [9]  = { .new_input = 0             , .cur_input = kButton_Right                        , .new_pose = kPose_26_FaceL_Turn_Stand               , },
  [10] = { .new_input = 0             , .cur_input = kButton_Left                         , .new_pose = kPose_0A_MoveL_NoAim                    , },
  [11] = { 0xffff },
};

static const PoseEntry Trans_8b[] = {  // 0x91ad1c
  [0]  = { .new_input = kButton_A     , .cur_input = kButton_Left                         , .new_pose = kPose_1A_FaceL_SpinJump                 , },
  [1]  = { .new_input = kButton_A     , .cur_input = 0                                    , .new_pose = kPose_4C_FaceL_Jumptrans                , },
  [2]  = { .new_input = 0             , .cur_input = kButton_Left                         , .new_pose = kPose_8B_FaceR_Turn_Stand_AimU          , },
  [3]  = { 0xffff },
};

static const PoseEntry Trans_8c[] = {  // 0x91ad30
  [0]  = { .new_input = kButton_A     , .cur_input = kButton_Right                        , .new_pose = kPose_19_FaceR_SpinJump                 , },
  [1]  = { .new_input = kButton_A     , .cur_input = 0                                    , .new_pose = kPose_4B_FaceR_Jumptrans                , },
  [2]  = { .new_input = 0             , .cur_input = kButton_Right                        , .new_pose = kPose_8C_FaceL_Turn_Stand_AimU          , },
  [3]  = { 0xffff },
};

static const PoseEntry Trans_8d[] = {  // 0x91ad44
  [0]  = { .new_input = kButton_A     , .cur_input = kButton_Left                         , .new_pose = kPose_1A_FaceL_SpinJump                 , },
  [1]  = { .new_input = kButton_A     , .cur_input = 0                                    , .new_pose = kPose_4C_FaceL_Jumptrans                , },
  [2]  = { .new_input = 0             , .cur_input = kButton_Left                         , .new_pose = kPose_8D_FaceR_Turn_Stand_AimDR         , },
  [3]  = { 0xffff },
};

static const PoseEntry Trans_8e[] = {  // 0x91ad58
  [0]  = { .new_input = kButton_A     , .cur_input = kButton_Right                        , .new_pose = kPose_19_FaceR_SpinJump                 , },
  [1]  = { .new_input = kButton_A     , .cur_input = 0                                    , .new_pose = kPose_4B_FaceR_Jumptrans                , },
  [2]  = { .new_input = 0             , .cur_input = kButton_Right                        , .new_pose = kPose_8E_FaceL_Turn_Stand_AimDL         , },
  [3]  = { 0xffff },
};

static const PoseEntry Trans_ba[] = {  // 0x91ae18
  [0]  = { .new_input = 0             , .cur_input = kButton_X+kButton_Left+kButton_Up    , .new_pose = kPose_BB_FaceL_Draygon_NoMove_AimUL     , },
  [1]  = { .new_input = 0             , .cur_input = kButton_X+kButton_Left+kButton_Down  , .new_pose = kPose_BD_FaceL_Draygon_NoMove_AimDL     , },
  [2]  = { .new_input = 0             , .cur_input = kButton_X+kButton_Left               , .new_pose = kPose_BC_FaceL_Draygon_Fire             , },
  [3]  = { .new_input = 0             , .cur_input = kButton_R                            , .new_pose = kPose_BB_FaceL_Draygon_NoMove_AimUL     , },
  [4]  = { .new_input = 0             , .cur_input = kButton_L                            , .new_pose = kPose_BD_FaceL_Draygon_NoMove_AimDL     , },
  [5]  = { .new_input = 0             , .cur_input = kButton_X                            , .new_pose = kPose_BC_FaceL_Draygon_Fire             , },
  [6]  = { .new_input = 0             , .cur_input = kButton_Left                         , .new_pose = kPose_BE_FaceL_Draygon_Move             , },
  [7]  = { .new_input = 0             , .cur_input = kButton_Right                        , .new_pose = kPose_BE_FaceL_Draygon_Move             , },
  [8]  = { .new_input = 0             , .cur_input = kButton_Up                           , .new_pose = kPose_BE_FaceL_Draygon_Move             , },
  [9]  = { .new_input = 0             , .cur_input = kButton_Down                         , .new_pose = kPose_BE_FaceL_Draygon_Move             , },
  [10] = { 0xffff },
};

static const PoseEntry Trans_bf[] = {  // 0x91af98
  [0]  = { .new_input = 0             , .cur_input = kButton_A+kButton_Left               , .new_pose = kPose_1A_FaceL_SpinJump                 , },
  [1]  = { .new_input = kButton_A     , .cur_input = 0                                    , .new_pose = kPose_4C_FaceL_Jumptrans                , },
  [2]  = { .new_input = 0             , .cur_input = kButton_Left                         , .new_pose = kPose_BF_FaceR_Moonwalk_TurnjumpL       , },
  [3]  = { 0xffff },
};

static const PoseEntry Trans_c0[] = {  // 0x91afac
  [0]  = { .new_input = 0             , .cur_input = kButton_A+kButton_Right              , .new_pose = kPose_19_FaceR_SpinJump                 , },
  [1]  = { .new_input = kButton_A     , .cur_input = 0                                    , .new_pose = kPose_4B_FaceR_Jumptrans                , },
  [2]  = { .new_input = 0             , .cur_input = kButton_Right                        , .new_pose = kPose_C0_FaceL_Moonwalk_TurnjumpR       , },
  [3]  = { 0xffff },
};

static const PoseEntry Trans_c1[] = {  // 0x91afc0
  [0]  = { .new_input = kButton_A     , .cur_input = kButton_Left                         , .new_pose = kPose_1A_FaceL_SpinJump                 , },
  [1]  = { .new_input = kButton_A     , .cur_input = 0                                    , .new_pose = kPose_4C_FaceL_Jumptrans                , },
  [2]  = { .new_input = 0             , .cur_input = kButton_Left                         , .new_pose = kPose_C1_FaceR_Moonwalk_TurnjumpL_AimUR , },
  [3]  = { 0xffff },
};

static const PoseEntry Trans_c2[] = {  // 0x91afd4
  [0]  = { .new_input = kButton_A     , .cur_input = kButton_Right                        , .new_pose = kPose_19_FaceR_SpinJump                 , },
  [1]  = { .new_input = kButton_A     , .cur_input = 0                                    , .new_pose = kPose_4B_FaceR_Jumptrans                , },
  [2]  = { .new_input = 0             , .cur_input = kButton_Right                        , .new_pose = kPose_C2_FaceL_Moonwalk_TurnjumpR_AimUL , },
  [3]  = { 0xffff },
};

static const PoseEntry Trans_c3[] = {  // 0x91afe8
  [0]  = { .new_input = kButton_A     , .cur_input = kButton_Left                         , .new_pose = kPose_1A_FaceL_SpinJump                 , },
  [1]  = { .new_input = kButton_A     , .cur_input = 0                                    , .new_pose = kPose_4C_FaceL_Jumptrans                , },
  [2]  = { .new_input = 0             , .cur_input = kButton_Left                         , .new_pose = kPose_C3_FaceR_Moonwalk_TurnjumpL_AimDR , },
  [3]  = { 0xffff },
};

static const PoseEntry Trans_c4[] = {  // 0x91affc
  [0]  = { .new_input = kButton_A     , .cur_input = kButton_Right                        , .new_pose = kPose_19_FaceR_SpinJump                 , },
  [1]  = { .new_input = kButton_A     , .cur_input = 0                                    , .new_pose = kPose_4B_FaceR_Jumptrans                , },
  [2]  = { .new_input = 0             , .cur_input = kButton_Right                        , .new_pose = kPose_C4_FaceL_Moonwalk_TurnjumpR_AimDL , },
  [3]  = { 0xffff },
};

static const PoseEntry Trans_c7[] = {  // 0x91ad6c
  [0]  = { .new_input = 0             , .cur_input = kButton_A+kButton_Up                 , .new_pose = kPose_CB_FaceR_Shinespark_Vert          , },
  [1]  = { .new_input = 0             , .cur_input = kButton_R+kButton_A                  , .new_pose = kPose_CD_FaceR_Shinespark_Diag          , },
  [2]  = { .new_input = 0             , .cur_input = kButton_A+kButton_Right              , .new_pose = kPose_C9_FaceR_Shinespark_Horiz         , },
  [3]  = { 0xffff },
};

static const PoseEntry Trans_c8[] = {  // 0x91ad80
  [0]  = { .new_input = 0             , .cur_input = kButton_A+kButton_Up                 , .new_pose = kPose_CC_FaceL_Shinespark_Vert          , },
  [1]  = { .new_input = 0             , .cur_input = kButton_R+kButton_A                  , .new_pose = kPose_CE_FaceL_Shinespark_Diag          , },
  [2]  = { .new_input = 0             , .cur_input = kButton_A+kButton_Left               , .new_pose = kPose_CA_FaceL_Shinespark_Horiz         , },
  [3]  = { 0xffff },
};

static const PoseEntry Trans_df[] = {  // 0x91ae10
  [0]  = { .new_input = kButton_Up    , .cur_input = 0                                    , .new_pose = kPose_DE                                , },
  [1]  = { 0xffff },
};

static const PoseEntry Trans_ec[] = {  // 0x91ae56
  [0]  = { .new_input = 0             , .cur_input = kButton_X+kButton_Right+kButton_Up   , .new_pose = kPose_ED_FaceR_Draygon_NoMove_AimUR     , },
  [1]  = { .new_input = 0             , .cur_input = kButton_X+kButton_Right+kButton_Down , .new_pose = kPose_EF_FaceR_Draygon_NoMove_AimDR     , },
  [2]  = { .new_input = 0             , .cur_input = kButton_X+kButton_Right              , .new_pose = kPose_EE_FaceR_Draygon_Fire             , },
  [3]  = { .new_input = 0             , .cur_input = kButton_R                            , .new_pose = kPose_ED_FaceR_Draygon_NoMove_AimUR     , },
  [4]  = { .new_input = 0             , .cur_input = kButton_L                            , .new_pose = kPose_EF_FaceR_Draygon_NoMove_AimDR     , },
  [5]  = { .new_input = 0             , .cur_input = kButton_X                            , .new_pose = kPose_EE_FaceR_Draygon_Fire             , },
  [6]  = { .new_input = 0             , .cur_input = kButton_Left                         , .new_pose = kPose_F0_FaceR_Draygon_Move             , },
  [7]  = { .new_input = 0             , .cur_input = kButton_Right                        , .new_pose = kPose_F0_FaceR_Draygon_Move             , },
  [8]  = { .new_input = 0             , .cur_input = kButton_Up                           , .new_pose = kPose_F0_FaceR_Draygon_Move             , },
  [9]  = { .new_input = 0             , .cur_input = kButton_Down                         , .new_pose = kPose_F0_FaceR_Draygon_Move             , },
  [10] = { 0xffff },
};

static const PoseEntry* get_PoseEntry(uint16 pose) {
  switch (pose) {
    case kPose_00_FaceF_Powersuit:
    case kPose_9B_FaceF_VariaGravitySuit:  return Trans_00;
    case kPose_01_FaceR_Normal:
    case kPose_03_FaceR_AimU: 
    case kPose_05_FaceR_AimUR: 
    case kPose_07_FaceR_AimDR: 
    case kPose_A4_FaceR_LandJump: 
    case kPose_A6_FaceR_LandSpinJump: 
    case kPose_E0_FaceR_LandJump_AimU: 
    case kPose_E2_FaceR_LandJump_AimUR: 
    case kPose_E4_FaceR_LandJump_AimDR: 
    case kPose_E6_FaceR_LandJump_Fire:  return Trans_01;
    case kPose_02_FaceL_Normal:
    case kPose_04_FaceL_AimU: 
    case kPose_06_FaceL_AimUL: 
    case kPose_08_FaceL_AimDL: 
    case kPose_A5_FaceL_LandJump: 
    case kPose_A7_FaceL_LandSpinJump: 
    case kPose_E1_FaceL_LandJump_AimU: 
    case kPose_E3_FaceL_LandJump_AimUL: 
    case kPose_E5_FaceL_LandJump_AimDL: 
    case kPose_E7_FaceL_LandJump_Fire:  return Trans_02;
    case kPose_09_MoveR_NoAim:
    case kPose_0D: 
    case kPose_0F_MoveR_AimUR: 
    case kPose_11_MoveR_AimDR:  return Trans_09;
    case kPose_0A_MoveL_NoAim:
    case kPose_0E: 
    case kPose_10_MoveL_AimUL: 
    case kPose_12_MoveL_AimDL:  return Trans_0a;
    case kPose_0B_MoveR_Gun: return Trans_0b;
    case kPose_0C_MoveL_Gun: return Trans_0c;
    case kPose_13_FaceR_Jump_NoAim_NoMove_Gun: return Trans_13;
    case kPose_14_FaceL_Jump_NoAim_NoMove_Gun: return Trans_14;
    case kPose_15_FaceR_Jump_AimU:
    case kPose_4D_FaceR_Jump_NoAim_NoMove_NoGun: 
    case kPose_51_FaceR_Jump_NoAim_MoveF: 
    case kPose_69_FaceR_Jump_AimUR: 
    case kPose_6B_FaceR_Jump_AimDR:  return Trans_15;
    case kPose_16_FaceL_Jump_AimU:
    case kPose_4E_FaceL_Jump_NoAim_NoMove_NoGun: 
    case kPose_52_FaceL_Jump_NoAim_MoveF: 
    case kPose_6A_FaceL_Jump_AimUL: 
    case kPose_6C_FaceL_Jump_AimDL:  return Trans_16;
    case kPose_17_FaceR_Jump_AimD: return Trans_17;
    case kPose_18_FaceL_Jump_AimD: return Trans_18;
    case kPose_19_FaceR_SpinJump: return Trans_19;
    case kPose_1A_FaceL_SpinJump: return Trans_1a;
    case kPose_1B_FaceR_SpaceJump: return Trans_1b;
    case kPose_1C_FaceL_SpaceJump: return Trans_1c;
    case kPose_1D_FaceR_Morphball_Ground: return Trans_1d;
    case kPose_1E_MoveR_Morphball_Ground: return Trans_1e;
    case kPose_1F_MoveL_Morphball_Ground: return Trans_1f;
    case kPose_20:
    case kPose_21: 
    case kPose_22: 
    case kPose_24:  return Trans_20;
    case kPose_23: return Trans_23;
    case kPose_25_FaceR_Turn_Stand: return Trans_25;
    case kPose_26_FaceL_Turn_Stand: return Trans_26;
    case kPose_27_FaceR_Crouch:
    case kPose_71_FaceR_Crouch_AimUR: 
    case kPose_73_FaceR_Crouch_AimDR: 
    case kPose_85_FaceR_Crouch_AimU:  return Trans_27;
    case kPose_28_FaceL_Crouch:
    case kPose_72_FaceL_Crouch_AimUL: 
    case kPose_74_FaceL_Crouch_AimDL: 
    case kPose_86_FaceL_Crouch_AimU:  return Trans_28;
    case kPose_29_FaceR_Fall:
    case kPose_2B_FaceR_Fall_AimU: 
    case kPose_6D_FaceR_Fall_AimUR: 
    case kPose_6F_FaceR_Fall_AimDR:  return Trans_29;
    case kPose_2A_FaceL_Fall:
    case kPose_2C_FaceL_Fall_AimU: 
    case kPose_6E_FaceL_Fall_AimUL: 
    case kPose_70_FaceL_Fall_AimDL:  return Trans_2a;
    case kPose_2D_FaceR_Fall_AimD: return Trans_2d;
    case kPose_2E_FaceL_Fall_AimD: return Trans_2e;
    case kPose_2F_FaceR_Turn_Jump:
    case kPose_30_FaceL_Turn_Jump: 
    case kPose_35_FaceR_CrouchTrans: 
    case kPose_36_FaceL_CrouchTrans: 
    case kPose_37_FaceR_MorphTrans: 
    case kPose_38_FaceL_MorphTrans: 
    case kPose_39: 
    case kPose_3A: 
    case kPose_3B_FaceR_StandTrans: 
    case kPose_3C_FaceL_StandTrans: 
    case kPose_3F: 
    case kPose_40: 
    case kPose_43_FaceR_Turn_Crouch: 
    case kPose_44_FaceL_Turn_Crouch: 
    case kPose_5D: 
    case kPose_5E: 
    case kPose_5F: 
    case kPose_60: 
    case kPose_61: 
    case kPose_62: 
    case kPose_87_FaceR_Turn_Fall: 
    case kPose_88_FaceL_Turn_Fall: 
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
    case kPose_A8_FaceR_Grappling: 
    case kPose_A9_FaceL_Grappling: 
    case kPose_AA_FaceR_Grappling_AimDR: 
    case kPose_AB_FaceL_Grappling_AimDL: 
    case kPose_AC: 
    case kPose_AD: 
    case kPose_AE: 
    case kPose_AF: 
    case kPose_B0: 
    case kPose_B1: 
    case kPose_B2_FaceR_Grapple_Air: 
    case kPose_B3_FaceL_Grapple_Air: 
    case kPose_B4_FaceR_Grappling_Crouch: 
    case kPose_B5_FaceL_Grappling_Crouch: 
    case kPose_B6_FaceR_Grappling_Crouch_AimDR: 
    case kPose_B7_FaceL_Grappling_Crouch_AimDL: 
    case kPose_B8_FaceL_GrappleWalljumpPose: 
    case kPose_B9_FaceR_GrappleWalljumpPose: 
    case kPose_C5: 
    case kPose_C6: 
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
    case kPose_E8_FaceR_Drained_CrouchFalling: 
    case kPose_E9_FaceL_Drained_CrouchFalling: 
    case kPose_EA_FaceR_Drained_Stand: 
    case kPose_EB_FaceL_Drained_Stand: 
    case kPose_F1_FaceR_CrouchTrans_AimU: 
    case kPose_F2_FaceL_CrouchTrans_AimU: 
    case kPose_F3_FaceR_CrouchTrans_AimUR: 
    case kPose_F4_FaceL_CrouchTrans_AimUL: 
    case kPose_F5_FaceR_CrouchTrans_AimDR: 
    case kPose_F6_FaceL_CrouchTrans_AimDL: 
    case kPose_F7_FaceR_StandTrans_AimU: 
    case kPose_F8_FaceL_StandTrans_AimU: 
    case kPose_F9_FaceR_StandTrans_AimUR: 
    case kPose_FA_FaceL_StandTrans_AimUL: 
    case kPose_FB_FaceR_StandTrans_AimDR: 
    case kPose_FC_FaceL_StandTrans_AimDL:  return Trans_2f;
    case kPose_31_FaceR_Morphball_Air: return Trans_31;
    case kPose_32_FaceL_Morphball_Air: return Trans_32;
    case kPose_33: return Trans_33;
    case kPose_34: return Trans_34;
    case kPose_3D_FaceR_UnmorphTrans: return Trans_3d;
    case kPose_3E_FaceL_UnmorphTrans: return Trans_3e;
    case kPose_41_FaceL_Morphball_Ground: return Trans_41;
    case kPose_42: return Trans_42;
    case kPose_45: return Trans_45;
    case kPose_46: return Trans_46;
    case kPose_47: return Trans_47;
    case kPose_48: return Trans_48;
    case kPose_49_FaceL_Moonwalk:
    case kPose_75_FaceL_Moonwalk_AimUL: 
    case kPose_77_FaceL_Moonwalk_AimDL:  return Trans_49;
    case kPose_4A_FaceR_Moonwalk:
    case kPose_76_FaceR_Moonwalk_AimUR: 
    case kPose_78_FaceR_Moonwalk_AimDR:  return Trans_4a;
    case kPose_4B_FaceR_Jumptrans:
    case kPose_55_FaceR_Jumptrans_AimU: 
    case kPose_57_FaceR_Jumptrans_AimUR: 
    case kPose_59_FaceR_Jumptrans_AimDR:  return Trans_4b;
    case kPose_4C_FaceL_Jumptrans:
    case kPose_56_FaceL_Jumptrans_AimU: 
    case kPose_58_FaceL_Jumptrans_AimUL: 
    case kPose_5A_FaceL_Jumptrans_AimDL:  return Trans_4c;
    case kPose_4F_FaceL_Dmgboost: return Trans_4f;
    case kPose_50_FaceR_Dmgboost: return Trans_50;
    case kPose_53_FaceR_Knockback: return Trans_53;
    case kPose_54_FaceL_Knockback: return Trans_54;
    case kPose_5B: return Trans_5b;
    case kPose_5C: return Trans_5c;
    case kPose_63: return Trans_63;
    case kPose_64: return Trans_64;
    case kPose_65: return Trans_65;
    case kPose_66: return Trans_66;
    case kPose_67_FaceR_Fall_Gun: return Trans_67;
    case kPose_68_FaceL_Fall_Gun: return Trans_68;
    case kPose_79_FaceR_Springball_Ground:
    case kPose_7B_MoveR_Springball_Ground:  return Trans_79;
    case kPose_7A_FaceL_Springball_Ground:
    case kPose_7C_MoveL_Springball_Ground:  return Trans_7a;
    case kPose_7D_FaceR_Springball_Fall: return Trans_7d;
    case kPose_7E_FaceL_Springball_Fall: return Trans_7e;
    case kPose_7F_FaceR_Springball_Air: return Trans_7f;
    case kPose_80_FaceL_Springball_Air: return Trans_80;
    case kPose_81_FaceR_Screwattack: return Trans_81;
    case kPose_82_FaceL_Screwattack: return Trans_82;
    case kPose_83_FaceR_Walljump: return Trans_83;
    case kPose_84_FaceL_Walljump: return Trans_84;
    case kPose_89_FaceR_Ranintowall:
    case kPose_CF_FaceR_Ranintowall_AimUR: 
    case kPose_D1_FaceR_Ranintowall_AimDR:  return Trans_89;
    case kPose_8A_FaceL_Ranintowall:
    case kPose_D0_FaceL_Ranintowall_AimUL: 
    case kPose_D2_FaceL_Ranintowall_AimDL:  return Trans_8a;
    case kPose_8B_FaceR_Turn_Stand_AimU: return Trans_8b;
    case kPose_8C_FaceL_Turn_Stand_AimU: return Trans_8c;
    case kPose_8D_FaceR_Turn_Stand_AimDR: return Trans_8d;
    case kPose_8E_FaceL_Turn_Stand_AimDL: return Trans_8e;
    case kPose_BA_FaceL_Draygon_NoMove_NoAim:
    case kPose_BB_FaceL_Draygon_NoMove_AimUL: 
    case kPose_BC_FaceL_Draygon_Fire: 
    case kPose_BD_FaceL_Draygon_NoMove_AimDL: 
    case kPose_BE_FaceL_Draygon_Move:  return Trans_ba;
    case kPose_BF_FaceR_Moonwalk_TurnjumpL: return Trans_bf;
    case kPose_C0_FaceL_Moonwalk_TurnjumpR: return Trans_c0;
    case kPose_C1_FaceR_Moonwalk_TurnjumpL_AimUR: return Trans_c1;
    case kPose_C2_FaceL_Moonwalk_TurnjumpR_AimUL: return Trans_c2;
    case kPose_C3_FaceR_Moonwalk_TurnjumpL_AimDR: return Trans_c3;
    case kPose_C4_FaceL_Moonwalk_TurnjumpR_AimDL: return Trans_c4;
    case kPose_C7_FaceR_ShinesparkWindup_Vert: return Trans_c7;
    case kPose_C8_FaceL_ShinesparkWindup_Vert: return Trans_c8;
    case kPose_DF: return Trans_df;
    case kPose_EC_FaceR_Draygon_NoMove_NoAim:
    case kPose_ED_FaceR_Draygon_NoMove_AimUR: 
    case kPose_EE_FaceR_Draygon_Fire: 
    case kPose_EF_FaceR_Draygon_NoMove_AimDR: 
    case kPose_F0_FaceR_Draygon_Move:  return Trans_ec;
    default: Unreachable(); return (PoseEntry*){0};
  }
}

DemoSetDef kDemoSetDefPtrs[4][6] = {
  [0] = {
    [0] = { .items = 0, .missiles = 0, .super_missiles = 0, .power_bombs = 0, .health = 99, .collected_beams_ = 0, .equipped_beams_ = 0, .demo_obj = 0x9e52 },
    [1] = { .items = kItem_MorphBall, .missiles = 5, .super_missiles = 0, .power_bombs = 0, .health = 99, .collected_beams_ = 0, .equipped_beams_ = 0, .demo_obj = 0x9e88 },
    [2] = { .items = kItem_MorphBall, .missiles = 15, .super_missiles = 0, .power_bombs = 0, .health = 199, .collected_beams_ = kBeam_Charge, .equipped_beams_ = kBeam_Charge, .demo_obj = 0x9eac },
    [3] = { .items = kItem_VariaSuit+kItem_MorphBall+kItem_HiJumpBoots+kItem_SpeedBooster, .missiles = 30, .super_missiles = 5, .power_bombs = 0, .health = 299, .collected_beams_ = kBeam_Spazer+kBeam_Charge, .equipped_beams_ = kBeam_Spazer+kBeam_Charge, .demo_obj = 0x9e5e },
    [4] = { .items = kItem_VariaSuit+kItem_MorphBall+kItem_HiJumpBoots+kItem_SpeedBooster+kItem_Grapple, .missiles = 30, .super_missiles = 5, .power_bombs = 5, .health = 399, .collected_beams_ = kBeam_Ice+kBeam_Spazer+kBeam_Charge, .equipped_beams_ = kBeam_Ice+kBeam_Spazer+kBeam_Charge, .demo_obj = 0x9eb2 },
    [5] = { .items = kItem_MorphBall, .missiles = 20, .super_missiles = 0, .power_bombs = 0, .health = 199, .collected_beams_ = kBeam_Charge, .equipped_beams_ = kBeam_Charge, .demo_obj = 0x9e58 },
  },
  [1] = {
    [0] = { .items = kItem_VariaSuit+kItem_MorphBall+kItem_HiJumpBoots+kItem_SpeedBooster, .missiles = 30, .super_missiles = 5, .power_bombs = 0, .health = 299, .collected_beams_ = kBeam_Ice+kBeam_Spazer+kBeam_Charge, .equipped_beams_ = kBeam_Ice+kBeam_Spazer+kBeam_Charge, .demo_obj = 0x9eb8 },
    [1] = { .items = kItem_MorphBall, .missiles = 10, .super_missiles = 0, .power_bombs = 0, .health = 199, .collected_beams_ = 0, .equipped_beams_ = 0, .demo_obj = 0x9e94 },
    [2] = { .items = kItem_MorphBall, .missiles = 25, .super_missiles = 5, .power_bombs = 0, .health = 199, .collected_beams_ = kBeam_Charge, .equipped_beams_ = kBeam_Charge, .demo_obj = 0x9ea0 },
    [3] = { .items = kItem_VariaSuit+kItem_MorphBall+kItem_GravitySuit+kItem_HiJumpBoots+kItem_SpaceJump+kItem_SpeedBooster+kItem_Grapple+kItem_Xray, .missiles = 75, .super_missiles = 15, .power_bombs = 10, .health = 899, .collected_beams_ = kBeam_Charge, .equipped_beams_ = kBeam_Charge, .demo_obj = 0x9e76 },
    [4] = { .items = kItem_VariaSuit+kItem_MorphBall+kItem_ScrewAttack+kItem_GravitySuit+kItem_HiJumpBoots+kItem_SpaceJump+kItem_SpeedBooster+kItem_Grapple+kItem_Xray, .missiles = 85, .super_missiles = 15, .power_bombs = 10, .health = 999, .collected_beams_ = 0, .equipped_beams_ = 0, .demo_obj = 0x9e9a },
    [5] = { .items = kItem_VariaSuit+kItem_MorphBall+kItem_HiJumpBoots+kItem_SpeedBooster+kItem_Grapple+kItem_Xray, .missiles = 45, .super_missiles = 5, .power_bombs = 5, .health = 399, .collected_beams_ = kBeam_Charge, .equipped_beams_ = kBeam_Charge, .demo_obj = 0x9e64 },
  },
  [2] = {
    [0] = { .items = kItem_VariaSuit+kItem_MorphBall+kItem_HiJumpBoots+kItem_SpeedBooster+kItem_Grapple+kItem_Xray, .missiles = 55, .super_missiles = 5, .power_bombs = 5, .health = 399, .collected_beams_ = kBeam_Charge, .equipped_beams_ = kBeam_Charge, .demo_obj = 0x9e70 },
    [1] = { .items = kItem_VariaSuit+kItem_SpringBall+kItem_MorphBall+kItem_ScrewAttack+0x10+kItem_GravitySuit+kItem_HiJumpBoots+kItem_SpaceJump+kItem_Bombs+kItem_SpeedBooster+kItem_Grapple+kItem_Xray, .missiles = 85, .super_missiles = 15, .power_bombs = 10, .health = 999, .collected_beams_ = kBeam_Wave+kBeam_Ice+kBeam_Spazer+kBeam_Plasma+kBeam_Charge, .equipped_beams_ = kBeam_Charge, .demo_obj = 0x9e82 },
    [2] = { .items = kItem_MorphBall+kItem_HiJumpBoots, .missiles = 25, .super_missiles = 5, .power_bombs = 0, .health = 299, .collected_beams_ = kBeam_Spazer+kBeam_Charge, .equipped_beams_ = kBeam_Spazer+kBeam_Charge, .demo_obj = 0x9e7c },
    [3] = { .items = kItem_VariaSuit+kItem_MorphBall+kItem_HiJumpBoots+kItem_SpeedBooster, .missiles = 30, .super_missiles = 5, .power_bombs = 0, .health = 299, .collected_beams_ = 0, .equipped_beams_ = 0, .demo_obj = 0x9e6a },
    [4] = { .items = kItem_MorphBall+kItem_HiJumpBoots, .missiles = 25, .super_missiles = 5, .power_bombs = 0, .health = 299, .collected_beams_ = 0, .equipped_beams_ = 0, .demo_obj = 0x9e8e },
    [5] = { .items = kItem_VariaSuit+kItem_MorphBall+kItem_HiJumpBoots+kItem_SpeedBooster, .missiles = 30, .super_missiles = 5, .power_bombs = 5, .health = 299, .collected_beams_ = kBeam_Plasma+kBeam_Charge, .equipped_beams_ = kBeam_Plasma+kBeam_Charge, .demo_obj = 0x9ed6 },
  },
  [3] = {
    [0] = { .items = kItem_VariaSuit+kItem_MorphBall+kItem_ScrewAttack+kItem_GravitySuit+kItem_HiJumpBoots+kItem_SpaceJump+kItem_Bombs+kItem_SpeedBooster+kItem_Grapple+kItem_Xray, .missiles = 85, .super_missiles = 15, .power_bombs = 10, .health = 999, .collected_beams_ = kBeam_Charge, .equipped_beams_ = kBeam_Charge, .demo_obj = 0x9ebe },
    [1] = { .items = kItem_VariaSuit+kItem_MorphBall+kItem_ScrewAttack+kItem_GravitySuit+kItem_HiJumpBoots+kItem_SpaceJump+kItem_Bombs+kItem_SpeedBooster+kItem_Grapple+kItem_Xray, .missiles = 85, .super_missiles = 15, .power_bombs = 10, .health = 999, .collected_beams_ = 0, .equipped_beams_ = 0, .demo_obj = 0x9ec4 },
    [2] = { .items = kItem_VariaSuit+kItem_MorphBall+kItem_ScrewAttack+kItem_GravitySuit+kItem_HiJumpBoots+kItem_SpaceJump+kItem_Bombs+kItem_SpeedBooster+kItem_Grapple+kItem_Xray, .missiles = 85, .super_missiles = 15, .power_bombs = 10, .health = 999, .collected_beams_ = 0, .equipped_beams_ = 0, .demo_obj = 0x9eca },
    [3] = { .items = kItem_VariaSuit+kItem_MorphBall+kItem_ScrewAttack+kItem_GravitySuit+kItem_HiJumpBoots+kItem_SpaceJump+kItem_Bombs+kItem_SpeedBooster+kItem_Grapple+kItem_Xray, .missiles = 85, .super_missiles = 15, .power_bombs = 10, .health = 999, .collected_beams_ = kBeam_Plasma+kBeam_Charge, .equipped_beams_ = kBeam_Plasma+kBeam_Charge, .demo_obj = 0x9ed0 },
    [4] = { .items = kItem_VariaSuit+kItem_MorphBall+kItem_ScrewAttack+kItem_GravitySuit+kItem_HiJumpBoots+kItem_SpaceJump+kItem_Bombs+kItem_SpeedBooster+kItem_Grapple+kItem_Xray, .missiles = 85, .super_missiles = 20, .power_bombs = 20, .health = 999, .collected_beams_ = kBeam_Charge, .equipped_beams_ = kBeam_Charge, .demo_obj = 0x9edc },
  },
};

DemoInputObject get_DemoInputObject(uint16 demo_obj) {
  switch(demo_obj) {
    case 0x877e: return (DemoInputObject){ .ptr = FUNC16(DemoPreInstr_nullsub_162), .pre_instr = FUNC16(DemoPreInstr_BabyMetroidDiscovery_RunLeft), .instr_ptr = 0x860d };
    case 0x8784: return (DemoInputObject){ .ptr = FUNC16(DemoPreInstr_nullsub_162), .pre_instr = FUNC16(DemoPreInstr_nullsub_162), .instr_ptr = 0x8694 };
    case 0x9e52: return (DemoInputObject){ .ptr = FUNC16(DemoPreInstr_nullsub_162), .pre_instr = FUNC16(DemoPreInstr_CheckLeaveDemo), .instr_ptr = 0x8ace };
    case 0x9e58: return (DemoInputObject){ .ptr = FUNC16(DemoPreInstr_nullsub_162), .pre_instr = FUNC16(DemoPreInstr_CheckLeaveDemo), .instr_ptr = 0x8c3e };
    case 0x9e5e: return (DemoInputObject){ .ptr = FUNC16(DemoPreInstr_nullsub_162), .pre_instr = FUNC16(DemoPreInstr_CheckLeaveDemo), .instr_ptr = 0x8df0 };
    case 0x9e64: return (DemoInputObject){ .ptr = FUNC16(DemoPreInstr_nullsub_162), .pre_instr = FUNC16(DemoPreInstr_CheckLeaveDemo), .instr_ptr = 0x8e64 };
    case 0x9e6a: return (DemoInputObject){ .ptr = FUNC16(DemoPreInstr_nullsub_162), .pre_instr = FUNC16(DemoPreInstr_CheckLeaveDemo), .instr_ptr = 0x8eb4 };
    case 0x9e70: return (DemoInputObject){ .ptr = FUNC16(DemoPreInstr_nullsub_162), .pre_instr = FUNC16(DemoPreInstr_CheckLeaveDemo), .instr_ptr = 0x8f3a };
    case 0x9e76: return (DemoInputObject){ .ptr = FUNC16(DemoPreInstr_nullsub_162), .pre_instr = FUNC16(DemoPreInstr_CheckLeaveDemo), .instr_ptr = 0x8fe4 };
    case 0x9e7c: return (DemoInputObject){ .ptr = FUNC16(DemoPreInstr_nullsub_162), .pre_instr = FUNC16(DemoPreInstr_CheckLeaveDemo), .instr_ptr = 0x9154 };
    case 0x9e82: return (DemoInputObject){ .ptr = FUNC16(DemoPreInstr_nullsub_162), .pre_instr = FUNC16(DemoPreInstr_CheckLeaveDemo_Shinespark), .instr_ptr = 0x933c };
    case 0x9e88: return (DemoInputObject){ .ptr = FUNC16(DemoPreInstr_nullsub_162), .pre_instr = FUNC16(DemoPreInstr_CheckLeaveDemo), .instr_ptr = 0x93cc };
    case 0x9e8e: return (DemoInputObject){ .ptr = FUNC16(DemoPreInstr_nullsub_162), .pre_instr = FUNC16(DemoPreInstr_CheckLeaveDemo), .instr_ptr = 0x9464 };
    case 0x9e94: return (DemoInputObject){ .ptr = FUNC16(DemoPreInstr_nullsub_162), .pre_instr = FUNC16(DemoPreInstr_CheckLeaveDemo), .instr_ptr = 0x946c };
    case 0x9e9a: return (DemoInputObject){ .ptr = FUNC16(DemoPreInstr_nullsub_162), .pre_instr = FUNC16(DemoPreInstr_CheckLeaveDemo), .instr_ptr = 0x950a };
    case 0x9ea0: return (DemoInputObject){ .ptr = FUNC16(DemoPreInstr_nullsub_162), .pre_instr = FUNC16(DemoPreInstr_CheckLeaveDemo), .instr_ptr = 0x9560 };
    case 0x9eac: return (DemoInputObject){ .ptr = FUNC16(DemoPreInstr_nullsub_162), .pre_instr = FUNC16(DemoPreInstr_CheckLeaveDemo), .instr_ptr = 0x965a };
    case 0x9eb2: return (DemoInputObject){ .ptr = FUNC16(DemoPreInstr_nullsub_162), .pre_instr = FUNC16(DemoPreInstr_CheckLeaveDemo), .instr_ptr = 0x973a };
    case 0x9eb8: return (DemoInputObject){ .ptr = FUNC16(DemoPreInstr_nullsub_162), .pre_instr = FUNC16(DemoPreInstr_CheckLeaveDemo), .instr_ptr = 0x989e };
    case 0x9ebe: return (DemoInputObject){ .ptr = FUNC16(DemoPreInstr_nullsub_162), .pre_instr = FUNC16(DemoPreInstr_CheckLeaveDemo), .instr_ptr = 0x99ae };
    case 0x9ec4: return (DemoInputObject){ .ptr = FUNC16(DemoPreInstr_nullsub_162), .pre_instr = FUNC16(DemoPreInstr_CheckLeaveDemo), .instr_ptr = 0x99c8 };
    case 0x9eca: return (DemoInputObject){ .ptr = FUNC16(DemoPreInstr_nullsub_162), .pre_instr = FUNC16(DemoPreInstr_CheckLeaveDemo), .instr_ptr = 0x9af0 };
    case 0x9ed0: return (DemoInputObject){ .ptr = FUNC16(DemoPreInstr_nullsub_162), .pre_instr = FUNC16(DemoPreInstr_CheckLeaveDemo), .instr_ptr = 0x9cd8 };
    case 0x9ed6: return (DemoInputObject){ .ptr = FUNC16(DemoPreInstr_nullsub_162), .pre_instr = FUNC16(DemoPreInstr_CheckLeaveDemo), .instr_ptr = 0x9da6 };
    case 0x9edc: return (DemoInputObject){ .ptr = FUNC16(DemoPreInstr_nullsub_162), .pre_instr = FUNC16(DemoPreInstr_CheckLeaveDemo), .instr_ptr = 0x9dae };
    default: return (DemoInputObject){ Unreachable() };
  }
}

DemoInputEntry get_DemoInputEntry(uint16 demo_input_) {
  switch(demo_input_) {
    case 0x860d: return (DemoInputEntry){ .timer =  90, .cur_input =                                              0, .new_input =                                0 };
    case 0x8613: return (DemoInputEntry){ .timer =   1, .cur_input =                                   kButton_Left, .new_input =                     kButton_Left };
    case 0x8619: return (DemoInputEntry){ .timer =   1, .cur_input =                                   kButton_Left, .new_input =                                0 };
    case 0x861f: return (DemoInputEntry){ .func_ptr = FUNC16(DemoInstr_Goto), .instr_list_ptr = 0x8619 };
    case 0x8623: return (DemoInputEntry){ .timer = 300, .cur_input =                                              0, .new_input =                                0 };
    case 0x8629: return (DemoInputEntry){ .timer =   1, .cur_input =                                      kButton_R, .new_input =                        kButton_R };
    case 0x862f: return (DemoInputEntry){ .timer = 170, .cur_input =                                      kButton_R, .new_input =                                0 };
    case 0x8635: return (DemoInputEntry){ .timer = 240, .cur_input =                                              0, .new_input =                                0 };
    case 0x863b: return (DemoInputEntry){ .timer =   1, .cur_input =                                   kButton_Left, .new_input =                     kButton_Left };
    case 0x8641: return (DemoInputEntry){ .timer =   1, .cur_input =                                   kButton_Left, .new_input =                                0 };
    case 0x8647: return (DemoInputEntry){ .func_ptr = FUNC16(DemoInstr_Goto), .instr_list_ptr = 0x8641 };
    case 0x864b: return (DemoInputEntry){ .func_ptr = FUNC16(DemoInstr_DisableDemo), .instr_list_ptr = 0x864d };
    case 0x864d: return (DemoInputEntry){ .func_ptr = FUNC16(DemoInstr_Finish), .instr_list_ptr = 0 };
    case 0x8694: return (DemoInputEntry){ .timer =  90, .cur_input =                                              0, .new_input =                                0 };
    case 0x869a: return (DemoInputEntry){ .timer =   1, .cur_input =                                      kButton_X, .new_input =                        kButton_X };
    case 0x86a0: return (DemoInputEntry){ .timer =  40, .cur_input =                                      kButton_X, .new_input =                                0 };
    case 0x86a6: return (DemoInputEntry){ .timer =   1, .cur_input =                                      kButton_X, .new_input =                        kButton_X };
    case 0x86ac: return (DemoInputEntry){ .timer =  29, .cur_input =                                      kButton_X, .new_input =                                0 };
    case 0x86b2: return (DemoInputEntry){ .timer =  70, .cur_input =                                              0, .new_input =                                0 };
    case 0x86b8: return (DemoInputEntry){ .timer =  20, .cur_input =                                              0, .new_input =                                0 };
    case 0x86be: return (DemoInputEntry){ .timer =   1, .cur_input =                                   kButton_Left, .new_input =                     kButton_Left };
    case 0x86c4: return (DemoInputEntry){ .timer =   7, .cur_input =                                   kButton_Left, .new_input =                                0 };
    case 0x86ca: return (DemoInputEntry){ .timer =   1, .cur_input =                         kButton_A+kButton_Left, .new_input =                        kButton_A };
    case 0x86d0: return (DemoInputEntry){ .timer =   7, .cur_input =                         kButton_A+kButton_Left, .new_input =                                0 };
    case 0x86d6: return (DemoInputEntry){ .timer =   4, .cur_input =                                   kButton_Left, .new_input =                                0 };
    case 0x86dc: return (DemoInputEntry){ .timer =  60, .cur_input =                                              0, .new_input =                                0 };
    case 0x86e2: return (DemoInputEntry){ .timer =   1, .cur_input =                                      kButton_X, .new_input =                        kButton_X };
    case 0x86e8: return (DemoInputEntry){ .timer =  40, .cur_input =                                      kButton_X, .new_input =                                0 };
    case 0x86ee: return (DemoInputEntry){ .timer =   1, .cur_input =                                      kButton_X, .new_input =                        kButton_X };
    case 0x86f4: return (DemoInputEntry){ .timer =  19, .cur_input =                                      kButton_X, .new_input =                                0 };
    case 0x86fa: return (DemoInputEntry){ .func_ptr = FUNC16(DemoInstr_FaceSamusLeftAndDisableDemo), .instr_list_ptr = 0x86fc };
    case 0x86fc: return (DemoInputEntry){ .func_ptr = FUNC16(DemoInstr_Finish), .instr_list_ptr = 0 };
    case 0x8776: return (DemoInputEntry){ .func_ptr = FUNC16(DemoInstr_Finish), .instr_list_ptr = 0 };
    case 0x8ace: return (DemoInputEntry){ .timer = 289, .cur_input =                                              0, .new_input =                                0 };
    case 0x8ad4: return (DemoInputEntry){ .timer =   1, .cur_input =                                   kButton_Left, .new_input =                     kButton_Left };
    case 0x8ada: return (DemoInputEntry){ .timer =   6, .cur_input =                                   kButton_Left, .new_input =                                0 };
    case 0x8ae0: return (DemoInputEntry){ .timer =   1, .cur_input =                        kButton_Left+kButton_Up, .new_input =                       kButton_Up };
    case 0x8ae6: return (DemoInputEntry){ .timer =   3, .cur_input =                        kButton_Left+kButton_Up, .new_input =                                0 };
    case 0x8aec: return (DemoInputEntry){ .timer =  19, .cur_input =                                   kButton_Left, .new_input =                                0 };
    case 0x8af2: return (DemoInputEntry){ .timer =   1, .cur_input =                         kButton_A+kButton_Left, .new_input =                        kButton_A };
    case 0x8af8: return (DemoInputEntry){ .timer =  40, .cur_input =                         kButton_A+kButton_Left, .new_input =                                0 };
    case 0x8afe: return (DemoInputEntry){ .timer =  50, .cur_input =                                   kButton_Left, .new_input =                                0 };
    case 0x8b04: return (DemoInputEntry){ .timer =  36, .cur_input =                                              0, .new_input =                                0 };
    case 0x8b0a: return (DemoInputEntry){ .timer =   1, .cur_input =                                  kButton_Right, .new_input =                    kButton_Right };
    case 0x8b10: return (DemoInputEntry){ .timer =   5, .cur_input =                                  kButton_Right, .new_input =                                0 };
    case 0x8b16: return (DemoInputEntry){ .timer =  15, .cur_input =                                              0, .new_input =                                0 };
    case 0x8b1c: return (DemoInputEntry){ .timer =   1, .cur_input =                                   kButton_Left, .new_input =                     kButton_Left };
    case 0x8b22: return (DemoInputEntry){ .timer =   5, .cur_input =                                   kButton_Left, .new_input =                                0 };
    case 0x8b28: return (DemoInputEntry){ .timer =  34, .cur_input =                                              0, .new_input =                                0 };
    case 0x8b2e: return (DemoInputEntry){ .timer =   1, .cur_input =                                   kButton_Left, .new_input =                     kButton_Left };
    case 0x8b34: return (DemoInputEntry){ .timer =  74, .cur_input =                                   kButton_Left, .new_input =                                0 };
    case 0x8b3a: return (DemoInputEntry){ .timer =   5, .cur_input =                                              0, .new_input =                                0 };
    case 0x8b40: return (DemoInputEntry){ .timer =   1, .cur_input =                                  kButton_Right, .new_input =                    kButton_Right };
    case 0x8b46: return (DemoInputEntry){ .timer =   5, .cur_input =                                  kButton_Right, .new_input =                                0 };
    case 0x8b4c: return (DemoInputEntry){ .timer =  69, .cur_input =                                              0, .new_input =                                0 };
    case 0x8b52: return (DemoInputEntry){ .timer =   1, .cur_input =                                   kButton_Left, .new_input =                     kButton_Left };
    case 0x8b58: return (DemoInputEntry){ .timer =   3, .cur_input =                                   kButton_Left, .new_input =                                0 };
    case 0x8b5e: return (DemoInputEntry){ .timer =   1, .cur_input =                         kButton_Left+kButton_B, .new_input =                        kButton_B };
    case 0x8b64: return (DemoInputEntry){ .timer =  73, .cur_input =                         kButton_Left+kButton_B, .new_input =                                0 };
    case 0x8b6a: return (DemoInputEntry){ .timer =   1, .cur_input =              kButton_Left+kButton_Up+kButton_B, .new_input =                       kButton_Up };
    case 0x8b70: return (DemoInputEntry){ .timer =   3, .cur_input =              kButton_Left+kButton_Up+kButton_B, .new_input =                                0 };
    case 0x8b76: return (DemoInputEntry){ .timer =   1, .cur_input =                                   kButton_Left, .new_input =                                0 };
    case 0x8b7c: return (DemoInputEntry){ .timer =   2, .cur_input =                                              0, .new_input =                                0 };
    case 0x8b82: return (DemoInputEntry){ .timer =   1, .cur_input =                                  kButton_Right, .new_input =                    kButton_Right };
    case 0x8b88: return (DemoInputEntry){ .timer =   7, .cur_input =                                  kButton_Right, .new_input =                                0 };
    case 0x8b8e: return (DemoInputEntry){ .timer =  11, .cur_input =                                              0, .new_input =                                0 };
    case 0x8b94: return (DemoInputEntry){ .timer =   1, .cur_input =                                      kButton_R, .new_input =                        kButton_R };
    case 0x8b9a: return (DemoInputEntry){ .timer =  31, .cur_input =                                      kButton_R, .new_input =                                0 };
    case 0x8ba0: return (DemoInputEntry){ .timer =   1, .cur_input =                         kButton_R+kButton_Left, .new_input =                     kButton_Left };
    case 0x8ba6: return (DemoInputEntry){ .timer =   5, .cur_input =                         kButton_R+kButton_Left, .new_input =                                0 };
    case 0x8bac: return (DemoInputEntry){ .timer =  29, .cur_input =                                      kButton_R, .new_input =                                0 };
    case 0x8bb2: return (DemoInputEntry){ .timer =   1, .cur_input =                                   kButton_Left, .new_input =                     kButton_Left };
    case 0x8bb8: return (DemoInputEntry){ .timer =  94, .cur_input =                                   kButton_Left, .new_input =                                0 };
    case 0x8bbe: return (DemoInputEntry){ .timer =  48, .cur_input =                                              0, .new_input =                                0 };
    case 0x8bc4: return (DemoInputEntry){ .timer =   1, .cur_input =                                   kButton_Left, .new_input =                     kButton_Left };
    case 0x8bca: return (DemoInputEntry){ .timer =  46, .cur_input =                                   kButton_Left, .new_input =                                0 };
    case 0x8bd0: return (DemoInputEntry){ .timer =  31, .cur_input =                                              0, .new_input =                                0 };
    case 0x8bd6: return (DemoInputEntry){ .timer =   1, .cur_input =                                  kButton_Right, .new_input =                    kButton_Right };
    case 0x8bdc: return (DemoInputEntry){ .timer =   4, .cur_input =                                  kButton_Right, .new_input =                                0 };
    case 0x8be2: return (DemoInputEntry){ .timer =  64, .cur_input =                                              0, .new_input =                                0 };
    case 0x8be8: return (DemoInputEntry){ .timer =   1, .cur_input =                                   kButton_Left, .new_input =                     kButton_Left };
    case 0x8bee: return (DemoInputEntry){ .timer =   4, .cur_input =                                   kButton_Left, .new_input =                                0 };
    case 0x8bf4: return (DemoInputEntry){ .timer =  40, .cur_input =                                              0, .new_input =                                0 };
    case 0x8bfa: return (DemoInputEntry){ .timer =   1, .cur_input =                                      kButton_X, .new_input =                        kButton_X };
    case 0x8c00: return (DemoInputEntry){ .timer =   6, .cur_input =                                      kButton_X, .new_input =                                0 };
    case 0x8c06: return (DemoInputEntry){ .timer =  43, .cur_input =                                              0, .new_input =                                0 };
    case 0x8c0c: return (DemoInputEntry){ .timer =   1, .cur_input =                                   kButton_Left, .new_input =                     kButton_Left };
    case 0x8c12: return (DemoInputEntry){ .timer =  17, .cur_input =                                   kButton_Left, .new_input =                                0 };
    case 0x8c18: return (DemoInputEntry){ .timer =   7, .cur_input =                                              0, .new_input =                                0 };
    case 0x8c1e: return (DemoInputEntry){ .timer =   1, .cur_input =                                   kButton_Left, .new_input =                     kButton_Left };
    case 0x8c24: return (DemoInputEntry){ .timer =   4, .cur_input =                                   kButton_Left, .new_input =                                0 };
    case 0x8c2a: return (DemoInputEntry){ .timer =  20, .cur_input =                                  kButton_Right, .new_input =                                0 };
    case 0x8c30: return (DemoInputEntry){ .timer =   1, .cur_input =                        kButton_X+kButton_Right, .new_input =                        kButton_X };
    case 0x8c36: return (DemoInputEntry){ .timer =   3, .cur_input =                        kButton_X+kButton_Right, .new_input =                                0 };
    case 0x8c3c: return (DemoInputEntry){ .func_ptr = FUNC16(DemoInstr_Finish), .instr_list_ptr = 0 };
    case 0x8c3e: return (DemoInputEntry){ .timer =  22, .cur_input =                                              0, .new_input =                                0 };
    case 0x8c44: return (DemoInputEntry){ .timer =   1, .cur_input =                                     kButton_Up, .new_input =                       kButton_Up };
    case 0x8c4a: return (DemoInputEntry){ .timer =   3, .cur_input =                                     kButton_Up, .new_input =                                0 };
    case 0x8c50: return (DemoInputEntry){ .timer =   5, .cur_input =                                              0, .new_input =                                0 };
    case 0x8c56: return (DemoInputEntry){ .timer =   1, .cur_input =                                     kButton_Up, .new_input =                       kButton_Up };
    case 0x8c5c: return (DemoInputEntry){ .timer =   6, .cur_input =                                     kButton_Up, .new_input =                                0 };
    case 0x8c62: return (DemoInputEntry){ .timer =  22, .cur_input =                                              0, .new_input =                                0 };
    case 0x8c68: return (DemoInputEntry){ .timer =   1, .cur_input =                                   kButton_Left, .new_input =                     kButton_Left };
    case 0x8c6e: return (DemoInputEntry){ .timer =   5, .cur_input =                                   kButton_Left, .new_input =                                0 };
    case 0x8c74: return (DemoInputEntry){ .timer =  11, .cur_input =                                              0, .new_input =                                0 };
    case 0x8c7a: return (DemoInputEntry){ .timer =   1, .cur_input =                                      kButton_X, .new_input =                        kButton_X };
    case 0x8c80: return (DemoInputEntry){ .timer =  78, .cur_input =                                      kButton_X, .new_input =                                0 };
    case 0x8c86: return (DemoInputEntry){ .timer =   1, .cur_input =                         kButton_X+kButton_Left, .new_input =                     kButton_Left };
    case 0x8c8c: return (DemoInputEntry){ .timer =  13, .cur_input =                         kButton_X+kButton_Left, .new_input =                                0 };
    case 0x8c92: return (DemoInputEntry){ .timer =   1, .cur_input =               kButton_X+kButton_A+kButton_Left, .new_input =                        kButton_A };
    case 0x8c98: return (DemoInputEntry){ .timer =  20, .cur_input =               kButton_X+kButton_A+kButton_Left, .new_input =                                0 };
    case 0x8c9e: return (DemoInputEntry){ .timer =  20, .cur_input =                         kButton_X+kButton_Left, .new_input =                                0 };
    case 0x8ca4: return (DemoInputEntry){ .timer =  32, .cur_input =                                      kButton_X, .new_input =                                0 };
    case 0x8caa: return (DemoInputEntry){ .timer =   1, .cur_input =                        kButton_X+kButton_Right, .new_input =                    kButton_Right };
    case 0x8cb0: return (DemoInputEntry){ .timer =  15, .cur_input =                        kButton_X+kButton_Right, .new_input =                                0 };
    case 0x8cb6: return (DemoInputEntry){ .timer =   1, .cur_input =              kButton_X+kButton_A+kButton_Right, .new_input =                        kButton_A };
    case 0x8cbc: return (DemoInputEntry){ .timer =   6, .cur_input =              kButton_X+kButton_A+kButton_Right, .new_input =                                0 };
    case 0x8cc2: return (DemoInputEntry){ .timer =   2, .cur_input =                            kButton_X+kButton_A, .new_input =                                0 };
    case 0x8cc8: return (DemoInputEntry){ .timer =   1, .cur_input =               kButton_X+kButton_A+kButton_Left, .new_input =                     kButton_Left };
    case 0x8cce: return (DemoInputEntry){ .timer =  30, .cur_input =               kButton_X+kButton_A+kButton_Left, .new_input =                                0 };
    case 0x8cd4: return (DemoInputEntry){ .timer =   8, .cur_input =                         kButton_X+kButton_Left, .new_input =                                0 };
    case 0x8cda: return (DemoInputEntry){ .timer =   6, .cur_input =                                      kButton_X, .new_input =                                0 };
    case 0x8ce0: return (DemoInputEntry){ .timer =   1, .cur_input =                        kButton_X+kButton_Right, .new_input =                    kButton_Right };
    case 0x8ce6: return (DemoInputEntry){ .timer =  11, .cur_input =                        kButton_X+kButton_Right, .new_input =                                0 };
    case 0x8cec: return (DemoInputEntry){ .timer =   1, .cur_input =              kButton_X+kButton_A+kButton_Right, .new_input =                        kButton_A };
    case 0x8cf2: return (DemoInputEntry){ .timer =  35, .cur_input =              kButton_X+kButton_A+kButton_Right, .new_input =                                0 };
    case 0x8cf8: return (DemoInputEntry){ .timer =  58, .cur_input =                        kButton_X+kButton_Right, .new_input =                                0 };
    case 0x8cfe: return (DemoInputEntry){ .timer =   1, .cur_input =              kButton_X+kButton_A+kButton_Right, .new_input =                        kButton_A };
    case 0x8d04: return (DemoInputEntry){ .timer =  19, .cur_input =              kButton_X+kButton_A+kButton_Right, .new_input =                                0 };
    case 0x8d0a: return (DemoInputEntry){ .timer =   1, .cur_input =   kButton_X+kButton_A+kButton_Right+kButton_Up, .new_input =                       kButton_Up };
    case 0x8d10: return (DemoInputEntry){ .timer =   2, .cur_input =              kButton_X+kButton_A+kButton_Right, .new_input =                                0 };
    case 0x8d16: return (DemoInputEntry){ .timer =   8, .cur_input =                            kButton_X+kButton_A, .new_input =                                0 };
    case 0x8d1c: return (DemoInputEntry){ .timer =  13, .cur_input =                                      kButton_X, .new_input =                                0 };
    case 0x8d22: return (DemoInputEntry){ .timer =   1, .cur_input =                         kButton_X+kButton_Left, .new_input =                     kButton_Left };
    case 0x8d28: return (DemoInputEntry){ .timer =  41, .cur_input =                         kButton_X+kButton_Left, .new_input =                                0 };
    case 0x8d2e: return (DemoInputEntry){ .timer =   1, .cur_input =               kButton_X+kButton_A+kButton_Left, .new_input =                        kButton_A };
    case 0x8d34: return (DemoInputEntry){ .timer =   7, .cur_input =               kButton_X+kButton_A+kButton_Left, .new_input =                                0 };
    case 0x8d3a: return (DemoInputEntry){ .timer =   1, .cur_input =    kButton_X+kButton_A+kButton_Left+kButton_Up, .new_input =                       kButton_Up };
    case 0x8d40: return (DemoInputEntry){ .timer =   2, .cur_input =    kButton_X+kButton_A+kButton_Left+kButton_Up, .new_input =                                0 };
    case 0x8d46: return (DemoInputEntry){ .timer =   1, .cur_input =                 kButton_X+kButton_A+kButton_Up, .new_input =                                0 };
    case 0x8d4c: return (DemoInputEntry){ .timer =   1, .cur_input =              kButton_X+kButton_A+kButton_Right, .new_input =                    kButton_Right };
    case 0x8d52: return (DemoInputEntry){ .timer =  40, .cur_input =              kButton_X+kButton_A+kButton_Right, .new_input =                                0 };
    case 0x8d58: return (DemoInputEntry){ .timer =  16, .cur_input =                        kButton_X+kButton_Right, .new_input =                                0 };
    case 0x8d5e: return (DemoInputEntry){ .timer =   6, .cur_input =                                      kButton_X, .new_input =                                0 };
    case 0x8d64: return (DemoInputEntry){ .timer =   1, .cur_input =                            kButton_X+kButton_A, .new_input =                        kButton_A };
    case 0x8d6a: return (DemoInputEntry){ .timer =   4, .cur_input =                            kButton_X+kButton_A, .new_input =                                0 };
    case 0x8d70: return (DemoInputEntry){ .timer =   1, .cur_input =                  kButton_L+kButton_X+kButton_A, .new_input =                        kButton_L };
    case 0x8d76: return (DemoInputEntry){ .timer =  18, .cur_input =                  kButton_L+kButton_X+kButton_A, .new_input =                                0 };
    case 0x8d7c: return (DemoInputEntry){ .timer =  42, .cur_input =                                      kButton_L, .new_input =                                0 };
    case 0x8d82: return (DemoInputEntry){ .timer =   1, .cur_input =                        kButton_L+kButton_Right, .new_input =                    kButton_Right };
    case 0x8d88: return (DemoInputEntry){ .timer =   2, .cur_input =                        kButton_L+kButton_Right, .new_input =                                0 };
    case 0x8d8e: return (DemoInputEntry){ .timer =   5, .cur_input =                                  kButton_Right, .new_input =                                0 };
    case 0x8d94: return (DemoInputEntry){ .timer =   8, .cur_input =                                              0, .new_input =                                0 };
    case 0x8d9a: return (DemoInputEntry){ .timer =   1, .cur_input =                                  kButton_Right, .new_input =                    kButton_Right };
    case 0x8da0: return (DemoInputEntry){ .timer =  17, .cur_input =                                  kButton_Right, .new_input =                                0 };
    case 0x8da6: return (DemoInputEntry){ .timer =   1, .cur_input =                        kButton_A+kButton_Right, .new_input =                        kButton_A };
    case 0x8dac: return (DemoInputEntry){ .timer =  15, .cur_input =                        kButton_A+kButton_Right, .new_input =                                0 };
    case 0x8db2: return (DemoInputEntry){ .timer =  19, .cur_input =                                  kButton_Right, .new_input =                                0 };
    case 0x8db8: return (DemoInputEntry){ .timer =   1, .cur_input =                        kButton_Right+kButton_B, .new_input =                        kButton_B };
    case 0x8dbe: return (DemoInputEntry){ .timer =  41, .cur_input =                        kButton_Right+kButton_B, .new_input =                                0 };
    case 0x8dc4: return (DemoInputEntry){ .timer =   1, .cur_input =              kButton_A+kButton_Right+kButton_B, .new_input =                        kButton_A };
    case 0x8dca: return (DemoInputEntry){ .timer =  32, .cur_input =              kButton_A+kButton_Right+kButton_B, .new_input =                                0 };
    case 0x8dd0: return (DemoInputEntry){ .timer =   5, .cur_input =                            kButton_A+kButton_B, .new_input =                                0 };
    case 0x8dd6: return (DemoInputEntry){ .timer =   6, .cur_input =                                      kButton_B, .new_input =                                0 };
    case 0x8ddc: return (DemoInputEntry){ .timer =   1, .cur_input =                                   kButton_Left, .new_input =                     kButton_Left };
    case 0x8de2: return (DemoInputEntry){ .timer =  15, .cur_input =                                   kButton_Left, .new_input =                                0 };
    case 0x8de8: return (DemoInputEntry){ .timer = 101, .cur_input =                                              0, .new_input =                                0 };
    case 0x8dee: return (DemoInputEntry){ .func_ptr = FUNC16(DemoInstr_Finish), .instr_list_ptr = 0 };
    case 0x8df0: return (DemoInputEntry){ .timer =  32, .cur_input =                                              0, .new_input =                                0 };
    case 0x8df6: return (DemoInputEntry){ .timer =   1, .cur_input =                                   kButton_Left, .new_input =                     kButton_Left };
    case 0x8dfc: return (DemoInputEntry){ .timer =   2, .cur_input =                                   kButton_Left, .new_input =                                0 };
    case 0x8e02: return (DemoInputEntry){ .timer =   1, .cur_input =                         kButton_Left+kButton_B, .new_input =                        kButton_B };
    case 0x8e08: return (DemoInputEntry){ .timer = 238, .cur_input =                         kButton_Left+kButton_B, .new_input =                                0 };
    case 0x8e0e: return (DemoInputEntry){ .timer =   1, .cur_input =              kButton_Left+kButton_Up+kButton_B, .new_input =                       kButton_Up };
    case 0x8e14: return (DemoInputEntry){ .timer =   2, .cur_input =                         kButton_Left+kButton_B, .new_input =                                0 };
    case 0x8e1a: return (DemoInputEntry){ .timer =   1, .cur_input =                        kButton_Right+kButton_B, .new_input =                    kButton_Right };
    case 0x8e20: return (DemoInputEntry){ .timer =  22, .cur_input =                                  kButton_Right, .new_input =                                0 };
    case 0x8e26: return (DemoInputEntry){ .timer =  49, .cur_input =                                              0, .new_input =                                0 };
    case 0x8e2c: return (DemoInputEntry){ .timer =   1, .cur_input =                                   kButton_Left, .new_input =                     kButton_Left };
    case 0x8e32: return (DemoInputEntry){ .timer =   5, .cur_input =                                   kButton_Left, .new_input =                                0 };
    case 0x8e38: return (DemoInputEntry){ .timer =  19, .cur_input =                                              0, .new_input =                                0 };
    case 0x8e3e: return (DemoInputEntry){ .timer =   1, .cur_input =                                      kButton_X, .new_input =                        kButton_X };
    case 0x8e44: return (DemoInputEntry){ .timer =   8, .cur_input =                                      kButton_X, .new_input =                                0 };
    case 0x8e4a: return (DemoInputEntry){ .timer =  17, .cur_input =                                              0, .new_input =                                0 };
    case 0x8e50: return (DemoInputEntry){ .timer =   1, .cur_input =                                   kButton_Left, .new_input =                     kButton_Left };
    case 0x8e56: return (DemoInputEntry){ .timer =  27, .cur_input =                                   kButton_Left, .new_input =                                0 };
    case 0x8e5c: return (DemoInputEntry){ .timer =  99, .cur_input =                                              0, .new_input =                                0 };
    case 0x8e62: return (DemoInputEntry){ .func_ptr = FUNC16(DemoInstr_Finish), .instr_list_ptr = 0 };
    case 0x8e64: return (DemoInputEntry){ .timer =   8, .cur_input =                                              0, .new_input =                                0 };
    case 0x8e6a: return (DemoInputEntry){ .timer =   1, .cur_input =                                   kButton_Left, .new_input =                     kButton_Left };
    case 0x8e70: return (DemoInputEntry){ .timer =   1, .cur_input =                                   kButton_Left, .new_input =                                0 };
    case 0x8e76: return (DemoInputEntry){ .timer = 266, .cur_input =                                              0, .new_input =                                0 };
    case 0x8e7c: return (DemoInputEntry){ .timer =   1, .cur_input =                                  kButton_Right, .new_input =                    kButton_Right };
    case 0x8e82: return (DemoInputEntry){ .timer =   4, .cur_input =                                  kButton_Right, .new_input =                                0 };
    case 0x8e88: return (DemoInputEntry){ .timer =  17, .cur_input =                                              0, .new_input =                                0 };
    case 0x8e8e: return (DemoInputEntry){ .timer =   1, .cur_input =                                   kButton_Left, .new_input =                     kButton_Left };
    case 0x8e94: return (DemoInputEntry){ .timer =   4, .cur_input =                                   kButton_Left, .new_input =                                0 };
    case 0x8e9a: return (DemoInputEntry){ .timer =  56, .cur_input =                                              0, .new_input =                                0 };
    case 0x8ea0: return (DemoInputEntry){ .timer =   1, .cur_input =                                   kButton_Left, .new_input =                     kButton_Left };
    case 0x8ea6: return (DemoInputEntry){ .timer = 356, .cur_input =                                   kButton_Left, .new_input =                                0 };
    case 0x8eac: return (DemoInputEntry){ .timer = 286, .cur_input =                                              0, .new_input =                                0 };
    case 0x8eb2: return (DemoInputEntry){ .func_ptr = FUNC16(DemoInstr_Finish), .instr_list_ptr = 0 };
    case 0x8eb4: return (DemoInputEntry){ .timer =  90, .cur_input =                                              0, .new_input =                                0 };
    case 0x8eba: return (DemoInputEntry){ .timer =   1, .cur_input =                                  kButton_Right, .new_input =                    kButton_Right };
    case 0x8ec0: return (DemoInputEntry){ .timer =  10, .cur_input =                                  kButton_Right, .new_input =                                0 };
    case 0x8ec6: return (DemoInputEntry){ .timer =   1, .cur_input =                        kButton_A+kButton_Right, .new_input =                        kButton_A };
    case 0x8ecc: return (DemoInputEntry){ .timer =   6, .cur_input =                        kButton_A+kButton_Right, .new_input =                                0 };
    case 0x8ed2: return (DemoInputEntry){ .timer =  17, .cur_input =                                  kButton_Right, .new_input =                                0 };
    case 0x8ed8: return (DemoInputEntry){ .timer =  32, .cur_input =                                              0, .new_input =                                0 };
    case 0x8ede: return (DemoInputEntry){ .timer =   1, .cur_input =                                   kButton_Left, .new_input =                     kButton_Left };
    case 0x8ee4: return (DemoInputEntry){ .timer =   1, .cur_input =                                   kButton_Left, .new_input =                                0 };
    case 0x8eea: return (DemoInputEntry){ .timer =   1, .cur_input =                         kButton_A+kButton_Left, .new_input =                        kButton_A };
    case 0x8ef0: return (DemoInputEntry){ .timer =  20, .cur_input =                         kButton_A+kButton_Left, .new_input =                                0 };
    case 0x8ef6: return (DemoInputEntry){ .timer =   3, .cur_input =                                   kButton_Left, .new_input =                                0 };
    case 0x8efc: return (DemoInputEntry){ .timer =  20, .cur_input =                                              0, .new_input =                                0 };
    case 0x8f02: return (DemoInputEntry){ .timer =   1, .cur_input =                                  kButton_Right, .new_input =                    kButton_Right };
    case 0x8f08: return (DemoInputEntry){ .timer =   4, .cur_input =                                  kButton_Right, .new_input =                                0 };
    case 0x8f0e: return (DemoInputEntry){ .timer =  72, .cur_input =                                              0, .new_input =                                0 };
    case 0x8f14: return (DemoInputEntry){ .timer =   1, .cur_input =                                      kButton_A, .new_input =                        kButton_A };
    case 0x8f1a: return (DemoInputEntry){ .timer =  17, .cur_input =                                      kButton_A, .new_input =                                0 };
    case 0x8f20: return (DemoInputEntry){ .timer =   1, .cur_input =                        kButton_A+kButton_Right, .new_input =                    kButton_Right };
    case 0x8f26: return (DemoInputEntry){ .timer =  10, .cur_input =                        kButton_A+kButton_Right, .new_input =                                0 };
    case 0x8f2c: return (DemoInputEntry){ .timer =  22, .cur_input =                                  kButton_Right, .new_input =                                0 };
    case 0x8f32: return (DemoInputEntry){ .timer = 512, .cur_input =                                              0, .new_input =                                0 };
    case 0x8f38: return (DemoInputEntry){ .func_ptr = FUNC16(DemoInstr_Finish), .instr_list_ptr = 0 };
    case 0x8f3a: return (DemoInputEntry){ .timer =  61, .cur_input =                                              0, .new_input =                                0 };
    case 0x8f40: return (DemoInputEntry){ .timer =   1, .cur_input =                                  kButton_Right, .new_input =                    kButton_Right };
    case 0x8f46: return (DemoInputEntry){ .timer =   5, .cur_input =                                  kButton_Right, .new_input =                                0 };
    case 0x8f4c: return (DemoInputEntry){ .timer =  15, .cur_input =                                              0, .new_input =                                0 };
    case 0x8f52: return (DemoInputEntry){ .timer =   1, .cur_input =                                   kButton_Left, .new_input =                     kButton_Left };
    case 0x8f58: return (DemoInputEntry){ .timer =   5, .cur_input =                                   kButton_Left, .new_input =                                0 };
    case 0x8f5e: return (DemoInputEntry){ .timer =  39, .cur_input =                                              0, .new_input =                                0 };
    case 0x8f64: return (DemoInputEntry){ .timer =   1, .cur_input =                                   kButton_Left, .new_input =                     kButton_Left };
    case 0x8f6a: return (DemoInputEntry){ .timer = 102, .cur_input =                                   kButton_Left, .new_input =                                0 };
    case 0x8f70: return (DemoInputEntry){ .timer =   1, .cur_input =                         kButton_Left+kButton_B, .new_input =                        kButton_B };
    case 0x8f76: return (DemoInputEntry){ .timer =   7, .cur_input =                         kButton_Left+kButton_B, .new_input =                                0 };
    case 0x8f7c: return (DemoInputEntry){ .timer =  79, .cur_input =                                   kButton_Left, .new_input =                                0 };
    case 0x8f82: return (DemoInputEntry){ .timer =  87, .cur_input =                                              0, .new_input =                                0 };
    case 0x8f88: return (DemoInputEntry){ .timer =   1, .cur_input =                                  kButton_Right, .new_input =                    kButton_Right };
    case 0x8f8e: return (DemoInputEntry){ .timer =   2, .cur_input =                                  kButton_Right, .new_input =                                0 };
    case 0x8f94: return (DemoInputEntry){ .timer = 100, .cur_input =                                              0, .new_input =                                0 };
    case 0x8f9a: return (DemoInputEntry){ .timer =   1, .cur_input =                                  kButton_Right, .new_input =                    kButton_Right };
    case 0x8fa0: return (DemoInputEntry){ .timer =  78, .cur_input =                                  kButton_Right, .new_input =                                0 };
    case 0x8fa6: return (DemoInputEntry){ .timer =   1, .cur_input =                        kButton_Right+kButton_B, .new_input =                        kButton_B };
    case 0x8fac: return (DemoInputEntry){ .timer =  23, .cur_input =                        kButton_Right+kButton_B, .new_input =                                0 };
    case 0x8fb2: return (DemoInputEntry){ .timer =   6, .cur_input =                                  kButton_Right, .new_input =                                0 };
    case 0x8fb8: return (DemoInputEntry){ .timer =   1, .cur_input =                        kButton_Right+kButton_B, .new_input =                        kButton_B };
    case 0x8fbe: return (DemoInputEntry){ .timer =   3, .cur_input =                        kButton_Right+kButton_B, .new_input =                                0 };
    case 0x8fc4: return (DemoInputEntry){ .timer =   1, .cur_input =                                  kButton_Right, .new_input =                                0 };
    case 0x8fca: return (DemoInputEntry){ .timer =   1, .cur_input =                        kButton_Right+kButton_B, .new_input =                        kButton_B };
    case 0x8fd0: return (DemoInputEntry){ .timer =   2, .cur_input =                        kButton_Right+kButton_B, .new_input =                                0 };
    case 0x8fd6: return (DemoInputEntry){ .timer =  52, .cur_input =                                  kButton_Right, .new_input =                                0 };
    case 0x8fdc: return (DemoInputEntry){ .timer = 169, .cur_input =                                              0, .new_input =                                0 };
    case 0x8fe2: return (DemoInputEntry){ .func_ptr = FUNC16(DemoInstr_Finish), .instr_list_ptr = 0 };
    case 0x8fe4: return (DemoInputEntry){ .timer =  19, .cur_input =                                              0, .new_input =                                0 };
    case 0x8fea: return (DemoInputEntry){ .timer =   1, .cur_input =                                   kButton_Left, .new_input =                     kButton_Left };
    case 0x8ff0: return (DemoInputEntry){ .timer =  18, .cur_input =                                   kButton_Left, .new_input =                                0 };
    case 0x8ff6: return (DemoInputEntry){ .timer =  41, .cur_input =                                              0, .new_input =                                0 };
    case 0x8ffc: return (DemoInputEntry){ .timer =   1, .cur_input =                                      kButton_B, .new_input =                        kButton_B };
    case 0x9002: return (DemoInputEntry){ .timer =  21, .cur_input =                                      kButton_B, .new_input =                                0 };
    case 0x9008: return (DemoInputEntry){ .timer =  11, .cur_input =                                              0, .new_input =                                0 };
    case 0x900e: return (DemoInputEntry){ .timer =   1, .cur_input =                                      kButton_B, .new_input =                        kButton_B };
    case 0x9014: return (DemoInputEntry){ .timer =  31, .cur_input =                                      kButton_B, .new_input =                                0 };
    case 0x901a: return (DemoInputEntry){ .timer =   1, .cur_input =                         kButton_Left+kButton_B, .new_input =                     kButton_Left };
    case 0x9020: return (DemoInputEntry){ .timer =  48, .cur_input =                         kButton_Left+kButton_B, .new_input =                                0 };
    case 0x9026: return (DemoInputEntry){ .timer =   3, .cur_input =                                      kButton_B, .new_input =                                0 };
    case 0x902c: return (DemoInputEntry){ .timer =   1, .cur_input =                         kButton_Left+kButton_B, .new_input =                     kButton_Left };
    case 0x9032: return (DemoInputEntry){ .timer =   7, .cur_input =                         kButton_Left+kButton_B, .new_input =                                0 };
    case 0x9038: return (DemoInputEntry){ .timer =  69, .cur_input =                                      kButton_B, .new_input =                                0 };
    case 0x903e: return (DemoInputEntry){ .timer =   1, .cur_input =                         kButton_Left+kButton_B, .new_input =                     kButton_Left };
    case 0x9044: return (DemoInputEntry){ .timer = 145, .cur_input =                         kButton_Left+kButton_B, .new_input =                                0 };
    case 0x904a: return (DemoInputEntry){ .timer =  10, .cur_input =                                      kButton_B, .new_input =                                0 };
    case 0x9050: return (DemoInputEntry){ .timer =   1, .cur_input =                         kButton_Left+kButton_B, .new_input =                     kButton_Left };
    case 0x9056: return (DemoInputEntry){ .timer =   6, .cur_input =                         kButton_Left+kButton_B, .new_input =                                0 };
    case 0x905c: return (DemoInputEntry){ .timer =  54, .cur_input =                                      kButton_B, .new_input =                                0 };
    case 0x9062: return (DemoInputEntry){ .timer =   1, .cur_input =                         kButton_Left+kButton_B, .new_input =                     kButton_Left };
    case 0x9068: return (DemoInputEntry){ .timer = 144, .cur_input =                         kButton_Left+kButton_B, .new_input =                                0 };
    case 0x906e: return (DemoInputEntry){ .timer =  17, .cur_input =                                   kButton_Left, .new_input =                                0 };
    case 0x9074: return (DemoInputEntry){ .timer =   1, .cur_input =                         kButton_A+kButton_Left, .new_input =                        kButton_A };
    case 0x907a: return (DemoInputEntry){ .timer =  23, .cur_input =                         kButton_A+kButton_Left, .new_input =                                0 };
    case 0x9080: return (DemoInputEntry){ .timer =   8, .cur_input =                                      kButton_A, .new_input =                                0 };
    case 0x9086: return (DemoInputEntry){ .timer =   1, .cur_input =                        kButton_A+kButton_Right, .new_input =                    kButton_Right };
    case 0x908c: return (DemoInputEntry){ .timer =  14, .cur_input =                        kButton_A+kButton_Right, .new_input =                                0 };
    case 0x9092: return (DemoInputEntry){ .timer =  15, .cur_input =                                  kButton_Right, .new_input =                                0 };
    case 0x9098: return (DemoInputEntry){ .timer =   2, .cur_input =                                              0, .new_input =                                0 };
    case 0x909e: return (DemoInputEntry){ .timer =   1, .cur_input =                                      kButton_A, .new_input =                        kButton_A };
    case 0x90a4: return (DemoInputEntry){ .timer =  28, .cur_input =                                      kButton_A, .new_input =                                0 };
    case 0x90aa: return (DemoInputEntry){ .timer =   1, .cur_input =                         kButton_A+kButton_Left, .new_input =                     kButton_Left };
    case 0x90b0: return (DemoInputEntry){ .timer =  12, .cur_input =                         kButton_A+kButton_Left, .new_input =                                0 };
    case 0x90b6: return (DemoInputEntry){ .timer =   2, .cur_input =                                   kButton_Left, .new_input =                                0 };
    case 0x90bc: return (DemoInputEntry){ .timer =  15, .cur_input =                                              0, .new_input =                                0 };
    case 0x90c2: return (DemoInputEntry){ .timer =   1, .cur_input =                                      kButton_A, .new_input =                        kButton_A };
    case 0x90c8: return (DemoInputEntry){ .timer =  17, .cur_input =                                      kButton_A, .new_input =                                0 };
    case 0x90ce: return (DemoInputEntry){ .timer =   1, .cur_input =                        kButton_A+kButton_Right, .new_input =                    kButton_Right };
    case 0x90d4: return (DemoInputEntry){ .timer =  15, .cur_input =                        kButton_A+kButton_Right, .new_input =                                0 };
    case 0x90da: return (DemoInputEntry){ .timer =   2, .cur_input =                                      kButton_A, .new_input =                                0 };
    case 0x90e0: return (DemoInputEntry){ .timer =  16, .cur_input =                                              0, .new_input =                                0 };
    case 0x90e6: return (DemoInputEntry){ .timer =   1, .cur_input =                                      kButton_A, .new_input =                        kButton_A };
    case 0x90ec: return (DemoInputEntry){ .timer =   1, .cur_input =                         kButton_A+kButton_Left, .new_input =                     kButton_Left };
    case 0x90f2: return (DemoInputEntry){ .timer =  20, .cur_input =                         kButton_A+kButton_Left, .new_input =                                0 };
    case 0x90f8: return (DemoInputEntry){ .timer =  21, .cur_input =                                   kButton_Left, .new_input =                                0 };
    case 0x90fe: return (DemoInputEntry){ .timer =   1, .cur_input =                         kButton_Left+kButton_B, .new_input =                        kButton_B };
    case 0x9104: return (DemoInputEntry){ .timer =  14, .cur_input =                         kButton_Left+kButton_B, .new_input =                                0 };
    case 0x910a: return (DemoInputEntry){ .timer =   6, .cur_input =                                   kButton_Left, .new_input =                                0 };
    case 0x9110: return (DemoInputEntry){ .timer =   1, .cur_input =                         kButton_A+kButton_Left, .new_input =                        kButton_A };
    case 0x9116: return (DemoInputEntry){ .timer =   4, .cur_input =                         kButton_A+kButton_Left, .new_input =                                0 };
    case 0x911c: return (DemoInputEntry){ .timer =  17, .cur_input =                                   kButton_Left, .new_input =                                0 };
    case 0x9122: return (DemoInputEntry){ .timer =   1, .cur_input =                         kButton_Left+kButton_B, .new_input =                        kButton_B };
    case 0x9128: return (DemoInputEntry){ .timer =  36, .cur_input =                         kButton_Left+kButton_B, .new_input =                                0 };
    case 0x912e: return (DemoInputEntry){ .timer =   2, .cur_input =                                   kButton_Left, .new_input =                                0 };
    case 0x9134: return (DemoInputEntry){ .timer =  20, .cur_input =                                   kButton_Left, .new_input =                                0 };
    case 0x913a: return (DemoInputEntry){ .timer =   7, .cur_input =                                              0, .new_input =                                0 };
    case 0x9140: return (DemoInputEntry){ .timer =   1, .cur_input =                                  kButton_Right, .new_input =                    kButton_Right };
    case 0x9146: return (DemoInputEntry){ .timer =   9, .cur_input =                                  kButton_Right, .new_input =                                0 };
    case 0x914c: return (DemoInputEntry){ .timer =  45, .cur_input =                                              0, .new_input =                                0 };
    case 0x9152: return (DemoInputEntry){ .func_ptr = FUNC16(DemoInstr_Finish), .instr_list_ptr = 0 };
    case 0x9154: return (DemoInputEntry){ .timer =  11, .cur_input =                                  kButton_Right, .new_input =                                0 };
    case 0x915a: return (DemoInputEntry){ .timer =  23, .cur_input =                                              0, .new_input =                                0 };
    case 0x9160: return (DemoInputEntry){ .timer =   1, .cur_input =                                      kButton_X, .new_input =                        kButton_X };
    case 0x9166: return (DemoInputEntry){ .timer =   8, .cur_input =                                      kButton_X, .new_input =                                0 };
    case 0x916c: return (DemoInputEntry){ .timer =   4, .cur_input =                                              0, .new_input =                                0 };
    case 0x9172: return (DemoInputEntry){ .timer =   1, .cur_input =                                  kButton_Right, .new_input =                    kButton_Right };
    case 0x9178: return (DemoInputEntry){ .timer =   2, .cur_input =                                  kButton_Right, .new_input =                                0 };
    case 0x917e: return (DemoInputEntry){ .timer =  12, .cur_input =                                              0, .new_input =                                0 };
    case 0x9184: return (DemoInputEntry){ .timer =   1, .cur_input =                                 kButton_Select, .new_input =                   kButton_Select };
    case 0x918a: return (DemoInputEntry){ .timer =   6, .cur_input =                                 kButton_Select, .new_input =                                0 };
    case 0x9190: return (DemoInputEntry){ .timer =  13, .cur_input =                                              0, .new_input =                                0 };
    case 0x9196: return (DemoInputEntry){ .timer =   1, .cur_input =                                  kButton_Right, .new_input =                    kButton_Right };
    case 0x919c: return (DemoInputEntry){ .timer =  10, .cur_input =                                  kButton_Right, .new_input =                                0 };
    case 0x91a2: return (DemoInputEntry){ .timer =   1, .cur_input =                        kButton_A+kButton_Right, .new_input =                        kButton_A };
    case 0x91a8: return (DemoInputEntry){ .timer =   6, .cur_input =                        kButton_A+kButton_Right, .new_input =                                0 };
    case 0x91ae: return (DemoInputEntry){ .timer =  14, .cur_input =                                  kButton_Right, .new_input =                                0 };
    case 0x91b4: return (DemoInputEntry){ .timer =  16, .cur_input =                                              0, .new_input =                                0 };
    case 0x91ba: return (DemoInputEntry){ .timer =   1, .cur_input =                                  kButton_Right, .new_input =                    kButton_Right };
    case 0x91c0: return (DemoInputEntry){ .timer =   2, .cur_input =                                  kButton_Right, .new_input =                                0 };
    case 0x91c6: return (DemoInputEntry){ .timer =   1, .cur_input =                        kButton_A+kButton_Right, .new_input =                        kButton_A };
    case 0x91cc: return (DemoInputEntry){ .timer =   6, .cur_input =                        kButton_A+kButton_Right, .new_input =                                0 };
    case 0x91d2: return (DemoInputEntry){ .timer =  13, .cur_input =                                  kButton_Right, .new_input =                                0 };
    case 0x91d8: return (DemoInputEntry){ .timer =  16, .cur_input =                                              0, .new_input =                                0 };
    case 0x91de: return (DemoInputEntry){ .timer =   1, .cur_input =                                  kButton_Right, .new_input =                    kButton_Right };
    case 0x91e4: return (DemoInputEntry){ .timer =   2, .cur_input =                                  kButton_Right, .new_input =                                0 };
    case 0x91ea: return (DemoInputEntry){ .timer =   1, .cur_input =                        kButton_A+kButton_Right, .new_input =                        kButton_A };
    case 0x91f0: return (DemoInputEntry){ .timer =   8, .cur_input =                        kButton_A+kButton_Right, .new_input =                                0 };
    case 0x91f6: return (DemoInputEntry){ .timer =  28, .cur_input =                                  kButton_Right, .new_input =                                0 };
    case 0x91fc: return (DemoInputEntry){ .timer =  32, .cur_input =                                              0, .new_input =                                0 };
    case 0x9202: return (DemoInputEntry){ .timer =   1, .cur_input =                                  kButton_Right, .new_input =                    kButton_Right };
    case 0x9208: return (DemoInputEntry){ .timer =   1, .cur_input =                        kButton_A+kButton_Right, .new_input =                        kButton_A };
    case 0x920e: return (DemoInputEntry){ .timer =  11, .cur_input =                        kButton_A+kButton_Right, .new_input =                                0 };
    case 0x9214: return (DemoInputEntry){ .timer =  18, .cur_input =                                  kButton_Right, .new_input =                                0 };
    case 0x921a: return (DemoInputEntry){ .timer =  22, .cur_input =                                              0, .new_input =                                0 };
    case 0x9220: return (DemoInputEntry){ .timer =   1, .cur_input =                                  kButton_Right, .new_input =                    kButton_Right };
    case 0x9226: return (DemoInputEntry){ .timer =   6, .cur_input =                                  kButton_Right, .new_input =                                0 };
    case 0x922c: return (DemoInputEntry){ .timer =  40, .cur_input =                                              0, .new_input =                                0 };
    case 0x9232: return (DemoInputEntry){ .timer =   1, .cur_input =                                  kButton_Right, .new_input =                    kButton_Right };
    case 0x9238: return (DemoInputEntry){ .timer =   6, .cur_input =                                  kButton_Right, .new_input =                                0 };
    case 0x923e: return (DemoInputEntry){ .timer =   1, .cur_input =                        kButton_A+kButton_Right, .new_input =                        kButton_A };
    case 0x9244: return (DemoInputEntry){ .timer =   8, .cur_input =                        kButton_A+kButton_Right, .new_input =                                0 };
    case 0x924a: return (DemoInputEntry){ .timer =  23, .cur_input =                                  kButton_Right, .new_input =                                0 };
    case 0x9250: return (DemoInputEntry){ .timer =  15, .cur_input =                                              0, .new_input =                                0 };
    case 0x9256: return (DemoInputEntry){ .timer =   1, .cur_input =                                      kButton_A, .new_input =                        kButton_A };
    case 0x925c: return (DemoInputEntry){ .timer =   6, .cur_input =                                      kButton_A, .new_input =                                0 };
    case 0x9262: return (DemoInputEntry){ .timer =  10, .cur_input =                                              0, .new_input =                                0 };
    case 0x9268: return (DemoInputEntry){ .timer =   1, .cur_input =                                      kButton_X, .new_input =                        kButton_X };
    case 0x926e: return (DemoInputEntry){ .timer =   6, .cur_input =                                      kButton_X, .new_input =                                0 };
    case 0x9274: return (DemoInputEntry){ .timer =  37, .cur_input =                                              0, .new_input =                                0 };
    case 0x927a: return (DemoInputEntry){ .timer =   1, .cur_input =                                   kButton_Left, .new_input =                     kButton_Left };
    case 0x9280: return (DemoInputEntry){ .timer =   7, .cur_input =                                   kButton_Left, .new_input =                                0 };
    case 0x9286: return (DemoInputEntry){ .timer =   8, .cur_input =                                              0, .new_input =                                0 };
    case 0x928c: return (DemoInputEntry){ .timer =   1, .cur_input =                                  kButton_Right, .new_input =                    kButton_Right };
    case 0x9292: return (DemoInputEntry){ .timer =   7, .cur_input =                                  kButton_Right, .new_input =                                0 };
    case 0x9298: return (DemoInputEntry){ .timer =  82, .cur_input =                                              0, .new_input =                                0 };
    case 0x929e: return (DemoInputEntry){ .timer =   1, .cur_input =                                      kButton_A, .new_input =                        kButton_A };
    case 0x92a4: return (DemoInputEntry){ .timer =   7, .cur_input =                                      kButton_A, .new_input =                                0 };
    case 0x92aa: return (DemoInputEntry){ .timer =  17, .cur_input =                                              0, .new_input =                                0 };
    case 0x92b0: return (DemoInputEntry){ .timer =   1, .cur_input =                                      kButton_X, .new_input =                        kButton_X };
    case 0x92b6: return (DemoInputEntry){ .timer =   4, .cur_input =                                      kButton_X, .new_input =                                0 };
    case 0x92bc: return (DemoInputEntry){ .timer =  12, .cur_input =                                              0, .new_input =                                0 };
    case 0x92c2: return (DemoInputEntry){ .timer =   1, .cur_input =                                      kButton_A, .new_input =                        kButton_A };
    case 0x92c8: return (DemoInputEntry){ .timer =  11, .cur_input =                                      kButton_A, .new_input =                                0 };
    case 0x92ce: return (DemoInputEntry){ .timer =  30, .cur_input =                                              0, .new_input =                                0 };
    case 0x92d4: return (DemoInputEntry){ .timer =   1, .cur_input =                                      kButton_X, .new_input =                        kButton_X };
    case 0x92da: return (DemoInputEntry){ .timer =   6, .cur_input =                                      kButton_X, .new_input =                                0 };
    case 0x92e0: return (DemoInputEntry){ .timer =  13, .cur_input =                                              0, .new_input =                                0 };
    case 0x92e6: return (DemoInputEntry){ .timer =   1, .cur_input =                                      kButton_A, .new_input =                        kButton_A };
    case 0x92ec: return (DemoInputEntry){ .timer =   5, .cur_input =                                      kButton_A, .new_input =                                0 };
    case 0x92f2: return (DemoInputEntry){ .timer =  13, .cur_input =                                              0, .new_input =                                0 };
    case 0x92f8: return (DemoInputEntry){ .timer =   1, .cur_input =                                      kButton_X, .new_input =                        kButton_X };
    case 0x92fe: return (DemoInputEntry){ .timer =   6, .cur_input =                                      kButton_X, .new_input =                                0 };
    case 0x9304: return (DemoInputEntry){ .timer = 124, .cur_input =                                              0, .new_input =                                0 };
    case 0x930a: return (DemoInputEntry){ .timer =   1, .cur_input =                                   kButton_Left, .new_input =                     kButton_Left };
    case 0x9310: return (DemoInputEntry){ .timer =   7, .cur_input =                                   kButton_Left, .new_input =                                0 };
    case 0x9316: return (DemoInputEntry){ .timer =  17, .cur_input =                                              0, .new_input =                                0 };
    case 0x931c: return (DemoInputEntry){ .timer =   1, .cur_input =                                  kButton_Right, .new_input =                    kButton_Right };
    case 0x9322: return (DemoInputEntry){ .timer =   9, .cur_input =                                  kButton_Right, .new_input =                                0 };
    case 0x9328: return (DemoInputEntry){ .timer =   1, .cur_input =                        kButton_X+kButton_Right, .new_input =                        kButton_X };
    case 0x932e: return (DemoInputEntry){ .timer =   3, .cur_input =                        kButton_X+kButton_Right, .new_input =                                0 };
    case 0x9334: return (DemoInputEntry){ .timer =   4, .cur_input =                                  kButton_Right, .new_input =                                0 };
    case 0x933a: return (DemoInputEntry){ .func_ptr = FUNC16(DemoInstr_Finish), .instr_list_ptr = 0 };
    case 0x933c: return (DemoInputEntry){ .timer = 165, .cur_input =                                              0, .new_input =                                0 };
    case 0x9342: return (DemoInputEntry){ .func_ptr = FUNC16(DemoInstr_Goto), .instr_list_ptr = 0x933c };
    case 0x9346: return (DemoInputEntry){ .timer = 150, .cur_input =                                              0, .new_input =                                0 };
    case 0x934c: return (DemoInputEntry){ .timer =   1, .cur_input =                                   kButton_Left, .new_input =                     kButton_Left };
    case 0x9352: return (DemoInputEntry){ .timer = 204, .cur_input =                                   kButton_Left, .new_input =                                0 };
    case 0x9358: return (DemoInputEntry){ .timer =   1, .cur_input =                         kButton_Left+kButton_B, .new_input =                        kButton_B };
    case 0x935e: return (DemoInputEntry){ .timer = 118, .cur_input =                         kButton_Left+kButton_B, .new_input =                                0 };
    case 0x9364: return (DemoInputEntry){ .timer =   2, .cur_input =                                      kButton_B, .new_input =                                0 };
    case 0x936a: return (DemoInputEntry){ .timer =   1, .cur_input =                        kButton_Right+kButton_B, .new_input =                    kButton_Right };
    case 0x9370: return (DemoInputEntry){ .timer = 182, .cur_input =                        kButton_Right+kButton_B, .new_input =                                0 };
    case 0x9376: return (DemoInputEntry){ .timer =  12, .cur_input =                                  kButton_Right, .new_input =                                0 };
    case 0x937c: return (DemoInputEntry){ .timer =   1, .cur_input =                        kButton_A+kButton_Right, .new_input =                        kButton_A };
    case 0x9382: return (DemoInputEntry){ .timer =   6, .cur_input =                        kButton_A+kButton_Right, .new_input =                                0 };
    case 0x9388: return (DemoInputEntry){ .timer =  14, .cur_input =                                  kButton_Right, .new_input =                                0 };
    case 0x938e: return (DemoInputEntry){ .timer =  36, .cur_input =                                              0, .new_input =                                0 };
    case 0x9394: return (DemoInputEntry){ .timer =   1, .cur_input =                                 kButton_Select, .new_input =                   kButton_Select };
    case 0x939a: return (DemoInputEntry){ .timer =   5, .cur_input =                                 kButton_Select, .new_input =                                0 };
    case 0x93a0: return (DemoInputEntry){ .timer =  11, .cur_input =                                              0, .new_input =                                0 };
    case 0x93a6: return (DemoInputEntry){ .timer =   1, .cur_input =                                 kButton_Select, .new_input =                   kButton_Select };
    case 0x93ac: return (DemoInputEntry){ .timer =   4, .cur_input =                                 kButton_Select, .new_input =                                0 };
    case 0x93b2: return (DemoInputEntry){ .timer =  14, .cur_input =                                              0, .new_input =                                0 };
    case 0x93b8: return (DemoInputEntry){ .timer =   1, .cur_input =                                      kButton_X, .new_input =                        kButton_X };
    case 0x93be: return (DemoInputEntry){ .timer =   7, .cur_input =                                      kButton_X, .new_input =                                0 };
    case 0x93c4: return (DemoInputEntry){ .timer = 240, .cur_input =                                              0, .new_input =                                0 };
    case 0x93ca: return (DemoInputEntry){ .func_ptr = FUNC16(DemoInstr_Finish), .instr_list_ptr = 0 };
    case 0x93cc: return (DemoInputEntry){ .timer =  41, .cur_input =                                              0, .new_input =                                0 };
    case 0x93d2: return (DemoInputEntry){ .timer =   1, .cur_input =                                  kButton_Right, .new_input =                    kButton_Right };
    case 0x93d8: return (DemoInputEntry){ .timer =  49, .cur_input =                                  kButton_Right, .new_input =                                0 };
    case 0x93de: return (DemoInputEntry){ .timer =  68, .cur_input =                                              0, .new_input =                                0 };
    case 0x93e4: return (DemoInputEntry){ .timer =   1, .cur_input =                                 kButton_Select, .new_input =                   kButton_Select };
    case 0x93ea: return (DemoInputEntry){ .timer =   5, .cur_input =                                 kButton_Select, .new_input =                                0 };
    case 0x93f0: return (DemoInputEntry){ .timer =  35, .cur_input =                                              0, .new_input =                                0 };
    case 0x93f6: return (DemoInputEntry){ .timer =   1, .cur_input =                                      kButton_X, .new_input =                        kButton_X };
    case 0x93fc: return (DemoInputEntry){ .timer =   8, .cur_input =                                      kButton_X, .new_input =                                0 };
    case 0x9402: return (DemoInputEntry){ .timer =  10, .cur_input =                                              0, .new_input =                                0 };
    case 0x9408: return (DemoInputEntry){ .timer =   1, .cur_input =                                      kButton_X, .new_input =                        kButton_X };
    case 0x940e: return (DemoInputEntry){ .timer =   8, .cur_input =                                      kButton_X, .new_input =                                0 };
    case 0x9414: return (DemoInputEntry){ .timer =  17, .cur_input =                                              0, .new_input =                                0 };
    case 0x941a: return (DemoInputEntry){ .timer =   1, .cur_input =                                      kButton_X, .new_input =                        kButton_X };
    case 0x9420: return (DemoInputEntry){ .timer =   7, .cur_input =                                      kButton_X, .new_input =                                0 };
    case 0x9426: return (DemoInputEntry){ .timer =  13, .cur_input =                                              0, .new_input =                                0 };
    case 0x942c: return (DemoInputEntry){ .timer =   1, .cur_input =                                      kButton_X, .new_input =                        kButton_X };
    case 0x9432: return (DemoInputEntry){ .timer =   8, .cur_input =                                      kButton_X, .new_input =                                0 };
    case 0x9438: return (DemoInputEntry){ .timer =   7, .cur_input =                                              0, .new_input =                                0 };
    case 0x943e: return (DemoInputEntry){ .timer =   1, .cur_input =                                      kButton_X, .new_input =                        kButton_X };
    case 0x9444: return (DemoInputEntry){ .timer =   9, .cur_input =                                      kButton_X, .new_input =                                0 };
    case 0x944a: return (DemoInputEntry){ .timer =  32, .cur_input =                                              0, .new_input =                                0 };
    case 0x9450: return (DemoInputEntry){ .timer =   1, .cur_input =                        kButton_Right+kButton_B, .new_input =          kButton_Right+kButton_B };
    case 0x9456: return (DemoInputEntry){ .timer =  17, .cur_input =                        kButton_Right+kButton_B, .new_input =                                0 };
    case 0x945c: return (DemoInputEntry){ .timer =  26, .cur_input =                                              0, .new_input =                                0 };
    case 0x9462: return (DemoInputEntry){ .func_ptr = FUNC16(DemoInstr_Finish), .instr_list_ptr = 0 };
    case 0x9464: return (DemoInputEntry){ .timer = 512, .cur_input =                                              0, .new_input =                                0 };
    case 0x946a: return (DemoInputEntry){ .func_ptr = FUNC16(DemoInstr_Finish), .instr_list_ptr = 0 };
    case 0x946c: return (DemoInputEntry){ .timer =  43, .cur_input =                                              0, .new_input =                                0 };
    case 0x9472: return (DemoInputEntry){ .timer =   1, .cur_input =                                   kButton_Left, .new_input =                     kButton_Left };
    case 0x9478: return (DemoInputEntry){ .timer =  70, .cur_input =                                   kButton_Left, .new_input =                                0 };
    case 0x947e: return (DemoInputEntry){ .timer =  55, .cur_input =                                              0, .new_input =                                0 };
    case 0x9484: return (DemoInputEntry){ .timer =   1, .cur_input =                                   kButton_Left, .new_input =                     kButton_Left };
    case 0x948a: return (DemoInputEntry){ .timer =  12, .cur_input =                                   kButton_Left, .new_input =                                0 };
    case 0x9490: return (DemoInputEntry){ .timer =   1, .cur_input =                         kButton_A+kButton_Left, .new_input =                        kButton_A };
    case 0x9496: return (DemoInputEntry){ .timer =  19, .cur_input =                         kButton_A+kButton_Left, .new_input =                                0 };
    case 0x949c: return (DemoInputEntry){ .timer =  19, .cur_input =                                   kButton_Left, .new_input =                                0 };
    case 0x94a2: return (DemoInputEntry){ .timer =   1, .cur_input =                         kButton_X+kButton_Left, .new_input =                        kButton_X };
    case 0x94a8: return (DemoInputEntry){ .timer =  11, .cur_input =                         kButton_X+kButton_Left, .new_input =                                0 };
    case 0x94ae: return (DemoInputEntry){ .timer =   5, .cur_input =                                   kButton_Left, .new_input =                                0 };
    case 0x94b4: return (DemoInputEntry){ .timer =   1, .cur_input =                         kButton_A+kButton_Left, .new_input =                        kButton_A };
    case 0x94ba: return (DemoInputEntry){ .timer =  21, .cur_input =                         kButton_A+kButton_Left, .new_input =                                0 };
    case 0x94c0: return (DemoInputEntry){ .timer =  37, .cur_input =                                   kButton_Left, .new_input =                                0 };
    case 0x94c6: return (DemoInputEntry){ .timer =   1, .cur_input =                         kButton_A+kButton_Left, .new_input =                        kButton_A };
    case 0x94cc: return (DemoInputEntry){ .timer =  14, .cur_input =                         kButton_A+kButton_Left, .new_input =                                0 };
    case 0x94d2: return (DemoInputEntry){ .timer =  33, .cur_input =                                   kButton_Left, .new_input =                                0 };
    case 0x94d8: return (DemoInputEntry){ .timer =   1, .cur_input =                         kButton_A+kButton_Left, .new_input =                        kButton_A };
    case 0x94de: return (DemoInputEntry){ .timer =   9, .cur_input =                         kButton_A+kButton_Left, .new_input =                                0 };
    case 0x94e4: return (DemoInputEntry){ .timer =  29, .cur_input =                                   kButton_Left, .new_input =                                0 };
    case 0x94ea: return (DemoInputEntry){ .timer =   8, .cur_input =                                              0, .new_input =                                0 };
    case 0x94f0: return (DemoInputEntry){ .timer =   1, .cur_input =                                      kButton_L, .new_input =                        kButton_L };
    case 0x94f6: return (DemoInputEntry){ .timer =   1, .cur_input =                                      kButton_L, .new_input =                                0 };
    case 0x94fc: return (DemoInputEntry){ .timer =   1, .cur_input =                         kButton_L+kButton_Down, .new_input =                     kButton_Down };
    case 0x9502: return (DemoInputEntry){ .timer = 196, .cur_input =                                      kButton_L, .new_input =                                0 };
    case 0x9508: return (DemoInputEntry){ .func_ptr = FUNC16(DemoInstr_Finish), .instr_list_ptr = 0 };
    case 0x950a: return (DemoInputEntry){ .timer =  48, .cur_input =                                              0, .new_input =                                0 };
    case 0x9510: return (DemoInputEntry){ .timer =   1, .cur_input =                        kButton_Right+kButton_B, .new_input =          kButton_Right+kButton_B };
    case 0x9516: return (DemoInputEntry){ .timer =  30, .cur_input =                        kButton_Right+kButton_B, .new_input =                                0 };
    case 0x951c: return (DemoInputEntry){ .timer =   1, .cur_input =              kButton_A+kButton_Right+kButton_B, .new_input =                        kButton_A };
    case 0x9522: return (DemoInputEntry){ .timer =  12, .cur_input =              kButton_A+kButton_Right+kButton_B, .new_input =                                0 };
    case 0x9528: return (DemoInputEntry){ .timer =  28, .cur_input =                        kButton_Right+kButton_B, .new_input =                                0 };
    case 0x952e: return (DemoInputEntry){ .timer =   1, .cur_input =              kButton_A+kButton_Right+kButton_B, .new_input =                        kButton_A };
    case 0x9534: return (DemoInputEntry){ .timer =  23, .cur_input =              kButton_A+kButton_Right+kButton_B, .new_input =                                0 };
    case 0x953a: return (DemoInputEntry){ .timer =  43, .cur_input =                        kButton_Right+kButton_B, .new_input =                                0 };
    case 0x9540: return (DemoInputEntry){ .timer =   1, .cur_input =                                   kButton_Down, .new_input =                     kButton_Down };
    case 0x9546: return (DemoInputEntry){ .timer =   3, .cur_input =                                              0, .new_input =                                0 };
    case 0x954c: return (DemoInputEntry){ .timer =   1, .cur_input =                                   kButton_Left, .new_input =                     kButton_Left };
    case 0x9552: return (DemoInputEntry){ .timer =   1, .cur_input =                         kButton_R+kButton_Left, .new_input =                        kButton_R };
    case 0x9558: return (DemoInputEntry){ .timer = 157, .cur_input =                                      kButton_R, .new_input =                                0 };
    case 0x955e: return (DemoInputEntry){ .func_ptr = FUNC16(DemoInstr_Finish), .instr_list_ptr = 0 };
    case 0x9560: return (DemoInputEntry){ .timer =  41, .cur_input =                                              0, .new_input =                                0 };
    case 0x9566: return (DemoInputEntry){ .timer =   1, .cur_input =                                  kButton_Right, .new_input =                    kButton_Right };
    case 0x956c: return (DemoInputEntry){ .timer =  18, .cur_input =                                  kButton_Right, .new_input =                                0 };
    case 0x9572: return (DemoInputEntry){ .timer =   1, .cur_input =                        kButton_A+kButton_Right, .new_input =                        kButton_A };
    case 0x9578: return (DemoInputEntry){ .timer =  22, .cur_input =                        kButton_A+kButton_Right, .new_input =                                0 };
    case 0x957e: return (DemoInputEntry){ .timer =  65, .cur_input =                                  kButton_Right, .new_input =                                0 };
    case 0x9584: return (DemoInputEntry){ .timer =  20, .cur_input =                                              0, .new_input =                                0 };
    case 0x958a: return (DemoInputEntry){ .timer =   1, .cur_input =                                      kButton_R, .new_input =                        kButton_R };
    case 0x9590: return (DemoInputEntry){ .timer =  10, .cur_input =                                      kButton_R, .new_input =                                0 };
    case 0x9596: return (DemoInputEntry){ .timer =   1, .cur_input =                            kButton_R+kButton_X, .new_input =                        kButton_X };
    case 0x959c: return (DemoInputEntry){ .timer =  29, .cur_input =                            kButton_R+kButton_X, .new_input =                                0 };
    case 0x95a2: return (DemoInputEntry){ .timer =   5, .cur_input =                                      kButton_X, .new_input =                                0 };
    case 0x95a8: return (DemoInputEntry){ .timer =   1, .cur_input =                         kButton_X+kButton_Down, .new_input =                     kButton_Down };
    case 0x95ae: return (DemoInputEntry){ .timer =  55, .cur_input =                         kButton_X+kButton_Down, .new_input =                                0 };
    case 0x95b4: return (DemoInputEntry){ .timer = 219, .cur_input =                                              0, .new_input =                                0 };
    case 0x95ba: return (DemoInputEntry){ .func_ptr = FUNC16(DemoInstr_Finish), .instr_list_ptr = 0 };
    case 0x965a: return (DemoInputEntry){ .timer =  27, .cur_input =                                              0, .new_input =                                0 };
    case 0x9660: return (DemoInputEntry){ .timer =   1, .cur_input =                                   kButton_Left, .new_input =                     kButton_Left };
    case 0x9666: return (DemoInputEntry){ .timer =   5, .cur_input =                                   kButton_Left, .new_input =                                0 };
    case 0x966c: return (DemoInputEntry){ .timer =  15, .cur_input =                                              0, .new_input =                                0 };
    case 0x9672: return (DemoInputEntry){ .timer =   1, .cur_input =                                  kButton_Right, .new_input =                    kButton_Right };
    case 0x9678: return (DemoInputEntry){ .timer =   5, .cur_input =                                  kButton_Right, .new_input =                                0 };
    case 0x967e: return (DemoInputEntry){ .timer =  16, .cur_input =                                              0, .new_input =                                0 };
    case 0x9684: return (DemoInputEntry){ .timer =   1, .cur_input =                                  kButton_Right, .new_input =                    kButton_Right };
    case 0x968a: return (DemoInputEntry){ .timer =  13, .cur_input =                                  kButton_Right, .new_input =                                0 };
    case 0x9690: return (DemoInputEntry){ .timer =  42, .cur_input =                                  kButton_Right, .new_input =                                0 };
    case 0x9696: return (DemoInputEntry){ .timer =   7, .cur_input =                                              0, .new_input =                                0 };
    case 0x969c: return (DemoInputEntry){ .timer =   1, .cur_input =                                      kButton_A, .new_input =                        kButton_A };
    case 0x96a2: return (DemoInputEntry){ .timer =  21, .cur_input =                                      kButton_A, .new_input =                                0 };
    case 0x96a8: return (DemoInputEntry){ .timer =  30, .cur_input =                                              0, .new_input =                                0 };
    case 0x96ae: return (DemoInputEntry){ .timer =   1, .cur_input =                                   kButton_Left, .new_input =                     kButton_Left };
    case 0x96b4: return (DemoInputEntry){ .timer =  19, .cur_input =                                   kButton_Left, .new_input =                                0 };
    case 0x96ba: return (DemoInputEntry){ .timer =  16, .cur_input =                                              0, .new_input =                                0 };
    case 0x96c0: return (DemoInputEntry){ .timer =   1, .cur_input =                                  kButton_Right, .new_input =                    kButton_Right };
    case 0x96c6: return (DemoInputEntry){ .timer =   8, .cur_input =                                  kButton_Right, .new_input =                                0 };
    case 0x96cc: return (DemoInputEntry){ .timer =   1, .cur_input =                        kButton_A+kButton_Right, .new_input =                        kButton_A };
    case 0x96d2: return (DemoInputEntry){ .timer =  15, .cur_input =                        kButton_A+kButton_Right, .new_input =                                0 };
    case 0x96d8: return (DemoInputEntry){ .timer =   1, .cur_input =                                      kButton_A, .new_input =                                0 };
    case 0x96de: return (DemoInputEntry){ .timer =   1, .cur_input =                         kButton_A+kButton_Left, .new_input =                     kButton_Left };
    case 0x96e4: return (DemoInputEntry){ .timer =   7, .cur_input =                         kButton_A+kButton_Left, .new_input =                                0 };
    case 0x96ea: return (DemoInputEntry){ .timer =   4, .cur_input =                                   kButton_Left, .new_input =                                0 };
    case 0x96f0: return (DemoInputEntry){ .timer =   1, .cur_input =                                              0, .new_input =                                0 };
    case 0x96f6: return (DemoInputEntry){ .timer =   1, .cur_input =                                  kButton_Right, .new_input =                    kButton_Right };
    case 0x96fc: return (DemoInputEntry){ .timer =   4, .cur_input =                                  kButton_Right, .new_input =                                0 };
    case 0x9702: return (DemoInputEntry){ .timer =   1, .cur_input =                        kButton_X+kButton_Right, .new_input =                        kButton_X };
    case 0x9708: return (DemoInputEntry){ .timer =   9, .cur_input =                        kButton_X+kButton_Right, .new_input =                                0 };
    case 0x970e: return (DemoInputEntry){ .timer =   5, .cur_input =                        kButton_X+kButton_Right, .new_input =                                0 };
    case 0x9714: return (DemoInputEntry){ .timer =  76, .cur_input =                                      kButton_X, .new_input =                                0 };
    case 0x971a: return (DemoInputEntry){ .timer =   1, .cur_input =                         kButton_X+kButton_Down, .new_input =                     kButton_Down };
    case 0x9720: return (DemoInputEntry){ .timer =   3, .cur_input =                                      kButton_X, .new_input =                                0 };
    case 0x9726: return (DemoInputEntry){ .timer =   1, .cur_input =                            kButton_R+kButton_X, .new_input =                        kButton_R };
    case 0x972c: return (DemoInputEntry){ .timer =   4, .cur_input =                            kButton_R+kButton_X, .new_input =                                0 };
    case 0x9732: return (DemoInputEntry){ .timer = 132, .cur_input =                                      kButton_R, .new_input =                                0 };
    case 0x9738: return (DemoInputEntry){ .func_ptr = FUNC16(DemoInstr_Finish), .instr_list_ptr = 0 };
    case 0x973a: return (DemoInputEntry){ .timer =  16, .cur_input =                                              0, .new_input =                                0 };
    case 0x9740: return (DemoInputEntry){ .timer =   1, .cur_input =                                 kButton_Select, .new_input =                   kButton_Select };
    case 0x9746: return (DemoInputEntry){ .timer =  12, .cur_input =                                              0, .new_input =                                0 };
    case 0x974c: return (DemoInputEntry){ .timer =   1, .cur_input =                                 kButton_Select, .new_input =                   kButton_Select };
    case 0x9752: return (DemoInputEntry){ .timer =  12, .cur_input =                                              0, .new_input =                                0 };
    case 0x9758: return (DemoInputEntry){ .timer =   1, .cur_input =                                 kButton_Select, .new_input =                   kButton_Select };
    case 0x975e: return (DemoInputEntry){ .timer =  12, .cur_input =                                              0, .new_input =                                0 };
    case 0x9764: return (DemoInputEntry){ .timer =   1, .cur_input =                                 kButton_Select, .new_input =                   kButton_Select };
    case 0x976a: return (DemoInputEntry){ .timer =  12, .cur_input =                                              0, .new_input =                                0 };
    case 0x9770: return (DemoInputEntry){ .timer =   1, .cur_input =                                      kButton_R, .new_input =                        kButton_R };
    case 0x9776: return (DemoInputEntry){ .timer =  34, .cur_input =                                      kButton_R, .new_input =                                0 };
    case 0x977c: return (DemoInputEntry){ .timer =   1, .cur_input =                            kButton_R+kButton_X, .new_input =                        kButton_X };
    case 0x9782: return (DemoInputEntry){ .timer =  16, .cur_input =                            kButton_R+kButton_X, .new_input =                                0 };
    case 0x9788: return (DemoInputEntry){ .timer =   1, .cur_input =  kButton_R+kButton_X+kButton_Left+kButton_Down, .new_input =        kButton_Left+kButton_Down };
    case 0x978e: return (DemoInputEntry){ .timer =   6, .cur_input =  kButton_R+kButton_X+kButton_Left+kButton_Down, .new_input =                                0 };
    case 0x9794: return (DemoInputEntry){ .timer =  12, .cur_input =               kButton_R+kButton_X+kButton_Down, .new_input =                                0 };
    case 0x979a: return (DemoInputEntry){ .timer =   1, .cur_input = kButton_R+kButton_X+kButton_Right+kButton_Down, .new_input =                    kButton_Right };
    case 0x97a0: return (DemoInputEntry){ .timer =   4, .cur_input = kButton_R+kButton_X+kButton_Right+kButton_Down, .new_input =                                0 };
    case 0x97a6: return (DemoInputEntry){ .timer =  18, .cur_input =              kButton_R+kButton_X+kButton_Right, .new_input =                                0 };
    case 0x97ac: return (DemoInputEntry){ .timer =   6, .cur_input =                        kButton_R+kButton_Right, .new_input =                                0 };
    case 0x97b2: return (DemoInputEntry){ .timer =   1, .cur_input =              kButton_R+kButton_X+kButton_Right, .new_input =                        kButton_X };
    case 0x97b8: return (DemoInputEntry){ .timer =   7, .cur_input =              kButton_R+kButton_X+kButton_Right, .new_input =                                0 };
    case 0x97be: return (DemoInputEntry){ .timer =   1, .cur_input = kButton_R+kButton_X+kButton_Right+kButton_Down, .new_input =                     kButton_Down };
    case 0x97c4: return (DemoInputEntry){ .timer =   4, .cur_input = kButton_R+kButton_X+kButton_Right+kButton_Down, .new_input =                                0 };
    case 0x97ca: return (DemoInputEntry){ .timer =  22, .cur_input =               kButton_R+kButton_X+kButton_Down, .new_input =                                0 };
    case 0x97d0: return (DemoInputEntry){ .timer =   1, .cur_input = kButton_R+kButton_X+kButton_Right+kButton_Down, .new_input =                    kButton_Right };
    case 0x97d6: return (DemoInputEntry){ .timer =   5, .cur_input = kButton_R+kButton_X+kButton_Right+kButton_Down, .new_input =                                0 };
    case 0x97dc: return (DemoInputEntry){ .timer =  11, .cur_input =              kButton_R+kButton_X+kButton_Right, .new_input =                                0 };
    case 0x97e2: return (DemoInputEntry){ .timer =   7, .cur_input =                        kButton_R+kButton_Right, .new_input =                                0 };
    case 0x97e8: return (DemoInputEntry){ .timer =   1, .cur_input =              kButton_R+kButton_X+kButton_Right, .new_input =                        kButton_X };
    case 0x97ee: return (DemoInputEntry){ .timer =  10, .cur_input =              kButton_R+kButton_X+kButton_Right, .new_input =                                0 };
    case 0x97f4: return (DemoInputEntry){ .timer =   1, .cur_input = kButton_R+kButton_X+kButton_Right+kButton_Down, .new_input =                     kButton_Down };
    case 0x97fa: return (DemoInputEntry){ .timer =  12, .cur_input = kButton_R+kButton_X+kButton_Right+kButton_Down, .new_input =                                0 };
    case 0x9800: return (DemoInputEntry){ .timer =  14, .cur_input =              kButton_R+kButton_X+kButton_Right, .new_input =                                0 };
    case 0x9806: return (DemoInputEntry){ .timer =  10, .cur_input =                        kButton_R+kButton_Right, .new_input =                                0 };
    case 0x980c: return (DemoInputEntry){ .timer =   1, .cur_input =              kButton_R+kButton_X+kButton_Right, .new_input =                        kButton_X };
    case 0x9812: return (DemoInputEntry){ .timer =   8, .cur_input =              kButton_R+kButton_X+kButton_Right, .new_input =                                0 };
    case 0x9818: return (DemoInputEntry){ .timer =   1, .cur_input = kButton_R+kButton_X+kButton_Right+kButton_Down, .new_input =                     kButton_Down };
    case 0x981e: return (DemoInputEntry){ .timer =  12, .cur_input = kButton_R+kButton_X+kButton_Right+kButton_Down, .new_input =                                0 };
    case 0x9824: return (DemoInputEntry){ .timer =  14, .cur_input =              kButton_R+kButton_X+kButton_Right, .new_input =                                0 };
    case 0x982a: return (DemoInputEntry){ .timer =  10, .cur_input =                        kButton_R+kButton_Right, .new_input =                                0 };
    case 0x9830: return (DemoInputEntry){ .timer =   1, .cur_input =              kButton_R+kButton_X+kButton_Right, .new_input =                        kButton_X };
    case 0x9836: return (DemoInputEntry){ .timer =   8, .cur_input =              kButton_R+kButton_X+kButton_Right, .new_input =                                0 };
    case 0x983c: return (DemoInputEntry){ .timer =   1, .cur_input = kButton_R+kButton_X+kButton_Right+kButton_Down, .new_input =                     kButton_Down };
    case 0x9842: return (DemoInputEntry){ .timer =  13, .cur_input = kButton_R+kButton_X+kButton_Right+kButton_Down, .new_input =                                0 };
    case 0x9848: return (DemoInputEntry){ .timer =  14, .cur_input =              kButton_R+kButton_X+kButton_Right, .new_input =                                0 };
    case 0x984e: return (DemoInputEntry){ .timer =  10, .cur_input =                        kButton_R+kButton_Right, .new_input =                                0 };
    case 0x9854: return (DemoInputEntry){ .timer =   1, .cur_input =              kButton_R+kButton_X+kButton_Right, .new_input =                        kButton_X };
    case 0x985a: return (DemoInputEntry){ .timer =   9, .cur_input =              kButton_R+kButton_X+kButton_Right, .new_input =                                0 };
    case 0x9860: return (DemoInputEntry){ .timer =   1, .cur_input = kButton_R+kButton_X+kButton_Right+kButton_Down, .new_input =                     kButton_Down };
    case 0x9866: return (DemoInputEntry){ .timer =  12, .cur_input = kButton_R+kButton_X+kButton_Right+kButton_Down, .new_input =                                0 };
    case 0x986c: return (DemoInputEntry){ .timer =   8, .cur_input =              kButton_R+kButton_X+kButton_Right, .new_input =                                0 };
    case 0x9872: return (DemoInputEntry){ .timer =   4, .cur_input =                                  kButton_Right, .new_input =                                0 };
    case 0x9878: return (DemoInputEntry){ .timer =  32, .cur_input =                                              0, .new_input =                                0 };
    case 0x987e: return (DemoInputEntry){ .timer =   1, .cur_input =                                   kButton_Down, .new_input =                     kButton_Down };
    case 0x9884: return (DemoInputEntry){ .timer =   5, .cur_input =                                   kButton_Down, .new_input =                                0 };
    case 0x988a: return (DemoInputEntry){ .timer =   1, .cur_input =                                   kButton_Left, .new_input =                     kButton_Left };
    case 0x9890: return (DemoInputEntry){ .timer =   5, .cur_input =                                   kButton_Left, .new_input =                                0 };
    case 0x9896: return (DemoInputEntry){ .timer =  40, .cur_input =                                              0, .new_input =                                0 };
    case 0x989c: return (DemoInputEntry){ .func_ptr = FUNC16(DemoInstr_Finish), .instr_list_ptr = 0 };
    case 0x989e: return (DemoInputEntry){ .timer =  33, .cur_input =                                              0, .new_input =                                0 };
    case 0x98a4: return (DemoInputEntry){ .timer =   1, .cur_input =                                      kButton_X, .new_input =                        kButton_X };
    case 0x98aa: return (DemoInputEntry){ .timer =   5, .cur_input =                                      kButton_X, .new_input =                                0 };
    case 0x98b0: return (DemoInputEntry){ .timer =   6, .cur_input =                                              0, .new_input =                                0 };
    case 0x98b6: return (DemoInputEntry){ .timer =   1, .cur_input =                                      kButton_X, .new_input =                        kButton_X };
    case 0x98bc: return (DemoInputEntry){ .timer =   5, .cur_input =                                      kButton_X, .new_input =                                0 };
    case 0x98c2: return (DemoInputEntry){ .timer =  18, .cur_input =                                              0, .new_input =                                0 };
    case 0x98c8: return (DemoInputEntry){ .timer =   1, .cur_input =                                   kButton_Left, .new_input =                     kButton_Left };
    case 0x98ce: return (DemoInputEntry){ .timer =  23, .cur_input =                                   kButton_Left, .new_input =                                0 };
    case 0x98d4: return (DemoInputEntry){ .timer =  28, .cur_input =                                              0, .new_input =                                0 };
    case 0x98da: return (DemoInputEntry){ .timer =   1, .cur_input =                                      kButton_A, .new_input =                        kButton_A };
    case 0x98e0: return (DemoInputEntry){ .timer =  14, .cur_input =                                      kButton_A, .new_input =                                0 };
    case 0x98e6: return (DemoInputEntry){ .timer =   1, .cur_input =                         kButton_A+kButton_Down, .new_input =                     kButton_Down };
    case 0x98ec: return (DemoInputEntry){ .timer =   5, .cur_input =                         kButton_A+kButton_Down, .new_input =                                0 };
    case 0x98f2: return (DemoInputEntry){ .timer =  11, .cur_input =                                   kButton_Down, .new_input =                                0 };
    case 0x98f8: return (DemoInputEntry){ .timer =   1, .cur_input =                         kButton_X+kButton_Down, .new_input =                        kButton_X };
    case 0x98fe: return (DemoInputEntry){ .timer =   6, .cur_input =                         kButton_X+kButton_Down, .new_input =                                0 };
    case 0x9904: return (DemoInputEntry){ .timer =   8, .cur_input =                                   kButton_Down, .new_input =                                0 };
    case 0x990a: return (DemoInputEntry){ .timer =   7, .cur_input =                                              0, .new_input =                                0 };
    case 0x9910: return (DemoInputEntry){ .timer =   1, .cur_input =                                   kButton_Left, .new_input =                     kButton_Left };
    case 0x9916: return (DemoInputEntry){ .timer =  29, .cur_input =                                   kButton_Left, .new_input =                                0 };
    case 0x991c: return (DemoInputEntry){ .timer =   9, .cur_input =                                              0, .new_input =                                0 };
    case 0x9922: return (DemoInputEntry){ .timer =   1, .cur_input =                                   kButton_Left, .new_input =                     kButton_Left };
    case 0x9928: return (DemoInputEntry){ .timer =  14, .cur_input =                                   kButton_Left, .new_input =                                0 };
    case 0x992e: return (DemoInputEntry){ .timer =   1, .cur_input =                         kButton_A+kButton_Left, .new_input =                        kButton_A };
    case 0x9934: return (DemoInputEntry){ .timer =  29, .cur_input =                         kButton_A+kButton_Left, .new_input =                                0 };
    case 0x993a: return (DemoInputEntry){ .timer =  56, .cur_input =                                   kButton_Left, .new_input =                                0 };
    case 0x9940: return (DemoInputEntry){ .timer =   1, .cur_input =                         kButton_A+kButton_Left, .new_input =                        kButton_A };
    case 0x9946: return (DemoInputEntry){ .timer =  22, .cur_input =                         kButton_A+kButton_Left, .new_input =                                0 };
    case 0x994c: return (DemoInputEntry){ .timer =  43, .cur_input =                                   kButton_Left, .new_input =                                0 };
    case 0x9952: return (DemoInputEntry){ .timer =   1, .cur_input =                                      kButton_A, .new_input =                        kButton_A };
    case 0x9958: return (DemoInputEntry){ .timer =  16, .cur_input =                                      kButton_A, .new_input =                                0 };
    case 0x995e: return (DemoInputEntry){ .timer =   1, .cur_input =                         kButton_A+kButton_Down, .new_input =                     kButton_Down };
    case 0x9964: return (DemoInputEntry){ .timer =   8, .cur_input =                         kButton_A+kButton_Down, .new_input =                                0 };
    case 0x996a: return (DemoInputEntry){ .timer =   5, .cur_input =                                   kButton_Down, .new_input =                                0 };
    case 0x9970: return (DemoInputEntry){ .timer =   1, .cur_input =                         kButton_X+kButton_Down, .new_input =                        kButton_X };
    case 0x9976: return (DemoInputEntry){ .timer =   8, .cur_input =                         kButton_X+kButton_Down, .new_input =                                0 };
    case 0x997c: return (DemoInputEntry){ .timer =   8, .cur_input =                                   kButton_Down, .new_input =                                0 };
    case 0x9982: return (DemoInputEntry){ .timer =   8, .cur_input =                                              0, .new_input =                                0 };
    case 0x9988: return (DemoInputEntry){ .timer =   1, .cur_input =                                   kButton_Left, .new_input =                     kButton_Left };
    case 0x998e: return (DemoInputEntry){ .timer =  43, .cur_input =                                   kButton_Left, .new_input =                                0 };
    case 0x9994: return (DemoInputEntry){ .timer =   1, .cur_input =                         kButton_A+kButton_Left, .new_input =                        kButton_A };
    case 0x999a: return (DemoInputEntry){ .timer =  16, .cur_input =                         kButton_A+kButton_Left, .new_input =                                0 };
    case 0x99a0: return (DemoInputEntry){ .timer =  18, .cur_input =                                   kButton_Left, .new_input =                                0 };
    case 0x99a6: return (DemoInputEntry){ .timer =  93, .cur_input =                                              0, .new_input =                                0 };
    case 0x99ac: return (DemoInputEntry){ .func_ptr = FUNC16(DemoInstr_Finish), .instr_list_ptr = 0 };
    case 0x99ae: return (DemoInputEntry){ .timer =  22, .cur_input =                                              0, .new_input =                                0 };
    case 0x99b4: return (DemoInputEntry){ .timer =   1, .cur_input =                                  kButton_Right, .new_input =                    kButton_Right };
    case 0x99ba: return (DemoInputEntry){ .timer =   5, .cur_input =                                  kButton_Right, .new_input =                                0 };
    case 0x99c0: return (DemoInputEntry){ .timer = 256, .cur_input =                                              0, .new_input =                                0 };
    case 0x99c6: return (DemoInputEntry){ .func_ptr = FUNC16(DemoInstr_Finish), .instr_list_ptr = 0 };
    case 0x99c8: return (DemoInputEntry){ .timer =  63, .cur_input =                                              0, .new_input =                                0 };
    case 0x99ce: return (DemoInputEntry){ .timer =   1, .cur_input =                                  kButton_Right, .new_input =                    kButton_Right };
    case 0x99d4: return (DemoInputEntry){ .timer =   5, .cur_input =                                  kButton_Right, .new_input =                                0 };
    case 0x99da: return (DemoInputEntry){ .timer =  30, .cur_input =                                              0, .new_input =                                0 };
    case 0x99e0: return (DemoInputEntry){ .timer =   1, .cur_input =                                   kButton_Left, .new_input =                     kButton_Left };
    case 0x99e6: return (DemoInputEntry){ .timer =   5, .cur_input =                                   kButton_Left, .new_input =                                0 };
    case 0x99ec: return (DemoInputEntry){ .timer =  22, .cur_input =                                              0, .new_input =                                0 };
    case 0x99f2: return (DemoInputEntry){ .timer =   1, .cur_input =                                 kButton_Select, .new_input =                   kButton_Select };
    case 0x99f8: return (DemoInputEntry){ .timer =   4, .cur_input =                                 kButton_Select, .new_input =                                0 };
    case 0x99fe: return (DemoInputEntry){ .timer =  13, .cur_input =                                              0, .new_input =                                0 };
    case 0x9a04: return (DemoInputEntry){ .timer =   1, .cur_input =                                 kButton_Select, .new_input =                   kButton_Select };
    case 0x9a0a: return (DemoInputEntry){ .timer =   5, .cur_input =                                 kButton_Select, .new_input =                                0 };
    case 0x9a10: return (DemoInputEntry){ .timer =   8, .cur_input =                                              0, .new_input =                                0 };
    case 0x9a16: return (DemoInputEntry){ .timer =   1, .cur_input =                                 kButton_Select, .new_input =                   kButton_Select };
    case 0x9a1c: return (DemoInputEntry){ .timer =   6, .cur_input =                                 kButton_Select, .new_input =                                0 };
    case 0x9a22: return (DemoInputEntry){ .timer =   7, .cur_input =                                              0, .new_input =                                0 };
    case 0x9a28: return (DemoInputEntry){ .timer =   1, .cur_input =                                 kButton_Select, .new_input =                   kButton_Select };
    case 0x9a2e: return (DemoInputEntry){ .timer =   5, .cur_input =                                 kButton_Select, .new_input =                                0 };
    case 0x9a34: return (DemoInputEntry){ .timer =  47, .cur_input =                                              0, .new_input =                                0 };
    case 0x9a3a: return (DemoInputEntry){ .timer =   1, .cur_input =                                   kButton_Left, .new_input =                     kButton_Left };
    case 0x9a40: return (DemoInputEntry){ .timer =  20, .cur_input =                                   kButton_Left, .new_input =                                0 };
    case 0x9a46: return (DemoInputEntry){ .timer =   2, .cur_input =                                              0, .new_input =                                0 };
    case 0x9a4c: return (DemoInputEntry){ .timer =   1, .cur_input =                                  kButton_Right, .new_input =                    kButton_Right };
    case 0x9a52: return (DemoInputEntry){ .timer =   6, .cur_input =                                  kButton_Right, .new_input =                                0 };
    case 0x9a58: return (DemoInputEntry){ .timer =   9, .cur_input =                                              0, .new_input =                                0 };
    case 0x9a5e: return (DemoInputEntry){ .timer =   1, .cur_input =                                      kButton_X, .new_input =                        kButton_X };
    case 0x9a64: return (DemoInputEntry){ .timer =  25, .cur_input =                                      kButton_X, .new_input =                                0 };
    case 0x9a6a: return (DemoInputEntry){ .timer =   1, .cur_input =                         kButton_X+kButton_Down, .new_input =                     kButton_Down };
    case 0x9a70: return (DemoInputEntry){ .timer =   5, .cur_input =                         kButton_X+kButton_Down, .new_input =                                0 };
    case 0x9a76: return (DemoInputEntry){ .timer =   1, .cur_input =           kButton_X+kButton_Right+kButton_Down, .new_input =                    kButton_Right };
    case 0x9a7c: return (DemoInputEntry){ .timer =   2, .cur_input =           kButton_X+kButton_Right+kButton_Down, .new_input =                                0 };
    case 0x9a82: return (DemoInputEntry){ .timer =   6, .cur_input =                        kButton_X+kButton_Right, .new_input =                                0 };
    case 0x9a88: return (DemoInputEntry){ .timer =  39, .cur_input =                                      kButton_X, .new_input =                                0 };
    case 0x9a8e: return (DemoInputEntry){ .timer =   1, .cur_input =                         kButton_X+kButton_Left, .new_input =                     kButton_Left };
    case 0x9a94: return (DemoInputEntry){ .timer =  13, .cur_input =                         kButton_X+kButton_Left, .new_input =                                0 };
    case 0x9a9a: return (DemoInputEntry){ .timer =  52, .cur_input =                                      kButton_X, .new_input =                                0 };
    case 0x9aa0: return (DemoInputEntry){ .timer =   1, .cur_input =                        kButton_X+kButton_Right, .new_input =                    kButton_Right };
    case 0x9aa6: return (DemoInputEntry){ .timer =   7, .cur_input =                        kButton_X+kButton_Right, .new_input =                                0 };
    case 0x9aac: return (DemoInputEntry){ .timer =  55, .cur_input =                                      kButton_X, .new_input =                                0 };
    case 0x9ab2: return (DemoInputEntry){ .timer =   1, .cur_input =                         kButton_X+kButton_Left, .new_input =                     kButton_Left };
    case 0x9ab8: return (DemoInputEntry){ .timer =  15, .cur_input =                         kButton_X+kButton_Left, .new_input =                                0 };
    case 0x9abe: return (DemoInputEntry){ .timer =  47, .cur_input =                                      kButton_X, .new_input =                                0 };
    case 0x9ac4: return (DemoInputEntry){ .timer =   1, .cur_input =                        kButton_X+kButton_Right, .new_input =                    kButton_Right };
    case 0x9aca: return (DemoInputEntry){ .timer = 177, .cur_input =                        kButton_X+kButton_Right, .new_input =                                0 };
    case 0x9ad0: return (DemoInputEntry){ .timer =   1, .cur_input =              kButton_X+kButton_A+kButton_Right, .new_input =                        kButton_A };
    case 0x9ad6: return (DemoInputEntry){ .timer =  11, .cur_input =              kButton_X+kButton_A+kButton_Right, .new_input =                                0 };
    case 0x9adc: return (DemoInputEntry){ .timer = 186, .cur_input =                        kButton_A+kButton_Right, .new_input =                                0 };
    case 0x9ae2: return (DemoInputEntry){ .timer =   3, .cur_input =                                  kButton_Right, .new_input =                                0 };
    case 0x9ae8: return (DemoInputEntry){ .timer =  70, .cur_input =                                              0, .new_input =                                0 };
    case 0x9aee: return (DemoInputEntry){ .func_ptr = FUNC16(DemoInstr_Finish), .instr_list_ptr = 0 };
    case 0x9af0: return (DemoInputEntry){ .timer =  25, .cur_input =                                              0, .new_input =                                0 };
    case 0x9af6: return (DemoInputEntry){ .timer =   1, .cur_input =                                  kButton_Right, .new_input =                    kButton_Right };
    case 0x9afc: return (DemoInputEntry){ .timer =  34, .cur_input =                                  kButton_Right, .new_input =                                0 };
    case 0x9b02: return (DemoInputEntry){ .timer =  24, .cur_input =                                              0, .new_input =                                0 };
    case 0x9b08: return (DemoInputEntry){ .timer =   1, .cur_input =                                      kButton_A, .new_input =                        kButton_A };
    case 0x9b0e: return (DemoInputEntry){ .timer =  11, .cur_input =                                      kButton_A, .new_input =                                0 };
    case 0x9b14: return (DemoInputEntry){ .timer =   1, .cur_input =                         kButton_A+kButton_Down, .new_input =                     kButton_Down };
    case 0x9b1a: return (DemoInputEntry){ .timer =   7, .cur_input =                         kButton_A+kButton_Down, .new_input =                                0 };
    case 0x9b20: return (DemoInputEntry){ .timer =   2, .cur_input =                                      kButton_A, .new_input =                                0 };
    case 0x9b26: return (DemoInputEntry){ .timer =   1, .cur_input =                         kButton_A+kButton_Down, .new_input =                     kButton_Down };
    case 0x9b2c: return (DemoInputEntry){ .timer =   8, .cur_input =                         kButton_A+kButton_Down, .new_input =                                0 };
    case 0x9b32: return (DemoInputEntry){ .timer =   1, .cur_input =               kButton_X+kButton_A+kButton_Down, .new_input =                        kButton_X };
    case 0x9b38: return (DemoInputEntry){ .timer =   3, .cur_input =               kButton_X+kButton_A+kButton_Down, .new_input =                                0 };
    case 0x9b3e: return (DemoInputEntry){ .timer =  10, .cur_input =                            kButton_X+kButton_A, .new_input =                                0 };
    case 0x9b44: return (DemoInputEntry){ .timer =   2, .cur_input =                                      kButton_A, .new_input =                                0 };
    case 0x9b4a: return (DemoInputEntry){ .timer =  32, .cur_input =                                              0, .new_input =                                0 };
    case 0x9b50: return (DemoInputEntry){ .timer =   1, .cur_input =                                      kButton_X, .new_input =                        kButton_X };
    case 0x9b56: return (DemoInputEntry){ .timer =  11, .cur_input =                                      kButton_X, .new_input =                                0 };
    case 0x9b5c: return (DemoInputEntry){ .timer =  37, .cur_input =                                              0, .new_input =                                0 };
    case 0x9b62: return (DemoInputEntry){ .timer =   1, .cur_input =                                      kButton_X, .new_input =                        kButton_X };
    case 0x9b68: return (DemoInputEntry){ .timer =   9, .cur_input =                                      kButton_X, .new_input =                                0 };
    case 0x9b6e: return (DemoInputEntry){ .timer =  38, .cur_input =                                              0, .new_input =                                0 };
    case 0x9b74: return (DemoInputEntry){ .timer =   1, .cur_input =                                      kButton_X, .new_input =                        kButton_X };
    case 0x9b7a: return (DemoInputEntry){ .timer =   9, .cur_input =                                      kButton_X, .new_input =                                0 };
    case 0x9b80: return (DemoInputEntry){ .timer =  38, .cur_input =                                              0, .new_input =                                0 };
    case 0x9b86: return (DemoInputEntry){ .timer =   1, .cur_input =                                      kButton_X, .new_input =                        kButton_X };
    case 0x9b8c: return (DemoInputEntry){ .timer =   8, .cur_input =                                      kButton_X, .new_input =                                0 };
    case 0x9b92: return (DemoInputEntry){ .timer =  39, .cur_input =                                              0, .new_input =                                0 };
    case 0x9b98: return (DemoInputEntry){ .timer =   1, .cur_input =                                      kButton_X, .new_input =                        kButton_X };
    case 0x9b9e: return (DemoInputEntry){ .timer =   9, .cur_input =                                      kButton_X, .new_input =                                0 };
    case 0x9ba4: return (DemoInputEntry){ .timer =  40, .cur_input =                                              0, .new_input =                                0 };
    case 0x9baa: return (DemoInputEntry){ .timer =   1, .cur_input =                                      kButton_X, .new_input =                        kButton_X };
    case 0x9bb0: return (DemoInputEntry){ .timer =   8, .cur_input =                                      kButton_X, .new_input =                                0 };
    case 0x9bb6: return (DemoInputEntry){ .timer =  40, .cur_input =                                              0, .new_input =                                0 };
    case 0x9bbc: return (DemoInputEntry){ .timer =   1, .cur_input =                                      kButton_X, .new_input =                        kButton_X };
    case 0x9bc2: return (DemoInputEntry){ .timer =   9, .cur_input =                                      kButton_X, .new_input =                                0 };
    case 0x9bc8: return (DemoInputEntry){ .timer =  38, .cur_input =                                              0, .new_input =                                0 };
    case 0x9bce: return (DemoInputEntry){ .timer =   1, .cur_input =                                      kButton_X, .new_input =                        kButton_X };
    case 0x9bd4: return (DemoInputEntry){ .timer =   8, .cur_input =                                      kButton_X, .new_input =                                0 };
    case 0x9bda: return (DemoInputEntry){ .timer =  40, .cur_input =                                              0, .new_input =                                0 };
    case 0x9be0: return (DemoInputEntry){ .timer =   1, .cur_input =                                      kButton_X, .new_input =                        kButton_X };
    case 0x9be6: return (DemoInputEntry){ .timer =   7, .cur_input =                                      kButton_X, .new_input =                                0 };
    case 0x9bec: return (DemoInputEntry){ .timer =  41, .cur_input =                                              0, .new_input =                                0 };
    case 0x9bf2: return (DemoInputEntry){ .timer =   1, .cur_input =                                      kButton_X, .new_input =                        kButton_X };
    case 0x9bf8: return (DemoInputEntry){ .timer =   7, .cur_input =                                      kButton_X, .new_input =                                0 };
    case 0x9bfe: return (DemoInputEntry){ .timer =  41, .cur_input =                                              0, .new_input =                                0 };
    case 0x9c04: return (DemoInputEntry){ .timer =   1, .cur_input =                                      kButton_X, .new_input =                        kButton_X };
    case 0x9c0a: return (DemoInputEntry){ .timer =   7, .cur_input =                                      kButton_X, .new_input =                                0 };
    case 0x9c10: return (DemoInputEntry){ .timer =  40, .cur_input =                                              0, .new_input =                                0 };
    case 0x9c16: return (DemoInputEntry){ .timer =   1, .cur_input =                                      kButton_X, .new_input =                        kButton_X };
    case 0x9c1c: return (DemoInputEntry){ .timer =   8, .cur_input =                                      kButton_X, .new_input =                                0 };
    case 0x9c22: return (DemoInputEntry){ .timer =  39, .cur_input =                                              0, .new_input =                                0 };
    case 0x9c28: return (DemoInputEntry){ .timer =   1, .cur_input =                                      kButton_X, .new_input =                        kButton_X };
    case 0x9c2e: return (DemoInputEntry){ .timer =   7, .cur_input =                                      kButton_X, .new_input =                                0 };
    case 0x9c34: return (DemoInputEntry){ .timer =  42, .cur_input =                                              0, .new_input =                                0 };
    case 0x9c3a: return (DemoInputEntry){ .timer =   1, .cur_input =                                      kButton_X, .new_input =                        kButton_X };
    case 0x9c40: return (DemoInputEntry){ .timer =   7, .cur_input =                                      kButton_X, .new_input =                                0 };
    case 0x9c46: return (DemoInputEntry){ .timer =  42, .cur_input =                                              0, .new_input =                                0 };
    case 0x9c4c: return (DemoInputEntry){ .timer =   1, .cur_input =                                      kButton_X, .new_input =                        kButton_X };
    case 0x9c52: return (DemoInputEntry){ .timer =   7, .cur_input =                                      kButton_X, .new_input =                                0 };
    case 0x9c58: return (DemoInputEntry){ .timer =  40, .cur_input =                                              0, .new_input =                                0 };
    case 0x9c5e: return (DemoInputEntry){ .timer =   1, .cur_input =                                      kButton_X, .new_input =                        kButton_X };
    case 0x9c64: return (DemoInputEntry){ .timer =   7, .cur_input =                                      kButton_X, .new_input =                                0 };
    case 0x9c6a: return (DemoInputEntry){ .timer =  40, .cur_input =                                              0, .new_input =                                0 };
    case 0x9c70: return (DemoInputEntry){ .timer =   1, .cur_input =                                      kButton_X, .new_input =                        kButton_X };
    case 0x9c76: return (DemoInputEntry){ .timer =   7, .cur_input =                                      kButton_X, .new_input =                                0 };
    case 0x9c7c: return (DemoInputEntry){ .timer =  16, .cur_input =                                              0, .new_input =                                0 };
    case 0x9c82: return (DemoInputEntry){ .timer =   1, .cur_input =                                  kButton_Right, .new_input =                    kButton_Right };
    case 0x9c88: return (DemoInputEntry){ .timer =  30, .cur_input =                                  kButton_Right, .new_input =                                0 };
    case 0x9c8e: return (DemoInputEntry){ .timer =  23, .cur_input =                                              0, .new_input =                                0 };
    case 0x9c94: return (DemoInputEntry){ .timer =   1, .cur_input =                                     kButton_Up, .new_input =                       kButton_Up };
    case 0x9c9a: return (DemoInputEntry){ .timer =   9, .cur_input =                                     kButton_Up, .new_input =                                0 };
    case 0x9ca0: return (DemoInputEntry){ .timer =   8, .cur_input =                                              0, .new_input =                                0 };
    case 0x9ca6: return (DemoInputEntry){ .timer =   1, .cur_input =                                     kButton_Up, .new_input =                       kButton_Up };
    case 0x9cac: return (DemoInputEntry){ .timer =   5, .cur_input =                                     kButton_Up, .new_input =                                0 };
    case 0x9cb2: return (DemoInputEntry){ .timer =   1, .cur_input =                                              0, .new_input =                                0 };
    case 0x9cb8: return (DemoInputEntry){ .timer =   1, .cur_input =                                     kButton_Up, .new_input =                       kButton_Up };
    case 0x9cbe: return (DemoInputEntry){ .timer =   9, .cur_input =                                              0, .new_input =                                0 };
    case 0x9cc4: return (DemoInputEntry){ .timer =   1, .cur_input =                                   kButton_Left, .new_input =                     kButton_Left };
    case 0x9cca: return (DemoInputEntry){ .timer =   4, .cur_input =                                   kButton_Left, .new_input =                                0 };
    case 0x9cd0: return (DemoInputEntry){ .timer = 196, .cur_input =                                              0, .new_input =                                0 };
    case 0x9cd6: return (DemoInputEntry){ .func_ptr = FUNC16(DemoInstr_Finish), .instr_list_ptr = 0 };
    case 0x9cd8: return (DemoInputEntry){ .timer =  26, .cur_input =                                              0, .new_input =                                0 };
    case 0x9cde: return (DemoInputEntry){ .timer =   1, .cur_input =                                 kButton_Select, .new_input =                   kButton_Select };
    case 0x9ce4: return (DemoInputEntry){ .timer =   8, .cur_input =                                 kButton_Select, .new_input =                                0 };
    case 0x9cea: return (DemoInputEntry){ .timer =   6, .cur_input =                                              0, .new_input =                                0 };
    case 0x9cf0: return (DemoInputEntry){ .timer =   1, .cur_input =                                 kButton_Select, .new_input =                   kButton_Select };
    case 0x9cf6: return (DemoInputEntry){ .timer =   6, .cur_input =                                 kButton_Select, .new_input =                                0 };
    case 0x9cfc: return (DemoInputEntry){ .timer =   6, .cur_input =                                              0, .new_input =                                0 };
    case 0x9d02: return (DemoInputEntry){ .timer =   1, .cur_input =                                 kButton_Select, .new_input =                   kButton_Select };
    case 0x9d08: return (DemoInputEntry){ .timer =   6, .cur_input =                                 kButton_Select, .new_input =                                0 };
    case 0x9d0e: return (DemoInputEntry){ .timer =   8, .cur_input =                                              0, .new_input =                                0 };
    case 0x9d14: return (DemoInputEntry){ .timer =   1, .cur_input =                                      kButton_A, .new_input =                        kButton_A };
    case 0x9d1a: return (DemoInputEntry){ .timer =   3, .cur_input =                                      kButton_A, .new_input =                                0 };
    case 0x9d20: return (DemoInputEntry){ .timer =   1, .cur_input =                        kButton_A+kButton_Right, .new_input =                    kButton_Right };
    case 0x9d26: return (DemoInputEntry){ .timer =  35, .cur_input =                        kButton_A+kButton_Right, .new_input =                                0 };
    case 0x9d2c: return (DemoInputEntry){ .timer =   7, .cur_input =                                  kButton_Right, .new_input =                                0 };
    case 0x9d32: return (DemoInputEntry){ .timer =  16, .cur_input =                                              0, .new_input =                                0 };
    case 0x9d38: return (DemoInputEntry){ .timer =   1, .cur_input =                                      kButton_A, .new_input =                        kButton_A };
    case 0x9d3e: return (DemoInputEntry){ .timer =  16, .cur_input =                                      kButton_A, .new_input =                                0 };
    case 0x9d44: return (DemoInputEntry){ .timer =   1, .cur_input =                         kButton_A+kButton_Left, .new_input =                     kButton_Left };
    case 0x9d4a: return (DemoInputEntry){ .timer =   7, .cur_input =                         kButton_A+kButton_Left, .new_input =                                0 };
    case 0x9d50: return (DemoInputEntry){ .timer =   1, .cur_input =               kButton_X+kButton_A+kButton_Left, .new_input =                        kButton_X };
    case 0x9d56: return (DemoInputEntry){ .timer =   4, .cur_input =               kButton_X+kButton_A+kButton_Left, .new_input =                                0 };
    case 0x9d5c: return (DemoInputEntry){ .timer =  14, .cur_input =                         kButton_X+kButton_Left, .new_input =                                0 };
    case 0x9d62: return (DemoInputEntry){ .timer =  16, .cur_input =                                      kButton_X, .new_input =                                0 };
    case 0x9d68: return (DemoInputEntry){ .timer =   1, .cur_input =                            kButton_X+kButton_A, .new_input =                        kButton_A };
    case 0x9d6e: return (DemoInputEntry){ .timer =   8, .cur_input =                            kButton_X+kButton_A, .new_input =                                0 };
    case 0x9d74: return (DemoInputEntry){ .timer =   1, .cur_input =              kButton_X+kButton_A+kButton_Right, .new_input =                    kButton_Right };
    case 0x9d7a: return (DemoInputEntry){ .timer =  11, .cur_input =              kButton_X+kButton_A+kButton_Right, .new_input =                                0 };
    case 0x9d80: return (DemoInputEntry){ .timer =  20, .cur_input =                        kButton_X+kButton_Right, .new_input =                                0 };
    case 0x9d86: return (DemoInputEntry){ .timer =  21, .cur_input =                                      kButton_X, .new_input =                                0 };
    case 0x9d8c: return (DemoInputEntry){ .timer =   1, .cur_input =                         kButton_X+kButton_Down, .new_input =                     kButton_Down };
    case 0x9d92: return (DemoInputEntry){ .timer =   6, .cur_input =                         kButton_X+kButton_Down, .new_input =                                0 };
    case 0x9d98: return (DemoInputEntry){ .timer =  64, .cur_input =                                      kButton_X, .new_input =                                0 };
    case 0x9d9e: return (DemoInputEntry){ .timer =  52, .cur_input =                                              0, .new_input =                                0 };
    case 0x9da4: return (DemoInputEntry){ .func_ptr = FUNC16(DemoInstr_Finish), .instr_list_ptr = 0 };
    case 0x9da6: return (DemoInputEntry){ .timer = 405, .cur_input =                                              0, .new_input =                                0 };
    case 0x9dac: return (DemoInputEntry){ .func_ptr = FUNC16(DemoInstr_Finish), .instr_list_ptr = 0 };
    case 0x9dae: return (DemoInputEntry){ .timer =  27, .cur_input =                                              0, .new_input =                                0 };
    case 0x9db4: return (DemoInputEntry){ .timer =   1, .cur_input =                                   kButton_Down, .new_input =                     kButton_Down };
    case 0x9dba: return (DemoInputEntry){ .timer =   5, .cur_input =                                   kButton_Down, .new_input =                                0 };
    case 0x9dc0: return (DemoInputEntry){ .timer =   5, .cur_input =                                              0, .new_input =                                0 };
    case 0x9dc6: return (DemoInputEntry){ .timer =   1, .cur_input =                                   kButton_Down, .new_input =                     kButton_Down };
    case 0x9dcc: return (DemoInputEntry){ .timer =   7, .cur_input =                                   kButton_Down, .new_input =                                0 };
    case 0x9dd2: return (DemoInputEntry){ .timer =   9, .cur_input =                                              0, .new_input =                                0 };
    case 0x9dd8: return (DemoInputEntry){ .timer =   1, .cur_input =                                 kButton_Select, .new_input =                   kButton_Select };
    case 0x9dde: return (DemoInputEntry){ .timer =   6, .cur_input =                                 kButton_Select, .new_input =                                0 };
    case 0x9de4: return (DemoInputEntry){ .timer =   6, .cur_input =                                              0, .new_input =                                0 };
    case 0x9dea: return (DemoInputEntry){ .timer =   1, .cur_input =                                 kButton_Select, .new_input =                   kButton_Select };
    case 0x9df0: return (DemoInputEntry){ .timer =   5, .cur_input =                                 kButton_Select, .new_input =                                0 };
    case 0x9df6: return (DemoInputEntry){ .timer =   8, .cur_input =                                              0, .new_input =                                0 };
    case 0x9dfc: return (DemoInputEntry){ .timer =   1, .cur_input =                                 kButton_Select, .new_input =                   kButton_Select };
    case 0x9e02: return (DemoInputEntry){ .timer =   7, .cur_input =                                 kButton_Select, .new_input =                                0 };
    case 0x9e08: return (DemoInputEntry){ .timer =  49, .cur_input =                                              0, .new_input =                                0 };
    case 0x9e0e: return (DemoInputEntry){ .timer =   1, .cur_input =               kButton_R+kButton_L+kButton_Down, .new_input = kButton_R+kButton_L+kButton_Down };
    case 0x9e14: return (DemoInputEntry){ .timer =   9, .cur_input =               kButton_R+kButton_L+kButton_Down, .new_input =                                0 };
    case 0x9e1a: return (DemoInputEntry){ .timer =   1, .cur_input =     kButton_R+kButton_L+kButton_X+kButton_Down, .new_input =                        kButton_X };
    case 0x9e20: return (DemoInputEntry){ .timer =  16, .cur_input =     kButton_R+kButton_L+kButton_X+kButton_Down, .new_input =                                0 };
    case 0x9e26: return (DemoInputEntry){ .timer =  30, .cur_input =               kButton_R+kButton_L+kButton_Down, .new_input =                                0 };
    case 0x9e2c: return (DemoInputEntry){ .timer =   1, .cur_input =     kButton_R+kButton_L+kButton_X+kButton_Down, .new_input =                        kButton_X };
    case 0x9e32: return (DemoInputEntry){ .timer = 190, .cur_input =     kButton_R+kButton_L+kButton_X+kButton_Down, .new_input =                                0 };
    case 0x9e38: return (DemoInputEntry){ .timer =   3, .cur_input =                  kButton_R+kButton_L+kButton_X, .new_input =                                0 };
    case 0x9e3e: return (DemoInputEntry){ .timer =   1, .cur_input =                            kButton_R+kButton_L, .new_input =                                0 };
    case 0x9e44: return (DemoInputEntry){ .timer =   1, .cur_input =                                      kButton_R, .new_input =                                0 };
    case 0x9e4a: return (DemoInputEntry){ .timer = 316, .cur_input =                                              0, .new_input =                                0 };
    case 0x9e50: return (DemoInputEntry){ .func_ptr = FUNC16(DemoInstr_Finish), .instr_list_ptr = 0 };
    default: return (DemoInputEntry){ Unreachable() };
  }
}


const uint8 kSamusAnimationDelayData_09[24] = {  // 0x91B20A
  2, 3, 2, 3, 2, 3, 2, 3, 2, 3, 0xff,
  4, 4, 4, 4, 4, 4, 3, 4, 4, 3, 0xff,
  10, 0xff,
 };

const uint8 kSamusAnimationDelayData_03[4] = {  // 0x91B222
  2, 16, 0xfe,1,
 };

const uint8 kSamusAnimationDelayData_49[7] = {  // 0x91B226
  16, 16, 16, 16, 16, 16, 0xff,
 };

const uint8 kSamusAnimationDelayData_A4[4] = {  // 0x91B22D
  5, 2, 0xf8,kPose_01_FaceR_Normal,
 };

const uint8 kSamusAnimationDelayData_A5[4] = {  // 0x91B231
  5, 2, 0xf8,kPose_02_FaceL_Normal,
 };

const uint8 kSamusAnimationDelayData_A6[5] = {  // 0x91B235
  3, 5, 2, 0xf8,kPose_01_FaceR_Normal,
 };

const uint8 kSamusAnimationDelayData_A7[5] = {  // 0x91B23A
  3, 5, 2, 0xf8,kPose_02_FaceL_Normal,
 };

const uint8 kSamusAnimationDelayData_E0[4] = {  // 0x91B23F
  5, 2, 0xf8,kPose_03_FaceR_AimU,
 };

const uint8 kSamusAnimationDelayData_E1[4] = {  // 0x91B243
  5, 2, 0xf8,kPose_04_FaceL_AimU,
 };

const uint8 kSamusAnimationDelayData_E2[4] = {  // 0x91B247
  5, 2, 0xf8,kPose_05_FaceR_AimUR,
 };

const uint8 kSamusAnimationDelayData_E3[4] = {  // 0x91B24B
  5, 2, 0xf8,kPose_06_FaceL_AimUL,
 };

const uint8 kSamusAnimationDelayData_E4[4] = {  // 0x91B24F
  5, 2, 0xf8,kPose_07_FaceR_AimDR,
 };

const uint8 kSamusAnimationDelayData_E5[4] = {  // 0x91B253
  5, 2, 0xf8,kPose_08_FaceL_AimDL,
 };

const uint8 kSamusAnimationDelayData_E8[17] = {  // 0x91B257
  2, 2, 2, 16, 0xf7,
  1, 0xfe,1,
  16, 16, 16, 16, 0xfe,4,
  3, 0xfd,kPose_01_FaceR_Normal,
 };

const uint8 kSamusAnimationDelayData_E9[32] = {  // 0x91B268
  2, 2, 16, 0xf7,
  1, 0xfe,1,
  8, 16, 16, 16, 16, 0xfe,4,
  16, 16, 16, 0xfd,kPose_02_FaceL_Normal,
  16, 16, 16, 16, 16, 0xfe,14,
  16, 0xfe,17,
  16, 0xfe,1,
 };

const uint8 kSamusAnimationDelayData_EA[8] = {  // 0x91B288
  16, 16, 16, 16, 0xff,
  3, 0xfd,kPose_01_FaceR_Normal,
 };

const uint8 kSamusAnimationDelayData_EB[8] = {  // 0x91B290
  16, 16, 16, 16, 0xff,
  3, 0xfd,kPose_02_FaceL_Normal,
 };

const uint8 kSamusAnimationDelayData_01[11] = {  // 0x91B298
  10, 10, 10, 10, 0xf6,
  8, 8, 8, 8, 0xfe,4,
 };

const uint8 kSamusAnimationDelayData_27[11] = {  // 0x91B2A3
  10, 10, 10, 10, 0xf6,
  8, 8, 8, 8, 0xfe,4,
 };

const uint8 kSamusAnimationDelayData_D5[6] = {  // 0x91B2AE
  15, 15, 15, 15, 15, 0xff,
 };

const uint8 kSamusAnimationDelayData_05[2] = {  // 0x91B2B4
  16, 0xff,
 };

const uint8 kSamusAnimationDelayData_A8[2] = {  // 0x91B2B6
  16, 0xff,
 };

const uint8 kSamusAnimationDelayData_AC[4] = {  // 0x91B2B8
  2, 16, 0xfe,1,
 };

const uint8 kSamusAnimationDelayData_AE[4] = {  // 0x91B2BC
  2, 16, 0xfe,1,
 };

const uint8 kSamusAnimationDelayData_B0[4] = {  // 0x91B2C0
  2, 16, 0xfe,1,
 };

const uint8 kSamusAnimationDelayData_B2[68] = {  // 0x91B2C4
  8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
  8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
  8, 8, 0xfe,1,
 };

const uint8 kSamusAnimationDelayData_4B[3] = {  // 0x91B308
  1, 0xfd,kPose_4D_FaceR_Jump_NoAim_NoMove_NoGun,
 };

const uint8 kSamusAnimationDelayData_4C[3] = {  // 0x91B30B
  1, 0xfd,kPose_4E_FaceL_Jump_NoAim_NoMove_NoGun,
 };

const uint8 kSamusAnimationDelayData_55[4] = {  // 0x91B30E
  1, 0xfd,kPose_15_FaceR_Jump_AimU,
  0,};

const uint8 kSamusAnimationDelayData_56[4] = {  // 0x91B312
  1, 0xfd,kPose_16_FaceL_Jump_AimU,
  0,};

const uint8 kSamusAnimationDelayData_57[4] = {  // 0x91B316
  1, 0xfd,kPose_69_FaceR_Jump_AimUR,
  0,};

const uint8 kSamusAnimationDelayData_58[4] = {  // 0x91B31A
  1, 0xfd,kPose_6A_FaceL_Jump_AimUL,
  0,};

const uint8 kSamusAnimationDelayData_59[4] = {  // 0x91B31E
  1, 0xfd,kPose_6B_FaceR_Jump_AimDR,
  0,};

const uint8 kSamusAnimationDelayData_5A[4] = {  // 0x91B322
  1, 0xfd,kPose_6C_FaceL_Jump_AimDL,
  0,};

const uint8 kSamusAnimationDelayData_4D[8] = {  // 0x91B326
  3, 4, 4, 4, 4, 80, 0xfe,1,
 };

const uint8 kSamusAnimationDelayData_4F[12] = {  // 0x91B32E
  8, 2, 2, 2, 2, 2, 2, 2, 2, 2, 0xfe,1,
 };

const uint8 kSamusAnimationDelayData_15[4] = {  // 0x91B33A
  2, 16, 0xfe,1,
 };

const uint8 kSamusAnimationDelayData_17[4] = {  // 0x91B33E
  2, 16, 0xfe,1,
 };

const uint8 kSamusAnimationDelayData_51[4] = {  // 0x91B342
  2, 3, 0xfe,1,
 };

const uint8 kSamusAnimationDelayData_13[4] = {  // 0x91B346
  2, 16, 0xfe,1,
 };

const uint8 kSamusAnimationDelayData_29[9] = {  // 0x91B34A
  8, 6, 6, 0xfe,1,
  8, 16, 0xfe,1,
 };

const uint8 kSamusAnimationDelayData_67[9] = {  // 0x91B353
  8, 6, 6, 0xfe,1,
  8, 16, 0xfe,1,
 };

const uint8 kSamusAnimationDelayData_2B[5] = {  // 0x91B35C
  2, 16, 16, 0xfe,1,
 };

const uint8 kSamusAnimationDelayData_6D[5] = {  // 0x91B361
  2, 0xf0,
  16, 0xfe,1,
 };

const uint8 kSamusAnimationDelayData_2D[4] = {  // 0x91B366
  2, 16, 0xfe,1,
 };

const uint8 kSamusAnimationDelayData_53[14] = {  // 0x91B36A
  2, 16, 0xfe,1,
  6, 6, 6, 8, 0xff,
  8, 8, 0xff,
  10, 0xff,
 };

const uint8 kSamusAnimationDelayData_1D[12] = {  // 0x91B378
  3, 3, 3, 3, 3, 3, 3, 3, 0xff,
  3, 0xfe,10,
 };

const uint8 kSamusAnimationDelayData_19[13] = {  // 0x91B384
  4, 3, 2, 3, 2, 3, 2, 3, 2, 0xfe,8,
  8, 0xff,
 };

const uint8 kSamusAnimationDelayData_1B[13] = {  // 0x91B391
  4, 1, 1, 1, 1, 1, 1, 1, 1, 0xfe,8,
  8, 0xff,
 };

const uint8 kSamusAnimationDelayData_81[29] = {  // 0x91B39E
  4, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0xfe,24,
  8, 0xff,
 };

const uint8 kSamusAnimationDelayData_25[5] = {  // 0x91B3BB
  2, 2, 2, 0xf8,kPose_02_FaceL_Normal,
 };

const uint8 kSamusAnimationDelayData_26[5] = {  // 0x91B3C0
  2, 2, 2, 0xf8,kPose_01_FaceR_Normal,
 };

const uint8 kSamusAnimationDelayData_2F[5] = {  // 0x91B3C5
  2, 2, 2, 0xf8,kPose_52_FaceL_Jump_NoAim_MoveF,
 };

const uint8 kSamusAnimationDelayData_30[5] = {  // 0x91B3CA
  2, 2, 2, 0xf8,kPose_51_FaceR_Jump_NoAim_MoveF,
 };

const uint8 kSamusAnimationDelayData_43[5] = {  // 0x91B3CF
  2, 2, 2, 0xf8,kPose_28_FaceL_Crouch,
 };

const uint8 kSamusAnimationDelayData_44[5] = {  // 0x91B3D4
  2, 2, 2, 0xf8,kPose_27_FaceR_Crouch,
 };

const uint8 kSamusAnimationDelayData_87[5] = {  // 0x91B3D9
  2, 2, 2, 0xf8,kPose_2A_FaceL_Fall,
 };

const uint8 kSamusAnimationDelayData_88[5] = {  // 0x91B3DE
  2, 2, 2, 0xf8,kPose_29_FaceR_Fall,
 };

const uint8 kSamusAnimationDelayData_8B[5] = {  // 0x91B3E3
  2, 2, 2, 0xf8,kPose_04_FaceL_AimU,
 };

const uint8 kSamusAnimationDelayData_8C[5] = {  // 0x91B3E8
  2, 2, 2, 0xf8,kPose_03_FaceR_AimU,
 };

const uint8 kSamusAnimationDelayData_8D[5] = {  // 0x91B3ED
  2, 2, 2, 0xf8,kPose_08_FaceL_AimDL,
 };

const uint8 kSamusAnimationDelayData_8E[5] = {  // 0x91B3F2
  2, 2, 2, 0xf8,kPose_07_FaceR_AimDR,
 };

const uint8 kSamusAnimationDelayData_8F[5] = {  // 0x91B3F7
  2, 2, 2, 0xf8,kPose_16_FaceL_Jump_AimU,
 };

const uint8 kSamusAnimationDelayData_90[5] = {  // 0x91B3FC
  2, 2, 2, 0xf8,kPose_15_FaceR_Jump_AimU,
 };

const uint8 kSamusAnimationDelayData_91[5] = {  // 0x91B401
  2, 2, 2, 0xf8,kPose_18_FaceL_Jump_AimD,
 };

const uint8 kSamusAnimationDelayData_92[5] = {  // 0x91B406
  2, 2, 2, 0xf8,kPose_17_FaceR_Jump_AimD,
 };

const uint8 kSamusAnimationDelayData_93[5] = {  // 0x91B40B
  2, 2, 2, 0xf8,kPose_2C_FaceL_Fall_AimU,
 };

const uint8 kSamusAnimationDelayData_94[5] = {  // 0x91B410
  2, 2, 2, 0xf8,kPose_2B_FaceR_Fall_AimU,
 };

const uint8 kSamusAnimationDelayData_95[5] = {  // 0x91B415
  2, 2, 2, 0xf8,kPose_2E_FaceL_Fall_AimD,
 };

const uint8 kSamusAnimationDelayData_96[5] = {  // 0x91B41A
  2, 2, 2, 0xf8,kPose_2D_FaceR_Fall_AimD,
 };

const uint8 kSamusAnimationDelayData_97[5] = {  // 0x91B41F
  2, 2, 2, 0xf8,kPose_86_FaceL_Crouch_AimU,
 };

const uint8 kSamusAnimationDelayData_98[5] = {  // 0x91B424
  2, 2, 2, 0xf8,kPose_85_FaceR_Crouch_AimU,
 };

const uint8 kSamusAnimationDelayData_99[5] = {  // 0x91B429
  2, 2, 2, 0xf8,kPose_74_FaceL_Crouch_AimDL,
 };

const uint8 kSamusAnimationDelayData_9A[5] = {  // 0x91B42E
  2, 2, 2, 0xf8,kPose_73_FaceR_Crouch_AimDR,
 };

const uint8 kSamusAnimationDelayData_9C[5] = {  // 0x91B433
  2, 2, 2, 0xf8,kPose_06_FaceL_AimUL,
 };

const uint8 kSamusAnimationDelayData_9D[5] = {  // 0x91B438
  2, 2, 2, 0xf8,kPose_05_FaceR_AimUR,
 };

const uint8 kSamusAnimationDelayData_9E[5] = {  // 0x91B43D
  2, 2, 2, 0xf8,kPose_6A_FaceL_Jump_AimUL,
 };

const uint8 kSamusAnimationDelayData_9F[5] = {  // 0x91B442
  2, 2, 2, 0xf8,kPose_69_FaceR_Jump_AimUR,
 };

const uint8 kSamusAnimationDelayData_A0[5] = {  // 0x91B447
  2, 2, 2, 0xf8,kPose_6E_FaceL_Fall_AimUL,
 };

const uint8 kSamusAnimationDelayData_A1[5] = {  // 0x91B44C
  2, 2, 2, 0xf8,kPose_6D_FaceR_Fall_AimUR,
 };

const uint8 kSamusAnimationDelayData_A2[5] = {  // 0x91B451
  2, 2, 2, 0xf8,kPose_72_FaceL_Crouch_AimUL,
 };

const uint8 kSamusAnimationDelayData_A3[5] = {  // 0x91B456
  2, 2, 2, 0xf8,kPose_71_FaceR_Crouch_AimUR,
 };

const uint8 kSamusAnimationDelayData_BF[5] = {  // 0x91B45B
  2, 2, 2, 0xf8,kPose_1A_FaceL_SpinJump,
 };

const uint8 kSamusAnimationDelayData_C0[5] = {  // 0x91B460
  2, 2, 2, 0xf8,kPose_19_FaceR_SpinJump,
 };

const uint8 kSamusAnimationDelayData_C1[5] = {  // 0x91B465
  2, 2, 2, 0xf8,kPose_1A_FaceL_SpinJump,
 };

const uint8 kSamusAnimationDelayData_C2[5] = {  // 0x91B46A
  2, 2, 2, 0xf8,kPose_19_FaceR_SpinJump,
 };

const uint8 kSamusAnimationDelayData_C3[5] = {  // 0x91B46F
  2, 2, 2, 0xf8,kPose_1A_FaceL_SpinJump,
 };

const uint8 kSamusAnimationDelayData_C4[5] = {  // 0x91B474
  2, 2, 2, 0xf8,kPose_19_FaceR_SpinJump,
 };

const uint8 kSamusAnimationDelayData_C6[5] = {  // 0x91B479
  2, 2, 2, 0xfd,kPose_BA_FaceL_Draygon_NoMove_NoAim,
 };

const uint8 kSamusAnimationDelayData_63[4] = {  // 0x91B47E
  4, 3, 0xfe,1,
 };

const uint8 kSamusAnimationDelayData_64[4] = {  // 0x91B482
  4, 3, 0xfe,1,
 };

const uint8 kSamusAnimationDelayData_65[11] = {  // 0x91B486
  3, 2, 2, 2, 2, 2, 2, 2, 2, 0xfe,8,
 };

const uint8 kSamusAnimationDelayData_83[49] = {  // 0x91B491
  5, 5, 0xfb,
  3, 2, 3, 2, 3, 2, 3, 2, 0xfe,8,
  2, 1, 2, 1, 2, 1, 2, 1, 0xfe,8,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0xfe,24,
 };

const uint8 kSamusAnimationDelayData_35[3] = {  // 0x91B4C2
  3, 0xfd,kPose_27_FaceR_Crouch,
 };

const uint8 kSamusAnimationDelayData_36[3] = {  // 0x91B4C5
  3, 0xfd,kPose_28_FaceL_Crouch,
 };

const uint8 kSamusAnimationDelayData_37[9] = {  // 0x91B4C8
  3, 3, 0xf9,kItem_SpringBall,kPose_00_FaceF_Powersuit,kPose_1D_FaceR_Morphball_Ground,kPose_31_FaceR_Morphball_Air,kPose_79_FaceR_Springball_Ground,
  125,};

const uint8 kSamusAnimationDelayData_38[9] = {  // 0x91B4D1
  3, 3, 0xf9,kItem_SpringBall,kPose_00_FaceF_Powersuit,kPose_41_FaceL_Morphball_Ground,kPose_32_FaceL_Morphball_Air,kPose_7A_FaceL_Springball_Ground,
  126,};

const uint8 kSamusAnimationDelayData_39[3] = {  // 0x91B4DA
  0, 0xfd,kPose_20,
 };

const uint8 kSamusAnimationDelayData_3A[3] = {  // 0x91B4DD
  0, 0xfd,kPose_42,
 };

const uint8 kSamusAnimationDelayData_3B[3] = {  // 0x91B4E0
  3, 0xfd,kPose_01_FaceR_Normal,
 };

const uint8 kSamusAnimationDelayData_3C[3] = {  // 0x91B4E3
  3, 0xfd,kPose_02_FaceL_Normal,
 };

const uint8 kSamusAnimationDelayData_3D[4] = {  // 0x91B4E6
  3, 3, 0xfd,kPose_27_FaceR_Crouch,
 };

const uint8 kSamusAnimationDelayData_3E[4] = {  // 0x91B4EA
  3, 3, 0xfd,kPose_28_FaceL_Crouch,
 };

const uint8 kSamusAnimationDelayData_3F[6] = {  // 0x91B4EE
  0, 0xfc,kItem_SpringBall,kPose_00_FaceF_Powersuit,kPose_1D_FaceR_Morphball_Ground,
  121,};

const uint8 kSamusAnimationDelayData_40[6] = {  // 0x91B4F4
  0, 0xfc,kItem_SpringBall,kPose_00_FaceF_Powersuit,kPose_41_FaceL_Morphball_Ground,
  122,};

const uint8 kSamusAnimationDelayData_DB[10] = {  // 0x91B4FA
  3, 3, 3, 0xf9,kItem_SpringBall,kPose_00_FaceF_Powersuit,kPose_1D_FaceR_Morphball_Ground,kPose_31_FaceR_Morphball_Air,kPose_79_FaceR_Springball_Ground,
  125,};

const uint8 kSamusAnimationDelayData_DC[10] = {  // 0x91B504
  3, 3, 3, 0xf9,kItem_SpringBall,kPose_00_FaceF_Powersuit,kPose_DF,kPose_DF,kPose_DF,
  223,};

const uint8 kSamusAnimationDelayData_DD[5] = {  // 0x91B50E
  3, 3, 3, 0xfd,kPose_01_FaceR_Normal,
 };

const uint8 kSamusAnimationDelayData_DE[5] = {  // 0x91B513
  3, 3, 3, 0xfd,kPose_BA_FaceL_Draygon_NoMove_NoAim,
 };

const uint8 kSamusAnimationDelayData_F1[3] = {  // 0x91B518
  3, 0xfd,kPose_85_FaceR_Crouch_AimU,
 };

const uint8 kSamusAnimationDelayData_F2[3] = {  // 0x91B51B
  3, 0xfd,kPose_86_FaceL_Crouch_AimU,
 };

const uint8 kSamusAnimationDelayData_F3[3] = {  // 0x91B51E
  3, 0xfd,kPose_71_FaceR_Crouch_AimUR,
 };

const uint8 kSamusAnimationDelayData_F4[3] = {  // 0x91B521
  3, 0xfd,kPose_72_FaceL_Crouch_AimUL,
 };

const uint8 kSamusAnimationDelayData_F5[3] = {  // 0x91B524
  3, 0xfd,kPose_73_FaceR_Crouch_AimDR,
 };

const uint8 kSamusAnimationDelayData_F6[3] = {  // 0x91B527
  3, 0xfd,kPose_74_FaceL_Crouch_AimDL,
 };

const uint8 kSamusAnimationDelayData_F7[3] = {  // 0x91B52A
  3, 0xfd,kPose_03_FaceR_AimU,
 };

const uint8 kSamusAnimationDelayData_F8[3] = {  // 0x91B52D
  3, 0xfd,kPose_04_FaceL_AimU,
 };

const uint8 kSamusAnimationDelayData_F9[3] = {  // 0x91B530
  3, 0xfd,kPose_05_FaceR_AimUR,
 };

const uint8 kSamusAnimationDelayData_FA[3] = {  // 0x91B533
  3, 0xfd,kPose_06_FaceL_AimUL,
 };

const uint8 kSamusAnimationDelayData_FB[3] = {  // 0x91B536
  3, 0xfd,kPose_07_FaceR_AimDR,
 };

const uint8 kSamusAnimationDelayData_FC[3] = {  // 0x91B539
  3, 0xfd,kPose_08_FaceL_AimDL,
 };

const uint8 kSamusAnimationDelayData_BE[7] = {  // 0x91B53C
  6, 6, 6, 6, 6, 6, 0xff,
 };

const uint8 kSamusAnimationDelayData_C9[2] = {  // 0x91B543
  8, 0xff,
 };

const uint8 kSamusAnimationDelayData_D3[17] = {  // 0x91B545
  3, 3, 1, 1, 0xfe,2,
  12, 12, 12, 12, 0xfe,4,
  3, 3, 3, 0xfd,kPose_01_FaceR_Normal,
 };

const uint8 kSamusAnimationDelayData_D4[17] = {  // 0x91B556
  3, 3, 1, 1, 0xfe,2,
  12, 12, 12, 12, 0xfe,4,
  3, 3, 3, 0xfd,kPose_02_FaceL_Normal,
 };

const uint8 kSamusAnimationDelayData_D7[8] = {  // 0x91B567
  2, 2, 2, 2, 2, 2, 0xfe,1,
 };

const uint8 kSamusAnimationDelayData_00[98] = {  // 0x91B56F
  8, 0xff,
  3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3,
  3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3,
  3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 51, 2, 2, 2, 48, 0xfe,1,
 };


const uint8 *get_AnimationDelayData(uint16 pose) {
  switch (pose) {
  case kPose_09_MoveR_NoAim:
  case kPose_0A_MoveL_NoAim:
  case kPose_0B_MoveR_Gun:
  case kPose_0C_MoveL_Gun:
  case kPose_0D:
  case kPose_0E:
  case kPose_0F_MoveR_AimUR:
  case kPose_10_MoveL_AimUL:
  case kPose_11_MoveR_AimDR:
  case kPose_12_MoveL_AimDL:
  case kPose_45:
  case kPose_46:
    return kSamusAnimationDelayData_09;
  case kPose_03_FaceR_AimU:
  case kPose_04_FaceL_AimU:
  case kPose_85_FaceR_Crouch_AimU:
  case kPose_86_FaceL_Crouch_AimU:
    return kSamusAnimationDelayData_03;
  case kPose_49_FaceL_Moonwalk:
  case kPose_4A_FaceR_Moonwalk:
  case kPose_75_FaceL_Moonwalk_AimUL:
  case kPose_76_FaceR_Moonwalk_AimUR:
  case kPose_77_FaceL_Moonwalk_AimDL:
  case kPose_78_FaceR_Moonwalk_AimDR:
    return kSamusAnimationDelayData_49;
  case kPose_A4_FaceR_LandJump:
  case kPose_E6_FaceR_LandJump_Fire:
    return kSamusAnimationDelayData_A4;
  case kPose_A5_FaceL_LandJump:
  case kPose_E7_FaceL_LandJump_Fire:
    return kSamusAnimationDelayData_A5;
  case kPose_A6_FaceR_LandSpinJump:
    return kSamusAnimationDelayData_A6;
  case kPose_A7_FaceL_LandSpinJump:
    return kSamusAnimationDelayData_A7;
  case kPose_E0_FaceR_LandJump_AimU:
    return kSamusAnimationDelayData_E0;
  case kPose_E1_FaceL_LandJump_AimU:
    return kSamusAnimationDelayData_E1;
  case kPose_E2_FaceR_LandJump_AimUR:
    return kSamusAnimationDelayData_E2;
  case kPose_E3_FaceL_LandJump_AimUL:
    return kSamusAnimationDelayData_E3;
  case kPose_E4_FaceR_LandJump_AimDR:
    return kSamusAnimationDelayData_E4;
  case kPose_E5_FaceL_LandJump_AimDL:
    return kSamusAnimationDelayData_E5;
  case kPose_E8_FaceR_Drained_CrouchFalling:
    return kSamusAnimationDelayData_E8;
  case kPose_E9_FaceL_Drained_CrouchFalling:
    return kSamusAnimationDelayData_E9;
  case kPose_EA_FaceR_Drained_Stand:
    return kSamusAnimationDelayData_EA;
  case kPose_EB_FaceL_Drained_Stand:
    return kSamusAnimationDelayData_EB;
  case kPose_01_FaceR_Normal:
  case kPose_02_FaceL_Normal:
    return kSamusAnimationDelayData_01;
  case kPose_27_FaceR_Crouch:
  case kPose_28_FaceL_Crouch:
    return kSamusAnimationDelayData_27;
  case kPose_D5_FaceR_Xray_Stand:
  case kPose_D6_FaceL_Xray_Stand:
  case kPose_D9_FaceR_Xray_Crouch:
  case kPose_DA_FaceL_Xray_Crouch:
    return kSamusAnimationDelayData_D5;
  case kPose_05_FaceR_AimUR:
  case kPose_06_FaceL_AimUL:
  case kPose_07_FaceR_AimDR:
  case kPose_08_FaceL_AimDL:
  case kPose_47:
  case kPose_48:
  case kPose_71_FaceR_Crouch_AimUR:
  case kPose_72_FaceL_Crouch_AimUL:
  case kPose_73_FaceR_Crouch_AimDR:
  case kPose_74_FaceL_Crouch_AimDL:
  case kPose_89_FaceR_Ranintowall:
  case kPose_8A_FaceL_Ranintowall:
  case kPose_B4_FaceR_Grappling_Crouch:
  case kPose_B5_FaceL_Grappling_Crouch:
  case kPose_B6_FaceR_Grappling_Crouch_AimDR:
  case kPose_B7_FaceL_Grappling_Crouch_AimDL:
  case kPose_B8_FaceL_GrappleWalljumpPose:
  case kPose_B9_FaceR_GrappleWalljumpPose:
  case kPose_BA_FaceL_Draygon_NoMove_NoAim:
  case kPose_BB_FaceL_Draygon_NoMove_AimUL:
  case kPose_BC_FaceL_Draygon_Fire:
  case kPose_BD_FaceL_Draygon_NoMove_AimDL:
  case kPose_CF_FaceR_Ranintowall_AimUR:
  case kPose_D0_FaceL_Ranintowall_AimUL:
  case kPose_D1_FaceR_Ranintowall_AimDR:
  case kPose_D2_FaceL_Ranintowall_AimDL:
  case kPose_EC_FaceR_Draygon_NoMove_NoAim:
  case kPose_ED_FaceR_Draygon_NoMove_AimUR:
  case kPose_EE_FaceR_Draygon_Fire:
  case kPose_EF_FaceR_Draygon_NoMove_AimDR:
    return kSamusAnimationDelayData_05;
  case kPose_A8_FaceR_Grappling:
  case kPose_A9_FaceL_Grappling:
  case kPose_AA_FaceR_Grappling_AimDR:
  case kPose_AB_FaceL_Grappling_AimDL:
    return kSamusAnimationDelayData_A8;
  case kPose_AC:
  case kPose_AD:
    return kSamusAnimationDelayData_AC;
  case kPose_AE:
  case kPose_AF:
    return kSamusAnimationDelayData_AE;
  case kPose_B0:
  case kPose_B1:
    return kSamusAnimationDelayData_B0;
  case kPose_B2_FaceR_Grapple_Air:
  case kPose_B3_FaceL_Grapple_Air:
    return kSamusAnimationDelayData_B2;
  case kPose_4B_FaceR_Jumptrans:
    return kSamusAnimationDelayData_4B;
  case kPose_4C_FaceL_Jumptrans:
    return kSamusAnimationDelayData_4C;
  case kPose_55_FaceR_Jumptrans_AimU:
    return kSamusAnimationDelayData_55;
  case kPose_56_FaceL_Jumptrans_AimU:
    return kSamusAnimationDelayData_56;
  case kPose_57_FaceR_Jumptrans_AimUR:
    return kSamusAnimationDelayData_57;
  case kPose_58_FaceL_Jumptrans_AimUL:
    return kSamusAnimationDelayData_58;
  case kPose_59_FaceR_Jumptrans_AimDR:
    return kSamusAnimationDelayData_59;
  case kPose_5A_FaceL_Jumptrans_AimDL:
    return kSamusAnimationDelayData_5A;
  case kPose_4D_FaceR_Jump_NoAim_NoMove_NoGun:
  case kPose_4E_FaceL_Jump_NoAim_NoMove_NoGun:
  case kPose_C7_FaceR_ShinesparkWindup_Vert:
  case kPose_C8_FaceL_ShinesparkWindup_Vert:
    return kSamusAnimationDelayData_4D;
  case kPose_4F_FaceL_Dmgboost:
  case kPose_50_FaceR_Dmgboost:
    return kSamusAnimationDelayData_4F;
  case kPose_15_FaceR_Jump_AimU:
  case kPose_16_FaceL_Jump_AimU:
    return kSamusAnimationDelayData_15;
  case kPose_17_FaceR_Jump_AimD:
  case kPose_18_FaceL_Jump_AimD:
    return kSamusAnimationDelayData_17;
  case kPose_51_FaceR_Jump_NoAim_MoveF:
  case kPose_52_FaceL_Jump_NoAim_MoveF:
    return kSamusAnimationDelayData_51;
  case kPose_13_FaceR_Jump_NoAim_NoMove_Gun:
  case kPose_14_FaceL_Jump_NoAim_NoMove_Gun:
  case kPose_69_FaceR_Jump_AimUR:
  case kPose_6A_FaceL_Jump_AimUL:
  case kPose_6B_FaceR_Jump_AimDR:
  case kPose_6C_FaceL_Jump_AimDL:
    return kSamusAnimationDelayData_13;
  case kPose_29_FaceR_Fall:
  case kPose_2A_FaceL_Fall:
    return kSamusAnimationDelayData_29;
  case kPose_67_FaceR_Fall_Gun:
  case kPose_68_FaceL_Fall_Gun:
    return kSamusAnimationDelayData_67;
  case kPose_2B_FaceR_Fall_AimU:
  case kPose_2C_FaceL_Fall_AimU:
    return kSamusAnimationDelayData_2B;
  case kPose_6D_FaceR_Fall_AimUR:
  case kPose_6E_FaceL_Fall_AimUL:
  case kPose_6F_FaceR_Fall_AimDR:
  case kPose_70_FaceL_Fall_AimDL:
    return kSamusAnimationDelayData_6D;
  case kPose_2D_FaceR_Fall_AimD:
  case kPose_2E_FaceL_Fall_AimD:
    return kSamusAnimationDelayData_2D;
  case kPose_53_FaceR_Knockback:
  case kPose_54_FaceL_Knockback:
    return kSamusAnimationDelayData_53;
  case kPose_1D_FaceR_Morphball_Ground:
  case kPose_1E_MoveR_Morphball_Ground:
  case kPose_1F_MoveL_Morphball_Ground:
  case kPose_20:
  case kPose_21:
  case kPose_22:
  case kPose_23:
  case kPose_24:
  case kPose_31_FaceR_Morphball_Air:
  case kPose_32_FaceL_Morphball_Air:
  case kPose_33:
  case kPose_34:
  case kPose_41_FaceL_Morphball_Ground:
  case kPose_42:
  case kPose_5B:
  case kPose_5C:
  case kPose_5D:
  case kPose_5E:
  case kPose_5F:
  case kPose_60:
  case kPose_61:
  case kPose_62:
  case kPose_79_FaceR_Springball_Ground:
  case kPose_7A_FaceL_Springball_Ground:
  case kPose_7B_MoveR_Springball_Ground:
  case kPose_7C_MoveL_Springball_Ground:
  case kPose_7D_FaceR_Springball_Fall:
  case kPose_7E_FaceL_Springball_Fall:
  case kPose_7F_FaceR_Springball_Air:
  case kPose_80_FaceL_Springball_Air:
  case kPose_C5:
  case kPose_DF:
    return kSamusAnimationDelayData_1D;
  case kPose_19_FaceR_SpinJump:
  case kPose_1A_FaceL_SpinJump:
    return kSamusAnimationDelayData_19;
  case kPose_1B_FaceR_SpaceJump:
  case kPose_1C_FaceL_SpaceJump:
    return kSamusAnimationDelayData_1B;
  case kPose_81_FaceR_Screwattack:
  case kPose_82_FaceL_Screwattack:
    return kSamusAnimationDelayData_81;
  case kPose_25_FaceR_Turn_Stand:
    return kSamusAnimationDelayData_25;
  case kPose_26_FaceL_Turn_Stand:
    return kSamusAnimationDelayData_26;
  case kPose_2F_FaceR_Turn_Jump:
    return kSamusAnimationDelayData_2F;
  case kPose_30_FaceL_Turn_Jump:
    return kSamusAnimationDelayData_30;
  case kPose_43_FaceR_Turn_Crouch:
    return kSamusAnimationDelayData_43;
  case kPose_44_FaceL_Turn_Crouch:
    return kSamusAnimationDelayData_44;
  case kPose_87_FaceR_Turn_Fall:
    return kSamusAnimationDelayData_87;
  case kPose_88_FaceL_Turn_Fall:
    return kSamusAnimationDelayData_88;
  case kPose_8B_FaceR_Turn_Stand_AimU:
    return kSamusAnimationDelayData_8B;
  case kPose_8C_FaceL_Turn_Stand_AimU:
    return kSamusAnimationDelayData_8C;
  case kPose_8D_FaceR_Turn_Stand_AimDR:
    return kSamusAnimationDelayData_8D;
  case kPose_8E_FaceL_Turn_Stand_AimDL:
    return kSamusAnimationDelayData_8E;
  case kPose_8F_FaceR_Turn_Air_AimU:
    return kSamusAnimationDelayData_8F;
  case kPose_90_FaceL_Turn_Air_AimU:
    return kSamusAnimationDelayData_90;
  case kPose_91_FaceR_Turn_Air_AimDDR:
    return kSamusAnimationDelayData_91;
  case kPose_92_FaceL_Turn_Air_AimDDL:
    return kSamusAnimationDelayData_92;
  case kPose_93_FaceR_Turn_Fall_AimU:
    return kSamusAnimationDelayData_93;
  case kPose_94_FaceL_Turn_Fall_AimU:
    return kSamusAnimationDelayData_94;
  case kPose_95_FaceR_Turn_Fall_AimDDR:
    return kSamusAnimationDelayData_95;
  case kPose_96_FaceL_Turn_Fall_AimDDL:
    return kSamusAnimationDelayData_96;
  case kPose_97_FaceR_Turn_Crouch_AimU:
    return kSamusAnimationDelayData_97;
  case kPose_98_FaceL_Turn_Crouch_AimU:
    return kSamusAnimationDelayData_98;
  case kPose_99_FaceR_Turn_Crouch_AimDDR:
    return kSamusAnimationDelayData_99;
  case kPose_9A_FaceL_Turn_Crouch_AimDDL:
    return kSamusAnimationDelayData_9A;
  case kPose_9C_FaceR_Turn_Stand_AimUR:
    return kSamusAnimationDelayData_9C;
  case kPose_9D_FaceL_Turn_Stand_AimUL:
    return kSamusAnimationDelayData_9D;
  case kPose_9E_FaceR_Turn_Air_AimUR:
    return kSamusAnimationDelayData_9E;
  case kPose_9F_FaceL_Turn_Air_AimUL:
    return kSamusAnimationDelayData_9F;
  case kPose_A0_FaceR_Turn_Fall_AimUR:
    return kSamusAnimationDelayData_A0;
  case kPose_A1_FaceL_Turn_Fall_AimUL:
    return kSamusAnimationDelayData_A1;
  case kPose_A2_FaceR_Turn_Crouch_AimUR:
    return kSamusAnimationDelayData_A2;
  case kPose_A3_FaceL_Turn_Crouch_AimUL:
    return kSamusAnimationDelayData_A3;
  case kPose_BF_FaceR_Moonwalk_TurnjumpL:
    return kSamusAnimationDelayData_BF;
  case kPose_C0_FaceL_Moonwalk_TurnjumpR:
    return kSamusAnimationDelayData_C0;
  case kPose_C1_FaceR_Moonwalk_TurnjumpL_AimUR:
    return kSamusAnimationDelayData_C1;
  case kPose_C2_FaceL_Moonwalk_TurnjumpR_AimUL:
    return kSamusAnimationDelayData_C2;
  case kPose_C3_FaceR_Moonwalk_TurnjumpL_AimDR:
    return kSamusAnimationDelayData_C3;
  case kPose_C4_FaceL_Moonwalk_TurnjumpR_AimDL:
    return kSamusAnimationDelayData_C4;
  case kPose_C6:
    return kSamusAnimationDelayData_C6;
  case kPose_63:
    return kSamusAnimationDelayData_63;
  case kPose_64:
    return kSamusAnimationDelayData_64;
  case kPose_65:
  case kPose_66:
    return kSamusAnimationDelayData_65;
  case kPose_83_FaceR_Walljump:
  case kPose_84_FaceL_Walljump:
    return kSamusAnimationDelayData_83;
  case kPose_35_FaceR_CrouchTrans:
    return kSamusAnimationDelayData_35;
  case kPose_36_FaceL_CrouchTrans:
    return kSamusAnimationDelayData_36;
  case kPose_37_FaceR_MorphTrans:
    return kSamusAnimationDelayData_37;
  case kPose_38_FaceL_MorphTrans:
    return kSamusAnimationDelayData_38;
  case kPose_39:
    return kSamusAnimationDelayData_39;
  case kPose_3A:
    return kSamusAnimationDelayData_3A;
  case kPose_3B_FaceR_StandTrans:
    return kSamusAnimationDelayData_3B;
  case kPose_3C_FaceL_StandTrans:
    return kSamusAnimationDelayData_3C;
  case kPose_3D_FaceR_UnmorphTrans:
    return kSamusAnimationDelayData_3D;
  case kPose_3E_FaceL_UnmorphTrans:
    return kSamusAnimationDelayData_3E;
  case kPose_3F:
    return kSamusAnimationDelayData_3F;
  case kPose_40:
    return kSamusAnimationDelayData_40;
  case kPose_DB:
    return kSamusAnimationDelayData_DB;
  case kPose_DC:
    return kSamusAnimationDelayData_DC;
  case kPose_DD:
    return kSamusAnimationDelayData_DD;
  case kPose_DE:
    return kSamusAnimationDelayData_DE;
  case kPose_F1_FaceR_CrouchTrans_AimU:
    return kSamusAnimationDelayData_F1;
  case kPose_F2_FaceL_CrouchTrans_AimU:
    return kSamusAnimationDelayData_F2;
  case kPose_F3_FaceR_CrouchTrans_AimUR:
    return kSamusAnimationDelayData_F3;
  case kPose_F4_FaceL_CrouchTrans_AimUL:
    return kSamusAnimationDelayData_F4;
  case kPose_F5_FaceR_CrouchTrans_AimDR:
    return kSamusAnimationDelayData_F5;
  case kPose_F6_FaceL_CrouchTrans_AimDL:
    return kSamusAnimationDelayData_F6;
  case kPose_F7_FaceR_StandTrans_AimU:
    return kSamusAnimationDelayData_F7;
  case kPose_F8_FaceL_StandTrans_AimU:
    return kSamusAnimationDelayData_F8;
  case kPose_F9_FaceR_StandTrans_AimUR:
    return kSamusAnimationDelayData_F9;
  case kPose_FA_FaceL_StandTrans_AimUL:
    return kSamusAnimationDelayData_FA;
  case kPose_FB_FaceR_StandTrans_AimDR:
    return kSamusAnimationDelayData_FB;
  case kPose_FC_FaceL_StandTrans_AimDL:
    return kSamusAnimationDelayData_FC;
  case kPose_BE_FaceL_Draygon_Move:
  case kPose_F0_FaceR_Draygon_Move:
    return kSamusAnimationDelayData_BE;
  case kPose_C9_FaceR_Shinespark_Horiz:
  case kPose_CA_FaceL_Shinespark_Horiz:
  case kPose_CB_FaceR_Shinespark_Vert:
  case kPose_CC_FaceL_Shinespark_Vert:
  case kPose_CD_FaceR_Shinespark_Diag:
  case kPose_CE_FaceL_Shinespark_Diag:
    return kSamusAnimationDelayData_C9;
  case kPose_D3_FaceR_CrystalFlash:
    return kSamusAnimationDelayData_D3;
  case kPose_D4_FaceL_CrystalFlash:
    return kSamusAnimationDelayData_D4;
  case kPose_D7_FaceR_CrystalFlashEnd:
  case kPose_D8_FaceL_CrystalFlashEnd:
    return kSamusAnimationDelayData_D7;
  case kPose_00_FaceF_Powersuit:
  case kPose_9B_FaceF_VariaGravitySuit:
    return kSamusAnimationDelayData_00;
  default: Unreachable(); return (uint8*){0};
  }
}
