#pragma once

#include "RectangleWindowClippingArtist.h"

class RectangleWindowPointClippingArtist : public RectangleWindowClippingArtist {
private:
    utils::Point<int> p;
protected:
    void clip(HDC hdc) override;
public:
    void onMouseLeftDown(HDC hdc, int x, int y) override;
    void handleConsole(HDC hdc) override;
    ~RectangleWindowPointClippingArtist() = default;
};