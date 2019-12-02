#ifndef BACKGROUND_H
#define BACKGROUND_H

#include "GameObject.h"
#include "TextureManager.h"
#include "AudioManager.h"
#include "Sprite.h"
#include "Audio.h"


class Background : public GameObject
{
public:
	Background(glm::vec2 pos);
	virtual ~Background() {};

	virtual void Draw();
	virtual void Update();

public:
	bool IsAlive();
	bool IsAvtive();
	bool IsVisible();

	void IsAlive(bool flag);
	void IsAvtive(bool flag);
	void IsVisible(bool flag);


private:

	Sprite m_sprite;
	Audio m_music;

};


#endif