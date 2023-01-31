


#include "led.h"

#include "pico/stdlib.h"
#include "hardware/i2c.h"

void init_pins() {
    gpio_init(pin);
    gpio_set_dir(pin, GPIO_OUT);
}




int main() {
    FlashPin(25);
    Flash(25, 50);
    return 0; // If it somehow reaches this should it really be return 1.?
}
