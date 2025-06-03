#pragma once

#include "Artist.h"
#include "Utils.h"
#include <cmath>
#include <algorithm>
#include <iostream>
#include "EllipseStrat.h"

class EllipseArtist: public Artist
{
protected:
    utils::Point<int> centre;
    unsigned int semiHorizontalLengthSquared, semiVerticalLengthSquared;
    EllipseStrat *strategy;
public:
    EllipseArtist();
    EllipseArtist(EllipseStrat *strat);
    void setStrat(EllipseStrat *strat);
    void onMouseLeftDown(HDC hdc, int x, int y) override;
    void onMouseLeftUp(HDC hdc, int x, int y) override;
    void handleConsole(HDC hdc) override;
    ~EllipseArtist(){delete strategy; };       /* <<== The only feasible workaround to release the allocated memory by the strategy when initialized in the menu, as deleting it directly before returning 
                                                       will crash the program as the actual even is handled in main                                                                         */
};