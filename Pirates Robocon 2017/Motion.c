////////////////////////////////////////////////
/*
This file is used to control the motion of the whole robot

Using 10 Motors controlled by citroen motor drivers
4 motors for base (omni wheels)
3 motors for lifter 
2 motors for serving the saucer
1 motor  for loading the saucer


*/
////////////////////////////////////////////////

#include "Motion.h"
 /*
M5------>M1
M6------>M2
M7------>M3
M8------>M4
*/
///

////////////////////////////Each Motor has a diffrent speed in both directions//////////////////
/*   
unsigned long M5_CW  =63;
unsigned long M6_CW  =276;
unsigned long M7_CW  =63;
unsigned long M8_CW  =401;

unsigned long M5_CCW =376;
unsigned long M6_CCW =651;
unsigned long M7_CCW =463;
unsigned long M8_CCW =363;
///////*/
/*
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
unsigned long DOWNLEFT[4]={3190,188,3190,689};
//Motor 1   CCW  //Motor 2   CCW  //Motor 3   CCW	//Motor 4   CCW
unsigned long CLOCKWISE[4]={563,188,438,438};
//Motor 1   CW 	//Motor 2   CW //Motor 3  CW  //Motor 4   CW
unsigned long COUNTERCLOCKWISE[4]={563,413,413,588};
*/
// Motor 1 CW  dir pin // Motor 2 CCW // Motor 3 CCW 	// Motor 4 CW  dir pin
unsigned long FORWARD[4]={2500,940,4070,2940};
// Motor 1 CCW    // Motor 2 CW    dir pin // Motor 3 CW    dir pin // Motor 4 CCW 
unsigned long REVERSE[4]={3445,2065,2130,2815};
//Motor 1   CW   dir pin 	//Motor 2   CW   dir pin //Motor 3   CCW  //Motor 4   CCW  
unsigned long LEFT[4]={2815,2065,3445,3755};
//Motor 1   CCW   	//Motor 2   CCW  //Motor 3   CW    dir pin //Motor 4   CW    dir pin
unsigned long RIGHT[4]={3445,500,940,2940};
	//Motor 1  //Motor 2   CCW   dir pin  //Motor 3 //Motor 4   CW   dir pin
unsigned long UPRIGHT[4]={15950,315,15950,1565};
	//Motor 1   CW    dir pin //Motor 2 //Motor 3   CCW  //Motor 4  
unsigned long UPLEFT[4]={2815,15950,3445,15950};
//Motor 1   CCW   //Motor 2   //Motor 3   CW   dir pin //Motor 4 
unsigned long DOWNRIGHT[4]={3130,15950,3445,15950};
//Motor 1    	//Motor 2   CW   dir pin //Motor 3  //Motor 4   CCW  
unsigned long DOWNLEFT[4]={15950,940,15950,3445};
//Motor 1   CCW  //Motor 2   CCW  //Motor 3   CCW	//Motor 4   CCW
unsigned long CLOCKWISE[4]={2815,940,315,3445};
//Motor 1   CW 	//Motor 2   CW //Motor 3  CW  //Motor 4   CW
unsigned long COUNTERCLOCKWISE[4]={2815,2065,2065,2940};


#define constrain(amt,low,high) ((amt)<(low)?(low):((amt)>(high)?(high):(amt)))



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
		digitalWrite(Motor5,HIGH);
	analogWrite(Motor5,FORWARD[0]) ;
	
	digitalWrite(Motor6,LOW);
	analogWrite(Motor6,FORWARD[1]) ;
	
	digitalWrite(Motor7,LOW);
	analogWrite(Motor7,FORWARD[2]) ;
	
	digitalWrite(Motor8,HIGH);
	analogWrite(Motor8,FORWARD[3]) ;	
	
}

void Reverse()
{
	
	digitalWrite(Motor5,LOW);
	analogWrite(Motor5,REVERSE[0]) ;
	
	digitalWrite(Motor6,HIGH);
	analogWrite(Motor6,REVERSE[1]) ;
	
	digitalWrite(Motor7,HIGH);
	analogWrite(Motor7,REVERSE[2]) ;
	
	digitalWrite(Motor8,LOW);
	analogWrite(Motor8,REVERSE[3]) ;
	
}


void Left()
{
			digitalWrite(Motor5,HIGH);
	analogWrite(Motor5,LEFT[0]) ;
	
	digitalWrite(Motor6,HIGH);
	analogWrite(Motor6,LEFT[1]) ;
	
	digitalWrite(Motor7,LOW);
	analogWrite(Motor7,LEFT[2]) ;
	
	digitalWrite(Motor8,LOW);
	analogWrite(Motor8,LEFT[3]) ;
	
}


