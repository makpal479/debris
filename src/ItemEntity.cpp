#include "ItemEntity.h"

ItemEntity::ItemEntity(sf::Vector2f position, ItemType type)
{
    this->position = position;
    this->type = type;

    if (!texture.loadFromFile("assets/Wood.png"))
    {
        return;
    }

    sprite.setTexture(texture);

    sprite.setOrigin(
        texture.getSize().x / 2.f,
        texture.getSize().y / 2.f
    );

    sprite.setPosition(position);
}

void ItemEntity::draw(sf::RenderWindow& window)
{
    window.draw(sprite);
}

sf::Vector2f ItemEntity::getPosition() const
{
    return sprite.getPosition();
}