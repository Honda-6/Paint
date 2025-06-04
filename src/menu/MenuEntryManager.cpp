#include "MenuEntryManager.h"

void MenuEntryManager::addMenuEntry(MenuEntry &menuEntry)
{
    menuEntries.push_back(&menuEntry);
}

void MenuEntryManager::removeMenuEntry(MenuEntry &menuEntry)
{
    vector<MenuEntry *>::iterator found = find(menuEntries.begin(), menuEntries.end(), &menuEntry);

    if (found != menuEntries.end())
    {
        menuEntries.erase(found);
    }
}

void MenuEntryManager::notify()
{
    for (auto entry : menuEntries)
    {
        entry->update();
    }
}
