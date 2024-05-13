#include "avr/io.h"
#include "avr/interrupt.h"

int main(void)
{
	DDRB |= 0x20; //setting pin PB5 (0100 0000) as output

	OCR0A = 0xFE; //In Timer0's Output compare register of A channel we
	//have kept value as oxFE i.e 1111 1110
	//AS Timer0 is 8 bit timer is TCNT0 register can count
	//till maximumm 255 i.e 0xFF or 1111 1111
	//Once value present in TCNT0 register matches with
	//OCR0A register then an Output compare match
	//interrupt will get triggered
	
	//The Output Compare Register A contains an 8-bit value that is continuously compared with the counter value
	//(TCNT0).


	TCCR0A = (1 << WGM01); //We had kept timer0 in capture compare mode so
	//it can generate interrupt when TCNT0's count
	//will reach to value present in OCR register
	//
	//This is achieved by giving value 010 to WGM02, WGM01
	//and WGM00 bits respectively
	
	//
	//out of them WGM01 and WGM00 are present in TCCR0A, while
	//WGM02 is present in TCCR0B register
	
	/*
	Shifting by 1:

	Shifting the value 1 by 1 position to the left effectively moves the single 1 bit one position to the left, creating a new binary value:
	Original: 0000 0001 (1)
	Shifted: 0000 0010 (2 in decimal)
	Setting WGM01 Bit:

	By assigning the result (0000 0010) to the TCCR0A register, 
	we are essentially setting the bit at position 1 (which corresponds to WGM01 in most AVR microcontrollers) to 1
	 and keeping all other bits unchanged.
	
	
	*/

	TCCR0B = 0x05; //0000 0101 here we had kept Clock select bits CS02, CS01, CS00
	//we had used prescalar with value clk/1024 maximum possible
	//prescalar so that we can observe the output

	TIMSK0 = (1 << OCIE0A); //Enabling interrupt for Timer0 Compare match for channel A

	sei(); //This functione enables interrupt

	volatile long long int i = 0;

	while(1)
	i++;

	return 0;
}

ISR(TIMER0_COMPA_vect)
{
	PORTB ^= 0x20; 
}