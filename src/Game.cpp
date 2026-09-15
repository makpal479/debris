#include "Game.h"
#include <iostream>

Game::Game()
    : main_window(sf::VideoMode(1280, 720), "PixelSandbox"),
      camera(sf::FloatRect(0.f, 0.f, 1280.f, 720.f)),
      world(200, 30)
{
}

void Game::run()
{
    while (main_window.isOpen())
    {
        processEvents();

        sf::Time dTime = clock.restart();

        update(dTime);

        render();
    }
}

void Game::processEvents()
{
    sf::Event event;

    while (main_window.pollEvent(event))
    {
        if (event.type == sf::Event::MouseButtonPressed)
        {
            if (event.mouseButton.button == sf::Mouse::Left)
            {
                sf::Vector2i mousePosition(
                    event.mouseButton.x,
                    event.mouseButton.y);

                sf::Vector2f worldPosition =
                    main_window.mapPixelToCoords(
                        mousePosition,
                        camera);

                Tree *tree = world.getTreeAt(worldPosition);

                if (tree != nullptr)
                {
                    if (tree->getType() == TreeType::Oak)
                    {
                        tree->hit();
                    }
                }
            }
        }

        if (event.type == sf::Event::Closed)
        {
            main_window.close();
        }

        if (event.type == sf::Event::KeyPressed)
        {
            if (event.key.code == sf::Keyboard::Space ||
                event.key.code == sf::Keyboard::W)
            {
                player.jump();
            }

            if (event.key.code == sf::Keyboard::Left ||
                event.key.code == sf::Keyboard::A)
            {
                player.setMoveLeft(true);
            }

            if (event.key.code == sf::Keyboard::Right ||
                event.key.code == sf::Keyboard::D)
            {
                player.setMoveRight(true);
            }
        }

        if (event.type == sf::Event::KeyReleased)
        {
            if (event.key.code == sf::Keyboard::Left ||
                event.key.code == sf::Keyboard::A)
            {
                player.setMoveLeft(false);
            }

            if (event.key.code == sf::Keyboard::Right ||
                event.key.code == sf::Keyboard::D)
            {
                player.setMoveRight(false);
            }
        }
    }
}

void Game::update(sf::Time dTime)
{
    player.update(dTime, world);

    sf::Vector2f playerCenter = player.getCenter();

    world.update(
        dTime.asSeconds(),
        playerCenter,
        inventory);
    playerCenter.y -= 100.f;

    camera.setCenter(playerCenter);
}

void Game::render()
{
    main_window.setView(camera);

    main_window.clear(sf::Color(30, 30, 30));

    world.draw(main_window);
    player.draw(main_window);

    inventoryUI.draw(main_window, inventory);

    main_window.display();
}