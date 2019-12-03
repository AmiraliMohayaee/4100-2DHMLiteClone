#include "Background.h"

Background::Background(glm::vec2 pos)
{
	TheTexture::Instance()->LoadTextureFromFile("Assets/Textures/HondaStage.jpg", "LEVEL");
	m_sprite.SetTexture("LEVEL");
	m_sprite.SetSpriteDimension(1280, 720);
	m_sprite.SetTextureDimension(1, 1, 3072, 1234);
	

	TheAudio::Instance()->LoadFromFile("Assets/Audio/GuileTheme.ogg", AudioManager::MUSIC_AUDIO, "MUS");
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
