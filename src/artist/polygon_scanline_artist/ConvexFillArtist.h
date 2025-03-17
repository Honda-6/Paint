#pragma once

#include <vector>
#include "Artist.h"
#include "PolygonValidation.h"

struct EdgeRec {int xLeft; int xRight;};
typedef EdgeRec EdgeTable[800];

class ConvexFillArtist : public Artist {

private:
    std::vector<utils::Point<int>> points;


    void initEdgeTable(EdgeTable& edgeTable);
    void addEdgeToTable(EdgeTable& edgeTable,const utils::Point<int>& p1,const utils::Point<int>& p2);
    void constructEdgeTable(EdgeTable& edgeTable);
    void drawLines(HDC hdc, EdgeTable& edgeTable, COLORREF color);
    void convexFill(HDC hdc);

public:
    void onMouseLeftUp(HDC hdc, int x, int y) override;
    void handleConsole(HDC hdc) override;
    void onMouseRightDown(HDC hdc, int x, int y) override;
};
