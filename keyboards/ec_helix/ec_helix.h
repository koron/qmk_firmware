/* Copyright 2020 kano_v
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#include "quantum.h"

/* This is a shortcut to help you visually see your layout.
 *
 * The first section contains all of the arguments representing the physical
 * layout of the board and position of the keys.
 *
 * The second converts the arguments into a two-dimensional array which
 * represents the switch matrix.
 */

 #define LAYOUT( \
   L00, L01, L02, L03, L04, L05,          R01, R02, R03, R04, R05, R06, \
   L10, L11, L12, L13, L14, L15,          R11, R12, R13, R14, R15, R16, \
   L20, L21, L22, L23, L24, L25,          R21, R22, R23, R24, R25, R26, \
   L30, L31, L32, L33, L34, L35, L36, R30, R31, R32, R33, R34, R35, R36, \
   L40, L41, L42, L43, L44, L45, L46, R40, R41, R42, R43, R44, R45, R46  \
   ) \
   { \
     { L03, L02, L04, L05, KC_NO, L01, L00 }, \
     { L13, L12, L14, L15, KC_NO, L11, L10 }, \
     { L23, L22, L24, L25, KC_NO, L21, L20 }, \
     { L33, L32, L34, L35, L36, L31, L30 }, \
     { L43, L42, L44, L45, L46, L41, L40 }, \
     { R05, R02, R04, R06, KC_NO, R03, R01 }, \
     { R15, R12, R14, R16, KC_NO, R13, R11 }, \
     { R15, R22, R24, R26, KC_NO, R23, R21 }, \
     { R25, R32, R34, R36, R30, R33, R31 }, \
     { R35, R42, R44, R46, R40, R43, R41 }, \
   }
