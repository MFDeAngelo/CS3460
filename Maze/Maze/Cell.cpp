#include <stdlib.h> 
#include "Cell.h"





bool Cell::getLeft() {
	return this->left;
}
bool Cell::getRight() {
	return this->right;
}
bool Cell::getUp() {
	return this->up;
}
bool Cell::getDown() {
	return this->down;
}


Cell::Cell()
{
	int randomValue = rand() % 12;
	if (randomValue == 0) this->structure = ' ';
	else if (randomValue < 5) this->structure = randomValue + 184;
	else this->structure = randomValue + 195;

	switch(randomValue)
	{
		case 0:
			this->structure = ' ';
			this->left = false;
			this->up = false;
			this->right = false;
			this->down = false;
			break;
		case 1:
			this->left = true;
			this->up = true;
			this->right = false;
			this->down = true;
			break;
		case 2:
			this->left = false;
			this->up = true;
			this->right = false;
			this->down = true;
			break;
		case 3:
			this->left = true;
			this->up = false;
			this->right = false;
			this->down = true;
			break;
		case 4:
			this->left = true;
			this->up = true;
			this->right = false;
			this->down = false;
			break;
		case 5:
			this->left = false;
			this->up = true;
			this->right = true;
			this->down = false;
			break;
		case 6:
			this->left = false;
			this->up = false;
			this->right = true;
			this->down = true;
			break;
		case 7:
			this->left = true;
			this->up = true;
			this->right = true;
			this->down = false;
			break;
		case 8:
			this->left = true;
			this->up = false;
			this->right = true;
			this->down = true;
			break;
		case 9:
			this->left = false;
			this->up = true;
			this->right = true;
			this->down = true;
			break;
		case 10:
			this->left = true;
			this->up = false;
			this->right = true;
			this->down = false;
			break;
		case 11:
			this->left = true;
			this->up = true;
			this->right = true;
			this->down = true;
			break;
			
	}
}

char Cell::getChar() {
	return this->structure;
}

Cell::~Cell()
{
}