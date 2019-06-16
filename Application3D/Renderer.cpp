#include "Renderer.h"

Renderer::Renderer()
{
	gameobjectPool.reserve(gameobjectPoolCapacity);
	cout << "[ENGINE-INFO] Renderer started" << endl;
}

Renderer::~Renderer()
{
	cout << "[ENGINE-INFO] Renderer started" << endl;
}

void Renderer::render() {
	float test = 0.05f;

	glClearColor(0.0f, 0.15f, 0.3f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	su->bind(0);
	cam->setLocMVP(su->getLocMVP());
	vec3 testPos1(gameobjectPool[0].getPosition());
	testPos1.x += test;
	gameobjectPool[0].setPosition(testPos1);
	cam->update(&gameobjectPool[0]);
	mu->drawCube(0);

	su->bind(1);
	cam->setLocMVP(su->getLocMVP());
	vec3 testPos2(gameobjectPool[1].getPosition());
	testPos2.x += test;
	gameobjectPool[1].setPosition(testPos2);
	cam->update(&gameobjectPool[1]);
	mu->drawCube(1);
}
