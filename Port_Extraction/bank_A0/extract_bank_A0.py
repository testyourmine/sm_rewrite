import sys
import os
sys.path.append(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
import common_data as rom

kEnemyLayerToQueuePtr = []
kStandardSpriteTiles = []
kSine8bit = []
kEquationForQuarterCircle = []
kEnemyDestroySpikeBtsOffset = []
kEnemyXYSlopeOffsetMultiplicationIndices = []
kAlignYPos_Tab0 = []

#Format is as follows: 
#rom.get_data(bank, starting address, ending address, "data type", array, "array name", hex bool, array bool, new line, new space)
#"hex bool" is whether you want the data in hexadecimal or in decimal format
#"array bool" is whether it's a single value or an array (will print [] if array, won't otherwise)
#"new line/space" is how many elements you want before you insert a new line/space, -1 is never
def get_A0():
    rom.get_data(0xA0, 0xB133, 0xB143, "uint16", kEnemyLayerToQueuePtr, "kEnemyLayerToQueuePtr", True, True, -1, 1)
    rom.get_data(0x9A, 0xD200, 0xF200, "uint16", kStandardSpriteTiles, "kStandardSpriteTiles", True, True, 16, 1)
    rom.get_data(0xA0, 0xB143, 0xB5C3, "uint8", kSine8bit, "kSine8bit", True, True, 16, 1)
    rom.get_data(0xA0, 0xB7EE, 0xB8EE, "uint16", kEquationForQuarterCircle, "kEquationForQuarterCircle", True, True, 16, 1)
    rom.get_data(0xA0, 0xC2DA, 0xC2FA, "uint16", kEnemyDestroySpikeBtsOffset, "kEnemyDestroySpikeBtsOffset", True, True, -1, 1)
    rom.get_data(0xA0, 0xC49F, 0xC51F, "uint16", kEnemyXYSlopeOffsetMultiplicationIndices, "kEnemyXYSlopeOffsetMultiplicationIndices", True, True, 16, 2)
    rom.get_data(0x94, 0x8B2B, 0x8D2B, "uint8", kAlignYPos_Tab0, "kAlignYPos_Tab0", False, True, 16, 1)
    return

get_A0()