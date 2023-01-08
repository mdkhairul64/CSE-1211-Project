#include"Load.h"
#include"Load.cpp"
#include"initialization.h"
#include"initialization.cpp"
#include"score.h"
#include"score.cpp"
#include"playerMove.h"
#include"playerMove.cpp"



int main(int agr, char* args[]) {
	initializer();
	frameTime++;

	
	int stepX = 0, stepY = 0, CURRENT_FRAME = 0;
	

	SDL_Event event;

	if(init()) {
		if(screenLoader()) {
			
								
			while(running) {
				
				frameTime++, backgroundFrameRate++;
				frameTime %= FPS;
				while(SDL_PollEvent( &event ) != 0) {
					if(event.type == SDL_QUIT) {
						running = false;
						break;
					}
					else if(event.type == SDL_KEYDOWN) {
						if(game_start) {
							

							if(event.key.keysym.sym == SDLK_RIGHT || event.key.keysym.sym == SDLK_d) {
								playerDirection = 'r';
								playerMovementHandler(playerDirection, jump, playerMoveX, playerMoveY);
							}
					
				

							if(event.key.keysym.sym == SDLK_LEFT || event.key.keysym.sym == SDLK_a) {
								playerDirection = 'l';
								playerMovementHandler(playerDirection, jump, playerMoveX, playerMoveY);
							}	

							if(event.key.keysym.sym == SDLK_UP || event.key.keysym.sym == SDLK_w) {
								playerDirection = 'u';
								playerMovementHandler(playerDirection, jump, playerMoveX, playerMoveY);
							}	

							if(event.key.keysym.sym == SDLK_DOWN || event.key.keysym.sym == SDLK_s) {
								playerDirection = 'd';
								playerMovementHandler(playerDirection, jump, playerMoveX, playerMoveY);
							}		




						}

						
					}
				} 

				int mouseX, mouseY;
				int mouseButtons = SDL_GetMouseState(&mouseX, &mouseY);

				if(!game_start) {

					if(mouseX >= 500 && mouseX <= 780 && mouseY >= 425 && mouseY <= 470 && (mouseButtons & SDL_BUTTON(SDL_BUTTON_LEFT))) {
					game_start = true ;
					Mix_PlayMusic(backgroundMusic, -1) ;
					}

					else if(mouseX >= 600 && mouseX <= 720 && mouseY >= 503 && mouseY <= 718 && (mouseButtons & SDL_BUTTON(SDL_BUTTON_LEFT))) {
						running = false;
						SDL_Quit();
					}

				}
				else if(game_start == true && frameTime % 6 == 0 &&  mouseButtons && SDL_MOUSEBUTTONUP) {
					
						Mix_PlayChannel(-1, bulletMusic, 0);
						
						bullet[bulletFired].direction = 'r';

						bullet[bulletFired].bulletPosition.x = playerPos.x + playerPos.w;
						bullet[bulletFired].bulletPosition.y = playerPos.y + 80;
						bullet[bulletFired].bulletPosition.w = BULLET_WIDTH;
						bullet[bulletFired].bulletPosition.h = BULLET_HEIGHT;
						bullet[bulletFired].active = true;
						bulletFired++;
					
					
 				}	



				for(int bullIndex = 0; bullIndex < bulletFired; bullIndex++) {
					
					if(bullet[bullIndex].bulletPosition.x < SCREEN_WIDTH && bullet[bullIndex].bulletPosition.x > 0 && bullet[bullIndex].active) {
						if(bullet[bullIndex].direction == 'r') {
							bullet[bullIndex].bulletPosition.x += 20;
							// bullet[bullIndex].active = true;
							if(bullet[bullIndex].bulletPosition.x>SCREEN_WIDTH)
							{
								bullet[bullIndex].active = false ;

							}
						}
					}
				}
				// enemy movement on screen right to left
				if(game_start) {
					for(int i = 0; i < 20; i++) {
						if(i >= 0 && i < 5) {
							snakeRect[i].x -= 2.5;
							scorpionRect[i].x -= 2.9;
							hyenaRect[i].x -= 2.4;
							vultureRect[i].x -= 2.7;
						}
						else if(i >= 5 && i < 10) {
							snakeRect[i].x -= 2.9;
							scorpionRect[i].x -= 2.7;
							hyenaRect[i].x -= 3.6;
							vultureRect[i].x -= 2.9;
						}
						else if(i >= 10 && i < 15) {
							snakeRect[i].x -= 3.9;
							scorpionRect[i].x -= 4.9;
							hyenaRect[i].x -= 3.18;
							vultureRect[i].x -= 3.8;
						}
						else {
							snakeRect[i].x -= 4.8;
							scorpionRect[i].x -= 5.5;
							hyenaRect[i].x -= 3.9;
							vultureRect[i].x -= 3.8;
						}

				        
						
					}
				}
				

				
					if(FPS / frameTime == 4) {
						playerRect.x += frameWidth1;
						if(playerRect.x >= textureWidth1) playerRect.x = 0;
						
						for(int i = 0; i < 20; i++) {
							hyenaPos[i].x += 48;
							snakePos[i].x += 48;
							scorpionPos[i].x += 48;
							vulturePos[i].x += 48;
							
							if(snakePos[i].x >= 192) snakePos[i].x = 0;
							if(hyenaPos[i].x >= 192) hyenaPos[i].x = 0;
							if(scorpionPos[i].x >= 192) scorpionPos[i].x = 0;
							if(vulturePos[i].x >= 192) vulturePos[i].x = 0;
						}
						frameTime = 0;
					}
                //here we check collision for each bullet that we had already fired  
				for(int bulletIndex = 0; bulletIndex < bulletFired; bulletIndex++) {
						
						for(int i = 0; i < 20; i++) {
							if((bullet[bulletIndex].bulletPosition.x >= vultureRect[i].x)&& ((bullet[bulletIndex].bulletPosition.y >= vultureRect[i].y) && (bullet[bulletIndex].bulletPosition.y <= vultureRect[i].y+vultureRect[i].w)) && bullet[bulletIndex].active && enemyAlive.vultureAlive[i] == true){
								enemyAlive.vultureAlive[i] = false;
								bullet[bulletIndex].bulletPosition.w = 0;
								bullet[bulletIndex].bulletPosition.h = 0;
								bullet[bulletIndex].active = false;
								SDL_RenderClear(renderer);
								score++;
								
								
							}
						}
						for(int i = 0; i < 20; i++) {
							if((bullet[bulletIndex].bulletPosition.x - 50 >= snakeRect[i].x)&& enemyAlive.snakeAlive[i] == true && ((bullet[bulletIndex].bulletPosition.y >=snakeRect[i].y)&&(bullet[bulletIndex].bulletPosition.y <= snakeRect[i].y + snakeRect[i].w)) && bullet[bulletIndex].active){
								enemyAlive.snakeAlive[i] = false;
								bullet[bulletIndex].bulletPosition.w = 0;
								bullet[bulletIndex].bulletPosition.h = 0;
								bullet[bulletIndex].active = false;

								
								score++;
								SDL_RenderClear(renderer);
							}
						}
						for(int i = 0; i < 20; i++) {
							if((bullet[bulletIndex].bulletPosition.x - 50 >= scorpionRect[i].x)&& enemyAlive.scorpionAlive[i] == true && ((bullet[bulletIndex].bulletPosition.y>=scorpionRect[i].y)&&(bullet[bulletIndex].bulletPosition.y<=scorpionRect[i].y+scorpionRect[i].w))&& bullet[bulletIndex].active){
								enemyAlive.scorpionAlive[i] = false;	
								bullet[bulletIndex].bulletPosition.w = 0;
								bullet[bulletIndex].bulletPosition.h = 0;
								bullet[bulletIndex].active = false;

								
								score++;
								SDL_RenderClear(renderer);
								
							}
						}
						for(int i = 0; i < 20; i++) {
							if((bullet[bulletIndex].bulletPosition.x -50 >= hyenaRect[i].x)&& enemyAlive.hyenaAlive[i] == true && ((bullet[bulletIndex].bulletPosition.y>=hyenaRect[i].y)&&(bullet[bulletIndex].bulletPosition.y<=(hyenaRect[i].y+hyenaRect[i].w)))&& bullet[bulletIndex].active){
							// if(bullet[bulletIndex].bulletPosition.x + bullet[bulletIndex].bulletPosition.w >= hyenaRect[i].x && bullet[bulletIndex].bulletPosition.y > hyenaRect[i].y && bullet[bulletIndex].bulletPosition.y < hyenaRect[i].y + hyenaRect[i].h && playerPos.x < hyenaPos[i].x && bullet[bulletIndex].active) {
								enemyAlive.hyenaAlive[i] = false;
								bullet[bulletIndex].bulletPosition.w = 0;
								bullet[bulletIndex].bulletPosition.h = 0;
								bullet[bulletIndex].active = false;
							
								score++;
								SDL_RenderClear(renderer);
							}
						}	
						for(int i = 0; i < 20; i++) {
							//********** we need to check	game over condition ********
							if((vultureRect[i].x < -2 && enemyAlive.vultureAlive[i] == true) || (scorpionRect[i].x < -2 && enemyAlive.scorpionAlive[i] == true) || (snakeRect[i].x < -2 && enemyAlive.snakeAlive[i] == true) || (hyenaRect[i].x < -2 && enemyAlive.hyenaAlive[i] == true)) {
								game_over = true ;
								
								break ;
								cout << i << " ";
							}
						}
						
				}// collision detector end ;

                SDL_RenderClear(renderer);
                // for each loop we check our game is in  whcih situation and take necesaary steps(score loading, rendering )
				if(game_won) {
					SDL_RenderCopy(renderer, gameWonTex, NULL, &gameOverPos);
				}
				else if(game_over)
				{	
					game_start = false;
				
						scoreLoader(525, 550, score);
						// here we have to save score in file if current score is gather than the previous(stored score in the file)score 
						newGameLoader(300, 600);
						int x = 0;
						int hScore = 0 ;
						FILE* highScore;
						
						highScore = fopen("highScore.txt", "r") ;
						fscanf(highScore,"%d", &hScore);
						fclose(highScore);
						highScore = fopen("highScore.txt", "w") ;
						hScore = max(hScore,score) ;
						fprintf(highScore, "%d", hScore);
						fclose(highScore);
					
						highScoreLoader(500, 450 , hScore);
						

					SDL_RenderCopy(renderer,gameOverTex,NULL, &gameOverPos);
					SDL_RenderCopy(renderer, scoreTex, NULL, &scorePos);
					// SDL_RenderCopy(renderer, yourScoreTex, NULL, &yourScorePos);
					SDL_RenderCopy(renderer, highScoreTex, NULL, &highScorePos);
					SDL_RenderCopy(renderer, newGameTex, NULL, &newGamePos);

					if(event.key.keysym.sym == SDLK_SPACE && game_over) {
								game_start = true;
								game_over = false;
								init();
								screenLoader();

								running = true;
								
					}

				}
				else if(!game_start)
				{
					SDL_RenderCopy(renderer,startScreenTex,NULL,&startScreenPos);
				}
				else{
					SDL_RenderCopy(renderer,backgroundTex ,&backgroundPos, &backgroundRect);
					
					SDL_RenderCopy(renderer, playerTex, &playerRect ,&playerPos);
					//We have rendered all the enemies here
					for(int i = 0; i < 20; i++){
                        if(enemyAlive.vultureAlive[i]) SDL_RenderCopy(renderer, vultureTex, &vulturePos[i], &vultureRect[i] );
                    }
                    for(int i = 0;i < 20; i++){
                        if(enemyAlive.snakeAlive[i]) SDL_RenderCopy(renderer, snakeTex,  &snakePos[i], &snakeRect[i]);
                    }
                    for(int i = 0; i < 20; i++){
                        if(enemyAlive.scorpionAlive[i]) SDL_RenderCopy(renderer, scorpionTex, &scorpionPos[i], &scorpionRect[i] );
                    }
					for(int i = 0; i < 20; i++){
                        if(enemyAlive.hyenaAlive[i]) SDL_RenderCopy(renderer, hyenaTex, &hyenaPos[i], &hyenaRect[i] );
                    }
					// SDL_RenderCopy(renderer, yourScoreTex, NULL, &yourScorePos);

					//We have rendered all the bullets here
					scoreLoader(20,20,score);
					for(int bullIndex = 0; bullIndex < bulletFired; bullIndex++) {
						if(bullet[bullIndex].bulletPosition.x < SCREEN_WIDTH && (bullet[bullIndex].bulletPosition.x > 0 )&& bullet[bullIndex].active == true) {
							SDL_RenderCopy(renderer, bulletTex, NULL, &bullet[bullIndex].bulletPosition);
						}
					}


				}
				SDL_RenderPresent(renderer);
				SDL_Delay(1000 / FPS);
			}
		}
	

	clean();

}
	return 0;
	
}
