#pragma once

struct SDL_Window;
struct SDL_Renderer;

class Engine
{
public:
	Engine(bool isFullscreen);
	~Engine();

	void Run();
	void Init();
	void Update(float deltaTime);
	void Shutdown();

	void Render();
	void HandleEvents();

private:
	bool m_IsRunning = false;

	//SDL related variables
	SDL_Window* m_Window = nullptr;
	SDL_Renderer* m_Renderer = nullptr;
};
