#include "graph_class.h"

#include "lcd_lib.h"
#include "font8x8.h"
#include "fonts/font8x12_lsb.h"
#include "fonts/font8x14_lsb.h"
#include "fonts/font10x16_lsb.h"
#include "fonts/font12x16_lsb.h"
#include "fonts/font12x20_lsb.h"
#include "fonts/font16x26_lsb.h"
#include "fonts/font22x36_lsb.h"
#include "fonts/font24x40_lsb.h"
#include "fonts/font32x53_lsb.h"

GraphElement::GraphElement( RGB t_fg_color, RGB t_bg_color ) 
    : m_fg_color( t_fg_color )
    , m_bg_color( t_bg_color ) 
{}

void GraphElement::drawPixel( int32_t t_x, int32_t t_y ) {
    if(t_x >= 0 && t_x <= LCD_WIDTH && t_y >= 0 && t_y <= LCD_HEIGHT) {
        lcd_put_pixel( t_x, t_y, convert_RGB888_to_RGB565( m_fg_color ) ); 
    } else if(DBG) printf("out_of_bound: ( %ld , %ld )\n", t_x, t_y);
}


void GraphElement::hide() { swap_fg_bg_color(); draw(); swap_fg_bg_color(); }
void GraphElement::swap_fg_bg_color() { RGB l_tmp = m_fg_color; m_fg_color = m_bg_color; m_bg_color = l_tmp; } 
uint16_t GraphElement::convert_RGB888_to_RGB565( RGB t_color ) { 
    return ((t_color.r >> 3) << 11) + ((t_color.g >> 2) << 5) + (t_color.b >> 3);
}


Pixel::Pixel( Point2D t_pos, RGB t_fg_color, RGB t_bg_color ) 
    : GraphElement( t_fg_color, t_bg_color ), m_pos( t_pos ) {}

void Pixel::draw() { 
    drawPixel( m_pos.x, m_pos.y ); 
}


Circle::Circle( Point2D t_center, int32_t t_radius, RGB t_fg, RGB t_bg ) : 
    GraphElement( t_fg, t_bg ), m_center( t_center ), m_radius( t_radius ) 
{}

void Circle::other_octant(int t_xc, int t_yc, int t_x, int t_y) {
    drawPixel( t_xc+t_x, t_yc+t_y );
    drawPixel( t_xc-t_x, t_yc+t_y );
    drawPixel( t_xc+t_x, t_yc-t_y );
    drawPixel( t_xc-t_x, t_yc-t_y );
    drawPixel( t_xc+t_y, t_yc+t_x );
    drawPixel( t_xc-t_y, t_yc+t_x );
    drawPixel( t_xc+t_y, t_yc-t_x );
    drawPixel( t_xc-t_y, t_yc-t_x );
}

void Circle::draw() { 
    int l_xc = m_center.x;
    int l_yc = m_center.y;
    int l_r = m_radius;
    int l_x = 0;
    int l_y = l_r;
    int l_d = 3 - 2*l_r;
    other_octant(l_xc, l_yc, l_x, l_y);
    while (l_y >= l_x) {
        ++l_x;
        if (l_d > 0) {
            --l_y; 
            l_d += 4*(l_x - l_y) + 10;
        } else l_d += 4*l_x + 6;
        other_octant(l_xc, l_yc, l_x, l_y);
    }
} 

#define FONT_FF_LOOP(t_x, t_y) \
        for(size_t i = 0; i < t_y; ++i) { \
            for(size_t j = 0; j < t_x; ++j) { \
                if(font##t_x##x##t_y[(int)m_character][i] & (1 << j)) { \
                    drawPixel(j + m_pos.x, i + m_pos.y); \
                } \
            } \
        } \

#define FONT_CASE(t_x, t_y) \
        case (t_y): \
            FONT_FF_LOOP(t_x, t_y); \
            break; \

Character::Character( Point2D t_pos, char t_char, RGB t_fg, RGB t_bg ) : 
  GraphElement( t_fg, t_bg ), m_pos( t_pos ), m_character( t_char ) 
{};

void Character::draw() {
    draw(8, 8);
}

void Character::draw(uint8_t t_x, uint8_t t_y) {
    if(DBG) printf("char: %c -> value: %d\n", m_character, m_character);
    if(DBG) printf("res: %dx%d\n", t_x, t_y);
    switch(t_y) {
        FONT_CASE(8,8);
        FONT_CASE(8,12);
        FONT_CASE(8,14);
        FONT_CASE(10,16);
        FONT_CASE(12,20);
        FONT_CASE(16,26);
        FONT_CASE(22,36);
        FONT_CASE(24,40);
        FONT_CASE(32,53);
        default: break;
    }
}; 

String::String( Point2D t_pos, const char* t_str, RGB t_fg, RGB t_bg ) 
    : GraphElement( t_fg, t_bg )
    , m_pos( t_pos )
    , m_string( t_str )
{}

void String::draw() {
    draw(8,8);
}

void String::draw(uint8_t t_x, uint8_t t_y) {
    Point2D l_pos = m_pos;
    for(size_t i = 0; i < strlen(m_string); ++i) {
        size_t l_start = i;
        size_t l_end = i;
        while(m_string[l_end] != ' ' || m_string[l_end] != '\0') {
            if((m_string[l_end] == ' ' || m_string[l_end] == '\0') || (l_end >= strlen(m_string) - 1)) break;
            l_end++;
        }
        if(m_pos.x + (t_x * (l_end - l_start)) >= LCD_WIDTH) {
            m_pos.y += t_y;
            m_pos.x = l_pos.x;
        }
        for(size_t j = l_start; j < l_end + 1 && j < strlen(m_string); ++j) {
            char m_character = m_string[j];
            switch(t_y) {
                FONT_CASE(8,8);
                FONT_CASE(8,12);
                FONT_CASE(8,14);
                FONT_CASE(10,16);
                FONT_CASE(12,20);
                FONT_CASE(16,26);
                FONT_CASE(22,36);
                FONT_CASE(24,40);
                FONT_CASE(32,53);
                default: break;
            }
            m_pos.x += t_x; 
        }
        i = l_end; 
    }
    m_pos = l_pos;
}


Line::Line( Point2D t_pos1, Point2D t_pos2, RGB t_fg, RGB t_bg ) 
    : GraphElement( t_fg, t_bg ), m_pos1( t_pos1 ), m_pos2( t_pos2 ) 
{}

void Line::draw_line(Point2D start, Point2D end) {
    int l_dx = abs(end.x - start.x);
    int l_dy = abs(end.y - start.y);
    int l_sx = start.x < end.x ? 1 : -1;
    int l_sy = start.y < end.y ? 1 : -1;
    int l_err = l_dx - l_dy;
    int l_x = start.x;
    int l_y = start.y;
    while (true) {
        if(DBG) printf("(%d, %d)\n", l_x, l_y);
        drawPixel(l_x, l_y);
        if (l_x == end.x && l_y == end.y) {
            break;
        }
        int l_e2 = 2 * l_err;
        if (l_e2 > -l_dy) {
            l_err -= l_dy;
            l_x += l_sx;
        }
        if (l_e2 < l_dx) {
            l_err += l_dx;
            l_y += l_sy;
        }
    }
}

void Line::draw() {
    draw_line(m_pos1, m_pos2);
} 
