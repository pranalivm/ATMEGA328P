// define macros for memory-mapped registers
#define PranaliIOPort (volatile unsigned char *)0x24  // points to DDRB (Data Direction Register for PORTB)
#define PranaliLEDPort (volatile unsigned char *)0x25 // points to PORTB (controls pin states)


int main(void)
{
    // set pin 13 (PB5) as output by setting the 5th bit of DDRB to 1 (0x20)
    *PranaliIOPort = 0x20;

    // infinite loop
    while(1)
    {
        unsigned long int i = 0, j = 0;  // declare variables for loop counters

        // first loop to turn the LED ON
        for(i; i < 100000; i++)
        {
            *PranaliLEDPort = 0x20;  // set pin 13 (PB5) HIGH (turn ON LED)
        }

        // second loop to turn the LED OFF
        for(j; j < 100000; j++)
        {
            *PranaliLEDPort = 0x00;  // set pin 13 (PB5) LOW (turn OFF LED)
        }
    }
}
