#include "Menu.h"
#include <iostream>



Menu::Menu()
{

}


Menu::~Menu()
{
	SDL_DestroyTexture(startButtonTexture);
	SDL_DestroyTexture(leaderButtonTexture);
	SDL_DestroyTexture(quitButtonTexture);
}

void Menu::set_renderer(SDL_Renderer * renderer)
{
	this->renderer = renderer;
}

void Menu::drawmenu()//need to seperate creation of textures and rendering of texture in future.
{
	
	if (button1)//check what version of button to use
		startButtonSurface = IMG_Load("assets/startbuttonactiviteIMG.png");
	else
		startButtonSurface = IMG_Load("assets/startbuttonIMG.png");

	startButtonTexture = SDL_CreateTextureFromSurface(renderer, startButtonSurface);
	SDL_FreeSurface(startButtonSurface);
	SDL_Rect startButtonRect = { 0, 0, 100, 100 };
	SDL_Rect SBDestation;
	SBDestation.x = 100;
	SBDestation.y = 300;
	SBDestation.w = 150;
	SBDestation.h = 60;
	
	
	//SDL_RenderPresent(renderer);

	
	if (button2)//check what version of button to use
		leaderButtonSurface = IMG_Load("assets/leaderboardactiviteIMG.png");
	else
		leaderButtonSurface = IMG_Load("assets/leaderboardIMG.png");

	leaderButtonTexture = SDL_CreateTextureFromSurface(renderer, leaderButtonSurface);
	SDL_FreeSurface(leaderButtonSurface);
	SDL_Rect leaderButtonRect = { 0,0 };
	SDL_Rect LBDestation;
	LBDestation.x = 100;
	LBDestation.y = 400;
	LBDestation.w = 330;
	LBDestation.h = 60;

	
	if (button3)//check what version of button to use
		quitButtonSurface = IMG_Load("assets/quitactiviteIMG.png");
	else
		quitButtonSurface = IMG_Load("assets/quitIMG.png");

	quitButtonTexture = SDL_CreateTextureFromSurface(renderer, quitButtonSurface);
	SDL_FreeSurface(quitButtonSurface);
	SDL_Rect quitButtonRect = { 0, 0 };
	SDL_Rect QBDestation;
	QBDestation.x = 100;
	QBDestation.y = 500;
	QBDestation.w = 120;
	QBDestation.h = 60;


	/*SDL_QueryTexture(startButtonTexture, NULL, NULL, &startButtonRect.w, &startButtonRect.h);
	SDL_QueryTexture(leaderButtonTexture, NULL, NULL, &leaderButtonRect.w, &leaderButtonRect.h);
	SDL_QueryTexture(quitButtonTexture, NULL, NULL, &quitButtonRect.w, &quitButtonRect.h);*/

	//put textures into renderer
	SDL_RenderCopy(renderer, startButtonTexture, NULL, &SBDestation);
	SDL_RenderCopy(renderer, leaderButtonTexture, NULL, &LBDestation);
	SDL_RenderCopy(renderer, quitButtonTexture, NULL, &QBDestation);

	SDL_DestroyTexture(startButtonTexture);
	SDL_DestroyTexture(leaderButtonTexture);
	SDL_DestroyTexture(quitButtonTexture);


}

void Menu::startGame()
{

}

void Menu::showLeadBord()
{
}

void Menu::Quit()
{
	State::loop = false;
}