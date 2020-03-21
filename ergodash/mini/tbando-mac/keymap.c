#include QMK_KEYBOARD_H

#define _QWERTY 0
#define _SYMBOL 1
#define _FN_MOVE 2
#define _SETTING 16

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  SYNBOL,
  FN_MOVE,
  SYMBOL,
  SETTING,
  KC_BSES    // Back slash with non modifier, Escape with LCTL
};

// Layer related keycodes
#define SYMBOL   MO(_SYMBOL)
#define FN_MOVE  MO(_FN_MOVE)

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT( \
 //+--------+--------+--------+--------+--------+--------+--------+                 +--------+--------+--------+--------+--------+--------+--------+
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_SPC,                    XXXXXXX, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSES, \
 //|--------+--------+--------+--------+--------+--------+--------|                 |--------+--------+--------+--------+--------+--------+--------|
    KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_ENT,                    KC_B   , KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
 //|--------+--------+--------+--------+--------+--------+--------|                 |--------+--------+--------+--------+--------+--------+--------|
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_BSPC,                   SYMBOL,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, \
 //|--------+--------+--------+--------+--------+--------|        |--------+--------|        |--------+--------+--------+--------+--------+--------|
    KC_LCTL, KC_LALT, KC_LGUI,          SYMBOL,  FN_MOVE, KC_BSPC, XXXXXXX, XXXXXXX, SYMBOL,  KC_SPC,  FN_MOVE,          KC_RGUI, KC_RALT, KC_RCTL  \
 //+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+
  ),

  [_SYMBOL] = LAYOUT(
 //+--------+--------+--------+--------+--------+--------+--------+                 +--------+--------+--------+--------+--------+--------+--------+
    _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    XXXXXXX,                   XXXXXXX, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, \
 //|--------+--------+--------+--------+--------+--------+--------|                 |--------+--------+--------+--------+--------+--------+--------|
    _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, XXXXXXX,                   XXXXXXX, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_UNDS, \
 //|--------+--------+--------+--------+--------+--------+--------|                 |--------+--------+--------+--------+--------+--------+--------|
    _______, KC_GRV,  KC_TILD, KC_EQL,  KC_PLUS, XXXXXXX, _______,                   _______, XXXXXXX, KC_LBRC, KC_RBRC, KC_LCBR, KC_RCBR, XXXXXXX, \
 //|--------+--------+--------+--------+--------+--------|        |--------+--------|        |--------+--------+--------+--------+--------+--------|
    _______, _______, _______,          _______, _______, _______, XXXXXXX, XXXXXXX, _______, _______, _______,          _______, _______, _______  \
 //|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
  ),

  [_FN_MOVE] = LAYOUT(
 //+--------+--------+--------+--------+--------+--------+--------+                 +--------+--------+--------+--------+--------+--------+--------+
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  XXXXXXX, XXXXXXX, \
 //|--------+--------+--------+--------+--------+--------+--------|                 |--------+--------+--------+--------+--------+--------+--------|
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, XXXXXXX, KC_F12,  \
 //|--------+--------+--------+--------+--------+--------+--------|                 |--------+--------+--------+--------+--------+--------+--------|
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_DEL,                    _______, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  \
 //|--------+--------+--------+--------+--------+--------|        |--------+--------|        |--------+--------+--------+--------+--------+--------|
    _______, _______, _______,          _______, _______, KC_DEL,  XXXXXXX, XXXXXXX, _______, KC_ENT,  _______,          _______, _______, _______  \
 //|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
    ),

  [_SETTING] = LAYOUT(
 //+--------+--------+--------+--------+---------+--------+--------+                 +--------+--------+--------+--------+--------+--------+--------+
    _______, RESET  , RGB_TOG, RGB_MOD, RGB_HUD,  RGB_HUI, _______,                   _______, RGB_SAD, RGB_SAI, RGB_VAD, RGB_VAI, _______, _______, \
 //+--------+--------+--------+--------+---------+--------+--------+                 +--------+--------+--------+--------+--------+--------+--------+
    _______, _______, BL_TOGG, BL_BRTG, BL_INC ,  BL_DEC,  _______,                   _______, _______, _______, _______, _______, _______, _______, \
 //+--------+--------+--------+--------+---------+--------+--------+                 +--------+--------+--------+--------+--------+--------+--------+
    _______, _______, _______, _______, _______,  _______, _______,                   _______, _______, _______, _______, _______, _______, _______, \
 //|--------+--------+--------+--------+---------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
    _______, _______, _______,          _______,  _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______  \
 //|--------+--------+--------+--------+---------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
  )
};

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
