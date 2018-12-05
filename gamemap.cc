#include <iostream>
#include <string>

#include "gamemap.h"

	void GameMap::setlength(int number){
		length = number;
	}
	void GameMap::clearScreen(){
		std::cout << "\033[2J";
	}
	
	void GameMap::moveCursor(int col, int row){
	 std::cout<< "\033[" << row << ";" << col << "H";
	}
	int GameMap::getlength(){
		return length;
	}
	bool GameMap::isrunning(){
		return running;
	}
	
	void GameMap::setbool(bool input){
		running = input;
	}
	
	void GameMap::drawBorders(){
		moveCursor( 0, 2);
		std::cout<<"=-=-=-=-=-=-=-=-=-=";	
		moveCursor( 0, length);
		std::cout<<"=-=-=-=-=-=-=-=-=-=";
	}
	
	void GameMap::drawMap(){
		for(int i = 3; i < length; i++){
			moveCursor( 0, (i % length));
			if( (i%2 ) == 0 ){
				std::cout<<"|        |        |";
			}else
				std::cout<<"|                 |";
		}
	}
