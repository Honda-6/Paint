#pragma once

#include "Artist.h"
#include "Utils.h"
#include "FloodFillStrategy.h"

class FloodFillArtist : public Artist {
private:
    FloodFillStrategy* strategy;
    COLORREF initialColor{RGB(255,255,255)};

public:
    FloodFillArtist(FloodFillStrategy* strat);
    void setStrategy(FloodFillStrategy* strat);
    void onMouseLeftUp(HDC hdc, int x, int y) override;
    void handleConsole(HDC hdc) override;
    ~FloodFillArtist();
};
