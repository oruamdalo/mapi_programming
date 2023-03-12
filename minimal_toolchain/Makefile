#Folders
SRC_DIR = src
SUP_DIR = startup
OUT_DIR = debug

BOARD = stm32f303xc

TARGET = main

# Define the linker script location and chip architecture.
LD_SCRIPT = $(SUP_DIR)/linker_script.ld
MCU_SPEC  = cortex-m4

# Toolchain for Linux
# CC = arm-none-eabi-gcc

# Toolchain definitions (ARM bare metal defaults) - IF ON LINUX COMMENT
TOOLCHAIN = C:\gccarm
CC = $(TOOLCHAIN)\bin\arm-none-eabi-gcc
AS = $(TOOLCHAIN)\bin\arm-none-eabi-as
LD = $(TOOLCHAIN)\bin\arm-none-eabi-ld
OC = $(TOOLCHAIN)\bin\arm-none-eabi-objcopy
OD = $(TOOLCHAIN)\bin\arm-none-eabi-objdump
OS = $(TOOLCHAIN)\bin\arm-none-eabi-size

# Assembly directives.
ASFLAGS += -c
ASFLAGS += -O0
ASFLAGS += -mcpu=$(MCU_SPEC)
ASFLAGS += -mthumb
ASFLAGS += -Wall
# (Set error messages to appear on a single line.)
ASFLAGS += -fmessage-length=0

# C compilation directives
CFLAGS += -mcpu=$(MCU_SPEC)
CFLAGS += -mthumb
CFLAGS += -Wall
CFLAGS += -g
# (Set error messages to appear on a single line.)
CFLAGS += -fmessage-length=0
# (Set system to ignore semihosted junk)
CFLAGS += --specs=nosys.specs

# Linker directives.
LSCRIPT = ./$(LD_SCRIPT)
LFLAGS += -mcpu=$(MCU_SPEC)
LFLAGS += -mthumb
LFLAGS += -Wall
LFLAGS += --specs=nosys.specs
LFLAGS += -nostdlib
LFLAGS += -lgcc
LFLAGS += -T$(LSCRIPT)

STARTUP_SRC = $(SUP_DIR)\startup_$(BOARD).s
C_SRC    = $(SRC_DIR)\main.c

OBJS =  $(STARTUP_SRC:.s=.o)
OBJS += $(C_SRC:.c=.o)

INCLUDE = -I./
INCLUDE += -I./lib

.PHONY: all
all: $(OUT_DIR)\$(TARGET).bin

%.o: %.s
	$(CC) -x assembler-with-cpp $(ASFLAGS) $< -o $@

%.o: %.c
	$(CC) -c $(CFLAGS) $(INCLUDE) $< -o $@

$(OUT_DIR)\$(TARGET).elf: $(OBJS)
	$(CC) $^ $(LFLAGS) -o $@

$(OUT_DIR)\$(TARGET).bin: $(OUT_DIR)\$(TARGET).elf
	$(OC) -S -O binary $< $@
	$(OS) $<

.PHONY: clean
# Windows
clean:
	del $(SUP_DIR)\startup_$(BOARD).o
	del $(OUT_DIR)\$(TARGET).elf
	del $(SRC_DIR)\$(TARGET).o
	del $(OUT_DIR)\$(TARGET).bin

# Linux
# clean:
#   rm $(SUP_DIR)/startup_$(BOARD).o
#   rm $(OUT_DIR)/$(TARGET).elf
#   rm $(SRC_DIR)/$(TARGET).o
#	rm $(OUT_DIR)/$(TARGET).bin