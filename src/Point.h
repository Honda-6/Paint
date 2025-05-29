#pragma once

#include "core.h"

struct Point
{
    int x, y;
    Point(int X = 0, int Y = 0)
        : x{X}, y{Y} {}
};


inline int squareDistance(Point p1,Point p2)
{
    return (p2.x - p1.x) * (p2.x - p1.x) + (p2.y - p1.y) * (p2.y - p1.y);
}

inline void drawFourPixels(HDC hdc, Point centre, int x, int y, COLORREF color)
{
    SetPixel(hdc,centre.x + x, centre.y + y, color);
    SetPixel(hdc,centre.x + x, centre.y - y, color);
    SetPixel(hdc,centre.x - x, centre.y + y, color);
    SetPixel(hdc,centre.x - x, centre.y - y, color);
}