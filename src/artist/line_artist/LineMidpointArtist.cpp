#include "LineMidpointArtist.h"

void LineMidPointArtist::draw(HDC hdc, int x1, int y1, int x2, int y2, COLORREF color)
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

void LineMidPointArtist::drawHorizontal(HDC hdc, int x1, int y1, int x2, int y2, COLORREF color, bool invert)
{
    if (x1 > x2)
    {
        std::swap(x1, x2);
        std::swap(y1, y2);
    }

    int dx = x2 - x1;
    int dy = y2 - y1;

    int incr = dy < 0 ? -1 : 1;
    dy *= incr;

    int d = 2 * dy - dx;
    int d1 = 2 * dy;
    int d2 = -2 * dx;

    int x = x1, y = y1;
    while (x < x2)
    {
        if (d >= 0)
        {
            y += incr;
            d += d2;
        }

        d += d1;
        x++;

        if (invert)
        {
            SetPixel(hdc, y, x, color);
        }
        else
        {
            SetPixel(hdc, x, y, color);
        }
    }
}

void LineMidPointArtist::drawVertical(HDC hdc, int x1, int y1, int x2, int y2, COLORREF color)
{
    drawHorizontal(hdc, y1, x1, y2, x2, color, true);
}