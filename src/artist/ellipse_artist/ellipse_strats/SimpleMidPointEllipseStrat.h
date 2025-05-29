#pragma once

#include "EllipseStrat.h"


class  SimpleMidPointEllipseStrat: public EllipseStrat
{
public:
    void drawEllipse(HDC hdc, Point centre, unsigned int semiHorizontalLengthSquared, unsigned int semiVerticalLengthSquared, COLORREF color) override;
    ~SimpleMidPointEllipseStrat() = default;
};