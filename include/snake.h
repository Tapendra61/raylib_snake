#pragma once
#include<deque>
#include"grid.h"
#include"raylib.h"
#include"raymath.h"
#include"score.h"

class Food;

class Snake {
public:
	std::deque<Vector2> body = { Vector2{6, 9}, Vector2{5, 9}, Vector2{4, 9} };
	Vector2 direction{ 1, 0 };
	Color bodyColor{ 40, 55, 30, 255 };
	bool segmentAdded = false;

	void draw(Grid& grid) const;
	void move();
	void handleInput();
	void checkCollisionWithFood(Food& food, Grid& grid, Snake& snake, Score& score);
	void addSegment();
	void reset();
};