#pragma once
#include "LifeSimulator.hpp"
#include "Renderer.hpp"
#include "rlutil.h"

class RenderConsole : public Renderer
{
  public:
    RenderConsole();

    void render(const LifeSimulator& simulation);
};