#include "RectangleWindowClippingArtist.h"


void RectangleWindowClippingArtist::onMouseLeftDown(HDC hdc, int x, int y)
{
    if (this->clippingWindow.state == NOT_DRAWN)
        this->clippingWindow.pointOne = utils::Point<int>(x, y);

}
void RectangleWindowClippingArtist::onMouseLeftUp(HDC hdc, int x, int y)
{
    if (this->clippingWindow.state == NOT_DRAWN)
    {
        this->clippingWindow.pointTwo = utils::Point<int>(x,y);
        this->clippingWindow.draw(hdc,this->color);
        this->clippingWindow.state = DRAWN;
    }
}
void RectangleWindowClippingArtist::handleConsole(HDC hdc)
{
    if (this->clippingWindow.state == NOT_DRAWN)
    {
        int x1, y1, x2, y2;
        std::cout << "Enter the first corner (X,Y): ";
        std::cin >> x1 >> y1;
        std::cout << "Enter the opposite corner (X,Y): ";
        std::cin >> x2 >> y2;
        this->clippingWindow.pointOne = utils::Point<int>(x1,y1);
        this->clippingWindow.pointTwo = utils::Point<int>(x2,y2);
        this->clippingWindow.draw(hdc,this->color);
        this->clippingWindow.state = DRAWN;
    }
}