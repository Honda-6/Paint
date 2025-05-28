#include "Artist.h"
#include <vector>

struct Point {
    double x, y;
    Point(int x = 0, int y = 0) : x(x) , y(y) {}
};

struct Slope {
    double u, v;
    Slope() : u(0), v(0) {}
    Slope(Point p1, Point p2, double c) {
        u = c / 2 * (p2.x - p1.x);
        v = c / 2 * (p2.y - p1.y);
    }
};

class CardinalSplineArtist : public Artist {
private:
    std::vector<Point> control_points;
    int c = 1;

    void drawCardinalSpline(HDC hdc, std::vector<Point> pts, double c ,COLORREF color);

public:
    void onMouseLeftUp(HDC hdc, int x, int y) override;
    void onMouseRightDown(HDC hdc, int x, int y) override;
    void handleConsole(HDC hdc) override;
};
