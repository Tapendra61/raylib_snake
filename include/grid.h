#pragma once
#include"raylib.h"

class Grid {
public:
	const int CELL_SIZE = 32;
	const int CELL_COUNT = 25;
	const int OFFSET = 75;

	Grid() {};
	Vector2 getRandomCellPosition();
};