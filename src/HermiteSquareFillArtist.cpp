#include "HermiteSquareFillArtist.h"
#include "Matrix.h"
#include "Palette.h"
#include <cmath>
#include <iostream>

void HermiteSquareFillArtist::fillSquare(HDC hdc) {
    int y1 = y;
    int y2 = y + length;
    int x1 = x;
    int x2 = x + length;
    
    for (int x = x1; x <= x2; x++) {
        drawHermite(hdc, x, y1, 0, 0, x, y2, 0, 0, 1000, COLOR_EMERALD_GREEN);
    }
}

void HermiteSquareFillArtist::drawHermite(HDC hdc, int x1, int y1, int u1, int v1, int x2, int y2, int u2, int v2, int numpoints, COLORREF color) {
    Matrix<int, 4, 4> H({
        { 2,  1, -2,  1},
        {-3, -2,  3, -1},
        { 0,  1,  0,  0},
        { 1,  0,  0,  0},
    });

    Matrix<int, 4, 2> g({
        {x1, y1},
        {u1, v1},
        {x2, y2},
        {u2, v2}
    });

    Matrix<int, 4, 2> c = H * g;

    double dt = 1.0 / numpoints;
    for (double t = 0; t <= 1; t += dt) {
        double x = c(0, 0) * t * t * t + c(1, 0) * t * t + c(2, 0) * t + c(3, 0);
        double y = c(0, 1) * t * t * t + c(1, 1) * t * t + c(2, 1) * t + c(3, 1);

        SetPixel(hdc, round(x), round(y), color);
    }
}

void HermiteSquareFillArtist::onMouseLeftDown(HDC hdc, int x, int y) {
    this->x = x;
    this->y = y;
}

void HermiteSquareFillArtist::onMouseLeftUp(HDC hdc, int x, int y) {
    length = abs(this->x - x);

    fillSquare(hdc);
}

void HermiteSquareFillArtist::handleConsole(HDC hdc) {
    std::cout << "Enter top-left corner's x: ";
    std::cin >> x;
    std::cout << "Enter top-left corner's y: ";
    std::cin >> y;
    std::cout << "Enter side length: ";
    std::cin >> length;

    fillSquare(hdc);
}
