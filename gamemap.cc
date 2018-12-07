#include <iostream>
#include <string>

#include "gamemap.h"
	// takes an int and sets the GameMap's pvt int length to the input int.
	void GameMap::setlength(int number){
		length = number;
	}
	
	//runs ANSI clear screen code. 
	void GameMap::clearScreen(){
		std::cout << "\033[2J";
	}
	//ANSI code to move cursor to current position. 
	void GameMap::moveCursor(int col, int row){
	 std::cout<< "\033[" << row << ";" << col << "H";
	}
	
	//return the pvt int length of the GameMap
	int GameMap::getlength(){
		return length;
	}
	
	//return the pvt boolean running of the GameMap
	bool GameMap::isrunning(){
		return running;
	}
	
	//set the pvt boolean running to the boolean input of the function.
	void GameMap::setbool(bool input){
		running = input;
	}
	
	//Draw the borders of the map.
	void GameMap::drawBorders(){
		moveCursor( 0, 2);
		std::cout<<"=-=-=-=-=-=-=-=-=-=";	
		moveCursor( 0, length);
		std::cout<<"=-=-=-=-=-=-=-=-=-=";
	}
	
	//Draw the map/background of the game. 
	void GameMap::drawMap(){
		for(int i = 3; i < length; i++){
			moveCursor( 0, (i % length));
			if( (i%2 ) == 0 ){
				std::cout<<"|        |        |";
			}else
				std::cout<<"|                 |";
		}
	}
	
	//Print the instructions below the gamemap.
	void GameMap::drawControls(){
	moveCursor(0, 20);
	std::cout<< "Press D Pad Arrow closest to the top to"<<"\n";
	std::cout<< "Move Left, Press 2 to Move Right. Press 1 To Quit" <<"\n";
	}
