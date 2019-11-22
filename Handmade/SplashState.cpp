#include "SplashState.h"


const std::string SplashState::s_splashStateID = "Splash";

bool SplashState::Initialize(const std::string name, int width, int height)
{

	return true;
}

void SplashState::Draw()
{

}

void SplashState::Update()
{

}

bool SplashState::OnEnter()
{
	std::cout << "Entering SplashState" << std::endl;
	return true;
}

bool SplashState::OnExit()
{
	std::cout << "Exiting SplashState" << std::endl;
	return true;
}

void SplashState::ClearState()
{
	TheTexture::Instance()->UnloadFromMemory(TextureManager::TEXTURE_DATA, TextureManager::ALL_DATA);
	TheTexture::Instance()->UnloadFromMemory(TextureManager::FONT_DATA, TextureManager::ALL_DATA);


	TheAudio::Instance()->UnloadFromMemory(AudioManager::MUSIC_AUDIO, AudioManager::ALL_AUDIO);

	//close down audio 
	TheAudio::Instance()->ShutDown();

	//close down game screen 
	TheScreen::Instance()->ShutDown();
}
