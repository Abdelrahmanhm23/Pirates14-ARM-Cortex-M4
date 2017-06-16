#include "Motion.h"
 /*
M5------>M1
M6------>M2
M7------>M3
M8------>M4
*/
///
unsigned long M5_CW  =63;
unsigned long M6_CW  =276;
unsigned long M7_CW  =63;
unsigned long M8_CW  =401;

unsigned long M5_CCW =376;
unsigned long M6_CCW =651;
unsigned long M7_CCW =463;
unsigned long M8_CCW =363;
///////
// Motor 1 CW  dir pin // Motor 2 CCW // Motor 3 CCW 	// Motor 4 CW  dir pin
unsigned long FORWARD[4]={438,188,814,588};
// Motor 1 CCW    // Motor 2 CW    dir pin // Motor 3 CW    dir pin // Motor 4 CCW 
unsigned long REVERSE[4]={689,413,426,563};
//Motor 1   CW   dir pin 	//Motor 2   CW   dir pin //Motor 3   CCW  //Motor 4   CCW  
unsigned long LEFT[4]={563,413,689,751};
//Motor 1   CCW   	//Motor 2   CCW  //Motor 3   CW    dir pin //Motor 4   CW    dir pin
unsigned long RIGHT[4]={689,63,188,588};
	//Motor 1  //Motor 2   CCW   dir pin  //Motor 3 //Motor 4   CW   dir pin
unsigned long UPRIGHT[4]={3190,63,3190,313};
	//Motor 1   CW    dir pin //Motor 2 //Motor 3   CCW  //Motor 4  
unsigned long UPLEFT[4]={563,3190,689,3190};
//Motor 1   CCW   //Motor 2   //Motor 3   CW   dir pin //Motor 4 
unsigned long DOWNRIGHT[4]={626,3190,689,3190};
//Motor 1    	//Motor 2   CW   dir pin //Motor 3  //Motor 4   CCW  
unsigned long DOWNLEFT[4]={3190,188,63,689};
//Motor 1   CCW  //Motor 2   CCW  //Motor 3   CCW	//Motor 4   CCW
unsigned long CLOCKWISE[4]={563,188,438,438};
//Motor 1   CW 	//Motor 2   CW //Motor 3  CW  //Motor 4   CW
unsigned long COUNTERCLOCKWISE[4]={563,413,413,588};

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

//	digitalWrite(Motor5,HIGH);
// analogWrite(Motor5,M5_CW) ;
	
	digitalWrite(Motor6,LOW);
	analogWrite(Motor6,FORWARD[1]) ;
	
	digitalWrite(Motor7,LOW);
	analogWrite(Motor7,FORWARD[2]) ;
	
	digitalWrite(Motor8,HIGH);
	analogWrite(Motor8,FORWARD[3]) ;	
	
	delayUs(1); // delay for motor 1
		digitalWrite(Motor5,HIGH);
	analogWrite(Motor5,FORWARD[0]) ;
}

void Reverse()
{
	// Motor 1 CCW    
	// Motor 2 CW    dir pin
	// Motor 3 CW    dir pin
	// Motor 4 CCW   
	
//	digitalWrite(Motor5,LOW);
//	analogWrite(Motor5,REVERSE[0]) ;
	
	digitalWrite(Motor6,HIGH);
	analogWrite(Motor6,REVERSE[1]) ;
	
	digitalWrite(Motor7,HIGH);
	analogWrite(Motor7,REVERSE[2]) ;
	
	digitalWrite(Motor8,LOW);
	analogWrite(Motor8,REVERSE[3]) ;
	
		delayUs(1); // delay for motor 1
	digitalWrite(Motor5,LOW);
	analogWrite(Motor5,REVERSE[0]) ;	
}


void Left()
{
	//Motor 1   CW   dir pin
	//Motor 2   CW   dir pin
	//Motor 3   CCW  
	//Motor 4   CCW  
	
//		digitalWrite(Motor5,HIGH);
//	analogWrite(Motor5,M5_CW) ;
	
	digitalWrite(Motor6,LEFT[1]);
	analogWrite(Motor6,M6_CW) ;
	
	digitalWrite(Motor7,LOW);
	analogWrite(Motor7,LEFT[2]) ;
	
	digitalWrite(Motor8,LOW);
	analogWrite(Motor8,LEFT[3]) ;
	
			delayUs(1); // delay for motor 1
			digitalWrite(Motor5,HIGH);
	analogWrite(Motor5,LEFT[0]) ;
}


