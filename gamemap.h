#ifndef GAMEMAP_H_
#define GAMEMAP_H_

class GameMap{
	int length;
	bool running;
		
	public:
	
	int getlength();
	
	bool isrunning();
	
	void setbool(bool input);
		
	void setlength(int number);
	
	void clearScreen();
	
	void moveCursor(int col, int row);

	void drawBorders();
	
	void drawMap();
};

#endif 
