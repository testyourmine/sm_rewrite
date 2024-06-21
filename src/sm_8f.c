// Rooms definitions
#include "ida_types.h"
#include "variables.h"
#include "sm_rtl.h"
#include "funcs.h"
#include "sm_8f.h"

void RoomCode_GenRandomExplodes(uint16 x_r18, uint16 y_r20);

/**
* @brief Clears the block passage and shakes the screen after saving the animals in the Bomb Torizo room during the escape
* @brief Used in the Crateria mainstreet room
*/
void RoomSetup_AfterSavingAnimals(void) {  // 0x8F9194
  SpawnHardcodedPlm((SpawnHardcodedPlmArgs) { .x_pos = 61, .y_pos = 11, .plm_id_ = addr_kPlmHeader_BB30_Crateria_Mainstreet_ClearPassageIfCrittersEscaped });
  earthquake_type = EARTHQUAKE(kEarthquake_Direction_Horiz, kEarthquake_Intensity_3, kEarthquake_Layers_Bg1_Bg2_Enemies);
  earthquake_timer = -1;
}

/**
* @brief Destroys the wall in the Old Tourian escape shaft during the escape
*/
void RoomSetup_AutoDestroyWallAfterEscape(void) {  // 0x8F91A9
  SpawnHardcodedPlm((SpawnHardcodedPlmArgs) { .x_pos = 16, .y_pos = 135, .plm_id_ = addr_kPlmHeader_B964_OldTourianEscapeShaft_ExplodeFakeWall });
}

/**
* @brief Turns the wall into shotblocks in the Bomb Torizo room during the escape
*/
void RoomSetup_TurnWallIntoShotblocks(void) {  // 0x8F91B2
  SpawnHardcodedPlm((SpawnHardcodedPlmArgs) { .x_pos = 15, .y_pos = 10, .plm_id_ = addr_kPlmHeader_B9ED_CrittersEscapeBlock });
}

/**
* @brief Shake the screen in the landing site during the escape
*/
void RoomSetup_ShakeDuringEscape(void) {  // 0x8F91BD
  earthquake_type = EARTHQUAKE(kEarthquake_Direction_Horiz, kEarthquake_Intensity_3, kEarthquake_Layers_Bg1);
  earthquake_timer = -1;
  FxTypeFunc_20_ScrollingSkyLand();
}

/**
* @brief Set up the scrolling sky for the landing site
*/
void RoomSetup_ScrollingSkyLand(void) {  // 0x8F91C9
  FxTypeFunc_20_ScrollingSkyLand();
}

/**
* @brief Set up the scrolling sky for the large room leading to the Wrecked Ship
*/
void RoomSetup_ScrollingSkyOcean(void) {  // 0x8F91CE
  RoomSetupAsm_ScrollingSkyOcean();
}

/**
* @brief Run the unlock animations for the statues in the Tourian entrance
*/
void RoomSetup_RunStatueUnlockAnims(void) {  // 0x8F91D7
  SpawnAnimtiles(addr_kAnimtiles_TourianStatue_Kraid);
  SpawnAnimtiles(addr_kAnimtiles_TourianStatue_Phantoon);
  SpawnAnimtiles(addr_kAnimtiles_TourianStatue_Draygon);
  SpawnAnimtiles(addr_kAnimtiles_TourianStatue_Ridley);
}

/**
* @brief Start the tiles and PLM for the treadmill in the Wrecked Ship west entrance
*/
void DoorCode_StartWreckedShipTreadmill_West(void) {  // 0x8FB971
  SpawnAnimtiles(addr_kAnimtiles_WreckedShipTreadmillRight);
  SpawnHardcodedPlm((SpawnHardcodedPlmArgs) { .x_pos = 4, .y_pos = 9, .plm_id_ = addr_kPlmHeader_B64B_WreckedShip_EntranceTreadmill_West });
}

/**
* Used by:
* kRoom_93D5_Crateria_save_station door 0
* kRoom_96BA_Old_Tourian_escape_shaft door 0
* kRoom_98E2_Pre_Crateria_map_station_hall door 0
* kRoom_9A44_Crateria_bomb_block_hall door 1
*/
void DoorCode_Scroll6_Green(void) {  // 0x8FB981
  scrolls[6] = kScroll_Green;
}

/**
* Used by:
* kRoom_990D_Crateria_slope door 1
*/
void DoorCode_Scroll0_Blue(void) {  // 0x8FB98C
  scrolls[0] = kScroll_Blue;
}

/**
* Used by:
* kRoom_92B3_Gauntlet_east door 0
*/
void DoorCode_Scroll13_Blue(void) {  // 0x8FB997
  scrolls[19] = kScroll_Blue;
}

/**
* Used by:
* kRoom_9879_Pre_Bomb_Torizo_hall door 0
*/
void DoorCode_Scroll_4Blue_8Green(void) {  // 0x8FB9A2
  scrolls[4] = kScroll_Red;
  scrolls[8] = kScroll_Green;
}

/**
* Used by:
* kRoom_93FE_Wrecked_Ship_entrance door 4
*/
void DoorCode_Scroll_8toB_Red(void) {  // 0x8FB9B3
  scrolls[11] = scrolls[10] = scrolls[9] = scrolls[8] = kScroll_Red;
}

/**
* Used by:
* kRoom_968F_Orange_zoomer_hall door 1
*/
void DoorCode_Scroll_LotsRed(void) {  // 0x8FB9CA
  scrolls[5] = scrolls[4] = scrolls[3] = scrolls[2] = kScroll_Red;
  scrolls[17] = scrolls[13] = scrolls[12] = scrolls[11] = kScroll_Red;
}

/**
* Used by:
* kRoom_962A_Crateria_to_Red_Brinstar_elevator door 0
*/
void DoorCode_Scroll_1_4_Green(void) {  // 0x8FB9F1
  scrolls[4] = scrolls[1] = kScroll_Green;
}

/**
* Used by:
* kRoom_99F9_Crateria_spike_floor_room door 0
*/
void DoorCode_Scroll_2_Blue(void) {  // 0x8FBA00
  scrolls[2] = kScroll_Blue;
}

/**
* Used by:
* kRoom_99F9_Crateria_spike_floor_room door 1
*/
void DoorCode_Scroll_17_Blue(void) {  // 0x8FBA0B
  scrolls[23] = kScroll_Blue;
}

/**
* Used by:
* kRoom_99BD_Crateria_space_pirate_shaft door 3
*/
void DoorCode_Scroll_4_Blue(void) {  // 0x8FBA16
  scrolls[4] = kScroll_Blue;
}

/**
* Used by:
* kRoom_962A_Crateria_to_Red_Brinstar_elevator door 1
*/
void DoorCode_Scroll_6_Green(void) {  // 0x8FBA21
  scrolls[6] = kScroll_Green;
}

