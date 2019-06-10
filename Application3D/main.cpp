#include "Display.h"
#include "ShaderUtil.h"
#include "TextureUtil.h"
#include "tmp_data.h"

void test(GLFWwindow* window,double xpos,double ypos) {
	cout << "test";
}

int main()
{
	Display display;
	display.initialize();
	display.create();
	display.makeContext();
	display.logStatus();
	
	ShaderUtil shaderUtil;
	shaderUtil.load("res/basicShader.v", "res/basicShader.f");

	//TextureUtil textureUtil;
	//textureUtil.load("res/illuminati.png");

	MeshUtil meshUtil;
	//meshUtil.create(triangleVertices, textureCoordinates, 3);
	meshUtil.createCube(cubeDataChunk);

	PhysicsUtil physicsUtil;
	physicsUtil.flushTransformValues();

	Camera camera(vec3(0,0,8), 70.0f, (float)(800/600), 0.01f, 1000.0f);
	
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


