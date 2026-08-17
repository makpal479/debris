#include "Tile.h"

Tile::Tile(sf::Vector2f position)
{
    main_shape.setSize(sf::Vector2f(32.f, 32.f));
    main_shape.setPosition(position);
    main_shape.setFillColor(sf::Color(120, 80, 40));
}

void Tile::draw(sf::RenderWindow& window)
{
    window.draw(main_shape);
}