#pragma once
#include "Pattern.hpp"

#include <cstdint>
#include <vector>

class LifeSimulator
{
  private:
    std::uint8_t sizeX;
    std::uint8_t sizeY;
    std::vector<std::vector<bool>> grid;

  public:
    LifeSimulator(std::uint8_t sizeX, std::uint8_t sizeY);

    void insertPattern(const Pattern& pattern, std::uint8_t startX, std::uint8_t startY);
    void update();

    std::uint8_t getSizeX() const { return sizeX; }
    std::uint8_t getSizeY() const { return sizeY; }
    bool getCell(std::uint8_t x, std::uint8_t y) const { return grid[x][y]; }
};