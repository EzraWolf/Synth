
// TODO: Clean up the code that runs this in `main.c` and remove this file.

#include "pico/stdlib.h"
#include "led.h"

void FlashPin(uint8_t pin) {
    gpio_init(pin);
    gpio_set_dir(pin, GPIO_OUT);
}

void Flash(uint8_t pin, uint16_t duration_ms) {
    while (true) {
        gpio_put(pin, 1);
        sleep_ms(duration_ms);
        gpio_put(pin, 0);
        sleep_ms(duration_ms);
    }
}
