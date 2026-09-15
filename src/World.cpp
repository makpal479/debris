#include "World.h"
#include <cstdlib>
#include <cmath>
#include <iostream>

World::World(int width, int height)
    : width(width), height(height)
{
    tiles.reserve(width * 20);
    trees.reserve(width);

    WorldGenerator generator(width, height);

    std::vector<int> surface = generator.generateSurface();

    for (int x = 0; x < width; ++x)
    {
        int surfaceY = surface[x];

        for (int y = surfaceY; y < height; ++y)
        {
            sf::Vector2f position(
                x * 32.f,
                y * 32.f);

            if (y == surfaceY)
            {
                tiles.emplace_back(
                    position,
                    TileType::Grass);
            }
            else
            {
                tiles.emplace_back(
                    position,
                    TileType::Dirt);
            }
        }
    }

    int lastTreeX = -10;

    for (int x = 2; x < width - 2; ++x)
    {
        if (x - lastTreeX < 6)
            continue;

        if (surface[x] != surface[x - 1] ||
            surface[x] != surface[x + 1])
        {
            continue;
        }

        if (rand() % 100 < 10)
        {
            trees.push_back(
                std::make_unique<Tree>(
                    sf::Vector2f(
                        x * 32.f + 16.f,
                        surface[x] * 32.f),
                    TreeType::Oak));

            lastTreeX = x;
        }
    }
}

bool World::hasTileAt(int x, int y)
{
    for (const Tile &tile : tiles)
    {
        sf::Vector2f position = tile.getPosition();

        if (position.x == x * 32.f &&
            position.y == y * 32.f)
        {
            return true;
        }
    }

    return false;
}

bool World::isGrassAt(int x, int y)
{
    for (const Tile &tile : tiles)
    {
        sf::Vector2f position = tile.getPosition();

        if (position.x == x * 32.f &&
            position.y == y * 32.f)
        {
            return tile.getType() == TileType::Grass;
        }
    }

    return false;
}

Tile *World::getTileAt(int x, int y)
{
    for (Tile &tile : tiles)
    {
        sf::Vector2f position = tile.getPosition();

        if (position.x == x * 32.f &&
            position.y == y * 32.f)
        {
            return &tile;
        }
    }

    return nullptr;
}

Tree *World::getTreeAt(sf::Vector2f point)
{
    for (auto &tree : trees)
    {
        if (tree->contains(point))
        {
            return tree.get();
        }
    }

    return nullptr;
}

void World::update(
    float dt,
    sf::Vector2f playerPosition,
    Inventory &inventory)
{
    for (auto it = trees.begin(); it != trees.end();)
    {
        (*it)->update(dt);

        if ((*it)->Destroyed())
        {
            sf::Vector2f position = (*it)->getPosition();

            items.push_back(
                std::make_unique<ItemEntity>(
                    position,
                    ItemType::Wood));

            it = trees.erase(it);
        }
        else
        {
            ++it;
        }
    }

    for (auto it = items.begin(); it != items.end();)
    {
        sf::Vector2f itemPosition = (*it)->getPosition();

        float dx = itemPosition.x - playerPosition.x;
        float dy = itemPosition.y - playerPosition.y;

        float distance = std::sqrt(dx * dx + dy * dy);

        if (distance < 40.f)
        {
            inventory.addItem(ItemType::Wood);
            it = items.erase(it);
        }
        else
        {
            ++it;
        }
    }
}

void World::draw(sf::RenderWindow &window)
{
    for (auto &tree : trees)
    {
        tree->draw(window);
    }

    for (auto &tile : tiles)
    {
        tile.draw(window);
    }

    for (auto &item : items)
    {
        item->draw(window);
    }
}