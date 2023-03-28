
#ifndef _INTERFACE_PCA9555_H_
#define _INTERFACE_PCA9555_H_

#include <stdint.h>


// The base address for the
// PCA955 with all of the address
// selectors pulled to ground
#define PCA9555_BASE_ADDR 0x20

// The registers used inside of
// the PCA9555 and their addresses
#define PCA9555_PORT0_INPUT    0x0
#define PCA9555_PORT1_INPUT    0x1
#define PCA9555_PORT0_OUTPUT   0x2
#define PCA9555_PORT1_OUTPUT   0x3
#define PCA9555_PORT0_POLARITY 0x4
#define PCA9555_PORT1_POLARITY 0x5
#define PCA9555_PORT0_CONFIG   0x6
#define PCA9555_PORT1_CONFIG   0x7

// This stores the current "state" of the pins (pun intended)
// Meant to be read as binary, not as an integer or hexadecimal
// 0 = Output
// 1 = Input
// uint16_t PCA9555_pin_states = 0b0000000000000000;

// ^ **NOTE** ^
// To only read input values, do
// `uint16_t PCA9555_input_values = PCA9555_pin_values & PCA9555_pin_states`
//
// To only read output values (values that we've sent to LEDs or similar), do
// `uint16_t PCA9555_output_values = PCA9555_pin_values & (~PCA9555_pin_states)`
// v **NOTE** v

// This stores the current value of the pins
// Meant to be read as binary, not as an integer or hexadecimal
// Outputs = The last value sent out
// Inputs  = The last value read in
// uint16_t PCA9555_pin_values = 0b0000000000000000;

// These functions interface with the PCA9555 16-pin IO expander
// As of 28-Feb-23, 11:48
// Pins PORT0_0 to PORT0_2 drive CD4051_0, it cycles through and reads 8 input potentiometers
// Pins PORT0_3 to PORT0_5 drive CD4051_1, it cycles through and reads 8 input potentiometers
// Pins PORT0_6 to PORT1_0 drive CD4051_2, it cycles through and reads 8 input buttons
void     PCA9555_init           (uint16_t pin_states, bool retain_bus);
void     PCA9555_set_polarity   (uint16_t pin_states, bool retain_bus);
void     PCA9555_write          (uint8_t reg, uint8_t val, uint8_t val_bytes, bool retain_bus);
void     PCA9555_write_all_pins (uint16_t pin_values, bool retain_bus);
uint8_t  PCA9555_read           (uint8_t  reg, bool retain_bus);
uint16_t PCA9555_read_all_pins  (bool retain_bus);

#endif // _INTERFACE_PCA9555_H_
