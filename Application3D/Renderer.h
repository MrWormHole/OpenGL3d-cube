#ifndef RENDERER_H
#define RENDERER_H

#include <GLEW/glew.h>
#include <iostream>
#include <vector>
#include "Camera.h"
#include "ShaderUtil.h"
#include "MeshUtil.h"

using namespace std;

class Renderer {
public:
	Renderer();
	virtual ~Renderer();
	void setCamera(Camera& camera) { cam = &camera; if (cam != nullptr) { cout << "*** cam pointer is set ***" << endl; } }
	void setMeshUtil(MeshUtil& meshUtil) { mu = &meshUtil; if (mu != nullptr) { cout << "*** mu pointer is set ***" << endl; } }
	void setShaderUtil(ShaderUtil& shaderUtil) { su = &shaderUtil; if (su != nullptr) { cout << "*** su pointer is set ***" << endl; } }

	void addGameobject(Gameobject& gameobject) { gameobjectPool.push_back(gameobject); }

	void render();

private:
	Camera* cam;
	ShaderUtil* su;
	MeshUtil* mu;
	vector<Gameobject> gameobjectPool;
	const unsigned int gameobjectPoolCapacity = 10;
};

#endif
