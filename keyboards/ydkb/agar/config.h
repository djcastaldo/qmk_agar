#pragma once

#include "config_common.h"

/* USB Device descriptor parameter */
#define FW_VER_DATE     DP1H
#define CONTACT(x,y)    x##y
#define CONTACT2(x,y)   CONTACT(x,y)
#define FW_VER          CONTACT2(VIAL_, FW_VER_DATE)
#define VENDOR_ID       0x9D5B
#define PRODUCT_ID      0x240B  // Agar specific
#define DEVICE_VER      0x0001
#define MANUFACTURER    KBDFans_YDKB
#define PRODUCT         Agar Keyboard (FW_VER)

#define USB_MAX_POWER_CONSUMPTION 350
#define WAIT_FOR_USB

/* key matrix size */
#define MATRIX_ROWS 14
#define MATRIX_COLS 8

#define SOFTWARE_ESC_BOOTLOADER

/* RGB configuration */
#define RGBLIGHT_EFFECT_BREATHING
#define RGBLIGHT_EFFECT_RAINBOW_MOOD
#define RGBLIGHT_EFFECT_RAINBOW_SWIRL
#define RGBLIGHT_EFFECT_SNAKE
#define RGBLIGHT_EFFECT_KNIGHT
#define RGBLIGHT_EFFECT_CHRISTMAS
#define RGBLIGHT_EFFECT_STATIC_GRADIENT
#define RGBLIGHT_EFFECT_RGB_TEST
#define RGBLIGHT_EFFECT_ALTERNATING
#define RGBLIGHT_EFFECT_TWINKLE
#define RGBLIGHT_DEFAULT_MODE 7 // default: RAINBOW_MOOD

#define RGBLIGHT_LIMIT_VAL 128
#define RGBLIGHT_SLEEP
#define RGB_DI_PIN B15
#define RGBLED_NUM 16

/* LED indicators configuration */
#define PHY_INDICATOR_NUM    1
#define INDICATOR_FUNCT    {(1<<USB_LED_CAPS_LOCK)}
#define RGB_EXTRA_PROCESS_ENABLE

/* Vial configuration */
#define DYNAMIC_KEYMAP_LAYER_COUNT    8
#define FLASH_KEYMAP_COUNT    2
#define VIAL_KEYBOARD_UID    {0x2E, 0xE6, 0x0E, 0x23, 0x34, 0xEF, 0x99, 0x37}

/* key combination for command */
#define IS_COMMAND() (get_mods() == (MOD_BIT(KC_LSHIFT) | MOD_BIT(KC_RSHIFT))) || (get_mods() == (MOD_BIT(KC_LSHIFT) | MOD_BIT(KC_LCTRL) | MOD_BIT(KC_RSHIFT)))