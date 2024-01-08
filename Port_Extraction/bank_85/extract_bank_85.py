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

bank_85 = 0x850000

class MsgBoxConfig:
  def __init__(self, addr):
    self.modify_box_func = get_word(addr)
    self.draw_initial_tilemap = get_word(addr+2)
    self.message_tilemap = get_word(addr+4)
  def __str__(self):
    output = "%6s, %6s, %6s, " % (hex(self.modify_box_func), hex(self.draw_initial_tilemap), hex(self.message_tilemap))
    return output


#Message definitions
MessageDefinition = []
def getMessageDefinition():
  msg_def_address = 0x85869B
  end_address = 0x858749
  while msg_def_address != end_address:
    new_def = MsgBoxConfig(msg_def_address)
    MessageDefinition.append(new_def)
    msg_def_address += 6
  printMessageDefinition()
  return

def printMessageDefinition():
  print("MsgBoxConfig kMessageBoxDefs[] = {", end=" ")
  for msg_def in MessageDefinition:
    print(msg_def, end="\n\t\t\t\t\t\t\t\t   ")
  print("};")
  return


def getAll():
  getMessageDefinition()


getAll()

