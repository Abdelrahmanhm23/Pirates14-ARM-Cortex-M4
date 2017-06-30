#include "encoders.h"
unsigned long Q=0;
//unsigned long State=1 ; 
unsigned long W=0;
unsigned long T=0;


 unsigned long Mlifter1counter=0 ;
 unsigned long Mlifter2counter=0 ;
 unsigned long Mlifter3counter=0 ;
 unsigned long MServecounter=0 ;
 
unsigned long RPM_ML1=0;
unsigned long RPM_ML2=0;
unsigned long RPM_ML3=0 ;
unsigned long RPM_MServe=0 ;

unsigned long prev1 =0;
unsigned long prev2 =0;
unsigned long prev3 =0;
unsigned long prevMServe =0;

unsigned long counts1 =0 ;
unsigned long counts2 =0 ;
unsigned long counts3 =0 ;
unsigned long countsMServe =0 ;

unsigned long prev_counts1 =0 ;
unsigned long prev_counts2 =0 ;
unsigned long prev_counts3 =0 ;
unsigned long prev_MServe =0 ;

void GPIOA_Handler(void)
{
if(GPIORIS_PORTA&0x04)
{ GPIOICR_PORTA=0x04;   // acknowledge pin 2 clear for next interrupt 
	Mlifter1counter++;
	if(Mlifter1counter==0xFFFFFFFF)
	{ Mlifter1counter=0;                                      // reset counter Mlifter 1
		prev1=0;}
	GPIOICR_PORTA=0x04;   // acknowledge pin 2 clear for next interrupt
}
if(GPIORIS_PORTA&0x08)
{GPIOICR_PORTA=0x08;   // acknowledge pin 3 clear for next interrupt 
	Mlifter2counter++;
		if(Mlifter2counter==0xFFFFFFFF)
	{ Mlifter2counter=0;                                      // reset counter  Mlifter 2
		prev2=0;}
}
	if(GPIORIS_PORTA&0x10)
{GPIOICR_PORTA=0x10;   // acknowledge pin 4 clear for next interrupt 
	Mlifter3counter++;
		if(Mlifter3counter==0xFFFFFFFF)
	{ Mlifter3counter=0;                                      // reset counter   Mlifter 3
		prev3=0;}
}
	if(GPIORIS_PORTA&0x20)    // loading sensor 
{
	Delay1ms(5);
	/*MServecounter++;
		if(MServecounter==0xFFFFFFFF)
	{ MServecounter=0;                                      // reset counter   serve Motor
		prevMServe=0;}*/
	Q++;
	switch (State)
	{
		case 1:

		digitalWrite(ServePiston,HIGH);
digitalWrite(ServeMotorCW,LOW);
		digitalWrite(ServeMotorCCW,LOW);
		W++;
		GPIOIM_PORTA &= ~0x20;
			//	State=2;
		break;
		
		case 2:
		digitalWrite(ServePiston,HIGH);
		digitalWrite(ServeMotorCCW,LOW);
		digitalWrite(ServeMotorCW,LOW);
		T++;
			GPIOIM_PORTA &= ~0x20;
			//	State=1;
		break;
	}
	GPIOICR_PORTA=0x20;   // acknowledge pin 5 clear for next interrupt 
}
}



	
void SysTick_Handler()
{
//	GPIOIM_PORTA   &= ~0x3C; 
  	counts1=Mlifter1counter-prev1;           // no. of counts per 0.02 secs motor lifter 1
   	counts2=Mlifter2counter-prev2;           // no. of counts per 0.02 secs motor lifter 2
		counts3=Mlifter3counter-prev3;           // no. of counts per 0.02 secs motor lifter 3
	  countsMServe=MServecounter-prevMServe;           // no. of counts per 0.02 secs serve Motor
/*counts1=	singlePoleFilter(counts1,prev_counts1);   // filter 
counts2=	singlePoleFilter(counts2,prev_counts2);
counts3=	singlePoleFilter(counts3,prev_counts3);*/
	RPM_ML1 = (counts1)  * 50 * (0.001527)* (60) ;           // rpm count Mlifter 1    (counts/secs * rev/count * 60)
	RPM_ML2 = (counts2)  * 50 * (0.001527)* (60) ;           // rpm count Mlifter 2    (counts/secs * rev/count * 60)
	RPM_ML3 = (counts3)  * 50 * (0.001527)* (60) ;            // rpm count Mlifter 3    (counts/secs * rev/count * 60)
//	RPM_MServe = (countsMServe) * 50 * (0.005)* (60) ;    // rpm count MServe   (counts/secs * rev/count * 60)

	prev1 = Mlifter1counter ;                                  // set last count reached
	prev2 = Mlifter2counter ;                                  // set last count reached
	prev3 = Mlifter3counter ;                                  // set last count reached
//	prevMServe = MServecounter ;                                  // set last count reached
//	prev_counts1=counts1;
//	prev_counts2=counts2;
//	prev_counts3=counts3;
	/////////////////////////////////////////////////////////////////////////////////
	if(Mlifter1counter==0xFFFFFFFF)
	{ Mlifter1counter=0;                                      // reset counter
		prev1=0;}
		if(Mlifter2counter==0xFFFFFFFF)
	{Mlifter2counter=0;                                      // reset counter
		prev2=0;}
		if(Mlifter3counter==0xFFFFFFFF)
	{Mlifter3counter=0;                                      // reset counter
		prev3=0;}
//		if(MServecounter==0xFFFFFFFF)
//	{MServecounter=0;                                      // reset counter
//		prevMServe=0;}
	///////////////////////////////////////////////////////////////////////////////
//	GPIOIM_PORTA   |= 0x3C;
}



float singlePoleFilter(const int current, int prev_val)
{
    return SINGLE_POLE_C+ SINGLE_POLE_FILTER_A0*current + SINGLE_POLE_FILTER_B1*prev_val;
}

int Hex2Dec(char hexadecimal[30]) {  
    long long decimalNumber=0;
    char hexDigits[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8',
      '9', 'A', 'B', 'C', 'D', 'E', 'F'};
 //   char hexadecimal[30];  
    int i, j, power=0, digit;  
    /* Converting hexadecimal number to decimal number */
    for(i=strlen(hexadecimal)-1; i >= 0; i--) {
        /*search currect character in hexDigits array */
        for(j=0; j<16; j++){
            if(hexadecimal[i] == hexDigits[j]){
                decimalNumber += j*pow(16, power);
            }
        }
        power++;
    }  
    return decimalNumber;  
}
