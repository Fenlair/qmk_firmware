#include QMK_KEYBOARD_H
#include "features/achordion.h"

/* Qwerty
 * ┌──────┬──────┬──────┬──────┬──────┬──────┬──────┐  ┌──────┬──────┬──────┬──────┬──────┬──────┬──────┐
 * │ GESC │   1  │   2  │   3  │   4  │   5  │   -  │  │   =  │   6  │   7  │   8  │   9  │   0  │ BkSp │
 * ├──────┼──────┼──────┼──────┼──────┼──────┼──────┤  ├──────┼──────┼──────┼──────┼──────┼──────┼──────┤
 * │ Tab  │   Q  │   W  │   E  │   R  │   T  │   [  │  │   ]  │   Y  │   U  │   I  │   O  │   P  │   \  │
 * ├──────┼──────┼──────┼──────┼──────┼──────┼──────┤  ├──────┼──────┼──────┼──────┼──────┼──────┼──────┤
 * │FN_ESC│   A  │   S  │   D  │   F  │   G  │   (  │  │   )  │   H  │   J  │   K  │   L  │   ;  │   '  │
 * ├──────┼──────┼──────┼──────┼──────┼──────┼──────┤  ├──────┼──────┼──────┼──────┼──────┼──────┼──────┤
 * │Shift │   Z  │   X  │   C  │   V  │   B  │   {  │  │   }  │   N  │   M  │   ,  │   .  │   /  │Enter │
 * └──────┴──────┴──────┼──────┼──────┼──────┼──────┤  ├──────┼──────┼──────┼──────┼──────┴──────┴──────┘
 *                      │ Ctrl │ ALT  │      │ WIN  │  │ PGUP │      │  RGB │ ADJ  │
 *                      └──────┴──────┤ Space├──────┤  ├──────┤ Space├──────┴──────┘
 *                                    │      │ DEL  │  │ Enter│      │
 *                                    └──────┴──────┘  └──────┴──────┘
 * Rotary Encoders:
 *  Left-Thumb | Left of LThumb | Left Extra Col              Right-Thumb | Right of RThumb | Right Extra Col
 * ┌──────┬──────┬──────┬──────┬──────┬──────┐                ┌──────┬──────┬──────┬──────┬──────┬──────┐
 * │Vol Dn│Vol Up│Vol Dn│Vol Up│Vol Dn│Vol Up│                │Vol Dn│Vol Up│Vol Dn│Vol Up│Vol Dn│Vol Up│
 * └──────┴──────┴──────┴──────┴──────┴──────┘                └──────┴──────┴──────┴──────┴──────┴──────┘
 * Left Touchbar                                                     Right Touchbar
 * ┌──────┬──────┬──────┬──────┬──────┐                              ┌──────┬──────┬──────┬──────┬──────┐
 * │Vol Dn│Vol Up│ Prev │ Play │ Next │                              │Vol Dn│Vol Up│ Prev │ Play │ Next │
 * └──────┴──────┴──────┴──────┴──────┘                              └──────┴──────┴──────┴──────┴──────┘
 */

enum phobos_layers {
    _QWERTY,
    _GAME,
    _NAV,
    _SYM,
    _ADJUST
};

enum phobos_keycodes {
    // Disables touch processing
    RGB_RST = SAFE_RANGE,
};

enum phobos_combos {
  CAPS_COMBO,
  // Other combos...
  COMBO_LENGTH
};
uint16_t COMBO_LEN = COMBO_LENGTH;

const uint16_t caps_combo[] PROGMEM = {KC_COMM, KC_C, COMBO_END};

combo_t key_combos[] = {
  [CAPS_COMBO] = COMBO_ACTION(caps_combo),
  // Other combos...
};

#define QWERTY   DF(_QWERTY)
#define GAME     DF(_GAME)
#define NAV      MO(_NAV)
#define SYM      MO(_SYM)
#define ADJUST   MO(_ADJUST)

#define FN_ESC   LT(_FN, KC_ESC)
//#define RGB_ADJ  LT(_ADJUST, RGB_TOG)

// This keymap uses home row mods. In addition to mods, I have home row
// layer-tap keys for the SYM layer. The key arrangement is a variation on
// "GACS-order" home row mods:
//
//             Left hand                          Right hand
// +-------+-------+-------+-------+   +-------+-------+-------+-------+
// |  Sym  |  Alt  | Ctrl  | Shift |   | Shift | Ctrl  |  Alt  |  Sym  |
// +-------+-------+-------+-------+   +-------+-------+-------+-------+
// |  Gui  | AltGr |                                   | AltGr |  Gui  |
// +-------+-------+                                   +-------+-------+

