
/*
 * transmitter_code_for_character with interrupt.c
 *
 * Created: 05/08/2017 04:48:08 
 *  Author: Naimi
 */ 


#include <avr/io.h>          // AVR I/O declarations
#include <avr/interrupt.h>   // AVR interrupt handling
#include <util/delay.h>      // AVR delay functions

ISR(USART_UDRE_vect)
{
	UDR0 = 1 ;   // USART I/O Data Register
	
}

int main (void)
{
	UCSR0B = (1<<TXEN0)|(1<<UDRIE0);  
	/*
	UCSR0B - USART Control and Status Register 0 B
	bits -
	RXCIEn TXCIEn UDRIEn RXENn TXENn UCSZn2 RXB8n TXB8n
	

	 TXEN0 : (Transmitter Enable 0 ) Writing this bit to one enables the USART Transmitter. 
	UDRIE0 : ( USART Data Register Empty Interrupt Enable 0) Writing this bit to one enables interrupt on the UDREn Flag
	
		*/
	
	UCSR0C = (1<< UCSZ01)|(1<<UCSZ00);  
	/*
	
	UCSR0C -  USART Control and Status Register 0 C
	
	bits -
	UMSELn1 UMSELn0 UPMn1 UPMn0 USBSn UCSZn1 UCSZn0 UCPOLn
	------ ------
	
	UCSZn1 UCSZn0 : bit 2 , bit 1 : decides character size
	
	
	Set data frame format: 8 data bits
	
	*/
	
	UBRR0L = 103;  // USART Baud Rate Registers

	sei();				//enable interrupts globally
	while (1);
			
	return 0;
}