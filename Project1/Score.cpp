#include "Score.h"


Score::Score(SDL_Renderer* renderer)
{
	this->renderer = renderer;
	font = TTF_OpenFont("assets/FFF_Tusj.ttf", 40);
	textColor = { 255, 0, 0, 0 };

}

void Score::compareScore(int* highestScore)
{
	if (Hero::timer != 0 && Hero::finished == true)
	{
		score = Hero::timer/1000;
	}
	else
	{
		score = *highestScore;
	}
	if (score < *highestScore)
	{
		*highestScore = score;
		ofstream myfile("Score.txt");
		if (myfile.is_open())
		{
			myfile << score;
			myfile.close();
		}
	}
}

void Score::draw(int * highestScore)
{
	textSurface = TTF_RenderText_Blended(font, (to_string(*highestScore)).c_str(), textColor);
	textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
	SDL_FreeSurface(textSurface);

	SDL_Rect textDestRect;
	textDestRect.x = 550;
	textDestRect.y = 330;

	SDL_QueryTexture(textTexture, NULL, NULL, &textDestRect.w, &textDestRect.h);
	SDL_RenderCopy(renderer, textTexture, NULL, &textDestRect);
	SDL_DestroyTexture(textTexture);
}


