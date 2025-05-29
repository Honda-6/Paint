#include "MidPointDDAEllipseStrat.h"

void MidPointDDAEllipseStrat::drawEllipse(HDC hdc, utils::Point centre, unsigned int semiHorizontalLengthSquared, unsigned int semiVerticalLengthSquared, COLORREF color){
    //starting from y = b and x = 0;
    int y = std::sqrt(semiVerticalLengthSquared),x = 0;

    // some constants to avoid recomputing multiplication everytime when applying bresenham's
    int TWO_B_SQUARED = 2 * semiVerticalLengthSquared, TWO_A_SQUARED = 2 * semiHorizontalLengthSquared;

    /*
        when drawing an ellipse we divide its quarter into 2 regions; one in which the absolute of the derivative is greater than one (lower section) and the other is less than one (upper section)
        the decision variable equation varies according to the region where the lower section we compute the next x value and y increases in the other hand the decision variable computes the next y value while x is incremented
    */

    /*
        since we start at y = b then we are at the upper region, we will keep on computing the prospected value of y as long as the slope is less than 1
        according to the derivative of the ellipse y`= x*(b^2)/y*(a^2) then y`< 1 then `x*(b^2) < y * (a^2)`
        x*(b^2) < y * (a^2) this condition must hold for the upper section
        since x and y change by a discrete value, I dont need to recompute the expression - multiplication - each time
        so I simply add the differences - which are constants -  to each of them shown in the ddaDiff variables till the value of one of them exceeds the other
    */
    int ddaDiffX = 0, ddaDiffY = y * semiHorizontalLengthSquared;

    // the initial value of the decision variable at x = 0 and y = b;
    int decisionVar = - semiHorizontalLengthSquared * y + semiVerticalLengthSquared + semiHorizontalLengthSquared/4;

    // applying dda to the change in the decision variable to get rid of multiplications
    // ddaChangeOne is the value added to the decision variable if there is no change in y meanwhile the other is when y is decremented
    int ddaChangeOne = 3 * semiVerticalLengthSquared, ddaChangeTwo = ddaChangeOne + TWO_A_SQUARED * (1 - y);
    utils::drawFourPixels(hdc,centre,x,y,color);
    while(ddaDiffX <= ddaDiffY)
    {
        if(decisionVar >= 0)
        {
            decisionVar += ddaChangeTwo;
            ddaChangeTwo += TWO_A_SQUARED;
            y--;
            ddaDiffY -= semiHorizontalLengthSquared;
        }
        else
        {
            decisionVar += ddaChangeOne;
        }
        ddaChangeTwo += TWO_B_SQUARED, ddaChangeOne += TWO_B_SQUARED;
        x++;
        ddaDiffX += semiVerticalLengthSquared;
        utils::drawFourPixels(hdc,centre,x,y,color);
    }


    /*
        same routine as prior but now we start at x = a and y = 0
        and recomputing the decision variable accordingly
    */
    x = std::sqrt(semiHorizontalLengthSquared), y = 0;
    utils::drawFourPixels(hdc,centre,x,y,color);

    ddaDiffX = x * semiVerticalLengthSquared, ddaDiffY = 0;
    decisionVar = - semiVerticalLengthSquared * x + semiHorizontalLengthSquared + semiVerticalLengthSquared/4;
    ddaChangeOne = 3 * semiHorizontalLengthSquared, ddaChangeTwo = ddaChangeOne + TWO_B_SQUARED * (1 - x);
    while(ddaDiffX >= ddaDiffY)
    {
        if(decisionVar >= 0)
        {
            decisionVar += ddaChangeTwo;
            ddaChangeTwo += TWO_B_SQUARED;
            x--;
            ddaDiffX -= semiVerticalLengthSquared;
        }
        else
        {
            decisionVar += ddaChangeOne;
        }
        ddaChangeOne += TWO_A_SQUARED, ddaChangeTwo += TWO_A_SQUARED;
        y++;
        ddaDiffY += semiHorizontalLengthSquared;
        utils::drawFourPixels(hdc,centre,x,y,color);
    }
}