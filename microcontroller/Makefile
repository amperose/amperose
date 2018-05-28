##############################################################################
# Project & Device
#

# Project Name.
PROJECT   = amperose

# Define where the application will be built.
BUILD_DIR = build

# Define the main ELF file.
ELF       = $(BUILD_DIR)/$(PROJECT).elf

# Device Specifications
MCU       = cortex-m7
DEVICE    = STM32F767VI

#
# Project & Device
##############################################################################

##############################################################################
# Source files & Paths
#

# Linker script
LDSCRIPT =

# C sources that can be compiled in ARM or THUMB mode
C_SOURCES = main.c

# C Includes
C_INCLUDES =

# ASM sources
AS_SOURCES =

# ASM Includes
AS_INCLUDES =

#
# Source files & Paths
##############################################################################

##############################################################################
# Compilation Options
#

# Compilation Toolchain
PREFIX = arm-none-eabi-

# Compilation Tools
CC  = $(PREFIX)gcc
AS  = $(PREFIX)gcc -x assembler-with-cpp
LD  = $(PREFIX)gcc
CP  = $(PREFIX)objcopy
OD  = $(PREFIX)objdump
SZ  = $(PREFIX)size
GDB = $(PREFIX)gdb
HEX = $(CP) -O ihex
BIN = $(CP) -O binary

# C Flags
C_WARN   = -Wall -Wextra -Werror -Wundef -Wstrict-prototypes
C_OPTS   = -O2 -ggdb -fomit-frame-pointer -falign-functions=16

C_FLAGS  = $(C_OPTS) $(C_WARN)

# ASM Flags
AS_FLAGS =

# LD Flags
LD_FLAGS =
#
# Compilation Options
##############################################################################

##############################################################################
# Build Process
#

# List C Objects
# 1) Replace all .c by .o ($(VAR:pattern:replacement))
# 2) Extract only the file names without the directory ($notdir)
# 3) Build in the Build Directory ($addprefix)
C_OBJECTS  = $(addprefix $(BUILD_DIR)/, $(notdir $(C_SOURCES:.c=.o)))

# List ASM Objects
# 1) Replace all .s by .o ($(VAR:pattern:replacement))
# 2) Extract only the file names without the directory ($notdir)
# 3) Build in the Build Directory ($addprefix)
AS_OBJECTS = $(addprefix $(BUILD_DIR)/, $(notdir $(AS_SOURCES:.s=.o)))

# List of all Objects
OBJECTS    = $(C_OBJECTS) $(AS_OBJECTS)

# Specify where to search for dependencies for C files
vpath %.c $(sort $(dir $(C_SOURCES)))

# Specify where to search for dependencies for ASM files
vpath %.s $(sort $(dir $(AS_SOURCES)))

# Build C Objects
$(BUILD_DIR)/%.o: %.c
	$(CC) -c $(C_FLAGS) $< -o $@

# Build ASM Objects
$(BUILD_DIR)/%.o: %.s
	$(AS) -c $(AS_FLAGS) $< -o $@

# Build ELF file: Link all objects with corresponding Linking Flags,
# If Objects are not yet build ==> Build them using C & ASM Rules.
# List the size of each section as well as the total size.
$(ELF): $(OBJECTS)
	$(LD) $< $(LD_FLAGS) -o $@
	$(SZ) $@

# Generate the HEX file
$(BUILD_DIR)/%.hex: $(BUILD_DIR)/%.elf
	$(HEX) $< $@

# Generate the BINARY file
$(BUILD_DIR)/%.bin: $(BUILD_DIR)/%.elf
	$(BIN) $< $@

# Create the Build directory
$(BUILD_DIR):
	mkdir $@

#
# Build Process
##############################################################################

##############################################################################
# JLINK & Debug
#

# Phony Targets ==> No files will be created
.PHONY: startgdbserver stopgdbserver debug

startgdbserver:
	@pidof JLinkGDBServer > /dev/null || JLinkGDBServer -if swd -speed auto -device $(DEVICE)

stopgdbserver:
	@pidof JLinkGDBServer > /dev/null && killall JLinkGDBServer || true

debug: $(ELF) startgdbserver
	$(GDB) $(ELF)

#
# JLINK & Debug
##############################################################################

##############################################################################
# Dependencies
#



#
# Dependencies
##############################################################################

##############################################################################
# Clean
#

# Phony Target ==> No files will be created
.PHONY: clean

clean:
	rm -rf $(BUILD_DIR)

#
# Clean
##############################################################################
