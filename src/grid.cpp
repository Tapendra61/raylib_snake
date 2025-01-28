#include"grid.h"

Vector2 Grid::getRandomCellPosition() {
	float x = GetRandomValue(0, CELL_COUNT - 1);
	float y = GetRandomValue(0, CELL_COUNT - 1);

	return Vector2{ x, y };
}