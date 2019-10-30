#include "LifeSimulator.hpp"

LifeSimulator::LifeSimulator(std::uint8_t sizeX, std::uint8_t sizeY) :
    sizeX(sizeX),
    sizeY(sizeY)
{
    std::vector<std::vector<bool>> temp(sizeX, std::vector<bool>(sizeY, false));
    grid = temp;
}

void LifeSimulator::insertPattern(const Pattern& pattern, std::uint8_t startX, std::uint8_t startY)
{
    for (unsigned int i = 0; i < pattern.getSizeX(); i++)
    {
        for (unsigned int j = 0; j < pattern.getSizeY(); j++)
        {
            grid[i + startX][j + startY] = pattern.getCell[i][j];
        }
    }
}

void LifeSimulator::update()
{
}