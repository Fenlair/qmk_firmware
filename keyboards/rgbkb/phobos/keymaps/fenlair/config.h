#pragma once

// FROM DEFAULT CONFIG
#undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_WIDE
#undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_CROSS
#undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_NEXUS
#undef ENABLE_RGB_MATRIX_SPLASH
#undef ENABLE_RGB_MATRIX_SOLID_SPLASH

#define RGB_MATRIX_SLEEP

#define STM32_ONBOARD_EEPROM_SIZE 2048

// CUSTOM
// Reduces firmware size, if QK_AREP isn't used
#define NO_ALT_REPEAT_KEY
#undef AUDIO_CLICKY // uses quite a bit of memory

#define CAPS_WORD_INVERT_ON_SHIFT

// Tap-hold configuration for home row mods.
#define PERMISSIVE_HOLD
#define CHORDAL_HOLD
#define TAPPING_TERM 180 // Time (in ms) until a tap is interpreted as a hold (default 200)
#define TAPPING_TERM_PER_KEY
#define QUICK_TAP_TERM 100 // auto-repeat
#define QUICK_TAP_TERM_PER_KEY

#define ONESHOT_TAP_TOGGLE 3 // Tapping this number of times holds the key until tapped once again.
#define ONESHOT_TIMEOUT \
    5000 // Time (in ms) before the one shot key is released
         //
#define SPLIT_TRANSACTION_IDS_USER RPC_ID_USER_CAPS_WORD_SYNC
