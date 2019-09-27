#include <iostream>
#include "Maze.h"

void printChars();

int main() {

	Maze maze = Maze();
	maze.display();

	maze.showData();
	//printChars();
	return 0;
}



void printChars() {
	for (int i = 0; i < 255; i++) {
		std::cout << static_cast<char>(i) << "   " << i << std::endl;
	}
}