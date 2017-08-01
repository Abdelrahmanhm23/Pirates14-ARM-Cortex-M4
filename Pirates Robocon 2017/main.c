////////////////////////////////////////////////
/*
                           PIRATES
													 
													 
Authors : Omar Walid , Abdelrahman Eladawy   26/7/2017
Runs on TM4C123

This project controls a robot designed for Robocon 2017 competition
http://aburobocon.net/

System Includes:
                - 2 Tivas (used for robot control)
								- 1 arduino (used to connect a ps3 controller and send data to tivas using spi commuinication)
								- 8 channel ldr line sensor
								- 1 channel ldr line sensor
								- 3 optical encoders
								- 3 object detection sensors
								- 2 IR sensors
								- 10 Motors
								- 3 Pistons
								
					
- Project has full detailed files each for a specific function in the robot a Memory map and an initalization file
(linked to tivaware to use the SSI file)(some files are just for trial reasons)

-Robot has two modes Manual mode and Automatic mode 

-Robot has three PID controllers used for height,pitch and roll control.
Controllers were calculated based on system identification using simulink
which gave a transfer function that was used to get the controllers parametes (PID)





For more info contact: 
omarwalid@outlook.com
Abdelrahmanhm23@gmail.com

Please feel free to contact us for any questions or comments


*/
////////////////////////////////////////////////




#include "MemMap.h"
#include "MotorInit.h"
#include "PID.h"
#include "UART.h"
#include "Motion.h"
#include "spi.h"
#include "pistons.h"
#include "Serve.h"
#include "encoders.h"
#include "Poles.h"
#include "ADC.h"
#include "fence.h"
#include <math.h>
#define SCB_R                   (*((volatile unsigned long *) 0xE000ED88))
	

 int i=0;
int a=0;
unsigned long servepwm=8000 ;


void Delay1ms(unsigned long msec);
void Data();

int main()
{
	TIVA1();  // change to TIVA2() to upload to the second tiva
	while(1)
	{
	Data();
	}
}



