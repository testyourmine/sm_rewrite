import sys
import os
sys.path.append(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
import common_data as rom


kPaletteBlends = []
kFxTypeTilemapPtrs = []
kAreaPalFxListPointers = []
kAreaAnimtilesListPtrs = []
kCereElevatorShaftMode7TransformationMatrix = []

#Format is as follows: 
#rom.get_data(bank, starting address, ending address, "data type", array, "array name", hex bool, array bool, new line, new space)
#"hex bool" is whether you want the data in hexadecimal or in decimal format
#"array bool" is whether it's a single value or an array (will print [] if array, won't otherwise)
#"new line/space" is how many elements you want before you insert a new line/space, -1 is never
def get89():
    rom.get_data(0x89, 0xAA02, 0xAB02, "uint16", kPaletteBlends, "kPaletteBlends", True, True, 16, 1)
    rom.get_data(0x83, 0xABF0, 0xAC1E, "uint16", kFxTypeTilemapPtrs, "kFxTypeTilemapPtrs", True, True, 10, 1)
    rom.get_data(0x83, 0xAC46, 0xAC56, "uint16", kAreaPalFxListPointers, "kAreaPalFxListPointers", True, True, -1, 1)
    rom.get_data(0x83, 0xAC56, 0xAC66, "uint16", kAreaAnimtilesListPtrs, "kAreaAnimtilesListPtrs", True, True, -1, 1)
    rom.get_data(0x89, 0xAD5F, 0xAEFD, "uint16", kCereElevatorShaftMode7TransformationMatrix, "kCereElevatorShaftMode7TransformationMatrix", True, True, 3, -1)
    return


get89()