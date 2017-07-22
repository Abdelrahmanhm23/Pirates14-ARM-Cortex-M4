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
//double y = 0.00125 ;
 int i=0;
int a=0;
unsigned long servepwm=8000 ;
//uint32_t A[100]={0};
//uint32_t B[100]={0};
//uint32_t C[100]={0};
//uint32_t D[100]={0};
//uint32_t E[100]={0};
//uint32_t P[100]={0};
//uint32_t G[100]={0};
//uint32_t Z[100]={0};
//int e=0;	
//int y[8]={208,180,150,120,90,60,30,10};
//unsigned long x = 0 ;

void Delay1ms(unsigned long msec);
void Data();
//void PID_REV_lifters();


#define constrain(amt,low,high) ((amt)<(low)?(low):((amt)>(high)?(high):(amt)))

int main()
{

	TIVA1();
	while(1)
	{
	
	Data();
	/*   if(ReadData()==LIFTall_UP)  // UP
		{digitalWrite(ServeMotorCW,HIGH);} 
		else if(ReadData()==LIFTall_DOWN) // DOWN
		{	digitalWrite(ServeMotorCCW,HIGH);}
		else if(ReadData()==LIFT_STOP)
		{		digitalWrite(ServeMotorCW,LOW);
		digitalWrite(ServeMotorCCW,LOW);
		}
		*/
	
	}
}

 

