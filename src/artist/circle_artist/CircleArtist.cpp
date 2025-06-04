#include "CircleArtist.h"
#include "Utils.h"
#include <iostream>
CircleArtist::CircleArtist(CircleStrategy *circle) {
    this->circle = circle;
}

CircleArtist::~CircleArtist() {
    delete circle;
}


void CircleArtist::onMouseLeftDown(HDC hdc, int x, int y) {
    xc = x;
    yc = y;
}

void CircleArtist::onMouseLeftUp(HDC hdc, int x, int y) {
    r = static_cast<int>(sqrt(utils::distanceSquared(utils::Point<int>(xc, yc), utils::Point<int>(x, y))));
    circle->draw(hdc, xc, yc, r, color);
}

void CircleArtist::handleConsole(HDC hdc) {
    std::cout << "Enter circle's center x: ";
    std::cin >> xc;

    std::cout << "Enter circle's center y: ";
    std::cin >> yc;

    std::cout << "Enter circle's radius: ";
    std::cin >> r;

    circle->draw(hdc, xc, yc, r, color);
}