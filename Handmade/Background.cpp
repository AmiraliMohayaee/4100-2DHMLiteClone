#include "Background.h"

Background::Background(glm::vec2 pos)
{
	TheTexture::Instance()->LoadTextureFromFile("Assets/Textures/level.jpg", "LEVEL");
	m_sprite.SetTexture("LEVEL");
	m_sprite.SetSpriteDimension(1280, 720);
	m_sprite.SetTextureDimension(1, 1, 1280, 720);
	

	TheAudio::Instance()->LoadFromFile("Assets/Audio/Ambient.ogg", AudioManager::MUSIC_AUDIO, "MUS");
	m_music.SetVolume(100);
	m_music.SetAudio("MUS", Audio::MUSIC_AUDIO);
	m_music.Play();

	m_pos = pos;
}

void Background::Draw()
{
	m_sprite.Draw();
}

void Background::Update()
{

}

bool Background::IsAlive()
{
	return m_isAlive;
}

bool Background::IsAvtive()
{
	return m_isActive;
}

bool Background::IsVisible()
{
	return m_isVisible;
}

void Background::IsAlive(bool flag)
{

}

void Background::IsAvtive(bool flag)
{

}

void Background::IsVisible(bool flag)
{

}
