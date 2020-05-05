//Name: Alexander Perr
//Class:ECET 309
//Assignment:Lab 10 & 11 - Sonar  
//Date:3/29/2018
//File Description: This file contains all of the functions to create an LCD driver

#include <hidef.h>      /* common defines and macros */
#include "derivative.h" /* derivative-specific definitions */
#include "protos.h"     //includes protos.h
#include "defs.h"       //includes defs.h

void CheckStatus(void)   //Checks the status of the busy bit
{
DDRK_DDRK7=0;
PORTD_PD5=0;
PORTD_PD6=1;
PORTD_PD7=1;

   while(PORTK_PK7)      //while waiting for the 7th bit of PORTK to go low
   {
      PORTD_PD7=0;          
      PORTD_PD7=1;
   }

DDRK_DDRK7=1;            //when 7th bit of PORTK goes low, the 7th bit in the DDRK gets activated

}

void InitLCD(void)       //intializes Ports D and K and the bits of the LCD
{
   int index;

   unsigned char arrayLCD[]={0x30,0x30,0x30,0x38,0x0f,0x01,0x06};   //array that initializes the LCD screen and writes commands to the LCD to activate
   
   DDRK=0xff;               //sets K
   DDRD=0xe0;               //activates top 3 bits of the upper nibble in D
   DDRE=0xff;
   DISPLAY_GREEN;
   
   for(index=0;index<7;index++) //loops through the array values and sends them to PORTK
   {
      PORTK=arrayLCD[index];       //values from the array get sent to PORTK to initialize it
      WriteCommand();              //command function
   }
}

void WriteCommand(void)         //function that writes the command to initialize the LCD
{
   PORTD_PD5=0;
   PORTD_PD6=0;
   PORTD_PD7=1;
   PORTD_PD7=0;
   Delay(1000);
      
}

void WriteData(void)            //function that writes the command to write data from the string to the LCD
{
   PORTD_PD5=1;
   PORTD_PD6=0;
   PORTD_PD7=1;
   PORTD_PD7=0;
   CheckStatus();               //added to check the status of the busy bits
}

void DisplayString(char* myString)     //function that displays the string that is passed to it
{
   unsigned int index=0;
   
   while(!(myString[index]==0))        //checks to see if the index position ever hits zero
   {
      if(index == 16)                  //This if statement writes chars to the second line after the index goes over 16
      {
         PORTK=SECOND_LINE;
         WriteCommand();
      }
      PORTK=myString[index];           //portk gets passed the value that is in the written string
      index++;
      WriteData();                     //writes the string to the LCD
      Delay(10000);
   }
}

