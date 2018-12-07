#include <iostream>
#include <string>
#include <unistd.h>
#include "player.h"

//returns the player's pvt lives count.
int Player::getLives(){
	return lives;
}

//return the player's pvt score count.
int Player::getScore(){
	return score;
}

//sets the player's pvt score count to the input int.
void Player::setScore(int s){
	score= s;
}

//set all pvt fields of the player object.
void Player::setFields(int a, int b, int c) {
    x = a;
    score = b;
    lives = c;
}

// prints output at posn col, row of the terminal.
void Player::moveCursor(int col, int row) {
    std::cout << "\033[" << row << ";" << col << "H";
}

// Print the score, live count, and current posn of the player.
void Player::drawPlayer(int y) {
    moveCursor(10, 0);
    std::cout << "Score: " << score;

    moveCursor(0, 0);
    std::cout << "Lives: " << lives;

    usleep(100);
    moveCursor(x, y);
    std::cout << "^";

}
//returns the player's pvt x value.
int  Player::getx(){
	return x;
}

// updatePos: Int -> Int
// Update x value based on switch input.
void Player::updatePos(int sw) {
    switch (sw) {
        case 1: //1 = Left, update posn x - 1
        {
         if( x > 3){ //sets the bounds
		 --x;
		 }else{ 
			x = 2;
	 	 }
            
          break;

        }

        case 2: //2 = Right, update posn x + 1
        {
	if(x < 18){	//sets the bounds.
            ++x;
        }else{
	    x = 18;
	}
	
	break;
	}
	 
    }

    std::cout << "\n\n\n\n\n\n"; //move cursor away from the map.
}

// removeLife: Boolean -> int (update player)
// remove a life if it is passed true.
void Player::removeLife(bool contact) {
    if (contact == true) {
        --lives;
    }
}

// isAlive: none -> Boolean
// if lives > 0, returns true. else false.
bool Player::isAlive() {
    if (lives > 0) {
        return true;
    } else
        false;
}
