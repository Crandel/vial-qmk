#pragma once

void set_indicators_state(uint8_t hue, uint8_t sat, uint8_t val, const char *data){
  #ifdef OLED_ENABLE
  update_oled_layer(data);
  #endif // OLED_ENABLE
  #ifdef RGBLIGHT_ENABLE
  rgblight_sethsv(hue, sat, val);
  #endif // RGBLIGHT_ENABLE
}
