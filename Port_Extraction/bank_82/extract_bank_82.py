import sys

class Rom:
  def __init__(self):
    self.data = open('sm.smc', 'rb').read()

  def map(self, addr):
    assert addr & 0x8000
    return (((addr >> 16) << 15) | (addr & 0x7fff)) & 0x3fffff

  def get_byte(self, addr):
    return self.data[self.map(addr)]

  def get_word(self, addr):
    addr = self.map(addr)
    return self.data[addr] + self.data[addr + 1] * 256

  def get_long(self, addr):
    addr = self.map(addr)
    return self.data[addr] + self.data[addr + 1] * 256 + self.data[addr + 2] * 65536

  def get_bytes(self, addr, n):
    addr = self.map(addr)
    return self.data[addr:addr+n]

ROM = Rom()
get_byte = ROM.get_byte
get_word = ROM.get_word
get_long = ROM.get_long

bank_82 = 0x820000

class PauseScreenSpriteAnimationData:
  def __init__(self, addr):
    self.unused_1 = get_word(addr)
    self.lr_highlight = get_word(addr+2)
    self.item_selector = get_word(addr+4)
    self.unused_2 = get_word(addr+6)
    self.unused_3 = get_word(addr+8)
    self.map_scroll_arrow_up = get_word(addr+10)
    self.map_scroll_arrow_down = get_word(addr+12)
    self.map_scroll_arrow_right = get_word(addr+14)
    self.map_scroll_arrow_left = get_word(addr+16)
  def __str__(self):
    output = "%6s, %6s, %6s, %6s, %6s, %6s, %6s, %6s, %6s, };" % (hex(self.unused_1), hex(self.lr_highlight), hex(self.item_selector), hex(self.unused_2), 
                                                              hex(self.unused_3), hex(self.map_scroll_arrow_up), hex(self.map_scroll_arrow_down), 
                                                              hex(self.map_scroll_arrow_right), hex(self.map_scroll_arrow_left),)
    return output

class MapScrollArrowData:
  def __init__(self, addr):
    self.x_pos = get_word(addr)
    self.y_pos = get_word(addr+2)
    self.anim_id = get_word(addr+4)
    self.input = get_word(addr+6)
    self.map_scroll_dir = get_word(addr+8)
  def __str__(self):
    output = "%s, %s, %s, %s, %s, };" % (self.x_pos, self.y_pos, self.anim_id, self.input, self.map_scroll_dir)
    return output

class FileCopyArrowStuff:
  def __init__(self, addr):
    self.spritemap_index = get_word(addr)
    self.x_pos = get_word(addr+2)
    self.y_pos = get_word(addr+4)
  def __str__(self):
    output = "%s, %s, %s, " % (self.spritemap_index, self.x_pos, self.y_pos)
    return output


#Pointers to demo room data
DemoRoomDataPtr = []
def getDemoRoomDataPtr():
  ptr_address = 0x82876C
  end_address = 0x828774
  while ptr_address != end_address:
    get_ptr = hex(get_word(ptr_address))
    DemoRoomDataPtr.append(get_ptr)
    ptr_address += 2
  printDemoRoomDataPtr()
  return

def printDemoRoomDataPtr():
  print("uint16 kDemoRoomData[] = {", end=" ")
  for ptr in DemoRoomDataPtr:
    print(ptr, end=", ")
  print("};")
  return


#Pause screen sprite animation data
PauseScreenSpriteAnimTimer = []
PauseScreenSpriteAnimFrame = []
PauseScreenSpriteAnimMode = []
PauseScreenSpriteAnimData = []
def getPauseScreenSpriteAnim():
  ptr_address = 0x82C0B2
  new_data = PauseScreenSpriteAnimationData(ptr_address)
  PauseScreenSpriteAnimTimer.append(new_data)
  ptr_address += 18
  new_data = PauseScreenSpriteAnimationData(ptr_address)
  PauseScreenSpriteAnimFrame.append(new_data)
  ptr_address += 18
  new_data = PauseScreenSpriteAnimationData(ptr_address)
  PauseScreenSpriteAnimMode.append(new_data)
  ptr_address += 18
  new_data = PauseScreenSpriteAnimationData(ptr_address)
  PauseScreenSpriteAnimData.append(new_data)
  printPauseScreenSpriteAnim()
  return

