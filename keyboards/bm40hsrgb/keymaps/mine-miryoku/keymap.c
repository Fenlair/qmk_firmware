// qmk flash -kb bm40hsrgb -km signynt

/* Copyright 2021 Vincenzo Mitchell Barroso
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

#undef _______
#define _______ KC_NO

//define layers
enum layers {
  BASE,
  MEDR,
  NAVR,
  SYML,
  NUML,
  FUNL,
  GAME
};


//layer led colors

void rgb_matrix_indicators_user(void) {

//game indicators

if(IS_LAYER_ON(GAME)) {
  rgb_matrix_set_color(11, 0, 40, 50);
}

//layer indicators

if(IS_LAYER_ON(NAVR)) {
  rgb_matrix_set_color(40, 0, 40, 50);

  rgb_matrix_set_color(19, 0, 40, 50);
  rgb_matrix_set_color(20, 0, 40, 50);
  rgb_matrix_set_color(21, 0, 40, 50);
  rgb_matrix_set_color(22, 0, 40, 50);
}

if(IS_LAYER_ON(MEDR)) {
  rgb_matrix_set_color(39, 50, 10, 20);

  rgb_matrix_set_color(19, 50, 10, 20);

  rgb_matrix_set_color(22, 50, 10, 20);

  rgb_matrix_set_color(42, 50, 10, 20);
}

if(IS_LAYER_ON(FUNL)) {
  rgb_matrix_set_color(43, 50, 0, 0);

  rgb_matrix_set_color(1, 50, 0, 0);
  rgb_matrix_set_color(2, 50, 0, 0);
  rgb_matrix_set_color(3, 50, 0, 0);
  rgb_matrix_set_color(4, 50, 0, 0);

  rgb_matrix_set_color(13, 50, 0, 0);
  rgb_matrix_set_color(14, 50, 0, 0);
  rgb_matrix_set_color(15, 50, 0, 0);
  rgb_matrix_set_color(16, 50, 0, 0);

  rgb_matrix_set_color(25, 50, 0, 0);
  rgb_matrix_set_color(26, 50, 0, 0);
  rgb_matrix_set_color(27, 50, 0, 0);
  rgb_matrix_set_color(28, 50, 0, 0);
}

if(IS_LAYER_ON(NUML)) {
  rgb_matrix_set_color(42, 10, 0, 50);

  rgb_matrix_set_color(2, 10, 0, 50);
  rgb_matrix_set_color(3, 10, 0, 50);
  rgb_matrix_set_color(4, 10, 0, 50);

  rgb_matrix_set_color(14, 10, 0, 50);
  rgb_matrix_set_color(15, 10, 0, 50);
  rgb_matrix_set_color(16, 10, 0, 50);

  rgb_matrix_set_color(26, 10, 0, 50);
  rgb_matrix_set_color(27, 10, 0, 50);
  rgb_matrix_set_color(28, 10, 0, 50);

  rgb_matrix_set_color(38, 10, 0, 50);
  rgb_matrix_set_color(39, 10, 0, 50);
  rgb_matrix_set_color(40, 10, 0, 50);
}

if(IS_LAYER_ON(SYML)) {
  rgb_matrix_set_color(41, 0, 50, 1.9);

  rgb_matrix_set_color(1, 0, 50, 1.9);
  rgb_matrix_set_color(2, 0, 50, 1.9);
  rgb_matrix_set_color(3, 0, 50, 1.9);
  rgb_matrix_set_color(4, 0, 50, 1.9);
  rgb_matrix_set_color(5, 0, 50, 1.9);

  rgb_matrix_set_color(13, 0, 50, 1.9);
  rgb_matrix_set_color(14, 0, 50, 1.9);
  rgb_matrix_set_color(15, 0, 50, 1.9);
  rgb_matrix_set_color(16, 0, 50, 1.9);
  rgb_matrix_set_color(17, 0, 50, 1.9);

  rgb_matrix_set_color(25, 0, 50, 1.9);
  rgb_matrix_set_color(26, 0, 50, 1.9);
  rgb_matrix_set_color(27, 0, 50, 1.9);
  rgb_matrix_set_color(28, 0, 50, 1.9);
  rgb_matrix_set_color(29, 0, 50, 1.9);

}

//capslock leds

if (host_keyboard_leds() & (1<<USB_LED_CAPS_LOCK)) {
    rgb_matrix_set_color_all(50, 15.6, 0);
  }

}


//--------------------------------------------------------------------------------------------------------

// Left-hand home row mods
#define GUI_A LGUI_T(KC_A)
#define ALT_X RALT_T(KC_X)
#define ALT_S LALT_T(KC_S)
#define CTL_D LCTL_T(KC_D)
#define SFT_F LSFT_T(KC_F)

// Left-hand home row mods
#define SFT_J  LSFT_T(KC_J)
#define CTL_K  LCTL_T(KC_K)
#define ALT_DT RALT_T(KC_DOT)
#define ALT_L  LALT_T(KC_L)
#define GUI_SC LGUI_T(KC_SCLN)

// Thumb layer keys
#define KC_MED LT(MEDR, KC_TAB)
#define KC_NAV LT(NAVR, KC_SPC)
#define KC_SYM LT(SYML, KC_SPC)
#define KC_NUM LT(NUML, KC_BSPC)
#define KC_FUN LT(FUNL, KC_DEL)

//base

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Qwerty
 * ,-----------------------------------------------------------------------------------------------.
 * |  Tab  |   Q   |   W   |   E   |   R   |   T   |   Y   |   U   |   I   |   O   |   P   |  Bksp |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * |  Esc  |   A   |   S   |   D   |   F   |   G   |   H   |   J   |   K   |   L   |   ;   | Enter |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * | Shift |   Z   |   X   |   C   |   V   |   B   |   N   |   M   |   ,   |   .   |   /   | Shift |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * | Ctrl  |  Gui  |  Alt  |  Tab  | Space |     Space     |  Bksp |  Del  |  RAlt |  FN   |  Ctrl |
 * `-----------------------------------------------------------------------------------------------'
 */
