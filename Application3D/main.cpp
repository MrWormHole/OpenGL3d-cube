#include "Display.h"
#include "ShaderUtil.h"
#include "TextureUtil.h"

int main()
{
	Display display;
	display.initialize();
	display.create();
	display.makeContext();
	display.logStatus();

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

	//for illuminati texture
	float textureCoordinates[6] = {
			0.25f,0.1f, //lower left
			0.75f,0.1f, //lower right
			0.5f,0.9f  //top center
		};

	//for cube !!be aware this is unoptimized drawing without element buffer array!!
	Vertex cubaData[36] = {
			Vertex(-1.0f,-1.0f,-1.0f,1.0f,0.0f,0.0f,1.0f),
			Vertex(-1.0f,-1.0f, 1.0f,1.0f,0.0f,0.0f,1.0f),
			Vertex(-1.0f, 1.0f, 1.0f,1.0f,0.0f,0.0f,1.0f), 
			Vertex(1.0f, 1.0f,-1.0f,1.0f,0.0f,0.0f,1.0f), 
			Vertex(-1.0f,-1.0f,-1.0f,1.0f,0.0f,0.0f,1.0f),
			Vertex(-1.0f, 1.0f,-1.0f,1.0f,0.0f,0.0f,1.0f), 
			Vertex(1.0f,-1.0f, 1.0f,0.0f,1.0f,0.0f,1.0f),
			Vertex(-1.0f,-1.0f,-1.0f,0.0f,1.0f,0.0f,1.0f),
			Vertex(1.0f,-1.0f,-1.0f,0.0f,1.0f,0.0f,1.0f),
			Vertex(1.0f, 1.0f,-1.0f,0.0f,1.0f,0.0f,1.0f),
			Vertex(1.0f,-1.0f,-1.0f,0.0f,1.0f,0.0f,1.0f),
			Vertex(-1.0f,-1.0f,-1.0f,0.0f,1.0f,0.0f,1.0f),
			Vertex(-1.0f,-1.0f,-1.0f,0.0f,0.0f,1.0,1.0f),
			Vertex(-1.0f, 1.0f, 1.0f,0.0f,0.0f,1.0,1.0f),
			Vertex(-1.0f, 1.0f,-1.0f,0.0f,0.0f,1.0,1.0f),
			Vertex(1.0f,-1.0f, 1.0f,0.0f,0.0f,1.0,1.0f),
			Vertex(-1.0f,-1.0f, 1.0f,0.0f,0.0f,1.0,1.0f),
			Vertex(-1.0f,-1.0f,-1.0f,0.0f,0.0f,1.0,1.0f),
			Vertex(-1.0f, 1.0f, 1.0f,1.0f,1.0f,0.0,1.0f),
			Vertex(-1.0f,-1.0f, 1.0f,1.0f,1.0f,0.0,1.0f),
			Vertex(1.0f,-1.0f, 1.0f,1.0f,1.0f,0.0,1.0f),
			Vertex(1.0f, 1.0f, 1.0f,1.0f,1.0f,0.0,1.0f),
			Vertex(1.0f,-1.0f,-1.0f,1.0f,1.0f,0.0,1.0f),
			Vertex(1.0f, 1.0f,-1.0f,1.0f,1.0f,0.0,1.0f),
			Vertex(1.0f,-1.0f,-1.0f,0.0f,1.0f,1.0f,1.0f),
			Vertex(1.0f, 1.0f, 1.0f,0.0f,1.0f,1.0f,1.0f),
			Vertex(1.0f,-1.0f, 1.0f,0.0f,1.0f,1.0f,1.0f),
			Vertex(1.0f, 1.0f, 1.0f,0.0f,1.0f,1.0f,1.0f),
			Vertex(1.0f, 1.0f,-1.0f,0.0f,1.0f,1.0f,1.0f),
			Vertex(-1.0f, 1.0f,-1.0f,0.0f,1.0f,1.0f,1.0f),
			Vertex(1.0f, 1.0f, 1.0f,1.0f,0.0f,1.0f,1.0f),
			Vertex(-1.0f, 1.0f,-1.0f,1.0f,0.0f,1.0f,1.0f),
			Vertex(-1.0f, 1.0f, 1.0f,1.0f,0.0f,1.0f,1.0f),
			Vertex(1.0f, 1.0f, 1.0f,1.0f,0.0f,1.0f,1.0f),
			Vertex(-1.0f, 1.0f, 1.0f,1.0f,0.0f,1.0f,1.0f),
			Vertex(1.0f,-1.0f, 1.0f,1.0f,0.0f,1.0f,1.0f)
		};
/* DATAS END HERE */
		
	ShaderUtil shaderUtil;
	shaderUtil.load("res/basicShader.v", "res/basicShader.f");

	//TextureUtil textureUtil;
	//textureUtil.load("res/illuminati.png");

	MeshUtil meshUtil;
	//meshUtil.create(triangleVertices, textureCoordinates, 3);
	meshUtil.createCube(cubaData);

	PhysicsUtil physicsUtil;
	physicsUtil.flushTransformValues();

	Camera camera(vec3(0,0,6), 70.0f, (float)(800/600), 0.01f, 1000.0f);
	
	shaderUtil.bind();
	//textureUtil.bind();
	
	camera.setLocMVP(shaderUtil.getLocMVP());

	display.setCamera(camera);
	display.setMeshUtil(meshUtil);
	display.setPhysicsUtil(physicsUtil);
		
	display.update();
		
	shaderUtil.unbind();
	//textureUtil.unbind();
	
	display.destroy();
	return 1;
}


