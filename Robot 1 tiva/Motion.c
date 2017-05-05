#include "Motion.h"
 /*
M5------>M1
M6------>M2
M7------>M3
M8------>M4
*/

unsigned long M5_CW  =63;
unsigned long M6_CW  =276;
unsigned long M7_CW  =63;
unsigned long M8_CW  =401;

unsigned long M5_CCW =376;
unsigned long M6_CCW =651;
unsigned long M7_CCW =463;
unsigned long M8_CCW =363;

#define constrain(amt,low,high) ((amt)<(low)?(low):((amt)>(high)?(high):(amt)))


//unsigned long servepwm ;

void Stop()
{ 
	digitalWrite(Motor5,LOW);   // base motor 1
	MotorStop(Motor5);
	digitalWrite(Motor6,LOW);   // base moptor 2
	MotorStop(Motor6);
	digitalWrite(Motor7,LOW);   // base motor 3
	MotorStop(Motor7);
	digitalWrite(Motor8,LOW);   // base motor 4
	MotorStop(Motor8);
}
void Forward()
{ 
	// Motor 1 CW  dir pin
	// Motor 2 CCW   
	// Motor 3 CCW   
	// Motor 4 CW  dir pin

	digitalWrite(Motor5,HIGH);
	analogWrite(Motor5,M5_CW) ;
	
	digitalWrite(Motor6,LOW);
	analogWrite(Motor6,M6_CCW) ;
	
	digitalWrite(Motor7,LOW);
	analogWrite(Motor7,M7_CCW) ;
	
	digitalWrite(Motor8,HIGH);
	analogWrite(Motor8,M8_CW) ;	
}

void Reverse()
{
	// Motor 1 CCW    
	// Motor 2 CW    dir pin
	// Motor 3 CW    dir pin
	// Motor 4 CCW   
	
	digitalWrite(Motor5,LOW);
	analogWrite(Motor5,M5_CCW) ;
	
	digitalWrite(Motor6,HIGH);
	analogWrite(Motor6,M6_CW) ;
	
	digitalWrite(Motor7,HIGH);
	analogWrite(Motor7,M7_CW) ;
	
	digitalWrite(Motor8,LOW);
	analogWrite(Motor8,M8_CCW) ;	
}


void Left()
{
	//Motor 1   CW   dir pin
	//Motor 2   CW   dir pin
	//Motor 3   CCW  
	//Motor 4   CCW  
	
		digitalWrite(Motor5,HIGH);
	analogWrite(Motor5,M5_CW) ;
	
	digitalWrite(Motor6,HIGH);
	analogWrite(Motor6,M6_CW) ;
	
	digitalWrite(Motor7,LOW);
	analogWrite(Motor7,M7_CCW) ;
	
	digitalWrite(Motor8,LOW);
	analogWrite(Motor8,M8_CCW) ;	
}


void Right()
{
	
	//Motor 1   CCW   
	//Motor 2   CCW  
	//Motor 3   CW    dir pin
	//Motor 4   CW    dir pin
	
		digitalWrite(Motor5,LOW);
	analogWrite(Motor5,M5_CCW) ;
	
	digitalWrite(Motor6,LOW);
	analogWrite(Motor6,M6_CCW) ;
	
	digitalWrite(Motor7,HIGH);
	analogWrite(Motor7,M7_CW) ;
	
	digitalWrite(Motor8,HIGH);
	analogWrite(Motor8,M8_CW) ;	
}


void UpRight()
{
	
	//Motor 1    
	//Motor 2   CCW   dir pin
	//Motor 3   
	//Motor 4   CW   dir pin
	
		digitalWrite(Motor5,LOW);
	MotorStop(Motor5) ;
	
	digitalWrite(Motor6,LOW);
	analogWrite(Motor6,M6_CCW) ;
	
	digitalWrite(Motor7,LOW);
	MotorStop(Motor7) ;
	
	digitalWrite(Motor8,HIGH);
	analogWrite(Motor8,M8_CW) ;	 
}


void UpLeft()
{
	//Motor 1   CW    dir pin 
	//Motor 2     
	//Motor 3   CCW   
	//Motor 4   
	
		digitalWrite(Motor5,HIGH);
	analogWrite(Motor5,M5_CW) ;
	
	digitalWrite(Motor6,LOW);
		MotorStop(Motor6) ;
	
	digitalWrite(Motor7,LOW);
	analogWrite(Motor7,M7_CCW) ;
	
	digitalWrite(Motor8,LOW);
		MotorStop(Motor8) ;	
	
}

