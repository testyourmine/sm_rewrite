import sys
import os
sys.path.append(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
import common_data as rom

kSpecialAirPtrs = []
kSpecialBlockPtrs = []
kPlmHeaderDefPtrs = []
kBombablePlmTable = []
kBlockShotBombedReactionShootablePlm = []

#Format is as follows: 
#rom.get_data(bank, starting address, ending address, "data type", array, "array name", hex bool, array bool, new line, new space)
#"hex bool" is whether you want the data in hexadecimal or in decimal format
#"array bool" is whether it's a single value or an array (will print [] if array, won't otherwise)
#"new line/space" is how many elements you want before you insert a new line/space, -1 is never
def get_94():
    rom.get_data(0x94, 0x92D9, 0x92E9, "uint16", kSpecialAirPtrs, "kSpecialAirPtrs", True, True, -1, 1)
    rom.get_data(0x94, 0x92E9, 0x92F9, "uint16", kSpecialBlockPtrs, "kSpecialBlockPtrs", True, True, -1, 1)
    rom.get_data(0x94, 0x9139, 0x91D9, "uint16", kPlmHeaderDefPtrs, "kPlmHeaderDefPtrs", True, True, 16, 1)
    rom.get_data(0x94, 0x936B, 0x938B, "uint16", kBombablePlmTable, "kBombablePlmTable", True, True, -1, 1)
    rom.get_data(0x94, 0x9EA6, 0x9F46, "uint16", kBlockShotBombedReactionShootablePlm, "kBlockShotBombedReactionShootablePlm", True, True, 16, 1)
    return

get_94()