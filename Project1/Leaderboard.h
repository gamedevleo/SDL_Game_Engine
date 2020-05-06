#pragma once
#include <SDL.h>
#include <SDL_image.h>
class Leaderboard
{
public:
	SDL_Renderer* renderer;
	SDL_Texture* leaderboardTexture;

	Leaderboard(SDL_Renderer* renderer, SDL_Texture* leaderboardTexture);
	void draw();
	
};

