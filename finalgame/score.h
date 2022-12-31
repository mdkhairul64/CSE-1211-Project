#pragma once
#include"variables.h"
// #include"variables.cpp"

TTF_Font* font = TTF_OpenFont("Branda-yolq.ttf", 32);
SDL_Color color = {0, 0, 0, 255};

bool scoreLoader(int valueX, int valueY, int score) ;
bool yourScoreLoader(int valueX, int valueY) ;
bool newGameLoader(int valueX, int valueY) ;
bool highScoreLoader(int valueX, int valueY, int score);