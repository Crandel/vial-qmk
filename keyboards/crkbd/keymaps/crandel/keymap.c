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

void keyboard_post_init_user(void) {
  // Call the post init code.
  #ifdef TAP_DANCE_ENABLE
  install_tap_dance_entries();
  #endif
  #ifdef OLED_ENABLE
  update_oled_layer("Colemak");
  #endif // OLED_ENABLE
  #ifdef RGBLIGHT_ENABLE
  rgblight_sethsv(CR_HSV_GREEN);
  #endif // RGBLIGHT_ENABLE
}

uint16_t keycode_config(uint16_t keycode) {
    return keycode;
}

uint8_t mod_config(uint8_t mod) {
    return mod;
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [COLMAK_L] = LAYOUT_split_3x6_3(
  //,-------------------------------.    ,---------------------------.
     XXXXXXX, ____COLEMAK_L11____,       ____COLEMAK_L12____, XXXXXXX,
  //|-------+--------+-------+------|    |------+-------+---+--------|
     XXXXXXX, ____COLEMAK_L21____,       ____COLEMAK_L22____, XXXXXXX,
  //|-------+--------+-------+------|    |------+-------+---+--------|
     XXXXXXX, ____COLEMAK_L31____,       ____COLEMAK_L32____, XXXXXXX,
  //|-------+--------+-------+------|    |------+-------+---+--------|
                          __THUMB1__,     __THUMB2__
                        //`---------'    `----------'
  ),

  [NUM_L] = LAYOUT_split_3x6_3(
  //,-------------------------------.    ,---------------------------.
     XXXXXXX, ____NUMBERS_L11____,       ____NUMBERS_L12____, XXXXXXX,
  //|-------+--------+-------+------|    |------+-------+---+--------|
     XXXXXXX, ____NUMBERS_L21____,       ____NUMBERS_L22____, XXXXXXX,
  //|-------+--------+-------+------|    |------+-------+---+--------|
     XXXXXXX, ____NUMBERS_L31____,       ____NUMBERS_L32____, XXXXXXX,
  //|-------+--------+-------+------|    |------+-------+---+--------|
                          __THUMB1__,     __THUMB2__
                        //`---------'    `----------'
  ),

  [CHARS_L] = LAYOUT_split_3x6_3(
  //,------------------------------------------------------------------.    ---------------------------------------------------------------------------------.
       QK_GESC,   KC_F7, LSFT(KC_7), LSFT(KC_4), LSFT(KC_2),      KC_F8,           KC_EQL, LSFT(KC_BSLS),        KC_GRV, LSFT(KC_GRV), LSFT(KC_SCLN),  KC_DEL,
  //|---------+--------+-----------+-----------+-----------+-----------|    |------------+--------------+--------------+-------------+--------------+--------|
         TD(1), XXXXXXX, LSFT(KC_8), LSFT(KC_5), LSFT(KC_1), LSFT(KC_3),          KC_LCTL,       KC_LBRC,    LSFT(KC_9),   LSFT(KC_0),       KC_RBRC,   TD(2),
  //|---------+--------+-----------+-----------+-----------+-----------|    |------------+--------------+--------------+-------------+--------------+--------|
       KC_LALT, XXXXXXX,     KC_CUT, LSFT(KC_6),     KC_APP,    KC_PSTE,     LSFT(KC_EQL), LSFT(KC_LBRC), LSFT(KC_COMM), LSFT(KC_DOT), LSFT(KC_RBRC), KC_PSCR,
  //|---------+--------+-----------+-----------+-----------+-----------|    |------------+--------------+--------------+-------------+--------------+--------|
                                        QK_LEAD,     KC_SPC,      TD(0),           KC_ENT,        KC_TAB,       KC_BSPC
                                        //`----------------------------'    `------------------------------------------'
  ),

  [MOUSE_L] = LAYOUT_split_3x6_3(
  //,-------------------------------------------------------.     ,--------------------------------------------------------.
      QK_GESC,  KC_BRID, KC_BRIU,  KC_VOLD, KC_VOLU,   KC_F9,           KC_F10,  KC_F11, KC_WH_D, KC_WH_U, KC_PSCR, QK_BOOT,
  //|--------+---------+--------+---------+--------+--------|     |-----------+--------+--------+--------+--------+--------|
        TD(1),  XXXXXXX, KC_BTN4,  KC_BTN2, KC_BTN1, KC_BTN3,           KC_F12, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R,  TO_GAM,
  //|--------+---------+--------+---------+--------+--------|     |-----------+--------+--------+--------+-----------------|
      QK_BOOT,  XXXXXXX,  KC_CUT,  KC_COPY,  KC_APP, KC_PSTE,           KC_INS, KC_WBAK, KC_PGDN, KC_PGUP, KC_WFWD, XXXXXXX,
  //|--------+---------+--------+---------+--------+--------|     |-----------+--------+--------+--------+--------+--------|
                                   QK_LEAD,  KC_SPC,   TD(0),           KC_ENT,  KC_TAB, KC_BSPC
                                   //`----------------------'     `-----------------------------'
  ),

  [GAME_L] = LAYOUT_split_3x6_3(
  //,----------------------------------------------.    ,----------------------------------------------------.
     QK_GESC,    KC_G, KC_Q,   KC_W,   KC_E,   KC_H,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|-------+--------+-----+-------+-------+-------|    |------+---------+--------+--------+--------+--------|
      KC_TAB, KC_LSFT, KC_A,   KC_S,   KC_D,   KC_F,       KC_1,     KC_2,    KC_3,    KC_4,    KC_5, XXXXXXX,
  //|-------+--------+-----+-------+-------+-------|    |------+---------+--------+--------+--------+--------|
     KC_LALT, KC_LCTL, KC_Z,   KC_X,   KC_C,   KC_V,       KC_6,     KC_7,    KC_8,    KC_9,    KC_0, XXXXXXX,
  //|-------+--------+-----+-------+-------+-------|    |------+---------+--------+--------+--------+--------|
                             KC_ENT, KC_SPC,  TD(0),     KC_ENT,   KC_TAB, KC_BSPC
                            //`--------------------'    `-------------------------'
  ),
};
