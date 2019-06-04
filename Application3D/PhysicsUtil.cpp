#include "PhysicsUtil.h"

PhysicsUtil::PhysicsUtil()
{
	cout << "PhysicsUtil started" << endl;
}

PhysicsUtil::~PhysicsUtil()
{
	cout << "PhysicsUtil stopped" << endl;
}

void PhysicsUtil::update(GLint locModel) {
	if (locModel != -1) {
		glUniformMatrix4fv(locModel, 1, GL_FALSE, &(getModelMatrix()[0][0]));
	}
	else {
		cout << "can not find location of transform variable" << endl;
	}
}

void PhysicsUtil::flushTransformValues() {
	myPosition = vec3();
	myRotation = vec3();
	myScale = vec3(1.0f, 1.0f, 1.0f);
}
