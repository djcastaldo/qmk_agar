/* Copyright 2016 Jack Humbert
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifdef LEADER_ENABLE

#    include "process_leader.h"
#    include <string.h>

#    ifndef LEADER_TIMEOUT
#        define LEADER_TIMEOUT 300
#    endif

#ifdef CONSOLE_ENABLE
#  include "print.h"
#endif
#define DBG_LEADER(...) uprintf("[LEADER] " __VA_ARGS__)

__attribute__((weak)) void leader_start_user(void) {}
__attribute__((weak)) void leader_start(void) {
    leader_start_user();
}
__attribute__((weak)) void leader_end(void) {}

void qk_leader_end(void);

// Leader key stuff
bool     leading     = false;
uint16_t leader_time = 0;

uint16_t leader_sequence[5]   = {0, 0, 0, 0, 0};
uint8_t  leader_sequence_size = 0;

void qk_leader_start(void) {
    DBG_LEADER("START leading=%d size=%d\n", leading, leader_sequence_size);
    if (leading) {
        return;
    }



    leader_start();
    leading              = true;
    leader_sequence_size = 0;
    memset(leader_sequence, 0, sizeof(leader_sequence));
    
    DBG_LEADER("AFTER START leading=%d size=%d seq0=%d\n",
        leading, leader_sequence_size, leader_sequence[0]);
}

bool process_leader(uint16_t keycode, keyrecord_t *record) {
    // Leader key set-up
    if (record->event.pressed) {
        DBG_LEADER("PROCESS keycode=%d leading=%d size=%d timeout=%d\n",
            keycode,
            leading,
            leader_sequence_size,
            timer_elapsed(leader_time));
        if (leading) {
            #ifndef LEADER_NO_TIMEOUT
            if (leader_sequence_size > 0 && timer_elapsed(leader_time) > LEADER_TIMEOUT) {
                DBG_LEADER("PROCESS TIMEOUT → END\n");
                qk_leader_end();
                return true;
            }
            #endif

            {
#    ifndef LEADER_KEY_STRICT_KEY_PROCESSING
                if ((keycode >= QK_MOD_TAP && keycode <= QK_MOD_TAP_MAX) || (keycode >= QK_LAYER_TAP && keycode <= QK_LAYER_TAP_MAX)) {
                    keycode = keycode & 0xFF;
                }
#    endif // LEADER_KEY_STRICT_KEY_PROCESSING
                if (leader_sequence_size < (sizeof(leader_sequence) / sizeof(leader_sequence[0]))) {

                    // 🔥 START TIMER ONLY ON FIRST KEY
                    if (leader_sequence_size == 0) {
                        leader_time = timer_read();
                        DBG_LEADER("FIRST KEY → starting timer\n");
                    }

                    leader_sequence[leader_sequence_size] = keycode;
                    leader_sequence_size++;

                    DBG_LEADER("APPEND idx=%d key=%d\n", leader_sequence_size - 1, keycode);
                } else {
                    // IMPORTANT: preserve QMK semantics
                    // call end hook first, then flip state
                    qk_leader_end();
                    DBG_LEADER("END PATH leading=%d size=%d seq0=%d\n",
                        leading,
                        leader_sequence_size,
                        leader_sequence[0]);
                    return true;
                }
#    ifdef LEADER_PER_KEY_TIMING
                leader_time = timer_read();
#    endif
                return false;
            }
        } else {
            if (keycode == KC_LEAD) {
                qk_leader_start();
            }
        }
    }
    return true;
}
// Ensure proper teardown ordering is handled elsewhere (timeout path)
// If leader is ending due to timeout, enforce same ordering:
void qk_leader_end(void) {
    leader_end();
    leading = false;
    leader_sequence_size = 0;
}

void leader_task(void) {
    if (leading && leader_sequence_size > 0 && timer_elapsed(leader_time) > LEADER_TIMEOUT) {
        DBG_LEADER("TASK TIMEOUT HIT\n");
        qk_leader_end();
    }
}

#endif
