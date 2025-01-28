#include"application.h"

Application::Application(int width, int height, const char* title, int fps) :
	windowWidth(width), windowHeight(height), windowTitle(title), targetFPS(fps) {}

void Application::run() {
	InitWindow(windowWidth + (75 * 2), windowHeight + (75 * 2), windowTitle);
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
	handleInput();
	if (!gameRunning) return;
	snake->handleInput();
	if (eventTriggered(0.1)) {
		snake->move();
	}
	snake->checkCollisionWithFood(*food, *grid, *snake, score);
	if (snakeOutOfBounds(*grid, *snake) || snakeSelfCollided(*snake)) {
		gameOver();
	}
}

void Application::lateUpdate() {
	DrawRectangleLinesEx(Rectangle{ (float)grid->OFFSET - 5, (float)grid->OFFSET - 5, (float)grid->CELL_SIZE * grid->CELL_COUNT + 10, (float)grid->CELL_SIZE * grid->CELL_COUNT + 10 }, 5, { 40, 55, 30, 255 });
	DrawText("Classic Snake", grid->OFFSET - 5, 20, 40, { 40, 55, 30, 255 });
	DrawText(TextFormat("%i", score.score), grid->OFFSET - 5, grid->OFFSET + grid->CELL_SIZE * grid->CELL_COUNT + 10, 40, {40, 55, 30, 255});
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

void Application::handleInput() {
	if (!gameRunning) {
		if (GetKeyPressed() != NULL) {
			gameRunning = true;
		}
	}
}

void Application::gameOver() {
	snake->reset();
	food->position = food->getRandomPosition(*grid, *snake);
	gameRunning = false;
	score.score = 0;
}

Application::~Application() {
	delete food;
	delete grid;
	delete snake;
	CloseWindow();
}