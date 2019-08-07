//Name: Alexander Perr
//Class:ECET 309
//Assignment:Lab 10 & 11 - Sonar  
//Date:3/29/2018
//File Description: This file is initializing the ECT

#include <hidef.h>      /* common defines and macros */
#include "derivative.h"      /* derivative-specific definitions */
#include "protos.h" 
#include "defs.h"

void InitECT (void)               //Initializes the ECT
{
   ECT_TSCR1_TEN = 1;            //activates the timer 
   ECT_TSCR2 |= 0x03;            //Sets the prescalar resolution to 1 micro second
   ECT_TIOS &= ~0xc0;            //Sets channels 6 and 7 as input capture bits
   ECT_TCTL3_EDG6A = 1;          //Sets up channels 6 and 7 for rising edge inputs
   ECT_TCTL3_EDG6B = 0;
   ECT_TCTL3_EDG7A = 1;
   ECT_TCTL3_EDG7B = 0; 
}



