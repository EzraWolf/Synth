
#ifndef _INTERFACE_ST7789V2_H_
#define _INTERFACE_ST7789V2_H_

#include <stdint.h>

// Do NOT change these
#define ST7789V2_W 170
#define ST7789V2_H 320
#define ST7789V2_W_MIDDLE 85
#define ST7789V2_H_MIDDLE 160

#define ST7789V2_PIO_STATE_MACHINE 0x01

// Also do NOT change these
// These are control register values
// TODO

// Command list
// TODO

// Setup and control functions
void ST7789V2_init(uint16_t background_color);
void ST7789V2_clear();
void ST7789V2_set_backlight(uint8_t brightness);
void ST7789V2_send_command(uint8_t command);

#endif // _INTERFACE_ST7789V2_H_
