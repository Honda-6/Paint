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

        Point<T> operator+(const Point<T>& p) const {
            Point<T> q;
            q.x = x + p.x;
            q.y = y + p.y;
            return q;
        }

        Point<T> operator-(const Point<T>& p) const {
            Point<T> q;
            q.x = x - p.x;
            q.y = y - p.y;
            return q;
        }
    };

    struct Slope
    {
        double u, v;
        Slope() : u(0), v(0) {}
        Slope(const Point<int>& p1, const Point<int>& p2, double c) {
            u = c / 2 * (p2.x - p1.x);
            v = c / 2 * (p2.y - p1.y);
        }
    };
    template <typename T>
    using Line = Point<T>[2];

    template <typename T>
    static T distanceSquared(const Point<T>& a, const Point<T>& b) {
        return (b.x - a.x) * (b.x - a.x) + (b.y - a.y) * (b.y - a.y);
    }
    static Point<int> verticalIntersection(const Point<int> &p1, const Point<int> &p2, int X)
    {
        return {X, (X - p1.x) * (p2.y - p1.y) / (p2.x - p1.x) + p1.y};
    }
    static Point<int>horizontalIntersection(const Point<int> &p1, const Point<int> &p2, int Y)
    {
        return {(p2.x - p1.x) * (Y - p1.y) / (p2.y - p1.y) + p1.x, Y};
    }
    static void drawHermite(HDC hdc, int x1, int y1, int u1, int v1, int x2, int y2, int u2, int v2, int numpoints, COLORREF color)
    {
        Matrix<int, 4, 4> H({
            {2, 1, -2, 1},
            {-3, -2, 3, -1},
            {0, 1, 0, 0},
            {1, 0, 0, 0},
        });

        Matrix<int, 4, 2> g({{x1, y1},
                             {u1, v1},
                             {x2, y2},
                             {u2, v2}});

        Matrix<int, 4, 2> c = H * g;

        double dt = 1.0 / numpoints;
        for (double t = 0; t <= 1; t += dt)
        {
            double x = c(0, 0) * t * t * t + c(1, 0) * t * t + c(2, 0) * t + c(3, 0);
            double y = c(0, 1) * t * t * t + c(1, 1) * t * t + c(2, 1) * t + c(3, 1);

            SetPixel(hdc, round(x), round(y), color);
        }
    }

    static bool hasQuadraticRoots(double a, double b, double c) {
        return b * b >= 4 * a * c;
    }

    static double quadraticRoot(double a, double b, double c, int sign) {
        return (-b + sign * sqrt(b * b - 4 * a * c)) / (2 * a);
    }

    static void draw8Points(HDC hdc, int xc, int yc, int a, int b, COLORREF c) {
        SetPixel(hdc, xc + a, yc + b, c);
        SetPixel(hdc, xc - a, yc + b, c);
        SetPixel(hdc, xc + a, yc - b, c);
        SetPixel(hdc, xc - a, yc - b, c);
        SetPixel(hdc, xc + b, yc + a, c);
        SetPixel(hdc, xc - b, yc + a, c);
        SetPixel(hdc, xc + b, yc - a, c);
        SetPixel(hdc, xc - b, yc - a, c);
    }

    // TODO: REMOVE ME
    static void drawCircle(HDC hdc, int xc, int yc, int R, COLORREF c) {
        int x = 0;
        int y = R;
        int d = 1 - R;
        int dd1 = 3;
        int dd2 = 5 - 2 * R;
        
        draw8Points(hdc, xc, yc, x, y, c);

        while (x <= y) {
            if (d > 0) {
                d += dd2;
                dd2 += 4;
                y--;
            } else {
                d += dd1;
                dd2 += 2;
            }

            dd1 += 2;

            x++;
            draw8Points(hdc, xc, yc, x, y, c);
        }
    }
};
