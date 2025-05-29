#pragma once

#include "EllipseStrat.h"


class  SimpleMidPointEllipseStrat: public EllipseStrat
{
public:
    void drawEllipse(HDC hdc, utils::Point centre, unsigned int semiHorizontalLengthSquared, unsigned int semiVerticalLengthSquared, COLORREF color) override;
    ~SimpleMidPointEllipseStrat() = default;
};