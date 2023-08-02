#pragma once

#undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_WIDE
#undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_CROSS
#undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_NEXUS
#undef ENABLE_RGB_MATRIX_SPLASH
#undef ENABLE_RGB_MATRIX_SOLID_SPLASH

#define RGB_DISABLE_WHEN_USB_SUSPENDED

#define STM32_ONBOARD_EEPROM_SIZE 2048

#undefine AUDIO_CLICKY  // uses quite a bit of memory

// Reduces firmware size, if QK_AREP isn't used
#define NO_ALT_REPEAT_KEY

#define BOTH_SHIFTS_TURNS_ON_CAPS_WORD
#define CAPS_WORD_INVERT_ON_SHIFT

// Tap-hold configuration for home row mods.
#define TAPPING_TERM 180            // Time (in ms) until a tap is interpreted as a hold (default 200)
#define TAPPING_TERM_PER_KEY
#define PERMISSIVE_HOLD
#define QUICK_TAP_TERM 100          // auto-repeat
#define QUICK_TAP_TERM_PER_KEY

#define ONESHOT_TAP_TOGGLE 3        // Tapping this number of times holds the key until tapped once again.
#define ONESHOT_TIMEOUT 5000        // Time (in ms) before the one shot key is released
