#include "GameStateManager.h"

// Adds the new state to the container 
void GameStateManager::PushState(GameState* pState)
{
	m_stateContainer.push_back(pState);
	m_stateContainer.back()->OnEnter();
}

// Checks a gamestate's tag and if there is any other
// state running, it will shut it down and assign the 
// current one to run 
void GameStateManager::ChangeState(GameState* pState)
{
	if (!m_stateContainer.empty())
	{
		if (m_stateContainer.back()->getStateID() == pState->getStateID())
		{
			return;	// Does nothing
		}

		if (m_stateContainer.back()->OnExit())
		{
			delete m_stateContainer.back();
			m_stateContainer.pop_back();
		}
	}

	m_stateContainer.push_back(pState);

	m_stateContainer.back()->OnEnter();
}

// Simply removing the assigned state and
// cleaning up after it
void GameStateManager::PopState()
{
	if (!m_stateContainer.empty())
	{
		if (m_stateContainer.back()->OnExit())
		{
			delete m_stateContainer.back();
			m_stateContainer.pop_back();
		}
	}

}
