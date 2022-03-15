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
  MOUR,
  SYML,
  NUML,
  PROL,
  FUNL,
  GAME
};


//layer led colors

void rgb_matrix_indicators_user(void) {

//game indicators

if(IS_LAYER_ON(GAME)) {
  rgb_matrix_set_color(46, 0, 40, 50);
}

//layer indicators

if(IS_LAYER_ON(NAVR)) {
  rgb_matrix_set_color(39, 0, 40, 50);

  rgb_matrix_set_color(9, 0, 40, 50);
  rgb_matrix_set_color(20, 0, 40, 50);
  rgb_matrix_set_color(21, 0, 40, 50);
  rgb_matrix_set_color(22, 0, 40, 50);
}

if(IS_LAYER_ON(MEDR)) {
  rgb_matrix_set_color(38, 50, 10, 20);

  rgb_matrix_set_color(9, 50, 10, 20);
  rgb_matrix_set_color(20, 50, 10, 20);
  rgb_matrix_set_color(21, 50, 10, 20);
  rgb_matrix_set_color(22, 50, 10, 20);

  rgb_matrix_set_color(42, 50, 10, 20);
}

if(IS_LAYER_ON(FUNL)) {
  rgb_matrix_set_color(44, 50, 0, 0);

  rgb_matrix_set_color(0, 50, 0, 0);
  rgb_matrix_set_color(1, 50, 0, 0);
  rgb_matrix_set_color(2, 50, 0, 0);
  rgb_matrix_set_color(3, 50, 0, 0);

  rgb_matrix_set_color(12, 50, 0, 0);
  rgb_matrix_set_color(13, 50, 0, 0);
  rgb_matrix_set_color(14, 50, 0, 0);
  rgb_matrix_set_color(15, 50, 0, 0);

  rgb_matrix_set_color(24, 50, 0, 0);
  rgb_matrix_set_color(25, 50, 0, 0);
  rgb_matrix_set_color(26, 50, 0, 0);
  rgb_matrix_set_color(27, 50, 0, 0);
}

if(IS_LAYER_ON(NUML)) {
  rgb_matrix_set_color(43, 10, 0, 50);

  rgb_matrix_set_color(1, 10, 0, 50);
  rgb_matrix_set_color(2, 10, 0, 50);
  rgb_matrix_set_color(3, 10, 0, 50);

  rgb_matrix_set_color(13, 10, 0, 50);
  rgb_matrix_set_color(14, 10, 0, 50);
  rgb_matrix_set_color(15, 10, 0, 50);

  rgb_matrix_set_color(25, 10, 0, 50);
  rgb_matrix_set_color(26, 10, 0, 50);
  rgb_matrix_set_color(27, 10, 0, 50);

  rgb_matrix_set_color(38, 10, 0, 50);
  rgb_matrix_set_color(39, 10, 0, 50);
}

if(IS_LAYER_ON(SYML)) {
  rgb_matrix_set_color(44, 0, 50, 1.9);

  rgb_matrix_set_color(0, 0, 50, 1.9);
  rgb_matrix_set_color(1, 0, 50, 1.9);
  rgb_matrix_set_color(2, 0, 50, 1.9);
  rgb_matrix_set_color(3, 0, 50, 1.9);
  rgb_matrix_set_color(4, 0, 50, 1.9);

  rgb_matrix_set_color(12, 0, 50, 1.9);
  rgb_matrix_set_color(13, 0, 50, 1.9);
  rgb_matrix_set_color(14, 0, 50, 1.9);
  rgb_matrix_set_color(15, 0, 50, 1.9);
  rgb_matrix_set_color(16, 0, 50, 1.9);

  rgb_matrix_set_color(24, 0, 50, 1.9);
  rgb_matrix_set_color(25, 0, 50, 1.9);
  rgb_matrix_set_color(26, 0, 50, 1.9);
  rgb_matrix_set_color(27, 0, 50, 1.9);
  rgb_matrix_set_color(28, 0, 50, 1.9);

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
#define KC_MOU LT(MOUR, KC_ESC)
#define KC_PRO LT(PROL, KC_ENT)
#define KC_NUM LT(NUML, KC_BSPC)
#define KC_SYM LT(SYML, KC_DEL)

//base

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Qwerty
 * ,-----------------------------------------------------------------------------------------------.
 * |   Q   |   W   |   E   |   R   |   T   |///////|///////|   Y   |   U   |   I   |   O   |   P   |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * |   A   |   S   |   D   |   F   |   G   |  ESC  |///////|   H   |   J   |   K   |   L   |   ;   |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * |   Z   |   X   |   C   |   V   |   B   | CAPSL |///////|   N   |   M   |   ,   |   .   |   /   |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * |///////|///////|  MED  |  NAV  |  MOU  |///////////////|  PRO  |  NUM  |  SYM  |  FUN  |///////|
 * `-----------------------------------------------------------------------------------------------'
 */
[BASE] = LAYOUT_planck_mit(
  KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     _______,  _______,  KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,
  GUI_A,    ALT_S,    CTL_D,    SFT_F,    KC_G,     KC_ESC,   _______,  KC_H,     SFT_J,    CTL_K,    ALT_L,    GUI_SC,
  KC_Z,     ALT_X,    KC_C,     KC_V,     KC_B,     KC_CAPS,  _______,  KC_N,     KC_M,     KC_COMM,  ALT_DT,   KC_SLSH,
  _______,  _______,  KC_MED,   KC_NAV,   KC_MOU,       _______,        KC_PRO,   KC_NUM,   KC_SYM,   MO(FUNL), _______
),

//layers
/* Navigation
 * ,-----------------------------------------------------------------------------------------------.
 * |       |       |       |       |       |///////|///////|       | PgDn  |   Up  |  PgUp |       |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * |  Gui  |  Alt  |  Ctrl | Shift |       |///////|///////|       | Left  |  Down | Right |   |   |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * |       | AltGr |       |       |       |///////|///////|       | Home  |       |  End  |   \   |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * | GAME  |///////|       | ***** |       |///////////////|       |       |       |///////|///////|
 * `-----------------------------------------------------------------------------------------------'
 */
[NAVR] = LAYOUT_planck_mit(
  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  KC_PGDN,  KC_UP,    KC_PGUP,  _______,
  KC_LGUI,  KC_LALT,  KC_LCTL,  KC_LSFT,  _______,  _______,  _______,  _______,  KC_LEFT,  KC_DOWN,  KC_RGHT,  KC_PIPE,
  _______,  KC_RALT,  _______,  _______,  _______,  _______,  _______,  _______,  KC_HOME,  _______,  KC_END,   KC_BSLS,
  TG(GAME), _______,  _______,  _______,  _______,       _______,       _______,  _______,  _______,  _______,  _______
),
/* Media
 * ,-----------------------------------------------------------------------------------------------.
 * | Reset |       |       |       |       |///////|///////|       |       | M_Vo+ |       |       |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * |  Gui  |  Alt  |  Ctrl | Shift |       |///////|///////|       | M_Prv | M_Vo- | M_Nxt |       |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * |       | AltGr |       |       |       |///////|///////| C_Tog | C_Mod | C_HUI | C_SAI | C_VAI |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * |///////|///////| ***** |       |       |///////////////| M_Stp | M_Ply | M_Mut |///////|///////|
 * `-----------------------------------------------------------------------------------------------'
 */
[MEDR] = LAYOUT_planck_mit(
  RESET,    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  KC_VOLU,  _______,  _______,
  KC_LGUI,  KC_LALT,  KC_LCTL,  KC_LSFT,  _______,  _______,  _______,  _______,  KC_MPRV,  KC_VOLD,  KC_MNXT,  _______,
  _______,  KC_RALT,  _______,  _______,  _______,  _______,  _______,  RGB_TOG,  RGB_MOD,  RGB_HUI,  RGB_SAI,  RGB_VAI,
  _______,  _______,  _______,  _______,  _______,      _______,        KC_MSTP,  KC_MPLY,  KC_MUTE,  _______,  _______
),
/* Mouse
 * ,-----------------------------------------------------------------------------------------------.
 * | Reset |       |       |       |       |///////|///////|       | WDown |  MUp  |  WUp  |       |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * |  Gui  |  Alt  |  Ctrl | Shift |       |///////|///////|       | MLeft | MDown | MRight|       |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * |       | AltGr |       |       |       |///////|///////|       | WLeft |       | WRight|       |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * |///////|///////|       |       | ***** |///////////////| Btn1  | Btn3  | Btn2  |///////|///////|
 * `-----------------------------------------------------------------------------------------------'
 */
[MOUR] = LAYOUT_planck_mit(
  RESET,    _______,  _______,  _______,  _______,  _______,  _______,  _______,  KC_WH_D,  KC_MS_U,  KC_WH_U,  _______,
  KC_LGUI,  KC_LALT,  KC_LCTL,  KC_LSFT,  _______,  _______,  _______,  _______,  KC_MS_L,  KC_MS_D,  KC_MS_R,  _______,
  _______,  KC_RALT,  _______,  _______,  _______,  _______,  _______,  _______,  KC_WH_L,  _______,  KC_WH_R,  _______,
  _______,  _______,  _______,  _______,  _______,      _______,        KC_BTN1,  KC_BTN3,  KC_BTN2,  _______,  _______
),

/* Function Keys
 * ,-----------------------------------------------------------------------------------------------.
 * |  F12  |  F7   |  F8   |  F9   | PrScr |///////|///////|       |       |       |       | Reset |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * |  F11  |  F4   |  F5   |  F6   | ScrLk |///////|///////|       | Shift |  Ctrl |  Alt  |  Gui  |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * |  F10  |  F1   |  F2   |  F3   | Pause |///////|///////|       |       |       | AltGr |       |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * |///////|///////|       |       |       |///////////////|       |       |       | ***** |///////|
 * `-----------------------------------------------------------------------------------------------'
 */
[FUNL] = LAYOUT_planck_mit(
  KC_F12,   KC_F7,    KC_F8,    KC_F9,    KC_PSCR,  _______,  _______,  _______,  _______,  _______,  _______,  RESET,
  KC_F11,   KC_F4,    KC_F5,    KC_F6,    KC_SLCK,  _______,  _______,  _______,  KC_LSFT,  KC_LCTL,  KC_LALT,  KC_LGUI,
  KC_F10,   KC_F1,    KC_F2,    KC_F3,    KC_PAUS,  _______,  _______,  _______,  _______,  _______,  KC_RALT,  _______,
  _______,  _______,  _______,  _______,  _______,       _______,       _______,  _______,  _______,  _______,  _______
),
/* Programming
 * ,-----------------------------------------------------------------------------------------------.
 * |   ~   |   &   |   (   |   )   |       |///////|///////|       |       |       |       |       |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * |   '   |   "   |   [   |   ]   |       |///////|///////|       | Shift |  Ctrl |  Alt  |  Gui  |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * |   `   |       |   {   |   }   |       |///////|///////|       |       |       | AltGr |       |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * |///////|///////|       |   _   |   -   |///////////////| ***** |       |       |///////|///////|
 * `-----------------------------------------------------------------------------------------------'
 */
[PROL] = LAYOUT_planck_mit(
  KC_TILD,  KC_AMPR,  KC_LPRN,  KC_RPRN,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
  KC_QUOT,  KC_DLR,   KC_LBRC,  KC_RBRC,  _______,  _______,  _______,  _______,  KC_LSFT,  KC_LCTL,  KC_LALT,  KC_LGUI,
  KC_GRV,   _______,  KC_LCBR,  KC_RCBR,  _______,  _______,  _______,  _______,  _______,  _______,  KC_RALT,  _______,
  KC_LGUI,  KC_LALT,  _______,  KC_UNDS,  _______,       _______,       _______,  _______,  _______,  _______,  _______
),
/* Numbers
 * ,-----------------------------------------------------------------------------------------------.
 * |   /   |   7   |   8   |   9   |   *   |///////|///////|       |       |       |       |       |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * |   -   |   4   |   5   |   6   |   +   |///////|///////|       | Shift |  Ctrl |  Alt  |  Gui  |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * |   =   |   1   |   2   |   3   |   ^   |///////|///////|       |       |       | AltGr |       |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * |///////|///////|   .   |   0   |   %   |///////////////|       | ***** |       |///////|///////|
 * `-----------------------------------------------------------------------------------------------'
 */
[NUML] = LAYOUT_planck_mit(
  KC_SLSH,  KC_7,     KC_8,     KC_9,     KC_ASTR,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
  KC_MINS,  KC_4,     KC_5,     KC_6,     KC_PLUS,  _______,  _______,  _______,  KC_LSFT,  KC_LCTL,  KC_LALT,  KC_LGUI,
  KC_EQL,   KC_1,     KC_2,     KC_3,     KC_CIRC,  _______,  _______,  _______,  _______,  _______,  KC_RALT,  _______,
  _______,  _______,  KC_DOT,   KC_0,     KC_PERC,      _______,        _______,  _______,  _______,  _______,  _______
),
/* Symbols
 * ,-----------------------------------------------------------------------------------------------.
 * |   !   |   @   |   #   |   $   |       |///////|///////|       |       |       |       |       |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * |       |       |       |       |       |///////|///////|       | Shift |  Ctrl |  Alt  |  Gui  |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * |       |       |       |       |       |///////|///////|       |       |       | AltGr |       |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * |///////|///////|       |   $   |       |///////////////|       |       | ***** |///////|///////|
 * `-----------------------------------------------------------------------------------------------'
 */
[SYML] = LAYOUT_planck_mit(
  KC_EXLM,  KC_AT,    KC_HASH,   KC_LPRN, KC_RPRN,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
  KC_TILD,  KC_DLR,   KC_QUOT,   KC_LBRC, KC_RBRC,  _______,  _______,  _______,  KC_LSFT,  KC_LCTL,  KC_LALT,  KC_LGUI,
  KC_GRV,   KC_AMPR,  KC_PERC,   KC_LCBR, KC_RCBR,  _______,  _______,  _______,  _______,  _______,  KC_RALT,  _______,
  KC_LGUI,  KC_LALT,  KC_0,      KC_DLR,  _______,       _______,       _______,  _______,  _______,  _______,  _______
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
  KC_TAB,   KC_Q,     KC_W,     KC_E,      KC_R,    KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_BSPC,
  KC_ESC,   KC_A,     KC_S,     KC_D,      KC_F,    KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_ENT,
  KC_LSFT,  KC_Z,     KC_X,     KC_C,      KC_V,    KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT,
  KC_LCTL,  KC_LGUI,  KC_LALT,  KC_NAV,    KC_LALT,     KC_SPC,         KC_PRO,   KC_NUM,   KC_SYM,   MO(FUNL), TG(GAME)
)
};
