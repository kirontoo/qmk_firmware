#include QMK_KEYBOARD_H
#include "bootloader.h"
#ifdef PROTOCOL_LUFA
  #include "lufa.h"
  #include "split_util.h"
#endif
#ifdef SSD1306OLED
  #include "ssd1306.h"
#endif

extern keymap_config_t keymap_config;

#ifdef RGBLIGHT_ENABLE
//Following line allows macro to read current RGB settings
extern rgblight_config_t rgblight_config;
#endif

extern uint8_t is_master;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _COLEMAK 0
#define _LOWER 2
#define _RAISE 4
#define _GAME 1

enum custom_keycodes {
  COLEMAK = SAFE_RANGE,
  LOWER,
  RAISE,
  GAME,
  TD_EXT,
  NEQL,
  LEQL,
  GEQL
};

#define KC______ KC_TRNS
#define KC_XXXXX KC_NO
#define KC_LOWER LOWER
#define KC_RAISE RAISE
#define KC_NEQL NEQL
#define KC_GEQL GEQL
#define KC_LEQL LEQL
//#define KC_RST   RESET

#define KC_CTLTB CTL_T(KC_TAB)
#define KC_CTLEC CTL_T(KC_ESC)
#define KC_ALTEC ALT_T(KC_ESC)

#define KC_LWR OSL(_LOWER)
#define KC_RAS OSL(_RAISE)
#define KC_LST OSM(MOD_LSFT)
#define KC_RST OSM(MOD_RSFT)
#define KC_GAME DF(_GAME)
#define KC_CLMK DF(_COLEMAK)

//shortcuts
#define KC_LKSCN LGUI(KC_L)
#define KC_DESKT LGUI(KC_D)
#define KC_SNIP  LGUI(LSFT(KC_S))
#define KC_PSCRN LALT(KC_PSCR)
#define KC_TSKMG LCTL(LSFT(KC_ESC))

#ifdef TAP_DANCE_ENABLE
#define KC_EXT TD(0)
#endif

#ifdef TAP_DANCE_ENABLE
qk_tap_dance_action_t tap_dance_actions[] = {
  // tap once for F4, twice for ALT+F4
  [0] = ACTION_TAP_DANCE_DOUBLE(KC_F4, LALT(KC_F4)),
};
#endif


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_COLEMAK] = LAYOUT_kc( \
  //,-----------------------------------------.                ,-----------------------------------------.
        TAB,     Q,     W,     F,     P,     G,                      J,     L,     U,     Y,  SCLN,   GRV,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
      CTLEC,     A,     R,     S,     T,     D,                      H,     N,     E,     I,     O,   ENT,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
        LST,     Z,     X,     C,     V,     B,                      K,     M,  COMM,   DOT,  SLSH,  RST,\
  //|------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
                                    LALT,  LWR,   SPC,     BSPC,   RAS,   LGUI \
                              //`--------------------'  `--------------------'
  ),


  [_LOWER] = LAYOUT_kc( \
  //,-----------------------------------------.                ,-----------------------------------------.
        TAB,  EXLM,    AT,  HASH,   DLR,  PERC,                   CIRC,  AMPR,  ASTR,  LPRN,  RPRN,  UNDS,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
      CTLEC,     1,     2,     3,     4,     5,                   PLUS,  MINS,  LABK,  RABK,  PIPE,  QUOT,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
       LCBR,     6,     7,     8,     9,     0,                   LEQL,   EQL,  NEQL,  GEQL,  BSLS,  RCBR,\
  //|------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
                                  PSCRN,   LWR,   SPC,     BSPC,   RAS,  TSKMG \
                              //`--------------------'  `--------------------'
  ),
  [_RAISE] = LAYOUT_kc( \
  //,-----------------------------------------.                ,-----------------------------------------.
        TAB,    F1,    F2,    F3,   EXT, XXXXX,                   GAME, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
      CTLEC,    F5,    F6,    F7,    F8, XXXXX,                   LEFT,  DOWN,    UP, RIGHT,  PIPE,   DQT,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
       LBRC,    F9,   F10,    F11,  F12, XXXXX,                   MPLY,  VOLD,  VOLU,  MPRV,  MNXT,  RBRC,\
  //|------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
                                   SNIP,   LWR,   SPC,     BSPC,   RAS,  XXXXX \
                              //`--------------------'  `--------------------'
  ),

  [_GAME] = LAYOUT_kc( \
  //,-----------------------------------------.                ,-----------------------------------------.3
        TAB,     Q,     W,     E,     R,     T,                      Y,     U,     I,     O,     P,  CLMK,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
      ALTEC,     A,     S,     D,     F,     G,                      H,     J,     K,     L, XXXXX,   ENT,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
       LSFT,     Z,     X,     C,     V,     B,                      N,     M, XXXXX, XXXXX, XXXXX, XXXXX,\
  //|------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
                                    LCTL,  SPC,   LWR,     BSPC,   RAS,   LGUI \
                              //`--------------------'  `--------------------'
  )
};

