// Dactyl Manuform Hotswap
#pragma once

// Basic Config

// Using Serial instead of I2C
#define SERIAL_USART_FULL_DUPLEX
#define SERIAL_USART_TX_PIN GP0
#define SERIAL_USART_RX_PIN GP1
#define SERIAL_PIO_USE_PIO0
#define SERIAL_USART_TIMEOUT     100  // USART driver timeout. default 100
#define SERIAL_USART_SPEED 921600
#define SERIAL_USART_PIN_SWAP

#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_TIMEOUT 200U
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_LED_MASK 0U

/* key matrix size */
// Columns are doubled-up
#define MATRIX_ROWS 8
#define MATRIX_COLS 6

#define MATRIX_COL_PINS { GP8, GP7, GP6, GP5, GP4, GP3 }
#define MATRIX_ROW_PINS { GP9, GP10, GP11, GP13 }

#define POINTING_DEVICE_AUTO_MOUSE_ENABLE
#define POINTING_DEVICE_INVERT_Y
#define POINTING_DEVICE_RIGHT
#define POINTING_DEVICE_TASK_THROTTLE_MS 1

#define PMW33XX_CS_PIN GP21
#define PMW33XX_LIFTOFF_DISTANCE 0x02
#define ROTATIONAL_TRANSFORM_ANGLE  -25

// only required if not setting mouse layer elsewhere
#define AUTO_MOUSE_DEFAULT_LAYER 3


// Split settings
#define USE_SERIAL
#define SPLIT_LAYER_STATE_ENABLE
#define SPLIT_POINTING_ENABLE
#define SPLIT_TRANSACTION_IDS_KB RPC_ID_KB_CONFIG_SYNC
// end of split settings

// Misc settings
// Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap
#define LOCKING_SUPPORT_ENABLE
// Locking resynchronize hack
#define LOCKING_RESYNC_ENABLE// Enables This makes it easier for fast typists to use dual-function keys
#define PERMISSIVE_HOLD
// End of Basic Config


//// Sensor Notes ////
//// Pi Pico pins ////
// 3V3  -- Power (not 3v3_EN)
// GP17 -- CS pin
// GP20 -- MISO pin
// GP19 -- MOSI pin
// GP18 -- SCK pin clock Driver

#ifdef RGB_MATRIX_ENABLE
#define RGB_MATRIX_LED_COUNT 42
#define RGB_MATRIX_FRAMEBUFFER_EFFECTS
#define RGB_MATRIX_KEYPRESSES
#endif

#ifdef RGBLIGHT_ENABLE
#define RGBLED_NUM 42
#define RGBLIGHT_EFFECT_ALTERNATING
#define RGBLIGHT_EFFECT_BREATHING
#define RGBLIGHT_EFFECT_RAINBOW_MOOD
#define RGBLIGHT_EFFECT_RAINBOW_SWIRL
#define RGBLIGHT_EFFECT_SNAKE
#define RGBLIGHT_EFFECT_STATIC_GRADIENT
#define RGBLIGHT_EFFECT_TWINKLE
#endif