void DownRight()
{
		
	//Motor 1   CCW   
	//Motor 2     
	//Motor 3   CW   dir pin
	//Motor 4   
	
		digitalWrite(Motor5,LOW);
	analogWrite(Motor5,M5_CCW) ;
	
	digitalWrite(Motor6,LOW);
		MotorStop(Motor6) ;
	
	digitalWrite(Motor7,HIGH);
	analogWrite(Motor7,M7_CW) ;
	
	digitalWrite(Motor8,LOW);
		MotorStop(Motor8) ;	
}


void DownLeft()
{
	
		
	//Motor 1    
	//Motor 2   CW   dir pin
	//Motor 3   
	//Motor 4   CCW   
	
		digitalWrite(Motor5,LOW);
	MotorStop(Motor5) ;
	
	digitalWrite(Motor6,HIGH);
	analogWrite(Motor6,M6_CW) ;
	
	digitalWrite(Motor7,LOW);
	MotorStop(Motor7) ;
	
	digitalWrite(Motor8,LOW);
	analogWrite(Motor8,M8_CCW) ;	
}


void ClockWise()
{
	//Motor 1   CCW
	//Motor 2   CCW   
	//Motor 3   CCW
	//Motor 4   CCW
		digitalWrite(Motor5,LOW);
	analogWrite(Motor5,M5_CCW) ;
	
	digitalWrite(Motor6,LOW);
	analogWrite(Motor6,M6_CCW) ;
	
	digitalWrite(Motor7,LOW);
	analogWrite(Motor7,M7_CCW) ;
	
	digitalWrite(Motor8,LOW);
	analogWrite(Motor8,M8_CCW) ;	
}

void CounterClockWise()
{
	//Motor 1   CW   dir pin
	//Motor 2   CW   dir pin
	//Motor 3   CW   dir pin
	//Motor 4   CW   
		digitalWrite(Motor5,HIGH);
	analogWrite(Motor5,M5_CW) ;
	
	digitalWrite(Motor6,HIGH);
	analogWrite(Motor6,M6_CW) ;
	
	digitalWrite(Motor7,HIGH);
	analogWrite(Motor7,M7_CW) ;
	
	digitalWrite(Motor8,HIGH);
	analogWrite(Motor8,M8_CW) ;
}



void lifter12up()
{
		digitalWrite(Motor1,LOW);
	analogWrite(Motor1,1550) ;
		digitalWrite(Motor2,LOW);
	analogWrite(Motor2,1550) ;

}
void lifter12down()
{digitalWrite(Motor1,HIGH);
	analogWrite(Motor1,1550) ;
		digitalWrite(Motor2,HIGH);
	analogWrite(Motor2,1550) ; 
}

void lifter3up()
{
		digitalWrite(Motor3,LOW);
	analogWrite(Motor3,1550) ;
	}

void lifter3down()
{	digitalWrite(Motor3 ,HIGH);
	analogWrite(Motor3,1550) ;}

void liftersup()
{	
	digitalWrite(Motor1,LOW);
	analogWrite(Motor1,1550) ;
		digitalWrite(Motor2,LOW);
	analogWrite(Motor2,1550) ;
	digitalWrite(Motor3,LOW);
	analogWrite(Motor3,1550) ;
}

void liftersdown()
{
	digitalWrite(Motor1,HIGH);
	analogWrite(Motor1,1550) ;
		digitalWrite(Motor2,HIGH);
	analogWrite(Motor2,1550) ;
	digitalWrite(Motor3,HIGH);
	analogWrite(Motor3,1550) ;
}
	void liftersStop()
	{
	digitalWrite(Motor1,LOW);   // lifter 1
	MotorStop(Motor1);
	digitalWrite(Motor2,LOW);   // liftr 2
	MotorStop(Motor2);
	digitalWrite(Motor3,LOW);   // lifter 3
	MotorStop(Motor3);
	}
	
	void serve()
	{
		digitalWrite(Motor9,LOW);
	analogWrite(Motor9,servepwm) ;
				digitalWrite(Motor10,LOW);
	analogWrite(Motor10,servepwm) ;
	}
	void servestop()
		{
			MotorStop(Motor9);
			MotorStop(Motor10);
		}
			