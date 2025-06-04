#include "Utils.h"
#include <vector>

namespace sutherlandHodgman
{
    void clipPolygon(HDC hdc, std::vector<utils::Point<int>> &p, const int &xLeft, const int &xRight, const int &yBottom, const int &yTop, COLORREF polygonColor, COLORREF clipColor);
}

