#include "PolarCircleStrategy.h"
#include "Utils.h"
#include <cmath>

#ifndef M_PI_4
#define M_PI_4 0.7853981633974483 //    pi/4
#endif

void PolarCircleStrategy::draw(HDC hdc, int xc, int yc, int r, COLORREF color) {
    double step = 1.0 / r;

    for (double theta = 0; theta <= M_PI_4; theta += step) {
        int x = (int)round(r * cos(theta));
        int y = (int)round(r * sin(theta));
        utils::draw8Points(hdc, xc, yc, x, y, color);
    }
}

