#include QMK_KEYBOARD_H

// Layers
#define _QWERTY 0
#define _COLEMAK 1
#define _GAMEMODE 2
#define _LOWER 3
#define _RAISE 4
#define _FN1 5
#define _FN2 6

#define _______ KC_TRNS
#define XXXXXXX KC_NO

#define FN1 MO(_FN1)
#define FN2 LT(_FN2, KC_LEFT)
#define SP_LWR LT(_LOWER, KC_SPACE)
#define BS_RAS LT(_RAISE, KC_BSPC)
#define BS_LWR LT(_LOWER, KC_BSPC)

// shortcuts
#define TSK_MNG LCTL(LSFT(KC_ESC))
#define LCK_SCRN LGUI(KC_L)
#define DSKTOP LGUI(KC_D)
#define PSCRN LALT(KC_PSCR)

// Modifier Tap
#define CTRL_TAP RCTL_T(KC_RIGHT)
#define GUI_TAP RGUI_T(KC_UP)
#define ALT_TAP RALT_T(KC_DOWN)
#define ESC_TAP LCTL_T(KC_ESC)

enum custom_keycodes {
  COLEMAK = SAFE_RANGE,
  QWERTY,
  GAMEMODE
};

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

  [_QWERTY] = LAYOUT(
    KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,
    ESC_TAP,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_ENT,
    KC_LSFT,  KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT,
    KC_LCTL,  KC_LGUI,  FN1,      KC_LALT,  SP_LWR,   BS_RAS,   FN2,      ALT_TAP,  GUI_TAP,  CTRL_TAP
  ),

  [_COLEMAK] = LAYOUT(
    KC_TAB,   KC_Q,     KC_W,     KC_F,     KC_P,     KC_G,     KC_J,     KC_L,     KC_U,     KC_Y,     KC_SCLN,  KC_LBRC,  KC_RBRC,
    ESC_TAP,  KC_A,     KC_R,     KC_S,     KC_T,     KC_D,     KC_H,     KC_N,     KC_E,     KC_I,     KC_O,     KC_ENT,
    KC_LSFT,  KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_K,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT,
    KC_LCTL,  KC_LGUI,  FN1,      KC_LALT,  SP_LWR,   BS_RAS,   FN2,      ALT_TAP,  GUI_TAP,  CTRL_TAP
  ),

  [_GAMEMODE] = LAYOUT(
    KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,
    ESC_TAP,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_ENT,
    KC_LSFT,  KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT,
    KC_LCTL,  KC_LGUI,  FN1,      KC_LALT,  KC_SPACE, BS_LWR,   FN2,      ALT_TAP,  GUI_TAP,  CTRL_TAP
  ),

  [_LOWER] = LAYOUT(
    KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,
    _______,  KC_MINS,  KC_EQL,   KC_LCBR,  KC_RCBR,  KC_BSLS,  KC_HOME,  KC_PGDN,  KC_PGUP,  KC_END, KC_QUOT,  KC_QUOT,
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______
  ),

  [_RAISE] = LAYOUT(
    KC_TILD,  KC_EXLM,  KC_AT,    KC_HASH,  KC_DLR,   KC_PERC,  KC_CIRC,  KC_AMPR,  KC_ASTR,  KC_LPRN,  KC_RPRN,  KC_INS,  KC_DEL,
    _______,  KC_UNDS,  KC_PLUS,  KC_LBRC,  KC_RBRC,  KC_PIPE,  KC_LEFT,  KC_DOWN,  KC_UP,    KC_RIGHT, KC_DQT,   KC_DQT,
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______
  ),

  [_FN1] = LAYOUT(
    PSCRN,     KC_F1,    KC_F2,    KC_F3,    EXT_APP, _______,  _______,  KC_WBAK,  KC_WFWD,  _______,  _______,  _______,  QWERTY,
    TSK_MNG,   KC_F5,    KC_F6,    KC_F7,    KC_F8,   _______,  KC_WH_L,  KC_WH_D,  KC_WH_U,  KC_WH_R,  _______,  COLEMAK,
    DSKTOP,    KC_F9,    KC_F10,   KC_F11,   KC_F12,  _______,  _______,  _______,  _______,  _______,  _______,  GAMEMODE,
    LCK_SCRN,  _______,  _______,  _______,  _______, _______,  _______,  _______,  _______,  _______
  ),

   [_FN2] = LAYOUT(
    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX, XXXXXXX,  XXXXXXX,  KC_BTN1,  KC_BTN2,  XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_PWR,
    XXXXXXX,  KC_APP,   KC_WSCH,  XXXXXXX,  XXXXXXX, XXXXXXX,  KC_MS_L,  KC_MS_D,  KC_MS_U,  KC_MS_R,  XXXXXXX,  KC_SLEP,
    XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_CALC,  XXXXXXX, XXXXXXX,  XXXXXXX,  KC_MAIL,  XXXXXXX,  XXXXXXX,  KC_VOLU,  KC_MPLY,
    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX, XXXXXXX,  _______,  KC_MPRV,  KC_VOLD,  KC_MNXT
  )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {

  switch(keycode) {
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

  case GAMEMODE:
    if (record->event.pressed) {
      set_single_persistent_default_layer(_GAMEMODE);
    }

    return false;
    break;

  default:
    return true;
  }

  return true;
}
