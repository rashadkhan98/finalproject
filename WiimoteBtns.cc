#include "WiimoteBtns.h"

#include <fcntl.h>
#include <cstdlib>
#include <iostream>
using namespace std;

WiimoteBtns::WiimoteBtns(){
	fd = open("/dev/input/event2", O_RDONLY);
	if (fd == -1)
	{
		cerr << "Error: Could not open event file - forgot sudo?\n";
		exit(1);
	}
}

WiimoteBtns::~WiimoteBtns(){
	close(fd);
}

void WiimoteBtns::Run(){
     int state = 1; //Game is running
	while (true)                                                              
        {                                                                         
                // Read a packet of 32 bytes from Wiimote                        
                char buffer[32];                                                  
                read(fd, buffer, 32);                                             
                                                                                  
                // Extract code (byte 10) and value (byte 12) from packet        
                int code = buffer[10];                                            
                int value = buffer[12];                                           
                                                                                 
                // Print them                                                    
		//ButtonEvent(code, value);
   
   state = CheckEvent(code, value, state);
   
                   if (state == 0) then    
        }                          
		
}
void WiimoteBtns::ButtonEvent(int code, int value)
{
	cout << "Event code = " << code << " value = " << value << endl;
}
int WiimoteBtns::CheckEvent(int code, int value, int state)
{
	if (value == 1)
 {
 
     switch (code)
     {
            case 103: //Far left button pressed (UP)
            {
                            
            }
            case 2: //Far right button pressed (2)
            {
                 
            }
            case 151: //Home button pressed
            {
            
            }
     }
 }
}
