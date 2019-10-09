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



int main(void) {
    /* Insert DDR and PORT initializations */
	DDRA = 0x00;	PORTA = 0xFF;   //input 
	DDRB = 0x00;	PORTB = 0xFF;  //input
	DDRC = 0xFF;	PORTC = 0x00; //output 

    /* Insert your solution below */
	unsigned char temp_val = 0x00;
	int num_bits = 0;
	int k = 0;

	while (1) {
				temp_val = PINA;

		while (k != 0x80) {	// Inner while loop which checks bit 0 of temp_val and
					       // Right shifts temp_val so that the next bit can be checked
					      // Then it increments num_parked if bit 0 is 1.	
			if (temp_val & (0x01 << k)) {
				num_bits++;
			}
			k <<= 1;
		}

				temp_val = PINB;

		while (temp_val != 0x00) {  //Same while loop as above except for PINB
			
			if ((temp_val & 0x01)) {
				num_bits++;
			}
			temp_val = temp_val >> 1; 
		} 
		
		 //Brute force this because no brain :(
		//

		if (num_bits == 1) {
			PORTC = 0x01;
		}
		else if (num_bits == 2) {
			PORTC = 0x02;
		}
		else if (num_bits == 3) {
			PORTC = 0x03;
		}
		else if (num_bits == 4) {
			PORTC = 0x04;
		}
		else if (num_bits == 5) {
			PORTC = 0x05;
		}
		else if (num_bits == 6) {
			PORTC = 0x06;
		}
		else if (num_bits == 7) {
			PORTC = 0x07;
		}
		else if (num_bits == 8) {
			PORTC = 0x08;
		}
		else if (num_bits == 9) {
			PORTC = 0x09;
		}
		else if (num_bits == 10) {
			PORTC = 0x0A;
		}
		else if (num_bits == 11) {
			PORTC = 0x0B;
		}
		else if (num_bits == 12) {
			PORTC = 0x0C;
		}
		else if (num_bits == 13) {
			PORTC = 0x0D;
		}
		else if (num_bits == 14) {
			PORTC = 0x0E;
		}
		else if (num_bits == 15) {
			PORTC = 0x0F;
		}
		else if (num_bits == 16) {
			PORTC = 0x10; //The max possible bits in these two ports.
		}
		else {
			PORTC = 0x00; //Either you have zero bits or something is terribly wrong.
		}
		


	}

return 1;
}
