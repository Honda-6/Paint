#pragma once

#include "EllipseStrat.h"

class OptimizedPolarEllipseStrat: public EllipseStrat
{
public:
    void drawEllipse(HDC hdc, const utils::Point<int> &centre, unsigned int semiHorizontalLengthSquared, unsigned int semiVerticalLengthSquared, COLORREF color) override;
    ~OptimizedPolarEllipseStrat() = default; 
};