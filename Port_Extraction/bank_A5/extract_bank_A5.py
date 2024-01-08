import sys
import os
sys.path.append(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
import common_data as rom

kDraygon_Palette1 = []
kDraygon_Bg1AndBg2Palette5 = []
kDraygon_FlashPalette = []
kDraygonTurret_XYSpawnPositions = []
kDraygon_HealthPaletteTable = []
kDraygon_HealthPaletteThreshold = []
kMiniDraygon_MovementLatency = []
kMiniDraygon_DeathSequenceSubspeeds = []
kMiniDraygon_DeathSequenceSpawnPositions = []
kMiniDraygon_DeathSequenceAngles = []
kMiniDraygonIntroDanceTable = []
kSporeSpawn_HealthPaletteTable = []
kSporeSpawn_DeathSequencePalette1 = []
kSporeSpawn_DeathSequnceBg1AndBg2Palette4 = []
kSporeSpawn_DeathSequenceBg1AndBg2Palette7 = []
kSporeSpawn_Palette7 = []

#Format is as follows: 
#rom.get_data(bank, starting address, ending address, "data type", array, "array name", hex bool, array bool, new line, new space)
#"hex bool" is whether you want the data in hexadecimal or in decimal format
#"array bool" is whether it's a single value or an array (will print [] if array, won't otherwise)
#"new line/space" is how many elements you want before you insert a new line/space, -1 is never
def get_A5():
    rom.get_data(0xA5, 0xA217, 0xA237, "uint16", kDraygon_Palette1, "kDraygon_Palette1", True, True, -1, 1)
    rom.get_data(0xA5, 0xA277, 0xA297, "uint16", kDraygon_Bg1AndBg2Palette5, "kDraygon_Bg1AndBg2Palette5", True, True, -1, 1)
    rom.get_data(0xA5, 0xA297, 0xA2B7, "uint16", kDraygon_FlashPalette, "kDraygon_FlashPalette", True, True, -1, 1)
    rom.get_data(0xA5, 0x87DC, 0x87F4, "uint16", kDraygonTurret_XYSpawnPositions, "kDraygonTurret_XYSpawnPositions", False, True, 2, 1)
    rom.get_data(0xA5, 0x96AF, 0x96EF, "uint16", kDraygon_HealthPaletteTable, "kDraygon_HealthPaletteTable", True, True, 4, 1)
    rom.get_data(0xA5, 0x96EF, 0x9701, "uint16", kDraygon_HealthPaletteThreshold, "kDraygon_HealthPaletteThreshold", False, True, -1, 1)
    rom.get_data(0xA5, 0xA19F, 0xA1AF, "uint16", kMiniDraygon_MovementLatency, "kMiniDraygon_MovementLatency", True, True, 4, 1)
    rom.get_data(0xA5, 0xA1AF, 0xA1C7, "uint16", kMiniDraygon_DeathSequenceSubspeeds, "kMiniDraygon_DeathSequenceSubspeeds", True, True, 2, 1)
    rom.get_data(0xA5, 0xA1C7, 0xA1DF, "uint16", kMiniDraygon_DeathSequenceSpawnPositions, "kMiniDraygon_DeathSequenceSpawnPositions", True, True, 2, 1)
    rom.get_data(0xA5, 0xA1DF, 0xA1F7, "uint16", kMiniDraygon_DeathSequenceAngles, "kMiniDraygon_DeathSequenceAngles", True, True, 2, 1)
    rom.get_data(0xA5, 0xCE07, 0xDDC7, "uint8", kMiniDraygonIntroDanceTable, "kMiniDraygonIntroDanceTable", True, True, 16, 2)
    rom.get_data(0xA5, 0xE379, 0xE3F9, "uint16", kSporeSpawn_HealthPaletteTable, "kSporeSpawn_HealthPaletteTable", True, True, 16, 1)
    rom.get_data(0xA5, 0xE3F9, 0xE4F9, "uint16", kSporeSpawn_DeathSequencePalette1, "kSporeSpawn_DeathSequencePalette1", True, True, 16, 1)
    rom.get_data(0xA5, 0xE4F9, 0xE5D9, "uint16", kSporeSpawn_DeathSequnceBg1AndBg2Palette4, "kSporeSpawn_DeathSequnceBg1AndBg2Palette4", True, True, 16, 1)
    rom.get_data(0xA5, 0xE5D9, 0xE6B9, "uint16", kSporeSpawn_DeathSequenceBg1AndBg2Palette7, "kSporeSpawn_DeathSequenceBg1AndBg2Palette7", True, True, 16, 1)
    rom.get_data(0xA5, 0xE359, 0xE379, "uint16", kSporeSpawn_Palette7, "kSporeSpawn_Palette7", True, True, -1, 1)
    return

get_A5()