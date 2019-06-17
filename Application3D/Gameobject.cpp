#include "Gameobject.h"

int Gameobject::total_gameobjects_count = 0;

Gameobject::Gameobject() {
	_position = vec3();
	_rotation = vec3();
	_scale = vec3(1.0f, 1.0f, 1.0f);
	r_id = total_gameobjects_count;
	total_gameobjects_count++;
	cout << "[ENGINE-INFO] Gameobject " << " is created" << endl;
}

Gameobject::Gameobject(string GameobjectName) : Gameobject() {
	_name = GameobjectName;
	cout << "[ENGINE-INFO] Gameobject " << _name.c_str() << " is created" << endl;
}

Gameobject::~Gameobject() {
	cout << "[ENGINE-INFO] Gameobject " << _name.c_str() << " is destroyed" << endl;
}

const mat4 Gameobject::getModelMatrix() {
	mat4 positionMatrix = translate(_position);
	mat4 rotationXMatrix = rotate(_rotation.x, vec3(1, 0, 0));
	mat4 rotationYMatrix = rotate(_rotation.y, vec3(0, 1, 0));
	mat4 rotationZMatrix = rotate(_rotation.z, vec3(0, 0, 1));
	mat4 rotationMatrix = rotationZMatrix * rotationYMatrix * rotationXMatrix;
	mat4 scaleMatrix = scale(_scale);

	return positionMatrix * rotationMatrix * scaleMatrix;
}