#include "Inventory.h"

void Inventory::addItem(ItemType type)
{
    ++items[type];
}

int Inventory::getItemCount(ItemType type) const
{
    auto it = items.find(type);

    if (it != items.end())
    {
        return it->second;
    }

    return 0;
}