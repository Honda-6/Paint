#include "LineArtistParametric.h"

void LineArtistParametric::draw(HDC hdc, int x1, int y1, int x2, int y2, COLORREF color)
{
    double a1 = x2 - x1;
    double b1 = x1;

    double a2 = y2 - y1;
    double b2 = y1;

    double step = 1.0 / std::max(abs(a1), abs(a2));

    double x, y;
    for (double t = 0.0; t <= 1.0; t += step)
    {
        x = a1 * t + b1;

        y = a2 * t + b2;

        SetPixel(hdc, round(x), round(y), color);
    }
}