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
    for (uint8_t i = 0; i < pattern.getSizeX(); i++)
    {
        for (uint8_t j = 0; j < pattern.getSizeY(); j++)
        {
            grid[i + startX][j + startY] = pattern.getCell(i, j);
        }
    }
}

void LifeSimulator::update()
{
    std::vector<std::vector<bool>> temp(sizeX, std::vector<bool>(sizeY, false));
    for (int i = 0; i < sizeX; i++)
    {
        for (int j = 0; j < sizeY; j++)
        {
            unsigned short neighbors = 0;
            if (i != 0)
            {
                if (j != 0)
                {
                    neighbors += static_cast<short>(grid[i - 1][j - 1]);
                }
                if (j != sizeY - 1)
                {
                    neighbors += static_cast<short>(grid[i - 1][j + 1]);
                }
                neighbors += static_cast<short>(grid[i - 1][j]);
            }

            if (i != sizeX - 1)
            {
                if (j != 0)
                {
                    neighbors += static_cast<short>(grid[i + 1][j - 1]);
                }
                if (j != sizeY - 1)
                {
                    neighbors += static_cast<short>(grid[i + 1][j + 1]);
                }
                neighbors += static_cast<short>(grid[i + 1][j]);
            }

            if (j != 0)
            {
                neighbors += static_cast<short>(grid[i][j - 1]);
            }

            if (j != sizeY - 1)
            {
                neighbors += static_cast<short>(grid[i][j + 1]);
            }

            if ((neighbors == 2 && grid[i][j]) || neighbors == 3)
                temp[i][j] = true;
        }
    }
    grid = temp;
}