#include "fence.h"


void Fence()
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