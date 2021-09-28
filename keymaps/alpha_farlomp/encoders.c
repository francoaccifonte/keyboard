#include "enums.h"

bool encoder_left(bool clockwise) {
    switch(get_highest_layer(layer_state)) {
        case _BASE:
            //clockwise ? LALT(KC_TAB) : LALT(LSFT(KC_TAB))
            tap_code(KC_B);
            break;
        default:
            break;
    return false;
    }
}

bool custom_implementation(bool index, bool clockwise) {
    uint16_t held_keycode_timer = timer_read();
    if (index == 0) {
      encoder_left(clockwise);
    } else if (index == 1) {
      //
    }
    while (timer_elapsed(held_keycode_timer) < TAP_CODE_DELAY) {}
    return false;
}