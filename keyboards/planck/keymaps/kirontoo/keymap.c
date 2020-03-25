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

extern keymap_config_t keymap_config;

enum planck_layers {
  _QWERTY,
  _COLEMAK,
  _LOWER,
  _RAISE,
  _FN1,
  _FN2
};

enum planck_keycodes {
  QWERTY = SAFE_RANGE,
  COLEMAK,
  OW_THM,
  IMP_MRCH,
  // Encoder Mods
  ENC_ALT,
  ENC_GUI,
  ENC_CTRL,
  G_SWAP,
  NEQL,
  LEQL,
  GEQL
};

#define MEDIA_KEY_DELAY 10

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define FN1 MO(_FN1)
#define FN2 LT(_FN2, KC_LEFT)

// define songs
#ifdef AUDIO_ENABLE
float imperial_march[][2]  = SONG(IMPERIAL_MARCH);
float overwatch_theme[][2] = SONG(OVERWATCH_THEME);
#endif

// shortcuts
#define TSK_MNG LCTL(LSFT(KC_ESC))
#define LCK_SCRN LGUI(KC_L)
#define DSKTOP LGUI(KC_D)
#define PSCRN LALT(KC_PSCR)

// Modifier Tap
#define CTRL_TAP RCTL_T(KC_RIGHT)
#define GUI_TAP RGUI_T(KC_UP)
#define ALT_TAP RALT_T(KC_DOWN)
#define ESC_TAP LGUI_T(KC_ESC)


// One Shot Layers and Mods
#define OSL_LWR OSL(_LOWER)
#define OSL_RAS OSL(_RAISE)
#define OSM_LST OSM(MOD_LSFT)
#define OSM_RST OSM(MOD_RSFT)

// Tap Dance define
#ifdef TAP_DANCE_ENABLE
#define EXT_APP TD(0)
#endif

#ifdef TAP_DANCE_ENABLE
qk_tap_dance_action_t tap_dance_actions[] = {
  // tap once for F4, twice for ALT+F4
  [0] = ACTION_TAP_DANCE_DOUBLE(KC_F4, LALT(KC_F4)),
};
#endif

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_QWERTY] = LAYOUT_planck_grid(
    KC_MPLY, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_TAB,
    ESC_TAP, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT,
    OSM_LST, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, OSM_RST,
    KC_LCTL, KC_LGUI, FN1,     KC_LALT, OSL_LWR, KC_SPC,  KC_BSPC, OSL_RAS, FN2,     ALT_TAP, GUI_TAP, CTRL_TAP
),

[_COLEMAK] = LAYOUT_planck_grid(
    KC_MPLY,   KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_TAB,
    ESC_TAP,   KC_A,    KC_R,    KC_S,    KC_T,    KC_D,    KC_H,    KC_N,    KC_E,    KC_I,    KC_O,    KC_ENT,
    OSM_LST,   KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, OSM_RST,
    ENC_CTRL,  ENC_GUI, FN1,     ENC_ALT, OSL_LWR, KC_SPC,  KC_BSPC, OSL_RAS, FN2,     ALT_TAP, GUI_TAP, CTRL_TAP
),

[_RAISE] = LAYOUT_planck_grid(
    _______, KC_F1,    KC_F2,    KC_F3,    EXT_APP, XXXXXXX,  XXXXXXX, XXXXXXX,  XXXXXXX,   XXXXXXX,  KC_TILD, KC_GRV,
    _______, KC_F5,    KC_F6,    KC_F7,      KC_F8, XXXXXXX,  KC_LEFT, KC_DOWN,    KC_UP,  KC_RIGHT,  KC_PIPE, KC_DQT,
    KC_LBRC, KC_F9,    KC_F10,   KC_F11,    KC_F12, XXXXXXX,  XXXXXXX, XXXXXXX,  XXXXXXX,   KC_VOLU,  XXXXXXX, KC_RBRC,
    _______, _______,  _______, _______,   _______, _______,  _______, _______,  XXXXXXX,   XXXXXXX,  XXXXXXX, XXXXXXX
),

