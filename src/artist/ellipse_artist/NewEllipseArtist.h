#pragma once

#include "Artist.h"
#include "Point.h"
#include <cmath>
#include <algorithm>
#include <iostream>
#include "ellipse_strats/EllipseStrat.h"

class NewEllipseArtist: public Artist
{
protected:
    Point centre;
    unsigned int semiHorizontalLengthSquared, semiVerticalLengthSquared;
    EllipseStrat *strategy;
    //hard coded color gamut for now till we implement the color attribute in the artist interface
    //virtual void drawEllipse(HDC hdc, COLORREF color = RGB(200,100,30)) = 0;
    void drawEllipse(HDC hdc, COLORREF color = RGB(200,100,30));
public:
    NewEllipseArtist();
    NewEllipseArtist(EllipseStrat *strat);
    void setStrat(EllipseStrat *strat);
    void onMouseLeftDown(HDC hdc, int x, int y) override;
    void handleConsole(HDC hdc) override;
    ~NewEllipseArtist() = default;
};