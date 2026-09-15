#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "WorldGenerator.h"
#include "Tile.h"
#include "Tree.h"
#include <memory>
#include "ItemEntity.h"
#include "Inventory.h"

class World
{
public:
    World(int width, int height);

    void draw(sf::RenderWindow &window);

    bool hasTileAt(int x, int y);
    bool isGrassAt(int x, int y);
    Tile *getTileAt(int x, int y);
    Tree *getTreeAt(sf::Vector2f point);

    void update(
        float dt,
        sf::Vector2f playerPosition,
        Inventory &inventory);

private:
    int width;
    int height;
    std::vector<std::unique_ptr<Tree>> trees;
    std::vector<Tile> tiles;
    std::vector<std::unique_ptr<ItemEntity>> items;
};