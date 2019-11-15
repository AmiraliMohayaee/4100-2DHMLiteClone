#include "Background.h"

Background::Background()
{
	TheTexture::Instance()->LoadTextureFromFile("Assets/Textures/Background.jpg", "BACKGROUND");
	m_sprite.SetTexture("BACKGROUND");
	m_sprite.SetSpriteDimension(1024, 768);
	m_sprite.SetTextureDimension(1, 1, 1024, 768);
	//m_music;

	TheAudio::Instance()->LoadFromFile("Assets/Audio/Ambient.ogg", AudioManager::MUSIC_AUDIO, "MUS");
	m_music.SetVolume(100);
	m_music.SetAudio("MUS", Audio::MUSIC_AUDIO);
	m_music.Play();
}

void Background::Draw()
{
	m_sprite.Draw();
}
