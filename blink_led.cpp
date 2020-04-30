/****************************
	     ANIL EFE
    "Catuino" Blink Led
	   ATMega32A-PU
*****************************/

#define F_CPU 16000000  // Crystal frequency set 16MHz
#include <avr/io.h>
#include <util/delay.h>
#include "catuino.h"

int main(void){
	pinMode(PB3, OUTPUT);
	
		while(1){	// Infinite loop, added because of codes run just once in avr.
		digitalWrite(PB3, HIGH);	// Also digitalWrite(PB1, HIGH); works too.
		_delay_ms(50);				// Include <util/delay.h> before using.
		digitalWrite(PB3, LOW);		// Also digitalWrite(PB1, HIGH); works too.
		_delay_ms(50);
		
		/*
		   |---------------|
		   | BUTTON EXAMPLE| Button pin 1 is connected to ATMega -In this example, to PD6(14)-, 
		   |---------------| another is connected to GROUND.		
		
		if(digitalRead(14) == 0){
			// Pushed the button, write your code here.
		}
		
		*/ 
		
	}
}
