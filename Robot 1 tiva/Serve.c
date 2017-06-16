#include "Serve.h"

unsigned long State=1 ;
unsigned long I=0;

////////////RELAYS ACTIVE LOW ///////////////////



void GPIOD_Handler(void)     ///////////// serve sensor 
{
	
if(GPIORIS_PORTD&0x01)
{ GPIOICR_PORTD=0x01;   // acknowledge pin 0 clear for next interrupt 
	if(State==1 || State==3 )
	{
		I++;
		digitalWrite(ServePiston,LOW);
digitalWrite(ServeMotorCW,HIGH);
		State=2;
	}
	if(State==2 )
	{
		digitalWrite(ServePiston,LOW);
		digitalWrite(ServeMotorCCW,HIGH);
		State=3;
	}
}
}


void Serve()
{
	if(State==1 || State==3 )
	{
	digitalWrite(ServePiston,HIGH);
digitalWrite(ServeMotorCW,LOW);   // active LOW-----
	}
	if(State==2 )
	{
			digitalWrite(ServePiston,HIGH);
digitalWrite(ServeMotorCCW,LOW);
	}
}

