// ******************************************************************************************* //
//
// File:         lab0.c
// Date:         Monday, February 02, 2015
// Authors:      Michael Ziccarelli
//
// Description:  Lab 0 assignment for ECE 372 Spring 2015.
// ******************************************************************************************* //

#include "p24fj64ga002.h"
#include "initLab0.h"
#include <stdio.h>

// ******************************************************************************************* //
// Configuration bits for CONFIG1 settings.
//
// These settings are appropriate for debugging the PIC microcontroller. If you need to
// program the PIC for standalone operation, change the COE_ON option to COE_OFF.

_CONFIG1( JTAGEN_OFF & GCP_OFF & GWRP_OFF &
          BKBUG_ON & COE_ON & ICS_PGx1 &
          FWDTEN_OFF & WINDIS_OFF & FWPSA_PR128 & WDTPS_PS32768 )

_CONFIG2( IESO_OFF & SOSCSEL_SOSC & WUTSEL_LEG & FNOSC_PRIPLL & FCKSM_CSDCMD & OSCIOFNC_OFF &
          IOL1WAY_OFF & I2C1SEL_PRI & POSCMOD_XT )



typedef enum stateTypeEnum{
    //Define states by name
	D4, D5, D6, D7
} stateType;

volatile stateType currState;

int main(void)
{
	currState = D4;
	
    //TODO: Finish these functions in the provided c files
    initLEDs();
    initTimer1();
    initSW1();
    
    while(1)
    {
        //Use a switch statement to define the behavior based on the state
        switch(currState){
			case D4:
				break;
			case D5:
				break;
			case D6:
				break;
			case D7:
				break;
        }
    }
    return 0;
}

void _ISR _CNInterrupt(void){
    IFS1bits.CNIF = 0;	//put down interrupt flag
	
	//Move to next state when Switch 1 is pressed (and released)
    if(PORTBbits.RB5 == RELEASED){
        if(currState == D4) currState = D5;
        else if(currState == D5) currState = D6;
        else if(currState == D6) currState = D7;
        else if(currState == D7) currState = D4;
    }
}

void _ISR _T1Interrupt(void){
    //TODO: Put down the timer 1 flag first!
    IFS0bits.T1IF = 0;

    //TODO: Change states if necessary.
    //Make sure if you use any variables that they are declared volatile!
}