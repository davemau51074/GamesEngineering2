#include "Game.h"
#include <iostream>
#include <image\SDL_image.h>


Game::Game()
{
	m_window = NULL;
	m_windowSurface = NULL;

	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		std::cout << "SDL failed to initialize, SDL_Error: " << SDL_GetError() << std::endl;
	}
	else {
		m_window = SDL_CreateWindow("SDL: Command Pattern", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, m_windowWidth, m_windowHeight, SDL_WINDOW_SHOWN);
		if (!m_window) {
			std::cout << "SDL window failed to create, SDL_Error: " << SDL_GetError() << std::endl;
		}
		else {
			m_windowSurface = SDL_GetWindowSurface(m_window);

			//Fill the surface white
			SDL_FillRect(m_windowSurface, NULL, SDL_MapRGB(m_windowSurface->format, 0xFF, 0xFF, 0xFF));

			//Update the surface
			SDL_UpdateWindowSurface(m_window);
		}
	}

	IMG_Init(IMG_INIT_JPG);
	//m_inputHandler = new InputHandler();
	//m_animation = new Animation();
	m_renderer = SDL_CreateRenderer(m_window, -1, 0);
	if (NULL == m_renderer)
	{
		std::cout << "error could not create render" << std::endl;
	}
	if (IMG_Init(IMG_INIT_PNG) == 0)
	{
		std::cout << "failed to initialise image" << std::endl;
	}
	m_animation = new Animation();

	//bool quit = false;
	//SDL_Event event;
	//SDL_Renderer * renderer = SDL_CreateRenderer(m_window, -1, 0);
	//SDL_Surface * image = SDL_LoadBMP("animation.png");
	


	
}

Game::~Game()
{
	SDL_DestroyRenderer(m_renderer);
	IMG_Quit();
	SDL_DestroyWindow(m_window);
	SDL_Quit();
}

void Game::update(float deltaTime)
{
	//std::cout << "				Update" << std::endl;
}

void Game::render()
{
	//std::cout << "Render" << std::endl;
	Uint32 ticks = SDL_GetTicks();
	Uint32 seconds = ticks / 1000;
	Uint32 sprite = (ticks / 300) % 6 ;
	SDL_Rect srcret = { sprite * 16,0,16,25 };
	SDL_Rect dstrect = { 10,10,32,64 };

	SDL_RenderCopy(m_renderer, m_texture, &srcret, &dstrect);
	SDL_RenderPresent(m_renderer);
	SDL_RenderClear(m_renderer);
}

void Game::run()
{
	SDL_Surface * image = IMG_Load("animation.png");
	m_image2 = IMG_Load("animationFlip.png");
	m_image1 = IMG_Load("animation.png");
	m_image3 = IMG_Load("animationIdle.png");
	m_texture = SDL_CreateTextureFromSurface(m_renderer, image);
	SDL_FreeSurface(image);
	SDL_Event e;
	float timeSinceLastUpdate = 0.f;
	float timePerFrame = 1.f / 60.f; // 60 fps in ms
	float currentTime = SDL_GetTicks() / 1000.0f;
	while (!m_quit)
	{
		float frameStart = SDL_GetTicks() / 1000.0f;
		float frameTime = frameStart - currentTime;
		currentTime = frameStart;
		processEvents(e); // as many as possible
		timeSinceLastUpdate += frameTime;
		while (timeSinceLastUpdate > timePerFrame)
		{
			timeSinceLastUpdate -= timePerFrame;
			processEvents(e); // at least 60 fps
			update(timePerFrame); //60 fps
		}
		render(); // as many as possible
	}


	SDL_DestroyTexture(m_texture);
}

void Game::processEvents(SDL_Event & e)
{

	
		
	
	//std::cout << "PE" << std::endl;
	while (SDL_PollEvent(&e)) 
	{
		//m_inputHandler->handleInput(m_event);
		if (e.type == SDL_KEYDOWN)
		{
			switch (e.key.keysym.sym)
			{
			case SDL_QUIT:
				m_quit = true;
				break;

			case SDLK_SPACE:
				//std::cout << "Jumping" << std::endl;
				m_animation->jumping();
				break;

			case SDLK_l:
				m_animation->climbing();
				//std::cout << "Climbing" << std::endl;
				break;

			case SDLK_i:
				m_animation->idle();
				//std::cout << "Idle" << std::endl;
				m_texture = SDL_CreateTextureFromSurface(m_renderer, m_image3);
				break;
			case SDLK_LEFT:
				m_texture = SDL_CreateTextureFromSurface(m_renderer, m_image2);
				m_animation->jumping();
				break;
			case SDLK_RIGHT:
				m_texture = SDL_CreateTextureFromSurface(m_renderer, m_image1);
				m_animation->jumping();
				break;
			default:	
				break;
			}
		}
		else
		{
			m_animation->idle();
		}
	}
}
