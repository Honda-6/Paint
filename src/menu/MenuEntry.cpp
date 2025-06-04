#include "MenuEntry.h"

MenuEntry::MenuEntry(HMENU menu)
{
    this->menu = menu;
    isDisabled = false;
}

void MenuEntry::update()
{
    if (isDisabled)
    {
        isDisabled = false;
        enable();
        return;
    }

    isDisabled = true;
    disable();
}

void MenuEntry::setIndex(int idx)
{
    index = idx;
}
void MenuEntry::enable()
{
    EnableMenuItem(menu, index, MF_BYPOSITION | MF_ENABLED);
}

void MenuEntry::disable()
{
    EnableMenuItem(menu, index, MF_BYPOSITION | MF_GRAYED);
}

bool operator==(const MenuEntry &menuEntry1, const MenuEntry &menuEntry2)
{
    return menuEntry1.index == menuEntry2.index;
}
