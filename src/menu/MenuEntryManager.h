#ifndef MENU_ENTRY_MANAGER_H
#define MENU_ENTRY_MANAGER_H

#include <vector>
#include <algorithm>
#include "MenuEntry.h"

using namespace std;

class MenuEntryManager
{
public:
    void addMenuEntry(MenuEntry& menuEntry);

    void removeMenuEntry(MenuEntry& menuEntry);

    void notify();

private:
    vector<MenuEntry *> menuEntries;
};
#endif