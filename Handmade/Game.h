#ifndef GAME_H
#define GAME_H

#include "Singleton.h"


class Game
{
public:
	friend class Singleton<Game>;

private:
	Game();
	Game(const Game&);
	Game operator=(const Game&);

public:
	void Draw();
	void Update();

};


#endif