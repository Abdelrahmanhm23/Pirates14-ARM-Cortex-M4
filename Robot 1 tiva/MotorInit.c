
#include <stdint.h>
#include "MemMap.h"
#include "MotorInit.h"


#define EnableUp    0x03 
#define EnableDown  0x01
//void EnableInterrupts(void);  // Enable interrupts
char HIGH = 1 ;
char LOW  = 0;


/*
   Module 1 pwm 2 PA6 genA M9
   Module 1 pwm 3 PA7 genB M10   */
void PWMA_Init()
{
	RCGCGPIO    |=0x01;
	RCGCUART    |=0x01;
	GPIODATA_PORTA  = 0x00;                  // Initialize data register
	GPIOAMSEL_PORTA = 0x00;                 // disable analog 
	/////////////////////Interupts initalization //////////////////////
	GPIOAFSEL_PORTA &= ~0x1C;
	GPIOPCTL_PORTA  &= ~0x000FFF00;     //  configure 2,3,4 as GPIO
	GPIODIR_PORTA   &= ~ 0x1C;    // set direction of 2,3,4 as inputs
	GPIODEN_PORTA   |= 0x1C;      // digital enable for pins 2,3,4
	GPIOIS_PORTA    &= ~0x1C;     // 2,3,4 are edge senstive set to 1 for level
  GPIOIBE_PORTA   &= ~0x1C;    //  2,3,4 is not both edges
  GPIOEV_PORTA     |= 0x1C;     // 2,3,4 are rising edges
	GPIOICR_PORTA    = 0x1C;     // clear flags of 2,3,4
	GPIOIM_PORTA    |= 0x1C;     // arm interrupts for pins 2,3,4
	PRI0 = (PRI0&0xFFFFFF00)|0x000000E0 ; // priority 2 
	EN0  = 1<<0;               // enable interrupts 16
	
	///////////////////////////////////////////////////////////////////
		///////////////////UART////////////////////////////////
	/*RCGCUART |=   0x01;                // activate UART0
	UARTCTL_UART0 &= ~0x00000001;      // disable UART
	UARTIBRD_UART0 = 104 ;             // 16MHz/16=1MHz, 1MHz/104=9600 baud rate
  UARTFBRD_UART0 = 11 ;              // fraction part
	UARTLCRH_UART0 = 0x70;             // 8 bit word length (no parity bits, one stop bit, FIFOs)
	UARTCTL_UART0 &= ~0x301;            // enable UART , TX , RX
	UARTCTL_UART0 |= 0x01;
	
	GPIOAFSEL_PORTA |= 0x03;          // enable alt funct 0,1
	GPIOPCTL_PORTA &= ~0x000000FF;    // initialize pctl
	GPIOPCTL_PORTA |=  0x00000011;    // enable UART2 for 0,1
	GPIODEN_PORTA  |=  0x03;           // digital enable 0,1*/
	//////////////////////////////////////////////////////

	GPIOAFSEL_PORTA |= 0xC0;                // activate alternate function for 6,7
	GPIOPCTL_PORTA  &= ~0xFF000000;         //initialize pctl
	GPIOPCTL_PORTA  |= 0x55000000;          //enable pctl PWMMO pin 6,7
  GPIODIR_PORTA   |= 0x00;                // set direction 
	GPIODEN_PORTA   |= 0xC0;                // digital enable for 6,7
	
	PWM1_CTL_1    = 0x00; 
	PWM1_GENA_1  |= 0x0000008C ;            // M1PWM2 output set when reload clear when match PWM CMP A ch2  PA6
	PWM1_GENB_1  |= 0x0000080C ;            //M1PWM3 output set when reload clear when match PWM CMP B ch3   PA7
	PWM1_LOAD_1   = 3200 ;                    // set frequency to 5khz max freq for driver 
                                          //(16MHz/3200)
	//PWM1_CMPA_1                           // set duty ratio for PA6 
	//PWM1_CMPB_1                           // set duty ratio for PA7
	//PWM1_CTL_1 |=0x01;                     // start timer
	//PWM1_EN |= 0x04;                      // PA6  pin enable
	//PWM1_EN |= 0x08;                      // PA7  pin enable
	
}

