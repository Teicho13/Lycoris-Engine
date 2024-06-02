#include "./R-Type/GameStates/PlayState.h"
#include "Entities/Entity.h"


PlayState PlayState::m_PlayState;

Entity* test;


void PlayState::Init(GameStateManager* manager)
{
	test = new Entity("Assets/R-Type/Textures/Player/Player.png");
}

void PlayState::Tick(GameStateManager* manager, float deltaTime)
{
}

void PlayState::Shutdown()
{
	delete test;
}

void PlayState::Render(GameStateManager* manager)
{
	test->Draw();
}

void PlayState::HandleEvents(GameStateManager* manager)
{
}
