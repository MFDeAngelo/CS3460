#pragma once


class Cell
{
public:
	Cell();
	~Cell();
	char getChar();

private:
	char structure;
	bool up;
	bool down;
	bool left;
	bool right;
};