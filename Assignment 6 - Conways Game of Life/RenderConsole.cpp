#include "RenderConsole.hpp"

#include "LifeSimulator.hpp"

RenderConsole::RenderConsole() {}

void RenderConsole::render(const LifeSimulator& simulation)
{
    rlutil::cls();
    rlutil::hidecursor();

    for (int i = 0; i < simulation.getSizeX(); i++)
    {
        for (int j = 0; j < simulation.getSizeY(); j++)
        {
        }
    }

    rlutil::showcursor();
}