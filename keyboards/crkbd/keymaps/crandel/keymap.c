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

enum layers {
  COLMAK_L = 0,
  NUM_L = 1,
  CHARS_L = 2,
  MOUSE_L = 3,
};

#define TO_CLM DF(COLMAK_L)
#define TO_NMB DF(NUM_L)
#define TO_CHR DF(CHARS_L)
#define TO_MOS DF(MOUSE_L)

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
      set_indicators_state(CR_HSV_RED);
    }
    break;
  }
  return true;
}
#endif // RGBLIGHT_ENABLE

#ifdef TAP_DANCE_ENABLE
#define TAP_TAPPING_TERM 220
void keyboard_post_init_user(void) {
    vial_tap_dance_entry_t td0 = { TO_CLM,
                                   TO_CHR,
                                   TO_NMB,
                                   TO_MOS,
                                   TAP_TAPPING_TERM };
    vial_tap_dance_entry_t td1 = { KC_DOT,
                                   KC_QUOT,
                                   KC_COMM,
                                   LSFT(KC_SLSH),
                                   TAP_TAPPING_TERM };
    vial_tap_dance_entry_t td2 = { KC_BTN1,
                                   KC_BTN3,
                                   KC_BTN2,
                                   KC_BTN4,
                                   TAP_TAPPING_TERM };
    vial_tap_dance_entry_t td3 = { KC_QUOT,
                                   KC_LBRC,
                                   KC_SLSH,
                                   KC_RBRC,
                                   TAP_TAPPING_TERM };
    dynamic_keymap_set_tap_dance(0, &td0); // the first value corresponds to the TD(i) slot
    dynamic_keymap_set_tap_dance(1, &td1);
    dynamic_keymap_set_tap_dance(2, &td2);
    dynamic_keymap_set_tap_dance(3, &td3);
}
#endif // TAP_DANCE_ENABLE


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [COLMAK_L] = LAYOUT_split_3x6_3(
  //,-------------------------------------------------------------------.    ,------------------------------------------------------------------------.
      QK_GESC,    KC_Q, RALT_T(KC_W), LCTL_T(KC_F), LSFT_T(KC_P), KC_B,         KC_J, LSFT_T(KC_L), LCTL_T(KC_U), RALT_T(KC_Y),       KC_SCLN,  KC_DEL,
  //|--------+--------+-------------+-------------+-------------+-------|    |------+-------------+-------------+-------------+--------------+--------|
      KC_CAPS,    KC_A,         KC_R,         KC_S,         KC_T, KC_G,         KC_M,         KC_N,         KC_E,         KC_I,          KC_O,   TD(3),
  //|--------+--------+-------------+-------------+-------------+-------|    |------+-------------+-------------+-------------+--------------+--------|
      KC_LSFT,    KC_Z,         KC_X,         KC_C,         KC_D, KC_V,         KC_K,         KC_H,      KC_COMM,       KC_DOT, LSFT(KC_SLSH), KC_PSCR,
  //|--------+--------+-------------+-------------+-------------+-------|    |------+-------------+-------------+-------------+--------------+--------|
                                           KC_LGUI,        TD(0), KC_SPC,     KC_ENT,      KC_BSPC,       KC_TAB
                                           //`--------------------------'    `----------------------------------'
  ),

  [NUM_L] = LAYOUT_split_3x6_3(
  //,-------------------------------------------------------------------.    ,---------------------------------------------------------------------------.
        QK_GESC, KC_F5, LALT_T(KC_7), LCTL_T(KC_4), LSFT_T(KC_2),  KC_F1,          KC_HOME, LSFT_T(KC_PGDN), LCTL_T(KC_PGUP),    KC_END, XXXXXXX, KC_BSPC,
  //|----------+------+-------------+-------------+-------------+-------|    |------------+----------------+----------------+----------+--------+--------|
          KC_F1, KC_F4,         KC_8,         KC_5,         KC_1,   KC_3,          KC_LEFT,         KC_DOWN,           KC_UP,  KC_RIGHT, KC_LCTL,   TD(3),
  //|----------+------+-------------+-------------+-------------+-------|    |------------+----------------+----------------+----------+--------+--------|
        KC_PSCR, KC_F3,         KC_9,         KC_6,         KC_0,  KC_F2,          KC_BTN4,         KC_BTN1,         KC_BTN2,   KC_BTN3, KC_BSLS,  KC_DEL,
  //|----------+------+-------------+-------------+-------------+-------|    |------------+----------------+----------------+----------+--------+--------|
                                           KC_LGUI,        TD(0), KC_SPC,           KC_ENT,         KC_BSPC,          KC_TAB
                                           //`--------------------------'    `----------------------------------------------'
  ),

  [CHARS_L] = LAYOUT_split_3x6_3(
  //,------------------------------------------------------------------.    ----------------------------------------------------------------------------------.
       QK_GESC,   KC_F7, LSFT(KC_7), LSFT(KC_4), LSFT(KC_2),      KC_F8,           KC_EQL, LSFT(KC_BSLS),        KC_GRV, LSFT(KC_GRV),       KC_EQUAL, KC_BSPC,
  //|---------+--------+-----------+-----------+-----------+-----------|    |------------+--------------+--------------+-------------+---------------+--------|
       KC_LCTL, XXXXXXX, LSFT(KC_8), LSFT(KC_5), LSFT(KC_1), LSFT(KC_3),       KC_KB_MUTE,       KC_LBRC,    LSFT(KC_9),   LSFT(KC_0),        KC_RBRC,   TD(3),
  //|---------+--------+-----------+-----------+-----------+-----------|    |------------+--------------+--------------+-------------+---------------+--------|
       KC_LALT, XXXXXXX,     KC_CUT, LSFT(KC_6),     KC_APP,    KC_PSTE,     LSFT(KC_EQL), LSFT(KC_LBRC), LSFT(KC_COMM), LSFT(KC_DOT),  LSFT(KC_RBRC),  KC_DEL,
  //|---------+--------+-----------+-----------+-----------+-----------|    |------------+--------------+--------------+-------------+---------------+--------|
                                        KC_LGUI,      TD(0),     KC_SPC,           KC_ENT,       KC_BSPC,        KC_TAB
                                        //`----------------------------'    `------------------------------------------'
  ),

  [MOUSE_L] = LAYOUT_split_3x6_3(
  //,-------------------------------------------------------.              ,--------------------------------------------------------.
      KC_GESC,  KC_BRID, KC_BRIU,  KC_VOLD, KC_VOLU,   KC_F9,                    KC_F10,  KC_F11, KC_WH_D, KC_WH_U, KC_PSCR, QK_BOOT,
  //|--------+---------+--------+---------+--------+--------|              |-----------+--------+--------+--------+--------+--------|
      KC_BTN4,  XXXXXXX, KC_SLCT,  KC_BTN2, KC_BTN1, KC_BTN3,                    KC_F12, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, XXXXXXX,
  //|--------+---------+--------+---------+--------+--------|              |-----------+--------+--------+--------+-----------------|
      QK_BOOT,  XXXXXXX,  KC_CUT,  KC_COPY,  KC_APP, KC_PSTE,                    KC_INS, KC_WBAK, KC_PGDN, KC_PGUP, KC_WFWD, XXXXXXX,
  //|--------+---------+--------+------------------+--------|              |-----------+--------+--------+--------+--------+- ------|
                                   KC_LGUI,   TD(0),  KC_SPC,                    KC_ENT, KC_BSPC,  KC_TAB
                                   //`----------------------'              `-----------------------------'
  ),
};
