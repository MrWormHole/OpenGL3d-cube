/* DATAS START HERE */

//for a regular triangle
Vertex triangleVerticesFirstExample[] = {
	Vertex(vec3(-0.8f,-0.5f,0.0f)),
	Vertex(vec3(0.0f,0.9f,0.0f)),
	Vertex(vec3(0.5f,-0.7f,0.0f))
};

//for illuminati triangle
Vertex triangleVertices[] = {
	Vertex(vec3(-0.5f,-0.5f,0.0f)),
	Vertex(vec3(0.5f,-0.5f,0.0f)),
	Vertex(vec3(0.0f,0.5f,0.0f))
};

//for illuminati texture
float textureCoordinates[6] = {
		0.25f,0.1f, //lower left
		0.75f,0.1f, //lower right
		0.5f,0.9f  //top center
};

//for square
Vertex squareVertices[] = {
		Vertex(vec3(-0.5f,-0.5f,0.0f)),
		Vertex(vec3(0.5f,-0.5f,0.0f)),
		Vertex(vec3(0.5f,0.5f,0.0f)),
		Vertex(vec3(-0.5f,0.5f,0.0f)),
};

//for square
unsigned short squareIndices[6] = {
	0,1,2,
	2,3,0
};

//points for optimized cube drawing
Vertex cubeVertices[8] = {
	Vertex(vec3(-1.0f,-1.0f,-1.0f)), //0
	Vertex(vec3(-1.0f,-1.0f,1.0f)),  //1
	Vertex(vec3(-1.0f,1.0f,-1.0f)),  //2
	Vertex(vec3(-1.0f,1.0f,1.0f)),   //3
	Vertex(vec3(1.0f,-1.0f,-1.0f)),  //4
	Vertex(vec3(1.0f,-1.0f,1.0f)),   //5
	Vertex(vec3(1.0f,1.0f,-1.0f)),   //6
	Vertex(vec3(1.0f,1.0f,1.0f)),    //7
};

//for optimized cube drawing with only 8 vertices
unsigned int cubeIndices[36] = {
	3,1,5,3,5,7, //5,7,3, // A front 
	7,5,4,7,4,6, //4,6,7, // B right 
	6,4,0,6,0,2, //0,2,6, // C back 
	2,0,1,2,1,3, //1,3,2, // D left 
	2,3,7,2,7,6, //7,6,2, // E upper 
	0,1,5,0,5,4  //5,4,0  // F bottom 
};

//for a colorful cube with 36 colorful vertices
ColorfulVertex cubeDataChunk[36] = {
	// A front 
	ColorfulVertex(-1.0f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f, 1.0f),
	ColorfulVertex(-1.0f, -1.0f, 1.0f, 1.0f, 0.0f, 0.0f, 1.0f),
	ColorfulVertex(1.0f, -1.0f, 1.0f, 1.0f, 0.0f, 0.0f, 1.0f),
	ColorfulVertex(-1.0f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f, 1.0f),
	ColorfulVertex(1.0f, -1.0f, 1.0f, 1.0f, 0.0f, 0.0f, 1.0f),
	ColorfulVertex(1.0f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f, 1.0f),
	// B right
	ColorfulVertex(1.0f, 1.0f, 1.0f, 0.0f, 1.0f, 0.0f, 1.0f),
	ColorfulVertex(1.0f, -1.0f, 1.0f, 0.0f, 1.0f, 0.0f, 1.0f),
	ColorfulVertex(1.0f, -1.0f, -1.0f, 0.0f, 1.0f, 0.0f, 1.0f),
	ColorfulVertex(1.0f, 1.0f, 1.0f, 0.0f, 1.0f, 0.0f, 1.0f),
	ColorfulVertex(1.0f, -1.0f, -1.0f, 0.0f, 1.0f, 0.0f, 1.0f),
	ColorfulVertex(1.0f, 1.0f, -1.0f, 0.0f, 1.0f, 0.0f, 1.0f),
	// C back
	ColorfulVertex(1.0f, 1.0f, -1.0f, 0.0f, 0.0f, 1.0f, 1.0f),
	ColorfulVertex(1.0f, -1.0f, -1.0f, 0.0f, 0.0f, 1.0f, 1.0f),
	ColorfulVertex(-1.0f, -1.0f, -1.0f, 0.0f, 0.0f, 1.0f, 1.0f),
	ColorfulVertex(1.0f, 1.0f, -1.0f, 0.0f, 0.0f, 1.0f, 1.0f),
	ColorfulVertex(-1.0f, -1.0f, -1.0f, 0.0f, 0.0f, 1.0f, 1.0f),
	ColorfulVertex(-1.0f,1.0f,-1.0f, 0.0f, 0.0f, 1.0f, 1.0f),
	// D left 
	ColorfulVertex(-1.0f, 1.0f, -1.0f, 1.0f, 1.0f, 0.0f, 1.0f),
	ColorfulVertex(-1.0f, -1.0f, -1.0f, 1.0f, 1.0f, 0.0f, 1.0f),
	ColorfulVertex(-1.0f, -1.0f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f),
	ColorfulVertex(-1.0f, 1.0f, -1.0f, 1.0f, 1.0f, 0.0f, 1.0f),
	ColorfulVertex(-1.0f, -1.0f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f),
	ColorfulVertex(-1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f),
	// E upper 
	ColorfulVertex(-1.0f, 1.0f, -1.0f, 0.0f, 1.0f, 1.0f, 1.0f),
	ColorfulVertex(-1.0f, 1.0f, 1.0f, 0.0f, 1.0f, 1.0f, 1.0f),
	ColorfulVertex(1.0f, 1.0f, 1.0f, 0.0f, 1.0f, 1.0f, 1.0f),
	ColorfulVertex(-1.0f, 1.0f, -1.0f, 0.0f, 1.0f, 1.0f, 1.0f),
	ColorfulVertex(1.0f, 1.0f, 1.0f, 0.0f, 1.0f, 1.0f, 1.0f),
	ColorfulVertex(1.0f, 1.0f, -1.0f, 0.0f, 1.0f, 1.0f, 1.0f),
	// F bottom 
	ColorfulVertex(-1.0f, -1.0f, -1.0f, 1.0f, 0.0f, 1.0f, 1.0f),
	ColorfulVertex(-1.0f, -1.0f, 1.0f, 1.0f, 0.0f, 1.0f, 1.0f),
	ColorfulVertex(1.0f, -1.0f, 1.0f, 1.0f, 0.0f, 1.0f, 1.0f),
	ColorfulVertex(-1.0f, -1.0f, -1.0f, 1.0f, 0.0f, 1.0f, 1.0f),
	ColorfulVertex(1.0f, -1.0f, 1.0f, 1.0f, 0.0f, 1.0f, 1.0f),
	ColorfulVertex(1.0f, -1.0f, -1.0f, 1.0f, 0.0f, 1.0f, 1.0f)
};

