#pragma once

#include "FloodFillStrategy.h"

class IterativeFloodFill : public FloodFillStrategy {
    void floodFill(HDC hdc, int x, int y, COLORREF fillColor, COLORREF initialColor) override;
};
