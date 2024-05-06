#define F_CPU 16000000UL
#include <util/delay.h>
#include <avr/io.h>

int main(void)
{
	DDRB = 0xFF;    // set all pins of port B as outputs
	PORTB = 0x00;   // disable internal pull-up resistors for all pins of port B

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
