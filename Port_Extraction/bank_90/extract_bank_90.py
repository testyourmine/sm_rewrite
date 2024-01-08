import sys
import os
sys.path.append(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
import common_data as rom

kSamusFramesForUnderwaterSfx = []
kPauseMenuMapData = []
kPauseMenuMapTilemaps = []
kBeamTilePtrs = []
kBeamPalettePtrs = []
kLeftProjTrailInstrListPtrs = []
kRightProjTrailInstrListPtrs = []
kFlareAnimDelays = []

#Format is as follows: 
#rom.get_data(bank, starting address, ending address, "data type", array, "array name", hex bool, array bool, new line, new space)
#"hex bool" is whether you want the data in hexadecimal or in decimal format
#"array bool" is whether it's a single value or an array (will print [] if array, won't otherwise)
#"new line/space" is how many elements you want before you insert a new line/space, -1 is never
def get_90():
    rom.get_data(0x90, 0xA514, 0xA521, "uint8", kSamusFramesForUnderwaterSfx, "kSamusFramesForUnderwaterSfx", False, True, -1, 1)
    rom.get_data(0x82, 0x9717, 0x9727, "uint16", kPauseMenuMapData, "kPauseMenuMapData", True, True, -1, 1)
    rom.get_data(0x82, 0x964A, 0x965F, "LongPtr", kPauseMenuMapTilemaps, "kPauseMenuMapTilemaps", True, True, -1, 1)
    rom.get_data(0x90, 0xC3B1, 0xC3C9, "uint16", kBeamTilePtrs, "kBeamTilePtrs", True, True, -1, 1)
    rom.get_data(0x90, 0xC3C9, 0xC3E1, "uint16", kBeamPalettePtrs, "kBeamPalettePtrs", True, True, -1, 1)
    rom.get_data(0x90, 0xB5BB, 0xB609, "uint16", kLeftProjTrailInstrListPtrs, "kLeftProjTrailInstrListPtrs", True, True, 13, 1)
    rom.get_data(0x90, 0xB609, 0xB657, "uint16", kRightProjTrailInstrListPtrs, "kRightProjTrailInstrListPtrs", True, True, 13, 1)
    rom.get_data(0x90, 0xC481, 0xC487, "uint16", kFlareAnimDelays, "kFlareAnimDelays", True, True, -1, 1)
    return

get_90()