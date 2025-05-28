#ifndef LINE_MIDPOINT_H
#define LINE_MIDPOINT_H

#include "LineStrategy.h"

class LineMidpointStrategy : public LineStrategy
{
public:
    void draw(HDC hdc, int x1, int y1, int x2, int y2, COLORREF color) override;

private:
    void drawHorizontal(HDC hdc, int x1, int y1, int x2, int y2, COLORREF color, bool reverse = false);
    void drawVertical(HDC hdc, int x1, int y1, int x2, int y2, COLORREF color);
};

#endif