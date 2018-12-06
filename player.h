#ifndef PLAYER_H_
#define PLAYER_H_

class Player{
		int x;
		int score;
		int lives;
	public:
		int getScore();

		int getLives();
			
		void setScore(int s);
	
		void setFields( int a, int b, int c);
		// moveCursor: output int int -> text @ cursor posn. 
		// prints outpus at posn col, row of the terminal. 
		void moveCursor(int col, int row);
		
		// drawScore: int -> cout
		// Print the score,live count, and current posn of the player. 
		void drawPlayer(int length);
		
		// updatePos: Int -> Int 
		// Update x value based on switch input.  
		void updatePos(int sw);
		
		// removeLife: Boolean -> int (update player) 
		// remove a life if it is passed true. 
		void removeLife(bool contact);
		
		// isAlive?: none -> Boolean
		// if lives > 0, returns true. else false. 
		bool isAlive();
		
		int getx();
};

#endif