ColorfulVertex cubeDataChunkMovedRightOnX[36] = {
	// A front 
	ColorfulVertex(4.0f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f, 1.0f),
	ColorfulVertex(4.0f, -1.0f, 1.0f, 1.0f, 0.0f, 0.0f, 1.0f),
	ColorfulVertex(6.0f, -1.0f, 1.0f, 1.0f, 0.0f, 0.0f, 1.0f),
	ColorfulVertex(4.0f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f, 1.0f),
	ColorfulVertex(6.0f, -1.0f, 1.0f, 1.0f, 0.0f, 0.0f, 1.0f),
	ColorfulVertex(6.0f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f, 1.0f),
	// B right
	ColorfulVertex(6.0f, 1.0f, 1.0f, 0.0f, 1.0f, 0.0f, 1.0f),
	ColorfulVertex(6.0f, -1.0f, 1.0f, 0.0f, 1.0f, 0.0f, 1.0f),
	ColorfulVertex(6.0f, -1.0f, -1.0f, 0.0f, 1.0f, 0.0f, 1.0f),
	ColorfulVertex(6.0f, 1.0f, 1.0f, 0.0f, 1.0f, 0.0f, 1.0f),
	ColorfulVertex(6.0f, -1.0f, -1.0f, 0.0f, 1.0f, 0.0f, 1.0f),
	ColorfulVertex(6.0f, 1.0f, -1.0f, 0.0f, 1.0f, 0.0f, 1.0f),
	// C back
	ColorfulVertex(6.0f, 1.0f, -1.0f, 0.0f, 0.0f, 1.0f, 1.0f),
	ColorfulVertex(6.0f, -1.0f, -1.0f, 0.0f, 0.0f, 1.0f, 1.0f),
	ColorfulVertex(4.0f, -1.0f, -1.0f, 0.0f, 0.0f, 1.0f, 1.0f),
	ColorfulVertex(6.0f, 1.0f, -1.0f, 0.0f, 0.0f, 1.0f, 1.0f),
	ColorfulVertex(4.0f, -1.0f, -1.0f, 0.0f, 0.0f, 1.0f, 1.0f),
	ColorfulVertex(4.0f,1.0f,-1.0f, 0.0f, 0.0f, 1.0f, 1.0f),
	// D left 
	ColorfulVertex(4.0f, 1.0f, -1.0f, 1.0f, 1.0f, 0.0f, 1.0f),
	ColorfulVertex(4.0f, -1.0f, -1.0f, 1.0f, 1.0f, 0.0f, 1.0f),
	ColorfulVertex(4.0f, -1.0f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f),
	ColorfulVertex(4.0f, 1.0f, -1.0f, 1.0f, 1.0f, 0.0f, 1.0f),
	ColorfulVertex(4.0f, -1.0f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f),
	ColorfulVertex(4.0f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f),
	// E upper 
	ColorfulVertex(4.0f, 1.0f, -1.0f, 0.0f, 1.0f, 1.0f, 1.0f),
	ColorfulVertex(4.0f, 1.0f, 1.0f, 0.0f, 1.0f, 1.0f, 1.0f),
	ColorfulVertex(6.0f, 1.0f, 1.0f, 0.0f, 1.0f, 1.0f, 1.0f),
	ColorfulVertex(4.0f, 1.0f, -1.0f, 0.0f, 1.0f, 1.0f, 1.0f),
	ColorfulVertex(6.0f, 1.0f, 1.0f, 0.0f, 1.0f, 1.0f, 1.0f),
	ColorfulVertex(6.0f, 1.0f, -1.0f, 0.0f, 1.0f, 1.0f, 1.0f),
	// F bottom 
	ColorfulVertex(4.0f, -1.0f, -1.0f, 1.0f, 0.0f, 1.0f, 1.0f),
	ColorfulVertex(4.0f, -1.0f, 1.0f, 1.0f, 0.0f, 1.0f, 1.0f),
	ColorfulVertex(6.0f, -1.0f, 1.0f, 1.0f, 0.0f, 1.0f, 1.0f),
	ColorfulVertex(4.0f, -1.0f, -1.0f, 1.0f, 0.0f, 1.0f, 1.0f),
	ColorfulVertex(6.0f, -1.0f, 1.0f, 1.0f, 0.0f, 1.0f, 1.0f),
	ColorfulVertex(6.0f, -1.0f, -1.0f, 1.0f, 0.0f, 1.0f, 1.0f)
};

/* DATAS END HERE */