/**
* Used by:
* kRoom_965B_Gauntlet_west door 1
*/
void DoorCode_Scroll_3_Green(void) {  // 0x8FBA2C
  scrolls[3] = kScroll_Green;
}

/**
* @todo the rest of these
*/
void DoorCode_SetScroll_0(void) {  // 0x8FBD07
  scrolls[28] = scrolls[24] = kScroll_Green;
}

void DoorCode_SetScroll_1(void) {  // 0x8FBD16
  scrolls[6] = scrolls[5] = kScroll_Blue;
}

void DoorCode_SetScroll_2(void) {  // 0x8FBD25
  scrolls[29] = kScroll_Blue;
}

void DoorCode_SetScroll_3(void) {  // 0x8FBD30
  scrolls[3] = scrolls[2] = kScroll_Green;
}

void DoorCode_SetScroll_4(void) {  // 0x8FBD3F
  scrolls[0] = kScroll_Red;
  scrolls[1] = kScroll_Green;
}

void DoorCode_SetScroll_5(void) {  // 0x8FBD50
  scrolls[11] = kScroll_Green;
}

void DoorCode_SetScroll_6(void) {  // 0x8FBD5B
  scrolls[28] = kScroll_Red;
  scrolls[29] = kScroll_Blue;
}

void DoorCode_SetScroll_7(void) {  // 0x8FBD6C
  scrolls[4] = kScroll_Red;
}

void DoorCode_SetScroll_8(void) {  // 0x8FBD77
  scrolls[37] = scrolls[36] = scrolls[32] = kScroll_Green;
}

void DoorCode_SetScroll_9(void) {  // 0x8FBD8A
  scrolls[2] = kScroll_Blue;
}

void DoorCode_SetScroll_10(void) {  // 0x8FBD95
  scrolls[0] = kScroll_Green;
}

void DoorCode_SetScroll_11(void) {  // 0x8FBDA0
  scrolls[7] = scrolls[6] = kScroll_Green;
}

void DoorCode_SetScroll_12(void) {  // 0x8FBDAF
  scrolls[1] = kScroll_Blue;
  scrolls[2] = kScroll_Red;
}

void DoorCode_SetScroll_13(void) {  // 0x8FBDC0
  scrolls[1] = kScroll_Blue;
  scrolls[3] = kScroll_Red;
}

void DoorCode_SetScroll_14(void) {  // 0x8FBDD1
  scrolls[0] = kScroll_Red;
  scrolls[4] = kScroll_Blue;
}

void DoorCode_SetScroll_15(void) {  // 0x8FBDE2
  scrolls[3] = scrolls[2] = kScroll_Blue;
}

void DoorCode_SetScroll_16(void) {  // 0x8FBDF1
  scrolls[1] = scrolls[0] = kScroll_Green;
}

void DoorCode_SetScroll_17(void) {  // 0x8FBE00
  scrolls[1] = kScroll_Green;
}

void DoorCode_SetScroll_18(void) {  // 0x8FBE0B
  scrolls[18] = scrolls[15] = kScroll_Green;
}

void DoorCode_SetScroll_19(void) {  // 0x8FBE1A
  scrolls[6] = kScroll_Green;
}

void DoorCode_SetScroll_20(void) {  // 0x8FBE25
  scrolls[0] = kScroll_Green;
  scrolls[1] = kScroll_Blue;
}

void DoorCode_SetScroll_21(void) {  // 0x8FBE36
  scrolls[2] = kScroll_Green;
}

void DoorCode_SetScroll_22(void) {  // 0x8FBF9E
  scrolls[4] = scrolls[3] = kScroll_Red;
  scrolls[8] = scrolls[7] = scrolls[6] = kScroll_Blue;
}

void DoorCode_SetScroll_23(void) {  // 0x8FBFBB
  scrolls[3] = scrolls[2] = scrolls[1] = kScroll_Blue;
  scrolls[4] = kScroll_Green;
  scrolls[6] = kScroll_Red;
}

void DoorCode_SetScroll_24(void) {  // 0x8FBFDA
  scrolls[1] = scrolls[0] = kScroll_Blue;
}

void DoorCode_SetScroll_25(void) {  // 0x8FBFE9
  scrolls[1] = kScroll_Red;
  scrolls[0] = kScroll_Blue;
}

void DoorCode_SetScroll_26(void) {  // 0x8FBFFA
  scrolls[10] = kScroll_Green;
}

void DoorCode_SetScroll_27(void) {  // 0x8FC005
  scrolls[0] = kScroll_Blue;
  scrolls[2] = kScroll_Red;
}

void DoorCode_SetScroll_28(void) {  // 0x8FC016
  scrolls[2] = scrolls[0] = kScroll_Green;
}

void DoorCode_SetScroll_29(void) {  // 0x8FC025
  scrolls[7] = scrolls[6] = kScroll_Blue;
  scrolls[8] = kScroll_Red;
}

void DoorCode_SetScroll_30(void) {  // 0x8FC03A
  scrolls[2] = kScroll_Red;
  scrolls[3] = kScroll_Blue;
}

void DoorCode_SetScroll_31(void) {  // 0x8FC04B
  scrolls[7] = kScroll_Green;
}

void DoorCode_SetScroll_32(void) {  // 0x8FC056
  scrolls[1] = kScroll_Red;
  scrolls[2] = kScroll_Blue;
}

void DoorCode_SetScroll_33(void) {  // 0x8FC067
  scrolls[3] = kScroll_Red;
  scrolls[0] = kScroll_Blue;
}

void DoorCode_SetScroll_34(void) {  // 0x8FC078
  scrolls[1] = kScroll_Blue;
  scrolls[4] = kScroll_Red;
}

void DoorCode_SetScroll_35(void) {  // 0x8FC089
  scrolls[0] = kScroll_Blue;
  scrolls[3] = scrolls[2] = scrolls[1] = kScroll_Red;
}

void DoorCode_SetScroll_36(void) {  // 0x8FC0A2
  scrolls[0] = kScroll_Green;
}

void DoorCode_SetScroll_37(void) {  // 0x8FC0AD
  scrolls[1] = scrolls[0] = kScroll_Blue;
  scrolls[4] = kScroll_Red;
}

void DoorCode_SetScroll_38(void) {  // 0x8FC0C2
  scrolls[0] = kScroll_Blue;
  scrolls[3] = kScroll_Red;
}

void DoorCode_SetScroll_39(void) {  // 0x8FC0D3
  scrolls[0] = kScroll_Blue;
}

void DoorCode_SetScroll_40(void) {  // 0x8FC0DE
  scrolls[0] = kScroll_Blue;
  scrolls[1] = kScroll_Red;
}

