#include <iostream>
#include <string>
#include <unistd.h>
#include <ctime>
#include <cstdlib>

#include "player.h"
#include "gamemap.h"
#include "WiimoteBtns.h"
#include "obstacle.h"

void runGame(Player plyr, GameMap gm, WiimoteBtns wii, Obstacle obs1, Obstacle obs2, Obstacle obs3, Obstacle obs4,int counter);
void runMainMenu(WiimoteBtns wii, GameMap gm, Player plyr);
void runEndScreen(Player plyr, GameMap gm);

int main(){
	srand(time( NULL) );
	
	int count = 0;
	WiimoteBtns wii;
	Player player1;
	player1.setFields(9, 0, 3);
	GameMap currentgame;
	currentgame.setlength(16);
	currentgame.setbool(true);
	
	Obstacle obs1;
	obs1.setFields(((rand() % 16) + 1), 3 );
	Obstacle obs2;
	obs2.setFields(((rand() % 16) + 1), 3 );
	Obstacle obs3;
	obs3.setFields(((rand() % 16) + 1), 3 );
	Obstacle obs4;
	obs4.setFields(((rand() % 16) + 1), 3 );
	
	currentgame.clearScreen();
	
	// run in while alive? loop
	runMainMenu(wii, currentgame, player1);
	currentgame.clearScreen();
	currentgame.drawBorders();
	currentgame.setbool(true);
	currentgame.drawControls();
	WiimoteBtns wii2;
	runGame(player1, currentgame, wii2, obs1, obs2, obs3, obs4, count);
	runEndScreen(player1, currentgame);

}
void runEndScreen(Player plyr, GameMap gm){

	gm.clearScreen();
	plyr.moveCursor(0,0);
		std::cout<< "=-=-=-=-=-=-=-=-=-="<<"\n";
		std::cout<< "=                 ="<<"\n";
		std::cout<< "=   Game Over.    ="<<"\n";
		std::cout<< "=                 ="<<"\n";
		std::cout<< "=                 ="<<"\n";
		std::cout<< "=                 ="<<"\n";
		std::cout<< "=                 ="<<"\n";
		std::cout<< "=                 ="<<"\n";
		std::cout<< "=                 ="<<"\n";
		std::cout<< "=                 ="<<"\n";
		std::cout<< "=                 ="<<"\n";
		std::cout<< "=   Thanks For    ="<<"\n";
		std::cout<< "=    Playing!     ="<<"\n";
		std::cout<< "=                 ="<<"\n";
		std::cout<< "=-=-=-=-=-=-=-=-=-="<<"\n";
}

void runMainMenu(WiimoteBtns wii, GameMap gm, Player plyr){
		gm.moveCursor(0,0);
		std::cout<< "=-=-=-=-=-=-=-=-=-="<<"\n";
		std::cout<< "=  Crash Course   ="<<"\n";
		std::cout<< "=                 ="<<"\n";
		std::cout<< "=    EECE2160     ="<<"\n";
		std::cout<< "=                 ="<<"\n";
		std::cout<< "=  Press 1        ="<<"\n";
		std::cout<< "=  To Start       ="<<"\n";
		std::cout<< "=                 ="<<"\n";
		std::cout<< "=  Press 1        ="<<"\n";
		std::cout<< "=  During Game    ="<<"\n";
		std::cout<< "=  To Quit        ="<<"\n";
		std::cout<< "=                 ="<<"\n";
		std::cout<< "= Rashad & Blake  ="<<"\n";
		std::cout<< "= Khan     McHale ="<<"\n";
		std::cout<< "=-=-=-=-=-=-=-=-=-="<<"\n";
	while( gm.isrunning() == true ){
		int btn = wii.Listen();
		if(btn == 3){
			plyr.setFields(9, 0, 3);
			gm.setbool(false);
		}
	}
	}
	
void runGame(Player plyr, GameMap gm, WiimoteBtns wii, Obstacle obs1, Obstacle obs2, Obstacle obs3, Obstacle obs4, int counter){
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
		obs1.drawObstacle();
		obs2.drawObstacle();
		obs3.drawObstacle();
		obs4.drawObstacle();
		if(btn == 3 ){
			//save
			plyr.setFields(9,0,0);
		}else {	
		plyr.updatePos(btn); //get input from buttons.
		obs1.updatePos(gm.getlength());
		obs2.updatePos(gm.getlength());
		obs3.updatePos(gm.getlength());
		obs4.updatePos(gm.getlength());
		counter++;
		plyr.setScore(counter);
		}
		
	}

}
