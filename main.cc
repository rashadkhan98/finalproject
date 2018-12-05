#include <iostream>
#include <string>

//#include <player.h>
#include "gamemap.h"

int main(){
	int count = 0;
	//Player player1;
	//player1.x  = 15;
	//player.lives = 5;
	//player.score = 0; 
	GameMap currentgame;
	currentgame.setlength(16);
	currentgame.setbool(true);
	
	currentgame.clearScreen();
	currentgame.drawBorders();
	
	//Generate initial map.
	for(int i = 3; i < currentgame.getlength() ; i++){
		currentgame.drawMap(i);
	}
	
	while(currentgame.isrunning()){
		currentgame.drawMap(count);
		
		
		count++;
	  
	}
} 
