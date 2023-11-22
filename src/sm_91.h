#pragma once

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
//#define kSamusPose_Falling ((uint16*)RomFixedPtr(0x91e921))
//#define kSamusPose_Landing ((uint16*)RomFixedPtr(0x91e9f3))
//#define kSamusPose_RanIntoWall ((uint16*)RomFixedPtr(0x91eb74))
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
  0xff00,
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

uint16 kSamusPose_Falling[] = {
    0x29,  0x2a,
    0x31,  0x32,
    0x33,  0x34,
    0x7d,  0x7e,
};

uint16 kSamusPose_Landing[] = {
    0xe0,  0xe2,  0xa4,  0xe4,  0xa4,
    0xa5,  0xe5,  0xa5,  0xe3,  0xe1,
};

uint16 kSamusPose_RanIntoWall[] = {
     0x3,  0xcf,  0x89,  0xd1,  0x89,
    0x8a,  0xd2,  0x8a,  0xd0,   0x4,
};

uint8 kSamusTurnPose_Standing[] = {
  0x8b, 0x9c, 0x25, 0x8d, 0x8d, 0x8e, 0x8e, 0x26, 0x9d, 0x8c,
};

uint8 kSamusTurnPose_Crouching[] = {
  0x97, 0xa2, 0x43, 0x99, 0x99, 0x9a, 0x9a, 0x44, 0xa3, 0x98,
};

uint8 kSamusTurnPose_Jumping[] = {
  0x8f, 0x9e, 0x2f, 0x91, 0x91, 0x92, 0x92, 0x30, 0x9f, 0x90,
};

uint8 kSamusTurnPose_Falling[] = {
  0x93, 0xa0, 0x87, 0x95, 0x95, 0x96, 0x96, 0x88, 0xa1, 0x94,
};

uint8 kSamusTurnPose_Moonwalk[] = {
  0xc1, 0xc1, 0xbf, 0xc3, 0x8d, 0x8e, 0xc4, 0xc0, 0xc2, 0xc2,
};

