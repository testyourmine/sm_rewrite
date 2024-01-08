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
  
class ExpandingSquareVels:
  def __init__(self, addr):
    self.left_subvel = get_word(addr)
    self.left_vel = get_word(addr+2)
    self.right_subvel = get_word(addr+4)
    self.right_vel = get_word(addr+6)
    self.top_subvel = get_word(addr+8)
    self.top_vel = get_word(addr+10)
    self.bottom_subvel = get_word(addr+12)
    self.bottom_vel = get_word(addr+14)
  def __str__(self):
    output = "%6s,%6s, %6s,%3s, %6s,%6s, %6s,%3s, " % (hex(self.left_subvel), hex(self.left_vel), hex(self.right_subvel), hex(self.right_vel), 
                                                           hex(self.top_subvel), hex(self.top_vel), hex(self.bottom_subvel), hex(self.bottom_vel))
    return output


bank_81 = 0x810000

#SRAM offsets for each save slot
SaveSlotOffset = []
def getSaveSlotOffset():
  save_slot_offset_address = 0x81812b
  end_address = 0x818131
  while save_slot_offset_address != end_address:
    get_offset = hex(get_word(save_slot_offset_address))
    SaveSlotOffset.append(get_offset)
    save_slot_offset_address += 2
  printSavesSlotOffset()
  return

def printSavesSlotOffset():
  print("uint16 kOffsetToSaveSlot[] = {", end=" ")
  for save_slot_offset in SaveSlotOffset:
    print(save_slot_offset, end=", ")
  print("};")
  return


#Size of each area map
AreaMapSize = []
def getAreaMapSize():
  area_map_size_address = 0x818131
  end_address = 0x818138
  while area_map_size_address != end_address:
    get_size = get_byte(area_map_size_address)
    AreaMapSize.append(get_size)
    area_map_size_address += 1
  printAreaMapSize()
  return

def printAreaMapSize():
  print("uint8 kPackedBytesPerArea_Count[] = {", end=" ")
  for area_map_size in AreaMapSize:
    print(area_map_size, end=", ")
  print("};")
  return


#Offset for each area map
AreaMapOffset = []
def getAreaMapOffset():
  area_map_offset_address = 0x818138
  end_address = 0x818146
  while area_map_offset_address != end_address:
    get_offset = get_word(area_map_offset_address)
    AreaMapOffset.append(get_offset)
    area_map_offset_address += 2
  printAreaMapOffset()
  return

def printAreaMapOffset():
  print("uint16 kPackedBytesPerArea_PackedOffs[] = {", end=" ")
  for area_map_offset in AreaMapOffset:
    print(area_map_offset, end=", ")
  print("};")
  return


#Pointer to each area's map rooms
MapRoomPtr = []
def getMapRoomPtr():
  map_room_ptr_address = 0x8182D6
  end_address = 0x8182E4
  while map_room_ptr_address != end_address:
    get_ptr = hex(get_word(map_room_ptr_address))
    MapRoomPtr.append(get_ptr)
    map_room_ptr_address += 2
  printMapRoomPtr()
  return

def printMapRoomPtr():
  print("uint16 kPackedBytesPerArea_UnpackedOffs[] = {", end=" ")
  for map_room in MapRoomPtr:
    print(map_room, end=", ")
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


#Zebes and stars tilemap
ZebesStarsTilemap = []
def getZebesStarsTilemap():
  zebes_stars_tilemap_address = 0x8EDC00
  end_address = 0x8EE400
  while zebes_stars_tilemap_address != end_address:
    get_zebes_stars_tilemap = hex(get_word(zebes_stars_tilemap_address))
    ZebesStarsTilemap.append(get_zebes_stars_tilemap)
    zebes_stars_tilemap_address += 2
  printZebesStarsTilemap()
  return

def printZebesStarsTilemap():
  print("uint16 kZebesAndStarsTilemap[] = {", end=" ")
  new_line_counter = 0
  for zebes_stars_tilemap in ZebesStarsTilemap:
    if new_line_counter == 32:
      print("\n\t\t\t\t\t\t\t\t   ", end="")
      new_line_counter = 0
    print("%6s" % zebes_stars_tilemap, end=", ")
    new_line_counter += 1
  print("};")
  return


#Area select map foreground palettes offsets
AreaMapForegroundPalettesOffset = []
def getAreaMapForegroundPalettesOffset():
  offset_address = 0x81A4E6
  end_address = 0x81A546
  while offset_address != end_address:
    get_offset = hex(get_word(offset_address))
    AreaMapForegroundPalettesOffset.append(get_offset)
    offset_address += 2
  printAreaMapForegroundPalettesOffset()
  return

