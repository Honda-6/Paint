#pragma once
#include "EllipseArtist.h"

class DirectEllipseDrawingArtist: public EllipseArtist
{
private:
    void drawEllipse(HDC hdc) override;
public:;
    ~DirectEllipseDrawingArtist() = default;
};