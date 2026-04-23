#pragma once

#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID 0x9D5B
#define PRODUCT_ID 0x240B // Agar specific
#define DEVICE_VER 0x0001
#define MANUFACTURER KBDFans_YDKB
#define PRODUCT Agar Keyboard

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
//#define RGBLIGHT_DEFAULT_MODE 7 // default: RAINBOW_MOOD

#define RGBLIGHT_LIMIT_VAL 128
#define RGBLIGHT_SLEEP
#define RGB_DI_PIN B15
#define RGBLED_NUM 16

/* LED indicators configuration */
#define PHY_INDICATOR_NUM 1
#define INDICATOR_FUNCT {(1 << USB_LED_CAPS_LOCK)}
#define RGB_EXTRA_PROCESS_ENABLE
#define WELCOME_LIGHT // Enable welcome light effect

/* key combination for command */
//#define IS_COMMAND() (get_mods() == (MOD_BIT(KC_LSHIFT) | MOD_BIT(KC_LCTRL) | MOD_BIT(KC_RSHIFT)))

// ~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~
// djc: defaults above.  my own stuff below
// ~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~
#    define DEBOUNCE_TYPE none
#    define DOUBLE_CLICK_FIX_MS 12
#    define DEBOUNCE_DN 4
#    define DEBOUNCE_NK 1
#    define DEBOUNCE_UP 4
/* rgb settings */
#    define RGB_DI_PIN B15
#    define RGBLIGHT_DEFAULT_MODE RGBLIGHT_MODE_STATIC_LIGHT
#    define RGB_MATRIX_DEFAULT_MODE 0
#    define RGB_MATRIX_DEFAULT_HUE 100
#    define RGB_MATRIX_DEFAULT_SAT 255
#    define RGB_MATRIX_DEFAULT_VAL 128
#    define RGB_MATRIX_DEFAULT_SPD 70
/* force enable NKRO */
#    define FORCE_NKRO
/* oneshot no timeout */
#    define ONESHOT_TIMEOUT 0

/* increase layer count above the default of 5 */
#    define DYNAMIC_KEYMAP_LAYER_COUNT 19

/* include layers that are not used on all keyboards */
#    define CONFIG_HAS_FKEY_LAYR

/* tap time for tap dancing */
#    define TAPPING_TERM 250
#    define TAPPING_TERM_PER_KEY

/* enable caps word when both shift keys are tapped */
//#    define BOTH_SHIFTS_TURNS_ON_CAPS_WORD // setup in userspace for Agar

/* do not allow dynamic macros to nest (can cause infinite loop) */
#    define DYNAMIC_MACRO_NO_NESTING

/* allow setting constant mode mouse cursor and wheel speeds */
#    define MK_3_SPEED
#    define MK_C_OFFSET_0 1
#    define MK_C_INTERVAL_0 6
#    define MK_C_OFFSET_1 4
#    define MK_C_INTERVAL_1 8

/* leader key settings */
#    define LEADER_TIMEOUT 250
#    define LEADER_PER_KEY_TIMING
/* do not use LEADER_NO_TIMEOUT with this qmk version; core was already modified for the same functionality */

/* for various delays */
#    define TMUX_DELAY 25
#    define CONFIG_VS_LAYR_SEND_STRING_DELAY 35
#    define CONFIG_RDP_DELAY_KEY 15    // ms between key press/release
#    define CONFIG_RDP_DELAY_MOD 20    // ms for modifiers

/* monitored base layers for macos */
#    define CONFIG_MACOS_BASE_LAYERS { MAC_BASE }
#    define CONFIG_MACOS_BASE_LAYERS_COUNT 1
#    define CONFIG_DEFAULT_MAC_LAYR MAC_BASE
#    define CONFIG_DEFAULT_WIN_LAYR WIN_BASE

/* monitored base layers */
#    define CONFIG_ALL_BASE_LAYERS { MAC_BASE, WIN_BASE }
#    define CONFIG_ALL_BASE_LAYERS_COUNT 2
/* key indexes that changed to shifted version when caps is used */

/* rgb_matrix_indicators_advanced_user settings */
#    define CONFIG_KEY_INDEX_MAX 16

// single indicator config
#    define CONFIG_RGB_LAYER_INDICATORS { I_INDICATOR }
#    define CONFIG_RGB_LAYER_INDICATORS_COUNT 1

// layer settings
#    define CONFIG_HAS_TMUX_LAYR_NAV

// more indicator settings (in GRB)
#    define CONFIG_BASE_LAYR_COLOR     10,  10,  10   // dim white
#    define CONFIG_FN_LAYR_COLOR      255,   0,   0   // RGB_GREEN
#    define CONFIG_MREC_KEY_COLOR       0, 255, 255   // RGB_MAGENTA
#    define CONFIG_SHIFT_LAYR_COLOR   165, 255,   0   // RGB_ORANGE
#    define CONFIG_SHIFTB_LAYR_COLOR  200, 255, 128   // very soft peach 
#    define CONFIG_KCTL_LAYR_COLOR      0, 255,   0   // RGB_RED
#    define CONFIG_TMUX_LAYR_COLOR    255,   0, 255   // RGB_CYAN
#    define CONFIG_TMUXB_LAYR_COLOR   255, 128, 200   // very pale cyan
#    define CONFIG_VS_LAYR_COLOR        0, 128, 128   // RGB_PURPLE
#    define CONFIG_SYM_LAYR_COLOR       0,   0, 255   // RGB_BLUE
#    define CONFIG_WIDE_LAYR_COLOR    208,  64, 224   // RGB_TURQUOISE
#    define CONFIG_CIRC_LAYR_COLOR    127, 255,  80   // RGB_CORAL
#    define CONFIG_EMO_LAYR_COLOR       0, 128, 128   // RGB_PURPLE
#    define CONFIG_LEADER_COLORA      208,  64, 224   // RGB_TURQUOISE
#    define CONFIG_LEADER_COLORB      255,   0, 255   // RGB_CYAN
#    define CONFIG_FKEY_LAYR_COLOR    255, 255, 255   // RGB_WHITE
#    define CONFIG_DEFUALT_LAYR_COLOR  10,  10,  10   // dim white
#    define CONFIG_EXTRA_BASE_LAYR_COLORS_COUNT 0
#    define CONFIG_CAPS_WORD_SHIFT_COLOR 0x77,0x77,0x77

#    define CONFIG_EEPROM_RESET_DEFAULT_LAYER WIN_BASE

#    define CONFIG_LOCK_ANIMATION 0
#    define CONFIG_LOCK_ANIMATION_TIMEOUT 30000

/* custom sleep setup */
#    define CONFIG_CUSTOM_SLEEP_TIMEOUT 540000
#    define CONFIG_CUSTOM_SLEEP_WARNING 5000
#    define CONFIG_CUSTOM_BLINK_INTERVAL 250

// for key sequnece processing
#    define CONFIG_MAX_SEQ_QUEUE 3
