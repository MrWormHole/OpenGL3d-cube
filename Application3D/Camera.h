#include <GLM/glm.hpp>
#define GLM_ENABLE_EXPERIMENTAL
#include <GLM/gtx/transform.hpp>
#include <iostream>

#include "PhysicsUtil.h"

using namespace std;
using namespace glm;

class Camera
{
public:
	Camera(const vec3& position, float fov, float aspectRatio, float zNear, float zFar)
	{
		cout << "[INFO] Camera started working" << endl;
		cameraPosition = position;
		forwardDirection = vec3(0, 0, -1);
		upDirection = vec3(0, 1, 0);
		viewMatrix = lookAt(cameraPosition, cameraPosition + forwardDirection, upDirection);
		perspectiveMatrix = perspective(fov, aspectRatio, zNear, zFar);
		
	}
	virtual ~Camera() { cout << "[INFO] Camera stopped working" << endl; };

	inline void debugCameraPosition() { cout << cameraPosition.x << " " << cameraPosition.y << " " << cameraPosition.z << endl; };

	inline vec3 getCameraPosition() { return cameraPosition; }
	inline vec3 getForwardDirection() { return forwardDirection; }
	inline vec3 getUpDirection() { return upDirection; }

	inline void setCameraPosition(const vec3 pos) { cameraPosition = pos; }
	inline void setForwardDirection(const vec3 forward) { forwardDirection = forward; }
	inline void setUpDirection(const vec3 up) { upDirection = up; }

	inline const mat4 calculateMVP(PhysicsUtil* physicsUtil) {
		return (perspectiveMatrix * viewMatrix * (physicsUtil->getModelMatrix())); // projection M * view M * model M
	}

	inline void setLocMVP(GLint value) { locMVP = value; }

	void update(PhysicsUtil* physicsUtil);

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

void Camera::update(PhysicsUtil* physicsUtil) {
	if (locMVP != -1) {
		glUniformMatrix4fv(locMVP, 1, GL_FALSE, &(calculateMVP(physicsUtil)[0][0]));
	}
	else {
		cout << "can not find location of Model-View-Projection variable" << endl;
	}
}

void Camera::processKeyboardInput(GLFWwindow* window, double deltaTime) {
	float cameraSpeed = 0.08f * (float)(deltaTime);
	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS) {
		cameraPosition += cameraSpeed * forwardDirection;
	}
	if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS) {
		cameraPosition -= cameraSpeed * forwardDirection;
	}
	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS) {
		cameraPosition -= normalize(cross(forwardDirection, upDirection)) * cameraSpeed;
	}
	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS) {
		cameraPosition += normalize(cross(forwardDirection, upDirection)) * cameraSpeed;
	}
	viewMatrix = lookAt(cameraPosition, cameraPosition + forwardDirection, upDirection);
}

void Camera::processMouseInput(double mousePositionX, double mousePositionY) {
	if (firstMouse)
	{
		lastX = (float)(mousePositionX);
		lastY = (float)(mousePositionY);
		firstMouse = false;
	}

	float xoffset = float(mousePositionX) - lastX;
	float yoffset = lastY - float(mousePositionY);
	lastX = (float)(mousePositionX);
	lastY = (float)(mousePositionY);

	float sensitivity = 0.08f;
	xoffset *= sensitivity;
	yoffset *= sensitivity;

	yaw = mod(yaw + xoffset, 360.0f);
	pitch += yoffset;

	if (pitch > 89.0f) { pitch = 89.0f; }
	if (pitch < -89.0f) { pitch = -89.0f; }

	vec3 front;
	front.x = cos(radians(pitch)) * cos(radians(yaw));
	front.y = sin(radians(pitch));
	front.z = cos(radians(pitch)) * sin(radians(yaw));
	forwardDirection = normalize(front);
	viewMatrix = lookAt(cameraPosition, cameraPosition + forwardDirection, upDirection);
}


