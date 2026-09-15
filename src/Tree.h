#pragma once

#include <SFML/Graphics.hpp>

enum class TreeType
{
    Oak
};

class Tree
{
public:
    Tree(sf::Vector2f position, TreeType type);

    void draw(sf::RenderWindow &window);

    bool contains(sf::Vector2f point) const;

    sf::Vector2f getPosition() const;

    TreeType getType() const;

    void hit();

    bool Destroyed() const;

    void update(float dt);

private:
    TreeType type;

    int hitCount = 0;
    bool destroyed = false;
    float crashTimer = 0.f;
    bool Breaking = false;

    sf::Texture texture;
    sf::Texture crack1Texture;
    sf::Texture crack2Texture;
    sf::Texture crack3Texture;
    sf::Texture crash1Texture;
    sf::Texture crash2Texture;
    sf::Sprite sprite;
};