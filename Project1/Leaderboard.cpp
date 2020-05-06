#include "Leaderboard.h"


Leaderboard::Leaderboard(SDL_Renderer* renderer, SDL_Texture* leaderboardTexture)
{
	this->renderer = renderer;
	this->leaderboardTexture = leaderboardTexture;
}


void Leaderboard::draw()
{
	SDL_Rect destRect = { 0, 0, 1280, 720 };
	SDL_RenderCopy(renderer, leaderboardTexture, NULL, &destRect);
}
