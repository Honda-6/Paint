#pragma once

#include "Core.h"
#include "Matrix.h"
#include <cmath>

namespace utils {
    template <typename T>
    struct Point {
        T x, y;
        Point(T x = 0, T y = 0) : x(x) , y(y) {}

        T normSquared() {
            return x * x + y * y;
        }

        Point<T> operator+(const Point<T>& p) {
            Point<T> q;
            q.x = x + p.x;
            q.y = y + p.y;
            return q;
        }

        Point<T> operator-(const Point<T>& p) {
            Point<T> q;
            q.x = x - p.x;
            q.y = y - p.y;
            return q;
        }
    };

    struct Slope {
        double u, v;
        Slope() : u(0), v(0) {}
        Slope(Point<int> p1, Point<int> p2, double c) {
            u = c / 2 * (p2.x - p1.x);
            v = c / 2 * (p2.y - p1.y);
        }
    };

    template <typename T>
    static T distanceSquared(Point<T> a, Point<T> b) {
        return (b.x - a.x) * (b.x - a.x) + (b.y - a.y) * (b.y - a.y);
    }

    static void drawHermite(HDC hdc, int x1, int y1, int u1, int v1, int x2, int y2, int u2, int v2, int numpoints, COLORREF color) {
        Matrix<int, 4, 4> H({
                                    { 2,  1, -2,  1},
                                    {-3, -2,  3, -1},
                                    { 0,  1,  0,  0},
                                    { 1,  0,  0,  0},
                            });

        Matrix<int, 4, 2> g({
                                    {x1, y1},
                                    {u1, v1},
                                    {x2, y2},
                                    {u2, v2}
                            });

        Matrix<int, 4, 2> c = H * g;

        double dt = 1.0 / numpoints;
        for (double t = 0; t <= 1; t += dt) {
            double x = c(0, 0) * t * t * t + c(1, 0) * t * t + c(2, 0) * t + c(3, 0);
            double y = c(0, 1) * t * t * t + c(1, 1) * t * t + c(2, 1) * t + c(3, 1);

            SetPixel(hdc, round(x), round(y), color);
        }
    }
};
