#include "MouseHandler.h"



MouseHandler::MouseHandler()
{
}


MouseHandler::~MouseHandler()
{
}

void MouseHandler::update(SDL_Event* event) {
	Mix_Music * music = NULL;

	if (State::state == 0)
	{
		if (event->motion.x >= 100 && event->motion.x <= 250 && event->motion.y >= 300 && event->motion.y <= 360) {//check button position
			menu->button1 = true;//change button state to change its colour
			if (event->type == SDL_MOUSEBUTTONDOWN && event->button.button == SDL_BUTTON_LEFT)
			{
				State::state = 1;
				if (controlNumber == 0)
				{
					Hero::startTime = SDL_GetTicks();
					controlNumber++;
				}
				music = Mix_LoadMUS("assets/racingMusic.mp3");
				if (music == NULL)
				{
					cout << "Music failed to load" << endl;
					SDL_Quit();
					system("pause");
				}
				Mix_PlayMusic(music, -1);
			}
		}
		else if (event->motion.x >= 100 && event->motion.x <= 430 && event->motion.y >= 400 && event->motion.y <= 460) {
			menu->button2 = true;
			if (event->type == SDL_MOUSEBUTTONDOWN && event->button.button == SDL_BUTTON_LEFT)
			{
				State::state = 2;
				music = Mix_LoadMUS("assets/leaderboardMusic.mp3");
				if (music == NULL)
				{
					cout << "Music failed to load" << endl;
					SDL_Quit();
					system("pause");
				}
				Mix_PlayMusic(music, -1);
			}
		}
		else if (event->motion.x >= 100 && event->motion.x <= 240 && event->motion.y >= 500 && event->motion.y <= 560) {
			menu->button3 = true;
			if (event->type == SDL_MOUSEBUTTONDOWN && event->button.button == SDL_BUTTON_LEFT)
			{
				menu->Quit();
			}
			
		}
		else
		{
			//will reset button state when it is not being hovered over
			menu->button1 = false;
			menu->button2 = false;
			menu->button3 = false;
		}

		

	}
	
}