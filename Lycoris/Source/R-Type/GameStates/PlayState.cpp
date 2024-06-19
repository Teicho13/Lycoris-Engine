#include "./R-Type/GameStates/PlayState.h"

#include <iostream>
#include <SDL_events.h>

#include "./Core/Sprite.h"
#include "./Managers/TextureManager.h"
#include "./R-Type/Entities/Player.h"
#include "./R-Type/Entities/Bullet.h"
#include "./R-Type/Map/Camera.h"
#include "./R-Type/Map/Map.h"


PlayState PlayState::m_PlayState;

Player* player;
Camera camera;
Bullet* bullet;

void PlayState::Init(GameStateManager* manager)
{
	player = new Player("Assets/Games/R-Type/Textures/Player/Player.png",5,1);
	player->GetSprite()->SetFrame(2);

	m_Level01 = new Map("./Assets/Games/R-Type/MapData/Level01.csv", "Assets/Games/R-Type/Textures/Maps/Level01Tiles64.png", 22, 20);

	bullet = new Bullet("Assets/Games/R-Type/Textures/Player/Bullet.png", 1, 1);

	player->SetCamera(&camera);
}

void PlayState::Tick(GameStateManager* manager, float deltaTime)
{
	player->Update(deltaTime);
	player->HandleTileCollision(m_Level01);
	camera.MoveCamera(deltaTime);
	bullet->Update(deltaTime);
}

void PlayState::Shutdown()
{
	delete player;
	delete m_Level01;
	delete bullet;
}

void PlayState::Render(GameStateManager* manager)
{
	m_Level01->DrawMap(camera);
	player->Draw();
	bullet->Draw();

	TextureManager::RenderBox(player->GetPosX(), player->GetPosY(), player->GetWidth(), player->GetHeight());
}

void PlayState::HandleEvents(GameStateManager* manager)
{

	SDL_Event event;
	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
			//Window "X" is clicked
		case SDL_QUIT:
			manager->Shutdown();
			break;

			//key is pressed
		case SDL_KEYDOWN:
			//If Escape is clicked exit out
			if (event.key.keysym.sym == SDLK_ESCAPE)
			{
				manager->Shutdown();
				return;
			}
		case SDL_MOUSEBUTTONDOWN:
			if (event.button.button == SDL_BUTTON_LEFT)
			{
			}
			break;
		}
	}

}
