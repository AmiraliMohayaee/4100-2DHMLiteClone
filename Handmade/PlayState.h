#ifndef PLAY_STATE_H
#define PLAY_STATE_H


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
#include <string>
#include <iostream>


class PlayState
{
public:
	// Initialize screen and sound pre-requisites
	bool Initialize(const std::string name, int width, int height);

	void Draw();
	void Update();

	void EventHandle();

	void ClearState();



private:
	GameObject* m_background;
	GameObject* m_player1;
	GameObject* m_player2;


	Animation m_explosion;
	Text m_textDraw;
	Audio m_audio;
	Sprite m_barrel;
	Sprite m_box;
	Sprite m_rock;

	float posX;
	float posY;

	//AABB m_p1bounds;
	//AABB m_p2bounds;

	const Uint8* m_keys = nullptr;

	bool m_endState;
};


#endif
