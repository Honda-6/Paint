#include "DirectEllipseDrawingArtist.h"

void DirectEllipseDrawingArtist::drawEllipse(HDC hdc, COLORREF color)
{
    double x,y;
    
    if(this->semiHorizontalLengthSquared > this->semiVerticalLengthSquared)
    {
        x = std::sqrt(this->semiHorizontalLengthSquared), y = 0;
        drawFourPixels(hdc,centre,round(x),round(y),color);
        x--;
        while(x > 0)
        {
            y = std::sqrt(this->semiVerticalLengthSquared * (1 - (x*x)/this->semiHorizontalLengthSquared));
            drawFourPixels(hdc,centre,round(x),round(y),color);
            x--;
        }
    }
    else
    {
        y = std::sqrt(this->semiVerticalLengthSquared), x = 0;
        drawFourPixels(hdc,centre,round(x),round(y),color);
        y--;
        while(y > 0)
        {
            x = std::sqrt(this->semiHorizontalLengthSquared * (1 - (y*y)/this->semiVerticalLengthSquared));
            drawFourPixels(hdc,centre,round(x),round(y),color);
            y--;
        }
    }
}