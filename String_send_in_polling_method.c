/*
 * UART_Example_10.c
 *
 * Created: 24-04-2024 5.14.01 PM
 * Author : Admin
 */ 


#include <avr/io.h>
#include <util/delay.h> 
#define F_CPU 16000000UL  //Define CPU frequency
#define BAUD_RATE 9600  //Define baud rate for UART communication

void usart_init (void)   //initializes the USART communication.
{
	UCSR0B = (1<<TXEN0);
	/*
	
	UCSR0B - USART Control and Status Register 0 B
	bits - 
	RXCIEn TXCIEn UDRIEn RXENn TXENn UCSZn2 RXB8n TXB8n
							   ------
							   
	TXENn : Bit 3  :  Transmitter Enable
	Writing this bit to one enables the USART Transmitter. The Transmitter will override normal port operation for
	the TxDn pin when enabled.
		
	
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
	
	UBRR0L = F_CPU/16/BAUD_RATE-1; //UBRR0L = 103;
	
	/*
	UBRR0L : – USART Baud Rate Register 
	
	UBRR = F_CPU / (16 * BAUD_RATE) -1 
	UBRR = 16,000,000 / (16 * 9,600) - 1
	UBRR = 104.16667 - 1
	UBRR = 103 (in integer)
	
	*/
}

void usart_send_string(const char *str) // a function taking string to pass as an argument
{
	while (*str != '\0')  // loop till the end of the string ('\0' character)
	{
		// Wait until the USART Data Register (UDR0) is empty and ready to receive new data
		
		/*
		UCSR0A – USART Control and Status Register 0 A: It contains various flags indicating the status of the USART module.
		
		bits = 
		
		RXCn TXCn UDREn FEn DORn UPEn U2Xn MPCMn
					  -----
					  
		UDRE0 : bit 5 : USART Data Register Empty
		
		The UDREn Flag indicates if the transmit buffer (UDRn) is ready to receive new data. If UDREn is one, the
		buffer is empty, and therefore ready to be written
					  
					  
		(1<<UDRE0) : It indicates whether the transmit buffer (UDR0) is ready to receive new data.
		
		UCSR0A & (1<<UDRE0) : This operation isolates the UDRE flag from the other bits in UCSR0A.
		
		!(UCSR0A & (1<<UDRE0)) :
		If UDRE0 is set (indicating that the transmit buffer is empty),
		this expression evaluates to false (0), and
		if UDRE0 is clear (indicating that the transmit buffer is full),
		it evaluates to true (1).
		
		
		while (! (UCSR0A & (1<<UDRE0)));
		:
		A loop that waits until the UDRE flag in UCSR0A becomes set, indicating that the transmit buffer is empty and ready to receive new data.
		It continuously checks the status of the UDRE flag until it becomes set.
		*/
		
		while (!(UCSR0A & (1 << UDRE0))); // wait until UDR0 is empty
		
		// transmit each character of the string and move to the next character
		UDR0 = *str++;
		
	}
}




int main (void)
{
	usart_init();				//initialize the USART
	
	while(1){					//do forever
		  
		usart_send_string("Hello"); // transmit the string
		_delay_ms(250);   // Delay for 250 milliseconds
	}
	
	return 0;
}


