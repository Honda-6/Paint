#pragma once

#include "Artist.h"
#include <list>
#include<vector>
#include "PolygonValidation.h"
struct Node {
    double x1, slopeInv;
    int yMax;
    Node(double x1 = 0, double slopeInv = 0, int yMax = 0) :
        x1(x1), slopeInv(slopeInv), yMax(yMax) {}
};



typedef std::list<Node> LList;
typedef  LList Table[800];




class GeneralPolygonFillArtist : public Artist {
private:
    std::vector<utils::Point<int>> points;
    void addEdgeToTable(Table& edgeTable,const utils::Point<int>& p1,const utils::Point<int>& p2);
    void fillPolygonFromEdgeTable(HDC hdc, Table& edgeTable, COLORREF color);
    void scanLineFill(HDC hdc, COLORREF color);

public:
    void onMouseLeftUp(HDC hdc, int x, int y) override;
    void handleConsole(HDC hdc) override;
    void onMouseRightDown(HDC hdc, int x, int y) override;
};
