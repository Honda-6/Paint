#ifndef LINE_PARAMETRIC_H
#define LINE_PARAMETRIC_H

#include "LineStrategy.h"

class LineParametricStrategy : public LineStrategy
{
public:
    void draw(HDC hdc, int x1, int y1, int x2, int y2, COLORREF color) override;
};

#endif