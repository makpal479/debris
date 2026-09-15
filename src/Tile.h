#pragma once

#include <SFML/Graphics.hpp>

enum class TileType
{
    Grass,
    Dirt
};

class Tile
{
public:
    Tile(sf::Vector2f position, TileType type);

    void draw(sf::RenderWindow &window);

    sf::Vector2f getPosition() const;
    TileType getType() const;

private:
    sf::RectangleShape main_shape;
    TileType type;
    sf::Texture texture;
};