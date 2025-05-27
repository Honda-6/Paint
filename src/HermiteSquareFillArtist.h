#pragma once

#include "Artist.h"

class HermiteSquareFillArtist: public Artist {
private:
    int x1, y1, x2, y2;

    void fillSquare(HDC hdc);
    void drawHermite(HDC hdc, int x1, int y1, int u1, int v1, int x2, int y2, int u2, int v2, int numpoints, COLORREF color);

public:
    void onMouseLeftDown(HDC hdc, int x, int y) override;
    void onMouseLeftUp(HDC hdc, int x, int y) override;
    void handleConsole(HDC hdc) override;
};
