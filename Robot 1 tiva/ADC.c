	#include <stdint.h>

#include "ADC.h"

// passing an array to this function and its size to get the ADC FIFO's data 
// data_get(array_name , size of the array) 
// EX : data_get (ADCValue , 4);

void data_get (int *pt , int i )
   {
     int k;
     ADCPSSI_ADC0 = 0x0010;    // start sampling (SS1)
     while((ADCRIS_ADC0 &0x02)==0){};  // wait untill sampling is done (for SS1)
      //get SS FIFO values
     for(k=0 ; k<i ; k++)
       {
        *(pt+k) = ADCSSFIFO1_ADC0 &0xFFF;
       }
      ADCISC_ADC0 = 0x0010;   // set interrupt flag for SS1 
   }
