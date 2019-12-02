#include "TestState.h"


const std::string TestState::s_testStateID = "Test";

bool TestState::Initialize(const std::string name, int width, int height)
{
	m_endState = false;

	//initialise game screen and background rendering color
	TheScreen::Instance()->Initialize(name.c_str(), width, height);
	TheScreen::Instance()->SetClearColor(0, 0, 0);

	//initialize audio
	TheAudio::Instance()->Initialize();

	TheTexture::Instance()->Initialize();

	TheTexture::Instance()->LoadTextureFromFile("Assets/Textures/Background.jpg", "BACKGROUND");
	TheTexture::Instance()->LoadTextureFromFile("Assets/Sprites/objects.png", "OBJECTS");
	TheTexture::Instance()->LoadTextureFromFile("Assets/Sprites/Explosion.png", "EXP");
	TheTexture::Instance()->LoadTextureFromFile("Assets/Sprites/Hero.png", "PLAYER");
	TheTexture::Instance()->LoadFontFromFile("Assets/Fonts/Impact.ttf", 100, "FONT");

	TheAudio::Instance()->LoadFromFile("Assets/Audio/Ambient.ogg", AudioManager::MUSIC_AUDIO, "BACK_MUSIC");

	//read keyboard state
	TheInput::Instance()->Update();
	m_keys = TheInput::Instance()->GetKeyStates();

	m_audio.SetAudio("BACK_MUSIC", Audio::MUSIC_AUDIO);
	m_audio.SetVolume(50);
	m_audio.Play();

	//m_background.SetTexture("BACKGROUND");
	//m_background.SetSpriteDimension(1024, 768);
	//m_background.SetTextureDimension(1, 1, 1024, 768);

	m_barrel.SetTexture("OBJECTS");
	m_barrel.SetSpriteDimension(100, 100);
	m_barrel.SetTextureDimension(3, 1, 200, 200);
	m_barrel.SetTextureCell(0, 0);

	m_box.SetTexture("OBJECTS");
	m_box.SetSpriteDimension(100, 100);
	m_box.SetTextureDimension(3, 1, 200, 200);
	m_box.SetTextureCell(1, 0);

	m_rock.SetTexture("OBJECTS");
	m_rock.SetSpriteDimension(100, 100);
	m_rock.SetTextureDimension(3, 1, 200, 200);
	m_rock.SetTextureCell(2, 0);

	m_explosion.SetTexture("EXP");
	m_explosion.SetAnimationVelocity(50.0f);
	m_explosion.SetSpriteDimension(400, 400);
	m_explosion.SetTextureDimension(8, 6, 128, 128);
	m_explosion.IsAnimationLooping() = true;	// blow up forever

	m_player.SetTexture("PLAYER");
	m_player.SetAnimationVelocity(20.0f);
	m_player.SetSpriteDimension(100, 250);
	m_player.SetTextureDimension(8, 1, 127, 250);
	m_player.IsAnimationLooping() = true;	// blow up forever

	m_textDraw.SetFont("FONT");
	m_textDraw.SetText("Hi There");
	m_textDraw.SetColor(100, 100, 100);
	m_textDraw.SetSize(400, 200);


	return true;
}

void TestState::Draw()
{
	m_barrel.Draw(400, 400);
	m_box.Draw(400, 500);
	m_rock.Draw(400, 600);
	m_explosion.Draw(550, 480);
	m_textDraw.Draw(100, 100);

	//draw screen by swapping SDL frame buffer
	TheScreen::Instance()->Draw();
}

void TestState::Update()
{
	//main game loop!
	while (!m_endState)
	{
		Draw();
		EventHandle();
		//update screen by clearing SDL frame buffer
		TheScreen::Instance()->Update();

		//update input handling by listening for input events
		TheInput::Instance()->Update();

		//background->Draw();

		//if game window's top right X is clicked flag game to end
		if (TheInput::Instance()->IsXClicked())
		{
			m_endState = true;
		}

		// if escape key is pressed flag game to end]
		// Alternative if the statemachine fails
		if (m_keys[SDL_SCANCODE_ESCAPE])
		{
			m_endState = true;
		}


		glm::vec2 mouseMotion = TheInput::Instance()->GetMouseMotion();

		//std::cout << mouseMotion.x << ", " << mouseMotion.y << std::endl;

		glm::vec2 mousePos = TheInput::Instance()->GetMousePosition();

		//std::cout << mousePos.x << ", " << mousePos.y << std::endl;



		//Player.Draw(int(posX), 400, 0.0, Sprite::HORIZONTAL);


		if (m_keys[SDL_SCANCODE_D])
		{
			posX += 20.0f;
			std::cout << "moving right\n";
			m_player.Draw(int(posX), 400, 0.0, Sprite::HORIZONTAL);
		}
		else if (m_keys[SDL_SCANCODE_A])
		{
			posX -= 20.0f;
			std::cout << "moving left\n";
			m_player.Draw(int(posX), 400, 0.0, Sprite::NO_FLIP);
		}
		else
		{
			m_player.Draw(int(posX), 400, 0.0, Sprite::HORIZONTAL);
		}



		//draw screen by swapping SDL frame buffer
		TheScreen::Instance()->Draw();

	}
}

void TestState::PauseState()
{

}

void TestState::UnPauseState()
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

void TestState::EventHandle()
{
	if (m_keys[SDL_SCANCODE_RETURN])
	{
//		m_gameStateManager->ChangeState(new SplashState);
	}
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
