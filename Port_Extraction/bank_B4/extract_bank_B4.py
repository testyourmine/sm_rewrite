import sys
import os
sys.path.append(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
import common_data as rom

kSpriteObject_InstrListPtrs = []

#Format is as follows: 
#rom.get_data(bank, starting address, ending address, "data type", array, "array name", hex bool, array bool, new line, new space)
#"hex bool" is whether you want the data in hexadecimal or in decimal format
#"array bool" is whether it's a single value or an array (will print [] if array, won't otherwise)
#"new line/space" is how many elements you want before you insert a new line/space, -1 is never
def get_B4():
    rom.get_data(0xB4, 0xBDA8, 0xBE24, "uint16", kSpriteObject_InstrListPtrs, "kSpriteObject_InstrListPtrs", True, True, 16, 1)
    #rom.get_data(, 0x, "", , "", , , , )
    return

get_B4()