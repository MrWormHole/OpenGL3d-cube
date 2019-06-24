#include "Camera.h"

Camera::Camera(const vec3& position, float fov, float aspectRatio, float zNear, float zFar)
{
	cout << "[ENGINE-INFO] Camera started" << endl;
	cameraPosition = position;
	forwardDirection = vec3(0, 0, -1);
	upDirection = vec3(0, 1, 0);
	viewMatrix = lookAt(cameraPosition, cameraPosition + forwardDirection, upDirection);
	perspectiveMatrix = perspective(fov, aspectRatio, zNear, zFar);

}

Camera::~Camera() { 
	cout << "[ENGINE-INFO] Camera stopped" << endl; 
};

const mat4 Camera::calculateMVPmatrix(Gameobject* gameobject) {
	return (perspectiveMatrix * viewMatrix * (gameobject->getModelMatrix())); // projection M * view M * model M
}

void Camera::update(Gameobject* gameobject) {
	if (locMVP != -1) {
		glUniformMatrix4fv(locMVP, 1, GL_FALSE, &(calculateMVPmatrix(gameobject)[0][0]));
	}
	else {
		cout << "can not find location of Model-View-Projection variable(locMVP) in Camera" << endl;
	}
}

void Camera::processKeyboardInput(GLFWwindow* window, double deltaTime) {
	float cameraSpeed = 0.16f * (float)(deltaTime);
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