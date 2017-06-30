#include "Serve.h"

unsigned long State=1 ;
unsigned long I=0;



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
	
	switch (State)
	{
		case 1:
	    digitalWrite(ServePiston,LOW);
      digitalWrite(ServeMotorCW,HIGH); 
		  digitalWrite(ServeMotorCCW,LOW);		
		  State=2;
			GPIOIM_PORTA    |= 0x20;
		  Delay1ms(5);
	/*	while(1)
		{
			if((PA5&0x20)==0x20)
			{		digitalWrite(ServePiston,HIGH);
     digitalWrite(ServeMotorCW,LOW);
		digitalWrite(ServeMotorCCW,LOW);
						Delay1ms(5);
      break;
			}
		}*/
		break;
		
		case 2:
			digitalWrite(ServePiston,LOW);
      digitalWrite(ServeMotorCCW,HIGH);
			digitalWrite(ServeMotorCW,LOW);
		  State=1;
			GPIOIM_PORTA    |= 0x20;
		  Delay1ms(5);
		/*	while(1)
		{
			if((PA5&0x20)==0x20)
			{
		digitalWrite(ServePiston,HIGH);
		digitalWrite(ServeMotorCCW,LOW);
		digitalWrite(ServeMotorCW,LOW);
					Delay1ms(5);
      break;
			}
		}*/
		break;
	}
}