uint16* kPoseTransitionTable(void) {
  static uint16 Trans_00[] = {  //  0x91a0de
    0                                  , kButton_Right                      , kPose_26_FaceL_Turn_Stand          , 
    0                                  , kButton_Left                       , kPose_25_FaceR_Turn_Stand          , 
    0xffff
  };

  static uint16 Trans_01[] = {  //  0x91a0ec
    kButton_A                          , kButton_Up                         , kPose_55_FaceR_Jumptrans_AimU      , 
    kButton_A                          , kButton_R                          , kPose_57_FaceR_Jumptrans_AimUR     , 
    kButton_A                          , kButton_L                          , kPose_59_FaceR_Jumptrans_AimDR     , 
    kButton_A                          , 0                                  , kPose_4B_FaceR_Jumptrans           , 
    kButton_Down                       , kButton_R+kButton_L                , kPose_F1_FaceR_CrouchTrans_AimU    , 
    kButton_Down                       , kButton_R                          , kPose_F3_FaceR_CrouchTrans_AimUR   , 
    kButton_Down                       , kButton_L                          , kPose_F5_FaceR_CrouchTrans_AimDR   , 
    kButton_Down                       , 0                                  , kPose_35_FaceR_CrouchTrans         , 
    0                                  , kButton_L+kButton_X+kButton_Left   , kPose_78_FaceR_Moonwalk_AimDR      , 
    0                                  , kButton_R+kButton_X+kButton_Left   , kPose_76_FaceR_Moonwalk_AimUR      , 
    0                                  , kButton_R+kButton_L+kButton_Left   , kPose_25_FaceR_Turn_Stand          , 
    0                                  , kButton_R+kButton_L                , kPose_03_FaceR_AimU                , 
    0                                  , kButton_R+kButton_Right            , kPose_0F_MoveR_AimUR               , 
    0                                  , kButton_L+kButton_Right            , kPose_11_MoveR_AimDR               , 
    0                                  , kButton_Right+kButton_Up           , kPose_0F_MoveR_AimUR               , 
    0                                  , kButton_Right+kButton_Down         , kPose_11_MoveR_AimDR               , 
    0                                  , kButton_X+kButton_Left             , kPose_4A_FaceR_Moonwalk            , 
    0                                  , kButton_Left                       , kPose_25_FaceR_Turn_Stand          , 
    0                                  , kButton_Up                         , kPose_03_FaceR_AimU                , 
    0                                  , kButton_R                          , kPose_05_FaceR_AimUR               , 
    0                                  , kButton_L                          , kPose_07_FaceR_AimDR               , 
    0                                  , kButton_Right                      , kPose_09_MoveR_NoAim               , 
    0xffff
  };

  static uint16 Trans_02[] = {  //  0x91a172
    kButton_A                          , kButton_Up                         , kPose_56_FaceL_Jumptrans_AimU      , 
    kButton_A                          , kButton_R                          , kPose_58_FaceL_Jumptrans_AimUL     , 
    kButton_A                          , kButton_L                          , kPose_5A_FaceL_Jumptrans_AimDL     , 
    kButton_A                          , 0                                  , kPose_4C_FaceL_Jumptrans           , 
    kButton_Down                       , kButton_R+kButton_L                , kPose_F2_FaceL_CrouchTrans_AimU    , 
    kButton_Down                       , kButton_R                          , kPose_F4_FaceL_CrouchTrans_AimUL   , 
    kButton_Down                       , kButton_L                          , kPose_F6_FaceL_CrouchTrans_AimDL   , 
    kButton_Down                       , 0                                  , kPose_36_FaceL_CrouchTrans         , 
    0                                  , kButton_L+kButton_X+kButton_Right  , kPose_77_FaceL_Moonwalk_AimDL      , 
    0                                  , kButton_R+kButton_X+kButton_Right  , kPose_75_FaceL_Moonwalk_AimUL      , 
    0                                  , kButton_R+kButton_L+kButton_Right  , kPose_26_FaceL_Turn_Stand          , 
    0                                  , kButton_R+kButton_L                , kPose_04_FaceL_AimU                , 
    0                                  , kButton_R+kButton_Left             , kPose_10_MoveL_AimUL               , 
    0                                  , kButton_L+kButton_Left             , kPose_12_MoveL_AimDL               , 
    0                                  , kButton_Left+kButton_Up            , kPose_10_MoveL_AimUL               , 
    0                                  , kButton_Left+kButton_Down          , kPose_12_MoveL_AimDL               , 
    0                                  , kButton_X+kButton_Right            , kPose_49_FaceL_Moonwalk            , 
    0                                  , kButton_Right                      , kPose_26_FaceL_Turn_Stand          , 
    0                                  , kButton_Up                         , kPose_04_FaceL_AimU                , 
    0                                  , kButton_R                          , kPose_06_FaceL_AimUL               , 
    0                                  , kButton_L                          , kPose_08_FaceL_AimDL               , 
    0                                  , kButton_Left                       , kPose_0A_MoveL_NoAim               , 
    0xffff
  };

  static uint16 Trans_09[] = {  //  0x91a1f8
    kButton_Down                       , 0                                  , kPose_35_FaceR_CrouchTrans         , 
    kButton_A                          , 0                                  , kPose_19_FaceR_SpinJump            , 
    0                                  , kButton_R+kButton_Right            , kPose_0F_MoveR_AimUR               , 
    0                                  , kButton_L+kButton_Right            , kPose_11_MoveR_AimDR               , 
    0                                  , kButton_Right+kButton_Up           , kPose_0F_MoveR_AimUR               , 
    0                                  , kButton_Right+kButton_Down         , kPose_11_MoveR_AimDR               , 
    0                                  , kButton_X+kButton_Right            , kPose_0B_MoveR_Gun                 , 
    0                                  , kButton_Right                      , kPose_09_MoveR_NoAim               , 
    0                                  , kButton_Left                       , kPose_25_FaceR_Turn_Stand          , 
    0                                  , kButton_Up                         , kPose_03_FaceR_AimU                , 
    0                                  , kButton_R                          , kPose_05_FaceR_AimUR               , 
    0                                  , kButton_L                          , kPose_07_FaceR_AimDR               , 
    0xffff
  };

  static uint16 Trans_0a[] = {  //  0x91a242
    kButton_Down                       , 0                                  , kPose_36_FaceL_CrouchTrans         , 
    kButton_A                          , 0                                  , kPose_1A_FaceL_SpinJump            , 
    0                                  , kButton_R+kButton_Left             , kPose_10_MoveL_AimUL               , 
    0                                  , kButton_L+kButton_Left             , kPose_12_MoveL_AimDL               , 
    0                                  , kButton_Left+kButton_Up            , kPose_10_MoveL_AimUL               , 
    0                                  , kButton_Left+kButton_Down          , kPose_12_MoveL_AimDL               , 
    0                                  , kButton_X+kButton_Left             , kPose_0C_MoveL_Gun                 , 
    0                                  , kButton_Left                       , kPose_0A_MoveL_NoAim               , 
    0                                  , kButton_Right                      , kPose_26_FaceL_Turn_Stand          , 
    0                                  , kButton_Up                         , kPose_04_FaceL_AimU                , 
    0                                  , kButton_R                          , kPose_06_FaceL_AimUL               , 
    0                                  , kButton_L                          , kPose_08_FaceL_AimDL               , 
    0xffff
  };

  static uint16 Trans_0b[] = {  //  0x91ae94
    kButton_Down                       , 0                                  , kPose_35_FaceR_CrouchTrans         , 
    kButton_A                          , 0                                  , kPose_19_FaceR_SpinJump            , 
    0                                  , kButton_R+kButton_Right            , kPose_0F_MoveR_AimUR               , 
    0                                  , kButton_L+kButton_Right            , kPose_11_MoveR_AimDR               , 
    0                                  , kButton_Right+kButton_Up           , kPose_0F_MoveR_AimUR               , 
    0                                  , kButton_Right+kButton_Down         , kPose_11_MoveR_AimDR               , 
    0                                  , kButton_X+kButton_Right            , kPose_0B_MoveR_Gun                 , 
    0                                  , kButton_Right                      , kPose_0B_MoveR_Gun                 , 
    0                                  , kButton_Left                       , kPose_25_FaceR_Turn_Stand          , 
    0                                  , kButton_Up                         , kPose_03_FaceR_AimU                , 
    0                                  , kButton_R                          , kPose_05_FaceR_AimUR               , 
    0                                  , kButton_L                          , kPose_07_FaceR_AimDR               , 
    0xffff
  };

  static uint16 Trans_0c[] = {  //  0x91aede
    kButton_Down                       , 0                                  , kPose_36_FaceL_CrouchTrans         , 
    kButton_A                          , 0                                  , kPose_1A_FaceL_SpinJump            , 
    0                                  , kButton_R+kButton_Left             , kPose_10_MoveL_AimUL               , 
    0                                  , kButton_L+kButton_Left             , kPose_12_MoveL_AimDL               , 
    0                                  , kButton_Left+kButton_Up            , kPose_10_MoveL_AimUL               , 
    0                                  , kButton_Left+kButton_Down          , kPose_12_MoveL_AimDL               , 
    0                                  , kButton_X+kButton_Left             , kPose_0C_MoveL_Gun                 , 
    0                                  , kButton_Left                       , kPose_0C_MoveL_Gun                 , 
    0                                  , kButton_Right                      , kPose_26_FaceL_Turn_Stand          , 
    0                                  , kButton_Up                         , kPose_04_FaceL_AimU                , 
    0                                  , kButton_R                          , kPose_06_FaceL_AimUL               , 
    0                                  , kButton_L                          , kPose_08_FaceL_AimDL               , 
    0xffff
  };

  static uint16 Trans_13[] = {  //  0x91aac0
    0                                  , kButton_A+kButton_Right+kButton_Up , kPose_69_FaceR_Jump_AimUR          , 
    0                                  , kButton_A+kButton_Right+kButton_Down, kPose_6B_FaceR_Jump_AimDR          , 
    0                                  , kButton_R+kButton_A+kButton_Right  , kPose_69_FaceR_Jump_AimUR          , 
    0                                  , kButton_L+kButton_A+kButton_Right  , kPose_6B_FaceR_Jump_AimDR          , 
    0                                  , kButton_Right+kButton_Up           , kPose_69_FaceR_Jump_AimUR          , 
    0                                  , kButton_Right+kButton_Down         , kPose_6B_FaceR_Jump_AimDR          , 
    0                                  , kButton_A+kButton_Left             , kPose_2F_FaceR_Turn_Jump           , 
    0                                  , kButton_A+kButton_Up               , kPose_15_FaceR_Jump_AimU           , 
    0                                  , kButton_A+kButton_Down             , kPose_17_FaceR_Jump_AimD           , 
    0                                  , kButton_R+kButton_A                , kPose_69_FaceR_Jump_AimUR          , 
    0                                  , kButton_L+kButton_A                , kPose_6B_FaceR_Jump_AimDR          , 
    0                                  , kButton_A+kButton_Right            , kPose_51_FaceR_Jump_NoAim_MoveF    , 
    0                                  , kButton_X+kButton_A                , kPose_13_FaceR_Jump_NoAim_NoMove_Gun, 
    0                                  , kButton_Left                       , kPose_2F_FaceR_Turn_Jump           , 
    0                                  , kButton_Up                         , kPose_15_FaceR_Jump_AimU           , 
    0                                  , kButton_Down                       , kPose_17_FaceR_Jump_AimD           , 
    0                                  , kButton_R                          , kPose_69_FaceR_Jump_AimUR          , 
    0                                  , kButton_L                          , kPose_6B_FaceR_Jump_AimDR          , 
    0                                  , kButton_Right                      , kPose_51_FaceR_Jump_NoAim_MoveF    , 
    0                                  , kButton_X                          , kPose_13_FaceR_Jump_NoAim_NoMove_Gun, 
    0xffff
  };

  static uint16 Trans_14[] = {  //  0x91ab3a
    0                                  , kButton_A+kButton_Left+kButton_Up  , kPose_6A_FaceL_Jump_AimUL          , 
    0                                  , kButton_A+kButton_Left+kButton_Down, kPose_6C_FaceL_Jump_AimDL          , 
    0                                  , kButton_R+kButton_A+kButton_Left   , kPose_6A_FaceL_Jump_AimUL          , 
    0                                  , kButton_L+kButton_A+kButton_Left   , kPose_6C_FaceL_Jump_AimDL          , 
    0                                  , kButton_Left+kButton_Up            , kPose_6A_FaceL_Jump_AimUL          , 
    0                                  , kButton_Left+kButton_Down          , kPose_6C_FaceL_Jump_AimDL          , 
    0                                  , kButton_A+kButton_Right            , kPose_30_FaceL_Turn_Jump           , 
    0                                  , kButton_A+kButton_Up               , kPose_16_FaceL_Jump_AimU           , 
    0                                  , kButton_A+kButton_Down             , kPose_18_FaceL_Jump_AimD           , 
    0                                  , kButton_R+kButton_A                , kPose_6A_FaceL_Jump_AimUL          , 
    0                                  , kButton_L+kButton_A                , kPose_6C_FaceL_Jump_AimDL          , 
    0                                  , kButton_A+kButton_Left             , kPose_52_FaceL_Jump_NoAim_MoveF    , 
    0                                  , kButton_X+kButton_A                , kPose_14_FaceL_Jump_NoAim_NoMove_Gun, 
    0                                  , kButton_Right                      , kPose_30_FaceL_Turn_Jump           , 
    0                                  , kButton_Up                         , kPose_16_FaceL_Jump_AimU           , 
    0                                  , kButton_Down                       , kPose_18_FaceL_Jump_AimD           , 
    0                                  , kButton_R                          , kPose_6A_FaceL_Jump_AimUL          , 
    0                                  , kButton_L                          , kPose_6C_FaceL_Jump_AimDL          , 
    0                                  , kButton_Left                       , kPose_52_FaceL_Jump_NoAim_MoveF    , 
    0                                  , kButton_X                          , kPose_14_FaceL_Jump_NoAim_NoMove_Gun, 
    0xffff
  };

  static uint16 Trans_15[] = {  //  0x91a2f6
    0                                  , kButton_A+kButton_Right+kButton_Up , kPose_69_FaceR_Jump_AimUR          , 
    0                                  , kButton_A+kButton_Right+kButton_Down, kPose_6B_FaceR_Jump_AimDR          , 
    0                                  , kButton_R+kButton_A+kButton_Right  , kPose_69_FaceR_Jump_AimUR          , 
    0                                  , kButton_L+kButton_A+kButton_Right  , kPose_6B_FaceR_Jump_AimDR          , 
    0                                  , kButton_Right+kButton_Up           , kPose_69_FaceR_Jump_AimUR          , 
    0                                  , kButton_Right+kButton_Down         , kPose_6B_FaceR_Jump_AimDR          , 
    0                                  , kButton_A+kButton_Left             , kPose_2F_FaceR_Turn_Jump           , 
    0                                  , kButton_A+kButton_Up               , kPose_15_FaceR_Jump_AimU           , 
    0                                  , kButton_A+kButton_Down             , kPose_17_FaceR_Jump_AimD           , 
    0                                  , kButton_R+kButton_A                , kPose_69_FaceR_Jump_AimUR          , 
    0                                  , kButton_L+kButton_A                , kPose_6B_FaceR_Jump_AimDR          , 
    0                                  , kButton_A+kButton_Right            , kPose_51_FaceR_Jump_NoAim_MoveF    , 
    0                                  , kButton_X+kButton_A                , kPose_13_FaceR_Jump_NoAim_NoMove_Gun, 
    0                                  , kButton_Left                       , kPose_2F_FaceR_Turn_Jump           , 
    0                                  , kButton_Up                         , kPose_15_FaceR_Jump_AimU           , 
    0                                  , kButton_Down                       , kPose_17_FaceR_Jump_AimD           , 
    0                                  , kButton_R                          , kPose_69_FaceR_Jump_AimUR          , 
    0                                  , kButton_L                          , kPose_6B_FaceR_Jump_AimDR          , 
    0                                  , kButton_Right                      , kPose_51_FaceR_Jump_NoAim_MoveF    , 
    0                                  , kButton_A                          , kPose_4D_FaceR_Jump_NoAim_NoMove_NoGun, 
    0                                  , kButton_X                          , kPose_13_FaceR_Jump_NoAim_NoMove_Gun, 
    0xffff
  };

  static uint16 Trans_16[] = {  //  0x91a376
    0                                  , kButton_A+kButton_Left+kButton_Up  , kPose_6A_FaceL_Jump_AimUL          , 
    0                                  , kButton_A+kButton_Left+kButton_Down, kPose_6C_FaceL_Jump_AimDL          , 
    0                                  , kButton_R+kButton_A+kButton_Left   , kPose_6A_FaceL_Jump_AimUL          , 
    0                                  , kButton_L+kButton_A+kButton_Left   , kPose_6C_FaceL_Jump_AimDL          , 
    0                                  , kButton_Left+kButton_Up            , kPose_6A_FaceL_Jump_AimUL          , 
    0                                  , kButton_Left+kButton_Down          , kPose_6C_FaceL_Jump_AimDL          , 
    0                                  , kButton_A+kButton_Right            , kPose_30_FaceL_Turn_Jump           , 
    0                                  , kButton_A+kButton_Up               , kPose_16_FaceL_Jump_AimU           , 
    0                                  , kButton_A+kButton_Down             , kPose_18_FaceL_Jump_AimD           , 
    0                                  , kButton_R+kButton_A                , kPose_6A_FaceL_Jump_AimUL          , 
    0                                  , kButton_L+kButton_A                , kPose_6C_FaceL_Jump_AimDL          , 
    0                                  , kButton_A+kButton_Left             , kPose_52_FaceL_Jump_NoAim_MoveF    , 
    0                                  , kButton_X+kButton_A                , kPose_14_FaceL_Jump_NoAim_NoMove_Gun, 
    0                                  , kButton_Right                      , kPose_30_FaceL_Turn_Jump           , 
    0                                  , kButton_Up                         , kPose_16_FaceL_Jump_AimU           , 
    0                                  , kButton_Down                       , kPose_18_FaceL_Jump_AimD           , 
    0                                  , kButton_R                          , kPose_6A_FaceL_Jump_AimUL          , 
    0                                  , kButton_L                          , kPose_6C_FaceL_Jump_AimDL          , 
    0                                  , kButton_Left                       , kPose_52_FaceL_Jump_NoAim_MoveF    , 
    0                                  , kButton_A                          , kPose_4E_FaceL_Jump_NoAim_NoMove_NoGun, 
    0                                  , kButton_X                          , kPose_14_FaceL_Jump_NoAim_NoMove_Gun, 
    0xffff
  };

  static uint16 Trans_17[] = {  //  0x91abb4
    kButton_Down                       , 0                                  , kPose_37_FaceR_MorphTrans          , 
    0                                  , kButton_A+kButton_Right+kButton_Up , kPose_69_FaceR_Jump_AimUR          , 
    0                                  , kButton_A+kButton_Right+kButton_Down, kPose_6B_FaceR_Jump_AimDR          , 
    0                                  , kButton_R+kButton_A+kButton_Right  , kPose_69_FaceR_Jump_AimUR          , 
    0                                  , kButton_L+kButton_A+kButton_Right  , kPose_6B_FaceR_Jump_AimDR          , 
    0                                  , kButton_X+kButton_A+kButton_Right  , kPose_13_FaceR_Jump_NoAim_NoMove_Gun, 
    0                                  , kButton_Right+kButton_Up           , kPose_69_FaceR_Jump_AimUR          , 
    0                                  , kButton_Right+kButton_Down         , kPose_6B_FaceR_Jump_AimDR          , 
    0                                  , kButton_A+kButton_Left             , kPose_2F_FaceR_Turn_Jump           , 
    0                                  , kButton_A+kButton_Up               , kPose_15_FaceR_Jump_AimU           , 
    0                                  , kButton_A+kButton_Down             , kPose_17_FaceR_Jump_AimD           , 
    0                                  , kButton_R+kButton_A                , kPose_69_FaceR_Jump_AimUR          , 
    0                                  , kButton_L+kButton_A                , kPose_6B_FaceR_Jump_AimDR          , 
    0                                  , kButton_A+kButton_Right            , kPose_51_FaceR_Jump_NoAim_MoveF    , 
    0                                  , kButton_X+kButton_A                , kPose_13_FaceR_Jump_NoAim_NoMove_Gun, 
    0                                  , kButton_Left                       , kPose_2F_FaceR_Turn_Jump           , 
    0                                  , kButton_Up                         , kPose_15_FaceR_Jump_AimU           , 
    0                                  , kButton_Down                       , kPose_17_FaceR_Jump_AimD           , 
    0                                  , kButton_R                          , kPose_69_FaceR_Jump_AimUR          , 
    0                                  , kButton_L                          , kPose_6B_FaceR_Jump_AimDR          , 
    0                                  , kButton_Right                      , kPose_51_FaceR_Jump_NoAim_MoveF    , 
    0                                  , kButton_A                          , kPose_17_FaceR_Jump_AimD           , 
    0                                  , kButton_X                          , kPose_13_FaceR_Jump_NoAim_NoMove_Gun, 
    0xffff
  };

  static uint16 Trans_18[] = {  //  0x91ac40
    kButton_Down                       , 0                                  , kPose_38_FaceL_MorphTrans          , 
    0                                  , kButton_A+kButton_Left+kButton_Up  , kPose_6A_FaceL_Jump_AimUL          , 
    0                                  , kButton_A+kButton_Left+kButton_Down, kPose_6C_FaceL_Jump_AimDL          , 
    0                                  , kButton_R+kButton_A+kButton_Left   , kPose_6A_FaceL_Jump_AimUL          , 
    0                                  , kButton_L+kButton_A+kButton_Left   , kPose_6C_FaceL_Jump_AimDL          , 
    0                                  , kButton_L+kButton_A+kButton_Left   , kPose_6C_FaceL_Jump_AimDL          , 
    0                                  , kButton_Left+kButton_Up            , kPose_6A_FaceL_Jump_AimUL          , 
    0                                  , kButton_Left+kButton_Down          , kPose_6C_FaceL_Jump_AimDL          , 
    0                                  , kButton_A+kButton_Right            , kPose_30_FaceL_Turn_Jump           , 
    0                                  , kButton_A+kButton_Up               , kPose_16_FaceL_Jump_AimU           , 
    0                                  , kButton_A+kButton_Down             , kPose_18_FaceL_Jump_AimD           , 
    0                                  , kButton_R+kButton_A                , kPose_6A_FaceL_Jump_AimUL          , 
    0                                  , kButton_L+kButton_A                , kPose_6C_FaceL_Jump_AimDL          , 
    0                                  , kButton_A+kButton_Left             , kPose_52_FaceL_Jump_NoAim_MoveF    , 
    0                                  , kButton_X+kButton_A                , kPose_14_FaceL_Jump_NoAim_NoMove_Gun, 
    0                                  , kButton_Right                      , kPose_30_FaceL_Turn_Jump           , 
    0                                  , kButton_Up                         , kPose_16_FaceL_Jump_AimU           , 
    0                                  , kButton_Down                       , kPose_18_FaceL_Jump_AimD           , 
    0                                  , kButton_R                          , kPose_6A_FaceL_Jump_AimUL          , 
    0                                  , kButton_L                          , kPose_6C_FaceL_Jump_AimDL          , 
    0                                  , kButton_Left                       , kPose_52_FaceL_Jump_NoAim_MoveF    , 
    0                                  , kButton_A                          , kPose_18_FaceL_Jump_AimD           , 
    0                                  , kButton_X                          , kPose_14_FaceL_Jump_NoAim_NoMove_Gun, 
    0xffff
  };

  static uint16 Trans_19[] = {  //  0x91a41e
    kButton_X                          , 0                                  , kPose_13_FaceR_Jump_NoAim_NoMove_Gun, 
    kButton_X                          , kButton_Right                      , kPose_13_FaceR_Jump_NoAim_NoMove_Gun, 
    0                                  , kButton_X+kButton_Up               , kPose_15_FaceR_Jump_AimU           , 
    0                                  , kButton_X+kButton_Down             , kPose_17_FaceR_Jump_AimD           , 
    0                                  , kButton_R+kButton_X                , kPose_69_FaceR_Jump_AimUR          , 
    0                                  , kButton_L+kButton_X                , kPose_6B_FaceR_Jump_AimDR          , 
    0                                  , kButton_A+kButton_Right            , kPose_19_FaceR_SpinJump            , 
    0                                  , kButton_Up                         , kPose_15_FaceR_Jump_AimU           , 
    0                                  , kButton_R                          , kPose_69_FaceR_Jump_AimUR          , 
    0                                  , kButton_L                          , kPose_6B_FaceR_Jump_AimDR          , 
    0                                  , kButton_Down                       , kPose_17_FaceR_Jump_AimD           , 
    0                                  , kButton_Right                      , kPose_19_FaceR_SpinJump            , 
    0                                  , kButton_Left                       , kPose_1A_FaceL_SpinJump            , 
    0xffff
  };

  static uint16 Trans_1a[] = {  //  0x91a46e
    kButton_X                          , 0                                  , kPose_14_FaceL_Jump_NoAim_NoMove_Gun, 
    kButton_X                          , kButton_Left                       , kPose_14_FaceL_Jump_NoAim_NoMove_Gun, 
    0                                  , kButton_X+kButton_Up               , kPose_16_FaceL_Jump_AimU           , 
    0                                  , kButton_X+kButton_Down             , kPose_18_FaceL_Jump_AimD           , 
    0                                  , kButton_R+kButton_X                , kPose_6A_FaceL_Jump_AimUL          , 
    0                                  , kButton_L+kButton_X                , kPose_6C_FaceL_Jump_AimDL          , 
    0                                  , kButton_A+kButton_Left             , kPose_1A_FaceL_SpinJump            , 
    0                                  , kButton_Up                         , kPose_16_FaceL_Jump_AimU           , 
    0                                  , kButton_R                          , kPose_6A_FaceL_Jump_AimUL          , 
    0                                  , kButton_L                          , kPose_6C_FaceL_Jump_AimDL          , 
    0                                  , kButton_Down                       , kPose_18_FaceL_Jump_AimD           , 
    0                                  , kButton_Left                       , kPose_1A_FaceL_SpinJump            , 
    0                                  , kButton_Right                      , kPose_19_FaceR_SpinJump            , 
    0xffff
  };

  static uint16 Trans_1b[] = {  //  0x91a4be
    kButton_X                          , 0                                  , kPose_13_FaceR_Jump_NoAim_NoMove_Gun, 
    kButton_X                          , kButton_Right                      , kPose_13_FaceR_Jump_NoAim_NoMove_Gun, 
    0                                  , kButton_X+kButton_Up               , kPose_15_FaceR_Jump_AimU           , 
    0                                  , kButton_X+kButton_Down             , kPose_17_FaceR_Jump_AimD           , 
    0                                  , kButton_R+kButton_X                , kPose_69_FaceR_Jump_AimUR          , 
    0                                  , kButton_L+kButton_X                , kPose_6B_FaceR_Jump_AimDR          , 
    0                                  , kButton_A+kButton_Right            , kPose_1B_FaceR_SpaceJump           , 
    0                                  , kButton_Up                         , kPose_15_FaceR_Jump_AimU           , 
    0                                  , kButton_R                          , kPose_69_FaceR_Jump_AimUR          , 
    0                                  , kButton_L                          , kPose_6B_FaceR_Jump_AimDR          , 
    0                                  , kButton_Down                       , kPose_17_FaceR_Jump_AimD           , 
    0                                  , kButton_Right                      , kPose_1B_FaceR_SpaceJump           , 
    0                                  , kButton_Left                       , kPose_1C_FaceL_SpaceJump           , 
    0xffff
  };

  static uint16 Trans_1c[] = {  //  0x91a50e
    kButton_X                          , 0                                  , kPose_14_FaceL_Jump_NoAim_NoMove_Gun, 
    kButton_X                          , kButton_Left                       , kPose_14_FaceL_Jump_NoAim_NoMove_Gun, 
    0                                  , kButton_X+kButton_Up               , kPose_16_FaceL_Jump_AimU           , 
    0                                  , kButton_X+kButton_Down             , kPose_18_FaceL_Jump_AimD           , 
    0                                  , kButton_R+kButton_X                , kPose_6A_FaceL_Jump_AimUL          , 
    0                                  , kButton_L+kButton_X                , kPose_6C_FaceL_Jump_AimDL          , 
    0                                  , kButton_A+kButton_Left             , kPose_1C_FaceL_SpaceJump           , 
    0                                  , kButton_Up                         , kPose_16_FaceL_Jump_AimU           , 
    0                                  , kButton_R                          , kPose_6A_FaceL_Jump_AimUL          , 
    0                                  , kButton_L                          , kPose_6C_FaceL_Jump_AimDL          , 
    0                                  , kButton_Down                       , kPose_18_FaceL_Jump_AimD           , 
    0                                  , kButton_Left                       , kPose_1C_FaceL_SpaceJump           , 
    0                                  , kButton_Right                      , kPose_1B_FaceR_SpaceJump           , 
    0xffff
  };

  static uint16 Trans_1d[] = {  //  0x91a5fe
    kButton_Up                         , 0                                  , kPose_3D_FaceR_UnmorphTrans        , 
    kButton_A                          , 0                                  , kPose_3D_FaceR_UnmorphTrans        , 
    0                                  , kButton_Right                      , kPose_1E_MoveR_Morphball_Ground    , 
    0                                  , kButton_Left                       , kPose_1F_MoveL_Morphball_Ground    , 
    0xffff
  };

  static uint16 Trans_1e[] = {  //  0x91a618
    kButton_Up                         , 0                                  , kPose_3D_FaceR_UnmorphTrans        , 
    kButton_A                          , 0                                  , kPose_3D_FaceR_UnmorphTrans        , 
    0                                  , kButton_Right                      , kPose_1E_MoveR_Morphball_Ground    , 
    0                                  , kButton_Left                       , kPose_1F_MoveL_Morphball_Ground    , 
    0xffff
  };

  static uint16 Trans_1f[] = {  //  0x91a632
    kButton_Up                         , 0                                  , kPose_3E_FaceL_UnmorphTrans        , 
    kButton_A                          , 0                                  , kPose_3E_FaceL_UnmorphTrans        , 
    0                                  , kButton_Right                      , kPose_1E_MoveR_Morphball_Ground    , 
    0                                  , kButton_Left                       , kPose_1F_MoveL_Morphball_Ground    , 
    0xffff
  };

  static uint16 Trans_20[] = {  //  0x91a666
    0xffff
  };

  static uint16 Trans_23[] = {  //  0x91a668
    0xffff
  };

  static uint16 Trans_25[] = {  //  0x91acf4
    0                                  , kButton_A+kButton_Left             , kPose_1A_FaceL_SpinJump            , 
    kButton_A                          , 0                                  , kPose_4C_FaceL_Jumptrans           , 
    0                                  , kButton_Left                       , kPose_25_FaceR_Turn_Stand          , 
    0xffff
  };

  static uint16 Trans_26[] = {  //  0x91ad08
    0                                  , kButton_A+kButton_Right            , kPose_19_FaceR_SpinJump            , 
    kButton_A                          , 0                                  , kPose_4B_FaceR_Jumptrans           , 
    0                                  , kButton_Right                      , kPose_26_FaceL_Turn_Stand          , 
    0xffff
  };

  static uint16 Trans_27[] = {  //  0x91a66c
    kButton_Up                         , kButton_R+kButton_L                , kPose_F7_FaceR_StandTrans_AimU     , 
    kButton_Up                         , kButton_R                          , kPose_F9_FaceR_StandTrans_AimUR    , 
    kButton_Up                         , kButton_L                          , kPose_FB_FaceR_StandTrans_AimDR    , 
    kButton_Up                         , 0                                  , kPose_3B_FaceR_StandTrans          , 
    kButton_Left                       , 0                                  , kPose_43_FaceR_Turn_Crouch         , 
    kButton_Down                       , 0                                  , kPose_37_FaceR_MorphTrans          , 
    kButton_A                          , 0                                  , kPose_4B_FaceR_Jumptrans           , 
    0                                  , kButton_R+kButton_L                , kPose_85_FaceR_Crouch_AimU         , 
    0                                  , kButton_R+kButton_Right            , kPose_01_FaceR_Normal              , 
    0                                  , kButton_L+kButton_Right            , kPose_01_FaceR_Normal              , 
    0                                  , kButton_R                          , kPose_71_FaceR_Crouch_AimUR        , 
    0                                  , kButton_L                          , kPose_73_FaceR_Crouch_AimDR        , 
    0                                  , kButton_Right                      , kPose_01_FaceR_Normal              , 
    0xffff
  };

  static uint16 Trans_28[] = {  //  0x91a6bc
    kButton_Up                         , kButton_R+kButton_L                , kPose_F8_FaceL_StandTrans_AimU     , 
    kButton_Up                         , kButton_R                          , kPose_FA_FaceL_StandTrans_AimUL    , 
    kButton_Up                         , kButton_L                          , kPose_FC_FaceL_StandTrans_AimDL    , 
    kButton_Up                         , 0                                  , kPose_3C_FaceL_StandTrans          , 
    kButton_Right                      , 0                                  , kPose_44_FaceL_Turn_Crouch         , 
    kButton_Down                       , 0                                  , kPose_38_FaceL_MorphTrans          , 
    kButton_A                          , 0                                  , kPose_4C_FaceL_Jumptrans           , 
    0                                  , kButton_R+kButton_L                , kPose_86_FaceL_Crouch_AimU         , 
    0                                  , kButton_L+kButton_Left             , kPose_02_FaceL_Normal              , 
    0                                  , kButton_R+kButton_Left             , kPose_02_FaceL_Normal              , 
    0                                  , kButton_R                          , kPose_72_FaceL_Crouch_AimUL        , 
    0                                  , kButton_L                          , kPose_74_FaceL_Crouch_AimDL        , 
    0                                  , kButton_Left                       , kPose_02_FaceL_Normal              , 
    0xffff
  };

  static uint16 Trans_29[] = {  //  0x91a70c
    0                                  , kButton_Right+kButton_Up           , kPose_6D_FaceR_Fall_AimUR          , 
    0                                  , kButton_Right+kButton_Down         , kPose_6F_FaceR_Fall_AimDR          , 
    0                                  , kButton_Left+kButton_Up            , kPose_87_FaceR_Turn_Fall           , 
    0                                  , kButton_Left+kButton_Down          , kPose_87_FaceR_Turn_Fall           , 
    0                                  , kButton_Left                       , kPose_87_FaceR_Turn_Fall           , 
    0                                  , kButton_Up                         , kPose_2B_FaceR_Fall_AimU           , 
    0                                  , kButton_Down                       , kPose_2D_FaceR_Fall_AimD           , 
    0                                  , kButton_R                          , kPose_6D_FaceR_Fall_AimUR          , 
    0                                  , kButton_L                          , kPose_6F_FaceR_Fall_AimDR          , 
    0                                  , kButton_X                          , kPose_67_FaceR_Fall_Gun            , 
    0                                  , kButton_Right                      , kPose_29_FaceR_Fall                , 
    0xffff
  };

  static uint16 Trans_2a[] = {  //  0x91a750
    0                                  , kButton_Left+kButton_Up            , kPose_6E_FaceL_Fall_AimUL          , 
    0                                  , kButton_Left+kButton_Down          , kPose_70_FaceL_Fall_AimDL          , 
    0                                  , kButton_Right+kButton_Up           , kPose_88_FaceL_Turn_Fall           , 
    0                                  , kButton_Right+kButton_Down         , kPose_88_FaceL_Turn_Fall           , 
    0                                  , kButton_Right                      , kPose_88_FaceL_Turn_Fall           , 
    0                                  , kButton_Up                         , kPose_2C_FaceL_Fall_AimU           , 
    0                                  , kButton_Down                       , kPose_2E_FaceL_Fall_AimD           , 
    0                                  , kButton_R                          , kPose_6E_FaceL_Fall_AimUL          , 
    0                                  , kButton_L                          , kPose_70_FaceL_Fall_AimDL          , 
    0                                  , kButton_X                          , kPose_68_FaceL_Fall_Gun            , 
    0                                  , kButton_Left                       , kPose_2A_FaceL_Fall                , 
    0xffff
  };

  static uint16 Trans_2d[] = {  //  0x91ad94
    kButton_Down                       , 0                                  , kPose_37_FaceR_MorphTrans          , 
    0                                  , kButton_Right+kButton_Up           , kPose_6D_FaceR_Fall_AimUR          , 
    0                                  , kButton_Right+kButton_Down         , kPose_6F_FaceR_Fall_AimDR          , 
    0                                  , kButton_Up                         , kPose_2B_FaceR_Fall_AimU           , 
    0                                  , kButton_Down                       , kPose_2D_FaceR_Fall_AimD           , 
    0                                  , kButton_Left                       , kPose_87_FaceR_Turn_Fall           , 
    0                                  , kButton_R                          , kPose_6D_FaceR_Fall_AimUR          , 
    0                                  , kButton_L                          , kPose_6F_FaceR_Fall_AimDR          , 
    0                                  , kButton_X                          , kPose_67_FaceR_Fall_Gun            , 
    0                                  , kButton_Right                      , kPose_29_FaceR_Fall                , 
    0xffff
  };

  static uint16 Trans_2e[] = {  //  0x91add2
    kButton_Down                       , 0                                  , kPose_38_FaceL_MorphTrans          , 
    0                                  , kButton_Left+kButton_Up            , kPose_6E_FaceL_Fall_AimUL          , 
    0                                  , kButton_Left+kButton_Down          , kPose_70_FaceL_Fall_AimDL          , 
    0                                  , kButton_Up                         , kPose_2C_FaceL_Fall_AimU           , 
    0                                  , kButton_Down                       , kPose_2E_FaceL_Fall_AimD           , 
    0                                  , kButton_Right                      , kPose_88_FaceL_Turn_Fall           , 
    0                                  , kButton_R                          , kPose_6E_FaceL_Fall_AimUL          , 
    0                                  , kButton_L                          , kPose_70_FaceL_Fall_AimDL          , 
    0                                  , kButton_X                          , kPose_68_FaceL_Fall_Gun            , 
    0                                  , kButton_Left                       , kPose_2A_FaceL_Fall                , 
    0xffff
  };

  static uint16 Trans_2f[] = {  //  0x91a0dc
    0xffff
  };

  static uint16 Trans_31[] = {  //  0x91a794
    kButton_Up                         , 0                                  , kPose_3D_FaceR_UnmorphTrans        , 
    kButton_A                          , 0                                  , kPose_3D_FaceR_UnmorphTrans        , 
    0                                  , kButton_Right                      , kPose_31_FaceR_Morphball_Air       , 
    0                                  , kButton_Left                       , kPose_32_FaceL_Morphball_Air       , 
    0xffff
  };

  static uint16 Trans_32[] = {  //  0x91a7ae
    kButton_Up                         , 0                                  , kPose_3E_FaceL_UnmorphTrans        , 
    kButton_A                          , 0                                  , kPose_3E_FaceL_UnmorphTrans        , 
    0                                  , kButton_Left                       , kPose_32_FaceL_Morphball_Air       , 
    0                                  , kButton_Right                      , kPose_31_FaceR_Morphball_Air       , 
    0xffff
  };

  static uint16 Trans_33[] = {  //  0x91a7c8
    0xffff
  };

  static uint16 Trans_34[] = {  //  0x91a7ca
    0xffff
  };

  static uint16 Trans_3d[] = {  //  0x91accc
    0                                  , kButton_X+kButton_Right            , kPose_67_FaceR_Fall_Gun            , 
    0                                  , kButton_X+kButton_Up               , kPose_2B_FaceR_Fall_AimU           , 
    0                                  , kButton_X+kButton_Down             , kPose_2D_FaceR_Fall_AimD           , 
    0xffff
  };

  static uint16 Trans_3e[] = {  //  0x91ace0
    0                                  , kButton_X+kButton_Left             , kPose_68_FaceL_Fall_Gun            , 
    0                                  , kButton_X+kButton_Up               , kPose_2C_FaceL_Fall_AimU           , 
    0                                  , kButton_X+kButton_Down             , kPose_2E_FaceL_Fall_AimD           , 
    0xffff
  };

  static uint16 Trans_41[] = {  //  0x91a64c
    kButton_Up                         , 0                                  , kPose_3E_FaceL_UnmorphTrans        , 
    kButton_A                          , 0                                  , kPose_3E_FaceL_UnmorphTrans        , 
    0                                  , kButton_Right                      , kPose_1E_MoveR_Morphball_Ground    , 
    0                                  , kButton_Left                       , kPose_1F_MoveL_Morphball_Ground    , 
    0xffff
  };

  static uint16 Trans_42[] = {  //  0x91a66a
    0xffff
  };

  static uint16 Trans_45[] = {  //  0x91a7cc
    0                                  , kButton_X+kButton_Left             , kPose_45                           , 
    0                                  , kButton_Right                      , kPose_09_MoveR_NoAim               , 
    0                                  , kButton_Left                       , kPose_25_FaceR_Turn_Stand          , 
    0xffff
  };

  static uint16 Trans_46[] = {  //  0x91a7e0
    0                                  , kButton_X+kButton_Right            , kPose_46                           , 
    0                                  , kButton_Left                       , kPose_0A_MoveL_NoAim               , 
    0                                  , kButton_Right                      , kPose_26_FaceL_Turn_Stand          , 
    0xffff
  };

  static uint16 Trans_47[] = {  //  0x91a7f4
    0xffff
  };

  static uint16 Trans_48[] = {  //  0x91a834
    0xffff
  };

  static uint16 Trans_49[] = {  //  0x91a874
    kButton_Down                       , 0                                  , kPose_36_FaceL_CrouchTrans         , 
    kButton_A                          , 0                                  , kPose_C0_FaceL_Moonwalk_TurnjumpR  , 
    kButton_A                          , kButton_R                          , kPose_C2_FaceL_Moonwalk_TurnjumpR_AimUL, 
    kButton_A                          , kButton_L                          , kPose_C4_FaceL_Moonwalk_TurnjumpR_AimDL, 
    0                                  , kButton_L+kButton_X+kButton_Right  , kPose_77_FaceL_Moonwalk_AimDL      , 
    0                                  , kButton_R+kButton_X+kButton_Right  , kPose_75_FaceL_Moonwalk_AimUL      , 
    0                                  , kButton_X+kButton_Right            , kPose_49_FaceL_Moonwalk            , 
    0                                  , kButton_Left                       , kPose_0A_MoveL_NoAim               , 
    0                                  , kButton_Right                      , kPose_26_FaceL_Turn_Stand          , 
    0xffff
  };

  static uint16 Trans_4a[] = {  //  0x91a8ac
    kButton_Down                       , 0                                  , kPose_35_FaceR_CrouchTrans         , 
    kButton_A                          , 0                                  , kPose_BF_FaceR_Moonwalk_TurnjumpL  , 
    kButton_A                          , kButton_R                          , kPose_C1_FaceR_Moonwalk_TurnjumpL_AimUR, 
    kButton_A                          , kButton_L                          , kPose_C3_FaceR_Moonwalk_TurnjumpL_AimDR, 
    0                                  , kButton_R+kButton_X+kButton_Left   , kPose_76_FaceR_Moonwalk_AimUR      , 
    0                                  , kButton_L+kButton_X+kButton_Left   , kPose_78_FaceR_Moonwalk_AimDR      , 
    0                                  , kButton_X+kButton_Left             , kPose_4A_FaceR_Moonwalk            , 
    0                                  , kButton_Right                      , kPose_09_MoveR_NoAim               , 
    0                                  , kButton_Left                       , kPose_25_FaceR_Turn_Stand          , 
    0xffff
  };

  static uint16 Trans_4b[] = {  //  0x91a28c
    0                                  , kButton_A+kButton_Left             , kPose_2F_FaceR_Turn_Jump           , 
    0                                  , kButton_A+kButton_Up               , kPose_15_FaceR_Jump_AimU           , 
    0                                  , kButton_A+kButton_Down             , kPose_17_FaceR_Jump_AimD           , 
    0                                  , kButton_R+kButton_A                , kPose_69_FaceR_Jump_AimUR          , 
    0                                  , kButton_L+kButton_A                , kPose_6B_FaceR_Jump_AimDR          , 
    0                                  , kButton_A+kButton_Right            , kPose_51_FaceR_Jump_NoAim_MoveF    , 
    0                                  , kButton_X+kButton_A                , kPose_13_FaceR_Jump_NoAim_NoMove_Gun, 
    0                                  , kButton_X                          , kPose_13_FaceR_Jump_NoAim_NoMove_Gun, 
    0xffff
  };

  static uint16 Trans_4c[] = {  //  0x91a2be
    0                                  , kButton_A+kButton_Right            , kPose_30_FaceL_Turn_Jump           , 
    0                                  , kButton_A+kButton_Up               , kPose_16_FaceL_Jump_AimU           , 
    0                                  , kButton_A+kButton_Down             , kPose_18_FaceL_Jump_AimD           , 
    0                                  , kButton_R+kButton_A                , kPose_6A_FaceL_Jump_AimUL          , 
    0                                  , kButton_L+kButton_A                , kPose_6C_FaceL_Jump_AimDL          , 
    0                                  , kButton_A+kButton_Left             , kPose_52_FaceL_Jump_NoAim_MoveF    , 
    0                                  , kButton_X+kButton_A                , kPose_14_FaceL_Jump_NoAim_NoMove_Gun, 
    0                                  , kButton_Right                      , kPose_30_FaceL_Turn_Jump           , 
    0                                  , kButton_X                          , kPose_14_FaceL_Jump_NoAim_NoMove_Gun, 
    0xffff
  };

  static uint16 Trans_4f[] = {  //  0x91a3f6
    0                                  , kButton_A+kButton_Left             , kPose_52_FaceL_Jump_NoAim_MoveF    , 
    0                                  , kButton_A+kButton_Right            , kPose_4F_FaceL_Dmgboost            , 
    0                                  , kButton_A                          , kPose_4E_FaceL_Jump_NoAim_NoMove_NoGun, 
    0xffff
  };

  static uint16 Trans_50[] = {  //  0x91a40a
    0                                  , kButton_A+kButton_Left             , kPose_50_FaceR_Dmgboost            , 
    0                                  , kButton_A+kButton_Right            , kPose_51_FaceR_Jump_NoAim_MoveF    , 
    0                                  , kButton_A                          , kPose_4D_FaceR_Jump_NoAim_NoMove_NoGun, 
    0xffff
  };

  static uint16 Trans_53[] = {  //  0x91a8e4
    0                                  , kButton_A+kButton_Left             , kPose_50_FaceR_Dmgboost            , 
    0xffff
  };

  static uint16 Trans_54[] = {  //  0x91a8ec
    0                                  , kButton_A+kButton_Right            , kPose_4F_FaceL_Dmgboost            , 
    0xffff
  };

  static uint16 Trans_5b[] = {  //  0x91a8fc
    0                                  , kButton_A+kButton_Left             , kPose_66                           , 
    0xffff
  };

  static uint16 Trans_5c[] = {  //  0x91a904
    0                                  , kButton_A+kButton_Right            , kPose_65                           , 
    0xffff
  };

  static uint16 Trans_63[] = {  //  0x91a990
    0                                  , kButton_A+kButton_Left             , kPose_66                           , 
    0xffff
  };

  static uint16 Trans_64[] = {  //  0x91a998
    0                                  , kButton_A+kButton_Right            , kPose_65                           , 
    0xffff
  };

  static uint16 Trans_65[] = {  //  0x91a9a0
    0                                  , kButton_A+kButton_Right            , kPose_65                           , 
    0                                  , kButton_R                          , kPose_69_FaceR_Jump_AimUR          , 
    0                                  , kButton_L                          , kPose_6B_FaceR_Jump_AimDR          , 
    0                                  , kButton_X                          , kPose_13_FaceR_Jump_NoAim_NoMove_Gun, 
    0                                  , kButton_A                          , kPose_65                           , 
    0                                  , kButton_Right                      , kPose_65                           , 
    0xffff
  };

  static uint16 Trans_66[] = {  //  0x91a9c6
    0                                  , kButton_A+kButton_Left             , kPose_66                           , 
    0                                  , kButton_R                          , kPose_6A_FaceL_Jump_AimUL          , 
    0                                  , kButton_L                          , kPose_6C_FaceL_Jump_AimDL          , 
    0                                  , kButton_X                          , kPose_14_FaceL_Jump_NoAim_NoMove_Gun, 
    0                                  , kButton_A                          , kPose_66                           , 
    0                                  , kButton_Left                       , kPose_66                           , 
    0xffff
  };

  static uint16 Trans_67[] = {  //  0x91af28
    0                                  , kButton_Right+kButton_Up           , kPose_6D_FaceR_Fall_AimUR          , 
    0                                  , kButton_Right+kButton_Down         , kPose_6F_FaceR_Fall_AimDR          , 
    0                                  , kButton_Up                         , kPose_2B_FaceR_Fall_AimU           , 
    0                                  , kButton_Down                       , kPose_2D_FaceR_Fall_AimD           , 
    0                                  , kButton_Left                       , kPose_87_FaceR_Turn_Fall           , 
    0                                  , kButton_R                          , kPose_6D_FaceR_Fall_AimUR          , 
    0                                  , kButton_L                          , kPose_6F_FaceR_Fall_AimDR          , 
    0                                  , kButton_X                          , kPose_67_FaceR_Fall_Gun            , 
    0                                  , kButton_Right                      , kPose_67_FaceR_Fall_Gun            , 
    0xffff
  };

  static uint16 Trans_68[] = {  //  0x91af60
    0                                  , kButton_Left+kButton_Up            , kPose_6E_FaceL_Fall_AimUL          , 
    0                                  , kButton_Left+kButton_Down          , kPose_70_FaceL_Fall_AimDL          , 
    0                                  , kButton_Up                         , kPose_2C_FaceL_Fall_AimU           , 
    0                                  , kButton_Down                       , kPose_2E_FaceL_Fall_AimD           , 
    0                                  , kButton_Right                      , kPose_88_FaceL_Turn_Fall           , 
    0                                  , kButton_R                          , kPose_6E_FaceL_Fall_AimUL          , 
    0                                  , kButton_L                          , kPose_70_FaceL_Fall_AimDL          , 
    0                                  , kButton_X                          , kPose_68_FaceL_Fall_Gun            , 
    0                                  , kButton_Left                       , kPose_68_FaceL_Fall_Gun            , 
    0xffff
  };

  static uint16 Trans_79[] = {  //  0x91a90c
    kButton_Up                         , 0                                  , kPose_3D_FaceR_UnmorphTrans        , 
    kButton_A                          , 0                                  , kPose_7F_FaceR_Springball_Air      , 
    0                                  , kButton_Right                      , kPose_7B_MoveR_Springball_Ground   , 
    0                                  , kButton_Left                       , kPose_7C_MoveL_Springball_Ground   , 
    0xffff
  };

  static uint16 Trans_7a[] = {  //  0x91a926
    kButton_Up                         , 0                                  , kPose_3E_FaceL_UnmorphTrans        , 
    kButton_A                          , 0                                  , kPose_80_FaceL_Springball_Air      , 
    0                                  , kButton_Right                      , kPose_7B_MoveR_Springball_Ground   , 
    0                                  , kButton_Left                       , kPose_7C_MoveL_Springball_Ground   , 
    0xffff
  };

  static uint16 Trans_7d[] = {  //  0x91a940
    kButton_Up                         , 0                                  , kPose_3D_FaceR_UnmorphTrans        , 
    0                                  , kButton_Left                       , kPose_7E_FaceL_Springball_Fall     , 
    0                                  , kButton_Right                      , kPose_7D_FaceR_Springball_Fall     , 
    0xffff
  };

  static uint16 Trans_7e[] = {  //  0x91a954
    kButton_Up                         , 0                                  , kPose_3E_FaceL_UnmorphTrans        , 
    0                                  , kButton_Right                      , kPose_7D_FaceR_Springball_Fall     , 
    0                                  , kButton_Left                       , kPose_7E_FaceL_Springball_Fall     , 
    0xffff
  };

  static uint16 Trans_7f[] = {  //  0x91a968
    kButton_Up                         , 0                                  , kPose_3D_FaceR_UnmorphTrans        , 
    0                                  , kButton_Right                      , kPose_7F_FaceR_Springball_Air      , 
    0                                  , kButton_Left                       , kPose_80_FaceL_Springball_Air      , 
    0xffff
  };

  static uint16 Trans_80[] = {  //  0x91a97c
    kButton_Up                         , 0                                  , kPose_3E_FaceL_UnmorphTrans        , 
    0                                  , kButton_Right                      , kPose_7F_FaceR_Springball_Air      , 
    0                                  , kButton_Left                       , kPose_80_FaceL_Springball_Air      , 
    0xffff
  };

  static uint16 Trans_81[] = {  //  0x91a55e
    kButton_X                          , 0                                  , kPose_13_FaceR_Jump_NoAim_NoMove_Gun, 
    kButton_X                          , kButton_Right                      , kPose_13_FaceR_Jump_NoAim_NoMove_Gun, 
    0                                  , kButton_X+kButton_Up               , kPose_15_FaceR_Jump_AimU           , 
    0                                  , kButton_X+kButton_Down             , kPose_17_FaceR_Jump_AimD           , 
    0                                  , kButton_R+kButton_X                , kPose_69_FaceR_Jump_AimUR          , 
    0                                  , kButton_L+kButton_X                , kPose_6B_FaceR_Jump_AimDR          , 
    0                                  , kButton_A+kButton_Right            , kPose_81_FaceR_Screwattack         , 
    0                                  , kButton_Up                         , kPose_15_FaceR_Jump_AimU           , 
    0                                  , kButton_R                          , kPose_69_FaceR_Jump_AimUR          , 
    0                                  , kButton_L                          , kPose_6B_FaceR_Jump_AimDR          , 
    0                                  , kButton_Down                       , kPose_17_FaceR_Jump_AimD           , 
    0                                  , kButton_Right                      , kPose_81_FaceR_Screwattack         , 
    0                                  , kButton_Left                       , kPose_82_FaceL_Screwattack         , 
    0xffff
  };

  static uint16 Trans_82[] = {  //  0x91a5ae
    kButton_X                          , 0                                  , kPose_14_FaceL_Jump_NoAim_NoMove_Gun, 
    kButton_X                          , kButton_Left                       , kPose_14_FaceL_Jump_NoAim_NoMove_Gun, 
    0                                  , kButton_X+kButton_Up               , kPose_16_FaceL_Jump_AimU           , 
    0                                  , kButton_X+kButton_Down             , kPose_18_FaceL_Jump_AimD           , 
    0                                  , kButton_R+kButton_X                , kPose_6A_FaceL_Jump_AimUL          , 
    0                                  , kButton_L+kButton_X                , kPose_6C_FaceL_Jump_AimDL          , 
    0                                  , kButton_A+kButton_Left             , kPose_82_FaceL_Screwattack         , 
    0                                  , kButton_Up                         , kPose_16_FaceL_Jump_AimU           , 
    0                                  , kButton_R                          , kPose_6A_FaceL_Jump_AimUL          , 
    0                                  , kButton_L                          , kPose_6C_FaceL_Jump_AimDL          , 
    0                                  , kButton_Down                       , kPose_18_FaceL_Jump_AimD           , 
    0                                  , kButton_Left                       , kPose_82_FaceL_Screwattack         , 
    0                                  , kButton_Right                      , kPose_81_FaceR_Screwattack         , 
    0xffff
  };

  static uint16 Trans_83[] = {  //  0x91a9ec
    kButton_Down                       , 0                                  , kPose_37_FaceR_MorphTrans          , 
    0                                  , kButton_Left                       , kPose_1A_FaceL_SpinJump            , 
    0                                  , kButton_R                          , kPose_69_FaceR_Jump_AimUR          , 
    0                                  , kButton_L                          , kPose_6B_FaceR_Jump_AimDR          , 
    0                                  , kButton_X                          , kPose_13_FaceR_Jump_NoAim_NoMove_Gun, 
    0                                  , kButton_A                          , kPose_83_FaceR_Walljump            , 
    0xffff
  };

  static uint16 Trans_84[] = {  //  0x91aa12
    kButton_Down                       , 0                                  , kPose_38_FaceL_MorphTrans          , 
    0                                  , kButton_Right                      , kPose_19_FaceR_SpinJump            , 
    0                                  , kButton_R                          , kPose_6A_FaceL_Jump_AimUL          , 
    0                                  , kButton_L                          , kPose_6C_FaceL_Jump_AimDL          , 
    0                                  , kButton_X                          , kPose_14_FaceL_Jump_NoAim_NoMove_Gun, 
    0                                  , kButton_A                          , kPose_84_FaceL_Walljump            , 
    0xffff
  };

  static uint16 Trans_89[] = {  //  0x91aa38
    kButton_A                          , 0                                  , kPose_4B_FaceR_Jumptrans           , 
    0                                  , kButton_Right+kButton_Up           , kPose_0F_MoveR_AimUR               , 
    0                                  , kButton_Right+kButton_Down         , kPose_11_MoveR_AimDR               , 
    kButton_Down                       , 0                                  , kPose_35_FaceR_CrouchTrans         , 
    0                                  , kButton_L+kButton_Left             , kPose_78_FaceR_Moonwalk_AimDR      , 
    0                                  , kButton_R+kButton_Left             , kPose_76_FaceR_Moonwalk_AimUR      , 
    0                                  , kButton_Up                         , kPose_03_FaceR_AimU                , 
    0                                  , kButton_R                          , kPose_05_FaceR_AimUR               , 
    0                                  , kButton_L                          , kPose_07_FaceR_AimDR               , 
    0                                  , kButton_Left                       , kPose_25_FaceR_Turn_Stand          , 
    0                                  , kButton_Right                      , kPose_09_MoveR_NoAim               , 
    0xffff
  };

  static uint16 Trans_8a[] = {  //  0x91aa7c
    kButton_A                          , 0                                  , kPose_4C_FaceL_Jumptrans           , 
    0                                  , kButton_Left+kButton_Up            , kPose_10_MoveL_AimUL               , 
    0                                  , kButton_Left+kButton_Down          , kPose_12_MoveL_AimDL               , 
    kButton_Down                       , 0                                  , kPose_36_FaceL_CrouchTrans         , 
    0                                  , kButton_L+kButton_Right            , kPose_77_FaceL_Moonwalk_AimDL      , 
    0                                  , kButton_R+kButton_Right            , kPose_75_FaceL_Moonwalk_AimUL      , 
    0                                  , kButton_Up                         , kPose_04_FaceL_AimU                , 
    0                                  , kButton_R                          , kPose_06_FaceL_AimUL               , 
    0                                  , kButton_L                          , kPose_08_FaceL_AimDL               , 
    0                                  , kButton_Right                      , kPose_26_FaceL_Turn_Stand          , 
    0                                  , kButton_Left                       , kPose_0A_MoveL_NoAim               , 
    0xffff
  };

  static uint16 Trans_8b[] = {  //  0x91ad1c
    kButton_A                          , kButton_Left                       , kPose_1A_FaceL_SpinJump            , 
    kButton_A                          , 0                                  , kPose_4C_FaceL_Jumptrans           , 
    0                                  , kButton_Left                       , kPose_8B_FaceR_Turn_Stand_AimU     , 
    0xffff
  };

  static uint16 Trans_8c[] = {  //  0x91ad30
    kButton_A                          , kButton_Right                      , kPose_19_FaceR_SpinJump            , 
    kButton_A                          , 0                                  , kPose_4B_FaceR_Jumptrans           , 
    0                                  , kButton_Right                      , kPose_8C_FaceL_Turn_Stand_AimU     , 
    0xffff
  };

  static uint16 Trans_8d[] = {  //  0x91ad44
    kButton_A                          , kButton_Left                       , kPose_1A_FaceL_SpinJump            , 
    kButton_A                          , 0                                  , kPose_4C_FaceL_Jumptrans           , 
    0                                  , kButton_Left                       , kPose_8D_FaceR_Turn_Stand_AimDR    , 
    0xffff
  };

  static uint16 Trans_8e[] = {  //  0x91ad58
    kButton_A                          , kButton_Right                      , kPose_19_FaceR_SpinJump            , 
    kButton_A                          , 0                                  , kPose_4B_FaceR_Jumptrans           , 
    0                                  , kButton_Right                      , kPose_8E_FaceL_Turn_Stand_AimDL    , 
    0xffff
  };

  static uint16 Trans_ba[] = {  //  0x91ae18
    0                                  , kButton_X+kButton_Left+kButton_Up  , kPose_BB_FaceL_Draygon_NoMove_AimUL, 
    0                                  , kButton_X+kButton_Left+kButton_Down, kPose_BD_FaceL_Draygon_NoMove_AimDL, 
    0                                  , kButton_X+kButton_Left             , kPose_BC_FaceL_Draygon_Fire        , 
    0                                  , kButton_R                          , kPose_BB_FaceL_Draygon_NoMove_AimUL, 
    0                                  , kButton_L                          , kPose_BD_FaceL_Draygon_NoMove_AimDL, 
    0                                  , kButton_X                          , kPose_BC_FaceL_Draygon_Fire        , 
    0                                  , kButton_Left                       , kPose_BE_FaceL_Draygon_Move        , 
    0                                  , kButton_Right                      , kPose_BE_FaceL_Draygon_Move        , 
    0                                  , kButton_Up                         , kPose_BE_FaceL_Draygon_Move        , 
    0                                  , kButton_Down                       , kPose_BE_FaceL_Draygon_Move        , 
    0xffff
  };

  static uint16 Trans_bf[] = {  //  0x91af98
    0                                  , kButton_A+kButton_Left             , kPose_1A_FaceL_SpinJump            , 
    kButton_A                          , 0                                  , kPose_4C_FaceL_Jumptrans           , 
    0                                  , kButton_Left                       , kPose_BF_FaceR_Moonwalk_TurnjumpL  , 
    0xffff
  };

  static uint16 Trans_c0[] = {  //  0x91afac
    0                                  , kButton_A+kButton_Right            , kPose_19_FaceR_SpinJump            , 
    kButton_A                          , 0                                  , kPose_4B_FaceR_Jumptrans           , 
    0                                  , kButton_Right                      , kPose_C0_FaceL_Moonwalk_TurnjumpR  , 
    0xffff
  };

  static uint16 Trans_c1[] = {  //  0x91afc0
    kButton_A                          , kButton_Left                       , kPose_1A_FaceL_SpinJump            , 
    kButton_A                          , 0                                  , kPose_4C_FaceL_Jumptrans           , 
    0                                  , kButton_Left                       , kPose_C1_FaceR_Moonwalk_TurnjumpL_AimUR, 
    0xffff
  };

  static uint16 Trans_c2[] = {  //  0x91afd4
    kButton_A                          , kButton_Right                      , kPose_19_FaceR_SpinJump            , 
    kButton_A                          , 0                                  , kPose_4B_FaceR_Jumptrans           , 
    0                                  , kButton_Right                      , kPose_C2_FaceL_Moonwalk_TurnjumpR_AimUL, 
    0xffff
  };

  static uint16 Trans_c3[] = {  //  0x91afe8
    kButton_A                          , kButton_Left                       , kPose_1A_FaceL_SpinJump            , 
    kButton_A                          , 0                                  , kPose_4C_FaceL_Jumptrans           , 
    0                                  , kButton_Left                       , kPose_C3_FaceR_Moonwalk_TurnjumpL_AimDR, 
    0xffff
  };

  static uint16 Trans_c4[] = {  //  0x91affc
    kButton_A                          , kButton_Right                      , kPose_19_FaceR_SpinJump            , 
    kButton_A                          , 0                                  , kPose_4B_FaceR_Jumptrans           , 
    0                                  , kButton_Right                      , kPose_C4_FaceL_Moonwalk_TurnjumpR_AimDL, 
    0xffff
  };

  static uint16 Trans_c7[] = {  //  0x91ad6c
    0                                  , kButton_A+kButton_Up               , kPose_CB_FaceR_Shinespark_Vert     , 
    0                                  , kButton_R+kButton_A                , kPose_CD_FaceR_Shinespark_Diag     , 
    0                                  , kButton_A+kButton_Right            , kPose_C9_FaceR_Shinespark_Horiz    , 
    0xffff
  };

  static uint16 Trans_c8[] = {  //  0x91ad80
    0                                  , kButton_A+kButton_Up               , kPose_CC_FaceL_Shinespark_Vert     , 
    0                                  , kButton_R+kButton_A                , kPose_CE_FaceL_Shinespark_Diag     , 
    0                                  , kButton_A+kButton_Left             , kPose_CA_FaceL_Shinespark_Horiz    , 
    0xffff
  };

  static uint16 Trans_df[] = {  //  0x91ae10
    kButton_Up                         , 0                                  , kPose_DE                           , 
    0xffff
  };

  static uint16 Trans_ec[] = {  //  0x91ae56
    0                                  , kButton_X+kButton_Right+kButton_Up , kPose_ED_FaceR_Draygon_NoMove_AimUR, 
    0                                  , kButton_X+kButton_Right+kButton_Down, kPose_EF_FaceR_Draygon_NoMove_AimDR, 
    0                                  , kButton_X+kButton_Right            , kPose_EE_FaceR_Draygon_Fire        , 
    0                                  , kButton_R                          , kPose_ED_FaceR_Draygon_NoMove_AimUR, 
    0                                  , kButton_L                          , kPose_EF_FaceR_Draygon_NoMove_AimDR, 
    0                                  , kButton_X                          , kPose_EE_FaceR_Draygon_Fire        , 
    0                                  , kButton_Left                       , kPose_F0_FaceR_Draygon_Move        , 
    0                                  , kButton_Right                      , kPose_F0_FaceR_Draygon_Move        , 
    0                                  , kButton_Up                         , kPose_F0_FaceR_Draygon_Move        , 
    0                                  , kButton_Down                       , kPose_F0_FaceR_Draygon_Move        , 
    0xffff
  };

  switch (samus_pose) {
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
    default: return (uint16*)Unreachable();
  }
}

