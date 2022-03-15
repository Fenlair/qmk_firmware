/*
 * ----------------------------------------------------------------------------
 * "THE BEER-WARE LICENSE" (Revision 42):
 * <https://github.com/Fenlair> wrote this file.  As long as you retain this
 * notice you can do whatever you want with this stuff. If we meet some day, and
 * you think this stuff is worth it, you can buy me a beer in return. Pascal Hertrich
 * ----------------------------------------------------------------------------
 */

#pragma once

//
// TAPPING
//
#define TAPPING_TERM 250          // Time (in ms) until a tap is interpreted as a hold (default 200)
#define IGNORE_MOD_TAP_INTERRUPT  // disable custom behavior for Mod Tap keys (by default hold is strongly prefered)
#define PERMISSIVE_HOLD_PER_KEY   // Enables function rgb_matrix_indicators_user (in keymap.c)
#define ONESHOT_TAP_TOGGLE 5      // Tapping this number of times holds the key until tapped once again.
#define ONESHOT_TIMEOUT 5000      // Time (in ms) before the one shot key is released


//
// RGB
//

// No need for the single versions when multi performance isn't a problem =D
#undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_WIDE
#undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_CROSS
#undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_NEXUS
#undef ENABLE_RGB_MATRIX_SPLASH
#undef ENABLE_RGB_MATRIX_SOLID_SPLASH

// test if it makes a difference in memory footprint
/*
#undef RGBLIGHT_EFFECT_BREATHING
#undef RGBLIGHT_EFFECT_RAINBOW_MOOD
#undef RGBLIGHT_EFFECT_RAINBOW_SWIRL
#undef RGBLIGHT_EFFECT_SNAKE
#undef RGBLIGHT_EFFECT_KNIGHT
#undef RGBLIGHT_EFFECT_CHRISTMAS
#undef RGBLIGHT_EFFECT_STATIC_GRADIENT
#undef RGBLIGHT_EFFECT_RGB_TEST
#undef RGBLIGHT_EFFECT_ALTERNATING
#undef RGBLIGHT_EFFECT_TWINKLE
*/

// 20m timeout (20m * 60s * 1000mil)
// #define RGB_DISABLE_TIMEOUT 1200000
#define RGB_DISABLE_WHEN_USB_SUSPENDED


//
// VIA
//
#define VIA_EEPROM_LAYOUT_OPTIONS_SIZE 2
// 224B per layer right now
#define DYNAMIC_KEYMAP_LAYER_COUNT 8
#define DYNAMIC_KEYMAP_EEPROM_MAX_ADDR 2047

#define VIA_QMK_RGBLIGHT_ENABLE

#define STM32_ONBOARD_EEPROM_SIZE 2048

