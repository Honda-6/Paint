#pragma once

#include "../Core.h"

class Artist {
public:
    virtual void onMouseLeftDown(HDC hdc, int x, int y) { }
    virtual void onMouseLeftUp(HDC hdc, int x, int y) { } 
    virtual void onMouseRightDown(HDC hdc, int x, int y) { }
    virtual void onMouseRightUp(HDC hdc, int x, int y) { }
    virtual void handleConsole(HDC hdc) = 0;

    virtual ~Artist() = default;
};
