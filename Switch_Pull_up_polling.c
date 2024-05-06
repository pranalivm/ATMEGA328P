
/*
 * GccApplication1.c
 *
 * Created: 02-11-2023 11.31.09 PM
 * Author : Admin
 */ 


#include <avr/io.h>        // AVR I/O declarations
#include <util/delay.h>    // AVR delay functions

int main(void) {
	// Configure Port C and Port B
	DDRC = 0x00;   // Set Port C as input
	PORTC = 0x01;  // Enable pull-up resistor for PC0
	DDRB = 0x24;   // Set PB5  and PB2 as outputs
	
	unsigned char previous_state, current_state;
	
	while (1) {
		// Read the previous state of the switch connected to PC0
		previous_state = PINC;
		
		// If the switch is off
		if (previous_state == 0x01) {
			// Wait for a short time to stabilize the switch input
			_delay_ms(100);
			
			// Read the current state of the switch again after waiting
			current_state = PINC;
			
			// If the switch is still off after waiting
			if (current_state == 0x00) {
				// Toggle the output on PB5
				PORTB ^= 0x20;  // Toggle PB5
				} else {
				// Turn off the output on PB5
				PORTB = 0x00;   // Set PB5 low
			}
		}
	}
	return 0;
}
