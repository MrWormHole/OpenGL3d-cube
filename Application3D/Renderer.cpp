#include "Renderer.h"

Renderer::Renderer() {
	gameobjectPool.reserve(gameobjectPoolCapacity);
	cout << "[ENGINE-INFO] Renderer started" << endl;
}

Renderer::~Renderer() {
	cout << "[ENGINE-INFO] Renderer started" << endl;
}

void Renderer::setCamera(Camera& camera) { cam = &camera; if (cam != nullptr) { cout << "*** cam pointer is set ***" << endl; } }
void Renderer::setShaderUtil(ShaderUtil& shaderUtil) { su = &shaderUtil; if (su != nullptr) { cout << "*** su pointer is set ***" << endl; } }
void Renderer::setTextureUtil(TextureUtil& textureUtil) { tu = &textureUtil; if (tu != nullptr) { cout << "*** tu pointer is set ***" << endl; } }
void Renderer::setMeshUtil(MeshUtil& meshUtil) { mu = &meshUtil; if (mu != nullptr) { cout << "*** mu pointer is set ***" << endl; } }

void Renderer::addGameobject(Gameobject& gameobject) { gameobjectPool.push_back(gameobject); }

void Renderer::render(int index) {
	su->bind(index);
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

	for (int i = 0; i < 21; i++) {
		render(i);
	}
}
