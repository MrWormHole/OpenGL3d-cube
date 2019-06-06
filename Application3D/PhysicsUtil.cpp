#include "PhysicsUtil.h"

PhysicsUtil::PhysicsUtil()
{
	cout << "[INFO] PhysicsUtil started" << endl;
}

PhysicsUtil::~PhysicsUtil()
{
	cout << "[INFO] PhysicsUtil stopped" << endl;
}

void PhysicsUtil::flushTransformValues() {
	myPosition = vec3();
	myRotation = vec3();
	myScale = vec3(1.0f, 1.0f, 1.0f);
}
