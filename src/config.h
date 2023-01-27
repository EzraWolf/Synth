
#ifndef _CONFIG_H_
#define _CONFIG_H_

// Settings
#define SAMPLING_RATE 40000 // 40kHz, 25 microseconds

// SPI-0 PINS
#define SPI_0_PIN_TX 0 // Transmit
#define SPI_0_PIN_RX 0 // Receive
#define SPI_0_PIN_CK 0 // Clock
#define SPI_0_PIN_CS 0 // Chip-Select

// SPI-1 PINS
#define SPI_1_PIN_TX 0 // Transmit
#define SPI_1_PIN_RX 0 // Receive
#define SPI_1_PIN_CK 0 // Clock
#define SPI_1_PIN_CS 0 // Chip-Select

// I2C-0 PINS
#define I2C_0_SDA 0    // Data
#define I2C_0_SCL 0    // Clock

// I2C-1 PINS
// NADA

// I2S-0 PINS
#define I2S_0_DIN 0    // Data-IN
#define I2S_0_BCK 0    // ?
#define I2S_0_LCK 0    // Left-Right-Clock

// I2S-1 PINS
// NADA

/*
// PCA9555 PINS
#define PCA9555_INP 0
#define PCA9555_OUT 2
#define PCA9555_INV 4
#define PCA9555_CFG 6
*/

#endif // _CONFIG_H_
