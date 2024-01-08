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
  
  def get_double(self, addr):
    addr = self.map(addr)
    return self.data[addr] + self.data[addr + 1] * 256 + self.data[addr + 2] * 65536 + self.data[addr + 3] * 16777216

  def get_bytes(self, addr, n):
    addr = self.map(addr)
    return self.data[addr:addr+n]

ROM = Rom()
get_byte = ROM.get_byte
get_word = ROM.get_word
get_long = ROM.get_long
get_double = ROM.get_double


class uint8:
  def __init__(self, addr):
    self.byte = get_byte(addr)
  def __str__(self):
    output = ""
    if hex_flag == True:
      output = "%4s" % hex(self.byte)
    else:
      #if self.byte >= 0x80:
        #self.byte = -(self.byte ^ 0xFF) -1
      output = "%3s" % self.byte
    return output

class uint16:
  def __init__(self, addr):
    self.word = get_word(addr)
  def __str__(self):
    output = ""
    if hex_flag == True:
      output = "%6s" % hex(self.word)
    else:
      #if self.word >= 0x8000:
        #self.word = -(self.word ^ 0xFFFF) -1
      output = "%5s" % self.word
    return output

class LongPtr:
  def __init__(self, addr):
    self.long_addr = get_word(addr)
    self.bank = get_byte(addr+2)
  def __str__(self):
    output = ""
    if hex_flag == True:
      output = "%6s, %4s" % (hex(self.long_addr), hex(self.bank))
    else:
      output = "%s, %s" % (self.long_addr, self.bank)
    return output

class uint32:
  def __init__(self, addr):
    self.double = get_double(addr)
  def __str__(self):
    output = ""
    if hex_flag == True:
      output = "%10s" % hex(self.double)
    else:
      output = "%10s" % self.double
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

class FileCopyArrowStuff:
  def __init__(self, addr):
    self.spritemap_index = get_word(addr)
    self.x_pos = get_word(addr+2)
    self.y_pos = get_word(addr+4)
  def __str__(self):
    output = "%s, %s, %s, " % (self.spritemap_index, self.x_pos, self.y_pos)
    return output
  
class MsgBoxConfig:
  def __init__(self, addr):
    self.modify_box_func = get_word(addr)
    self.draw_initial_tilemap = get_word(addr+2)
    self.message_tilemap = get_word(addr+4)
  def __str__(self):
    output = "%6s, %6s, %6s, " % (hex(self.modify_box_func), hex(self.draw_initial_tilemap), hex(self.message_tilemap))
    return output

class HdmaScrollEntry:
  def __init__(self, addr):
    self.top_pos = get_word(addr)
    self.scroll_subspeed = get_word(addr+2)
    self.scroll_speed = get_word(addr+4)
    self.hdma_data_table_entry = get_word(addr+6)
  def __str__(self):
    output = "%6s, %6s, %6s, %6s" % (hex(self.top_pos), hex(self.scroll_subspeed), hex(self.scroll_speed), hex(self.hdma_data_table_entry))
    return output

class XrayBlockData:
  def __init__(self, addr):
    self.value = get_word(addr)
    self.addr = get_word(addr+2)
  def __str__(self):
    output = "%6s, %6s" % (hex(self.value), hex(self.addr))
    return output

class SamusCrystalFlashPalTable:
  def __init__(self, addr):
    self.ptr = get_word(addr)
    self.timer = get_word(addr+2)
  def __str__(self):
    output = "%6s,%s" % (hex(self.ptr), self.timer)
    return output

class ProjectileDamagesAndInstrPtr:
  def __init__(self, addr):
    self.damages = get_word(addr)
    self.instr_ptr = get_word(addr+2)
  def __str__(self):
    output = "%6s, %6s" % (hex(self.damages), hex(self.instr_ptr))
    return output

class GrappleBeamSpecialAngles:
  def __init__(self, addr):
    self.angle = get_word(addr)
    self.pose = get_word(addr+2)
    self.x_offset = get_word(addr+4)
    self.y_offset = get_word(addr+6)
    self.grapple_function = get_word(addr+8)
  def __str__(self):
    output = "%6s, %6s, %6s, %6s, %6s" % (hex(self.angle), hex(self.pose), hex(self.x_offset), hex(self.y_offset), hex(self.grapple_function))
    return output

class MaridiaSnailData2:
  def __init__(self, addr):
    self.field_0 = get_word(addr)
    self.field_2 = get_word(addr+2)
    self.field_4 = get_word(addr+4)
    self.field_6 = get_word(addr+6)
  def __str__(self):
    output = "%6s, %5s, %6s, %5s" % (hex(self.field_0), self.field_2, hex(self.field_4), self.field_6)
    return output

class KraidInstrList:
  def __init__(self, addr):
    self.timer = get_word(addr)
    self.tilemap = get_word(addr+2)
    self.vuln_mouth_hitbox = get_word(addr+4)
    self.invuln_mouth_hitbox = get_word(addr+6)
  def __str__(self):
    output = "%5s, %6s, %6s, %6s" % (self.timer, hex(self.tilemap), hex(self.vuln_mouth_hitbox), hex(self.invuln_mouth_hitbox))
    return output

