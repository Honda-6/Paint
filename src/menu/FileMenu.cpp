#include "Menu.h"

HMENU FileMenu::createMenu()
{
    HMENU fileMenu = CreateMenu();

    AppendMenu(fileMenu, MF_STRING, FILE_MENU_EXPORT, LPCSTR("Export"));
    AppendMenu(fileMenu, MF_STRING, FILE_MENU_IMPORT, LPCSTR("Import"));

    return fileMenu;
}

bool FileMenu::handleEvent(HWND hwnd, WPARAM wp)
{
    bool matches = true;
    switch (wp)
    {
    case FILE_MENU_EXPORT:
        break;
    case FILE_MENU_IMPORT:
        break;
    default:
        matches = false;
        break;
    }

    return matches;
}