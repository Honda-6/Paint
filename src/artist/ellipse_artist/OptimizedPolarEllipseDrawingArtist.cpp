#include "OptimizedPolarEllipseDrawingArtist.h"

void OptimizedPolarEllipseDrawingArtist::drawEllipse(HDC hdc, COLORREF color)
{
    this->centre.color = RGB(35,199,50);
    int a = std::sqrt(this->semiHorizontalLengthSquared), b = std::sqrt(this->semiVerticalLengthSquared);
    double dTheta = 1.0/std::max(a,b);
    double cosineDTheta = std::cos(dTheta), sineDTheta = std::sin(dTheta);
    double aSine = 0, bCosine = b;
    double x = a, y = 0;
    drawFourPixels(hdc,this->centre,x,y,color);
    while (x > 0) {
        aSine = aSine * cosineDTheta + x * sineDTheta;
        bCosine = bCosine * cosineDTheta - y * sineDTheta;
        x = x*cosineDTheta - aSine * sineDTheta;
        y = y*cosineDTheta + bCosine * sineDTheta;
        drawFourPixels(hdc,this->centre,round(x),round(y),color);
    }
}