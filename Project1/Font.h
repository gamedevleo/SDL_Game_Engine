#pragma once
#include <SDL.h>
#include <SDL_ttf.h>
#include <iostream>
#include <sstream>

class Font
{
public:
	TTF_Font* font;
	SDL_Color textColor;
	SDL_Surface* textSurface;
	SDL_Texture* textTexture;
	SDL_Renderer* renderer;
	
	Font();

	Font(SDL_Renderer* renderer);
	void draw();

	void setTextfont();//add a new function to set the font

};

