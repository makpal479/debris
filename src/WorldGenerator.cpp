#include "WorldGenerator.h"
#include <cmath>

WorldGenerator::WorldGenerator(int width, int height)
    : width(width), height(height)
{
}

std::vector<int> WorldGenerator::generateSurface()
{
    std::vector<int> surface;
    surface.reserve(width);

    float baseHeight = static_cast<float>(height - 20);

    for (int x = 0; x < width; ++x)
    {
        float wave1 = std::sin(x * 0.08f) * 2.f;
        float wave2 = std::sin(x * 0.025f) * 5.f;

        int surfaceY = static_cast<int>(
            baseHeight + wave1 + wave2);

        int minSurfaceY = height - 35;
        int maxSurfaceY = height - 10;

        if (surfaceY < minSurfaceY)
            surfaceY = minSurfaceY;

        if (surfaceY > maxSurfaceY)
            surfaceY = maxSurfaceY;

        surface.push_back(surfaceY);
    }

    return surface;
}