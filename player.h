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
		
		void moveCursor(int col, int row);
		
		void drawPlayer(int length);
		
		void updatePos(int sw);
		
		void removeLife(bool contact);
		
		bool isAlive();
		
		int getx();
};

#endif
