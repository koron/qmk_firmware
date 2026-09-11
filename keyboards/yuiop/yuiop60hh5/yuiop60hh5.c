/*
Copyright 2022 MURAOKA Taro (aka KoRoN, @kaoriya)

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

#include QMK_KEYBOARD_H

// clang-format off
matrix_row_t matrix_mask[MATRIX_ROWS] = {
    0b111111111111111,
    0b101111111111111,
    0b100111111111111,
    0b110111111111101,
    0b000110001000110,
};
// clang-format on

//////////////////////////////////////////////////////////////////////////////

#ifdef LED_ARRAY_STATE

#    include <string.h>
#    include "ws2812.h"

#    ifndef LAS_LAYER_LED_VALUE
#        define LAS_LAYER_LED_VALUE 64
#    endif
#    ifndef LAS_LOCK_LED_VALUE
#        define LAS_LOCK_LED_VALUE 192
#    endif

typedef struct {
    bool  layers[3];
    led_t locks;
} las_state_t;

void las_led_set(LED_TYPE *led, uint8_t r, uint8_t g, uint8_t b) {
    LED_TYPE v = { .r = r, .g = g, .b = b };
    *led = v;
}

void las_init(void) {
    LED_TYPE leds[3] = {0};
    ws2812_setleds(leds, 3);
}

static las_state_t las = {0};

void las_layer_state_set(layer_state_t state) {
    las.layers[0] = layer_state_cmp(state, 1);
    las.layers[1] = layer_state_cmp(state, 2);
    las.layers[2] = layer_state_cmp(state, 3);
}

void las_led_update(led_t led_state) {
    las.locks = led_state;
}

void las_housekeeping(void) {
    static las_state_t prev = {0};
    if (memcmp(&las, &prev, sizeof(las)) == 0) {
        return;
    }
    prev = las;
    LED_TYPE leds[3] = {0};
    // apply layers state
    if (las.layers[0]) {
        las_led_set(&leds[0], LAS_LAYER_LED_VALUE, LAS_LAYER_LED_VALUE, LAS_LAYER_LED_VALUE);
    }
    if (las.layers[1]) {
        las_led_set(&leds[1], LAS_LAYER_LED_VALUE, LAS_LAYER_LED_VALUE, LAS_LAYER_LED_VALUE);
    }
    if (las.layers[2]) {
        las_led_set(&leds[2], LAS_LAYER_LED_VALUE, LAS_LAYER_LED_VALUE, LAS_LAYER_LED_VALUE);
    }
    // apply locks state
    if (las.locks.caps_lock) {
        leds[0].r = LAS_LOCK_LED_VALUE;
    }
    if (las.locks.scroll_lock) {
        leds[1].g = LAS_LOCK_LED_VALUE;
    }
    if (las.locks.num_lock) {
        leds[2].b = LAS_LOCK_LED_VALUE;
    }
    // update WS2812 array
    ws2812_setleds(leds, 3);
}

#endif

//////////////////////////////////////////////////////////////////////////////

void keyboard_post_init_kb(void) {
#ifdef LED_ARRAY_STATE
    las_init();
#endif
    keyboard_post_init_user();
}

layer_state_t layer_state_set_kb(layer_state_t state) {
#ifdef LED_ARRAY_STATE
    las_layer_state_set(state);
#endif
    return state;
}

bool led_update_kb(led_t led_state) {
    bool res = led_update_user(led_state);
    if (!res) {
        return false;
    }
#ifdef LED_ARRAY_STATE
    las_led_update(led_state);
#endif
    return true;
}

void housekeeping_task_kb(void) {
#ifdef LED_ARRAY_STATE
    las_housekeeping();
#endif
}
