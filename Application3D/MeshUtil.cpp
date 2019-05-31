#include "MeshUtil.h"

MeshUtil::MeshUtil()
{
	glGenVertexArrays(1, &myVAO);
	glGenBuffers(2, myVAB);
	cout << "MeshUtil started" << endl;
}

MeshUtil::~MeshUtil()
{
	cout << "MeshUtil stopped" << endl;
}

void MeshUtil::create(Vertex* vertices, Vertex* vertices2, unsigned int numberOfVertices) {
	myDrawCount = numberOfVertices;

	
	glBindVertexArray(myVAO);

	glBindBuffer(GL_ARRAY_BUFFER, myVAB[0]);
	glBufferData(GL_ARRAY_BUFFER, numberOfVertices * sizeof(Vertex), vertices, GL_STATIC_DRAW);
	glEnableVertexAttribArray(8);
	glVertexAttribPointer(8, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 3, 0);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);

	glBindVertexArray(myVAO);

	glBindBuffer(GL_ARRAY_BUFFER, myVAB[1]);
	glBufferData(GL_ARRAY_BUFFER, numberOfVertices * sizeof(Vertex), vertices2, GL_STATIC_DRAW);
	glEnableVertexAttribArray(8);
	glVertexAttribPointer(8, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 3, 0);


	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
}

void MeshUtil::create(Vertex* vertices, unsigned short* indices, unsigned int numberOfVertices) {
	isEABused = true;
	myDrawCount = numberOfVertices;

	glGenVertexArrays(1, &myVAO);
	glGenBuffers(10, myVAB);
	glGenBuffers(10, myEAB);
	
	glBindVertexArray(myVAO);

	glBindBuffer(GL_ARRAY_BUFFER, myVAB[0]);
	glBufferData(GL_ARRAY_BUFFER, 4 * sizeof(Vertex), vertices, GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, myEAB[0]);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, 6 * sizeof(unsigned int), indices, GL_STATIC_DRAW);

	glEnableVertexAttribArray(8);
	glVertexAttribPointer(8, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 3, 0);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
};

void MeshUtil::destroy() {
	glDeleteVertexArrays(1, &myVAO);
}

void MeshUtil::draw() {
	glBindVertexArray(myVAO);
	if (!isEABused) { glDrawArrays(GL_TRIANGLES, 0, myDrawCount); }
	else { glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_SHORT, nullptr); }
	//glBindVertexArray(0);
	/*if (myVAO2 != NULL) {
		glBindVertexArray(myVAO[1]);
		glDrawArrays(GL_TRIANGLES, 0, myDrawCount); 
		//glBindVertexArray(0);
	}*/
}


