
#include "pico/stdlib.h"
#include "hardware/i2c.h"
#include <stdio.h>
// Local
#include "main.h"
#include "config.h"
#include "interface/PCA9555.h"


void init_core_0() {
    stdio_init_all();
    
    // Pin setup

    gpio_init(0);
    gpio_set_dir(0, GPIO_IN);
    gpio_pull_up(0);

    // On-board LED output
    gpio_init(25);
    gpio_set_dir(25, GPIO_OUT);


    // -=========================-
    //         I2C_0 Setup        
    // -=========================-
    i2c_init(I2C_0, 400 * 1000); // 400kHz

    gpio_init(I2C_0_SDA);
    gpio_init(I2C_0_SCL);
    
    // GPIO_FUNC_I2C = 0x3
    gpio_set_function(I2C_0_SDA, GPIO_FUNC_I2C);
    gpio_set_function(I2C_0_SCL, GPIO_FUNC_I2C);
    gpio_pull_up(I2C_0_SDA);
    gpio_pull_up(I2C_0_SCL);

    /*
    // -=========================-
    //         I2C_1 Setup        
    // -=========================-
    i2c_init(I2C_1, 400 * 1000); // 400kHz

    // GPIO_FUNC_I2C = 0x3
    gpio_set_function(I2C_1_SDA, GPIO_FUNC_I2C);
    gpio_set_function(I2C_1_SCL, GPIO_FUNC_I2C);
    gpio_pull_up(I2C_1_SDA);
    gpio_pull_up(I2C_1_SCL);
     */

    // Device setups
    PCA9555_init(0x0000, false);
}

int main() {
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
