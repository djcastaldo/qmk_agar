# Project specific files
SRC ?= matrix.c led.c

# MCU name
MCU = STM32F103
BOARD = MAPLEMINI_STM32_F103

# Bootloader selection
BOOTLOADER = custom

# Linker script - Note: we specify the full path from the qmk root
MCU_LDSCRIPT_PATH = $(KEYBOARD)/ld
MCU_LDSCRIPT = STM32F103CBT6_uf2_bootloader

# Build Options
CUSTOM_MATRIX = yes        # Custom matrix file
UNICODE_ENABLE = yes       # Unicode
BOOTMAGIC_ENABLE = no     # Enable Bootmagic Lite
MOUSEKEY_ENABLE = yes     # Mouse keys
EXTRAKEY_ENABLE = yes     # Audio control and System control
COMMAND_ENABLE = yes      # Commands for debug and configuration
NKRO_ENABLE = yes        # Enable N-Key Rollover
BACKLIGHT_ENABLE = no    # Enable keyboard backlight functionality
RGBLIGHT_ENABLE = yes    # Enable keyboard RGB underglow
AUDIO_ENABLE = no        # Audio output
SLEEP_LED_ENABLE = no

# ChibiOS specific options
OPT_DEFS += -DCORTEX_ENABLE_WFI_IDLE=TRUE
OPT_DEFS += -DCORTEX_VTOR_INIT=0x4000

# Include the YDKB directory for shared header files
VPATH += keyboards/ydkb