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

bank_84 = 0x840000


#Golden Torizo palette 1
GoldenTorizoPalette1 = []
def getGoldzenTorizoPalette1():
  palette_address = 0x848032
  end_address = 0x848132
  while palette_address != end_address:
    get_palette = hex(get_word(palette_address))
    GoldenTorizoPalette1.append(get_palette)
    palette_address += 2
  printGoldzenTorizoPalette1()
  return

def printGoldzenTorizoPalette1():
  print("uint16 kGoldenTorizoPalette1[] = {", end=" ")
  new_line_counter = 0
  for palette in GoldenTorizoPalette1:
    if new_line_counter == 16:
      print("\n\t\t\t\t\t\t\t\t   ", end="")
      new_line_counter = 0
    print("%6s" % palette, end=", ")
    new_line_counter += 1
  print("};\n")
  return


#Golden Torizo palette 2
GoldenTorizoPalette2 = []
def getGoldzenTorizoPalette2():
  palette_address = 0x848132
  end_address = 0x848232
  while palette_address != end_address:
    get_palette = hex(get_word(palette_address))
    GoldenTorizoPalette2.append(get_palette)
    palette_address += 2
  printGoldzenTorizoPalette2()
  return

def printGoldzenTorizoPalette2():
  print("uint16 kGoldenTorizoPalette2[] = {", end=" ")
  new_line_counter = 0
  for palette in GoldenTorizoPalette2:
    if new_line_counter == 16:
      print("\n\t\t\t\t\t\t\t\t   ", end="")
      new_line_counter = 0
    print("%6s" % palette, end=", ")
    new_line_counter += 1
  print("};\n")
  return


#Pointers to x-ray block drawing instructions
XrayBlockDrawingInstructionsPtr = []
def getXrayBlockDrawingInstructionsPtr():
  ptr_address = 0x84839D
  end_address = 0x8483AD
  while ptr_address != end_address:
    get_ptr = hex(get_word(ptr_address))
    XrayBlockDrawingInstructionsPtr.append(get_ptr)
    ptr_address += 2
  printXrayBlockDrawingInstructionsPtr()
  return

def printXrayBlockDrawingInstructionsPtr():
  print("uint16 kXrayBlockDrawingInstrs[] = {", end=" ")
  for ptr in XrayBlockDrawingInstructionsPtr:
    print(ptr, end=", ")
  print("};\n")
  return


#Grey door pre-instructions
GreyDoorPreInstructions = []
def getGreyDoorPreInstructions():
  ptr_address = 0x84BE4B
  end_address = 0x84BE59
  while ptr_address != end_address:
    get_ptr = hex(get_word(ptr_address))
    GreyDoorPreInstructions.append(get_ptr)
    ptr_address += 2
  printGreyDoorPreInstructions()
  return

def printGreyDoorPreInstructions():
  print("uint16 kGrayDoorPreInstrs[] = {", end=" ")
  for ptr in GreyDoorPreInstructions:
    print(ptr, end=", ")
  print("};\n")
  return


#Setup - PLM $C836 (downwards gate shotblock) - Instruction list
DownwardsGateShotblockInstructionList = []
def getDownwardsGateShotblockInstructionList():
  ptr_address = 0x84C70A
  end_address = 0x84C71A
  while ptr_address != end_address:
    get_ptr = hex(get_word(ptr_address))
    DownwardsGateShotblockInstructionList.append(get_ptr)
    ptr_address += 2
  printDownwardsGateShotblockInstructionList()  
  return

def printDownwardsGateShotblockInstructionList():
  print("uint16 kDowardGatePlmListPtrs[] = {", end=" ")
  for ptr in DownwardsGateShotblockInstructionList:
    print(ptr, end=", ")
  print("};\n")
  return


#Setup - PLM $C836 (downwards gate shotblock) - Block type / BTS for block to the left
DownwardsGateShotblockLeftBts = []
def getDownwardsGateShotblockLeftBts():
  ptr_address = 0x84C71A
  end_address = 0x84C72A
  while ptr_address != end_address:
    get_ptr = hex(get_word(ptr_address))
    DownwardsGateShotblockLeftBts.append(get_ptr)
    ptr_address += 2
  printDownwardsGateShotblockLeftBts()  
  return

