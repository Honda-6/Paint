#pragma once

#include "CircleFillingArtist.h"
#include "../../utilities/LineMidpointStrategy.h"

class CircleLineFillingArtist: public CircleFillingArtist {
private:
    void fillCircle(HDC hdc, unsigned int radius, utils::Point (*firstOctant)(utils::Point,int,int), utils::Point (*secondOctant)(utils::Point,int,int), COLORREF color) override;
public:
    ~CircleLineFillingArtist() = default;
};