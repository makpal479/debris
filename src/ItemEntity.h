#pragma once

#include <SFML/Graphics.hpp>
#include "Item.h"

class ItemEntity
{
public:
    ItemEntity(sf::Vector2f position, ItemType type);

    void draw(sf::RenderWindow& window);
    sf::Vector2f getPosition() const;
private:
    sf::Vector2f position;
    ItemType type;

    sf::Texture texture;
    sf::Sprite sprite;
};