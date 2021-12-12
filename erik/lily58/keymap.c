#include QMK_KEYBOARD_H

#ifdef RGBLIGHT_ENABLE
//Following line allows macro to read current RGB settings
extern rgblight_config_t rgblight_config;
#endif

extern uint8_t is_master;

#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _ADJUST 3

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST,
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  `   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |  \   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LCtl  |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |ENTER |
 * |------+------+------+------+------+------|       |    |    '  |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LALT | LGUI |LOWER | /Space  /       \Tab.  \  |RAISE |      |   `  |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

 [_QWERTY] = LAYOUT(
  KC_GESC,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                                 KC_6,  KC_7,    KC_8,    KC_9,    KC_0,     KC_BSPC, \
  KC_TAB,    KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                                 KC_Y,  KC_U,    KC_I,    KC_O,    KC_P,     KC_BSLASH, \
  KC_LCTRL,  KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                                 KC_H,  KC_J,    KC_K,    KC_L,    KC_SCLN,  KC_ENTER, \
  KC_LSFT,   KC_Z,   KC_X,    KC_C,    KC_V,    KC_B,      KC_MUTE,   KC_QUOTE,       KC_N,  KC_M,    KC_COMM, KC_DOT,  KC_SLSH,  KC_RSFT, \
                             KC_LALT,  KC_LGUI, MO(_LOWER), KC_SPC,   KC_TAB,   MO(_RAISE),  _______, KC_GRAVE \
),
/* LOWER
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  Del |  F1  |  F2  |  F3  |  F4  |  F5  |                    |  F6  |  F7  |  F8  | F9   | F10  | F11  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |                    |  =   |  F8  |  F9  | F10  | F11  | F12  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |   `  |   !  |   @  |   #  |   $  |   %  |-------.    ,-------|   ^  |   &  |   *  |   (  |   )  |   -  |
 * |------+------+------+------+------+------|       |    |  -    |------+------+------+------+------+------|
 * |      |      |      |ctrl c|      |      |-------|    |-------|      |   -  |   _  |   [  |   ]  |   |  |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /Space  /       \Enter \  |      |  {   |  }   |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
[_LOWER] = LAYOUT(
  KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                     KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11, \
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                     KC_EQUAL,_______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, C(KC_C), _______, _______, _______, KC_MINUS,_______, KC_MINS, KC_UNDS, KC_LBRC, KC_RBRC, KC_PIPE, \
                             _______, _______, _______, _______, _______, _______, KC_LCBR, KC_RCBR \
),
/* RAISE
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |   `  |   1  |   2  |  {   |  }   |   5  |                    |   6  |      |  Up  |      |   0  |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  F1  |  F2  |  F3  |  (   |  )   |  F6  |-------.    ,-------|      | Left | Down |Right |      |      |
 * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
 * |  F7  |  F8  |  F9  |  [   |  ]   | F12  |-------|    |-------|   +  |   -  |   =  |   [  |   ]  |   \  |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /Ctl+B  /       \Enter \  |RAISE |BackSP| RGUI |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

[_RAISE] = LAYOUT(
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                           _______, _______, _______, _______,  KC_DEL,  _______, \
  KC_F7,   KC_F8,   KC_F9,   KC_LCBR, KC_RCBR, KC_F12,                          KC_6,    _______, KC_UP,   _______,  KC_0,    _______, \
  _______, _______, _______, KC_LPRN, KC_RPRN, _______,                         XXXXXXX, KC_LEFT, KC_DOWN, KC_RIGHT, KC_RGHT, XXXXXXX, \
  _______, _______, _______, KC_LBRC, KC_RBRC, _______, _______,    TG(_ADJUST),KC_PLUS, KC_MUTE ,KC_VOLD  ,KC_VOLU, _______, _______,  \
                             _______, _______, _______, LCTL(KC_B), _______,    _______, _______, _______ \
),
/* ADJUST
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |  7   |   8  |   9  |RGB ON| HUE+ |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |      |  4   |   5  |   6  | MODE | HUE- |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.    ,-------|      |  1   |   2  |   3  | SAT+ | VAL+ |
 * |------+------+------+------+------+------|       |    |DEFAULT|------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |  0   |   0  |   .  | SAT- | VAL- |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /Space  /       \Enter \  |RAISE |BackSP| RGUI |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
  [_ADJUST] = LAYOUT(
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX,  KC_7  ,  KC_8  ,  KC_9  , RGB_TOG, RGB_HUI, \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX,  KC_4  ,  KC_5  ,  KC_6  , RGB_MOD, RGB_HUD, \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX,  KC_1  ,  KC_2  ,  KC_3  , RGB_SAI, RGB_VAI, \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, TG(_ADJUST), XXXXXXX,  KC_0  ,  KC_0  , KC_DOT, RGB_SAD, RGB_VAD,\
                             _______, _______, _______, _______, _______,  _______,KC_BSPC, _______ \
  )
};

int RGB_current_mode;

int counter = 0;
int lastIndex = 9;

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
}

#ifdef OLED_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master())
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  return rotation;
}

// When add source files to SRC in rules.mk, you can use functions.
const char *read_layer_state(void);
const char *read_logo(void);
void set_keylog(uint16_t keycode, keyrecord_t *record);
const char *read_keylog(void);
const char *read_keylogs(void);

const char *read_mode_icon(bool swap);
const char *read_host_led_state(void);
void set_timelog(void);
const char *read_timelog(void);

char encoder_debug[24];

bool oled_task_user(void) {
  // Host Keyboard Layer Status
  snprintf(encoder_debug, sizeof(encoder_debug), "%i   %i", counter, lastIndex );
  if (is_keyboard_master()) {
    // If you want to change the display of OLED, you need to change here
    oled_write_ln(read_layer_state(), false);
    // oled_write_ln(read_keylog(), false);
    // oled_write_ln(read_keylogs(), false);
    // oled_write_ln(read_mode_icon(keymap_config.swap_lalt_lgui), false);
    oled_write_ln(read_host_led_state(), false);
    oled_write_ln(encoder_debug, false);
    // oled_write_ln(read_timelog(), false);
  } else {
    oled_write(read_logo(), false);
    // oled_write_ln(encoder_debug, false);
  }
    return false;
}
#endif //OLED_ENABLE

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
#ifdef SSD1306OLED
    // set_keylog(keycode, record);
#endif
    // set_timelog();
  }

  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWERTY);
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

bool encoder_update_user(uint8_t index, bool clockwise) {
    lastIndex = index;
    if (clockwise) {
        counter++;
        tap_code(KC_VOLU);
    } else {
        counter--;
        tap_code(KC_VOLD);
    }
    return true;
}
