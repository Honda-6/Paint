#pragma once

#include "../Core.h"
#include "Artist.h"
#include "../Palette.h"
#include "Utils.h"
#include <iostream>
#include <cmath>

class CircleFillingArtist: public Artist {
protected:
    utils::Point<int> centre;
    unsigned int radius;
    virtual void fillCircle(HDC hdc, unsigned int radius, utils::Point<int> (*firstOctant)(utils::Point<int>,int,int),utils::Point<int> (*secondOctant)(utils::Point<int>,int,int), COLORREF color = COLOR_TEAL) = 0;
public:
    void onMouseLeftDown(HDC hdc, int x, int y) override;
    void onMouseLeftUp(HDC hdc, int x, int y) override;
    void handleConsole(HDC hdc) override;
    ~CircleFillingArtist() = default;
};
