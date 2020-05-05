//Name: Alexander Perr
//Class:ECET 309
//Assignment:Lab 10 & 11 - Sonar  
//Date:3/29/2018
//File Description: This file is main. Initialize ECT, LCD driver, and IO port for sonar module. Wait for button press. Set LCD, collect data with sonar, and display on LCD

#include <hidef.h>      /* common defines and macros */
#include <stdio.h>
#include "derivative.h"      /* derivative-specific definitions */
#include "protos.h"
#include "defs.h"


void main(void) 
{
  /* put your own code here */
  
  InitECT();              //initializes the ECT
  InitLCD();              //Initializes the LCD 
  
  DDRT = 0x40;            //initializes the PORT for the sonar module


  for(;;) 
  {
   
   PTT &= ~0x40;              //deactivates the sonar module after being active
   
   while (PTIS & 0x10)       //waits for the button to be pressed
   {
      ;
   }
   
   Delay(20);                //debounce
   
   while (!(PTIS & 0x10))       //waits for the button to be released
   {
      ;
   }
   
   PORTK=HOME_DISPLAY;              //brings the pointer back to the home position
   WriteCommand();                  //initializes LCD to have data written to it
   PORTK=CLEAR_DISPLAY;             //clears the LCD
   WriteCommand();                  //initializes LCD to have data writen to it
   
   SonarStart();                    //Activates the sonar module and clear the flags 
   SonarCheck();                    //Check the timers, calculate and display information
   
   
  } /* loop forever */
  /* please make sure that you never leave main */
}
