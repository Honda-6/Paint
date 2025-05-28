#ifndef LINE_ARTIST_PARAMETRIC_H
#define LINE_ARTIST_PARAMETRIC_H

#include "LineArtist.h"

class LineParametricArtist : public LineArtist
{
public:
    void draw(HDC hdc, int x1, int y1, int x2, int y2, COLORREF color);
};

#endif