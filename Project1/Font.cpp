#include "Font.h"


Font::Font()
{
}


Font::Font(SDL_Renderer* renderer)
{
	this->renderer = renderer;
	
	font = TTF_OpenFont("assets/FFF_Tusj.ttf", 40);
	textColor = { 255, 0, 0, 0 };
	textSurface = TTF_RenderText_Blended(font, "Best time", textColor);
	textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);

	SDL_FreeSurface(textSurface);
}

void Font::draw(){
	SDL_Rect textDestRect; 
	textDestRect.x = 515;
	textDestRect.y = 290;

	SDL_QueryTexture(textTexture, NULL, NULL, &textDestRect.w, &textDestRect.h);
	SDL_RenderCopy(renderer, textTexture, NULL, &textDestRect);

}

void Font::setTextfont()
{
	this->font = TTF_OpenFont("assets/FFF_Tusj.ttf", 40);
	this->textColor = { 255, 0, 0, 0 };
}