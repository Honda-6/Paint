#pragma once
#include "Core.h"

class FloodFillStrategy {
public:
    virtual void floodFill(HDC hdc, int x, int y, COLORREF fillColor, COLORREF initialColor)  = 0;
};
