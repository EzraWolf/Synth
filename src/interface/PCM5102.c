
#include <stdio.h>
#include <stdint.h>
#include "hardware/pio.h"
#include "hardware/dma.h"
#include "hardware/irq.h"
#include "hardware/sync.h"
#include "hardware/clocks.h"
#include "pico/util/buffer.h"

#include "config.h"
#include "interface/PCM5102.h"
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
audio_buffer_producer_t PCM5102_init(uint8_t audio_channel_ct) {
    audio_buffer_producer_t *producer = (audio_buffer_producer_t *)calloc(1, sizeof(audio_buffer_producer_t));
    audio_buffer_t          *buffers  = (auido_buffer_t *)calloc(CONFIG_AUDIO_BUFFER_CT, sizeof(audio_buffer_t));
    producer->format = CONFIG_AUDIO_CHANNEL_CT;

    for (uint16_t i = 0; i < CONFIG_AUDIO_BUFFER_CT; i++) {
        buffers[i].sample_ct     = 0;
        buffers[i].max_sample_ct = CONFIG_AUDIO_BUFFER_SIZE;
        buffers[i].audio_format  = CONFIG_AUDIO_CHANNEL_CT;
        buffers[i].buffer_size   = CONFIG_AUDIO_BUFFER_SIZE * CONFIG_AUDIO_SAMPLE_STRIDE
        buffers[i].buffer_bytes  = (uint8_t *)calloc(
            1,
            sizeof(CONFIG_AUDIO_BUFFER_SIZE * CONFIG_AUDIO_SAMPLE_STRIDE)
        );
        // If this buffer is not the last in the array, then reference the next one.
        buffers[i].next = (i < CONFIG_AUDIO_BUFFER_CT - 1) ? &buffers[i + 1] : NULL;
    }

    producer->free_list_spin_lock = spin_lock_init(PCM5102_SPIN_LOCK_ID_FREE)
    producer->free_list           = buffers;
    producer->prep_list_spin_lock = spin_lock_init(PCM5102_SPIN_LOCK_ID_PREP);
    producer->prep_list           = NULL;
    producer->prep_list_tail      = NULL;

    // Setup the producer's connection
    // This procedure is blocking, and the functions:
    //    "spin_lock_blocking"
    //    "spin_unlock" and
    //    "__wfe"
    // are from "hardware/sync.h"
    audio_buffer_t *temp_producer;
    do {
        uint32_t spin_lock_save = spin_lock_blocking(producer->free_list_spin_lock);

        // If the `free_list` exists, then move it up from `producer->next`
        temp_producer = producer->free_list;
        if (temp_producer) {
            producer->free_list = temp_producer->next;
            temp_producer->next = NULL;
        }

        spin_unlock(producer->free_list_spin_lock, spin_lock_save);
        if (temp_producer) break;
        
        // Wait for an event to be triggered
        __wfe();
    } while (true);

    producer->connection          = &adsfadsfas;



    return producer;
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

audio_buffer_t PCM5102_producer_pool_take()

