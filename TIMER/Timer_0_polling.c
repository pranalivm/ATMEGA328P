/*
 * T0_programming.c
 *
 * Created: 28-03-2024 4.46.47 PM
 * Author : Admin
 */ 


#include <avr/io.h>

void T0Delay() ;

int main(void)
{
	DDRB = 0xFF ;   // Set all pins of Port B as outputs
	
	 while (1)
    {  //We are using LED for pin PB0 in Active Low Configuration
		PORTB = 0x00 ; // To make LED ON we will put 0 for PORTB0 to 0 
		T0Delay();  // delay function
		PORTB = 0x01 ;  // To make LED OFF we will put 1 for PORTB0 to 1 
		T0Delay();  // delay function
    }
	return 0;
	
}

void T0Delay() 
{
			
			TCNT0 = 0x00 ; // Timer/Counter Register for Timer/Counter 0  , 
			// 0000 0000 : load the initial value from which timer will start 
			// When TCNT0 reaches its maximum value (255 for an 8-bit timer), it overflows, and the Timer Overflow Flag (TOV0) is set.

			
			TCCR0A =0 ;// Setup code of – Timer/Counter Control Register A . Output pin OC0A is off (disconnected) .			 
			TCCR0B = 0x05 ;  // Timer/Counter Control Register B
			//0000 0101 : using prescaling : Clock / 1024
			
			while((TIFR0 & (1 << TOV0 )) == 0) ;  //checks for Timer overflow continuously 
			/*
			1 << TOV0 :  sets T0V0  to 1
			(TIFR0 & (1 << TOV0)) == 0  :  checks whether the Timer Overflow Flag (TOV0) is not set , it set then time overflow 
			
			
			
			Timer/Counter 0 Interrupt Flag Register :  used to indicate the status of various interrupt flags related to Timer/Counter 0
			
													
			
			
			
			
			
					: 
			
			
			
			*/
			
			TCCR0B = 0x05 ; 
			TIFR0 =  1 << TOV0 ; 
			
			
			
}