def printPauseScreenSpriteAnim():
  for data in PauseScreenSpriteAnimTimer:
    print("PauseScreenSpriteAnimationData kPauseScreenSpriteAnimationData_Timer = {", end=" ")
    print(data)
  for data in PauseScreenSpriteAnimFrame:
    print("PauseScreenSpriteAnimationData kPauseScreenSpriteAnimationData_Frame = {", end=" ")
    print(data)
  for data in PauseScreenSpriteAnimMode:
    print("PauseScreenSpriteAnimationData kPauseScreenSpriteAnimationData_Mode = {", end=" ")
    print(data)
  for data in PauseScreenSpriteAnimData:
    print("PauseScreenSpriteAnimationData kPauseScreenSpriteAnimationData_Data = {", end=" ")
    print(data)
  return


#Sprite palette index values
SpritePaletteIndexValue = []
def getSpritePaletteIndexValue():
  index_address = 0x82C0FA
  end_address = 0x82C10A
  while index_address != end_address:
    get_index = hex(get_word(index_address))
    SpritePaletteIndexValue.append(get_index)
    index_address += 2
  printSpritePaletteIndexValue()
  return

def printSpritePaletteIndexValue():
  print("uint16 kPauseSpritePaletteIndexValues[] = {", end=" ")
  for index in SpritePaletteIndexValue:
    print(index, end=", ")
  print("};")
  return


#Pointers to animation spritemap base IDs (into $82:C569 table)
GeneralMenuAnimationSpritemapBaseIdPtr = []
def getGeneralMenuAnimationSpritemapBaseIdPtr():
  ptr_address = 0x82C1E4
  end_address = 0x82C1F6
  while ptr_address != end_address:
    get_ptr = hex(get_word(ptr_address))
    GeneralMenuAnimationSpritemapBaseIdPtr.append(get_ptr)
    ptr_address += 2
  printGeneralMenuAnimationSpritemapBaseIdPtr()
  return

def printGeneralMenuAnimationSpritemapBaseIdPtr():
  print("uint16 kPausePtsToAnimationSpritemapBaseIds[] = {", end=" ")
  for ptr in GeneralMenuAnimationSpritemapBaseIdPtr:
    print(ptr, end=", ")
  print("};")
  return


#Initial palette
InitialPalette = []
def getInitialPalette():
  palette_address = 0x9A8000
  end_address = 0x9A8200
  while palette_address != end_address:
    get_palette = hex(get_word(palette_address))
    InitialPalette.append(get_palette)
    palette_address += 2
  printInitialPalette()
  return

def printInitialPalette():
  print("uint16 kInitialPalette[] = {", end=" ")
  new_line_counter = 0
  for palette in InitialPalette:
    if new_line_counter == 16:
      print("\n\t\t\t\t\t\t\t ", end="")
      new_line_counter = 0
    print("%6s" % palette, end=", ")
    new_line_counter += 1
  print("};")
  return


#Palettes - pause screen 
PauseScreenPalette = []
def getPauseScreenPalette():
  palette_address = 0xB6F000
  end_address = 0xB6F200
  while palette_address != end_address:
    get_palette = hex(get_word(palette_address))
    PauseScreenPalette.append(get_palette)
    palette_address += 2
  printPauseScreenPalette()
  return

def printPauseScreenPalette():
  print("uint16 kPauseScreenPalettes[] = {", end=" ")
  new_line_counter = 0
  for palette in PauseScreenPalette:
    if new_line_counter == 16:
      print("\n\t\t\t\t\t\t\t\t  ", end="")
      new_line_counter = 0
    print("%6s" % palette, end=", ")
    new_line_counter += 1
  print("};")
  return


#L/R highlight animation data / pause screen palette animation delays
LRHighlightAnimData = []
def getLRHighlightAnimData():
  data_address = 0x82C10C
  end_address = 0x82C137
  while data_address != end_address:
    get_data = get_byte(data_address)
    LRHighlightAnimData.append(get_data)
    data_address += 1
  printLRHighlightAnimData()
  return

def printLRHighlightAnimData():
  print("uint8 kPauseLrHighlightAnimData[] = {", end=" ")
  new_space_counter = 0
  for data in LRHighlightAnimData:
    if new_space_counter == 3:
      print(" ", end="")
      new_space_counter = 0
    print(data, end=",")
    new_space_counter += 1
  print("};")
  return


