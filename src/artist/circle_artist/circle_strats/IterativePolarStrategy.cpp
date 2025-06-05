#include "IterativePolarStrategy.h"
#include "Utils.h"

void IterativePolarStrategy::draw(HDC hdc, int xc, int yc, int r, COLORREF color) {

    double dtheta = 1.0 / r;
    double ct = cos(dtheta);
    double st = sin(dtheta);

    double x = 0;
    double y = r;

    while (x <= y) {

        utils::draw8Points(hdc, xc, yc, (int)round(x), (int)round(y), color);
        double newX = x * ct - y * st;
        double newY = x * st + y * ct;

        x = newX;
        y = newY;
    }
}
