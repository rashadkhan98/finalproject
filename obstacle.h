#ifndef OBSTACLE_H_
#define OBSTACLE_H_

class Obstacle{
		int x;
		int y;
		
	public:
		
		// moveCursor: output int int -> text @ cursor posn. 
		// prints outpus at posn col, row of the terminal. 
		void moveCursor(int col, int row);
		
		// drawScore: int -> cout
		// Print the score,live count, and current posn of the player. 
		void drawObstacle();
		
		void setFields(int a, int b);
		// updatePos: Int -> Int 
		// Update x value based on switch input.  
		void updatePos(int max);
		
		// removeLife: Boolean -> int (update player) 
		// remove a life if it is passed true. 
		bool isColliding(int a);

};

#endif
