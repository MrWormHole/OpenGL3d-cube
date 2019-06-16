#ifndef DISPLAY_H
#define DISPLAY_H

#define GLEW_STATIC
#include <GLEW/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <string>
#include <vector>

#include "Camera.h"
#include "Renderer.h"

class Display
{
public:
	bool displayError = false;
	GLenum err = GL_FALSE;

	Display();
	virtual ~Display();
	void setCamera(Camera& camera) { cam = &camera; if (cam != nullptr) { cout << "*** cam pointer is set ***" << endl; } }
	void setRenderer(Renderer& renderer) { rrr = &renderer; if (rrr != nullptr) { cout << "*** rrr pointer is set ***" << endl; } }
	void initialize();
	void create();
	void makeContext();
	void logStatus();
	void destroy();
	void update();
	GLFWwindow* getWindow() { return window; }
private:
	GLFWwindow* window;
	Camera* cam;
	Renderer* rrr;

	int frames = 0;
	double lastTime = 0.0f;
	double currentTime = 0.0f;
	double mousePositionX = 0.0f; double mousePositionY = 0.0f;

	double logFrames();
};


Display::Display()
{
	cout << "[INFO] Display started working" << endl;
}


Display::~Display()
{
	cout << "[INFO] Display stopped working" << endl;
}

void Display::initialize() {
	if (!glfwInit()) {
		displayError = true;
	};
	if (!displayError) {
		glfwWindowHint(GLFW_SAMPLES, 4); // 4x antialiasing
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); // We want OpenGL 3.3
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); // We don't want the old OpenGL 
		glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
	}
}

void Display::create() {
	if (!displayError) {
		window = glfwCreateWindow(800, 600, "OpenGL is awesome", NULL, NULL);
		if (!window)
		{
			displayError = true;
			destroy();
		}
	}
}

void Display::makeContext() {
	if (!displayError) {
		glfwMakeContextCurrent(window);
		glEnable(GL_DEPTH_TEST);
		glDepthFunc(GL_LESS); // try GL_ALWAYS to freak out
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
	}
}

void Display::logStatus() {
	printf("OpenGL version supported by this platform (%s): \n", glGetString(GL_VERSION));
	err = glewInit();
	if (err != GLEW_OK) {
		fprintf(stderr, "Error: %s\n", glewGetErrorString(err));
		displayError = true;
	}
	else {
		fprintf(stdout, "Status: Using GLEW %s\n", glewGetString(GLEW_VERSION));
	}
}

double Display::logFrames() {
	currentTime = glfwGetTime();
	frames++;
	if (currentTime - lastTime >= 1.0) {
		//printf("[ENGINE-INFO] %f ms/frame\n", 1000.0 / double(frames));
		const string title = "OpenGL is awesome [" + to_string(frames) + " FPS]";
		glfwSetWindowTitle(window, title.c_str());
		frames = 0;
		lastTime += 1.0;
	}
	return currentTime - lastTime;
}

void Display::destroy() {
	glfwTerminate();
}

void Display::update() {
	lastTime = glfwGetTime();
	
	if (!displayError) {
		while (!glfwWindowShouldClose(window)) {
			double deltaTime = logFrames();

			/* Input processing starts here*/
			cam->processKeyboardInput(window, deltaTime);
			glfwGetCursorPos(window, &mousePositionX, &mousePositionY);
			cam->processMouseInput(mousePositionX, mousePositionY);
			/* Input processing ends here*/

			/* Rendering starts here */			
			rrr->render();
			/* Rendering ends here */

			glfwSwapBuffers(window);
			glfwPollEvents();
		}
	}
	else {
		destroy();
	}
}

#endif

