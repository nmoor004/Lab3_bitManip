/*	Author: nmoor004
 *  Partner(s) Name: 
 *	Lab Section: 022	
 *	Assignment: Lab # 3 Exercise #
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

int main(void) {
    /* Insert DDR and PORT initializations */
	DDRA = 0x00; PORTA = 0xFF;   //input
	DDRB = 0xFF; PORTB = 0x00;  //output
	DDRC = 0xFF; PORTC = 0x00; //output

    /* Insert your solution below */
	unsigned char up_nib = 0x00;
	unsigned char low_nib = 0x00;
	while (1) {
		up_nib = PINA & 0xF0;
		low_nib = PINA & 0x0F;

		up_nib >>= 4;  //Shift the upper nibble of PINA to lower nibble.
		low_nib <<=4; //Shift the lower nibble of PINA to upper nibble.

		PORTB = up_nib;
		PORTC = low_nib;
		
	}
	return 1;
}
