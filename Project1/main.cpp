#include <iostream>
#include <string>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include "MouseHandler.h"
#include "KeyboardHandler.h"
#include "Menu.h"
#include "State.h"
#include "Hero.h"
#include "Font.h"
#include "Score.h"
#include "Leaderboard.h"



using namespace std;


int main(int argc, char **argv){

	//initialise everything of SDL
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
	{	//output something if failed
		cout << " SDL failed to initialise!" << endl;
		return -1;
	}  
	cout << "SDL sucessfully initialised!" << endl;
		//initialise the image
	if (!(IMG_Init(IMG_INIT_PNG)&IMG_INIT_PNG))
	{
		cout << "SDL Image didn't load: " << IMG_GetError()<< endl;
		SDL_Quit();
		system("pause");
		return -1;
	}

	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 4096) == -1)
	{
		cout << "Mixer did not initialise" << endl;
		SDL_Quit();
		system("pause");
		return -1;
	}

	if (TTF_Init() == -1)
	{
		cout << "font did not initialise" << endl;
	}

	// create a new window
	SDL_Window *window = SDL_CreateWindow("Crazy Animals", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1280, 720, SDL_WINDOW_SHOWN);
	//check if the window works
	if (window != NULL)
		cout << " Window created!" << endl;
	else
	{
		cout << "Window failed" << endl;
		return -1;
	}
	//create a renderer
	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	//check if it works
	if (renderer != NULL)
	{
		cout << "Renderer is created!" << endl;
	}
	else
	{
		cout << "Renderer failed" << endl;
		return -1;
	}

	Mix_Music* music = NULL;

	Menu * menu = new Menu();
	MouseHandler mouseHandler;
	mouseHandler.menu = menu;

	//menu bg
	SDL_Surface * backgroundSurface = IMG_Load("assets/titlescreen.png");
	//create a texture from surface
	SDL_Texture * backgroundTexture = SDL_CreateTextureFromSurface(renderer, backgroundSurface);
	//release the surface memory
	SDL_FreeSurface(backgroundSurface);
	//make a rectangle to draw the background texture
	SDL_Rect backgroundRect = { 0, 0, 1280, 720 };
	//copy the texture to renderer
	SDL_RenderCopy(renderer, backgroundTexture, NULL, &backgroundRect);

	//leaderboard bg
	SDL_Surface * leaderboardSurface = IMG_Load("assets/leaderboard.png");
	//create a texture from surface
	SDL_Texture * leaderboardTexture = SDL_CreateTextureFromSurface(renderer, leaderboardSurface);
	//release the surface memory
	SDL_FreeSurface(leaderboardSurface);



	//level 1
	SDL_Surface * level1Surface = IMG_Load("assets/map1.png");
	//create a texture from surface
	SDL_Texture * level1 = SDL_CreateTextureFromSurface(renderer, level1Surface);
	//release the surface memory
	SDL_FreeSurface(level1Surface);
	//make a rectangle to draw the background texture
	SDL_Rect level1Rect = { 0, 0, 1280, 720 };
	//copy the texture to renderer
	SDL_RenderCopy(renderer, level1, NULL, &level1Rect);

	//level 2
	SDL_Surface * level2Surface = IMG_Load("assets/map2.png");
	//create a texture from surface
	SDL_Texture * level2 = SDL_CreateTextureFromSurface(renderer, level2Surface);
	//release the surface memory
	SDL_FreeSurface(level2Surface);
	//make a rectangle to draw the background texture
	SDL_Rect level2Rect = { 0, 0, 1280, 720 };
	//copy the texture to renderer
	SDL_RenderCopy(renderer, level2, NULL, &level2Rect);

	//create character
	SDL_Surface* pandaSurface = IMG_Load("assets/panda.png");
	SDL_Texture* pandaTexture = SDL_CreateTextureFromSurface(renderer, pandaSurface);
	SDL_FreeSurface(pandaSurface);

	Animation anim(pandaTexture, renderer, 1, 72, 72, 0);
	Leaderboard leaderboard(renderer, leaderboardTexture);

	Hero* hero = new Hero();
	hero->setAnimation(&anim);
	hero->setRenderer(renderer);

	KeyboardHandler keyboardHandler;
	keyboardHandler.hero = hero;
	
	Font font(renderer);

	//setting up the time
	Uint32 lastUpdate = SDL_GetTicks();//milliseconds since the start of the game running
	//current frame (0-3)
	int currentFrame = 0;
	float frameTimer = 0.083;//83 milliseconds per frame

	int framesCounted = 0;
	float oneSecondTimer = 1;

	float millisecondsInASecond = 1000;

	music = Mix_LoadMUS("assets/startMusic.mp3");
	if (music == NULL)
	{
		cout << "Music failed to load" << endl;
		SDL_Quit();
		system("pause");
		return -1;
	}
	Mix_PlayMusic(music, -1);

	string sScore;
	int highestScore;
	ifstream myfile("Score.txt");

	if (myfile.is_open())
	{
		getline(myfile, sScore);
		highestScore = stoi(sScore);
		myfile.close();
	}
	else
	{
		cout << "error" << endl;
		SDL_Quit();
		system("pause");
	}

	Score s(renderer);
	//s.compareScore(&highestScore);
	while (State::loop)
	{
		
		//TIME!!!!
		//===================
		//get difference between currentTime running minus the last update time
		//ensures game runs at same speed for different computers
		Uint32 timeDiff = SDL_GetTicks() - lastUpdate;
		//convert to deltaTime
		float dt = timeDiff / millisecondsInASecond;
		
		//update lastUpdate to currentTime
		lastUpdate = SDL_GetTicks();

		framesCounted++;
		oneSecondTimer -= dt;//minusing how many milliseconds since last game loop cycle

		//1 second has passed
		if (oneSecondTimer <= 0)
		{
			cout << "FPS = " << framesCounted << " dt = " << dt << endl;
			framesCounted = 0;
			oneSecondTimer = 1;
		}

		SDL_Event event;

		while (SDL_PollEvent(&event)) {
			//check if user has closed window
			if (event.type == SDL_QUIT) {
				//exit loop
				State::loop = false;
			}

			mouseHandler.update(&event);
			keyboardHandler.update(&event);
		}
		
		if (State::state == 0)
		{
			//sets up menu button textures
			SDL_RenderCopy(renderer, backgroundTexture, NULL, &backgroundRect);
			menu->set_renderer(renderer);
			menu->drawmenu();//NEEDS TO CHANGE - currently continues to make and destroy textures instead of using a set of textures
			
			
		}
		if (State::state == 1)//main game
		{
			if (State::level == 1)
			{
				SDL_RenderCopy(renderer, level1, NULL, &level1Rect);
			}
			if (State::level == 2)
			{
				SDL_RenderCopy(renderer, level2, NULL, &level2Rect);
			}
			
			std::cout << hero->pos.x << " " << hero->pos.y << endl;
			hero->collide();
			hero->update(dt);
			hero->draw();
			//timer drawn
			int currentTime = SDL_GetTicks();
			Hero::timer = currentTime - Hero::startTime;
			
		}
		if (State::state == 2)//leaderboard
		{
			leaderboard.draw();
			font.draw();
			s.compareScore(&highestScore);
			s.draw(&highestScore);
		}

		//draw the game
		SDL_RenderPresent(renderer);
		//std::cout << State::state;
	}

	//cleanup
	SDL_DestroyTexture(backgroundTexture);
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);

	//shut down sdl subsystems
	SDL_Quit();

	return 0;
}