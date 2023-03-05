
#ifndef _DISPLAY_FONT_H_
#define _DISPLAY_FONT_H_

void font_print_char(uint16_t x_pos, uint16_t y_pos, char character, uint16_t color);
void font_print_string(uint16_t x_pos, uint16_t y_pos, const char *string, uint16_t color);

#endif // _DISPLAY_FONT_H_
