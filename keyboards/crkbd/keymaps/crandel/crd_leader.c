void umlauts(uint8_t code){
    tap_code(KC_PSCR);
    tap_code16(S(KC_QUOT));
    tap_code(code);
}
void shifted_letters(uint8_t code){
  register_code(KC_LSFT);
  tap_code16(C(code));
  unregister_code(KC_LSFT);
}

void leader_end_user(void) {
  if (leader_sequence_one_key(KC_C)) {
    shifted_letters(KC_C);
    return;
  }
  if (leader_sequence_one_key(KC_V)) {
    shifted_letters(KC_V);
    return;
  }
  if (leader_sequence_one_key(KC_A)) {
    umlauts(KC_A);
    return;
  }
  if (leader_sequence_one_key(KC_E)) {
    umlauts(KC_E);
    return;
  }
  if (leader_sequence_one_key(KC_O)) {
    umlauts(KC_O);
    return;
  }
  if (leader_sequence_one_key(KC_S)) {
    tap_code(KC_PSCR);
    tap_code(KC_S);
    tap_code(KC_S);
    return;
  }
  if (leader_sequence_one_key(KC_U)) {
    umlauts(KC_U);
    return;
  }
  if (leader_sequence_one_key(KC_Q)) {
    tap_code(KC_SCLN);
    tap_code(KC_W);
    tap_code(KC_Q);
    return;
  }
  if (leader_sequence_one_key(KC_SCLN)) {
    tap_code16(A(KC_X));
    return;
  }
  if (leader_sequence_one_key(SLS_TD)) {
    tap_code16(S(KC_7));
    return;
  }
  if (leader_sequence_two_keys(KC_T, KC_T)) {
    tap_code16(A(KC_X));
    return;
  }
  if (leader_sequence_two_keys(KC_T, KC_S)) {
    tap_code16(S(KC_7));
    return;
  }  if (leader_sequence_one_key(KC_A)) {
    umlauts(KC_A);
    return;
  }
  // terminal Ctrl Shift C
  if (leader_sequence_one_key(KC_C)) {
    shifted_letters(KC_C);
    return;
  }
  if (leader_sequence_one_key(KC_E)) {
    umlauts(KC_E);
    return;
  }
  // ukrainian х
  if (leader_sequence_one_key(KC_H)) {
    tap_code(KC_LBRC);
    return;
  }
  // ukrainian ї
  if (leader_sequence_one_key(KC_I)) {
    tap_code(KC_RBRC);
    return;
  }
  if (leader_sequence_one_key(KC_O)) {
    umlauts(KC_O);
    return;
  }
  if (leader_sequence_one_key(KC_Q)) {
    tap_code(KC_SCLN);
    tap_code(KC_W);
    tap_code(KC_Q);
    return;
  }
  if (leader_sequence_one_key(KC_S)) {
    tap_code(KC_PSCR);
    tap_code(KC_S);
    tap_code(KC_S);
    return;
  }
  // terminal Ctrl Shift V
  if (leader_sequence_one_key(KC_V)) {
    shifted_letters(KC_V);
    return;
  }
  if (leader_sequence_one_key(KC_U)) {
    umlauts(KC_U);
    return;
  }
  // Emacs Alt+X
  if (leader_sequence_one_key(KC_SCLN)) {
    tap_code16(A(KC_X));
    return;
  }
  // ukrainian comma
  if (leader_sequence_one_key(KC_COMM)) {
    tap_code16(S(KC_SLSH));
    return;
  }
  // ukrainian dot
  if (leader_sequence_one_key(KC_DOT)) {
    tap_code(KC_SLSH);
    return;
  }
  // Emacs Alt+X
  if (leader_sequence_two_keys(KC_T, KC_T)) {
    tap_code16(A(KC_X));
    return;
  }
  // ukrainian ?
  if (leader_sequence_two_keys(KC_T, KC_S)) {
    tap_code16(S(KC_7));
    return;
  }
}
