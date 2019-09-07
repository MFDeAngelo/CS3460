#pragma once
#include "Cell.h"
#include <string>

class Maze
{
private:
	const int ROWS = 40;
	const int COLUMNS = 10;
	Cell maze[40][10];

public:
	Maze();
	std::string toString();
	void display();
};

