
#ifndef SERVE_H_
#define SERVE_H_

#include "MemMap.h"
#include "MotorInit.h"
#include "Motion.h"
#include "spi.h"
#include "ADC.h"
extern unsigned long State ;


void Serve();
void GPIOD_Handler(void);

#endif