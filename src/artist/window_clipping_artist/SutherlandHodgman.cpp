#include "SutherlandHodgman.h"
#include "LineMidpointStrategy.h"
#include "PolygonValidation.h"
#include <iostream>
#include <cmath>

namespace sutherlandHodgman {

    void evaluateEdge(bool in1, bool in2,
                    std::vector<utils::Point<int>> &clippedPoints,
                     const utils::Point<int> &p1, const utils::Point<int> &p2,
                     int edge, bool isHorizontal) {
        if (in1 && in2) {
            clippedPoints.push_back(p2);
        } else if (in1 && !in2) {
            utils::Point<int> intersection = isHorizontal ? utils::horizontalIntersection(p1, p2, edge) : utils::verticalIntersection(p1, p2, edge);
            clippedPoints.push_back(intersection);
        } else if (!in1 && in2) {
            utils::Point<int> intersection = isHorizontal ? utils::horizontalIntersection(p1, p2, edge) : utils::verticalIntersection(p1, p2, edge);
            clippedPoints.push_back(intersection);
            clippedPoints.push_back(p2);
        }
    }

    void drawPolygon(HDC hdc, const std::vector<utils::Point<int>> &p, COLORREF color) {
        LineMidpointStrategy lineStrategy;
        for (size_t i = 0; i < p.size(); ++i) {
            lineStrategy.draw(hdc, p[i].x, p[i].y,
                            p[(i + 1) % p.size()].x, p[(i + 1) % p.size()].y, color);
        }
    }

    void clipPolygon(HDC hdc, std::vector<utils::Point<int>> &p,
                    const int &xLeft, const int &xRight, const int &yBottom, const int &yTop,
                    COLORREF polygonColor, COLORREF clipColor) {
        if (!validPolygon(p)) {
            std::cout << "Invalid polygon." << std::endl;
            return;
        }
        drawPolygon(hdc, p, polygonColor);

        int actualYTop = std::min(yTop, yBottom);
        int actualYBottom = std::max(yTop, yBottom);

        std::vector<utils::Point<int>> buffer;

        // Clip left
        buffer.clear();
        for (size_t i = 0; i < p.size(); ++i) {
            bool in1 = p[i].x >= xLeft;
            bool in2 = p[(i + 1) % p.size()].x >= xLeft;
            evaluateEdge(in1, in2, buffer, p[i], p[(i + 1) % p.size()], xLeft, false);
        }
        p = buffer;
        if (p.empty()) return;

        // Clip right
        buffer.clear();
        for (size_t i = 0; i < p.size(); ++i) {
            bool in1 = p[i].x <= xRight;
            bool in2 = p[(i + 1) % p.size()].x <= xRight;
            evaluateEdge(in1, in2, buffer, p[i], p[(i + 1) % p.size()], xRight, false);
        }
        p = buffer;
        if (p.empty()) return;

        // Clip top
        buffer.clear();
        for (size_t i = 0; i < p.size(); ++i) {
            bool in1 = p[i].y >= actualYTop;
            bool in2 = p[(i + 1) % p.size()].y >= actualYTop;
            evaluateEdge(in1, in2, buffer, p[i], p[(i + 1) % p.size()], actualYTop, true);
        }
        p = buffer;
        if (p.empty()) return;

        // Clip bottom
        buffer.clear();
        for (size_t i = 0; i < p.size(); ++i) {
            bool in1 = p[i].y <= actualYBottom;
            bool in2 = p[(i + 1) % p.size()].y <= actualYBottom;
            evaluateEdge(in1, in2, buffer, p[i], p[(i + 1) % p.size()], actualYBottom, true);
        }
        p = buffer;

        drawPolygon(hdc, p, clipColor);
    }
}