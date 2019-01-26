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
#ifdef AUDIO_ENABLE
#include "audio.h"
#endif
#include "eeconfig.h"


extern keymap_config_t keymap_config;

enum planck_layers {
  _QWERTY,
  _COLEMAK,
  _LOWER,
  _RAISE,
  _ADJUST,
  _FN,
  _NUMPAD
};

enum planck_keycodes {
  QWERTY = SAFE_RANGE,
  COLEMAK,
  NUMPAD,
  TSK_MNG,
  EXT_APP,
  NEQL,
  EQUIV,
  AND,
  OR,
  LTHNEQ,
  RTHNEQ,
  SHFT_CAP,
  ENT_SHFT
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define FN MO(_FN)
#define PRTSCN LALT(KC_PSCR)
#define DSKTP LGUI(KC_D)
#define LCK_SCN LGUI(KC_L)
#define ENT_SHFT MT(MOD_RSFT, KC_ENT)

#ifdef TAP_DANCE_ENABLE
#define EXT_APP TD(0)
#endif

#ifdef TAP_DANCE_ENABLE
qk_tap_dance_action_t tap_dance_actions[] = {
    [0]  = ACTION_TAP_DANCE_DOUBLE(KC_LSFT, KC_CAPS)
};
#endif

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl |   FN  |GUI  | Alt |Lower |    Space    |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_planck_grid(
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
    KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, ENT_SHFT,
    KC_LCTL, FN,      KC_LGUI, KC_LALT,  LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
),

/* Colemak
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   F  |   P  |   G  |   J  |   L  |   U  |   Y  |   ;  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   R  |   S  |   T  |   D  |   H  |   N  |   E  |   I  |   O  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   K  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl |  FN  | GUI  |  FN  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_COLEMAK] = LAYOUT_planck_grid(
    KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_BSPC,
    KC_ESC,  KC_A,    KC_R,    KC_S,    KC_T,    KC_D,    KC_H,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, ENT_SHFT,
    KC_LCTL, FN,      KC_LGUI, KC_LALT, LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
),

/* Lower
* ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   -  |   =  |   [  |   ]  |  \   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO # |ISO / |Pg Up |Pg Dn |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_planck_grid(
    KC_GRV,  KC_1,       KC_2,     KC_3,      KC_4,      KC_5,      KC_6,      KC_7,    KC_8,    KC_9,     KC_0,    KC_BSPC,
    KC_DEL,  KC_PMNS,   KC_EQL,   KC_LCBR,   KC_RCBR,   KC_BSLS,   KC_LEFT,   KC_DOWN, KC_UP,   KC_RIGHT, _______, KC_BSLS,
    _______, _______,    _______,  _______,   _______,  _______,   _______,    _______, _______, _______,  _______, _______,
    _______, _______,    _______, _______,    _______,  _______,   _______,    _______, KC_HOME, KC_PGDN,  KC_PGUP, KC_END
), 

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |  ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   _  |   +  |   {  |   }  |  |   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO ~ |ISO | | Home | End  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_planck_grid(
    KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR,  KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC,
    KC_DEL,  KC_UNDS, KC_PLUS, KC_LBRC, KC_RBRC, KC_PIPE, KC_HOME, KC_PGDN,  KC_PGUP, KC_END,  _______, KC_PIPE,
    _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, KC_MUTE, KC_MPLY,
    _______, _______, _______, _______, _______, _______, _______, _______,  KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT  
),

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |      | Reset|      |      |      |      |      |      |      |      |      |  Del |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |Aud on|Audoff|AGnorm|AGswap|Qwerty|Colemk|Dvorak|Plover|      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |Voice-|Voice+|Mus on|Musoff|MIDIon|MIDIof|      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_planck_grid(
    QWERTY,  _______,   _______,  LTHNEQ,    RTHNEQ,    _______, KC_PGUP, KC_HOME, KC_UP,   KC_END,   _______, KC_PWR,
    COLEMAK, _______,   _______,  AND,     OR,      _______, KC_PGDN, KC_LEFT, KC_DOWN, KC_RIGHT, _______, DSKTP,
    NUMPAD,  _______,   _______,  NEQL,    EQUIV,   _______, _______, _______, _______, _______,  _______, _______,
    _______, _______,   _______,  _______, _______, _______, _______, _______, _______, _______,  _______, RESET
),

[_FN] = LAYOUT_planck_grid(
    PRTSCN,  KC_F1,   KC_F2,   KC_F3,   EXT_APP, _______, _______, _______, _______, _______, _______, KC_SLEP ,
    TSK_MNG, KC_F5,   KC_F6,   KC_F7,   KC_F8,   _______, _______, _______, _______, _______, _______, KC_WAKE,
    DSKTP,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, _______, _______, _______, _______, _______, _______,
    LCK_SCN, _______, _______, _______, _______, KC_CALC, KC_CALC, _______, MU_ON,   MU_OFF,  AU_ON,   AU_OFF 
),

[_NUMPAD] = LAYOUT_planck_grid(
    QWERTY, KC_TAB,   KC_UP,    _______,  _______,  _______, _______, KC_PSLS, KC_P7, KC_P8,   KC_P9,   KC_PMNS ,
    COLEMAK, KC_LEFT, KC_DOWN,  KC_RIGHT, _______,  _______, _______, KC_PAST, KC_P4, KC_P5,   KC_P6,   KC_PSLS,
    KC_LSFT, _______, _______,  _______,  _______,  _______, _______, KC_BSPC, KC_P1, KC_P2,   KC_P3,   KC_PENT,
    KC_LCTL, FN,      KC_LGUI, KC_LALT,   LOWER,    KC_SPC,  KC_SPC,  RAISE,   KC_P0, KC_PDOT, KC_PCMM, KC_PEQL
)

};

#ifdef AUDIO_ENABLE
  float qwerty_song[][2] = SONG(QWERTY_SOUND);
  float colemak_song[][2] = SONG(COLEMAK_SOUND);
  float tone_numpad[][2] = SONG(NUM_LOCK_ON_SOUND);
#endif

uint32_t layer_state_set_user(uint32_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWERTY);
        #ifdef AUDIO_ENABLE
          stop_all_notes();
          PLAY_SONG(qwerty_song);
        #endif
      }
      return false;
      break;
    case COLEMAK:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_COLEMAK);
        #ifdef AUDIO_ENABLE
          stop_all_notes();
          PLAY_SONG(colemak_song);
        #endif
      }
      return false;
      break;

    case NUMPAD:
      if (record->event.pressed) {
        if (!IS_LAYER_ON(_NUMPAD)) {
          #ifdef AUDIO_ENABLE
          stop_all_notes();
          PLAY_SONG(tone_numpad);
          #endif
          layer_on(_NUMPAD);
        }

      }
      return false;
      break;
    case NEQL:
      if (record->event.pressed) {
          send_string("!=");
      }
      break;
    case EQUIV:
      if (record->event.pressed) {
          send_string("==");
      }
      break;
    case AND:
      if (record->event.pressed) {
          send_string("&&");
      }
      break;
    case OR:
      if (record->event.pressed) {
          send_string("||");
      }
      break;
    case LTHNEQ:
      if (record->event.pressed) {
          send_string("<=");
      }
      break;
    case RTHNEQ:
      if (record->event.pressed) {
          send_string(">=");
      }
      break;
  }
  return true;
}
