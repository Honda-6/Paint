#include "OptimizedPolarEllipseStrat.h"

void OptimizedPolarEllipseStrat::drawEllipse(HDC hdc, Point centre, unsigned int semiHorizontalLengthSquared, unsigned int semiVerticalLengthSquared, COLORREF color){

    int a = std::sqrt(semiHorizontalLengthSquared), b = std::sqrt(semiVerticalLengthSquared);
    double dTheta = 1.0/std::max(a,b);
    double cosineDTheta = std::cos(dTheta), sineDTheta = std::sin(dTheta);
    double aSine = 0, bCosine = b;
    double x = a, y = 0;
    drawFourPixels(hdc,centre,x,y,color);
    while (x > 0) {
        aSine = aSine * cosineDTheta + x * sineDTheta;
        bCosine = bCosine * cosineDTheta - y * sineDTheta;
        x = x*cosineDTheta - aSine * sineDTheta;
        y = y*cosineDTheta + bCosine * sineDTheta;
        drawFourPixels(hdc,centre,round(x),round(y),color);
    }
}