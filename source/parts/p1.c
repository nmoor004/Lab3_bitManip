/*	Author: nmoor004
 *  Partner(s) Name: 
 *	Lab Section: 022	
 *	Assignment: Lab # 3 Exercise # 1
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

void THE_ADDER(unsigned char &input_val, int bitnum) {

unsigned char mask = 0x01;

	while (input_val & mask) {
		input_val &= mask;
		mask <<= 1;

	}
	input_val |= mask;

}

int main(void) {
    /* Insert DDR and PORT initializations */
	DDRA = 0x00;	PORTA = 0xFF;   //input 
	DDRB = 0x00;	PORTB = 0xFF;  //input
	DDRC = 0xFF;	PORTC = 0x00; //output 

    /* Insert your solution below */
	unsigned char temp_val = 0x00;
	unsigned char end_counter = 0x00;
	int num_bits = 0;
	//int i = 0;

	while (1) {
				temp_val = PINA;

		while (temp_val != 0x00) {	// Inner while loop which checks bit 0 of temp_val and
					       // Right shifts temp_val so that the next bit can be checked
					      // Then it increments num_parked if bit 0 is 1.	
			if ((temp_val & 0x01) == 0x01) {
			   num_bits++;
			}
			temp_val = temp_val >> 1;
		}

				temp_val = PINB;

		while (temp_val != 0x00) {  //Same while loop as above except for PINB
			
			if ((temp_val & 0x01) == 0x01) {
				num_bits++;
			}
			temp_val = temp_val >> 1; 
		}
		
		
		THE_ADDER(end_counter);

		num_bits = 0;
		PORTC = end_counter;

	}

return 1;
}
