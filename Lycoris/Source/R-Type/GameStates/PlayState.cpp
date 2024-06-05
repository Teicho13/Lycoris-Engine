#include "./R-Type/GameStates/PlayState.h"

#include "Core/Sprite.h"
#include "./R-Type/Entities/Player.h"


PlayState PlayState::m_PlayState;

Player* player;


void PlayState::Init(GameStateManager* manager)
{
	player = new Player("Assets/Games/R-Type/Textures/Player/Player.png",5,1);
	player->GetSprite()->SetFrame(2);
}

void PlayState::Tick(GameStateManager* manager, float deltaTime)
{
	player->Update(deltaTime);
}

void PlayState::Shutdown()
{
	delete player;
}

void PlayState::Render(GameStateManager* manager)
{
	player->Draw();
}

void PlayState::HandleEvents(GameStateManager* manager)
{
}
