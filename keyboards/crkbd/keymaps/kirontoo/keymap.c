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
#define _LOWER 3
#define _RAISE 4
#define _ADJUST 16

enum custom_keycodes {
  COLEMAK = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST,
  TD_EXT
};

#define KC______ KC_TRNS
#define KC_XXXXX KC_NO
#define KC_LOWER LOWER
#define KC_RAISE RAISE
//#define KC_RST   RESET

#define KC_CTLTB CTL_T(KC_TAB)
#define KC_CTLEC CTL_T(KC_ESC)

#define KC_LWR OSL(_LOWER)
#define KC_RAS OSL(_RAISE)
#define KC_LST OSM(MOD_LSFT)
#define KC_RST OSM(MOD_RSFT)

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
        TAB,     1,     2,     3,     4,     5,                      6,     7,     8,     9,     0,   GRV,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
      CTLEC, XXXXX, XXXXX,  MINS,  EQL,   BSLS,                   HOME,  PGDN,  PGUP,   END,  BSLS,  QUOT,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
       LCBR,  UNDO,   CUT,  COPY, PASTE, XXXXX,                  XXXXX, XXXXX, XXXXX, XXXXX, XXXXX,  RCBR,\
  //|------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
                                  PSCRN,   LWR,   SPC,     BSPC,   RAS,  DESKT \
                              //`--------------------'  `--------------------'
  ),

  [_RAISE] = LAYOUT_kc( \
  //,-----------------------------------------.                ,-----------------------------------------.
        TAB,  EXLM,    AT,  HASH,   DLR,  PERC,                   CIRC,  AMPR,  ASTR,  LPRN,  RPRN,  TILD,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
      CTLEC, XXXXX, XXXXX,  UNDS,  PLUS,  PIPE,                   LEFT,  DOWN,    UP, RIGHT,  PIPE,   DQT,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
       LBRC, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX,                   MPLY,  MPRV,  VOLU,  VOLD,  MNXT,  RBRC,\
  //|------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
                                   SNIP,   LWR,   SPC,     BSPC,   RAS,  TSKMG \
                              //`--------------------'  `--------------------'
  ),

  [_ADJUST] = LAYOUT_kc( \
  //,-----------------------------------------.                ,-----------------------------------------.
      XXXXX,    F1,    F2,    F3,   EXT, XXXXX,                  XXXXX, DESKT, XXXXX, XXXXX, XXXXX, XXXXX,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
      XXXXX,    F5,    F6,    F7,    F8, XXXXX,                  XXXXX, LKSCN, XXXXX, XXXXX, XXXXX, XXXXX,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
      XXXXX,    F9,   F10,    F11,  F12, XXXXX,                  XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX,\
  //|------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
                                    LALT,  LWR,   SPC,     BSPC,   RAS,   LGUI \
                              //`--------------------'  `--------------------'
  )
};

int RGB_current_mode;

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

// Setting ADJUST layer RGB back to default
void update_tri_layer_RGB(uint8_t layer1, uint8_t layer2, uint8_t layer3) {
  if (IS_LAYER_ON(layer1) && IS_LAYER_ON(layer2)) {
    layer_on(layer3);
  } else {
    layer_off(layer3);
  }
}

void matrix_init_user(void) {
    #ifdef RGBLIGHT_ENABLE
      RGB_current_mode = rgblight_config.mode;
    #endif
    //SSD1306 OLED init, make sure to add #define SSD1306OLED in config.h
    #ifdef SSD1306OLED
        iota_gfx_init(!has_usb());   // turns on the display
    #endif
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

void matrix_scan_user(void) {
   iota_gfx_task();
}

void matrix_render_user(struct CharacterMatrix *matrix) {
  if (is_master) {
    // If you want to change the display of OLED, you need to change here
    matrix_write_ln(matrix, read_layer_state());
    matrix_write_ln(matrix, read_keylog());
    matrix_write_ln(matrix, read_keylogs());
    //matrix_write_ln(matrix, read_mode_icon(keymap_config.swap_lalt_lgui));
    //matrix_write_ln(matrix, read_host_led_state());
    //matrix_write_ln(matrix, read_timelog());
  } else {
    matrix_write(matrix, read_logo());
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
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
#ifdef SSD1306OLED
    set_keylog(keycode, record);
#endif
    // set_timelog();
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
        update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
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

