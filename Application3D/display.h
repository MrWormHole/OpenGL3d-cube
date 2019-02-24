#ifndef DISPLAY_H
#define DISPLAY_H

#include <iostream>
#include <string>
#include <SDL2/SDL.h>
#include <GL/glew.h>

using namespace std;

class Display {
public:
	Display(int width,int height,const string& title);
	virtual ~Display();
	void clear(float r, float g, float b, float a);
	void update();
	bool isClosed();
protected:
private:
	SDL_Window* myWindow;
	SDL_GLContext myGLContext;
	bool closed;
	Display(const Display& other);
	Display& operator=(const Display& other);
};

#endif