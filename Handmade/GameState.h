#ifndef GAME_STATE_H
#define GAME_STATE_H

#include <string>


class GameState
{
public:
	virtual bool Initialize(const std::string name, int width, int height) = 0;
	virtual void Draw() = 0;
	virtual void Update() = 0;

	virtual void PauseState() = 0;
	virtual void UnPauseState() = 0;

	virtual void EventHandle() = 0;

	virtual bool OnEnter() = 0;
	virtual bool OnExit() = 0;

	virtual void ClearState() = 0;

	virtual std::string getStateID() const = 0;

	bool m_endState;

};


#endif