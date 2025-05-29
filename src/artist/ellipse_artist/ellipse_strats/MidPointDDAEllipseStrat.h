#pragma once

#include "EllipseStrat.h"


class  MidPointDDAEllipseStrat: public EllipseStrat
{
public:
    void drawEllipse(HDC hdc, utils::Point centre, unsigned int semiHorizontalLengthSquared, unsigned int semiVerticalLengthSquared, COLORREF color) override;
    ~MidPointDDAEllipseStrat() = default;
};