int RGB_current_mode;

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}


//SSD1306 OLED update loop, make sure to add #define SSD1306OLED in config.h
#ifdef SSD1306OLED

// When add source files to SRC in rules.mk, you can use functions.
const char *read_layer_state(void);
const char *read_logo(void);
void set_keylog(uint16_t keycode, keyrecord_t *record);
const char *read_keylog(void);
const char *read_keylogs(void);

// const char *read_mode_icon(bool swap);
// const char *read_host_led_state(void);
// void set_timelog(void);
// const char *read_timelog(void);

// to display layer state on OLED
char layer_state_str[24];

const char *write_layer_state(void) {
  switch (biton32(layer_state))
  {
    case _COLEMAK:
        snprintf(layer_state_str, sizeof(layer_state_str), "       COLEMAK");
        break;
    case _LOWER:
        snprintf(layer_state_str, sizeof(layer_state_str), "       CODE");
        break;
    case _RAISE:
        snprintf(layer_state_str, sizeof(layer_state_str), "       FUNCTION");
        break;
    case _GAME:
        snprintf(layer_state_str, sizeof(layer_state_str), "       GAME");
        break;
    default:
        snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Undef-%ld", layer_state);
  }

  return layer_state_str;
}

void matrix_scan_user(void) {
   iota_gfx_task();
}

void matrix_render_user(struct CharacterMatrix *matrix) {
  if (is_master) {
    // If you want to change the display of OLED, you need to change here
    // matrix_write_ln(matrix, read_keylog());
    // matrix_write_ln(matrix, read_keylogs());
    //matrix_write_ln(matrix, read_host_led_state());
    // matrix_write_ln(matrix, read_timelog());
    matrix_write_ln(matrix, "cxxx][=============>");
    matrix_write_ln(matrix, write_layer_state());
    matrix_write_ln(matrix, "cxxx][=============>");
  } else {
    // matrix_write(matrix, read_logo());
    // matrix_write_ln(matrix, read_mode_icon(keymap_config.swap_lalt_lgui));
    matrix_write_ln(matrix, "0)xxx[=====---------");
    matrix_write_ln(matrix, "       KIRONTO");
    matrix_write_ln(matrix, "0)xxx[=====---------");
  }
}

void matrix_update(struct CharacterMatrix *dest, const struct CharacterMatrix *source) {
  if (memcmp(dest->display, source->display, sizeof(dest->display))) {
    memcpy(dest->display, source->display, sizeof(dest->display));
    dest->dirty = true;
  }
}

void iota_gfx_task_user(void) {
  struct CharacterMatrix matrix;
  matrix_clear(&matrix);
  matrix_render_user(&matrix);
  matrix_update(&display, &matrix);
}
#endif//SSD1306OLED


uint32_t layer_state_set_user(uint32_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _GAME);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    #ifdef SSD1306OLED
        set_keylog(keycode, record);
        // set_timelog();
    #endif
  }

  switch (keycode) {
    case COLEMAK:
      if (record->event.pressed) {
        persistent_default_layer_set(1UL<<_COLEMAK);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
      } else {
        layer_off(_LOWER);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
      } else {
        layer_off(_RAISE);
     }
      return false;
      break;
    case GAME:
        if (record->event.pressed) {
          layer_on(_GAME);
        } else {
          layer_off(_GAME);
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

