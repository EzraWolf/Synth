
#include <stdio.h>

#include "pico/stdlib.h"
#include "hardware/i2c.h"
#include "hardware/pio.h"
#include "hardware/dma.h"

#include "main.h"
#include "config.h"
#include "interface/PCA9555.h"
#include "interface/PCM5102.h"
#include "interface/ST7789V2.h"
#include "pio/PCM5102.pio.h"
#include "pio/ST7789V2.pio.h"


// Initialize the first core of the RP2040
// This core is responsible for setting up
// the audio DAC and creating the audio.
void init_core_0() {

    // Initialize this thing
    stdio_init_all();

    // On-board LED output
    gpio_init(CONFIG_LED_PIN);
    gpio_set_dir(CONFIG_LED_PIN, GPIO_OUT);

    // I2C_0 Setup        
    i2c_init(I2C_0, 400 * 1000); // 400KHz
    gpio_init(I2C_0_SDA);
    gpio_init(I2C_0_SCL);
    gpio_set_function(I2C_0_SDA, GPIO_FUNC_I2C);
    gpio_set_function(I2C_0_SCL, GPIO_FUNC_I2C);
    gpio_pull_up(I2C_0_SDA);
    gpio_pull_up(I2C_0_SCL);
    gpio_set_drive_strength(I2C_0_SDA, GPIO_DRIVE_STRENGTH_12MA);
    gpio_set_drive_strength(I2C_0_SCL, GPIO_DRIVE_STRENGTH_12MA);
    gpio_set_slew_rate(I2C_0_SDA, GPIO_SLEW_RATE_FAST);
    gpio_set_slew_rate(I2C_0_SCL, GPIO_SLEW_RATE_FAST);

    /*
    // I2C_1 Setup        
    i2c_init(I2C_1, 400 * 1000); // 400kHz
    gpio_set_function(I2C_1_SDA, GPIO_FUNC_I2C);
    gpio_set_function(I2C_1_SCL, GPIO_FUNC_I2C);
    gpio_pull_up(I2C_1_SDA);
    gpio_pull_up(I2C_1_SCL);
    gpio_set_drive_strength(I2C_1_SDA, GPIO_DRIVE_STRENGTH_12MA);
    gpio_set_drive_strength(I2C_1_SCL, GPIO_DRIVE_STRENGTH_12MA);
    gpio_set_slew_rate(I2C_1_SDA, GPIO_SLEW_RATE_FAST);
    gpio_set_slew_rate(I2C_1_SCL, GPIO_SLEW_RATE_FAST);
     */

    // -==============================-
    // -== PCA9555 Setup            ==-
    // -==============================-
    PCA9555_init(0x0000, false); // I love how easy this one is.

    // -==============================-
    // -== PCM5102 Setup            ==-
    // -==============================-
    pio_sm_claim(CONFIG_PCM5102_PIO, CONFIG_PCM5102_PIO_SM);

    // `PCM5102_i2s_pio_init` is the PIO program defined in PCM5102.pio
    // (fetched from PCM5102.pio.h)
    uint32_t PCM5102_pio_offset = pio_add_program(CONFIG_PCM5102_PIO, &PCM5102_i2s_pio_program);
    PCM5102_i2s_pio_init(
        CONFIG_PCM5102_PIO,
        CONFIG_PCM5102_PIO_SM,
        PCM5102_pio_offset,
        CONFIG_PCM5102_DIN_GPIO,
        CONFIG_PCM5102_LCK_GPIO
    );



    dma_channel_claim(CONFIG_PCM5102_DMA_CHANNEL);


    PCM5102_init(CONFIG_AUDIO_CHANNEL_CT);

    // ST7789V2 Setup
    pio_sm_claim(CONFIG_ST7789V2_PIO, CONFIG_ST7789V2_PIO_SM);
    dma_channel_claim(CONFIG_ST7789V2_DMA_CHANNEL);
}

int main() {

    // 132 MHz helps evenly divide the audio frequencies
    set_sys_clock_khz(132 * 1000, true);
    init_core_0();

    // If the button on PORT0 pin 0 is 1, set the LED to on
    // If the button on PORT0 pin 7 is 1, clear the LED
    uint16_t pin_vals = 0;
    while (true) {
        pin_vals = PCA9555_read_all_pins(false);
        if (pin_vals & 0b0000000000000001) {
            gpio_put(25, 1);

        } else if (pin_vals & 0b0000000010000000) {
            gpio_put(25, 0);
        }
    }

    // If it somehow reaches this should it really return 1?
    return 0;
}
