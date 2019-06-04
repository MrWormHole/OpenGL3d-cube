#include "PhysicsUtil.h"

PhysicsUtil::PhysicsUtil()
{
	cout << "PhysicsUtil started" << endl;
}

PhysicsUtil::~PhysicsUtil()
{
	cout << "PhysicsUtil stopped" << endl;
}

void PhysicsUtil::update(Camera& camera,GLint locMVP) {
	if (locMVP != -1) {
		glUniformMatrix4fv(locMVP, 1, GL_FALSE, &(getMVPmatrix(camera)[0][0]));
	}
	else {
		cout << "can not find location of Model-View-Projection variable" << endl;
	}
}

void PhysicsUtil::flushTransformValues() {
	myPosition = vec3();
	myRotation = vec3();
	myScale = vec3(1.0f, 1.0f, 1.0f);
}