#Area label tilemaps
AreaLabelTilemapPtr = []
def getAreaLabelTilemapPtr():
  ptr_address = 0x82965F
  end_address = 0x82966F
  while ptr_address != end_address:
    get_ptr = hex(get_word(ptr_address))
    AreaLabelTilemapPtr.append(get_ptr)
    ptr_address += 2
  printAreaLabelTilemapPtr()
  return

def printAreaLabelTilemapPtr():
  print("uint16 kPauseAreaLabelTilemap[] = {", end=" ")
  for ptr in AreaLabelTilemapPtr:
    print(ptr, end=", ")
  print("};")
  return


#Pointers to area maps
AreaMapPtr = []
def getAreaMapPtr():
  ptr_address = 0x82964A
  end_address = 0x82965F
  while ptr_address != end_address:
    #get_ptr = hex(get_long(ptr_address))
    #AreaMapPtr.append(get_ptr)
    #ptr_address += 3
    get_ptr_address = hex(get_word(ptr_address))
    AreaMapPtr.append(get_ptr_address)
    ptr_address += 2
    get_ptr_bank = hex(get_byte(ptr_address))
    AreaMapPtr.append(get_ptr_bank)
    ptr_address += 1
  printAreaMapPtr()
  return

def printAreaMapPtr():
  print("LongPtr kPauseMenuMapTilemaps[] = {", end=" ")
  for ptr in AreaMapPtr:
    print(ptr, end=", ")
  print("};")
  return


#Map data pointers
MapDataPtr = []
def getMapDataPtr():
  ptr_address = 0x829717
  end_address = 0x829727
  while ptr_address != end_address:
    get_ptr = hex(get_word(ptr_address))
    MapDataPtr.append(get_ptr)
    ptr_address += 2
  printMapDataPtr()
  return

def printMapDataPtr():
  print("uint16 kPauseMenuMapData[] = {", end=" ")
  for ptr in MapDataPtr:
    print(ptr, end=", ")
  print("};")
  return


#Pointers to equipment tilemaps
TanksEquipmentTilemap = []
def getTanksEquipmentTilemap():
  ptr_address = 0x82C088
  end_address = 0x82C08C
  while ptr_address != end_address:
    get_ptr = hex(get_word(ptr_address))
    TanksEquipmentTilemap.append(get_ptr)
    ptr_address += 2
  printTanksEquipmentTilemap()
  return

def printTanksEquipmentTilemap():
  print("uint16 kEquipmentTilemaps_Tanks[] = {", end=" ")
  for ptr in TanksEquipmentTilemap:
    print(ptr, end=", ")
  print("};")
  return


WeaponsEquipmentTilemap = []
def getWeaponsEquipmentTilemap():
  ptr_address = 0x82C08C
  end_address = 0x82C096
  while ptr_address != end_address:
    get_ptr = hex(get_word(ptr_address))
    WeaponsEquipmentTilemap.append(get_ptr)
    ptr_address += 2
  printWeaponsEquipmentTilemap()
  return

def printWeaponsEquipmentTilemap():
  print("uint16 kEquipmentTilemaps_Weapons[] = {", end=" ")
  for ptr in WeaponsEquipmentTilemap:
    print(ptr, end=", ")
  print("};")
  return


SuitsEquipmentTilemap = []
def getSuitsEquipmentTilemap():
  ptr_address = 0x82C096
  end_address = 0x82C0A2
  while ptr_address != end_address:
    get_ptr = hex(get_word(ptr_address))
    SuitsEquipmentTilemap.append(get_ptr)
    ptr_address += 2
  printSuitsEquipmentTilemap()
  return

def printSuitsEquipmentTilemap():
  print("uint16 kEquipmentTilemaps_Suits[] = {", end=" ")
  for ptr in SuitsEquipmentTilemap:
    print(ptr, end=", ")
  print("};")
  return


BootsEquipmentTilemap = []
def getBootsEquipmentTilemap():
  ptr_address = 0x82C0A2
  end_address = 0x82C0A8
  while ptr_address != end_address:
    get_ptr = hex(get_word(ptr_address))
    BootsEquipmentTilemap.append(get_ptr)
    ptr_address += 2
  printBootsEquipmentTilemap()
  return

def printBootsEquipmentTilemap():
  print("uint16 kEquipmentTilemaps_Boots[] = {", end=" ")
  for ptr in BootsEquipmentTilemap:
    print(ptr, end=", ")
  print("};")
  return