[BASE] = LAYOUT_planck_mit(
  KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_BSPC,
  KC_ESC,   GUI_A,    ALT_S,    CTL_D,    SFT_F,    KC_G,     KC_H,     SFT_J,    CTL_K,    ALT_L,    GUI_SC,   KC_ENT,
  KC_LSFT,  KC_Z,     ALT_X,    KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  ALT_DT,   KC_SLSH,  KC_RSFT,
  KC_LCTL,  KC_LGUI,  KC_LALT,  KC_MED,   KC_NAV,        KC_SYM,        KC_NUM,   KC_FUN,   KC_RALT,  TT(NUML), KC_RCTL
),

//layers
/* Navigation
 * ,-----------------------------------------------------------------------------------------------.
 * |  Tab  |       |       |       |       |       |       |       |       |       |       |  Del  |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * | CapsL |  Gui  |  Alt  |  Ctrl | Shift |       | Left  | Down  |  Up   | Right |   |   | Enter |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * | Shift |       | AltGr |       |       |       | Home  |  PgDn |  PgUp |  End  |   \   | Shift |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * | GAME  |       |       |       | ***** |       _       |       |       |       |       |  Ctrl |
 * `-----------------------------------------------------------------------------------------------'
 */
[NAVR] = LAYOUT_planck_mit(
  KC_TAB,   _______,  _______,  _______,  _______,  _______,  _______,   _______,  _______,  _______,  _______,  KC_DEL,
  KC_CAPS,  KC_LGUI,  KC_LALT,  KC_LCTL,  KC_LSFT,  _______,  KC_LEFT,   KC_DOWN,  KC_UP,    KC_RGHT,  KC_PIPE,  KC_ENT,
  KC_LSFT,  _______,  KC_RALT,  _______,  _______,  _______,  KC_HOME,   KC_PGDN,  KC_PGUP,  KC_END,   KC_BSLS,  KC_RSFT,
  TG(GAME), _______,  _______,  _______,  _______,       KC_UNDS,        _______,  _______,  _______,  _______,  KC_RCTL
),
/* Media
 * ,-----------------------------------------------------------------------------------------------.
 * |  Tab  | Reset |       |       |       |       | C_Tog | C_Mod | C_HUI | C_SAI | C_VAI |  Del  |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * | CapsL |  Gui  |  Alt  |  Ctrl | Shift |       |       | M_Prv | M_Vo- | M_Vo+ | M_Nxt | Enter |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * | Shift |       | AltGr |       |       |       |       |       |       |       |       | Shift |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * | Ctrl  |       |       | ***** |       |     M_Stp     | M_Ply | M_Mut |       |       |  Ctrl |
 * `-----------------------------------------------------------------------------------------------'
 */
