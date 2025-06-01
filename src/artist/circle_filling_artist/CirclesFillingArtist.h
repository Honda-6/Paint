#pragma once

#include "CircleFillingArtist.h"

class CirclesFillingArtist: public CircleFillingArtist {
private:
    void fillCircle(HDC hdc, unsigned int radius, utils::Point<int> (*firstOctant)(utils::Point<int>,int,int),utils::Point<int> (*secondOctant)(const utils::Point<int>&,int,int), COLORREF color) override;
public:
    ~CirclesFillingArtist() = default;
};
