#include "DirectCircleStrategy.h"
#include "Utils.h"
void DirectCircleStrategy::draw(HDC hdc, int xc, int yc, int r, COLORREF color) {
    int x = 0;
    int y = r;
    while (x < y) {
        utils::draw8Points(hdc, xc, yc, x, y, color);
        x++;
        y = (int)round(sqrt(r * r - x * x));
    }

}
