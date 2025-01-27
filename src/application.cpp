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
	snake = new Snake();

	food->position = food->getRandomPosition(*grid, *snake);
}

void Application::update() {
	snake->handleInput();
	if (eventTriggered(0.1)) {
		snake->move();
	}
	snake->checkCollisionWithFood(*food, *grid, *snake);
}

void Application::lateUpdate() {
	food->draw(*grid);
	snake->draw(*grid);

}

bool Application::eventTriggered(double interval) {
	double currentTime = GetTime();

	if (currentTime - lastTriggeredTime >= interval) {
		lastTriggeredTime = currentTime;
		return true;
	}

	return false;
}

Application::~Application() {
	delete food;
	delete grid;
	delete snake;
	CloseWindow();
}