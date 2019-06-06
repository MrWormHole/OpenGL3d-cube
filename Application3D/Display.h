#define GLEW_STATIC
#include <GLEW/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <string>

#include "Camera.h"
#include "MeshUtil.h"

class Display
{
public:
	bool displayError = false;
	GLenum err = GL_FALSE;

	Display();
	virtual ~Display();
	void setCamera(Camera& camera) { cam = &camera; if (cam != nullptr) { cout << "*** cam pointer is set ***" << endl; } }
	void setMeshUtil(MeshUtil& meshUtil) { mu = &meshUtil; if (mu != nullptr) { cout << "*** mu pointer is set ***" << endl; } }
	void setPhysicsUtil(PhysicsUtil& physicsUtil) { pu = &physicsUtil; if (pu != nullptr) { cout << "*** pu pointer is set ***" << endl; } }
	void initialize();
	void create();
	void makeContext();
	void logStatus();
	void destroy();
	void update();
	void draw(int drawCount);
private:
	GLFWwindow* window;
	Camera* cam;
	MeshUtil* mu;
	PhysicsUtil* pu;
	int frames = 0;
	double lastTime;

	void logFrames();
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

void Display::logFrames() {
	double currentTime = glfwGetTime();
	frames++;
	if (currentTime - lastTime >= 1.0) {
		printf("[INFO] %f ms/frame\n", 1000.0 / double(frames));
		const string title = "OpenGL is awesome [" + to_string(frames) + " FPS]";
		glfwSetWindowTitle(window, title.c_str());
		frames = 0;
		lastTime += 1.0;
	}
}

void Display::destroy() {
	glfwTerminate();
}

void Display::update() {
	double lastTime = glfwGetTime();
	//testing variables
	float n = 0.2f;
	bool goUp = true;
	float c = 0.00001f;
	
	if (!displayError) {
		while (!glfwWindowShouldClose(window)) {
			logFrames();
			
			if (goUp) { n += 0.02f; if (n > 1.0f) { goUp = false; } }
			else { n -= 0.02f; if (n < 0.2f) { goUp = true; } }

			/* Render here */
			glClearColor(0.0f, 0.15f, 0.3f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

			vec3 test1(pu->getPosition()); //position
			vec3 test2(pu->getRotation()); //rotation
			//vec3 test3(cosf(c), cosf(c), cosf(c)); //scale
			test1.x = sinf(c);
			test1.z = 2 * cosf(c);
			test2.z += 0.05f;
			test2.y += 0.05f;
			test2.x += 0.05f;

			pu->setPosition(test1);
			pu->setRotation(test2);
			//pu->setScale(test3);

			cam->update(pu);

			draw(36); //draw count depends on vertex count

			glfwSwapBuffers(window);
			glfwPollEvents();
			c += 0.01f;
		}
	}
	else {
		destroy();
	}
}

void Display::draw(int drawCount) {
	glBindVertexArray(mu->getVAO());
	glDrawArrays(GL_TRIANGLES, 0, drawCount);
	glBindVertexArray(0);
}
