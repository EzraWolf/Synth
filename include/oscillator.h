

#ifndef _OSCILLATOR_H_
#define _OSCILLATOR_H_

// Imports
#include <stdint.h>


float osc_fx_glide_value = 0.0f; // (portamento)
float osc_fx_detune_freq = 0.0f;
float osc_fx_reverb_ms   = 0.0f;
float osc_fx_chorus_ms   = 0.0f;
float osc_fx_delay_ms    = 0.0f;

float osc_fm_value       = 0.0f;
float osc_adsr_atk_value = 0.0f;
float osc_adsr_dec_value = 0.0f;
float osc_adsr_sus_value = 0.0f;
float osc_adsr_rel_value = 0.0f;

// Heute wir leiden
void osc_adsr(uint16_t atk, uint16_t dec, uint16_t sus, uint16_t rel);

void osc_hpf(uint16_t freq, uint16_t res, uint16_t mix);
void osc_lpf(uint16_t freq, uint16_t res, uint16_t mix);
void osc_bpf(uint16_t freq, uint16_t res, uint16_t mix);


#endif // _OSCILLATOR_H_
