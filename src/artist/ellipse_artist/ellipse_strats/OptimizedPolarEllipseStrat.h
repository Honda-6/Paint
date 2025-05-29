#include "EllipseStrat.h"

class OptimizedPolarEllipseStrat: public EllipseStrat
{
public:
    void drawEllipse(HDC hdc, Point centre, unsigned int semiHorizontalLength, unsigned int semiVerticalLength, COLORREF color) override;
    ~OptimizedPolarEllipseStrat() = default; 
};