/* Module 0 pwm 0 PB6 genA M0
   Module 0 pwm 1 PB7 genB M0
   Module 0 pwm 2 PB4 genA M1
   Module 0 pwm 3 PB5 genB M1   */

void PWMB_Init()
{
 // RCGCPWM  |=0x01;                        // enable clock to PWM0                      
//	RCC      &= ~0x00100000 ;               // don't use pre-divide for PWM clock (default)
	RCGCGPIO |=0x02;                        // activate clock for Port B
	GPIODATA_PORTB   = 0x00;                  // Initialize data register
	GPIOAMSEL_PORTB  = 0x00;                 // disable analog 
	GPIOAFSEL_PORTB |= 0xF0;                // activate alternate function for 4,0,1
	GPIOPCTL_PORTB  &= ~0xFFFF0000;         //initialize pctl
	GPIOPCTL_PORTB  |= 0x44440000;          //enable pctl PWMMO pin 4  4,0,1
  GPIODIR_PORTB   |= 0x0B;                // set direction of 0,1,3 as outputs
	GPIODEN_PORTB   |= 0xFB;                // digital enable for 0,1,3,4,0,1

	PWM0_CTL_0 = 0x00;                      // stop counter  generator 0
	PWM0_CTL_1 = 0x00;                      // stop counter  generator 1
  PWM0_GENA_0  |= 0x0000008C ;            // M0PWM0 output set when reload clear when match PWM CMP A ch0  pB6
	PWM0_GENB_0  |= 0x0000080C ;           // M0PWM1 output set when reload clear when match PWM CMP B ch1  pB7
  PWM0_GENA_1  |= 0x0000008C ;            // M0PWM2 output set when reload clear when match PWM CMP A ch2 PB4
	PWM0_GENB_1  |= 0x0000080C ;            //M0PWM3 output set when reload clear when match PWM CMP B ch3  PB5
	PWM0_LOAD_0  = 3200;                     // set frequency to 5khz max freq for driver
  PWM0_LOAD_1  = 3200;                     //(16MHz/3200)
  //PWM0_CMPA_0                           // set duty ratio for PB6
	//PWM0_CMPB_0                           // set duty ratio for PB7
	//PWM0_CMPA_1                           // set duty ratio for PB4
	//PWM0_CMPB_1                           // set duty ratio for PB5
  //PWM0_CTL_0 |=0x01;                    // start timer
  //PWM0_CTL_1 |=0x01;                    // start timer
	//PWM0_EN |= 0x01;                      // PB6  pin enable
	//PWM0_EN |= 0X02;                      // PB7  pin enable
	//PWM0_EN |= 0x04;                      // PB4  pin enable
	//PWM0_EN |= 0x08;                      // PB5  pin enable
}

/*Module 0 pwm 6 PC4 genA M3
  Module 0 pwm 7 PC5 genB M3      */

void PWMC_Init()
{
//	RCGCPWM  |=0x01;                         // enable clock to PWM0
	RCGCGPIO |=0x04;                         // activate clock for Port C
	GPIODATA_PORTC   = 0x00;                  // Initialize data register
	GPIOAMSEL_PORTC  = 0x00;                  // disable analog 
	GPIOAFSEL_PORTC |= 0x30;                 // activate alternate function for 4,5
	GPIOPCTL_PORTC  &= ~0x00FF0000;          //initialize pctl
	GPIOPCTL_PORTC  |= 0x00440000;           //enable pctl PWMMO pin 4,5  
	GPIODIR_PORTC   |= 0xC0;                 // set direction of 6,7 as outputs
	GPIODEN_PORTC   |= 0xF0;                 // digital enable for 4,5,6,7
	
	PWM0_CTL_3 = 0x00;                      // stop counter  generator 3
  PWM0_GENA_3 |= 0x0000008C ;            // M0PWM6 output set when reload clear when match PWM CMP A ch6
	PWM0_GENB_3 |= 0x0000080C ;            //M0PWM7 output set when reload clear when match PWM CMP B ch7
	PWM0_LOAD_3  = 3200;                   // set frequency to 5khz max freq for driver 
	//PWM0_CMPA_3                           // set duty ratio for PC4
	//PWM0_CMPB_3                           // set duty ratio for PC5
  //PWM0_CTL_3 |=0x01;                    // start timer
	//PWM0_EN |= 0x40;                      // PC4  pin enable
	//PWM0_EN |= 0X80;                      // PC5  pin enable
}


