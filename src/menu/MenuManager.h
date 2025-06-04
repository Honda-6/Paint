#include "Menu.h"
#include "Artist.h"
#include <thread>
#include "MenuEntry.h"
#include "MenuEntryManager.h"
#include <map>

using namespace std;

class MenuManager
{
public:
    MenuManager(Artist **artist, COLORREF *color);

    void setMenu(HWND hwnd);

    void handleInput(HWND hwnd, WPARAM wp);

private:
    map<LPCSTR, Menu *> menus;
    thread input;
    HMENU mainMenu;
    MenuEntry shapesEntry{nullptr}; 
    MenuEntry consoleEntry{nullptr};
    MenuEntryManager menuEntryManager;

    Artist **artist;

    void handleConsole(HWND hwnd);
};
