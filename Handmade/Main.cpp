/*

  All code has been written by Karsten Vermeulen and may be used freely by anyone. It is by no
  means perfect and there is certainly room for improvement in some parts. As a whole, the code
  has been created as part of an engine for the purposes of educating other fellow programmers,
  and anyone else wishing to learn C++ and OOP. Feel free to use, copy, break, update and do as
  you wish with this code - it is there for all!

  UPDATED : February 2017

  -----------------------------------------------------------------------------------------------

- This is the main starting point for the game demo. The main game state is created here and added
  to the main game manager, from where it is run. Change the screen width and height accordingly, 
  and feel free to add more game states.

*/

//include SDL main header file to prevent 
//main lib conflicts in Release mode
#include <SDL.h> 

#include <iostream>
#include <string>
#include "AudioManager.h"
#include "InputManager.h"
#include "ScreenManager.h"
#include "Text.h"
#include "TextureManager.h"
#include "Sprite.h"
#include "Animation.h"
#include "Audio.h"
#include "Background.h"


//screen width and height values
int screenWidth = 1024;
int screenHeight = 768;

//variable for name of game demo
std::string gameName = "Street Fighting: Bootleg Guttertrash Edition";

//other variables
bool endGame = false;
const Uint8* keys = nullptr;

//------------------------------------------------------------------------------------------------------
//main function that processes everything  
//------------------------------------------------------------------------------------------------------
int main(int argc, char* args[])
{
	//initialise game screen and background rendering color
	TheScreen::Instance()->Initialize(gameName.c_str(), screenWidth, screenHeight);
	TheScreen::Instance()->SetClearColor(0, 0, 0);


	
	//initialize audio
	TheAudio::Instance()->Initialize();

	TheTexture::Instance()->Initialize();


	Background* background = new Background;


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


	Sprite barrel;
	barrel.SetTexture("OBJECTS");
	barrel.SetSpriteDimension(100, 100);
	barrel.SetTextureDimension(3, 1, 200, 200);
	barrel.SetTextureCell(0, 0);

	Sprite box;
	box.SetTexture("OBJECTS");
	box.SetSpriteDimension(100, 100);
	box.SetTextureDimension(3, 1, 200, 200);
	box.SetTextureCell(1, 0);


	Sprite rock;
	rock.SetTexture("OBJECTS");
	rock.SetSpriteDimension(100, 100);
	rock.SetTextureDimension(3, 1, 200, 200);
	rock.SetTextureCell(2, 0);

	Animation Explosion;
	Explosion.SetTexture("EXP");
	Explosion.SetAnimationVelocity(50.0f);
	Explosion.SetSpriteDimension(400, 400);
	Explosion.SetTextureDimension(8, 6, 128, 128);
	Explosion.IsAnimationLooping() = true;	// blow up forever

	Animation Player;
	Player.SetTexture("PLAYER");
	Player.SetAnimationVelocity(20.0f);
	Player.SetSpriteDimension(100, 250);
	Player.SetTextureDimension(8, 1, 127, 250);
	Player.IsAnimationLooping() = true;	// blow up forever


	Text textDraw;
	textDraw.SetFont("FONT");
	textDraw.SetText("Hi There");
	textDraw.SetColor(100, 100, 100);
	textDraw.SetSize(400, 200);



	static float posX = 600;
	static float posY = 300;


	//main game loop!
	while (!endGame)
	{

		//update screen by clearing SDL frame buffer
		TheScreen::Instance()->Update();

		//update input handling by listening for input events
		TheInput::Instance()->Update();

		//read keyboard state
		keys = TheInput::Instance()->GetKeyStates();

		background->Draw();

		//if game window's top right X is clicked flag game to end
		if (TheInput::Instance()->IsXClicked())
		{
			endGame = true;
		}

		//if escape key is pressed flag game to end
		if (keys[SDL_SCANCODE_ESCAPE])
		{
			endGame = true;
		}


		glm::vec2 mouseMotion = TheInput::Instance()->GetMouseMotion();

		//std::cout << mouseMotion.x << ", " << mouseMotion.y << std::endl;

		glm::vec2 mousePos = TheInput::Instance()->GetMousePosition();

		//std::cout << mousePos.x << ", " << mousePos.y << std::endl;

		
		barrel.Draw(400, 400);
		box.Draw(400, 500);
		rock.Draw(400, 600);
		Explosion.Draw(550, 480);
		textDraw.Draw(100, 100);


		//Player.Draw(int(posX), 400, 0.0, Sprite::HORIZONTAL);


		if (keys[SDL_SCANCODE_D])
		{
			posX += 20.0f;
			std::cout << "moving right\n";
			Player.Draw(int(posX), 400, 0.0, Sprite::HORIZONTAL);
		}
		else if (keys[SDL_SCANCODE_A])
		{
			posX -= 20.0f;
			std::cout << "moving left\n";
			Player.Draw(int(posX), 400, 0.0, Sprite::NO_FLIP);
		}


		//draw screen by swapping SDL frame buffer
		TheScreen::Instance()->Draw();

	}
	
	TheTexture::Instance()->UnloadFromMemory(TextureManager::TEXTURE_DATA, TextureManager::ALL_DATA);
	TheTexture::Instance()->UnloadFromMemory(TextureManager::FONT_DATA, TextureManager::ALL_DATA);


	TheAudio::Instance()->UnloadFromMemory(AudioManager::MUSIC_AUDIO, AudioManager::ALL_AUDIO);

	//close down audio 
	TheAudio::Instance()->ShutDown();

	//close down game screen 
	TheScreen::Instance()->ShutDown();

	//end application
	return 0;
}