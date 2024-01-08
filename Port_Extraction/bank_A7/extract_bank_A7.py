import sys
import os
sys.path.append(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
import common_data as rom

kKraid_BgTargetPalette6 = []
kKraid_BgTargetPalette3 = []
kEproj_RocksFallingKraidCeilingXPositions = []
kKraid_InvulnerableRoarInstrLists = []
kKraid_VulnerableRoarInstrLists = []
kKraid_BodyHitboxTable = []
kKraid_BgPalette7 = []
kKraid_BgPalette7_KraidDeath = []
kKraid_SprPalette7 = []
kKraid_EyeGlowingInstrLists = []
kKraid_DyingInstrLists = []
kKraid_LintBoundary = []
kKraid_XMovementTable = []
kEproj_RocksKraidSpits_RandomParameters = []
kKraid_GoodFingernailInstrLists = []
kKraidsFingernail_UpwardsVelocityTable = []
kKraidsFingernail_DownwardsVelocityTable = []
kKraidsFingernail_BoundaryOffsets = []
kKraidSinkEntry = []
kPhantoon_InstrListPtrs = []
kPhantoon_MaterialisationSoundEffects = []
kPhantoon_BrokenCode = []
kEproj_DestroyableFireballs_Positions = []
kPhantoon_CasualFlameTimerPtrs = []
kPhantoon_Figure8VulnerabilityTimers = []
kPhantoon_EyeClosedTimers = []
kPhantoon_FireballRainHidingTimers = []
kPhantoon_EyeballDirectionInstrListPtrs = []
kPhantoon_FlameRainSpawnPositions = []
kPhantoon_DyingExplosionsTable = []
kPhantoon_HealthPalettePtrs = []
kDachora_PalettePtrs_1 = []
kDachora_PalettePtrs_2 = []
kPhantoon_FadeOutTargetPalettes = []
kWreckedShipOn_Bg1AndBg2TargetPalettes = []
kSpritePaletteRamPtrs = []

#Format is as follows: 
#rom.get_data(bank, starting address, ending address, "data type", array, "array name", hex bool, array bool, new line, new space)
#"hex bool" is whether you want the data in hexadecimal or in decimal format
#"array bool" is whether it's a single value or an array (will print [] if array, won't otherwise)
#"new line/space" is how many elements you want before you insert a new line/space, -1 is never
def get_A7():
    rom.get_data(0xA7, 0x86C7, 0x86E7, "uint16", kKraid_BgTargetPalette6, "kKraid_BgTargetPalette6", True, True, -1, 1)
    rom.get_data(0xA7, 0xAAA6, 0xAAC6, "uint16", kKraid_BgTargetPalette3, "kKraid_BgTargetPalette3", True, True, -1, 1)
    rom.get_data(0xA7, 0xACB3, 0xACC5, "uint16", kEproj_RocksFallingKraidCeilingXPositions, "kEproj_RocksFallingKraidCeilingXPositions", False, True, -1, 1)
    rom.get_data(0xA7, 0x96D2, 0x96DA, "KraidInstrList", kKraid_InvulnerableRoarInstrLists, "kKraid_InvulnerableRoarInstrLists", True, False, -1, 1)
    rom.get_data(0xA7, 0x96DA, 0x96DB, "KraidInstrList", kKraid_VulnerableRoarInstrLists, "kKraid_VulnerableRoarInstrLists", True, False, -1, 1)
    rom.get_data(0xA7, 0xB161, 0xB180, "uint16", kKraid_BodyHitboxTable, "kKraid_BodyHitboxTable", True, True, 2, 1)
    rom.get_data(0xA7, 0xB3D3, 0xB3F3, "uint16", kKraid_BgPalette7, "kKraid_BgPalette7", True, True, -1, 1)
    rom.get_data(0xA7, 0xB4F3, 0xB513, "uint16", kKraid_BgPalette7_KraidDeath, "kKraid_BgPalette7_KraidDeath", True, True, -1, 1)
    rom.get_data(0xA7, 0xB513, 0xB533, "uint16", kKraid_SprPalette7, "kKraid_SprPalette7", True, True, -1, 1)
    rom.get_data(0xA7, 0x974A, 0x9764, "KraidInstrList", kKraid_EyeGlowingInstrLists, "kKraid_EyeGlowingInstrLists", True, True, 1, 1)
    rom.get_data(0xA7, 0x9764, 0x9788, "KraidInstrList", kKraid_DyingInstrLists, "kKraid_DyingInstrLists", True, True, 1, 1)
    rom.get_data(0xA7, 0x92B7, 0x92C3, "Hitbox", kKraid_LintBoundary, "kKraid_LintBoundary", True, False, -1, 1)
    rom.get_data(0xA7, 0xBA7D, 0xBA95, "uint16", kKraid_XMovementTable, "kKraid_XMovementTable", True, True, 2, 1)
    rom.get_data(0xA7, 0xBC65, 0xBC75, "uint16", kEproj_RocksKraidSpits_RandomParameters, "kEproj_RocksKraidSpits_RandomParameters", True, True, -1, 1)
    rom.get_data(0xA7, 0x8B0A, 0x8B0E, "SpriteDrawInstr", kKraid_GoodFingernailInstrLists, "kKraid_GoodFingernailInstrLists", True, False, -1, 1)
    rom.get_data(0xA7, 0xBE3E, 0xBE46, "uint16", kKraidsFingernail_UpwardsVelocityTable, "kKraidsFingernail_UpwardsVelocityTable", True, True, -1, 1)
    rom.get_data(0xA7, 0xBE46, 0xBE4E, "uint16", kKraidsFingernail_DownwardsVelocityTable, "kKraidsFingernail_DownwardsVelocityTable", True, True, -1, 1)
    rom.get_data(0xA7, 0xBF1D, 0xBF2D, "uint16", kKraidsFingernail_BoundaryOffsets, "kKraidsFingernail_BoundaryOffsets", True, True, 2, 1)
    rom.get_data(0xA7, 0xC5E7, 0xC691, "KraidSinkTable", kKraidSinkEntry, "kKraidSinkEntry", True, True, 1, 1)
    rom.get_data(0xA7, 0xCE8E, 0xCE96, "uint16", kPhantoon_InstrListPtrs, "kPhantoon_InstrListPtrs", True, True, -1, 1)
    rom.get_data(0xA7, 0xCDED, 0xCDF3, "uint16", kPhantoon_MaterialisationSoundEffects, "kPhantoon_MaterialisationSoundEffects", True, True, -1, 1)
    rom.get_data(0xA7, 0x902D, 0x9055, "ExtendedSpriteMap", kPhantoon_BrokenCode, "kPhantoon_BrokenCode", True, True, 1, 1)
    rom.get_data(0xA7, 0xCFC2, 0xCFCA, "uint8", kEproj_DestroyableFireballs_Positions, "kEproj_DestroyableFireballs_Positions", False, True, -1, 1)
    rom.get_data(0xA7, 0xCCFD, 0xCD05, "uint16", kPhantoon_CasualFlameTimerPtrs, "kPhantoon_CasualFlameTimerPtrs", True, True, -1, 1)
    rom.get_data(0xA7, 0xCD41, 0xCD51, "uint16", kPhantoon_Figure8VulnerabilityTimers, "kPhantoon_Figure8VulnerabilityTimers", False, True, -1, 1)
    rom.get_data(0xA7, 0xCD53, 0xCD63, "uint16", kPhantoon_EyeClosedTimers, "kPhantoon_EyeClosedTimers", False, True, -1, 1)
    rom.get_data(0xA7, 0xCD63, 0xCD73, "uint16", kPhantoon_FireballRainHidingTimers, "kPhantoon_FireballRainHidingTimers", False, True, -1, 1)
    rom.get_data(0xA7, 0xD40D, 0xD421, "uint16", kPhantoon_EyeballDirectionInstrListPtrs, "kPhantoon_EyeballDirectionInstrListPtrs", True, True, -1, 1)
    rom.get_data(0xA7, 0xCDAD, 0xCDED, "uint16", kPhantoon_FlameRainSpawnPositions, "kPhantoon_FlameRainSpawnPositions", False, True, 4, 1)
    rom.get_data(0xA7, 0xDA1D, 0xDA51, "uint8", kPhantoon_DyingExplosionsTable, "kPhantoon_DyingExplosionsTable", False, True, 4, 1)
    rom.get_data(0xA7, 0xDC4A, 0xDC5A, "uint16", kPhantoon_HealthPalettePtrs, "kPhantoon_HealthPalettePtrs", True, True, -1, 1)
    rom.get_data(0xA7, 0xF787, 0xF78F, "uint16", kDachora_PalettePtrs_1, "kDachora_PalettePtrs_1", True, True, -1, 1)
    rom.get_data(0xA7, 0xF92D, 0xF935, "uint16", kDachora_PalettePtrs_2, "kDachora_PalettePtrs_2", True, True, -1, 1)
    rom.get_data(0xA7, 0xCA41, 0xCA61, "uint16", kPhantoon_FadeOutTargetPalettes, "kPhantoon_FadeOutTargetPalettes", False, True, -1, 1)
    rom.get_data(0xA7, 0xCA61, 0xCB41, "uint16", kWreckedShipOn_Bg1AndBg2TargetPalettes, "kWreckedShipOn_Bg1AndBg2TargetPalettes", True, True, 16, 1)
    rom.get_data(0xA7, 0xF55F, 0xF56F, "uint16", kSpritePaletteRamPtrs, "kSpritePaletteRamPtrs", True, True, -1, 1)
    return

get_A7()