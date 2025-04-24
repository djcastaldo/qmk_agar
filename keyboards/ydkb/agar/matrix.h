#pragma once

#include <stdint.h>
#include <stdbool.h>

// Function declarations for shared functions
void hook_keyboard_loop(void);
void enter_bootloader(void);
void rgb_extra_process(void *rgbled);