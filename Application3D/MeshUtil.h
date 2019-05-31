#include <GLEW/glew.h>
#include <glm/glm.hpp>
#include <iostream>

using namespace std;
using namespace glm;

struct Vertex {
	vec3 vector3D;

	Vertex(const vec3& vector3D) {
		this->vector3D = vector3D;
	}
};

class MeshUtil
{
public:
	MeshUtil();
	~MeshUtil();

	//creating the mesh
	void create(Vertex* vertices,Vertex* vertices2, unsigned int numberOfVertices);

	void create(Vertex* vertices, unsigned short* indices, unsigned int numberOfVertices);

	//destroy the mesh
	void destroy();

	//draw the mesh
	void draw();

private:
	unsigned int myDrawCount;
	bool isEABused = false;
	int rendererID = 0;
	GLuint myVAO; //vertex array object
	//GLuint myVAO[2];
	GLuint myVAB[10]; //vertex array buffer
	GLuint myEAB[10]; //element array buffer
};