void DoorCode_SetScroll_41(void) {  // 0x8FC0EF
  scrolls[24] = kScroll_Blue;
}

void DoorCode_SetScroll_42(void) {  // 0x8FC0FA
  scrolls[3] = kScroll_Red;
  scrolls[2] = kScroll_Blue;
}

void DoorCode_SetScroll_43(void) {  // 0x8FC10B
  scrolls[14] = kScroll_Red;
}

void RoomCode_ScrollingSkyLand_(void) {  // 0x8FC116
  RoomCode_ScrollingSkyLand();
}

void RoomCode_ScrollingSkyOcean_(void) {  // 0x8FC11B
  RoomMainAsm_ScrollingSkyOcean();
}

/**
* @brief Create random explosions on even frames on random non blank tiles
*/
void RoomCode_GenRandomExplodes_EvenFrames_NonblankTile(void) {  // 0x8FC131
  if (!time_is_frozen_flag && (nmi_frame_counter_word & 1) == 0) {
    uint16 Random = NextRandom();
    uint16 x_pos = layer1_x_pos + LOBYTE(Random);
    uint16 y_pos = layer1_y_pos + HIBYTE(Random);
    uint16 block_index = Mult8x8(y_pos / 0x10, room_width_in_blocks) + (x_pos / 0x10);
    if ((level_data[block_index] & 0x3FF) != 0xFF)
      RoomCode_GenRandomExplodes(x_pos, y_pos);
  }
}

/**
* @brief Create explosions and shake the screen in Brinstar during the escape
*/
void RoomCode_ExplodeShakes(void) {  // 0x8FC124
  RoomCode_GenRandomExplodes_EvenFrames_NonblankTile();
  earthquake_timer |= 0x8000;
}

/**
* @brief Handle scrolling sky and random explosions for the landing site during the escape
*/
void RoomCode_ScrollingSkyLand_Shakes(void) {  // 0x8FC120
  RoomCode_ScrollingSkyLand();
  RoomCode_ExplodeShakes();
}

/**
* @brief Create random explosions on every fourth frame
*/
void RoomCode_GenRandomExplodes_Every4Frames(void) {  // 0x8FC183
  if (!time_is_frozen_flag && (nmi_frame_counter_word & 3) == 0) {
    uint16 Random = NextRandom();
    uint16 x_pos = layer1_x_pos + LOBYTE(Random);
    uint16 y_pos = layer1_y_pos + HIBYTE(Random);
    RoomCode_GenRandomExplodes(x_pos, y_pos);
  }
}

/**
* @brief Generates random explosions at (x_pos, y_pos)
* @param x_pos The x position of the explosion
* @param y_pos The y position of the explosion
*/
void RoomCode_GenRandomExplodes(uint16 x_pos, uint16 y_pos) {  // 0x8FC1A9
  static const uint8 kRoomCode_GenRandomExplodes_Sprite[8] = { 3, 3, 9, 12, 12, 18, 18, 21 };
  static const uint8 kRoomCode_GenRandomExplodes_Sfx[8] = { kSfx2_SmallExplosion, 0, 0, kSfx2_BigExplosion, 0, 0, 0, 0 };

  // Bugfix, X is garbage
  uint16 Random = NextRandom() & 0xF;
  if (Random < 8) {
    uint16 explosion_sfx = kRoomCode_GenRandomExplodes_Sfx[Random];
    if (explosion_sfx != 0)
      QueueSfx2_Max6(explosion_sfx);
  }
  uint16 explosion_sprite = kRoomCode_GenRandomExplodes_Sprite[Random & 7];
  CreateSpriteAtPos(x_pos, y_pos, explosion_sprite, 0);
}

/**
* @brief Scrolls the screen right in the Dachora room
*/
void RoomCode_ScrollRightDachora(void) {  // 0x8FC1E6
  // This statement is never satisfied, so the scrolling never happens
  if (scrolls[11] == kScroll_Green && layer1_y_pos < 0x500 && layer1_x_pos < 0x380)
    layer1_x_pos += (layer1_x_pos >= 0x380) + 3; // Wrong?
}

/**
* @brief Spawns the "projectile" that scrolls BG2 in the pre-Phantoon room
*/
void RoomCode_SpawnPrePhantoonRoomEnemyProj(void) {  // 0x8FC8C8
  SpawnEprojWithRoomGfx(addr_kEproj_PrePhantomRoom, 0);
}

/**
* @brief Spawn the PLMs in Shaktools room
*/
void RoomCode_SetupShaktoolRoomPlm(void) {  // 0x8FC8D3
  SpawnHardcodedPlm((SpawnHardcodedPlmArgs) { .x_pos = 0, .y_pos = 0, .plm_id_ = addr_kPlmHeader_B8EB_ShaktoolsRoom });
}

/**
* @brief Set the pausing function for Draygon's room
*/
void RoomCode_SetPauseCodeForDraygon(void) {  // 0x8FC8DD
  pause_hook = (LongPtr)LONGPTR(fnPauseHook_DraygonRoom);
  unpause_hook = (LongPtr)LONGPTR(fnUnpauseHook_DraygonRoom);
}

/**
* @brief Set the interrupt to main gameplay when pausing in Draygon's room
*/
void PauseHook_DraygonRoom(void) {  // 0x8FC8F6
  irqhandler_next_handler = kInterruptCommand_4_Main_BeginHudDraw;
}

/**
* @brief Set the interrupt to Draygon's room
*/
CoroutineRet UnpauseHook_DraygonRoom(void) {  // 0x8FC8FC
  if (hdma_object_channels_bitmask[1] == 8)
    irqhandler_next_handler = kInterruptCommand_12_Draygon_BeginHud;
  return kCoroutineNone;
}

/**
* @brief Reveal the Tourian map when first taking the elevator
*/
void RoomCode_SetCollectedMap(void) {  // 0x8FC90A
  has_area_map = WORD(map_station_byte_array[area_index]) |= 1;
}

/**
* @brief Sets the Zebes escape event and lightly shake the screen in the first escape room after Mother Brain
*/
void RoomCode_SetZebesTimebombEvent(void) {  // 0x8FC91F
  SetEventHappened(kEvent_14_ZebesTimebombSet);
  earthquake_type = EARTHQUAKE(kEarthquake_Direction_Horiz, kEarthquake_Intensity_1, kEarthquake_Layers_Bg1_Bg2_Enemies);
  earthquake_timer = -1;
}

/**
* @brief Lightly shake the screen in the second escape room
*/
void RoomCode_SetLightHorizRoomShake(void) {  // 0x8FC933
  earthquake_type = EARTHQUAKE(kEarthquake_Direction_Horiz, kEarthquake_Intensity_1, kEarthquake_Layers_Bg1_Bg2_Enemies);
  room_shake_type = earthquake_type;
  diagonal_shake_timer = 0;
  earthquake_timer = -1;
}

