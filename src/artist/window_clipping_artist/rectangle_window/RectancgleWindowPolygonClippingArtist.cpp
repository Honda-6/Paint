#include "RectancgleWindowPolygonClippingArtist.h"
#include "SutherlandHodgman.h"
#include "Palette.h"

void RectangleWindowPolygonClippingArtist::clip(HDC hdc)
{
    int xLeft = std::min(this->clippingWindow.pointOne.x, this->clippingWindow.pointTwo.x);
    int yTop = std::min(this->clippingWindow.pointOne.y, this->clippingWindow.pointTwo.y);
    int xRight = std::max(this->clippingWindow.pointOne.x, this->clippingWindow.pointTwo.x);
    int yBottom = std::max(this->clippingWindow.pointOne.y, this->clippingWindow.pointTwo.y);
    sutherlandHodgman::clipPolygon(hdc, points, xLeft, xRight, yBottom, yTop, COLOR_LIGHT_GRAY, this->color);
}
void RectangleWindowPolygonClippingArtist::onMouseLeftDown(HDC hdc, int x, int y) {
    if (this->clippingWindow.state == NOT_DRAWN)
        RectangleWindowClippingArtist::onMouseLeftDown(hdc, x, y);
    else
        points.push_back(utils::Point<int>(x, y));
}

void RectangleWindowPolygonClippingArtist::onMouseRightDown(HDC hdc, int x, int y)
{
    if (this->clippingWindow.state == NOT_DRAWN)
        return;
    else
    {
        this->clip(hdc);
    }
}

void RectangleWindowPolygonClippingArtist::handleConsole(HDC hdc) {
    std::cout << "Enter number of points: ";
    int n;
    std::cin >> n;
    std::cout << "Enter points (x y):" << std::endl;
    for (int i = 0; i < n; i++) {
        int x, y;
        std ::cin >> x >> y;
        points.push_back(utils::Point<int>{x,y});
    }
    this->clip(hdc);
    points.clear();
}

