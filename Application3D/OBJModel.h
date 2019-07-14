#ifndef OBJ_MODEL_H
#define OBJ_MODEL_H

#include <glm/glm.hpp>
#include <vector>
#include <string>


using namespace std;
using namespace glm;

class OBJIndex {
public:
	unsigned int vertexIndex;
	unsigned int uvIndex;
	unsigned int normalIndex;
};

class OBJModel
{
public:
	int totalVertexCount; 
	OBJModel(const string& fileName);
	virtual ~OBJModel();

	inline vector<vec3> getVertices() { return vertices; }
	inline vector<vec2> getUvs() { return uvs; };
	inline vector<vec3> getNormals() { return normals; };
private:
	string fileName;
	bool hasUVs = false;
	bool hasNormals = false;

	vector<vec3> vertices;
	vector<vec2> uvs;
	vector<vec3> normals;
};

#endif 

