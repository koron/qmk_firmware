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

#include "config_common.h"

// USB Device descriptor parameter
#define VENDOR_ID 0x7890
#define PRODUCT_ID 0x000c
#define DEVICE_VER 0x0001
#define MANUFACTURER unknown

#define PRODUCT Key3
#define DESCRIPTION Macro pad

// Key matrix size and pins
#define MATRIX_ROWS 4
#define MATRIX_COLS 3
#define DIRECT_PINS { \
    { D4, C6, D7 }, \
    { E6, B4, B5 }, \
    { F6, F7, B1 }, \
    { B3, B2, B6 } \
}

// For input stability
#define DEBOUNCE 5

#if !defined(LAYER_STATE_8BIT) && !defined(LAYER_STATE_16BIT) && !defined(LAYER_STATE_32BIT)
#    define LAYER_STATE_8BIT
#endif
