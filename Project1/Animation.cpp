#include "Animation.h"


Animation::Animation(SDL_Texture* spriteSheet, SDL_Renderer* renderer, int numberOfFrames, int frameWidth, int frameHeight, float frameDuration){
	this->spriteSheet = spriteSheet;
	this->renderer = renderer;
	this->numberOfFrames = numberOfFrames;
	this->frameWidth = frameWidth;
	this->frameHeight = frameHeight;
	this->frameDuration = frameDuration;
	angle = 0;


}

int Animation::angle;

void Animation::draw(int x, int y){
	SDL_Rect srcRect;
	srcRect.x = currentFrame*frameWidth;
	srcRect.y = 0;
	srcRect.w = frameWidth;
	srcRect.h = frameHeight;
	SDL_RendererFlip flipType = SDL_FLIP_NONE;

	//setup destination rect
	SDL_Rect destRect = { x, y, frameWidth/2, frameHeight/2 };
	//draw
	SDL_RenderCopyEx(renderer, spriteSheet, &srcRect, &destRect, angle, NULL, flipType);
}
