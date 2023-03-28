
#ifndef _CONFIG_H_
#define _CONFIG_H_

#include "hardware/i2c.h"
#include "hardware/spi.h"


// -=========================-
//          SETTINGS         
// -=========================-
#define CONFIG_PCM5102_USE_DMA true
#define CONFIG_DISPLAY_USE_DMA false

// Audio
#define CONFIG_AUDIO_SAMPLE_RATE   48 * 1000 // 48kHz, 20.8333... microseconds
#define CONFIG_AUDIO_SAMPLE_STRIDE 8         // 8 bytes per sample
#define CONFIG_AUDIO_CHANNELS      1         // Mono
#define CONFIG_AUDIO_BITS          32        // 32bit audio
#define CONFIG_AUDIO_DMA_CHANNEL   0         // DMA channel 0

#define CONFIG_AUDIO_MONO          1
#define CONFIG_AUDIO_STEREO        2

// Devices
#define CONFIG_PCA9555_PORT I2C_0


// -=========================-
//            SPI_0           
// -=========================-

// Devices connected to SPI_0:
//  - Nada

// **NOTE** These are the GPIO numbers
// #define SPI_0_PIN_CK 0 // Clock
// #define SPI_0_PIN_TX 0 // Transmit
// #define SPI_0_PIN_RX 0 // Receive


// -=========================-
//            SPI_1           
// -=========================-

// Devices connected to SPI_0:
//  - ST7789V2 170x320 display
//    (Only on SPI_1 because its closest to the TFT on the breadboard)

// **NOTE** These are the GPIO numbers
#define CONFIG_SPI_1_PIN_CK 10 // Clock
#define CONFIG_SPI_1_PIN_TX 11 // Transmit
#define CONFIG_SPI_1_PIN_RX 12 // Receive

#define CONFIG_ST7789V2_CS  13 // ST7789 Chip-select
#define CONFIG_ST7789V2_DC  14 // ST7789 Data command
#define CONFIG_ST7789V2_RS  15 // ST7789 Reset


// -=========================-
//            I2C_0           
// -=========================-
#define CONFIG_I2C_0 i2c0 // Port

// Devices connected to I2C_0:
//  - PCA9555 16b IO expander

// **NOTE** These are the GPIO numbers
#define CONFIG_I2C_0_SDA 20   // Data
#define CONFIG_I2C_0_SCL 21   // Clock


// -=========================-
//            I2C_1           
// -=========================-
#define CONFIG_I2C_1 i2c1 // Port

// Devices connected to I2C_1:
//  - Nada

// **NOTE** These are the GPIO numbers
// #define I2C_1_SDA 0    // Data
// #define I2C_1_SCL 0    // Clock


// -=========================-
//            I2S_0           
// -=========================-

// Devices connected to I2S_0:
//  - PCM5102 Audio DAC (Accepts up to 32bit audio data)

// **NOTE** These are the GPIO numbers
#define CONFIG_I2S_0_DIN 18 // Audio data input
#define CONFIG_I2S_0_BCK 16 // Audio data bit  clock
#define CONFIG_I2S_0_LCK 17 // Left-right word clock

#endif // _CONFIG_H_
