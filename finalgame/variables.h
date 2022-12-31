#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_timer.h>
#include<SDL2/SDL_mixer.h>
#include<SDL2/SDL_ttf.h>
#include<sstream>
#include<fstream>
#include <bits/stdc++.h>
using namespace std;

#define SCREEN_WIDTH  1360
#define	SCREEN_HEIGHT 760
#define SCROLL_SPEED 300 ;

const int FPS = 60;
const int PIXELS_PER_FRAME = 5;
const int JUMP_PER_FRAME = 4; 
const int BULLET_WIDTH = 45;
const int BULLET_HEIGHT = 25;

struct EnemyAliveState {
    bool snakeAlive[20];
    bool vultureAlive[20];
    bool hyenaAlive[20];
    bool scorpionAlive[20];
} enemyAlive;

struct Bullet {
	char direction;
	// int initX;
	// int initY;
	SDL_Rect bulletPosition;
	bool active = false;
	bool end;
} bullet[5000];



struct Snake {
	int initX;
	int initY;
	SDL_Rect snakePosition;
	bool active;
} snake[20];

struct Hyena {
	int initX;
	int initY;
	SDL_Rect hyenaPosition;
	bool active;
} hyena[20];

struct Scorpion {
	int initX;
	int initY;
	SDL_Rect scorpionPosition;
	bool active;
} scorpion[20];

struct Vulture {
	int initX;
	int initY;
	SDL_Rect vulturePosition;
	bool active;
} vulture[20];


extern int enemy_count ;



int textureWidth1, textureHeight1 , frameHeight1, frameWidth1 , backgroundTextureWidth, backgroundTextureHeight ,
    playerCurrentFrame, frameWidth, frameHeight, backgroundFrameWidth, 
    backgroundFrameHeight , textureWidth,  texTureHeight, gameOverTextureWidth, gameOverTextureHeight , 
	prevScore ,   frameTime = 10, backgroundFrameRate = 0 ,
	totalMoveX = 6, bulletActive = 0 , playerMoveX = 0, playerMoveY = 0, bulletFired = 0, flag = 0 , enemy_count = 20  ;


int score =  0 ;

bool vultureAlive = true, hyenaAlive = true, scorpionAlive = true, snakeAlive = true , 
    running = true, game_start = false, game_over = false, game_won = false, jump = false;


char playerDirection;

SDL_Rect   backgroundPos , backgroundRect , playerPos , playerRect , gameOverPos , startScreenPos ,
        backgroundAnchor,snakePos[20], hyenaPos[20], scorpionPos[20], vulturePos[20], snakeRect[20] ,
        hyenaRect[20], vultureRect[20], scorpionRect[20] , highScorePos, yourScorePos, scorePos, newGamePos,  
        vultureDeadPos, hyenaDeadPos, scorpionDeadPos, snakeDeadPos,  gameOverRect ;
		
stringstream playerScore;

SDL_Window* window;
SDL_Window* startScreenWindow;
SDL_Surface* surface;
SDL_Renderer* renderer;


SDL_Texture* startScreenTex;
SDL_Texture* backgroundTex;
SDL_Texture* playerTex;
SDL_Texture* shootingTex;
SDL_Texture* hyenaTexture[20];
SDL_Texture* snakeTexture[20];
SDL_Texture* vultureTexture[20];
SDL_Texture* scorpionTexture[20];
SDL_Texture* snakeTex ;
SDL_Texture* hyenaTex ;
SDL_Texture* vultureTex ;
SDL_Texture* scorpionTex ;
SDL_Texture* bulletTex ;
SDL_Texture* gameOverTex ;
SDL_Texture* enemyTex;
SDL_Texture* gameWonTex;
SDL_Texture* scoreTex;
SDL_Texture* yourScoreTex;
SDL_Texture* highScoreTex;
SDL_Texture* newGameTex;



Mix_Music *backgroundMusic;
Mix_Chunk *bulletMusic;
Mix_Chunk *enemyMusic;
Mix_Chunk *jumpMusic;










