#include "TestState.h"


const std::string TestState::s_testStateID = "Test";

bool TestState::Initialize(const std::string name, int width, int height)
{
	return true;
}

void TestState::Draw()
{

}

void TestState::Update()
{

}

bool TestState::OnEnter()
{
	std::cout << "Entering TestState" << std::endl;
	return true;
}

bool TestState::OnExit()
{
	std::cout << "Exiting TestState" << std::endl;
	return true;
}

void TestState::ClearState()
{
	TheTexture::Instance()->UnloadFromMemory(TextureManager::TEXTURE_DATA, TextureManager::ALL_DATA);
	TheTexture::Instance()->UnloadFromMemory(TextureManager::FONT_DATA, TextureManager::ALL_DATA);


	TheAudio::Instance()->UnloadFromMemory(AudioManager::MUSIC_AUDIO, AudioManager::ALL_AUDIO);

	//close down audio 
	TheAudio::Instance()->ShutDown();

	//close down game screen 
	TheScreen::Instance()->ShutDown();

}
