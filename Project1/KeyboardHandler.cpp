#include "KeyboardHandler.h"



KeyboardHandler::KeyboardHandler()
{
}


KeyboardHandler::~KeyboardHandler()
{
}

void KeyboardHandler::update(SDL_Event* event){
	Mix_Music * music = NULL;

	//Check if Key is held down
	const Uint8* keystates = SDL_GetKeyboardState(NULL);//pass in array of keys you want to check OR NULL if you want state of alllll keys
	//reset velocity to zero, THEN check to see if each part should be changed
	//hero->velocity.x = 0;
	//hero->velocity.y = 0;
	
	
	//key is considered down if = 1, no held down = 0
	if (keystates[SDL_SCANCODE_UP]){
		hero->velocity.y += -4;
		Animation::angle = 0;
		if (hero->velocity.y < -180)
			hero->velocity.y = -180;
	}
	if (keystates[SDL_SCANCODE_DOWN]){
		hero->velocity.y += 4;
		Animation::angle = 180;
		if (hero->velocity.y > 180)
			hero->velocity.y = 180;
	}
	if (keystates[SDL_SCANCODE_LEFT]){
		hero->velocity.x += -4;
		Animation::angle = 270;
		if (hero->velocity.x < -180)
			hero->velocity.x = -180;
	}
	if (keystates[SDL_SCANCODE_RIGHT]){
		hero->velocity.x += 4;
		Animation::angle = 90;
		if (hero->velocity.x > 180)
			hero->velocity.x = 180;
	}
	if (keystates[SDL_SCANCODE_SPACE])
	{
		if (hero->velocity.y < 0)
			hero->velocity.y += 5;
		if (hero->velocity.y > 0)
			hero->velocity.y -= 5;
		if (hero->velocity.x < 0)
			hero->velocity.x += 5;
		if (hero->velocity.x > 0)
			hero->velocity.x -= 5;
	}
	if (keystates[SDL_SCANCODE_ESCAPE])
	{
		hero->pos.x = 706;
		hero->pos.y = 58;
		hero->velocity.x = 0;
		hero->velocity.y = 0;
		State::state = 0;
		State::level = 1;

		music = Mix_LoadMUS("assets/startMusic.mp3");
		if (music == NULL)
		{
			cout << "Music failed to load" << endl;
			SDL_Quit();
			system("pause");
		}
		Mix_PlayMusic(music, -1);
		
	}






}