void Right()
{
	
			digitalWrite(Motor5,LOW);
	analogWrite(Motor5,RIGHT[0]) ;
	
	digitalWrite(Motor6,LOW);
	analogWrite(Motor6,RIGHT[1]) ;
	
	digitalWrite(Motor7,HIGH);
	analogWrite(Motor7,RIGHT[2]) ;
	
	digitalWrite(Motor8,HIGH);
	analogWrite(Motor8,RIGHT[3]) ;	

}


void UpRight()
{
	
	
	
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
		digitalWrite(Motor5,HIGH);
	analogWrite(Motor5,UPLEFT[0]) ;
	
	digitalWrite(Motor6,LOW);
		MotorStop(Motor6) ;
	
	digitalWrite(Motor7,LOW);
	analogWrite(Motor7,UPLEFT[2]) ;
	
	digitalWrite(Motor8,LOW);
		MotorStop(Motor8) ;	
	
	
}

void DownRight()
{
		
		digitalWrite(Motor5,LOW);
	analogWrite(Motor5,DOWNRIGHT[0]) ;
	
	digitalWrite(Motor6,LOW);
		MotorStop(Motor6) ;
	
	digitalWrite(Motor7,HIGH);
	analogWrite(Motor7,DOWNRIGHT[2]) ;
	
	digitalWrite(Motor8,LOW);
		MotorStop(Motor8) ;	
	

}


void DownLeft()
{
 
	
		digitalWrite(Motor5,LOW);
	MotorStop(Motor5) ;
	
	digitalWrite(Motor6,HIGH);
	analogWrite(Motor6,DOWNLEFT[1]) ;
	
	digitalWrite(Motor7,LOW);
	MotorStop(Motor7) ;
	
	digitalWrite(Motor8,LOW);
	analogWrite(Motor8,DOWNLEFT[3]) ;	
}


void ClockWise()  // low speed rotation
{
		digitalWrite(Motor5,LOW);
	//analogWrite(Motor5,CLOCKWISE[0]) ;
analogWrite(Motor5,10000) ;
	digitalWrite(Motor6,LOW);
	//analogWrite(Motor6,CLOCKWISE[1]) ;
	analogWrite(Motor6,10000) ;
	digitalWrite(Motor7,LOW);
	analogWrite(Motor7,CLOCKWISE[2]) ;
//	analogWrite(Motor7,8000) ;
	digitalWrite(Motor8,LOW);
//	analogWrite(Motor8,CLOCKWISE[3]) ;	
	analogWrite(Motor8,10000) ;

}

void CounterClockWise()  // low speed rotation
{

			digitalWrite(Motor5,HIGH);
//	analogWrite(Motor5,COUNTERCLOCKWISE[0]) ;
		analogWrite(Motor5,10000) ;
	digitalWrite(Motor6,HIGH);
//	analogWrite(Motor6,COUNTERCLOCKWISE[1]) ;
		analogWrite(Motor6,10000) ;
	digitalWrite(Motor7,HIGH);
	//analogWrite(Motor7,COUNTERCLOCKWISE[2]) ;
		analogWrite(Motor7,10000) ;
	digitalWrite(Motor8,HIGH);
	//analogWrite(Motor8,COUNTERCLOCKWISE[3]) ;
		analogWrite(Motor8,10000) ;

}

void lifter1up()
{
		digitalWrite(Motor1,LOW);
	analogWrite(Motor1,1500) ;

}
void lifter1down()
{digitalWrite(Motor1,HIGH);
	analogWrite(Motor1,1500) ;
}
void lifter2up()
{
		digitalWrite(Motor2,LOW);
	analogWrite(Motor2,1500) ;

}
void lifter2down()
{
		digitalWrite(Motor2,HIGH);
	analogWrite(Motor2,1500) ; 
}

void lifter12up()
{
		digitalWrite(Motor1,LOW);
	analogWrite(Motor1,1500) ;
		digitalWrite(Motor2,LOW);
	analogWrite(Motor2,1500) ;

}
void lifter12down()
{digitalWrite(Motor1,HIGH);
	analogWrite(Motor1,1500) ;
		digitalWrite(Motor2,HIGH);
	analogWrite(Motor2,1500) ; 
}

void lifter3up()
{
		digitalWrite(Motor3,LOW);
	analogWrite(Motor3,1500) ;
	}

void lifter3down()
{	digitalWrite(Motor3 ,HIGH);
	analogWrite(Motor3,1500) ;}

void liftersup()
{	
	digitalWrite(Motor1,LOW);
	analogWrite(Motor1,1500) ;
		digitalWrite(Motor2,LOW);
	analogWrite(Motor2,1500) ;
	digitalWrite(Motor3,LOW);
	analogWrite(Motor3,1500) ;
}

void liftersdown()
{
	digitalWrite(Motor1,HIGH);
	analogWrite(Motor1,1500) ;
		digitalWrite(Motor2,HIGH);
	analogWrite(Motor2,1500) ;
	digitalWrite(Motor3,HIGH);
	analogWrite(Motor3,1500) ;
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

	}
	void servestop()
		{
			MotorStop(Motor9);
		}
			