/**
* @brief Mediumly shake the screen in the third escape room
*/
void RoomCode_SetMediumHorizRoomShake(void) {  // 0x8FC946
  earthquake_type = EARTHQUAKE(kEarthquake_Direction_Horiz, kEarthquake_Intensity_2, kEarthquake_Layers_Bg1_Bg2_Enemies);
  earthquake_timer = -1;
}

/**
* @brief Set up the PLMs and mediumly shake the screen in the fourth escape room
*/
void RoomCode_Escape4_SetMediumHorizRoomShake(void) {  // 0x8FC953
  SpawnHardcodedPlm((SpawnHardcodedPlmArgs) { .x_pos = 16, .y_pos = 16, .plm_id_ = addr_kPlmHeader_B968_EscapeRoom4_RaiseAcid });
  earthquake_type = EARTHQUAKE(kEarthquake_Direction_Horiz, kEarthquake_Intensity_2, kEarthquake_Layers_Bg1_Bg2_Enemies);
  room_shake_type = earthquake_type;
  diagonal_shake_timer = 0;
  earthquake_timer = -1;
}

/**
* @brief Turn the Ceres elevator door solid during the escape and spawn haze
*/
void RoomCode_SetCeresDoorSolid(void) {  // 0x8FC96E
  SpawnHardcodedPlm((SpawnHardcodedPlmArgs) { .x_pos = 15, .y_pos = 38, .plm_id_ = addr_kPlmHeader_BA48_Ceres_ElevatorShaft_TurnDoorSolidDuringEscape });
  FxTypeFunc_2C_Haze();
}

/**
* @brief Spawn haze in Ceres rooms
*/
void RoomCode_SpawnHaze(void) {  // 0x8FC976
  FxTypeFunc_2C_Haze();
}

/**
* @brief Set the BG address to 0x6000 and spawn haze in Ceres Ridley's room
*/
void RoomCode_SpawnHaze_BgBase(void) {  // 0x8FC97B
  reg_BG12NBA = 0x66;
  FxTypeFunc_2C_Haze();
  hdma_data_table_in_ceres = 9;
}

/**
* @brief Start the tiles and PLM for the treadmill in the Wrecked Ship east entrance
*/
void DoorCode_StartWreckedSkipTreadmill_East(void) {  // 0x8FE1D8
  SpawnAnimtiles(addr_kAnimtiles_WreckedShipTreadmillLeft);
  SpawnHardcodedPlm((SpawnHardcodedPlmArgs) { .x_pos = 4, .y_pos = 9, .plm_id_ = addr_kPlmHeader_B64F_WreckedShip_EntranceTreadmill_East });
}

void DoorCode_SetScroll_44(void) {  // 0x8FE1E8
  scrolls[1] = kScroll_Blue;
}

void DoorCode_SetScroll_45(void) {  // 0x8FE1F3
  scrolls[0] = kScroll_Green;
}

void DoorCode_SetScroll_46(void) {  // 0x8FE1FE
  scrolls[3] = kScroll_Red;
  scrolls[4] = kScroll_Blue;
}

void DoorCode_SetScroll_47(void) {  // 0x8FE20F
  scrolls[41] = kScroll_Blue;
}

void DoorCode_SetScroll_48(void) {  // 0x8FE21A
  scrolls[46] = scrolls[40] = kScroll_Green;
}

void DoorCode_SetScroll_49(void) {  // 0x8FE229
  scrolls[11] = scrolls[10] = scrolls[9] = scrolls[8] = scrolls[7] = scrolls[6] = kScroll_Red;
}

/**
* @brief Lock Samus and set up the elevatube from the south entrance
*/
void DoorCode_SetupElevatubeFromSouth(void) {  // 0x8FE26C
  elevatube_velocity = -0x100;
  elevatube_position = 0x40*39;
  elevatube_acceleration = -0x20;
  RunSamusCode(kSamusCode_0_LockSamus);
  SpawnHardcodedPlm((SpawnHardcodedPlmArgs) { .x_pos = 1, .y_pos = 0, .plm_id_ = addr_kPlmHeader_B8F9_Maridia_Elevatube });
}

/**
* @brief Lock Samus and set up the elevatube from the north entrance
*/
void DoorCode_SetupElevatubeFromNorth(void) {  // 0x8FE291
  elevatube_velocity = 0x100;
  elevatube_position = 0x40;
  elevatube_acceleration = 0x20;
  RunSamusCode(kSamusCode_0_LockSamus);
  SpawnHardcodedPlm((SpawnHardcodedPlmArgs) { .x_pos = 1, .y_pos = 0, .plm_id_ = addr_kPlmHeader_B8F9_Maridia_Elevatube });
}

/**
* @brief Move the elevatube and move Samus through the elevatube
*/
void RoomCode_Elevatube(void) {  // 0x8FE2B6
  samus_x_pos = 128;
  samus_x_subpos = 0;
  int32 vel = INT16_SHL8(elevatube_velocity);
  uint16 pos = (vel + DWORD(elevatube_subposition)) >> 16;
  elevatube_subposition += vel;
  elevatube_position = pos;
  Samus_MoveDown_NoSolidColl(vel);
  if ((uint16)(elevatube_acceleration + elevatube_velocity + 0xE20) < 0x1C41)
    elevatube_velocity += elevatube_acceleration;
}

/**
* @brief Unlock Samus and reset the elevatube when exiting north
*/
void DoorCode_ResetElevatubeNorthExit(void) {  // 0x8FE301
  RunSamusCode(kSamusCode_1_UnlockSamus);
}

/**
* @brief Unlock Samus and reset the elevatube when exiting south
*/
void DoorCode_ResetElevatubeSouthExit(void) {  // 0x8FE309
  scrolls[1] = scrolls[0] = kScroll_Green;
  RunSamusCode(kSamusCode_1_UnlockSamus);
}

void DoorCode_SetScroll_50(void) {  // 0x8FE318
  scrolls[10] = kScroll_Red;
  scrolls[11] = kScroll_Blue;
}

void UNUSED_DoorCode_SetScroll_51(void) {  // 0x8FE329
  scrolls[17] = kScroll_Red;
  scrolls[16] = kScroll_Blue;
}

void UNUSED_DoorCode_SetScroll_52(void) {  // 0x8FE33A
  scrolls[4] = kScroll_Green;
}

void DoorCode_SetScroll_53(void) {  // 0x8FE345
  scrolls[0] = kScroll_Red;
  scrolls[4] = kScroll_Blue;
}

