#include QMK_KEYBOARD_H

#include "print.h"

layer_state_t layer_state_set_user(layer_state_t state) {
    if ((state & 0b0000110) == 0b0000110) {
        state |= 0b0001000;
    } else {
        state &= ~0b0001000;
    }
    if ((state & 0b0110000) == 0b0110000) {
        state |= 0b1000000;
    } else {
        state &= ~0b1000000;
    }
#ifdef CONSOLE_ENABLE
    uprintf("layer: %04X\n", state);
#endif
    return state;
}
