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
#include <keymap_spanish.h>

#define SYM_SPC LT(_SYM, KC_SPC)
#define NAV_SPC LT(_NAV, KC_SPC)
#define RST_SPC LT(_RST, KC_SPC)

bool is_alt_tab_active = false;
uint16_t alt_tab_timer = 0;


// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _BASE,
    _SYM,
    _NAV,
    _RST
};

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
    QMKBEST = SAFE_RANGE,
    QMKURL
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT(
        //|--------+--------+--------+--------+--------+--------|
            KC_TAB,   KC_Q,    KC_W,    KC_E,    KC_R,   KC_T,
        //|--------+--------+--------+--------+--------+--------|
            KC_LSFT,  KC_A,    KC_S,    KC_D,    KC_F,   KC_G,
        //|--------+--------+--------+--------+--------+--------|
            KC_LCTL,  KC_Z,    KC_X,    KC_C,    KC_V,   KC_B,
        //|--------+--------+--------+--------+--------+--------+--------|
                               KC_NO,  KC_LALT, KC_LGUI, NAV_SPC,   SYM_SPC,
        //===============================================================|
        //===============================================================|
                    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,   KC_BSPC,
        //        |--------+--------+--------+--------+--------+--------|
                    KC_H,    KC_J,    KC_K,    KC_L,    KC_QUES,   KC_ENTER,
        //        |--------+--------+--------+--------+--------+--------|
                    KC_N,    KC_M,  KC_COMMA,  KC_DOT, KC_SLASH,   KC_RSFT,
        //|--------|--------+--------+--------+--------+--------+--------|
        SYM_SPC,    S(KC_LCTL),    KC_MENU,    KC_RALT,    KC_NO
        //|--------------------------------------------+
    ),
    [_SYM] = LAYOUT(
        //|--------+--------+--------+--------+--------+--------|
            KC_BSLS, KC_LEFT_CURLY_BRACE, KC_RIGHT_CURLY_BRACE, KC_LEFT_ANGLE_BRACKET, KC_RIGHT_ANGLE_BRACKET, KC_AT,
        //|--------+--------+--------+--------+--------+--------|
            KC_LSFT,  KC_LBRACKET,    KC_RBRACKET,    KC_COLON,    KC_SCOLON,   KC_HASH,
        //|--------+--------+--------+--------+--------+--------|
            KC_LCTL,  KC_LEFT_PAREN,    KC_RIGHT_PAREN,    KC_QUOT,    KC_GRV,   KC_TILDE,
        //|--------+--------+--------+--------+--------+--------+--------|
                               KC_NO,  KC_LALT, KC_LCTL, KC_NO,   SYM_SPC,
        //===============================================================|
        //===============================================================|
                    KC_7,    KC_8,    KC_9,    KC_MINUS,    KC_NO,   KC_BSPC,
        //        |--------+--------+--------+--------+--------+--------|
                    KC_4,    KC_5,    KC_6,    KC_PLUS,    ES_IQUE,   KC_ENTER,
        //        |--------+--------+--------+--------+--------+--------|
                    KC_1,    KC_2,    KC_3,    KC_EQL,    KC_UNDS,   KC_RSFT,
        //|--------|--------+--------+--------+--------+--------+--------|
        RST_SPC,    KC_0,    KC_NO,    KC_NO,    ES_NTIL
        //|--------------------------------------------+
    ),
    [_NAV] = LAYOUT(
        //|--------+--------+--------+--------+--------+--------|
            KC_ESC, KC_TAB, KC_GRV, KC_NO, KC_NO, KC_NO,
        //|--------+--------+--------+--------+--------+--------|
            KC_LSFT,  KC_NO,    KC_NO,    KC_NO,    KC_NO,   KC_NO,
        //|--------+--------+--------+--------+--------+--------|
            KC_LALT,  KC_NO,    KC_NO,    KC_NO,    KC_NO,   KC_NO,
        //|--------+--------+--------+--------+--------+--------+--------|
                               KC_NO,  KC_NO, KC_NO, KC_NO,   KC_NO,
        //===============================================================|
        //===============================================================|
                    KC_NO,    KC_NO,    KC_UP,  KC_NO,    KC_DEL, KC_BSPC,
        //        |--------+--------+--------+--------+--------+--------|
                    KC_NO,    KC_LEFT,    KC_DOWN,    KC_RIGHT,    KC_HOME,   KC_END,
        //        |--------+--------+--------+--------+--------+--------|
                    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,   KC_NO,
        //|--------|--------+--------+--------+--------+--------+--------|
        KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO
        //|--------------------------------------------+
    ),
    [_RST] = LAYOUT(
        //|--------+--------+--------+--------+--------+--------|
            KC_ESC, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        //|--------+--------+--------+--------+--------+--------|
            KC_LSFT,  KC_NO,    KC_NO,    KC_NO,    KC_NO,   KC_NO,
        //|--------+--------+--------+--------+--------+--------|
            KC_LCTL,  KC_NO,    KC_NO,    KC_NO,    KC_NO,   KC_NO,
        //|--------+--------+--------+--------+--------+--------+--------|
                               KC_NO,  KC_NO, KC_NO, KC_NO,   KC_NO,
        //===============================================================|
        //===============================================================|
                    KC_NO,    KC_NO,    KC_NO,  KC_NO,    RESET,   KC_NO,
        //        |--------+--------+--------+--------+--------+--------|
                    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,   KC_NO,
        //        |--------+--------+--------+--------+--------+--------|
                    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,   KC_NO,
        //|--------|--------+--------+--------+--------+--------+--------|
        KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO
        //|--------------------------------------------+
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

/*
    [_NAV] = LAYOUT(
        //|--------+--------+--------+--------+--------+--------|
            KC_ESC, KC_NO, KC_UP, KC_NO, KC_NO, KC_NO,
        //|--------+--------+--------+--------+--------+--------|
            KC_LSFT,  KC_NO,    KC_NO,    KC_NO,    KC_NO,   KC_NO,
        //|--------+--------+--------+--------+--------+--------|
            KC_LCTL,  KC_NO,    KC_NO,    KC_NO,    KC_NO,   KC_NO,
        //|--------+--------+--------+--------+--------+--------+--------|
                               KC_NO,  KC_NO, KC_NO, KC_NO,   KC_NO,
        //===============================================================|
        //===============================================================|
                    KC_NO,    KC_NO,    KC_NO,  KC_NO,    KC_NO,   KC_NO,
        //        |--------+--------+--------+--------+--------+--------|
                    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,   KC_NO,
        //        |--------+--------+--------+--------+--------+--------|
                    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,   KC_NO,
        //|--------|--------+--------+--------+--------+--------+--------|
        KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO
        //|--------------------------------------------+
    )
*/

bool encoder_left(bool clockwise) {
    switch(get_highest_layer(layer_state)) {
        case _BASE:
            if (!clockwise) {
                if (!is_alt_tab_active) {
                    is_alt_tab_active = true;
                    register_code(KC_LALT);
                }
                alt_tab_timer = timer_read();
                tap_code16(KC_TAB);
            } else {
                if (!is_alt_tab_active) {
                    is_alt_tab_active = true;
                    register_code(KC_LALT);
                }
                alt_tab_timer = timer_read();
                tap_code16(S(KC_TAB));
            }
            break;
        default:
            break;
    }
    return false;
}

bool encoder_right(bool clockwise) {
    switch(get_highest_layer(layer_state)) {
        case _BASE:
            tap_code16( clockwise ? LCTL(KC_TAB) : LCTL(LSFT(KC_TAB)));
            break;
        case _NAV:
            tap_code16( clockwise ? KC_WH_D : KC_WH_U);
        default:
            break;
    }
    return false;
}

bool custom_implementation(bool index, bool clockwise) {
    uint16_t held_keycode_timer = timer_read();
    if (index == 0) {
      encoder_left(clockwise);
    } else if (index == 1) {
      encoder_right(clockwise);
    }
    while (timer_elapsed(held_keycode_timer) < TAP_CODE_DELAY) {}
    return false;
}

bool encoder_update_user(uint8_t index, bool clockwise) {
    // uint16_t held_keycode_timer = timer_read();
    return custom_implementation(index, clockwise);
}

void matrix_scan_user(void) {
  if (is_alt_tab_active) {
    if (timer_elapsed(alt_tab_timer) > 700) {
      unregister_code(KC_LALT);
      is_alt_tab_active = false;
    }
  }
}