HyperEquipmentTilemap = []
def getHyperEquipmentTilemap():
  ptr_address = 0x82C0A8
  end_address = 0x82C0B2
  while ptr_address != end_address:
    get_ptr = hex(get_word(ptr_address))
    HyperEquipmentTilemap.append(get_ptr)
    ptr_address += 2
  printHyperEquipmentTilemap()
  return

def printHyperEquipmentTilemap():
  print("uint16 kHyperBeamWeaponsTilemaps[] = {", end=" ")
  for ptr in HyperEquipmentTilemap:
    print(ptr, end=", ")
  print("};")
  return


#Equipment bitmasks
WeaponsEquipmentBitmask = []
def getWeaponsEquipmentBitmask():
  bitmask_address = 0x82C04C
  end_address = 0x82C056
  while bitmask_address != end_address:
    get_bitmask = hex(get_word(bitmask_address))
    WeaponsEquipmentBitmask.append(get_bitmask)
    bitmask_address += 2
  printWeaponsEquipmentBitmask()
  return

def printWeaponsEquipmentBitmask():
  print("uint16 kEquipmentBitmasks_Weapons[] = {", end=" ")
  for bitmask in WeaponsEquipmentBitmask:
    print(bitmask, end=", ")
  print("};")
  return


SuitsEquipmentBitmask = []
def getSuitsEquipmentBitmask():
  bitmask_address = 0x82C056
  end_address = 0x82C062
  while bitmask_address != end_address:
    get_bitmask = hex(get_word(bitmask_address))
    SuitsEquipmentBitmask.append(get_bitmask)
    bitmask_address += 2
  printSuitsEquipmentBitmask()
  return

def printSuitsEquipmentBitmask():
  print("uint16 kEquipmentBitmasks_Suits[] = {", end=" ")
  for bitmask in SuitsEquipmentBitmask:
    print(bitmask, end=", ")
  print("};")
  return


BootsEquipmentBitmask = []
def getBootsEquipmentBitmask():
  bitmask_address = 0x82C062
  end_address = 0x82C068
  while bitmask_address != end_address:
    get_bitmask = hex(get_word(bitmask_address))
    BootsEquipmentBitmask.append(get_bitmask)
    bitmask_address += 2
  printBootsEquipmentBitmask()
  return

def printBootsEquipmentBitmask():
  print("uint16 kEquipmentBitmasks_Boots[] = {", end=" ")
  for bitmask in BootsEquipmentBitmask:
    print(bitmask, end=", ")
  print("};")
  return


#Pause screen animation palette data
PauseScreenAnimPaletteData = []
def getPauseScreenAnimPaletteData():
  palette_address = 0x82A987
  end_address = 0x82AB47
  while palette_address != end_address:
    get_palette = hex(get_word(palette_address))
    PauseScreenAnimPaletteData.append(get_palette)
    palette_address += 2
  printPauseScreenAnimPaletteData()
  return

def printPauseScreenAnimPaletteData():
  print("uint16 kPauseAnimatedPalette[] = {", end=" ")
  new_line_counter = 0
  for palette in PauseScreenAnimPaletteData:
    if new_line_counter == 16:
      print("\n\t\t\t\t\t\t\t\t   ", end="")
      new_line_counter = 0
    print("%6s" % palette, end=", ")
    new_line_counter += 1
  print("};")
  return


#Reserve tank animation data
ReserveTankAnimData = []
def getReserveTankAnimData():
  data_address = 0x82C165
  end_address = 0x82C182
  while data_address != end_address:
    get_data = get_byte(data_address)
    ReserveTankAnimData.append(get_data)
    data_address += 1
  printReserveTankAnimData()
  return

def printReserveTankAnimData():
  print("uint8 kPauseReserveTankAnimationData[] = {", end=" ")
  new_space_counter = 0
  for data in ReserveTankAnimData:
    if new_space_counter == 2:
      print(" ", end="")
      new_space_counter = 0
    print(data, end=",")
    new_space_counter += 1
  print("};")
  return


#RAM tilemap offsets
TanksEquipmentOffset = []
def getTanksEquipmentOffset():
  offset_address = 0x82C068
  end_address = 0x82C06C
  while offset_address != end_address:
    get_offset = hex(get_word(offset_address))
    TanksEquipmentOffset.append(get_offset)
    offset_address += 2
  printTanksEquipmentOffset()
  return

