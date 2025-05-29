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
    //hard coded color gamut for now till we implement the color attribute in the artist interface
    virtual void drawEllipse(HDC hdc, COLORREF color = RGB(200,100,30)) = 0;
public:
    void onMouseLeftDown(HDC hdc, int x, int y) override;
    void handleConsole(HDC hdc) override;
    ~EllipseArtist() = default;
};