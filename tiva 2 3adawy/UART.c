#include "UART.h"

void UART_OutChar(unsigned char data){
  while((UARTFR_UART0& 0x00000020) != 0);
  UARTDR_UART0 = data;
}


void UART_OutString(char *pt){
  while(*pt){
    UART_OutChar(*pt);
    pt++;
  }
}
