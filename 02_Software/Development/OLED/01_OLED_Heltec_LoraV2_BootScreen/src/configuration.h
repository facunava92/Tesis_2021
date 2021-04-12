#pragma once

// -----------------------------------------------------------------------------
// Version
// -----------------------------------------------------------------------------
#define APP_VERSION 0.1

// -----------------------------------------------------------------------------
// Configuration
// -----------------------------------------------------------------------------

/// Convert a preprocessor name into a quoted string
#define xstr(s) str(s)
#define str(s) #s

// This string must exactly match the case used in release file names or the android updater won't work
#define HW_VENDOR HardwareModel_HELTEC

// the default ESP32 Pin of 15 is the Oled SCL, set to 36 and 37 and works fine.
// Tested on Neo6m module.
#define GPS_RX_PIN 36
#define GPS_TX_PIN 37

#define I2C_SDA 4 // I2C pins for this board
#define I2C_SCL 15

#define RESET_OLED 16 // If defined, this pin will be used to reset the display controller

#define VEXT_ENABLE 21 // active low, powers the oled display and the lora antenna boost
#define LED_PIN 25     // If defined we will blink this LED
#define BUTTON_PIN 0   // If defined, this will be used for user button presses

#define USE_RF95
#define LORA_DIO0 26 // a No connect on the SX1262 module
#ifndef USE_JTAG
#define LORA_RESET 14
#endif
#define LORA_DIO1 35 // Not really used
#define LORA_DIO2 34 // Not really used

// -----------------------------------------------------------------------------
// OLED
// -----------------------------------------------------------------------------

#define SSD1306_ADDRESS 0x3C


// Flip the screen upside down by default as it makes more sense 
// Comment this out to not rotate screen 180 degrees.
#define SCREEN_FLIP_VERTICALLY

// Define if screen should be mirrored left to right
// #define SCREEN_MIRROR