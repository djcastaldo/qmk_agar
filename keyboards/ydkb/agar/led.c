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
#include "color.h"
#include "rgblight.h"

#include "stdint.h"
#include "quantum.h"
#include "timer.h"
#include "wait.h"

#ifndef LOGIC_INDICATOR_NUM
#define LOGIC_INDICATOR_NUM PHY_INDICATOR_NUM
#endif

extern rgblight_config_t rgblight_config;
extern bool is_ver5020;
extern bool is_sc_leds_mcu;
LED_TYPE rgbled[PHY_INDICATOR_NUM + RGBLED_NUM];

__attribute__((weak)) bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    return true;
}
__attribute__((weak)) void rgb_extra_process(LED_TYPE *rgbled) {
    // default no-op
}

void rgblight_call_driver(LED_TYPE *start_led, uint8_t num_leds) {
    // Clear indicator LEDs first
    memset(rgbled, 0, sizeof(rgbled));

    uint8_t count = num_leds > RGBLED_NUM ? RGBLED_NUM : num_leds;
    memcpy(&rgbled[PHY_INDICATOR_NUM], start_led, count * sizeof(LED_TYPE));

#ifdef RGB_EXTRA_PROCESS_ENABLE
    rgb_extra_process(rgbled);
#endif

    ws2812_setleds(rgbled, PHY_INDICATOR_NUM + RGBLED_NUM);
}

bool process_record_kb(uint16_t keycode, keyrecord_t *record) {
    return process_record_user(keycode, record);
}

void enter_bootloader(void) {
    clear_keyboard();
    volatile uint32_t *uf2bl_backup_reg = (uint32_t *)0x20004000;
    *uf2bl_backup_reg                   = 0x9d5bfc2bUL;
    NVIC_SystemReset();
}

bool command_extra(uint8_t code) {
    uint8_t pressed_mods = get_mods();
    clear_keyboard();
    switch (code) {
        case KC_B:
            wait_us(500 * 1000);
            if (pressed_mods & MOD_BIT(KC_LCTRL)) {
                enter_bootloader();
            }
            NVIC_SystemReset();
            break;
        default:
            return false;
    }
    return true;
}

void restart_usb_driver(USBDriver *usbp) {
    NVIC_SystemReset();
}

__attribute__((weak)) void hook_keyboard_loop(void) {}
