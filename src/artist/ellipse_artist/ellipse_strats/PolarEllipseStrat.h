#include "EllipseStrat.h"

class PolarEllipseStrat: public EllipseStrat
{
public:
    void drawEllipse(HDC hdc, Point centre, unsigned int semiHorizontalLength, unsigned int semiVerticalLength, COLORREF color) override;
    ~PolarEllipseStrat() = default;
};