[_LOWER] = LAYOUT_planck_grid(
    KC_GRV,  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN,  KC_RPRN, KC_UNDS,
    _______,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,   KC_PLUS, KC_MINS, KC_LABK, KC_RABK,  KC_PIPE, KC_QUOT,
    KC_LCBR, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    LEQL,    KC_EQL,    NEQL,    GEQL,  KC_BSLS, KC_RCBR,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

[_FN1] = LAYOUT_planck_grid(
    PSCRN,     KC_F1,    KC_F2,    KC_F3,    EXT_APP, XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    TSK_MNG,   KC_F5,    KC_F6,    KC_F7,    KC_F8,   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    DSKTOP,    KC_F9,    KC_F10,   KC_F11,   KC_F12,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    LCK_SCRN,  _______,  _______,  _______,  _______, _______,  _______,  _______,  _______, _______, _______, _______
),

[_FN2] = LAYOUT_planck_grid(
    QWERTY,   COLEMAK,   G_SWAP,  G_SWAP,  TERM_ON, TERM_OFF,  XXXXXXX,  XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX,  PSCRN,
    XXXXXXX,  XXXXXXX,   MU_MOD,   AU_ON,   AU_OFF,  XXXXXXX,  XXXXXXX,  XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX,   MUV_DE,   MUV_IN,   MU_ON,   MU_OFF,  XXXXXXX,  XXXXXXX,  XXXXXXX, XXXXXXX,  XXXXXXX, KC_VOLU, KC_MPLY,
    XXXXXXX,  XXXXXXX,  XXXXXXX, XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX, _______,  KC_MPRV, KC_VOLD, KC_MNXT
)

};

// flags for encoder and alt gui swap
bool lalt = false, lctrl = false, lgui = false, ag_swap = true;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
    case COLEMAK:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_COLEMAK);
      }
      return false;
      break;
    case OW_THM:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(overwatch_theme);
        #endif
      }
      return false;
      break;
    case IMP_MRCH:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(imperial_march);
        #endif
      }
      return false;
      break;

    case G_SWAP:
      if (record->event.pressed) {
        ag_swap = !ag_swap;
      }
      return false;
      break;

    case ENC_ALT:
      if (record->event.pressed) {
        (ag_swap) ? register_code(KC_LALT) : register_code(KC_LGUI);
        lalt = !lalt;
      } else {
        (ag_swap) ? unregister_code(KC_LALT) : unregister_code(KC_LGUI);
        lalt = !lalt;
      }
      return false;
      break;

    case ENC_GUI:
      if (record->event.pressed) {
        (ag_swap) ? register_code(KC_LGUI) : register_code(KC_LALT);
        lgui = !lgui;
      } else {
        (ag_swap) ? unregister_code(KC_LGUI) : unregister_code(KC_LALT);
        lgui = !lgui;
      }
      return false;
      break;

    case ENC_CTRL:
      if (record->event.pressed) {
        register_code(KC_LCTRL);
        lctrl = !lctrl;
      } else {
        unregister_code(KC_LCTRL);
        lctrl = !lctrl;
      }
      return false;
      break;

    case NEQL:
      if (record->event.pressed) {
        SEND_STRING("!=");
      }
      return false;
      break;
    case LEQL:
      if (record->event.pressed) {
        SEND_STRING("<=");
      }
      return false;
      break;
    case GEQL:
      if (record->event.pressed) {
        SEND_STRING(">=");
      }
      return false;
      break;
  }
  return true;
}


void encoder_update(bool clockwise) {
  uint16_t held_keycode_timer = timer_read();
  if (IS_LAYER_ON(_LOWER)) {
    if (!clockwise) {
      register_code(KC_VOLU);
      while (timer_elapsed(held_keycode_timer) < MEDIA_KEY_DELAY) {
        continue;
      }
      unregister_code(KC_VOLU);
    } else {
      register_code(KC_VOLD);
      while (timer_elapsed(held_keycode_timer) < MEDIA_KEY_DELAY) {
        continue;
      }
      unregister_code(KC_VOLD);
    }
  } else if (lalt || lctrl) {
    if (!clockwise) tap_code(KC_TAB);
    else {
      register_code(KC_LSFT);
      tap_code(KC_TAB);
      unregister_code(KC_LSFT);
    }
  } else if (IS_LAYER_ON(_RAISE)) {
    (!clockwise) ? tap_code(KC_RIGHT) :tap_code(KC_LEFT);
  } else if(IS_LAYER_ON(_FN1)) {
    (!clockwise) ? tap_code(KC_DOWN) : tap_code(KC_UP);
  }
  else {
    if (!clockwise) {
      #ifdef MOUSEKEY_ENABLE
        register_code(KC_MS_WH_DOWN);
        unregister_code(KC_MS_WH_DOWN);
      #else
        register_code(KC_PGDN);
        unregister_code(KC_PGDN);
      #endif
    } else {
      #ifdef MOUSEKEY_ENABLE
        register_code(KC_MS_WH_UP);
        unregister_code(KC_MS_WH_UP);
      #else
        register_code(KC_PGUP);
        unregister_code(KC_PGUP);
      #endif
    }
  }
}
