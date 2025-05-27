#include "Menu.h"

HMENU ColorMenu::createMenu()
{
    HMENU colorMenu = CreateMenu();

    AppendMenu(colorMenu, MF_STRING, COLOR_MENU_BACKGROUND, LPCSTR("Background"));
    AppendMenu(colorMenu, MF_STRING, COLOR_MENU_SHAPE, LPCSTR("Shape"));

    return colorMenu;
}

bool ColorMenu::handleEvent(HWND hwnd, WPARAM wp)
{
    bool matches = true;
    switch (wp)
    {
    case COLOR_MENU_BACKGROUND:
        changeBackgroundColor(hwnd, colorPicker.getColor(hwnd));
        break;
    case COLOR_MENU_SHAPE:
        colorPicker.getColor(hwnd);
        break;
    default:
        matches = false;
        break;
    }
    return matches;
}

void ColorMenu::changeBackgroundColor(HWND hwnd, COLORREF color)
{
    HBRUSH hBrush = CreateSolidBrush(color);

    SetClassLongPtr(hwnd, GCLP_HBRBACKGROUND, (LONG_PTR)hBrush);

    InvalidateRect(hwnd, NULL, TRUE);
}