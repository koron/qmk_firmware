#include QMK_KEYBOARD_H
#include "bootloader.h"
#include"keymap_jp.h"
#ifdef PROTOCOL_LUFA
#include "lufa.h"
#include "split_util.h"
#endif


#ifdef RGBLIGHT_ENABLE
//Following line allows macro to read current RGB settings
extern rgblight_config_t rgblight_config;
#endif

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
enum layer_number {
    _QWERTY = 0
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* Qwerty
   * ,-----------------------------------------.             ,-----------------------------------------.
   * |   `  |   1  |   2  |   3  |   4  |   5  |             |   6  |   7  |   8  |   9  |   0  | Del  |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * | Tab  |   Q  |   W  |   E  |   R  |   T  |             |   Y  |   U  |   I  |   O  |   P  | Bksp |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * | Ctrl |   A  |   S  |   D  |   F  |   G  |             |   H  |   J  |   K  |   L  |   ;  |  '   |
   * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
   * | Shift|   Z  |   X  |   C  |   V  |   B  |   [  |   ]  |   N  |   M  |   ,  |   .  |   /  |Enter |
   * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
   * |Adjust| Esc  | Alt  | GUI  | EISU |Lower |Space |Space |Raise | KANA | Left | Down |  Up  |Right |
   * `-------------------------------------------------------------------------------------------------'
   */

  [_QWERTY] = LAYOUT( \
      KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,   KC_NO,     KC_NO, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL, \
      KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,   KC_NO,     KC_NO,  KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC, \
      KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,   KC_NO,     KC_NO,  KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
      KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_LBRC, KC_RBRC, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT , \
      KC_ESC,  KC_A,  KC_LALT, KC_LGUI, KC_NO,    KC_NO,   KC_SPC,  KC_SPC,  KC_ESC,   KC_NO,    KC_LEFT, KC_DOWN, KC_UP,   KC_ESC \
  ),
     /*scanf("%s\n", );
      [_QWERTY] = LAYOUT( \
          KC_A,  KC_A,    KC_A,    KC_A,    KC_A,    KC_A,    KC_A,        KC_1,     KC_2,    KC_C,    KC_D,    KC_E,    KC_F,    KC_G, \
          KC_B,  KC_B,    KC_B,    KC_B,    KC_B,    KC_B,    KC_B,        KC_1,      KC_2,    KC_C,    KC_D,    KC_E,    KC_F,    KC_G, \
          KC_C, KC_C,    KC_C,    KC_C,    KC_C,    KC_C,     KC_C,        KC_1,     KC_2,     KC_C,    KC_D,    KC_E,    KC_F, KC_G, \
          KC_D, KC_D,    KC_D,    KC_D,    KC_D,    KC_D,    KC_D,         KC_1,    KC_2,      KC_C,   KC_D,    KC_E,    KC_F , KC_G, \
          KC_E,  KC_E,  KC_E,    KC_E,    KC_E,    KC_E,   KC_E,           KC_1,    KC_2,      KC_C,   KC_D,    KC_E,     KC_F, KC_G \
          ),
          */
};


__attribute__ ((weak))
void get_matrix_key_val(uint8_t col, uint8_t row, uint8_t* val, uint8_t *threshold){
*val=0;
*threshold=0;
(void)col;
(void)row;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  return true;
}

void matrix_init_user(void) {
}

void matrix_scan_user(void) {
  uint8_t col,row,val,threshold;;
  static uint32_t last_timer=0;
  uint32_t timer_now = timer_read32();
  // 100msに一回
  if (TIMER_DIFF_32(timer_now, last_timer) > 100) {
last_timer = timer_now;
    oled_task_user();

    // デバッグ用
    col = 1;
    row = 2;
    get_matrix_key_val(col, row, &val, &threshold);

#ifdef CONSOLE_ENABLE
    uprintf("col=%d row=%d val=%d threshold=%d\n", col, row, val, threshold);
#endif
  }
}
static void render_logo(void) {

  static const char helix_logo[] PROGMEM ={
    0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8a,0x8b,0x8c,0x8d,0x8e,0x8f,0x90,0x91,0x92,0x93,0x94,
    0xa0,0xa1,0xa2,0xa3,0xa4,0xa5,0xa6,0xa7,0xa8,0xa9,0xaa,0xab,0xac,0xad,0xae,0xaf,0xb0,0xb1,0xb2,0xb3,0xb4,
    0xc0,0xc1,0xc2,0xc3,0xc4,0xc5,0xc6,0xc7,0xc8,0xc9,0xca,0xcb,0xcc,0xcd,0xce,0xcf,0xd0,0xd1,0xd2,0xd3,0xd4,
    0};

  oled_write_P(helix_logo, false);
 // struct CharacterMatrix *matrix;
 // char buf[10];
    // matrix_write_P(&matrix, PSTR("val-"));
     //snprintf(buf,sizeof(buf), "%ld", layer_state);
    // matrix_write(matrix, buf);

}

#ifdef OLED_DRIVER_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (!is_keyboard_master()) {
        return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
    }

    return rotation;
}

void oled_task_user(void) {
    if (is_keyboard_master()) {
        render_logo();
    } else {
        render_logo();
        oled_scroll_left();  // Turns on scrolling
    }
}
#endif
