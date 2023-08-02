
//Comment: When added veriable flag0 to interrupt function,
//the output is very unstable and always indicates that the button is being pressed(falling edge) regardless of the physical button state. 
//the flag is set to 1 and and not being reset  
//proposed solution is to use switch statement with two cases to trigger desired interrupt function in a stable state, execute the code within the function in this case 
//print the button state next to reset state of the flag0 veriable and break/exit the case fuction. This solution also allows to avoid switch debounce effect. 


#include "mbed.h"

//declare variables and Interrupt method
InterruptIn button (PC_13); //Active high (3.3VDC) button on mbed board
char flag0=0; //Veriable of char type

void fall_int(){ //Declaring fall function 
flag0=1;
}
void rise_int(){ //Declaring rise function 
flag0=2;
}
int main(){ //main runs in its own thread in the OS

    button.fall(&fall_int);//When button is pressed voltage falling to 0VDC and sets the  fall_int function 
    button.rise(&rise_int);//When button is depressed voltage rising to 3.3VDC and sets the rise_int function

    while(true){ //Continous loop
    switch (flag0){ //Switch statement compares flag0 state with case1&case2 and executes the code within the case
    case 1:
    printf("Fall Interrupt\n\r");
    flag0=0;
    break;
    case 2:
    printf("Rise Interrupt\n\r");
    flag0=0;
    break;
    default:
    flag0=0;
    break;
    
    }
 thread_sleep_for(50);
}

}
