#include QMK_KEYBOARD_H
#include "features/achordion.h"

/* Qwerty
 * ┌──────┬──────┬──────┬──────┬──────┬──────┬──────┐  ┌──────┬──────┬──────┬──────┬──────┬──────┬──────┐
 * │  `   │   1  │   2  │   3  │   4  │   5  │      │  │      │   6  │   7  │   8  │   9  │   0  │ BkSp │
 * ├──────┼──────┼──────┼──────┼──────┼──────┼──────┤  ├──────┼──────┼──────┼──────┼──────┼──────┼──────┤
 * │ Tab  │   Q  │   W  │   E  │   R  │   T  │      │  │      │   Y  │   U  │   I  │   O  │   P  │   \  │
 * ├──────┼──────┼──────┼──────┼──────┼──────┼──────┤  ├──────┼──────┼──────┼──────┼──────┼──────┼──────┤
 * │      │   A  │   S  │   D  │   F  │   G  │      │  │      │   H  │   J  │   K  │   L  │   ;  │   '  │
 * ├──────┼──────┼──────┼──────┼──────┼──────┼──────┤  ├──────┼──────┼──────┼──────┼──────┼──────┼──────┤
 * │ NAV  │   Z  │   X  │   C  │   V  │   B  │      │  │      │   N  │   M  │   ,  │   .  │   /  │      │
 * └──────┴──────┴──────┼──────┼──────┼──────┼──────┤  ├──────┼──────┼──────┼──────┼──────┴──────┴──────┘
 *                      │      │      │      │      │  │      │      │  RGB │ Game │
 *                      └──────┴──────┤ Space├──────┤  ├──────┤ Enter├──────┴──────┘
 *                                    │      │      │  │      │      │
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
    _NUM,
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


#define QWERTY   DF(_QWERTY)
#define GAME     DF(_GAME)
#define NAV      MO(_NAV)
#define SYM      MO(_SYM)
#define NUM      TG(_NUM)
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
#define SYM_A LT(_SYM, KC_A)
#define ALT_S LALT_T(KC_S)
#define CTL_D LCTL_T(KC_D)
#define SFT_F LSFT_T(KC_F)
#define GUI_Z LGUI_T(KC_Z)
#define ALTG_X RALT_T(KC_X)

#define SFT_J RSFT_T(KC_J)
#define CTL_K RCTL_T(KC_K)
#define ALT_L LALT_T(KC_L)
#define SYM_SC LT(_SYM, KC_SCLN)
#define ALTG_DT RALT_T(KC_DOT)
#define GUI_SL RGUI_T(KC_SLSH)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_QWERTY] = LAYOUT(
        KC_GRV,   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    GAME,                      KC_EQL,  KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSLS,
        KC_TAB,   KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    ADJUST,                    KC_RBRC, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
        _______,  SYM_A,   ALT_S,   CTL_D,   SFT_F,   KC_G,    NUM,                       KC_RPRN, KC_H,    SFT_J,   CTL_K,   ALT_L,   SYM_SC,  KC_QUOT,
        NAV,      GUI_Z,   ALTG_X,  KC_C,    KC_V,    KC_B,    NUM,                       KC_RCBR, KC_N,    KC_M,    KC_COMM, ALTG_DT, GUI_SL,  _______,
                                    KC_LEFT, KC_RGHT, KC_SPC,  _______, _______, _______, QK_REP,  KC_ENT,  KC_DOWN, KC_UP, 

        KC_VOLD, KC_VOLU, KC_VOLD, KC_VOLU, KC_VOLD, KC_VOLU,                                      KC_VOLD, KC_VOLU, KC_VOLD, KC_VOLU, KC_VOLD, KC_VOLU,
        KC_VOLD, KC_VOLU, KC_MNXT, KC_MPLY, KC_MPRV,                                                        KC_VOLD, KC_VOLU, KC_MNXT, KC_MPLY, KC_MPRV
    ),

    [_GAME] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______, _______,
        KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    _______, _______,                   _______, _______, KC_J,    KC_K,    KC_L,    KC_SCLN, _______,
        KC_LSFT, KC_Z,    KC_X,    _______, _______, _______, _______,                   _______, _______, _______, _______, KC_DOT,  KC_SLSH, KC_RSFT,
                                   _______, KC_LALT, _______, _______, _______, _______, _______, _______, _______, QWERTY,

        _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______,                                                       _______, _______, _______, _______, _______
    ),

    [_NAV] = LAYOUT(
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F11,                    KC_F11,  KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______,
        _______, KC_HOME, KC_UP,   KC_END,  XXXXXXX, XXXXXXX, KC_F12,                    KC_F12,  KC_PGUP, KC_HOME, KC_UP,   KC_END,  KC_PSCR, _______,
        _______, KC_LEFT, KC_DOWN, KC_RGHT, XXXXXXX, XXXXXXX, KC_F13,                    KC_F13,  KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, KC_INS,  _______,
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_F14,                    KC_F14,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
                                   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,

        _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______,                                                       _______, _______, _______, _______, _______
    ),
    
    [_SYM] = LAYOUT(
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F11,                    KC_F11,  KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  XXXXXXX,
        _______, _______, KC_LABK, KC_RABK, KC_AT,   _______, KC_F12,                    KC_F12,  XXXXXXX, KC_P7,   KC_LBRC, KC_RBRC, XXXXXXX, KC_DEL,
        KC_CAPS, KC_EXLM, KC_MINS, KC_PLUS, KC_EQL , KC_HASH, KC_F13,                    KC_F13,  XXXXXXX, KC_P4,   KC_LPRN, KC_RPRN, XXXXXXX, XXXXXXX,
        _______, _______, KC_SLSH, KC_ASTR, KC_CIRC, _______, KC_F14,                    KC_F14,  XXXXXXX, KC_P1,   KC_LCBR, KC_RCBR, XXXXXXX, _______,
                                   KC_PGDN, KC_PGUP, KC_UNDS, _______, _______, _______, _______, _______, KC_HOME, KC_END,

        _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______,                                                       _______, _______, _______, _______, _______
    ),
    
    [_NUM] = LAYOUT(
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   _______,                   KC_F11,  KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______,
        _______, _______, _______, _______, _______, _______, _______,                   KC_F12,  _______, KC_P7,   KC_P8,   KC_P9,   _______, _______,
        _______, _______, _______, _______, _______, _______, _______,                   KC_F13,  _______, KC_P4,   KC_P5,   KC_P6,   _______, _______,
        _______, _______, _______, _______, _______, _______, _______,                   KC_F14,  _______, KC_P1,   KC_P2,   KC_P3,   _______, _______,
                                   _______, _______, _______, _______, _______, _______, _______, _______, KC_P0,   KC_PDOT,

        _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______,                                                       _______, _______, _______, _______, _______
    ),

    [_ADJUST] = LAYOUT(
        _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   _______,                   KC_F11,  KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______,
        _______, RGB_SAI, RGB_VAI, RGB_HUI, RGB_SPI, QK_BOOT, _______,                   KC_F12, _______, _______, _______, _______, _______, _______,
        _______, RGB_SAD, RGB_VAD, RGB_HUD, RGB_SPD, RGB_RST, _______,                   KC_F13, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______, _______,
                                   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,

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
    case SYM_A:
    case ALT_S:
    case GUI_Z:
    case ALTG_X:
    case ALT_L:
    case SYM_SC:
    case ALTG_DT:
    case GUI_SL:
      return TAPPING_TERM + 15;

    default:
      return TAPPING_TERM;
  }
}

// uint16_t get_quick_tap_term(uint16_t keycode, keyrecord_t* record) {
//   // If you quickly hold a tap-hold key after tapping it, the tap action is
//   // repeated. Key repeating is useful e.g. for Vim navigation keys, but can
//   // lead to missed triggers in fast typing. Here, returning 0 means we
//   // instead want to "force hold" and disable key repeating.
//   switch (keycode) {
//     // Repeating is useful for Vim navigation keys.
//     case SFT_J:
//     case CTL_K:
//     case ALT_L:
//       return QUICK_TAP_TERM;  // Enable key repeating.
//     default:
//       return 0;  // Otherwise, force hold and disable key repeating.
//   }
// }

bool achordion_chord(uint16_t tap_hold_keycode, keyrecord_t* tap_hold_record,
                     uint16_t other_keycode, keyrecord_t* other_record) {
  // Exceptionally consider the following chords as holds, even though they
  // are on the same hand in Magic Sturdy.
  switch (tap_hold_keycode) {
    case SYM_A:  // A + F.
      if (other_keycode == SFT_F) {
        return true;
      }
      break;
    case CTL_D:  // CTRL + {X,C,V}
      if (other_keycode == ALTG_X || other_keycode == KC_C || other_keycode == KC_V) {
        return true;
      }
      break;
  }

  // Also allow same-hand holds when the other key is in the rows below the
  // alphas. I need the `% (MATRIX_ROWS / 2)` because my keyboard is split.
  if (other_record->event.key.row % MATRIX_ROWS >= 4) {
    return true;
  }

  // Otherwise, follow the opposite hands rule.
  return achordion_opposite_hands(tap_hold_record, other_record);
}

uint16_t achordion_timeout(uint16_t tap_hold_keycode) {
  switch (tap_hold_keycode) {
    case GUI_Z:
    case GUI_SL:
      return 0;  // Bypass Achordion for these keys.
  }

  return 500;  // Otherwise use a timeout of 500 ms.
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

void matrix_scan_user(void) {
    achordion_task();
}

//
// CUSTOM RGB
//
static int caps_word_state = 0;
void caps_word_set_user(bool active) {
    if (active) {
        caps_word_state = 1;
    } else {
        caps_word_state = 0;
    }
}

void rgb_matrix_indicators_user(void) {
    // capslock indicators
    if (host_keyboard_leds() & (1<<USB_LED_CAPS_LOCK)) {
        rgb_matrix_set_color_all(RGB_ORANGE);
    }
    if (caps_word_state) {
        rgb_matrix_set_color_all(RGB_ORANGE);
    }
    
    // layer indicators
    if(IS_LAYER_ON(_GAME)) {
        rgb_matrix_set_color( 47, RGB_RED);
    }
    if(IS_LAYER_ON(_NUM)) {
        rgb_matrix_set_color( 61, RGB_BLUE);
        rgb_matrix_set_color(121, RGB_BLUE);
        rgb_matrix_set_color(122, RGB_BLUE);
        rgb_matrix_set_color(123, RGB_BLUE);
        rgb_matrix_set_color(130, RGB_BLUE);
        rgb_matrix_set_color(129, RGB_BLUE);
        rgb_matrix_set_color(128, RGB_BLUE);
        rgb_matrix_set_color(135, RGB_BLUE);
        rgb_matrix_set_color(136, RGB_BLUE);
        rgb_matrix_set_color(137, RGB_BLUE);
        rgb_matrix_set_color(153, RGB_BLUE);
        rgb_matrix_set_color(154, RGB_BLUE);
    }
    if(IS_LAYER_ON(_NAV) {
        rgb_matrix_set_color(129, RGB_SPRINGGREEN);
        rgb_matrix_set_color(135, RGB_SPRINGGREEN);
        rgb_matrix_set_color(136, RGB_SPRINGGREEN);
        rgb_matrix_set_color(137, RGB_SPRINGGREEN);
    }
    if(IS_LAYER_ON(_ADJUST)) {
        rgb_matrix_set_color( 48, RGB_MAGENTA);
        rgb_matrix_set_color( 49, RGB_RED);
        rgb_matrix_set_color( 60, RGB_ORAGNE);
        rgb_matrix_set_color( 53, RGB_GREEN);
        rgb_matrix_set_color( 52, RGB_GREEN);
        rgb_matrix_set_color( 51, RGB_GREEN);
        rgb_matrix_set_color( 50, RGB_GREEN);
        rgb_matrix_set_color( 56, RGB_BLUE);
        rgb_matrix_set_color( 57, RGB_BLUE);
        rgb_matrix_set_color( 58, RGB_BLUE);
        rgb_matrix_set_color( 59, RGB_BLUE);
    }
}
