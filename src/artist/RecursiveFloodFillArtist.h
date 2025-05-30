#pragma once

#include "Artist.h"
#include "utils.h"

class RecursiveFloodFillArtist : public Artist {
private:
    COLORREF initialColor, fill_color;

    void floodFill(HDC hdc, int x, int y, COLORREF fill_color);

public:
    void onMouseLeftUp(HDC hdc, int x, int y) override;
    void handleConsole(HDC hdc) override;
};
