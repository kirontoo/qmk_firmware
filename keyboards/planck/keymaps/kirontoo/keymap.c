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
  _PLOVER,
  _ADJUST,
  _FN1,
  _FN2
};

enum planck_keycodes {
  QWERTY = SAFE_RANGE,
  COLEMAK,
  PLOVER,
  EXT_PLV,
  OW_THM,
  IMP_MRCH,
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define FN1 MO(_FN1)
#define FN2 LT(_FN2, KC_LEFT)

// define songs
#ifdef AUDIO_ENABLE
float plover_song[][2]     = SONG(PLOVER_SOUND);
float plover_gb_song[][2]  = SONG(PLOVER_GOODBYE_SOUND);
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

// One Shot Layers
#define OSL_LWR OSL(_LOWER)
#define OSL_RAS OSL(_RAISE)

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

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  |  ~   |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |Enter |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Shift |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | GUI  | FN1  | ALT  |Lower | SPC  | BSPC |Raise | FN2  | ALT  | GUI  | Ctrl |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_planck_grid(
    KC_MUTE, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_GRV,
    ESC_TAP,  KC_A,   KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT ,
    KC_LCTL, KC_LGUI, FN1,     KC_LALT, OSL_LWR, KC_SPC,  KC_BSPC, OSL_RAS, FN2,     ALT_TAP, GUI_TAP, CTRL_TAP
),

/* Colemak
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   F  |   P  |   G  |   J  |   L  |   U  |   Y  |   ;  |  ~   |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   R  |   S  |   T  |   D  |   H  |   N  |   E  |   I  |   O  |Enter |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   K  |   M  |   ,  |   .  |   /  |Shift |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | GUI  | FN1  | ALT  |Lower | SPC  | BSPC |Raise | FN2  | ALT  | GUI  | Ctrl |
 * `-----------------------------------------------------------------------------------'
 */
[_COLEMAK] = LAYOUT_planck_grid(
    KC_MUTE, KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_GRV,
    ESC_TAP,  KC_A,   KC_R,    KC_S,    KC_T,    KC_D,    KC_H,    KC_N,    KC_E,    KC_I,    KC_O,    KC_ENT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT ,
    KC_LCTL, KC_LGUI, FN1,     KC_LALT, OSL_LWR, KC_SPC,  KC_BSPC, OSL_RAS, FN2,     ALT_TAP, GUI_TAP, CTRL_TAP
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | DEL  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |  _   |  +   |  [   |  ]   |  |   |Left  | Down |  Up  |Right |  |   |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |ISO ~ |ISO | | Home | End  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_planck_grid(
    KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR,    KC_ASTR,    KC_LPRN,  KC_RPRN, KC_DEL,
    _______, KC_UNDS, KC_PLUS, KC_LBRC, KC_RBRC, KC_PIPE, KC_LEFT, KC_DOWN,    KC_UP,      KC_RIGHT, KC_PIPE, KC_DQT,
    _______, _______, _______, _______, _______, _______, _______, _______,    _______,    KC_VOLU,  _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______,    KC_MPRV,    KC_VOLD,  KC_MNXT, KC_MPLY
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | INS  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |  -   |  =   |  {   |  }   |  \   |Home  |PgDn  |PgUp  |End   |  \   |  '   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_planck_grid(
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_INS,
    KC_TAB,  KC_MINS, KC_EQL,  KC_LCBR, KC_RCBR, KC_BSLS, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_BSLS, KC_QUOT,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

/* Plover layer (http://opensteno.org)
 * ,-----------------------------------------------------------------------------------.
 * |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |   S  |   T  |   P  |   H  |   *  |   *  |   F  |   P  |   L  |   T  |   D  |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |   S  |   K  |   W  |   R  |   *  |   *  |   R  |   B  |   G  |   S  |   Z  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Exit |      |      |   A  |   O  |             |   E  |   U  |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_PLOVER] = LAYOUT_planck_grid(
    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1   ,
    XXXXXXX, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC,
    XXXXXXX, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    EXT_PLV, XXXXXXX, XXXXXXX, KC_C,    KC_V,    XXXXXXX, XXXXXXX, KC_N,    KC_M,    XXXXXXX, XXXXXXX, XXXXXXX
),

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |Aud on|Audoff|AGnorm|AGswap|Qwerty|Colemk|Dvorak|Plover|      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |Voice-|Voice+|Mus on|Musoff|      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_planck_grid(
    _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______,
    _______, _______, MU_MOD,  AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, QWERTY,  COLEMAK,  PLOVER,  _______, _______,
    _______, MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,  _______, _______, TERM_ON, TERM_OFF, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______
),

/* FN1
 * ,-----------------------------------------------------------------------------------.
 * |PSCRN |  F1  |  F2  |  F3  |  F4  |      |      | WBAK | WFWD |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |TSKMNG|  F5  |  F6  |  F7  |  F8  |      | WHL  | WHD  | WHU  |WHR   |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |DSKTOP|  F9  |  F10 |  F11 |  F12 |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |LCKSCN|      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_FN1] = LAYOUT_planck_grid(
    PSCRN,     KC_F1,    KC_F2,    KC_F3,    EXT_APP, _______,  _______,  KC_WBAK,  KC_WFWD, _______, _______, _______,
    TSK_MNG,   KC_F5,    KC_F6,    KC_F7,    KC_F8,   _______,  KC_WH_L,  KC_WH_D,  KC_WH_U, KC_WH_R, _______, _______,
    DSKTOP,    KC_F9,    KC_F10,   KC_F11,   KC_F12,  _______,  _______,  _______,  _______, _______, _______, _______,
    LCK_SCRN,  _______,  _______,  _______,  _______, _______,  _______,  _______,  _______, _______, _______, _______
),

/* FN2
 * ,-----------------------------------------------------------------------------------.
 * |IPMRCH| OW   |      |      |      |      |      |BTN1  |BTN2  |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      | APP  |WSRCH |      |      |      |  ML  |  MD  |  MU  | MR   |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      | CALC |      |      |      | Mail |      |      | Vol+ | Play |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      | MPrv | Vol- | Mnxt |
 * `-----------------------------------------------------------------------------------'
 */
[_FN2] = LAYOUT_planck_grid(
    IMP_MRCH,  OW_THM,   XXXXXXX, XXXXXXX,  XXXXXXX, _______,  XXXXXXX,  KC_BTN1,  KC_BTN2,  XXXXXXX, _______, _______,
    XXXXXXX,   KC_APP,   KC_WSCH, XXXXXXX,  XXXXXXX, XXXXXXX,  KC_MS_L,  KC_MS_D,  KC_MS_U,  KC_MS_R, _______, _______,
    XXXXXXX,   XXXXXXX,  XXXXXXX, KC_CALC,  XXXXXXX, XXXXXXX,  XXXXXXX,  KC_MAIL,  XXXXXXX,  XXXXXXX, KC_VOLU, KC_MPLY,
    XXXXXXX,   XXXXXXX,  XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX,  _______,  _______,  _______,  KC_MPRV, KC_VOLD, KC_MNXT
)

};


uint32_t layer_state_set_user(uint32_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        print("mode just switched to qwerty and this is a huge string\n");
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
    case PLOVER:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          stop_all_notes();
          PLAY_SONG(plover_song);
        #endif
        layer_off(_RAISE);
        layer_off(_LOWER);
        layer_off(_ADJUST);
        layer_on(_PLOVER);
        if (!eeconfig_is_enabled()) {
            eeconfig_init();
        }
        keymap_config.raw = eeconfig_read_keymap();
        keymap_config.nkro = 1;
        eeconfig_update_keymap(keymap_config.raw);
      }
      return false;
      break;
    case EXT_PLV:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(plover_gb_song);
        #endif
        layer_off(_PLOVER);
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
  }
  return true;
}

