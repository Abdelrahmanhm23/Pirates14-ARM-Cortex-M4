#include "SPI.h"
#include "MemMap.h"

unsigned long z=0;
/*
	SPIO Module Master
	portA 2,3,5 used (clk,ss,TX)
	portA 6,7 used for Nokia lcd Reset and CD
	
	*/
void INIT_SPI0(void)
{ volatile unsigned long delay;
	RCGCSSI  |= 0x01;    // SPI module 0
	RCGCGPIO |= 0x01;    // clock for PORT A SPI and Slave Select
    delay=RCGCGPIO;

	/*portA 2 ,  3 , 4 , 5   
		   clk, ss , rx, tx */
 
    GPIODATA_PORTA   = 0x0000000000;
	GPIODIR_PORTA    =0xC0;               // PA 6,7 output 
	GPIOAFSEL_PORTA |= 0x2C;              // Alternate function pins select 2,3,5
	GPIOAFSEL_PORTA &= ~0xC0;             // Disable Alternate function pins 6,7
	GPIODEN_PORTA   |= 0xEC;              // Digital enable pins 2,3,5,6,7
    GPIOPCTL_PORTA  &= ~0x00F0FF00 ;      // Initialize PCTL
    GPIOPCTL_PORTA  |=  0x00202200 ;      // set alternate functions SSI
	GPIOAMSEL_PORTA  = 0x00;              // Disable analog
	
    SPI0_SSICR1     &= ~0x02;	      	 // disable SPI	
	SPI0_SSICR1     &= ~0x04;            // choose master operation
    SPI0_SSICC      &= ~0x0F ;           // configure for system clock/PLL baud clock source
	SPI0_SSICPSR    &= ~0xFF;			 // clock divider for 3.125 MHz SSIClk (50 MHz PIOSC/16)
	SPI0_SSICPSR    |= 0x16;
	SPI0_SSICR0     &= ~0xFFC0;	         // CPOL & CPHA equal 0  mode 0   scr = 0
    SPI0_SSICR0     &= ~0x30 ;           // Frame select (0,0)
	SPI0_SSICR0     |= 0x07;             // data = 8
	SPI0_SSICR1     |= 0x02;             // enable SPI   
}
/*
SPI1 Module Slave
portF 2,3,0 (clk,ss,RX)

*/
void INIT_SPI1(void)
{ volatile unsigned long delay;
		RCGCSSI |= 0x02;             // SPI module 1
		RCGCGPIO |= 0x20;            // clock for PORT F SPI and Slave Select
        delay=RCGCGPIO;
    /*portf 2, 3 , 0 ,1 
		  clk, ss,rx ,tx */
        GPIODATA_PORTF = 0x0000000000;
        GPIOLOCK_PORTF=0x4C4F434B;        // Port F unlock
	    GPIOCR_PORTF = 0x1F;              // Change dor pin 0
	
	    GPIOAFSEL_PORTF |= 0xF;           // Alternate function pins select 2,3,0
	    GPIODEN_PORTF |= 0x0F;            // Digital enable pins   2,3,0
    	GPIOPCTL_PORTF &= ~0x0000FFFF ;   // Initialize PCTL
        GPIOPCTL_PORTF |=  0x00002222 ;   // set alternate functions SSI
	    GPIOAMSEL_PORTF = 0x00;           // Disable analog

     	SPI1_SSICR1  &= ~0x02;	     	  // disable SPI	
	    SPI1_SSICR1  |= 0x04;             // choose SLAVE operation
        SPI1_SSICC   &= ~0x0F ;           // configure for system clock/PLL baud clock source
	    SPI1_SSICPSR &= ~0xFF;			  // clock divider for 3.125 MHz SSIClk (50 MHz PIOSC/16)
	    SPI1_SSICPSR |= 0x16;
	    SPI1_SSICR0  &= ~0xFFC0;	   	  // CPOL & CPHA equal 0  mode 0   scr = 0
        SPI1_SSICR0  &= ~0x30 ;           // Frame select (0,0)
	    SPI1_SSICR0  |= 0x07;             // data = 8
	    SPI1_SSICR1  |= 0x02;             // enable SPI  
}
/*
SPI write function sending data to slave
*/
int SPI_Write(unsigned char data)
{
	unsigned char x[10];
	unsigned char y[10] ;
	DC=0x40;
	while((SPI0_SSISR & 2) == 0);     // wait until FIFO not full
	SPI0_SSIDR =data ;                // Transmit high byte
	x[z]=SPI1_SSIDR ;                 // Matrix to check data sent 
	while(SPI0_SSISR & 0x10);         // wait transmit complete 
	//y[z]=SPI1_SSIDR ;
	if(z<=9)
	{
	z++;
	}
return SPI0_SSIDR ;
}

void SPI_Read()
{
	 int x =0 ;
while((SPI1_SSISR & 4) == 0);         //wait until FIFO is not empty  
x=SPI1_SSIDR ;
}



