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
#include QMK_KEYBOARD_H



#define SYM_SPC LT(_SYM, KC_SPC)




// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _BASE,
    _SYM
};

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
    QMKBEST = SAFE_RANGE,
    QMKURL
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Base */
    [_BASE] = LAYOUT(
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_TAB,   KC_Q,    KC_W,    KC_E,    KC_R,   KC_T,                          KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,   KC_BSPACE,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_LSFT,  KC_A,    KC_S,    KC_D,    KC_F,   KC_G,                          KC_H,    KC_J,    KC_K,    KC_L,    KC_L,   KC_ENTER,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_LCTL,  KC_Z,    KC_X,    KC_C,    KC_V,   KC_B,                          KC_N,    KC_M,  KC_COMMA,  KC_DOT, KC_SLASH,   KC_RSFT,
    //|--------+--------+--------+--------+--------+--------+--------|  |--------|--------+--------+--------+--------+--------+--------|
                          KC_NO,   KC_LALT, KC_LCTL,  KC_NO,   SYM_SPC,   SYM_SPC,    KC_NO,    KC_RCTL,    KC_RALT,    KC_NO
                      //+--------------------------------------------|  |--------------------------------------------+
    ),
    [_SYM] = LAYOUT(
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_TAB, KC_LEFT_CURLY_BRACE, KC_RIGHT_CURLY_BRACE, KC_E, KC_R, KC_T, KC_KP_7,    KC_KP_8,    KC_KP_9,    KC_KP_MINUS,    RESET,   KC_BSPACE,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_LSFT,  KC_LBRACKET,    KC_RBRACKET,    KC_D,    KC_F,   KC_G,                          KC_KP_4,    KC_KP_5,    KC_KP_6,    KC_KP_PLUS,    KC_L,   KC_ENTER,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_LCTL,  KC_LEFT_PAREN,    KC_RIGHT_PAREN,    KC_C,    KC_V,   KC_B,                          KC_KP_1,    KC_KP_2,    KC_KP_3,    KC_V,    KC_B,   KC_RSFT,
    //|--------+--------+--------+--------+--------+--------+--------|  |--------|--------+--------+--------+--------+--------+--------|
                           KC_0,   KC_LALT,  KC_2,    KC_3,   SYM_SPC,   SYM_SPC,    KC_0,    KC_6,    KC_7,    KC_8
                      //+--------------------------------------------|  |--------------------------------------------+
    )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case QMKBEST:
            if (record->event.pressed) {
                // when keycode QMKBEST is pressed
                SEND_STRING("QMK is the best thing ever!");
            } else {
                // when keycode QMKBEST is released
            }
            break;
        case QMKURL:
            if (record->event.pressed) {
                // when keycode QMKURL is pressed
                SEND_STRING("https://qmk.fm/\n");
            } else {
                // when keycode QMKURL is released
            }
            break;
    }
    return true;
}
