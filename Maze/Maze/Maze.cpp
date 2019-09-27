#include "Maze.h"
#include "Cell.h"
#include <iostream>
#include <time.h>
#include <array>


Maze::Maze() {
	srand(time(NULL));
	
	/*
	this->maze[0][COLUMNS - 1] = Cell(3);
	this->maze[0][0] = Cell(6);
	this->maze[ROWS - 1][0] = Cell(5);
	this->maze[ROWS - 1][COLUMNS - 1] = Cell(4);
	*/

	//this->display();
	
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLUMNS; j++) {
			/*
			if ((i == 0 && j == 0) || (i == 0 && j == COLUMNS - 1) || (i == ROWS - 1 && j == 0) || (i == ROWS - 1 && j == COLUMNS - 1)) {
				continue;
			}
			*/
			do {
				int randomValue = rand() % 12;
				if (rand() % 4 == 0 || rand() % 4 == 1 || rand() % 4 == 2) randomValue = 0;
				this->maze[i][j] = Cell(randomValue);
			} while (!this->doesPieceFit(i, j));
		}
	}
}


void Maze::display() {
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLUMNS; j++) {
			std::cout << this->maze[i][j].getChar();
		}
		std::cout << std::endl;
	}
}


void Maze::showData() {
	std::array<int, 12> data = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	std::array<char, 12> charaters = { ' ', 185, 186, 187, 188, 200, 201, 202, 203, 204, 205, 206 };
	for (int i = 0; i <= ROWS; i++) {
		for (int j = 0; j <= COLUMNS; j++) {
			char charater = maze[i][j].getChar();
			for (int k = 0; k < 12; k++) {
				if (charater == charaters[k]) data[k]++;
			}
		}
	}

	for (int i = 0; i < 12; i++) {
		std::cout << charaters[i] << " " << data[i]  << std::endl;
	}
}


std::string Maze::toString() {
	return "finish...";
}


bool Maze::doesPieceFit(int i, int j) {
	bool left = true, right = true, up = true, down = true;
	if (i != 0) up = (this->maze[i - 1][j].getDown() && this->maze[i][j].getUp()) || (!this->maze[i - 1][j].getDown() && !this->maze[i][j].getUp());
	if (j != 0) left = (this->maze[i][j - 1].getRight() && this->maze[i][j].getLeft()) || (!this->maze[i][j - 1].getRight() && !this->maze[i][j].getLeft());
	return left && right && up && down;
}

/*
bool Maze::doesPieceFit(int i, int j) {
	bool left = true, right = true, up = true, down = true;
	if (i == 0) up = !this->maze[i][j].getUp();
	else up = (this->maze[i - 1][j].getDown() && this->maze[i][j].getUp()) || (!this->maze[i - 1][j].getDown() && !this->maze[i][j].getUp());
	if (j == 0) left = !this->maze[i][j].getLeft();
	else left = (this->maze[i][j - 1].getRight() && this->maze[i][j].getLeft()) || (!this->maze[i][j - 1].getRight() && !this->maze[i][j].getLeft());
	if (i == ROWS - 1) down = !this->maze[i][j].getDown();
	else if (this->maze[i + 1][j].getUp()) std::cout << "FALSE!!!!\n";
	//else down = (this->maze[i + 1][j].getUp() && this->maze[i][j].getDown()) || (!this->maze[i + 1][j].getUp() && !this->maze[i][j].getDown());
	if (j == COLUMNS - 1) right = !this->maze[i][j].getRight();
	return left && right && up && down;
}
*/