void DoorCode_SetScroll_54(void) {  // 0x8FE356
  scrolls[0] = kScroll_Red;
  scrolls[1] = kScroll_Blue;
}

void DoorCode_SetScroll_55(void) {  // 0x8FE367
  scrolls[9] = kScroll_Red;
  scrolls[10] = kScroll_Blue;
}

void DoorCode_SetScroll_56(void) {  // 0x8FE378
  scrolls[2] = scrolls[0] = kScroll_Red;
  scrolls[1] = kScroll_Blue;
}

void DoorCode_SetScroll_57(void) {  // 0x8FE38D
  scrolls[1] = kScroll_Blue;
}

void DoorCode_SetScroll_58(void) {  // 0x8FE398
  scrolls[6] = kScroll_Blue;
}

void DoorCode_SetScroll_59(void) {  // 0x8FE3A3
  scrolls[4] = kScroll_Red;
}

void DoorCode_SetScroll_60(void) {  // 0x8FE3AE
  scrolls[1] = kScroll_Red;
}

void DoorCode_SetScroll_61(void) {  // 0x8FE3B9
  scrolls[7] = scrolls[4] = kScroll_Red;
}

void DoorCode_SetScroll_62(void) {  // 0x8FE3C8
  scrolls[2] = kScroll_Red;
  scrolls[1] = kScroll_Blue;
}

void DoorCode_SetScroll_63(void) {  // 0x8FE3D9
  scrolls[2] = scrolls[0] = kScroll_Green;
}

void DoorCode_SetScroll_64(void) {  // 0x8FE4C0
  scrolls[1] = scrolls[0] = kScroll_Green;
}

void DoorCode_SetScroll_65(void) {  // 0x8FE4CF
  scrolls[24] = kScroll_Blue;
  scrolls[25] = kScroll_Red;
}

/**
* @brief Set up Mode 7 for the Ceres elevator shaft during the escape
*/
void DoorCode_ToCeresElevatorShaft(void) {  // 0x8FE4E0
  reg_BGMODE_fake = 7;
  WriteReg(BGMODE, 7);
  // Set Mode 7 transformation matrix to identity
  reg_M7A = 256;
  reg_M7D = 256;
  reg_M7B = 0;
  reg_M7C = 0;
  // Set Mode 7 transformation origin to (128, 1008), which is the bottom of the room in the center
  reg_M7X = 8*16;
  reg_M7Y = 63*16;
  irq_enable_mode7 = 1;
  // Start the index at 34, which is the axis of symmetry for the matrix
  uint16 starting_index = arraysize(kCeresElevatorShaftMode7TransformationMatrix) / 2;
  rotation_matrix_index = starting_index;
  elevatube_position = 60;
}

/**
* @brief Remove Mode 7 for the Ceres elevator shaft during the escape
*/
void DoorCode_FromCeresElevatorShaft(void) {  // 0x8FE513
  reg_BGMODE_fake = 9;
  irq_enable_mode7 = 0;
}

/**
* @brief Handles Mode 7 operations and landing on the elevator for the Ceres elevator shaft during the escape
*/
void RoomCode_CeresElevatorShaft_(void) {  // 0x8FE51F
  RoomCode_CeresElevatorShaft();
}

/**
* @brief Spawn falling debris in hall before the Ceres elevator during the escape
*/
void RoomCode_SpawnCeresFallingDebris(void) {  // 0x8FE525
  static const uint16 kRoomCode_SpawnCeresFallingDebris_XPos[16] = {
     0x50,  0x60,  0x70,  0x80,  0x90, 0xa0, 0xb0, 0xc0, 0xd0, 0xe0, 0xf0,
    0x110, 0x130, 0x150, 0x170, 0x190,
  };

  if (ceres_status != kCeresStatus_0_BeforeRidleyEscape && (int16)--debris_delay_timer < 0) {
    debris_delay_timer = 8;
    uint16 debris_eproj = sign16(random_number) ? addr_kEproj_CeresFallingDebris_Dark : addr_kEproj_CeresFallingDebris_Light;
    uint16 x_pos = kRoomCode_SpawnCeresFallingDebris_XPos[random_number & 0xF];
    SpawnEprojWithRoomGfx(debris_eproj, x_pos);
  }
}

/**
* @brief Handles Ceres Ridley's escape cutscene
*/
void RoomCode_HandleCeresRidleyGetaway(void) {  // 0x8FE571
  if (ceres_status & kCeresStatus_1_DuringRidleyEscapeCutscene)
    HandleCeresRidleyGetawayCutscene();
}

/**
* @brief Set the screen shake to be light horizontal, with a 1/128 chance of being medium diagonal for 42 frames
* @brief Used in the second Tourian escape room
*/
void RoomCode_ShakeScreenHorizDiag(void) {  // 0x8FE57C
  uint16 earthquake;

  if (diagonal_shake_timer != 0) {
    if (--diagonal_shake_timer == 0) {
      earthquake = EARTHQUAKE(kEarthquake_Direction_Horiz, kEarthquake_Intensity_1, kEarthquake_Layers_Bg1_Bg2_Enemies);
      earthquake_type = earthquake;
    }
  }
  else if (NextRandom() < 0x200) {
    diagonal_shake_timer = 42;
    earthquake = EARTHQUAKE(kEarthquake_Direction_Diag, kEarthquake_Intensity_2, kEarthquake_Layers_Bg1_Bg2_Enemies);
    earthquake_type = earthquake;
  }
  RoomCode_GenRandomExplodes_Every4Frames();
}

/**
* @brief Set the screen shake to be medium horizontal, with a 3/512 chance of being strong diagonal for 42 frames
* @brief Used in the first and third Tourian escape room
*/
void RoomCode_ShakeScreenHorizDiagStrong(void) {  // 0x8FE5A4
  uint16 earthquake;

  if (diagonal_shake_timer != 0) {
    if (--diagonal_shake_timer == 0) {
      earthquake = EARTHQUAKE(kEarthquake_Direction_Horiz, kEarthquake_Intensity_2, kEarthquake_Layers_Bg1_Bg2_Enemies);
      room_shake_type = earthquake;
    }
  }
  else if (NextRandom() < 0x180) {
    diagonal_shake_timer = 42;
    earthquake = EARTHQUAKE(kEarthquake_Direction_Diag, kEarthquake_Intensity_3, kEarthquake_Layers_Bg1_Bg2_Enemies);
    room_shake_type = earthquake;
  }
  earthquake_type = room_shake_type;
  RoomCode_GenRandomExplodes_Every4Frames();
}

