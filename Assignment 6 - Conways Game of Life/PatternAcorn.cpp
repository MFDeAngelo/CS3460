#include "PatternAcorn.hpp"

std::uint8_t PatternAcorn::getSizeX() const
{
    return 9;
}

std::uint8_t PatternAcorn::getSizeY() const
{
    return 5;
}

bool PatternAcorn::getCell(std::uint8_t x, std::uint8_t y) const
{
    if (x == 2 && y == 1)
        return true;
    if (x == 4 && y == 2)
        return true;
    if (y == 3)
        return x == 1 || x == 2 || x == 5 || x == 6 || x == 7;

    return false;
}
