#ifndef GAME_H
#define GAME_H

#include "Singleton.h"
#include "GameState.h"
#include "AudioManager.h"
#include "TextureManager.h"
#include "InputManager.h"
#include "AudioManager.h"
#include "ScreenManager.h"
#include <string>

class Game : public GameState
{
public:
	friend class Singleton<Game>;

public:
	// Initialize screen and sound pre-requisites
	bool Init(const std::string name, int width, int height);
	
	void Draw();
	void Update();

	void ClearState();
private:
	bool m_endGame = false;
	const Uint8* m_keys = nullptr;



private:
	Game();
	Game(const Game&);
	Game& operator=(const Game&);

};

typedef Singleton<Game> TheGame;

#endif