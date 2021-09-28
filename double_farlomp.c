/* Copyright 2021 FrancoAccifonte
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

#include "double_farlomp.h"

bool encoder_update(uint8_t index, bool clockwise) {
    uint16_t held_keycode_timer = timer_read();
    if (index == 0) { /* First encoder */
        if (clockwise) {
            tap_code(KC_A);
            while (timer_elapsed(held_keycode_timer) < TAP_CODE_DELAY) {
            }
        } else {
            tap_code(KC_B);
            while (timer_elapsed(held_keycode_timer) < TAP_CODE_DELAY) {
            }
        }
    } else if (index == 1) { /* Second encoder */
        if (clockwise) {
            tap_code(KC_C);
            while (timer_elapsed(held_keycode_timer) < TAP_CODE_DELAY) {
            }
        } else {
            tap_code(KC_D);
            while (timer_elapsed(held_keycode_timer) < TAP_CODE_DELAY) {
            }
        }
    }
    return false;
}

bool encoder_update_kb(uint8_t index, bool clockwise) {
    return encoder_update(index, clockwise);
}

bool encoder_update_user(uint8_t index, bool clockwise) {
    return encoder_update(index, clockwise);
}