#pragma once

#include "Artist.h"
#include "LineStrategy.h"
#include "Utils.h"
#include "CircleStrategy.h"

enum PointCircleWindowClippingState {
    POINT_CIRCLE_WINDOW_CLIPPING_STATE_CIRCLE_WINDOW,
    POINT_CIRCLE_WINDOW_CLIPPING_STATE_POINT_CLIPPING
};

class PointCircleWindowClippingArtist: public Artist {
private:
    PointCircleWindowClippingState state;
    utils::Point<double> pc;
    double r;
    CircleStrategy *circle;

    bool clipPoint(utils::Point<double> p);

public:
    PointCircleWindowClippingArtist();
    ~PointCircleWindowClippingArtist();
    void onMouseLeftDown(HDC hdc, int x, int y) override;
    void onMouseLeftUp(HDC hdc, int x, int y) override;
    void handleConsole(HDC hdc) override;
};
