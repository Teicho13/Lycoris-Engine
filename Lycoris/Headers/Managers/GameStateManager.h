#pragma once
#include <vector>

class GameState;
class GameStateManager
{
public:

	void Init();
	void Update(const float deltaTime);
	void Shutdown();
	void Render();
	void HandleEvents();

	void ChangeState(GameState* state);
	void RemoveState();

	std::vector<GameState*> m_States;
};
