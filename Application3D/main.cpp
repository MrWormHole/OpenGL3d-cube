#define GLEW_STATIC
#include <GLEW/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

#include "MeshUtil.h"
#include "ShaderUtil.h"
#include "PhysicsUtil.h"

int main()
{
	GLFWwindow* window;

	/* Initialize the library */
	if (!glfwInit())
		return -1;

	glfwWindowHint(GLFW_SAMPLES, 4); // 4x antialiasing
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); // We want OpenGL 3.3
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); // We don't want the old OpenGL 

	/* Create a windowed mode window and its OpenGL context */
	window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		return -1;
	}
	
	/* Make the window's context current */
	glfwMakeContextCurrent(window);
	printf("OpenGL version supported by this platform (%s): \n", glGetString(GL_VERSION));

	GLenum err = glewInit();
	if (GLEW_OK != err)
	{
		/* Problem: glewInit failed, something is seriously wrong. */
		fprintf(stderr, "Error: %s\n", glewGetErrorString(err));
	}
	else {
		fprintf(stdout, "Status: Using GLEW %s\n", glewGetString(GLEW_VERSION));

		//for triangle
		Vertex triangleVertices[] = {
			Vertex(vec3(-0.8f,-0.5f,0.0f)),
			Vertex(vec3(0.0f,0.9f,0.0f)),
			Vertex(vec3(0.5f,-0.7f,0.0f))
		};

		Vertex triangleVertices2[] = {
			Vertex(vec3(0.8f,0.5f,0.0f)),
			Vertex(vec3(0.0f,-0.9f,0.0f)),
			Vertex(vec3(-0.5f,0.7f,0.0f))
		};

		//for square
		Vertex squareVertices[] = {
			Vertex(vec3(-0.5f,-0.5f,0.0f)),
			Vertex(vec3(0.5f,-0.5f,0.0f)),
			Vertex(vec3(0.5f,0.5f,0.0f)),
			Vertex(vec3(-0.5f,0.5f,0.0f)),
		};

		unsigned short squareIndices[6] = {
			0,1,2,
			2,3,0
		};

		ShaderUtil shaderUtil;
		shaderUtil.load("res/basicShader.v", "res/basicShader.f");

		MeshUtil meshUtil;
		meshUtil.create(triangleVertices, triangleVertices2, 3);
		//meshUtil.create(triangleVertices2, sizeof(triangleVertices2) / sizeof(triangleVertices2[0]));


		/*float points[6] = {
			-0.8f,-0.5f, //left
			0.0f,0.9f, //top
			0.5f,-0.7f //right
		};*/

		/*unsigned int buffer;
		//create buffer
		glGenBuffers(1, &buffer);

		//bind the buffer to vertex attributes
		glBindBuffer(GL_ARRAY_BUFFER, buffer);

		//init the buffer
		glBufferData(GL_ARRAY_BUFFER, 6 * sizeof(float), points, GL_STATIC_DRAW);

		glEnableVertexAttribArray(0);
		glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), 0);*/

		shaderUtil.bind();

		float n = 0.2f;
		bool goUp = true;

		/* Loop until the user closes the window */
		while (!glfwWindowShouldClose(window))
		{
			if (goUp) { n += 0.02f; if (n > 1.0f) { goUp = false; } }
			else { n -= 0.02f; if (n < 0.2f) { goUp = true; } }
			/* Render here */
			glClearColor(0.0f, 0.15f, 0.3f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT);

			//glDrawArrays(GL_TRIANGLES, 0, 3);
			meshUtil.draw();

			/* Scaling shape and tinting color animation */
			//shaderUtil.scale(n);
			//shaderUtil.tint(n);

			/* Swap front and back buffers */
			glfwSwapBuffers(window);

			/* Poll for and process events */
			glfwPollEvents();
		}

		shaderUtil.unbind();
	}
	

	glfwTerminate();
	return 1;
}