void Right()
{
	
	//Motor 1   CCW   
	//Motor 2   CCW  
	//Motor 3   CW    dir pin
	//Motor 4   CW    dir pin
	
//		digitalWrite(Motor5,LOW);
//	analogWrite(Motor5,M5_CCW) ;
	
	digitalWrite(Motor6,LOW);
	analogWrite(Motor6,RIGHT[1]) ;
	
	digitalWrite(Motor7,HIGH);
	analogWrite(Motor7,RIGHT[2]) ;
	
	digitalWrite(Motor8,HIGH);
	analogWrite(Motor8,RIGHT[3]) ;	
	
				delayUs(1); // delay for motor 1
			digitalWrite(Motor5,LOW);
	analogWrite(Motor5,RIGHT[0]) ;
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
	analogWrite(Motor6,UPRIGHT[1]) ;
	
	digitalWrite(Motor7,LOW);
	MotorStop(Motor7) ;
	
	digitalWrite(Motor8,HIGH);
	analogWrite(Motor8,UPRIGHT[3]) ;	 
	
}


void UpLeft()
{
	//Motor 1   CW    dir pin 
	//Motor 2     
	//Motor 3   CCW   
	//Motor 4   
	
	//	digitalWrite(Motor5,HIGH);
	//analogWrite(Motor5,M5_CW) ;
	
	digitalWrite(Motor6,LOW);
		MotorStop(Motor6) ;
	
	digitalWrite(Motor7,LOW);
	analogWrite(Motor7,UPLEFT[2]) ;
	
	digitalWrite(Motor8,LOW);
		MotorStop(Motor8) ;	
	
	delayUs(1);
		digitalWrite(Motor5,HIGH);
	analogWrite(Motor5,UPLEFT[0]) ;
	
}

void DownRight()
{
		
	//Motor 1   CCW   
	//Motor 2     
	//Motor 3   CW   dir pin
	//Motor 4   
	
//		digitalWrite(Motor5,LOW);
//	analogWrite(Motor5,M5_CCW) ;
	
	digitalWrite(Motor6,LOW);
		MotorStop(Motor6) ;
	
	digitalWrite(Motor7,HIGH);
	analogWrite(Motor7,DOWNRIGHT[2]) ;
	
	digitalWrite(Motor8,LOW);
		MotorStop(Motor8) ;	
	
	delayUs(1);
		digitalWrite(Motor5,LOW);
	analogWrite(Motor5,DOWNRIGHT[0]) ;
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
	analogWrite(Motor6,DOWNLEFT[1]) ;
	
	digitalWrite(Motor7,LOW);
	MotorStop(Motor7) ;
	
	digitalWrite(Motor8,LOW);
	analogWrite(Motor8,DOWNLEFT[3]) ;	
}


void ClockWise()
{
	//Motor 1   CCW
	//Motor 2   CCW   
	//Motor 3   CCW
	//Motor 4   CCW
//		digitalWrite(Motor5,LOW);
//	analogWrite(Motor5,M5_CCW) ;
	
	digitalWrite(Motor6,LOW);
	analogWrite(Motor6,CLOCKWISE[1]) ;
	
	digitalWrite(Motor7,LOW);
	analogWrite(Motor7,CLOCKWISE[2]) ;
	
	digitalWrite(Motor8,LOW);
	analogWrite(Motor8,CLOCKWISE[3]) ;	
	
	delayUs(1);
		digitalWrite(Motor5,LOW);
	analogWrite(Motor5,CLOCKWISE[0]) ;
}

void CounterClockWise()
{
	//Motor 1   CW   dir pin
	//Motor 2   CW   dir pin
	//Motor 3   CW   dir pin
	//Motor 4   CW   
//		digitalWrite(Motor5,HIGH);
//	analogWrite(Motor5,M5_CW) ;
	
	digitalWrite(Motor6,HIGH);
	analogWrite(Motor6,COUNTERCLOCKWISE[1]) ;
	
	digitalWrite(Motor7,HIGH);
	analogWrite(Motor7,COUNTERCLOCKWISE[2]) ;
	
	digitalWrite(Motor8,HIGH);
	analogWrite(Motor8,COUNTERCLOCKWISE[3]) ;
	
	delayUs(1);
			digitalWrite(Motor5,HIGH);
	analogWrite(Motor5,COUNTERCLOCKWISE[0]) ;
	
}

void lifter1up()
{
		digitalWrite(Motor1,LOW);
	analogWrite(Motor1,1550) ;

}
void lifter1down()
{digitalWrite(Motor1,HIGH);
	analogWrite(Motor1,1550) ;
}
void lifter2up()
{
		digitalWrite(Motor2,LOW);
	analogWrite(Motor2,1550) ;

}
void lifter2down()
{
		digitalWrite(Motor2,HIGH);
	analogWrite(Motor2,1550) ; 
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
			