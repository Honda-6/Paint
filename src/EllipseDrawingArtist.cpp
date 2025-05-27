#include "EllipseDrawingArtist.h"



void EllipseDrawingArtist::drawEllipse(HDC hdc)
{
    int aSquared = distance(centre,major_axis), bSquared = distance(centre,minor_axis);
    double x,y;
    
    if(aSquared > bSquared)
    {
        x = std::sqrt(aSquared), y = 0;
        drawFourPixels(hdc,centre,round(x),round(y));
        x--;
        while(x > 0)
        {
            y = std::sqrt(bSquared * (1 - (x*x)/aSquared));
            drawFourPixels(hdc,centre,round(x),round(y));
            x--;
        }
    }
    else
    {
        y = std::sqrt(bSquared), x = 0;
        drawFourPixels(hdc,centre,round(x),round(y));
        y--;
        while(y > 0)
        {
            x = std::sqrt(aSquared * (1 - (y*y)/bSquared));
            drawFourPixels(hdc,centre,round(x),round(y));
            y--;
        }
    }
}

void EllipseDrawingArtist::onMouseLeftDown(HDC hdc, int x, int y)
{
    static int clicks = 0;
    clicks++;
    if(clicks == 1)
        this->centre = {x,y,RGB(0,0,0)};
    else if(clicks == 2)
        this->major_axis = {x,y,RGB(0,0,0)};
    else
    {
        this->minor_axis = {x,y,RGB(0,0,0)};
        this->drawEllipse(hdc);
        clicks = 0;
    }

}