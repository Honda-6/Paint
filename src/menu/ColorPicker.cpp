#include "ColorPicker.h"

COLORREF ColorPicker::getColor(HWND hwnd)
{
    COLORREF customColors[16] = {0};
    CHOOSECOLOR cc = {0};
    cc.lStructSize = sizeof(CHOOSECOLOR);
    cc.hwndOwner = hwnd;
    cc.lpCustColors = customColors;
    cc.rgbResult = getCurrentScreenColor();
    cc.Flags = CC_FULLOPEN | CC_RGBINIT;

    ChooseColor(&cc);

    currentScreenColor = cc.rgbResult;

    return cc.rgbResult;
}

COLORREF ColorPicker::getCurrentScreenColor()
{
    return currentScreenColor;
}