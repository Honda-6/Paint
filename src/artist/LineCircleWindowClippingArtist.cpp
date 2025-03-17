#include "LineCircleWindowClippingArtist.h"
#include "LineMidpointStrategy.h"
// #include "CircleMidpointStrategy.h"
#include "Palette.h"
#include <iostream>

using namespace std;

LineCircleWindowClippingArtist::LineCircleWindowClippingArtist() {
    state = LINE_CIRCLE_WINDOW_CLIPPING_STATE_CIRCLE_WINDOW;
    line = new LineMidpointStrategy();
    // circle = new CircleMidpointStrategy();
}

LineCircleWindowClippingArtist::~LineCircleWindowClippingArtist() {
    delete line;
    // delete circle;
}

void LineCircleWindowClippingArtist::onMouseLeftDown(HDC hdc, int x, int y) {
    if (state == LINE_CIRCLE_WINDOW_CLIPPING_STATE_CIRCLE_WINDOW) {
        pc.x = x;
        pc.y = y;
    } else {
        p1.x = x;
        p1.y = y;
    }
}

void LineCircleWindowClippingArtist::onMouseLeftUp(HDC hdc, int x, int y) {
    p2.x = x;
    p2.y = y;

    if (state == LINE_CIRCLE_WINDOW_CLIPPING_STATE_CIRCLE_WINDOW) {
        r = sqrt(utils::distanceSquared(pc, p2));

        // TODO: Remove drawCircle and use CircleStrategy once implemented.
        utils::drawCircle(hdc, pc.x, pc.y, r, COLOR_CRIMSON_RED);
        // circle->draw(hdc, pc.x, pc.y, r, COLOR_CRIMSON_RED);
        state = LINE_CIRCLE_WINDOW_CLIPPING_STATE_LINE_CLIPPING;
    } else {
        line->draw(hdc, round(p1.x), round(p1.y), round(p2.x), round(p2.y), COLOR_LIGHT_GRAY);
        
        if (clipLine()) {
            line->draw(hdc, round(p1.x), round(p1.y), round(p2.x), round(p2.y), COLOR_BLACK);
        }
    }
}

void LineCircleWindowClippingArtist::handleConsole(HDC hdc) {
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
        cout << "Enter line first point's x: ";
        cin >> p1.x;

        cout << "Enter line first point's y: ";
        cin >> p1.y;

        cout << "Enter line second point's x: ";
        cin >> p2.x;

        cout << "Enter line second point's y: ";
        cin >> p2.y;

        line->draw(hdc, round(p1.x), round(p1.y), round(p2.x), round(p2.y), COLOR_LIGHT_GRAY);
        
        if (clipLine()) {
            line->draw(hdc, round(p1.x), round(p1.y), round(p2.x), round(p2.y), COLOR_BLACK);
        }

        char answer;
        cout << "Do you want to add more lines? (Y/n) ";
        cin >> answer;
        
        shouldInputLine = tolower(answer) != 'n';
    }
}

bool LineCircleWindowClippingArtist::clipLine() {
    // Make coordinate system such that the circle is at (0, 0) to simplify equations.
    p1 = p1 - pc;
    p2 = p2 - pc;

    if (p1.x > p2.x) {
        swap(p1, p2);
    }

    double r2 = r * r;
    double norm1 = p1.normSquared();
    double norm2 = p2.normSquared();

    if (norm1 <= r2 && norm2 <= r2) {
        // Undo coordinate system transformation.
        p1 = p1 + pc;
        p2 = p2 + pc;
        return true;
    }

    if (p1.x == p2.x) {
        if (abs(p1.x) > r) {
            return false;
        }

        if (p1.y > p2.y) {
            swap(p1, p2);
            swap(norm1, norm2);
        }

        double y = sqrt(r2 - p1.x * p1.x);
        
        if (norm1 > r2) {
            p1.y = -y;
        }

        if (norm2 > r2) {
            p2.y = y;
        }
    } else {
        double m = (p1.y - p2.y) / (p1.x - p2.x);

        // Quadratic parameters
        double a = m * m + 1;
        double b = -2 * m * m * p1.x + 2 * p1.y * m;
        double c = m * m * p1.x * p1.x + p1.y * p1.y - 2 * p1.y * p1.x * m - r2;

        if (!utils::hasQuadraticRoots(a, b, c)) {
            return false;
        }

        if (norm1 > r2) {
            double x = utils::quadraticRoot(a, b, c, -1);
            double y = m * (x - p1.x) + p1.y;
            p1.x = x;
            p1.y = y;
        }

        if (norm2 > r2) {
            double x = utils::quadraticRoot(a, b, c, 1);
            double y = m * (x - p1.x) + p1.y;
            p2.x = x;
            p2.y = y;
        }
    }

    // Undo coordinate system transformation.
    p1 = p1 + pc;
    p2 = p2 + pc;
    return true;
}
