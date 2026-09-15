#include "Tree.h"

Tree::Tree(sf::Vector2f position, TreeType type)
{
    this->type = type;

    if (!texture.loadFromFile("assets/Oak3.png"))
    {
        return;
    }

    if (!crack1Texture.loadFromFile("assets/OakCrack1.png") ||
        !crack2Texture.loadFromFile("assets/OakCrack2.png") ||
        !crack3Texture.loadFromFile("assets/OakCrack3.png") ||
        !crash1Texture.loadFromFile("assets/OakCrash1.png") ||
        !crash2Texture.loadFromFile("assets/OakCrash2.png"))
    {
        return;
    }

    sprite.setTexture(texture);
    sprite.setScale(2.4f, 2.f);

    sprite.setOrigin(
        texture.getSize().x / 2.f,
        static_cast<float>(texture.getSize().y));

    sprite.setPosition(
        position.x,
        position.y + 12.f);
}

void Tree::draw(sf::RenderWindow &window)
{
    window.draw(sprite);
}

bool Tree::contains(sf::Vector2f point) const
{
    return sprite.getGlobalBounds().contains(point);
}

sf::Vector2f Tree::getPosition() const
{
    return sprite.getPosition();
}

TreeType Tree::getType() const
{
    return type;
}

bool Tree::Destroyed() const
{
    return destroyed;
}

void Tree::hit()
{
    if (destroyed)
    {
        return;
    }

    hitCount++;

    if (hitCount == 1)
    {
        sprite.setTexture(crack1Texture);
    }
    else if (hitCount == 2)
    {
        sprite.setTexture(crack2Texture);
    }
    else if (hitCount == 3)
    {
        sprite.setTexture(crack3Texture);
    }
    else if (hitCount == 4)
    {
        Breaking = true;
        crashTimer = 0.f;
        sprite.setTexture(crash1Texture);
    }
}
void Tree::update(float dt)
{
    if (!Breaking)
    {
        return;
    }

    crashTimer += dt;

    if (crashTimer >= 0.15f)
    {
        sprite.setTexture(crash2Texture);
    }
    if (crashTimer >= 0.30f)
    {
        destroyed = true;
    }
}