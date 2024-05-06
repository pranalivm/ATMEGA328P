#define PranaliIOPort (volatile unsigned char *)0x24
#define PranaliLEDPort (volatile unsigned char *)0x25

int main(void)
{
	*PranaliIOPort = 0x20;
	
	
	while(1)
	{
		unsigned long int i = 0, j = 0;
	
		for(i; i < 100000; i++)
		{
			*PranaliLEDPort = 0x20;
		}
		
		for(j; j < 100000; j++)
		{
			*PranaliLEDPort = 0x00;
		}
	}
}
	