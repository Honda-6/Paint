#include "LineDDAStrategy.h"

void LineDDAStrategy::draw(HDC hdc, int x1, int y1, int x2, int y2, COLORREF color)
{
    int dx = x2 - x1;
    int dy = y2 - y1;

    if (abs(dx) >= abs(dy))
    {
        drawHorizontal(hdc, x1, y1, x2, y2, color);
    }
    else
    {
        drawVertical(hdc, x1, y1, x2, y2, color);
    }
}

void LineDDAStrategy::drawHorizontal(HDC hdc, int x1, int y1, int x2, int y2, COLORREF color, bool invert)
{
    if (x1 > x2)
    {
        std::swap(x1, x2);
        std::swap(y1, y2);
    }

    double dx = x2 - x1;
    double dy = y2 - y1;

    double m = dy / dx;

    int x = x1;
    double y = y1;
    while (x < x2)
    {

        y += m;

        x++;

        if (invert)
        {
            SetPixel(hdc, round(y), x, color);
        }
        else
        {
            SetPixel(hdc, x, round(y), color);
        }
    }
}

void LineDDAStrategy::drawVertical(HDC hdc, int x1, int y1, int x2, int y2, COLORREF color)
{
    drawHorizontal(hdc, y1, x1, y2, x2, color, true);
}