#define GLEW_STATIC
#include <GLEW/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

#include "ShaderUtil.h"
#include "TextureUtil.h"
#include "MeshUtil.h"
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
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

	/* Create a windowed mode window and its OpenGL context */
	window = glfwCreateWindow(800, 600, "OpenGL is awesome", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		return -1;
	}
	
	/* Make the window's context current */
	glfwMakeContextCurrent(window);
	// enable depth test
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS); // try GL_ALWAYS to freak out
	// enable alpha support
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	// log the version
	printf("OpenGL version supported by this platform (%s): \n", glGetString(GL_VERSION));

	GLenum err = glewInit();
	if (GLEW_OK != err)
	{
		/* Problem: glewInit failed, something is seriously wrong. */
		fprintf(stderr, "Error: %s\n", glewGetErrorString(err));
	}
	else {
		fprintf(stdout, "Status: Using GLEW %s\n", glewGetString(GLEW_VERSION));

		//for a regular triangle
		Vertex triangleVerticesFirstExample[] = {
			Vertex(vec3(-0.8f,-0.5f,0.0f)),
			Vertex(vec3(0.0f,0.9f,0.0f)),
			Vertex(vec3(0.5f,-0.7f,0.0f))
		};

		//for illuminati triangle
		Vertex triangleVertices[] = {
			Vertex(vec3(-0.5f,-0.5f,0.0f)),
			Vertex(vec3(0.5f,-0.5f,0.0f)),
			Vertex(vec3(0.0f,0.5f,0.0f))
		};

		//for square
		Vertex squareVertices[] = {
			Vertex(vec3(-0.5f,-0.5f,0.0f)),
			Vertex(vec3(0.5f,-0.5f,0.0f)),
			Vertex(vec3(0.5f,0.5f,0.0f)),
			Vertex(vec3(-0.5f,0.5f,0.0f)),
		};

		//for square
		unsigned short squareIndices[6] = {
			0,1,2,
			2,3,0
		};

		//for illuminati texture
		float textureCoordinates[6] = {
			0.25f,0.1f, //lower left
			0.75f,0.1f, //lower right
			0.5f,0.9f  //top center
		};

		//for cube !!be aware this is unoptimized drawing without element buffer array!!
		Vertex cubaData[36] = {
			Vertex(-1.0f,-1.0f,-1.0f,1.0f,0.0f,0.0f,1.0f),
			Vertex(-1.0f,-1.0f, 1.0f,1.0f,0.0f,0.0f,1.0f),
			Vertex(-1.0f, 1.0f, 1.0f,1.0f,0.0f,0.0f,1.0f), 
			Vertex(1.0f, 1.0f,-1.0f,1.0f,0.0f,0.0f,1.0f), 
			Vertex(-1.0f,-1.0f,-1.0f,1.0f,0.0f,0.0f,1.0f),
			Vertex(-1.0f, 1.0f,-1.0f,1.0f,0.0f,0.0f,1.0f), 
			Vertex(1.0f,-1.0f, 1.0f,0.0f,1.0f,0.0f,1.0f),
			Vertex(-1.0f,-1.0f,-1.0f,0.0f,1.0f,0.0f,1.0f),
			Vertex(1.0f,-1.0f,-1.0f,0.0f,1.0f,0.0f,1.0f),
			Vertex(1.0f, 1.0f,-1.0f,0.0f,1.0f,0.0f,1.0f),
			Vertex(1.0f,-1.0f,-1.0f,0.0f,1.0f,0.0f,1.0f),
			Vertex(-1.0f,-1.0f,-1.0f,0.0f,1.0f,0.0f,1.0f),
			Vertex(-1.0f,-1.0f,-1.0f,0.0f,0.0f,1.0,1.0f),
			Vertex(-1.0f, 1.0f, 1.0f,0.0f,0.0f,1.0,1.0f),
			Vertex(-1.0f, 1.0f,-1.0f,0.0f,0.0f,1.0,1.0f),
			Vertex(1.0f,-1.0f, 1.0f,0.0f,0.0f,1.0,1.0f),
			Vertex(-1.0f,-1.0f, 1.0f,0.0f,0.0f,1.0,1.0f),
			Vertex(-1.0f,-1.0f,-1.0f,0.0f,0.0f,1.0,1.0f),
			Vertex(-1.0f, 1.0f, 1.0f,1.0f,1.0f,0.0,1.0f),
			Vertex(-1.0f,-1.0f, 1.0f,1.0f,1.0f,0.0,1.0f),
			Vertex(1.0f,-1.0f, 1.0f,1.0f,1.0f,0.0,1.0f),
			Vertex(1.0f, 1.0f, 1.0f,1.0f,1.0f,0.0,1.0f),
			Vertex(1.0f,-1.0f,-1.0f,1.0f,1.0f,0.0,1.0f),
			Vertex(1.0f, 1.0f,-1.0f,1.0f,1.0f,0.0,1.0f),
			Vertex(1.0f,-1.0f,-1.0f,0.0f,1.0f,1.0f,1.0f),
			Vertex(1.0f, 1.0f, 1.0f,0.0f,1.0f,1.0f,1.0f),
			Vertex(1.0f,-1.0f, 1.0f,0.0f,1.0f,1.0f,1.0f),
			Vertex(1.0f, 1.0f, 1.0f,0.0f,1.0f,1.0f,1.0f),
			Vertex(1.0f, 1.0f,-1.0f,0.0f,1.0f,1.0f,1.0f),
			Vertex(-1.0f, 1.0f,-1.0f,0.0f,1.0f,1.0f,1.0f),
			Vertex(1.0f, 1.0f, 1.0f,1.0f,0.0f,1.0f,1.0f),
			Vertex(-1.0f, 1.0f,-1.0f,1.0f,0.0f,1.0f,1.0f),
			Vertex(-1.0f, 1.0f, 1.0f,1.0f,0.0f,1.0f,1.0f),
			Vertex(1.0f, 1.0f, 1.0f,1.0f,0.0f,1.0f,1.0f),
			Vertex(-1.0f, 1.0f, 1.0f,1.0f,0.0f,1.0f,1.0f),
			Vertex(1.0f,-1.0f, 1.0f,1.0f,0.0f,1.0f,1.0f)
		};
			
		ShaderUtil shaderUtil;
		shaderUtil.load("res/basicShader.v", "res/basicShader.f");

		//TextureUtil textureUtil;
		//textureUtil.load("res/illuminati.png");

		MeshUtil meshUtil;
		//meshUtil.create(triangleVertices, textureCoordinates, 3);
		meshUtil.createCube(cubaData);

		PhysicsUtil physicsUtil;
		physicsUtil.flushTransformValues();

		Camera cam(vec3(0,0,6), 70.0f, (float)(800/600), 0.01f, 1000.0f);
	
		shaderUtil.bind();
		//textureUtil.bind();

		//testing variables
		float n = 0.2f;
		bool goUp = true;
		float c = 0.00001f;
		//FPS counter variables
		double lastTime = glfwGetTime();
		int frames = 0;

		/* Loop until the user closes the window */
		while (!glfwWindowShouldClose(window))
		{
			double currentTime = glfwGetTime();
			frames++;
			if (currentTime - lastTime >= 1.0) { 
				printf("%f ms/frame\n", 1000.0 / double(frames));
				const string title = "OpenGL is awesome [" + to_string(frames) + " FPS]";
				glfwSetWindowTitle(window, title.c_str());
				frames = 0;
				lastTime += 1.0;
			}
			if (goUp) { n += 0.02f; if (n > 1.0f) { goUp = false; } }
			else { n -= 0.02f; if (n < 0.2f) { goUp = true; } }

			/* Render here */
			glClearColor(0.0f, 0.15f, 0.3f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

			vec3 test1(physicsUtil.getPosition()); //position
			vec3 test2(physicsUtil.getRotation()); //rotation
			//vec3 test3(cosf(c), cosf(c), cosf(c)); //scale
			test1.x = sinf(c);
			test1.z = 2 * cosf(c);
			test2.z += 0.05f;
			test2.y += 0.05f;
			test2.x += 0.05f;

			physicsUtil.setPosition(test1);
			physicsUtil.setRotation(test2);
			//physicsUtil.setScale(test3);
			
			physicsUtil.update(cam,shaderUtil.getLocMVP());

			//meshUtil.draw();
			meshUtil.drawCube();

			/* Swap front and back buffers */
			glfwSwapBuffers(window);

			/* Poll for and process events */
			glfwPollEvents();
			c += 0.01f;
		}

		shaderUtil.unbind();
		//textureUtil.unbind();
	}

	glfwTerminate();
	return 1;
}


