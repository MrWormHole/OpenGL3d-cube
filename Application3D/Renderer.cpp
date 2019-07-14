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
		//tu->bind(0, 0);
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

void Renderer::addGameobject(Gameobject& gameobject) { gameobjectPool.push_back(gameobject); }

void Renderer::render(int index,int num) {
	//su->bind(index);
	//tu->bind(0);
	tu->bind(num, num);
	cam->setLocMVP(su->getLocMVP());
	vec3 testRot(gameobjectPool[index].getRotation());
	vec3 testPos(gameobjectPool[index].getPosition());
	testRot.x += test;
	testRot.y += test;
	testRot.z += test;
	//testPos.x += test;
	gameobjectPool[index].setRotation(testRot);
	gameobjectPool[index].setPosition(testPos);
	cam->update(&gameobjectPool[index]);
	mu->draw(index);
}

void Renderer::renderAll() {
	glClearColor(0.0f, 0.15f, 0.3f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//render(0, 0);
	for (int i = 0; i < gameobjectPoolCapacity; i++) {
		if (i < 5) {
			render(i, 2);
		}
		else if (i > 4 && i < 10) {
			render(i, 0);
		}
		else {
			render(i, 1);
		}
	}
}
