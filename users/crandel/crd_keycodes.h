#pragma once

enum layers {
  COLMAK_L = 0,
  NUM_L = 1,
  CHARS_L = 2,
  MOUSE_L = 3,
  GAME_L = 4,
};

enum virtual_keycodes {
    V_US = QK_KB_0,
    V_UK,
};

#define TO_CLM DF(COLMAK_L)
#define TO_NMB DF(NUM_L)
#define TO_CHR DF(CHARS_L)
#define TO_MOS DF(MOUSE_L)
#define TO_GAM DF(GAME_L)
#define SLS_TD TD(3)

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
