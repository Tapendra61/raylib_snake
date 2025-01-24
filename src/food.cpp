#include"food.h"

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

void Food::draw(Grid &grid) const {
	DrawTexture(foodTexture, position.x * grid.CELL_SIZE, position.y * grid.CELL_SIZE, WHITE);
}

Food::~Food() {
	UnloadTexture(foodTexture);
}

Vector2 Food::GetRandomPosition(Grid &grid) {
	float x = GetRandomValue(0, grid.CELL_COUNT - 1);
	float y = GetRandomValue(0, grid.CELL_COUNT - 1);

	return Vector2{ x, y };
}