#include "Hero.h"





Hero::Hero()
{
	this->pos.x = 706;
	this->pos.y = 58;
	Animation::angle = 90;
	finished = false;
}


Hero::~Hero()
{
}


void Hero::setAnimation(Animation* animation){
	this->animation = animation;
}


void Hero::update(float dt){
	//if moving on the X axis, change facing
	

	//std::cout << "x = " << velocity.x << " y = " << velocity.y << std::endl;

	if (velocity.y < 0)
		velocity.y += 0.3;
	if (velocity.y > 0)
		velocity.y -= 0.3;
	if (velocity.x < 0)
		velocity.x += 0.3;
	if (velocity.x > 0)
		velocity.x -= 0.3;

	if (State::state == 1 && pos.x < 670 && pos.x > 626 && pos.y > 12 && pos.y < 96)
	{
		if (State::level == 1)
			State::level = 2;
		else if (State::level == 2)
		{
			State::state = 0;
			finished = true;
		}
			
		
		pos.x = 706;
		pos.y = 58;
		velocity.x = 0;
		velocity.y = 0;
	}


	//move character based on velocity
	updateMovement(dt);

}

void Hero::collide(){
	if (State::level == 1)
	{
		//outer boundry
		if (pos.x < 30)
		{
			pos.x = 30;
			velocity.x = velocity.x * -(0.8);
		}
		if (pos.x > 1210)
		{
			pos.x = 1210;
			velocity.x = velocity.x * -(0.8);
		}
		if (pos.y < 30)
		{
			pos.y = 30;
			velocity.y = velocity.y * -(0.8);
		}
		if (pos.y > 650)
		{
			pos.y = 650;
			velocity.y = velocity.y * -(0.8);
		}

		//top inner
		if (pos.y > 85 && pos.y < 90 && pos.x > 85 && pos.x < 1160)
		{
			pos.y = 85;
			velocity.y = velocity.y * -(0.8);
		}

		//bottom inner
		if (pos.y < 600 && pos.y > 595 && pos.x > 85 && pos.x < 1160)
		{
			pos.y = 600;
			velocity.y = velocity.y * -(0.8);
		}

		//right inner
		if (pos.x < 1160 && pos.x > 1150 && pos.y > 85 && pos.y < 600)
		{
			pos.x = 1160;
			velocity.x = velocity.x * -(0.8);
		}
		
		//left inner
		if (pos.x > 85 && pos.x < 90 && pos.y > 85 && pos.y < 600)
		{
			pos.x = 85;
			velocity.x = velocity.x * -(0.8);
		}

		//start wall
		if (pos.x < 700 && pos.x > 695 && pos.y < 120)
		{
			pos.x = 700;
			velocity.x = velocity.x * -(0.8);
		}
	}
	else if (State::level == 2)
	{
		//outer boundry
		if (pos.x < 30)
		{
			pos.x = 30;
			velocity.x = velocity.x * -(0.8);
		}
		if (pos.x > 1210)
		{
			pos.x = 1210;
			velocity.x = velocity.x * -(0.8);
		}
		if (pos.y < 30)
		{
			pos.y = 30;
			velocity.y = velocity.y * -(0.8);
		}
		if (pos.y > 650)
		{
			pos.y = 650;
			velocity.y = velocity.y * -(0.8);
		}

		//start wall
		if (pos.x < 700 && pos.x > 695 && pos.y < 120)
		{
			pos.x = 700;
			velocity.x = velocity.x * -(0.8);
		}

		//right most wall
		if (pos.x > 975)
		{
			pos.x = 975;
			velocity.x = velocity.x * -(0.8);
		}

		//outer wall 1
		if (pos.y > 353 && pos.y < 360 && pos.x > 600)
		{
			pos.y = 353;
			velocity.y = velocity.y * -(0.8);
		}

		//outer wall 2
		if (pos.x < 693 && pos.x > 688 && pos.y > 245)
		{
			pos.x = 693;
			velocity.x = velocity.x * -(0.8);
		}

		//outer wall 3
		if (pos.y > 245 && pos.y < 250 && pos.x < 693 && pos.x > 245)
		{
			pos.y = 245;
			velocity.y = velocity.y * -(0.8);
		}

		//outer wall 4
		if (pos.x > 245 && pos.x < 250 && pos.y > 245 && pos.y < 460)
		{
			pos.x = 245;
			velocity.x = velocity.x * -(0.8);
		}

		//outer wall 5
		if (pos.y < 460 && pos.y > 455 && pos.x > 245)
		{
			pos.y = 460;
			velocity.y = velocity.y * -(0.8);
		}

		//outer wall 6
		if (pos.x > 395 && pos.x < 405 && pos.y > 460)
		{
			pos.x = 395;
			velocity.x = velocity.x * -(0.8);
		}

		//top inner wall
		if (pos.y > 85 && pos.y < 90 && pos.x > 85 && pos.x < 914)
		{
			pos.y = 85;
			velocity.y = velocity.y * -(0.8);
		}

		//right inner wall
		if (pos.x < 915 && pos.x > 910 && pos.y > 85 && pos.y < 300)
		{
			pos.x = 915;
			velocity.x = velocity.x * -(0.8);
		}

		//inner wall 1
		if (pos.y < 300 && pos.y > 295 && pos.x < 915 && pos.x > 750)
		{
			pos.y = 300;
			velocity.y = velocity.y * -(0.8);
		}

		//inner wall 2
		if (pos.x > 750 && pos.x < 755 && pos.y < 300 && pos.y > 180)
		{
			pos.x = 750;
			velocity.x = velocity.x * -(0.8);
		}

		//inner wall 3
		if (pos.y < 185 && pos.y > 170 && pos.x < 750 && pos.x > 188)
		{
			pos.y = 185;
			velocity.y = velocity.y * -(0.8);
		}

		//inner wall 4
		if (pos.x < 188 && pos.x > 180 && pos.y > 185 && pos.y < 550)
		{
			pos.x = 188;
			velocity.x = velocity.x * -(0.8);
		}

		//inner wall 5
		if (pos.y > 512 && pos.y < 520 && pos.x > 188 && pos.x < 335)
		{
			pos.y = 512;
			velocity.y = velocity.y * -(0.8);
		}

		//tiny inner wall
		if (pos.x < 335 && pos.x > 330 && pos.y > 512 && pos.y < 600)
		{
			pos.x = 335;
			velocity.x = velocity.x * -(0.8);
		}

		//bottom inner wall
		if (pos.y < 600 && pos.y > 595 && pos.x < 335 && pos.x > 85)
		{
			pos.y = 600;
			velocity.y = velocity.y * -(0.8);
		}

		//left inner wall
		if (pos.x > 85 && pos.x < 90 && pos.y < 600 && pos.y > 85)
		{
			pos.x = 85;
			velocity.x = velocity.x * -(0.8);
		}
	}
}

void Hero::draw(){
	if (animation != NULL)
	{
		animation->draw(pos.x, pos.y);
	}

}

int Hero::timer;
int Hero::startTime;
bool Hero::finished;