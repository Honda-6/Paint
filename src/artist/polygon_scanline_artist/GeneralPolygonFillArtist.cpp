#include "GeneralPolygonFillArtist.h"
#include <iostream>
#include <cmath>
#include "LineMidpointStrategy.h"


//Color will be added later
static void drawLine(HDC hdc, int x1, int y1, int x2, int y2, COLORREF color) {
    LineMidpointStrategy line;
    line.draw(hdc, x1, y1, x2, y2, color);
}


void GeneralPolygonFillArtist::addEdgeToTable(Table &edgeTable, const utils::Point<int> &firstPoint, const utils::Point<int> &secondPoint) {
    utils::Point<int> p1 = firstPoint;
    utils::Point<int> p2 = secondPoint;
    if (p1.y == p2.y) return;
    if (p1.y > p2.y) {
        std::swap(p1, p2);
    }
    double slopeInv = double(p2.x - p1.x) / (p2.y - p1.y);
    edgeTable[p1.y].push_back(Node(p1.x, slopeInv, p2.y));
}


void GeneralPolygonFillArtist::fillPolygonFromEdgeTable(HDC hdc, Table &edgeTable, COLORREF color) {
    int y = 0;
    while (edgeTable[y].empty() && y < 800) y++;

    if (y == 800) return;

    LList activeEdges = edgeTable[y];

    while (activeEdges.size() > 0 && y < 800) {
        activeEdges.sort([](const Node &a, const Node &b) { return a.x1 < b.x1; });

        //Drawing
        auto it = activeEdges.begin();
        while (it != activeEdges.end()) {
            Node n1 = *it++;
            if (it == activeEdges.end()) break;
            Node n2 = *it++;
            drawLine(hdc, (int) ceil(n1.x1), y, (int) floor(n2.x1), y, color);
        }
        //Incrementing
        y++;

        //Deleting
        it = activeEdges.begin();
        while (it != activeEdges.end()) {
            if (it->yMax <= y) {
                it = activeEdges.erase(it);
            } else {
                ++it;
            }
        }

        //Updating
        for (auto &node: activeEdges) {
            node.x1 += node.slopeInv;
        }

        //Append
        if (!edgeTable[y].empty()) {
            activeEdges.insert(activeEdges.end(), edgeTable[y].begin(), edgeTable[y].end());
        }
    }
}


void GeneralPolygonFillArtist::scanLineFill(HDC hdc, COLORREF color) {
    if (!validPolygon(points)) {
        std::cout << "The polygon is not valid." << std::endl;
        return;
    }
    Table edgeTable;
    for (int i = 0; i < points.size(); i++) {
        addEdgeToTable(edgeTable, points[i], points[(i + 1) % points.size()]);
    }
    fillPolygonFromEdgeTable(hdc, edgeTable, color);
}


void GeneralPolygonFillArtist::onMouseLeftUp(HDC hdc, int x, int y) {
    points.push_back(utils::Point<int>{x, y});
}

void GeneralPolygonFillArtist::handleConsole(HDC hdc) {
    std::cout << "Enter number of points: ";
    int n;
    std::cin >> n;
    std::cout << "Enter points (x y):" << std::endl;
    for (int i = 0; i < n; i++) {
        int x, y;
        std::cin >> x >> y;
        points.push_back(utils::Point<int>{x, y});
    }


    points.clear();
}


void GeneralPolygonFillArtist::onMouseRightDown(HDC hdc, int x, int y) {
    scanLineFill(hdc, color);
    points.clear();
}
