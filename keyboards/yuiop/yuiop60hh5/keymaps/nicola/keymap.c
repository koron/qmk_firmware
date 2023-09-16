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

#include "ws2812.h"

enum nicola_keycodes {
    NC_TOG = SAFE_RANGE,
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
      KC_ESC  ,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_MINS, KC_EQL , KC_BSLS, KC_GRV ,
      KC_TAB      ,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, KC_LBRC, KC_RBRC,      KC_BSPC,
      KC_LCTL       ,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,             KC_ENT ,
      KC_LSFT           ,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M, KC_COMM, KC_DOT , KC_SLSH,         KC_RSFT, MO(1)  ,
                   MO(1)   ,  KC_LALT ,                         KC_SPC                         ,   KC_RALT  , KC_RGUI
    ),

    [1] = LAYOUT(
      XXXXXXX , KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  , KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 , KC_F12 , KC_INS , KC_DEL ,
      KC_CAPS     , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_NUM, KC_PSCR, KC_SCRL, KC_PAUS, KC_UP  , XXXXXXX,      XXXXXXX,
      _______       , KC_VOLD, KC_VOLU, KC_MUTE, XXXXXXX, XXXXXXX, KC_PAST, KC_PSLS, KC_HOME, KC_PGUP, KC_LEFT, KC_RGHT,             XXXXXXX,
      _______           , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_PPLS, KC_PMNS, KC_END , KC_PGDN, KC_DOWN,         _______, _______,
                   _______ ,  _______ ,                         NC_TOG                         ,   _______  , _______
    ),
};
// clang-format on

static bool nicola_enable = false;
static bool nicola_left = false;
static bool nicola_right = false;

static LED_TYPE indicator[3] = {0};


#if 0
static bool nicola_passthrough = false;
#endif

static void nicola_on(void) {
    LED_TYPE v = {.r = 0xff, .g = 0xff, .b=0xff};
    indicator[2] = v;
    ws2812_setleds(indicator, 3);

    tap_code(KC_LANG1); // enable IME
}

static void nicola_off(void) {
    LED_TYPE v = {.r = 0x00, .g = 0x00, .b=0x00};
    indicator[2] = v;
    ws2812_setleds(indicator, 3);

    tap_code(KC_LANG2); // disable IME
}

static void nicola_send_string(bool pressed, const char *normal, const char *left, const char *right) {
    if (!pressed) {
        return;
    }
    if (nicola_left && left) {
        send_string(left);
    } else if (nicola_right && right) {
        send_string(right);
    } else if (normal) {
        send_string(normal);
    }
}

static bool nicola_process(uint16_t keycode, keyrecord_t *record) {
    bool pressed = record->event.pressed;
    // capture ALT pressed status
    switch (keycode) {
        case KC_LALT:
            nicola_left = pressed;
            return false;
        case KC_RALT:
            nicola_right = pressed;
            return false;
    }
    switch (keycode) {

#if 0
        case KC_1:
            nicola_send_string(pressed, "1", "?", NULL); break;
        case KC_2:
            nicola_send_string(pressed, "2", "/", NULL); break;
        case KC_3:
            nicola_send_string(pressed, "3", "~", NULL); break;
        case KC_4:
            nicola_send_string(pressed, "4", "[", NULL); break;
        case KC_5:
            nicola_send_string(pressed, "5", "]", NULL); break;
        case KC_6:
            nicola_send_string(pressed, "6", NULL, "["); break;
        case KC_7:
            nicola_send_string(pressed, "7", NULL, "]"); break;
        case KC_8:
            nicola_send_string(pressed, "8", NULL, "("); break;
        case KC_9:
            nicola_send_string(pressed, "9", NULL, ")"); break;
        case KC_0:
            nicola_send_string(pressed, "0", NULL, "["); break;
#endif

        case KC_Q:
            nicola_send_string(pressed, ".", "xa", NULL); break;
        case KC_W:
            nicola_send_string(pressed, "ka", "e", "ga"); break;
        case KC_E:
            nicola_send_string(pressed, "ta", "ri", "da"); break;
        case KC_R:
            nicola_send_string(pressed, "ko", "xya", "go"); break;
        case KC_T:
            nicola_send_string(pressed, "sa", "re", "za"); break;
        case KC_Y:
            nicola_send_string(pressed, "ra", "pa", "yo"); break;
        case KC_U:
            nicola_send_string(pressed, "ti", "di", "ni"); break;
        case KC_I:
            nicola_send_string(pressed, "ku", "gu", "ru"); break;
        case KC_O:
            nicola_send_string(pressed, "tu", "du", "ma"); break;
        case KC_P:
            nicola_send_string(pressed, ",", "pi", "xe"); break;

        case KC_A:
            nicola_send_string(pressed, "u", "wo", NULL); break;
        case KC_S:
            nicola_send_string(pressed, "si", "a", "ji"); break;
        case KC_D:
            nicola_send_string(pressed, "te", "na", "de"); break;
        case KC_F:
            nicola_send_string(pressed, "ke", "xyu", "ge"); break;
        case KC_G:
            nicola_send_string(pressed, "se", "mo", "ze"); break;
        case KC_H:
            nicola_send_string(pressed, "ha", "ba", "mi"); break;
        case KC_J:
            nicola_send_string(pressed, "to", "do", "o"); break;
        case KC_K:
            nicola_send_string(pressed, "ki", "gi", "no"); break;
        case KC_L:
            nicola_send_string(pressed, "i", "po", "xyo"); break;
        case KC_SCLN:
            nicola_send_string(pressed, "nn", NULL, "xtu"); break;

        case KC_Z:
            nicola_send_string(pressed, ".", "xu", NULL); break;
        case KC_X:
            nicola_send_string(pressed, "hi", "-", "bi"); break;
        case KC_C:
            nicola_send_string(pressed, "su", "ro", "zu"); break;
        case KC_V:
            nicola_send_string(pressed, "hu", "ya", "bu"); break;
        case KC_B:
            nicola_send_string(pressed, "he", "xi", "be"); break;
        case KC_N:
            nicola_send_string(pressed, "me", "pu", "nu"); break;
        case KC_M:
            nicola_send_string(pressed, "so", "zo", "yu"); break;
        case KC_COMM:
            nicola_send_string(pressed, "ne", "pe", "mu"); break;
        case KC_DOT:
            nicola_send_string(pressed, "ho", "bo", "wa"); break;
        case KC_SLSH:
            nicola_send_string(pressed, "/", NULL, "xo"); break;

        default:
#if 0
            if (pressed) {
                if (nicola_left) {
                    register_mods(MOD_BIT(KC_LEFT_ALT));
                }
                if (nicola_right) {
                    register_mods(MOD_BIT(KC_RIGHT_ALT));
                }
                nicola_passthrough = true;
            }
#endif
            return true;
    }
    return false;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case NC_TOG:
            if (record->event.pressed) {
                (nicola_enable = !nicola_enable) ? nicola_on() : nicola_off();
            }
            return false;
    }
    if (nicola_enable) {
        return nicola_process(keycode, record);
    }
    return true;
}

#if 0
void post_process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (nicola_passthrough) {
        nicola_passthrough = false;
        if (nicola_left) {
            unregister_mods(MOD_BIT(KC_LEFT_ALT));
        }
        if (nicola_right) {
            unregister_mods(MOD_BIT(KC_RIGHT_ALT));
        }
    }
}
#endif
