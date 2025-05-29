#include "SimpleMidPointEllipseStrat.h"


void SimpleMidPointEllipseStrat::drawEllipse(HDC hdc, Point centre, unsigned int semiHorizontalLengthSquared, unsigned int semiVerticalLengthSquared, COLORREF color){
    int x = std::sqrt(semiHorizontalLengthSquared),y = 0;

    int decisionVar;
    int TWO_B_SQUARED = 2 * semiVerticalLengthSquared, TWO_A_SQUARED = 2 * semiHorizontalLengthSquared;
    int ddaDiffX = x * semiVerticalLengthSquared, ddaDiffY = 0;

    drawFourPixels(hdc,centre,x,y,color);
    while(ddaDiffX >= ddaDiffY)
    {
        decisionVar = semiVerticalLengthSquared * x * x - semiVerticalLengthSquared * x + semiVerticalLengthSquared/4 + semiHorizontalLengthSquared * y * y + TWO_A_SQUARED * y + semiHorizontalLengthSquared - semiHorizontalLengthSquared * semiVerticalLengthSquared ;
        if(decisionVar >= 0)
        {
            x--;
            ddaDiffX -= semiVerticalLengthSquared;
        }
        y++;
        ddaDiffY += semiHorizontalLengthSquared;
        drawFourPixels(hdc,centre,x,y,color);
    }

    y = std::sqrt(semiVerticalLengthSquared), x = 0;
    ddaDiffX = 0, ddaDiffY = y * semiHorizontalLengthSquared;

    while(ddaDiffY > ddaDiffX)
    {
        decisionVar = semiVerticalLengthSquared * x * x + TWO_B_SQUARED * x + semiHorizontalLengthSquared * y * y - semiHorizontalLengthSquared * y + semiHorizontalLengthSquared/4 + semiVerticalLengthSquared - semiHorizontalLengthSquared * semiVerticalLengthSquared;
        if(decisionVar >= 0)
        {
            y--;
            ddaDiffY -= semiHorizontalLengthSquared;
        }
        x++;
        ddaDiffX += semiVerticalLengthSquared;
        drawFourPixels(hdc,centre,x,y,color);
    }
}