def printTanksEquipmentOffset():
  print("uint16 kEquipmentTilemapOffs_Tanks[] = {", end=" ")
  for offset in TanksEquipmentOffset:
    print(offset, end=", ")
  print("};")
  return


WeaponsEquipmentOffset = []
def getWeaponsEquipmentOffset():
  offset_address = 0x82C06C
  end_address = 0x82C076
  while offset_address != end_address:
    get_offset = hex(get_word(offset_address))
    WeaponsEquipmentOffset.append(get_offset)
    offset_address += 2
  printWeaponsEquipmentOffset()
  return

def printWeaponsEquipmentOffset():
  print("uint16 kEquipmentTilemapOffs_Weapons[] = {", end=" ")
  for offset in WeaponsEquipmentOffset:
    print(offset, end=", ")
  print("};")
  return


SuitsEquipmentOffset = []
def getSuitsEquipmentOffset():
  offset_address = 0x82C076
  end_address = 0x82C082
  while offset_address != end_address:
    get_offset = hex(get_word(offset_address))
    SuitsEquipmentOffset.append(get_offset)
    offset_address += 2
  printSuitsEquipmentOffset()
  return

def printSuitsEquipmentOffset():
  print("uint16 kEquipmentTilemapOffs_Suits[] = {", end=" ")
  for offset in SuitsEquipmentOffset:
    print(offset, end=", ")
  print("};")
  return


BootsEquipmentOffset = []
def getBootsEquipmentOffset():
  offset_address = 0x82C082
  end_address = 0x82C088
  while offset_address != end_address:
    get_offset = hex(get_word(offset_address))
    BootsEquipmentOffset.append(get_offset)
    offset_address += 2
  printBootsEquipmentOffset()
  return

def printBootsEquipmentOffset():
  print("uint16 kEquipmentTilemapOffs_Boots[] = {", end=" ")
  for offset in BootsEquipmentOffset:
    print(offset, end=", ")
  print("};")
  return


#Samus wireframe item bitmasks
SamusWireframeItemBitmask = []
def getSamusWireframeItemBitmask():
  bitmask_address = 0x82B257
  end_address = 0x82B25F
  while bitmask_address != end_address:
    get_bitmask = hex(get_word(bitmask_address))
    SamusWireframeItemBitmask.append(get_bitmask)
    bitmask_address += 2
  printSamusWireframeItemBitmask()
  return

def printSamusWireframeItemBitmask():
  print("uint16 kEquipmentScreenWireframeCmp[] = {", end=" ")
  for bitmask in SamusWireframeItemBitmask:
    print(bitmask, end=", ")
  print("};")
  return


#Samus wireframe item pointers
SamusWireframeItemPtr = []
def getSamusWireframeItemPtr():
  ptr_address = 0x82B25F
  end_address = 0x82B267
  while ptr_address != end_address:
    get_ptr = hex(get_word(ptr_address))
    SamusWireframeItemPtr.append(get_ptr)
    ptr_address += 2
  printSamusWireframeItemPtr()
  return

def printSamusWireframeItemPtr():
  print("uint16 kEquipmentScreenWireframePtrs[] = {", end=" ")
  for ptr in SamusWireframeItemPtr:
    print(ptr, end=", ")
  print("};")
  return


#Pointers to lists of equipment screen item selector positions
ItemSelectPosEquipmentPtr = []
def getItemSelectPosEquipmentPtr():
  ptr_address = 0x82C18E
  end_address = 0x82C196
  while ptr_address != end_address:
    get_ptr = hex(get_word(ptr_address))
    ItemSelectPosEquipmentPtr.append(get_ptr)
    ptr_address += 2
  printItemSelectPosEquipmentPtr()
  return

def printItemSelectPosEquipmentPtr():
  print("uint16 kEquipmentScreenPtrsToItemXYpos[] = {", end=" ")
  for ptr in ItemSelectPosEquipmentPtr:
    print(ptr, end=", ")
  print("};")
  return


#Equipment screen data - Pointers to lists of RAM tilemap offsets
EquipmentScreenRamOffset = []
def getEquipmentScreenRamOffset():
  offset_address = 0x82C02C
  end_address = 0x82C034
  while offset_address != end_address:
    get_offset = hex(get_word(offset_address))
    EquipmentScreenRamOffset.append(get_offset)
    offset_address += 2
  printEquipmentScreenRamOffset()
  return

