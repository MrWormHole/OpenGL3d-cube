#ifndef CAMERA_H
#define CAMERA_H

#include <GLEW/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

#include "Gameobject.h"

using namespace std;
using namespace glm;

class Camera
{
public:
	Camera(const vec3& position, float fov, float aspectRatio, float zNear, float zFar);
	virtual ~Camera();

	inline void debugCameraPosition() { cout << cameraPosition.x << " " << cameraPosition.y << " " << cameraPosition.z << endl; };

	inline vec3 getCameraPosition() { return cameraPosition; }
	inline vec3 getForwardDirection() { return forwardDirection; }
	inline vec3 getUpDirection() { return upDirection; }

	inline void setCameraPosition(const vec3 pos) { cameraPosition = pos; }
	inline void setForwardDirection(const vec3 forward) { forwardDirection = forward; }
	inline void setUpDirection(const vec3 up) { upDirection = up; }

	inline void setLocMVP(GLint value) { locMVP = value; }

	const mat4 calculateMVPmatrix(Gameobject* gameobject);

	void update(Gameobject* gameobject);

	void processKeyboardInput(GLFWwindow* window, double deltaTime);

	void processMouseInput(double mousePositionX, double mousePositionY);

private:
	vec3 cameraPosition;
	vec3 forwardDirection;
	vec3 upDirection;
	mat4 viewMatrix;
	mat4 perspectiveMatrix;
	GLint locMVP;
	float yaw =	 270.0f;
	float pitch = 0.0f;
	float lastX = 400.0f, lastY = 300.0f;
	bool firstMouse = true;
};

#endif
