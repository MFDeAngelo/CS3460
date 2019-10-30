#include "PatternGlider.hpp"

std::uint8_t PatternGlider::getSizeX() const
{
    return 5;
}

std::uint8_t PatternGlider::getSizeY() const
{
    return 5;
}

bool PatternGlider::getCell(std::uint8_t x, std::uint8_t y) const
{
    if (x == 1 && y == 2)
        return true;
    if (x == 2 && y == 3)
        return true;
    if (x == 3 && y > 0 && y < 4)
        return true;
	
    return false;
}
