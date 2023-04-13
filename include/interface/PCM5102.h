
#ifndef _INTERFACE_PCM5102_H_
#define _INTERFACE_PCM5102_H_

#include <stdint.h>
#include "hardware/sync.h"

// DO NOT CHANGE
#define PCM5102_SPIN_LOCK_ID_FREE 0x06
#define PCM5102_SPIN_LOCK_ID_PREP 0x07


// Used for
// ???
typedef struct audio_buffer {
    uint8_t *buffer_bytes;
    uint16_t buffer_size;

    uint16_t audio_format;
    uint16_t sample_stride;

    uint32_t sample_ct;
    uint32_t max_sample_ct;

    struct audio_buffer *next; // Disgusting use of inheritance but it works...
} audio_buffer_t;


// Used for
// ???
typedef struct audio_buffer_producer {
    const uint16_t      audio_format;
    audio_connection_t *connection;

    // Used only for spinlock functions
    // in "hardware/sync.h" in the PICO-SDK
    spin_lock_t    *free_list_spin_lock;
    audio_buffer_t *free_list;

    spin_lock_t    *prep_list_spin_lock;
    audio_buffer_t *prep_list;
    audio_buffer_t *prep_list_tail;
} audio_buffer_producer_t;


// Used for
// ???
typedef struct audio_buffer_consumer {
    const uint16_t      audio_format;
    audio_connection_t *connection;

    // Used only for spinlock functions
    // in "hardware/sync.h" in the PICO-SDK
    spin_lock_t    *free_list_spin_lock;
    audio_buffer_t *free_list;

    spin_lock_t    *prep_list_spin_lock;
    audio_buffer_t *prep_list;
    audio_buffer_t *prep_list_tail;
} audio_buffer_consumer_t;


void PCM5102_init(uint8_t audio_channel_ct); // Is 32b audio resolution by default
void PCM5102_update_freq(uint32_t freq_l, uint32_t freq_r);
void PCM5102_update_vol(uint8_t vol);

#endif // _INTERFACE_PCM5102_H_