[MEDR] = LAYOUT_planck_mit(
  KC_TAB,   RESET,    _______,  _______,  _______,  _______,  RGB_TOG,  RGB_MOD,  RGB_HUI,  RGB_SAI,  RGB_VAI,  KC_DEL,
  KC_CAPS,  KC_LGUI,  KC_LALT,  KC_LCTL,  KC_LSFT,  _______,  _______,  KC_MPRV,  KC_VOLD,  KC_VOLU,  KC_MNXT,  KC_ENT,
  KC_LSFT,  _______,  KC_RALT,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  KC_RSFT,
  KC_LCTL,  _______,  _______,  _______,  _______,      KC_MSTP,        KC_MPLY,  KC_MUTE,  KC_RALT,  _______,  KC_RCTL
),

/* Function Keys
 * ,-----------------------------------------------------------------------------------------------.
 * |  Tab  |  F12  |  F7   |  F8   |  F9   | PrScr |       |       |       |       | Reset |  Bksp |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * |  Esc  |  F11  |  F4   |  F5   |  F6   | ScrLk |       | Shift |  Ctrl |  Alt  |  Gui  | Enter |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * | Shift |  F10  |  F1   |  F2   |  F3   | Pause |       |       |       | AltGr |       | Shift |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * | Ctrl  |       |       |       |       |               |       | ***** |       |       |  Ctrl |
 * `-----------------------------------------------------------------------------------------------'
 */
[FUNL] = LAYOUT_planck_mit(
  KC_TAB,   KC_F12,   KC_F7,    KC_F8,    KC_F9,    KC_PSCR,  _______,  _______,  _______,  _______,  RESET,    KC_BSPC,
  KC_ESC,   KC_F11,   KC_F4,    KC_F5,    KC_F6,    KC_SLCK,  _______,  KC_LSFT,  KC_LCTL,  KC_LALT,  KC_LGUI,  KC_ENT,
  KC_LSFT,  KC_F10,   KC_F1,    KC_F2,    KC_F3,    KC_PAUS,  _______,  _______,  _______,  KC_RALT,  _______,  KC_RSFT,
  KC_LCTL,  _______,  _______,  _______,  _______,       _______,       _______,  _______,  _______,  _______,  KC_RCTL
),
/* Numbers
 * ,-----------------------------------------------------------------------------------------------.
 * |  Tab  |   +   |   7   |   8   |   9   |   +   |   -   |       |       |       |       |  Bksp |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * |  Esc  |   -   |   4   |   5   |   6   |   *   |   /   | Shift |  Ctrl |  Gui  |  Alt  | Enter |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * | Shift |   *   |   1   |   2   |   3   |   =   |   ^   |       |       |       | AltGr | Shift |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * | Ctrl  |   /   |   ^   |   .   |   0   |       -       | ***** |       |       |       |  Ctrl |
 * `-----------------------------------------------------------------------------------------------'
 */
