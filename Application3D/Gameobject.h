#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <GLM/glm.hpp>
#define GLM_ENABLE_EXPERIMENTAL
#include <GLM/gtx/transform.hpp>
#include <iostream>
#include <string>

using namespace std;
using namespace glm;

class Gameobject {
public:
	Gameobject();
	Gameobject(string GameobjectName);
	~Gameobject();

	inline vec3 getPosition() { return _position; }
	inline vec3 getRotation() { return _rotation; }
	inline vec3 getScale() { return _scale; }
	inline string getName() { return _name; }
	inline int getRendererID() { return r_id; }

	inline void setPosition(const vec3& position) { _position = position; }
	inline void setRotation(const vec3& rotation) { _rotation = rotation; }
	inline void setScale(const vec3& scale) { _scale = scale; }
	inline void setName(const string& name) { _name = name; }
	inline void setRendererID(const int& rendererID) { r_id = rendererID; }

	inline void debugPosition() { cout << _position.x << " " << _position.y << " " << _position.z << endl; };
	inline void debugRotation() { cout << _rotation.x << " " << _rotation.y << " " << _rotation.z << endl; };
	inline void debugScale() { cout << _scale.x << " " << _scale.y << " " << _scale.z << endl; };
	inline void debugTotalCount() { cout << "Total gameobjects counted: " << total_gameobjects_count << endl; }

	const mat4 getModelMatrix();
private:
	vec3 _position;
	vec3 _rotation;
	vec3 _scale;
	string _name;
	int r_id; //for renderer order
	static int total_gameobjects_count;
};

#endif
