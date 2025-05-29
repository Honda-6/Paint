#pragma once
#include <vector>

//temporarily until this structure be added to util
struct Point
{
    int x = 0, y = 0;
};

class PolygonValidation {
public:
    static bool validPolygon(const std::vector<Point>& points);
    static bool isConvexPolygon(const std::vector<Point>& points);

};



