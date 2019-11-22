#ifndef GAME_STATE_MANAGER_H
#define GAME_STATE_MANAGER_H

#include "GameState.h"
#include <vector>


class GameStateManager
{
public:
	void PushState(GameState* pState);
	void ChangeState(GameState* pState);
	void PopState();


protected:

	std::vector<GameState*> m_stateContainer;
};


#endif