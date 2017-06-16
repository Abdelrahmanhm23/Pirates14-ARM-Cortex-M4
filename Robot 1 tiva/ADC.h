#ifndef ADC_H_
#define ADC_H_

#include <stdint.h>
#include "MemMap.h"
#include "MotorInit.h"

uint32_t ADC0Value[]={0,0,0,0,0,0,0,0};
int ls1 ,ls2 , ls3 ,ls4 ,ls5 ,ls6 ,ls7 ,ls8;




void init_adc();
void data_get (int *pt , int i );
void digital_reads(uint32_t *ADC );
void line (int error);



#endif