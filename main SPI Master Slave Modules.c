#include "MemMap.h"
#include "SPI.h"


int main (void)
{
	unsigned long i;
	INIT_SPI0();
	INIT_SPI1();

	while(1)
	{
		for(i=0;i<=100;i++)
		{
    SPI_Write(i);
			
		}
	}
	
}