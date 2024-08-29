/*
 * LED_Pull_up.c
 *
 * Created: 04-05-2024 11.35.17 PM
 * Author : Admin
 */ 


/* Define SFR addresses manually to avoid including avr/io.h.
 * 'volatile' keyword prevents compiler optimization of these accesses. */
#define PORTB *((volatile unsigned char*) 0x25)
#define DDRB *((volatile unsigned char*) 0x24)

int main(void)
{
    /* Configure PB5 as output and set it high to turn on the onboard LED */
    DDRB = 0x20;  // Set PB5 as output
    PORTB = 0x20; // Set PB5 high to turn on LED

    // Infinite loop to keep the LED continuously on
    while(1) {
    }

    return 0;
}


	return 0;
}


