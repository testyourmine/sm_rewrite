import sys
import os
sys.path.append(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
import common_data as rom

kXrayBlockData = []
kSamusPalette_Normal = []
kSamusPalette_HyperBeam = []
kSamusPalette_NonPseudoScrew = []
kSamusPalette_PseudoScrew = []
kSamus_VisorColors = []
kSamus_SpeedBoostingPalettes = []
kSamus_HyperBeamPalettes = []
kSamusPal_ScrewAttack = []
kSamusPal_SpeedBoost = []
kSamusPal_SpeedBoostShine = []
kSamusPal_Shinespark = []
kSamusPal_CrystalFlash0to9 = []
kSamusPal_CrystalFlash10to15 = []
kSamusPose_Falling = []
kSamusPose_Landing = []
kSamusPose_RanIntoWall = []
kSamusTurnPose_Standing = []
kSamusTurnPose_Crouching = []
kSamusTurnPose_Jumping = []
kSamusTurnPose_Falling = []
kSamusTurnPose_Moonwalk = []

#Format is as follows: 
#rom.get_data(bank, starting address, ending address, "data type", array, "array name", hex bool, array bool, new line, new space)
#"hex bool" is whether you want the data in hexadecimal or in decimal format
#"array bool" is whether it's a single value or an array (will print [] if array, won't otherwise)
#"new line/space" is how many elements you want before you insert a new line/space, -1 is never
def get_91():
    rom.get_data(0x91, 0xD2D6, 0xD2FC, "XrayBlockData", kXrayBlockData, "kXrayBlockData", True, True, 1, -1)
    rom.get_data(0x91, 0xD727, 0xD72D, "uint16", kSamusPalette_Normal, "kSamusPalette_Normal", True, True, -1, 1)
    rom.get_data(0x91, 0xD829, 0xD83F, "uint16", kSamusPalette_HyperBeam, "kSamusPalette_HyperBeam", True, True, -1, 1)
    rom.get_data(0x91, 0xD7D5, 0xD7DB, "uint16", kSamusPalette_NonPseudoScrew, "kSamusPalette_NonPseudoScrew", True, True, -1, 1)
    rom.get_data(0x91, 0xD7FF, 0xD805, "uint16", kSamusPalette_PseudoScrew, "kSamusPalette_PseudoScrew", True, True, -1, 1)
    rom.get_data(0x9B, 0xA3C0, 0xA3CC, "uint16", kSamus_VisorColors, "kSamus_VisorColors", True, True, 3, 1)
    rom.get_data(0x91, 0xD998, 0xD99E, "uint16", kSamus_SpeedBoostingPalettes, "kSamus_SpeedBoostingPalettes", True, True, -1, 1)
    rom.get_data(0x91, 0xD99E, 0xD9B2, "uint16", kSamus_HyperBeamPalettes, "kSamus_HyperBeamPalettes", True, True, -1, 1)
    rom.get_data(0x91, 0xDA4A, 0xDA50, "uint16", kSamusPal_ScrewAttack, "kSamusPal_ScrewAttack", True, True, -1, 1)
    rom.get_data(0x91, 0xDAA9, 0xDAAF, "uint16", kSamusPal_SpeedBoost, "kSamusPal_SpeedBoost", True, True, -1, 1)
    rom.get_data(0x91, 0xDB10, 0xDB16, "uint16", kSamusPal_SpeedBoostShine, "kSamusPal_SpeedBoostShine", True, True, -1, 1)
    rom.get_data(0x91, 0xDB75, 0xDB7B, "uint16", kSamusPal_Shinespark, "kSamusPal_Shinespark", True, True, -1, 1)
    rom.get_data(0x91, 0xDC00, 0xDC28, "SamusCrystalFlashPalTable", kSamusPal_CrystalFlash0to9, "kSamusPal_CrystalFlash0to9", True, True, -1, 1)
    rom.get_data(0x91, 0xDC28, 0xDC34, "uint16", kSamusPal_CrystalFlash10to15, "kSamusPal_CrystalFlash10to15", True, True, -1, 1)
    rom.get_data(0x91, 0xE921, 0xE931, "uint16", kSamusPose_Falling, "kSamusPose_Falling", True, True, 2, -1)
    rom.get_data(0x91, 0xE9F3, 0xEA07, "uint16", kSamusPose_Landing, "kSamusPose_Landing", True, True, 5, -1)
    rom.get_data(0x91, 0xEB74, 0xEB88, "uint16", kSamusPose_RanIntoWall, "kSamusPose_RanIntoWall", True, True, 5, -1)
    rom.get_data(0x91, 0xF9C2, 0xF9CC, "uint8", kSamusTurnPose_Standing, "kSamusTurnPose_Standing", True, True, -1, 1)
    rom.get_data(0x91, 0xF9CC, 0xF9D6, "uint8", kSamusTurnPose_Crouching, "kSamusTurnPose_Crouching", True, True, -1, 1)
    rom.get_data(0x91, 0xF9D6, 0xF9E0, "uint8", kSamusTurnPose_Jumping, "kSamusTurnPose_Jumping", True, True, -1, 1)
    rom.get_data(0x91, 0xF9E0, 0xF9EA, "uint8", kSamusTurnPose_Falling, "kSamusTurnPose_Falling", True, True, -1, 1)
    rom.get_data(0x91, 0xF9EA, 0xF9F4, "uint8", kSamusTurnPose_Moonwalk, "kSamusTurnPose_Moonwalk", True, True, -1, 1)
    return

get_91()