def printEquipmentScreenRamOffset():
  print("uint16 kEquipmentPtrsToRamTilemapOffsets[] = {", end=" ")
  for offset in EquipmentScreenRamOffset:
    print(offset, end=", ")
  print("};")
  return


#Equipment screen data - Pointers to lists of equipment bitmasks
EquipmentScreenBitmaskOffset = []
def getEquipmentScreenBitmaskOffset():
  bitmask_address = 0x82C034
  end_address = 0x82C03C
  while bitmask_address != end_address:
    get_bitmask = hex(get_word(bitmask_address))
    EquipmentScreenBitmaskOffset.append(get_bitmask)
    bitmask_address += 2
  printEquipmentScreenBitmaskOffset()
  return

def printEquipmentScreenBitmaskOffset():
  print("uint16 kEquipmentPtrsToBitmasks[] = {", end=" ")
  for bitmask in EquipmentScreenBitmaskOffset:
    print(bitmask, end=", ")
  print("};")
  return


#Equipment screen data - Pointers to equipment bitsets
EquipmentScreenBitsetOffset = []
def getEquipmentScreenBitsetOffset():
  bitset_address = 0x82C03C
  end_address = 0x82C044
  while bitset_address != end_address:
    get_bitset = hex(get_word(bitset_address))
    EquipmentScreenBitsetOffset.append(get_bitset)
    bitset_address += 2
  printEquipmentScreenBitsetOffset()
  return

def printEquipmentScreenBitsetOffset():
  print("uint16 kEquipmentPtrsToBitsets[] = {", end=" ")
  for bitset in EquipmentScreenBitsetOffset:
    print(bitset, end=", ")
  print("};")
  return


#Equipment screen data - Pointers to lists of pointers to equipment tilemaps
EquipmentScreenTilemapPtr = []
def getEquipmentScreenTilemapPtr():
  ptr_address = 0x82C044
  end_address = 0x82C04C
  while ptr_address != end_address:
    get_ptr = hex(get_word(ptr_address))
    EquipmentScreenTilemapPtr.append(get_ptr)
    ptr_address += 2
  printEquipmentScreenTilemapPtr()
  return

def printEquipmentScreenTilemapPtr():
  print("uint16 kEquipmentPtrsToEquipmentTilemaps[] = {", end=" ")
  for ptr in EquipmentScreenTilemapPtr:
    print(ptr, end=", ")
  print("};")
  return


#Map icon data pointers
MapIconDataPointer = []
def getMapIconDataPointer():
  data_ptr = 0x82C7CB
  end_address = 0x82C83B
  while data_ptr != end_address:
    get_ptr = hex(get_word(data_ptr))
    MapIconDataPointer.append(get_ptr)
    data_ptr += 2
  printMapIconDataPointer()
  return

def printMapIconDataPointer():
  print("MapIconDataPointers kMapIconDataPointers[] = {", end=" ")
  new_line_counter = 0
  for data_ptr in MapIconDataPointer:
    if new_line_counter == 8:
      print("\n\t\t\t\t\t\t\t\t\t\t\t   ", end="")
      new_line_counter = 0
    print("%6s" % data_ptr, end=", ")
    new_line_counter += 1
  print("};")
  return


#Map scroll arrow data
LeftMapScrollArrowData = []
RightMapScrollArrowData = []
UpMapScrollArrowData = []
DownMapScrollArrowData = []
def getMapScrollArrowData():
  map_arrow_data = 0x82B9A0
  new_data = MapScrollArrowData(map_arrow_data)
  LeftMapScrollArrowData.append(new_data)
  map_arrow_data += 10
  new_data = MapScrollArrowData(map_arrow_data)
  RightMapScrollArrowData.append(new_data)
  map_arrow_data += 10
  new_data = MapScrollArrowData(map_arrow_data)
  UpMapScrollArrowData.append(new_data)
  map_arrow_data += 10
  new_data = MapScrollArrowData(map_arrow_data)
  map_arrow_data += 10
  DownMapScrollArrowData.append(new_data)
  printMapScrollArrowData()
  return

def printMapScrollArrowData():
  for data in LeftMapScrollArrowData:
    print("MapScrollArrowData kLeftMapScrollArrowData = {", end=" ")
    print(data)
  for data in RightMapScrollArrowData:
    print("MapScrollArrowData kRightMapScrollArrowData = {", end=" ")
    print(data)
  for data in UpMapScrollArrowData:
    print("MapScrollArrowData kUpMapScrollArrowData = {", end=" ")
    print(data)
  for data in DownMapScrollArrowData:
    print("MapScrollArrowData kDownMapScrollArrowData = {", end=" ")
    print(data)
  return


