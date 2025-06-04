#pragma once

#include "SquareWindowClippingArtist.h"

class SquareWindowPointClippingArtist : public SquareWindowClippingArtist {
private:
    utils::Point<int> p;
protected:
    void clip(HDC hdc) override;
public:
    void onMouseLeftDown(HDC hdc, int x, int y) override;
    void handleConsole(HDC hdc) override;
    ~SquareWindowPointClippingArtist() = default;
};