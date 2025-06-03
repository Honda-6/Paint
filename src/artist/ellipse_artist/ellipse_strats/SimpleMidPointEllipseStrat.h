#pragma once

#include "EllipseStrat.h"


class  SimpleMidPointEllipseStrat: public EllipseStrat
{
public:
    void drawEllipse(HDC hdc, const utils::Point<int> &centre, unsigned int semiHorizontalLengthSquared, unsigned int semiVerticalLengthSquared, COLORREF color) override;
    ~SimpleMidPointEllipseStrat() = default;
};