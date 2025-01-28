#include"snake.h"
#include"food.h"

void Snake::draw(Grid& grid) const {
	for (Vector2 segment : body) {
		int x = (int)segment.x;
		int y = (int)segment.y;

		Rectangle rect{ grid.OFFSET + x * (float)grid.CELL_SIZE, grid.OFFSET + y * (float)grid.CELL_SIZE, (float)grid.CELL_SIZE, (float)grid.CELL_SIZE };
		DrawRectangleRounded(rect, 0.5, 6, bodyColor);
	}
}

void Snake::move() {
	if (segmentAdded) {
		segmentAdded = false;
		return;
	}
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

void Snake::checkCollisionWithFood(Food& food, Grid& grid, Snake& snake, Score& score) {
	if (Vector2Equals(body[0], food.position)) {
		food.moveFood(grid, snake);
		snake.addSegment();
		score.score++;
	}
}

void Snake::addSegment() {
	body.push_front(Vector2Add(body[0], direction));
	segmentAdded = true;
}

void Snake::reset() {
	body = { Vector2{6, 9}, Vector2{5, 9}, Vector2{4, 9} };
	direction = {1, 0};
}