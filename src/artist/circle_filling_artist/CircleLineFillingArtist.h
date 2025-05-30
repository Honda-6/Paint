#pragma once

#include "CircleFillingArtist.h"
#include "LineMidpointStrategy.h"

class CircleLineFillingArtist: public CircleFillingArtist {
private:
    void fillCircle(HDC hdc, unsigned int radius, utils::Point<int> (*firstOctant)(const utils::Point<int>&,int,int), utils::Point<int> (*secondOctant)(const utils::Point<int>&,int,int), COLORREF color) override;
public:
    ~CircleLineFillingArtist() = default;
};
