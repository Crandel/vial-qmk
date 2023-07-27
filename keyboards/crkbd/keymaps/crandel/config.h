/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>
Copyright 2023 Vitalii Drevenchuk <@Crandel>

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

// Vial settings
#define VIAL_KEYBOARD_UID      {0x3B, 0x6B, 0xA0, 0x29, 0x80, 0x56, 0xED, 0xD1}
#define VIAL_UNLOCK_COMBO_ROWS {0, 2}
#define VIAL_UNLOCK_COMBO_COLS {0, 2}
#define VIAL_TAP_DANCE_ENTRIES 9
#define VIAL_COMBO_ENTRIES     9

#define DYNAMIC_KEYMAP_LAYER_COUNT 5
#define TAPPING_TERM 360
#define TAPPING_TOGGLE 3
#define PERMISSIVE_HOLD

//#define USE_MATRIX_I2C
#ifdef KEYBOARD_crkbd_rev1_legacy
#    undef USE_I2C
#    define USE_SERIAL
#endif

/* Select hand configuration */

// #define MASTER_LEFT
#define MASTER_RIGHT

// #define EE_HANDS

#define USE_SERIAL_PD2

#ifdef RGBLIGHT_ENABLE
#  undef RGBLIGHT_EFFECT_ALTERNATING
#  undef RGBLIGHT_EFFECT_BREATHING
#  undef RGBLIGHT_EFFECT_CHRISTMAS
#  undef RGBLIGHT_EFFECT_KNIGHT
#  undef RGBLIGHT_EFFECT_RAINBOW_MOOD
#  undef RGBLIGHT_EFFECT_RAINBOW_SWIRL
#  undef RGBLIGHT_EFFECT_RGB_TEST
#  undef RGBLIGHT_EFFECT_SNAKE
#  undef RGBLIGHT_EFFECT_STATIC_GRADIENT
#  undef RGBLIGHT_EFFECT_TWINKLE
#  define RGBLIGHT_DEFAULT_HUE 85
#  define RGBLIGHT_DEFAULT_VAL 55
#  define RGBLIGHT_DISABLE_KEYCODES
#  define RGBLIGHT_HUE_STEP 10
#  define RGBLIGHT_SAT_STEP 17
#  define RGBLIGHT_VAL_STEP 10
#  define RGBLIGHT_LIMIT_VAL 120
#  define RGBLIGHT_SLEEP
#endif

#ifdef OLED_ENABLE
#  define OLED_FONT_H "keyboards/crkbd/lib/glcdfont.c"
#endif // OLED_ENABLE
