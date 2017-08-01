#ifndef UART_H_
#define UART_H_
#include "MemMap.h"
#include "MotorInit.h"

void UART_OutChar(unsigned char data);
void UART_OutString(char *pt);

#endif /*UART_H_*/