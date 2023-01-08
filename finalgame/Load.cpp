#pragma once
#include"Load.h"


bool screenLoader() {
    surface = NULL;
    surface = IMG_Load("./asset/startScreen.jpg");
	startScreenTex = NULL;
    startScreenTex = SDL_CreateTextureFromSurface(renderer, surface);
    return true;
}
//Loaded the Background Here
bool backgroundLoader() {
	surface = NULL;
	surface = IMG_Load("./asset/Background/game_background_1.png");
	backgroundTex = NULL;
	backgroundTex = SDL_CreateTextureFromSurface(renderer, surface);
	SDL_QueryTexture(backgroundTex, NULL, NULL, &backgroundTextureWidth, &backgroundTextureHeight);

	backgroundPos.x = 0;
	backgroundPos.y = 0;
	backgroundPos.w = backgroundTextureWidth;
	backgroundPos.h = backgroundTextureHeight;

	backgroundRect.x = 0;
	backgroundRect.y = 0;
	backgroundRect.w = SCREEN_WIDTH;
	backgroundRect.h = SCREEN_HEIGHT;


	return true;
}

bool characterLoader() {
	//Millitary Player Character
	surface = NULL;
	surface = IMG_Load("./asset/character/Gunner_Red_Run.png"); 
	playerTex = SDL_CreateTextureFromSurface(renderer, surface);
	SDL_QueryTexture(playerTex, NULL, NULL, &textureWidth1, &textureHeight1);

	frameWidth1 = textureWidth1 / 6;
	frameHeight1 = textureHeight1;

	playerPos.x = 20;
	playerPos.y = 350;
	playerPos.w = 400;
	playerPos.h = 100 * 2;

	playerRect.x = 0;
	playerRect.y = 0;
	playerRect.w = frameWidth1;
	playerRect.h = frameHeight1;

	return true;
}

