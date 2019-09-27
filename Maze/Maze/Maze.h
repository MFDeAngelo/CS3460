#pragma once
#include "Cell.h"
#include <string>

class Maze
{
private:
	const int ROWS = 30;
	const int COLUMNS = 100;
	Cell maze[30][100];
	bool doesPieceFit(int i, int j);

public:
	Maze();
	std::string toString();
	void display();
	void showData();
};

