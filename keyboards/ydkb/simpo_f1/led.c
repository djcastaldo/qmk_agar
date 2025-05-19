/*
Copyright 2023 YANG <drk@live.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "hal.h"
#include "ch.h"
#include "led.h"
#include "rgblight.h"

#include "stdint.h"
#include "quantum.h"

extern rgblight_config_t rgblight_config;
static LED_TYPE RGBLIGHT_COLOR_OFF = { .r = 0, .g = 0, .b = 0 };
uint8_t indicator_state = 0;

uint8_t indicator_color_config[3];
LED_TYPE indicator_color[3];

void rgblight_call_driver(LED_TYPE *start_led, uint8_t num_leds) {
#ifdef RGB_MATRIX_ENABLE
    return;
#endif

}

void led_set_user(uint8_t usb_led)
{
#ifdef RGB_MATRIX_ENABLE
    if (rgb_matrix_config.enable == 0) {
        rgb_matrix_indicators_user();
    }
    return;
#endif
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    static uint8_t mod_keys_registered;
    uint8_t pressed_mods = get_mods();
    switch (keycode) {
        case 0x5c00: // via/vial reset to bootloader
            if (record->event.pressed) {
                clear_keyboard();
                volatile uint32_t *uf2bl_backup_reg = (uint32_t*)0x20004000;
                *uf2bl_backup_reg = 0x9d5bfc2bUL;
                NVIC_SystemReset();
            }
            return false;
        // 0x5f8f for Alt+Esc=f4 and RShift+Esc=~
        case 0x5F8F:
            if (record->event.pressed) {
                if ((pressed_mods & MOD_BIT(KC_RSHIFT)) && (~pressed_mods & MOD_BIT(KC_LCTRL))) {
                    mod_keys_registered = KC_GRV;
                } else if (pressed_mods & MOD_BIT(KC_LALT)) {
                    mod_keys_registered = KC_F4;
                } else {
                    mod_keys_registered = KC_ESC;
                }
                register_code(mod_keys_registered);
                send_keyboard_report();
            } else {
                unregister_code(mod_keys_registered);
                send_keyboard_report();
            }
            return false;
        default:
            return true; // Process all other keycodes normally
    }
}

void enter_bootloader(void) {
    clear_keyboard();
    volatile uint32_t *uf2bl_backup_reg = (uint32_t*)0x20004000;
    *uf2bl_backup_reg = 0x9d5bfc2bUL;
    NVIC_SystemReset();
}
/* LShift+RShift+LCtrl+B to Bootloader */
#include "command.h"

bool command_extra(uint8_t code)
{
    uint8_t pressed_mods = get_mods();
    clear_keyboard();
    switch (code) {
        case KC_B:
            ;
            wait_us(500*1000);
            if (pressed_mods & MOD_BIT(KC_LCTRL)) {
                enter_bootloader();
            }
            //soft reset
            NVIC_SystemReset();
            //*(uint32_t *)(0xE000ED0CUL) = 0x05FA0000UL | (*(uint32_t *)(0xE000ED0CUL) & 0x0700) | 0x04;
            break;
        default:
            return false;   // yield to default command
    }
    return true;
}


void restart_usb_driver(USBDriver *usbp) {
    NVIC_SystemReset();
}

void user_config_update(void)
{
    static const uint8_t indicator_hue_preset[8] = {0, 21, 42, 85, 127, 170, 212, 255};
    #ifdef INDICATOR_VAL
    static uint8_t val = INDICATOR_VAL;
    #else 
    static uint8_t val = 255;
    #endif

    static uint16_t last_value = 0xffff;
    uint16_t new_value = eeprom_read_word((void *)(VIA_EEPROM_LAYOUT_OPTIONS_ADDR));
    if (new_value != last_value) {
        last_value = new_value;
        for (uint8_t i=0; i<3; i++) {
            indicator_color_config[i] = (new_value & 0b111);
            uint8_t hue = indicator_hue_preset[ indicator_color_config[i] ];
            new_value >>= 3;
            if (hue == 255) indicator_color[i] = (LED_TYPE){val/2, val/2, val/2};
            else            indicator_color[i] = hsv_to_rgb((HSV){hue, 255, val});
            xprintf("\n indicator %d R: %d, G: %d, B:%d", i, indicator_color[i].r, indicator_color[i].g, indicator_color[i].b);
        }
    }
}

//rgblight welcome
extern rgblight_config_t rgblight_config;
extern bool is_rgblight_initialized;
extern LED_TYPE led[];
void hook_keyboard_loop(void)
{
    static uint16_t one_second_timer = 0;
    if (one_second_timer != timer_read() && timer_elapsed(one_second_timer) >= 1000) {
        one_second_timer = timer_read();
        user_config_update();
    }
#ifndef WELCOME_LIGHT
    return;
#endif
}

// Snap Tap / SOCD
static const uint8_t SOCD_KEY[2][2] = {
    { KC_W, KC_S },
    { KC_A, KC_D }
};

bool socd_key_state[2][2] = { {0,0},{0,0}};

void post_process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (keycode >= USER00 && keycode <= USER03) {
        uint8_t key = keycode - USER00;
        uint8_t k_group = key&1;
        uint8_t k_num = key>>1;
        uint8_t k_op_num = k_num?0:1;
        if (record->event.pressed) {
            socd_key_state[k_group][k_num] = 1;
            if (socd_key_state[k_group][k_op_num]) {
                unregister_code(SOCD_KEY[k_group][k_op_num]);
            }
            register_code(SOCD_KEY[k_group][k_num]);
        } else {
            socd_key_state[k_group][k_num] = 0;
            unregister_code(SOCD_KEY[k_group][k_num]);
            if (socd_key_state[k_group][k_op_num]) {
                register_code(SOCD_KEY[k_group][k_op_num]);
            }
        }
    }
}
