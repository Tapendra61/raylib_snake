#include"collision.h"

bool foodPosOverlapsSnakeBody(Vector2& foodPos, Snake& snake) {
	for (Vector2 segment : snake.body) {
		if (Vector2Equals(foodPos, segment)) {
			return true;
		}
	}

	return false;
}

bool snakeOutOfBounds(Grid& grid, Snake& snake) {
	if (snake.body[0].x >= grid.CELL_COUNT || snake.body[0].x <= -1) {
		return true;
	}
	if (snake.body[0].y >= grid.CELL_COUNT || snake.body[0].y <= -1) {
		return true;
	}

	return false;
}