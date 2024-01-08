import sys
import os
sys.path.append(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
import common_data as rom

kEnemyInit_BouncingGoofball_Tab0 = []
kEnemyInit_BouncingGoofball_Tab1 = []
kBouncingGoofball_Tab0 = []
kMaridiaBeybladeTurtle_Tab0 = []
kThinHoppingBlobs_HopTable = []
kEnemyInit_SpikeShootingPlant_XRadiusTravel = []
kEnemyInit_SpikeShootingPlant_FuncPtrs = []
kEnemyInit_MaridiaSpikeyShell_XDistanceRanges = []
kEnemyInit_MaridiaSpikeyShell_UndergroundTimers = []
kGunshipTop_HoverValues = []
kGunshipTop_YVelocitiesBrakeData = []
kGunshipTop_DustCloudTilesSourceAddresses = []
kGunshipTop_DustCloudTilesDestinationAddresses = []
kLavaquakeRocks_Tab0 = []
kLavaquakeRocks_Tab1 = []
kLavaquakeRocks_Tab2 = []
kRinka_MotherBrainRoomSpawnTable = []
kRio_Constant0 = []
kRio_Constant1 = []
kNorfairLavajumpingEnemy_Tab0 = []
kNorfairRio_Tab0 = []
kNorfairRio_Constant0 = []
kLowerNorfairRio_Constant0 = []
kLowerNorfairRio_Constant1 = []
kMaridiaLargeSnail_InstrListPtrs = []
kHirisingSlowFalling_Ptrs0 = []
kHirisingSlowFalling_Ptrs1 = []
kLavaSeahorse_InstrListPtrs = []
kEnemyInit_TimedShutter_YPositionIndices = []
kEnemyInit_TimedShutter_FuncPtrs = []

#Format is as follows: 
#rom.get_data(bank, starting address, ending address, "data type", array, "array name", hex bool, array bool, new line, new space)
#"hex bool" is whether you want the data in hexadecimal or in decimal format
#"array bool" is whether it's a single value or an array (will print [] if array, won't otherwise)
#"new line/space" is how many elements you want before you insert a new line/space, -1 is never
def get_A2():
    rom.get_data(0xA2, 0x86DF, 0x86EF, "uint16", kEnemyInit_BouncingGoofball_Tab0, "kEnemyInit_BouncingGoofball_Tab0", False, True, -1, 1)
    rom.get_data(0xA2, 0x86EF, 0x8701, "uint16", kEnemyInit_BouncingGoofball_Tab1, "kEnemyInit_BouncingGoofball_Tab1", True, True, -1, 1)
    rom.get_data(0xA2, 0x8701, 0x8718, "uint8", kBouncingGoofball_Tab0, "kBouncingGoofball_Tab0", False, True, -1, 1)
    rom.get_data(0xA2, 0x8D56, 0x8D5E, "uint16", kMaridiaBeybladeTurtle_Tab0, "kMaridiaBeybladeTurtle_Tab0", True, True, -1, 1)
    rom.get_data(0xA2, 0x9A07, 0x9A3F, "uint16", kThinHoppingBlobs_HopTable, "kThinHoppingBlobs_HopTable", True, True, 4, 1)
    rom.get_data(0xA2, 0x9F36, 0x9F42, "uint16", kEnemyInit_SpikeShootingPlant_XRadiusTravel, "kEnemyInit_SpikeShootingPlant_XRadiusTravel", False, True, -1, 1)
    rom.get_data(0xA2, 0x9F42, 0x9F48, "uint16", kEnemyInit_SpikeShootingPlant_FuncPtrs, "kEnemyInit_SpikeShootingPlant_FuncPtrs", True, True, -1, 1)
    rom.get_data(0xA2, 0xA3DD, 0xA3ED, "uint16", kEnemyInit_MaridiaSpikeyShell_XDistanceRanges, "kEnemyInit_MaridiaSpikeyShell_XDistanceRanges", False, True, -1, 1)
    rom.get_data(0xA2, 0xA3ED, 0xA3F9, "uint16", kEnemyInit_MaridiaSpikeyShell_UndergroundTimers, "kEnemyInit_MaridiaSpikeyShell_UndergroundTimers", False, True, -1, 1)
    rom.get_data(0xA2, 0xA7CF, 0xA7D7, "uint8", kGunshipTop_HoverValues, "kGunshipTop_HoverValues", True, True, 2, 1)
    rom.get_data(0xA2, 0xA622, 0xA644, "uint16", kGunshipTop_YVelocitiesBrakeData, "kGunshipTop_YVelocitiesBrakeData", True, True, 6, 1)
    rom.get_data(0xA2, 0xAC07, 0xAC11, "uint16", kGunshipTop_DustCloudTilesSourceAddresses, "kGunshipTop_DustCloudTilesSourceAddresses", True, True, -1, 1)
    rom.get_data(0xA2, 0xAC11, 0xAC1B, "uint16", kGunshipTop_DustCloudTilesDestinationAddresses, "kGunshipTop_DustCloudTilesDestinationAddresses", True, True, -1, 1)
    rom.get_data(0xA2, 0xB520, 0xB530, "uint16", kLavaquakeRocks_Tab0, "kLavaquakeRocks_Tab0", True, True, -1, 1)
    rom.get_data(0xA2, 0xB530, 0xB550, "uint16", kLavaquakeRocks_Tab1, "kLavaquakeRocks_Tab1", True, True, 8, 1)
    rom.get_data(0xA2, 0xB550, 0xB570, "uint16", kLavaquakeRocks_Tab2, "kLavaquakeRocks_Tab2", True, True, 8, 1)
    rom.get_data(0xA2, 0xB75B, 0xB79D, "uint16", kRinka_MotherBrainRoomSpawnTable, "kRinka_MotherBrainRoomSpawnTable", True, True, 3, 1)
    rom.get_data(0xA2, 0xBBBB, 0xBBBD, "uint16", kRio_Constant0, "kRio_Constant0", True, False, -1, -1)
    rom.get_data(0xA2, 0xBBBF, 0xBBC1, "uint16", kRio_Constant1, "kRio_Constant1", True, False, -1, -1)
    rom.get_data(0xA2, 0xBE86, 0xBE8E, "uint16", kNorfairLavajumpingEnemy_Tab0, "kNorfairLavajumpingEnemy_Tab0", True, True, -1, 1)
    rom.get_data(0xA2, 0xC1C1, 0xC1C5, "uint16", kNorfairRio_Tab0, "kNorfairRio_Tab0", True, True, -1, 1)
    rom.get_data(0xA2, 0xC1C5, 0xC1C7, "uint16", kNorfairRio_Constant0, "kNorfairRio_Constant0", True, False, -1, -1)
    rom.get_data(0xA2, 0xC6CA, 0xC6CC, "uint16", kLowerNorfairRio_Constant0, "kLowerNorfairRio_Constant0", True, False, -1, -1)
    rom.get_data(0xA2, 0xC6CE, 0xC6D0, "uint16", kLowerNorfairRio_Constant1, "kLowerNorfairRio_Constant1", True, False, -1, -1)
    rom.get_data(0xA2, 0xCB77, 0xCB87, "uint16", kMaridiaLargeSnail_InstrListPtrs, "kMaridiaLargeSnail_InstrListPtrs", True, True, -1, 1)
    rom.get_data(0xA2, 0xDF5E, 0xDF6A, "uint16", kHirisingSlowFalling_Ptrs0, "kHirisingSlowFalling_Ptrs0", True, True, -1, 1)
    rom.get_data(0xA2, 0xDF6A, 0xDF76, "uint16", kHirisingSlowFalling_Ptrs1, "kHirisingSlowFalling_Ptrs1", True, True, -1, 1)
    rom.get_data(0xA2, 0xE5EF, 0xE5FB, "uint16", kLavaSeahorse_InstrListPtrs, "kLavaSeahorse_InstrListPtrs", True, True, -1, 1)
    rom.get_data(0xA2, 0xEA56, 0xEAB6, "uint16", kEnemyInit_TimedShutter_YPositionIndices, "kEnemyInit_TimedShutter_YPositionIndices", True, True, 16, 2)
    rom.get_data(0xA2, 0xEA4E, 0xEA56, "uint16", kEnemyInit_TimedShutter_FuncPtrs, "kEnemyInit_TimedShutter_FuncPtrs", True, True, -1, 1)
    return

#define kMaridiaBeybladeTurtle_Tab0 (*(uint16*)RomFixedPtr(0xa28d56))
#define kMaridiaBeybladeTurtle_Tab1 (*(uint16*)RomFixedPtr(0xa28d58))
#define kThinHoppingBlobs_JumpHeightIndices (*(uint16*)RomFixedPtr(0xa29a07))
#define kThinHoppingBlobs_XSpeedIndices (*(uint16*)RomFixedPtr(0xa29a09))
#define kThinHoppingBlobs_YSpeedIndices (*(uint16*)RomFixedPtr(0xa29a0b))
#define kThinHoppingBlobs_AirborneFuncPtrs (*(uint16*)RomFixedPtr(0xa29a0d))

get_A2()