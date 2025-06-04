#ifndef MENU_ENTRY_H
#define MENU_ENTRY_H

#include "Core.h"

class MenuEntry
{
public:
    MenuEntry(HMENU menu);

    void update();

    void setIndex(int idx);

    friend bool operator==(const MenuEntry &menuEntry1, const MenuEntry &menuEntry2);

private:
    int index;
    HMENU menu;
    bool isDisabled;

    void enable();

    void disable();
};

#endif