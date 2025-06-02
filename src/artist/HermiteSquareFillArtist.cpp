#include "HermiteSquareFillArtist.h"
#include <cmath>
#include <iostream>
#include "Utils.h"

void HermiteSquareFillArtist::fillSquare(HDC hdc) {
    if (x1 > x2) {
        std::swap(y1, y2);
        std::swap(x1, x2);
    }

    for (int x = x1; x <= x2; x++) {
        utils::drawHermite(hdc, x, y1, 0, 0, x, y2, 0, 0, 1000, color);
    }
}

void HermiteSquareFillArtist::onMouseLeftDown(HDC hdc, int x, int y) {
    x1 = x;
    y1 = y;
}

void HermiteSquareFillArtist::onMouseLeftUp(HDC hdc, int x, int y) {
    x2 = x;
    int length = abs(x2 - x1);
    if (y1 > y) {
        y2 = y1 - length;
    } else {
        y2 = y1 + length;
    }

    fillSquare(hdc);
}

void HermiteSquareFillArtist::handleConsole(HDC hdc) {
    std::cout << "Enter top-left corner's x: ";
    std::cin >> x1;
    std::cout << "Enter top-left corner's y: ";
    std::cin >> y2;

    int length;
    std::cout << "Enter side length: ";
    std::cin >> length;

    x2 = x1 + length;
    y2 = y1 + length;

    fillSquare(hdc);
}