// Home row mods for QWERTY layer.
#define HOME_A LT(_SYM, KC_A)
#define HOME_S LALT_T(KC_S)
#define HOME_D LCTL_T(KC_D)
#define HOME_F LSFT_T(KC_F)
#define HOME_Z LGUI_T(KC_Z)
#define HOME_X RALT_T(KC_X)

#define HOME_J RSFT_T(KC_J)
#define HOME_K RCTL_T(KC_K)
#define HOME_L LALT_T(KC_L)
#define HOME_SC LT(_SYM, KC_SCLN)
#define HOME_DT RALT_T(KC_DOT)
#define HOME_SL RGUI_T(KC_SLSH)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_QWERTY] = LAYOUT(
        KC_GRV,   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_MINS,                   KC_EQL,  KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSLS,
        KC_TAB,   KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_LBRC,                   KC_RBRC, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
        _______,  HOME_A,  HOME_S,  HOME_D,  HOME_F,  KC_G,    KC_LPRN,                   KC_RPRN, KC_H,    HOME_J,  HOME_K,  HOME_L,  HOME_SC, KC_QUOT,
        _______,  HOME_Z,  HOME_X,  KC_C,    KC_V,    KC_B,    KC_LCBR,                   KC_RCBR, KC_N,    KC_M,    KC_COMM, HOME_DT, HOME_SL, _______,
                                    _______, _______, KC_SPC,  _______, _______, _______, _______, KC_ENT,  RGB_TOG, GAME, 

        KC_VOLD, KC_VOLU, KC_VOLD, KC_VOLU, KC_VOLD, KC_VOLU,                                      KC_VOLD, KC_VOLU, KC_VOLD, KC_VOLU, KC_VOLD, KC_VOLU,
        KC_VOLD, KC_VOLU, KC_MNXT, KC_MPLY, KC_MPRV,                                                        KC_VOLD, KC_VOLU, KC_MNXT, KC_MPLY, KC_MPRV
    ),

    [_GAME] = LAYOUT(
        KC_GESC, _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______, _______,
        KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    _______, _______,                   _______, _______, KC_J,    KC_K,    KC_L,    KC_SCLN, _______,
        KC_LSFT, KC_Z,    KC_X,    _______, _______, _______, _______,                   _______, _______, _______, _______, KC_DOT,  KC_SLSH, _______,
                                   _______, KC_LALT, _______, _______, _______, _______, _______, _______, _______, QWERTY,

        _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______,                                                       _______, _______, _______, _______, _______
    ),

    [_NAV] = LAYOUT(
        _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F11,                    KC_F11,  KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______,
        _______, KC_HOME, KC_UP,   KC_END,  _______, _______, KC_F12,                    KC_F12,  KC_PGUP, KC_HOME, KC_UP,   KC_END,  KC_PSCR, _______,
        _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______, KC_F13,                    KC_F13,  KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, KC_INS,  _______,
        _______, AU_TOG,  MU_TOG,  MU_MOD,  _______, _______, KC_F14,                    KC_F14, _______, _______, _______, _______, _______, _______,
                                   _______, _______, _______, _______, _______, KC_MPLY, KC_MNXT, KC_MUTE, KC_VOLD, KC_VOLU,

        _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______,                                                       _______, _______, _______, _______, _______
    ),
    
    [_SYM] = LAYOUT(
        _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F11,                    KC_F12,  KC_F6,   KC_F7,   KC_F8,  KC_F9,   KC_F10,  _______,
        _______, _______, _______, _______, _______, _______, _______,                   _______, _______, KC_P7,   KC_P8,  KC_P9,   _______, _______,
        _______, _______, _______, _______, _______, _______, _______,                   _______, _______, KC_P4,   KC_P5,  KC_P6,   _______, _______,
        _______, _______, _______, _______, _______, _______, _______,                   _______, _______, KC_P1,   KC_P2,  KC_P3,   _______, _______,
                                   _______, _______, _______, _______, _______, _______, _______, _______, KC_P0,   KC_PDOT,

        _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______,                                                       _______, _______, _______, _______, _______
    ),

    [_ADJUST] = LAYOUT(
        _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F11,                    KC_F12,  KC_F6,   KC_F7,   KC_F8,  KC_F9,   KC_F10,  _______,
        _______, RGB_SAD, RGB_VAI, RGB_SAI, QK_BOOT, _______, _______,                   _______, _______, KC_P7,   KC_P8,  KC_P9,   _______, _______,
        _______, RGB_HUD, RGB_VAD, RGB_HUI, RGB_RST, _______, DM_REC1,                   _______, _______, KC_P4,   KC_P5,  KC_P6,   _______, _______,
        _______, RGB_SPD, _______, RGB_SPI, _______, _______, DM_RSTP,                   _______, _______, KC_P1,   KC_P2,  KC_P3,   _______, _______,
                                   _______, _______, _______, _______, _______, _______, _______, _______, KC_P0,   KC_PDOT,

        _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______,                                                       _______, _______, _______, _______, _______
    ),

};

