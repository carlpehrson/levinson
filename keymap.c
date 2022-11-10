#include QMK_KEYBOARD_H
#include "keymap_extras/keymap_swedish_pro_mac_ansi.h"

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
enum layer_names {
    _WORKMAN,
    _LOWER,
    _RAISE,
    _ADJUST
};

enum custom_keycodes {
  WORKMAN = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Workman
 * ,------------------------------------------   -----------------------------------------.
 * | Tab  |   Q  |   D  |   R  |   W  |   B  |      J  |   F  |   U  |   P  |   '  | Bksp |
 * |------+------+------+------+------+-------   ------+------+------+------+------+------|
 * |CtlEsc|   A  |   S  |   H  |   T  |   G  |      Y  |   N  |   E  |   O  |   I  |Enter |
 * |------+------+------+------+------+------|   ------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   M  |   C  |   V  |      K  |   L  |   <  |   ,  |   .  | Ctrl |
 * |------+------+------+------+------+------+   ------+------+------+------+------+------|
 * |   |  | Ctrl | Ctrl | Alt  | GUI  |Space |   Lower |Raise | Left | Down |  Up  |Right |
 * `------------------------------------------   -----------------------------------------'
 */
[_WORKMAN] = LAYOUT_ortho_4x12(
  KC_TAB,         KC_Q,    KC_D,    KC_R,    KC_W,    KC_B,        KC_J,    KC_F,    KC_U,    KC_P,     SE_QUOT, KC_BSPC,
  CTL_T(KC_ESC),  KC_A,    KC_S,    KC_H,    KC_T,    KC_G,        KC_Y,    KC_N,    KC_E,    KC_O,     KC_I,    KC_ENT,
  KC_LSFT,        KC_Z,    KC_X,    KC_M,    KC_C,    KC_V,        KC_K,    KC_L,    SE_LABK, KC_COMM,  KC_DOT,  KC_LCTL ,
  SE_PIPE,        KC_LCTL, KC_LCTL, KC_LALT, KC_LGUI, KC_SPC,      LOWER,   RAISE,   KC_LEFT, KC_DOWN,  KC_UP,   KC_RGHT
),

/* Lower
 * ,------------------------------------------  -----------------------------------------.
 * |   ~  |   !  |   @  |   ?  |   $  |   %  |     &  |   1  |   2  |   3  |   4  | Bksp |
 * |------+------+------+------+------+-------  ------+------+------+------+------+------|
 * |   "  |      |      |      |      |      |        |   5  |   6  |   7  |   8  |  9   |
 * |------+------+------+------+------+------|  ------+------+------+------+------+------|
 * |      |      |      |   [  |   ]  |      |        |   0  |   Ö  |   Ä  |   Å  |      |
 * |------+------+------+------+------+------+  ------+------+------+------+------+------|
 * |      |      |      |      |      |               |      |      | Vol- | Vol+ |     |
 * `------------------------------------------  -----------------------------------------'
 */
[_LOWER] = LAYOUT_ortho_4x12(
  SE_TILD, KC_EXLM, SE_AT,   SE_QUES, SE_DLR,  KC_PERC,    SE_AMPR, KC_1,    KC_2,    KC_3,    KC_4,    _______,
  SE_DQUO, _______, _______, _______, _______, _______,    _______, KC_5,    KC_6,    KC_7,    KC_8,    KC_9,
  _______, _______, _______, SE_LBRC, SE_RBRC, _______,    _______, KC_0,    SE_ODIA, SE_ADIA, SE_ARNG, _______,
  _______, _______, _______, _______, _______, _______,    _______, _______, _______, KC_VOLD, KC_VOLU, _______
),

/* Raise
 * ,------------------------------------------  -----------------------------------------.
 * |   ´  |   |  |   #  |   %  |   $  |   ^  |        |      |      |      |      | Bksp |
 * |------+------+------+------+------+-------  ------+------+------+------+------+------|
 * |   `  |   /  |   *  |   (  |   )  |  "   |     &  |      |   =  |  Up  | Down |  \   |
 * |------+------+------+------+------+------|  ------+------+------+------+------+------|
 * |      |   -  |   +  |   {  |   }  |   ^  |        |   _  |      | Left | Right|      |
 * |------+------+------+------+------+------+  ------+------+------+------+------+------|
 * |      |      |      |      |      |               |      |      |      |      |      |
 * `------------------------------------------  -----------------------------------------'
 */
[_RAISE] = LAYOUT_ortho_4x12(
  SE_ACUT,       SE_PIPE,     KC_HASH, KC_PERC,     SE_DLR,      SE_CIRC,    _______, _______, _______, _______, _______,  _______,
  LSFT(SE_ACUT), SE_SLSH,     SE_ASTR, SE_LPRN,     SE_RPRN,     SE_QUOT,    SE_AMPR, _______, SE_EQL,  KC_UP,   KC_DOWN,  SE_BSLS,
  _______,       SE_MINS,     SE_PLUS, SE_LCBR,     SE_RCBR    , SE_CIRC,    _______, SE_UNDS, _______, KC_LEFT, KC_RIGHT, _______,
  _______,       _______,     _______, _______,     _______,     _______,    _______, _______, _______, _______, _______,  _______
),

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |      | Reset|      |      |      |      |      |      |      |      |      |  Del |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |Aud on|Audoff|AGnorm|AGswap|Qwerty|Colemk|Dvorak|      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] =  LAYOUT_ortho_4x12(
  _______, QK_BOOT,   _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_DEL,
  _______, _______, _______, AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, _______,  _______, _______,  _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
)


};

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case WORKMAN:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(tone_colemak);
        #endif
        persistent_default_layer_set(1UL<<_WORKMAN);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case ADJUST:
      if (record->event.pressed) {
        layer_on(_ADJUST);
      } else {
        layer_off(_ADJUST);
      }
      return false;
      break;
  }
  return true;
}
