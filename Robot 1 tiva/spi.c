#include "spi.h"
uint32_t ui32Index=0 ;
uint32_t pui32DataRx[NUM_SSI_DATA];

uint32_t ReadData()
{
	 SSIDataGet(SSI1_BASE, &pui32DataRx[ui32Index]);	
	
if(pui32DataRx[ui32Index]>0x3F &&  pui32DataRx[ui32Index]!=0xFF && pui32DataRx[ui32Index]!=0x41 && pui32DataRx[ui32Index]!=0x43 && pui32DataRx[ui32Index]!=0x45)
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