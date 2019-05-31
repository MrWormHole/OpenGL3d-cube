#include <GLM/glm.hpp>
#define GLM_ENABLE_EXPERIMENTAL
#include <GLM/gtx/transform.hpp>
#include <iostream>

using namespace std;
using namespace glm;

class PhysicsUtil
{
public:
	PhysicsUtil();
	virtual ~PhysicsUtil();

	inline vec3 getPosition() { return myPosition; }
	inline vec3 getRotation() { return myRotation; }
	inline vec3 getScale() { return myScale; }

	inline void setPosition(vec3& position) { myPosition = position; }
	inline void setRotation(vec3& rotation) { myRotation = rotation; }
	inline void setScale(vec3& scale) { myScale = scale; }

	inline const mat4 getModelMatrix() {
		mat4 positionMatrix = translate(myPosition);
		mat4 rotationXMatrix = rotate(myRotation.x, vec3(1, 0, 0));
		mat4 rotationYMatrix = rotate(myRotation.y, vec3(0, 1, 0));
		mat4 rotationZMatrix = rotate(myRotation.z, vec3(0, 0, 1));
		mat4 rotationMatrix = rotationZMatrix * rotationYMatrix * rotationXMatrix;
		mat4 scaleMatrix = scale(myScale);

		return positionMatrix * rotationMatrix * scaleMatrix;
	}
private:
	vec3 myPosition;
	vec3 myRotation;
	vec3 myScale;

};

