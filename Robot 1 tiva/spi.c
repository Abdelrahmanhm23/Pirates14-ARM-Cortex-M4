#include "spi.h"


//MANUALL MODE

char stop = 0xFF ;
char F = 0x01 ;
char Rev = 0x02;
char L  =0x03;
char R =0x04;
char UR = 0x05;
char UL = 0x06;
char DR = 0x07;
char DL = 0x08;
char CW = 0x09;
char CCW = 0x10;
char ServeStart = 0x11;
char ServeStop = 0x12 ;
char LIFT1_UP =0x25;
char LIFT1_DOWN=0x26;
char LIFT2_UP=0x27;           //R2
char LIFT2_DOWN=0x28;         //L2
char LIFT12_UP = 0x14;        // TRIANGLE
char LIFT12_DOWN = 0x15;      // CROSS
char LIFT3_UP =0x16;          //  CIRCLE
char LIFT3_DOWN = 0x17;        // SQUARE
char LIFTall_UP = 0x18;       // UP
char LIFTall_DOWN = 0x19;     // DOWN
char LIFT_STOP = 0x20;
char servepwm_UP = 0x21 ;     //RIGHT
char servepwm_DOWN = 0x22;    // LEFT

// AUTOMATIC MODE
char POLE3 = 0x14;        // TRIANGLE
char POLE1 = 0x15;        // CROSS
char POLE2 =0x16;         // CIRCLE
char POLE5 = 0x17;        // SQUARE
char POLE4 = 0x18;        // UP
char VERTICAL_LINE = 0x19;  // DOWN
char LINE = 0x21 ;          //RIGHT
char R2=0x27;            // R2



uint32_t ui32Index=0 ;
uint32_t pui32DataRx[NUM_SSI_DATA];

uint32_t ReadData()
{
	 SSIDataGet(SSI1_BASE, &pui32DataRx[ui32Index]);	

if(pui32DataRx[ui32Index]>0x3F &&  pui32DataRx[ui32Index]!=0x61 &&  pui32DataRx[ui32Index]!=0x51 &&  pui32DataRx[ui32Index]!=0x4F &&  pui32DataRx[ui32Index]!=0xFF && pui32DataRx[ui32Index]!=0x41  && pui32DataRx[ui32Index]!=0x47  && pui32DataRx[ui32Index]!=0x49 && pui32DataRx[ui32Index]!=0x43 && pui32DataRx[ui32Index]!=0x45)
{
	pui32DataRx[ui32Index]=(pui32DataRx[ui32Index] &= 0xFF )<< 1;
	pui32DataRx[ui32Index]&= 0xFE;
}
else if (pui32DataRx[ui32Index]==0xFF)
{
	pui32DataRx[ui32Index]= (pui32DataRx[ui32Index] &= 0xFF) ;
}
else{
	pui32DataRx[ui32Index]=(pui32DataRx[ui32Index] &= 0xFF )>> 1;
}
	pui32DataRx[ui32Index]=(pui32DataRx[ui32Index] &= 0xFF );
  return ( pui32DataRx[ui32Index] );
} 	