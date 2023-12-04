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

#include QMK_KEYBOARD_H
#include "vial.h"

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

#ifdef RGBLIGHT_ENABLE
#define CR_HSV_BLUE        170, 255, 55
#define CR_HSV_CYAN        128, 255, 55
#define CR_HSV_GOLD         36, 255, 55
#define CR_HSV_GREEN        85, 255, 55
#define CR_HSV_MAGENTA     213, 255, 55
#define CR_HSV_ORANGE       21, 255, 55
#define CR_HSV_PURPLE      191, 255, 55
#define CR_HSV_RED           0, 255, 55
#define CR_HSV_YELLOW       43, 255, 55

void set_indicators_state(uint8_t hue, uint8_t sat, uint8_t val){
  rgblight_sethsv(hue, sat, val);
}


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
  case TO_CLM:
    if (record->event.pressed) {
      set_indicators_state(CR_HSV_GREEN);
    }
    break;
  case TO_NMB:
    if (record->event.pressed) {
      set_indicators_state(CR_HSV_BLUE);
    }
    break;
  case TO_CHR:
    if (record->event.pressed) {
      set_indicators_state(CR_HSV_GOLD);
    }
    break;
  case TO_MOS:
    if (record->event.pressed) {
      set_indicators_state(CR_HSV_ORANGE);
    }
    break;
  case TO_GAM:
    if (record->event.pressed) {
      set_indicators_state(CR_HSV_RED);
    }
    break;
  case V_US:
    if (record->event.pressed) {
      tap_code(KC_CAPS);
    }
    break;
  case V_UK:
    if (record->event.pressed) {
      tap_code16(S(KC_CAPS));
    }
    break;
  }
  return true;
}
#endif // RGBLIGHT_ENABLE


#ifdef LEADER_ENABLE
void leader_end_user(void) {
  if (leader_sequence_one_key(QK_LEAD)) {
    return;
  }
  if (leader_sequence_one_key(KC_C)) {
    register_code(KC_LSFT);
    tap_code16(C(KC_C));
    unregister_code(KC_LSFT);
    return;
  }
  if (leader_sequence_one_key(KC_V)) {
    register_code(KC_LSFT);
    tap_code16(C(KC_V));
    unregister_code(KC_LSFT);
    return;
  }
  if (leader_sequence_one_key(KC_A)) {
    tap_code(KC_PSCR);
    tap_code16(S(KC_QUOT));
    tap_code(KC_A);
    return;
  }
  if (leader_sequence_one_key(KC_E)) {
    tap_code(KC_PSCR);
    tap_code16(S(KC_QUOT));
    tap_code(KC_E);
    return;
  }
  if (leader_sequence_one_key(KC_O)) {
    tap_code(KC_PSCR);
    tap_code16(S(KC_QUOT));
    tap_code(KC_O);
    return;
  }
  if (leader_sequence_one_key(KC_U)) {
    tap_code(KC_PSCR);
    tap_code16(S(KC_QUOT));
    tap_code(KC_U);
    return;
  }
  if (leader_sequence_one_key(KC_Q)) {
    tap_code(KC_SCLN);
    tap_code(KC_W);
    tap_code(KC_Q);
    return;
  }
  if (leader_sequence_one_key(KC_X)) {
    tap_code16(A(KC_X));
    return;
  }
}
#endif

