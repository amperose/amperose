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
LDSCRIPT = src/STM32F767VITx.ld

# C sources that can be compiled in ARM or THUMB mode
C_SOURCES = \
	drivers/STM32F7xx_HAL_Driver/Src/ \
		stm32f7xx_hal_cortex.c \
		stm32f7xx_hal_pwr_ex.c \
		stm32f7xx_hal_flash_ex.c \
		stm32f7xx_hal_rcc_ex.c \
		stm32f7xx_hal_gpio.c \
		stm32f7xx_hal_dma_ex.c \
		stm32f7xx_hal_dma.c \
		stm32f7xx_hal_flash.c \
		stm32f7xx_hal.c \
		stm32f7xx_hal_rcc.c \
		stm32f7xx_hal_pwr.c \
	drivers/Initialization/Src/ \
		stm32f7xx_it.c \
		stm32f7xx_hal_msp.c \
		stm32f7xx_system_clock.c \
		system_stm32f7xx.c \
	src/ \
		board.c \
		error_handler.c \
		SEGGER_RTT.c \
		SEGGER_RTT_printf.c \
		rtt.c \
		main.c

# C Includes
C_INCLUDES = \
	-Iconfig \
	-Iinclude \
	-Idrivers/Initialization/Inc \
	-Idrivers/STM32F7xx_HAL_Driver/Inc \
	-Idrivers/STM32F7xx_HAL_Driver/Inc/Legacy \
	-Idrivers/CMSIS/Device/ST/STM32F7xx/Include \
	-Idrivers/CMSIS/Include

# C defines
C_DEFS =  \
	-DUSE_HAL_DRIVER \
	-DSTM32F767xx \
	-DUSE_FULL_ASSERT

# ASM sources
AS_SOURCES = src/startup_stm32f767xx.s

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

# Common Flags
COMMON = -mcpu=$(MCU) -mthumb

# C Flags
C_WARN   = -Wall -Werror -Wextra -Wundef -Wstrict-prototypes
C_OPTS   = -O2 -ggdb -fomit-frame-pointer -falign-functions=16
C_STD 	 = -std=gnu11

C_FLAGS  = $(COMMON) $(C_OPTS) $(C_WARN) $(C_STD) $(C_INCLUDES) $(C_DEFS)

# ASM Flags
AS_FLAGS = $(COMMON) $(AS_INCLUDES)

# LD Flags
LD_FLAGS = $(COMMON) -T$(LDSCRIPT) -lc -lm -lnosys

#
# Compilation Options
##############################################################################

##############################################################################
# Build Process
#

# Default Target : ELF - HEX - BIN
all: $(ELF) $(BUILD_DIR)/$(PROJECT).hex $(BUILD_DIR)/$(PROJECT).bin

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
$(BUILD_DIR)/%.o: %.c | $(BUILD_DIR)
	@echo "Building $@"
	@$(CC) -c $(C_FLAGS) $< -o $@

# Build ASM Objects
$(BUILD_DIR)/%.o: %.s | $(BUILD_DIR)
	@echo "Building $@"
	@$(AS) -c $(AS_FLAGS) $< -o $@

# Build ELF file: Link all objects with corresponding Linking Flags,
# If Objects are not yet build ==> Build them using C & ASM Rules.
# List the size of each section as well as the total size.
$(ELF): $(OBJECTS) | $(BUILD_DIR)
	@echo "Building the application $@"
	@$(LD) $(OBJECTS) $(LD_FLAGS) -o $@
	$(SZ) $@

# Generate the HEX file
$(BUILD_DIR)/%.hex: $(BUILD_DIR)/%.elf | $(BUILD_DIR)
	@echo "Generating hexadecimal output file $@"
	@$(HEX) $< $@

# Generate the BINARY file
$(BUILD_DIR)/%.bin: $(BUILD_DIR)/%.elf | $(BUILD_DIR)
	@echo "Generating binary output file $@"
	@$(BIN) $< $@

# Create the Build directory
$(BUILD_DIR):
	@echo "Creating $(BUILD_DIR) Directory"
	@mkdir $@

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
	@echo "Cleaning ..."
	@echo "Remove $(BUILD_DIR) directory"
	@rm -rf $(BUILD_DIR)

#
# Clean
##############################################################################
