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

//points for optimed square drawing
Vertex squareVertices[] = {
		Vertex(vec3(-0.5f,-0.5f,0.0f)),
		Vertex(vec3(0.5f,-0.5f,0.0f)),
		Vertex(vec3(0.5f,0.5f,0.0f)),
		Vertex(vec3(-0.5f,0.5f,0.0f)),
};

//points for optimed square drawing with only 4 vertices
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

vector<ColorfulVertex*> massCubeDataCollection;

ColorfulVertex* createShiftedCubeDataChunk(ColorfulVertex* tmp, int changeX, int changeY, float shiftValue = 2.5) {
	ColorfulVertex* copy = new ColorfulVertex[36];
	memcpy(copy, tmp, sizeof(ColorfulVertex) * 36);

	for (int i = 0; i < 36; i++) {
		vec3 v = copy[i].getPos();
		v.x += changeX * shiftValue;
		v.y += changeY * shiftValue;
		copy[i].setPos(v);
	}
	return copy;
}

//fuzzy loading
void loadThePowahOfCplusplus() {
	massCubeDataCollection.reserve(21);
	massCubeDataCollection.push_back(createShiftedCubeDataChunk(cubeDataChunk, 0, 0));
	massCubeDataCollection.push_back(createShiftedCubeDataChunk(cubeDataChunk, 1, 0));
	massCubeDataCollection.push_back(createShiftedCubeDataChunk(cubeDataChunk, -1, 0));
	massCubeDataCollection.push_back(createShiftedCubeDataChunk(cubeDataChunk, 0, -1));
	massCubeDataCollection.push_back(createShiftedCubeDataChunk(cubeDataChunk, 0, 1));
	massCubeDataCollection.push_back(createShiftedCubeDataChunk(cubeDataChunk, 4, 0));
	massCubeDataCollection.push_back(createShiftedCubeDataChunk(cubeDataChunk, 4, 1));
	massCubeDataCollection.push_back(createShiftedCubeDataChunk(cubeDataChunk, 4, -1));
	massCubeDataCollection.push_back(createShiftedCubeDataChunk(cubeDataChunk, 3, 0));
	massCubeDataCollection.push_back(createShiftedCubeDataChunk(cubeDataChunk, 5, 0));
	massCubeDataCollection.push_back(createShiftedCubeDataChunk(cubeDataChunk, -3, 2));
	massCubeDataCollection.push_back(createShiftedCubeDataChunk(cubeDataChunk, -3, -2));
	massCubeDataCollection.push_back(createShiftedCubeDataChunk(cubeDataChunk, -4, 3));
	massCubeDataCollection.push_back(createShiftedCubeDataChunk(cubeDataChunk, -4, -3));
	massCubeDataCollection.push_back(createShiftedCubeDataChunk(cubeDataChunk, -5, 3));
	massCubeDataCollection.push_back(createShiftedCubeDataChunk(cubeDataChunk, -5, -3));
	massCubeDataCollection.push_back(createShiftedCubeDataChunk(cubeDataChunk, -6, 2));
	massCubeDataCollection.push_back(createShiftedCubeDataChunk(cubeDataChunk, -6, 1));
	massCubeDataCollection.push_back(createShiftedCubeDataChunk(cubeDataChunk, -6, 0));
	massCubeDataCollection.push_back(createShiftedCubeDataChunk(cubeDataChunk, -6, -1));
	massCubeDataCollection.push_back(createShiftedCubeDataChunk(cubeDataChunk, -6, -2));
}

