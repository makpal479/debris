#include "Player.h"

Player::Player()
{
    main_shape.setSize(sf::Vector2f(50.f, 50.f));
    main_shape.setPosition(sf::Vector2f(615.f, 335.f));
}

void Player::draw(sf::RenderWindow& window)
{
    window.draw(main_shape);
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

void Player::update(sf::Time dTime)
{
    float dt = dTime.asSeconds();

    
    velocityY += gravity * dt;

    
    main_shape.move(0.f, velocityY * dt);

   
    if (main_shape.getPosition().y + main_shape.getSize().y >= ground)
    {
        main_shape.setPosition(
            main_shape.getPosition().x,
            ground - main_shape.getSize().y
        );

        velocityY = 0.f;
        isOnGround = true;
    }

 
    if (moveLeft)
    {
        main_shape.move(-speed * dt, 0.f);
    }

 
    if (moveRight)
    {
        main_shape.move(speed * dt, 0.f);
    }
}