#include "WiimoteBtns.h"

#include <fcntl.h>
#include <cstdlib>
#include <iostream>

using namespace std;

WiimoteBtns::WiimoteBtns() {
    fd = open("/dev/input/event2", O_RDONLY);
    if (fd == -1) {
        cerr << "Error: Could not open event file - forgot sudo?\n";
        exit(1);
    }
}

WiimoteBtns::~WiimoteBtns() {
    close(fd);
}

int WiimoteBtns::Listen() {

    // Read a packet of 32 bytes from Wiimote
    char buffer[32];
    read(fd, buffer, 32);

    // Extract code (byte 10) and value (byte 12) from packet
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
        }
    }

    // Print them
    //ButtonEvent(code, value);
}

void WiimoteBtns::ButtonEvent(int code, int value) {
    cout << "Event code = " << code << " value = " << value << endl;
}

