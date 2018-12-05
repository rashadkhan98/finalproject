#include <iostream>
#include <string>

#include "player.h"
#include "gamemap.h"

int main(){
	int count = 0;
	Player player1;
	player1.setFields(9, 0, 3);
	GameMap currentgame;
	currentgame.setlength(16);
	currentgame.setbool(true);
	
	currentgame.clearScreen();
	currentgame.drawBorders();
	
	//Generate initial map.
	currentgame.drawMap();
	//Generate player
	player1.drawPlayer(15);
	
	
} 
