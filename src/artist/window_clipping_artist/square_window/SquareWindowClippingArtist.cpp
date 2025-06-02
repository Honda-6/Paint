#include "SquareWindowClippingArtist.h"


void SquareWindowClippingArtist::onMouseLeftDown(HDC hdc, int x, int y)
{
    if (this->clippingWindow.state == NOT_DRAWN)
        this->clippingWindow.pointOne = utils::Point(x, y);

}
void SquareWindowClippingArtist::onMouseLeftUp(HDC hdc, int x, int y)
{
    if (this->clippingWindow.state == NOT_DRAWN)
    {
        int dx = x - this->clippingWindow.pointOne.x;
        int dy = y - this->clippingWindow.pointOne.y;
        if(std::abs(dx) > std::abs(dy))
            this->clippingWindow.pointTwo = utils::Point(this->clippingWindow.pointOne.x + dx, this->clippingWindow.pointOne.y + std::abs(dx) * ((dy < 0) ? -1 : 1));
        else
            this->clippingWindow.pointTwo = utils::Point(this->clippingWindow.pointOne.x + std::abs(dy) * ((dx < 0) ? -1 : 1), this->clippingWindow.pointOne.y + dy);

        this->clippingWindow.draw(hdc);
        this->clippingWindow.state = DRAWN;
    }
}
void SquareWindowClippingArtist::handleConsole(HDC hdc)
{
    if (this->clippingWindow.state == NOT_DRAWN)
    {
        int x1, y1, sideLength;
        std::cout << "Enter top left corner (x y): ";
        std::cin >> x1 >> y1;
        std::cout << "Enter side length: ";
        std::cin >> sideLength;
        this->clip(hdc);
    }
}