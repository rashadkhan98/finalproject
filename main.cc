#include <iostream>
#include <string>
#include <unistd.h>

#include "player.h"
#include "gamemap.h"
#include "WiimoteBtns.h"

void runGame(Player a, GameMap b);

int main(){

	int count = 0;
	WiimoteBtns wii;
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

void runGame(Player plyr, GameMap gm){
	while(a.isAlive()){
		usleep(100000);
		int btn = wii.Listen();
		//Generate initial map.
		gm.drawMap();
		//Generate player

		plyr.removeLife(true); //replace with check if obstacles values are the same.
		plyr.drawPlayer(15);

		plyr.updatePos(btn); //get input from buttons.

	}
}
