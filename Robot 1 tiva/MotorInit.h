#ifndef MOTORINIT_H_
#define MOTORINIT_H_

#include <stdint.h>
#include "MemMap.h"

#define Motor1  1
#define Motor2  2         
#define Motor3  3      
#define Motor4  4          
#define Motor5  5           
#define Motor6  6         
#define Motor7  7            
#define Motor8  8            
#define Motor9  9       
#define Motor10 10 
#define ServeMotorCW 11
#define ServeMotorCCW 12
#define ServePiston 13
#define Motor3Piston 14
extern char HIGH ;
extern char LOW ;


void PWMA_Init();
void PWMB_Init();
void PWMC_Init();
void PWMD_Init();
void PWME_Init();
void ADCB_Init();
void ADCC_Init();
void ADCD_Init();
void ADCE_Init();
void PortF_Init();
void Timer4(void);
void SysTick_Init(void);
int  SysTick_time();
void TIVA1();
void TIVA2();
void analogWrite(int pin,int speed);
void digitalWrite(uint32_t pin, char dir);
void MotorStop(int pin);
void init_adc_3pins();
void init_adc_8pins();
void init_adc_2pins();
void delayUs(int n);

#endif /* MOTORINIT_H_*/