void PWMD_Init()
{
	RCGCGPIO |=0x08;                        // activate clock for Port D
	GPIODATA_PORTD   = 0x00;                  // Initialize data register
	GPIOAMSEL_PORTD  = 0x00;                  // disable analog 
	GPIOAFSEL_PORTD  = 0x00;
	GPIOPCTL_PORTD   = 0x00000000; 
	GPIODIR_PORTD   |= 0x0C;                 // set direction of 2,3 as outputs
	GPIODEN_PORTD   |= 0x0C;                 // digital enable for 2,3
	
	
}

/*Module 0 pwm 4 PC4 genA M2
  Module 0 pwm 5 PC5 genB M2      */
void PWME_Init()
{
//RCGCPWM  |=0x01;                        // enable clock to PWM0
	RCGCGPIO |= 0x10;                        // activate clock for Port E
	GPIODATA_PORTE   = 0x00;                  // Initialize data register
	GPIOAMSEL_PORTE  = 0x00;                  // disable analog 
	GPIOAFSEL_PORTE |= 0x30;                 // activate alternate function for 4,5
	GPIOPCTL_PORTE  &= ~0x00FF0000;          //initialize pctl
	GPIOPCTL_PORTE  |= 0x00440000;           //enable pctl PWMMO pin 4,5  
	GPIODIR_PORTE   |= 0x03;                 // set direction of 0,1 as outputs
	GPIODEN_PORTE   |= 0x33;                 // digital enable for 0,1,4,5

	PWM0_CTL_2 = 0x00;                      // stop counter  generator 3
  PWM0_GENA_2  |= 0x0000008C ;            // M0PWM4 output set when reload clear when match PWM CMP A ch4
	PWM0_GENB_2  |= 0x0000080C ;            //M0PWM5 output set when reload clear when match PWM CMP B ch5
	PWM0_LOAD_2  = 3200;                     // set frequency to 5khz max freq for driver 
  PWM0_LOAD_2  = 3200;                     //(16MHz/3200)
  //PWM0_CMPA_2                      // set duty ratio for PE4
	//PWM0_CMPB_2                           // set duty ratio for PE5
	//PWM0_CTL_2 |=0x01;                      // start timer
	//PWM0_EN |= 0x10;                      // PE4  pin enable
	//PWM0_EN |= 0X20;                      // PE5  pin enable

}



