#pragma once

#include "Artist.h"
#include "LineStrategy.h"
#include "Utils.h"
#include "CircleStrategy.h"
enum LineCircleWindowClippingState {
    LINE_CIRCLE_WINDOW_CLIPPING_STATE_CIRCLE_WINDOW,
    LINE_CIRCLE_WINDOW_CLIPPING_STATE_LINE_CLIPPING
};

class LineCircleWindowClippingArtist: public Artist {
private:
    LineCircleWindowClippingState state;
    utils::Point<double> pc, p1, p2;
    double r;

    LineStrategy *line;
    CircleStrategy *circle;


    bool clipLine();

public:
    LineCircleWindowClippingArtist();

    void onMouseLeftDown(HDC hdc, int x, int y) override;
    void onMouseLeftUp(HDC hdc, int x, int y) override;
    void handleConsole(HDC hdc) override;

    ~LineCircleWindowClippingArtist();
};
