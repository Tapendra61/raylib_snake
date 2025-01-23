#pragma once

class WindowManager {
private:
	int windowWidth = 0;
	int windowHeight = 0;
	const char* windowTitle;
	int targetFPS = 0;

public:
	WindowManager(int width, int height, const char *title, int fps);
	~WindowManager();

	int getWidth() const { return windowWidth; }
	int getHeight() const { return windowHeight; }
	const char* getTitle() const { return windowTitle; }

	void run();
	void update();
	void lateUpdate();
};