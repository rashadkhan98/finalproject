#ifndef OBSTACLE_H_
#define OBSTACLE_H_

class Obstacle{
		int x;
		int y;
		
	public:
		

		void moveCursor(int col, int row);
	
		void drawObstacle();
		
		void setFields(int a, int b);
		
		void updatePos(int max);
		
		bool isColliding(int a);

};

#endif
