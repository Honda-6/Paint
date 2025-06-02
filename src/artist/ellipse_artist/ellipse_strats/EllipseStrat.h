#pragma once

#include "Core.h"
#include "Utils.h"
#include <cmath>
#include <algorithm>

class EllipseStrat
{
public:
    virtual void drawEllipse(HDC hdc, const utils::Point<int> &centre, unsigned int semiHorizontal,unsigned int semiVertical, COLORREF color = RGB(200,30,100)) = 0;
    virtual ~EllipseStrat() = default;
};