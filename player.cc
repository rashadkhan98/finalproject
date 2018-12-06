#include <iostream>
#include <string>
#include <unistd.h>
#include "player.h"

void Player::setFields(int a, int b, int c) {
    x = a;
    score = b;
    lives = c;
}

// moveCursor: output int int -> text @ cursor posn.
// prints outpus at posn col, row of the terminal.
void Player::moveCursor(int col, int row) {
    std::cout << "\033[" << row << ";" << col << "H";
}

// drawScore: int -> cout
// Print the score,live count, and current posn of the player.
void Player::drawPlayer(int y) {
    moveCursor(0, 0);
    std::cout << "Score: " << score;

    moveCursor(10, 0);
    std::cout << "Lives: " << lives;

    usleep(10000);
    moveCursor(x, y);
    std::cout << "^";

}

// updatePos: Int -> Int
// Update x value based on switch input.
void Player::updatePos(int sw) {
    switch (sw) {
        case 1: //1 = Left, update posn x - 1
        {
            --x;
            //usleep(10000);
            //std::cout << "\n\n\n\n\n\n";
            break;

        }

        case 2: //2 = Right, update posn x + 1
        {
            ++x;
            break;
        }
    }

    std::cout << "\n\n\n\n\n\n";
}

// removeLife: Boolean -> int (update player)
// remove a life if it is passed true.
void Player::removeLife(bool contact) {
    if (contact == true) {
        --lives;
    }
}

// isAlive?: none -> Boolean
// if lives > 0, returns true. else false.
bool Player::isAlive() {
    if (lives > 0) {
        return true;
    } else
        false;
}
