

//SPI with LOOP Back

#include <stdint.h>

#define RCGCGPIO  (*((volatile unsigned long *)0x400FE608))
#define GPIOAFSEL (*((volatile unsigned long *)0x40004420))
#define GPIODEN   (*((volatile unsigned long *)0x4000451c))
#define GPIOPCTL  (*((volatile unsigned long *)0x4000452c))
#define RCGCSSI   (*((volatile unsigned long *)0x400fe61c))
#define SSICR1    (*((volatile unsigned long *)0x40008004))
#define SSICPSR   (*((volatile unsigned long *)0x40008010))
#define SSICR0    (*((volatile unsigned long *)0x40008000))
#define SSISR     (*((volatile unsigned long *)0x4000800c))
#define SSIDR     (*((volatile unsigned long *)0x40008008))
#define GPIODIR   (*((volatile unsigned long *)0x40004400))
#define GPIODATA  (*((volatile unsigned long *)0x40004000))
#define SSICC     (*((volatile unsigned long *)0x40008FC8))
#define GPIOPDR   (*((volatile unsigned long *)0x40004514))


void SPI_init(void)
{
    RCGCSSI  |= 0x1;  // enable spi clock
    RCGCGPIO |= 0x1; // enable gpio clock
    GPIOAFSEL |= 0x3c;  // PA[5:2] alternate
    GPIOPCTL  |= 0x222200; // pctl
    GPIODEN   |= 0x3c;
    GPIOPDR   |= 0x08;
    //pull up is missed
    // ssi config
    SSICR1 &= ~0x02; //disable sse bit
    SSICR1 |= 0x00; // master
    SSICC |=0x0;    //clock mode
    SSICR0 |= 0x07;  //8-bit data frame
    SSICR1 |= 0x03;  // enable and LBM

     }



uint8_t tx (uint8_t data);
uint8_t rx ();


int main(void) {
    uint8_t  DR=0 ;
    uint8_t  REC=0 ;

    SPI_init();

    while (1){

        DR= tx(0xAA);

        REC= rx();
    }


	return 0;
}



uint8_t tx (uint8_t data)
  {  SSIDR = data;
    while((SSISR & 2)==0);  //wait until TNF bit is equal 1
     return SSIDR;
    }

  uint8_t rx ()
  {  uint8_t data =0;
      while((SSISR & 4)== 1);  //wait until RNE bit is equal 0
     data= SSIDR+1;
       return data;
  }

  /*uint8_t SPI_TRSF (uint8_t data)
     {
      SSIDR = data;
      while (!(SSISR & 0x04));
      return SSIDR;
     }*/
