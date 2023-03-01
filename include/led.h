
#ifndef _LED_H_
#define _LED_H_

#include <stdint.h>

void FlashPin(uint8_t pin);
void Flash(uint8_t pin, uint16_t duration_ms);

#endif // _LED_H_
