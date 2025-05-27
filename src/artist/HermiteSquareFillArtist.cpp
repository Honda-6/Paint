#include "HermiteSquareFillArtist.h"
#include "Matrix.h"
#include "../Palette.h"
#include <cmath>
#include <iostream>

void HermiteSquareFillArtist::fillSquare(HDC hdc) {
    if (x1 > x2) {
        std::swap(y1, y2);
        std::swap(x1, x2);
    }

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
