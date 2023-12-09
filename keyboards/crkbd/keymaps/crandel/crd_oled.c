char layer_str[34] = {};

void update_oled_layer(const char *data){
  // update layer_str
  snprintf(layer_str,
           sizeof(layer_str),
           "%s",
           data);
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master()) {
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  }
  return rotation;
}

void oled_render_layer_state(void) {
  oled_write_P(PSTR("Layer: "), false);
  oled_write_ln(layer_str, true);
}

bool oled_task_user(void) {
  oled_render_layer_state();
  return false;
}

