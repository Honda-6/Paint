#pragma once

#include "Artist.h"
#include "Point.h"
#include <cmath>
#include <algorithm>

class EllipseDrawingArtist: public Artist
{
private:
    Point centre,major_axis,minor_axis;
    void drawEllipse(HDC hdc);
public:
    virtual void onMouseLeftDown(HDC hdc, int x, int y) override;
    virtual void onMouseLeftUp(HDC hdc, int x, int y) override;
    ~EllipseDrawingArtist() = default;
};