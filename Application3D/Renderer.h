#ifndef RENDERER_H
#define RENDERER_H

#include <Windows.h>
#include <vector>

#include "Camera.h"
#include "ShaderUtil.h"
#include "TextureUtil.h"
#include "MeshUtil.h"

class Renderer {
public:
	Renderer(ShaderUtil& shaderUtil, TextureUtil& textureUtil, MeshUtil& meshUtil, Camera& camera);
	virtual ~Renderer();

	void addGameobject(Gameobject& gameobject);

	void render(int index, int num);

	void renderAll();

private:
	Camera* cam;
	ShaderUtil* su;
	TextureUtil* tu;
	MeshUtil* mu;
	vector<Gameobject> gameobjectPool;
	const unsigned int gameobjectPoolCapacity = 21;
	float test = 0.025f;
};

#endif