def printDownwardsGateShotblockLeftBts():
  print("uint16 kDowardGateLeftBlockBts[] = {", end=" ")
  for ptr in DownwardsGateShotblockLeftBts:
    print(ptr, end=", ")
  print("};\n")
  return


#Setup - PLM $C836 (downwards gate shotblock) - Block type / BTS for block to the right
DownwardsGateShotblockRightBts = []
def getDownwardsGateShotblockRightBts():
  ptr_address = 0x84C72A
  end_address = 0x84C73A
  while ptr_address != end_address:
    get_ptr = hex(get_word(ptr_address))
    DownwardsGateShotblockRightBts.append(get_ptr)
    ptr_address += 2
  printDownwardsGateShotblockRightBts()  
  return

def printDownwardsGateShotblockRightBts():
  print("uint16 kDowardGateRightBlockBts[] = {", end=" ")
  for ptr in DownwardsGateShotblockRightBts:
    print(ptr, end=", ")
  print("};\n")
  return


#Setup - PLM $C83A (upwards gate shotblock) - Instruction list
UpwardsGateShotblockInstructionList = []
def getUpwardsGateShotblockInstructionList():
  ptr_address = 0x84C764
  end_address = 0x84C774
  while ptr_address != end_address:
    get_ptr = hex(get_word(ptr_address))
    UpwardsGateShotblockInstructionList.append(get_ptr)
    ptr_address += 2
  printUpwardsGateShotblockInstructionList()  
  return

def printUpwardsGateShotblockInstructionList():
  print("uint16 kUpwardGatePlmListPtrs[] = {", end=" ")
  for ptr in UpwardsGateShotblockInstructionList:
    print(ptr, end=", ")
  print("};\n")
  return


#Setup - PLM $C83A (upwards gate shotblock) - Block type / BTS for block to the left
UpwardsGateShotblockLeftBts = []
def getUpwardsGateShotblockLeftBts():
  ptr_address = 0x84C774
  end_address = 0x84C784
  while ptr_address != end_address:
    get_ptr = hex(get_word(ptr_address))
    UpwardsGateShotblockLeftBts.append(get_ptr)
    ptr_address += 2
  printUpwardsGateShotblockLeftBts()  
  return

def printUpwardsGateShotblockLeftBts():
  print("uint16 kUpwardGateLeftBlockBts[] = {", end=" ")
  for ptr in UpwardsGateShotblockLeftBts:
    print(ptr, end=", ")
  print("};\n")
  return


#Setup - PLM $C83A (upwards gate shotblock) - Block type / BTS for block to the right
UpwardsGateShotblockRightBts = []
def getUpwardsGateShotblockRightBts():
  ptr_address = 0x84C784
  end_address = 0x84C794
  while ptr_address != end_address:
    get_ptr = hex(get_word(ptr_address))
    UpwardsGateShotblockRightBts.append(get_ptr)
    ptr_address += 2
  printUpwardsGateShotblockRightBts()  
  return

def printUpwardsGateShotblockRightBts():
  print("uint16 kUpwardGateRightBlockBts[] = {", end=" ")
  for ptr in UpwardsGateShotblockRightBts:
    print(ptr, end=", ")
  print("};\n")
  return


#Setup - PLM $DB44 (sets Metroids cleared states when required) - pre-instructions
MetroidsClearedPreInstructions = []
def getMetroidsClearedPreInstructions():
  ptr_address = 0x84DB28
  end_address = 0x84DB42
  while ptr_address != end_address:
    get_ptr = hex(get_word(ptr_address))
    MetroidsClearedPreInstructions.append(get_ptr)
    ptr_address += 2
  printMetroidsClearedPreInstructions()
  return

def printMetroidsClearedPreInstructions():
  print("uint16 kSetMetroidsClearStatePreInstrs[] = {", end=" ")
  for ptr in MetroidsClearedPreInstructions:
    print(ptr, end=", ")
  print("};\n")
  return


