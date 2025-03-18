#include "LineArtist.h"

LineArtist::LineArtist(LineStrategy *line)
{
    this->line = line;
}

void LineArtist::onMouseLeftDown(HDC hdc, int x, int y)
{
    x1 = x;
    y1 = y;
}

void LineArtist::onMouseLeftUp(HDC hdc, int x, int y)
{
    x2 = x;
    y2 = y;

    line->draw(hdc, x1, y1, x2, y2, color);
}

void LineArtist::handleConsole(HDC hdc)
{
    std::cout << "Enter first point's x: ";
    std::cin >> x1;

    std::cout << "Enter first point's y: ";
    std::cin >> y1;

    std::cout << "Enter second point's x: ";
    std::cin >> x2;

    std::cout << "Enter second point's y: ";
    std::cin >> y2;

    line->draw(hdc, x1, y1, x2, y2, color);
}
