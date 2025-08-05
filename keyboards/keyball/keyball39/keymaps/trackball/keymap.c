/*
Copyright 2022 @Yowkees
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

#include "quantum.h"

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  // keymap for default
  [0] = LAYOUT_universal(
    _______  , _______  , _______  , _______  , _______  ,                            KC_NO    , KC_NO    , KC_NO    , KC_NO    , KC_NO    ,
    _______  , _______  , _______  , _______  , _______  ,                            KC_NO    , KC_BTN1  , SCRL_MO  , KC_BTN2  , KC_NO    ,
    _______  , _______  , _______  , _______  , _______  ,                            KC_NO    , KC_NO    , KC_BTN3  , KC_NO    , KC_NO    ,
    _______  , _______  , _______  , _______  , _______  , _______  ,      KC_BTN5  , KC_BTN4  , _______  , _______  , _______  , MO(1)
  ),

  [1] = LAYOUT_universal(
    _______  , _______  , _______  , _______  , _______  ,                            _______  , _______  , SSNP_HOR , SSNP_VRT , SSNP_FRE ,
    _______  , _______  , _______  , _______  , _______  ,                            _______  , _______  , _______  , SCRL_DVI , SCRL_DVD ,
    _______  , _______  , _______  , _______  , _______  ,                            CPI_D1K  , CPI_D100 , CPI_I100 , CPI_I1K  , KBC_SAVE ,
    _______  , _______  , _______  , _______  , _______  , _______  ,      _______  , _______  , _______  , _______  , _______  , _______
  ),

  [2] = LAYOUT_universal(
    _______  , _______  , _______  , _______  , _______  ,                            KC_NO    , KC_NO    , KC_NO    , KC_NO    , KC_NO    ,
    _______  , _______  , _______  , _______  , _______  ,                            KC_NO    , KC_NO    , KC_NO    , KC_NO    , KC_NO    ,
    _______  , _______  , _______  , _______  , _______  ,                            KC_NO    , KC_NO    , KC_NO    , KC_NO    , KC_NO    ,
    _______  , _______  , _______  , _______  , _______  , _______  ,      KC_NO    , KC_NO    , _______  , _______  , _______  , KC_NO
  ),
};
// clang-format on

void keyboard_post_init_user() {
    keyball_set_cpi(16);
    keyball_set_scroll_div(6);
}

#ifdef OLED_ENABLE

#    include "lib/oledkit/oledkit.h"

void oledkit_render_info_user(void) {
    keyball_oled_render_keyinfo();
    keyball_oled_render_ballinfo();
    keyball_oled_render_layerinfo();
}
#endif
