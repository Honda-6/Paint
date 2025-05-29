#include "ConvexFillArtist.h"
#include <iostream>
#include <limits.h>
#include <cmath>
#include <algorithm>
#include "LineMidpointStrategy.h"

//Color will be added later
static void drawLine(HDC hdc, int x1, int y1, int x2, int y2, COLORREF color) {
    LineMidpointStrategy line;
    line.draw(hdc, x1, y1, x2, y2, RGB(0, 0, 0));
}



void ConvexFillArtist::initEdgeTable(EdgeTable& edgeTable) {
    for (int i = 0; i < 800; i++) {
        edgeTable[i].xLeft = INT_MAX;
        edgeTable[i].xRight = INT_MIN;
    }
}

void ConvexFillArtist::addEdgeToTable(EdgeTable &edgeTable,const utils::Point& firstPoint,const utils::Point& secondPoint) {
    utils::Point p1 = firstPoint;
    utils::Point p2 = secondPoint;
    if (p1.y == p2.y) return;
    if (p1.y > p2.y) {
        std::swap(p1, p2);
    }

    double slopeInv = double(p2.x - p1.x)/ (p2.y - p1.y) ;
    int y = p1.y;
    double x = p1.x;
    while (y < p2.y) {
        if (x < edgeTable[y].xLeft) edgeTable[y].xLeft = (int) ceil(x);
        if (x > edgeTable[y].xRight) edgeTable[y].xRight =(int) floor(x);
        y++;
        x += slopeInv;
    }
}



void ConvexFillArtist::constructEdgeTable(EdgeTable& edgeTable) {
    for (int i = 0; i < points.size(); i++) {
        addEdgeToTable(edgeTable, points[i], points[(i + 1) % points.size()]);
    }
}

void ConvexFillArtist::drawLines(HDC hdc, EdgeTable& edgeTable, COLORREF color) {
    for (int i = 0; i < 800; i++) {
        if (edgeTable[i].xLeft <= edgeTable[i].xRight) {
            drawLine(hdc,edgeTable[i].xLeft, i, edgeTable[i].xRight, i, color);
        }
    }
}

void ConvexFillArtist::convexFill(HDC hdc) {
    if (!isConvexPolygon(points)) {
        std::cout << "The polygon is not convex." << std::endl;
        return;
    }

    EdgeTable edgeTable;
    initEdgeTable(edgeTable);
    constructEdgeTable(edgeTable);
    drawLines(hdc, edgeTable, RGB(0, 0, 0));

}


void ConvexFillArtist::onMouseLeftUp(HDC hdc, int x, int y) {
    points.push_back(utils::Point{x,y});
}

void ConvexFillArtist::handleConsole(HDC hdc) {
    std::cout << "Enter number of points: ";
    int n;
    std::cin >> n;
    std::cout << "Enter points (x y):" << std::endl;
    for (int i = 0; i < n; i++) {
        int x, y;
        std ::cin >> x >> y;
        points.push_back(utils::Point{x,y});
    }

    convexFill(hdc);
    points.clear();
}



void ConvexFillArtist::onMouseRightDown(HDC hdc, int x, int y) {
    convexFill(hdc);
    points.clear();
}


