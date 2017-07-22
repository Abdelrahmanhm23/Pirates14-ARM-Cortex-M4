#ifndef ENCODERS_H_
#define ENCODERS_H_
#include <stdio.h>  
#include <math.h>
#include <string.h>  
#include "MemMap.h"
#include "MotorInit.h"

#define SINGLE_POLE_FILTER_A0 0.4
#define SINGLE_POLE_FILTER_B1 1
#define SINGLE_POLE_C 1

extern unsigned long Mlifter1counter ;
extern unsigned long Mlifter2counter ;
extern unsigned long Mlifter3counter ;
extern unsigned long MServecounter ;

extern unsigned long RPM_ML1 ;
extern unsigned long RPM_ML2 ;
extern unsigned long RPM_ML3 ;
extern unsigned long RPM_MServe ;

extern unsigned long prev1;
extern unsigned long prev2 ;
extern unsigned long prev3 ;
extern unsigned long prevMserve ;

extern unsigned long counts1  ;
extern unsigned long counts2  ;
extern unsigned long counts3  ;
extern unsigned long countsMserve  ;

extern unsigned long prev_counts1  ;
extern unsigned long prev_counts2  ;
extern unsigned long prev_counts3  ;
extern unsigned long prev_Mservecounts  ;

float singlePoleFilter(const int current, int prev_val);
void GPIOA_Handler(void);
void SysTick_Handler();
int Hex2Dec(char hexadecimal[30]);
#endif /* ENCODERS_H_ */
