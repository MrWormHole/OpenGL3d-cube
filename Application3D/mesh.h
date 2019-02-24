#ifndef MESH_H
#define MESH_H

#include <glm/glm.hpp>
#include <GL/glew.h>

struct Vertex {
	glm::vec3 pos;

	Vertex(const glm::vec3& pos) {
		this->pos = pos;
	}
};

class Mesh {
public:
	Mesh(Vertex* vertices,unsigned int numberOfVertices);
	virtual ~Mesh();
	void draw();	
protected:
private:
	enum {
		position_of_vertex_buffer,
		number_of_buffer
	};
	GLuint myVertexArrayObject;
	GLuint myVertexArrayBuffers[number_of_buffer];
	unsigned int myDrawCount;

	Mesh(const Mesh& other);
	Mesh& operator=(const Mesh& other);
};

#endif
