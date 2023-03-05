
#ifndef _DISPLAY_GFX_H_
#define _DISPLAY_GFX_H_

#include <stdint.h>

// Colors
#define GFX_COLOR_WHITE         0xFFFF
#define GFX_COLOR_LIGHT_GREY    0xCFFD
#define GFX_COLOR_GREY          0x7FFF
#define GFX_COLOR_DARK_GREY     0x3000
#define GFX_COLOR_BLACK         0x0000
#define GFX_COLOR_RED           0xFFFF
#define GFX_COLOR_RED_ORANGE    0xFFFF
#define GFX_COLOR_ORANGE        0xFFFF
#define GFX_COLOR_ORANGE_YELLOW 0xFFFF
#define GFX_COLOR_YELLOW        0xFFFF
#define GFX_COLOR_YELLOW_GREEN  0xFFFF
#define GFX_COLOR_GREEN         0xFFFF
#define GFX_COLOR_GREEN_BLUE    0xFFFF
#define GFX_COLOR_BLUE          0xFFFF
#define GFX_COLOR_BLUE_PURPLE   0xFFFF
#define GFX_COLOR_PURPLE        0xFFFF
#define GFX_COLOR_PURPLE_RED    0xFFFF

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
