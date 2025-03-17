#include "PolygonValidation.h"


static int calculateCrossProduct(const utils::Point<int> &p1, const utils::Point<int> &p2, const utils::Point<int> &p3) {
    return (p2.x - p1.x) * (p3.y - p1.y) - (p2.y - p1.y) * (p3.x - p1.x);
}

static bool allPointsCollinear(const std::vector<utils::Point<int>> &points) {
        if (points.size() < 3) return true;

        int n = points.size();
        for (int i = 0; i < n; i++) {
            if (calculateCrossProduct(points[i], points[(i + 1) % n], points[(i + 2) % n]) != 0) {
                return false;
            }
        }

        return true; //No area to fill
    }

bool validPolygon(const std::vector<utils::Point<int>> &points) {
    if (points.size() < 3 || allPointsCollinear(points)) {
        return false;
    }
    return true;
}

bool isConvexPolygon(const std::vector<utils::Point<int>> &points) {

    if (!validPolygon(points))
        return false;
    int n = points.size();
    int sign = 0;
    for (int i = 0; i < n; i++) {
        int z = calculateCrossProduct(points[i], points[(i + 1) % n], points[(i + 2) % n]);
        // If z is zero >> points in the same line
        if (z != 0) {
            if (sign == 0) { //Assigning sign for the first turn
                sign = (z > 0) ? 1 : -1;
            } else if ((z > 0 && sign < 0) || (z < 0 && sign > 0)) {
                return false; //not convex
            }
        }
    }

    return true;
}
