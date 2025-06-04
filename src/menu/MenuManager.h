#include "Menu.h"
#include "Artist.h"
#include <map>

using namespace std;

class MenuManager
{
public:
    MenuManager(Artist **artist, COLORREF *color)
    {
        this->artist = artist;

        menus.insert({LPCSTR("File"), new FileMenu()});
        menus.insert({LPCSTR("Shapes"), new ShapesMenu(artist, color)});
        menus.insert({LPCSTR("Color"), new ColorMenu(artist, color)});
        menus.insert({LPCSTR("Cursor"), new CursorMenu()});
    }

    void setMenu(HWND hwnd)
    {
        HMENU mainMenu = CreateMenu();
        for (auto &menu : menus)
        {
            AppendMenu(mainMenu, MF_POPUP, (UINT_PTR)menu.second->createMenu(), menu.first);
        }

        AppendMenu(mainMenu, MF_STRING, CLEAR_SCREEN, LPCSTR("Clear"));
        AppendMenu(mainMenu, MF_STRING, CONSOLE_INPUT, LPCSTR("Console Input"));

        SetMenu(hwnd, mainMenu);
    }

    void handleInput(HWND hwnd, WPARAM wp)
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
            HDC hdc = GetDC(hwnd);
            (*(artist))->handleConsole(hdc);
        }
    }

private:
    map<LPCSTR, Menu *> menus;
    Artist **artist;
};
