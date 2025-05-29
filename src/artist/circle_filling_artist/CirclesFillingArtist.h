#pragma once

#include "CircleFillingArtist.h"

class CirclesFillingArtist: public CircleFillingArtist {
private:
    void fillCircle(HDC hdc, unsigned int radius, Point (*firstOctant)(Point,int,int),Point (*secondOctant)(Point,int,int), COLORREF color) override;
public:
    ~CirclesFillingArtist() = default;
};