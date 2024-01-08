import sys
import os
sys.path.append(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
import common_data as rom

kCrocomire_Bg1AndBg2Palette7 = []
kEnemyInit_Crocomire_Palette2 = []
kEnemyInit_Crocomire_Palette5 = []
kCrocomire_Palette1 = []
kCrocomire_Palette3 = []
kCrocomire_SpritemapPtrs = []
kCrocomire_BridgeCrumbleTab0 = []
kCrocomire_Bg2TilemapIndices0 = []
kCrocomire_Bg2TilemapIndices1 = []
kCrocoVlineRandomPos = []
kCrocomire_Tab0 = []
kCrocomire_TilesDestinationAddresses = []
kCrocomire_TilesSourceAddresses = []

#Format is as follows: 
#rom.get_data(bank, starting address, ending address, "data type", array, "array name", hex bool, array bool, new line, new space)
#"hex bool" is whether you want the data in hexadecimal or in decimal format
#"array bool" is whether it's a single value or an array (will print [] if array, won't otherwise)
#"new line/space" is how many elements you want before you insert a new line/space, -1 is never
def get_A4():
    rom.get_data(0xA4, 0xB89D, 0xB8BD, "uint16", kCrocomire_Bg1AndBg2Palette7, "kCrocomire_Bg1AndBg2Palette7", True, True, -1, 1)
    rom.get_data(0xA4, 0xB8BD, 0xB8DD, "uint16", kEnemyInit_Crocomire_Palette2, "kEnemyInit_Crocomire_Palette2", True, True, -1, 1)
    rom.get_data(0xA4, 0xB8DD, 0xB8FD, "uint16", kEnemyInit_Crocomire_Palette5, "kEnemyInit_Crocomire_Palette5", True, True, -1, 1)
    rom.get_data(0xA4, 0xB8FD, 0xB91D, "uint16", kCrocomire_Palette1, "kCrocomire_Palette1", True, True, -1, 1)
    rom.get_data(0xA4, 0xB91D, 0xB93D, "uint16", kCrocomire_Palette3, "kCrocomire_Palette3", True, True, -1, 1)
    rom.get_data(0xA4, 0x8B79, 0x8B9B, "uint16", kCrocomire_SpritemapPtrs, "kCrocomire_SpritemapPtrs", True, True, 8, 1)
    rom.get_data(0xA4, 0x9156, 0x916C, "uint16", kCrocomire_BridgeCrumbleTab0, "kCrocomire_BridgeCrumbleTab0", True, True, -1, 1)
    rom.get_data(0xA4, 0x9C79, 0x9E7B, "uint16", kCrocomire_Bg2TilemapIndices0, "kCrocomire_Bg2TilemapIndices0", True, True, 16, 1)
    rom.get_data(0xA4, 0x9E7B, 0xA07D, "uint16", kCrocomire_Bg2TilemapIndices1, "kCrocomire_Bg2TilemapIndices1", True, True, 16, 1)




    rom.get_data(0xA4, 0x9697, 0x96C8, "uint8", kCrocoVlineRandomPos, "kCrocoVlineRandomPos", False, True, 16, 1)
    rom.get_data(0xA4, 0x98CA, 0x990A, "uint16", kCrocomire_Tab0, "kCrocomire_Tab0", True, True, 4, 1)
    rom.get_data(0xA4, 0x99CB, 0x99D9, "uint16", kCrocomire_TilesDestinationAddresses, "kCrocomire_TilesDestinationAddresses", True, True, -1, 1)
    rom.get_data(0xA4, 0x99D9, 0x99E5, "uint16", kCrocomire_TilesSourceAddresses, "kCrocomire_TilesSourceAddresses", True, True, -1, 1)
    #rom.get_data(, 0x, "", , "", , , , )
    return

#define kCrocomire_MeltingTilesTab0 (*(uint16*)RomFixedPtr(0xa49bc5))
#define kCrocomire_MeltingTilesTab1 (*(uint16*)RomFixedPtr(0xa49bc7))
#define kCrocomire_MeltingTilesTab2 (*(uint16*)RomFixedPtr(0xa49bc9))
#define kCrocomire_MeltingTilesTab3 (*(uint16*)RomFixedPtr(0xa49bcb))

get_A4()