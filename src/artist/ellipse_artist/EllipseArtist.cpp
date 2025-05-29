#include "EllipseArtist.h"

void EllipseArtist::onMouseLeftDown(HDC hdc, int x, int y)
{
    static int clicks = 0;
    Point vertix = {x,y};
    clicks++;

    if(clicks == 1)
        this->centre = vertix;
    else if(clicks == 2)
        this->semiHorizontalLengthSquared = squareDistance(vertix,this->centre);
    else
    {
        this->semiVerticalLengthSquared = squareDistance(vertix,this->centre);
        this->drawEllipse(hdc);
    }
    
    clicks %= 3;

}

void EllipseArtist::handleConsole(HDC hdc)
{
    int x,y,a,b;
    std::cout << "Enter the centre coordinates of the ellipse: ";
    std::cin >> x >> y;
    std::cout << "Enter the semi-horizontal axis length: ";
    std::cin >> a;
    std::cout << "Enter the semi-vertical axis length: ";
    std::cin >> b;
    this->centre = {x,y}, this->semiHorizontalLengthSquared = a, this->semiVerticalLengthSquared = b;
    this->drawEllipse(hdc);
}