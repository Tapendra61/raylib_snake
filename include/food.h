#pragma once
#include<iostream>
#include"raylib.h"
#include"grid.h"

class Food {
public:
	Color foodColor{40, 55, 30, 255};
	Vector2 position{0, 0}; //Represents food position in grid
	Texture2D foodTexture;

	Food();
	~Food();
	void draw(Grid &grid) const;
	Vector2 GetRandomPosition(Grid &grid);
};