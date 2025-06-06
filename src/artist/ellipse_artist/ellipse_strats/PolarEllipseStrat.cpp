#include "PolarEllipseStrat.h"


void PolarEllipseStrat::drawEllipse(HDC hdc, const utils::Point<int> &centre, unsigned int semiHorizontalLengthSquared, unsigned int semiVerticalLengthSquared, COLORREF color)
{
    int a = std::sqrt(semiHorizontalLengthSquared), b = std::sqrt(semiVerticalLengthSquared);
    double dTheta = 1.0/std::max(a,b), theta = 0;
    double x = a, y = 0;
    utils::drawFourPixels(hdc,centre,round(x),round(y),color);
    theta += dTheta;
    while(theta <= 11.0/7)
    {
        x = a * std::cos(theta);
        y = b * std::sin(theta);
        utils::drawFourPixels(hdc,centre,round(x),round(y),color);
        theta += dTheta;
    }
}