bool muse_mode = false;
uint8_t last_muse_note = 0;
uint16_t muse_counter = 0;
uint8_t muse_offset = 70;
uint16_t muse_tempo = 50;

void matrix_scan_user(void) {
  #ifdef AUDIO_ENABLE
    if (muse_mode) {
      if (muse_counter == 0) {
        uint8_t muse_note = muse_offset + SCALE[muse_clock_pulse()];
        if (muse_note != last_muse_note) {
          stop_note(compute_freq_for_midi_note(last_muse_note));
          play_note(compute_freq_for_midi_note(muse_note), 0xF);
          last_muse_note = muse_note;
        }
      }
      muse_counter = (muse_counter + 1) % muse_tempo;
    }
  #endif
}

bool music_mask_user(uint16_t keycode) {
  switch (keycode) {
    case RAISE:
    case LOWER:
      return false;
    default:
      return true;
  }
}


void encoder_update(bool clockwise) {
  if (IS_LAYER_ON(_LOWER)) {
    if (clockwise) {
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
        register_code(KC_MS_WH_UP);
        unregister_code(KC_MS_WH_UP);
      #endif
    }
  } else {
    if (clockwise) {
      #ifdef MOUSEKEY_ENABLE
        register_code(KC_MS_WH_DOWN);
        unregister_code(KC_MS_WH_DOWN);
      #else
        register_code(KC_VOLU);
        unregister_code(KC_VOLU);
      #endif
    } else {
        register_code(KC_VOLD);
        unregister_code(KC_VOLD);
    }
  }
}
