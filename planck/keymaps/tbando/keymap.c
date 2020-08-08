/* Copyright 2015-2017 Jack Humbert
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H
#include "muse.h"


enum planck_layers {
  _QWERTY,
  _SYMBOL,
  _FN_MOVE,
  _SETTING
};

enum planck_keycodes {
  QWERTY = SAFE_RANGE,
  SYMBOL,
  FN_MOVE,
  SETTING,
  KC_BSES    // Back slash with non modifier, Escape with LCTL
};

//#define LOWER MO(_LOWER)
//#define RAISE MO(_RAISE)

#define SYMBOL   MO(_SYMBOL)
#define FN_MOVE  MO(_FN_MOVE)
#define FN_MOVE  MO(_FN_MOVE)

#define _______ KC_TRNS
#define XXXXXXX KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_QWERTY] = LAYOUT_planck_grid(
 //+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSES,
 //|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
    KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
 //|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
 //|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
    KC_RCTL, KC_LGUI, KC_LALT, SYMBOL,  FN_MOVE, KC_BSPC, KC_SPC,  FN_MOVE, SYMBOL,  KC_RALT, KC_RGUI, KC_RCTL
 //+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+
), 


[_SYMBOL] = LAYOUT_planck_grid(
 //+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+
    _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, \
 //|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
    _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_UNDS, \
 //|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
    _______, KC_GRV,  KC_TILD, KC_EQL,  KC_PLUS, XXXXXXX, XXXXXXX, KC_LBRC, KC_RBRC, KC_LCBR, KC_RCBR, _______, \
 //|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ 
 //+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+
),

[_FN_MOVE] = LAYOUT_planck_grid(
 //+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  XXXXXXX, XXXXXXX, \
 //|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, XXXXXXX, KC_F12,  \
 //|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  \
 //|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
    _______, _______, _______, _______, _______, KC_DEL,  KC_ENT,  _______, _______, _______, _______, _______
 //+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+
),

[_SETTING] = LAYOUT_planck_grid(
 //+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, RESET,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
 //|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
 //|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
 //|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
 //+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+
)

};

#ifdef AUDIO_ENABLE
  float plover_song[][2]     = SONG(PLOVER_SOUND);
  float plover_gb_song[][2]  = SONG(PLOVER_GOODBYE_SOUND);
#endif

// layer_state_t layer_state_set_user(layer_state_t state) {
//   return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
// }

static bool lctrl_pressed = false;
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case SYMBOL:
      if (record->event.pressed) {
        layer_on(_SYMBOL);
        update_tri_layer(_SYMBOL, _FN_MOVE, _SETTING);
      } else {
        layer_off(_SYMBOL);
        update_tri_layer(_SYMBOL, _FN_MOVE, _SETTING);
      }
      return false;
      break;
    case FN_MOVE:
      if (record->event.pressed) {
        layer_on(_FN_MOVE);
        update_tri_layer(_SYMBOL, _FN_MOVE, _SETTING);
      } else {
        layer_off(_FN_MOVE);
        update_tri_layer(_SYMBOL, _FN_MOVE, _SETTING);
      }
      return false;
      break;

    // back slash and escape key
    case KC_BSES:
      if (record->event.pressed) {
        if (lctrl_pressed) {
          unregister_code(KC_LCTRL);
          register_code(KC_ESC);
        } else {
          register_code(KC_BSLS);
        }
      } else {
        unregister_code(KC_ESC);
        unregister_code(KC_BSLS);
        if (lctrl_pressed) {
          register_code(KC_LCTRL);
        }
      }
      return false;
      break;
  }
  if (record->event.pressed) {
    switch (keycode) {
    case KC_LCTRL:
      lctrl_pressed = true;
      return true;
    }
  }
  else if (!record->event.pressed) {
    switch (keycode) {
    case KC_LCTRL:
      lctrl_pressed = false;
      return true;
    }
  }
  return true;
}

bool muse_mode = false;
uint8_t last_muse_note = 0;
uint16_t muse_counter = 0;
uint8_t muse_offset = 70;
uint16_t muse_tempo = 50;

//void encoder_update(bool clockwise) {
//  if (muse_mode) {
//    if (IS_LAYER_ON(_RAISE)) {
//      if (clockwise) {
//        muse_offset++;
//      } else {
//        muse_offset--;
//      }
//    } else {
//      if (clockwise) {
//        muse_tempo+=1;
//      } else {
//        muse_tempo-=1;
//      }
//    }
//  } else {
//    if (clockwise) {
//      #ifdef MOUSEKEY_ENABLE
//        tap_code(KC_MS_WH_DOWN);
//      #else
//        tap_code(KC_PGDN);
//      #endif
//    } else {
//      #ifdef MOUSEKEY_ENABLE
//        tap_code(KC_MS_WH_UP);
//      #else
//        tap_code(KC_PGUP);
//      #endif
//    }
//  }
//}

//void dip_switch_update_user(uint8_t index, bool active) {
//    switch (index) {
//        case 0: {
//#ifdef AUDIO_ENABLE
//            static bool play_sound = false;
//#endif
//            if (active) {
//#ifdef AUDIO_ENABLE
//                if (play_sound) { PLAY_SONG(plover_song); }
//#endif
//                layer_on(_ADJUST);
//            } else {
//#ifdef AUDIO_ENABLE
//                if (play_sound) { PLAY_SONG(plover_gb_song); }
//#endif
//                layer_off(_ADJUST);
//            }
//#ifdef AUDIO_ENABLE
//            play_sound = true;
//#endif
//            break;
//        }
//        case 1:
//            if (active) {
//                muse_mode = true;
//            } else {
//                muse_mode = false;
//            }
//    }
//}
//
//void matrix_scan_user(void) {
//#ifdef AUDIO_ENABLE
//    if (muse_mode) {
//        if (muse_counter == 0) {
//            uint8_t muse_note = muse_offset + SCALE[muse_clock_pulse()];
//            if (muse_note != last_muse_note) {
//                stop_note(compute_freq_for_midi_note(last_muse_note));
//                play_note(compute_freq_for_midi_note(muse_note), 0xF);
//                last_muse_note = muse_note;
//            }
//        }
//        muse_counter = (muse_counter + 1) % muse_tempo;
//    } else {
//        if (muse_counter) {
//            stop_all_notes();
//            muse_counter = 0;
//        }
//    }
//#endif
//}

//bool music_mask_user(uint16_t keycode) {
//  switch (keycode) {
//    case RAISE:
//    case LOWER:
//      return false;
//    default:
//      return true;
//  }
//}
