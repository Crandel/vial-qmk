#include QMK_KEYBOARD_H
#include "vial.h"

#include "crd_keycodes.h"

#ifdef OLED_ENABLE
#  include <stdio.h>
#  include "crd_oled.c"
#endif

#include "crd_helpers.c"

#ifdef LEADER_ENABLE
#  include "crd_leader.c"
#endif

#ifdef TAP_DANCE_ENABLE
#  include "crd_tapdance.c"
#endif

#ifdef RGBLIGHT_ENABLE
layer_state_t default_layer_state_set_user(layer_state_t state) {
  #ifdef CONSOLE_ENABLE
  uprintf("current state in default_layer_state_set_user %d, biton %d\n", state, biton32(state));
  #endif // CONSOLE_ENABLE
  switch (biton32(state)) {
    case COLMAK_L:
      set_indicators_state(CR_HSV_GREEN, "Colemak");
      break;
    case NUM_L:
      set_indicators_state(CR_HSV_BLUE, "Numbers");
      break;
    case CHARS_L:
      set_indicators_state(CR_HSV_GOLD, "Chars");
      break;
    case MOUSE_L:
      set_indicators_state(CR_HSV_ORANGE, "Mouse");
      break;
    case GAME_L:
      set_indicators_state(CR_HSV_RED, "Games");
      break;
  }
  return state;
};
#endif // RGBLIGHT_ENABLE

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

