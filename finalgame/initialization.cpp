#pragma once
#include"initialization.h"
#include"score.h"
#include"score.cpp"
bool init() {
	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_Init(SDL_INIT_AUDIO);
	TTF_Init();
	Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
	window = SDL_CreateWindow("Jungle King", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	Uint32 flags = SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC;
	renderer = SDL_CreateRenderer(window, -1, flags);

	backgroundLoader();
	characterLoader();
	soundLoader();
	bulletLoader();
	enemyLoader();
	
	gameOverLoader();
	return true;

}



void initializer() {

const int B_HEIGHT = 30;
const int B_WIDTH = 60;
// Initialized the background position and screen position here
gameOverPos.x = 0;
gameOverPos.y = 0;
gameOverPos.w = 1360;
gameOverPos.h = 760;

startScreenPos.x = 0;
startScreenPos.y = 0;
startScreenPos.w = 1360;
startScreenPos.h = 760;


backgroundAnchor.x = 0;
backgroundAnchor.y = 0;
backgroundAnchor.w = 1360 * 5;
backgroundAnchor.h = 760;
//here we initialize that our enemy is alive
for(int i =0; i< enemy_count;i++){
        enemyAlive.snakeAlive[i] = true;
    }
for(int i =0;i< enemy_count;i++){
        enemyAlive.vultureAlive[i] = true;
    }
for(int i = 0; i < enemy_count;i++){
        enemyAlive.hyenaAlive[i] = true;
    }
for(int i = 0; i < enemy_count;i++){
        enemyAlive.scorpionAlive[i] = true;
    }
}
// We have closed everything to free up the RAM
void clean() {
	
	SDL_FreeSurface(surface);
	Mix_FreeMusic(backgroundMusic);
	Mix_FreeChunk(bulletMusic);
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	window = NULL;
	IMG_Quit();
	SDL_Quit();

}
