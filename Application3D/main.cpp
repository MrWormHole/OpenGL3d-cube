#include <vector>
#include "Display.h"
#include "tmp_data.h"

int main()
{
	//loadThePowahOfCplusplus();
	loadThePowahOfCplusplus_textured();

	Display display;
	display.initialize();
	display.create();
	display.makeContext();
	display.logStatus();
	
	ShaderUtil shaderUtil;
	//shaderUtil.load("res/basicShader.v", "res/basicShader.f", 0);
	shaderUtil.load("res/texturedShader.v", "res/texturedShader.f", 0);
	
	TextureUtil textureUtil;
	textureUtil.load("res/illuminati.png", 0);
	textureUtil.load("res/tile_1.png", 0);
	textureUtil.load("res/tile_2.png", 1);
	textureUtil.load("res/tile_3.png", 2); 

	MeshUtil meshUtil;
	//OBJModel monkeyModel("res/monkey.obj");
	//Gameobject monkey("blender monkey");
	Gameobject cubes[21];
	
	//meshUtil.create(triangleVertices, textureCoordinates, 3);
	for (int i = 0; i < 21; i++) {
		meshUtil.createCube(massTexturedCubeDataCollection[i], &cubes[i]);
	}
	//meshUtil.createModel(monkeyModel, &monkey);

	Camera camera(vec3(0, 0, 10), 70.0f, (float)(800 / 600), 0.01f, 1000.0f);

	Renderer renderer(shaderUtil, textureUtil, meshUtil, camera);

	for (int i = 0; i < 21; i++) {
		renderer.addGameobject(cubes[i]);
	}
	//renderer.addGameobject(monkey);
	
	display.setCamera(camera);
	display.setRenderer(renderer);
	display.update();
	
	display.destroy();
	return 1;
}


