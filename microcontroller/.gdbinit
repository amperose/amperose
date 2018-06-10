target ext :2331
mon endian little
mon halt

# User interface with asm, regs and cmd windows
define split
  layout asm
  layout regs
  layout split
  focus cmd
end

# Initialization function
define init
  mon halt
  lo
  mon reset
end

