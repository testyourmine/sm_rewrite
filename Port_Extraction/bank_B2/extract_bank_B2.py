import sys
import os
sys.path.append(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
import common_data as rom

kWallSpacePirates_Palette_3 = []
kSpacePirate_InstrListPtrs = []

#Format is as follows: 
#rom.get_data(bank, starting address, ending address, "data type", array, "array name", hex bool, array bool, new line, new space)
#"hex bool" is whether you want the data in hexadecimal or in decimal format
#"array bool" is whether it's a single value or an array (will print [] if array, won't otherwise)
#"new line/space" is how many elements you want before you insert a new line/space, -1 is never
def get_B2():
    rom.get_data(0xB2, 0x8727, 0x8747, "uint16", kWallSpacePirates_Palette_3, "kWallSpacePirates_Palette_3", True, True, -1, 1)
    rom.get_data(0xB2, 0xF959, 0xF969, "uint16", kSpacePirate_InstrListPtrs, "kSpacePirate_InstrListPtrs", True, True, 4, 1)
    return

get_B2()