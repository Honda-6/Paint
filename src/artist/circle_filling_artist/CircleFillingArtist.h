#pragma once

#include "../Core.h"
#include "Artist.h"
#include "../Palette.h"
#include "polygon_scanline_artist/ConvexFillArtist.h"
#include <iostream>
#include <cmath>

class CircleFillingArtist: public Artist {
protected:
    Point centre;
    unsigned int radius;
    virtual void fillCircle(HDC hdc, unsigned int radius, Point (*firstOctant)(Point,int,int),Point (*secondOctant)(Point,int,int), COLORREF color = COLOR_TEAL) = 0;
public:
    void onMouseLeftDown(HDC hdc, int x, int y) override;
    void onMouseLeftUp(HDC hdc, int x, int y) override;
    void handleConsole(HDC hdc) override;
    ~CircleFillingArtist() = default;
};