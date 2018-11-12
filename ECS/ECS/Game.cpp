#include "Game.h"
#include <iostream>
#include <image/SDL_image.h>


Game::Game() {

	m_window = NULL;
	m_renderer = NULL;
	isRuning = true;
	SDL_Event event;
	SDL_PollEvent(&event);
	SDL_Delay(3000);
	m_window = SDL_CreateWindow("Window", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 600, SDL_WINDOW_SHOWN);
	m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

	/**********SYSTEM************/
	conSys = new ControlSystem();
	renSys = new RenderSystem();
	posSys = new PositionSystem();
	healSys = new HealthSystem();
	aiSys = new AISystem();





//	healSys->addEntity(m_player);
	//healCom = new HealthComponent();
	//posCom = new PositionComponent();

	//*****************************
	m_player = new Entity();
	
	healCom = new HealthComponent();
	posCom = new PositionComponent();
	renCos = new RenderComponent();
	conCos = new ControlComponent();
	//*****************************

	//*****************************
	m_cat = new Entity();

	m_catHeal = new HealthComponent();
	m_catPos = new PositionComponent();
	m_catRen = new RenderComponent();

	//*****************************

	//*****************************
	m_dog = new Entity();

	m_dogHeal = new HealthComponent();
	m_dogPos = new PositionComponent();
	m_dogRen = new RenderComponent();
	//m_dogCon = new ControlComponent();

	//*****************************


	m_player->addComponent(healCom);
	healSys->addEntity(m_player);
	m_player->addComponent(posCom);
	posSys->addEntity(m_player);
	m_player->addComponent(renCos);
	renSys->addEntity(m_player);
	m_player->addComponent(conCos);
	conSys->addEntity(m_player);
	aiSys->addEntity(m_player); 








	//**********************************
	m_alien = new Entity();

	m_alienHeal = new HealthComponent();
	m_alienPos = new PositionComponent();
	m_alienRen = new RenderComponent();
	//m_alienCon = new ControlComponent();

	

	//Cat
	/*m_cat->addComponent(m_catHeal);
	healSys->addEntity(m_cat);
	m_cat->addComponent(m_catPos);
	posSys->addEntity(m_cat);
	m_cat->addComponent(m_catRen);
	renSys->addEntity(m_cat);;
	conSys->addEntity(m_cat);
	aiSys->addEntity(m_cat); */

	//Dog
	/*m_dog->addComponent(m_dogHeal);
	healSys->addEntity(m_dog);
	m_dog->addComponent(m_dogPos);
	posSys->addEntity(m_dog);
	m_dog->addComponent(m_dogRen);
	renSys->addEntity(m_dog);
	m_dog->addComponent(m_dogCon);
	conSys->addEntity(m_dog); */

	//m_alien->addComponent(m_alienHeal);
	//healSys->addEntity(m_alien);
	//m_alien->addComponent(m_alienPos);
	//posSys->addEntity(m_alien);
	//m_alien->addComponent(m_alienRen);
	//renSys->addEntity(m_alien);
	////m_alien->addComponent(conCos);
	////conSys->addEntity(m_alien);
	//aiSys->addEntity(m_alien); 

}

Game::~Game()
{


}

void Game::update()
{
	//SDL_Event e;

	healSys->update();
	posSys->update();
	renSys->update();
	//conSys->update(e);
}

void Game::render()
{
	SDL_Rect * m_dst = new SDL_Rect();
	m_dst->x = 400;
	m_dst->y = 400;
	m_dst->w = 16;
	m_dst->h = 32;

	if (m_renderer == nullptr) {
		std::cout << "NO Render" << std::endl;
	}

	SDL_RenderClear(m_renderer);
	SDL_SetRenderDrawColor(m_renderer, 0, 0, 0, 255);
	SDL_RenderPresent(m_renderer);
}

void Game::run()
{
	const Uint16 fps = 5;
	const Uint16 minFrameTime = 1000 / fps; 
	
	Uint16 frameTime;
	Uint16 previousFrameTime = 0;
	Uint16 dt = 0;

	while (isRuning)
	{
		processEvents();
		frameTime = SDL_GetTicks();

		dt = frameTime - previousFrameTime;
		previousFrameTime = frameTime;

		update();
		render();

		if ((SDL_GetTicks() - frameTime) < minFrameTime)
		{
			SDL_Delay(minFrameTime - (SDL_GetTicks() - frameTime));
		}

	}

	SDL_DestroyRenderer(m_renderer);
	SDL_DestroyWindow(m_window);
	SDL_Quit();

}

void Game::processEvents()
{
	SDL_Event e;

	while (SDL_PollEvent(&e))
	{
		switch (e.type)
		{
		case SDL_QUIT:
			isRuning = false;
			break;
		case SDL_KEYDOWN:
			conSys->update(e);
			if (e.key.keysym.sym == SDLK_ESCAPE)
			{
				isRuning = false;
				break;
			}
		}

	}

}