#pragma once
#include <SDL.h>
#include "Menu.h"
#include "State.h"
#include "Hero.h"
class InputHandler
{
public:
	Menu * menu;// Class identifier
	Hero* hero;
	InputHandler();
	~InputHandler();


	virtual void update(SDL_Event* event) = 0;
};

