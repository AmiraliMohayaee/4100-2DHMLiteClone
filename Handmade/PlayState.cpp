#include "PlayState.h"


const std::string PlayState::s_playStateID = "Play";

bool PlayState::Initialize(const std::string name, int width, int height)
{
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

	//Audio audio;
	//audio.SetAudio("BACK_MUSIC", Audio::MUSIC_AUDIO);
	//audio.SetVolume(50);
	//audio.Play();

	//Sprite background;
	//background.SetTexture("BACKGROUND");
	//background.SetSpriteDimension(1024, 768);
	//background.SetTextureDimension(1, 1, 1024, 768);
	
	barrel.SetTexture("OBJECTS");
	barrel.SetSpriteDimension(100, 100);
	barrel.SetTextureDimension(3, 1, 200, 200);
	barrel.SetTextureCell(0, 0);

	
	box.SetTexture("OBJECTS");
	box.SetSpriteDimension(100, 100);
	box.SetTextureDimension(3, 1, 200, 200);
	box.SetTextureCell(1, 0);


	
	rock.SetTexture("OBJECTS");
	rock.SetSpriteDimension(100, 100);
	rock.SetTextureDimension(3, 1, 200, 200);
	rock.SetTextureCell(2, 0);

	
	Explosion.SetTexture("EXP");
	Explosion.SetAnimationVelocity(50.0f);
	Explosion.SetSpriteDimension(400, 400);
	Explosion.SetTextureDimension(8, 6, 128, 128);
	Explosion.IsAnimationLooping() = true;	// blow up forever

	
	Player.SetTexture("PLAYER");
	Player.SetAnimationVelocity(20.0f);
	Player.SetSpriteDimension(100, 250);
	Player.SetTextureDimension(8, 1, 127, 250);
	Player.IsAnimationLooping() = true;	// blow up forever


	
	textDraw.SetFont("FONT");
	textDraw.SetText("Hi There");
	textDraw.SetColor(100, 100, 100);
	textDraw.SetSize(400, 200);


	return true;
}

void PlayState::Draw()
{
	barrel.Draw(400, 400);
	box.Draw(400, 500);
	rock.Draw(400, 600);
	Explosion.Draw(550, 480);
	textDraw.Draw(100, 100);
}

void PlayState::Update()
{
	//main game loop!
	while (!m_endState)
	{

		//update screen by clearing SDL frame buffer
		TheScreen::Instance()->Update();

		//update input handling by listening for input events
		TheInput::Instance()->Update();

		//read keyboard state
		m_keys = TheInput::Instance()->GetKeyStates();

		//background->Draw();

		//if game window's top right X is clicked flag game to end
		if (TheInput::Instance()->IsXClicked())
		{
			m_endState = true;
		}

		//if escape key is pressed flag game to end
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
			Player.Draw(int(posX), 400, 0.0, Sprite::HORIZONTAL);
		}
		else if (m_keys[SDL_SCANCODE_A])
		{
			posX -= 20.0f;
			std::cout << "moving left\n";
			Player.Draw(int(posX), 400, 0.0, Sprite::NO_FLIP);
		}
		else
		{
			Player.Draw(int(posX), 400, 0.0);
		}


		//draw screen by swapping SDL frame buffer
		TheScreen::Instance()->Draw();

	}
}

bool PlayState::OnEnter()
{
	std::cout << "Entering PlayState" << std::endl;
	return true;
}

bool PlayState::OnExit()
{
	std::cout << "Exiting PlayState" << std::endl;
	return true;
}

void PlayState::ClearState()
{
	TheTexture::Instance()->UnloadFromMemory(TextureManager::TEXTURE_DATA, TextureManager::ALL_DATA);
	TheTexture::Instance()->UnloadFromMemory(TextureManager::FONT_DATA, TextureManager::ALL_DATA);


	TheAudio::Instance()->UnloadFromMemory(AudioManager::MUSIC_AUDIO, AudioManager::ALL_AUDIO);

	//close down audio 
	TheAudio::Instance()->ShutDown();

	//close down game screen 
	TheScreen::Instance()->ShutDown();
}
