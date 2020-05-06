#pragma once
#include <SDL_mixer.h>
#include "InputHandler.h"
#include "Animation.h"
class MouseHandler :
	public InputHandler
{
	int state = 0;

public:
	MouseHandler();
	~MouseHandler();
	int controlNumber = 0;

	//override
	void update(SDL_Event* event);
};

