import sys
import os
sys.path.append(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
import common_data as rom

kSamus_AnimationDefinitionPtrs = []
kSamus_TileDefs_TopHalf = []
kSamus_TileDefs_BottomHalf = []

#Format is as follows: 
#rom.get_data(bank, starting address, ending address, "data type", array, "array name", hex bool, array bool, new line, new space)
#"hex bool" is whether you want the data in hexadecimal or in decimal format
#"array bool" is whether it's a single value or an array (will print [] if array, won't otherwise)
#"new line/space" is how many elements you want before you insert a new line/space, -1 is never
def get_92():
    rom.get_data(0x92, 0xD94E, 0xDB48, "uint16", kSamus_AnimationDefinitionPtrs, "kSamus_AnimationDefinitionPtrs", True, True, 16, 1)
    rom.get_data(0x92, 0xD91E, 0xD938, "uint16", kSamus_TileDefs_TopHalf, "kSamus_TileDefs_TopHalf", True, True, -1, 1)
    rom.get_data(0x92, 0xD938, 0xD94E, "uint16", kSamus_TileDefs_BottomHalf, "kSamus_TileDefs_BottomHalf", True, True, -1, 1)
    return

get_92()