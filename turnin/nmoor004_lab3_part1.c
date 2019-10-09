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


int DA_COUNTA(unsigned char DA_BITZ_A, unsigned char DA_BITZ_B) {
	int sum = 0;
	while (DA_BITZ_A != 0x00) { // Takes bits, counts if bit is 1, then right shifts for next bit
		if ((DA_BITZ_A & 0x01) == 0x01) {
			sum += 1;
		} 
		DA_BITZ_A >>= 1;

	}

	while (DA_BITZ_B != 0x00) {
		if ((DA_BITZ_B & 0x01) == 0x01) {
			sum += 1;
		}
		DA_BITZ_B >>= 1;
	}
	
return sum;
}


int main(void) {
    /* Insert DDR and PORT initializations */
	DDRA = 0x00;	PORTA = 0xFF;   //input 
	DDRB = 0x00;	PORTB = 0xFF;  //input
	DDRC = 0xFF;	PORTC = 0x00; //output 

    /* Insert your solution below */
	unsigned char input_val_a;
	unsigned char input_val_b;
	int num_bits = 0;

	while (1) {
		input_val_a = PINA; 
		input_val_b = PINB;
		num_bits = DA_COUNTA(input_val_a, input_val_b);
		
		 //Brute force this because no brain

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



