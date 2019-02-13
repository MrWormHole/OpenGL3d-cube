#include <iostream>
#include "display.h"
#include <GL/glew.h>

int main(int argc, char **argv) {
	Display display(800, 600, "OpenGL is awesome!");
	
	while (!display.isClosed()) {
		display.clear(0.0f, 0.15f, 0.3f, 1.0f);
		display.update();
	}

	return 0;
}