#Instruction - draw item frame 0 - draw instructions
ItemFrame0DrawInstructions = []
def getItemFrame0DrawInstructions():
  ptr_address = 0x84E05F
  end_address = 0x84E067
  while ptr_address != end_address:
    get_ptr = hex(get_word(ptr_address))
    ItemFrame0DrawInstructions.append(get_ptr)
    ptr_address += 2
  printItemFrame0DrawInstructions()
  return

def printItemFrame0DrawInstructions():
  print("uint16 kDrawItemFrame0DrawInstrs[] = {", end=" ")
  for ptr in ItemFrame0DrawInstructions:
    print(ptr, end=", ")
  print("};\n")
  return


#Instruction - draw item frame 1 - draw instructions
ItemFrame1DrawInstructions = []
def getItemFrame1DrawInstructions():
  ptr_address = 0x84E077
  end_address = 0x84E07F
  while ptr_address != end_address:
    get_ptr = hex(get_word(ptr_address))
    ItemFrame1DrawInstructions.append(get_ptr)
    ptr_address += 2
  printItemFrame1DrawInstructions()
  return

def printItemFrame1DrawInstructions():
  print("uint16 kDrawItemFrame1DrawInstrs[] = {", end=" ")
  for ptr in ItemFrame1DrawInstructions:
    print(ptr, end=", ")
  print("};\n")
  return


#Instruction - load item PLM GFX - VRAM addresses
PlmGfxVramAddress = []
def getPlmVramAddress():
  vram_ptr_address = 0x8487CD
  end_address = 0x8487D5
  while vram_ptr_address != end_address:
    get_vram_ptr = hex(get_word(vram_ptr_address))
    PlmGfxVramAddress.append(get_vram_ptr)
    vram_ptr_address += 2
  printPlmVramAddress()
  return

def printPlmVramAddress():
  print("uint16 kPlmVramAddresses[] = {", end=" ")
  for vram_ptr in PlmGfxVramAddress:
    print(vram_ptr, end=", ")
  print("};\n")
  return


#Instruction - load item PLM GFX - Tile data offsets
PlmGfxVramTileDataOffset = []
def getPlmVramTileDataOffset():
  offset_address = 0x8487D5
  end_address = 0x8487DD
  while offset_address != end_address:
    get_offset = hex(get_word(offset_address))
    PlmGfxVramTileDataOffset.append(get_offset)
    offset_address += 2
  printPlmVramTileDataOffset()
  return

def printPlmVramTileDataOffset():
  print("uint16 kPlmTileDataOffs[] = {", end=" ")
  for offset in PlmGfxVramTileDataOffset:
    print(offset, end=", ")
  print("};\n")
  return


#Instruction - load item PLM GFX - Starting tile numbers
PlmGfxVramStartingTile = []
def getPlmVramStartingTile():
  start_address = 0x8487DD
  end_address = 0x8487E5
  while start_address != end_address:
    get_start = hex(get_word(start_address))
    PlmGfxVramStartingTile.append(get_start)
    start_address += 2
  printPlmVramStartingTile()
  return

def printPlmVramStartingTile():
  print("uint16 kPlmStartingTileNumber[] = {", end=" ")
  for start in PlmGfxVramStartingTile:
    print(start, end=", ")
  print("};\n")
  return




def getAll():
  getGoldzenTorizoPalette1()
  getGoldzenTorizoPalette2()
  getXrayBlockDrawingInstructionsPtr()
  getGreyDoorPreInstructions()
  getDownwardsGateShotblockInstructionList()
  getDownwardsGateShotblockLeftBts()
  getDownwardsGateShotblockRightBts()
  getUpwardsGateShotblockInstructionList()
  getUpwardsGateShotblockLeftBts()
  getUpwardsGateShotblockRightBts()
  getMetroidsClearedPreInstructions()
  getItemFrame0DrawInstructions()
  getItemFrame1DrawInstructions()
  getPlmVramAddress()
  getPlmVramTileDataOffset()
  getPlmVramStartingTile()

getAll()