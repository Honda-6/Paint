#ifndef LINE_ARTIST_H
#define LINE_ARTIST_H

#include "Core.h"
#include "Artist.h"
#include <iostream>

class LineArtist : public Artist
{
public:
    void onMouseLeftDown(HDC hdc, int x, int y);
    void onMouseLeftUp(HDC hdc, int x, int y); 
    void handleConsole(HDC hdc);
    virtual void draw(HDC hdc, int x1, int y1, int x2, int y2, COLORREF color) = 0;
private:
    int x1, y1, x2, y2;
};

#endif