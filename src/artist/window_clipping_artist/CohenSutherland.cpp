#include "CohenSutherland.h"


void initializeRegionCode(const utils::Point &p, const int &xLeft, const int &xRight, const int &yBottom,const int &yTop,regionCode &code)
{
    code.code = 0; // Reset the codes
    if(p.x < xLeft)
        code.left = 1;
    else if(p.x > xRight)
        code.right = 1;
    if(p.y < yTop)
        code.top = 1;
    else if(p.y > yBottom)
        code.bottom = 1;
}

utils::Point verticalIntersection(const utils::Point &p1, const utils::Point &p2, int X) {
    return {X, (X - p1.x)*(p2.y - p1.y)/(p2.x - p1.x) + p1.y};
}
utils::Point horizontalIntersection(const utils::Point &p1, const utils::Point &p2, int Y) {
    return {(p2.x - p1.x)*(Y - p1.y)/(p2.y - p1.y) + p1.x, Y};
}


void clipLine(HDC hdc, const utils::Point &p1, const utils::Point &p2, const int &xLeft, const int &xRight, const int &yBottom, const int &yTop)
{
    regionCode p1Code{}, p2Code{};
    initializeRegionCode(p1, xLeft, xRight, yBottom, yTop, p1Code);
    initializeRegionCode(p2, xLeft, xRight, yBottom, yTop, p2Code);

    bool accept = false;
    Line clippedLine = {p1, p2};
    while (true)
    {
        if (p1Code.code & p2Code.code)
            break;
        if (!(p1Code.code | p2Code.code))
        {
            accept = true;
            break;
        }
        // At least one point is outside the clipping window
        regionCode outCode = (p1Code.code) ? p1Code : p2Code;
        utils::Point intersection;

        if (outCode.left)
            intersection = verticalIntersection(p1, p2, xLeft);
        else if (outCode.right) 
            intersection = verticalIntersection(p1, p2, xRight);
        else if (outCode.top)
            intersection = horizontalIntersection(p1, p2, yTop);
        else if (outCode.bottom)
            intersection = horizontalIntersection(p1, p2, yBottom);  

        if (outCode.code == p1Code.code)
        {
            clippedLine[0] = intersection;
            initializeRegionCode(intersection,xLeft, xRight, yBottom, yTop, p1Code);
        }
        else
        {
            clippedLine[1] = intersection;
            initializeRegionCode(intersection,xLeft, xRight, yBottom, yTop, p2Code);
        }
    }
    LineMidpointStrategy lineStrategy;
    if (accept)
    {
        lineStrategy.draw(hdc,p1.x, p1.y, clippedLine[0].x, clippedLine[0].y, RGB(255, 10, 10));
        lineStrategy.draw(hdc, clippedLine[0].x, clippedLine[0].y, clippedLine[1].x, clippedLine[1].y, RGB(0, 255, 0));
        lineStrategy.draw(hdc,clippedLine[1].x, clippedLine[1].y, p2.x, p2.y, RGB(255, 10, 10));        
    }
    else
        lineStrategy.draw(hdc, p1.x, p1.y, p2.x, p2.y, RGB(255, 0, 0));
    
}

void clipPoint(HDC hdc, const utils::Point &p, const int &xLeft, const int &xRight, const int &yBottom, const int &yTop) {
    if(p.x >= xLeft && p.x <= xRight && p.y >= yTop, p.y <= yBottom)
        SetPixel(hdc,p.x,p.y,RGB(0,0,0));
    else
        SetPixel(hdc,p.x,p.y,RGB(100,100,100));
}