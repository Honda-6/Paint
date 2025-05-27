#include "Menu.h"

HMENU CursorMenu::createMenu()
{
    HMENU cursorChangeMenu = CreateMenu();

    AppendMenu(cursorChangeMenu, MF_STRING, CURSOR_MENU_ARROW, LPCSTR("Arrow"));
    AppendMenu(cursorChangeMenu, MF_STRING, CURSOR_MENU_CROSS, LPCSTR("Cross"));
    AppendMenu(cursorChangeMenu, MF_STRING, CURSOR_MENU_WAIT, LPCSTR("Wait"));
    AppendMenu(cursorChangeMenu, MF_STRING, CURSOR_MENU_HAND, LPCSTR("Hand"));

    return cursorChangeMenu;
}

void CursorMenu::changeCursor(HWND hwnd, LPCTSTR oldCursor)
{
    HCURSOR newCursor = LoadCursor(NULL, oldCursor);
    SetClassLongPtr(hwnd, GCLP_HCURSOR, (LONG_PTR)newCursor);

    SetCursor(newCursor);
}

bool CursorMenu::handleEvent(HWND hwnd, WPARAM wp)
{
    bool matches = true;
    switch (wp)
    {
    case CURSOR_MENU_ARROW:
        changeCursor(hwnd, IDC_ARROW);
        break;
    case CURSOR_MENU_CROSS:
        changeCursor(hwnd, IDC_CROSS);
        break;
    case CURSOR_MENU_WAIT:
        changeCursor(hwnd, IDC_WAIT);
        break;
    case CURSOR_MENU_HAND:
        changeCursor(hwnd, IDC_HAND);
        break;
    default:
        matches = false;
        break;
    }
    return matches;
}
