#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include "State.h"


using namespace std;

class Menu
{
public:
	bool button1 = false;
	bool button2 = false;
	bool button3 = false;
	SDL_Renderer* renderer;
	SDL_Surface* startButtonSurface;
	SDL_Surface* leaderButtonSurface;
	SDL_Surface* quitButtonSurface;
	SDL_Texture* startButtonTexture;
	SDL_Texture* leaderButtonTexture;
	SDL_Texture* quitButtonTexture;


	Menu();
	~Menu();

	void set_renderer(SDL_Renderer* renderer);

	void drawmenu();
	

	void startGame();
	void showLeadBord();
	void Quit();
};