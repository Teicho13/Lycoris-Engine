#include <SDL.h>

//Util
#include "./Core/DeltaTime.h"
#include "./Core/KeyStates.h"

#include "./Core/Engine.h"

DeltaTime dt;

Engine::Engine(bool isFullscreen)
{
	SDL_Init(SDL_INIT_EVERYTHING);

	if(isFullscreen)
	{
		m_Window = SDL_CreateWindow("Lycoris", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, m_WindowWidth, m_WindowHeight, SDL_WINDOW_FULLSCREEN);
	}
	else
	{
		m_Window = SDL_CreateWindow("Lycoris", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, m_WindowWidth, m_WindowHeight, SDL_WINDOW_SHOWN);
	}

	//Create renderer for SDL and set default background color
	m_Renderer = SDL_CreateRenderer(m_Window, -1, 0);
	SDL_SetRenderDrawColor(m_Renderer, 27, 146, 214, 255);

	//Pointer to keyboard button states
	g_KeyStates = SDL_GetKeyboardState(nullptr);
}

Engine::~Engine()
{
	SDL_DestroyRenderer(m_Renderer);
	SDL_DestroyWindow(m_Window);
	SDL_Quit();
}

void Engine::Run()
{
	Init();

	while(m_IsRunning)
	{
		dt.Update();
		HandleEvents();
		Update(dt.GetSeconds());
		Render();
	}
}

void Engine::Init()
{
	//Set current time
	dt.GetTime();

	//Initialize is done and set game to run
	m_IsRunning = true;
}

void Engine::Update(float deltaTime)
{

}

void Engine::Shutdown()
{
	m_IsRunning = false;

	//<-- Shutdown game elements here -->
}

void Engine::Render()
{
	if (!m_IsRunning) return;

	//Clear render screen for new frame
	SDL_SetRenderDrawColor(m_Renderer, 27, 146, 214, 255);
	SDL_RenderClear(m_Renderer);

	//<-- Render Game Objects here -->


	//Render everything to the screen
	SDL_RenderPresent(m_Renderer);
}

void Engine::HandleEvents()
{
	SDL_Event event;
	while (SDL_PollEvent(&event))
	{
		switch(event.type)
		{
			//Window "X" is clicked
		case SDL_QUIT:
			m_IsRunning = false;
			break;

			//key is pressed
		case SDL_KEYDOWN:
			//If Escape is clicked exit out
			if (event.key.keysym.sym == SDLK_ESCAPE)
			{
				m_IsRunning = false;
				return;
			}
		}
	}
}


