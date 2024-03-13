/*
Copyright 2024 Vitalii Drevenchuk <cradlemann@gmail.com> @crandel

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
#pragma once

#ifndef USERSPACE
#define USERSPACE

#include "crd_keycodes.h"

#ifdef DEBUG_ENABLE
#include "print.h"
// Disable options
#ifndef NO_DEBUG
#define NO_DEBUG
#endif // !NO_DEBUG
#ifndef NO_PRINT
#define NO_PRINT
#endif // !NO_PRINT
#undef LOCKING_SUPPORT_ENABLE
#undef LOCKING_RESYNC_ENABLE
#define NO_ACTION_ONESHOT
#define NO_MUSIC_MODE
#endif

#define LAYER_STATE_8BIT
#define TAPPING_TERM   260
#define TAPPING_TOGGLE 3
#define PERMISSIVE_HOLD

#ifdef LEADER_ENABLE
#  define LEADER_NO_TIMEOUT
#  define LEADER_PER_KEY_TIMING
void umlauts(uint8_t code)
void shifted_letters(uint8_t code)
#endif

#ifdef OLED_ENABLE
void update_oled_layer(const char* data)
#endif

void set_indicators_state(uint8_t hue, uint8_t sat, uint8_t val, const char *data)

void set_lang(bool lng)
#endif
