#pragma once

#include "Artist.h"

class BezierRectangleFillArtist: public Artist {
private:
    int x1, y1, x2, y2;

    void fillRectangle(HDC hdc);
    void drawBezier(HDC hdc, int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4, int numpoints, COLORREF color);

public:
    void onMouseLeftDown(HDC hdc, int x, int y) override;
    void onMouseLeftUp(HDC hdc, int x, int y) override;
    void handleConsole(HDC hdc) override;
};
