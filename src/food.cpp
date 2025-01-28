#include"food.h"
#include"snake.h"

Food::Food() {
	Image foodImage = LoadImage("resources/food.png");
	if (!IsImageValid(foodImage)) {
		std::cerr << "Could not load food image!" << std::endl;
	}

	foodTexture = LoadTextureFromImage(foodImage);
	if (!IsTextureValid(foodTexture)) {
		std::cerr << "Could not load food texture!" << std::endl;
	}
	UnloadImage(foodImage);
}

void Food::draw(Grid& grid) const {
	DrawTexture(foodTexture, grid.OFFSET + (int)position.x * grid.CELL_SIZE, grid.OFFSET + (int)position.y * grid.CELL_SIZE, WHITE);
}

Food::~Food() {
	UnloadTexture(foodTexture);
}

Vector2 Food::getRandomPosition(Grid& grid, Snake& snake) {
	Vector2 newPosition = grid.getRandomCellPosition();

	while (foodPosOverlapsSnakeBody(newPosition, snake)) {
		newPosition = grid.getRandomCellPosition();
	}

	return newPosition;
}

void Food::moveFood(Grid& grid, Snake& snake) {
	position = getRandomPosition(grid, snake);
}