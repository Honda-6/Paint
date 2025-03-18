#pragma once

#include "Core.h"

class Artist {
protected:
    COLORREF color = RGB(0, 0, 0);

public:
    virtual void onMouseLeftDown(HDC hdc, int x, int y) { }
    virtual void onMouseLeftUp(HDC hdc, int x, int y) { } 
    virtual void onMouseRightDown(HDC hdc, int x, int y) { }
    virtual void onMouseRightUp(HDC hdc, int x, int y) { }
    virtual void handleConsole(HDC hdc) = 0;

    virtual void setColor(COLORREF color) {
        this->color = color;
    }

    virtual ~Artist() = default;
};
