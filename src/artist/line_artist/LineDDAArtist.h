#ifndef LINE_ARTIST_DDA_H
#define LINE_ARTIST_DDA_H

#include "LineArtist.h"

class LineDDAArtist : public LineArtist
{
public:
    void draw(HDC hdc, int x1, int y1, int x2, int y2, COLORREF color);

private:
    void drawHorizontal(HDC hdc, int x1, int y1, int x2, int y2, COLORREF color, bool invert = false);
    void drawVertical(HDC hdc, int x1, int y1, int x2, int y2, COLORREF color);
};

#endif