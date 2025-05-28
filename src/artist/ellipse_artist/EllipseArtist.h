#pragma once

#include "Artist.h"
#include "Point.h"
#include <cmath>
#include <algorithm>
#include <iostream>

class EllipseArtist: public Artist
{
protected:
    Point centre;
    int semiHorizontalLengthSquared, semiVerticalLengthSquared;
    virtual void drawEllipse(HDC hdc) = 0;
public:
    void onMouseLeftDown(HDC hdc, int x, int y) override;
    void handleConsole(HDC hdc) override;
    ~EllipseArtist() = default;
};