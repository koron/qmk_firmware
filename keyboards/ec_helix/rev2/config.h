/*
Copyright 2012 Jun Wako <wakojun@gmail.com>
Copyright 2015 Jack Humbert

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

/* USB Device descriptor parameter */
#define VENDOR_ID 0xFEED
#define PRODUCT_ID 0x0000
#define DEVICE_VER 0x0001
#define MANUFACTURER ginjake
#define PRODUCT ec_helix
#define DESCRIPTION helix only for varmilo EC switch or NiZ switch

#define TAPPING_FORCE_HOLD
#define TAPPING_TERM 100

/* Use I2C or Serial */
#define USE_SERIAL

#ifndef USE_SERIAL
#define USE_MATRIX_I2C
#endif

/* Soft Serial defines */
#define SOFT_SERIAL_PIN D2
#define SERIAL_USE_MULTI_TRANSACTION

#if !defined(SERIAL_USE_MULTI_TRANSACTION) || defined(USE_MATRIX_I2C)
#define SERIAL_SLAVE_BUFFER_LENGTH  ((MATRIX_ROWS)/2)
#define SERIAL_MASTER_BUFFER_LENGTH ((MATRIX_ROWS)/2)
#endif

/* Select hand configuration */
#define MASTER_LEFT
//#define MASTER_RIGHT
// #define EE_HANDS

/* key matrix size */
// Rows are doubled-up
#define MATRIX_ROWS 10
#define MATRIX_ROW_PINS { D4, C6, D7, E6, B4 }

// wiring of each half
#define MATRIX_COLS 7
#define MATRIX_COL_PINS { F4, F5, F6 }

// custom matrix
#define CHARGE_PIN B2
#define ADC_PIN B6

/* ws2812 RGB LED */
#define RGB_DI_PIN D3

// keyboard RGB LED support
#define RGBLED_NUM 32
#define RGBLIGHT_ANIMATIONS

#define OLED_FONT_H "common/glcdfont.c"
#ifndef IOS_DEVICE_ENABLE
  #define RGBLIGHT_LIMIT_VAL 200
  #define RGBLIGHT_VAL_STEP 17
#else
  #define RGBLIGHT_LIMIT_VAL 35
  #define RGBLIGHT_VAL_STEP 4
#endif
#define RGBLIGHT_HUE_STEP 10
#define RGBLIGHT_SAT_STEP 17

#if defined(RGBLIGHT_ENABLE) && !defined(IOS_DEVICE_ENABLE)
// USB_MAX_POWER_CONSUMPTION value for Helix keyboard
//  120  RGBoff, OLEDoff
//  120  OLED
//  330  RGB 6
//  300  RGB 32
//  310  OLED & RGB 32
  #define USB_MAX_POWER_CONSUMPTION 400
#else
  // fix iPhone and iPad power adapter issue
  // iOS device need lessthan 100
  #define USB_MAX_POWER_CONSUMPTION 100
#endif
