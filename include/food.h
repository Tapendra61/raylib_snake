#pragma once
#include<iostream>
#include"raylib.h"
#include"grid.h"
#include<deque>
#include"collision.h"

class Snake;

class Food {
public:
	Color foodColor{ 40, 55, 30, 255 };
	Vector2 position{ 0, 0 }; //Represents food position in grid
	Texture2D foodTexture;

	Food();
	~Food();
	void draw(Grid& grid) const;
	void moveFood(Grid& grid, Snake &snake);
	Vector2 getRandomPosition(Grid& grid, Snake& snake);
};