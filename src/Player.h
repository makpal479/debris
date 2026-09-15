#pragma once

#include <SFML/Graphics.hpp>
class World;

class Player
{
public:
    Player();

    void update(sf::Time dTime, World &world);
    void draw(sf::RenderWindow &window);
    void jump();

    sf::Vector2f getCenter();

    void setMoveLeft(bool value);
    void setMoveRight(bool value);

private:
    sf::RectangleShape main_shape;

    sf::Texture texture;
    sf::Sprite sprite;

    float speed = 200.f;
    float velocityY = 0.f;

    float jumpStrength = 700.f;
    float gravity = 1200.f;

    bool isOnGround = true;

    bool moveLeft = false;
    bool moveRight = false;

    sf::Texture walkTexture;

    int currentFrame = 0;
    float animationTimer = 0.f;
    float animationSpeed = 0.15f;
};