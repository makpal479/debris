#pragma once

#include <SFML/Graphics.hpp>
#include "Player.h"
#include "World.h"
#include "Inventory.h"
#include "InventoryUI.h"

class Game
{
public:
    Game();

    void run();

private:
    void processEvents();
    void update(sf::Time dTime);
    void render();

private:
    sf::RenderWindow main_window;
    Player player;
    World world;
    sf::Clock clock;
    sf::View camera;
    Inventory inventory;
    InventoryUI inventoryUI;
    
};