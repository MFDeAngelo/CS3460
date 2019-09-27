#pragma once


class Cell
{
public:
	Cell(int randomvalue);
	Cell();
	~Cell();
	char getChar();
	bool getLeft();
	bool getRight();
	bool getUp();
	bool getDown();

private:
	char structure;
	bool up;
	bool down;
	bool left;
	bool right;
};