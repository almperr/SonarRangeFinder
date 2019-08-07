//Name: Alexander Perr
//Class:ECET 309
//Assignment:Lab 10 & 11 - Sonar  
//Date:3/29/2018
//File Description: This file is for macros definitions

#define BIT2 0x04                   //creates BIT2  
#define BIT3 0x08                   //creates BIT3
#define HOME_DISPLAY 0x02           //bit that sets the display pointer back to the original position
#define CLEAR_DISPLAY 0x01          //bit that clears display of all chars
#define SECOND_LINE 0xc0            //brings the pointer to the second line
#define DISPLAY_OFF PORTE &= ~0x0c           //turns the LCD light off
#define DISPLAY_RED PORTE |= BIT2 & ~BIT3    //turns the LCD light red 
#define DISPLAY_GREEN PORTE |= ~BIT2 & BIT3  //turns the LCD green
#define DISPLAY_BLUE PORTE |= 0x0C  //turns the LCD blue