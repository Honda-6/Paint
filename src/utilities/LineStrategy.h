#ifndef LINE_STRATEGY_H
#define LINE_STRATEGY_H

#include "Core.h"
#include <iostream>

class LineStrategy
{
public:
    virtual void draw(HDC hdc, int x1, int y1, int x2, int y2, COLORREF color) = 0;

protected:
    int x1, y1, x2, y2;
};

#endif