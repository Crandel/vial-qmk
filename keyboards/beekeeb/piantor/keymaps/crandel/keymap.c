// Copyright 2022 Diego Palacios (@diepala)
// SPDX-License-Identifier: GPL-2.0

#include QMK_KEYBOARD_H
#include "crd_keycodes.h"

#ifdef LEADER_ENABLE
#  include "crd_leader.c"
#endif

#ifdef TAP_DANCE_ENABLE
#  include "crd_tapdance.c"
#endif

void set_lang(bool lng){
  if (lng) {
    tap_code(KC_CAPS);
  } else {
    tap_code16(S(KC_CAPS));
  }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
  case V_US:
    if (record->event.pressed) {
      set_lang(true);
    }
    break;
  case V_UK:
    if (record->event.pressed) {
      set_lang(false);
    }
    break;
  }
  return true;
}

void keyboard_post_init_user(void) {
  // Call the post init code.
  #ifdef TAP_DANCE_ENABLE
  install_tap_dance_entries();
  #endif
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
     /*
      * ┌───┬───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┬───┐
      * │Tab│ Q │ W │ E │ R │ T │       │ Y │ U │ I │ O │ P │Bsp│
      * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
      * │Ctl│ A │ S │ D │ F │ G │       │ H │ J │ K │ L │ ; │ ' │
      * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
      * │Sft│ Z │ X │ C │ V │ B │       │ N │ M │ , │ . │ / │Sft│
      * └───┴───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┴───┘
      *               ┌───┐                   ┌───┐
      *               │GUI├───┐           ┌───┤Alt│
      *               └───┤   ├───┐   ┌───┤   ├───┘
      *                   └───┤Bsp│   │Ent├───┘
      *                       └───┘   └───┘
      */
    [COLMAK_L] = LAYOUT_split_3x6_3(
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                               KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
        KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                               KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                               KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
                                            KC_LGUI, KC_SPC, KC_BSPC,          KC_ENT, KC_SPC, KC_RALT
    )
};

  [COLMAK_L] = LAYOUT_3x5(
  //,-------------------------------------------------------.    ,---------------------------------------------------------------.
      KC_Q, RALT_T(KC_W), LCTL_T(KC_F), LSFT_T(KC_P), KC_B,         KC_E, LSFT_T(KC_I), LCTL_T(KC_U), RALT_T(KC_Y),       KC_SCLN,
  //|-----+-------------+-------------+-------------+-------|    |------+-------------+-------------+-------------+--------------|
      KC_A,         KC_R,         KC_S,         KC_T, KC_G,         KC_M,         KC_H,         KC_J,         KC_K,          KC_L,
  //|-----+-------------+-------------+-------------+-------|    |------+-------------+-------------+-------------+--------------|
      KC_Z,         KC_X,         KC_C,         KC_D, KC_V,         KC_O,         KC_N,      KC_COMM,       KC_DOT,         TD(3),
  //|-----+-------------+-------------+-------------+-------|    |------+-------------+-------------+-------------+--------------|
                                             KC_LGUI, KC_SPC,                   KC_ENT,
                                      // -----------+-------|    |------+-------------|
                                             QK_LEAD,  TD(0),                  KC_BSPC,
                                      // -----------+-------|    |------+-------------|
                                             QK_GESC, KC_DEL,       TD(2),      KC_TAB
                                      // -----------+-------|    |------+-------------|
  ),

  [NUM_L] = LAYOUT_3x5(
  //,---------------------------------------------------------.    ,------------------------------------------------------------------------.
      KC_F5, LALT_T(KC_7), LCTL_T(KC_4), LSFT_T(KC_2), KC_MINS,           KC_HOME,  LSFT_T(KC_END), LCTL_T(KC_PGDN),RALT_T(KC_PGUP), XXXXXXX,
  //|------+-------------+-------------+-------------+--------|    |-------------+----------------+----------------+---------------+--------|
      KC_F4,        KC_8 ,        KC_5 ,        KC_1 ,    KC_3,            KC_DOT,         KC_LEFT,         KC_DOWN,          KC_UP,KC_RIGHT,
  //|------+-------------+-------------+-------------+--------|    |-------------+----------------+----------------+---------------+--------|
      KC_F3,        KC_9 ,        KC_6 ,        KC_0 ,   KC_F2,           KC_BTN4,         KC_BTN1,         KC_BTN2,        KC_BTN3, KC_BSLS,
  //|------+-------------+-------------+-------------+--------|    |-------------+----------------+----------------+---------------+--------|
                                              KC_LGUI,  KC_SPC,                             KC_ENT,
                                       // -----------+-- -----|    |-------------+----------------|
                                              QK_LEAD,   TD(0),                            KC_BSPC,
                                       // -----------+--------|    |-------------+----------------|
                                               KC_DEL,   KC_F1,             TD(2),          KC_TAB
                                       // -----------+--------|    |-------------+----------------|
  ),

  [CHARS_L] = LAYOUT_3x5(
  //,--------------------------------------------------------.    ,--------------------------------------------------------------------------.
        KC_F7, LSFT(KC_7), LSFT(KC_4), LSFT(KC_2),      KC_F8,             KC_EQL, LSFT(KC_BSLS),        KC_GRV, LSFT(KC_GRV),  LSFT(KC_SCLN),
  //|--------+-----------+-----------+-----------+-----------|    |--------------+--------------+--------------+-------------+---------------|
      XXXXXXX, LSFT(KC_8), LSFT(KC_5), LSFT(KC_1), LSFT(KC_3),            KC_LCTL,       KC_LBRC,    LSFT(KC_9),   LSFT(KC_0),        KC_RBRC,
  //|--------+-----------+-----------+-----------+-----------|    |--------------+--------------+--------------+-------------+---------------|
      XXXXXXX,     KC_CUT, LSFT(KC_6),     KC_APP,    KC_PSTE,       LSFT(KC_EQL), LSFT(KC_LBRC),LSFT(KC_COMMA), LSFT(KC_DOT),  LSFT(KC_RBRC),
  //|--------+-----------+-----------+-----------+-----------|    |--------------+--------------+--------------+-------------+---------------|
                                          KC_LGUI,     KC_SPC,                            KC_ENT,
                                   // -----------+-----------|    |--------------+--------------|
                                          KC_LALT,      TD(0),                           KC_BSPC,
                                   // -----------+-----------|    |--------------+--------------|
                                           KC_DEL,    QK_GESC,              TD(2),        KC_TAB
                                   // -----------+-----------|    |--------------+--------------|
  ),

  [MOUSE_L] = LAYOUT_3x5(
  //,---------------------------------------------.    ,--------------------------------------------.
      KC_BRID, KC_BRIU,  KC_VOLD, KC_VOLU,   KC_F9,       KC_F10,  KC_F11, KC_WH_D, KC_WH_U, KC_PSCR,
  //|--------+--------+---------+--------+--------|    |--------+--------+--------+--------+--------|
      XXXXXXX, KC_BTN4,  KC_BTN2, KC_BTN1, KC_BTN3,       KC_F12, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R,
  //|--------+--------+---------+--------+--------|    |--------+--------+--------+--------+--------|
      XXXXXXX,  KC_CUT,  SNIPING, DRGSCRL, KC_PSTE,       KC_INS, KC_WBAK, KC_PGDN, KC_PGUP, KC_WFWD,
  //|--------+--------+------------------+--------|    |--------+--------+--------+--------+--------|
                                  KC_LGUI,  KC_SPC,                             KC_ENT,
                           // -----------+--------|    |-------------+----------------|
                                    TD(1),   TD(0),                            KC_BSPC,
                           // -----------+--------|    |-------------+----------------|
                                  QK_BOOT,  TO_GAM,           QK_BOOT,          KC_TAB
                           // -----------+--------|    |-------------+----------------|
  ),

  [GAME_L] = LAYOUT_3x5(
  //,-------------------------------------.    ,-------------------------------------------.
        KC_G, KC_Q,   KC_W,   KC_E,   KC_H,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|-------+-----+-------+-------+-------|    |------+---------+--------+--------+--------|
     KC_LSFT, KC_A,   KC_S,   KC_D,   KC_F,       KC_1,     KC_2,    KC_3,    KC_4,    KC_5,
  //|-------+-----+-------+-------+-------|    |------+---------+--------+--------+--------|
     KC_LCTL, KC_Z,   KC_X,   KC_C,   KC_V,       KC_6,     KC_7,    KC_8,    KC_9,    KC_0,
  //|-------+-----+-------+-------+-------|    |------+---------+--------+--------+--------|
                            KC_ENT, KC_SPC,               KC_ENT,
                          //------+-------|    |- -----+--------|
                            KC_TAB,  TD(0),              KC_BSPC,
                          //------+-------|    |-------+--------|
                           KC_LALT, TO_GAM,     XXXXXXX,  KC_TAB
                          // -----+-------|    |-------+--------|
  )
};
