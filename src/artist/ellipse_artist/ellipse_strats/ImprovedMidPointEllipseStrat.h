#include "EllipseStrat.h"

class  ImprovedMidPointEllipseStrat: public EllipseStrat
{
public:
    void drawEllipse(HDC hdc, Point centre, unsigned int semiHorizontalLengthSquared, unsigned int semiVerticalLengthSquared, COLORREF color) override;
    ~ImprovedMidPointEllipseStrat() = default;
};