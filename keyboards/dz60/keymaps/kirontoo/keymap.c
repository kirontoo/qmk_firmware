// Using DZ60 60_b_ansi layout
#include QMK_KEYBOARD_H

// Layer definition
#define _QWERTY 0
#define _COLEMAK 1
#define _FL 2
#define _FN 3
#define _ML 4
#define _KL 5

// To make layers more clear
#define ____ KC_TRNS

// Custom Shortcuts
#define TSK_MNG LCTL(LSFT(KC_ESC))   // ctrl+shift+esc
#define LCK_SCRN LGUI(KC_L)     // win+L
#define SHUT_DWN LALT(KC_F4)    // alt+f4
#define RSFT_Q RSFT_T(KC_SLSH)   // right shift on hold, / on tap

// Custom keycodes
enum custom_keycodes {
  CMD = SAFE_RANGE,
  VSCODE,
  STEAM,
  BLIZZ,
  PSCR_MON,
  COLEMAK,
  QWERTY
};

/* LAYOUT_60_b_ansi (maximized DZ60 Plate B layout for ANSI)
 * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┐
 * │00 │01 │02 │03 │04 │05 │06 │07 │08 │09 │0a │0b │0c │0d │0e │  15 KEYS
 * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴───┤
 * │10   │12 │13 │14 │15 │16 │17 │18 │19 │1a │1b │1c │1d │1e   │  14 KEYS
 * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┤
 * │20    │22 │23 │24 │25 │26 │27 │28 │29 │2a │2b │2c │2d      │  13 KEYS
 * ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴───┴┬───┬───┤
 * │30      │32 │33 │34 │35 │36 │37 │38 │39 │3a │3c    │3d │3e │  13 KEYS
 * ├────┬───┴┬──┴─┬─┴───┴──┬┴───┼───┴───┴──┬┴──┬┴──┬───┼───┼───┤
 * │40  │41  │43  │44      │46  │48        │4a │4b │4c │4d │4e │  11 KEYS
 * └────┴────┴────┴────────┴────┴──────────┴───┴───┴───┴───┴───┘
*/

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    // Base Layer - ANSI QWERTY
    [_QWERTY] = LAYOUT_60_b_ansi(
        KC_GRV,          KC_1,    KC_2,     KC_3,    KC_4,    KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,        KC_MINS,   KC_EQL,      KC_BSPC,   KC_DEL,
        KC_TAB,          KC_Q,    KC_W,     KC_E,    KC_R,    KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,        KC_LBRC,   KC_RBRC,     KC_BSLS,
        LT(_FL, KC_ESC), KC_A,    KC_S,     KC_D,    KC_F,    KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,     KC_QUOT,   KC_ENT,
        KC_LSFT,         KC_Z,    KC_X,     KC_C,    KC_V,    KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   RSFT_Q,      KC_UP,     KC_PSCR,
        KC_LCTL,         KC_LGUI, KC_LALT,  KC_SPC,  MO(_FN), KC_BSPC,  MO(_KL),  TT(_ML),  KC_LEFT,  KC_DOWN,  KC_RIGHT
    ),

    [_COLEMAK] = LAYOUT_60_b_ansi(
        KC_GRV,          KC_1,    KC_2,     KC_3,    KC_4,    KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,        KC_MINS,   KC_EQL,      KC_BSPC,   KC_DEL,
        KC_TAB,          KC_Q,    KC_W,     KC_F,    KC_P,    KC_G,     KC_J,     KC_L,     KC_U,     KC_Y,     KC_SCLN,     KC_LBRC,   KC_RBRC,     KC_BSLS,
        LT(_FL, KC_ESC), KC_A,    KC_R,     KC_S,    KC_T,    KC_D,     KC_H,     KC_N,     KC_E,     KC_I,     KC_O,        KC_QUOT,   KC_ENT,
        KC_LSFT,         KC_Z,    KC_X,     KC_C,    KC_V,    KC_B,     KC_K,     KC_M,     KC_COMM,  KC_DOT,   RSFT_Q,      KC_UP,     KC_PSCR,
        KC_LCTL,         KC_LGUI, KC_LALT,  KC_SPC,  MO(_FN), KC_BSPC,  MO(_KL),  TT(_ML),  KC_LEFT,  KC_DOWN,  KC_RIGHT
    ),

    // Function Layer - Custom binds
    [_FL] = LAYOUT_60_b_ansi(
      ____,            KC_F1,   KC_F2,    KC_F3,   KC_F4,   KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,        KC_F11,    KC_F12,       KC_PAUS,  ____,
      ____,            ____,    ____,     KC_EQL,  KC_PLUS, ____,     ____,     KC_MINS,  KC_UNDS,  ____,     ____,          ____,      ____,         ____,
      ____,            ____,    ____,     KC_LCBR, KC_RCBR, ____,     ____,     KC_RBRC,  KC_LBRC,  ____,     ____,          ____,      ____,
      ____,            ____,    ____,     ____,    ____,    ____,     ____,     ____,     ____,     ____,     KC_INS,        KC_PGUP,   KC_DEL,
      ____,            ____,    ____,     ____,    ____,    ____,     ____,     ____,     KC_HOME,  KC_PGDN,  KC_END
    ),

    // F1-F12
    [_FN] = LAYOUT_60_b_ansi(
      ____,            QWERTY,  COLEMAK,  ____,    ____,    ____,     ____,     ____,     ____,     ____,     ____,          ____,      ____,         ____,      ____,
      ____,            KC_F1,   KC_F2,    KC_F3,   KC_F4,   ____,     KC_PGUP,  KC_HOME,  KC_UP,    KC_END,   ____,          ____,      ____,         ____,
      ____,            KC_F5,   KC_F6,    KC_F7,   KC_F8,   ____,     KC_PGDN,  KC_LEFT,  KC_DOWN,  KC_RIGHT, ____,          ____,      ____,
      ____,            KC_F9,   KC_F10,   KC_F11,  KC_F12,  ____,     ____,     ____,     ____,     ____,     KC_INS,        KC_PGUP,   KC_DEL,
      ____,            ____,    ____,     ____,    ____,    ____,     ____,     ____,     KC_HOME,  KC_PGDN,  KC_END
    ),

    // Media Layer - Lighting and Media Controls
    [_ML] = LAYOUT_60_b_ansi(
      ____,            RGB_HUI, RGB_HUD,  RGB_SPI, RGB_SAD, RGB_M_T,  ____,     ____,     ____,     ____,     RGB_TOG,       RGB_VAD,   RGB_VAI,      ____,      ____,
      ____,            ____,    RGB_M_SW, ____,    RGB_M_R, ____,     ____,     ____,     ____,     ____,     RGB_M_P,       RGB_RMOD,  RGB_MOD,      ____,
      ____,            ____,    RGB_M_SN, ____,    ____,    RGB_M_G,  ____,     ____,     RGB_M_K,  ____,     ____,          ____,      ____,
      ____,            ____,    RGB_M_X,  ____,    ____,    RGB_M_B,  ____,     ____,     ____,     ____,     KC_MUTE,       KC_VOLU,   KC_MPLY,
      ____,            ____,    ____,     ____,    ____,    ____,     ____,     ____,     KC_MPRV,  KC_VOLD,  KC_MNXT
    ),

    // Keyboard Shortcuts Layer - Useful shortcuts
    [_KL] = LAYOUT_60_b_ansi(
      ____,            ____,    ____,     ____,    ____,    ____,     ____,     ____,     ____,     ____,     SHUT_DWN,      ____,      ____,         PSCR_MON,      TSK_MNG,
      ____,            ____,    ____,     ____,    ____,    ____,     ____,     ____,     ____,     ____,     CMD,           ____,      ____,         ____,
      ____,            ____,    STEAM,    ____,    ____,    ____,     ____,     ____,      ____,    LCK_SCRN, ____,          ____,      ____,
      ____,            ____,    ____,     KC_CALC, VSCODE,  BLIZZ,    ____,     ____,     ____,     ____,     ____,          ____,      ____,
      ____,            ____,    ____,     ____,    ____,    ____,     ____,     ____,     ____,     ____,     ____
    )

};

