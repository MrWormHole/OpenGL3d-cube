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

	inline const mat4 calculateMVP(PhysicsUtil* physicsUtil) {
		return (perspectiveMatrix * viewMatrix * (physicsUtil->getModelMatrix())); // projection M * view M * model M
	}

	inline void setLocMVP(GLint value) { locMVP = value; }

	void update(PhysicsUtil* physicsUtil);
private:
	vec3 cameraPosition;
	vec3 forwardDirection;
	vec3 upDirection;
	mat4 viewMatrix;
	mat4 perspectiveMatrix;
	GLint locMVP;
};

void Camera::update(PhysicsUtil* physicsUtil) {
	if (locMVP != -1) {
		glUniformMatrix4fv(locMVP, 1, GL_FALSE, &(calculateMVP(physicsUtil)[0][0]));
	}
	else {
		cout << "can not find location of Model-View-Projection variable" << endl;
	}
}

