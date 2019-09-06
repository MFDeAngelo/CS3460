#pragma once
#include "Cell.h"
#include <string>

class Maze
{
private:
	Cell maze[10][10];

public:
	Maze();
	std::string toString();
	void display();
};

