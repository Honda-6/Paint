#pragma once


#include "Core.h"
#include "Artist.h"
#include "CircleStrategy.h"


class CircleArtist : public Artist {
public:
    CircleArtist(CircleStrategy *circle);
    void onMouseLeftDown(HDC hdc, int x, int y) override;
    void onMouseLeftUp(HDC hdc, int x, int y) override;
    void handleConsole(HDC hdc) override;

private:
    int xc, yc, r;

    CircleStrategy *circle;
};