// set a persistant default layer
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch(keycode) {

    // Open cmd prompt
    case CMD:
      if (record->event.pressed) {
        SEND_STRING(SS_LGUI("r"));
        SEND_STRING("cmd" SS_TAP(X_ENTER));
      }
      break;

    // Open VSCode
    case VSCODE:
      if (record->event.pressed) {
        SEND_STRING(SS_LGUI("r"));
        SEND_STRING("code" SS_TAP(X_ENTER));
      }
      break;

    // Open Steam
    case STEAM:
      if (record->event.pressed) {
        SEND_STRING(SS_LGUI("r"));
        SEND_STRING("steam:" SS_TAP(X_ENTER));
      }
      break;

    // Open Blizzard Launcher
    case BLIZZ:
      if (record->event.pressed) {
        SEND_STRING(SS_LGUI("r"));
        SEND_STRING("battlenet:" SS_TAP(X_ENTER));
      }
      break;

    // Save screenshot of one monitor
    case PSCR_MON:
      if (record->event.pressed) {
        SEND_STRING(SS_DOWN(X_LALT) SS_TAP(X_PSCREEN) SS_UP(X_LALT));
      }
      break;

    case COLEMAK:
        if (record->event.pressed) {
            set_single_persistent_default_layer(_COLEMAK);
        }

        return false;
        break;

    case QWERTY:
        if (record->event.pressed) {
            set_single_persistent_default_layer(_QWERTY);
        }

        return false;
        break;

    default:
      return true;
  }

  return true;
};
