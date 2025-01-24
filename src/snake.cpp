#include"snake.h"

void Snake::draw(Grid& grid) const {
	for (Vector2 segment : body) {
		int x = segment.x;
		int y = segment.y;

		Rectangle rect{ x * grid.CELL_SIZE, y * grid.CELL_SIZE, grid.CELL_SIZE, grid.CELL_SIZE };
		DrawRectangleRounded(rect, 0.5, 6, bodyColor);
	}
}

void Snake::move() {
	body.pop_back();
	body.push_front(Vector2Add(body[0], direction));
}

void Snake::handleInput() {
	if (IsKeyPressed(KEY_W) && direction.y != 1) {
		direction = { 0, -1 };
	}
	else if (IsKeyPressed(KEY_S) && direction.y != -1) {
		direction = { 0, 1 };
	}
	else if (IsKeyPressed(KEY_A) && direction.x != 1) {
		direction = { -1, 0 };
	}
	else if (IsKeyPressed(KEY_D) && direction.x != -1) {
		direction = { 1, 0 };
	}
}