void Data()
{
	if(ReadData()==0x30)   // ps button
		{Stop();
		 servestop();
		 liftersStop();}
	if (ReadData()== 0x23)  // start manual mode
	{ 
		//a=20;
while(1)
{	
		if(ReadData()==0x0A)   // ps button
		{Stop();
		 servestop();
		 liftersStop();}
	if(ReadData()==0x30)   // ps button
		{Stop();
		 servestop();
		 liftersStop();}
	//	a=20;
	if(ReadData()==0x30)   // ps button
		{Stop();
		 servestop();
		 liftersStop();}
		if(ReadData()==stop)
		{Stop();}
		else if(ReadData()==F)        // analog forward
		{Forward();
		a=1;}
		else if(ReadData()==Rev)      // analog backward
		{Reverse();
		a=2;}
		else if(ReadData()==stop)    
		{Stop();}
		else if(ReadData()==L)        // analog left
		{Left();
		a=3;}
		else if(ReadData()==R)        // analog right
		{Right();
		a=4;}
		else 	if(ReadData()==stop)
		{Stop();}
		else if(ReadData()==UR)       // analog upright
		{UpRight();
		a=5;}
		else if(ReadData()==UL)       // analog upright
		{UpLeft();
		a=6;}  
		else if(ReadData()==DR)       // analog down right
		{DownRight();
		a=7;}
		else if(ReadData()==DL)       //analog down left 
		{DownLeft();
			a=8;}
		else if(ReadData()==CW)       // right analog right( CW)
		{ClockWise();
		a=9;}
		else 	if(ReadData()==stop)
		{Stop();}
		else if(ReadData()==CCW)      // right analog left (CCW)
		{CounterClockWise();
		a=10;}
		else if(ReadData()==stop)
		{Stop();}
		else if(ReadData()==ServeStart)  // R1
		{analogWrite(Motor9,servepwm) ;	  
Delay1ms(5);			
			Serve();
			}
		else if(ReadData()==ServeStop)   // L1
		{servestop();}
		else if(ReadData()==LIFT1_UP)   // R2
		{lifter1up();}
		else if(ReadData()==LIFT1_DOWN) // L2
		{lifter1down();}
		else if(ReadData()==LIFT12_UP)   // TRIANGLE
		{lifter12up();}
		else if(ReadData()==LIFT12_DOWN) // CROSS
		{a=40;
			lifter12down();}
		else if(ReadData()==LIFT3_UP)    // CIRCLE
		{lifter3up();}
		else if(ReadData()==LIFT3_DOWN)  // SQUARE
		{lifter3down();}
		else if(ReadData()==LIFTall_UP)  // UP
		{liftersup();} 
		else if(ReadData()==LIFTall_DOWN) // DOWN
		{liftersdown();}
		else if(ReadData()==LIFT_STOP)
		{liftersStop();}
		else if(ReadData()==servepwm_DOWN)  // LEFT
		{servepwm=servepwm+12;
		if(servepwm>16000)
		{ servepwm=15800; }		}
		else if(ReadData()==servepwm_UP)    // RIGHT
		{servepwm=servepwm-12;
		if(servepwm<80)
		{servepwm=500;}
		if(servepwm>0xFFFF)
		{servepwm=500;}
		}
		else if(ReadData()==stop)
		{Stop();}
	if (ReadData()==0x24)////////break and go into automatic mode 
	{break;}
	}
}
	
/////////////////////////////////// select Automatic mode////////////////////////////////////
	if (ReadData()==0x24) 
	{
		a=90;
		
		while(1)
	{
		if(ReadData()==0x30)   // ps button
		{Stop();
		 servestop();
		 liftersStop();}
		if(ReadData()==0x0A)   // ps button
		{Stop();
		 servestop();
		 liftersStop();}
	//-------------------------------------------------------------		
	if (ReadData()==POLE1)
	{Pole1(2915,3550,2730,4000);}
	//-------------------------------------------------------------	
		if (ReadData()==POLE2)
	{Pole2(3300,3650,2730,10224);}
	//-------------------------------------------------------------	
	if (ReadData()==POLE3)
	{Pole1(3300,3650,2730,9552);}
	//-------------------------------------------------------------		
	if (ReadData()==POLE4)
	{Pole4(0,0,0,1550);}
	//----------------------------------------------------------
//	if (ReadData()==POLE5)
//	{Pole5(0,0,0,1550);}
//-------------------------------------------------------------	
else if(ReadData()==servepwm_DOWN)  // LEFT
		{servepwm=servepwm+25;
		if(servepwm>16000)
		{ servepwm=15800; }		}
		else if(ReadData()==servepwm_UP)    // RIGHT
		{servepwm=servepwm-25;
		if(servepwm<80)
		{servepwm=500;}
		if(servepwm>0xFFFF)
		{servepwm=500;}
		}
//-------------------------------------------------------------
			if(ReadData()==stop)
		{Stop();}
		else if(ReadData()==F)        // analog forward
		{Forward();}
		else if(ReadData()==Rev)      // analog backward
		{Reverse();}
		else if(ReadData()==stop)    
		{Stop();}
		else if(ReadData()==L)        // analog left
		{Left();}
		else if(ReadData()==R)        // analog right
		{Right();}
		else 	if(ReadData()==stop)
		{Stop();}
		else if(ReadData()==UR)       // analog upright
		{UpRight();}
		else if(ReadData()==UL)       // analog upright
		{UpLeft();}  
		else if(ReadData()==DR)       // analog down right
		{DownRight();}
		else if(ReadData()==DL)       //analog down left 
		{DownLeft();}
		else if(ReadData()==CW)       // right analog right(CW)
		{ClockWise();}
		else 	if(ReadData()==stop)
		{Stop();}
		else if(ReadData()==CCW)      // right analog left (CCW)
		{CounterClockWise();}
		else if(ReadData()==stop)
		{Stop();
		MotorStop(Motor10);}
		else if(ReadData()==ServeStart)  // R1
		{serve();}
		else if(ReadData()==ServeStop)   // L1
		{servestop();}
		else if(ReadData()==LIFT_STOP)
		{liftersStop();
		MotorStop(Motor10);}
		else if(ReadData()==R2)
		{
		PD2 &= ~0x04;
	analogWrite(Motor10,1000) ;
		}
				else if(ReadData()==L2)   // L2
		{
		PD2 |= 0x04;
	analogWrite(Motor10,1000) ;
		}
		
				else if(ReadData()==POLE5)   
		{
	digitalWrite(ServePiston,HIGH);
					Delay1ms(150);
		digitalWrite(ServePiston,LOW);
		}
	if (ReadData()==0x23)
	{break;}
	}
}
}




void SystemInit(void)
{
/* Grant coprocessor access */
/* This is required since TM4C123G has a floating point coprocessor */
 SCB_R |= 0x00f00000;
}