#include "TextureUtil.h"
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

TextureUtil::TextureUtil()
{
	cout << "[INFO] TextureUtil started" << endl;
}

TextureUtil::~TextureUtil()
{
	cout << "[INFO] TextureUtil stopped" << endl;
}

void TextureUtil::load(const string& fileName) {
	int width, height, bytesPerPixel;
	stbi_set_flip_vertically_on_load(true); //because of png's origin position(top right)
	unsigned char* imageData = stbi_load(fileName.c_str(), &width, &height, &bytesPerPixel, 4);

	checkTextureError(imageData,fileName);

	glGenTextures(1, &myTexture);
	glBindTexture(GL_TEXTURE_2D, myTexture);
	// Set our texture parameters
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_MIRRORED_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_MIRRORED_REPEAT);
	// Set texture filtering
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, imageData);
	glGenerateMipmap(GL_TEXTURE_2D);
	stbi_image_free(imageData);
	
	glBindTexture(GL_TEXTURE_2D, 0);
}

void TextureUtil::bind(unsigned int slot) {
	glActiveTexture(GL_TEXTURE + slot);
	glBindTexture(GL_TEXTURE_2D, myTexture);
}

void TextureUtil::unbind() {
	glBindTexture(GL_TEXTURE_2D, 0);
}

void TextureUtil::destroy() {
	glDeleteTextures(1, &myTexture);
}

void TextureUtil::checkTextureError(unsigned char* imageData,const string fileName) {
	if (imageData == NULL) { 
		cerr << "Texture loading failed: " << fileName << endl; 
	}
}
