#include <iostream>
#include <chrono>
#include <thread>
#include <string>

#include <player.h>

		
		// moveCursor: output int int -> text @ cursor posn. 
		// prints outpus at posn col, row of the terminal. 
		void player::void moveCursor(int col, int row){
		std::cout << "\033[" << row << ";" << col << "H";
		}
		
		// drawScore: int -> cout
		// Print the score,live count, and current posn of the player. 
		void player::drawPlayer(int length){
		moveCursor( 0, 0){
		std::cout<<"Score: " score;
		}
		
		moveCursor( 10, 0){
		std::cout<<"Lives: " lives;
		}
		
		moveCursor(x, --length){
		std::cout<<"^";
		}
		}
		
		// updatePos: Int -> Int 
		// Update x value based on switch input.  
		void player::updatePos(int sw){
			switch(sw){
				case 1: //1 = Left, update posn x - 1
				 x = x - 1;
				break;
				
				case 2: //2 = Right, update posn x + 1
				x = x + 1; 
				break;
			}
		}
		
		// removeLife: Boolean -> int (update player) 
		// remove a life if it is passed true. 
		removeLife(bool contact){
			if(contact == true ){
				lives = lives - 1
			}
		}		
		
		// isAlive?: none -> Boolean
		// if lives > 0, returns true. else false. 
		bool isAlive?(){
			if (lives > 0){
				return true;
			}else 
				false;
		}

};
