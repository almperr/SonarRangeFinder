//Name: Alexander Perr
//Class:ECET 309
//Assignment:Lab 10 & 11 - Sonar  
//Date:3/29/2018
//File Description: This file contains functions that drive the sonar module to send/receive a pulse, used ECT to time echo, and display data on LCD  

#include <hidef.h>      /* common defines and macros */
#include <stdio.h>
#include "derivative.h"      /* derivative-specific definitions */
#include "protos.h" 
#include "defs.h"
    
void SonarStart(void)           //This function clears flags to 6 and 7 capture timers and activates sonar module  
{
   ECT_TFLG1_C7F = 1;           //clears carry flag for bit 7 capture timer
   ECT_TFLG1_C6F = 1;           //clears carry flag for bit 6 capture timer
   PTT |= 0x40;                 //activates sonar for one pulse
}

void SonarCheck(void)           //This function takes data from the sonar and calculates the distance and send the string to the LCD 
{
   //variables
   volatile unsigned int init;
   volatile unsigned int echo;
   volatile unsigned int travelTime;
   volatile unsigned int d;
   volatile unsigned int inches;
   volatile unsigned int feet;
   unsigned long prescale = 1000;
   
   char buffer[33];                      //Assigns an array to input data to our LCD
   
   init = ECT_TC6;                       //takes value from capture timer 6 and gives it to the initial value variable 
   
   while(!(ECT_TFLG1_C7F))               //waits for the echo to return by checking if the flag is high 
   {
      ;
   }
                                         
   echo = ECT_TC7;                       //stores the value from caputure timer 7 and associates it with the echo return time 
   
   if(init > echo)                                   //checks to see if initial value is greater than the return value 
   {
      travelTime = ((echo + (65535 - init))/2);      //if it is greater, then it sends the total travel time to a variable called travel time
   }
   else 
   {
      travelTime = ((echo + init)/2);                //if echo is not less than the initial value, then travel time becomes the sum of echo and the initial time. It gets divided by two in order to compensate for the time going there and back. 
   }
   
   dist = (1116*travelTime)/prescale;                   //this converts the time from the value stored in memory from ECT, into feet and inches
   
   feet = dist;
   inches = dist%12;
    
   
   sprintf(buffer, "D=%d Feet %d Inches", feet,inches);       //This sends the feet and inches value into the buffer array in the appropriate locations in the string 
   
   DisplayString(buffer);                                     //Sends the buffer array string the the LCD
        
}

void Delay(unsigned long pass)                                //delay function
{ 
   int i;
   for(i=0; i < pass; i++)
   {
      ;
   }
}


   
   