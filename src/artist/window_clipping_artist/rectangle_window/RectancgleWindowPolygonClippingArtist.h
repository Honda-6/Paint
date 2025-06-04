#pragma once

#include "RectangleWindowClippingArtist.h"
#include <vector>

class RectangleWindowPolygonClippingArtist : public RectangleWindowClippingArtist {
private:
   std::vector<utils::Point<int>> points;
protected:
    void clip(HDC hdc) override;
public:
    void onMouseLeftDown(HDC hdc, int x, int y) override;
    void onMouseRightDown(HDC hdc, int x, int y) override;
    void handleConsole(HDC hdc) override;
    ~RectangleWindowPolygonClippingArtist() = default;
};
