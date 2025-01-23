#include<iostream>
#include"application.h"

int main() {
	Application app{800, 800, "Raylib Snake", 60};
	app.run();

	return 0;
}