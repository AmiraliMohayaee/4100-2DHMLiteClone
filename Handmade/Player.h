#ifndef PLAYER_H
#define PLAYER_H

#include "GameObject.h"
#include "AudioManager.h"
#include "TextureManager.h"
#include "Sprite.h"
#include "Animation.h"
#include "Audio.h"
#include "AABB.h"


class Player : public GameObject
{
public:
	Player(glm::vec2 pos);

	virtual void Draw();
	virtual void Update();


public:
	bool IsAlive();
	bool IsAvtive();
	bool IsVisible();

	void IsAlive(bool flag);
	void IsAvtive(bool flag);
	void IsVisible(bool flag);


protected:
	Sprite m_sprite;
	Audio m_audio;
	Animation m_anim;
	Animation m_lightP;
};

#endif