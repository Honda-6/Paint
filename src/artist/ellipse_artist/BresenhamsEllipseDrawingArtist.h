#pragma once

#include "EllipseArtist.h"

class BresenhamsEllipseDrawingArtist : public EllipseArtist
{
private:
    void drawEllipse(HDC hdc, COLORREF color = RGB(150,100,50)) override;
public:
    ~BresenhamsEllipseDrawingArtist() = default;
};