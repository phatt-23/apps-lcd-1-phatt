#ifndef __graph_class_h__
#define __graph_class_h__

#include "mbed.h"

#define DBG 0

struct Point2D { int32_t x, y; };
struct RGB { uint8_t r, g, b; };

class GraphElement {
    RGB m_fg_color, m_bg_color;

public:
    GraphElement(RGB t_fg_color, RGB t_bg_color);
    void drawPixel(int32_t t_x, int32_t t_y);
    virtual void draw() = 0;
    virtual void hide();

private:
    void swap_fg_bg_color();
    uint16_t convert_RGB888_to_RGB565(RGB t_color);
};


class Pixel : public GraphElement {
    Point2D m_pos;

public:
    Pixel(Point2D t_pos, RGB t_fg_color, RGB t_bg_color);
    virtual void draw();
};


class Circle : public GraphElement {
    Point2D m_center;
    int32_t m_radius;
    void other_octant(int t_xc, int t_yc, int t_x, int t_y);

public:
    Circle( Point2D t_center, int32_t t_radius, RGB t_fg, RGB t_bg ); 
    void draw();
};

class Character : public GraphElement  {
    Point2D m_pos;
    char m_character;

  public:
    Character(Point2D t_pos, char t_char, RGB t_fg, RGB t_bg);
    void draw();
    void draw(uint8_t t_x, uint8_t t_y);
};

class String : public GraphElement {
    Point2D m_pos;
    const char* m_string;

public:
    String(Point2D t_pos, const char* t_str, RGB t_fg, RGB t_bg);
    void draw();
    void draw(uint8_t t_x, uint8_t t_y);
};

class Line : public GraphElement {
    Point2D m_pos1, m_pos2;

public:
    Line(Point2D t_pos1, Point2D t_pos2, RGB t_fg, RGB t_bg);
    void draw_line(Point2D start, Point2D end);
    void draw();
};

#endif//__graph_class_h__