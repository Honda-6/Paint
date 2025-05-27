#pragma once

#include "Artist.h"
#include "Point.h"
#include <cmath>
#include <algorithm>
#include <iostream>

class EllipseDrawingArtist: public Artist
{
private:
    Point centre;
    int semiHorizontalLength, semiVerticalLength;
    void drawEllipse(HDC hdc);
public:
    void onMouseLeftDown(HDC hdc, int x, int y) override;
    void handleConsole(HDC hdc) override;
    ~EllipseDrawingArtist() = default;
};