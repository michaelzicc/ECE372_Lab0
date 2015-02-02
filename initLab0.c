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
	TRISBbits.TRISB15 = TRISOut;
    TRISBbits.TRISB14 = TRISOut;
    TRISBbits.TRISB13 = TRISOut;
    TRISBbits.TRISB12 = TRISOut;

    //Turn each LED OFF
	LED4 = OFF;
	LED5 = OFF;
	LED6 = OFF;
	LED7 = OFF;
	
}

void initSW1(){
    //Initialize the pin connected to the switch as an input.
	TRISBbits.TRISB5 = TRISIn;
	
	//Put the overall CN Interrupt flag down
    IFS1bits.CNIF = 0;

    //Enable the overall change notification interrupt
    IEC1bits.CNIE = 1;

    // Enable the change notification interrupt for the switch 1 
    CNEN2bits.CN27IE = 1;
}


void initTimer1(){
    //TODO: Initialize the timer
	unsigned int prVal = (FCY*TIME_DELAY)/256.0 - 1;
    PR1 = prVal;
    T1CONbits.TCKPS = 0b11; //prescalar 256
    IEC0bits.T1IE = 1; // Enable the interrupt
    IFS0bits.T1IF = 0; // Put the interrupt flag down
}

void turnOnLED(int led){
    if(led == 4){
        LED4 = ON;
        LED5 = OFF;
        LED6 = OFF;
        LED7 = OFF;
    }
    else if(led == 5){
        LED4 = OFF;
        LED5 = ON;
        LED6 = OFF;
        LED7 = OFF;
    }
    else if(led == 6){
        LED4 = OFF;
        LED5 = OFF;
        LED6 = ON;
        LED7 = OFF;
    }
    else if(led == 7){
        LED4 = OFF;
        LED5 = OFF;
        LED6 = OFF;
        LED7 = ON;
    }
}