void SystemInit(void)
{
/* Grant coprocessor access */
/* This is required since TM4C123G has a floating point coprocessor */
 SCB_R |= 0x00f00000;
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
		{servepwm=servepwm+8;
		if(servepwm>16000)
		{ servepwm=15800; }		}
		else if(ReadData()==servepwm_UP)    // RIGHT
		{servepwm=servepwm-8;
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
	if (ReadData()==0x15)
	{Pole1(3170,3170,2370,1550);
	a=50;}
	//-------------------------------------------------------------	
		if (ReadData()==POLE2)
	{Pole2(3350,3750,2730,9500);}
	//-------------------------------------------------------------	
	if (ReadData()==POLE3)
	{Pole1(500,500,500,1550);}
	//-------------------------------------------------------------		
	if (ReadData()==POLE4)
	{Pole4(0,0,0,1550);}
	//----------------------------------------------------------
	if (ReadData()==POLE5)
	{Pole5(0,0,0,1550);}
//-------------------------------------------------------------	
	if (ReadData()==LINE)        //RIGHT
	{while(1)
		{	line ();
	if(ReadData()==R2)
		{break;}
	if (ReadData()==0x23)
	{break;}
		}
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
	analogWrite(Motor10,5000) ;
		}
				else if(ReadData()==L2)   // L2
		{
		PD2 |= 0x04;
	analogWrite(Motor10,5000) ;
		}
		
				else if(ReadData()==UP)   // L2
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



/*

void PID_REV_lifters()
{
	if(ReadData()==0x18)  // lifters up PID
		{
			digitalWrite(Motor1,LOW);
			  digitalWrite(Motor2,LOW);
			  digitalWrite(Motor3,LOW);
			while(1)
			{
			PID_ML1_RPM();
			PID_ML2_RPM();
			PID_ML3_RPM();
			Data();
			if(ReadData()==0x20) // lifters stop
			{
				Mlifter1counter=0 ;
				Mlifter2counter=0 ;
				Mlifter3counter=0 ;
					liftersStop();
				break;
			}
			}
		}
		
		if(ReadData()==0x78)  // lifters down PID
		{
			digitalWrite(Motor1,HIGH);
			digitalWrite(Motor2,HIGH);
			digitalWrite(Motor3,HIGH);
			while(1)
			{
			PID_ML1_RPM();
			PID_ML2_RPM();
			PID_ML3_RPM();
			Data();
			if(ReadData()==0x66) // lifters stop
			{
				Mlifter1counter=0 ;
				Mlifter2counter=0 ;
				Mlifter3counter=0 ;
				liftersStop();
				break;
			}
			}
		}
		
		
		if(ReadData()==0x78)  // lifters REV up PID
		{
			digitalWrite(Motor1,LOW);
			digitalWrite(Motor2,LOW);
			digitalWrite(Motor3,LOW);
			while(1)
			{
			PID_ML1_REV();
			PID_ML2_REV();
			PID_ML3_REV();
			Data();
			if(Mlifter1counter>=135 && Mlifter2counter>=135 && Mlifter3counter>=135) // lifters stop
			{
				Mlifter1counter=0 ;
				Mlifter2counter=0 ;
				Mlifter3counter=0 ;
			liftersStop();
				break;
			}
			}
		}
		if(ReadData()==0x78)  // lifters REV DOWN up PID
		{
			digitalWrite(Motor1,HIGH);
			digitalWrite(Motor2,HIGH);
			digitalWrite(Motor3,HIGH);
			while(1)
			{
			PID_ML1_REV();
			PID_ML2_REV();
			PID_ML3_REV();
			Data();
			if(Mlifter1counter>=135 && Mlifter2counter>=135 && Mlifter3counter>=135) // lifters stop
			{
				Mlifter1counter=0 ;
				Mlifter2counter=0 ;
				Mlifter3counter=0 ;
			liftersStop();
				break;
			}
			}
		}
		
		if(ReadData()==0x80)  // lifters 1,2 up PID
		{
			digitalWrite(Motor1,LOW);
			  digitalWrite(Motor2,LOW);
			while(1)
			{
			PID_ML1_RPM();
			PID_ML2_RPM();
			Data();
			if(ReadData()==0x81) // lifters stop
			{
				Mlifter1counter=0 ;
				Mlifter2counter=0 ;
							digitalWrite(Motor1,LOW);
			  digitalWrite(Motor2,LOW);
				MotorStop(Motor1);
				MotorStop(Motor2);
				break;
			}
			}
		}
		
		if(ReadData()==0x82)  // lifters 1,2 down PID
		{
			digitalWrite(Motor1,HIGH);
			digitalWrite(Motor2,HIGH);
			while(1)
			{
			PID_ML1_RPM();
			PID_ML2_RPM();
			Data();
			if(ReadData()==0x81) // lifters stop
			{
				Mlifter1counter=0 ;
				Mlifter2counter=0 ;
					digitalWrite(Motor1,LOW);
			  digitalWrite(Motor2,LOW);
				MotorStop(Motor1);
				MotorStop(Motor2);
				break;
			}
			}
		}
		
		if(ReadData()==0x83)  // lifters 3 up PID
		{
			digitalWrite(Motor1,LOW);
			  digitalWrite(Motor2,LOW);
			while(1)
			{
			PID_ML3_RPM();
			Data();
			if(ReadData()==0x81) // lifters stop
			{
				Mlifter3counter=0 ;
			  digitalWrite(Motor3,LOW);
				MotorStop(Motor3);
				break;
			}
			}
		}
		
		
		
			if(ReadData()==0x84)  // lifters 3 down PID
		{
			digitalWrite(Motor3,HIGH);
			while(1)
			{
			PID_ML3_RPM();
			Data();
			if(ReadData()==0x81) // lifters stop
			{
				Mlifter3counter=0 ;
			  digitalWrite(Motor3,LOW);
				MotorStop(Motor3);
				break;
			}
			}
		}
		
		if(ReadData()==0x85)  // lifter 1,2 REV up PID
		{
			digitalWrite(Motor1,LOW);
			digitalWrite(Motor2,LOW);
			while(1)
			{
			PID_ML1_REV();
			PID_ML2_REV();
			Data();
			if(Mlifter1counter>=135 && Mlifter2counter>=135 ) // lifters stop
			{
				Mlifter1counter=0 ;
				Mlifter2counter=0 ;
				digitalWrite(Motor1,LOW);
			  digitalWrite(Motor2,LOW);
				MotorStop(Motor1);
				MotorStop(Motor2);
				break;
			}
			}
		}
		if(ReadData()==0x86)  // lifter 1,2 REV DOWN up PID
		{
			digitalWrite(Motor1,HIGH);
			digitalWrite(Motor2,HIGH);
			while(1)
			{
			PID_ML1_REV();
			PID_ML2_REV();
			Data();
			if(Mlifter1counter>=135 && Mlifter2counter>=135 ) // lifters stop
			{
				Mlifter1counter=0 ;
				Mlifter2counter=0 ;
				digitalWrite(Motor1,LOW);
			  digitalWrite(Motor2,LOW);
				MotorStop(Motor1);
				MotorStop(Motor2);
				break;
			}
			}
		}
			
		if(ReadData()==0x87)  // lifter 3 REV up PID
		{
			digitalWrite(Motor3,LOW);
			while(1)
			{
			PID_ML3_REV();
			Data();
			if(Mlifter3counter>=135 ) // lifters stop
			{
				Mlifter3counter=0 ;
			  digitalWrite(Motor3,LOW);
				MotorStop(Motor3);
				break;
			}
			}
		}
		if(ReadData()==0x88)  // lifter 1,2 REV DOWN up PID
		{
			digitalWrite(Motor3,HIGH);
			while(1)
			{
			PID_ML3_REV();
			Data();
			if(Mlifter3counter>=135 ) // lifters stop
			{
				Mlifter3counter=0 ;
			  digitalWrite(Motor3,LOW);
				MotorStop(Motor3);
				break;
			}
			}
		}
		
}*/



/*main()
{
	while(1)

//	for(a=0;a<=8;a++)
	//{
	//i=	map(y[a] , 0 , 255 , 3190 , 0);
	//}
		//GPIODATA_PORTD |= 0x40;
		//digitalWrite(ServeMotorCCW,LOW);
		//	digitalWrite(ServePiston,1);
	//	digitalWrite(ServeMotorCCW,1);
	//digitalWrite(ServeMotorCW,1);
	//	Serve();
	//	delayUs(200000);
		//if(State==2)
		//{
		//	while(1);
	//	}
//	LOAD();
	//	TIMER4A_Start();
	//	TIMER4A_Stop();
	
	/*	for(i=0;i<=1600;i=i+100)
		{
		analogWrite(Motor7,i);
			analogWrite(Motor8,i);
			for(x=0;x<=50000;x++)
		{
			
		}

	}*/
	//analogWrite(Motor1,2000);
	//analogWrite(Motor2,2000);
//	i = (0x3FC) * (1/0.02) * (y)* 60 ;

//	x=Hex2Dec(0xA0);
//digitalWrite(Motor1,HIGH);
//	digitalWrite(Motor2,HIGH);
	/*
	while(1)
	{
		
		
	
		Data();
	 // PID_REV_lifters();
		
	//	if(ReadData()==0x11)
	//	{
		while(1)
		{PID_ML2_REV();
		if(PID_value_ML2==3190)
		{Mlifter2counter=0;
		break;}}}
		PID_ML2_REV();*/
		//	analogWrite(Motor1,2000);
   //  analogWrite(Motor2,2000);
	//	PID_ML1_REV();
	//	PID_ML3_REV();
	//	WaitForInterrupt();
//		PID_ML1_RPM();
// PID_ML3_RPM();
//Delay1ms(4);
	//	SysTick();
//	analogWrite(Motor1,0);
	//	analogWrite(Motor2,500);
	//	for(i=1;i<1600;i++)
	//	{
 //analogWrite(Motor1,0);
		//	for(x=1600;x>0;x--)
		//{
		//}
		//}
	//	MotorStop(Motor7);
	//	MotorStop(Motor8);
	//	analogWrite(Motor10,400);
   // MotorStop(Motor2);
	 
//	}


//}