void PortF_Init()
{
		RCGCSSI |= 0x02;             // SPI module 1
		RCGCGPIO |= 0x20;            // clock for PORT F SPI and Slave Select
    /*portf 2, 3 , 0 ,1 
		  clk, ss,rx ,tx */
    GPIODATA_PORTF = 0x0000000000;
    GPIOLOCK_PORTF=0x4C4F434B;        // Port F unlock
	  GPIOCR_PORTF = 0x1F;              // Change dor pin 0
	  GPIOAFSEL_PORTF |= 0xF;           // Alternate function pins select 0,1,2,3
	  GPIODEN_PORTF |= 0x0F;            // Digital enable pins   0,1,2,3
    GPIOPCTL_PORTF &= ~0x0000FFFF ;   // Initialize PCTL
    GPIOPCTL_PORTF |=  0x00002222 ;   // set alternate functions SSI
	  GPIOAMSEL_PORTF = 0x00;           // Disable analog

   	SPI1_SSICR1  &= ~0x02;	     	    // disable SPI	
	  SPI1_SSICR1  |= 0x04;             // choose SLAVE operation
    SPI1_SSICC   &= ~0x0F ;           // configure for system clock/PLL baud clock source
	  SPI1_SSICPSR &= ~0xFF;			      // clock divider for 1 MHz SSIClk 
	 // SPI1_SSICPSR |= 0x16;
	  SPI1_SSICR0  &= ~0xFFC0;	    	  // CPOL & CPHA equal 0  mode 0   scr = 0
    SPI1_SSICR0  &= ~0x30 ;           // Frame select (0,0)
	  SPI1_SSICR0  |= 0x07;             // data = 8
    SPI1_SSICR1  |= 0x02;             // enable SPI 
}


void SysTick_Init(void){
  STCTRL  = 0;                   // disable SysTick during setup
  STRELOAD = 0x003FFFF;          // maximum reload value
  STCURRENT = 0;                 // any write to current clears it
  STCTRL |= 0x03;                 // SysTick with core clock
}




void PWM()
{
  RCGCPWM  |=0x03;                        // enable clock to PWM0 & PWM1
	RCC        &= ~0x00100000 ;               // don't use pre-divide for PWM clock (default)
	PWMA_Init();                            // PWM M9 M10 + Interrupts encoders (2 Mlifter1) (3 Mlifter2) (4 Mlifter3)
	PWMB_Init();                            // PWM M1 M2 M3 M4 + Direction M8 M9 M10  
	PWMC_Init();                            // PWM M7 M8 + Direction M1 M2 
	PWMD_Init();                            // Direction M5 M6 + ADC
	PWME_Init();                            // PWM M5 M6   + Direction M3 M7 + ADC
	PortF_Init();                            // SPI communication slave 
	//analogWrite(Motor1,0);
	SysTick_Init();
}



// ADC Initilaitation 
void init_adc(void)
 {
  /*  
      AIN7  AIN6  AIN1  AIN0
      PD0   PD1   PE2   PE3
  */
 RCGCADC |= 0x1;                //adc0 Module clock clock
 ADCACTSS_ADC0 &=~0x02 ;        // disable SS1 during configartion
 ADCSSPRI_ADC0 |= 0x3201;       // Set the highest piriority for SS1 (the highest pirority 0x0)
 ADCEMUX_ADC0 &= ~0x00F0;       // software trigger for sequencer 1
 ADCSSMUX1_ADC0 &= ~0xFFFF;     // mask register bits
 ADCSSMUX1_ADC0 += 0;
/* 
        if  PE3 - (AIN0) ==>>  (HEX(0x0000)) (DEC(0)) 
   else if  PE2 - (AIN1) ==>>  (HEX(0x0001)) (DEC(1))
   else if  PD0 - (AIN6) ==>>  (HEX(0x0006)) (DEC(6))
   else if  PD1 - (AIN7) ==>>  (HEX(0x0007)) (DEC(7)) 
*/    
 ADCSSCTL1_ADC0 |= 0x0000;      // (0x6) for ending squence and enable interrupt , (0x4) enable interrupt only 
 ADCACTSS_ADC0  |=0x02 ;        // Enable SS1 
 
 }






