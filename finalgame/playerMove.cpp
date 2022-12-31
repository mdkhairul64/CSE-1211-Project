#pragma once
#include"playerMove.h"

//We have handled the player movement here

bool playerMovementHandler(char direction, bool jump, int stepY, int stepX) {
	if(!jump) {
		switch(direction) {
			case 'r' :
				if(playerPos.x < SCREEN_WIDTH - playerPos.w) {
					playerPos.x += PIXELS_PER_FRAME * 2;
				}
				break;
			case 'l' : 
				if(playerPos.x > playerPos.w) {
					playerPos.x -= PIXELS_PER_FRAME;
				}
				break;

			case 'u' :
				if(playerPos.y > 0) {
					playerPos.y -= PIXELS_PER_FRAME * 2.5;
				}
				break;

			case 'd' :
				if(playerPos.y < SCREEN_HEIGHT - playerPos.h) {
					playerPos.y += PIXELS_PER_FRAME * 2.5;
				}
				break;
		}
	}
	return true;
}