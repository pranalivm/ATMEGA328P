/*
 * Timer1_Programming_.c
 * Created: 28-03-2024 5.35.44 PM
 * Author : Admin
 */ 

#include <avr/io.h>

void T1Delay();

int main(void)
{
	DDRB = 0xFF; // Set all pins of Port B as output , DDRB register corresponds to a pin on port b. setting a bit to 1 makes the corresponding pin as an output.
	
	while (1)
	{
		// Toggle LED connected to pin PB0
		PORTB ^= (1 << 0); // To make LED ON, we will toggle the bits using XOR operator 
		
		T1Delay(); // Wait using the T1Delay function
	}
	return 0;
}

void T1Delay()
{
	// set initial value for timer/counter 1
	TCNT1H = 0xF0; // load high byte into counter (TCNT1H) , 
	TCNT1L = 0x00; // load low byte into counter (TCNT1L)
	//TCNT1H and TCNT1L together form a 16-bit counter , together they signify the initial count value for the 16-bit timer
	// sets the initial count value of Timer/Counter1 to 0xF000.
	//sets the initial count value of Timer/Counter1 to 0xF000. it increments till 0xFFFF then overflows 

	// configure Timer/Counter1 for delay
	TCCR1A = 0x00; // configure TCCR1A for normal mode 
	
	//COM1A1 COM1A0 COM1B1 COM1B0 – – WGM11 WGM10 :  0000 0000 : normal port operation 
	//Compare Output Mode ,            Waveform Generation Mode
	// TOV1 Flag sets on MAX : 0xFFFF 

	
	TCCR1B = 0x05; // configure (Timer/Counter1 Control Register B) TCCR1B with a prescaler of 1024
	// TCCR1B – Timer/Counter1 Control Register B
	//ICNC1 ICES1 – WGM13 WGM12 CS12 CS11 CS10 
	// 0     0    0   0    0     1     0   1 
	// 101 so 1024 prescalar used .  A prescaler is a divider circuit that reduces the frequency of a clock signal before it is applied to a device or a subsystem within a device.
	
	
	
	/*
	ICNC1: Input Capture Noise Canceler (ICNC1) bit
	ICES1: Input Capture Edge Select (ICES1) bit
	WGM13: Waveform Generation Mode 13 (WGM13) bit
	WGM12: Waveform Generation Mode 12 (WGM12) bit
	CS12: Clock Select 12 (CS12) bit
	CS11: Clock Select 11 (CS11) bit
	CS10: Clock Select 10 (CS10) bit
	*/
	
	while ((TIFR1 & (0x1 << TOV1)) == 0) ; // Polling the Timer/Counter1 Overflow Flag (TOV1) bit
	/*
	 # TIFR1 = Timer/Counter1 Interrupt Flag Register
	 – – ICF1 – – OCF1B OCF1A TOV1
	 
	 Pin name ::
	 ICF1: Input Capture Flag 1 (ICF1) bit
	 OCF1B: Output Compare Flag 1B (OCF1B) bit
	 OCF1A: Output Compare Flag 1A (OCF1A) bit
	 TOV1: Timer/Counter1 Overflow Flag (TOV1) bit
	
	
	
	*/
	
	// reset Timer/Counter1 and overflow flag
	TCCR1B = 0; // stop Timer/Counter1 by clearing clock source bits .
	TIFR1 = 0x1 << TOV1; // clear the  TOV1 by writing 1 to it
}

// different port for LED ,  2 LED , 


