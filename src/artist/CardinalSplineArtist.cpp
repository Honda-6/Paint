#include "CardinalSplineArtist.h"
#include "HermiteSquareFillArtist.h"
#include "Palette.h"
#include <iostream>
#include "Utils.h"

void CardinalSplineArtist::drawCardinalSpline(HDC hdc, std::vector<Point> pts, double c ,COLORREF color) {
    unsigned n = pts.size();
    // compute the slopes for each segment
    std::vector<Slope> d(n);
    for (int i = 1; i < n-1; ++i) {
        d[i] = Slope(pts[i-1], pts[i+1], c);
    }
    d[0] = d[1]; d[n-1] = d[n-2];

    // draw the hermite curve for each segment
    for (int i = 0; i < n-1; ++i) {
        Utils::drawHermite(hdc, pts[i].x, pts[i].y, d[i].u, d[i].v, pts[i+1].x, pts[i+1].y, d[i+1].u, d[i+1].v, 1000, color);
    }
}

void CardinalSplineArtist::onMouseLeftDown(HDC hdc, int x, int y) {
    control_points.emplace_back(x, y);
}

void CardinalSplineArtist::onMouseRightDown(HDC hdc, int x, int y) {
    drawCardinalSpline(hdc, control_points, c, COLOR_CRIMSON_RED);
    control_points.clear();
}

void CardinalSplineArtist::handleConsole(HDC hdc) {
    std::cout << "Enter the smoothing factor: ";
    std::cin >> c;
}
