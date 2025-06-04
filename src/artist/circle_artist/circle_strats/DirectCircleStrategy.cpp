#include "DirectCircleStrategy.h"
#include "Utils.h"
void DirectCircleStrategy::draw(HDC hdc, int xc, int yc, int r, COLORREF color) {
    for (int x = 0; x <= r; x++) {
        int y = (int)round(sqrt(r * r - x * x));
        utils::draw8Points(hdc, xc, yc, x, y, color);
    }
}
