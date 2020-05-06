#pragma once
#include "GameObjects.h"
#include "Animation.h"
#include "state.h"
#include <iostream>
#include <SDL_mixer.h>

using namespace std;
class Hero :
	public GameObjects, State
{
private:
	Animation* animation = NULL;
	
public:
	Hero();
	~Hero();

	void setAnimation(Animation* animation);

	//override GameObject methods
	virtual void collide();
	virtual void update(float dt);
	virtual void draw();

	static int timer;
	static int startTime;
	static bool finished;
};

