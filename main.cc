#include <iostream>
#include <string>
#include <unistd.h>

#include "player.h"
#include "gamemap.h"

void runGame(Player a, GameMap b);

int main(){
	
	int count = 0;
	Player player1;
	player1.setFields(9, 0, 7);
	GameMap currentgame;
	currentgame.setlength(16);
	currentgame.setbool(true);
	
	currentgame.clearScreen();
	currentgame.drawBorders();
	
	// run in while alive? loop
	
	runGame(player1, currentgame);
	
} 

void runGame(Player a, GameMap b){
	while(a.isAlive()){
	usleep(100000);
	//Generate initial map.
	b.drawMap();
	//Generate player
	
	a.removeLife(true); //replace with check if obstacles values are the same. 
	a.drawPlayer(15);
	
	a.updatePos(1); //get input from buttons.
	
	}
}
