#include "Maze.h"
#include <iostream>

Maze::Maze() {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			this->maze[i][j] = Cell();
		}
	}
}


void Maze::display() {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			std::cout << this->maze[i][j].getChar();
		}
		std::cout << std::endl;
	}
}


std::string Maze::toString() {
	return "finish...";
}