/****************************
	  OPEN SOURCE SOCIETY
	   	 ANIL EFE
	    30.04.2020
*****************************/
#ifndef CATUINO_H_
#define CATUINO_H_

#define OUTPUT true	
#define INPUT false
#define HIGH true
#define LOW false
#define PORTB0 0	#define PORTD0 8	#define PORTC0 16
#define PORTB1 1	#define PORTD1 9	#define PORTC1 17
#define PORTB2 2	#define PORTD2 10	#define PORTC2 18
#define PORTB3 3	#define PORTD3 11	#define PORTC3 19	// ATMega32 pins are defined like arduino's pin.
#define PORTB4 4	#define PORTD4 12	#define PORTC4 20	//		PORTAx ADC pins maye use next version of "catuino".
#define PORTB5 5	#define PORTD5 13	#define PORTC5 21
#define PORTB6 6	#define PORTD6 14	#define PORTC6 22
#define PORTB7 7	#define PORTD7 15	#define PORTC7 23

void pinMode(int pin, bool mode){		
	if(mode == INPUT){					// DDRx Register will set ---> pinMode(x, INPUT);
		if (pin >= 0 && pin <= 7 ){
			DDRB&= ~(1 << pin);
			}
		if (pin >= 8 && pin <= 15 ){
			DDRD&= ~(1 << pin);
			}
		if (pin >= 16 && pin <= 23 ){
			DDRC&= ~(1 << pin);
			}
	}
	
	if(mode == OUTPUT){			
		if (pin >= 0 && pin <= 7 ){		// DDRXn Register will set ---> pinMode(x, OUTPUT);
			DDRB|= (1 << pin);
			}
		if (pin >= 8 && pin <= 15 ){
			DDRD|= (1 << pin);
			}
		if (pin >= 16 && pin <= 23 ){
			DDRC|= (1 << pin);
			}
		}
}

void digitalWrite(int pin, bool status){
	if(status == LOW){					// PORTXn Register will set ---> digitalWrite(x, LOW);
		if (pin >= 0 && pin <= 7 ){	
			PORTB&= ~(1 << pin);
		}
		if (pin >= 8 && pin <= 15 ){
			PORTD&= ~(1 << pin);
		}
		if (pin >= 16 && pin <= 23 ){
			PORTC&= ~(1 << pin);
		}
	}
	
	if(status == HIGH){					// PORTXn Register will set ---> digitalWrite(x, HIGH);
		if (pin >= 0 && pin <= 7 ){
			PORTB|= (1 << pin);
		}
		if (pin >= 8 && pin <= 15 ){
			PORTD|= (1 << pin);
		}
		if (pin >= 16 && pin <= 23 ){
			PORTC|= (1 << pin);
		}
	}
}

bool digitalRead(int pin){		// digitalRead(Buton) == 1
		if (pin >= 0 && pin <= 7 ){
			if(bit_is_clear(PINB, pin)){
				return 0;
			}
			else
				return 1;
		}
		if (pin >= 8 && pin <= 15 ){ //pinD
			if(bit_is_clear(PIND, pin - 8)){
				return 0;
			}
			else
			return 1;
		}
		if (pin >= 16 && pin <= 23 ){
			if(bit_is_clear(PINC, pin - 16)){
				return 0;
			}
			else
			return 1;
		}
}

#endif /* CATUINO_H_ */
