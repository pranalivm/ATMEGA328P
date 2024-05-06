volatile  char* IOPortB = (char*)0x24;
volatile char* LEDPortB = (char*)0x25;

int main(void) {
  *IOPortB = 0x20 ;


  while(1) {

       *LEDPortB = 0x00 ;
    for(unsigned long long int i=0 ; i < 100000 ; i++) {
          *LEDPortB = 0x00 ;
;
    }
    *LEDPortB = 0x20 ;
    for(unsigned long long int i=0 ; i <100000 ; i++) {
          *LEDPortB = 0x20 ;

    }
 
  }

}