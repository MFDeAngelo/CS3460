#include "RenderConsole.hpp"

#include "LifeSimulator.hpp"


void RenderConsole::render(const LifeSimulator& simulation)
{
    rlutil::cls();

    for (int i = 0; i < simulation.getSizeX(); i++)
    {
        for (int j = 0; j < simulation.getSizeY(); j++)
        {
            if (simulation.getCell(i, j))
            {
                rlutil::locate(i + 1, j + 1);
                rlutil::setChar('*');
            }
        }
    }

}