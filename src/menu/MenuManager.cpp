#include "MenuManager.h"

MenuManager::MenuManager(Artist **artist, FileManager *fileManager, COLORREF *color)
{
    this->artist = artist;

    menus.insert({LPCSTR("File"), new FileMenu(fileManager)});
    menus.insert({LPCSTR("Shapes"), new ShapesMenu(artist, color)});
    menus.insert({LPCSTR("Color"), new ColorMenu(artist, color)});
    menus.insert({LPCSTR("Cursor"), new CursorMenu()});
}

void MenuManager::setMenu(HWND hwnd)
{
    mainMenu = CreateMenu();

    shapesEntry = MenuEntry(mainMenu);
    consoleEntry = MenuEntry(mainMenu);

    for (auto &menu : menus)
    {
        AppendMenu(mainMenu, MF_POPUP, (UINT_PTR)menu.second->createMenu(), menu.first);
        if (menu.first == LPCSTR("Shapes"))
        {
            shapesEntry.setIndex(GetMenuItemCount(mainMenu) - 1);
        }
    }

    AppendMenu(mainMenu, MF_STRING, CLEAR_SCREEN, LPCSTR("Clear"));

    AppendMenu(mainMenu, MF_STRING, CONSOLE_INPUT, LPCSTR("Console Input"));
    consoleEntry.setIndex(GetMenuItemCount(mainMenu) - 1);

    menuEntryManager.addMenuEntry(shapesEntry);
    menuEntryManager.addMenuEntry(consoleEntry);

    SetMenu(hwnd, mainMenu);
}

void MenuManager::handleInput(HWND hwnd, WPARAM wp)
{
    for (auto &menu : menus)
    {
        if (menu.second->handleEvent(hwnd, wp))
        {
            break;
        }
    }
    if (wp == CLEAR_SCREEN)
    {
        InvalidateRect(hwnd, NULL, TRUE);
    }
    else if (wp == CONSOLE_INPUT)
    {
        menuEntryManager.notify();

        input = thread(handleConsole, this, hwnd);

        input.detach();
    }
}

void MenuManager::handleConsole(HWND hwnd)
{
    HDC hdc = GetDC(hwnd);

    (*(artist))->handleConsole(hdc);

    menuEntryManager.notify();

    ReleaseDC(hwnd, hdc);
}