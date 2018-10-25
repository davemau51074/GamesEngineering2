#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <SDL.h>
#include <image/SDL_image.h>
#include "Animation.h"


//#include "Command.h"
//#include "Commands.h"
//#include "InputHandler.h"

class Game {
public:
	Game();
	~Game();

	void update(float deltaTime);
	void render();
	void run();
	void processEvents(SDL_Event & e);
private:
	SDL_Window * m_window;
	SDL_Surface * m_windowSurface;
	SDL_Renderer * m_renderer;
	const int m_windowWidth = 500;
	const int m_windowHeight = 200;
	Animation * m_animation;
	SDL_Texture * m_texture;
	SDL_Surface * m_image2;
	SDL_Surface * m_image1;
	SDL_Surface * m_image3;
	//Loop Content
	bool m_quit;
	SDL_Event m_event;
//	InputHandler* m_inputHandler;
};

#endif // !GAME_H