[NUML] = LAYOUT_planck_mit(
  KC_TAB,   KC_PLUS,  KC_7,     KC_8,     KC_9,     KC_PLUS,  KC_MINS,  _______,  _______,  _______,  _______,  KC_BSPC,
  KC_ESC,   KC_MINS,  KC_4,     KC_5,     KC_6,     KC_ASTR,  KC_SLSH,  KC_LSFT,  KC_LCTL,  KC_LALT,  KC_LGUI,  KC_ENT,
  KC_LSFT,  KC_ASTR,  KC_1,     KC_2,     KC_3,     KC_EQL,   KC_CIRC,  _______,  _______,  KC_RALT,  _______,  KC_LSFT,
  KC_LCTL,  KC_SLSH,  KC_CIRC,  KC_DOT,   KC_0,         KC_MINS,        _______,  _______,  _______,  _______,  _______
),
/* [NUML] = LAYOUT_planck_mit( */
/*   KC_TAB,   KC_LPRN,  KC_7,     KC_8,     KC_9,     KC_RPRN,  KC_LBRC,  KC_AMPR,  KC_ASTR,  KC_LCBR,  KC_RBRC,  KC_BSPC, */
/*   KC_ESC,   KC_COLN,  KC_4,     KC_5,     KC_6,     KC_EQL,   KC_LCBR,  KC_DLR,   KC_PERC,  KC_CIRC,  KC_RCBR,  KC_LSFT, */
/*   KC_LSFT,  KC_GRV,   KC_1,     KC_2,     KC_3,     KC_PLUS,  KC_TILD,  KC_EXLM,  KC_COMM,  KC_DOT,   KC_SLSH,  KC_LCTL, */
/*   KC_LCTL,  _______,  KC_DOT,   KC_UNDS,  KC_0,         KC_MINS,        _______,  _______,  _______,  _______,  _______ */
/* ), */
/* Symbols
 * ,-----------------------------------------------------------------------------------------------.
 * |  Tab  |   !   |   @   |   #   |   (   |   )   |       |       |       |       |       |  Del  |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * |  Esc  |   ~   |   $   |   &   |   [   |   ]   | MLeft | MDown |  MUp  | MRight|       | Enter |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * | Shift |   `   |   ^   |   %   |   {   |   }   |       | WLeft | WDown |  WUp  | WRight| Shift |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * | Ctrl  |  Gui  |  Alt  |   0   |   $   |     *****     |  Btn1 |  Btn3 |  Btn2 |       |  Ctrl |
 * `-----------------------------------------------------------------------------------------------'
 */
[SYML] = LAYOUT_planck_mit(
  KC_TAB,   KC_EXLM,  KC_AT,    KC_HASH,   KC_LPRN, KC_RPRN,  _______,  _______,  _______,  _______,  RESET,    KC_DEL,
  KC_ESC,   KC_TILD,  KC_DLR,   KC_QUOT,   KC_LBRC, KC_RBRC,  KC_MS_L,  KC_MS_D,  KC_MS_U,  KC_MS_R,  _______,  KC_LSFT,
  KC_LSFT,  KC_GRV,   KC_AMPR,  KC_PERC,   KC_LCBR, KC_RCBR,  _______,  KC_WH_L,  KC_WH_D,  KC_WH_U,  KC_WH_R,  KC_LCTL,
  KC_LCTL,  KC_LGUI,  KC_LALT,  KC_0,      KC_DLR,      _______,        KC_BTN1,  KC_BTN3,  KC_BTN2,  _______,  _______
),

/* Game Layer
 * ,-----------------------------------------------------------------------------------------------.
 * |  Tab  |   Q   |   W   |   E   |   R   |   T   |   Y   |   U   |   I   |   O   |   P   |  Exit |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * |  Esc  |   A   |   S   |   D   |   F   |   G   |   H   |   J   |   K   |   L   |   ;   | Enter |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * | Shift |   Z   |   X   |   C   |   V   |   B   |   N   |   M   |   ,   |   .   |   /   | Shift |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * | Ctrl  |  Gui  |  Alt  |  Alt  |  Alt  |     Space     |  Bksp |  Del  | M_Prv | M_Ply | M_Nxt |
 * `-----------------------------------------------------------------------------------------------'
 */
[GAME] = LAYOUT_planck_mit(
  KC_TAB,   KC_Q,     KC_W,     KC_E,      KC_R,    KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     TG(GAME),
  KC_ESC,   KC_A,     KC_S,     KC_D,      KC_F,    KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_LSFT,
  KC_LSFT,  KC_Z,     KC_X,     KC_C,      KC_V,    KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_LCTL,
  KC_LCTL,  KC_LGUI,  KC_LALT,  KC_LALT,   KC_LALT,     KC_SPC,         KC_BSPC,  KC_DEL,   KC_MPRV,  KC_MPLY,  KC_MNXT
)
};
