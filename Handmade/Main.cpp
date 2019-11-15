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

//screen width and height values
int screenWidth = 1080;
int screenHeight = 720;

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

	//main game loop!
	while (!endGame)
	{

		//update screen by clearing SDL frame buffer
		TheScreen::Instance()->Update();

		//update input handling by listening for input events
		TheInput::Instance()->Update();

		//read keyboard state
		keys = TheInput::Instance()->GetKeyStates();

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

		//draw screen by swapping SDL frame buffer
		TheScreen::Instance()->Draw();

	}
	
	//close down audio 
	TheAudio::Instance()->ShutDown();

	//close down game screen 
	TheScreen::Instance()->ShutDown();

	//end application
	return 0;

}