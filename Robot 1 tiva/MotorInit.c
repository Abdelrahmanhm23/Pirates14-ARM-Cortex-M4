
#include <stdint.h>
#include "MemMap.h"
#include "MotorInit.h"


#define EnableUp    0x03 
#define EnableDown  0x01
//void EnableInterrupts(void);  // Enable interrupts
char HIGH = 1 ;
char LOW  = 0;

/*/////////     TO WORK WITH ONE TIVA CHANGE VALUS IN digitalWrite
///// TIVA 2 PC6 -- PD2 for one tiva
///// TIVA 2 PC7 -- PD3 for one tiva
///// TIVA 2 PB0 -- PE0 for one tiva
///// TIVA 2 PB1 -- PB3 for one tiva
*/
/*
   Module 1 pwm 2 PA6 genA M9
   Module 1 pwm 3 PA7 genB M10   */
	 // PortA encoder 2,3,4,5  pwm 6,7
void PWMA_Init()
{
	RCGCGPIO    |=0x01;
	//RCGCUART    |=0x01;
	GPIODATA_PORTA  &= ~0xFC;                  // Initialize data register
	GPIOAMSEL_PORTA &= ~0xFC;                 // disable analog 
	/////////////////////Interupts initalization //////////////////////
	GPIOAFSEL_PORTA &= ~0x3C;
	GPIOPCTL_PORTA  &= ~0x00FFFF00;     //  configure 2,3,4,5 as GPIO
	GPIODIR_PORTA   &= ~ 0x3C;    // set direction of 2,3,4 as inputs
	GPIODR8R_PORTA |= 0xFF;
	GPIOSLR_PORTA   |= 0x3C;
	GPIOPUR_PORTA   |= 0xFC;      // pullup registers
	GPIODEN_PORTA   |= 0x3C;      // digital enable for pins 2,3,4,5
	
	GPIOIS_PORTA    &= ~0x3C;     // 2,3,4,5 are edge senstive set to 1 for level
  GPIOIBE_PORTA   &= ~0x3C;    //  2,3,4,5 is not both edges
  GPIOEV_PORTA     &= ~0x3C;     // 2,3,4,5 are rising edges
	GPIOICR_PORTA    = 0x3C;     // clear flags of 2,3,4,5
	GPIOIM_PORTA    |= 0x1C;     // arm interrupts for pins 2,3,4 
	PRI0 = (PRI0&0xFFFFFF00)|0x000000F0 ; // priority 5 
	EN0  = 1<<0;               // enable interrupts 16
	
	/*
	
		GPIOIS_PORTA    &= ~0x1C;     // 2,3,4,5 are edge senstive set to 1 for level
  GPIOIBE_PORTA   &= ~0x1C;    //  2,3,4,5 is not both edges
  GPIOEV_PORTA     &= ~0x1C;     // 2,3,4,5 are rising edges
	GPIOICR_PORTA    = 0x1C;     // clear flags of 2,3,4,5
	GPIOIM_PORTA    |= 0x1C;     // arm interrupts for pins 2,3,4 
	PRI0 = (PRI0&0xFFFFFF00)|0x000000F0 ; // priority 5 
	EN0  = 1<<0;               // enable interrupts 16
	
	
	*/
	
	
	
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
	GPIODR8R_PORTA |= 0x3C;
	GPIOSLR_PORTA  |= 0x3C;
	GPIOPUR_PORTA |=0x3C;
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

/* Module 0 pwm 0 PB6 genA M0  Motor3
   Module 0 pwm 1 PB7 genB M0  Motor2 
   Module 0 pwm 2 PB4 genA M1  Motor1
   Module 0 pwm 3 PB5 genB M1  Motor4*/
// PortB dir 0,1,3     PWM 4,5,6,7
void PWMB_Init()
{
 // RCGCPWM  |=0x01;                        // enable clock to PWM0                      
//	RCC      &= ~0x00100000 ;               // don't use pre-divide for PWM clock (default)
	RCGCGPIO |=0x02;                        // activate clock for Port B
	GPIODATA_PORTB   &= ~0xFB;                  // Initialize data register
	GPIOAMSEL_PORTB  &= ~0xFB;                 // disable analog 
	GPIOAFSEL_PORTB &= ~0x0B;                // disable 0,1,3
	GPIOAFSEL_PORTB |= 0xF0;                 // activate alternate function for 4,5,6,7
	GPIOPCTL_PORTB  &= ~0xFFFF0000;         //initialize pctl
	GPIOPCTL_PORTB  |= 0x44440000;          //enable pctl PWMMO pin 4,5,6,7
  GPIODIR_PORTB   |= 0x0B;                // set direction of 0,1,3 as outputs
	GPIODR8R_PORTB  |= 0xFB;
	GPIOPUR_PORTB   |= 0xFB;                // pull down resistors
	GPIODEN_PORTB   |= 0xFB;                // digital enable for 0,1,3,4,5,6,7

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

/*Module 0 pwm 6 PC4 genA M3  Motor7
  Module 0 pwm 7 PC5 genB M3  Motor8    */
// PortC dir 6,7 PWM 4,5
void PWMC_Init()
{
//	RCGCPWM  |=0x01;                         // enable clock to PWM0
	RCGCGPIO |=0x04;                         // activate clock for Port C
	GPIODATA_PORTC  &= ~0xF0;                  // Initialize data register
	GPIOAMSEL_PORTC &= ~0xF0;                  // disable analog 
	GPIOAFSEL_PORTC |= 0x30;                 // activate alternate function for 4,5
	GPIOPCTL_PORTC  &= ~0x00FF0000;          //initialize pctl
	GPIOPCTL_PORTC  |= 0x00440000;           //enable pctl PWMMO pin 4,5  
	GPIODIR_PORTC   |= 0xC0;                 // set direction of 6,7 as outputs
	GPIODR8R_PORTC  |= 0xF0;
	GPIOPUR_PORTC   |= 0xF0; 
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

// PortD 0 sensor 1 analog 2,3 dir 6,7 relays
void PWMD_Init()      // 0 analog 1 input  2,3,6,7 output
{
	RCGCGPIO |=0x08;                        // activate clock for Port D
	GPIODATA_PORTD   &= ~0xCF;                  // Initialize data register
	GPIOLOCK_PORTD = 0x4C4F434B ;              // unlock port D
	GPIOCR_PORTD = 0x80 ;                      // allow changes to 
	GPIOAFSEL_PORTD &= ~0xCE;                 // disable 0,2,3,6,7 alternate functions
	GPIOAMSEL_PORTD &= ~0xCE;                 // disable analog functions  0,2,3,6,7
	GPIODIR_PORTD   &= ~0x02;                 // set direction of 0 as input
	GPIODIR_PORTD   |= 0xCC;                  // set direction of 2,3,6,7 as outputs
	GPIOAFSEL_PORTD |= 0x01;                 // enable alternate function pin 0
	GPIODEN_PORTD   &= ~0x01;                 // disable digital pin 0
	GPIOAMSEL_PORTD  |= 0x01;                  // enable analog pin 0
	GPIODR8R_PORTD |= 0xCF;
	GPIOPUR_PORTD |=0xCE;
	GPIODEN_PORTD   |= 0xCE;                  // digital enable for 0,2,3,6,7
	  RCGCADC |= 0x01;                       // enable clock to ADC 
}

/*Module 0 pwm 4 PC4 genA M2 Motor5
  Module 0 pwm 5 PC5 genB M2 Motor6    */
// PortE 0,1 dir 2,3 analog 4,5 PWM
void PWME_Init()
{
//RCGCPWM  |=0x01;                        // enable clock to PWM0
	RCGCGPIO |= 0x10;                        // activate clock for Port E
	GPIODATA_PORTE   &= ~0x3F;                  // Initialize data register
	GPIOAMSEL_PORTE  &= ~0x33;                  // disable analog 
	GPIOAFSEL_PORTE |= 0x3C;                 // activate alternate function for 2,3,4,5
	GPIOPCTL_PORTE  &= ~0x00FF0000;          //initialize pctl
	GPIOPCTL_PORTE  |= 0x00440000;           //enable pctl PWMMO pin 4,5 
  GPIODEN_PORTE   &= ~0x0C;                 // digital disable for 2,3	GPIOAMSEL_PORTE |= 0x0C;	               // enable analog function for 2,3
	GPIODIR_PORTE   |= 0x03;                 // set direction of 0,1 as outputs
	GPIODR8R_PORTE |= 0x3C;
	GPIOPUR_PORTE |=0x33;
	GPIODEN_PORTE   |= 0x33;                 // digital enable for 0,1,4,5
	  RCGCADC |= 0x01; 

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


///////////////////ADC TIVA 2/////////////////
 void ADCB_Init()  // B0 dir M7 B1 dir M8 b6 b7 input interrupts   4,5 analog
{
  RCGCGPIO |=0x02;                        // activate clock for Port B
	//  RCGCADC |= 0x01;                       // enable clock to ADC 

	GPIODATA_PORTB   &= ~0xF3;                  // Initialize data register
	GPIOAMSEL_PORTB &= ~0xC3;                 // disable analog 
	GPIOAFSEL_PORTB &= ~0xC3;                // disable alternate function for 0,1,6,7
	GPIOPCTL_PORTB  &= ~0x00000000;         //initialize pctl
  GPIODIR_PORTB   |= 0x03;                // set direction of 0,1 as outputs
  GPIODIR_PORTB   &= ~ 0xC0;              // set direction of 6,7 as inputs
		GPIOAFSEL_PORTB |= 0x30;                // enable alternate function for 4,5
	GPIODEN_PORTB   &= ~0x30;                // digital disable for 4,5
	//GPIOAMSEL_PORTB |= 0x30;                 // enable analog function for 4,5
	GPIODEN_PORTB   |= 0xC3;                // digital enable for 0,1,6,7
	
	/*
	GPIOIS_PORTB    &= ~0xC0;     // 0 are edge senstive set to 1 for level
  GPIOIBE_PORTB   &= ~0xC0;    //  0 is not both edges
  GPIOEV_PORTB     |= 0xC0;     // 0 are rising edges
	GPIOICR_PORTB    = 0xC0;     // clear flags of 0
	GPIOIM_PORTB    |= 0xC0;     // arm interrupts for pins 0
	PRI0 = (PRI0&0xFFFF00FF)|0x0000A000 ; // priority 5
	EN0  = 1<<1;               // enable interrupts 16*/
}

	void ADCC_Init() // C4 PWM M7 C5 PWM M8 C6 dir M5  C7 dir DIR M6
{
//	RCGCPWM  |=0x01;                         // enable clock to PWM0
	RCGCGPIO |=0x04;                         // activate clock for Port C
	GPIODATA_PORTC  &= ~0xF0;                  // Initialize data register
	GPIOAMSEL_PORTC &= ~0xF0;                   // disable analog 
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

	void ADCD_Init() // ADC init 0,1,2,3
{
RCGCGPIO |=0x08;                        // activate clock for Port D
	//  RCGCADC |= 0x01;                       // enable clock to ADC 

	GPIODATA_PORTD   &= ~0x0F;                  // Initialize data register
	GPIOLOCK_PORTD = 0x4C4F434B ;           // unlock port d
	//GPIOAFSEL_PORTD  |= 0x0F;               // enable alternate function pin 1
	//GPIOAMSEL_PORTD  |= 0x0F;                  // enable analog pin 1
	GPIOPCTL_PORTD   = 0x00000000; 
	//GPIODEN_PORTD   |= 0x0F;                 // digital enable for 0,1,2,3
	
	}

	void ADCE_Init() // ADC init E4 PWM M5 E5 PWM M6
{
	//RCGCPWM  |=0x01;                        // enable clock to PWM0
	RCGCGPIO |= 0x10;                        // activate clock for Port E
	// RCGCADC |= 0x01;                       // enable clock to ADC 
	GPIODATA_PORTE   &= ~0x3F;                  // Initialize data register
  GPIOAFSEL_PORTE |= 0x3F;                 // activate alternate function for 4,5
  //GPIOAMSEL_PORTE  |= 0x0F;                  // enable analog pin 0,1,2,3
	GPIOPCTL_PORTE  &= ~0x00FF0000;          //initialize pctl
	GPIOPCTL_PORTE  |= 0x00440000;           //enable pctl PWMMO pin 4,5 
	//GPIODIR_PORTE   |= 0x30;                 // set direction of 0,1 as outputs
	GPIODEN_PORTE   |= 0x30 ;                 // digital en3able for 0,1,2,3,4,5

	
	PWM0_CTL_2 = 0x00;                      // stop counter  generator 3
  PWM0_GENA_2  |= 0x0000008C ;            // M0PWM4 output set when reload clear when match PWM CMP A ch4
	PWM0_GENB_2  |= 0x0000080C ;            //M0PWM5 output set when reload clear when match PWM CMP B ch5
	PWM0_LOAD_2  = 3200;                     // set frequency to 5khz max freq for driver 
  // PWM0_LOAD_2  = 3200;                     //(16MHz/3200)
  //PWM0_CMPA_2                      // set duty ratio for PE4
	//PWM0_CMPB_2                           // set duty ratio for PE5
	//PWM0_CTL_2 |=0x01;                      // start timer
	//PWM0_EN |= 0x10;                      // PE4  pin enable
	//PWM0_EN |= 0X20;                      // PE5  pin enable
}

////////////////////////////////////////////////
// PortF SPI Communication 4 relay
void PortF_Init()
{
		RCGCSSI |= 0x02;             // SPI module 1
		RCGCGPIO |= 0x20;            // clock for PORT F SPI and Slave Select
    /*portf 2, 3 , 0 ,1 
		  clk, ss,rx ,tx */
    GPIODATA_PORTF = 0x0000000000;
    GPIOLOCK_PORTF=0x4C4F434B;        // Port F unlock
	  GPIOCR_PORTF = 0x1F;              // allow changes to 0 and 4
	  GPIOAFSEL_PORTF |= 0xF;           // Alternate function pins select 0,1,2,3
		GPIODIR_PORTF   |= 0x10;          // set direction of 4 as output
	  GPIODEN_PORTF |= 0x1F;            // Digital enable pins   0,1,2,3,4
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
  STRELOAD = 0x003FFFF;          // maximum reload value 0.2
  STCURRENT = 0;                 // any write to current clears it
  STCTRL |= 0x03;                 // SysTick with core clock
}




void TIVA1()  // initialization of tiva 1 (lifters,encoders,3pins ADC,Serve)
{
RCGCGPIO |=0x3F;
	  RCGCPWM  |=0x03;                        // enable clock to PWM0 & PWM1
	RCC        &= ~0x00100000 ;               // don't use pre-divide for PWM clock (default)
	PWMA_Init();                            // PWM M9 M10 + Interrupts encoders (2 Mlifter1) (3 Mlifter2) (4 Mlifter3)
	PWMB_Init();                            // PWM M1 M2 M3 M4 + Direction M8 M9 M10  
	PWMC_Init();                            // PWM M7 M8 + Direction M1 M2 
	PWMD_Init();                            // Direction M5 M6 + ADC
	PWME_Init();                            // PWM M5 M6   + Direction M3 M7 + ADC
	PortF_Init();                            // SPI communication slave 
	//	init_adc_3pins();
	SysTick_Init();
		digitalWrite(ServePiston,LOW);
digitalWrite(ServeMotorCW,LOW);
digitalWrite(ServeMotorCCW,LOW);
	digitalWrite(Motor3Piston,HIGH);
}

void TIVA2()  // initialization of tiva 2 (Base , LINE follower , base sensors) 
{
	//RCGCGPIO |=0x3E;
		RCGCPWM  |=0x03;                         // enable clock to PWM0 & PWM1
	RCC        &= ~0x00100000 ;               // don't use pre-divide for PWM clock (default)
	
  ADCB_Init();
  ADCC_Init();
 ADCD_Init();
		  ADCE_Init();
  PortF_Init();
 //init_adc_8pins();
	//init_adc_2pins();
 SysTick_Init();
}


// ADC Initilaitation 
void init_adc_3pins()
 {
  /*  
         AIN6  AIN1  AIN0
         PD1   PE2   PE3
  */
 //RCGCADC |= 0x01;                //adc0 Module clock clock
 ADCACTSS_ADC0 &=~0x01 ;        // disable SS0 during configartion
 ADCSSPRI_ADC0 |= 0x3210;       // Set the highest piriority for SS0 (the highest pirority 0x0)
 ADCEMUX_ADC0 &= ~0x000F;       // software trigger for sequencer 0
 ADCSSMUX0_ADC0 &= ~0xFFFFFFFF;     // mask register bits
 ADCSSMUX0_ADC0 = 0x701;           //10
/* 
        if  PE3 - (AIN0) ==>>  (HEX(0x0000)) (DEC(0)) 
   else if  PE2 - (AIN1) ==>>  (HEX(0x0001)) (DEC(1))
   else if  PD1 - (AIN6) ==>>  (HEX(0x0006)) (DEC(6))
   else if  PD0 - (AIN7) ==>>  (HEX(0x0007)) (DEC(7)) 
*/    
 ADCSSCTL0_ADC0 |= 0x0644;      // (0x6) for ending squence and enable interrupt , (0x4) enable interrupt only 
 ADCACTSS_ADC0  |=0x01 ;        // Enable SS0 
 
 }
 
void init_adc_8pins()
{
    volatile unsigned long delay;
 //   RCGCGPIO |= 0x18;  // port D, E clock
//    RCGCADC |= 0x1;    //adc0 clock
   // port E initialization
  //  GPIOAFSEL_PORTE |= 0x0F;   // PE 0,1,2,3 alterntae function enable
  //  GPIODEN_PORTE &= ~0x0F;    // PE 0,1,2,3 digital function disable
  // GPIOAMSEL_PORTE |= 0x0F;   // PE 0,1,2,3 analog function enable
  // port D initialization
  //  GPIOAFSEL_PORTD |= 0x0F;   // PD 0,1,2,3 alterntae function enable
  // GPIODEN_PORTD &= ~0x0F;    // PD 0,1,2,3 digital function disable
  // GPIOAMSEL_PORTD |= 0x0F;   // PD 0,1,2,3 analog function enable

  // ADC 0 init
  /*  PE0   PD0   PD1   PD2   PD3    PE1   PE2   PE3
      AIN3  AIN7  AIN6  AIN5  AIN4   AIN2  AIN1  AIN0
  */

    ADCACTSS_ADC0 &=~0x01;        // disable SS0 during configartion
    ADCSSPRI_ADC0 |= 0x3210;       // Set the highest piriority for SS0
    ADCEMUX_ADC0 &= ~0x000F;       //software trigger for sequencer 0
    ADCSSMUX0_ADC0 &= ~0xFFFFFFFF;  // mask register bits
    ADCSSMUX0_ADC0 += 0x30124567;   // [(AIN3)-(AIN0)-(AIN1)-(AIN2)-(AIN4)-(AIN5)-(AIN6)-(AIN7) ] 0x30124567
    ADCSSCTL0_ADC0 |= 0x64444444;   // enable raw interrupt signal (IE) for all channels and END7(sample 8 is the last sample)
    ADCACTSS_ADC0 |= 0x01;         //Enable SS0
}

void init_adc_2pins()//--------------------
 {
  /*  
        AIN10  AIN11  
         PB4   PB5   
  */
 //RCGCADC |= 0x01;                //adc0 Module clock clock
 ADCACTSS_ADC0 &=~0x02 ;        // disable SS2 during configartion
 ADCSSPRI_ADC0 |= 0x3201;       // Set the highest piriority for SS1 (the highest pirority 0x0)
 ADCEMUX_ADC0 &= ~0x00F0;       // software trigger for sequencer 1
 ADCSSMUX1_ADC0 &= ~0xFFFF;     // mask register bits
 ADCSSMUX1_ADC0 = 0x00BA;      
/* 
        if  PB4 - (AIN10) ==>>  (HEX(0x000A)) (DEC(10)) 
   else if  PB5 - (AIN11) ==>>  (HEX(0x000B)) (DEC(11))
 
*/    
 ADCSSCTL1_ADC0 |= 0x0006;      // (0x6) for ending squence and enable interrupt , (0x4) enable interrupt only 
 ADCACTSS_ADC0  |=0x02 ;        // Enable SS1
 
 }
/*
void Timer4(void)
{
----	GPIOLOCK_PORTC = 0x4C4F434B ;
	GPIOCR_PORTC   |= 0x01;
	GPIOAFSEL_PORTC |= 0x01;                 // activate alternate function for 0
	GPIOPCTL_PORTC  &= ~0x000000F;          //initialize pctl
	GPIOPCTL_PORTC  |= 0x00000007;---------------
  RCGCTIMER |= 0x10;   // 0) activate timer4
  GPTMCTL4 = 0x00000000;   // 1) disable timer4A
  GPTMCFG4 = 0x00000000;   // 2) 32-bit mode
  GPTMTAMR4 = 0x00000002;  // 3) oneshot mode
  GPTMTAILR4 = 0x00400000;   // 4) reload value
  GPTMTAPR4 = 0;           // 5) clock resolution
  GPTMICR4 = 0x00000001;   // 6) clear timeout flag
  GPTMIMR4 = 0x00000001;   // 7) arm timeout
  PRI23 = (PRI23&0x00FFFFFF)|0x80000000; 
// 8) priority 4
  EN2 = 1<<6;          // 9) enable IRQ 70 in
  //GPTMCTL4 = 0x00000001;   // 10) enable timer4A
}
*/

void delayUs(int n)
{
    int i, j;
    for(i = 0 ; i < n; i++)
	
        for(j = 0; j < 3; j++)
     {}  // do nothing for 1 us
	}

void analogWrite(int pin,int speed)
{
	if( pin == Motor1)         // single drivers
	{
		PWM0_CMPA_1 = speed;
		PWM0_CTL_1 |= EnableDown;
		PWM0_EN |= 0x04; 
		}
	else if(pin == Motor2)    // single drivers    PWM0_CMPA_0                           
	{ 	
	PWM0_CMPA_0=speed;
		PWM0_CTL_0 |= EnableDown;
	 	PWM0_EN |= 0x01;
	digitalWrite(Motor2Piston,LOW);
	}
	else if(pin==Motor3)
	{    
 PWM0_CMPB_0=speed;
		PWM0_CTL_0 |= EnableDown;
		PWM0_EN |= 0x02; 	
	digitalWrite(Motor3Piston,LOW);
	}
	else if(pin==Motor4)     // SERVO
	{   PWM0_CMPB_1 = speed;
		PWM0_CTL_1 |= EnableDown;
		PWM0_EN |= 0x08;      }
	else if(pin==Motor5)    ///////////////////////////////////////
	{   PWM0_CMPA_2 =speed;
		PWM0_CTL_2 |= EnableDown;
		PWM0_EN |= 0x10;      }
	else if(pin==Motor6)    ////////////////
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
	{                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                           
	if(dir==1)
	{PE1 |= 0x02;}
	else if (dir==LOW)
	{PE1 &= ~0x02;}
	}
	else if(pin==Motor2)
	{  if(dir==1)
	{PC6 |= 0x40;}
	else if (dir==LOW)
	{PC6 &= ~0x40;} }
	else if(pin==Motor3)
	{
	 if(dir==1)
	{PC7 |= 0x80;}
	else if (dir==LOW)
	{PC7 &= ~0x80;}}
	else if(pin==Motor4)  // SERVO
	{if(dir==1)
	{}
	else if (dir==LOW)
	{}  }
	else if(pin==Motor5)       ///// TIVA 2 PC6 -- PD2 for one tiva
	{if(dir==1)
	{PC6 |= 0x40;}              
	else if (dir==0)
	{PC6 &= ~0x40;}}
	else if(pin==Motor6)        /////// TIVA 2 PC7 ---PD3  for one tiva   
	{ if(dir==1)
	{PC7 |= 0x80;}              
	else if (dir==0)
	{PC7 &= ~0x80;}}
	else if(pin==Motor7)       /////// TIVA 2 PB0 --- PE0 
	{ if(dir==1)
	{PB0 |= 0x01;}               
	else if (dir==0)
	{PB0 &= ~0x01;}}
	else if(pin==Motor8)       /////// TIVA 2 PB0 ---  PB3
	{ if(dir==1)
	{PB1 |= 0x02;}
	else if (dir==0)
	{PB1 &= ~0x02;}}
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
	else if(pin==ServeMotorCW)
	{if(dir==1)
	{PD6 |= 0x40;}
	else if (dir==0)
	{PD6 &= ~0x40;}}
	else if(pin==ServeMotorCCW)
	{if(dir==1)
	{PD7 |= 0x80;
	PD6 |= 0x40;}   //----------------DRIVER----------
	else if (dir==0)
	{PD7 &= ~0x80;
	PD6 &= ~0x40;}} //----------------DRIVER----------
	else if(pin==ServePiston)
	{if(dir==1)
	{PE0 |= 0x1;}
	else if (dir==0)
	{PE0 &= ~0x1;}}
	else if(pin==Motor3Piston)
	{if(dir==1)
	{PD2 |= 0x04;}
	else if (dir==0)
	{PD2 &= ~0x04;}}
	else if (pin==Motor2Piston)
	{if(dir==1)
	{PE0|= 0x01;}
	else if (dir==0)
	{PE0 &= ~0x01;}}
}

void MotorStop(int pin)
{
	if( pin == Motor1)
	{ PWM0_EN &= ~0x04; }
	else if(pin == Motor2)
	{ PWM0_EN &= ~0x02; 
	 digitalWrite(Motor2Piston,HIGH);
	}
	else if(pin==Motor3)
	{PWM0_EN &= ~0x01; 
	 digitalWrite(Motor3Piston,HIGH);
	}
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




