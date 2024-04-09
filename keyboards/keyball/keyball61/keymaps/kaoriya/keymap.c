/*
Copyright 2023 MURAOKA Taro (aka KoRoN, @kaoriya)

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

#include "quantum.h"

enum keymap_layers {
    _Q,
    _M,
    _L,
    _R,
    _W,
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_Q] = LAYOUT_universal(
    KC_ESC   , KC_1     , KC_2     , KC_3     , KC_4     , KC_5     ,                                  KC_6     , KC_7     , KC_8     , KC_9     , KC_0     , KC_MINS  ,
    KC_TAB   , KC_Q     , KC_W     , KC_E     , KC_R     , KC_T     ,                                  KC_Y     , KC_U     , KC_I     , KC_O     , KC_P     , KC_EQL   ,
    KC_LCTL  , KC_A     , KC_S     , KC_D     , KC_F     , KC_G     ,                                  KC_H     , KC_J     , KC_K     , KC_L     , KC_SCLN  , KC_QUOT  ,
    KC_LSFT  , KC_Z     , KC_X     , KC_C     , KC_V     , KC_B     , KC_BSPC  ,            KC_ENT   , KC_N     , KC_M     , KC_COMM  , KC_DOT   , KC_SLSH  , KC_RSFT  ,
    KC_LBRC  , KC_RBRC  , KC_LGUI  , KC_LALT  , KC_BTN2  , KC_BTN1  , MO(_L)   ,            MO(_R)   , KC_SPC   , _______  , _______  , _______  , KC_BSLS  , KC_GRV
  ),

  [_L] = LAYOUT_universal(
    _______  , KC_F1    , KC_F2    , KC_F3    , KC_F4    , KC_F5    ,                                  KC_F6    , KC_F7    , KC_F8    , KC_F9    , KC_F10   , _______  ,
    _______  , _______  , _______  , _______  , _______  , _______  ,                                  KC_HOME  , KC_PGDN  , KC_PGUP  , KC_END   , _______  , _______  ,
    _______  , _______  , _______  , _______  , _______  , _______  ,                                  KC_LEFT  , KC_DOWN  , KC_UP    , KC_RIGHT , _______  , _______  ,
    _______  , _______  , _______  , _______  , _______  , _______  , KC_DEL   ,            _______  , _______  , _______  , _______  , _______  , _______  , _______  ,
    _______  , _______  , _______  , _______  , _______  , _______  , _______  ,            _______  , _______  , _______  , _______  , _______  , KC_INS   , _______
  ),

  [_R] = LAYOUT_universal(
    _______  , KC_F11   , KC_F12   , KC_F13   , KC_F14   , KC_F15   ,                                  KC_F16   , KC_F17   , KC_F18   , KC_F19   , KC_F20   , AML_TO   ,
    _______  , _______  , _______  , _______  , _______  , _______  ,                                  _______  , _______  , _______  , _______  , _______  , AML_I50  ,
    _______  , _______  , _______  , _______  , _______  , _______  ,                                  _______  , _______  , _______  , _______  , _______  , AML_D50  ,
    _______  , _______  , _______  , _______  , _______  , _______  , _______  ,            _______  , _______  , _______  , _______  , _______  , _______  , _______  ,
    _______  , _______  , _______  , _______  , _______  , _______  , _______  ,            _______  , _______  , _______  , _______  , _______  , _______  , _______
  ),

  [_W] = LAYOUT_universal(
    _______  , _______  , _______  , _______  , _______  , _______  ,                                  _______  , _______  , _______  , _______  , _______  , _______  ,
    _______  , _______  , _______  , _______  , _______  , _______  ,                                  _______  , _______  , _______  , _______  , _______  , _______  ,
    _______  , _______  , _______  , _______  , _______  , _______  ,                                  _______  , _______  , _______  , _______  , _______  , _______  ,
    _______  , _______  , _______  , _______  , _______  , _______  , EE_CLR   ,            EE_CLR   , _______  , _______  , _______  , _______  , _______  , _______  ,
    QK_BOOT  , _______  , _______  , _______  , _______  , _______  , _______  ,            _______  , _______  , _______  , _______  , _______  , _______  , QK_BOOT
  ),

  [_M] = LAYOUT_universal(
    _______  , _______  , _______  , _______  , _______  , _______  ,                                  _______  , _______  , _______  , _______  , _______  , _______  ,
    _______  , _______  , _______  , _______  , _______  , _______  ,                                  _______  , KC_BTN4  , KC_BTN3  , KC_BTN5  , _______  , _______  ,
    _______  , _______  , _______  , _______  , _______  , _______  ,                                  _______  , KC_BTN1  , SCRL_MO  , KC_BTN2  , _______  , _______  ,
    _______  , _______  , _______  , _______  , _______  , _______  , _______  ,            _______  , _______  , _______  , _______  , _______  , _______  , _______  ,
    _______  , _______  , _______  , _______  , _______  , _______  , _______  ,            _______  , _______  , _______  , _______  , _______  , _______  , _______
  ),
};
// clang-format on

void keyboard_post_init_user() {
#ifdef RGBLIGHT_ENABLE
    rgblight_enable_noeeprom();
    rgblight_sethsv_noeeprom(0, 0, 0);
#endif
#ifdef POINTING_DEVICE_AUTO_MOUSE_ENABLE
    set_auto_mouse_layer(_M);
    set_auto_mouse_timeout(650);
    set_auto_mouse_enable(true);
#endif
    // 1500CPI
    keyball_set_cpi(15);
    keyball_set_scroll_div(6);
}

#define SAT 204
#define VAL 120

#ifdef RGBLIGHT_ENABLE
layer_state_t layer_state_set_user(layer_state_t state) {
    state = update_tri_layer_state(state, _L, _R, _W);
    switch (get_highest_layer(state)) {
        default:
        case _Q:
            rgblight_sethsv_noeeprom(0, 0, 0);
            break;
        case _L:
            rgblight_sethsv_noeeprom(0, SAT, VAL);
            break;
        case _R:
            rgblight_sethsv_noeeprom(85, SAT, VAL);
            break;
        case _W:
            rgblight_sethsv_noeeprom(170, SAT, VAL);
            break;
        case _M:
            rgblight_sethsv_noeeprom(0, 0, 80);
            break;
    }
    keyball_set_scroll_mode(get_highest_layer(state) == _L);
    return state;
}
#endif

#ifdef OLED_ENABLE

#    include "lib/oledkit/oledkit.h"

void oledkit_render_info_user(void) {
    keyball_oled_render_keyinfo();
    keyball_oled_render_ballinfo();
    keyball_oled_render_layerinfo();
}
#endif
