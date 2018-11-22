#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <SDL.h>
#include <image/SDL_image.h>
#include <SDL_timer.h>
#include "HealthSystem.h"
#include <stdlib.h>
#include "Player.h"
#include "PositionComponent.h"
#include "PositionSystem.h"
#include "HealthComponent.h"
#include "HealthSystem.h"
#include "RenderSystem.h"
#include "RenderComponent.h"
#include "ControlComponent.h"
#include "ControlSystem.h"
#include "AISyatem.h"

class Game {

public:
	Game();
	~Game();

	SDL_Window * m_window;
	SDL_Renderer * m_renderer;
	bool isRuning;
	void update();
	void render();
	void run();
	void processEvents();

	Entity * m_player;
	HealthSystem * healSys;
	HealthComponent * healCom;
	PositionComponent * posCom;
	PositionSystem * posSys;
	RenderComponent * renCos;
	RenderSystem * renSys;
	ControlComponent * conCos;
	ControlSystem * conSys;
	AISystem * aiSys;
	

/**********************************/
	Entity * m_cat;
	HealthComponent * m_catHeal;
	PositionComponent * m_catPos;
	RenderComponent * m_catRen;


	/*******************************/
	Entity * m_dog;
	HealthComponent * m_dogHeal;
	PositionComponent * m_dogPos;
	RenderComponent * m_dogRen;
	ControlComponent * m_dogCon;

	/*******************************/
	Entity * m_alien;
	HealthComponent * m_alienHeal;
	PositionComponent * m_alienPos;
	RenderComponent * m_alienRen;
	//ControlComponent * m_alienCon;
};

#endif //!GAME_H