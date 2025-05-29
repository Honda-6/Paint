#include "Core.h"
#include "Point.h"
#include <cmath>
#include <algorithm>

class EllipseStrat
{
public:
    virtual void drawEllipse(HDC hdc, Point centre, unsigned int semiHorizontal,unsigned int semiVertical, COLORREF color) = 0;
    virtual ~EllipseStrat() = default;
};