#ifndef LINE_ARTIST_MIDPOINT_H
#define LINE_ARTIST_MIDPOINT_H

#include "LineArtist.h"

class LineArtistMidPoint : public LineArtist
{
public:
    void draw(HDC hdc, int x1, int y1, int x2, int y2, COLORREF color);
private:
    void drawHorizontal(HDC hdc, int x1, int y1, int x2, int y2, COLORREF color, bool reverse = false);
    void drawVertical(HDC hdc, int x1, int y1, int x2, int y2, COLORREF color);
};

#endif