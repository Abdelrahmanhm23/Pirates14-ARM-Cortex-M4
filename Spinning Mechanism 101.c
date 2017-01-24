
// 0. Documentation Section
/*
   This program controlls two Motors and a pneumatic valve (Spinning 101)
   Using Systick timer and PWM on tiva (TM4C123)
   Pirates 
   24-1-2017
*/


// 1. Pre-processor Directives Section

/*
Port  F base : 0x40025000 

DATA  offset : 0x3FC
DIR   offset : 0x400
AFSEL offset : 0x420
PUR   offset : 0x510
DEN   offset : 0x51C
LOCK  offset : 0x520
CR    offset : 0x524
AMSEL offset : 0x528
PCTL  offset : 0x52C

GPIO_LOCK_KEY           0x4C4F434B  // Unlocks the GPIO_CR register
*/

#define GPIO_PORTF_DATA_R       (*((volatile unsigned long *)0x400253FC))
#define GPIO_PORTF_DIR_R        (*((volatile unsigned long *)0x40025400))
#define GPIO_PORTF_AFSEL_R      (*((volatile unsigned long *)0x40025420))
#define GPIO_PORTF_PUR_R        (*((volatile unsigned long *)0x40025510))
#define GPIO_PORTF_DEN_R        (*((volatile unsigned long *)0x4002551C))
#define GPIO_PORTF_LOCK_R       (*((volatile unsigned long *)0x40025520))
#define GPIO_PORTF_CR_R         (*((volatile unsigned long *)0x40025524))
#define GPIO_PORTF_AMSEL_R      (*((volatile unsigned long *)0x40025528))
#define GPIO_PORTF_PCTL_R       (*((volatile unsigned long *)0x4002552C))
#define PF4                     (*((volatile unsigned long *)0x40025040))
#define PF3                     (*((volatile unsigned long *)0x40025020))
#define PF2                     (*((volatile unsigned long *)0x40025010))
#define PF1                     (*((volatile unsigned long *)0x40025008))
#define PF0                     (*((volatile unsigned long *)0x40025004)) 	
#define GPIO_LOCK_KEY           0x4C4F434B  // Unlocks the GPIO_CR register
#define SYSCTL_RCGC2_R          (*((volatile unsigned long *)0x400FE108))  // system clock GPIO



/*
               PWM Module 0 base : 0x40028000
These values of registers are for PWM Module 1 (M7 PF3)
                                  Generator 3 (CMPA,CMPB,LOAD,COUT)
               PWM Module 1 base : 0x40029000
                  0   ,   1   ,   2    ,  3
GENA  offsets : 0x060 , 0x0A0 , 0x0E0 , 0x120
GENB  offsets : 0x064 , 0x0A4 , 0x0E4 , 0x124
CMPA  offsets : 0x058 , 0x098 , 0x0D8 , 0x118
CMPB  offsets : 0x05C , 0x09C , 0x0DC , 0x11C
COUNT offsets : 0x054 , 0x094 , 0x0D4 , 0x114
LOAD  offsets : 0x050 , 0x090 , 0x0D0 , 0x110
CTL   offsets : 0x040 , 0x080 , 0x0C0 , 0x100
PWM RCGC : 0x640
RCC : 0x060
PWM ENABLE : 0x08
*/

#define SYSCTL_PWM_RCGC_R       (*((volatile unsigned long *) 0x400FE640)) // Clock source to PWM D1 or D0 bits of RCGCPWM register (1 PWM M0) (2 PWM M1)
#define SYSCTL_RCC_R            (*((volatile unsigned long *) 0x400FE060)) //system clock ( used for PWM divider.(D20 enable)(D19->D17 values) 2, 4, 8, 16, 32, and 64
#define GPIO_PWM_CTL_R          (*((volatile unsigned long *) 0x40029100)) // PWMx Control) register to enable the Generator (Counter).
#define GPIO_PWM1_LOAD_R        (*((volatile unsigned long *) 0x40029110)) //LOAD register To set the maximum value for the Counter
#define GPIO_PWM1_COUNT_R       (*((volatile unsigned long *) 0x40029114)) // Counter reg current count----READ ONLY------
#define GPIO_PWM1_CMPA_R        (*((volatile unsigned long *) 0x40029118)) // Comparetor A
#define GPIO_PWM1_CMPB_R        (*((volatile unsigned long *) 0x4002911C)) // Comparetor B
#define GPIO_PWM1_ENABLE_R      (*((volatile unsigned long *) 0x40029008)) //each PWM generator has an enable register PWMENABLE
#define GPIO_PWM1_GENA_R        (*((volatile unsigned long *) 0x40029120)) // Generator A
#define GPIO_PWM1_GENB_R        (*((volatile unsigned long *) 0x40029124)) // Generator B

/* Grant coprocessor access */
/* This is required since TM4C123G has a floating point coprocessor */

#define SCB_R                   (*((volatile unsigned long *) 0xE000ED88)) 


// Systic timer 
// Registers 
#define NVIC_ST_CTRL_R          (*((volatile unsigned long *)0xE000E010))
#define NVIC_ST_RELOAD_R        (*((volatile unsigned long *)0xE000E014))
#define NVIC_ST_CURRENT_R       (*((volatile unsigned long *)0xE000E018))
// Values
#define NVIC_ST_CTRL_COUNT      0x00010000 // Count flag
#define NVIC_ST_CTRL_CLK_SRC    0x00000004  // Clock Source
#define NVIC_ST_CTRL_INTEN      0x00000002  // Interrupt enable
#define NVIC_ST_CTRL_ENABLE     0x00000001  // Counter mode
#define NVIC_ST_RELOAD_M        0x000FFFFF  // Counter load value -----------------------TIMER VALUE------------------------