//
// CUSTOM PROCESSING
//
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t* record) {
  switch (keycode) {
    // Increase the tapping term a little for slower ring and pinky fingers.
    case HOME_A:
    case HOME_S:
    case HOME_Z:
    case HOME_X:
    case HOME_L:
    case HOME_SC:
    case HOME_DT:
    case HOME_SL:
      return TAPPING_TERM + 15;

    default:
      return TAPPING_TERM;
  }
}

uint16_t get_quick_tap_term(uint16_t keycode, keyrecord_t* record) {
  // If you quickly hold a tap-hold key after tapping it, the tap action is
  // repeated. Key repeating is useful e.g. for Vim navigation keys, but can
  // lead to missed triggers in fast typing. Here, returning 0 means we
  // instead want to "force hold" and disable key repeating.
  switch (keycode) {
    // Repeating is useful for Vim navigation keys.
    case QHOME_J:
    case QHOME_K:
    case QHOME_L:
      return QUICK_TAP_TERM;  // Enable key repeating.
    default:
      return 0;  // Otherwise, force hold and disable key repeating.
  }
}

bool achordion_chord(uint16_t tap_hold_keycode, keyrecord_t* tap_hold_record,
                     uint16_t other_keycode, keyrecord_t* other_record) {
  // Exceptionally consider the following chords as holds, even though they
  // are on the same hand in Magic Sturdy.
  switch (tap_hold_keycode) {
    case HOME_A:  // A + F.
      if (other_keycode == HOME_F) {
        return true;
      }
      break;
  }

  // Also allow same-hand holds when the other key is in the rows below the
  // alphas. I need the `% (MATRIX_ROWS / 2)` because my keyboard is split.
  if (other_record->event.key.row % (MATRIX_ROWS / 2) >= 4) {
    return true;
  }

  // Otherwise, follow the opposite hands rule.
  return achordion_opposite_hands(tap_hold_record, other_record);
}

uint16_t achordion_timeout(uint16_t tap_hold_keycode) {
  switch (tap_hold_keycode) {
    case HOME_Z:
    case HOME_X:
    case HOME_DT:
    case HOME_SL:
      return 0;  // Bypass Achordion for these keys.
  }

  return 800;  // Otherwise use a timeout of 800 ms.
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_achordion(keycode, record)) { return false; }
    
    switch (keycode)
    {
        case RGB_RST:
            if (record->event.pressed) {
                eeconfig_update_rgb_matrix_default();
            }
            return false;  // Skip all further processing of this key
        default:
            return true;
    }
}

void process_combo_event(uint16_t combo_index, bool pressed) {
  switch(combo_index) {
    case CAPS_COMBO:
      if (pressed) {
        caps_word_on();  // Activate Caps Word!
      }
      break;

    // Other combos...
  }
}

void matrix_scan_user(void) {
    achordion_task();
}

//
// CUSTOM RGB
//
void my_set_rgb(int ind, HSV hsv) {
    RGB rgb = rgb_matrix_hsv_to_rgb(hsv);
    rgb_matrix_set_color(ind, rgb.r, rgb.g, rgb.b);
}

void my_set_rgb_all(HSV hsv) {
    RGB rgb = rgb_matrix_hsv_to_rgb(hsv);
    rgb_matrix_set_color_all(rgb.r, rgb.g, rgb.b);
}

void rgb_matrix_indicators_user(void) {
    // capslock indicators
    if (host_keyboard_leds() & (1<<USB_LED_CAPS_LOCK)) {
        my_set_rgb_all(HSV_ORANGE);
    }
    
    // layer indicators
    if(IS_LAYER_ON(_GAME)) {
        my_set_rgb(154, HSV_RED);
    }
    //if(IS_LAYER_ON(_FN)) {
    //    my_set_rgb(42, HSV_YELLOW);
    //    my_set_rgb(43, HSV_YELLOW);
    //}
    //if(IS_LAYER_ON(_ADJUST)) {
    //    my_set_rgb(153, HSV_MAGENTA);
    //}
}
