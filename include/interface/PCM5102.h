
#ifndef _INTERFACE_PCM5102_H_
#define _INTERFACE_PCM5102_H_

#include <stdint.h>

void PCM5102_init(uint8_t bit_resolution, bool is_mono);
void PCM5102_update_freq(uint32_t freq);

#endif // _INTERFACE_PCM5102_H_