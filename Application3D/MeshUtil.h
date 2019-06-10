#include <GLEW/glew.h>
#include <glm/glm.hpp>
#include <iostream>
#include <vector>

using namespace std;
using namespace glm;

class Vertex {
public:
	Vertex(const vec3& vector3D) {
		this->vector3D = vector3D;
	}

	Vertex(const float x,const float y,const float z) {
		vector3D = vec3(x, y, z);
		//colorRGBA = vec4(r, g, b, a);
	}
protected:
	vec3 vector3D;
};

class ColorfulVertex : Vertex {
public:
	ColorfulVertex(const vec3& vector3D,const vec4& colorRGBA) : Vertex(vector3D) {
		this->colorRGBA = colorRGBA;
	}

	ColorfulVertex(const float x, const float y, const float z, const float r, const float g, const float b, const float a) : Vertex(x,y,z) {
		colorRGBA = vec4(r, g, b, a);
	}
private:
	vec4 colorRGBA;
};

class MeshUtil
{
public:
	MeshUtil();
	~MeshUtil();

	//creating the mesh
	void create(Vertex* vertices, float* textureCoordinates,unsigned int numberOfVertices);

	void create(Vertex* vertices, unsigned short* indices, unsigned int numberOfVertices);

	//destroy the mesh
	void destroy();

	//draw the mesh
	void draw();

	//create a cube
	void createCube(ColorfulVertex* cubeData);

	void createCube(Vertex* vertices, unsigned int* indices);

	//draw a cube
	void drawCube();

	inline GLuint getVAO() { return myVAO; }

private:
	unsigned int myDrawCount;
	bool isEABused = false;
	int rendererID = 0;
	GLuint myVAO; //vertex array object
	GLuint myVAB[10]; //vertex array buffer
	GLuint myEAB[10]; //element array buffer
};

