/*
 * receiver_interrupt_enable_code.c
 *
 * Created: 05/08/2017 04:41:41 
 *  Author: Naimi
 */ 


#include <avr/io.h>          // AVR I/O declarations
#include <avr/interrupt.h>   // AVR interrupt handling

ISR(USART_RX_vect)  
{
	PORTC = UDR0;    // read received data from USART Data Register and write it to port C
	
	/*
	UDR0 : USART Data Register 0. 
	It's used for both receiving and transmitting serial data through the USART
	
	Read Operation: reading from this register returns the received data when in receive mode.
	Write Operation: writing to this register sends the data to be transmitted when in transmit mode.
	*/
}

int main (void)
{
	DDRC = 0x3F;				//make Port C an output 
	/*
	DDRC: Data Direction Register C (for PORT C )
	0011 1111 ( PB0 to PB5 ) set as output 
	*/

	UCSR0B = (1<<RXEN0)|(1<<RXCIE0);//enable receive and RXC int.
	
	/*
	UCSR0B - USART Control and Status Register 0 B
	bits -
	RXCIEn TXCIEn UDRIEn RXENn TXENn UCSZn2 RXB8n TXB8n
	------               -----
	
	
	
	*/
	
	
	UCSR0C = (1<< UCSZ01)|(1<<UCSZ00);
	
	/*
	UCSR0C -  USART Control and Status Register 0 C
	
	bits -
	UMSELn1 UMSELn0 UPMn1 UPMn0 USBSn UCSZn1 UCSZn0 UCPOLn
									  ----    ------
	
	UCSZn1 UCSZn0 : bit 2 , bit 1 : decides character size
	
	Set data frame format: 8 data bits
	
	*/
   UBRR0L = 103; // USART Baud Rate Register, sets the baud rate

   sei(); // Enable interrupts globally

   while (1)
   ; // Infinite loop, the program waits for interrupts to occur

}