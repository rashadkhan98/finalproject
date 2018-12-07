#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

#include "obstacle.h"


	
	
		// moves cursor to posn col, row of the terminal. 
		void Obstacle::moveCursor(int col, int row){
		std::cout << "\033[" << row << ";" << col << "H";
		}
		
	
		// draw the obstacle at its current position
		void Obstacle::drawObstacle(){
			moveCursor( x, y);
			std::cout<<"O";
		}
		// set x and y positions of the obstacle object.
		void Obstacle::setFields(int a, int b){
			x = a;
			y = b;
		}
		// Update x and y value based on previous value.  
		void Obstacle::updatePos(int max){
	
			if(y < --max){
				y = y++;
			}else{
				y = 3;
				x = (rand() % 16) + 2;	
			} 	
		}
		
		// return true if x value is same as the player when their y values are the same
		bool Obstacle::isColliding(int a){
			if( x == a && y == 15 ){
				return true;
			}else
				return false;
		}
	

