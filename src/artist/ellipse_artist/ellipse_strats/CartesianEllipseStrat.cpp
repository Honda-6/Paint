#include "CartesianEllipseStrat.h"

void CartesianEllipseStrat::drawEllipse(HDC hdc, utils::Point centre,unsigned int semiHorizontalLengthSquared,unsigned int semiVerticalLengthSquared, COLORREF color) {
    double x,y;
    
    if(semiHorizontalLengthSquared > semiVerticalLengthSquared)
    {
        x = std::sqrt(semiHorizontalLengthSquared), y = 0;
        utils::drawFourPixels(hdc,centre,round(x),round(y),color);
        x--;
        while(x > 0)
        {
            y = std::sqrt(semiVerticalLengthSquared * (1 - (x*x)/semiHorizontalLengthSquared));
            utils::drawFourPixels(hdc,centre,round(x),round(y),color);
            x--;
        }
    }
    else
    {
        y = std::sqrt(semiVerticalLengthSquared), x = 0;
        utils::drawFourPixels(hdc,centre,round(x),round(y),color);
        y--;
        while(y > 0)
        {
            x = std::sqrt(semiHorizontalLengthSquared * (1 - (y*y)/semiVerticalLengthSquared));
            utils::drawFourPixels(hdc,centre,round(x),round(y),color);
            y--;
        }
    }

}