#include "Serve.h"

unsigned long State=1 ;
unsigned long I=0;

////////////RELAYS ACTIVE LOW ///////////////////



void GPIOD_Handler(void)     ///////////// serve sensor 
{
	/*
if(GPIORIS_PORTD&0x02)
{ 
	switch (State)
	{
		case 1:
		digitalWrite(ServePiston,HIGH);
digitalWrite(ServeMotorCW,LOW);
		digitalWrite(ServeMotorCCW,LOW);
	//	GPIOIM_PORTD &= ~0x01;
			//	State=2;
		break;
		
		case 2:
		digitalWrite(ServePiston,HIGH);
		digitalWrite(ServeMotorCCW,LOW);
		digitalWrite(ServeMotorCW,LOW);
		//	GPIOIM_PORTD &= ~0x01;
			//	State=1;
		break;
	}
	I++;
 GPIOICR_PORTD=0x02;   // acknowledge pin 0 clear for next interrupt 
	//	GPIOIM_PORTD &= ~0x01;
}*/
}


void Serve()
{
	
	/*
				serve();
	digitalWrite(ServePiston,LOW);
			digitalWrite(ServeMotorCW,LOW);
digitalWrite(ServeMotorCCW,HIGH); 
		Delay1ms(1000);
	digitalWrite(ServeMotorCCW,LOW); 
	Delay1ms(100);
	digitalWrite(ServePiston,HIGH);
	Delay1ms(200);
		digitalWrite(ServeMotorCW,HIGH); 
Delay1ms(750);
			digitalWrite(ServeMotorCW,LOW);
		digitalWrite(ServeMotorCCW,LOW); 
	Delay1ms(290);
		digitalWrite(ServePiston,LOW);
	Delay1ms(200);
	servestop();
	
}*/
	/*
			digitalWrite(ServePiston,HIGH);
digitalWrite(ServeMotorCW,LOW); 
		digitalWrite(ServeMotorCCW,HIGH); 
		delayUs(20000);
					digitalWrite(ServePiston,LOW);
		digitalWrite(ServeMotorCW,LOW); 
		digitalWrite(ServeMotorCCW,LOW); 
servestop()		;*/

	
	switch (State)
	{
		case 1:
	digitalWrite(ServePiston,LOW);
digitalWrite(ServeMotorCW,HIGH); 
		digitalWrite(ServeMotorCCW,LOW);		
		State=2;
				GPIOIM_PORTA    |= 0x20;
		Delay1ms(5);
		break;
		
		case 2:
			digitalWrite(ServePiston,LOW);
digitalWrite(ServeMotorCCW,HIGH);
				digitalWrite(ServeMotorCW,LOW);
		State=1;
				GPIOIM_PORTA    |= 0x20;
				Delay1ms(5);

		break;
	}
	/*
	switch (State)
	{
		
		
		case 0:
			serve();
	digitalWrite(ServePiston,LOW);
digitalWrite(ServeMotorCW,HIGH); 
		digitalWrite(ServeMotorCCW,LOW);
		delayUs(100000);
			digitalWrite(ServePiston,HIGH);
digitalWrite(ServeMotorCW,LOW); 
		delayUs(100000);
servestop()		;
		State=1;
		break;
		
		case 1:
			serve();
	digitalWrite(ServePiston,LOW);
digitalWrite(ServeMotorCCW,HIGH); 
		digitalWrite(ServeMotorCW,LOW);
		delayUs(50000);
			digitalWrite(ServePiston,HIGH);
digitalWrite(ServeMotorCCW,LOW); 
		delayUs(50000);
servestop()		;
		State=2;
		break;
		
		case 2:
				serve();
	digitalWrite(ServePiston,LOW);
digitalWrite(ServeMotorCW,HIGH); 
		digitalWrite(ServeMotorCCW,LOW);
		delayUs(50000);
			digitalWrite(ServePiston,HIGH);
digitalWrite(ServeMotorCW,LOW); 
		delayUs(50000);
servestop()		;
		State=1;
		break;
}*/
	}

