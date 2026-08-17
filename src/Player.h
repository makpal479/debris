#pragma once

#include <SFML/Graphics.hpp>

class Player
{
public:
    Player();

    void update(sf::Time dTime);
    void draw(sf::RenderWindow& window);
    void jump();

    sf::Vector2f getCenter();

    void setMoveLeft(bool value);
    void setMoveRight(bool value);

private:
    sf::RectangleShape main_shape;

    float speed = 200.f;

    float jumpStrength = 700.f;
    float gravity = 1200.f;
    float velocityY = 0.f;

    bool isOnGround = true;
    float ground = 650.f;

    bool moveLeft = false;
    bool moveRight = false;
};