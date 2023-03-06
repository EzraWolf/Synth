
#ifndef _INTERFACE_PCM5102_H_
#define _INTERFACE_PCM5102_H_

#include <stdint.h>

void PCM5102_init(bool is_mono); // Is 32b audio resolution by default
void PCM5102_update_freq(uint32_t freq_l, uint32_t freq_r);
void PCM5102_update_vol(uint8_t vol);

#endif // _INTERFACE_PCM5102_H_
