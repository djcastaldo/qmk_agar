#pragma once

#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID       0x9D5B
#define PRODUCT_ID      0x240B  // Agar specific
#define DEVICE_VER      0x0001
#define MANUFACTURER    KBDFans_YDKB
#define PRODUCT         Agar Keyboard

#define USB_MAX_POWER_CONSUMPTION 350
#define WAIT_FOR_USB

/* key matrix size */
#define MATRIX_ROWS 14
#define MATRIX_COLS 8

#define SOFTWARE_ESC_BOOTLOADER



/* LED indicators configuration */
#define PHY_INDICATOR_NUM    1
#define INDICATOR_FUNCT    {(1<<USB_LED_CAPS_LOCK)}
#define WELCOME_LIGHT       // Enable welcome light effect



/* key combination for command */
#define IS_COMMAND() (get_mods() == (MOD_BIT(KC_LSHIFT) | MOD_BIT(KC_RSHIFT))) || (get_mods() == (MOD_BIT(KC_LSHIFT) | MOD_BIT(KC_LCTRL) | MOD_BIT(KC_RSHIFT)))