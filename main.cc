#include <iostream>
#include <string>
#include <unistd.h>
#include <ctime>
#include <cstdlib>

#include "player.h"
#include "gamemap.h"
#include "WiimoteBtns.h"

void runGame(Player plyr, GameMap gm, WiimoteBtns wii, Obstacle obs1, Obstacle obs2, Obstacle obs3, Obstacle obs4);
void runMainMenu(WiimoteBtns wii, GameMap gm, Player plyr);
void runEndScreen();

int main(){
	srand(time( NULL) );
	
	int count = 0;
	WiimoteBtns wii;
	Player player1;
	player1.setFields(9, 0, 7);
	GameMap currentgame;
	currentgame.setlength(16);
	currentgame.setbool(true);
	
	Obstacle obs1;
	obs1.setFields(((rand() % 16) + 1), 3 );
	Obstacle obs2;
	obs1.setFields(((rand() % 16) + 1), 3 );
	Obstacle obs2;
	obs1.setFields(((rand() % 16) + 1), 3 );
	Obstacle obs3;
	obs3.setFields(((rand() % 16) + 1), 3 );
	
	currentgame.clearScreen();
	
	
	
	currentgame.clearScreen();
	currentgame.drawBorders();

	// run in while alive? loop

	runGame(player1, currentgame, wii, obs1, obs2, obs3, obs4);
	
	endScreen(player1);

}

void runMainMenu(WiimoteBtns wii GameMap gm, Player plyr){
	(while gm.isrunning()){
		
		gm.moveCursor(0,0);
		std::cout<< "=-=-=-=-=-=-=-=-=-="<<endl;
		std::cout<< "=    EECE 2160    ="<<endl;
		std::cout<< "=  Final Project  ="<<endl;
		std::cout<< "=                 ="<<endl;
		std::cout<< "=  Press 1        ="<<endl;
		std::cout<< "=  To Load Save   ="<<endl;
		std::cout<< "=                 ="<<endl;
		std::cout<< "=  Press 2        ="<<endl;
		std::cout<< "=  To Start New   ="<<endl;
		std::cout<< "=                 ="<<endl;
		std::cout<< "=  Press 1 In Game="<<endl;
		std::cout<< "=  To Save & Quit ="<<endl;
		std::cout<< "=                 ="<<endl;
		std::cout<< "= Rashad & Blake  ="<<endl;
		std::cout<< "= Khan     McHale ="<<endl;
		std::cout<< "=-=-=-=-=-=-=-=-=-="<<endl;
		int btn = wii.Listen();
		if(btn == 2){
			plyr.setFields(9, 0, 3);
			gm.setbool(false);
		}
		if(btn == 3){
			//setfieldsfromload
			
			gm.setbool(false);
		}
	}
	}
	
void runGame(Player plyr, GameMap gm, WiimoteBtns wii, Obstacle obs1, Obstacle obs2, Obstacle obs3, Obstacle obs4){
	while(plyr.isAlive()){
		usleep(100000);
		int btn = wii.Listen();
		//Generate initial map.
		gm.drawMap();
		//Generate player
		bool oneCollides;
		int xpos = plyr.getx();
		oneCollides = (obs1.isColliding(xpos) || obs2.isColliding(xpos)
		 || obs3.isColliding(xpos) || obs4.isColliding(xpos) );
		 
		plyr.removeLife(oneCollides); 
		plyr.drawPlayer(15);
		if(btn == 3 ){
			//save
			plyr.setFields(9,0,0);
		}else {
			
		plyr.updatePos(btn); //get input from buttons.
		obs1.updatePos(gm.getlength());
		obs2.updatePos(gm.getlength());
		obs3.updatePos(gm.getlength());
		obs4.updatePos(gm.getlength());
		
		}
	}
}
