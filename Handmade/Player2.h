#ifndef PLAYER_2_H
#define PLAYER_2_H

#include "GameObject.h"
#include "AudioManager.h"
#include "TextureManager.h"
#include "Sprite.h"
#include "Animation.h"
#include "Audio.h"
#include "AABB.h"


class Player2 : public GameObject
{
public:
	Player2(glm::vec2 pos);

	virtual void Draw();
	virtual void Update();


public:
	bool IsAlive();
	bool IsAvtive();
	bool IsVisible();

	void IsAlive(bool flag);
	void IsAvtive(bool flag);
	void IsVisible(bool flag);

	bool IsColliding(GameObject& go);

protected:
	Sprite m_sprite;
	Audio m_audio;
	Animation m_anim;
	Animation m_lightP;
	Animation m_walk;

	// Implementing input for player object as
	// not all GOs need to get or return input
	const Uint8* m_keys = nullptr;
};

#endif