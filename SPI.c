#include "SPI.h"
#include "MemMap.h"

void INIT_SPI(void)
{
	RCGCSSI |= 0x01;    // SPI module 0

	SPI0_SSICR1 &= ~0x02;		// disable SPI
	SPI0_SSICR0 &= ~0xFFC0;			// CPOL & CPHA equal 0  mode 0   scr = 0
	SPI0_SSICPSR |= 0x02;				// frequency 8MHZ
	SPI0_SSICR0 |= 0x07;      // data = 8
	SPI0_SSICR1 &= ~0x04;           // choose master operation



	SPI0_SSICR1 |= 0x03;   // enable SPI   loop back enabled
}
