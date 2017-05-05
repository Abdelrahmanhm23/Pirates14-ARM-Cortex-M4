#ifndef SPI_H_
#define SPI_H_
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
#define NUM_SSI_DATA            1
   extern uint32_t pui32DataTx[NUM_SSI_DATA];
   extern uint32_t pui32DataRx[NUM_SSI_DATA];
   extern uint32_t ui32Index  ;
/*
stop              (0xAA)
forward           (0x01)
reverse           (0x02)
left              (0x03)
right             (0x04)
upright           (0x05)
upleft            (0x06)
downright         (0x07)
downleft          (0x08)
ClockWise         (0x09)
CounterClockWise  (0x10)
serve start       (0x11)
serve end         (0x12)
servo             (0x13)
lifter1,2         (0x14)            
lifter3           (0x15)
*/
  
uint32_t ReadData() ;

#endif
