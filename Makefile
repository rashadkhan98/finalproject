all: racegame

racegame: main.o player.o gamemap.o
	g++ main.o player.o gamemap.o -o racegame

main.o: main.cc player.h gamemap.h
	g++ -g -Wall -c main.cc player.h gamemap.h
	
player.o: player.cc player.h
	g++ -g -Wall -c player.cc player.h

obstacle.o: obstacle.cc obstacle.h
	g++ -g -Wall -c obstacle.cc obstacle.h
	
gamemap.o: gamemap.cc gamemap.h
	g++ -g -Wall -c gamemap.cc gamemap.h

WiimoteBtns.o: WiimoteBtns.cc WiimoteBtns.h
	g++ -g -Wall -c WiimoteBtns.cc WiimoteBtns.h
	
clean:
	rm racegame *.gch *.o
