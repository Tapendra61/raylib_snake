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

void Food::draw(Grid &grid) {
	DrawTexture(foodTexture, position.x * grid.CELL_SIZE, position.y * grid.CELL_SIZE, WHITE);
}

Food::~Food() {
	UnloadTexture(foodTexture);
}