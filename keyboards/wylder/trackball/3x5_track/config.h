// Dactyl Manuform Hotswap
#pragma once

// Basic Config

// TOP LEFT KEY ON LEFT SIDE
#define BOOTMAGIC_ROW    0
#define BOOTMAGIC_COLUMN 0

// TOP RIGHT KEY ON RIGHT SIDE
#define BOOTMAGIC_ROW_RIGHT    5
#define BOOTMAGIC_COLUMN_RIGHT 4

#define USE_SERIAL

// Using Serial instead of I2C
#define SERIAL_USART_FULL_DUPLEX
#define SERIAL_USART_TX_PIN GP0
#define SERIAL_USART_RX_PIN GP1
#define SERIAL_PIO_USE_PIO0
#define SERIAL_USART_TIMEOUT 100  // USART driver timeout. default 100
#define SERIAL_USART_SPEED   921600
#define SERIAL_USART_PIN_SWAP

#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_TIMEOUT  200U
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_LED_MASK 0U

/* key matrix size */
// Columns are doubled-up
#define MATRIX_ROWS 10
#define MATRIX_COLS 5

#define MATRIX_COL_PINS { GP2, GP3, GP4, GP5, GP6  }
#define MATRIX_ROW_PINS { GP9, GP10, GP11, GP12, GP13 }

#define POINTING_DEVICE_AUTO_MOUSE_ENABLE
#define POINTING_DEVICE_INVERT_Y
#define POINTING_DEVICE_RIGHT
#define POINTING_DEVICE_TASK_THROTTLE_MS 1

#define PMW33XX_CS_PIN GP21
#define PMW33XX_LIFTOFF_DISTANCE   0x02
#define ROTATIONAL_TRANSFORM_ANGLE -35

// only required if not setting mouse layer elsewhere
#define AUTO_MOUSE_DEFAULT_LAYER 3


// Split settings
/* #define USE_SERIAL */
/* #define SPLIT_LAYER_STATE_ENABLE */
#define SPLIT_POINTING_ENABLE
#define SPLIT_TRANSACTION_IDS_KB RPC_ID_KB_CONFIG_SYNC
// end of split settings

// Misc settings
// Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap
#define LOCKING_SUPPORT_ENABLE
// Locking resynchronize hack
#define LOCKING_RESYNC_ENABLE// Enables This makes it easier for fast typists to use dual-function keys
/* #define PERMISSIVE_HOLD */
// End of Basic Config


//// Sensor Notes ////
//// Pi Pico pins ////
// 3V3  -- Power (not 3v3_EN!)
// GP21 -- CS pin
// GP20 -- MISO pin
// GP19 -- MOSI pin
// GP18 -- SCK pin clock
// GND  -- GND
