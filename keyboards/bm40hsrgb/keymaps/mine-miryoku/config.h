#pragma once

#define TAPPING_TOGGLE 2
#define TAPPING_TERM 200  // default 200

// Prevent normal rollover on alphas from accidentally triggering mods.
#define IGNORE_MOD_TAP_INTERRUPT
#define PERMISSIVE_HOLD

// Enable rapid switch from tap to hold, disabled double tap hold and auto-repeat
/* #define TAPPING_FORCE_HOLD */

// Auto Shift
#define NO_AUTO_SHIFT_ALPHA
#define AUTO_SHIFT_TIMEOUT TAPPING_TERM
#define AUTO_SHIFT_NO_SETUP

// RGB
#define RGBLIGHT_LAYERS
#define RGBLIGHT_LAYERS_OVERRIDE_RGB_OFF
#define RGBLIGHT_ANIMATIONS

// Mouse key speed and acceleration.
/*
 * #undef MOUSEKEY_DELAY
 * #define MOUSEKEY_DELAY          0
 * #undef MOUSEKEY_INTERVAL
 * #define MOUSEKEY_INTERVAL       16
 * #undef MOUSEKEY_WHEEL_DELAY
 * #define MOUSEKEY_WHEEL_DELAY    0
 * #undef MOUSEKEY_MAX_SPEED
 * #define MOUSEKEY_MAX_SPEED      6
 * #undef MOUSEKEY_TIME_TO_MAX
 * #define MOUSEKEY_TIME_TO_MAX    64
*/

#ifdef RGB_MATRIX_ENABLE
// disable unnecessary animations
#define DISABLE_RGB_MATRIX_ALPHAS_MODS

#endif
