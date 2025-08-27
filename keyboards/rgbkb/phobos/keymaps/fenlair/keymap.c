/*
 * ----------------------------------------------------------------------------
 * "THE BEER-WARE LICENSE" (Revision 42):
 * <https://github.com/Legonut> wrote this file.  As long as you retain this
 * notice you can do whatever you want with this stuff. If we meet some day, and
 * you think this stuff is worth it, you can buy me a beer in return. David Rauseo
 * ----------------------------------------------------------------------------
 */

#include QMK_KEYBOARD_H
#include "transactions.h"

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

enum phobos_layers { _QWERTY, _GAME, _NAV, _SYM, _NUM, _ADJUST };

enum phobos_keycodes {
    // Disables touch processing
    TCH_TOG = SAFE_RANGE,
    MENU_BTN,
    MENU_UP,
    MENU_DN,
    RGB_RST
};

// Home row mods for QWERTY layer.
#define GUI_A LGUI_T(KC_A)
#define ALT_S LALT_T(KC_S)
#define CTL_D LCTL_T(KC_D)
#define SFT_F LSFT_T(KC_F)
#define ALTG_X RALT_T(KC_X)

#define SFT_J RSFT_T(KC_J)
#define CTL_K RCTL_T(KC_K)
#define ALT_L LALT_T(KC_L)
#define GUI_SCLN RGUI_T(KC_SCLN)
#define ALTG_DT RALT_T(KC_DOT)

#define QWERTY DF(_QWERTY)
#define GAME DF(_GAME)
#define NAV MO(_NAV)
#define SYM MO(_SYM)
#define NUM TG(_NUM)
#define ADJUST MO(_ADJUST)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    // clang-format off
    [_QWERTY] = LAYOUT(
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    GAME,                      XXXXXXX, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSLS,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    ADJUST,                    ADJUST,  KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
        KC_ESC,  GUI_A,   ALT_S,   CTL_D,   SFT_F,   KC_G,    NUM,                       XXXXXXX, KC_H,    SFT_J,   CTL_K,   ALT_L,   GUI_SCLN,KC_QUOT,
        NAV,     KC_Z,    ALTG_X,  KC_C,    KC_V,    KC_B,    TG(_NAV),                  XXXXXXX, KC_N,    KC_M,    KC_COMM, ALTG_DT, KC_SLSH, NAV,
                                   KC_LEFT, KC_RGHT, KC_SPC,  XXXXXXX, SYM,     SYM,     XXXXXXX, KC_ENT,  KC_DOWN, KC_UP,

        KC_VOLD, KC_VOLU, KC_VOLD, KC_VOLU, KC_VOLD, KC_VOLU, KC_VOLD, KC_VOLU, KC_VOLD, KC_VOLU, KC_VOLD, KC_VOLU, KC_VOLD, KC_VOLU, KC_MNXT, KC_MPLY, KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, KC_MPLY, KC_MPRV),

    [_GAME] = LAYOUT(
        _______, _______, _______, _______, _______, _______, QWERTY,                    _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______, _______,
        KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    _______, _______,                   _______, _______, KC_J,    KC_K,    KC_L,    KC_SCLN, _______,
        KC_LSFT, _______, KC_X,    _______, _______, _______, _______,                   _______, _______, _______, _______, KC_DOT,  _______, KC_RSFT,
                                   _______, KC_LALT, _______, _______, _______, _______, _______, _______, _______, _______,

        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______),

    [_NAV] = LAYOUT(
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F11,                    KC_F11,  KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______,
        _______, KC_HOME, KC_UP,   KC_END,  KC_PGUP, XXXXXXX, KC_F12,                    KC_F12,  KC_PGUP, KC_PGDN, KC_HOME, KC_END,  KC_PSCR, _______,
        _______, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN, XXXXXXX, KC_F13,                    KC_F13,  KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_INS,  _______,
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,                   KC_F14,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
                                   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,

        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______),

    [_SYM] = LAYOUT(
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F11,                    KC_F11,  KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  XXXXXXX,
        _______, _______, KC_LABK, KC_RABK, KC_AT,   _______, KC_F12,                    KC_F12,  XXXXXXX, XXXXXXX, KC_LBRC, KC_RBRC, XXXXXXX, KC_DEL,
        CW_TOGG, KC_EXLM, KC_MINS, KC_PLUS, KC_EQL,  KC_HASH, KC_F13,                    KC_F13,  XXXXXXX, XXXXXXX, KC_LPRN, KC_RPRN, XXXXXXX, XXXXXXX,
        _______, _______, KC_SLSH, KC_ASTR, KC_CIRC, _______, KC_F14,                    KC_F14,  XXXXXXX, XXXXXXX, KC_LCBR, KC_RCBR, XXXXXXX, _______,
                                   KC_HOME, KC_END,  KC_UNDS, _______, _______, _______, _______, _______, KC_PGDN, KC_PGUP,

        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______),

    [_NUM] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______,                   _______, _______, KC_P7,   KC_P8,   KC_P9,   _______, _______,
        _______, _______, _______, _______, _______, _______, _______,                   _______, _______, KC_P4,   KC_P5,   KC_P6,   _______, _______,
        _______, _______, _______, _______, _______, _______, _______,                   _______, _______, KC_P1,   KC_P2,   KC_P3,   _______, _______,
                                   _______, _______, _______, _______, _______, _______, _______, _______, KC_P0, KC_PDOT,

        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______),

    [_ADJUST] = LAYOUT(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, RM_SPDU, RM_VALU, RM_SATU, RM_HUEU, QK_BOOT, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, RM_SPDD, RM_VALD, RM_SATD, RM_HUED, RM_TOGG, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                   RM_PREV, RM_NEXT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,

        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX),

    // clang-format on
};

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        // Increase the tapping term a little for slower ring and pinky fingers.
        case GUI_A:
        case ALT_S:
        case ALTG_X:
        case ALT_L:
        case ALTG_DT:
        case GUI_SCLN:
            return TAPPING_TERM + 15;

        default:
            return TAPPING_TERM;
    }
}

