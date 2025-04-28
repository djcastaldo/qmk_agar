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
#include "quantum.h"
#include "timer.h"
#include "wait.h"

extern bool is_ver5020;
extern bool is_sc_leds_mcu;

// Just turn on the LED
void single_color_indicator_set(uint8_t index, bool on)
{
    if (index == 0) {
        if (on) palSetPad(GPIOB, 14);
        else palClearPad(GPIOB, 14);
    }
}

void led_init_kb(void) {
    // Set LED on at startup - pure test
    palSetPadMode(GPIOB, 14, PAL_MODE_OUTPUT_PUSHPULL);
    palSetPad(GPIOB, 14);
}

void led_set_user(uint8_t usb_led)
{
    // Keep LED on regardless of state
    single_color_indicator_set(0, true);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    return true;
}

void enter_bootloader(void) {
    clear_keyboard();
    volatile uint32_t *uf2bl_backup_reg = (uint32_t*)0x20004000;
    *uf2bl_backup_reg = 0x9d5bfc2bUL;
    NVIC_SystemReset();
}

bool command_extra(uint8_t code) {
    uint8_t pressed_mods = get_mods();
    clear_keyboard();
    switch (code) {
        case KC_B:
            wait_us(500*1000);
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

void hook_keyboard_loop(void) {
    // Keep LED on
    single_color_indicator_set(0, true);
}