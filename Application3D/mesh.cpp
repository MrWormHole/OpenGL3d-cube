#include "mesh.h"

Mesh::Mesh(Vertex * vertices, unsigned int numberOfVertices)
{
	myDrawCount = numberOfVertices;

	glGenVertexArrays(1, &myVertexArrayObject);
	glBindVertexArray(myVertexArrayObject);

	glGenBuffers(number_of_buffer, myVertexArrayBuffers);
	glBindBuffer(GL_ARRAY_BUFFER,myVertexArrayBuffers[position_of_vertex_buffer]);
	glBufferData(GL_ARRAY_BUFFER, numberOfVertices * sizeof(vertices[0]),vertices,GL_STATIC_DRAW);
	
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,0,0);

	glBindVertexArray(0);
}

Mesh::~Mesh() {
	glDeleteVertexArrays(1, &myVertexArrayObject);
}

void Mesh::draw() {
	glBindVertexArray(myVertexArrayObject);
	
	glDrawArrays(GL_TRIANGLES,0,myDrawCount);

	glBindVertexArray(0);
}