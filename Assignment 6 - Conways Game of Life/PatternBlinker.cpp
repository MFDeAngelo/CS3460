#include "PatternBlinker.hpp"

std::uint8_t PatternBlinker::getSizeX() const
{
    return 5;
}

std::uint8_t PatternBlinker::getSizeY() const
{
    return 5;
}

bool PatternBlinker::getCell(std::uint8_t x, std::uint8_t y) const
{
    return x == 2 && y > 0 && y < 4;
}
