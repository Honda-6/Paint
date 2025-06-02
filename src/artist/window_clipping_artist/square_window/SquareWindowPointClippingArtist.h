#pragma once

#include "SquareWindowClippingArtist.h"

class SquareWindowPointClipping : public SquareWindowClippingArtist {
private:
    utils::Point<int> p;
protected:
    void clip(HDC hdc) override;
public:
    void onMouseLeftDown(HDC hdc, int x, int y) override;
    void handleConsole(HDC hdc) override;
    ~SquareWindowPointClipping() = default;
};