#pragma once

#include "Artist.h"
#include "Core.h"
#include "Utils.h"
#include "LineMidpointStrategy.h"
#include "CohenSutherland.h"

enum State
{
    DRAWN,
    NOT_DRAWN
};

struct QuadrilateralWindow
{
    utils::Point pointOne, pointTwo;
    State state;
    void draw(HDC hdc, COLORREF color = RGB(150, 30, 15))
    {
        LineMidpointStrategy lineStrategy;
        lineStrategy.draw(hdc, pointOne.x, pointOne.y, pointTwo.x, pointOne.y, color);
        lineStrategy.draw(hdc, pointOne.x, pointOne.y, pointOne.x, pointTwo.y, color);
        lineStrategy.draw(hdc, pointTwo.x, pointTwo.y, pointOne.x, pointTwo.y, color);
        lineStrategy.draw(hdc, pointTwo.x, pointTwo.y, pointTwo.x, pointOne.y, color);
    }
    QuadrilateralWindow()
        : pointOne(0, 0), pointTwo(0, 0), state(NOT_DRAWN) {}
    QuadrilateralWindow(const utils::Point &p1, const utils::Point &p2)
        : pointOne(p1), pointTwo(p2), state(NOT_DRAWN) {}
};