#ifdef TAP_DANCE_ENABLE
#define TAP_TAPPING_TERM 220
void keyboard_post_init_user(void) {
    vial_tap_dance_entry_t td0 = { TO_CLM, // Change layers
                                   TO_CHR,
                                   TO_NMB,
                                   TO_MOS,
                                   TAP_TAPPING_TERM };
    vial_tap_dance_entry_t td1 = { V_US, // Change language
                                   V_UK,
                                   V_UK,
                                   V_UK,
                                   TAP_TAPPING_TERM };
    vial_tap_dance_entry_t td2 = { KC_QUOT, // ' [ ? ]
                                   KC_LBRC,
                                   LSFT(KC_SLSH),
                                   KC_RBRC,
                                   TAP_TAPPING_TERM };
    vial_tap_dance_entry_t td3 = { KC_SLASH, // / . , backslash
                                   KC_DOT,
                                   KC_COMM,
                                   KC_BSLS,
                                   TAP_TAPPING_TERM };
    dynamic_keymap_set_tap_dance(0, &td0); // the first value corresponds to the TD(i) slot
    dynamic_keymap_set_tap_dance(1, &td1);
    dynamic_keymap_set_tap_dance(2, &td2);
    dynamic_keymap_set_tap_dance(3, &td3);
}
#endif // TAP_DANCE_ENABLE


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [COLMAK_L] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------------------.    ,------------------------------------------------------------------.
     QK_GESC,    KC_Q, LALT_T(KC_W), LCTL_T(KC_F), LSFT_T(KC_P),  KC_B,       KC_E, LSFT_T(KC_I), LCTL_T(KC_U), RALT_T(KC_Y), KC_SCLN,  KC_DEL,
  //|-------+--------+-------------+-------------+-------------+------|    |------+-------------+-------------+-------------+--------+--------|
       TD(1),    KC_A,         KC_R,         KC_S,         KC_T,  KC_G,       KC_M,         KC_H,         KC_J,         KC_K,    KC_L,   TD(2),
  //|-------+--------+-------------+-------------+-------------+------|    |------+-------------+-------------+-------------+--------+--------|
     KC_LSFT,    KC_Z,         KC_X,         KC_C,         KC_D,  KC_V,       KC_O,         KC_N,      KC_COMM,       KC_DOT,   TD(3), QK_LEAD,
  //|-------+--------+-------------+-------------+-------------+-- ---|    |------+-------------+-------------+-------------+--------+--------|
                                          KC_LGUI,       KC_SPC, TD(0),     KC_ENT,       KC_TAB,      KC_BSPC
                                          //`-------------------------'    `----------------------------------'
  ),

  [NUM_L] = LAYOUT_split_3x6_3(
  //,------------------------------------------------------------------.    ,---------------------------------------------------------------------------------.
      QK_GESC, KC_F5, LALT_T(KC_7), LCTL_T(KC_4), LSFT_T(KC_2), KC_MINS,          KC_HOME, LSFT_T(KC_END), LCTL_T(KC_PGDN), RALT_T(KC_PGUP),  XXXXXXX,  KC_DEL,
  //|--------+------+-------------+-------------+-------------+--------|    |------------+---------------+----------------+----------------+---------+--------|
        TD(1), KC_F4,         KC_8,         KC_5,         KC_1,    KC_3,           KC_DOT,        KC_LEFT,         KC_DOWN,           KC_UP, KC_RIGHT,   TD(2),
  //|--------+------+-------------+-------------+-------------+--------|    |------------+---------------+----------------+----------------+---------+--------|
        KC_F1, KC_F3,         KC_9,         KC_6,         KC_0,   KC_F2,          KC_BTN4,        KC_BTN1,         KC_BTN2,         KC_BTN3,  KC_BSLS, KC_PSCR,
  //---------+------+-------------+-------------+-------------+--------|    |------------+---------------+----------------+----------------+---------+--------|
                                         KC_LGUI,       KC_SPC,   TD(0),           KC_ENT,         KC_TAB,         KC_BSPC
                                         //`---------------------------'    `---------------------------------------------'
  ),

  [CHARS_L] = LAYOUT_split_3x6_3(
  //,------------------------------------------------------------------.    ---------------------------------------------------------------------------------.
       QK_GESC,   KC_F7, LSFT(KC_7), LSFT(KC_4), LSFT(KC_2),      KC_F8,           KC_EQL, LSFT(KC_BSLS),        KC_GRV, LSFT(KC_GRV), LSFT(KC_SCLN),  KC_DEL,
  //|---------+--------+-----------+-----------+-----------+-----------|    |------------+--------------+--------------+-------------+--------------+--------|
         TD(1), XXXXXXX, LSFT(KC_8), LSFT(KC_5), LSFT(KC_1), LSFT(KC_3),          KC_LCTL,       KC_LBRC,    LSFT(KC_9),   LSFT(KC_0),       KC_RBRC,   TD(2),
  //|---------+--------+-----------+-----------+-----------+-----------|    |------------+--------------+--------------+-------------+--------------+--------|
       KC_LALT, XXXXXXX,     KC_CUT, LSFT(KC_6),     KC_APP,    KC_PSTE,     LSFT(KC_EQL), LSFT(KC_LBRC), LSFT(KC_COMM), LSFT(KC_DOT), LSFT(KC_RBRC), KC_PSCR,
  //|---------+--------+-----------+-----------+-----------+-----------|    |------------+--------------+--------------+-------------+--------------+--------|
                                        KC_LGUI,     KC_SPC,      TD(0),           KC_ENT,        KC_TAB,       KC_BSPC
                                        //`----------------------------'    `------------------------------------------'
  ),

  [MOUSE_L] = LAYOUT_split_3x6_3(
  //,-------------------------------------------------------.              ,--------------------------------------------------------.
      QK_GESC,  KC_BRID, KC_BRIU,  KC_VOLD, KC_VOLU,   KC_F9,                    KC_F10,  KC_F11, KC_WH_D, KC_WH_U, KC_PSCR, QK_BOOT,
  //|--------+---------+--------+---------+--------+--------|              |-----------+--------+--------+--------+--------+--------|
        TD(1),  XXXXXXX, KC_BTN4,  KC_BTN2, KC_BTN1, KC_BTN3,                    KC_F12, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R,  TO_GAM,
  //|--------+---------+--------+---------+--------+--------|              |-----------+--------+--------+--------+-----------------|
      QK_BOOT,  XXXXXXX,  KC_CUT,  KC_COPY,  KC_APP, KC_PSTE,                    KC_INS, KC_WBAK, KC_PGDN, KC_PGUP, KC_WFWD, XXXXXXX,
  //|--------+---------+--------+------------------+--------|              |-----------+--------+--------+--------+--------+--------|
                                   KC_LGUI,  KC_SPC,   TD(0),                    KC_ENT,  KC_TAB, KC_BSPC
                                   //`----------------------'              `-----------------------------'
  ),

  [GAME_L] = LAYOUT_split_3x6_3(
  //,----------------------------------------------.    ,----------------------------------------------------.
     QK_GESC,    KC_G, KC_Q,   KC_W,   KC_E,   KC_H,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|-------+--------+-----+-------+-------+-------|    |------+---------+--------+--------+--------+--------|
       TD(1), KC_LSFT, KC_A,   KC_S,   KC_D,   KC_F,       KC_1,     KC_2,    KC_3,    KC_4,    KC_5, XXXXXXX,
  //|-------+--------+-----+-------+-------+-------|    |------+---------+--------+--------+--------+--------|
     XXXXXXX, KC_LCTL, KC_Z,   KC_X,   KC_C,   KC_V,       KC_6,     KC_7,    KC_8,    KC_9,    KC_0, XXXXXXX,
  //|-------+--------+-----+-------+-------+-------|    |------+---------+--------+--------+--------+--------|
                            KC_LALT, KC_TAB, KC_ENT,     KC_ENT, TD(0), XXXXXXX
                            //`--------------------'    `----------------------'
  ),
};
