
// Allow push buttons to be used as keys through the PCA9555
// i2c IO expander IC
#ifndef _KEYS_H_
#define _KEYS_H_

#include <stdint.h>
#include <stdbool.h>

// The PCA9555's pin names
enum {
    PCA9555_00,
    PCA9555_01,
    PCA9555_02,
    PCA9555_03,
    PCA9555_04,
    PCA9555_05,
    PCA9555_06,
    PCA9555_07,
    PCA9555_08,
    PCA9555_09,
    PCA9555_10,
    PCA9555_11,
    PCA9555_12,
    PCA9555_13,
    PCA9555_14,
    PCA9555_15,
};

// The last value a pin when read
// array[0] is pin 0, array[1] is pin 1, etc
//  Inputs are set to -1 and are not updated
uint8_t PCA9555_pin_states[16] = {
    -1, -1, -1, -1,
    -1, -1, -1, -1,
    -1, -1, -1, -1,
    -1, -1, -1, -1
};

// These functions interface with the PCA9555 16-pin IO expander
// Pins 00-09 are used for tactile switch "keyboard" inputs
// Pins 10-15 are undecided right now as of 12-Jan-23
bool PCA9555_begin     (uint8_t  address           );
void PCA9555_set_clock (uint32_t freq              );
void PCA9555_pin_mode  (uint8_t  pin, bool is_input);
void PCA9555_write     (uint8_t  pin, uint8_t value);
void PCA9555_write_all (uint8_t  value[16]         );
void PCA9555_read      (uint8_t  pin               ); // Updates PCA9555_pin_states
void PCA9555_read_all  (                           ); // Updates PCA9555_pin_states

// Higher-level note and keyboard functions
// ?

#endif // _KEYS_H_
