#include "PointCircleWindowClippingArtist.h"
#include "Palette.h"
#include <iostream>

using namespace std;

PointCircleWindowClippingArtist::PointCircleWindowClippingArtist() {
    state = POINT_CIRCLE_WINDOW_CLIPPING_STATE_CIRCLE_WINDOW;
}

void PointCircleWindowClippingArtist::onMouseLeftDown(HDC hdc, int x, int y) {
    if (state == POINT_CIRCLE_WINDOW_CLIPPING_STATE_CIRCLE_WINDOW) {
        pc.x = x;
        pc.y = y;
    }
}

void PointCircleWindowClippingArtist::onMouseLeftUp(HDC hdc, int x, int y) {
    utils::Point<double> p(x, y);

    if (state == POINT_CIRCLE_WINDOW_CLIPPING_STATE_CIRCLE_WINDOW) {
        r = sqrt(utils::distanceSquared(pc, p));

        // TODO: Remove drawCircle and use CircleStrategy once implemented.
        utils::drawCircle(hdc, pc.x, pc.y, r, COLOR_CRIMSON_RED);
        // circle->draw(hdc, pc.x, pc.y, r, COLOR_CRIMSON_RED);
        state = POINT_CIRCLE_WINDOW_CLIPPING_STATE_POINT_CLIPPING;
    } else {
        if (clipPoint(p)) {
            SetPixel(hdc, round(p.x), round(p.y), color);
        } else {
            SetPixel(hdc, round(p.x), round(p.y), COLOR_LIGHT_GRAY);
        }
    }
}

void PointCircleWindowClippingArtist::handleConsole(HDC hdc) {
    pc.x = pc.y = r = -1;

    while (r <= 0 || pc.x < 0 || pc.y < 0) {
        cout << "Enter window (circle) center xc, yc, and radius: ";
        cin >> pc.x >> pc.y >> r;
    }

    // TODO: Remove drawCircle and use CircleStrategy once implemented.
    utils::drawCircle(hdc, pc.x, pc.y, r, COLOR_CRIMSON_RED);
    // circle->draw(hdc, pc.x, pc.y, r, COLOR_CRIMSON_RED);

    bool shouldInputLine = true;
    while (shouldInputLine) {
        utils::Point<double> p;

        cout << "Enter point's x: ";
        cin >> p.x;

        cout << "Enter point's y: ";
        cin >> p.y;

        if (clipPoint(p)) {
            SetPixel(hdc, round(p.x), round(p.y), color);
        } else {
            SetPixel(hdc, round(p.x), round(p.y), COLOR_LIGHT_GRAY);
        }

        char answer;
        cout << "Do you want to add more points? (Y/n) ";
        cin >> answer;
        
        shouldInputLine = tolower(answer) != 'n';
    }
}

bool PointCircleWindowClippingArtist::clipPoint(utils::Point<double> p) {
    double r2 = r * r;
    
    return utils::distanceSquared(pc, p) <= r2;
}
