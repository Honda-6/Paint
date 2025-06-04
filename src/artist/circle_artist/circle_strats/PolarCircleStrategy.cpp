#include "PolarCircleStrategy.h"
#include "Utils.h"
#include <cmath>

void PolarCircleStrategy::draw(HDC hdc, int xc, int yc, int r, COLORREF color) {
    double step = 1.0 / r;

    for (double theta = 0; theta <= M_PI / 4; theta += step) {
        int x = (int)round(r * cos(theta));
        int y = (int)round(r * sin(theta));
        utils::draw8Points(hdc, xc, yc, x, y, color);
    }
}

