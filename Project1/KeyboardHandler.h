#pragma once
#include <SDL_mixer.h>
#include "InputHandler.h"
#include "Animation.h"
#include "Hero.h"
class KeyboardHandler :
	public InputHandler
{
public:
	KeyboardHandler();
	~KeyboardHandler();
	

	void update(SDL_Event* event);
};