#File copy arrow spritemap index
FileCopyArrowIndex = []
def getFileCopyArrowIndex():
  index_address = 0x82BB0C
  end_address = 0x82BB30
  while index_address != end_address:
    new_index = FileCopyArrowStuff(index_address)
    FileCopyArrowIndex.append(new_index)
    index_address += 6
  printFileCopyArrowIndex()
  return

def printFileCopyArrowIndex():
  print("FileCopyArrowStuff file_copy_arrow_stuff[] = {", end=" ")
  new_line_counter = 0
  for index in FileCopyArrowIndex:
    if new_line_counter > 0:
      print("\n\t\t\t\t\t\t\t\t\t\t\t   ", end="")
    print(index, end="")
    new_line_counter += 1
  print("};")
  return


#Map elevator destinations
MapElevatorDestination = []
def getMapElevatorDestination():
  destination_address = 0x82C74D
  end_address = 0x82C759
  while destination_address != end_address:
    get_destination = hex(get_word(destination_address))
    MapElevatorDestination.append(get_destination)
    destination_address += 2
  printMapElevatorDestination()
  return

def printMapElevatorDestination():
  print("uint16 kMapElevatorDests[] = {", end=" ")
  for destination in MapElevatorDestination:
    print(destination, end=", ")
  print("};")
  return


#Tileset pointers
TilesetPtr = []
def getTilesetPtr():
  ptr_address = 0x8FE7A7
  end_address = 0x8FE7E1
  while ptr_address != end_address:
    get_ptr = hex(get_word(ptr_address))
    TilesetPtr.append(get_ptr)
    ptr_address += 2
  printTilesetPtr()
  return

def printTilesetPtr():
  print("uint16 kStateHeaderTileSets[] = {", end=" ")
  new_line_counter = 0
  for ptr in TilesetPtr:
    if(new_line_counter == 9):
      print("\n\t\t\t\t\t\t\t\t  ", end="")
      new_line_counter = 0
    print(ptr, end=", ")
    new_line_counter += 1
  print("};")
  return


#Standard target sprite palette line 0 (whites and greys for flashing)
FlashingSpritePalette = []
def getFlashingSpritePalette():
  palette_address = 0x9AFC00
  end_address = 0x9AFC20
  while palette_address != end_address:
    get_palette = hex(get_word(palette_address))
    FlashingSpritePalette.append(get_palette)
    palette_address += 2
  printFlashingSpritePalette()
  return

def printFlashingSpritePalette():
  print("uint16 kCommonSpritesPalette1[] = {", end=" ")
  new_line_counter = 0
  for palette in FlashingSpritePalette:
    if new_line_counter == 4:
      print("\n\t\t\t\t\t\t\t\t\t", end="")
      new_line_counter = 0
    print("%6s" % palette, end=", ")
    new_line_counter += 1
  print("};")
  return


#Menu palettes
MenuPalettes = []
def getMenuPalettes():
  menu_palettes_address = 0x8EE400
  end_address = 0x8EE600
  while menu_palettes_address != end_address:
    get_menu_palettes = hex(get_word(menu_palettes_address))
    MenuPalettes.append(get_menu_palettes)
    menu_palettes_address += 2
  printMenuPalettes()
  return

def printMenuPalettes():
  print("uint16 kMenuPalettes[] = {", end=" ")
  new_line_counter = 0
  for menu_palettes in MenuPalettes:
    if new_line_counter == 16:
      print("\n\t\t\t\t\t\t   ", end="")
      new_line_counter = 0
    print("%6s" % menu_palettes, end=", ")
    new_line_counter += 1
  print("};")
  return


#Special setting RAM addresses
SpecialSettingRamPtr = []
def getSpecialSettingRamPtr():
  ptr_address = 0x82F0AE
  end_address = 0x82F0B2
  while ptr_address != end_address:
    get_ram_ptr = hex(get_word(ptr_address))
    SpecialSettingRamPtr.append(get_ram_ptr)
    ptr_address += 2
  printSpecialSettingRamPtr()
  return

def printSpecialSettingRamPtr():
  print("uint16 kOptionsMenuSpecialPtrs[] = {", end=" ")
  for ram_ptr in SpecialSettingRamPtr:
    print(ram_ptr, end=", ")
  print("};")
  return


