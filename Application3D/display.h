#ifndef DISPLAY_H
#define DISPLAY_H

#include <SDL2/SDL.h>
#include <string>

class Display {
public:
	Display(int width,int height,const std::string& title);
	virtual ~Display();
	void clear(float r, float g, float b, float a);
	void update();
	bool isClosed();
protected:
private:
	Display(const Display& other);
	Display& operator=(const Display& other);

	SDL_Window* myWindow;
	SDL_GLContext myGLContext;
	bool closed;
};

#endif