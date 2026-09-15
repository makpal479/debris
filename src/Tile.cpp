#include "Tile.h"

Tile::Tile(sf::Vector2f position, TileType type)
{
    main_shape.setSize(sf::Vector2f(32.f, 32.f));
    main_shape.setPosition(position);

    this->type = type;

    if (type == TileType::Grass)
    {
        texture.loadFromFile("assets/gross2.png");
    }
    else if (type == TileType::Dirt)
    {
        texture.loadFromFile("assets/Dirt.png");
    }

    main_shape.setTexture(&texture);
}

void Tile::draw(sf::RenderWindow &window)
{
    window.draw(main_shape);
}

sf::Vector2f Tile::getPosition() const
{
    return main_shape.getPosition();
}

TileType Tile::getType() const
{
    return type;
}