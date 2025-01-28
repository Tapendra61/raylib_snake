#include"collision.h"

bool foodPosOverlapsSnakeBody(Vector2& foodPos, Snake& snake) {
	for (Vector2 segment : snake.body) {
		if (Vector2Equals(foodPos, segment)) {
			return true;
		}
	}

	return false;
}