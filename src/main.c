
#include "pico/stdlib.h"
#include "led.h"

int main() {
    FlashPin(25);
    Flash(25, 50);
    return 0; // If it somehow reaches this should it really be return 1; ?
}
