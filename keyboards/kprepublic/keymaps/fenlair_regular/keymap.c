/* Copyright 2020 tominabox1
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

enum layers {
  _QWERTY,
  _LOWER,
  _RAISE,
  _FN,
};

#define LOWER TT(_LOWER)
#define RAISE MO(_RAISE)
#define FN MO(_FN)

/* void rgb_matrix_indicators_user(void) { */
/*   rgb_matrix_set_color_all(0, 0, 0); */
/*   if(IS_LAYER_ON(_LOWER)) { */
/*     rgb_matrix_set_color( 7, 0, 40, 50); */
/*     rgb_matrix_set_color( 8, 0, 40, 50); */
/*     rgb_matrix_set_color( 9, 0, 40, 50); */
/*     rgb_matrix_set_color(19, 0, 40, 50); */
/*     rgb_matrix_set_color(20, 0, 40, 50); */
/*     rgb_matrix_set_color(21, 0, 40, 50); */
/*     rgb_matrix_set_color(31, 0, 40, 50); */
/*     rgb_matrix_set_color(32, 0, 40, 50); */
/*     rgb_matrix_set_color(33, 0, 40, 50); */
/*     rgb_matrix_set_color(42, 0, 40, 50); */
/*     rgb_matrix_set_color(43, 0, 40, 50); */
/*   } */
/*   if(IS_LAYER_ON(_FN)) { */
/*     rgb_matrix_set_color( 1, 50, 0, 0); */
/*     rgb_matrix_set_color( 2, 50, 0, 0); */
/*     rgb_matrix_set_color( 3, 50, 0, 0); */
/*     rgb_matrix_set_color( 4, 50, 0, 0); */
/*     rgb_matrix_set_color(13, 50, 0, 0); */
/*     rgb_matrix_set_color(14, 50, 0, 0); */
/*     rgb_matrix_set_color(15, 50, 0, 0); */
/*     rgb_matrix_set_color(16, 50, 0, 0); */
/*     rgb_matrix_set_color(24, 50, 0, 0); */
/*     rgb_matrix_set_color(25, 50, 0, 0); */
/*     rgb_matrix_set_color(26, 50, 0, 0); */
/*     rgb_matrix_set_color(27, 50, 0, 0); */

/*     rgb_matrix_set_color( 7, 50, 0, 0); */
/*     rgb_matrix_set_color( 8, 50, 0, 0); */
/*     rgb_matrix_set_color(18, 50, 0, 0); */
/*     rgb_matrix_set_color(19, 50, 0, 0); */
/*     rgb_matrix_set_color(20, 50, 0, 0); */
/*     rgb_matrix_set_color(21, 50, 0, 0); */
/*     rgb_matrix_set_color(31, 50, 0, 0); */
/*     rgb_matrix_set_color(32, 50, 0, 0); */
/*     rgb_matrix_set_color(42, 50, 0, 0); */
/*     rgb_matrix_set_color(43, 50, 0, 0); */
/*   } */
/* } */

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Shift |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | Gui  | Alt  |      |Lower |    Space    |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_planck_mit(
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
    KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT ,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
    KC_LCTL, KC_LGUI, KC_LALT, KC_A,   LOWER,       KC_SPC,       RAISE,   KC_RALT, KC_RALT, FN,      KC_RCTL
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   `  |      |      |      |      |      |   +  |   7  |   8  |   9  |   *  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |   +  |   -  |   *  |   /  |   ^  |   -  |   4  |   5  |   6  |   |  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |   =  |   1  |   2  |   3  |   \  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      _      |   0  |   .  |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_planck_mit(
  KC_GRV , _______, _______, _______, _______, _______, KC_PLUS, KC_7   , KC_8   , KC_9   , KC_ASTR, KC_DEL ,
  _______, KC_PLUS, KC_MINS, KC_ASTR, KC_SLSH, KC_CIRC, KC_MINS, KC_4   , KC_5   , KC_6   , KC_PIPE, _______,
  _______, _______, _______, _______, _______, _______, KC_EQL , KC_1   , KC_2   , KC_3   , KC_BSLS, _______,
  _______, _______, _______, _______, _______,     KC_UNDS,      KC_0   , KC_DOT , _______, _______, _______
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   !  |   @  |   {  |   }  |      |      |      |      |      |      | Del  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |   '  |   "  |   (  |   )  |   %  |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |   #  |   $  |   [  |   ]  |   &  |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_planck_mit(
  KC_TILD, KC_EXLM, KC_AT  , KC_LCBR, KC_RCBR, _______, _______, _______, _______, _______, _______, _______,
  _______, KC_QUOT, S(KC_QUOT), KC_LPRN, KC_RPRN, KC_PERC, KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, _______, _______,
  _______, KC_HASH, KC_DLR , KC_LBRC, KC_RBRC, KC_AMPR, KC_HOME, KC_PGDN, KC_PGUP, KC_END, _______, _______,
  _______, _______, _______, _______, _______,     KC_BSPC,      _______, _______, _______, _______, _______
),

/* Fn
 * ,-----------------------------------------------------------------------------------.
 * |      |  F1  |  F2  |  F3  |  F4  |      |      |      |      |      |      | Reset|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F5  |  F6  |  F7  |  F8  |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F9  |  F10 |  F11 |  F12 |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_FN] = LAYOUT_planck_mit(
  _______, KC_F1  , KC_F2  , KC_F3  , KC_F4  , _______, _______, RGB_HUI, RGB_HUD, _______, DEBUG  , RESET  ,
  _______, KC_F5  , KC_F6  , KC_F7  , KC_F8  , _______, RGB_TOG, RGB_SAI, RGB_SAD, RGB_MOD, _______, _______,
  _______, KC_F9  , KC_F10 , KC_F11 , KC_F12 , _______, _______, RGB_VAI, RGB_VAD, _______, _______, _______,
  _______, _______, _______, _______, _______,     _______,      _______, _______, _______, _______, _______
)

};

