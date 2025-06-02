#include "RectangleWindowPointClippingArtist.h"


void RectangleWindowPointClippingArtist::clip(HDC hdc) {
    int xLeft = std::min(this->clippingWindow.pointOne.x, this->clippingWindow.pointTwo.x);
    int yTop = std::min(this->clippingWindow.pointOne.y, this->clippingWindow.pointTwo.y);
    int xRight = std::max(this->clippingWindow.pointOne.x, this->clippingWindow.pointTwo.x);
    int yBottom = std::max(this->clippingWindow.pointOne.y, this->clippingWindow.pointTwo.y);
    cohenSutherland::clipPoint(hdc, this->p, xLeft, xRight, yBottom, yTop);
}

void RectangleWindowPointClippingArtist::onMouseLeftDown(HDC hdc, int x, int y) {
    if (this->clippingWindow.state == NOT_DRAWN)
        RectangleWindowClippingArtist::onMouseLeftDown(hdc, x, y);
    else
    {
        this->p = utils::Point<int>(x, y);
        this->clip(hdc);
    }
}

void RectangleWindowPointClippingArtist::handleConsole(HDC hdc) {
    if (this->clippingWindow.state == NOT_DRAWN)
        RectangleWindowClippingArtist::handleConsole(hdc);
    else
    {
        int x, y;
        std::cout << "Enter the point (X,Y): ";
        std::cin >> x >> y;
        this->p = utils::Point<int>(x, y);
        this->clip(hdc);
    }
    
}