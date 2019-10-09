/*	Author: nmoor004
 *  Partner(s) Name: 
 *	Lab Section: 022	
 *	Assignment: Lab # 3 Exercise # 5
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

int DA_COUNTA(unsigned char DA_BITZ, unsigned char DA_EXTRA_BIT) { //Returns int sum which is the decimal version of binary input
	int binary_to_decimal = 1;
	int sum = 0;

	if (DA_EXTRA_BIT == 0x01) { //Using the 0th bith
		sum += binary_to_decimal;
		binary_to_decimal *= 2;
	}

	while (DA_BITZ != 0x00) { //Adds current binary to decimal place value and then right shifts
		if ((DA_BITZ & 0x01) == 0x01) {
			sum += binary_to_decimal;

		}
		binary_to_decimal *= 2; //Switch to next bit place
		DA_BITZ >>= 1; //Right shift

	}

return sum;
}

int main(void) {
    /* Insert DDR and PORT initializations */
	DDRA = 0x00; PORTA = 0xFF;     //input for 0th bit of 9-bit
	DDRB = 0xFF; PORTB = 0x00;    //output for 0th bit of 9-bit
	DDRC = 0xFF; PORTC = 0x00;   //output for bits 9 to 1 of 9-bit
	DDRD = 0x00; PORTD = 0xFF;  //input for bits 9 to 1 of 9-bit


    /* Insert your solution below */
	unsigned char input_val;
	unsigned char zeroth_val;
	int test;
	while (1) { // Take input value, find decimal version and determine range, 
		   // and then output the input value plus any other signals
		input_val = PIND;
		zeroth_val = PINA;

		test = DA_COUNTA(input_val, zeroth_val);

		if (test >= 70) {
			PORTC = PIND;
			PORTB = (PINA |0x02); //PB1 = 1	
		}
		else if (test > 5) {
			PORTC = PIND;
			PORTB = (PINA | 0x04); //PB2 = 1
		}
		else {
			PORTC = PIND;
			PORTB = PINA;
		}

		
		
		
	}
	return 1;
}
