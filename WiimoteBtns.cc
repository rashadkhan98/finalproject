#include "WiimoteBtns.h"

#include <fcntl.h>
#include <cstdlib>
#include <iostream>

using namespace std;

//construct the object. read in data from event2, O_NONBLOCK so it reads nonblocking.
WiimoteBtns::WiimoteBtns() {
    fd = open("/dev/input/event2", O_RDONLY | O_NONBLOCK);
    if (fd == -1) {
        cerr << "Error: Could not open event file - forgot sudo?\n";
        exit(1);
    }
}
//deconstruct the object
WiimoteBtns::~WiimoteBtns() {
    close(fd);
}
//listen for the next button press, if not given a press, still reads packet so it doesn't block.
int WiimoteBtns::Listen() {

    // Read a packet of 32 bytes from Wiimote
    char buffer[32];
	read(fd, buffer, 32);
    int code = buffer[10];
    int value = buffer[12];
    if (value == 1){
        switch(code){
            case 103:
            {
                return 1; //Left
            }
            case 2:
            {
                return 2; //Right
            case 1:
            	
            	return 3; //Save and Quit.
            }
	    default:
		return 0; //keeps game running, doesn't pass
        }
	} 
	return 0;
}
//print button code and value, for debugging information. 
void WiimoteBtns::ButtonEvent(int code, int value) {
    cout << "Event code = " << code << " value = " << value << endl;
}

