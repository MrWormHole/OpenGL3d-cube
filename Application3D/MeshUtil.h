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
	Vertex(const vec3& positionXYZ) {
		this->positionXYZ = positionXYZ;
	}

	Vertex(const float x,const float y,const float z) {
		positionXYZ = vec3(x, y, z);
	}

	inline void setPos(const vec3& pos) { positionXYZ = pos; } //move this to base class
	inline vec3 getPos() { return positionXYZ; } //move this to base class
protected:
	vec3 positionXYZ;
};

class ColorfulVertex : public Vertex {
public:
	ColorfulVertex() : Vertex() {};
	ColorfulVertex(const vec3& positionXYZ,const vec4& colorRGBA) : Vertex(positionXYZ) {
		this->colorRGBA = colorRGBA;
	}

	ColorfulVertex(const float x, const float y, const float z, const float r, const float g, const float b, const float a) : Vertex(x,y,z) {
		colorRGBA = vec4(r, g, b, a);
	}

	inline void setColor(const vec4& color) { colorRGBA = color; }
	inline vec4 getColor() { return colorRGBA; }
private:
	vec4 colorRGBA;
};

class TextureVertex : public Vertex {
public:
	TextureVertex() : Vertex() {};
	TextureVertex(const vec3& positionXYZ, const vec2& textureXY) : Vertex(positionXYZ) {
		this->textureXY = textureXY;
	}

	TextureVertex(const float x, const float y, const float z, const float t1, const float t2) : Vertex(x,y,z) {
		textureXY = vec2(t1, t2);
	}

	inline void setTexCoord(const vec2& texCoord) { textureXY = texCoord; }
	inline vec2 getTexCoord() { return textureXY; }
private:
	vec2 textureXY;
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
	void createCube(TextureVertex* vertices, Gameobject* gameobject);

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

