#pragma once

#include "EllipseArtist.h"

class OptimizedPolarEllipseDrawingArtist : public EllipseArtist
{
private:
    void drawEllipse(HDC hdc, COLORREF color = RGB(255,0,0)) override;
public:
    ~OptimizedPolarEllipseDrawingArtist() = default;
};