#pragma once

#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Tile.h"

class Game
{
public:
    Game();

    void run();

private:
    void processEvents();
    void update(sf::Time dTime);
    void render();
    Tile testTile;
    

private:
    sf::RenderWindow main_window;
    Player player;
    sf::Clock clock;
    sf::View camera;
};