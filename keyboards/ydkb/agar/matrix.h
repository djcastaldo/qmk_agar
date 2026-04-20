#pragma once

#include <stdint.h>
#include <stdbool.h>
#include "quantum.h"  // for matrix_row_t

// Function declarations for shared functions
void hook_keyboard_loop(void);
void enter_bootloader(void);
void rgb_extra_process(LED_TYPE *rgbled);


// Core matrix API (required by QMK core)
void matrix_init(void);
uint8_t matrix_scan(void);
matrix_row_t matrix_get_row(uint8_t row);

// Optional / commonly expected helpers
bool matrix_is_on(uint8_t row, uint8_t col);
void matrix_print(void);
uint8_t matrix_key_count(void);

// Custom helper from your implementation
bool should_process_keypress(void);

// Weak hooks (already defined in your .c, but good to expose)
void matrix_scan_user(void);
void matrix_scan_kb(void);

// Bootmagic + early init (used elsewhere in QMK sometimes)
void bootmagic_lite(void);
void early_hardware_init_pre(void);
