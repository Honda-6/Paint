#pragma once

#include "CircleFillingArtist.h"

class CirclesFillingArtist: public CircleFillingArtist {
private:
    void fillCircle(HDC hdc, unsigned int radius, utils::Point<int> (*firstOctant)(const utils::Point<int>&,int,int),utils::Point<int> (*secondOctant)(const utils::Point<int>&,int,int)) override;
public:
    ~CirclesFillingArtist() = default;
};