def printAreaMapForegroundPalettesOffset():
  print("uint16 kAreaMapForegroundSetDefs[] = {", end=" ")
  new_line_counter = 0
  for offset in AreaMapForegroundPalettesOffset:
    if new_line_counter == 2:
      print("\n\t\t\t\t\t\t\t\t\t   ", end="")
      new_line_counter = 0
    print("%6s" % offset, end=", ")
    if offset == "0xffff":
      new_line_counter = 2
      continue
    new_line_counter += 1
  print("};")
  return


#Area select map foreground palettes
AreaMapForegroundPalettes = []
def getAreaMapForegroundPalettes():
  palette_address = 0x81A40E
  end_address = 0x81A4CE
  while palette_address != end_address:
    get_palette = hex(get_word(palette_address))
    AreaMapForegroundPalettes.append(get_palette)
    palette_address += 2
  printAreaMapForegroundPalettes()
  return

def printAreaMapForegroundPalettes():
  print("uint16 kAreaMapForegroundColors[] = {", end=" ")
  new_line_counter = 0
  for palette in AreaMapForegroundPalettes:
    if new_line_counter == 16:
      print("\n\t\t\t\t\t\t\t\t\t  ", end="")
      new_line_counter = 0
    print("%6s" % palette, end=", ")
    new_line_counter += 1
  print("};")
  return


#Tilemap - BG2 pause screen / BG2 room select map
Bg2PauseScreenRoomSelectTilemap = []
def getBg2PauseScreenRoomSelectTilemap():
  tilemap_address = 0xB6E000
  end_address = 0xB6E800
  while tilemap_address != end_address:
    get_tilemap = hex(get_word(tilemap_address))
    Bg2PauseScreenRoomSelectTilemap.append(get_tilemap)
    tilemap_address += 2
  printBg2PauseScreenRoomSelectTilemap()
  return

def printBg2PauseScreenRoomSelectTilemap():
  print("uint16 kBg2RoomSelectMapTilemap[] = {", end=" ")
  new_line_counter = 0
  for tilemap in Bg2PauseScreenRoomSelectTilemap:
    if new_line_counter == 32:
      print("\n\t\t\t\t\t\t\t\t\t  ", end="")
      new_line_counter = 0
    print("%6s" % tilemap, end=", ")
    new_line_counter += 1
  print("};")
  return


#Tilemap - room select map controls
RoomSelectMapControlsTilemap = []
def getRoomSelectMapControlsTilemap():
  tilemap_address = 0x81B14B
  end_address = 0x81B2CB
  while tilemap_address != end_address:
    get_tilemap = hex(get_word(tilemap_address))
    RoomSelectMapControlsTilemap.append(get_tilemap)
    tilemap_address += 2
  printRoomSelectMapControlsTilemap()
  return

def printRoomSelectMapControlsTilemap():
  print("uint16 kFileSelectExpandingSquareTilemap[] = {", end=" ")
  new_line_counter = 0
  for tilemap in RoomSelectMapControlsTilemap:
    if new_line_counter == 32:
      print("\n\t\t\t\t\t\t\t\t\t\t\t   ", end="")
      new_line_counter = 0
    print("%6s" % tilemap, end=", ")
    new_line_counter += 1
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


#Area select spritemap base index
AreaSelectSpritemapBaseIndex = []
def getAreaSelectSpritemapBaseIndex():
  index_ptr = 0x82C749
  get_index = hex(get_word(index_ptr))
  AreaSelectSpritemapBaseIndex.append(get_index)
  printAreaSelectSpritemapBaseIndex()
  return

def printAreaSelectSpritemapBaseIndex():
  print("uint16 gAreaSelectSpritemapOffset[] = {", end=" ")
  for index in AreaSelectSpritemapBaseIndex:
    print(index, end=" ")
  print("};")
  return


#Map scroll arrow data
FileSelectLeftMapScrollArrowData = []
FileSelectRightMapScrollArrowData = []
FileSelectUpMapScrollArrowData = []
FileSelectDownMapScrollArrowData = []
def getFileSelectMapScrollArrowData():
  map_arrow_data = 0x81AF32
  new_data = MapScrollArrowData(map_arrow_data)
  FileSelectLeftMapScrollArrowData.append(new_data)
  map_arrow_data += 10
  new_data = MapScrollArrowData(map_arrow_data)
  FileSelectRightMapScrollArrowData.append(new_data)
  map_arrow_data += 10
  new_data = MapScrollArrowData(map_arrow_data)
  FileSelectUpMapScrollArrowData.append(new_data)
  map_arrow_data += 10
  new_data = MapScrollArrowData(map_arrow_data)
  map_arrow_data += 10
  FileSelectDownMapScrollArrowData.append(new_data)
  printFileSelectMapScrollArrowData()
  return

