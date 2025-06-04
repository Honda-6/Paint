#pragma once

#include "Core.h"

class CircleStrategy {
public:
    virtual void draw(HDC hdc, int xc, int yc, int r, COLORREF color) = 0;
protected:
    int xc, yc, r;
};