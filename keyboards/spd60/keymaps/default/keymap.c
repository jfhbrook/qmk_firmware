#include "spd60.h"
#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
enum custom_layers
{
	_QWERTY,
	_FUNCTION
};

enum custom_keycodes
{
  QWERTY = SAFE_RANGE,
  FUNCTION
};

// Fillers to make layering more clear
#define XXXXXXX KC_NO
#define _______ KC_TRNS

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_QWERTY] = LAYOUT_60_ansi( \

			        KC_ESC,      KC_1,    KC_2,    KC_3,   KC_4,   KC_5,  KC_6, KC_7,    KC_8,     KC_9,    KC_0,  KC_BSPC, \
				KC_TAB,      KC_Q,    KC_W,    KC_E,   KC_R,   KC_T,  KC_Y, KC_U,    KC_I,     KC_O,    KC_P,  KC_BSPC, \
				KC_TAB,      KC_A,    KC_S,    KC_D,   KC_F,   KC_G,  KC_H, KC_J,    KC_K,     KC_L, KC_SCLN,  KC_QUOT, \
				KC_LSFT,      KC_Z,    KC_X,    KC_C,   KC_V,   KC_B,  KC_N, KC_M, KC_COMM,  KC_DOT, KC_SLSH,  KC_NO ,	\
		                KC_LCTL,   KC_LALT, KC_LGUI,  KC_NO, KC_SPC, KC_SPC, KC_SPC,KC_NO, KC_NO, FUNCTION,  KC_RCTL,  KC_ENT	\
),

[_FUNCTION] = LAYOUT_60_ansi( \
		
		KC_GRV,    KC_1,   KC_2,   KC_3,     KC_4,    KC_5,   KC_6,    KC_7,    KC_8,    KC_9,    KC_0,  KC_DEL,	\
		KC_GRV,    KC_1,   KC_2,   KC_3,     KC_4,    KC_5,   KC_6,    KC_7,    KC_8,    KC_9,    KC_0,  KC_DEL,	\
		KC_TILD,  KC_F1,  KC_F2,  KC_F3,    KC_F4,   KC_F5,  KC_F6, KC_PLUS, KC_MINS,  KC_EQL, KC_RBRC, KC_BSLS,	\
		KC_LSFT,  KC_F7,  KC_F8,  KC_F9,   KC_F10,  KC_F11, KC_F12, KC_NUHS, KC_NUBS,  KC_INS, KC_RSFT, KC_NO,	\
		KC_LCTL,  KC_F9, KC_F10,  KC_NO,  KC_PGDN, KC_PGUP,  KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_VOLU, KC_MPLY	\
) 


};
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
     case FUNCTION:
      if (record->event.pressed) {
        layer_on(_FUNCTION);
      } else {
        layer_off(_FUNCTION);
      }
      return false;
      break;

  }
  return true;
}

void matrix_scan_user(void) {
		return;
};
