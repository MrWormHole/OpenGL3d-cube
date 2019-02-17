#include <iostream>
#include <GL/glew.h>
#include "display.h"
#include "shader.h"

int main(int argc, char **argv) {
	Display display(800, 600, "OpenGL is awesome!");

	Shader shader("./resources/basicShader");
	
	while (!display.isClosed()) {
		display.clear(0.0f, 0.15f, 0.3f, 1.0f);
		shader.bind();

		display.update();
	}

	return 0;
}