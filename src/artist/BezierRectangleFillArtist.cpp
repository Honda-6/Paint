#include "BezierRectangleFillArtist.h"
#include "Matrix.h"
#include "../Palette.h"
#include <iostream>

void BezierRectangleFillArtist::fillRectangle(HDC hdc) {
    if (y1 > y2) {
        std::swap(y1, y2);
        std::swap(x1, x2);
    }

    for (int y = y1; y <= y2; y++) {
        drawBezier(hdc, x1, y, x1, y, x2, y, x2, y, 1000, COLOR_ELECTRIC_INDIGO);
    }
}

void BezierRectangleFillArtist::drawBezier(HDC hdc, int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4, int numpoints, COLORREF color) {
    Matrix<int, 4, 4> B = {
        { -1,  3, -3,  1 },
        {  3, -6,  3,  0 },
        { -3,  3,  0,  0 },
        {  1,  0,  0,  0 }
    };

    Matrix<int, 4, 2> g = {
        {x1, y1},
        {x2, y2},
        {x3, y3},
        {x4, y4}
    };

    Matrix<int, 4, 2> c = B * g;

    double dt = 1.0 / numpoints;
    for (double t = 0; t <= 1; t += dt) {
        double x = c(0, 0) * t * t * t + c(1, 0) * t * t + c(2, 0) * t + c(3, 0);
        double y = c(0, 1) * t * t * t + c(1, 1) * t * t + c(2, 1) * t + c(3, 1);

        SetPixel(hdc, round(x), round(y), color);
    }
}

void BezierRectangleFillArtist::onMouseLeftDown(HDC hdc, int x, int y) {
    x1 = x;
    y1 = y;
}

void BezierRectangleFillArtist::onMouseLeftUp(HDC hdc, int x, int y) {
    x2 = x;
    y2 = y;

    fillRectangle(hdc);
}

void BezierRectangleFillArtist::handleConsole(HDC hdc) {
    std::cout << "Enter x1: ";
    std::cin >> x1;
    std::cout << "Enter y1: ";
    std::cin >> y1;
    std::cout << "Enter x2: ";
    std::cin >> x2;
    std::cout << "Enter y2: ";
    std::cin >> y2;

    fillRectangle(hdc);
}
