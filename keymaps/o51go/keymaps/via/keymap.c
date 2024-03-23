/* Copyright 2021 ai03
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

enum custom_keycodes {
  KC_BSES = SAFE_RANGE, // "\", when ESC with KC_LCTL
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        //+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+
           KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    XXXXXXX, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSES,
        //|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
           KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    XXXXXXX, KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
        //|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
           KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    XXXXXXX, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
        //|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
           KC_RCTL, KC_LGUI, KC_LALT, TL_LOWR, TL_UPPR, KC_BSPC,          TL_LOWR, KC_SPC,  TL_UPPR, KC_RALT, KC_RGUI, KC_RCTL
        //+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+
    ),
    [1] = LAYOUT(
        //+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+
           _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    XXXXXXX, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, \
        //|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
           _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, XXXXXXX, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_UNDS, \
        //|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
           _______, KC_GRV,  KC_TILD, KC_EQL,  KC_PLUS, XXXXXXX, XXXXXXX, XXXXXXX, KC_LBRC, KC_RBRC, KC_LCBR, KC_RCBR, _______, \
        //|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
           _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______
        //+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+
    ),
    [2] = LAYOUT(
        //+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+
           _______, KC_F15,  KC_F16,  KC_F17,  KC_F18,  KC_F19,  XXXXXXX, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  XXXXXXX, KC_PSCR, \
        //|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
           _______, KC_F20,  KC_F21,  KC_F22,  KC_F23,  KC_F24,  XXXXXXX, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, XXXXXXX, KC_F12,  \
        //|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
           _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   XXXXXXX, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  \
        //|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
           _______, _______, _______, _______, _______, KC_DEL,           _______  ,KC_ENT,  _______, _______, _______, _______
        //+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+
    ),
    [3] = LAYOUT(
        //+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+
           XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
        //|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
           XXXXXXX, XXXXXXX, KC_SLEP, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_VOLD, KC_VOLU, XXXXXXX, XXXXXXX, XXXXXXX, \
        //|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
           XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_MUTE, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
        //|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
           XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
        //+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+
    ),
};

static bool lctrl_pressed = false;
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case KC_LCTL:
      if (record->event.pressed) {
        lctrl_pressed = true;
        return true;
      } else {
        lctrl_pressed = false;
        return true;
      }
      return false;
      break;
    // back slash and escape key
    case KC_BSES:
      if (record->event.pressed) {
        if (lctrl_pressed) {
          unregister_code(KC_LCTL);
          register_code(KC_ESC);
        } else {
          register_code(KC_BSLS);
        }
      } else {
        unregister_code(KC_ESC);
        unregister_code(KC_BSLS);
        if (lctrl_pressed) {
          register_code(KC_LCTL);
        }
      }
      return false;
      break;
  }
  return true;
}
