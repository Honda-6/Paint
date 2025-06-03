#pragma once

#include "FloodFillStrategy.h"

class RecursiveFloodFill : public FloodFillStrategy {
    void floodFill(HDC hdc, int x, int y, COLORREF fillColor, COLORREF initialColor) override;
};
