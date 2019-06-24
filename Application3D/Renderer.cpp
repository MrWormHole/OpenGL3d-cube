#include "Renderer.h"

Renderer::Renderer(ShaderUtil& shaderUtil, TextureUtil& textureUtil, MeshUtil& meshUtil, Camera& camera) {
	gameobjectPool.reserve(gameobjectPoolCapacity);
	su = &shaderUtil;
	tu = &textureUtil;
	mu = &meshUtil;
	cam = &camera;
	if (su != nullptr) { 
		//cout << "*** su pointer is set ***" << endl; 
		su->bind(0);
	}
	if (tu != nullptr) { 
		//cout << "*** tu pointer is set ***" << endl; 
		tu->bind(0, 0);
	}
	if (mu != nullptr) { 
		//cout << "*** mu pointer is set ***" << endl; 
	}
	if (cam != nullptr) { 
		//cout << "*** cam pointer is set" << endl; 
	}
	cout << "[ENGINE-INFO] Renderer started" << endl;
}

Renderer::~Renderer() {
	cout << "[ENGINE-INFO] Renderer stopped" << endl;
}

void Renderer::setCamera(Camera& camera) { cam = &camera; if (cam != nullptr) { cout << "*** cam pointer is set ***" << endl; } }
void Renderer::setShaderUtil(ShaderUtil& shaderUtil) { su = &shaderUtil; if (su != nullptr) { cout << "*** su pointer is set ***" << endl; } }
void Renderer::setTextureUtil(TextureUtil& textureUtil) { tu = &textureUtil; if (tu != nullptr) { cout << "*** tu pointer is set ***" << endl; } }
void Renderer::setMeshUtil(MeshUtil& meshUtil) { mu = &meshUtil; if (mu != nullptr) { cout << "*** mu pointer is set ***" << endl; } }

void Renderer::addGameobject(Gameobject& gameobject) { gameobjectPool.push_back(gameobject); }

void Renderer::render(int index) {
	//su->bind(index);
	//tu->bind(0);
	cam->setLocMVP(su->getLocMVP());
	vec3 testPos1(gameobjectPool[index].getRotation());
	testPos1.y += test;
	testPos1.x += test;
	gameobjectPool[index].setRotation(testPos1);
	cam->update(&gameobjectPool[index]);
	mu->drawCube(index);
}

void Renderer::renderAll() {
	glClearColor(0.0f, 0.15f, 0.3f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	render(0);
	/*for (int i = 0; i < 21; i++) {
		render(i);
	}*/
}
