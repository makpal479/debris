#pragma once

#include <SFML/Graphics.hpp>
#include "Inventory.h"

class InventoryUI
{
public:
    InventoryUI();

    void draw(
        sf::RenderWindow& window,
        const Inventory& inventory
    );

private:
    sf::Texture slotTexture;
    sf::Texture woodTexture;
};