bool enemyLoader() {
	long long int randomSnakeStart, randomSnakeGap, randomHyenaStart, randomHyenaGap, randomScorpionStart, randomScorpionGap, randomVultureStart, randomVultureGap;
	for(int i = 0; i < 20 ;){
        //snake
		randomSnakeStart = max((rand() % 300) * 30, 350);
		randomSnakeGap = rand() % 500;
        surface = NULL;
		surface = IMG_Load("./asset/1 Snake/Snake_walk.png");
        
        snakeTexture[i] = NULL;
        snakeTexture[i] = SDL_CreateTextureFromSurface(renderer, surface);

		snakePos[i].x = 0;
		snakePos[i].y = 0;
		snakePos[i].w = 48;
		snakePos[i].h = 48;

		snakeRect[i].y = 500 ;
		snakeRect[i].w = 32 * 6;
		snakeRect[i].h = 32 * 6;
		i++;


	}
    snakeTex = snakeTexture[0];
    for(int i = 0; i < 20 ;){
		//Hyena
    	randomHyenaStart = max((rand() % 300) * 30, 400);
		randomHyenaGap = rand() % 600;
		surface = NULL;
		surface = IMG_Load("./asset/2 Hyena/Hyena_idle.png");
			
		hyenaTexture[i] = NULL;
		hyenaTexture[i] = SDL_CreateTextureFromSurface(renderer, surface);

		hyenaPos[i].x = 0;
		hyenaPos[i].y = 0;
		hyenaPos[i].w = 48;
		hyenaPos[i].h = 48;

		
		hyenaRect[i].y = 200;
		hyenaRect[i].w = 32 * 6;
		hyenaRect[i].h = 32 * 6;
		for(int j = 0; j < 1000007; j++) {
			
		}
		i++;

	}
    hyenaTex = hyenaTexture[0];
    for(int i = 0; i < 20 ; i++){
    	//vulture
		randomVultureStart = max((rand() % 300) * 40, 350);
		randomVultureGap = rand() % 800;
		surface = NULL;
		surface = IMG_Load("./asset/4 Vulture/Vulture_walk.png");
			
		vultureTexture[i] = NULL;
		vultureTexture[i] = SDL_CreateTextureFromSurface(renderer, surface);

		 vulturePos[i].x = 0;
		vulturePos[i].y = 0;
		vulturePos[i].w = 48;
		vulturePos[i].h = 48;

		vultureRect[i].y = 0;
		vultureRect[i].w = 32 * 6;
		vultureRect[i].h = 32 * 6;

	}
    vultureTex = vultureTexture[0];
    for(int i = 0; i < 20 ; i++){
    	randomScorpionStart = max(500, (rand() % 300) * 30);
		
		randomScorpionGap = rand() % 600 ;
		surface = NULL;
		surface = IMG_Load("./asset/3 Scorpio/Scorpio_walk.png");
			
		scorpionTexture[i] = NULL;
		scorpionTexture[i] = SDL_CreateTextureFromSurface(renderer, surface);

		scorpionPos[i].x = 0;
		scorpionPos[i].y = 0;
		scorpionPos[i].w = 48;
		scorpionPos[i].h = 48;

		scorpionRect[i].y = 370;
		scorpionRect[i].w = 32 * 6;
		scorpionRect[i].h = 32 * 6;

	}
    scorpionTex = scorpionTexture[0];

//   initialize the enemy position of x axis on the game screen manually

	scorpionRect[0].x = SCREEN_WIDTH + 300;
	hyenaRect[0].x = SCREEN_WIDTH + 100;
	vultureRect[0].x = SCREEN_WIDTH + 200;
	snakeRect[0].x = SCREEN_WIDTH;

	scorpionRect[1].x = SCREEN_WIDTH + 1376;
	hyenaRect[1].x = SCREEN_WIDTH + 2123;
	vultureRect[1].x = SCREEN_WIDTH + 1344;
	snakeRect[1].x = SCREEN_WIDTH + 675;

	scorpionRect[2].x = SCREEN_WIDTH + 1000;
	hyenaRect[2].x = SCREEN_WIDTH + 1200;
	vultureRect[2].x = SCREEN_WIDTH + 1300;
	snakeRect[2].x = SCREEN_WIDTH + 1100;

	scorpionRect[3].x = SCREEN_WIDTH + 2000;
	hyenaRect[3].x = SCREEN_WIDTH + 1000;
	vultureRect[3].x = SCREEN_WIDTH + 900;
	snakeRect[3].x = SCREEN_WIDTH + 1200;

	scorpionRect[4].x = SCREEN_WIDTH + 2800;
	hyenaRect[4].x = SCREEN_WIDTH + 1300;
	vultureRect[4].x = SCREEN_WIDTH + 1400;
	snakeRect[4].x = SCREEN_WIDTH + 1600;

	scorpionRect[5].x = SCREEN_WIDTH + 3800;
	hyenaRect[5].x = SCREEN_WIDTH + 1800;
	vultureRect[5].x = SCREEN_WIDTH + 2200;
	snakeRect[5].x = SCREEN_WIDTH + 2100;

	scorpionRect[6].x = SCREEN_WIDTH + 2550;
	hyenaRect[6].x = SCREEN_WIDTH + 2500;
	vultureRect[6].x = SCREEN_WIDTH + 2700;
	snakeRect[6].x = SCREEN_WIDTH + 2700;

	scorpionRect[7].x = SCREEN_WIDTH + 3150;
	hyenaRect[7].x = SCREEN_WIDTH + 3600;
	vultureRect[7].x = SCREEN_WIDTH + 3900;
	snakeRect[7].x = SCREEN_WIDTH + 3100;

	scorpionRect[8].x = SCREEN_WIDTH + 4550;
	hyenaRect[8].x = SCREEN_WIDTH + 4500;
	vultureRect[8].x = SCREEN_WIDTH + 5000;
	snakeRect[8].x = SCREEN_WIDTH + 4800;

	scorpionRect[9].x = SCREEN_WIDTH + 6050;
	hyenaRect[9].x = SCREEN_WIDTH + 5900;
	vultureRect[9].x = SCREEN_WIDTH + 6500;
	snakeRect[9].x = SCREEN_WIDTH + 6900;

	scorpionRect[10].x = SCREEN_WIDTH + 7550;
	hyenaRect[10].x = SCREEN_WIDTH + 7900;
	vultureRect[10].x = SCREEN_WIDTH + 8300;
	snakeRect[10].x = SCREEN_WIDTH + 8100;

	scorpionRect[11].x = SCREEN_WIDTH + 9000;
	hyenaRect[11].x = SCREEN_WIDTH + 8900;
	vultureRect[11].x = SCREEN_WIDTH + 9500;
	snakeRect[11].x = SCREEN_WIDTH + 9300;

	scorpionRect[12].x = SCREEN_WIDTH + 10050;
	hyenaRect[12].x = SCREEN_WIDTH + 10200;
	vultureRect[12].x = SCREEN_WIDTH + 10300;
	snakeRect[12].x = SCREEN_WIDTH + 10500;

	scorpionRect[13].x = SCREEN_WIDTH + 11250;
	hyenaRect[13].x = SCREEN_WIDTH + 11300;
	vultureRect[13].x = SCREEN_WIDTH + 11200;
	snakeRect[13].x = SCREEN_WIDTH + 11400;

	scorpionRect[14].x = SCREEN_WIDTH + 12450;
	hyenaRect[14].x = SCREEN_WIDTH + 12000;
	vultureRect[14].x = SCREEN_WIDTH + 12300;
	snakeRect[14].x = SCREEN_WIDTH + 13000;

	scorpionRect[15].x = SCREEN_WIDTH + 13950;
	hyenaRect[15].x = SCREEN_WIDTH + 13000;
	vultureRect[15].x = SCREEN_WIDTH + 12650;
	snakeRect[15].x = SCREEN_WIDTH + 14900;

	scorpionRect[16].x = SCREEN_WIDTH + 15000;
	hyenaRect[16].x = SCREEN_WIDTH + 14100;
	vultureRect[16].x = SCREEN_WIDTH + 13700;
	snakeRect[16].x = SCREEN_WIDTH + 15000;

	scorpionRect[17].x = SCREEN_WIDTH + 16050;
	hyenaRect[17].x = SCREEN_WIDTH + 15000;
	vultureRect[17].x = SCREEN_WIDTH + 14500;
	snakeRect[17].x = SCREEN_WIDTH + 15900;

	scorpionRect[18].x = SCREEN_WIDTH + 16200;
	hyenaRect[18].x = SCREEN_WIDTH +16020;
	vultureRect[18].x = SCREEN_WIDTH + 15400;
	snakeRect[18].x = SCREEN_WIDTH + 17300;

	scorpionRect[19].x = SCREEN_WIDTH + 17550;
	hyenaRect[19].x = SCREEN_WIDTH + 17100;
	vultureRect[19].x = SCREEN_WIDTH + 16200;
	snakeRect[19].x = SCREEN_WIDTH + 18500;

	scorpionRect[20].x = SCREEN_WIDTH + 19000;
	hyenaRect[20].x = SCREEN_WIDTH + 18100;
	vultureRect[20].x = SCREEN_WIDTH + 17500;
	snakeRect[20].x = SCREEN_WIDTH + 19700;

    
    return true;
}

bool bulletLoader() {
	surface = NULL;
	surface = IMG_Load("./asset/bullet.png");
	bulletTex = SDL_CreateTextureFromSurface(renderer, surface);
	return true;
}
//we have loaded the sounds here
bool soundLoader() {
	backgroundMusic = Mix_LoadMUS("asset/audio/Tension Nonstop - Myuu.wav");
	bulletMusic = Mix_LoadWAV("asset/audio/explosion.ogg");
	// enemyMusic = Mix_LoadWAV("asset/audio/Character Died.mp3");
	return true;
}
//Screen to load when game is over
bool gameOverLoader() {
    surface = NULL;
    surface = IMG_Load("./asset/GameOver.jpg");
	gameOverTex = NULL;
    gameOverTex = SDL_CreateTextureFromSurface(renderer, surface);
	// SDL_QueryTexture(gameOverTex, NULL, NULL, &gameOverTextureWidth, &gameOverTextureHeight)


    return true;
}
