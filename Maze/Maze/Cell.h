#pragma once


class Cell
{
public:
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