#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "Font.h"
#include "Hero.h"
using namespace std;

class Score :
	public Font
{
public:
	int score;
	string sScore;

	
	Score(SDL_Renderer* renderer);
	void compareScore(int* highestScore);
	void draw(int* highestScore);
	
};

