#include "Menu.h"
#include "artist/Artist.h"
#include "artist/HermiteSquareFillArtist.h"
#include <map>

using namespace std;

class MenuManager
{
public:
    MenuManager(Artist **artist, FileManager *fileManager, COLORREF *color)
    {
        menus.insert({LPCSTR("File"), new FileMenu(fileManager)});
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
    }

private:
    map<LPCSTR, Menu *> menus;
};