def printFileSelectMapScrollArrowData():
  for data in FileSelectLeftMapScrollArrowData:
    print("MapScrollArrowData kFileSelectLeftMapScrollArrowData = {", end=" ")
    print(data)
  for data in FileSelectRightMapScrollArrowData:
    print("MapScrollArrowData kFileSelectRightMapScrollArrowData = {", end=" ")
    print(data)
  for data in FileSelectUpMapScrollArrowData:
    print("MapScrollArrowData kFileSelectUpMapScrollArrowData = {", end=" ")
    print(data)
  for data in FileSelectDownMapScrollArrowData:
    print("MapScrollArrowData kFileSelectDownMapScrollArrowData = {", end=" ")
    print(data)
  return


#Spritemap pointers
MenuSpritemapPtr = []
def getGeneralMenuSpritemap():
  spritemap_ptr_address = 0x82C569
  end_address = 0x82C639
  while spritemap_ptr_address != end_address:
    get_spritemap_ptr = hex(get_word(spritemap_ptr_address))
    MenuSpritemapPtr.append(get_spritemap_ptr)
    spritemap_ptr_address += 2
  printGeneralMenuSpritemap()
  return

def printGeneralMenuSpritemap():
  print("uint16 gMenuSpritemapTable[] = {", end=" ")
  new_line_counter = 0
  for spritemap_ptr in MenuSpritemapPtr:
    if new_line_counter == 16:
      print("\n\t\t\t\t\t\t\t\t ", end="")
      new_line_counter = 0
    print("%6s" % spritemap_ptr, end=", ")
    new_line_counter += 1
  print("};")
  return


#Samus spritemap table
SamusSpritemapTable = []
def getSamusSpritemapPtrs():
  spritemap_ptr = 0x92808D
  end_address = 0x9290ED
  while spritemap_ptr != end_address:
    get_ptr = hex(get_word(spritemap_ptr))
    SamusSpritemapTable.append(get_ptr)
    spritemap_ptr += 2
  SamusSpritemapTable.append(hex(0x9173))
  printSamusSpritemapTable()
  return

def printSamusSpritemapTable():
  print("uint16 kSamusSpritemapTable[] = {", end=" ")
  new_line_counter = 0
  for spritemap_ptr in SamusSpritemapTable:
    if new_line_counter == 16:
      print("\n\t\t\t\t\t\t\t\t  ", end="")
      new_line_counter = 0
    print("%6s" % spritemap_ptr, end=", ")
    new_line_counter += 1
  print("};")
  return


#Flare spritemap pointers
FlareSpritemapPtr = []
def getFlareSpritemapPtr():
  spritemap_ptr_address = 0x93A1A1
  end_address = 0x93A225
  while spritemap_ptr_address != end_address:
    get_spritemap_ptr = hex(get_word(spritemap_ptr_address))
    FlareSpritemapPtr.append(get_spritemap_ptr)
    spritemap_ptr_address += 2
  printFlareSpritemapPtr()
  return

def printFlareSpritemapPtr():
  print("uint16 gFlareSpritemapTable[] = {", end=" ")
  new_line_counter = 0
  for spritemap_ptr in FlareSpritemapPtr:
    if new_line_counter == 16:
      print("\n\t\t\t\t\t\t\t\t  ", end="")
      new_line_counter = 0
    print("%6s" % spritemap_ptr, end=", ")
    new_line_counter += 1
  print("};")
  return


#Room select map expanding square velocities
MapExpandVel = []
def getMapExpandVel():
  vel_address = 0x81AA34
  end_address = 0x81AA94
  while vel_address != end_address:
    new_vel = ExpandingSquareVels(vel_address)
    MapExpandVel.append(new_vel)
    vel_address += 16
  printMapExpandVel()
  return

def printMapExpandVel():
  print("ExpandingSquareVels kExpandingSquareVels[] = {", end= " ")
  new_line_counter = 0
  for vel in MapExpandVel:
    if new_line_counter > 0:
      print("\t\t\t\t\t\t\t\t\t\t\t   ", end="")
    print(vel)
    new_line_counter += 1
  print("};")
  return


def getAll():
  getSaveSlotOffset()
  getAreaMapSize()
  getAreaMapOffset()
  getMapRoomPtr()
  getMenuPalettes()
  getZebesStarsTilemap()
  getAreaMapForegroundPalettesOffset()
  getAreaMapForegroundPalettes()
  getBg2PauseScreenRoomSelectTilemap()
  getRoomSelectMapControlsTilemap()
  getMapIconDataPointer()
  getAreaSelectSpritemapBaseIndex()
  getFileSelectMapScrollArrowData()
  getGeneralMenuSpritemap()
  getSamusSpritemapPtrs()
  getFlareSpritemapPtr()
  getMapExpandVel()

getAll()