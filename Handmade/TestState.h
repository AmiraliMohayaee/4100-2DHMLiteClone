#ifndef TEST_STATE_H
#define TEST_STATE_H

#include "GameState.h"
#include "AudioManager.h"
#include "TextureManager.h"
#include "InputManager.h"
#include "AudioManager.h"
#include "ScreenManager.h"
#include "Sprite.h"
#include "Audio.h"
#include "Animation.h"
#include "Text.h"
#include <string>
#include <iostream>


class TestState : public GameState
{
public:
	// Initialize screen and sound pre-requisites
	virtual bool Initialize(const std::string name, int width, int height);

	virtual void Draw();
	virtual void Update();

	virtual bool OnEnter();
	virtual bool OnExit();

	void ClearState();

	virtual std::string getStateID() const
	{
		return s_testStateID;
	}


private:

	bool m_endGame = false;
	const Uint8* m_keys = nullptr;

	static const std::string s_testStateID;

};


#endif
