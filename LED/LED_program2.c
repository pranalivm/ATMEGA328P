// define volatile pointers to the portb registers
volatile char* IOPORTB = (char*)0x24;   // points to the data direction register of PORTB (DDRB)
volatile char* LEDPORTB = (char*)0x25;  // points to the PORTB register (controls pin states)

// main function that runs indefinitely
int main(void) {

  // set pin 13 (PB5) as output by setting the 5th bit of DDRB to 1 (0x20)
  *IOPORTB = 0x20;

  // infinite loop
  while(1) {

    // turn off LED by setting pin 13 (PB5) to LOW (0x00)
    *LEDPORTB = 0x00;

    // delay loop to keep the LED off for a while
    for(unsigned long long int i = 0; i < 100000; i++) {
      *LEDPORTB = 0x00;  // ensure LED stays off during the delay
    }

    // turn on LED by setting pin 13 (PB5) to HIGH (0x20)
    *LEDPORTB = 0x20;

    // delay loop to keep the LED on for a while
    for(unsigned long long int i = 0; i < 100000; i++) {
      *LEDPORTB = 0x20;  // ensure LED stays on during the delay
    }

  }

}
