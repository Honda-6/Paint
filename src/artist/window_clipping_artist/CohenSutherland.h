#pragma once

#include "Core.h"
#include "Utils.h"
#include "LineMidpointStrategy.h"

namespace cohenSutherland
{

    typedef union
    {
        struct
        {
            unsigned char left : 1, right : 1, top : 1, bottom : 1;
        };
        unsigned char code : 4;
    } regionCode;

    void initializeRegionCode(const utils::Point<int> &p, const int &xLeft, const int &xRight, const int &yBottom, const int &yUp, regionCode &code);
    void clipLine(HDC hdc, const utils::Point<int> &p1, const utils::Point<int> &p2, const int &xLeft, const int &xRight, const int &yBottom, const int &yTop);
    void clipPoint(HDC hdc, const utils::Point<int> &p, const int &xLeft, const int &xRight, const int &yBottom, const int &yTop);
}