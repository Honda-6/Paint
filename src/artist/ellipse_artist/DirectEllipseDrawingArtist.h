#pragma once
#include "EllipseArtist.h"

class DirectEllipseDrawingArtist: public EllipseArtist
{
private:
    void drawEllipse(HDC hdc,COLORREF color = RGB(200,150,50)) override;
public:;
    ~DirectEllipseDrawingArtist() = default;
};