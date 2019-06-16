#include "Display.h"
#include "Renderer.h"
#include "TextureUtil.h"
#include "Gameobject.h"
#include "tmp_data.h"


int main()
{
	Display display;
	Renderer renderer;
	display.initialize();
	display.create();
	display.makeContext();
	display.logStatus();
	
	

	//TextureUtil textureUtil;
	//textureUtil.load("res/illuminati.png");

	Gameobject cube1("cube1",0.0f,0.0f,0.0f);
	Gameobject cube2("cube2",5.0f,0.0f,0.0f);

	renderer.addGameobject(cube1);
	renderer.addGameobject(cube2);

	ShaderUtil shaderUtil;
	shaderUtil.load("res/basicShader.v", "res/basicShader.f", 0);
	shaderUtil.load("res/basicShader.v", "res/basicShader.f", 1);

	MeshUtil meshUtil;
	//meshUtil.create(triangleVertices, textureCoordinates, 3);
	meshUtil.createCube(cubeDataChunk, cube1);
	meshUtil.createCube(cubeDataChunkMovedRightOnX, cube2);

	/// *** DEPRECATED ***
	////////////////////////////////////////////////////////////////PhysicsUtil physicsUtil;
	////////////////////////////////////////////////////////////////physicsUtil.flushTransformValues();


	Camera camera(vec3(0,0,8), 70.0f, (float)(800/600), 0.01f, 1000.0f);

	
	
	//shaderUtil.bind(0);
	//textureUtil.bind();
	
	//camera.setLocMVP(shaderUtil.getLocMVP());

	display.setCamera(camera);
	display.setRenderer(renderer);
	renderer.setCamera(camera);
	renderer.setMeshUtil(meshUtil);
	renderer.setShaderUtil(shaderUtil);
	//display.setTextureUtil(textureUtil); //as you can see display is going full badass mod game engine style

	
	display.update();
		
	shaderUtil.unbind();
	//textureUtil.unbind();
	
	display.destroy();
	return 1;
}


