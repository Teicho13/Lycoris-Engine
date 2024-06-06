#pragma once
#include <vector>


enum class m_GameStates;
class GameState;
class GameStateManager
{
public:

	void Init();
	void Update(const float deltaTime);
	void Shutdown();
	void Render();
	void HandleEvents();

	void ChangeState(m_GameStates state);
	void RemoveState();

	std::vector<GameState*> m_States;
};
