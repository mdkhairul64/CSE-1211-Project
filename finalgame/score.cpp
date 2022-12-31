#pragma once
#include"score.h"


bool scoreLoader(int valueX, int valueY , int score) {
	
	string pScore = "Your Score : " + to_string(score);
	TTF_Font* font = TTF_OpenFont("OpenSans-ExtraBold.ttf", 42);
	SDL_Color color = {255, 250, 250, 255};
	surface = NULL;
	surface = TTF_RenderText_Solid(font, pScore.c_str(), color);
	scoreTex = SDL_CreateTextureFromSurface(renderer, surface); 

	scorePos.x = valueX;
	scorePos.y = valueY;
	SDL_QueryTexture(scoreTex, NULL, NULL, &scorePos.w, &scorePos.h);
	SDL_RenderCopy(renderer, scoreTex, NULL, &scorePos);

	return true;
}

bool newGameLoader(int valueX, int valueY) {
	
	string pScore = "Please Press Space Key to Play Again";
	TTF_Font* font = TTF_OpenFont("OpenSans-ExtraBold.ttf", 42);
	SDL_Color color = {255, 250, 250, 255};
	surface = NULL;
	surface = TTF_RenderText_Solid(font, pScore.c_str(), color);
	newGameTex = SDL_CreateTextureFromSurface(renderer, surface); 

	newGamePos.x = valueX;
	newGamePos.y = valueY;
	SDL_QueryTexture(newGameTex, NULL, NULL, &newGamePos.w, &newGamePos.h);
	SDL_RenderCopy(renderer, scoreTex, NULL, &newGamePos);

	return true;
}


bool highScoreLoader(int valueX, int valueY , int score) {

	string pScore = "High Score : " + to_string(score) ;
	TTF_Font* font = TTF_OpenFont("OpenSans-ExtraBold.ttf", 52);
	SDL_Color color = {155, 0, 100, 255};
	surface = NULL;
	surface = TTF_RenderText_Solid(font, pScore.c_str(), color);
	highScoreTex = SDL_CreateTextureFromSurface(renderer, surface); 

	highScorePos.x = valueX;
	highScorePos.y = valueY;
	SDL_QueryTexture(highScoreTex, NULL, NULL, &highScorePos.w, &highScorePos.h);
	return true;
}
