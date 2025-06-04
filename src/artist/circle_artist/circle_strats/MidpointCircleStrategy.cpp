#include "MidpointCircleStrategy.h"
#include "Utils.h"


void MidpointCircleStrategy::draw(HDC hdc, int xc, int yc, int r, COLORREF color) {
    int x = 0;
    int y = r;
    utils::draw8Points(hdc, xc, yc, x, y, color);

    while (x < y) {
        double d = (x+1)*(x+1) + (y-0.5)*(y-0.5) - r*r;
        if (d > 0) y--;
        x++;
        utils::draw8Points(hdc, xc, yc, x, y, color);
    }
}