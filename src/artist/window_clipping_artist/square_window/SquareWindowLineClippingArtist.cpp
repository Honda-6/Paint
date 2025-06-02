#include "SquareWindowLineClippingArtist.h"



void SquareWindowLineClippingArtist::clip(HDC hdc)
{
    int xLeft = std::min(this->clippingWindow.pointOne.x, this->clippingWindow.pointTwo.x);
    int yTop = std::min(this->clippingWindow.pointOne.y, this->clippingWindow.pointTwo.y);
    int xRight = std::max(this->clippingWindow.pointOne.x, this->clippingWindow.pointTwo.x);
    int yBottom = std::max(this->clippingWindow.pointOne.y, this->clippingWindow.pointTwo.y);   
    clipLine(hdc,this->line[0],this->line[1],xLeft,xRight,yBottom,yTop);
}

void SquareWindowLineClippingArtist::onMouseLeftDown(HDC hdc, int x, int y)
{
    if (this->clippingWindow.state == NOT_DRAWN)
        SquareWindowClippingArtist::onMouseLeftDown(hdc,x,y);
    else
        this->line[0] = utils::Point(x,y);
}
void SquareWindowLineClippingArtist::onMouseLeftUp(HDC hdc, int x, int y)
{
    if (this->clippingWindow.state == NOT_DRAWN)
        SquareWindowClippingArtist::onMouseLeftUp(hdc,x,y);
    else
    {
        this->line[1] = utils::Point(x,y);
        this->clip(hdc);
    }
}
void SquareWindowLineClippingArtist::handleConsole(HDC hdc)
{
    if (this->clippingWindow.state == NOT_DRAWN)
        SquareWindowClippingArtist::handleConsole(hdc);
    else
    {
        int x1,x2,y1,y2;
        std::cout << "Enter the first point (X,Y): ";
        std::cin >> x1 >> y1;
        std::cout << "Enter the second point (X,Y): ";
        std::cin >> x2 >> y2;
        this->line[0] = utils::Point(x1,y2), this->line[1] = utils::Point(x2,y2);
    }

}
