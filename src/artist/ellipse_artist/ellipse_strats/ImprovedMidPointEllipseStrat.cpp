#include "ImprovedMidPointEllipseStrat.h"

void ImprovedMidPointEllipseStrat::drawEllipse(HDC hdc, const utils::Point<int> &centre, unsigned int semiHorizontalLengthSquared, unsigned int semiVerticalLengthSquared, COLORREF color){
    int y = std::sqrt(semiVerticalLengthSquared),x = 0;
    int TWO_B_SQUARED = 2 * semiVerticalLengthSquared, TWO_A_SQUARED = 2 * semiHorizontalLengthSquared;

    int ddaDiffX = 0, ddaDiffY = y * semiHorizontalLengthSquared;
    int decisionVar = - semiHorizontalLengthSquared * y + semiVerticalLengthSquared + semiHorizontalLengthSquared/4;
    utils::drawFourPixels(hdc,centre,x,y,color);
    while(ddaDiffX < ddaDiffY)
    {
        if(decisionVar >= 0)
        {
            decisionVar += TWO_A_SQUARED * (1 - y);
            y--;
            ddaDiffY -= semiHorizontalLengthSquared;
        }
        decisionVar += semiVerticalLengthSquared * (2*x + 3);
        x++;
        ddaDiffX += semiVerticalLengthSquared;
        utils::drawFourPixels(hdc,centre,x,y,color);
    }

    x = std::sqrt(semiHorizontalLengthSquared), y = 0;
    utils::drawFourPixels(hdc,centre,x,y,color);

    ddaDiffX = (x+1) * semiVerticalLengthSquared, ddaDiffY = 0;
    decisionVar = - semiVerticalLengthSquared * x + semiHorizontalLengthSquared + semiVerticalLengthSquared/4;
    while(ddaDiffX > ddaDiffY)
    {
        if(decisionVar >= 0)
        {
            decisionVar += TWO_B_SQUARED * (1 - x);
            x--;
            ddaDiffX -= semiVerticalLengthSquared;
        }
        decisionVar += semiHorizontalLengthSquared * (2*y + 3);
        y++;
        ddaDiffY += semiHorizontalLengthSquared;
        utils::drawFourPixels(hdc,centre,x,y,color);
    }
}