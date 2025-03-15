#pragma once

#include "Artist.h"

class HermiteSquareFillArtist: public Artist {
private:
    // A square is defined by its top-left corner (x, y) and its side length `length`.
    int x, y, length;

    void fillSquare(HDC hdc);
    void drawHermite(HDC hdc, int x1, int y1, int u1, int v1, int x2, int y2, int u2, int v2, int numpoints, COLORREF color);

public:
    void onMouseLeftDown(HDC hdc, int x, int y) override;
    void onMouseLeftUp(HDC hdc, int x, int y) override;
    void handleConsole(HDC hdc) override;
};
