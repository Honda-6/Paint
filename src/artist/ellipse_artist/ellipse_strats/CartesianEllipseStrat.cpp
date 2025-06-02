#include "CartesianEllipseStrat.h"

void CartesianEllipseStrat::drawEllipse(HDC hdc, const utils::Point<int> &centre, unsigned int semiHorizontalLengthSquared, unsigned int semiVerticalLengthSquared, COLORREF color)
{
    double x = std::sqrt(semiHorizontalLengthSquared), y = 0;
    
    utils::drawFourPixels(hdc, centre, round(x), round(y), color);
    y++;
    while (x * semiVerticalLengthSquared >= y * semiHorizontalLengthSquared)
    {
        x = std::sqrt(semiHorizontalLengthSquared * (1 - (y * y) / semiVerticalLengthSquared));
        utils::drawFourPixels(hdc, centre, round(x), round(y), color);
        y++;
    }
    while (x > 0)
    {
        y = std::sqrt(semiVerticalLengthSquared * (1 - (x * x) / semiHorizontalLengthSquared));
        utils::drawFourPixels(hdc, centre, round(x), round(y), color);
        x--;
    }
}