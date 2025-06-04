#ifndef LINE_ARTIST_H
#define LINE_ARTIST_H

#include "Core.h"
#include "Artist.h"
#include "LineStrategy.h"
#include <iostream>

class LineArtist : public Artist
{
public:
    LineArtist(LineStrategy *line);
    void onMouseLeftDown(HDC hdc, int x, int y);
    void onMouseLeftUp(HDC hdc, int x, int y);
    void handleConsole(HDC hdc);
    ~LineArtist(); 

private:
    int x1, y1, x2, y2;
    LineStrategy *line;
};

#endif