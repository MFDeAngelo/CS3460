#include "LifeSimulator.hpp"
#include "PatternAcorn.hpp"
#include "PatternBlinker.hpp"
#include "PatternBlock.hpp"
#include "PatternGlider.hpp"
#include "PatternGosperGliderGun.hpp"
#include "RenderConsole.hpp"
#include "rlutil.h"

#include <cstdint>
#include <thread>

int main()
{
    LifeSimulator lifeSimulator(static_cast<uint8_t>(rlutil::tcols()), static_cast<uint8_t>(rlutil::trows()));
    RenderConsole rc;

    std::cout << "What pattern would you like to see?" << std::endl;
    std::cout << "1-Acorn" << std::endl;
    std::cout << "2-Blinker" << std::endl;
    std::cout << "3-Block" << std::endl;
    std::cout << "4-Glider" << std::endl;
    std::cout << "5-Gosper Glider Gun" << std::endl;

    int input = 0;

    while (input < 1 || input > 6)
    {
        input = rlutil::getkey() - 48;
    }

    if (input == 1)
    {
        PatternAcorn acorn;
        lifeSimulator.insertPattern(acorn, 50, 10);
    }
    if (input == 2)
    {
        PatternBlinker blinker;
        lifeSimulator.insertPattern(blinker, 50, 10);
    }
    if (input == 3)
    {
        PatternBlock block;
        lifeSimulator.insertPattern(block, 50, 10);
    }
    if (input == 4)
    {
        PatternGlider glider;
        lifeSimulator.insertPattern(glider, 5, 2);
    }
    if (input == 5)
    {
        PatternGosperGliderGun gun;
        lifeSimulator.insertPattern(gun, 30, 5);
    }

    rlutil::hidecursor();

    for (int i = 0; i < 50; i++)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        rc.render(lifeSimulator);
        lifeSimulator.update();
    }

    rlutil::cls();

    return 0;
}