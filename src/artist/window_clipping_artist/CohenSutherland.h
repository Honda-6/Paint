#include "Core.h"
#include "Utils.h"
#include "LineMidpointStrategy.h"

typedef union {
    struct {
        unsigned char left : 1,  right : 1,  top: 1,  bottom: 1;
    };
    unsigned char code : 4;
}regionCode;

typedef utils::Point Line[2];

void initializeRegionCode(const utils::Point &p, const int &xLeft, const int &xRight, const int &yBottom,const int &yUp,regionCode &code);
utils::Point verticalIntersection(const utils::Point& p1, const utils::Point& p2, int X);
utils::Point horizontalIntersection(const utils::Point& p1, const utils::Point& p2, int Y);
void clipLine(HDC hdc, const utils::Point &p1, const utils::Point &p2, const int &xLeft, const int &xRight, const int &yBottom, const int &yTop);
void clipPoint(HDC hdc, const utils::Point &p1, const utils::Point &p2, const int &xLeft, const int &xRight, const int &yBottom, const int &yTop);