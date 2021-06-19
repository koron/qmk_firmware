/*
This is the c configuration file for the keymap

Copyright 2012 Jun Wako <wakojun@gmail.com>
Copyright 2015 Jack Humbert
Copyright 2021 @Yowkees
Copyright 2021 MURAOKA Taro (aka KoRoN, @kaoriya)

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

#define PMW_3360

/* Select hand configuration */

//#define MASTER_LEFT
#define MASTER_RIGHT

#define SOFT_SERIAL_PIN D2

#ifdef RGBLIGHT_ENABLE
#    define RGBLIGHT_LIMIT_VAL 120
#    define RGBLIGHT_HUE_STEP 10
#    define RGBLIGHT_SAT_STEP 17
#    define RGBLIGHT_VAL_STEP 17

#    define RGBLIGHT_EFFECT_RGB_TEST
#endif

#define OLED_FONT_H "keyboards/keyball/lib/glcdfont.c"
