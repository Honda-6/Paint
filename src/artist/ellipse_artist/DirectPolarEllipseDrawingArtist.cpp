#include "DirectPolarEllipseDrawingArtist.h"


void DirectPolarEllipseDrawingArtist::drawEllipse(HDC hdc, COLORREF color)
{
    int a = std::sqrt(this->semiHorizontalLengthSquared), b = std::sqrt(this->semiVerticalLengthSquared);
    double dTheta = 1.0/std::max(a,b), theta = 0;
    double x = a, y = 0;
    drawFourPixels(hdc,this->centre,round(x),round(y),color);
    theta += dTheta;
    while(theta <= 11.0/7)
    {
        x = a * std::cos(theta);
        y = b * std::sin(theta);
        drawFourPixels(hdc,this->centre,round(x),round(y),color);
        theta += dTheta;
    }

}
