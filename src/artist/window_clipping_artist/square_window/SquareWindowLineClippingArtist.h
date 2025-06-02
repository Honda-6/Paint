#pragma once

#include "SquareWindowClippingArtist.h"


class SquareWindowLineClippingArtist : public SquareWindowClippingArtist {
private:
    Line line;
protected:
    void clip(HDC hdc) override;
public:
    void onMouseLeftDown(HDC hdc, int x, int y) override;
    void onMouseLeftUp(HDC hdc, int x, int y) override;
    void handleConsole(HDC hdc) override;
    ~SquareWindowLineClippingArtist() = default;
};