uint16 CallRoomDefStateSelect(uint32 ea, uint16 k) {
  switch (ea) {
  case fnRoomDefStateSelect_Finish: return RoomDefStateSelect_Finish(k);
  case fnRoomDefStateSelect_MainAreaBossDead: return RoomDefStateSelect_MainAreaBossDead(k);
  case fnRoomDefStateSelect_IsEventSet: return RoomDefStateSelect_IsEventSet(k);
  case fnRoomDefStateSelect_IsBossDead: return RoomDefStateSelect_IsBossDead(k);
  case fnRoomDefStateSelect_CollectedMorphBallAndMissiles: return RoomDefStateSelect_CollectedMorphBallAndMissiles(k);
  case fnRoomDefStateSelect_CollectedPowerBombs: return RoomDefStateSelect_CollectedPowerBombs(k);
  default: return Unreachable();
  }
}

/**
* @brief Handle the room state select
* @param room_ptr_ The pointer to the current room
*/
void HandleRoomDefStateSelect(uint16 room_ptr_) {  // 0x8FE5D2
  uint16 room_state_ptr = room_ptr_ + 11;
  do {
    uint16 event_func = get_RoomDefStateSelect(room_state_ptr).func_ptr;
    room_state_ptr = CallRoomDefStateSelect(event_func | 0x8F0000, room_state_ptr + 2);
  } while (room_state_ptr != 0);
}

/**
* @brief Select the room state
* @param room_state The state the room will be in
* @return uint16 0 indicating the state has been selected
*/
uint16 RoomDefStateSelect_Finish(uint16 room_state) {  // 0x8FE5E6
  roomdefroomstate_ptr = room_state;
  return 0;
}

/**
* @brief Chooses either the next state select or the state based on if the main area boss is dead
* @param state_select_ptr The pointer to the state select
* @return uint16 0 if the main boss is dead, else return the next state select
*/
uint16 RoomDefStateSelect_MainAreaBossDead(uint16 state_select_ptr) {  // 0x8FE5FF
  if (!CheckBossBitForCurArea(kBossBit_AreaBoss))
    return state_select_ptr + 2;
  RoomDefStateSelect RDSS = get_RoomDefStateSelect(state_select_ptr - 2);
  return RoomDefStateSelect_Finish(RDSS.state_ptr);
}

/**
* @brief Chooses either the next state select or the state based on if the event has happened
* @param state_select_ptr The pointer to the state select
* @return uint16 0 if the event has happened, else return the next state select
*/
uint16 RoomDefStateSelect_IsEventSet(uint16 state_select_ptr) {  // 0x8FE612
  RoomDefStateSelect RDSS = get_RoomDefStateSelect(state_select_ptr - 2);
  if (CheckEventHappened(RDSS.event_))
    return RoomDefStateSelect_Finish(RDSS.state_ptr);
  else
    return state_select_ptr + 3;
}

/**
* @brief Chooses either the next state select or the state based on if the area boss is dead
* @param state_select_ptr The pointer to the state select
* @return uint16 0 if the boss is dead, else return the next state select
*/
uint16 RoomDefStateSelect_IsBossDead(uint16 state_select_ptr) {  // 0x8FE629
  RoomDefStateSelect RDSS = get_RoomDefStateSelect(state_select_ptr - 2);
  if (CheckBossBitForCurArea(RDSS.area_boss))
    return RoomDefStateSelect_Finish(RDSS.state_ptr);
  else
    return state_select_ptr + 3;
}

/**
* @brief Chooses either the next state select or the state based on if morph and missiles are collected
* @param state_select_ptr The pointer to the state select
* @return uint16 0 if both items are collected, else return the next state select
*/
uint16 RoomDefStateSelect_CollectedMorphBallAndMissiles(uint16 state_select_ptr) {  // 0x8FE652
  if (!(collected_items & kItem_MorphBall) || samus_max_missiles == 0)
    return state_select_ptr + 2;
  RoomDefStateSelect RDSS = get_RoomDefStateSelect(state_select_ptr - 2);
  return RoomDefStateSelect_Finish(RDSS.state_ptr);
}

/**
* @brief Chooses either the next state select or the state based on if power bombs are collected
* @param state_select_ptr The pointer to the state select
* @return uint16 0 if power bombs are collected, else return the next state select
*/
uint16 RoomDefStateSelect_CollectedPowerBombs(uint16 state_select_ptr) {  // 0x8FE669
  if (samus_max_power_bombs == 0)
    return state_select_ptr + 2;
  RoomDefStateSelect RDSS = get_RoomDefStateSelect(state_select_ptr - 2);
  return RoomDefStateSelect_Finish(RDSS.state_ptr);
}

void CallRoomSetupCode(uint32 ea) {
  switch (ea) {
  case fnRoomSetup_AfterSavingAnimals: RoomSetup_AfterSavingAnimals(); return;
  case fnRoomSetup_AutoDestroyWallAfterEscape: RoomSetup_AutoDestroyWallAfterEscape(); return;
  case fnRoomSetup_TurnWallIntoShotblocks: RoomSetup_TurnWallIntoShotblocks(); return;
  case fnRoomSetup_ShakeDuringEscape: RoomSetup_ShakeDuringEscape(); return;
  case fnRoomSetup_ScrollingSkyLand: RoomSetup_ScrollingSkyLand(); return;
  case fnRoomSetup_ScrollingSkyOcean: RoomSetup_ScrollingSkyOcean(); return;
  case fnRoomSetup_RunStatueUnlockAnims: RoomSetup_RunStatueUnlockAnims(); return;
  case fnRoomCode_SpawnPrePhantoonRoomEnemyProj: RoomCode_SpawnPrePhantoonRoomEnemyProj(); return;
  case fnRoomCode_SetupShaktoolRoomPlm: RoomCode_SetupShaktoolRoomPlm(); return;
  case fnRoomCode_SetPauseCodeForDraygon: RoomCode_SetPauseCodeForDraygon(); return;
  case fnRoomCode_SetCollectedMap: RoomCode_SetCollectedMap(); return;
  case fnnullsub_132:
  case fnnullsub_133:
  case fnnullsub_134:
  case fnnullsub_135:
  case fnnullsub_136:
  case fnnullsub_137:
  case fnnullsub_138:
  case fnnullsub_139:
  case fnnullsub_140:
  case fnnullsub_141:
  case fnnullsub_142:
  case fnnullsub_143:
  case fnnullsub_144:
  case fnnullsub_145:
  case fnnullsub_146:
  case fnnullsub_147: return;
  case fnRoomCode_SetZebesTimebombEvent: RoomCode_SetZebesTimebombEvent(); return;
  case fnRoomCode_SetLightHorizRoomShake: RoomCode_SetLightHorizRoomShake(); return;
  case fnRoomCode_SetMediumHorizRoomShake: RoomCode_SetMediumHorizRoomShake(); return;
  case fnRoomCode_Escape4_SetMediumHorizRoomShake: RoomCode_Escape4_SetMediumHorizRoomShake(); return;
  case fnRoomCode_SetCeresDoorSolid: RoomCode_SetCeresDoorSolid(); return;
  case fnRoomCode_SpawnHaze: RoomCode_SpawnHaze(); return;
  case fnRoomCode_SpawnHaze_BgBase: RoomCode_SpawnHaze_BgBase(); return;
  default: Unreachable();
  }
}

