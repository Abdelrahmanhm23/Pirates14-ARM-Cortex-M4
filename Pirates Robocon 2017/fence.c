////////////////////////////////////////////////
/*
This file is used to make the robot moves straight along the
fence
Using two object detection sensors at the back of the robot 
*/
////////////////////////////////////////////////
#include "fence.h"


void FenceR()
{
	
	Right();
if((digitalRead(s1)==HIGH)&&(digitalRead(s2)==HIGH))
  {Forward();
		Delay1ms(340);
 }

  if((digitalRead(s1)==HIGH)&&(digitalRead(s2)==LOW))
  {CounterClockWise();
	Delay1ms(240);
	ClockWise();
		Delay1ms(20);
	}
  if((digitalRead(s2)==HIGH)&&(digitalRead(s1)==LOW))
  {ClockWise();
	Delay1ms(240);
		CounterClockWise();
		Delay1ms(20);
	}

}

void FenceL()
{
	
	Left();
if((digitalRead(s1)==HIGH)&&(digitalRead(s2)==HIGH))
  {Forward();
		Delay1ms(340);
 }

  if((digitalRead(s1)==HIGH)&&(digitalRead(s2)==LOW))
  {ClockWise();
	Delay1ms(240);
	CounterClockWise();
		Delay1ms(20);
	}
  if((digitalRead(s2)==HIGH)&&(digitalRead(s1)==LOW))
  {CounterClockWise();
	Delay1ms(240);
		ClockWise();
		Delay1ms(20);
	}

}