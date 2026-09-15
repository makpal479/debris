#pragma once

#include <vector>

class WorldGenerator
{
public:
    WorldGenerator(int width, int height);

    std::vector<int> generateSurface();

private:
    int width;
    int height;
};