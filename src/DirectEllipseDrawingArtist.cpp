#include "DirectEllipseDrawingArtist.h"



void DirectEllipseDrawingArtist::drawEllipse(HDC hdc)
{
    double x,y;
    
    if(this->semiHorizontalLength > this->semiVerticalLength)
    {
        x = std::sqrt(this->semiHorizontalLength), y = 0;
        drawFourPixels(hdc,centre,round(x),round(y));
        x--;
        while(x > 0)
        {
            y = std::sqrt(this->semiVerticalLength * (1 - (x*x)/this->semiHorizontalLength));
            drawFourPixels(hdc,centre,round(x),round(y));
            x--;
        }
    }
    else
    {
        y = std::sqrt(this->semiVerticalLength), x = 0;
        drawFourPixels(hdc,centre,round(x),round(y));
        y--;
        while(y > 0)
        {
            x = std::sqrt(this->semiHorizontalLength * (1 - (y*y)/this->semiVerticalLength));
            drawFourPixels(hdc,centre,round(x),round(y));
            y--;
        }
    }
}

void DirectEllipseDrawingArtist::onMouseLeftDown(HDC hdc, int x, int y)
{
    static int clicks = 0;
    Point vertix = {x,y,RGB(0,0,0)};
    clicks++;

    if(clicks == 1)
        this->centre = vertix;
    else if(clicks == 2)
        this->semiHorizontalLength = distance(vertix,this->centre);
    else
    {
        this->semiVerticalLength = distance(vertix,this->centre);
        this->drawEllipse(hdc);
    }
    
    clicks %= 3;

}

void DirectEllipseDrawingArtist::handleConsole(HDC hdc)
{
    int x,y,a,b;
    std::cout << "Enter the centre coordinates of the ellipse: ";
    std::cin >> x >> y;
    std::cout << "Enter the semi-horizontal axis length: ";
    std::cin >> a;
    std::cout << "Enter the semi-vertical axis length: ";
    std::cin >> b;
    this->centre = {x,y,RGB(0,0,0)}, this->semiHorizontalLength = a, this->semiVerticalLength = b;
    this->drawEllipse(hdc);
}