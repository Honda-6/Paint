#pragma once

#include "CircleStrategy.h"

class PolarCircleStrategy : public CircleStrategy
{
public:
    void draw(HDC hdc, int xc, int yc, int r, COLORREF color) override;
};
