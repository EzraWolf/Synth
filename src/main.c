
#include <stdio.h>

#include "pico/stdlib.h"
#include "hardware/i2c.h"
#include "hardware/pio.h"

#include "main.h"
#include "config.h"
#include "interface/PCA9555.h"
#include "interface/PCM5102.h"
#include "interface/ST7789V2.h"

// Initialize the first core of the RP2040
// This core is responsible for setting up
// the audio DAC and creating the audio.
void init_core_0() {
    stdio_init_all();
    
    // Pin setup
    gpio_init(0);
    gpio_set_dir(0, GPIO_IN);
    gpio_pull_up(0);

    // On-board LED output
    gpio_init(25);
    gpio_set_dir(25, GPIO_OUT);

    // I2C_0 Setup        
    i2c_init(I2C_0, 400 * 1000); // 400kH
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

    // PIO Setup
    pio_sm_claim(PCM5102_PIO,  PCM5102_PIO_STATE_MACHINE );
    pio_sm_claim(ST7789V2_PIO, ST7789V2_PIO_STATE_MACHINE);

    // Device setups
    PCA9555_init(0x0000, false);
}

int main() {

    set_sys_clock_khz(132 * 1000, true); // 132 MHz helps evenly divide the audio freqs
    init_core_0();

    uint16_t pin_vals = 0;


    // If the button on PORT0 pin 0 is 1, set the LED to on
    // If the button on PORT0 pin 7 is 1, clear the LED
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
