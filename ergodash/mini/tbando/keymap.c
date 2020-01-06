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
  SETTING
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
    KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_MINS,                   KC_EQL,  KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS, \
 //|--------+--------+--------+--------+--------+--------+--------|                 |--------+--------+--------+--------+--------+--------+--------|
    KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_LBRC,                   KC_RBRC, KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
 //|--------+--------+--------+--------+--------+--------+--------|                 |--------+--------+--------+--------+--------+--------+--------|
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_SPC,                    KC_ENT , KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, \
 //|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
    KC_LCTL, KC_LGUI, KC_LALT, EISU,             SYMBOL,   KC_SPC,  KC_DEL,  KC_BSPC, KC_ENT , FN_MOVE,            KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT  \
 //+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+
  ),

  [_SYMBOL] = LAYOUT(
 //+--------+--------+--------+--------+---------+--------+--------+                 +--------+--------+--------+--------+--------+--------+--------+
    KC_GRV , KC_EXLM, KC_AT,   KC_HASH, KC_DLR,   KC_PERC, KC_UNDS,                   KC_PLUS, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_PIPE, \
 //|--------+--------+--------+--------+---------+--------+--------|                 |--------+--------+--------+--------+--------+--------+--------|
    KC_TILD, KC_1,    KC_2,    KC_3,    KC_4,     KC_5,    KC_LCBR,                   KC_RCBR, KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT, KC_COLN, KC_DQT , \
 //|--------+--------+--------+--------+---------+--------+--------|                 |--------+--------+--------+--------+--------+--------+--------|
    KC_LSFT, KC_6,    KC_7,    KC_8,    KC_9,     KC_0,    KC_SPC ,                   KC_ENT , KC_N,    KC_M,    KC_LT,   KC_GT,   KC_QUES, KC_RSFT, \
 //|--------+--------+--------+--------+---------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
    KC_LCTL, KC_LGUI, KC_LALT, EISU,              SYMBOL,   KC_SPC , KC_DEL,  KC_BSPC, KC_ENT , FN_MOVE,            KC_HOME, KC_PGDN, KC_PGUP, KC_END   \
 //|--------+--------+--------+--------+---------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
  ),

  [_FN_MOVE] = LAYOUT(
 //+--------+--------+--------+--------+---------+--------+--------+                 +--------+--------+--------+--------+--------+--------+--------+
    KC_GRV , KC_EXLM, KC_AT,   KC_HASH, KC_DLR,   KC_PERC, KC_UNDS,                   KC_PLUS, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_PIPE, \
 //|--------+--------+--------+--------+---------+--------+--------|                 |--------+--------+--------+--------+--------+--------+--------|
    KC_TILD, KC_F1,   KC_F2,   KC_F3,   KC_F4,    KC_F5,   KC_LCBR,                   KC_RCBR, KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT, KC_COLN, KC_DQT , \
 //|--------+--------+--------+--------+---------+--------+--------|                 |--------+--------+--------+--------+--------+--------+--------|
    KC_LSFT, KC_F6,   KC_F7,   KC_F8,   KC_F9,    KC_F10,  KC_SPC ,                   KC_ENT,  KC_N,    KC_M,    KC_LT,   KC_GT,   KC_QUES, KC_RSFT, \
 //|--------+--------+--------+--------+---------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
    KC_LCTL, KC_F11 , KC_F12,  EISU,              SYMBOL,   KC_SPC , KC_DEL,  KC_BSPC, KC_ENT,  FN_MOVE,            KC_HOME, KC_PGDN, KC_PGUP, KC_END   \
 //|--------+--------+--------+--------+---------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
    ),

  [_SETTING] = LAYOUT(
 //+--------+--------+--------+--------+---------+--------+--------+                 +--------+--------+--------+--------+--------+--------+--------+
    _______, RESET  , RGB_TOG, RGB_MOD, RGB_HUD,  RGB_HUI, _______,                   _______, RGB_SAD, RGB_SAI, RGB_VAD, RGB_VAI, _______, _______, \
 //+--------+--------+--------+--------+---------+--------+--------+                 +--------+--------+--------+--------+--------+--------+--------+
    _______, _______, BL_TOGG, BL_BRTG, BL_INC ,  BL_DEC,  _______,                   _______, _______, _______, _______, _______, _______, _______, \
 //+--------+--------+--------+--------+---------+--------+--------+                 +--------+--------+--------+--------+--------+--------+--------+
    _______, _______, _______, _______, _______,  _______, _______,                   _______, _______, _______, _______, _______, _______, _______, \
 //|--------+--------+--------+--------+---------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
    _______, _______, _______, _______,           _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______  \
 //|--------+--------+--------+--------+---------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
  )
};

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
    case SETTING:
      if (record->event.pressed) {
        layer_on(_SETTING);
      } else {
        layer_off(_SETTING);
      }
      return false;
      break;
  }
  return true;
}