/**
* @brief Runs the setup function for the current room
*/
void RunRoomSetupCode(void) {  // 0x8FE88F
  RoomDefRoomstate RoomDefRoomstate = get_RoomDefRoomstate(roomdefroomstate_ptr);
  if (RoomDefRoomstate.room_setup_code != 0)
    CallRoomSetupCode(RoomDefRoomstate.room_setup_code | 0x8F0000);
}

void CallDoorDefSetupCode(uint32 ea) {
  switch (ea) {
  case fnDoorCode_StartWreckedShipTreadmill_West: DoorCode_StartWreckedShipTreadmill_West(); return;
  case fnDoorCode_Scroll6_Green: DoorCode_Scroll6_Green(); return;
  case fnDoorCode_Scroll0_Blue: DoorCode_Scroll0_Blue(); return;
  case fnDoorCode_Scroll13_Blue: DoorCode_Scroll13_Blue(); return;
  case fnDoorCode_Scroll_4Blue_8Green: DoorCode_Scroll_4Blue_8Green(); return;
  case fnDoorCode_Scroll_8toB_Red: DoorCode_Scroll_8toB_Red(); return;
  case fnDoorCode_Scroll_LotsRed: DoorCode_Scroll_LotsRed(); return;
  case fnDoorCode_Scroll_1_4_Green: DoorCode_Scroll_1_4_Green(); return;
  case fnDoorCode_Scroll_2_Blue: DoorCode_Scroll_2_Blue(); return;
  case fnDoorCode_Scroll_17_Blue: DoorCode_Scroll_17_Blue(); return;
  case fnDoorCode_Scroll_4_Blue: DoorCode_Scroll_4_Blue(); return;
  case fnDoorCode_Scroll_6_Green: DoorCode_Scroll_6_Green(); return;
  case fnDoorCode_Scroll_3_Green: DoorCode_Scroll_3_Green(); return;
  case fnDoorCode_SetScroll_0: DoorCode_SetScroll_0(); return;
  case fnDoorCode_SetScroll_1: DoorCode_SetScroll_1(); return;
  case fnDoorCode_SetScroll_2: DoorCode_SetScroll_2(); return;
  case fnDoorCode_SetScroll_3: DoorCode_SetScroll_3(); return;
  case fnDoorCode_SetScroll_4: DoorCode_SetScroll_4(); return;
  case fnDoorCode_SetScroll_5: DoorCode_SetScroll_5(); return;
  case fnDoorCode_SetScroll_6: DoorCode_SetScroll_6(); return;
  case fnDoorCode_SetScroll_7: DoorCode_SetScroll_7(); return;
  case fnDoorCode_SetScroll_8: DoorCode_SetScroll_8(); return;
  case fnDoorCode_SetScroll_9: DoorCode_SetScroll_9(); return;
  case fnDoorCode_SetScroll_10: DoorCode_SetScroll_10(); return;
  case fnDoorCode_SetScroll_11: DoorCode_SetScroll_11(); return;
  case fnDoorCode_SetScroll_12: DoorCode_SetScroll_12(); return;
  case fnDoorCode_SetScroll_13: DoorCode_SetScroll_13(); return;
  case fnDoorCode_SetScroll_14: DoorCode_SetScroll_14(); return;
  case fnDoorCode_SetScroll_15: DoorCode_SetScroll_15(); return;
  case fnDoorCode_SetScroll_16: DoorCode_SetScroll_16(); return;
  case fnDoorCode_SetScroll_17: DoorCode_SetScroll_17(); return;
  case fnDoorCode_SetScroll_18: DoorCode_SetScroll_18(); return;
  case fnDoorCode_SetScroll_19: DoorCode_SetScroll_19(); return;
  case fnDoorCode_SetScroll_20: DoorCode_SetScroll_20(); return;
  case fnDoorCode_SetScroll_21: DoorCode_SetScroll_21(); return;
  case fnDoorCode_SetScroll_22: DoorCode_SetScroll_22(); return;
  case fnDoorCode_SetScroll_23: DoorCode_SetScroll_23(); return;
  case fnDoorCode_SetScroll_24: DoorCode_SetScroll_24(); return;
  case fnDoorCode_SetScroll_25: DoorCode_SetScroll_25(); return;
  case fnDoorCode_SetScroll_26: DoorCode_SetScroll_26(); return;
  case fnDoorCode_SetScroll_28: DoorCode_SetScroll_28(); return;
  case fnDoorCode_SetScroll_29: DoorCode_SetScroll_29(); return;
  case fnDoorCode_SetScroll_30: DoorCode_SetScroll_30(); return;
  case fnDoorCode_SetScroll_31: DoorCode_SetScroll_31(); return;
  case fnDoorCode_SetScroll_32: DoorCode_SetScroll_32(); return;
  case fnDoorCode_SetScroll_33: DoorCode_SetScroll_33(); return;
  case fnDoorCode_SetScroll_34: DoorCode_SetScroll_34(); return;
  case fnDoorCode_SetScroll_35: DoorCode_SetScroll_35(); return;
  case fnDoorCode_SetScroll_36: DoorCode_SetScroll_36(); return;
  case fnDoorCode_SetScroll_37: DoorCode_SetScroll_37(); return;
  case fnDoorCode_SetScroll_38: DoorCode_SetScroll_38(); return;
  case fnDoorCode_SetScroll_39: DoorCode_SetScroll_39(); return;
  case fnDoorCode_SetScroll_40: DoorCode_SetScroll_40(); return;
  case fnDoorCode_SetScroll_41: DoorCode_SetScroll_41(); return;
  case fnDoorCode_SetScroll_42: DoorCode_SetScroll_42(); return;
  case fnDoorCode_SetScroll_43: DoorCode_SetScroll_43(); return;
  case fnDoorCode_StartWreckedSkipTreadmill_East: DoorCode_StartWreckedSkipTreadmill_East(); return;
  case fnDoorCode_SetScroll_44: DoorCode_SetScroll_44(); return;
  case fnDoorCode_SetScroll_45: DoorCode_SetScroll_45(); return;
  case fnDoorCode_SetScroll_46: DoorCode_SetScroll_46(); return;
  case fnDoorCode_SetScroll_47: DoorCode_SetScroll_47(); return;
  case fnDoorCode_SetScroll_48: DoorCode_SetScroll_48(); return;
  case fnDoorCode_SetScroll_49: DoorCode_SetScroll_49(); return;
  case fnDoorCode_SetupElevatubeFromSouth: DoorCode_SetupElevatubeFromSouth(); return;
  case fnDoorCode_SetupElevatubeFromNorth: DoorCode_SetupElevatubeFromNorth(); return;
  case fnDoorCode_ResetElevatubeNorthExit: DoorCode_ResetElevatubeNorthExit(); return;
  case fnDoorCode_ResetElevatubeSouthExit: DoorCode_ResetElevatubeSouthExit(); return;
  case fnDoorCode_SetScroll_50: DoorCode_SetScroll_50(); return;
  case fnDoorCode_SetScroll_53: DoorCode_SetScroll_53(); return;
  case fnDoorCode_SetScroll_54: DoorCode_SetScroll_54(); return;
  case fnDoorCode_SetScroll_55: DoorCode_SetScroll_55(); return;
  case fnDoorCode_SetScroll_56: DoorCode_SetScroll_56(); return;
  case fnDoorCode_SetScroll_57: DoorCode_SetScroll_57(); return;
  case fnDoorCode_SetScroll_58: DoorCode_SetScroll_58(); return;
  case fnDoorCode_SetScroll_59: DoorCode_SetScroll_59(); return;
  case fnDoorCode_SetScroll_61: DoorCode_SetScroll_61(); return;
  case fnDoorCode_SetScroll_62: DoorCode_SetScroll_62(); return;
  case fnDoorCode_SetScroll_63: DoorCode_SetScroll_63(); return;
  case fnDoorCode_SetScroll_64: DoorCode_SetScroll_64(); return;
  case fnDoorCode_SetScroll_65: DoorCode_SetScroll_65(); return;
  case fnDoorCode_ToCeresElevatorShaft: DoorCode_ToCeresElevatorShaft(); return;
  case fnDoorCode_FromCeresElevatorShaft: DoorCode_FromCeresElevatorShaft(); return;
  default: Unreachable();
  }
}