#Menu Selection Missile - Position Offset
MenuMissilePosPtr = []
def getMenuMissileStartPos():
  ptr_address = 0x82F2ED
  end_address = 0x82F307
  while ptr_address != end_address:
    get_ptr = hex(get_word(ptr_address))
    MenuMissilePosPtr.append(get_ptr)
    ptr_address += 2
  printMenuMissileStartPos()
  return

def printMenuMissileStartPos():
  print("uint16 kMenuMissilePtrsToStartPos[] = {", end=" ")
  for ptr in MenuMissilePosPtr:
    print(ptr, end=", ")
  print("};")
  return


#Configurable controller binding RAM addresses
ControllerBindingRamAddressPtr = []
def getControllerBindingRamAddressPtr():
  ptr_address = 0x82F54A
  end_address = 0x82F558
  while ptr_address != end_address:
    get_ram_ptr = hex(get_word(ptr_address))
    ControllerBindingRamAddressPtr.append(get_ram_ptr)
    ptr_address += 2
  printControllerBindingRamAddressPtr()
  return

def printControllerBindingRamAddressPtr():
  print("uint16 kControllerBindingRAMAddresses[] = {", end=" ")
  for ram_ptr in ControllerBindingRamAddressPtr:
    print(ram_ptr, end=", ")
  print("};")
  return


#Game options menu tilemap offsets
GameOptionsTilemapOffset = []
def getGameOptionsTilemapOffset():
  offset_address = 0x82F639
  end_address = 0x82F647
  while offset_address != end_address:
    get_offset = hex(get_word(offset_address))
    GameOptionsTilemapOffset.append(get_offset)
    offset_address += 2
  printGameOptionsTilemapOffset()
  return

def printGameOptionsTilemapOffset():
  print("uint16 kOptionsMenuPtrsToTilemapOffsets[] = {", end=" ")
  for offset in GameOptionsTilemapOffset:
    print(offset, end=", ")
  print("};")
  return


#Controller button tilemap pointers
ControllerButtonTilemapPtr = []
def getControllerButtonTilemapPtr():
  ptr_address = 0x82F647
  end_address = 0x82F659
  while ptr_address != end_address:
    get_ptr = hex(get_word(ptr_address))
    ControllerButtonTilemapPtr.append(get_ptr)
    ptr_address += 2
  printControllerButtonTilemapPtr()
  return

def printControllerButtonTilemapPtr():
  print("uint16 kOptionsMenuPtrsToButtonTilemaps[] = {", end=" ")
  for ptr in ControllerButtonTilemapPtr:
    print(ptr, end=", ")
  print("};")
  return


def getAll():
  getDemoRoomDataPtr()
  getPauseScreenSpriteAnim()
  getSpritePaletteIndexValue()
  getGeneralMenuAnimationSpritemapBaseIdPtr()
  getInitialPalette()
  getPauseScreenPalette()
  getLRHighlightAnimData()
  getAreaLabelTilemapPtr()
  getAreaMapPtr()
  getMapDataPtr()
  getTanksEquipmentTilemap()
  getWeaponsEquipmentTilemap()
  getSuitsEquipmentTilemap()
  getBootsEquipmentTilemap()
  getHyperEquipmentTilemap()
  getWeaponsEquipmentBitmask()
  getSuitsEquipmentBitmask()
  getBootsEquipmentBitmask()
  getPauseScreenAnimPaletteData()
  getReserveTankAnimData()
  getTanksEquipmentOffset()
  getWeaponsEquipmentOffset()
  getSuitsEquipmentOffset()
  getBootsEquipmentOffset()
  getSamusWireframeItemBitmask()
  getSamusWireframeItemPtr()
  getItemSelectPosEquipmentPtr()
  getEquipmentScreenRamOffset()
  getEquipmentScreenBitmaskOffset()
  getEquipmentScreenBitsetOffset()
  getEquipmentScreenTilemapPtr()
  getMapIconDataPointer()
  getMapScrollArrowData()
  getFileCopyArrowIndex()
  getMapElevatorDestination()
  getTilesetPtr()
  getFlashingSpritePalette()
  getMenuPalettes()
  getSpecialSettingRamPtr()
  getMenuMissileStartPos()
  getControllerBindingRamAddressPtr()
  getGameOptionsTilemapOffset()
  getControllerButtonTilemapPtr()

getAll()