void analogWrite(int pin,int speed)
{
	if( pin == Motor1)         // single drivers
	{
		PWM0_CMPA_1 = speed;
		PWM0_CTL_1 |= EnableDown;
		PWM0_EN |= 0x04;
		}
	else if(pin == Motor2)    // single drivers
	{  PWM0_CMPB_0=speed;
		PWM0_CTL_0 |= EnableDown;
		PWM0_EN |= 0x02;      }
	else if(pin==Motor3)
	{ PWM0_CMPA_0=speed;
		PWM0_CTL_0 |= EnableDown;
	 	PWM0_EN |= 0x01;     }
	else if(pin==Motor4)     // SERVO
	{   PWM0_CMPB_1 = speed;
		PWM0_CTL_1 |= EnableDown;
		PWM0_EN |= 0x08;      }
	else if(pin==Motor5)
	{   PWM0_CMPA_2 =speed;
		PWM0_CTL_2 |= EnableDown;
		PWM0_EN |= 0x10;      }
	else if(pin==Motor6)
	{   PWM0_CMPB_2 =speed;
		PWM0_CTL_2 |= EnableDown;
		PWM0_EN |= 0X20;      }
	else if(pin==Motor7)
	{   PWM0_CMPA_3 =speed;
		PWM0_CTL_3 |= EnableDown;
		PWM0_EN |= 0x40;      }
	else if(pin==Motor8)
	{ 
		PWM0_CMPB_3 = speed;
		PWM0_CTL_3 |= EnableDown;
		PWM0_EN |= 0X80;      }
	else if(pin==Motor9)
	{ PWM1_CMPA_1 = speed;
		PWM1_CTL_1 |= EnableDown; 
		PWM1_EN |= 0x04;      }
	else if(pin==Motor10)
	{ PWM1_CMPB_1 = speed;
		PWM1_CTL_1 |= EnableDown; 
		PWM1_EN |= 0x08;  
}
}


void digitalWrite(uint32_t pin, char dir)
{
	if(pin==Motor1)
	{  if(dir==1)
	{PE1 |= 0x02;}
	else if (dir==LOW)
	{PE1 &= ~0x02;}
	}
	else if(pin==Motor2)
	{   if(dir==1)
	{PC7 |= 0x80;}
	else if (dir==LOW)
	{PC7 &= ~0x80;}}
	else if(pin==Motor3)
	{
	if(dir==1)
	{PC6 |= 0x40;}
	else if (dir==LOW)
	{PC6 &= ~0x40;}}
	else if(pin==Motor4)  // SERVO
	{if(dir==1)
	{}
	else if (dir==LOW)
	{}  }
	else if(pin==Motor5)
	{if(dir==1)
	{PD2 |= 0x04;}
	else if (dir==0)
	{PD2 &= ~0x04;}}
	else if(pin==Motor6)
	{ if(dir==1)
	{PD3 |= 0x08;}
	else if (dir==0)
	{PD3 &= ~0x08;}}
	else if(pin==Motor7)
	{ if(dir==1)
	{PE0 |= 0x01;}
	else if (dir==0)
	{PE0 &= ~0x01;}}
	else if(pin==Motor8)
	{ if(dir==1)
	{PB3 |= 0x08;}
	else if (dir==0)
	{PB3 &= ~0x08;}}
	else if(pin==Motor9)
	{if(dir==1)
	{PB0 |= 0x01;}
	else if (dir==0)
	{PB0 &= ~0x01;}}
	else if(pin==Motor10)
	{if(dir==1)
	{PB1 |= 0x02;}
	else if (dir==0)
	{PB1 &= ~0x02;}}
}

void MotorStop(int pin)
{
	if( pin == Motor1)
	{ PWM0_EN &= ~0x04; }
	else if(pin == Motor2)
	{ PWM0_EN &= ~0x02;  }
	else if(pin==Motor3)
	{PWM0_EN &= ~0x01;   }
	else if(pin==Motor4)     // SERVO
	{  PWM0_EN &= ~0x08; }
	else if(pin==Motor5)
	{	PWM0_EN &= ~0x10;  }
	else if(pin==Motor6)
	{ PWM0_EN &= ~0X20;  }
	else if(pin==Motor7)
	{ PWM0_EN &= ~0x40;  }
	else if(pin==Motor8)
	{ PWM0_EN &= ~0X80;  }
	else if(pin==Motor9)
	{ PWM1_EN &= ~0x04;  }
	else if(pin==Motor10)
	{ PWM1_EN &= ~0x08;  }
}




