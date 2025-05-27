#include "Core.h"

class ColorPicker
{
public:
    ColorPicker();

    COLORREF getColor(HWND hwnd);

private:
    COLORREF defaultColor;
    COLORREF getCurrentScreenColor(HWND hwnd);
};
