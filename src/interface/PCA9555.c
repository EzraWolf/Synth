
#include "pico/stdlib.h"
#include "hardware/i2c.h"

// Local
#include "config.h"
#include "interface/PCA9555.h"

/**
 * @name PCA9555_init
 * @date 28-Feb-23
 * 
 * @brief Set the PCA9555's address and which pins are inputs and outputs
 * 
 * @param pin_states **TREAT THIS VALUE AS BINARY**
 * @return void
 */
void PCA9555_init(uint16_t pin_states, bool retain_bus) {

    // Slice `pin_states` into upper and lower 8 bits
    uint8_t pin_states_lo = (uint8_t)(pin_states &  0xFF); // 0b--------XXXXXXXX
    uint8_t pin_states_hi = (uint8_t)(pin_states >> 0x08); // 0bXXXXXXXX--------

    // Set PORT0_CONFIG and its pin config
    PCA9555_write(
        PCA9555_PORT0_CONFIG,
        (uint8_t)(pin_states & 0xFF),
        1,
        true
    );

    // Set PORT1_CONFIG and its pin config
    PCA9555_write(
        PCA9555_PORT1_CONFIG,
        (uint8_t)(pin_states >> 0x08),
        1,
        true
    );
}

/**
 * @name PCA9555_polarity
 * @date 01-Mar-23
 * 
 * @brief I have literally no idea what this is supposed to do
 * 
 * @param pin_states 
 * @param retain_bus
 * @return void 
 */
void PCA9555_polarity(uint16_t pin_states, bool retain_bus) {
    PCA9555_write(
        PCA9555_PORT0_POLARITY,
        (uint8_t)(pin_states & 0xFF),
        1,
        true
    );

    PCA9555_write(
        PCA9555_PORT1_POLARITY,
        (uint8_t)(pin_states >> 0x08),
        1,
        retain_bus
    );
}

/**
 * @name PCA9555_write
 * @date 28-Feb-23
 * 
 * @brief Write to a specific register a value
 * 
 * @param reg
 * @param val
 * @param val_bytes
 * @param retain_bus If true, it means you are still continuously writing to the PCA9555.
 *  You must return false if you are performing another task before writing to it again.
 * @return void
 */
void PCA9555_write(uint8_t reg, uint8_t val, uint8_t val_bytes, bool retain_bus) {
    i2c_write_blocking(
        PCA9555_PORT,
        PCA9555_BASE_ADDR,
        &reg,
        1,
        true
    );

    // Write which pins are inputs and outputs
    i2c_write_blocking(
        PCA9555_PORT,
        PCA9555_BASE_ADDR,
        &val,
        val_bytes,
        retain_bus
    );
}

/**
 * @name PCA9555_write_all_pins
 * @date 28-Feb-23
 * 
 * @brief Write to both PORT0_OUTPUT and PORT1_OUTPUT to set all pins
 * 
 * @param pin_values
 * @param retain_bus
 * @return void
 */
void PCA9555_write_all_pins(uint16_t pin_values, bool retain_bus) {
    PCA9555_write(PCA9555_PORT0_OUTPUT, (uint8_t)(pin_values &  0xFF), 1, true      );
    PCA9555_write(PCA9555_PORT1_OUTPUT, (uint8_t)(pin_values >> 0x08), 1, retain_bus);
}

/**
 * @name PCA9555_read
 * @date 28-Feb-23
 * 
 * @brief Read a specific register
 * 
 * @param reg
 * @param retain_bus If true, it means you are still continuously writing to the PCA9555.
 *  You must return false if you are performing another task before writing to it again.
 * @return uint8_t Returns the value read
 */
uint8_t PCA9555_read(uint8_t reg, bool retain_bus) {
    uint8_t register_contents = 0;

    i2c_write_blocking(
        PCA9555_PORT,
        PCA9555_BASE_ADDR,
        &reg,
        1,
        true
    );

    // Read the contents of the register
    i2c_read_blocking(
        PCA9555_PORT,
        PCA9555_BASE_ADDR,
        &register_contents,
        1,
        retain_bus
    );

    return register_contents;
}

/**
 * @name PCA9555_read_all_pins
 * @date 28-Feb-23
 * 
 * @brief Reads every pin on the PCA9555 all at once.
 *  Speficically, it returns PORT0_INPUT and PORT1_INPUT
 *  as a 16 bit unsigned int.
 *  PORT0 is --------XXXXXXXX
 *  PORT1 is XXXXXXXX--------
 * 
 * @param retain_bus If true, it means you are still continuously writing to the PCA9555.
 *  You must return false if you are performing another task before writing to it again.
 * @return uint16_t Returns the values read from PORT0_OUTPUT and PORT1_OUTPUT
 */
uint16_t PCA9555_read_all_pins(bool retain_bus) {
    uint16_t result;
    result  = PCA9555_read(PCA9555_PORT1_INPUT, true) << 8;
    result |= PCA9555_read(PCA9555_PORT0_INPUT, retain_bus);
    
    // Result is negated because the physical buttons
    // are tied to ground, so when they are "on" the
    // PCA9555 reads them as off. They are treated as
    // an active low signal which we don't want.
    return ~result;
}
