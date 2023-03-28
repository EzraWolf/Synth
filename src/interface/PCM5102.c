
#include <stdio.h>
#include <stdint.h>
#include "hardware/pio.h"
#include "hardware/dma.h"
#include "hardware/irq.h"
#include "hardware/sync.h"
#include "pico/util/buffer.h"

// Local
#include "config.h"
#include "pio/PCM5102.pio.h" // The "compiled" PCM5102.pio file

/**
 * @name PCM5102_init
 * @date 05-Mar-23
 * 
 * @brief Initializes the PCM5102 audio DAC. The default bit resolution is 32 bits.
 * If `is_mono` is set to false, then the Pico sends out 64b total, 32b each for
 * the left and right channels.
 * 
 * @param bool is_mono
 * @return void
 */
void PCM5102_init(uint8_t audio_channel_ct) {

}

/**
 * @name PCM5102_update_freq
 * @date 05-Mar-23
 * 
 * @brief Updates the output frequency, and holds the last set frequency if not updated.
 * If the device is setup as mono, then `freq_r` isn't read and can be set to anything,
 * but it's recommended to set it to 0 regardless
 * 
 * 
 * @param uint32_t freq
 * @return void
 */
void PCM5102_update_freq(uint32_t freq_l, uint32_t freq_r) {

}

/**
 * @name PCM5102_update_vol
 * @date 05-Mar-23
 * 
 * @brief Updates the volume of the PCA5102. Holds the last set volume if not udpated
 * 
 * @param uint8_t vol
 * @return void
 */
void PCM5102_update_vol(uint8_t vol) {

}
