import sys
import os
sys.path.append(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
import common_data as rom


kPalettes_Intro = []
kPalettes_SpaceGunshipCeres = []
kPalettes_PostCredits = []
kPalettes_Credits = []
kPalettes_ZebesExplosion = []
kPalettes_ZebesExplosionClouds = []
kInitialIntro_JapaneseTextTilemap = []
kPage1Intro_JapaneseTextRegion = []
kLevelData_MotherBrainRoomFromCutscene = []
kLevelData_RoomWithBabyMetroidHatching = []
kCredits_DeerForceTilemap = []
kCredits_1994NintendoCredits = []
kPalettes_EndingSuperMetroidIconGlare = []
kCredits_ItemPercentageRamAddresses = []
kCredits_ItemPercentageDivisors = []
kCredits_ItemPercentageItemBits = []
kCredits_ItemPercentageBeamBits = []
kCredits_ItemPercentageDigitsTilemap = []
kShootingStarTable = []
kCinematicFunction_Intro_Func142_Tab0 = []
kCinematicFunction_Intro_Func144_Tab0 = []
kCredits_ItemPercentageJapaneseTextTilemap = []
kShootingStarTileNumberAttributes = []
kCinematicFunction_Intro_Func216_SourceAddresses = []
kCinematicFunction_Intro_Func216_VramAddresses = []
kPalettes_TitleScreen = []
kTitleSequenceHdmaTablePtrs = []

#Format is as follows: 
#rom.get_data(bank, starting address, ending address, "data type", array, "array name", hex bool, array bool, new line, new space)
#"hex bool" is whether you want the data in hexadecimal or in decimal format
#"array bool" is whether it's a single value or an array (will print [] if array, won't otherwise)
#"new line/space" is how many elements you want before you insert a new line/space, -1 is never
def get8B():
    rom.get_data(0x8C, 0xE3E9, 0xE5E9, "uint16", kPalettes_Intro, "kPalettes_Intro", True, True, 16, -1)
    rom.get_data(0x8C, 0xE5E9, 0xE7E9, "uint16", kPalettes_SpaceGunshipCeres, "kPalettes_SpaceGunshipCeres", True, True, 16, -1)
    rom.get_data(0x8C, 0xE7E9, 0xE9E9, "uint16", kPalettes_PostCredits, "kPalettes_PostCredits", True, True, 16, -1)
    rom.get_data(0x8C, 0xE9E9, 0xEBE9, "uint16", kPalettes_Credits, "kPalettes_Credits", True, True, 16, -1)
    rom.get_data(0x8C, 0xEBE9, 0xEDE9, "uint16", kPalettes_ZebesExplosion, "kPalettes_ZebesExplosion", True, True, 16, -1)
    rom.get_data(0x8C, 0xEDE9, 0xEFE9, "uint16", kPalettes_ZebesExplosionClouds, "kPalettes_ZebesExplosionClouds", True, True, 16, -1)
    rom.get_data(0x8C, 0xD81B, 0xD91B, "uint16", kInitialIntro_JapaneseTextTilemap, "kInitialIntro_JapaneseTextTilemap", True, True, 32, -1)
    rom.get_data(0x8B, 0xA72B, 0xA82B, "uint16", kPage1Intro_JapaneseTextRegion, "kPage1Intro_JapaneseTextRegion", True, True, 32, -1)
    rom.get_data(0x8C, 0xBEC3, 0xC083, "uint16", kLevelData_MotherBrainRoomFromCutscene, "kLevelData_MotherBrainRoomFromCutscene", True, True, 16, -1)
    rom.get_data(0x8C, 0xC083, 0xC383, "uint16", kLevelData_RoomWithBabyMetroidHatching, "kLevelData_RoomWithBabyMetroidHatching", True, True, 32, -1)
    rom.get_data(0x8C, 0xDC9B, 0xDEDB, "uint16", kCredits_DeerForceTilemap, "kCredits_DeerForceTilemap", True, True, 32, -1)
    rom.get_data(0x8C, 0xDEDB, 0xDF5B, "uint16", kCredits_1994NintendoCredits, "kCredits_1994NintendoCredits", True, True, 32, -1)
    rom.get_data(0x8C, 0xEFE9, 0xF1E9, "uint16", kPalettes_EndingSuperMetroidIconGlare, "kPalettes_EndingSuperMetroidIconGlare", True, True, 16, -1)
    rom.get_data(0x8B, 0xE70D, 0xE717, "uint16", kCredits_ItemPercentageRamAddresses, "kCredits_ItemPercentageRamAddresses", True, True, -1, 1)
    rom.get_data(0x8B, 0xE717, 0xE721, "uint16", kCredits_ItemPercentageDivisors, "kCredits_ItemPercentageDivisors", False, True, -1, 1)
    rom.get_data(0x8B, 0xE721, 0xE737, "uint16", kCredits_ItemPercentageItemBits, "kCredits_ItemPercentageItemBits", True, True, -1, 1)
    rom.get_data(0x8B, 0xE737, 0xE741, "uint16", kCredits_ItemPercentageBeamBits, "kCredits_ItemPercentageBeamBits", True, True, -1, 1)
    rom.get_data(0x8B, 0xE741, 0xE769, "uint16", kCredits_ItemPercentageDigitsTilemap, "kCredits_ItemPercentageDigitsTilemap", True, True, 2, 1)
    rom.get_data(0x8B, 0xE9CF, 0xEB0F, "uint16", kShootingStarTable, "kShootingStarTable", True, True, 4, 1)
    rom.get_data(0x8B, 0xE45A, 0xE48A, "uint16", kCinematicFunction_Intro_Func142_Tab0, "kCinematicFunction_Intro_Func142_Tab0", True, True, 4, 1)
    rom.get_data(0x8B, 0xE5E7, 0xE627, "uint16", kCinematicFunction_Intro_Func144_Tab0, "kCinematicFunction_Intro_Func144_Tab0", True, True, 16, 2)
    rom.get_data(0x8C, 0xDF5B, 0xDFDB, "uint16", kCredits_ItemPercentageJapaneseTextTilemap, "kCredits_ItemPercentageJapaneseTextTilemap", True, True, 32, 1)
    rom.get_data(0x8B, 0xE9A7, 0xE9CF, "uint16", kShootingStarTileNumberAttributes, "kShootingStarTileNumberAttributes", True, True, 10, 1)
    rom.get_data(0x8B, 0xF6B8, 0xF6D8, "uint16", kCinematicFunction_Intro_Func216_SourceAddresses, "kCinematicFunction_Intro_Func216_SourceAddresses", True, True, 8, 1)
    rom.get_data(0x8B, 0xF6D8, 0xF6F8, "uint16", kCinematicFunction_Intro_Func216_VramAddresses, "kCinematicFunction_Intro_Func216_VramAddresses", True, True, 8, 1)
    rom.get_data(0x8C, 0xE1E9, 0xE3E9, "uint16", kPalettes_TitleScreen, "kPalettes_TitleScreen", True, True, 16, -1)
    rom.get_data(0x8C, 0xBC5D, 0xBC7D, "uint16", kTitleSequenceHdmaTablePtrs, "kTitleSequenceHdmaTablePtrs", True, True, -1, 1)
    return

get8B()