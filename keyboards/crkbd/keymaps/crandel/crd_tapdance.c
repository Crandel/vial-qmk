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
#include "crd_keycodes.h"
#include QMK_KEYBOARD_H

#define TAP_TAPPING_TERM 220
void install_tap_dance_entries(void) {
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
