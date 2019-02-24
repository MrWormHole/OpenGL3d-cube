#include <iostream>
#include <GL/glew.h>
#include "display.h"
#include "shader.h"
#include "mesh.h"

int main(int argc, char **argv) {
	Display display(800, 600, "OpenGL is awesome!");

	Shader shader("./resources/basicShader");
	Vertex vertices[] = { Vertex(glm::vec3(-0.5,-0.5,0)),
						  Vertex(glm::vec3(0,0.5,0)),
						  Vertex(glm::vec3(0.5,-0.5,0)) };
	Mesh mesh(vertices, sizeof(vertices) / sizeof(vertices[0]));
	
	while (!display.isClosed()) {
		display.clear(0.0f, 0.15f, 0.3f, 1.0f);
		shader.bind();
		mesh.draw();
		display.update();
	}

	return 0;
}