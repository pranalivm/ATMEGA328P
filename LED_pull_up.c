/*
 * LED_Pull_up.c
 *
 * Created: 04-05-2024 11.35.17 PM
 * Author : Admin
 */ 


#define F_CPU 16000000UL
#include <util/delay.h>
#include <avr/io.h>

int main(void)
{
	DDRB = 0xFF;    // Set all pins of port B as outputs
	PORTB = 0xFF;   // Activate internal pull-up resistors for all pins of port B

	while (1) {
		// Turn on all LEDs
		PORTB = 0xFF;
		_delay_ms(100); // Delay for 100 milliseconds

		// Turn off all LEDs
		PORTB = 0x00;
		_delay_ms(100); // Delay for 100 milliseconds
	}

	return 0;
}