TextureVertex cubeDataChunk_textured[36] = {
	// A front 
	TextureVertex(-1.0f, 1.0f, 1.0f, 0.0f, 1.0f), 
	TextureVertex(-1.0f, -1.0f, 1.0f, 0.0f, 0.0f), 
	TextureVertex(1.0f, -1.0f, 1.0f, 1.0f, 0.0f), 
	TextureVertex(-1.0f, 1.0f, 1.0f, 0.0f, 1.0f), 
	TextureVertex(1.0f, -1.0f, 1.0f, 1.0f, 0.0f), 
	TextureVertex(1.0f, 1.0f, 1.0f, 1.0f, 1.0f),
	// B right
	TextureVertex(1.0f, 1.0f, 1.0f, 0.0f, 1.0f),
	TextureVertex(1.0f, -1.0f, 1.0f, 0.0f, 0.0f),
	TextureVertex(1.0f, -1.0f, -1.0f, 1.0f, 0.0f),
	TextureVertex(1.0f, 1.0f, 1.0f, 0.0f, 1.0f),
	TextureVertex(1.0f, -1.0f, -1.0f, 1.0f, 0.0f),
	TextureVertex(1.0f, 1.0f, -1.0f, 1.0f, 1.0f),
	// C back
	TextureVertex(1.0f, 1.0f, -1.0f, 0.0f, 1.0f),
	TextureVertex(1.0f, -1.0f, -1.0f, 0.0f, 0.0f),
	TextureVertex(-1.0f, -1.0f, -1.0f, 1.0f, 0.0f),
	TextureVertex(1.0f, 1.0f, -1.0f, 0.0f, 1.0f),
	TextureVertex(-1.0f, -1.0f, -1.0f, 1.0f, 0.0f),
	TextureVertex(-1.0f,1.0f,-1.0f, 1.0f, 1.0f),
	// D left 
	TextureVertex(-1.0f, 1.0f, -1.0f, 0.0f, 1.0f),
	TextureVertex(-1.0f, -1.0f, -1.0f, 0.0f, 0.0f),
	TextureVertex(-1.0f, -1.0f, 1.0f, 1.0f, 0.0f),
	TextureVertex(-1.0f, 1.0f, -1.0f, 0.0f, 1.0f),
	TextureVertex(-1.0f, -1.0f, 1.0f, 1.0f, 0.0f),
	TextureVertex(-1.0f, 1.0f, 1.0f, 1.0f, 1.0f),
	// E upper 
	TextureVertex(-1.0f, 1.0f, -1.0f, 0.0f, 1.0f),
	TextureVertex(-1.0f, 1.0f, 1.0f, 0.0f, 0.0f),
	TextureVertex(1.0f, 1.0f, 1.0f, 1.0f, 0.0f),
	TextureVertex(-1.0f, 1.0f, -1.0f, 0.0f, 1.0f),
	TextureVertex(1.0f, 1.0f, 1.0f, 1.0f, 0.0f),
	TextureVertex(1.0f, 1.0f, -1.0f, 1.0f, 1.0f),
	// F bottom 
	TextureVertex(-1.0f, -1.0f, -1.0f, 0.0f, 1.0f),
	TextureVertex(-1.0f, -1.0f, 1.0f,  0.0f, 0.0f),
	TextureVertex(1.0f, -1.0f, 1.0f, 1.0f, 0.0f),
	TextureVertex(-1.0f, -1.0f, -1.0f, 0.0f, 1.0f),
	TextureVertex(1.0f, -1.0f, 1.0f, 1.0f, 0.0f),
	TextureVertex(1.0f, -1.0f, -1.0f, 1.0f, 1.0f)
};

vector<TextureVertex*> massTexturedCubeDataCollection;

TextureVertex* createShiftedCubeDataChunk(TextureVertex* tmp, int changeX, int changeY, float shiftValue = 2.0f) {
	TextureVertex* copy = new TextureVertex[36];
	memcpy(copy, tmp, sizeof(TextureVertex) * 36);

	for (int i = 0; i < 36; i++) {
		vec3 v = copy[i].getPos();
		v.x += changeX * shiftValue;
		v.y += changeY * shiftValue;
		copy[i].setPos(v);
	}
	return copy;
}

//fuzzy loading
void loadThePowahOfCplusplus_textured() {
	massTexturedCubeDataCollection.reserve(21);
	massTexturedCubeDataCollection.push_back(createShiftedCubeDataChunk(cubeDataChunk_textured, 0, 0));
	massTexturedCubeDataCollection.push_back(createShiftedCubeDataChunk(cubeDataChunk_textured, 1, 0));
	massTexturedCubeDataCollection.push_back(createShiftedCubeDataChunk(cubeDataChunk_textured, -1, 0));
	massTexturedCubeDataCollection.push_back(createShiftedCubeDataChunk(cubeDataChunk_textured, 0, -1));
	massTexturedCubeDataCollection.push_back(createShiftedCubeDataChunk(cubeDataChunk_textured, 0, 1));
	massTexturedCubeDataCollection.push_back(createShiftedCubeDataChunk(cubeDataChunk_textured, 4, 0));
	massTexturedCubeDataCollection.push_back(createShiftedCubeDataChunk(cubeDataChunk_textured, 4, 1));
	massTexturedCubeDataCollection.push_back(createShiftedCubeDataChunk(cubeDataChunk_textured, 4, -1));
	massTexturedCubeDataCollection.push_back(createShiftedCubeDataChunk(cubeDataChunk_textured, 3, 0));
	massTexturedCubeDataCollection.push_back(createShiftedCubeDataChunk(cubeDataChunk_textured, 5, 0));
	massTexturedCubeDataCollection.push_back(createShiftedCubeDataChunk(cubeDataChunk_textured, -3, 2));
	massTexturedCubeDataCollection.push_back(createShiftedCubeDataChunk(cubeDataChunk_textured, -3, -2));
	massTexturedCubeDataCollection.push_back(createShiftedCubeDataChunk(cubeDataChunk_textured, -4, 3));
	massTexturedCubeDataCollection.push_back(createShiftedCubeDataChunk(cubeDataChunk_textured, -4, -3));
	massTexturedCubeDataCollection.push_back(createShiftedCubeDataChunk(cubeDataChunk_textured, -5, 3));
	massTexturedCubeDataCollection.push_back(createShiftedCubeDataChunk(cubeDataChunk_textured, -5, -3));
	massTexturedCubeDataCollection.push_back(createShiftedCubeDataChunk(cubeDataChunk_textured, -6, 2));
	massTexturedCubeDataCollection.push_back(createShiftedCubeDataChunk(cubeDataChunk_textured, -6, 1));
	massTexturedCubeDataCollection.push_back(createShiftedCubeDataChunk(cubeDataChunk_textured, -6, 0));
	massTexturedCubeDataCollection.push_back(createShiftedCubeDataChunk(cubeDataChunk_textured, -6, -1));
	massTexturedCubeDataCollection.push_back(createShiftedCubeDataChunk(cubeDataChunk_textured, -6, -2));
}



/* DATAS END HERE */
