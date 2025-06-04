#include "ModifiedMidointCircleStrategy.h"
#include "Utils.h"


void ModifiedMidpointCircleStrategy::draw(HDC hdc, int xc, int yc, int r, COLORREF c) {
    //Working on 2nd octant of the circle
    int x = 0;
    int y = r;
    int d = 1 - r;

    int dda1 = 2;	// initial value when d < 0
    int dda2 = 5 - 2 * r;	// initial value when d >= 0
    utils::draw8Points(hdc, xc, yc, x, y, c);
    while (x < y) {
        // inside
        if (d < 0) {
            d += dda1;
            dda2 += 2;
        }
        // outside
        else {
            y--;
            d += dda2;
            dda2 += 4;
        }
        x++;
        dda1 += 2;
        utils::draw8Points(hdc, xc, yc, x, y, c);
    }

}