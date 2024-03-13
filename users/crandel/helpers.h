/*
Copyright 2024 Vitalii Drevenchuk <cradlemann@gmail.com> @crandel

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

#define __THUMB1__          QK_LEAD, KC_SPC,   TD(0)
#define __THUMB2__           KC_ENT, KC_TAB, KC_BSPC
#define ____COLEMAK_L11____ LGUI_T(KC_Q), LALT_T(KC_W), LCTL_T(KC_F), LSFT_T(KC_P),            KC_B
#define ____COLEMAK_L12____         KC_E, LSFT_T(KC_I), LCTL_T(KC_U), RALT_T(KC_Y), LGUI_T(KC_SCLN)
#define ____COLEMAK_L21____         KC_A,         KC_R,        KC_S,          KC_T,            KC_G
#define ____COLEMAK_L22____         KC_M,         KC_H,        KC_J,          KC_K,            KC_L
#define ____COLEMAK_L31____         KC_Z,         KC_X,        KC_C,          KC_D,            KC_V
#define ____COLEMAK_L32____         KC_O,         KC_N,     KC_COMM,        KC_DOT,          SLS_TD

#define ____NUMBERS_L11____ LGUI_T(KC_F5),   LALT_T(KC_7),    LCTL_T(KC_4),    LSFT_T(KC_2),        KC_MINS
#define ____NUMBERS_L12____       KC_HOME, LSFT_T(KC_END), LCTL_T(KC_PGDN), RALT_T(KC_PGUP), LGUI_T(KC_DOT)
#define ____NUMBERS_L21____         KC_F4,           KC_8,            KC_5,            KC_1,           KC_3
#define ____NUMBERS_L22____        KC_DOT,        KC_LEFT,         KC_DOWN,           KC_UP,       KC_RIGHT
#define ____NUMBERS_L31____         KC_F3,           KC_9,            KC_6,            KC_0,          KC_F2
#define ____NUMBERS_L32____       KC_BTN4,        KC_BTN1,         KC_BTN2,         KC_BTN3,        KC_BSLS
