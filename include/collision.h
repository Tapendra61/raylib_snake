#pragma once
#include"raylib.h"
#include"snake.h"
#include"grid.h"

bool foodPosOverlapsSnakeBody(Vector2& foodPos, Snake& snake);
bool snakeOutOfBounds(Grid& grid, Snake& snake);
bool snakeSelfCollided(Snake& snake);