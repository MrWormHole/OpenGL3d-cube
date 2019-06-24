#ifndef TEXTURE_UTIL_H
#define TEXTURE_UTIL_H

#include <GLEW/glew.h>
#include <iostream>
#include <string>

using namespace std;

class TextureUtil
{
public:
	TextureUtil();
	virtual ~TextureUtil();

	//loading the texture file
	void load(const string& fileName, int index);

	//using the texture
	void bind(unsigned int slot, int index);

	//not using the texture
	void unbind();

	//delete all textures
	void destroy();

	//checking for texture error
	void checkTextureError(unsigned char* imageData,const string fileName);

private:
	GLuint myTextures[5];
	GLsizei textureCount = 5;
};

#endif

