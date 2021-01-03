/*
This is the c configuration file for the keymap

Copyright 2012 Jun Wako <wakojun@gmail.com>
Copyright 2015 Jack Humbert
Copyright 2020 MURAOKA Taro <koron.kaoriya@gmail.com>

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

#undef PRODUCT
#define PRODUCT Corne +KaoriYa r5

#define LAYER_STATE_8BIT

#define STRICT_LAYER_RELEASE

// Hand configuration: left is master always
#define MASTER_LEFT
#define SPLIT_MODS_ENABLE

#define TAPPING_FORCE_HOLD
#define TAPPING_TERM 200

#define NO_ACTION_ONESHOT
#define NO_ACTION_MACRO
#define NO_ACTION_FUNCTION

#ifdef RGBLIGHT_ENABLE
#    undef RGBLED_NUM
#    define RGBLIGHT_ANIMATIONS
#    define RGBLED_NUM 27
#    define RGBLIGHT_LIMIT_VAL 120
#    define RGBLIGHT_HUE_STEP 17
#    define RGBLIGHT_SAT_STEP 17
#    define RGBLIGHT_VAL_STEP 12
#endif

#define OLED_FONT_H "keyboards/crkbd/lib/glcdfont.c"

#ifdef RGB_MATRIX_ENABLE
//#   define RGB_DISABLE_WHEN_USB_SUSPENDED true
//#   define RGB_DISABLE_AFTER_TIMEOUT 0 // number of ticks to wait until disabling effects

#    define RGB_MATRIX_KEYPRESSES
#    define RGB_MATRIX_FRAMEBUFFER_EFFECTS
#    define RGB_MATRIX_MAXIMUM_BRIGHTNESS 120
#    define RGB_MATRIX_HUE_STEP 8
#    define RGB_MATRIX_SAT_STEP 8
#    define RGB_MATRIX_VAL_STEP 5
#    define RGB_MATRIX_SPD_STEP 10

// Limitation on LED number: increases keyboard responsiveness
#    define RGB_MATRIX_LED_PROCESS_LIMIT ((DRIVER_LED_TOTAL + 4) / 5)
#    define RGB_MATRIX_LED_FLUSH_LIMIT 16

// Enabled matrix effects:
//  - RGB_MATRIX_SOLID_COLOR (*)
//  - RGB_MATRIX_BREATHING (*)
//  - RGB_MATRIX_CYCLE_ALL
//  - RGB_MATRIX_CYCLE_LEFT_RIGHT (*)
//  - RGB_MATRIX_CYCLE_PINWHEEL (*)
//  - RGB_MATRIX_RAINBOW_MOVING_CHEVRON
//  - RGB_MATRIX_DUAL_BEACON (?)
//  - RGB_MATRIX_TYPING_HEATMAP
//  - RGB_MATRIX_SOLID_REACTIVE_SIMPLE
//  - RGB_MATRIX_SOLID_REACTIVE_MULTIWIDE
//  - RGB_MATRIX_SOLID_REACTIVE_MULTICROSS
//  - RGB_MATRIX_SOLID_REACTIVE_MULTINEXUS
//  - RGB_MATRIX_MULTISPLASH (?)
//  - RGB_MATRIX_SOLID_MULTISPLASH
#    define DISABLE_RGB_MATRIX_ALPHAS_MODS
#    define DISABLE_RGB_MATRIX_GRADIENT_UP_DOWN
#    define DISABLE_RGB_MATRIX_GRADIENT_LEFT_RIGHT
#    define DISABLE_RGB_MATRIX_BAND_SAT
#    define DISABLE_RGB_MATRIX_BAND_VAL
#    define DISABLE_RGB_MATRIX_BAND_PINWHEEL_SAT
#    define DISABLE_RGB_MATRIX_BAND_PINWHEEL_VAL
#    define DISABLE_RGB_MATRIX_BAND_SPIRAL_SAT
#    define DISABLE_RGB_MATRIX_BAND_SPIRAL_VAL
#    define DISABLE_RGB_MATRIX_CYCLE_UP_DOWN
#    define DISABLE_RGB_MATRIX_CYCLE_OUT_IN
#    define DISABLE_RGB_MATRIX_CYCLE_OUT_IN_DUAL
#    define DISABLE_RGB_MATRIX_CYCLE_SPIRAL
#    define DISABLE_RGB_MATRIX_RAINBOW_BEACON
#    define DISABLE_RGB_MATRIX_RAINBOW_PINWHEELS
#    define DISABLE_RGB_MATRIX_RAINDROPS
#    define DISABLE_RGB_MATRIX_JELLYBEAN_RAINDROPS
#    define DISABLE_RGB_MATRIX_DIGITAL_RAIN
#    define DISABLE_RGB_MATRIX_SOLID_REACTIVE
#    define DISABLE_RGB_MATRIX_SOLID_REACTIVE_WIDE
#    define DISABLE_RGB_MATRIX_SOLID_REACTIVE_CROSS
#    define DISABLE_RGB_MATRIX_SOLID_REACTIVE_NEXUS
#    define DISABLE_RGB_MATRIX_SPLASH
#    define DISABLE_RGB_MATRIX_SOLID_SPLASH
#endif
