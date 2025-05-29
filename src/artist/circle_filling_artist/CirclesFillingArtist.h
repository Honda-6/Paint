#pragma once

#include "CircleFillingArtist.h"

class CirclesFillingArtist: public CircleFillingArtist {
private:
    void fillCircle(HDC hdc, unsigned int radius, utils::Point (*firstOctant)(utils::Point,int,int),utils::Point (*secondOctant)(utils::Point,int,int), COLORREF color) override;
public:
    ~CirclesFillingArtist() = default;
};