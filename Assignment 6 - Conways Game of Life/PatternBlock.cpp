#include "PatternBlock.hpp"

std::uint8_t PatternBlock::getSizeX() const
{
    return 4;
}

std::uint8_t PatternBlock::getSizeY() const
{
    return 4;
}

bool PatternBlock::getCell(std::uint8_t x, std::uint8_t y) const
{
    return (x == 1 || x == 2) && (y == 1 || y == 2);
}
