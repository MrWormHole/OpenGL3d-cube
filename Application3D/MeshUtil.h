#ifndef MESH_UTIL_H
#define MESH_UTIL_H

#include <GLEW/glew.h>
#include <glm/glm.hpp>
#include <iostream>
#include <vector>

#include "Gameobject.h"

using namespace std;
using namespace glm;

class Vertex {
public:
	Vertex() {};
	Vertex(const vec3& vector3D) {
		this->vector3D = vector3D;
	}

	Vertex(const float x,const float y,const float z) {
		vector3D = vec3(x, y, z);
	}
protected:
	vec3 vector3D;
};

class ColorfulVertex : Vertex {
public:
	ColorfulVertex() : Vertex() {};
	ColorfulVertex(const vec3& vector3D,const vec4& colorRGBA) : Vertex(vector3D) {
		this->colorRGBA = colorRGBA;
	}

	ColorfulVertex(const float x, const float y, const float z, const float r, const float g, const float b, const float a) : Vertex(x,y,z) {
		colorRGBA = vec4(r, g, b, a);
	}

	void setPos(const vec3& pos) { vector3D = pos; } //move this to base class
	vec3 getPos() { return vector3D; } //move this to base class

	void setColor(const vec4& color) { colorRGBA = color; }
	vec4 getColor() { return colorRGBA; }
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
	void createCube(ColorfulVertex* cubeData,Gameobject* gameobject);

	void createCube(Vertex* vertices, unsigned int* indices);

	//draw a cube
	void drawCube(int index);

	inline GLuint getVAO(int index) { return myVAO[index]; }

private:
	unsigned int myDrawCount;
	bool isEABused = false;
	int rendererID = 0;
	GLuint myVAO[21]; //vertex array object
	GLuint myVAB[21]; //vertex array buffer
	GLuint myEAB[21]; //element array buffer
};

#endif

