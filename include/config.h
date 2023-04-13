
#ifndef _CONFIG_H_
#define _CONFIG_H_

#include "hardware/i2c.h"
#include "hardware/spi.h"


// -=========================-
//          SETTINGS         
// -=========================-

// Audio
#define CONFIG_AUDIO_SAMPLE_RATE   48 * 1000 // 48kHz, 20.8333... microseconds
#define CONFIG_AUDIO_SAMPLE_STRIDE 8         // 8 bytes per sample
#define CONFIG_AUDIO_CHANNEL_CT    1         // Mono
#define CONFIG_AUDIO_BITS          32        // 32bit audio
#define CONFIG_AUDIO_DMA_CHANNEL   0         // DMA channel 0
#define CONFIG_AUDIO_BUFFER_CT     3         // 3 Buffers
#define CONFIG_AUDIO_BUFFER_SIZE   256       // 256 Samples per buffer

#define CONFIG_AUDIO_MONO          1
#define CONFIG_AUDIO_STEREO        2

// On-Board LED
#define CONFIG_LED_PIN 25

// PCA9555
#define CONFIG_PCA9555_PORT I2C_0

// PCM5102
#define CONFIG_PCM5102_USE_DMA      true
#define CONFIG_PCM5102_DMA_CHANNEL  0x00
#define CONFIG_PCM5102_PIO          pio0 // Instance
#define CONFIG_PCM5102_PIO_SM       0x00 // State machine
#define CONFIG_PCM5102_BIT_STEAL_CT 0x02 // DO NOT CHANGE
#define CONFIG_PCM5102_BIT_PULL_CT  0x20 // DO NOT CHANGE
#define CONFIG_PCM5102_CS_GPIO      ?? // GPIO ST7789 Chip-select
#define CONFIG_PCM5102_DIN_GPIO     18 // GPIO Audio data input
#define CONFIG_PCM5102_BCK_GPIO     16 // GPIO Audio data bit  clock
#define CONFIG_PCM5102_LCK_GPIO     17 // GPIO Left-right word clock

// ST7789V2
#define CONFIG_ST7789V2_USE_DMA true
#define CONFIG_ST7789V2_DMA_CHANNEL 0x01
#define CONFIG_ST7789V2_PIO         pio1 // Instance
#define CONFIG_ST7789V2_PIO_SM      0x01 // State machine
#define CONFIG_ST7789V2_CS_GPIO     13   // GPIO ST7789 Chip-select
#define CONFIG_ST7789V2_DC_GPIO     14   // GPIO ST7789 Data command
#define CONFIG_ST7789V2_RS_GPIO     15   // GPIO ST7789 Reset


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


// -=========================-
//            I2C_0           
// -=========================-
#define I2C_0 i2c0 // Better name

// Devices connected to I2C_0:
//  - PCA9555 16b IO expander

// **NOTE** These are the GPIO numbers
#define CONFIG_I2C_0_SDA 20   // Data
#define CONFIG_I2C_0_SCL 21   // Clock


// -=========================-
//            I2C_1           
// -=========================-
#define I2C_1 i2c1 // Better name

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

#endif // _CONFIG_H_
