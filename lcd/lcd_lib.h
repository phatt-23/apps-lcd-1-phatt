#ifndef __LCD_LIB_H
#define __LCD_LIB_H

#include <cstdint>

#define LCD_WIDTH  320
#define LCD_HEIGHT 240

// HW reset of LCD controller
void lcd_reset();

// LCD controller initialization
void lcd_init();

// draw one pixel to LCD screen
void lcd_put_pixel( int32_t t_x, int32_t t_y, uint16_t t_color );

#endif // __LCD_LIB_H
