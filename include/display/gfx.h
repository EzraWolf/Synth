
#ifndef _DISPLAY_GFX_H_
#define _DISPLAY_GFX_H_

#include <stdint.h>

// Useful 565 color picker:
// https://rgbcolorpicker.com/565
//
// Tells you how to work with 16b colors in C:
// https://www.barth-dev.de/online/rgb565-color-picker/
#define GFX_COLOR_WHITE         0xF7BE
#define GFX_COLOR_LIGHT_GREY    0xE71C
#define GFX_COLOR_GREY          0xAD75
#define GFX_COLOR_DARK_GREY     0x8410
#define GFX_COLOR_BLACK         0x4208
#define GFX_COLOR_RED           0xFA28
#define GFX_COLOR_RED_ORANGE    0xFAA7
#define GFX_COLOR_ORANGE        0xFBA7
#define GFX_COLOR_ORANGE_YELLOW 0xFE27
#define GFX_COLOR_YELLOW        0xF786
#define GFX_COLOR_YELLOW_GREEN  0xDFE7
#define GFX_COLOR_GREEN         0x7FE7
#define GFX_COLOR_GREEN_BLUE    0x3FF3
#define GFX_COLOR_BLUE          0x3F5F
#define GFX_COLOR_BLUE_PURPLE   0x8B7F
#define GFX_COLOR_PURPLE        0xE35F
#define GFX_COLOR_PURPLE_RED    0xFAB3

// Base Functions
void gfx_fill                     (uint16_t color);
void gfx_draw_pixel               (uint16_t x_pos,   uint16_t y_pos,   uint16_t color);
void gfx_draw_line                (uint16_t x_start, uint16_t y_start, uint16_t x_stop, uint16_t y_stop, uint16_t color);

// Circles
void gfx_draw_circle              (uint16_t x_center, uint16_t y_center, uint16_t radius, uint16_t color);
void gfx_draw_circle_fill         (uint16_t x_center, uint16_t y_center, uint16_t radius, uint16_t color);

// Rectangles
void gfx_draw_rect                (uint16_t x_center, uint16_t y_center, uint16_t width, uint16_t height, uint16_t color);
void gfx_draw_rect_round          (uint16_t x_center, uint16_t y_center, uint16_t width, uint16_t height, uint16_t radius, uint16_t color);
void gfx_draw_rect_fill           (uint16_t x_center, uint16_t y_center, uint16_t width, uint16_t height, uint16_t color);
void gfx_draw_rect_fill_round     (uint16_t x_center, uint16_t y_center, uint16_t width, uint16_t height, uint16_t radius, uint16_t color);
void gfx_draw_rect_rot            (uint16_t x_center, uint16_t y_center, uint16_t width, uint16_t height, uint16_t degree, uint16_t color);
void gfx_draw_rect_rot_round      (uint16_t x_center, uint16_t y_center, uint16_t width, uint16_t height, uint16_t degree, uint16_t radius, uint16_t color);
void gfx_draw_rect_rot_fill       (uint16_t x_center, uint16_t y_center, uint16_t width, uint16_t height, uint16_t degree, uint16_t color);
void gfx_draw_rect_rot_fill_round (uint16_t x_center, uint16_t y_center, uint16_t width, uint16_t height, uint16_t degree, uint16_t radius, uint16_t color);

// Triangles
void gfx_draw_tri                 (uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2, uint16_t x3, uint16_t y3, uint16_t color);
void gfx_draw_tri_round           (uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2, uint16_t x3, uint16_t y3, uint16_t radius, uint16_t color);
void gfx_draw_tri_fill            (uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2, uint16_t x3, uint16_t y3, uint16_t color);
void gfx_draw_tri_fill_round      (uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2, uint16_t x3, uint16_t y3, uint16_t radius, uint16_t color);
void gfx_draw_tri_rot             (uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2, uint16_t x3, uint16_t y3, uint16_t degree, uint16_t color);
void gfx_draw_tri_rot_round       (uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2, uint16_t x3, uint16_t y3, uint16_t degree, uint16_t radius, uint16_t color);
void gfx_draw_tri_rot_fill        (uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2, uint16_t x3, uint16_t y3, uint16_t degree, uint16_t color);
void gfx_draw_tri_rot_fill_round  (uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2, uint16_t x3, uint16_t y3, uint16_t degree, uint16_t radius, uint16_t color);

// N-Gons
void gfx_draw_poly                 (uint16_t x_center, uint16_t y_center, uint16_t width, uint16_t height, uint8_t side_count, uint16_t color);
void gfx_draw_poly_round           (uint16_t x_center, uint16_t y_center, uint16_t width, uint16_t height, uint8_t side_count, uint16_t radius, uint16_t color);
void gfx_draw_poly_fill            (uint16_t x_center, uint16_t y_center, uint16_t width, uint16_t height, uint8_t side_count, uint16_t color);
void gfx_draw_poly_fill_round      (uint16_t x_center, uint16_t y_center, uint16_t width, uint16_t height, uint8_t side_count, uint16_t radius, uint16_t color);
void gfx_draw_poly_rot             (uint16_t x_center, uint16_t y_center, uint16_t width, uint16_t height, uint8_t side_count, uint16_t degree, uint16_t color);
void gfx_draw_poly_rot_round       (uint16_t x_center, uint16_t y_center, uint16_t width, uint16_t height, uint8_t side_count, uint16_t degree, uint16_t radius, uint16_t color);
void gfx_draw_poly_rot_fill        (uint16_t x_center, uint16_t y_center, uint16_t width, uint16_t height, uint8_t side_count, uint16_t degree, uint16_t color);
void gfx_draw_poly_rot_fill_round  (uint16_t x_center, uint16_t y_center, uint16_t width, uint16_t height, uint8_t side_count, uint16_t degree, uint16_t radius, uint16_t color);

#endif // _DISPLAY_GFX_H_
