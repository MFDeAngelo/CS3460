#include "LifeSimulator.hpp"
#include "rlutil.h"
#include "RenderConsole.hpp"

int main()
{
    const LifeSimulator lifeSimulator(rlutil::tcols(), rlutil::trows());

	for (int i = 0; i < 30; i++)
    {
        RenderConsole renderConsole();

		renderConsole.render(lifeSimulator);
    }
    return 0;
}