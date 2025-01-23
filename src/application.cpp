#include"application.h"

Application::Application(int width, int height, const char* title, int fps) :
	windowWidth(width), windowHeight(height), windowTitle(title), targetFPS(fps) {}

void Application::run() {
	InitWindow(windowWidth, windowHeight, windowTitle);
	SetTargetFPS(targetFPS);
	Color clearColor{ 170, 200, 90, 255 };

	if (!IsWindowReady()) {
		std::cerr << "Window initialization failed!" << std::endl;
		return;
	}

	start();

	while (!WindowShouldClose()) {
		update(); //For input handling

		BeginDrawing();
		ClearBackground(clearColor);

		lateUpdate(); //For rendering

		EndDrawing();
	}
}

void Application::start() {
	grid = new Grid();
	food = new Food();
}

void Application::update() {

}

void Application::lateUpdate() {
	food->draw(*grid);
}

Application::~Application() {
	delete food;
	delete grid;
	CloseWindow();
}