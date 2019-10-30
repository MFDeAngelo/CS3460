#include "PatternGosperGliderGun.hpp"

std::uint8_t PatternGosperGliderGun::getSizeX() const
{
    return 38;
}

std::uint8_t PatternGosperGliderGun::getSizeY() const
{
    return 11;
}

bool PatternGosperGliderGun::getCell(std::uint8_t x, std::uint8_t y) const
{
    if ((x == 1 || x == 2) && (y == 5 || y == 6))
        return true;
    if (x == 11 && y > 4 && y < 8)
        return true;
    if (x == 12 && (y == 4 || y == 8))
        return true;
    if (x > 12 && x < 15 && (y == 3 || y == 9))
        return true;
    if (x == 15 && y == 6)
        return true;
    if (x == 16 && (y == 4 || y == 8))
        return true;
    if (x == 17 && y > 4 && y < 8)
        return true;
    if (x == 18 && y == 6)
        return true;
    if (x > 20 && x < 23 && y > 2 && y < 6)
        return true;
    if (x == 23 && (y == 2 || y == 6))
        return true;
    if (x == 25 && (y == 1 || y == 2 || y == 6 || y == 7))
        return true;
    if ((x == 35 || x == 36) && (y == 3 || y == 4))
        return true;
	
    return false;
}
