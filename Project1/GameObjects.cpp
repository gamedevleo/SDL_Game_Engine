#include "GameObjects.h"

void GameObjects::setRenderer(SDL_Renderer* renderer){
	this->renderer = renderer;
}

void GameObjects::update(float dt){
	//nuthin
}

void GameObjects::updateMovement(float dt){
	pos.x = pos.x + (velocity.x*dt);
	pos.y = pos.y + (velocity.y*dt);
}

void GameObjects::draw(){
	//nada
}