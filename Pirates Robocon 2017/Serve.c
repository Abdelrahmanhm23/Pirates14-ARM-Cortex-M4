////////////////////////////////////////////////
/*
This file is used to control the whole serve mechanism

Using object detection sensor to detect the saucer
Three motors (two for serving the saucer , one for loading the saucer from the magazines)
One piston
*/
////////////////////////////////////////////////

#include "Serve.h"

unsigned long State=1 ;
unsigned long I=0;
unsigned long state1=0;
unsigned long state2=0;
uint32_t SHARP[]={0};



	void Serve()
{
	/////////////////////////////1 magazine//////////////////////////

	digitalWrite(ServePiston,LOW);
		 Delay1ms(15);
      	PD2 &= ~0x04;
	analogWrite(Motor10,3000) ;
		  Delay1ms(5);
		while(1)
		{
			if (ReadData()==0x24) 
			{MotorStop(Motor10);
						digitalWrite(ServePiston,LOW);
			break;}
			if((PA5&0x20)==0x00)
			{	
				if (ReadData()==0x24)
 {MotorStop(Motor10);
	 		digitalWrite(ServePiston,LOW);

 break;}
				Delay1ms(65);
				digitalWrite(ServePiston,HIGH);
    MotorStop(Motor10);
						Delay1ms(5);
					Delay1ms(150);
		digitalWrite(ServePiston,LOW);
					PD2 |= 0x04;
	analogWrite(Motor10,3000) ;
		Delay1ms(470);
		digitalWrite(ServePiston,LOW);
      MotorStop(Motor10);
      break;
			}
		}

/////////////////////////////2 magazines//////////////////////////
/*
switch (State)
	{
		case 1:
	    digitalWrite(ServePiston,LOW);
		 Delay1ms(15);
      	PD2 &= ~0x04;
	analogWrite(Motor10,5000) ;
		  State=2;
		  Delay1ms(5);
	//	state1++;
		while(1)
		{
			if((PA5&0x20)==0x00)
			//if(((PE2&0x04)==0))
			{	
				Delay1ms(65);
				digitalWrite(ServePiston,HIGH);
    MotorStop(Motor10);
						Delay1ms(5);
						state1++;
//				PD2 |= 0x04;
//	analogWrite(Motor10,5000) ;
					Delay1ms(150);
			//	    MotorStop(Motor10);
		digitalWrite(ServePiston,LOW);
      break;
			}
		}
		break;
		
		case 2:
			digitalWrite(ServePiston,LOW);
		Delay1ms(15);
      	PD2 |= 0x04;
		Delay1ms(15);
	analogWrite(Motor10,5000) ;
		  State=1;
		  Delay1ms(5);
		//state2++;
			while(1)
		{
			if((PA5&0x20)==0x00)
		//	if(((PE2&0x04)==0))
			{
				Delay1ms(65);
		digitalWrite(ServePiston,HIGH);
		MotorStop(Motor10);
					Delay1ms(5);
	//			    	PD2 &= ~0x04;
//	analogWrite(Motor10,5000) ;
	Delay1ms(150);
		digitalWrite(ServePiston,LOW);
	//					MotorStop(Motor10);
      break;
			}
		}
		break;

}
/////////////////////////////////////////////////////////////////////
*/

	}
