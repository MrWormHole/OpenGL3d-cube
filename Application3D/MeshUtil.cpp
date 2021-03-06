#include "MeshUtil.h"

MeshUtil::MeshUtil()
{
	cout << "[INFO] MeshUtil started" << endl;
	glGenVertexArrays(objCount, myVAO);
	glGenBuffers(objCount, myVAB);
}

MeshUtil::~MeshUtil()
{
	cout << "[INFO] MeshUtil stopped" << endl;
}

void MeshUtil::create(Vertex* vertices,float* textureCoordinates, unsigned int numberOfVertices) {
	myDrawCount = numberOfVertices;

	glGenVertexArrays(10, myVAO);
	glGenBuffers(2, myVAB);
	
	glBindVertexArray(myVAO[0]);

	glBindBuffer(GL_ARRAY_BUFFER, myVAB[0]);
	glBufferData(GL_ARRAY_BUFFER, numberOfVertices * sizeof(vec3), vertices, GL_STATIC_DRAW);
	glEnableVertexAttribArray(8);
	glVertexAttribPointer(8, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 3, 0);

	glBindBuffer(GL_ARRAY_BUFFER, myVAB[1]);
	glBufferData(GL_ARRAY_BUFFER, numberOfVertices * sizeof(float) * 2, textureCoordinates, GL_STATIC_DRAW);
	glEnableVertexAttribArray(9);
	glVertexAttribPointer(9, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2, 0);

	glBindBuffer(GL_ARRAY_BUFFER, 0); 
	glBindVertexArray(0);
}

void MeshUtil::create(Vertex* vertices, unsigned short* indices, unsigned int numberOfVertices) {
	isEABused = true;
	myDrawCount = numberOfVertices;

	glGenVertexArrays(1, myVAO);
	glGenBuffers(10, myVAB);
	glGenBuffers(10, myEAB);
	
	glBindVertexArray(myVAO[0]);

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
	glDeleteVertexArrays(objCount, myVAO);
}

void MeshUtil::draw() {
	glBindVertexArray(myVAO[0]);

	if (!isEABused) { glDrawArrays(GL_TRIANGLES, 0, myDrawCount); }
	else { glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_SHORT, nullptr); }

	glBindVertexArray(0);
}

void MeshUtil::createCube(TextureVertex* vertices, Gameobject* gameobject) {
	myDrawCount = 36; //not optimized yet

	glBindVertexArray(myVAO[gameobject->getRendererID()]);
	glBindBuffer(GL_ARRAY_BUFFER, myVAB[gameobject->getRendererID()]);
	glBufferData(GL_ARRAY_BUFFER, 36 * sizeof(TextureVertex), vertices, GL_STATIC_DRAW);
	glEnableVertexAttribArray(8);
	glVertexAttribPointer(8, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 5, (GLvoid *)0);
	glEnableVertexAttribArray(12);
	glVertexAttribPointer(12, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 5, (GLvoid *)(3 * sizeof(float)));

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
}

void MeshUtil::createCube(ColorfulVertex* vertices,Gameobject* gameobject) {
	myDrawCount = 36; //not optimized yet

	glBindVertexArray(myVAO[gameobject->getRendererID()]);
	glBindBuffer(GL_ARRAY_BUFFER, myVAB[gameobject->getRendererID()]);
	glBufferData(GL_ARRAY_BUFFER, 36 * sizeof(ColorfulVertex), vertices, GL_STATIC_DRAW);
	glEnableVertexAttribArray(8);
	glVertexAttribPointer(8, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 7, (GLvoid *)0);
	glEnableVertexAttribArray(10);
	glVertexAttribPointer(10, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 7, (GLvoid *)(3 * sizeof(float)));

	glBindBuffer(GL_ARRAY_BUFFER, 0); 
	glBindVertexArray(0);
}

void MeshUtil::createCube(Vertex* vertices, unsigned int* indices) {
	isEABused = true;

	glGenVertexArrays(1, myVAO);
	glGenBuffers(10, myVAB);
	glGenBuffers(10, myEAB);

	glBindVertexArray(myVAO[0]);

	glBindBuffer(GL_ARRAY_BUFFER, myVAB[0]);
	glBufferData(GL_ARRAY_BUFFER, 8 * sizeof(Vertex), vertices, GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, myEAB[0]);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, 36 * sizeof(unsigned int), indices, GL_STATIC_DRAW);

	glEnableVertexAttribArray(8);
	glVertexAttribPointer(8, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 3, 0);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
}

void MeshUtil::draw(int index) {
	glBindVertexArray(myVAO[index]);

	if (!isEABused) { glDrawArrays(GL_TRIANGLES, 0, myDrawCount); }
	else { glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, nullptr); }

	glBindVertexArray(0);
}

void MeshUtil::createModel(OBJModel& model, Gameobject* gameobject) {
	myDrawCount = model.totalVertexCount;

	glBindVertexArray(myVAO[gameobject->getRendererID()]);
	glBindBuffer(GL_ARRAY_BUFFER, myVAB[gameobject->getRendererID()]);
	glBufferData(GL_ARRAY_BUFFER, model.totalVertexCount * sizeof(OBJIndex) , &model.getVertices()[0], GL_STATIC_DRAW);
	glEnableVertexAttribArray(8);
	glVertexAttribPointer(8, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 3, (GLvoid *)0);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
}


