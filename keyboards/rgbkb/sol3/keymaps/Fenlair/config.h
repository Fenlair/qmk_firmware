#pragma once

#define TAPPING_TERM 250  // default 200
// disable custom behavior for Mod Tap keys (by default hold is strongly prefered)
#define IGNORE_MOD_TAP_INTERRUPT
// Allow for custom permissive hold logic in keymap.c file
#define PERMISSIVE_HOLD_PER_KEY

// No need for the single versions when multi performance isn't a problem =D
#undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_WIDE
#undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_CROSS
#undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_NEXUS
#undef ENABLE_RGB_MATRIX_SPLASH
#undef ENABLE_RGB_MATRIX_SOLID_SPLASH

// 20m timeout (20m * 60s * 1000mil)
// #define RGB_DISABLE_TIMEOUT 1200000
#define RGB_DISABLE_WHEN_USB_SUSPENDED


#define VIA_EEPROM_LAYOUT_OPTIONS_SIZE 2
// 224B per layer right now
#define DYNAMIC_KEYMAP_LAYER_COUNT 8
#define DYNAMIC_KEYMAP_EEPROM_MAX_ADDR 2047

#define VIA_QMK_RGBLIGHT_ENABLE

#define STM32_ONBOARD_EEPROM_SIZE 2048

