#pragma once

#include "RectangleWindowClippingArtist.h"


class RectangleWindowLineClippingArtist : public RectangleWindowClippingArtist {
private:
    utils::Line<int> line;
protected:
    void clip(HDC hdc) override;
public:
    void onMouseLeftDown(HDC hdc, int x, int y) override;
    void onMouseLeftUp(HDC hdc, int x, int y) override;
    void handleConsole(HDC hdc) override;
    ~RectangleWindowLineClippingArtist() = default;
};
