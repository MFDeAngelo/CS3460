#pragma once

#include "Pattern.hpp"

#include <cstdint>

class PatternBlock : public Pattern
{
  public:
    std::uint8_t getSizeX() const;
    std::uint8_t getSizeY() const;
    bool getCell(std::uint8_t x, std::uint8_t y) const;
};