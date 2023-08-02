// The error below is generated when the code is downloaed into Mbed. It indicates that in ISR we should avoid any call
// to bulky library functions in particullar certain library function like printf, these are non re-entrant 
// librarys and their behaviour could be corrupted or not function as intended.
// ++ MbedOS Error Info ++
// Error Status: 0x80010133 Code: 307 Module: 1
// Error Message: Mutex: 0x200015FC, Not allowed in ISR context
// Location: 0x8009355
// Error Value: 0x200015FC
// Current Thread: rtx_idle Id: 0x20001D2C Entry: 0x8006DBD StackSize: 0x300 StackMem: 0x20001DF8 SP: 0x2009FF54 


#include "mbed.h"

// declare variables and Interrupt method
InterruptIn button (PC_13); //Active high button on mbed board

void button_interrupt(){ //Creating interrupt function
printf("Button Pressed \r\n");//Printing mesage on serial coolterm interface
}
int main(){ // main runs in its own thread in the OS
button.fall (&button_interrupt);// If button on falling edge button_interrupt function is true and prints msg

}