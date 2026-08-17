#pragma once

#include <SFML/Graphics.hpp>

class Tile
{
public:
    Tile(sf::Vector2f position);

    void draw(sf::RenderWindow& window);

private:
    sf::RectangleShape main_shape;
};