import sys
import os
sys.path.append(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
import common_data as rom


kScreenShakeOffsets = []
kAlignYPos_Tab0 = []
kAlignXPos_Tab1 = []
kGarbageInstrList = []
kCrocomireSpikeWallPieces_Ypos = []
kBombTorizoLowHealthDroolInstrlist = []
kBB50InstrListPtrs_UNUSED = []
kCommonEnemySpeeds_Quadratic_Copy = []
kCommonEnemySpeeds_Quadratic32 = []
kMotherBrainsDeathExplosionInstrListPtrs = []
kCrocomireProjectile_Ypos = []
kGunshipLiftoffDustCloudsInstrListPtrs = []
kEprojInit_BombTorizoStatueBreaking_InstrList = []
kGoldenTorizoSuperMissileInstrListPtrs = []
kEproj_MotherBrainRoomTurrets_DirectionIndexes = []
kEproj_MotherBrainRoomTurrets_AllowedRotations = []
kEproj_MotherBrainRoomTurrets_InstrLists = []
kEproj_MotherBrainRoomTurrets_InstrLists_FaceDir = []
kEprojInit_MotherBrainGlassShatteringShard_InstrPtrs = []
kEprojInit_N00bTubeShards_InstrPtrs = []
kEprojInit_SpikeShootingPlantSpikes_InstrList = []
kSporeMovementData = []
kEprojInit_NamiFuneFireball_XYvels = []
kEprojInit_DustCloudOrExplosion_InstrLists = []
kEprojInit_EyeDoorSmoke_XYpos = []
kEprojInit_BotwoonsBody_InstrLists = []
kEprojInit_Pickup_InstrLists = []
kEprojInit_EnemyDeathExplosion_InstrLists = []
kEprojInit_Sparks_EprojVars = []


#Format is as follows: 
#rom.get_data(bank, starting address, ending address, "data type", array, "array name", hex bool, array bool, new line, new space)
#"hex bool" is whether you want the data in hexadecimal or in decimal format
#"array bool" is whether it's a single value or an array (will print [] if array, won't otherwise)
#"new line/space" is how many elements you want before you insert a new line/space, -1 is never
def get86():
    rom.get_data(0x86, 0x846B, 0x84FB, "uint16", kScreenShakeOffsets, "kScreenShakeOffsets", False, True, 18, -1)
    rom.get_data(0x94, 0x8B2B, 0x8D2B, "uint8", kAlignYPos_Tab0, "kAlignYPos_Tab0", False, True, 16, -1)
    rom.get_data(0x94, 0x892B, 0x8B2B, "uint8", kAlignXPos_Tab1, "kAlignXPos_Tab1", False, True, 16, -1)
    rom.get_data(0x86, 0x8A75, 0x8A7D, "uint16", kGarbageInstrList, "kGarbageInstrList", True, True, -1, 1)
    rom.get_data(0x86, 0x9105, 0x9115, "uint16", kCrocomireSpikeWallPieces_Ypos, "kCrocomireSpikeWallPieces_Ypos", True, True, -1, 1)
    rom.get_data(0x86, 0xA64D, 0xA65D, "uint16", kBombTorizoLowHealthDroolInstrlist, "kBombTorizoLowHealthDroolInstrlist", True, True, -1, 1)
    rom.get_data(0x86, 0xBB1E, 0xBB24, "uint16", kBB50InstrListPtrs_UNUSED, "kBB50InstrListPtrs_UNUSED", True, True, -1, 1)
    rom.get_data(0xA0, 0xCBC7, 0xCEBF, "uint16", kCommonEnemySpeeds_Quadratic_Copy, "kCommonEnemySpeeds_Quadratic_Copy", True, True, 16, 4)
    rom.get_data(0xA0, 0xCBC7, 0xCEBF, "uint32", kCommonEnemySpeeds_Quadratic32, "kCommonEnemySpeeds_Quadratic32", True, True, 8, 1)
    rom.get_data(0x86, 0xC929, 0xC92F, "uint16", kMotherBrainsDeathExplosionInstrListPtrs, "kMotherBrainsDeathExplosionInstrListPtrs", True, True, -1, 1)
    rom.get_data(0x86, 0x9059, 0x906B, "uint16", kCrocomireProjectile_Ypos, "kCrocomireProjectile_Ypos", True, True, -1, 3)
    rom.get_data(0x86, 0xA2E2, 0xA2EE, "uint16", kGunshipLiftoffDustCloudsInstrListPtrs, "kGunshipLiftoffDustCloudsInstrListPtrs", True, True, -1, 1)
    rom.get_data(0x86, 0xA7AB, 0xA7CB, "uint16", kEprojInit_BombTorizoStatueBreaking_InstrList, "kEprojInit_BombTorizoStatueBreaking_InstrList", True, True, -1, 1)
    rom.get_data(0x86, 0xB209, 0xB20D, "uint16", kGoldenTorizoSuperMissileInstrListPtrs, "kGoldenTorizoSuperMissileInstrListPtrs", True, True, -1, 1)
    rom.get_data(0x86, 0xBEE1, 0xBEF9, "uint16", kEproj_MotherBrainRoomTurrets_DirectionIndexes, "kEproj_MotherBrainRoomTurrets_DirectionIndexes", False, True, -1, 1)
    rom.get_data(0x86, 0xBEC9, 0xBEE1, "uint16", kEproj_MotherBrainRoomTurrets_AllowedRotations, "kEproj_MotherBrainRoomTurrets_AllowedRotations", True, True, -1, 1)
    rom.get_data(0x86, 0xBEB9, 0xBEC9, "uint16", kEproj_MotherBrainRoomTurrets_InstrLists, "kEproj_MotherBrainRoomTurrets_InstrLists", True, True, -1, 1)
    rom.get_data(0x86, 0xC040, 0xC050, "uint16", kEproj_MotherBrainRoomTurrets_InstrLists_FaceDir, "kEproj_MotherBrainRoomTurrets_InstrLists_FaceDir", True, True, -1, 1)
    rom.get_data(0x86, 0xCE41, 0xCE61, "uint16", kEprojInit_MotherBrainGlassShatteringShard_InstrPtrs, "kEprojInit_MotherBrainGlassShatteringShard_InstrPtrs", True, True, -1, 1)
    rom.get_data(0x86, 0xD760, 0xD774, "uint16", kEprojInit_N00bTubeShards_InstrPtrs, "kEprojInit_N00bTubeShards_InstrPtrs", True, True, -1, 1)
    rom.get_data(0x86, 0xD96A, 0xD97E, "uint16", kEprojInit_SpikeShootingPlantSpikes_InstrList, "kEprojInit_SpikeShootingPlantSpikes_InstrList", True, True, -1, 1)
    rom.get_data(0x86, 0xDD6C, 0xDE6C, "uint8", kSporeMovementData, "kSporeMovementData", True, True, 16, 2)
    rom.get_data(0x86, 0xDEB6, 0xDED6, "uint16", kEprojInit_NamiFuneFireball_XYvels, "kEprojInit_NamiFuneFireball_XYvels", True, True, -1, 2)
    rom.get_data(0x86, 0xE42C, 0xE468, "uint16", kEprojInit_DustCloudOrExplosion_InstrLists, "kEprojInit_DustCloudOrExplosion_InstrLists", True, True, 15, 1)
    rom.get_data(0x86, 0xE47E, 0xE4A6, "uint16", kEprojInit_EyeDoorSmoke_XYpos, "kEprojInit_EyeDoorSmoke_XYpos", True, True, 4, 1)
    rom.get_data(0x86, 0xE9F1, 0xEA31, "uint16", kEprojInit_BotwoonsBody_InstrLists, "kEprojInit_BotwoonsBody_InstrLists", True, True, 8, 1)
    rom.get_data(0x86, 0xEF04, 0xEF10, "uint16", kEprojInit_Pickup_InstrLists, "kEprojInit_Pickup_InstrLists", True, True, -1, 1)
    rom.get_data(0x86, 0xEFD5, 0xEFDF, "uint16", kEprojInit_EnemyDeathExplosion_InstrLists, "kEprojInit_EnemyDeathExplosion_InstrLists", True, True, -1, 1)
    rom.get_data(0x86, 0xF3D4, 0xF3F0, "uint16", kEprojInit_Sparks_EprojVars, "kEprojInit_Sparks_EprojVars", True, True, -1, 2)
    return

get86()