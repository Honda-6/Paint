#ifndef LINE_DDA_H
#define LINE_DDA_H

#include "LineStrategy.h"

class LineDDAStrategy : public LineStrategy
{
public:
    void draw(HDC hdc, int x1, int y1, int x2, int y2, COLORREF color) override;

private:
    void drawHorizontal(HDC hdc, int x1, int y1, int x2, int y2, COLORREF color, bool reverse = false);
    void drawVertical(HDC hdc, int x1, int y1, int x2, int y2, COLORREF color);
};

#endif