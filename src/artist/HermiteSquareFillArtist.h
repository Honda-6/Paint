#pragma once

#include "Artist.h"

class HermiteSquareFillArtist: public Artist {
private:
    int x1, y1, x2, y2;

    void fillSquare(HDC hdc);

public:
    void onMouseLeftDown(HDC hdc, int x, int y) override;
    void onMouseLeftUp(HDC hdc, int x, int y) override;
    void handleConsole(HDC hdc) override;
};
