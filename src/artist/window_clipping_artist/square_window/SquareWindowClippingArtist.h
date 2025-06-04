#pragma once

#include "QuadrilateralWindow.h"

class SquareWindowClippingArtist : public Artist {
protected:
    QuadrilateralWindow clippingWindow;
    virtual void clip(HDC hdc) = 0;
public:
    SquareWindowClippingArtist()
        : clippingWindow(utils::Point<int>(0, 0), utils::Point<int>(0, 0)) {}
    void onMouseLeftDown(HDC hdc, int x, int y) override;
    void onMouseLeftUp(HDC hdc, int x, int y) override;
    void handleConsole(HDC hdc) override;
    ~SquareWindowClippingArtist() = default;
};

