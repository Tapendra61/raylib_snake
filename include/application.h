#pragma once
#include<iostream>
#include"raylib.h"
#include"grid.h"
#include"food.h"
#include"snake.h"

class Application {
private:
	int windowWidth = 0;
	int windowHeight = 0;
	const char* windowTitle;
	int targetFPS = 0;

public:
	Grid* grid = nullptr;
	Food* food = nullptr;
	Snake* snake = nullptr;

public:
	Application(int width, int height, const char *title, int fps);
	~Application();

	int getWidth() const { return windowWidth; }
	int getHeight() const { return windowHeight; }
	const char* getTitle() const { return windowTitle; }

	void run();
	void start();
	void update();
	void lateUpdate();
};