class Hitbox:
  def __init__(self, addr):
    self.left = get_word(addr)
    self.top = get_word(addr+2)
    self.right = get_word(addr+4)
    self.bottom = get_word(addr+6)
    self.samus_coll_ptr = get_word(addr+8)
    self.proj_coll_ptr = get_word(addr+10)
  def __str__(self):
    output = "%6s, %6s, %6s, %6s, %6s, %6s" % (hex(self.left), hex(self.top), hex(self.right), hex(self.bottom), 
                                               hex(self.samus_coll_ptr), hex(self.proj_coll_ptr))
    return output

class SpriteDrawInstr:
  def __init__(self, addr):
    self.timer = get_word(addr)
    self.sprite_ptr = get_word(addr+2)
  def __str__(self):
    output = "%5s, %6s" % (self.timer, hex(self.sprite_ptr))
    return output

class KraidSinkTable:
  def __init__(self, addr):
    self.kraid_y_pos = get_word(addr)
    self.vram_bg2_tilemap_offset = get_word(addr+2)
    self.func_ptr = get_word(addr+4)
  def __str__(self):
    output = "%6s, %6s, %6s" % (hex(self.kraid_y_pos), hex(self.vram_bg2_tilemap_offset), hex(self.func_ptr))
    return output

class ExtendedSpriteMap:
  def __init__(self, addr):
    self.xpos = get_word(addr)
    self.ypos = get_word(addr+2)
    self.spritemap = get_word(addr+4)
    self.hitbox_ptr_ = get_word(addr+6)
  def __str__(self):
    output = "%6s, %6s, %6s, %6s" % (hex(self.xpos), hex(self.ypos), hex(self.spritemap), hex(self.hitbox_ptr_))
    return output

hex_flag = False
array_flag = False

def get_data(bank, start, end, type, data, name, hexadecimal, array, new_line, new_space):
  global hex_flag, array_flag
  hex_flag = hexadecimal
  array_flag = array
  data_address = (bank << 16) + start
  end_address = (bank << 16) + end
  while data_address < end_address:
    new_data = 0
    if type == "uint8":
      new_data = uint8(data_address)
      data_address += 1

    elif type == "uint16":
      new_data = uint16(data_address)
      data_address += 2

    elif type == "LongPtr":
      new_data = LongPtr(data_address)
      data_address += 3
    
    elif type == "uint32":
      new_data = uint32(data_address)
      data_address += 4

    elif type == "MapScrollArrowData":
      new_data = MapScrollArrowData(data_address)
      data_address += 10

    elif type == "ExpandingSquareVels":
      new_data = ExpandingSquareVels(data_address)
      data_address += 16

    elif type == "PauseScreenSpriteAnimationData":
      new_data = PauseScreenSpriteAnimationData(data_address)
      data_address += 18
    
    elif type == "HdmaScrollEntry":
      new_data = HdmaScrollEntry(data_address)
      data_address += 8
      if data_address > end_address:
        data_address -= 6
        new_data = uint16(data_address)
        data.append(new_data)
        break
    
    elif type == "XrayBlockData":
      new_data = XrayBlockData(data_address)
      data_address += 4
      if data_address > end_address:
        data_address -= 2
        new_data = uint16(data_address)
        data.append(new_data)
        break
    
    elif type == "SamusCrystalFlashPalTable":
      new_data = SamusCrystalFlashPalTable(data_address)
      data_address += 4
    
    elif type == "ProjectileDamagesAndInstrPtr":
      new_data = ProjectileDamagesAndInstrPtr(data_address)
      data_address += 4
    
    elif type == "GrappleBeamSpecialAngles":
      new_data = GrappleBeamSpecialAngles(data_address)
      data_address += 10
    
    elif type == "MaridiaSnailData2":
      new_data = MaridiaSnailData2(data_address)
      data_address += 8
    
    elif type == "KraidInstrList":
      new_data = KraidInstrList(data_address)
      data_address += 8
      if data_address > end_address:
        data_address -= 8
        new_data = uint16(data_address)
        data.append(new_data)
        break
    
    elif type == "Hitbox":
      new_data = Hitbox(data_address)
      data_address += 12
    
    elif type == "SpriteDrawInstr":
      new_data = SpriteDrawInstr(data_address)
      data_address += 4
    
    elif type == "KraidSinkTable":
      new_data = KraidSinkTable(data_address)
      data_address += 6
      if data_address > end_address:
        data_address -= 6
        new_data = uint16(data_address)
        data.append(new_data)
        break
    
    elif type == "ExtendedSpriteMap":
      new_data = ExtendedSpriteMap(data_address)
      data_address += 8

    data.append(new_data)
  
  print_data(type, data, name, new_line, new_space)
  return


def print_data(type, data, name, new_line, new_space):
  #print(data type + " " + name + "[] = { \n\t")
  #print("%s %s[] = {" % (type, name), end="\n  ")
  print("%s %s" % (type, name), end="")
  if array_flag == True:
    print("[] = {", end="\n  ")
  elif array_flag == False:
    print(" = {", end=" ")
  new_space_counter = 0
  new_line_counter = 0
  for entry in data:
    if new_space_counter == new_space:
      print(end=" ")
      new_space_counter = 0

    if new_line_counter == new_line:
      print(end="\n  ")
      new_line_counter = 0

    print(entry, end=",")
    new_space_counter += 1
    new_line_counter += 1

  if array_flag == True:
    print("\n};\n")
  elif array_flag == False:
    print(" };\n")
  return

