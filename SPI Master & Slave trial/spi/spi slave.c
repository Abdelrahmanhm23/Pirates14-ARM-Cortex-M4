#include "MemMap.h"


#include <stdbool.h>
#include <stdint.h>
#include "inc/hw_memmap.h"
#include "driverlib/gpio.h"
#include "driverlib/pin_map.h"
#include "driverlib/ssi.h"
#include "driverlib/sysctl.h"
#include "driverlib/uart.h"
#include "utils/uartstdio.h"

#define SCB_R                   (*((volatile unsigned long *) 0xE000ED88))


void INIT_SPI0(void)
{volatile unsigned long delay;
	RCGCSSI  |= 0x01;    // SPI module 0
	RCGCGPIO |= 0x01;    // clock for PORT A SPI and Slave Select
    delay=RCGCGPIO;

	/*portA 2 ,  3 , 4 , 5   
		   clk, ss , rx, tx */
 
    GPIODATA_PORTA   = 0x0000000000;
	//GPIODIR_PORTA   |= 0x08;               // PA 3 output 
	GPIOAFSEL_PORTA |= 0x3C;              // Alternate function pins select 2,4,5
	//GPIOAFSEL_PORTA &= ~0x08;             // Disable Alternate function pins 3
    GPIOPCTL_PORTA  &= ~0x00FFFF00 ;      // Initialize PCTL
    GPIOPCTL_PORTA  |=  0x00222200 ;      // set alternate functions SSI
	GPIOAMSEL_PORTA  = 0x00;              // Disable analog
		GPIODEN_PORTA   |= 0x3C;              // Digital enable pins 2,3,5,6,7

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
#define NUM_SSI_DATA            3
    uint32_t pui32DataTx[NUM_SSI_DATA];
    uint32_t pui32DataRx[NUM_SSI_DATA];
    uint32_t pui32DataTx2[4];
    uint32_t pui32DataRx2[NUM_SSI_DATA];
    uint32_t ui32Index =0 ;
    uint32_t pui32Data[200];
int i;
int main(void)
{
	//INIT_SPI0();
	INIT_SPI1();
	 /* pui32DataTx[0] = 's';
    pui32DataTx[1] = 'p';
    pui32DataTx[2] = 'i';
		
		 pui32DataTx2[0] = '0';
				 pui32DataTx2[0] = 'K';
    pui32DataTx2[1] = 'a';
    pui32DataTx2[2] = 'i';
		 while(SSIDataGetNonBlocking(SSI0_BASE, &pui32DataRx[0]))
    {
    }
	
		 for(ui32Index = 0; ui32Index < NUM_SSI_DATA; ui32Index++)
    {
        SSIDataPut(SSI0_BASE, pui32DataTx[ui32Index]);
			while(SSIBusy(SSI0_BASE))
    {
    }
        SSIDataGet(SSI1_BASE, &pui32DataRx2[ui32Index]);
        pui32DataRx2[ui32Index] &= 0x00FF;
	
    }
	while(1)
	{

		if(pui32DataRx2[2]==0x69)
		{
				
			 for(ui32Index = 0; ui32Index < 3; ui32Index++)
    {
				SSIDataPut(SSI0_BASE, 0x00);	
        SSIDataPut(SSI1_BASE, pui32DataTx2[ui32Index]);
			SSIDataGet(SSI0_BASE, &pui32DataRx[ui32Index]);
        pui32DataRx[ui32Index] &= 0x00FF;

}
		if(pui32DataRx[0]==0x4B)
{break;}
	}
		
	}*/
	
		while(1)
	{
		    SSIDataGet(SSI1_BASE, &pui32DataRx2[ui32Index]);
     pui32DataRx2[ui32Index]=(   pui32DataRx2[ui32Index] &= 0x00FF )>> 1 ;

		if(pui32DataRx2[ui32Index]==0x03)
{break;}
		
	}
	  return(0);
	
}

void SystemInit(void)
{
/* Grant coprocessor access */
/* This is required since TM4C123G has a floating point coprocessor */
 SCB_R |= 0x00f00000;
}