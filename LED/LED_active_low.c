

/* Define SFR (Special Function Register) addresses manually
 * to avoid including the standard avr/io.h header file.
 * 'volatile' keyword ensures the compiler does not optimize 
 * the access to these registers, as their values may change
 * asynchronously due to hardware events. */
#define PORTC *((volatile unsigned char*) 0x28)
#define DDRC *((volatile unsigned char*) 0x27)

int main(void)
{
    /* Set PC0 (Port C, bit 0) as an output pin.
     * In the DDRC register, setting a bit to 1 configures it as an output. 
     * DDRC = 0x01 means that only PC0 is set as output (0000 0001 in binary). */
    DDRC = 0x01;

    /* Set PC0 to LOW (0) to turn on the LED.
     * In the PORTC register, setting a bit to 0 provides a logic LOW signal
     * to the corresponding pin, which in an active-low configuration, turns on the LED. */
    PORTC = 0x00;

    /* Infinite loop to keep the LED continuously on.
     * The program will stay in this loop indefinitely, ensuring the LED remains lit. */
    while(1) {
    }

    /* The return statement here is never reached as the while loop is infinite.
     * It’s included for completeness and follows the standard main function signature. */
    return 0;
}
