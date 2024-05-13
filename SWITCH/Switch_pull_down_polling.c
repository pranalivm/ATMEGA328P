/*
 * Switch_Pull_down.c
 *
 * Created: 04-05-2024 11.19.46 PM
 * Author : Admin
 */ 


#include <avr/io.h>        // AVR I/O definitions
#include <util/delay.h>    // AVR delay functions

int main(void) {
	// Configure Port C and Port B
	DDRC &= ~(1 << PC0);   // Set PC0 as input
	PORTC &= ~(1 << PC0);  // Disable internal pull-up resistor for PC0 (pull-down configuration)
	DDRB |= (1 << PB5);    // Set PB5 as output
	
	unsigned char previous_state, current_state;
	
	while (1) {
		// Read the previous state of the switch connected to PC0
		previous_state = PINC & (1 << PC0);
		
		// If the switch is off
		if (previous_state == 0) {
			// Wait for a short time to stabilize the switch input
			_delay_ms(100);
			
			// Read the current state of the switch again after waiting
			current_state = PINC & (1 << PC0);
			
			// If the switch is still off after waiting
			if (current_state == 0) {
				// Toggle the output on PB5
				PORTB ^= (1 << PB5);  // Toggle PB5
				} else {
				// Turn off the output on PB5
				PORTB &= ~(1 << PB5);  // Set PB5 low
			}
		}
	}
	return 0;
}


