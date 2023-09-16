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

#pragma once

// Key matrix size and pins
#define MATRIX_ROWS 5
#define MATRIX_COLS 15
#define MATRIX_ROW_PINS \
    { F1, F4, F5, F6, F7 }
#define MATRIX_COL_PINS \
    { B4, B5, B6, C6, C7, B0, B1, B2, D1, D2, D3, D5, D4, D6, D7 }
#define DIODE_DIRECTION COL2ROW
#define MATRIX_MASKED
#define DEBOUNCE 5

#if !defined(LAYER_STATE_8BIT) && !defined(LAYER_STATE_16BIT) && !defined(LAYER_STATE_32BIT)
#    define LAYER_STATE_8BIT
#endif

// To squeeze firmware size
#undef LOCKING_SUPPORT_ENABLE
#undef LOCKING_RESYNC_ENABLE

// RGB LED settings
#define R
#define WS2812_DI_PIN B3
#ifdef RGBLIGHT_ENABLE
#    define RGBLED_NUM 3
#    define RGBLIGHT_ANIMATIONS
#    define RGBLIGHT_LIMIT_VAL 255
#    define RGBLIGHT_HUE_STEP 17
#    define RGBLIGHT_SAT_STEP 17
#    define RGBLIGHT_VAL_STEP 17
#endif

// RGB matrix settings
#ifdef RGB_MATRIX_ENABLE
#    define DRIVER_LED_TOTAL 3
#    define RGB_MATRIX_KEYPRESSES
#    define RGB_MATRIX_FRAMEBUFFER_EFFECTS
#    define RGB_MATRIX_MAXIMUM_BRIGHTNESS 255
#endif
