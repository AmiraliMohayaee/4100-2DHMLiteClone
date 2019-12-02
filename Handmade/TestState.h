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
#include "Background.h"
#include "GameStateManager.h"
#include <string>
#include <iostream>


class TestState : public GameState
{
public:
	// Initialize screen and sound pre-requisites
	virtual bool Initialize(const std::string name, int width, int height);

	virtual void Draw();
	virtual void Update();

	virtual void PauseState();
	virtual void UnPauseState();

	virtual bool OnEnter();
	virtual bool OnExit();

	virtual void EventHandle();

	virtual void ClearState();

	virtual std::string getStateID() const
	{
		return s_testStateID;
	}


private:
	Sprite m_barrel;
	Sprite m_box;
	Sprite m_rock;
	Background m_background;
	Animation m_explosion;
	Animation m_player;
	Text m_textDraw;
	Audio m_audio;
	GameObject* m_player1;
	GameObject* m_player2;


	float posX;
	float posY;

	bool m_endGame = false;
	const Uint8* m_keys = nullptr;

	static const std::string s_testStateID;

	GameStateManager* m_gameStateManager;
};


#endif
