#include "ColorPicker.h"

ColorPicker::ColorPicker()
{
    defaultColor = defaultColor;
}

COLORREF ColorPicker::getColor(HWND hwnd)
{
    COLORREF customColors[16] = {0};
    CHOOSECOLOR cc = {0};
    cc.lStructSize = sizeof(CHOOSECOLOR);
    cc.hwndOwner = hwnd;
    cc.lpCustColors = customColors;
    cc.rgbResult = getCurrentScreenColor(hwnd);
    cc.Flags = CC_FULLOPEN | CC_RGBINIT;

    if (ChooseColor(&cc))
    {
        return cc.rgbResult;
    }

    return cc.rgbResult;
}

COLORREF ColorPicker::getCurrentScreenColor(HWND hwnd)
{
    HDC hdc = GetDC(hwnd);

    return GetPixel(hdc, 0, 0);
}