#pragma once

#include "core.h"

struct Point
{
    int x = 0,y = 0;
    COLORREF color = RGB(0,0,0);
};


/*
    `distance()` will be used mainly for comparisons and since `sqrt()` is monotonic,
    I don't need to compute the square root of the expression.
*/
int distance(Point p1,Point p2)
{
    return (p2.x - p1.x) * (p2.x - p1.x) + (p2.y - p1.y) * (p2.y - p1.y);
}

void drawFourPixels(HDC hdc, Point centre, int x, int y)
{
    SetPixel(hdc,centre.x + x, centre.y + y, centre.color);
    SetPixel(hdc,centre.x + x, centre.y - y, centre.color);
    SetPixel(hdc,centre.x - x, centre.y + y, centre.color);
    SetPixel(hdc,centre.x - x, centre.y - y, centre.color);
}