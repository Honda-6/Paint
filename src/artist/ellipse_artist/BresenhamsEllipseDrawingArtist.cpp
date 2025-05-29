#include "BresenhamsEllipseDrawingArtist.h"



/* void BresenhamsEllipseDrawingArtist::drawEllipse(HDC hdc, COLORREF color)       // ->>>> using decision variable directly
{
    int x = std::sqrt(this->semiHorizontalLengthSquared),y = 0;

    int decisionVar;
    int TWO_B_SQUARED = 2 * this->semiVerticalLengthSquared, TWO_A_SQUARED = 2 * this->semiHorizontalLengthSquared;
    int ddaDiffX = x * this->semiVerticalLengthSquared, ddaDiffY = 0;

    drawFourPixels(hdc,this->centre,x,y,color);
    while(ddaDiffX >= ddaDiffY)
    {
        decisionVar = this->semiVerticalLengthSquared * x * x - this->semiVerticalLengthSquared * x + this->semiVerticalLengthSquared/4 + this->semiHorizontalLengthSquared * y * y + TWO_A_SQUARED * y + this->semiHorizontalLengthSquared - this->semiHorizontalLengthSquared * this->semiVerticalLengthSquared ;
        if(decisionVar >= 0)
        {
            x--;
            ddaDiffX -= this->semiVerticalLengthSquared;
        }
        y++;
        ddaDiffY += this->semiHorizontalLengthSquared;
        drawFourPixels(hdc,this->centre,x,y,color);
    }

    y = std::sqrt(this->semiVerticalLengthSquared), x = 0;
    ddaDiffX = 0, ddaDiffY = y * this->semiHorizontalLengthSquared;

    while(ddaDiffY > ddaDiffX)
    {
        decisionVar = this->semiVerticalLengthSquared * x * x + TWO_B_SQUARED * x + this->semiHorizontalLengthSquared * y * y - this->semiHorizontalLengthSquared * y + this->semiHorizontalLengthSquared/4 + this->semiVerticalLengthSquared - this->semiHorizontalLengthSquared * this->semiVerticalLengthSquared;
        if(decisionVar >= 0)
        {
            y--;
            ddaDiffY -= this->semiHorizontalLengthSquared;
        }
        x++;
        ddaDiffX += this->semiVerticalLengthSquared;
        drawFourPixels(hdc,this->centre,x,y,color);
    }
} */

/* void BresenhamsEllipseDrawingArtist::drawEllipse(HDC hdc, COLORREF color)       //-->>>>>> applying dda to the decision variable (more optimized)
{
    int y = std::sqrt(this->semiVerticalLengthSquared),x = 0;
    int TWO_B_SQUARED = 2 * this->semiVerticalLengthSquared, TWO_A_SQUARED = 2 * this->semiHorizontalLengthSquared;

    int ddaDiffX = 0, ddaDiffY = y * this->semiHorizontalLengthSquared;
    int decisionVar = - this->semiHorizontalLengthSquared * y + this->semiVerticalLengthSquared + this->semiHorizontalLengthSquared/4;
    drawFourPixels(hdc,this->centre,x,y,color);
    while(ddaDiffX <= ddaDiffY)
    {
        if(decisionVar >= 0)
        {
            decisionVar += TWO_A_SQUARED * (1 - y);
            y--;
            ddaDiffY -= this->semiHorizontalLengthSquared;
        }
        decisionVar += this->semiVerticalLengthSquared * (2*x + 3);
        x++;
        ddaDiffX += this->semiVerticalLengthSquared;
        drawFourPixels(hdc,this->centre,x,y,color);
    }

    x = std::sqrt(this->semiHorizontalLengthSquared), y = 0;
    drawFourPixels(hdc,this->centre,x,y,color);

    ddaDiffX = (x+1) * this->semiVerticalLengthSquared, ddaDiffY = 0;
    decisionVar = - this->semiVerticalLengthSquared * x + this->semiHorizontalLengthSquared + this->semiVerticalLengthSquared/4;
    while(ddaDiffX >= ddaDiffY)
    {
        if(decisionVar >= 0)
        {
            decisionVar += TWO_B_SQUARED * (1 - x);
            x--;
            ddaDiffX -= this->semiVerticalLengthSquared;
        }
        decisionVar += this->semiHorizontalLengthSquared * (2*y + 3);
        y++;
        ddaDiffY += this->semiHorizontalLengthSquared;
        drawFourPixels(hdc,this->centre,x,y,color);
    }
} */

void BresenhamsEllipseDrawingArtist::drawEllipse(HDC hdc, COLORREF color)   // =====>>>>>>>>> getting rid of multiplication and applying dda to the change of the decision variable
{
    //starting from y = b and x = 0;
    int y = std::sqrt(this->semiVerticalLengthSquared),x = 0;

    // some constants to avoid recomputing multiplication everytime when applying bresenham's
    int TWO_B_SQUARED = 2 * this->semiVerticalLengthSquared, TWO_A_SQUARED = 2 * this->semiHorizontalLengthSquared;

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
    int ddaDiffX = 0, ddaDiffY = y * this->semiHorizontalLengthSquared;

    // the initial value of the decision variable at x = 0 and y = b;
    int decisionVar = - this->semiHorizontalLengthSquared * y + this->semiVerticalLengthSquared + this->semiHorizontalLengthSquared/4;

    // applying dda to the change in the decision variable to get rid of multiplications
    // ddaChangeOne is the value added to the decision variable if there is no change in y meanwhile the other is when y is decremented
    int ddaChangeOne = 3 * this->semiVerticalLengthSquared, ddaChangeTwo = ddaChangeOne + TWO_A_SQUARED * (1 - y);
    drawFourPixels(hdc,this->centre,x,y,color);
    while(ddaDiffX <= ddaDiffY)
    {
        if(decisionVar >= 0)
        {
            decisionVar += ddaChangeTwo;
            ddaChangeTwo += TWO_A_SQUARED;
            y--;
            ddaDiffY -= this->semiHorizontalLengthSquared;
        }
        else
        {
            decisionVar += ddaChangeOne;
        }
        ddaChangeTwo += TWO_B_SQUARED, ddaChangeOne += TWO_B_SQUARED;
        x++;
        ddaDiffX += this->semiVerticalLengthSquared;
        drawFourPixels(hdc,this->centre,x,y,color);
    }


    /*
        same routine as prior but now we start at x = a and y = 0
        and recomputing the decision variable accordingly
    */
    x = std::sqrt(this->semiHorizontalLengthSquared), y = 0;
    drawFourPixels(hdc,this->centre,x,y,color);

    ddaDiffX = x * this->semiVerticalLengthSquared, ddaDiffY = 0;
    decisionVar = - this->semiVerticalLengthSquared * x + this->semiHorizontalLengthSquared + this->semiVerticalLengthSquared/4;
    ddaChangeOne = 3 * this->semiHorizontalLengthSquared, ddaChangeTwo = ddaChangeOne + TWO_B_SQUARED * (1 - x);
    while(ddaDiffX >= ddaDiffY)
    {
        if(decisionVar >= 0)
        {
            decisionVar += ddaChangeTwo;
            ddaChangeTwo += TWO_B_SQUARED;
            x--;
            ddaDiffX -= this->semiVerticalLengthSquared;
        }
        else
        {
            decisionVar += ddaChangeOne;
        }
        ddaChangeOne += TWO_A_SQUARED, ddaChangeTwo += TWO_A_SQUARED;
        y++;
        ddaDiffY += this->semiHorizontalLengthSquared;
        drawFourPixels(hdc,this->centre,x,y,color);
    }
}