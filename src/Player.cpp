#include "Player.h"
#include "World.h"

Player::Player()
{
    main_shape.setSize(sf::Vector2f(32.f, 32.f));
    main_shape.setPosition(sf::Vector2f(615.f, 335.f));

    texture.loadFromFile("assets/player2.png");
    walkTexture.loadFromFile("assets/4frames.png");

    sprite.setTexture(walkTexture);
    sprite.setTextureRect(sf::IntRect(0, 0, 32, 32));

    sprite.setScale(3.f, 3.f);
    sprite.setOrigin(16.f, 32.f);

    sprite.setPosition(
        main_shape.getPosition().x + 16.f,
        main_shape.getPosition().y + 32.f);
}

void Player::draw(sf::RenderWindow &window)
{
    window.draw(sprite);
}

void Player::jump()
{
    if (isOnGround)
    {
        velocityY = -jumpStrength;
        isOnGround = false;
    }
}

sf::Vector2f Player::getCenter()
{
    return main_shape.getPosition() + main_shape.getSize() / 2.f;
}

void Player::setMoveLeft(bool value)
{
    moveLeft = value;
}

void Player::setMoveRight(bool value)
{
    moveRight = value;
}

void Player::update(sf::Time dTime, World &world)
{
    float dt = dTime.asSeconds();

    bool onGrass = false;

    isOnGround = false;

    velocityY += gravity * dt;
    main_shape.move(0.f, velocityY * dt);

    float bottom =
        main_shape.getPosition().y +
        main_shape.getSize().y;

    int leftTileX =
        static_cast<int>(
            main_shape.getPosition().x / 32.f);

    int rightTileX =
        static_cast<int>(
            (main_shape.getPosition().x +
             main_shape.getSize().x - 1.f) /
            32.f);

    int tileY =
        static_cast<int>(bottom / 32.f);

    if (velocityY >= 0.f &&
        (world.hasTileAt(leftTileX, tileY) ||
         world.hasTileAt(rightTileX, tileY)))
    {
        main_shape.setPosition(
            main_shape.getPosition().x,
            tileY * 32.f - main_shape.getSize().y);

        velocityY = 0.f;
        isOnGround = true;

        onGrass =
            world.isGrassAt(leftTileX, tileY) ||
            world.isGrassAt(rightTileX, tileY);
    }

    if (moveLeft)
    {
        float newX =
            main_shape.getPosition().x -
            speed * dt;

        int leftTileX =
            static_cast<int>(newX / 32.f);

        int topTileY =
            static_cast<int>(
                main_shape.getPosition().y / 32.f);

        int bottomTileY =
            static_cast<int>(
                (main_shape.getPosition().y +
                 main_shape.getSize().y - 1.f) /
                32.f);

        bool blocked =
            world.hasTileAt(leftTileX, topTileY) ||
            world.hasTileAt(leftTileX, bottomTileY);

        if (!blocked)
        {
            main_shape.move(-speed * dt, 0.f);
        }
    }

    if (moveRight)
    {
        float newX =
            main_shape.getPosition().x +
            speed * dt;

        float right =
            newX + main_shape.getSize().x - 1.f;

        int rightTileX =
            static_cast<int>(right / 32.f);

        int topTileY =
            static_cast<int>(
                main_shape.getPosition().y / 32.f);

        int bottomTileY =
            static_cast<int>(
                (main_shape.getPosition().y +
                 main_shape.getSize().y - 1.f) /
                32.f);

        bool blocked =
            world.hasTileAt(rightTileX, topTileY) ||
            world.hasTileAt(rightTileX, bottomTileY);

        if (!blocked)
        {
            main_shape.move(speed * dt, 0.f);
        }
    }

    if (moveLeft || moveRight)
    {
        animationTimer += dt;

        if (animationTimer >= animationSpeed)
        {
            animationTimer = 0.f;

            currentFrame++;

            if (currentFrame >= 4)
            {
                currentFrame = 0;
            }
        }

        sprite.setTexture(walkTexture);

        if (moveLeft)
        {
            sprite.setScale(-3.f, 3.f);
        }
        else
        {
            sprite.setScale(3.f, 3.f);
        }

        sprite.setTextureRect(
            sf::IntRect(
                currentFrame * 32,
                0,
                32,
                32));
    }
    else
    {
        currentFrame = 0;
        animationTimer = 0.f;

        sprite.setTexture(texture);
        sprite.setScale(3.f, 3.f);

        sprite.setTextureRect(
            sf::IntRect(0, 0, 32, 32));
    }

    float spriteOffsetY =
        onGrass ? 48.f : 32.f;

    sprite.setPosition(
        main_shape.getPosition().x + 16.f,
        main_shape.getPosition().y + spriteOffsetY);
}