static bool caps_word_state = false;

// void caps_word_set_user(bool active) {
//     caps_word_state = active;
// }

bool rgb_matrix_indicators_user(void) {
// if (host_keyboard_led_state().caps_lock) {
//     rgb_matrix_set_color_all(RGB_ORANGE);
// }
#ifdef CAPS_WORD_ENABLE
    if (caps_word_state) {
        rgb_matrix_set_color_all(RGB_ORANGE);
    }
#endif

    // layer indicators
    // switch (get_highest_layer(layer_state | default_layer_state)) {
    //     case _GAME:
    //         rgb_matrix_set_color(47, RGB_RED);
    //         break;
    // }
    // if (IS_LAYER_ON(_GAME)) {
    //     rgb_matrix_set_color_all(RGB_GREEN);
    //     rgb_matrix_set_color(47, RGB_RED);
    // }

    if (default_layer_state == _GAME + 1) {
        rgb_matrix_set_color(47, RGB_RED);
    }

    if (IS_LAYER_ON(_ADJUST) && is_keyboard_left()) {
        rgb_matrix_set_color(48, RGB_MAGENTA);
        rgb_matrix_set_color(49, RGB_RED);
        rgb_matrix_set_color(60, RGB_ORANGE);
        rgb_matrix_set_color(53, RGB_GREEN);
        rgb_matrix_set_color(52, RGB_GREEN);
        rgb_matrix_set_color(51, RGB_GREEN);
        rgb_matrix_set_color(50, RGB_GREEN);
        rgb_matrix_set_color(56, RGB_BLUE);
        rgb_matrix_set_color(57, RGB_BLUE);
        rgb_matrix_set_color(58, RGB_BLUE);
        rgb_matrix_set_color(59, RGB_BLUE);
    }

    if (IS_LAYER_ON(_NUM)) {
        if (is_keyboard_left()) {
            rgb_matrix_set_color(61, RGB_BLUE);
        }
        rgb_matrix_set_color(158, RGB_BLUE);
        rgb_matrix_set_color(157, RGB_BLUE);
        rgb_matrix_set_color(156, RGB_BLUE);
        rgb_matrix_set_color(163, RGB_BLUE);
        rgb_matrix_set_color(164, RGB_BLUE);
        rgb_matrix_set_color(165, RGB_BLUE);
        rgb_matrix_set_color(172, RGB_BLUE);
        rgb_matrix_set_color(171, RGB_BLUE);
        rgb_matrix_set_color(170, RGB_BLUE);
        rgb_matrix_set_color(175, RGB_BLUE);
        rgb_matrix_set_color(176, RGB_BLUE);
    }

    if (IS_LAYER_ON(_NAV)) {
        if (is_keyboard_left()) {
            rgb_matrix_set_color(62, RGB_GREEN);
        }
        rgb_matrix_set_color(166, RGB_GREEN);
        rgb_matrix_set_color(165, RGB_GREEN);
        rgb_matrix_set_color(164, RGB_GREEN);
        rgb_matrix_set_color(163, RGB_GREEN);
        rgb_matrix_set_color(155, RGB_BLUE);
        rgb_matrix_set_color(156, RGB_BLUE);
        rgb_matrix_set_color(157, RGB_MAGENTA);
        rgb_matrix_set_color(158, RGB_MAGENTA);
    }
    return true;
}

#ifdef CAPS_WORD_ENABLE

void caps_word_set_user(bool active) {
    caps_word_state = active;
    if (is_keyboard_master()) {
        // dprintf("RPC_ID_USER_CAPS_WORD_SYNC: %s\n", active ? "active" : "inactive");
        transaction_rpc_send(RPC_ID_USER_CAPS_WORD_SYNC, 1, &active);
    }
}

void caps_word_sync(uint8_t initiator2target_buffer_size, const void *initiator2target_buffer, uint8_t target2initiator_buffer_size, void *target2initiator_buffer) {
    caps_word_state = *(bool *)initiator2target_buffer;
}

void keyboard_post_init_user() {
    transaction_register_rpc(RPC_ID_USER_CAPS_WORD_SYNC, caps_word_sync);
}

#endif
