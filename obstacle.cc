#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

#include "obstacle.h"


	
		// moveCursor: output int int -> text @ cursor posn. 
		// prints outpus at posn col, row of the terminal. 
		void Obstacle::moveCursor(int col, int row){
		std::cout << "\033[" << row << ";" << col << "H";
		}
		
		// drawScore: int -> cout
		// Print the score,live count, and current posn of the player. 
		void Obstacle::drawObstacle(){
			moveCursor( x, y);
			std::cout<<"O";
		}
		
		void Obstacle::setFields(int a, int b){
			x = a;
			y = b;
		}
		// updatePos: Int -> Int 
		// Update x value based on switch input.  
		void Obstacle::updatePos(int max){
	
			if(y < max){
				y = y++;
			}else{
				y = 2;
				x = (rand() % 16) + 1;	
			} 	
		}
		
		bool Obstacle::isColliding(int a, int b){
			if( x == a && y == b){
				return true;
			}else
				return false;
		}
	

