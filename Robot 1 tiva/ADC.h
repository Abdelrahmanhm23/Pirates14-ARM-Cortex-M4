#ifndef ADC_H_
#define ADC_H_

#include <stdint.h>
#include "MemMap.h"
#include "MotorInit.h"

uint32_t ADC0Value[]={0,0,0,0,0,0,0,0};
extern int ls1 ,ls2 , ls3 ,ls4 ,ls5 ,ls6 ,ls7 ,ls8;
extern int VL ;



void init_adc();
void data_get (uint32_t *pt , int i );
void digital_reads(uint32_t *ADC );
void line ();
void VerticalLines();



#endif
