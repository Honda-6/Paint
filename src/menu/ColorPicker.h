#include "Core.h"

class ColorPicker
{
public:
    COLORREF getColor(HWND hwnd);

private:
    COLORREF currentScreenColor = RGB(255, 255, 255);
    COLORREF getCurrentScreenColor();
};
