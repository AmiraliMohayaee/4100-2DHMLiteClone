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
	Background();
	virtual ~Background() {};

	virtual void Draw();
	virtual void Update() {};

private:
	Sprite m_sprite;
	Audio m_music;

};


#endif