//-------------------------------------------------------------------------------------------------------------------------------------



 /*
     2.Function Prototypes

       Subroutines Section
 */

void PortF_INIT(void) ;
void SystemInit(void) ;
void delayMs(int n);
void SysTick_Init(void);
void delayUs(int n);

//------------------------------------------------------------------------------------------------------------------------------------


/*  
       3.Global declerations section

 */

volatile unsigned long i ;
volatile unsigned long x=0 ;

//----------------------------------------------------------------------------------------------------------------------------------------




// 4. MAIN: Mandatory for a C Program to be executable

int main(void)
{
    PortF_INIT();
	SystemInit();
    SysTick_Init();

	GPIO_PWM1_ENABLE_R =0x00;

while(1)
	{

	  if( PF4==0)       
	   {
    	PF1 |= 0x02;                       // close valve 
		delayUs(500);                      // delay before spinning 
		GPIO_PWM1_ENABLE_R = 0x40 ;        // enble spinning motor
		delayUs(500);                      // delay 

	     while(1)
	     {
			if(PF0==0)
		    {
			PF1 &= ~0x02;
			GPIO_PWM1_ENABLE_R =0x00;
			x=0;
			break;    }

	        NVIC_ST_CTRL_R = NVIC_ST_CTRL_ENABLE+NVIC_ST_CTRL_CLK_SRC;	// enable systick control system clock and enable
			GPIO_PWM1_ENABLE_R |= 0x80;

	        if(NVIC_ST_CTRL_R == 0x10005)  // check systick flag satus
		     { 
              NVIC_ST_CTRL_R = 0;  		   // disable systick control	
			  PF1 &=  ~0x02;               // open valve
		      GPIO_PWM1_ENABLE_R &= ~0x80; // Stop Motor
		  	  x=0;
			  delayUs(150000);
		      GPIO_PWM1_ENABLE_R &= ~0x40 ;
			  break;   
            if(PF0==0)
		   {
			PF1 &= ~0x02;
			GPIO_PWM1_ENABLE_R =0x00;
			x=0;
			break;    }
	     }	
      } 
   }
	       if(PF0==0)
		   {
			PF1 &= ~0x02;
			GPIO_PWM1_ENABLE_R =0x00;
			x=0; }
		
}	
	}

//--------------------------------------------------------------------------------------------------------------------------

//5. Functions

void PortF_INIT(void)
{
	SYSCTL_PWM_RCGC_R |=0x02;            // enable clock to PWM1 
    SYSCTL_RCGC2_R |= 0x00000020;        // 1) activate clock for Port F
	SYSCTL_RCC_R &= ~0x00100000 ;        // don't use pre-divide for PWM clock (default)
	
    GPIO_PORTF_AFSEL_R = 0x0C	;        // enable alt funct on PF3 and PF2
	
	GPIO_PORTF_PCTL_R &= ~0x0000FF00;    // make PF3 PWM outputn PWM pin & PF2 output PWM pins
    GPIO_PORTF_PCTL_R |= 0x00005500; 
	
	GPIO_PORTF_DATA_R = 0x0000000000;
	GPIO_PORTF_LOCK_R = 0x4C4F434B;      // 2) unlock GPIO Port F
    GPIO_PORTF_CR_R = 0x1F;              // allow changes to PF4-0
    GPIO_PORTF_PUR_R = 0x11;             // enable pull-up on PF0 and PF4	
	GPIO_PORTF_DEN_R = 0x1F;  
    GPIO_PORTF_DIR_R = 0x0E;             // 5) PF4,PF0 in, PF3-1 out
	
	GPIO_PWM_CTL_R =0x00;                 // stop counter
	GPIO_PWM1_GENA_R = 0x0000080C ;       // M1PWM6 output set when reload clear when match PWM CMP A  ch6
	GPIO_PWM1_GENB_R = 0x00000008C ;      // M1PWM7 output set when reload clear when match PWM CMP B ch7
	GPIO_PWM1_LOAD_R = 160000;            // set load value for 1kHz (16MHz/16000)
	GPIO_PWM1_CMPA_R = 10000;             // set duty cycle to min PWM1 ch 7 -------- MOTOR-------
	GPIO_PWM1_CMPB_R = 10000;             // set duty cycle to min PWM1 ch 6 ---------SPINNING-----
	GPIO_PWM_CTL_R =0x01;                 // start timer
//	GPIO_PWM1_ENABLE_R = 0xC0 ;           // start PWM1 ch7 and PWM1 ch6
//  GPIO_PWM1_ENABLE_R = 0x40 ;           // start PWM1 ch6
//  GPIO_PWM1_ENABLE_R = 0x80 ;           // start PWM1 ch7
	/*for(;;)                               // LOOP
	{ 
	}*/
	
 }




//Systick Function initialization

void SysTick_Init(void){
  NVIC_ST_CTRL_R = 0;                   // disable SysTick during setup
  NVIC_ST_RELOAD_R = NVIC_ST_RELOAD_M;  // maximum reload value
  NVIC_ST_CURRENT_R = 0;                // any write to current clears it
                                        // enable SysTick with core clock
  //NVIC_ST_CTRL_R = NVIC_ST_CTRL_ENABLE+NVIC_ST_CTRL_CLK_SRC;

}


// Delay function 
void delayUs(int n)
{   int i, j;
    for(i = 0 ; i < n; i++)
        for(j = 0; j < 3; j++)
     {}  // do nothing for 1 us
	}




/* Grant coprocessor access */
/* This is required since TM4C123G has a floating point coprocessor */
void SystemInit(void)
{
 SCB_R |= 0x00f00000;
}
//-----------------------------------------------------------------------------------------
