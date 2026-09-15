#pragma once

#include "Item.h"
#include <unordered_map>

class Inventory
{
public:
    void addItem(ItemType type);

    int getItemCount(ItemType type) const;

private:
    std::unordered_map<ItemType, int> items;
};