/**
* @brief Run the setup function for the current door
*/
void RunDoorSetupCode(void) {  // 0x8FE8A3
  DoorDef DD = get_DoorDef(door_def_ptr);
  if (DD.door_setup_code != 0)
    CallDoorDefSetupCode(DD.door_setup_code | 0x8F0000);
}

/**
* @brief Handles the shaking for Crocomire's room
*/
void RoomCode_CrocomireRoomShaking(void) {  // 0x8FE8CD
  uint16 crocomire_melt_timer;

  if (!(enemy_data[0].properties & kEnemyProps_Deleted)) {
    if (enemy_data[0].ai_var_A == 64) {
      reg_BG1VOFS = enemy_data[1].ai_var_D + bg1_y_offset + layer1_y_pos;
    }
    else if ((enemy_data[0].ai_var_B & 0x400) != 0) {
      if (sign16(--enemy_data[1].ai_var_D + 7)) {
        crocomire_melt_timer = enemy_data[1].ai_var_D - 2 * (enemy_data[1].ai_var_D + 7);
      }
      else {
        crocomire_melt_timer = enemy_data[1].ai_var_D;
      }
      reg_BG1VOFS += crocomire_melt_timer;
      reg_BG2VOFS = crocomire_melt_timer - 48;
    }
    else if (enemy_data[0].ai_var_C == 34 && enemy_data[0].ai_var_D) {
      --enemy_data[0].ai_var_D;
      if ((enemy_data[0].ai_var_D & 1) != 0)
        layer1_x_pos -= 4;
      else
        layer1_x_pos += 4;
    }
  }
}

/**
* @brief Handles the shaking for Ridley's room
*/
void RoomCode_RidleyRoomShaking(void) {  // 0x8FE950
  static const int16 kRoomCode_RidleyRoomShaking_ScrollSpeed_X[8] = { 0, 2, 2, 2, 0, -2, -2, -2 };
  static const int16 kRoomCode_RidleyRoomShaking_ScrollSpeed_Y[8] = { -2, -2, 0, 2, 2, 2, 0, -2 };

  // Seems to scroll the background in a circle when Ridley's tail explosion happens
  // However this variable is never set by Ridley, so this code never runs
  if (enemy_data[4].ai_var_A) {
    --enemy_data[4].ai_var_A;
    int index = enemy_data[4].ai_var_A;
    reg_BG1HOFS += kRoomCode_RidleyRoomShaking_ScrollSpeed_X[index];
    reg_BG2HOFS += kRoomCode_RidleyRoomShaking_ScrollSpeed_X[index];
    reg_BG1VOFS += kRoomCode_RidleyRoomShaking_ScrollSpeed_Y[index];
    reg_BG2VOFS += kRoomCode_RidleyRoomShaking_ScrollSpeed_Y[index];
  }
}

void CallRoomCode(uint32 ea) {
  switch (ea) {
  case fnRoomCode_ScrollingSkyLand_: RoomCode_ScrollingSkyLand_(); return;
  case fnRoomCode_ScrollingSkyOcean_: RoomCode_ScrollingSkyOcean_(); return;
  case fnRoomCode_ScrollingSkyLand_Shakes: RoomCode_ScrollingSkyLand_Shakes(); return;
  case fnRoomCode_ExplodeShakes: RoomCode_ExplodeShakes(); return;
  case fnRoomCode_ScrollRightDachora: RoomCode_ScrollRightDachora(); return;
  case fnRoomCode_Elevatube: RoomCode_Elevatube(); return;
  case fnRoomCode_CeresElevatorShaft_: RoomCode_CeresElevatorShaft_(); return;
  case fnnullsub_148: return;
  case fnRoomCode_SpawnCeresFallingDebris: RoomCode_SpawnCeresFallingDebris(); return;
  case fnRoomCode_HandleCeresRidleyGetaway: RoomCode_HandleCeresRidleyGetaway(); return;
  case fnRoomCode_ShakeScreenHorizDiag: RoomCode_ShakeScreenHorizDiag(); return;
  case fnRoomCode_GenRandomExplodes_Every4Frames: RoomCode_GenRandomExplodes_Every4Frames(); return;
  case fnRoomCode_ShakeScreenHorizDiagStrong: RoomCode_ShakeScreenHorizDiagStrong(); return;
  case fnRoomCode_CrocomireRoomShaking: RoomCode_CrocomireRoomShaking(); return;
  case fnRoomCode_RidleyRoomShaking: RoomCode_RidleyRoomShaking(); return;
  default: Unreachable();
  }
}

/**
* @brief Run the main function for the current room
*/
void RunRoomMainCode(void) {  // 0x8FE8BD
  if (room_main_code_ptr != 0)
    CallRoomCode(room_main_code_ptr | 0x8F0000);
}
