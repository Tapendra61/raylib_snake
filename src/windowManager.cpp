#include"windowManager.h";
#include<iostream>
#include"raylib.h";

WindowManager::WindowManager(int width, int height, const char* title, int fps) :
	windowWidth(width), windowHeight(height), windowTitle(title), targetFPS(fps) {}

void WindowManager::run() {
	InitWindow(windowWidth, windowHeight, windowTitle);
	SetTargetFPS(targetFPS);

	if (!IsWindowReady()) {
		std::cerr << "Window initialization failed!" << std::endl;
		return;
	}

	while (!WindowShouldClose()) {
		update(); //For input handling

		BeginDrawing();

		lateUpdate(); //For rendering

		EndDrawing();
	}
}

void WindowManager::update() {

}

void WindowManager::lateUpdate() {

}

WindowManager::~WindowManager() {
	CloseWindow();
}