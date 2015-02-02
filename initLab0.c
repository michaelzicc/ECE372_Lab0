/*
* File:   initLab0.c
* Date:   Monday, February 02, 2015, 04:22:52 AM
* Author: Michael Ziccarelli
*
* Created on December 27, 2014, 1:31 PM
*/

#include "p24fj64ga002.h"
#include "initLab0.h"

void initLEDs(){
    //Initialize the pin connected to the LEDs as outputs
	TRISBbits.TRISB15 = 0;
    TRISBbits.TRISB14 = 0;
    TRISBbits.TRISB13 = 0;
    TRISBbits.TRISB12 = 0;

    //Turn each LED OFF
	LED4 = OFF;
	LED5 = OFF;
	LED6 = OFF;
	LED7 = OFF;
	
}

void initSW1(){
    //Initialize the pin connected to the switch as an input.
	TRISBbits.TRISB5 = 1;
}


void initTimer1(){
    //TODO: Initialize the timer
}